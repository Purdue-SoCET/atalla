# Direct Programming Interface‑C (DPI‑C)

## Overview

The SystemVerilog Direct Programming Interface (DPI) provides a standard way to call C functions from SystemVerilog and to call SystemVerilog functions from C. The DPI forms a bridge between the two languages and allows re‑use of existing C/C++ models or libraries.

This guide walks through two complementary flows that combine DPI‑C and a parameterizable asynchronous FIFO. The first flow uses Verilator to convert a SystemVerilog FIFO into C++ and writes a C++ testbench. The second flow implements the FIFO in C++ and imports it into a SystemVerilog testbench via DPI‑C, targeting Siemens Questa SIM.

## Sources 
* [SV DPI Tutorial](https://www.doulos.com/knowhow/systemverilog/systemverilog-tutorials/systemverilog-dpi-tutorial/)
* [Async FIFO RTL](https://www.verilogpro.com/asynchronous-fifo-design)
* [Running Verilator](https://verilator.org/guide/latest/verilating.html)
* [How to call C-functions from SV using DPI-C](https://www.consulting.amiq.com/2019/01/30/how-to-call-c-functions-from-systemverilog-using-dpi-c/)
* [How to call SV-modules from C++ using DPI-C](https://www.elektroda.com/qa,questasim-systemverilog-dpi-c-c-function.html)

## Flow 1 -- Verilating the SystemVerilog FIFO and Creating a C++ Testbench

#### a. Convert SystemVerilog to C++ with Verilator

Copy over [async_fifo.sv](#fifo-rtl) into your local directory.

1. Invoke Verilator:

```
verilator --cc async_fifo.sv --exe fifo_tb.cpp -CFLAGS "-std=c++17" --build
```

* --cc tells Verilator to generate C++ output.
* --exe fifo_tb.cpp requests Verilator to compile the provided C++ testbench and link it with the generated model.
* --build invokes make to build the executable.

2. Run the compiled simulation:

```
./obj_dir/Vasync_fifo
```

Verilator will generate a directory (default obj_dir) containing C++ files for the design. The included fifo_tb.cpp drives the async_fifo model by toggling independent write and read clocks, writing a sequence of values, and reading them back. The testbench checks for ordering errors and prints “FIFO test passed” when successful. See the file fifo_tb.cpp for details.

#### b. Writing a C++ Testbench

The C++ testbench uses the Verilated model interface. After including Vasync_fifo.h and initializing reset signals, it toggles wclk and rclk at different rates to emulate independent clock domains. It drives w_en and r_en, monitors the w_full/r_empty flags and verifies correct FIFO operation. 

Refer to [fifo_tb.cpp](#fifo-tb-in-c).

Verilator’s generated wrapper class provides the public signals as C++ members. Remember to call top->eval() after changing inputs; this schedules and evaluates the model for the current timestep.


## Flow 2 – Importing a C++ FIFO into a SystemVerilog Testbench via DPI‑C

#### a. Implement the FIFO in C++ and Expose it via DPI

Implementing a FIFO in C++ gives flexibility and allows using existing algorithmic models as golden references. The DPI‑C interface maps SystemVerilog types to C types; for example, byte maps to char and int maps to int. More complex types (arrays, 4‑state logic) require DPI‑defined types in svdpi.h. Arguments can be passed by value or reference depending on the argument direction.

The provided file [dpi_fifo.cpp](#fifo-c) implements a simple power‑of‑two FIFO in C++. It defines a DpiFifo structure with depth, write and read pointers and a dynamically allocated array. The exported functions have extern "C" linkage so the names are not mangled. Key functions are defined in the [dpi_hdr.h](#fifo-c-header).

```cpp
// Allocate a FIFO with at least the requested depth (rounded up to a power of two)
DpiFifo* fifo_init(int depth);
// Free the FIFO
void fifo_free(DpiFifo* fifo);
// Return non‑zero if FIFO is full
int fifo_full(const DpiFifo* fifo);
// Return non‑zero if FIFO is empty
int fifo_empty(const DpiFifo* fifo);
// Push/pop an integer; return 1 on success, 0 on full/empty
int fifo_push(DpiFifo* fifo, int data);
int fifo_pop(DpiFifo* fifo, int* data);
```

#### b. Import the C++ Functions into SystemVerilog

In the SystemVerilog testbench ([sv_tb_dpi.sv](#fifo-tb-in-sv)) we declare the C functions using import "DPI-C". The chandle type represents an opaque C pointer. The testbench allocates the FIFO, pushes a sequence of integers, pops them back and checks the order:

```cpp
module tb;
    import "DPI-C" function chandle fifo_init(input int depth);
    import "DPI-C" function void    fifo_free(input chandle handle);
    import "DPI-C" function int     fifo_push(input chandle handle, input int data);
    import "DPI-C" function int     fifo_pop(input chandle handle, output int data);
    import "DPI-C" function int     fifo_full(input chandle handle);
    import "DPI-C" function int     fifo_empty(input chandle handle);
    // … allocate and use FIFO …
endmodule
```

#### c. Compile and Run with Questa SIM

Siemens’ Questa SIM automatically compiles and links DPI‑C code when using the vlog -dpiheader option. The Elektroda article summarises the steps:

Write your C function and compile it into a position‑independent shared object (.so on Linux).

Declare the function in SystemVerilog using import "DPI-C" ….

Compile both C and SystemVerilog files together with vlog, then run the simulation and load the shared object with vsim -sv_lib.

```bash
vlib work
vlog -dpiheader dpi_hdr.h dpi_fifo.cpp sv_tb_dpi.sv
vsim -c work.tb -do "run -all; quit"
```

The -dpiheader switch instructs vlog to generate a header (dpi_hdr.h) that contains the prototypes of the imported functions. Questa automatically calls GCC to compile the C file and link the resulting shared library. Alternatively you can pre‑compile the C library manually:

```bash
gcc -fPIC -shared -I$MTI_HOME/include -o libdpi.so dpi_fifo.cpp
vlog sv_tb_dpi.sv
vsim work.tb -sv_lib libdpi
```

Be sure that the C library is compiled for the same word size as your simulator (32‑bit vs. 64‑bit); otherwise you will see linker errors. Also remember to include svdpi.h in your C file; without it the DPI data types are undefined.

## Appendix 

#### FIFO RTL  

Adapted from https://www.verilogpro.com/asynchronous-fifo-design/.

```sv
// async_fifo.sv
module async_fifo #(
    parameter int DATA_WIDTH = 8,
    parameter int ADDR_WIDTH = 4
) (
    input  logic               wclk,
    input  logic               wrst_n,
    input  logic               w_en,
    input  logic [DATA_WIDTH-1:0] wdata,
    output logic               w_full,
    input  logic               rclk,
    input  logic               rrst_n,
    input  logic               r_en,
    output logic [DATA_WIDTH-1:0] rdata,
    output logic               r_empty
);
    localparam int FIFO_DEPTH = 1 << ADDR_WIDTH;
    logic [DATA_WIDTH-1:0] mem [0:FIFO_DEPTH-1];
    logic [ADDR_WIDTH:0] wptr_bin, rptr_bin;
    logic [ADDR_WIDTH:0] wptr_gray, rptr_gray;
    logic [ADDR_WIDTH:0] wptr_gray_sync1, wptr_gray_sync2;
    logic [ADDR_WIDTH:0] rptr_gray_sync1, rptr_gray_sync2;

    // Write domain
    always_ff @(posedge wclk or negedge wrst_n) begin
        if (!wrst_n) begin
            wptr_bin  <= '0;
            wptr_gray <= '0;
        end else if (w_en && !w_full) begin
            mem[wptr_bin[ADDR_WIDTH-1:0]] <= wdata;
            wptr_bin  <= wptr_bin + 1;
            wptr_gray <= (wptr_bin + 1) >> 1 ^ (wptr_bin + 1); // binary→Gray
        end
    end

    // Read domain
    always_ff @(posedge rclk or negedge rrst_n) begin
        if (!rrst_n) begin
            rptr_bin  <= '0;
            rptr_gray <= '0;
        end else if (r_en && !r_empty) begin
            rptr_bin  <= rptr_bin + 1;
            rptr_gray <= (rptr_bin + 1) >> 1 ^ (rptr_bin + 1);
        end
    end

    // Data output; asynchronous read with registered output
    always_ff @(posedge rclk) begin
        rdata <= mem[rptr_bin[ADDR_WIDTH-1:0]];
    end

    // Synchronize Gray pointers across domains
    always_ff @(posedge wclk or negedge wrst_n) begin
        if (!wrst_n) begin
            rptr_gray_sync1 <= '0;
            rptr_gray_sync2 <= '0;
        end else begin
            rptr_gray_sync1 <= rptr_gray;
            rptr_gray_sync2 <= rptr_gray_sync1;
        end
    end
    always_ff @(posedge rclk or negedge rrst_n) begin
        if (!rrst_n) begin
            wptr_gray_sync1 <= '0;
            wptr_gray_sync2 <= '0;
        end else begin
            wptr_gray_sync1 <= wptr_gray;
            wptr_gray_sync2 <= wptr_gray_sync1;
        end
    end

    // Full and empty detection:contentReference[oaicite:8]{index=8}
    always_comb begin
        // Empty when synchronized write pointer equals local read pointer
        r_empty = (wptr_gray_sync2 == rptr_gray);
        // Full when MSBs differ and lower bits match
        w_full  = (wptr_gray[ADDR_WIDTH] != rptr_gray_sync2[ADDR_WIDTH]) &&
                  (wptr_gray[ADDR_WIDTH-1:0] == rptr_gray_sync2[ADDR_WIDTH-1:0]);
    end
endmodule
```

#### FIFO TB in C++
```cpp
// fifo_tb.cpp
// -----------------------------------------------------------------------------
// C++ testbench for async_fifo.sv when Verilated into C++.
//
// Build idea (typical):
//   verilator -Wall --cc async_fifo.sv --exe fifo_tb.cpp --top-module async_fifo
//   make -C obj_dir -f Vasync_fifo.mk
//   ./obj_dir/Vasync_fifo
//
// Verilator's guide describes translating SV to C++ with --cc and building an
// executable with --binary/--exe.citeturn583946675001164
// -----------------------------------------------------------------------------

#include <cstdint>
#include <deque>
#include <iostream>
#include <random>

#include "Vasync_fifo.h"
#include "verilated.h"

static vluint64_t main_time = 0;

static void tick(Vasync_fifo* top) {
    top->eval();
    main_time++;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    auto* top = new Vasync_fifo;

    // Simple async clocks: write clock toggles every cycle, read clock every 2
    top->wclk = 0;
    top->rclk = 0;
    top->wrst_n = 0;
    top->rrst_n = 0;
    top->w_en = 0;
    top->r_en = 0;
    top->w_data = 0;

    // apply reset
    for (int i = 0; i < 10; i++) {
        top->wclk = !top->wclk;
        if ((i % 2) == 0) top->rclk = !top->rclk;
        tick(top);
    }
    top->wrst_n = 1;
    top->rrst_n = 1;

    std::deque<uint32_t> scoreboard;
    std::mt19937 rng(1);
    std::uniform_int_distribution<int> coin(0, 1);

    const int N = 2000;
    for (int t = 0; t < N; t++) {
        // drive enables in their own domains
        bool do_write = (coin(rng) == 1);
        bool do_read  = (coin(rng) == 1);

        // Write domain on rising edge of wclk
        if (!top->wclk) {
            top->w_en = do_write;
            if (do_write) {
                uint32_t v = (uint32_t)t;
                top->w_data = v;
            }
        }

        // Read domain on rising edge of rclk
        if (!top->rclk) {
            top->r_en = do_read;
        }

        // toggle clocks
        top->wclk = !top->wclk;
        if ((t % 2) == 0) top->rclk = !top->rclk;

        tick(top);

        // Scoreboard updates after edges
        if (top->w_en && !top->w_full) {
            scoreboard.push_back(top->w_data);
        }
        if (top->r_en && !top->r_empty) {
            if (scoreboard.empty()) {
                std::cerr << "ERROR: DUT popped but scoreboard empty\n";
                return 2;
            }
            uint32_t exp = scoreboard.front();
            uint32_t got = top->r_data;
            scoreboard.pop_front();
            if (got != exp) {
                std::cerr << "ERROR: mismatch exp=" << exp << " got=" << got << "\n";
                return 3;
            }
        }
    }

    std::cout << "PASS\n";
    delete top;
    return 0;
}

```

#### FIFO C++ 
```cpp
// dpi_fifo.cpp
// -----------------------------------------------------------------------------
// C++ async FIFO model exposed through a C ABI for SystemVerilog DPI-C.
//
// This is the "C++ golden model -> SV testbench" flow.
// - SV holds a handle (chandle) to an allocated C++ object.
// - SV calls fifo_push/fifo_pop each cycle or transaction.
//
// DPI-C uses svdpi.h types and API; keeping types consistent matters because
// SV<->C data must be interpreted identically.citeturn818598791849910
// -----------------------------------------------------------------------------

#include <cstdint>
#include <cstdlib>
#include <new>
#include <vector>

extern "C" {
#include "svdpi.h"
}

struct FifoU32 {
    explicit FifoU32(int depth_pow2)
        : depth(depth_pow2), mem((size_t)depth_pow2, 0) {
        reset();
    }

    void reset() {
        wptr = 0;
        rptr = 0;
    }

    bool empty() const { return wptr == rptr; }

    bool full() const {
        int mask = depth - 1;
        return ((wptr & mask) == (rptr & mask)) && (((wptr ^ rptr) & depth) != 0);
    }

    bool push(uint32_t v) {
        if (full()) return false;
        mem[(size_t)(wptr & (depth - 1))] = v;
        wptr = (wptr + 1) & ((2 * depth) - 1);
        return true;
    }

    bool pop(uint32_t* out) {
        if (empty()) return false;
        *out = mem[(size_t)(rptr & (depth - 1))];
        rptr = (rptr + 1) & ((2 * depth) - 1);
        return true;
    }

    int depth;
    std::vector<uint32_t> mem;
    int wptr{0};
    int rptr{0};
};

extern "C" {

// Create a FIFO. depth must be power-of-2.
void* fifo_create(int depth) {
    try {
        return new FifoU32(depth);
    } catch (...) {
        return nullptr;
    }
}

void fifo_destroy(void* h) {
    delete static_cast<FifoU32*>(h);
}

void fifo_reset(void* h) {
    if (!h) return;
    static_cast<FifoU32*>(h)->reset();
}

// Returns 1 on success, 0 on full
int fifo_push_u32(void* h, unsigned int v) {
    if (!h) return 0;
    return static_cast<FifoU32*>(h)->push((uint32_t)v) ? 1 : 0;
}

// Returns 1 on success, 0 on empty
int fifo_pop_u32(void* h, unsigned int* out_v) {
    if (!h || !out_v) return 0;
    uint32_t tmp = 0;
    if (!static_cast<FifoU32*>(h)->pop(&tmp)) return 0;
    *out_v = (unsigned int)tmp;
    return 1;
}

int fifo_empty(void* h) {
    if (!h) return 1;
    return static_cast<FifoU32*>(h)->empty() ? 1 : 0;
}

int fifo_full(void* h) {
    if (!h) return 0;
    return static_cast<FifoU32*>(h)->full() ? 1 : 0;
}

} // extern "C"

```

#### FIFO C++ Header
```cpp
// cpp_async_fifo.h
// -----------------------------------------------------------------------------
// Simple parameterizable FIFO model in C++ (power-of-2 depth)
// Used as a pure C++ golden model *or* inside DPI wrappers.
// -----------------------------------------------------------------------------
#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

// Depth must be power-of-2.
template <typename T, std::size_t DEPTH>
class AsyncFifo {
    static_assert((DEPTH & (DEPTH - 1)) == 0, "DEPTH must be power-of-2");

public:
    AsyncFifo() { reset(); }

    void reset() {
        wptr_ = 0;
        rptr_ = 0;
    }

    bool empty() const { return wptr_ == rptr_; }

    bool full() const {
        // full when lower bits match but MSB differs
        const std::size_t mask = DEPTH - 1;
        return ((wptr_ & mask) == (rptr_ & mask)) && ((wptr_ ^ rptr_) & DEPTH);
    }

    bool push(const T& v) {
        if (full()) return false;
        mem_[wptr_ & (DEPTH - 1)] = v;
        wptr_ = (wptr_ + 1) & ((DEPTH * 2) - 1);
        return true;
    }

    bool pop(T& out) {
        if (empty()) return false;
        out = mem_[rptr_ & (DEPTH - 1)];
        rptr_ = (rptr_ + 1) & ((DEPTH * 2) - 1);
        return true;
    }

private:
    std::array<T, DEPTH> mem_{};
    // pointers carry one extra wrap bit -> range [0, 2*DEPTH)
    std::size_t wptr_{0};
    std::size_t rptr_{0};
};
```

#### FIFO TB in SV
```sv
// sv_tb_dpi.sv
// -----------------------------------------------------------------------------
// SystemVerilog testbench that imports a C++ FIFO model via DPI-C.
//
// Questa compile notes (one common flow):
// - Compile SV + C together with vlog and autolink
// - Or compile C into a shared library and load with vsim -sv_lib
// Example commands appear in many guides; one common pattern is:
//   vlog -dpiheader dpi_hdr.h dpi_func.c tb_top.sv
//   vsim -c work.tb_top -do "run -all; quit"citeturn115040724918351
// -----------------------------------------------------------------------------

module tb_dpi_fifo;

  import "DPI-C" function chandle fifo_create(input int depth);
  import "DPI-C" function void    fifo_destroy(input chandle h);
  import "DPI-C" function void    fifo_reset(input chandle h);
  import "DPI-C" function int     fifo_push_u32(input chandle h, input int unsigned v);
  import "DPI-C" function int     fifo_pop_u32 (input chandle h, output int unsigned v);
  import "DPI-C" function int     fifo_empty(input chandle h);
  import "DPI-C" function int     fifo_full (input chandle h);

  chandle h;
  int unsigned got;

  localparam int DEPTH = 16;

  initial begin
    h = fifo_create(DEPTH);
    if (h == null) $fatal(1, "fifo_create failed");

    fifo_reset(h);

    // push 0..DEPTH-1
    for (int i = 0; i < DEPTH; i++) begin
      if (!fifo_push_u32(h, i)) $fatal(1, "unexpected full at i=%0d", i);
    end
    if (!fifo_full(h)) $display("NOTE: fifo_full() did not assert; check full policy");

    // pop and check
    for (int i = 0; i < DEPTH; i++) begin
      if (!fifo_pop_u32(h, got)) $fatal(1, "unexpected empty at i=%0d", i);
      if (got !== i[31:0]) $fatal(1, "mismatch exp=%0d got=%0d", i, got);
    end
    if (!fifo_empty(h)) $display("NOTE: fifo_empty() did not assert; check empty policy");

    fifo_destroy(h);
    $display("PASS");
    $finish;
  end

endmodule

```