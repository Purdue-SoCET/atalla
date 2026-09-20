# Introduction to the Atallax01 Programming Model

The Atallax01 Programming Model allows users to map C/C++ algorithms to throughput-focused deep-learning accelerator, architected around VLIW vector-datapath, SW-managed Scratchpad and a 32x32 BF16 Systolic Array. 

Unlike GPUs, Atallax01 does not expose a wide SIMT/SIMD programming interface. Instead, it provides a tile-centric compute model where kernels explicitly optimize and orchestrate data movement, vector lane utilization and Systolic Array computations through a single unified instruction stream. The workloads that will be run on Atalla are highly regular and need both wide-and-deep pipelines specifically for two-dimensional matrices. 

Atallax01 is not a general-purpose processor. It is a core that will be placed alongside a high-performance CPU for a heterogenous compute plateform. Programmability is offered through C/C++ and a custom compiler toolchain. We do not plan to support imperative languages like Python. 

This document defines: 
- the hardware execution model 
- the memory heirarchy 
- the programming constructs available to the user
- tile-based psuedocode conventions

## Hardware Differences

CPUs are computing machines that were fine-tuned over decades to minimize the latency of single-threaded instruction streams. They rely heavily on advanced techniques like prediction, speculaton, dynamic scheduling, etc. SMT, a computing perspective that partitioned/allocated register-sets to time-mulitplex independent software threads, was added as an afterthought into a single CPU core to exploit even more instruction-level parallelism. 

However, the industry saw the need for different machines to exploit the data-level parallelism seen in scientific and graphics workloads. GPUs are massively-parallel computing machines, primarily programmed using CUDA or HIP paradigms which expose implicit-SIMD perspectives to the user. This enables the user to write scalar-threaded code in C++ which are compiled into SIMT binaries to utilize the SIMD execution units. CUDA inintially innovated by combining hardware-efficiency of SIMD but the programmability of SMT. 

In recent years, GPUs been adapted to cater to the demand of the deep learning ecosystem with the addition of Tensor Cores for matrix-multiplications. TPUs grew parallely, but were targeted purely for deep-learning workloads that were domainted by GEMMs/CONVs. Atallax01 targets these primitives directly and disregards the SIMT/SIMD abstractions. Users will write single-thread code in C/C++ that directly defines tile-based descriptors for memory movement and vector-based kernels for compute datapaths. Thus, we say Atallax01 behaves more like a TPU than a GPU. 

## Heterogenous Programming 

Atallax01 is programmed using a heterogenous host-device model, similar in spirit to CUDA/HIP but fundamentally simpler. 

Host responsibilities include: 
    - Allocate DRAM Tenstors. 
    - Launch device kernels. 
    - Pass tile descriptors and kernel metadata. 
Device responsibilities include: 
    - Move data between DRAM and on-chip SRAM. 
    - Swizzle data within the Scratchpad to enable row/coloumn-major addressing. 
    - Load slices of the tiles into vector registers. 
    - Execute blocking vector load/store/compute operations to prime the Systolic Array, or utilize the execution lanes. 

The compiler issues VLIW bundles into a mapped-space within the DRAM partition exposed to Atallax01. The on-chip scheduling unit enforces a tainted-VLIW scheme by checking dependencies through scoreboarding. 

## Memory Model

The Atallax01 memory system is software-managed, and does not enforce any hardware-managed ordering mechanisms. The datapath is in-order, with the SDMA instructions making SCPAD locations valid before later accesses take place.  

Global Memory (DRAM): 
    - Large, high latency
    - Only accessible via SDMA instructions. 
    - Ideal for storing large tensors. Assume 8GB+ space. 
Scratchpad Memory (SCPAD): 
    - 1MB SRAM on-chip memory, low latency. 
    - Only accessible via SDMA instructions. 
    - Two seperate partitions indexed as SCPAD0 and SCPAD1
Vector Register File (VEGGIE): 
    - [X-Size] SRAM vector-register-file
    - Only accessible via VM instructions.
    - Intermediate tile-slice storage to send to Lanes/Systolic-Array
Scalar Register File: 
    - [X-Size] SRAM lockup-free D-Cache
    - Implemented as a hardware-managed L1 Cache. 
Systolic Array Accumulation Buffers: 
    - Not programmable. Hardware-controlled. 
    - Strided/Staggered collection and tranfer of vectors into VEGGIE.

## Execution Model

VLIW-based execution. Each cycle, the scheduler may one of [X] Packet types. The compiler ensures intra-bundle independence, with inter-bundle dependencies handled by the Scoreboardds in the Scheduler Unit. 

In the following sections, we will focus on explaining the different "concepts" to keep in mind before developing code for Atallax01. Following this, we will discuss abstracted kernels which utilize these concepts.  

### Abstract Entities: 

```
TileDesc       - 2D block of memory Global/Scpad (described by shape + strides)


GlobalRegion   - Where in Global Memory
GlobalTile     – N-D tensor in off-chip DRAM, has-a Global Region

ScpadRegion    - Which Scratchpad and where inside the Scratchpad
ScpadTile      – 2D tensor in on-chip SRAM, has-a TileDesc and ScpadRegion

VectorReg[v]   – vector register(s) in the vector core
```

