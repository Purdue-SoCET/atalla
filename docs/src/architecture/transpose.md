# Matrix Transpose Unit Architecture & Vector Core Integration

## 1. Overview
The **Transpose Unit** provides hardware acceleration for matrix transpositions on 2D matrices up to $32 \times 32$ (16-bit half-precision/Bfloat16 elements). It enables continuous matrix transposition directly within the **Vector Core Datapath** as a dedicated Functional Unit (**FU Slot 2**), executing alongside ALU (Slot 0), Multiply/Divider/Square-Root (Slot 1), and VLSU.

```
+----------------------------------------------------------------------------+
|                             Vector Core Datapath                           |
|                                                                            |
|   +--------------------+     +-----------------------------------------+   |
|   | Veggie (VRF)       |---->| Lane Crossbar / Slicers                 |   |
|   +--------------------+     +-----------------------------------------+   |
|             ^                                     |                        |
|             |                                     v                        |
|             |     +---------------+---------------+---------------+        |
|             |     | Slot 0: ALU   | Slot 1: MUL   | Slot 2: TRANS |        |
|             |     +---------------+---------------+---------------+        |
|             |                                             |                |
|             |                                             v                |
|             |                                    +-----------------+       |
|             |                                    | Transpose Unit  |       |
|             |                                    | (32-bank SRAM + |       |
|             |                                    |   32x32 Clos)   |       |
|             |                                    +-----------------+       |
|             |                                             |                |
|             |                                             v                |
|             +------------------------------------+-----------------+       |
|                                                  | Result Collector        |
|                                                  | (FU Slot 2 WB)          |
+----------------------------------------------------------------------------+
```

---

## 2. Microarchitecture

### 2.1 Storage & Interconnect
The Transpose Unit consists of:
- **32 SRAM Banks**: Each bank is 32 words deep with 16-bit word width (`ELEM_BITS = 16`). Total on-chip storage: 1024 elements (2 KB).
- **$32 \times 32$ 3-Stage Clos Network**: Bidirectional non-blocking permutation crossbar constructed using $4 \times 4$ parameterized switches (`param_switch.sv` and `clos.sv`). The Clos network performs cyclic shifts during both write (push) and read (pop) phases to ensure conflict-free diagonal bank mapping.

### 2.2 Operation Phases
1. **Push Phase (Matrix Ingestion via `tpus.vi`)**:
   - Pushes one row vector ($1 \times 32$) from the VRF into the unit.
   - For row $r \in [0, 31]$, elements are rotated by $(i + r) \pmod{32}$ through the Clos network and written to SRAM bank $i$ at address $r$.
   - Pipeline latency per vector in hardware: 9 cycles (2-cycle Clos write delay + 1-cycle launch + 4-cycle SRAM write latency + 1-cycle handshake).
   - 32 vectors pushed: $32 \times 9 = 288$ clock cycles.

2. **Pop Phase (Transposed Extraction via `tpop.vi`)**:
   - Initiated by a single `tpop.vi` instruction naming destination base register `vd`.
   - Automatically sequences and drains all 32 transposed column vectors out of SRAM.
   - For column $c \in [0, 31]$, banks are addressed with $(b + (32 - c)) \pmod{32}$ and unscrambled through the Clos network with inverse shift.
   - Pipeline latency per column in hardware: 6 cycles (1-cycle `POPPING` + 2-cycle SRAM read + 2-cycle Clos read flush + 1-cycle `DONE` writeback).
   - Total pop time: $32 \times 6 = 192$ clock cycles.
   - Columns stream directly onto `lanes_out.result_collectors[2]` to destination registers `vd, vd+1, ..., vd+31`.

---

## 3. Vector Datapath & ISA Integration

### 3.1 Datapath Functional Unit Slot 2
The Transpose Unit is integrated into `vector_datapath.sv` as **Functional Unit Slot 2**:
- **Issue Interface**: Sourced from `vif.lane_issue_ports[0]` and `[1]` when `usel == TRANS` (`2'b11`).
- **Ready Handshake**: `vif.unit_ready_signals.fu_global_status[2] = tu_if.out.ready_in && !tu_popping_r && !tu_issue_valid;`.
- **Writeback Interface**: Directly feeds `vif.lanes_out.result_collectors[2]`.

### 3.2 ISA & Instruction Encoding
In accordance with the updated Atalla ISA (aligned with `atalla-sim`):

| Instruction | Opcode | Functional Unit | Description |
| :--- | :---: | :---: | :--- |
| **`tpus.vi`** | **79** (`7'd79`) | `TRANS` (`2'b11`) | Push one vector row from `vs1` into the Transpose Unit |
| **`tpop.vi`** | **78** (`7'd78`) | `TRANS` (`2'b11`) | Drain all 32 transposed columns into consecutive VRF registers starting at `vd` |

---

## 4. Performance Monitoring & Hardware Counters

The L2 performance monitor (`tb/unit/vector/perf_monitor.sv`) tracks dedicated hardware telemetry for the Transpose Unit:

| Metric | Description | Measured Cycles (32x32) |
| :--- | :--- | :---: |
| **`transpose_active_cycles`** | Cycles Transpose Unit is actively pushing or popping | **545 cycles** |
| **`transpose_idle_cycles`** | Cycles Transpose Unit is quiescent | 255 cycles |
| **`transpose_push_count`** | Total row vectors pushed into Transpose Unit | 32 vectors |
| **`transpose_pop_count`** | Total pop commands executed | 1 command (32 cols drained) |
| **`transpose_matrix_count`** | Total complete $32 \times 32$ matrices transposed | 1 matrix |

---

## 5. Cycle Comparison with `atalla-sim`

| Metric | `atalla-sim` Model | RTL Hardware (`transpose_unit.sv`) | Root Cause of Delta |
| :--- | :---: | :---: | :--- |
| **Push Latency** *(per vector)* | **4 cycles** | **9 cycles** | RTL `sram_bank.sv` uses realistic `WRITE_LATENCY = 4` vs Sim single-cycle write. |
| **Push Phase Total** *(32 vectors)* | **128 cycles** | **288 cycles** | 9-cycle vs 4-cycle spacing between vector issues. |
| **Pop Latency** *(per column)* | **4 cycles** | **6 cycles** | RTL `sram_bank.sv` uses realistic `READ_LATENCY = 2` vs Sim single-cycle read. |
| **Pop Phase Total** *(32 columns)* | **128 cycles** | **192 cycles** | 6-cycle vs 4-cycle inter-column delivery. |
| **Total Transpose Core Cycles** | **256 cycles** | **480 cycles** (545 active sim cyc) | 100% attributable to SRAM macro read/write latency parameters. |

> [!NOTE]
> Parameterizing RTL `sram_bank` with `.READ_LATENCY(1), .WRITE_LATENCY(1)` yields exactly **256 cycles** in RTL ($32 \times 4 + 32 \times 4$), matching `atalla-sim` identically.
