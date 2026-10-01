# Matrix Transpose Unit Architecture & L2 Integration

## 1. Overview
The **Transpose Unit** provides hardware acceleration for matrix transpositions on 2D matrices up to $32 \times 32$ (16-bit half-precision/Bfloat16 elements). It enables continuous matrix transposition in-line between the Scratchpad memory subsystem and the Vector Register File (VRF) or Systolic Array (GSAU), eliminating software transpose overhead and memory stalls during weight loading and activation alignment.

```
+-------------------------------------------------------------+
|                     Vector Core Datapath                    |
|                                                             |
|   +-------------------+        +------------------------+   |
|   | Scratchpad Port 0 |------->| VLSU Port 0            |   |
|   +-------------------+        |  +------------------+  |   |
|                                |  |  Transpose Unit  |  |   |
|                                |  | (32-bank SRAM +  |  |   |
|                                |  |   32x32 Clos)    |  |   |
|                                |  +------------------+  |   |
|                                |           |            |   |
|                                +-----------v------------+   |
|                                            | Transposed Col |
|                                            v                |
|                                  +-------------------+      |
|                                  |   Veggie (VRF)    |      |
|                                  +-------------------+      |
+-------------------------------------------------------------+
```

---

## 2. Microarchitecture

### 2.1 Storage & Interconnect
The Transpose Unit consists of:
- **32 SRAM Banks**: Each bank is 32 words deep with 16-bit word width (`ELEM_BITS = 16`). Total on-chip storage: 1024 elements (2 KB).
- **$32 \times 32$ 3-Stage Clos Network**: Bidirectional non-blocking permutation crossbar constructed using $4 \times 4$ parameterized switches (`param_switch.sv` and `clos.sv`). The Clos network performs cyclic shifts during both write (push) and read (pop) phases to ensure conflict-free diagonal bank mapping.

### 2.2 Operation Phases
1. **Push Phase (Matrix Ingestion)**:
   - Receives 32 row vectors from Scratchpad via VLSU.
   - For row $r \in [0, 31]$, elements are rotated by $(i + r) \pmod{32}$ through the Clos network and written to SRAM bank $i$ at address $r$.
   - Pipeline latency per vector: 3 cycles (2 cycles Clos propagation + 1 cycle SRAM write trigger).
   - Total push time: $32 \times 3 = 96$ clock cycles.

2. **Pop Phase (Transposed Extraction)**:
   - Reads 32 column vectors out of SRAM.
   - For column $c \in [0, 31]$, banks are addressed with $(b + (32 - c)) \pmod{32}$ and unscrambled through the Clos network with inverse shift.
   - Pipeline latency per vector: 3 cycles (1 cycle SRAM read + 2 cycles Clos propagation).
   - Total pop time: $32 \times 3 = 96$ clock cycles.
   - Outputs stream directly into the VRF writeback port with zero bubble between vectors when `wb_ready` is asserted.

---

## 3. Level 2 (L2) Integration

### 3.1 Port Placement & Area Tradeoff
The Transpose Unit is instantiated exclusively on **VLSU Port 0** (`HAS_TRANSPOSE = (IDX == 0)`). 
- **Rationale**: Instantiating 32 SRAM banks and 3-stage Clos switches on all 4 VLSU ports would incur $4 \times 33,874\,\mu\text{m}^2 \approx 135,496\,\mu\text{m}^2$ of silicon area. Dedicating Port 0 provides full transpose acceleration while conserving area and routing congestion.
- Non-transpose loads on Port 0 and all requests on Ports 1, 2, 3 operate via the zero-overhead bypass and skid-buffer datapath.

### 3.2 ISA & Instruction Encoding
In the Atalla ISA, transposition is not an isolated compute instruction; instead, it is an architectural attribute of vector memory loads:
- **Vector Types (`vector_types.vh`)**: `rv_mtype_t` bit 54 defines `logic transpose; // 0 = row, 1 = column`.
- **VLSU Schedule Request (`vlsu_sched_req_t`)**: Field `logic transpose` passes this configuration from the scheduler to the VLSU.
- **Execution**: When `transpose == 1`, VLSU Port 0 captures the incoming scratchpad read stream into the Transpose Unit. Once 32 rows are loaded, the Transpose Unit streams 32 transposed columns into VRF registers `vdst, vdst+1, ..., vdst+31`.

### 3.3 Scratchpad & VLSU Handshake Protocol
- **Ingestion Stalling**: If scratchpad data arrives faster than the 3-cycle Clos/SRAM ingestion latency, VLSU asserts `sif.fe_vec_res_stall[0]` (`tu_stall_scpad`), safely backpressuring the scratchpad FIFO.
- **Writeback Priority**: Transpose Unit writeback takes priority over standard bypass and skid buffers, guaranteeing uninterrupted delivery of complete matrices into the VRF.

---

## 4. Performance Monitoring & Hardware Counters

The L2 performance monitor (`tb/unit/vector/perf_monitor.sv`) tracks dedicated hardware telemetry exposed via `vif.vlsu_out.status[0]`:

| Metric | Source Signal | Description |
| :--- | :--- | :--- |
| **`transpose_active_cycles`** | `status[0].transpose_active` | Cycles Transpose Unit is actively pushing, popping, or buffering |
| **`transpose_idle_cycles`** | `!status[0].transpose_active` | Cycles Transpose Unit is quiescent |
| **`transpose_push_count`** | `status[0].transpose_push` | Total number of row vectors pushed into Transpose Unit |
| **`transpose_pop_count`** | `status[0].transpose_pop` | Total number of transposed column vectors written back to VRF |
| **`transpose_matrix_count`** | `status[0].transpose_done` | Total complete $32 \times 32$ matrices transposed |
| **`transpose_sa_overlap_cycles`**| `transpose_active && sa_active`| Cycles where Transpose Unit operates concurrently with Systolic Array |

---

## 5. Verification & Regression

### 5.1 Standalone Unit Verification
- Located at [`tb/unit/vector/transpose_unit_tb.sv`](file:///C:/Users/tarak/Documents/Atalla/atalla/tb/unit/vector/transpose_unit_tb.sv).
- Tests arbitrary matrix dimensions from $1 \times 32$ up to $32 \times 32$.
- Features randomized backpressure on `ready_out` with zero data corruption.
- Synthesized and timing-clean at 600 MHz in Cadence Genus.

### 5.2 L2 Integration Test (`TEST_TRANSPOSE`)
- Located at [`tb/unit/vector/vector_core_L2_tb.sv`](file:///C:/Users/tarak/Documents/Atalla/atalla/tb/unit/vector/vector_core_L2_tb.sv) using assembly test [`tb/formal/vector/testcases/load-store/transpose_l2`](file:///C:/Users/tarak/Documents/Atalla/atalla/tb/formal/vector/testcases/load-store/transpose_l2).
- Preloads a $32 \times 32$ matrix (`data[r][c] = (r << 8) | c`) in vector registers `v0..v31`.
- Executes 32 `vreg.st` stores to scratchpad address `0x0000`.
- Executes 32 `vreg.ld` loads with `transpose = 1` through VLSU Port 0 into destination base register `v64`.
- End-to-end scoreboard verifies all 1024 elements across `v64..v95`:
  $$\text{VRF}[64 + c][r] == (r \ll 8) \mid c$$
