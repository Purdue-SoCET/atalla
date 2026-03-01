// Include directories
+incdir+./rtl/include/systolic_array
+incdir+./rtl/include/vector

// Packages & interfaces (order matters)
./rtl/include/vector/vector_pkg.vh
./rtl/include/systolic_array/sys_arr_pkg.vh
./rtl/include/systolic_array/systolic_array_MAC_if.vh
./rtl/include/vector/gsau_control_unit_if.vh

// Leaf modules
./rtl/modules/common/general/ha.sv
./rtl/modules/common/general/fa.sv
./rtl/modules/common/general/adder_5b.sv
./rtl/modules/systolic_array/left_shift.sv

// Intermediate modules
./rtl/modules/common/general/wallacetree_11b_2c.sv
./rtl/modules/systolic_array/arithmetic/mul_fp16.sv
./rtl/modules/systolic_array/arithmetic/add_fp16.sv
./rtl/modules/common/memory/sram_bank.sv

// High-level modules
./rtl/modules/systolic_array/mul_grid.sv
./rtl/modules/systolic_array/pipelined_adder_tree.sv
./rtl/modules/systolic_array/skew_buffer.sv

// Top
./rtl/modules/systolic_array/sysarr_MEISSA_top.sv
./tb/unit/systolic_array/systolic_array_tb_pkg.sv
