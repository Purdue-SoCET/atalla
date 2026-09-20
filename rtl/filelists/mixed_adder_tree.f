// Include directories
+incdir+./rtl/include/systolic_array
+incdir+./rtl/include/vector

./rtl/include/vector/vector_pkg.vh
./rtl/include/systolic_array/sys_arr_pkg.vh

./rtl/modules/systolic_array/left_shift.sv
./rtl/modules/systolic_array/arithmetic/add_fp16_1c.sv
./rtl/modules/systolic_array/arithmetic/sysarr_4_input_fp_adder_no_if.sv
./rtl/modules/systolic_array/arithmetic/add_fp16_4_input_no_if.sv

./rtl/modules/systolic_array/mixed_pipelined_adder_tree.sv