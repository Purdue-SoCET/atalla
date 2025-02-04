# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vsysarr_OUT_FIFO.mk for the caller.

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
VM_TRACE = 0
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vsysarr_OUT_FIFO \
	Vsysarr_OUT_FIFO___024root__DepSet_h45cbc159__0 \
	Vsysarr_OUT_FIFO___024root__DepSet_h65aa067f__0 \
	Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if__DepSet_h901721cd__0 \
	Vsysarr_OUT_FIFO__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vsysarr_OUT_FIFO___024root__Slow \
	Vsysarr_OUT_FIFO___024root__DepSet_h45cbc159__0__Slow \
	Vsysarr_OUT_FIFO___024root__DepSet_h65aa067f__0__Slow \
	Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if__Slow \
	Vsysarr_OUT_FIFO_systolic_array_OUT_FIFO_if__DepSet_h901721cd__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vsysarr_OUT_FIFO__Syms \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_timing \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
