VLOG = vlog
VSIM = vsim
VLIB = vlib
VMAP = vmap

#+incdir+tb/unit/vector/uvm_verifcation_teamF26 add this after getting original compile to work
INC = +incdir+UVM_1.2 +incdir+rtl/include/common/xbar +incdir+rtl/include/memory/scratchpad \
      +incdir+rtl/include/systolic_array +incdir+rtl/include/vector +incdir+rtl/include/vector/lane_FUs \
	  +incdir+rtl/include/vector/reduction \

TOP = vector_top
LIB ?= work

# usage: make compile FILE=filename.sv LIB=work_j
# compile a specific UVM file
compile:
	@if [ -z "$(FILE)" ]; then \
		echo "Usage: make compile FILE=<file> [LIB=<library>]"; \
		exit 1; \
	fi
	@if [ ! -d "$(LIB)" ]; then \
		$(VLIB) $(LIB); \
	fi
	$(VLOG) -work $(LIB) -sv $(INC) UVM_1.2/$(FILE)

# List of files for full testbench compile
FILES = \
	rtl/include/memory/scratchpad/scpad_params.svh \
	rtl/include/memory/scratchpad/scpad_pkg.sv \
	rtl/include/systolic_array/sys_arr_pkg.vh \
	rtl/include/vector/vector_pkg.vh \
	\
	rtl/include/memory/scratchpad/scpad_if.sv \
	rtl/include/vector/vlsu_if.sv \
	rtl/include/vector/gsau_control_unit_if.vh \
	rtl/include/vector/lane_sequencer_if.vh \
	rtl/include/vector/valu_if.vh \
	rtl/include/common/mul_if.vh \
	rtl/include/vector/lane_FUs/functional_unit_if.vh \
	rtl/include/vector/lane_if.vh \
	rtl/include/vector/result_collector_if.vh \
	rtl/include/vector/vreduction_alu_if.vh \
	rtl/include/vector/vreduction_if.vh \
	rtl/include/vector/lane_FUs/reduction_FU_if.vh \
	rtl/include/vector/vector_if.vh \
	\
	rtl/modules/systolic_array/left_shift_add_bf16.sv \
	rtl/modules/systolic_array/arithmetic/add_bf16.sv \
	rtl/modules/common/addsub_bf16.sv \
	rtl/modules/common/fa.sv \
	rtl/modules/common/ha.sv \
	rtl/modules/common/mul_bf16_fu.sv \
	rtl/modules/vector/sync_fifo.sv \
	rtl/modules/vector/lane_sequencer.sv \
	rtl/modules/vector/valu.sv \
	rtl/modules/vector/lane_FUs/alu_FU.sv \
	rtl/modules/vector/lane_FUs/mul_FU.sv \
	rtl/modules/vector/lane.sv \
	rtl/modules/vector/slicer.sv \
	rtl/modules/vector/result_collector_counter.sv \
	rtl/modules/vector/result_collector.sv \
	rtl/modules/vector/vlsu.sv \
	rtl/modules/vector/gsau_control_unit.sv \
	rtl/modules/vector/reduction/vreduction_alu.sv \
	rtl/modules/vector/reduction/reduction_tree.sv \
	rtl/modules/vector/reduction/vreduction.sv \
	rtl/modules/vector/lane_FUs/reduction_FU.sv \
	rtl/modules/vector/vector_datapath.sv 


#	<4. PUT YOUR UVM FILES HERE (e.g., uvm/*.svh in order: config -> item -> seq -> drv/mon -> agt -> sb/pred -> env -> test)> 
#   asdasd
#	<5. PUT YOUR TOP-LEVEL TB FILE HERE (e.g., tb/tb_top.sv or uvm/tb_top.sv)> 

# Full compile
# usage: make compile_all LIB=work_j
compile_all:
	@if [ ! -d "$(LIB)" ]; then \
		$(VLIB) $(LIB); \
	fi
	$(VLOG) -work $(LIB) -sv $(INC) $(FILES)

# usage: make run LIB=work_j
run:
	@rm -rf $(LIB)
	$(MAKE) compile_all LIB=$(LIB)
	$(VSIM) -c $(LIB).$(TOP) -do "run -all; quit"

# usage: make gui LIB=work_j
gui:
	@rm -rf $(LIB)
	$(MAKE) compile_all LIB=$(LIB)
	$(VSIM) -voptargs="+acc" $(LIB).$(TOP) -do "do uvm/waves/plic.do"