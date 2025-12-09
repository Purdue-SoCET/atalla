.SILENT: lint test
.ONESHELL: lint test

SHELL := /bin/bash

TOPDIR     := .
INCDIRROOT := $(TOPDIR)/rtl/include
SCRIPTROOT := $(TOPDIR)/scripts
WAVEROOT   := $(TOPDIR)/waves
MODROOT    := $(TOPDIR)/rtl/modules
TBROOT     := $(TOPDIR)/tb
UVMTESTROOT  := $(TBROOT)/uvm
UNITTESTROOT := $(TBROOT)/unit
SCRATCH       := work

# Include directory setup
INCFLAGS := $(shell find $(INCDIRROOT) -type d -print0 2>/dev/null | xargs -0 -I{} echo +incdir+{})

VLIB ?= vlib
VLOG ?= vlog
VSIM ?= vsim
GUI ?= OFF

# --- Coverage Controls ---
COVERAGE ?= OFF           # set to ON to enable coverage
VLOG_FLAGS ?=

ifeq ($(COVERAGE),ON)
  # Questa coverage switches
  VLOG_FLAGS += -cover bcesft
endif

# --- Target-Specific Variable Mappings ---
# Define specific DUT files for specific tests here
lane_sequencer.sim lane_sequencer.wav: dut := lane_sequencer.sv,lane.sv
veggie.sim veggie.wav: dut := veggie.sv

# For lane, only list "roots"; siblings will be auto-included
lane.sim lane.wav: dut := lane.sv,lane_fu_pt.sv,sqrt_bf16.sv,mul_bf16.sv,add_bf16.sv

# --- Pattern Rules for Module Testing ---
.PHONY: %.sim %.wav

%.sim:
	@$(MAKE) test tb_file=$*_tb.sv GUI=OFF dut=$(dut)

%.wav:
	@$(MAKE) test tb_file=$*_tb.sv GUI=ON dut=$(dut)

# --- Custom Test Shortcuts ---
.PHONY: test_lane_sequencer test_veggie test_lane cov_gsau

test_lane_sequencer:
	@$(MAKE) lane_sequencer.sim

test_veggie:
	@$(MAKE) veggie.sim

test_lane:
	@$(MAKE) lane.sim

# Example dedicated coverage compile for another design tree
cov_gsau:
	$(VLOG) $(VLOG_FLAGS) \
	  ./src/modules/simple_systolic_model.sv \
	  ./src/include/gsau_control_unit_if.vh \
	  ./src/testbench/gsau_control_unit_tb.sv \
	  ./src/modules/gsau_control_unit.sv \
	  ./src/modules/sync_fifo.sv

# --- Targets ---

.PHONY: setup lint test clean

setup:
	mkdir -p $(SCRATCH)
	python3 scripts/setup.py
	@echo "[setup] done"

lint:
	@if [ -z "$(folder)" ]; then \
	  echo "Usage: make lint folder=/sub/dir [file=name.sv] [include=/foo]"; exit 1; \
	fi; \
	SEARCH_FIRST_IN_INCLUDE="$(INCDIRROOT)$(folder)"; \
	SRCS=$$(find "$$SEARCH_FIRST_IN_INCLUDE" -type f -name '*.sv' -print 2>/dev/null | sort); \
	NOW_SEARCH_IN_MODULES="$(MODROOT)$(folder)"; \
	if [ -n "$(file)" ]; then \
	  for f in $$(echo "$(file)" | tr ',' ' '); do \
	    P="$$NOW_SEARCH_IN_MODULES/$$f"; \
	    [ -f "$$P" ] && SRCS="$$SRCS $$P"; \
	  done; \
	else \
	  SRCS=$$(find "$$NOW_SEARCH_IN_MODULES" -type f -name '*.sv' -print 2>/dev/null | sort); \
	fi; \
	PKGS=$$(printf '%s\n' $$SRCS | grep -E '_pkg\.sv$$' || true); \
	OTHERS=$$(printf '%s\n' $$SRCS | grep -Ev '_pkg\.sv$$' || true); \
	BASE_INCS="+incdir+$(INCDIRROOT)"; \
	MOD_INCS=$$(find "$$NOW_SEARCH_IN_MODULES" -type d -print 2>/dev/null | sed 's/^/+incdir+/'); \
	INC_INCS=$$(find "$(INCDIRROOT)$(folder)" -type d -print 2>/dev/null | sed 's/^/+incdir+/'); \
	echo "[lint] compiling..."; \
	$(VLOG) $(VLOG_FLAGS) -sv -mfcu -work work +acc $$BASE_INCS $$MOD_INCS $$INC_INCS $$PKGS $$OTHERS; \
	echo "[lint] done"

