// Include directories
+incdir+./rtl/include/systolic_array
+incdir+./rtl/include/vector

// Packages & interfaces (order matters)
./rtl/include/vector/vector_pkg.vh
./rtl/include/systolic_array/sys_arr_pkg.vh
./rtl/include/systolic_array/systolic_array_MAC_if.vh
./rtl/include/vector/gsau_control_unit_if.vh

// Leaf arithmetic modules
./rtl/modules/common/general/adder_5b.sv

// Multiplier (combinational FP16)
./rtl/modules/systolic_array/arithmetic/mul_fp16_nolatch.sv

// Adder (combinational FP16)
./rtl/modules/systolic_array/arithmetic/add_fp16_nolatch.sv

// OLD modules
./rtl/modules/systolic_array/OLD/sysarr_input_buffer.sv
./rtl/modules/systolic_array/OLD/sysarr_MAC_fp16_2c.sv
./rtl/modules/systolic_array/OLD/systolic_array_simple.sv
