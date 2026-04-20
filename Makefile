SHELL := /bin/bash

# ============================================================
# Toolchain
# ============================================================
# QuestaSim binary directory. Override on the command line if needed:
#   make sim QUESTA_BIN=/path/to/questasim/bin
QUESTA_BIN        ?= /package/eda/mg/questa2021.4/questasim/bin
MGLS_LICENSE_FILE ?= 28000@marina.ecn.purdue.edu
export MGLS_LICENSE_FILE

VLIB64 ?= $(QUESTA_BIN)/vlib
VLOG64 ?= $(QUESTA_BIN)/vlog -64
VSIM64 ?= $(QUESTA_BIN)/vsim -64

GCC14_CXX := /opt/rh/gcc-toolset-14/root/usr/bin/g++
GCC14_CC  := /opt/rh/gcc-toolset-14/root/usr/bin/gcc
GCC14_LIB := /opt/rh/gcc-toolset-14/root/lib64

# ============================================================
# Knobs (override on command line)
# ============================================================
GUI      ?= OFF                    # GUI=ON -> waveform vsim, OFF -> batch
COVERAGE ?= OFF                    # COVERAGE=ON -> enable coverage flags
DRAM     ?= ddr4                   # ddr3|ddr4|ddr5|gddr6|hbm2|hbm3|lpddr5
SIMTIME  ?= 100us                  # wav run time

# ============================================================
# Paths
# ============================================================
SCRATCH  := work
WAVEROOT ?= ./waves

# Ramulator wrapper
RAM_DIR   := ./rtl/modules/memory/ramulator_wrapper
DPIROOT   := $(RAM_DIR)
TBROOT    := ./tb/unit/memory/ramulator_wrapper
CFGROOT   := $(RAM_DIR)/configs

# AXI bus (shared by wrapper sim + standalone wav runs)
AXI_INC_DIR    := ./rtl/include/memory/axi_bus
AXI_MOD_DIR    := ./rtl/modules/memory/axi_bus
AXI_TB_DIR     := ./tb/unit/memory/axi_bus
AXI_SCRIPT_DIR := ./scripts/memory/axi_bus

# Back-compat alias used by wrapper sim recipes below
AXIROOT := $(AXI_INC_DIR)

# ============================================================
# Compile / sim flags
# ============================================================
VLOG_FLAGS ?= -sv -compile_uselibs -pedanticerrors -lint -mfcu
VSIM_FLAGS ?= -voptargs="+acc"

VLOG_COV_FLAGS :=
VSIM_COV_FLAGS :=
ifeq ($(COVERAGE),ON)
  VLOG_COV_FLAGS := -cover bcesft
  VSIM_COV_FLAGS := -coverage
endif

# ============================================================
# DRAM config selection
# ============================================================
DRAM_CFG_ddr3   := $(CFGROOT)/ddr3_config.yaml
DRAM_CFG_ddr4   := $(CFGROOT)/ddr4_config.yaml
DRAM_CFG_ddr5   := $(CFGROOT)/ddr5_config.yaml
DRAM_CFG_gddr6  := $(CFGROOT)/gddr6_config.yaml
DRAM_CFG_hbm2   := $(CFGROOT)/hbm2_config.yaml
DRAM_CFG_hbm3   := $(CFGROOT)/hbm3_config.yaml
DRAM_CFG_lpddr5 := $(CFGROOT)/lpddr5_config.yaml

CFG ?= $(DRAM_CFG_$(DRAM))

# ============================================================
# Memory preload — test_ramulator
# ============================================================
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

# ============================================================
# Memory preload / knobs — test_sdma
# ============================================================
SDMA_MEMINIT      ?=
SDMA_MEMINIT_TYPE ?= bin
SDMA_MEMINIT_BASE ?= 0
BURST             ?= 0
SR_DEPTH          ?= 8192
N_BURST_SLOTS     ?= 8192

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

# ============================================================
# Ramulator shared library
# ============================================================
RAMULATOR_LIB    := libramulator_dpi
RAMULATOR_TARGET := ramulator_dpi_shared
WRAPPER_SV       := $(DPIROOT)/ramulator_sv_wrapper.sv

# ============================================================
# Source lists
# ============================================================
AXI_SRCS := \
	$(AXIROOT)/axi_bus_pkg.sv \
	$(AXIROOT)/axi_bus_if.sv

DPI_SRCS := \
	$(WRAPPER_SV) \
	$(TBROOT)/test_ramulator.sv

SDMA_SRCS := \
	$(WRAPPER_SV) \
	$(TBROOT)/test_sdma.sv

