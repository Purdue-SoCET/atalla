VLOG = vlog
VSIM = vsim
VLIB = vlib
VMAP = vmap

INC = +incdir+../../rtl/include/systolic_array \
      +incdir+../../rtl/include/vector \
      +incdir+../../rtl/include/memory/scratchpad \
      +incdir+.

TOP = tb_top
LIB ?= work

# usage: make compile FILE=filename.sv LIB=work_j
compile:
	@if [ -z "$(FILE)" ]; then \
		echo "Usage: make compile FILE=<file> [LIB=<library>]"; \
		exit 1; \
	fi
	@if [ ! -d "$(LIB)" ]; then \
		$(VLIB) $(LIB); \
	fi
	$(VLOG) -work $(LIB) -sv $(INC) $(FILE)

# List of files for full testbench compile
FILES = \
	../../rtl/include/memory/scratchpad/scpad_pkg.sv \
	../../rtl/include/vector/vector_pkg.vh \
	../../rtl/include/systolic_array/sys_arr_pkg.vh \
	../../rtl/include/systolic_array/systolic_array_MAC_if.vh \
	../../rtl/include/vector/gsau_control_unit_if.vh \
	../../rtl/modules/systolic_array/left_shift.sv \
	../../rtl/modules/systolic_array/arithmetic/reducer.sv \
	../../rtl/modules/systolic_array/arithmetic/mul_bf.sv \
	../../rtl/modules/systolic_array/arithmetic/mul_bf_nolatch.sv \
	../../rtl/modules/systolic_array/arithmetic/add_fp16.sv \
	../../rtl/modules/systolic_array/arithmetic/add_fp16_nolatch.sv \
	../../rtl/modules/common/memory/sram_bank.sv \
	../../rtl/modules/systolic_array/STANDARD/sysarr_MAC_bf.sv \
	../../rtl/modules/systolic_array/STANDARD/sysarr_buffer.sv \
	../../rtl/modules/systolic_array/STANDARD/sysarr_control_unit.sv \
	../../rtl/modules/systolic_array/STANDARD/mac_grid.sv \
	../../rtl/modules/systolic_array/skew_buffer.sv \
	../../rtl/modules/systolic_array/STANDARD/sysarr_STANDARD.sv \
	systolic_array_tb_if.svh \
	systolic_array_tb_pkg.sv \
	predictor.c \
	tb_top.sv

# Full compile
# usage: make compile_all LIB=work_j
compile_all:
	@if [ ! -d "$(LIB)" ]; then \
		$(VLIB) $(LIB); \
	fi
	$(VLOG) -work $(LIB) -sv -ccflags "-msse3" $(INC) $(FILES)

# usage: make run LIB=work_j
run:
	@rm -rf $(LIB)
	$(MAKE) compile_all LIB=$(LIB)
	$(VSIM) -c $(LIB).$(TOP) -do "run -all; quit"

# usage: make gui LIB=work_j
gui:
	@rm -rf $(LIB)
	$(MAKE) compile_all LIB=$(LIB)
	$(VSIM) -voptargs="+acc" $(LIB).$(TOP)
