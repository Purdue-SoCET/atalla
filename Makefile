SIMTIME = 100us             # Default simulation run time

SCRDIR = ./rtl/modules/memory/axi_bus/

EXTRA_dram_top = $(wildcard $(SCRDIR)/*.sv)

INCLUDE = ./rtl/include/memory/axi_bus/
TB = ./tb/unit/memory/axi_bus/
MODULE = ./rtl/modules/memory/axi_bus/
SCRIPT = ./scripts/memory/axi_bus/
SCRATCH := work

VSIM_FLAGS ?= -coverage -voptargs="+acc"
VLOG_FLAGS ?= -sv -compile_uselibs -cover bst -sv -pedanticerrors -lint -mfcu

%.wav:
	vlog $(VLOG_FLAGS) +incdir+$(INCLUDE) $(TB)$*_tb.sv $(MODULE)$*.sv $(EXTRA_dram_top)
	vsim $(VSIM_FLAGS) work.$*_tb -do "do $(SCRIPT)$*.do; run $(SIMTIME);" -suppress 2275

clean:
	rm -rf $(SCRATCH) transcript vsim.wlf work modelsim.ini


# copy aryan's makefile, VSIM_FLAGS to add coverage report

# @if [ "$(GUI)" = "ON" ]; then \
# 		echo "[$@] launching vsim GUI on work.$$TB_TOP"; \
# 		$(VSIM) -coverage -voptargs="+acc" work.$$TB_TOP -do "view objects; do $(WAVEROOT)/$$TB_TOP.do; run -all;" -onfinish stop; \   ## do $$WAVEROOT/$$TB_TOP.do;
# 	else \
# 		echo "[$@] launching vsim on work.$$TB_TOP"; \
# 		$(VSIM) $(VSIM_FLAGS) -coverage -c -voptargs="+acc"  work.$$TB_TOP -do "run -all"; \
# 	fi 