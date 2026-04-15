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

#DPIC path config
DPI_INC := $(TBROOT)/formal/vector/include
DPI_SRC := $(TBROOT)/formal/vector/src/DPIC
DPI_LIB := libdpi_parser
QUESTA_INC     := /package/eda/mg/questa2021.4/questasim/include
CPP_MODEL_DIR := $(TBROOT)/formal/vector/src
CPP_MODEL_INC := $(TBROOT)//formal/vector/include
TESTCASEROOT := $(TBROOT)/formal/vector/testcases
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
VSIM_EXTRA_FLAGS ?=

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
	  echo "Usage: make $@ tb_file=tb_top.sv [folder=/sub/dir] [dut=file1.sv,file2.sv] [modules=/path/to/dir,/path/to/file.sv] [packages=/path/to/pkg.sv,/path/to/dir] [GUI=ON/OFF]"; exit 1; \
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
	PKGS=""; \
	INC_OTHERS=""; \
	\
	if [ -n "$(packages)" ]; then \
	  echo "[$@] compiling specified packages: $(packages)"; \
	  for p in $$(echo "$(packages)" | tr ',' ' '); do \
	    if [[ "$$p" = /* ]]; then \
	      FULL_PATH="$(INCDIRROOT)$$p"; \
	    else \
	      FULL_PATH="$$p"; \
	    fi; \
	    if [ -f "$$FULL_PATH" ]; then \
	      echo "  Adding package file: $$FULL_PATH"; \
	      PKGS="$$PKGS $$FULL_PATH"; \
	    elif [ -d "$$FULL_PATH" ]; then \
	      echo "  Searching for packages in directory: $$FULL_PATH"; \
	      PKG_FILES=$$(find "$$FULL_PATH" -type f \( -name '*_pkg.sv' -o -name '*_pkg.vh' -o -name '*.sv' ! -name '*_pkg.sv' \) -print 2>/dev/null); \
	      PKGS="$$PKGS $$PKG_FILES"; \
	    else \
	      echo "Error: Package path $$FULL_PATH not found (neither file nor directory)"; exit 1; \
	    fi; \
	  done; \
	  PKGS=$$(printf '%s\n' $$PKGS | sed '/^$$/d' | sort -u); \
	else \
	  echo "[$@] auto-discovering packages from include directories"; \
	  INCSRCS=""; \
	  if [ -n "$$TB_RELPATH" ] && [ "$$TB_RELPATH" != "/" ]; then \
	    INCSRCS=$$(find "$(INCDIRROOT)/common" "$(INCDIRROOT)$$TB_RELPATH" -type f \( -name '*.sv' -o -name '*_pkg.sv' -o -name '*_pkg.vh' \) -print 2>/dev/null | sort); \
	  else \
	    INCSRCS=$$(find "$(INCDIRROOT)" -type f \( -name '*.sv' -o -name '*_pkg.sv' -o -name '*_pkg.vh' \) -print 2>/dev/null | sort); \
	  fi; \
	  PKGS=$$(printf '%s\n' $$INCSRCS | grep -E '_pkg\.(sv|vh)$$' || true); \
	  INC_OTHERS=$$(printf '%s\n' $$INCSRCS | grep -Ev '_pkg\.(sv|vh)$$' || true); \
	fi; \
	\
	# 3. Identify Module Sources \
	MODSRCS=""; \
	MOD_SEARCH_PATH="$(MODROOT)$$TB_RELPATH"; \
	\
	if [ -n "$(modules)" ]; then \
	  echo "[$@] compiling modules from specified paths: $(modules)"; \
	  for p in $$(echo "$(modules)" | tr ',' ' '); do \
	    if [[ "$$p" = /* ]] && [[ ! "$$p" = $(MODROOT)* ]]; then \
	      FULL_PATH="$(MODROOT)$$p"; \
	    else \
	      FULL_PATH="$$p"; \
	    fi; \
	    if [ -f "$$FULL_PATH" ]; then \
	      echo "  Adding file: $$FULL_PATH"; \
	      MODSRCS="$$MODSRCS $$FULL_PATH"; \
	    elif [ -d "$$FULL_PATH" ]; then \
	      echo "  Searching directory: $$FULL_PATH"; \
	      DIR_FILES=$$(find "$$FULL_PATH" -type f -name '*.sv' ! -name '*_pkg.sv' -print 2>/dev/null); \
	      MODSRCS="$$MODSRCS $$DIR_FILES"; \
	    else \
	      echo "Error: Path $$FULL_PATH not found (neither file nor directory)"; exit 1; \
	    fi; \
	  done; \
	  MODSRCS=$$(printf '%s\n' $$MODSRCS | sed '/^$$/d' | sort -u); \
	elif [ -n "$(dut)" ]; then \
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
	echo "[$@] Ensuring work library exists..."; \
	$(VLIB) work 2>/dev/null || true; \
	echo "[$@] Running generic simulation script..."; \
	if [ "$(GUI)" = "ON" ]; then \
		$(VSIM) -voptargs="+acc" -do "set batch_mode 0; \
		             set WAVE_ROOT $(WAVEROOT); \
		             set TB_NAME $$TB_TOP; \
		             set SRCS {$$ORDERED_SRCS}; \
		             set INCS {$$ALL_INCS}; \
		             set VLOG_FLAGS {$(VLOG_FLAGS)}; \
		             set VSIM_FLAGS {$(VSIM_EXTRA_FLAGS)}; \
		             do $(SCRIPTROOT)/run_sim.tcl"; \
	else \
		$(VSIM) -voptargs="+acc" -c -do "set batch_mode 1; \
		                set WAVE_ROOT $(WAVEROOT); \
		                set TB_NAME $$TB_TOP; \
		                set SRCS {$$ORDERED_SRCS}; \
		                set INCS {$$ALL_INCS}; \
		                set VLOG_FLAGS {$(VLOG_FLAGS)}; \
		                set VSIM_FLAGS {$(VSIM_EXTRA_FLAGS)}; \
		                do $(SCRIPTROOT)/run_sim.tcl"; \
	fi
	
clean:
	rm -rf $(SCRATCH) transcript vsim.wlf work modelsim.ini

SHELL := /bin/bash

TOPDIR     := .
INCDIRROOT := $(TOPDIR)/rtl/include
SCRIPTROOT := $(TOPDIR)/scripts
WAVEROOT := $(TOPDIR)/waves
MODROOT    := $(TOPDIR)/rtl/modules
TBROOT     := $(TOPDIR)/tb
UVMTESTROOT  := $(TBROOT)/uvm
UNITTESTROOT := $(TBROOT)/unit
SCRATCH       := work

INCFLAGS := $(shell find $(INCDIRROOT) -type d -print0 2>/dev/null | xargs -0 -I{} echo +incdir+{})

PKG_SRCS := $(shell find $(TOPDIR)/rtl -type f \( -name "*_pkg.sv" -o -name "pkg_*.sv" \) 2>/dev/null | sort)

RTL_SRCS := $(shell \
  find $(INCDIRROOT) $(MODROOT) -type f -name "*.sv" \
    ! -name "*_pkg.sv" ! -name "pkg_*.sv" 2>/dev/null | sort)

VLIB ?= vlib
VLOG ?= vlog
VSIM ?= vsim
GUI ?= OFF

.PHONY: setup lint test clean_lib

setup:
	mkdir -p $(SCRATCH)
	python3 scripts/setup.py
	@echo "[setup] done"

## Example: 
## 		make run FILE=./scripts/xbar/benes_rom/verify.tcl
## 		make run FILE=./scripts/memory/scratchpad/swizzle/verify.tcl
run:
	vsim -c -do "source $(FILE)"

# Usage: make lint folder=/sub/dir [file=name.sv[,name2.sv,...]] [include=/foo/bar,/baz/qux ...]
## Example: 
##  make lint folder=/memory/scratchpad 
### 	-> `vlogs` all the files under rtl/include/memory/scratchpad and rtl/modules/memory/scratchpad
##  make lint folder=/memory/scratchpad include=/network/xbar 
### 	-> `vlogs` all the files under rtl/include/memory/scratchpad and rtl/modules/memory/scratchpad, and adds all the include paths under rtl/modules/network/xbar and rtl/include/network/xbar
##  make lint folder=/memory/scratchpad file=scpad_cntrl.sv,tail.sv 
### 	-> `vlogs` the files under rtl/include/memory/scratchpad and only the specified files under it
lint:
	@if [ -z "$(folder)" ]; then 
	  echo "Usage: make lint folder=/sub/dir [file=name.sv[,name2.sv,...]] [include=/foo/bar,/baz/qux ...]"; exit 1; 
	fi; 

	SEARCH_FIRST_IN_INCLUDE="$(INCDIRROOT)$(folder)"; 
	[ -d "$$SEARCH_FIRST_IN_INCLUDE" ] || { echo "[lint] SEARCH_FIRST_IN_INCLUDE not found: $$SEARCH_FIRST_IN_INCLUDE"; exit 2; }; 

	SRCS=$$(find "$$SEARCH_FIRST_IN_INCLUDE" -type f -name '*.sv' -print 2>/dev/null | sort); 
	[ -n "$$SRCS" ] || { echo "[lint] No .sv files under $$SEARCH_FIRST_IN_INCLUDE"; exit 4; }; 

	NOW_SEARCH_IN_MODULES="$(MODROOT)$(folder)"; 

	[ -d "$$NOW_SEARCH_IN_MODULES" ] || { echo "[lint] NOW_SEARCH_IN_MODULES not found: $$NOW_SEARCH_IN_MODULES"; exit 2; }; 

	if [ -n "$(file)" ]; then
	  for f in $$(echo "$(file)" | tr ',' ' '); do 
	    P="$$NOW_SEARCH_IN_MODULES/$$f"; 
	    [ -f "$$P" ] || { echo "[lint] Not found: $$P"; exit 3; }; 
	    SRCS="$$SRCS $$P"; 
	  done; 
	else 
	  SRCS=$$(find "$$NOW_SEARCH_IN_MODULES" -type f -name '*.sv' -print 2>/dev/null | sort); 
	  [ -n "$$SRCS" ] || { echo "[lint] No .sv files under $$NOW_SEARCH_IN_MODULES"; exit 4; }; 
	fi; 

	PKGS=$$(printf '%s\n' $$SRCS | grep -E '_pkg\.sv$$' || true); 
	OTHERS=$$(printf '%s\n' $$SRCS | grep -Ev '_pkg\.sv$$' || true); 

	BASE_INCS="+incdir+$(INCDIRROOT)"; 
	MOD_INCS=$$(find "$$NOW_SEARCH_IN_MODULES" -type d -print 2>/dev/null | sed 's/^/+incdir+/'); 
	INC_INCS=$$(find "$(INCDIRROOT)$(folder)" -type d -print 2>/dev/null | sed 's/^/+incdir+/'); 

	EXTRA_INCS=""; 
	if [ -n "$(include)" ]; then 
	  for p in $$(echo "$(include)" | tr ',' ' '); do 
	    [ -d "$(MODROOT)$$p" ] && EXTRA_INCS="$$EXTRA_INCS $$(find "$(MODROOT)$$p" -type d -print 2>/dev/null | sed 's/^/+incdir+/')"; 
	    [ -d "$(INCDIRROOT)$$p" ] && EXTRA_INCS="$$EXTRA_INCS $$(find "$(INCDIRROOT)$$p" -type d -print 2>/dev/null | sed 's/^/+incdir+/')"; 
	  done; 
	fi; 

	ORDERED_SRCS="$$PKGS $$OTHERS"; 
	INCFLAGS="$$BASE_INCS $$MOD_INCS $$INC_INCS $$EXTRA_INCS"; 
	
	echo "[lint] compiling (in-order):"; 
	printf '  %s\n' $$ORDERED_SRCS; 
	
	$(VLOG) -sv -compile_uselibs -cover bs -sv -pedanticerrors -lint -mfcu -work work +acc $$INCFLAGS $$ORDERED_SRCS; 
	echo "[lint] done"

# Similar to above! 
## Example: 
##  make test folder=/common/xbar tb_file=batcher_xbar_tb.sv
# to turn on the GUI: add GUI=ON
test2:
	@if [ -z "$(folder)" ] || [ -z "$(tb_file)" ]; then \
	  echo "Usage: make $@ folder=/sub/dir tb_file=tb_top.sv [include=/foo,/bar]"; exit 1; \
	fi; \
	
	[ -d "$(INCDIRROOT)$(folder)" ] || { echo "[$@] Not found: $(INCDIRROOT)$(folder)"; exit 2; }; \
	[ -d "$(MODROOT)$(folder)" ]   || { echo "[$@] Not found: $(MODROOT)$(folder)"; exit 2; }; \
	[ -d "$(UNITTESTROOT)$(folder)" ]    || { echo "[$@] Not found: $(UNITTESTROOT)$(folder)"; exit 2; }; \
	\
	INCSRCS=$$(find "$(INCDIRROOT)$(folder)" -type f -name '*.sv' -print 2>/dev/null | sort); \

	MODSRCS=$$(if [ -n "$(file)" ]; then \
	  SR=""; \
	  for f in $$(echo "$(file)" | tr ',' ' '); do \
	    P="$(MODROOT)$(folder)/$$f"; [ -f "$$P" ] || { echo "[$@] Not found: $$P"; exit 3; }; SR="$$SR $$P"; \
	  done; echo "$$SR"; \
	else \
	  find "$(MODROOT)$(folder)" -type f -name '*.sv' -print 2>/dev/null | sort; \
	fi); \
	TBSRCS=$$(find "$(UNITTESTROOT)$(folder)" -type f -name '*.sv' -print 2>/dev/null | sort); \
	[ -n "$$INCSRCS" ] || { echo "[$@] No .sv under $(INCDIRROOT)$(folder)"; exit 4; }; \
	[ -n "$$MODSRCS" ] || { echo "[$@] No .sv under $(MODROOT)$(folder)"; exit 4; }; \
	[ -n "$$TBSRCS"  ] || { echo "[$@] No .sv under $(UNITTESTROOT)$(folder)"; exit 4; }; \
	\

	ALLSRCS="$$INCSRCS $$MODSRCS $$TBSRCS"; \
	PKGS=$$(printf '%s\n' $$ALLSRCS | grep -E '_pkg\.sv$$' || true); \
	OTHERS=$$(printf '%s\n' $$ALLSRCS | grep -Ev '_pkg\.sv$$' || true); \
	ORDERED_SRCS="$$PKGS $$OTHERS"; \

	BASE_INCS="$(shell find $(INCDIRROOT) -type d | sed 's/^/+incdir+/') +incdir+$(MODROOT) +incdir+$(UNITTESTROOT)"	INCDIRS_MOD=$$(find "$(MODROOT)$(folder)"   -type d -print 2>/dev/null | sed 's/^/+incdir+/'); \
	INCDIRS_TB=$$(find "$(UNITTESTROOT)$(folder)"     -type d -print 2>/dev/null | sed 's/^/+incdir+/'); \

	EXTRA_INCS=""; \
	if [ -n "$(include)" ]; then \
	  for p in $$(echo "$(include)" | tr ',' ' '); do \
	    [ -d "$(INCDIRROOT)$$p" ] && EXTRA_INCS="$$EXTRA_INCS $$(find "$(INCDIRROOT)$$p" -type d -print 2>/dev/null | sed 's/^/+incdir+/')"; \
	    [ -d "$(MODROOT)$$p" ]    && EXTRA_INCS="$$EXTRA_INCS $$(find "$(MODROOT)$$p"    -type d -print 2>/dev/null | sed 's/^/+incdir+/')"; \
	    [ -d "$(UNITTESTROOT)$$p" ]     && EXTRA_INCS="$$EXTRA_INCS $$(find "$(UNITTESTROOT)$$p"     -type d -print 2>/dev/null | sed 's/^/+incdir+/')"; \
	  done; \
	fi; \
	INCFLAGS="$$BASE_INCS $$INCDIRS_INC $$INCDIRS_MOD $$INCDIRS_TB $$EXTRA_INCS"; \

	TB_CAND="$(UNITTESTROOT)$(folder)/$(tb_file)"; \
	[ -f "$$TB_CAND" ] || { echo "[$@] tb_file not found: $$TB_CAND"; exit 3; }; \
	TB_BASENAME=$$(basename "$$TB_CAND"); \
	TB_TOP="$${TB_BASENAME%.*}"; \

	[ -d work ] || $(VLIB) work; \
	echo "[$@] compiling (in-order):"; printf '  %s\n' $$ORDERED_SRCS; \
	$(VLOG) -sv -mfcu -work work +acc -cover bcesft $$INCFLAGS $$ORDERED_SRCS; \

	@if [ "$(GUI)" = "ON" ]; then \
		echo "[$@] launching vsim GUI on work.$$TB_TOP"; \
		$(VSIM) -coverage -voptargs="+acc" work.$$TB_TOP -do "view objects; do $(WAVEROOT)/$$TB_TOP.do; run -all;" -onfinish stop; \
	else \
		echo "[$@] launching vsim on work.$$TB_TOP"; \
		$(VSIM) -coverage -c -voptargs="+acc"  work.$$TB_TOP -do "run -all"; \
	fi 

clean:
	rm -rf $(SCRATCH) transcript vsim.wlf work modelsim.ini

.PHONY: dpi_lib l1_test l1_test_gui

PROGRAM ?= add_vv

dpi_lib:
	g++ -std=c++20 -fPIC -shared \
		-I$(DPI_INC) \
		-I$(CPP_MODEL_INC) \
		-I$(QUESTA_INC) \
		-o $(DPI_LIB).so \
		$(DPI_SRC)/inst_parser_dpi.cpp \
		$(DPI_SRC)/sysarr_dpi.cpp \
		$(DPI_SRC)/scratchpad_dpi.cpp \
		$(DPI_SRC)/veggie_dpi.cpp \
		$(CPP_MODEL_DIR)/schedular.cpp \
		$(CPP_MODEL_DIR)/sysarr.cpp \
		$(CPP_MODEL_DIR)/scratchpad.cpp \
		$(CPP_MODEL_DIR)/veggie.cpp

L1_PACKAGES := /vector/vector_pkg.vh,/memory/scratchpad/scpad_pkg.sv,/common/xbar/xbar_pkg.sv,/vector/vlsu_if.sv,/memory/scratchpad/scpad_if.sv,/vector/inst_parser_dpi_pkg.sv
L1_MODULES  := /common/arithmetic/adders,/common/arithmetic/multipliers,/vector/reduction,/vector/vector_datapath.sv,/vector/vlsu.sv,/vector/gsau_control_unit.sv,/vector/lane.sv,/vector/lane_sequencer.sv,/vector/result_collector.sv,/vector/result_collector_counter.sv,/vector/lane_FUs/lane_unit_fifo.sv,/vector/lane_FUs/mul_FU.sv,/vector/lane_FUs/sqrt_FU.sv,/vector/slicer.sv,/vector/sync_fifo.sv,/vector/valu.sv,/vector/lane_FUs/alu_FU.sv,/vector/lane_FUs/reduction_FU.sv

l1_test: dpi_lib
	$(MAKE) test \
		tb_file=vector_core_dpi_tb.sv \
		packages=$(L1_PACKAGES) \
		modules=$(L1_MODULES) \
		VSIM_EXTRA_FLAGS="-sv_lib ./$(DPI_LIB)" \
		GUI=OFF

l1_test_gui: dpi_lib
	$(MAKE) test \
		tb_file=vector_core_dpi_tb.sv \
		packages=$(L1_PACKAGES) \
		modules=$(L1_MODULES) \
		VSIM_EXTRA_FLAGS="-sv_lib ./$(DPI_LIB)" \
		GUI=ON

L2_PACKAGES := /vector/vector_pkg.vh,/memory/scratchpad/scpad_pkg.sv,/common/xbar/xbar_pkg.sv,/systolic_array/sys_arr_pkg.vh,/vector/vlsu_if.sv,/memory/scratchpad/scpad_if.sv,/vector/inst_parser_dpi_pkg.sv
L2_MODULES  := $(L1_MODULES),/memory/scratchpad,/common/general,/common/memory,/systolic_array/sysarr_MEISSA_top.sv,/systolic_array/sysarr_control_unit.sv,/systolic_array/sysarr_FIFO.sv,/systolic_array/sysarr_OUT_FIFO.sv,/systolic_array/sysarr_MAC.sv,/systolic_array/sysarr_MAC_fp16_2c.sv,/systolic_array/sysarr_MAC_fp16_4c.sv,/systolic_array/sysarr_add.sv,/systolic_array/mul_grid.sv,/systolic_array/mixed_pipelined_adder_tree.sv,/systolic_array/pipelined_adder_tree.sv,/systolic_array/skew_buffer.sv,/systolic_array/left_shift.sv,/systolic_array/left_shift_add_bf16.sv,/systolic_array/systolic_array.sv,/systolic_array/arithmetic/mul_bf.sv,/systolic_array/arithmetic/wtm_bf.sv,/systolic_array/arithmetic/mul_fp16.sv,/systolic_array/arithmetic/mul_fp16_nolatch.sv,/systolic_array/arithmetic/add_fp16.sv,/systolic_array/arithmetic/add_fp16_nolatch.sv,/systolic_array/arithmetic/add_fp16_4_input.sv,/systolic_array/arithmetic/reducer.sv,/systolic_array/TPU/TPU_buffer.sv,/common/general,/common/memory

l2_test: dpi_lib
	$(MAKE) test \
		tb_file=vector_core_L2_tb.sv \
		packages=$(L2_PACKAGES) \
		modules=$(L2_MODULES) \
		VSIM_EXTRA_FLAGS="-sv_lib ./$(DPI_LIB)" \
		GUI=OFF

l2_test_gui: dpi_lib
	$(MAKE) test \
		tb_file=vector_core_L2_tb.sv \
		packages=$(L2_PACKAGES) \
		modules=$(L2_MODULES) \
		VSIM_EXTRA_FLAGS="-sv_lib ./$(DPI_LIB)" \
		GUI=ON
