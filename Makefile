SIMTIME = 100us             # Default simulation run time

SCRDIR = ./rtl/modules/memory/axi_bus/

EXTRA_dram_top = $(wildcard $(SCRDIR)/*.sv)

INCLUDE = ./rtl/include/memory/axi_bus/
TB = ./tb/unit/memory/axi_bus/
MODULE = ./rtl/modules/memory/axi_bus/
#SCRIPT = ./scripts/memory/axi_bus/
SCRIPT = ./waves/
SCRATCH := work

VSIM_FLAGS ?= -coverage -voptargs="+acc"
VLOG_FLAGS ?= -sv -compile_uselibs -cover bst -sv -pedanticerrors -lint -mfcu

%.wav:
	vlog $(VLOG_FLAGS) +incdir+$(INCLUDE) $(TB)$*_tb.sv $(MODULE)$*.sv $(EXTRA_dram_top)
	vsim $(VSIM_FLAGS) work.$*_tb -do "do $(SCRIPT)$*.do; run $(SIMTIME);" -suppress 2275

clean:
	rm -rf $(SCRATCH) transcript vsim.wlf work modelsim.ini