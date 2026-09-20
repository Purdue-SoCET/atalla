## Overview 

Verification happens in two steps: 
1. Unit Tests for individual modules in SystemVerilog w/ QuestaSim. Ensure you apply assertions and performance counters! 
2. Top Level C++ tests w/ Verilator. This must be a more complete testbench, simulating real-workload situations. 

All your code must go in [./tb/](../tb/). 
- [./tb/formal](../tb/formal) must contain all the mathematical assertions w/ covergroups.  
- [./tb/unit](../tb/unit) must contain all the unit tests in the same heirarchy. Use `make sv_test folder= tb_file= GUI=` to run QuestaSim. Check the Makefile for options. 
- [./tb/uvm](../tb/uvm) is a maybe for now. 
- [./tb/verilator](../tb/verilator) will contain your actual C++ code. Use `make vl_test folder= tb_file=` to run it with Verilator. Check the Makefile for options.  