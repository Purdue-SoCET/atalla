SHELL := /bin/bash

# QuestaSim binary directory.  Override on the command line if needed:
#   make sim QUESTA_BIN=/path/to/questasim/bin
QUESTA_BIN          ?= /package/eda/mg/questa2021.4/questasim/bin
MGLS_LICENSE_FILE   ?= 28000@marina.ecn.purdue.edu
export MGLS_LICENSE_FILE

SIMTIME = 100us             # Default simulation run time

SCRDIR = ./rtl/modules/memory/axi_bus/

EXTRA_dram_top = $(wildcard $(SCRDIR)/*.sv)

INCLUDE = ./rtl/include/memory/axi_bus/
TB = ./tb/unit/memory/axi_bus/
MODULE = ./rtl/modules/memory/axi_bus/
SCRIPT = ./scripts/memory/axi_bus/
SCRATCH   := work
WAVEROOT  ?= ./waves

VSIM_FLAGS ?= -coverage -voptargs="+acc"
VLOG_FLAGS ?= -sv -compile_uselibs -cover bst -sv -pedanticerrors -lint -mfcu

RTL_SRCS := $(shell \
  find $(INCDIRROOT) $(MODROOT) -type f -name "*.sv" \
    ! -name "*_pkg.sv" ! -name "pkg_*.sv" 2>/dev/null | sort)

VLIB ?= vlib
VLOG ?= vlog
VSIM ?= vsim
GUI ?= OFF

VLOG_FLAGS ?= -sv -compile_uselibs -cover bst -pedanticerrors -lint -mfcu
VSIM_FLAGS ?= -coverage -c -voptargs="+acc"

# ============================================================
# Ramulator wrapper paths
# ============================================================
RAM_DIR   := ./rtl/modules/memory/ramulator_wrapper
AXIROOT   := ./rtl/include/memory/axi_bus
DPIROOT   := $(RAM_DIR)
TBROOT    := ./tb/unit/memory/ramulator_wrapper
CFGROOT   := $(RAM_DIR)/configs

# ---- Tool overrides (64-bit QuestaSim) ----
VLIB64 ?= $(QUESTA_BIN)/vlib
VLOG64 ?= $(QUESTA_BIN)/vlog -64
VSIM64 ?= $(QUESTA_BIN)/vsim -64

COVERAGE ?= OFF
VLOG_COV_FLAGS  :=
VSIM_COV_FLAGS  :=
ifeq ($(COVERAGE),ON)
  VLOG_COV_FLAGS  := -cover bcesft
  VSIM_COV_FLAGS  := -coverage
endif

# ---- DRAM standard selection ----
# Usage: make sim DRAM=hbm3   (default: ddr4)
DRAM ?= ddr4

DRAM_CFG_ddr3   := $(CFGROOT)/ddr3_config.yaml
DRAM_CFG_ddr4   := $(CFGROOT)/ddr4_config.yaml
DRAM_CFG_ddr5   := $(CFGROOT)/ddr5_config.yaml
DRAM_CFG_gddr6  := $(CFGROOT)/gddr6_config.yaml
DRAM_CFG_hbm2   := $(CFGROOT)/hbm2_config.yaml
DRAM_CFG_hbm3   := $(CFGROOT)/hbm3_config.yaml
DRAM_CFG_lpddr5 := $(CFGROOT)/lpddr5_config.yaml

CFG ?= $(DRAM_CFG_$(DRAM))

# ---- Wrapper SV selection ----
WRAPPER_SV_DEFAULT := $(DPIROOT)/ramulator_sv_wrapper.sv
WRAPPER_SV_HBM3    := $(DPIROOT)/ramulator_sv_wrapper_32.sv

WRAPPER_SV  := $(WRAPPER_SV_DEFAULT)
WRAPPER_DEF :=

ifeq ($(DRAM),hbm3)
  WRAPPER_SV  := $(WRAPPER_SV_HBM3)
  WRAPPER_DEF := +define+USE_HBM3_WRAPPER
endif

ifneq ($(findstring hbm3_config.yaml,$(CFG)),)
  WRAPPER_SV  := $(WRAPPER_SV_HBM3)
  WRAPPER_DEF := +define+USE_HBM3_WRAPPER
endif

# ---- Memory preload (test_ramulator) ----
MEMINIT      ?=
MEMINIT_TYPE ?= hex
MEMINIT_BASE ?= 0

ifneq ($(MEMINIT),)
  MEMINIT_FLAGS := -G MEM_INIT_FILE="$(MEMINIT)" \
                   -G MEM_INIT_TYPE="$(MEMINIT_TYPE)" \
                   -G MEM_INIT_BASE=$(MEMINIT_BASE) \
                   -G MEMINIT_FILE="$(MEMINIT)" \
                   -G MEMINIT_TYPE="$(MEMINIT_TYPE)" \
                   -G MEMINIT_BASE=$(MEMINIT_BASE) \
                   -G USE_MEMINIT=1
else
  MEMINIT_FLAGS :=
endif

# ---- Memory preload (test_sdma) ----
SDMA_MEMINIT      ?=
SDMA_MEMINIT_TYPE ?= bin
SDMA_MEMINIT_BASE ?= 0
BURST ?= 0

ifneq ($(SDMA_MEMINIT),)
  SDMA_MEMINIT_FLAGS := -G MEM_INIT_FILE="$(SDMA_MEMINIT)" \
                        -G MEM_INIT_TYPE="$(SDMA_MEMINIT_TYPE)" \
                        -G MEM_INIT_BASE=$(SDMA_MEMINIT_BASE) \
                        -G MEMINIT_FILE="$(SDMA_MEMINIT)" \
                        -G MEMINIT_TYPE="$(SDMA_MEMINIT_TYPE)" \
                        -G MEMINIT_BASE=$(SDMA_MEMINIT_BASE) \
                        -G USE_MEMINIT=1
else
  SDMA_MEMINIT_FLAGS :=
endif

# ---- Ramulator shared library ----
RAMULATOR_LIB    := libramulator_dpi
RAMULATOR_TARGET := ramulator_dpi_shared

GCC14_CXX := /opt/rh/gcc-toolset-14/root/usr/bin/g++
GCC14_CC  := /opt/rh/gcc-toolset-14/root/usr/bin/gcc
GCC14_LIB := /opt/rh/gcc-toolset-14/root/lib64

# ---- SV source lists ----
AXI_SRCS := \
	$(AXIROOT)/axi_bus_pkg.sv \
	$(AXIROOT)/axi_bus_if.sv

DPI_SRCS := \
	$(WRAPPER_SV) \
	$(TBROOT)/test_ramulator.sv

SDMA_SRCS := \
	$(DPIROOT)/ramulator_sv_wrapper.sv \
	$(TBROOT)/test_sdma.sv

# ============================================================
# Phony targets
# ============================================================
.PHONY: setup lint test ram_lib sim sim_gui sdma sdma_gui \
        gen_sdma_meminit clean \
        ddr3 ddr4 ddr5 gddr6 hbm2 hbm3 lpddr5

setup:
	mkdir -p $(SCRATCH)
	python3 scripts/setup.py
	@echo "[setup] done"

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

	$(VLOG) $(VLOG_FLAGS) -sv -mfcu -work work +acc $$INCFLAGS $$ORDERED_SRCS;
	echo "[lint] done"

# Similar to above!
## Example:
##  make test folder=/common/xbar tb_file=batcher_xbar_tb.sv
test:
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

	BASE_INCS="+incdir+$(INCDIRROOT) +incdir+$(MODROOT) +incdir+$(UNITTESTROOT)"; \
	INCDIRS_INC=$$(find "$(INCDIRROOT)$(folder)" -type d -print 2>/dev/null | sed 's/^/+incdir+/'); \
	INCDIRS_MOD=$$(find "$(MODROOT)$(folder)"   -type d -print 2>/dev/null | sed 's/^/+incdir+/'); \
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
	$(VLOG) -sv -mfcu -cover bcst -work work +acc $$INCFLAGS $$ORDERED_SRCS; \

	@if [ "$(GUI)" = "ON" ]; then \
		echo "[$@] launching vsim GUI on work.$$TB_TOP"; \
		$(VSIM) -coverage -voptargs="+acc" work.$$TB_TOP -do "view objects; do $(WAVEROOT)/$$TB_TOP.do; run -all;" -onfinish stop; \   ## do $$WAVEROOT/$$TB_TOP.do;
	else \
		echo "[$@] launching vsim on work.$$TB_TOP"; \
		$(VSIM) $(VSIM_FLAGS) -coverage -c -voptargs="+acc"  work.$$TB_TOP -do "run -all"; \
	fi

# ============================================================
# Ramulator targets
# ============================================================

# Build Ramulator DPI shared library via CMake.
# Ramulator2 requires C++20. RHEL8's default GCC 8 miscompiles -O3 Release
# builds; use gcc-toolset-14 explicitly.
ram_lib:
	@echo "[ram_lib] configuring..."
	cmake -S . -B ./build \
	    -DCMAKE_BUILD_TYPE=Release \
	    -DCMAKE_CXX_COMPILER=$(GCC14_CXX) \
	    -DCMAKE_C_COMPILER=$(GCC14_CC) \
	    -G "Unix Makefiles" > /dev/null 2>&1 || true
	@echo "[ram_lib] building $(RAMULATOR_TARGET)..."
	LD_LIBRARY_PATH=$(GCC14_LIB):$$LD_LIBRARY_PATH \
	cmake --build ./build --target $(RAMULATOR_TARGET) -j$$(nproc) 2>&1 | tail -5

# Usage:
#   make sim              # batch, default config (DDR4)
#   make sim GUI=ON       # waveform GUI
#   make sim CFG=rtl/modules/memory/ramulator_wrapper/configs/ddr5_config.yaml
#   make sim DRAM=hbm3
sim: ram_lib
	@\

	echo "[sim] cleaning stale work library..."; \
	rm -rf $(SCRATCH); \
	$(VLIB64) $(SCRATCH); \
	\
	echo "[sim] compiling SV sources..."; \
	echo "[sim] using wrapper: $(WRAPPER_SV)"; \
	$(VLOG64) -sv -mfcu -work $(SCRATCH) +acc $(VLOG_COV_FLAGS) \
	    $(WRAPPER_DEF) \
	    +incdir+$(AXIROOT) \
	    $(AXI_SRCS) \
	    $(DPI_SRCS); \
	echo "[sim] running $(if $(filter ON,$(GUI)),GUI,batch) simulation (config: $(CFG))..."; \
	if [ "$(GUI)" = "ON" ]; then \
	    $(VSIM64) $(VSIM_COV_FLAGS) -voptargs="+acc" \
	        -sv_lib ./$(RAMULATOR_LIB) \
	        -G CFG="$(CFG)" \
	        $(MEMINIT_FLAGS) \
	        $(SCRATCH).test_ramulator \
	        -onfinish stop \
	        -do "view objects; do $(WAVEROOT)/test_ramulator.do; run -all"; \
	else \
	    $(VSIM64) $(VSIM_COV_FLAGS) -c -voptargs="+acc" \
	        -sv_lib ./$(RAMULATOR_LIB) \
	        -G CFG="$(CFG)" \
	        $(MEMINIT_FLAGS) \
	        $(SCRATCH).test_ramulator \
	        -do "run -all"; \
	    if grep -q "=== PASSED ===" transcript 2>/dev/null; then \
	        echo "[sim] Result: PASSED"; \
	    elif grep -q "=== FAILED ===" transcript 2>/dev/null; then \
	        echo "[sim] Result: FAILED"; exit 1; \
	    else \
	        echo "[sim] Result: UNKNOWN (simulation may have crashed or timed out)"; \
	    fi; \
	fi

sim_gui:
	@$(MAKE) sim GUI=ON

# Usage:
#   make sdma              # batch, default config
#   make sdma GUI=ON
#   make sdma DRAM=ddr5
#   make sdma SDMA_MEMINIT=rtl/modules/memory/ramulator_wrapper/configs/sdma_meminit.bin
sdma: ram_lib
	@\

	echo "[sdma] cleaning stale work library..."; \
	rm -rf $(SCRATCH); \
	$(VLIB64) $(SCRATCH); \
	\
	echo "[sdma] compiling SV sources..."; \
	$(VLOG64) -sv -mfcu -work $(SCRATCH) +acc $(VLOG_COV_FLAGS) \
	    +incdir+$(AXIROOT) \
	    $(AXI_SRCS) \
	    $(SDMA_SRCS); \
	\
	echo "[sdma] running $(if $(filter ON,$(GUI)),GUI,batch) simulation (config: $(CFG))..."; \
	if [ "$(GUI)" = "ON" ]; then \
	    $(VSIM64) $(VSIM_COV_FLAGS) -voptargs="+acc" \
	        -sv_lib ./$(RAMULATOR_LIB) \
	        -G CFG="$(CFG)" \
	        -G USE_BURST=$(BURST) \
	        $(SDMA_MEMINIT_FLAGS) \
	        $(SCRATCH).test_sdma \
	        -onfinish stop \
	        -do "view objects; run -all"; \
	else \
	    $(VSIM64) $(VSIM_COV_FLAGS) -c -voptargs="+acc" \
	        -sv_lib ./$(RAMULATOR_LIB) \
	        -G CFG="$(CFG)" \
	        -G USE_BURST=$(BURST) \
	        $(SDMA_MEMINIT_FLAGS) \
	        $(SCRATCH).test_sdma \
	        -do "run -all" || true; \
	    if grep -q "=== PASSED ===" transcript 2>/dev/null; then \
	        echo "[sdma] Result: PASSED"; \
	    elif grep -q "=== FAILED ===" transcript 2>/dev/null; then \
	        echo "[sdma] Result: FAILED"; exit 1; \
	    else \
	        echo "[sdma] Result: UNKNOWN (simulation may have crashed or timed out)"; \
	    fi; \
	fi

sdma_gui:
	@$(MAKE) sdma GUI=ON

# Generate SDMA meminit binary (run once; regenerate if matrix params change).
gen_sdma_meminit:
	python3 $(RAM_DIR)/gen_sdma_meminit.py

# Per-standard shorthand targets
ddr3:   ; @$(MAKE) sim DRAM=ddr3
ddr4:   ; @$(MAKE) sim DRAM=ddr4
ddr5:   ; @$(MAKE) sim DRAM=ddr5
gddr6:  ; @$(MAKE) sim DRAM=gddr6
hbm2:   ; @$(MAKE) sim DRAM=hbm2
hbm3:   ; @$(MAKE) sim DRAM=hbm3
lpddr5: ; @$(MAKE) sim DRAM=lpddr5

clean:
	rm -rf $(SCRATCH) transcript vsim.wlf vsim_stacktrace.vstf modelsim.ini