test:
	@if [ -z "$(tb_file)" ]; then \
	  echo "Usage: make $@ tb_file=tb_top.sv [folder=/sub/dir] [dut=file1.sv,file2.sv] [GUI=ON/OFF]"; exit 1; \
	fi; \
	\
	# 1. Locate Testbench File \
	TB_CAND=""; \
	if [ -n "$(folder)" ]; then \
	  TB_CAND="$(UNITTESTROOT)$(folder)/$(tb_file)"; \
	  [ -f "$$TB_CAND" ] || TB_CAND=""; \
	fi; \
	if [ -z "$$TB_CAND" ]; then \
	  TB_CAND=$$(find "$(UNITTESTROOT)" -name "$(tb_file)" -type f | head -1); \
	  [ -f "$$TB_CAND" ] || { echo "[$@] tb_file not found: $(tb_file)"; exit 3; }; \
	fi; \
	TB_DIR=$$(dirname "$$TB_CAND"); \
	TB_BASENAME=$$(basename "$$TB_CAND"); \
	TB_TOP="$${TB_BASENAME%.*}"; \
	TB_RELPATH=$$(echo "$$TB_DIR" | sed "s|$(UNITTESTROOT)||"); \
	\
	# 2. Identify Include Sources and PACKAGES \
	INCSRCS=""; \
	if [ -n "$$TB_RELPATH" ] && [ "$$TB_RELPATH" != "/" ]; then \
	  INCSRCS=$$(find "$(INCDIRROOT)/common" "$(INCDIRROOT)$$TB_RELPATH" -type f \( -name '*.sv' -o -name '*_pkg.sv' -o -name '*_pkg.vh' \) -print 2>/dev/null | sort); \
	else \
	  INCSRCS=$$(find "$(INCDIRROOT)" -type f \( -name '*.sv' -o -name '*_pkg.sv' -o -name '*_pkg.vh' \) -print 2>/dev/null | sort); \
	fi; \
	PKGS=$$(printf '%s\n' $$INCSRCS | grep -E '_pkg\.(sv|vh)$$' || true); \
	INC_OTHERS=$$(printf '%s\n' $$INCSRCS | grep -Ev '_pkg\.(sv|vh)$$' || true); \
	\
	# 3. Identify Module Sources \
	MODSRCS=""; \
	MOD_SEARCH_PATH="$(MODROOT)$$TB_RELPATH"; \
	\
	# For vector unit tests (tb/unit/vector/*), compile the whole vector + sqrt + adders + multipliers + dividers + general subsystem \
	if [ "$$TB_RELPATH" = "/vector" ]; then \
	  echo "[$@] vector TB detected -> compiling all vector + sqrt + adders + multipliers + dividers + general modules"; \
	  MOD_SEARCH_PATH="$(MODROOT)/vector \
	                    $(MODROOT)/common/arithmetic/sqrt \
	                    $(MODROOT)/common/arithmetic/adders \
	                    $(MODROOT)/common/arithmetic/mutlipliers \
	                    $(MODROOT)/common/arithmetic/dividers \
	                    $(MODROOT)/common/general"; \
	  MODSRCS=$$(find $$MOD_SEARCH_PATH -type f -name '*.sv' ! -name '*_pkg.sv' -print 2>/dev/null | sort); \
	else \
	  if [ -n "$(dut)" ]; then \
	    echo "[$@] compiling specific DUT files: $(dut)"; \
	    for f in $$(echo "$(dut)" | tr ',' ' '); do \
	      FOUND=$$(find $$MOD_SEARCH_PATH -name "$$f" -print); \
	      [ -n "$$FOUND" ] || { echo "Error: DUT file $$f not found in $$MOD_SEARCH_PATH"; exit 1; }; \
	      MODSRCS="$$MODSRCS $$FOUND"; \
	    done; \
	    MODSRCS=$$(printf '%s\n' $$MODSRCS | sed '/^$$/d' | sort -u); \
	  else \
	    echo "[$@] compiling all modules in: $$MOD_SEARCH_PATH"; \
	    MODSRCS=$$(find $$MOD_SEARCH_PATH -type f -name '*.sv' ! -name '*_pkg.sv' -print 2>/dev/null | sort); \
	  fi; \
	fi; \
	\
	# 4. Testbench Sources \
	TBSRCS="$$TB_CAND"; \
	\
	# 5. Build final compilation order \
	ORDERED_SRCS="$$PKGS $$INC_OTHERS $$MODSRCS $$TBSRCS"; \
	\
	# 6. Setup Includes \
	BASE_INCS="+incdir+$(INCDIRROOT) +incdir+$(MODROOT) +incdir+$(UNITTESTROOT)"; \
	INCDIRS_ALL=$$(find "$(INCDIRROOT)" "$(MODROOT)" "$(UNITTESTROOT)" -type d -print 2>/dev/null | sed 's/^/+incdir+/'); \
	ALL_INCS="$$BASE_INCS $$INCDIRS_ALL"; \
	\
	echo "[$@] Running generic simulation script..."; \
	if [ "$(GUI)" = "ON" ]; then \
		$(VSIM) -do "set batch_mode 0; \
		             set WAVE_ROOT $(WAVEROOT); \
		             set TB_NAME $$TB_TOP; \
		             set SRCS {$$ORDERED_SRCS}; \
		             set INCS {$$ALL_INCS}; \
		             set VLOG_FLAGS {$(VLOG_FLAGS)}; \
		             do $(SCRIPTROOT)/run_sim.tcl"; \
	else \
		$(VSIM) -c -do "set batch_mode 1; \
		                set WAVE_ROOT $(WAVEROOT); \
		                set TB_NAME $$TB_TOP; \
		                set SRCS {$$ORDERED_SRCS}; \
		                set INCS {$$ALL_INCS}; \
		                set VLOG_FLAGS {$(VLOG_FLAGS)}; \
		                do $(SCRIPTROOT)/run_sim.tcl"; \
	fi
	
clean:
	rm -rf $(SCRATCH) transcript vsim.wlf work modelsim.ini
