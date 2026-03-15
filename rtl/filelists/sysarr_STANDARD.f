// Include directories
+incdir+./rtl/include/systolic_array
+incdir+./rtl/include/vector

// Packages & interfaces (order matters)
./rtl/include/vector/vector_pkg.vh
./rtl/include/systolic_array/sys_arr_pkg.vh
./rtl/include/systolic_array/systolic_array_MAC_if.vh
./rtl/include/vector/gsau_control_unit_if.vh

// Leaf arithmetic modules
./rtl/modules/common/general/ha.sv
./rtl/modules/common/general/fa.sv
./rtl/modules/common/general/adder_5b.sv
./rtl/modules/systolic_array/left_shift.sv
./rtl/modules/common/general/wtm_bf.sv
./rtl/modules/systolic_array/arithmetic/reducer.sv

// Multipliers (latched + combinational for MAC_LATENCY 4 and 2)
./rtl/modules/systolic_array/arithmetic/mul_bf.sv
./rtl/modules/systolic_array/arithmetic/mul_bf_nolatch.sv

// Adders (latched + combinational for MAC_LATENCY 4 and 2)
./rtl/modules/systolic_array/arithmetic/add_fp16.sv
./rtl/modules/systolic_array/arithmetic/add_fp16_nolatch.sv

// Memory
./rtl/modules/common/memory/sram_bank.sv

// STANDARD modules
./rtl/modules/systolic_array/STANDARD/sysarr_MAC_bf.sv
./rtl/modules/systolic_array/STANDARD/sysarr_buffer.sv
./rtl/modules/systolic_array/STANDARD/sysarr_control_unit.sv
./rtl/modules/systolic_array/STANDARD/mac_grid.sv
./rtl/modules/systolic_array/skew_buffer.sv
./rtl/modules/systolic_array/STANDARD/sysarr_STANDARD.sv

// Testbench package
./tb/unit/systolic_array/systolic_array_tb_pkg.sv
