// Verilator configuration for systolic_array_top testbench
// Usage: verilator -f verilator_top.f --binary
// Then run: ./obj_dir/Vsystolic_array_top_tb

--top-module systolic_array_top_tb

// RTL files - systolic array top module
rtl/modules/systolic_array/systolic_array_top.sv
rtl/modules/systolic_array/sysarr_control_unit.sv
rtl/modules/systolic_array/sysarr_MAC_fp16_2c.sv
rtl/modules/systolic_array/sysarr_add.sv
rtl/modules/systolic_array/sysarr_OUT_FIFO.sv

// Supporting modules for the 2-cycle MAC
rtl/modules/systolic_array/mul_fp16_nolatch.sv
rtl/modules/systolic_array/add_fp16_1c.sv
rtl/modules/systolic_array/left_shift.sv

// Testbench
tb/unit/systolic_array/systolic_array_top_tb.sv

// Include directories
+incdir+rtl/include/
+incdir+rtl/include/systolic_array/
+incdir+rtl/modules/systolic_array/

// Warnings
--Wall
--assert

// Waveform tracing
--trace
--trace-fst
--trace-underscore
