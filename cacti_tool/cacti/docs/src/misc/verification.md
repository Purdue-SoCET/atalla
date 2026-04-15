## Overview 

Verification happens in three steps: 
1. Smoke Tests for all modules in SystemVerilog w/ QuestaSim. 
1. Unit Tests for individual modules in SystemVerilog w/ QuestaSim. Ensure you apply assertions and performance counters! The goal 
2. Top Level C++ tests w/ Verilator. This must be a more complete testbench, simulating real-workload situations. 


All your code must go in [./tb/](../tb/). 
- [./tb/formal](../tb/formal) must contain all the mathematical assertions w/ covergroups.  
- [./tb/unit](../tb/unit) must contain all the unit tests in the same heirarchy. Use `make sv_test folder= tb_file= GUI=` to run QuestaSim. Check the Makefile for options. 
- [./tb/uvm](../tb/uvm) is a maybe for now. 
