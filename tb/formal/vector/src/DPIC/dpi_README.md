
# DPI-C Instruction Parser for Vector Core L1 Integration


## Overview

Purpose of this is to bridge the scheduler C++ tb into SystemVerilog through DPI-C, so that we are able to test L1 Integration of the vector-core datapath RTL
using the same program functions and logic already in the C++ tb.

```
┌──────────────────────────────────────────────────────────────┐
│  Program File (text)                                         │
│  "add.vv,0,1,2,0,0|mul.vv,3,4,5,0,0|nop.s|nop.s"             │
└──────────────────────┬───────────────────────────────────────┘
                       │ dpi_scheduler_init()
                       v
┌──────────────────────────────────────────────────────────────┐
│  C++ Scheduler (schedular.cpp — YOUR EXISTING CODE)          │
│                                                              │
│  • parse_packet() → instruction queue                        │
│  • all_ready() check                                         │
│  • decode() → populate signal structs                        │
│  • deassert_valids() each cycle                              │
└──────────────────────┬───────────────────────────────────────┘
                       │ DPI-C function calls
                       v
┌──────────────────────────────────────────────────────────────┐
│  SV Testbench (vector_core_tb.sv)                            │
│                                                              │
│  Each posedge clk:                                           │
│    1. Sample DUT ready signals                               │
│    2. dpi_set_ready_signals(...)                             │
│    3. dpi_scheduler_tick(rst_n)                              │
│    4. dpi_get_lane_*(), dpi_get_sys_*(), etc.                │
│    5. Drive DUT input ports                                  │
│    6. Check dpi_get_all_issued() for completion              │
└──────────────────────┬───────────────────────────────────────┘
                       │ RTL port connections
                       v
┌──────────────────────────────────────────────────────────────┐
│  vector_datapath_wrapper (RTL DUT)                           │
│                                                              │
│  Lanes, Systolic Array, Scratchpad, VRF, Mask RF             │
│  Outputs ready signals back to testbench                     │
└──────────────────────────────────────────────────────────────┘
```

## How It Works

### Instruction Format (unchanged from C++ TB)

Each line in a program file is a **packet** of 4 instructions separated by `|`:

```
<lane_op_0>|<lane_op_1>|<sys_sp_op>|<sp_op>
```

Each instruction is comma-separated: `mnemonic,field1,field2,...`

**note: I'm p sure this changed for slot 3 to be Systolic Array and SP as well but not sure**

| Slot | Purpose | Valid opcodes |
|------|---------|---------------|
| 0 | Vector operation | add.vv, sub.vv, mul.vv, div.vv, addi.vi, etc. |
| 1 | Vector operation | Same as slot 0 |
| 2 | Systolic array / Scratchpad | gemm.vv, lw.vi, vreg.ld, vreg.st, nop.s |
| 3 | Scratchpad | vreg.ld, vreg.st, nop.s |


**Note: Still working on completing this, want to add how to use, the API, set-up, etc.**