### Abstract Instrinsics: 

```
SDMA_LD_* ScpadTile, GlobalTile
SDMA_ST_* ScpadTile, GlobalTile
VM_LD VectorReg[v], ScpadTile
VM_ST VectorReg[v], ScpadTile
VV_* VectorReg[v], VectorReg[v]
VV_* VectorReg[v], Imm
VS_* VectorReg[v], ScalarReg[v]

GEMMV ScpadTile C, ScpadTile A, ScpadTile B
CONV ScpadTile C, ScpadTile A, ScpadTile B
```

## Kernels

### General Matrix-Multiply (GEMM)

Atallax01 does not expose 32x32 Systolic Array directly. Instead, we provide a fixed-shape sub-kernels that operate on tiles that satisfy [<= 32x32]. 

Let's define 
```
TM  – rows of the output tile   (TM ≤ 32)
TN  – cols of the output tile   (TN ≤ 32)
TK  – reduction dimension slice (TK ≤ 32)
```

A single GEMMV instrinsic consumes: 
```
A_tile  : TM × TK  (activations)
B_tile  : TK × TN  (weights)
C_tile  : TM × TN  (partial sums / output)
```

and computes: 
```
C_tile = A_tile · B_tile + C_tile
```

entirely inside the vector-core + systolic array microcode, blocking until SPCAD_C is updated. 

#### Tiling/Grouping

Given a standard GEMM of general dimensions
```
C[M × N] = A[M × K] · B[K × N]
```

we can decompose it into the following number of tiles:
```
MT = ceil(M / TM)   
NT = ceil(N / TN)  
KT = ceil(K / TK)   
```

Each output tile `C[i,j]` (for `0 ≤ i < MT`, `0 ≤ j < NT`) is defined as:

```text
C_tile(i,j) = C[ i*TM : (i+1)*TM,   j*TN : (j+1)*TN ]
A_tile(i,k) = A[ i*TM : (i+1)*TM,   k*TK : (k+1)*TK ]
B_tile(k,j) = B[ k*TK : (k+1)*TK,   j*TN : (j+1)*TN ]
```

All three of these tiles are loaded into on-chip SRAM as `ScpadTile`s before a `GEMMV` call.

Below, we define the tiling logic: 

```cpp
struct TileGroupDesc {
    GlobalTile A_g;   // TM x TK slice of A in DRAM
    GlobalTile B_g;   // TK x TN slice of B in DRAM
    GlobalTile C_g;   // TM x TN slice of C in DRAM 
    int i, j, k;      // tile indices (row, col, k reduction)
}

vector<TileGroupDesc> plan_gemmv(
    GlobalTile A, GlobalTile B, GlobalTile C,
    int M, int N, int K,
    int TM, int TN, int TK
) {
    vector<TileGroupDesc> groups;

    for (int i = 0; i < M; i += TM) {
      for (int j = 0; j < N; j += TN) {

        GlobalTile C_g = make_tile(C, i, j, TM, TN);

        for (int k = 0; k < K; k += TK) {

          GlobalTile A_g = make_tile(A, i, k, TM, TK);
          GlobalTile B_g = make_tile(B, k, j, TK, TN);

          groups.push_back(TileGroupDesc{.A_g = A_g, .B_g = B_g, .C_g = C_g, .i = i, j = j, .k = k});
        }
      }
    }

    return groups;
}

```

#### Execution Loop 

> Note: _alloc_scpad0, _alloc_scpad1 and _gemmv are functions defined in the stub library we provide with the E2E stack. It works at the vector-register level. 

```cpp
bool execute_gemmv(
    GlobalTile A, GlobalTile B, GlobalTile C,
    int M, int N, int K
) {
    const int TM = ...; // ≤ 32
    const int TN = ...; // ≤ 32
    const int TK = ...; // ≤ 32

    vector<TileGroupDesc> groups = plan_gemmv(A, B, C, M, N, K, TM, TN, TK);

    for each distinct (i, j) over output tiles {
        GlobalTile C_g = pop_group(i,j, groups).C_g;

        ScpadTile sc_C  = _alloc_scpad1(TM, TN);  
        SDMA_LD_1(sc_C, C_g);
        
        for each g in groups where (g.i == i and g.j == j) { 
            in order of g.k {

                // Using different register spaces within the Scratchpad allows the compiler 
                // to packetize to allow overlapping loads while compute happens.
                ScpadTile sc_A  = _alloc_scpad0(TM, TK);  
                ScpadTile sc_B  = _alloc_scpad1(TK, TN);  
                SDMA_LD_0(sc_A, g.A_g);
                SDMA_LD_1(sc_B, g.B_g);

                _gemmv(sc_C, sc_A, sc_B);
            }
        }

        SDMA_ST_1(sc_C, C_g);
    }
}
```
