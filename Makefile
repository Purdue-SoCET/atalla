# Top-level Makefile adapted to new layout
# - RTL modules: ./rtl/
# - Testbenches: ./tb/
# - Testbench result outputs: ./tb/result_output/
# - Waveforms / do files: ./waves/

MKDIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))

RTL_DIR := $(MKDIR)/rtl
TB_DIR := $(MKDIR)/tb
INCLUDE_DIR := $(MKDIR)/include
WAVES_DIR := $(MKDIR)/waves
TB_OUT_DIR := $(TB_DIR)/result_output

# Simulator config
VLOG := vlog
VSIM := vsim
WARNINGS_IGNORE := -suppress 3015 -suppress 2275
VLOG_FLAGS := -sv +incdir+$(INCLUDE_DIR)
VSIM_FLAGS := -voptargs="+acc" $(WARNINGS_IGNORE)

SIMTERM := -c

help:
	@echo "Usage: make <testbench>         - run tb/<testbench>_tb.sv"
	@echo "       make <testbench>.wav     - run with waveform (waves/<testbench>.do loaded when present)"
	@echo "       make <module>_vlint      - lint rtl/<module>.sv with verilator"
	@echo "       make clean               - clean build artifacts and results"

# Ensure output directories exist
.PHONY: dirs
dirs:
	@mkdir -p $(TB_OUT_DIR)
	@mkdir -p $(WAVES_DIR)

# Derive a canonical module name from the requested make goal.
# Examples:
#  - make mul_bf16        -> MODNAME=mul_bf16
#  - make mul_bf16.wav    -> MODNAME=mul_bf16
#  - make mul_bf16_run    -> MODNAME=mul_bf16
MODNAME := $(patsubst %_run,%,$(patsubst %.wav,%,$(firstword $(MAKECMDGOALS))))

# Generic simulation target: compile TB plus all RTL modules and run
%: dirs
	# Compile TB and all rtl files (ensures module dependencies are present)
	$(VLOG) $(VLOG_FLAGS) $(TB_DIR)/$(MODNAME)_tb.sv $(RTL_DIR)/*.sv; \
	$(VSIM) $(VSIM_FLAGS) $(SIMTERM) work.$(MODNAME)_tb -do "run -all;"

# Waveform target: compile TB and the named module, run GUI/do
%.wav: dirs
	# Compile TB and all rtl files (ensures module dependencies are present)
	$(VLOG) $(VLOG_FLAGS) $(TB_DIR)/$(MODNAME)_tb.sv $(RTL_DIR)/*.sv; \
	# If a do file exists under waves, load it; otherwise show default waves
	if [ -f $(WAVES_DIR)/$(MODNAME)_waves.do ]; then \
		DO="do $(abspath $(WAVES_DIR)/$(MODNAME)_waves.do);"; \
	else \
		DO="add wave *;"; \
	fi; \
	$(VSIM) $(VSIM_FLAGS) work.$(MODNAME)_tb -do "view objects; $$DO run -all;" -onfinish stop

# Lint with verilator
%_vlint:
	verilator --lint-only $(RTL_DIR)/$*.sv +incdir+$(INCLUDE_DIR)

clean:
	rm -rf work transcript vsim.wlf *.log *.jou *.vstf *.vcd
	rm -rf $(TB_OUT_DIR)/* || true

# Convenience: run all testbenches found in tb/ (may be slow)
.PHONY: run_all_tbs
run_all_tbs: dirs
	for tb in $(shell ls $(TB_DIR)/*_tb.sv 2>/dev/null | xargs -n1 basename -s _tb.sv); do \
		echo "Running $$tb"; \
		$(VLOG) $(VLOG_FLAGS) $(TB_DIR)/$$tb_tb.sv $(RTL_DIR)/*.sv; \
		$(VSIM) $(VSIM_FLAGS) $(SIMTERM) work.$$tb_tb -do "run -all;"; \
	done

# Target: run a specific test that produces VCD into waves/ and writes results into tb/result_output/
# Example: make add_bf16_test



%_run: dirs
	# Compile TB and all rtl files (ensures module dependencies are present)
	$(VLOG) $(VLOG_FLAGS) $(TB_DIR)/$(MODNAME)_tb.sv $(RTL_DIR)/*.sv; \
	$(VSIM) $(VSIM_FLAGS) $(SIMTERM) work.$(MODNAME)_tb -do "run -all;"

.PHONY: all
all: help