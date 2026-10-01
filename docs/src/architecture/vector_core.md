# Vector Core Architecture

## 1. Overview
The **Atalla Vector Core** is a high-throughput SIMD datapath designed for dense linear algebra, nonlinear activation functions, element-wise arithmetic, and reduction operations in deep learning workloads. It interfaces directly with:
- The **Systolic Array** (GSAU) for matrix multiplications ($\text{GEMM}$).
- The **Scratchpad Memory Subsystem** via a 4-port Vector Load-Store Unit (VLSU).
- The **Scheduler** and **Vector Register File** (VRF, internally modeled as Veggie).

```
                      +-----------------------------+
                      |          Scheduler          |
                      +-----------------------------+
                         |           |           |
            Issue Ports  |           |           |  VLSU Reqs
                         v           |           v
                  +-------------+    |    +-------------+
                  | Vector FUs  |    |    |    VLSU     |
                  |  - ALU 0/1  |    |    | (4 Ports)   |
                  |  - MUL 0/1  |    |    |   Port 0:   |
                  |  - Reducer  |    |    | [Transpose] |
                  +-------------+    |    +-------------+
                         |           |           |
            Writeback    |     GSAU  |           | Load / Transposed
            Collector    v     Ports v           v Writeback
                  +-------------------------------------+
                  |         Vector Register File        |
                  +-------------------------------------+
```

---

## 2. Functional Units & Execution Lanes

### 2.1 Arithmetic Units
The core contains multiple pipelined execution units operating on 32-element vectors of 16-bit data:
- **Vector ALU (VALU)**: Supports vector-vector (`.vv`), vector-immediate (`.vi`), and vector-scalar (`.vs`) integer and floating-point addition, subtraction, bitwise logic, and comparisons.
- **Vector Multiplier (VMUL)**: High-speed pipelined multipliers for vector scaling and Hadamard products.
- **Vector Reduction Unit**: Computes tree-based parallel reductions across 32 elements:
  - `RSUM`: Vector summation
  - `RMIN`: Minimum element selection
  - `RMAX`: Maximum element selection

### 2.2 Vector Load-Store Unit (VLSU)
The VLSU bridges the Vector Core and the on-chip Scratchpad memory across `NUM_SCPADS = 4` parallel channels:
- **Multi-Port Access**: Supports up to 4 concurrent read/write transactions per cycle to independent scratchpad banks.
- **Skid Buffering**: Decouples writeback backpressure from scratchpad response timing, avoiding pipeline deadlocks.
- **Port 0 Matrix Transpose Unit**: Port 0 integrates a hardware matrix transpose engine capable of transposing up to $32 \times 32$ matrices in-line between the Scratchpad and the VRF without processor intervention.

---

## 3. Matrix Transpose Subsystem
For detailed microarchitecture and verification details, see [Transpose Unit Architecture](./transpose.md).

- **Location**: VLSU Channel 0.
- **Capacity**: 32 vectors of 32 16-bit elements (2 KB internal storage across 32 SRAM banks).
- **Interconnect**: 3-stage $32 \times 32$ non-blocking Clos permutation network.
- **Activation**: Enabled via the ISA `transpose` flag in vector memory load operations (`rv_mtype_t[54]`).
- **Telemetry**: Hardware activity, push/pop metrics, and systolic array overlap are reported in real time by the L2 performance monitor (`tb/unit/vector/perf_monitor.sv`).