# All axi_bus .sv files — used by standalone `wav` runs
AXI_MOD_SRCS := $(wildcard $(AXI_MOD_DIR)/*.sv)

# ============================================================
# Phony
# ============================================================
.PHONY: help setup clean ram_lib \
        sim sim_gui sdma sdma_gui \
        wav wav_gui gen_sdma_meminit

help:
	@echo "Targets:"
	@echo "  setup                 Create work/ and run scripts/setup.py"
	@echo "  ram_lib               Build libramulator_dpi shared library (CMake)"
	@echo ""
	@echo "  sim [DRAM=<std>]      Ramulator wrapper sim (test_ramulator)"
	@echo "  sim_gui               Alias: sim GUI=ON"
	@echo "  sim-<std>             Alias: sim DRAM=<std>"
	@echo ""
	@echo "  sdma [DRAM=<std>]     SDMA sim (test_sdma)"
	@echo "  sdma_gui              Alias: sdma GUI=ON"
	@echo "  sdma-<std>            Alias: sdma DRAM=<std>"
	@echo ""
	@echo "  wav TB=<name>         Waveform run of axi_bus <name>_tb.sv + <name>.do"
	@echo "  wav_gui TB=<name>     Alias: wav TB=<name> GUI=ON"
	@echo "  wav-<name>            Alias: wav TB=<name>"
	@echo "  wav_gui-<name>        Alias: wav TB=<name> GUI=ON"
	@echo ""
	@echo "  gen_sdma_meminit      Regenerate SDMA preload binary"
	@echo "  clean                 Remove work/, transcript, waves"
	@echo ""
	@echo "Knobs: GUI=ON|OFF  COVERAGE=ON|OFF  DRAM=<std>  SIMTIME=<time>"
	@echo "       MEMINIT=<file>  SDMA_MEMINIT=<file>  CFG=<yaml>"
	@echo "       BURST  SR_DEPTH  N_BURST_SLOTS"

# ============================================================
# Setup / clean
# ============================================================
setup:
	mkdir -p $(SCRATCH)
	python3 scripts/setup.py
	@echo "[setup] done"

clean:
	rm -rf $(SCRATCH) transcript vsim.wlf vsim_stacktrace.vstf modelsim.ini

# ============================================================
# Ramulator DPI shared library
# ============================================================
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

# ============================================================
# Ramulator wrapper sim (test_ramulator)
# ============================================================
sim: ram_lib
	@echo "[sim] cleaning work..."; \
	rm -rf $(SCRATCH); \
	$(VLIB64) $(SCRATCH); \
	echo "[sim] compiling (wrapper: $(WRAPPER_SV))..."; \
	$(VLOG64) -sv -mfcu -work $(SCRATCH) +acc $(VLOG_COV_FLAGS) \
	    +incdir+$(AXIROOT) $(AXI_SRCS) $(AXI_MOD_SRCS) $(DPI_SRCS); \
	echo "[sim] running $(if $(filter ON,$(GUI)),GUI,batch) (config: $(CFG))..."; \
	if [ "$(GUI)" = "ON" ]; then \
	    $(VSIM64) $(VSIM_COV_FLAGS) -voptargs="+acc" \
	        -sv_lib ./$(RAMULATOR_LIB) \
	        -G CFG="$(CFG)" $(MEMINIT_FLAGS) \
	        $(SCRATCH).test_ramulator \
	        -onfinish stop \
	        -do "view objects; do $(WAVEROOT)/test_ramulator.do; run -all"; \
	else \
	    $(VSIM64) $(VSIM_COV_FLAGS) -c -voptargs="+acc" \
	        -sv_lib ./$(RAMULATOR_LIB) \
	        -G CFG="$(CFG)" $(MEMINIT_FLAGS) \
	        $(SCRATCH).test_ramulator \
	        -do "run -all"; \
	    if grep -q "=== PASSED ===" transcript 2>/dev/null; then \
	        echo "[sim] Result: PASSED"; \
	    elif grep -q "=== FAILED ===" transcript 2>/dev/null; then \
	        echo "[sim] Result: FAILED"; exit 1; \
	    else \
	        echo "[sim] Result: UNKNOWN (crashed or timed out)"; \
	    fi; \
	fi

sim_gui:
	@$(MAKE) sim GUI=ON

# Pattern: make sim-ddr4, make sim-hbm3, ...
sim-%:
	@$(MAKE) sim DRAM=$*

# ============================================================
# SDMA sim (test_sdma)
# ============================================================
sdma: ram_lib
	@echo "[sdma] cleaning work..."; \
	rm -rf $(SCRATCH); \
	$(VLIB64) $(SCRATCH); \
	echo "[sdma] compiling..."; \
	$(VLOG64) -sv -mfcu -work $(SCRATCH) +acc $(VLOG_COV_FLAGS) \
	    +incdir+$(AXIROOT) $(AXI_SRCS) $(SDMA_SRCS); \
	echo "[sdma] running $(if $(filter ON,$(GUI)),GUI,batch) (config: $(CFG))..."; \
	if [ "$(GUI)" = "ON" ]; then \
	    $(VSIM64) $(VSIM_COV_FLAGS) -voptargs="+acc" \
	        -sv_lib ./$(RAMULATOR_LIB) \
	        -G CFG="$(CFG)" \
	        -G USE_BURST=$(BURST) \
	        -G SR_DEPTH=$(SR_DEPTH) \
	        -G N_BURST_SLOTS=$(N_BURST_SLOTS) \
	        $(SDMA_MEMINIT_FLAGS) \
	        $(SCRATCH).test_sdma \
	        -onfinish stop \
	        -do "view objects; run -all"; \
	else \
	    $(VSIM64) $(VSIM_COV_FLAGS) -c -voptargs="+acc" \
	        -sv_lib ./$(RAMULATOR_LIB) \
	        -G CFG="$(CFG)" \
	        -G USE_BURST=$(BURST) \
	        -G SR_DEPTH=$(SR_DEPTH) \
	        -G N_BURST_SLOTS=$(N_BURST_SLOTS) \
	        $(SDMA_MEMINIT_FLAGS) \
	        $(SCRATCH).test_sdma \
	        -do "run -all" || true; \
	    if grep -q "=== PASSED ===" transcript 2>/dev/null; then \
	        echo "[sdma] Result: PASSED"; \
	    elif grep -q "=== FAILED ===" transcript 2>/dev/null; then \
	        echo "[sdma] Result: FAILED"; exit 1; \
	    else \
	        echo "[sdma] Result: UNKNOWN (crashed or timed out)"; \
	    fi; \
	fi

sdma_gui:
	@$(MAKE) sdma GUI=ON

# Pattern: make sdma-ddr4, make sdma-hbm3, ...
sdma-%:
	@$(MAKE) sdma DRAM=$*

gen_sdma_meminit:
	python3 $(RAM_DIR)/gen_sdma_meminit.py

# ============================================================
# AXI bus standalone waveform runs
# ============================================================
# Usage:
#   make wav TB=<name>           # batch, loads <name>.do, runs $(SIMTIME)
#   make wav TB=<name> GUI=ON    # waveform GUI
#   make wav TB=<name> DO=my.do SIMTIME=500us
#   make wav-<name>              # shorthand (batch)
#   make wav_gui-<name>          # shorthand (GUI)
#
# Looks for:
#   TB   : $(AXI_TB_DIR)/<name>_tb.sv
#   .do  : $(AXI_SCRIPT_DIR)/<name>.do   (override with DO=...)
#   srcs : all .sv under $(AXI_MOD_DIR)
wav:
	@if [ -z "$(TB)" ]; then \
	    echo "Usage: make wav TB=<tb_basename> [DO=path] [SIMTIME=<t>] [GUI=ON]"; exit 1; \
	fi; \
	TB_FILE="$(AXI_TB_DIR)/$(TB)_tb.sv"; \
	DO_FILE="$${DO:-$(AXI_SCRIPT_DIR)/$(TB).do}"; \
	[ -f "$$TB_FILE" ] || { echo "[wav] TB not found: $$TB_FILE"; exit 2; }; \
	[ -f "$$DO_FILE" ] || { echo "[wav] .do not found: $$DO_FILE (override with DO=...)"; exit 2; }; \
	echo "[wav] cleaning work..."; \
	rm -rf $(SCRATCH); \
	$(VLIB64) $(SCRATCH); \
	echo "[wav] compiling $(TB)_tb + axi_bus sources..."; \
	$(VLOG64) $(VLOG_FLAGS) $(VLOG_COV_FLAGS) \
	    +incdir+$(AXI_INC_DIR) \
	    $$TB_FILE $(AXI_MOD_SRCS); \
	echo "[wav] running $(if $(filter ON,$(GUI)),GUI,batch) ($(SIMTIME))..."; \
	if [ "$(GUI)" = "ON" ]; then \
	    $(VSIM64) $(VSIM_COV_FLAGS) $(VSIM_FLAGS) \
	        $(SCRATCH).$(TB)_tb \
	        -do "do $$DO_FILE; run $(SIMTIME);" \
	        -suppress 2275; \
	else \
	    $(VSIM64) $(VSIM_COV_FLAGS) -c $(VSIM_FLAGS) \
	        $(SCRATCH).$(TB)_tb \
	        -do "do $$DO_FILE; run $(SIMTIME); quit -f" \
	        -suppress 2275; \
	fi

wav_gui:
	@$(MAKE) wav GUI=ON TB=$(TB)

# Pattern: make wav-<name>, make wav_gui-<name>
wav-%:
	@$(MAKE) wav TB=$*

wav_gui-%:
	@$(MAKE) wav GUI=ON TB=$*
