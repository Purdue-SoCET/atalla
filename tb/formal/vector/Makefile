CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -g -Iinclude

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

SYSARR_EXE = $(BIN_DIR)/sysarr_test
SCRATCH_EXE = $(BIN_DIR)/scratch_test
SCHED_EXE = $(BIN_DIR)/schedular_test
VEGGIE_EXE = $(BIN_DIR)/veggie_test

.PHONY: compile_sysarr compile_scratch verilate run_verilator clean

# Verilator config
PROJECT_ROOT = ../../..
RTL_ROOT = $(PROJECT_ROOT)/rtl
RTL_INCLUDE = $(RTL_ROOT)/include
RTL_MODULES = $(RTL_ROOT)/modules
TB_DIR = .

# Verilator settings
VERILATOR = verilator
VERILATOR_FLAGS = --cc --exe -Wall
VERILATOR_FLAGS += --trace
VERILATOR_FLAGS += -Wno-DECLFILENAME -Wno-WIDTH -Wno-UNOPTFLAT -Wno-CASEINCOMPLETE -Wno-UNUSED -Wno-SYNCASYNCNET -Wno-MODDUP -Wno-PINMISSING -Wno-IMPORTSTAR -Wno-VARHIDDEN -Wno-UNPACKED -Wno-UNDRIVEN

# Pass C++ compiler flags to Verilator (for testbench compilation)
# Use $(CURDIR) to get absolute path to current directory
VERILATOR_FLAGS += -CFLAGS "-I$(CURDIR)/$(INCLUDE_DIR) -std=c++17 -g -Wall -Wextra"

# Link VCD tracing library
VERILATOR_FLAGS += -LDFLAGS "-lz"

# RTL include directories
VERILATOR_FLAGS += -I$(RTL_INCLUDE)/common/arithmetic/sqrt
VERILATOR_FLAGS += -I$(RTL_INCLUDE)/common/arithmetic/divider
VERILATOR_FLAGS += -I$(RTL_INCLUDE)/common/arithmetic/exp
VERILATOR_FLAGS += -I$(RTL_INCLUDE)/common/arithmetic/adders
VERILATOR_FLAGS += -I$(RTL_INCLUDE)/common/arithmetic/multipliers
VERILATOR_FLAGS += -I$(RTL_INCLUDE)/common/xbar
VERILATOR_FLAGS += -I$(RTL_INCLUDE)/vector
VERILATOR_FLAGS += -I$(RTL_INCLUDE)/vector/reduction
VERILATOR_FLAGS += -I$(RTL_MODULES)/vector

TOP_MODULE = lane_wrapper
VERILATOR_OBJ_DIR = obj_dir_verilator
VERILATOR_LOG = verilator_build.log

# RTL sources
RTL_SOURCES = $(wildcard $(RTL_MODULES)/common/arithmetic/adders/*.sv)
RTL_SOURCES += $(wildcard $(RTL_MODULES)/common/arithmetic/dividers/*.sv)
RTL_SOURCES += $(wildcard $(RTL_MODULES)/common/arithmetic/mutlipliers/*.sv)
RTL_SOURCES += $(RTL_MODULES)/common/general/fifo.sv
RTL_SOURCES += $(wildcard $(RTL_MODULES)/common/arithmetic/sqrt/*.sv)
RTL_SOURCES += $(wildcard $(RTL_MODULES)/common/arithmetic/exp/*.sv)
RTL_SOURCES += $(RTL_INCLUDE)/common/xbar/xbar_pkg.sv
RTL_SOURCES += $(RTL_MODULES)/vector/lane.sv
RTL_SOURCES += $(RTL_MODULES)/vector/lane_sequencer.sv
RTL_SOURCES += $(RTL_MODULES)/vector/lane_fu_pt.sv
RTL_SOURCES += $(RTL_MODULES)/vector/valu.sv
RTL_SOURCES += $(RTL_MODULES)/vector/sync_fifo.sv
RTL_SOURCES += $(RTL_MODULES)/vector/rc_fu.sv
RTL_SOURCES += $(SRC_DIR)/lane_wrapper.sv


# PERF TEST SOURCES
PERF_TB_SOURCES = $(SRC_DIR)/perf_test.cpp
PERF_EXE = $(BIN_DIR)/perf_test

# Verilate for perf test
perf_verilate:
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module $(TOP_MODULE) \
		--Mdir $(VERILATOR_OBJ_DIR) \
		$(RTL_SOURCES) \
		$(PERF_TB_SOURCES) 2>&1 | tee $(VERILATOR_LOG)

# Run perf test
run_perf: perf_verilate
	$(MAKE) -j -C $(VERILATOR_OBJ_DIR) -f V$(TOP_MODULE).mk V$(TOP_MODULE)
	./$(VERILATOR_OBJ_DIR)/V$(TOP_MODULE)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(VERILATOR_OBJ_DIR) $(VERILATOR_LOG)
	rm *.txt