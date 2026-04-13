# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vadder_4input_tree32_tb.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 1
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 1
# Tracing output mode?  0/1 (from --trace-fst/--trace-saif/--trace-vcd)
VM_TRACE = 1
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0
# Tracing output mode in SAIF format?  0/1 (from --trace-saif)
VM_TRACE_SAIF = 0
# Tracing output mode in VCD format?  0/1 (from --trace-vcd)
VM_TRACE_VCD = 1

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vadder_4input_tree32_tb \
	Vadder_4input_tree32_tb___024root__DepSet_h77d4a8f6__0 \
	Vadder_4input_tree32_tb___024root__DepSet_h64039a89__0 \
	Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3__DepSet_h1e38be87__0 \
	Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3__DepSet_h1e38be87__1 \
	Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3__DepSet_h3c1facf8__0 \
	Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1__DepSet_hd663f6a5__0 \
	Vadder_4input_tree32_tb__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vadder_4input_tree32_tb__ConstPool_0 \
	Vadder_4input_tree32_tb___024root__Slow \
	Vadder_4input_tree32_tb___024root__DepSet_h77d4a8f6__0__Slow \
	Vadder_4input_tree32_tb___024root__DepSet_h64039a89__0__Slow \
	Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3__Slow \
	Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3__DepSet_h1e38be87__0__Slow \
	Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3__DepSet_h1e38be87__1__Slow \
	Vadder_4input_tree32_tb_sysarr_4_input_fp_adder__pi3__DepSet_h3c1facf8__0__Slow \
	Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1__Slow \
	Vadder_4input_tree32_tb_systolic_array_4_input_adder_if__pi1__DepSet_hd663f6a5__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Vadder_4input_tree32_tb__Trace__0 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vadder_4input_tree32_tb__Syms \
	Vadder_4input_tree32_tb__Trace__0__Slow \
	Vadder_4input_tree32_tb__TraceDecls__0__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_vcd_c \
	verilated_timing \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
