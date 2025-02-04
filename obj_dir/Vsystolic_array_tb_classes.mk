# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vsystolic_array_tb.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 1
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 0
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 1
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 1

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vsystolic_array_tb \
	Vsystolic_array_tb___024root__DepSet_hdbe45c06__0 \
	Vsystolic_array_tb___024root__DepSet_h7c5333ca__0 \
	Vsystolic_array_tb_systolic_array_if__DepSet_h6d5a8c78__0 \
	Vsystolic_array_tb_systolic_array_control_unit_if__DepSet_h190b6bc7__0 \
	Vsystolic_array_tb_systolic_array_MAC_if__DepSet_h6d8269e0__0 \
	Vsystolic_array_tb_systolic_array_add_if__DepSet_h45933ba3__0 \
	Vsystolic_array_tb__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vsystolic_array_tb__ConstPool_0 \
	Vsystolic_array_tb___024root__Slow \
	Vsystolic_array_tb___024root__DepSet_hdbe45c06__0__Slow \
	Vsystolic_array_tb___024root__DepSet_h7c5333ca__0__Slow \
	Vsystolic_array_tb_systolic_array_if__Slow \
	Vsystolic_array_tb_systolic_array_if__DepSet_h6d5a8c78__0__Slow \
	Vsystolic_array_tb_systolic_array_control_unit_if__Slow \
	Vsystolic_array_tb_systolic_array_control_unit_if__DepSet_h190b6bc7__0__Slow \
	Vsystolic_array_tb_systolic_array_MAC_if__Slow \
	Vsystolic_array_tb_systolic_array_MAC_if__DepSet_h6d8269e0__0__Slow \
	Vsystolic_array_tb_systolic_array_add_if__Slow \
	Vsystolic_array_tb_systolic_array_add_if__DepSet_h45933ba3__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Vsystolic_array_tb__Trace__0 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vsystolic_array_tb__Syms \
	Vsystolic_array_tb__Trace__0__Slow \
	Vsystolic_array_tb__TraceDecls__0__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_fst_c \
	verilated_timing \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
