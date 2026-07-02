# Ramulator2 + AXI Bus Setup Guide

This page explains how to set up **CMU-SAFARI Ramulator2** inside the `atalla` repository and use it with our **AXI Bus**.

Run all commands from the `atalla` root unless stated otherwise.

> [!IMPORTANT]
> This work was primarily achieved by Heng-I (Ivor) Chu and Akram Reda during Spring '26. This documentation was reverse-engineered from their work.

Useful links:

* For quick setup, go to [Installation](#installation)
* For a basic Ramulator test, go to [Basic Ramulator AXI Test](#basic-ramulator-axi-test)
* For the SDMA benchmark, go to [SDMA Test](#sdma-test)

Note: While the names below mention "RamulatorWrapper", it is the official code which acts as the bridge to AXI. It does NOT contain sample scripts/files. Feel free to repurpose them, but don't edit them at will.

---

## What is Ramulator2?

**Ramulator2** is a modern, modular, cycle-level DRAM simulator from CMU-SAFARI. It models DRAM systems such as **DDR3, DDR4, DDR5, LPDDR5, GDDR6, HBM2, and HBM3** using configurable YAML files.

In our project, Ramulator2 replaces the need to hard-code behavior for one fixed custom DDR4 (blocking/non-blocking) controller. We can connect our **AXI Bus** to a Ramulator2-backed memory model and quickly evaluate different memory standards and timing configurations.

Ramulator2 is especially useful for architecture exploration. Our accelerator can now compare:

* DDR3 vs DDR4 vs DDR5
* HBM2 vs HBM3
* Different timing parameters
* Different bandwidth/latency tradeoffs
* Custom memory configurations (X channels vs Y channel-width)

It can also help answer:

* Is the accelerator compute-bound or memory-bound?
* Does HBM improve throughput for our workload?
* How much does DDR5 help compared to DDR4?
* Are burst patterns efficient for the selected memory standard?
* How sensitive is performance to memory latency and bandwidth?

---

## Installation

The original Ramulator2 repository can be found [here](https://github.com/CMU-SAFARI/ramulator2).

Ramulator2 is included in `atalla` as a **git submodule**. After cloning `atalla`, initialize the submodule:

```bash
git submodule update --init --recursive
```

Then build the Ramulator DPI shared library:

```bash
make ram_lib
```

This should generate:

```text
libramulator_dpi.so
```

This shared library is loaded by QuestaSim using:

```bash
-sv_lib ./libramulator_dpi
```

---

## Makefile Setup

The Ramulator flow depends on:

* **CMake**
* **Make**
* **C++20-capable compiler**
* **QuestaSim 64-bit**
* Access to the Purdue Questa license server

On Purdue ECN machines, the Makefile uses:

```make
QUESTA_BIN ?= /package/eda/mg/questa2021.4/questasim/bin
MGLS_LICENSE_FILE ?= 28000@marina.ecn.purdue.edu
```

Ramulator2 requires a modern C++ compiler, so the Makefile uses GCC 14:

```make
GCC14_CXX := /opt/rh/gcc-toolset-14/root/usr/bin/g++
GCC14_CC  := /opt/rh/gcc-toolset-14/root/usr/bin/gcc
GCC14_LIB := /opt/rh/gcc-toolset-14/root/lib64
```

The main wrapper paths are:

```make
RAM_DIR := ./rtl/modules/memory/ramulator_wrapper
AXIROOT := ./rtl/include/memory/axi_bus 
DPIROOT := $(RAM_DIR) -> DPI wrapper directory  
TBROOT  := ./tb/unit/memory/ramulator_wrapper
CFGROOT := $(RAM_DIR)/configs  -> Ramulator YAML config directory
```

---

## DRAM Configuration

The default DRAM model is **DDR4**:

```make
DRAM ?= ddr4
```

Supported configs:

```make
DRAM_CFG_ddr3   := $(CFGROOT)/ddr3_config.yaml
DRAM_CFG_ddr4   := $(CFGROOT)/ddr4_config.yaml
DRAM_CFG_ddr5   := $(CFGROOT)/ddr5_config.yaml
DRAM_CFG_gddr6  := $(CFGROOT)/gddr6_config.yaml
DRAM_CFG_hbm2   := $(CFGROOT)/hbm2_config.yaml
DRAM_CFG_hbm3   := $(CFGROOT)/hbm3_config.yaml
DRAM_CFG_lpddr5 := $(CFGROOT)/lpddr5_config.yaml

CFG ?= $(DRAM_CFG_$(DRAM))
```

Run with a specific DRAM standard:

```bash
make sim DRAM=ddr3
make sim DRAM=ddr4
make sim DRAM=hbm3
```

Run with a custom YAML config:

```bash
make sim CFG=rtl/modules/memory/ramulator_wrapper/configs/my_custom_config.yaml
```

---

## Basic Ramulator AXI Test

Run the default DDR4 simulation:

```bash
make sim
```

This target:

1. Builds `libramulator_dpi.so`
2. Compiles the AXI package/interface
3. Compiles the Ramulator SV wrapper and testbench
4. Runs `test_ramulator`

Relevant sources:

```make
AXI_SRCS := \
	$(AXIROOT)/axi_bus_pkg.sv \
	$(AXIROOT)/axi_bus_if.sv

DPI_SRCS := \
	$(DPIROOT)/ramulator_sv_wrapper.sv \
	$(TBROOT)/test_ramulator.sv
```

The simulation loads the Ramulator shared library and passes the YAML config into the testbench:

```make
$(VSIM64) -c -voptargs="+acc" \
    -sv_lib ./libramulator_dpi \
    -G CFG="$(CFG)" \
    work.test_ramulator \
    -do "run -all"
```

Expected result:

```text
[sim] Result: PASSED
```

---

## Questa GUI

Open the waveform GUI:

```bash
make sim GUI=ON
```

Equivalent shorthand:

```bash
make sim_gui
```

The GUI flow expects this wave script:

```text
./waves/test_ramulator.do
```

If this file does not exist, the simulation may still run, but waveform setup will not load automatically.

---

## Memory Preload

Use memory preload when the AXI/Ramulator testbench needs memory contents initialized before simulation.

Makefile variables:

```make
MEMINIT      ?=
MEMINIT_TYPE ?= hex
MEMINIT_BASE ?= 0
```

Basic usage:

```bash
make sim MEMINIT=path/to/meminit.hex
```

With explicit type and base address:

```bash
make sim \
  MEMINIT=path/to/meminit.hex \
  MEMINIT_TYPE=hex \
  MEMINIT_BASE=0
```

These are passed into QuestaSim as generics:

```make
-G MEM_INIT_FILE="$(MEMINIT)"
-G MEM_INIT_TYPE="$(MEMINIT_TYPE)"
-G MEM_INIT_BASE=$(MEMINIT_BASE)
-G USE_MEMINIT=1
```

---

## SDMA Test

The SDMA kernel/instruction is responsible for loading an entire matrix (maximum 32x32) into the Scratchpad. This procedure involves the Scratchpad, AXI Bus and Memory Controller.

1. First, generate the SDMA memory initialization binary. Read the file to understand how memory is laid out into a `*.bin` file.

```bash
python3 rtl/modules/memory/ramulator_wrapper/gen_sdma_meminit.py
```

2. Run the SDMA testbench with the generated file:

```bash
make sdma \
  GUI=ON \
  DRAM=ddr4 \
  SDMA_MEMINIT=rtl/modules/memory/ramulator_wrapper/configs/sdma_meminit.bin \
  SDMA_MEMINIT_TYPE=bin \
  SDMA_MEMINIT_BASE=0
```

Notes:

* Remove `GUI=ON` if the GUI is not needed.
* `ddr4` is the default DRAM config.

Relevant sources:

```make
SDMA_SRCS := \
	$(DPIROOT)/ramulator_sv_wrapper.sv \
	$(TBROOT)/test_sdma.sv
```

---

## Clean Build Artifacts

Clean simulation artifacts:

```bash
make clean
```

This removes:

```text
work/
transcript
vsim.wlf
vsim_stacktrace.vstf
modelsim.ini
```

For a full Ramulator rebuild, also remove:

```bash
rm -rf build libramulator_dpi.so
```

Then rebuild:

```bash
make ram_lib
make sim
```

---

## Common Commands

```bash
# Initialize Ramulator2 submodule
git submodule update --init --recursive

# Build Ramulator DPI shared library
make ram_lib

# Run default DDR4 test
make sim

# Run with HBM3
make sim DRAM=hbm3

# Run with GUI
make sim GUI=ON

# Generate SDMA memory init binary
python3 rtl/modules/memory/ramulator_wrapper/gen_sdma_meminit.py

# Run SDMA test
make sdma \
  DRAM=ddr4 \
  SDMA_MEMINIT=rtl/modules/memory/ramulator_wrapper/configs/sdma_meminit.bin \
  SDMA_MEMINIT_TYPE=bin \
  SDMA_MEMINIT_BASE=0

# Clean
make clean
```
