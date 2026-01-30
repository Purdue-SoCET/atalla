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
VERILATOR_FLAGS = --cc --exe --build -Wall
VERILATOR_FLAGS += --trace
VERILATOR_FLAGS += -Wno-DECLFILENAME -Wno-TIMESCALEMOD -Wno-UNUSEDSIGNAL
VERILATOR_FLAGS += -Wno-UNUSEDPARAM -Wno-PINMISSING -Wno-UNDRIVEN -Wno-WIDTHEXPAND

# Pass C++ compiler flags to Verilator (for testbench compilation)
# Use $(CURDIR) to get absolute path to current directory
VERILATOR_FLAGS += -CFLAGS "-I$(CURDIR)/$(INCLUDE_DIR) -std=c++17 -g -Wall -Wextra"

# Link VCD tracing library
VERILATOR_FLAGS += -LDFLAGS "-lz"

# RTL include directories
VERILATOR_FLAGS += -I$(RTL_INCLUDE)common/arithmetic/sqrt
VERILATOR_FLAGS += -I$(RTL_INCLUDE)common/arithmetic/divider
VERILATOR_FLAGS += -I$(RTL_INCLUDE)common/arithmetic/multipliers
VERILATOR_FLAGS += -I$(RTL_INCLUDE)common/xbar
VERILATOR_FLAGS += -I$(RTL_INCLUDE)vector
VERILATOR_FLAGS += -I$(RTL_INCLUDE)systolic_array




TOP_MODULE = vector_core_wrapper
VERILATOR_OBJ_DIR = obj_dir_verilator
VERILATOR_LOG = verilator_build.log

# RTL sources
RTL_SOURCES = $(wildcard $(RTL_MODULES)/common/arithmetic/adders/*.sv)
RTL_SOURCES = $(wildcard $(RTL_MODULES)/common/arithmetic/dividers/*.sv)
RTL_SOURCES = $(wildcard $(RTL_MODULES)/common/arithmetic/multipliers/*.sv)
RTL_SOURCES = $(wildcard $(RTL_MODULES)/common/arithmetic/sqrt/*.sv)
RTL_SOURCES = $(wildcard $(RTL_MODULES)/common/arithmetic/exp/*.sv)
RTL_SOURCES += $(wildcard $(RTL_MODULES)/vector/*.sv)
RTL_SOURCES += $(wildcard $(RTL_MODULES)/vector/reduction/*.sv)

# VERILATOR TESTBENCH SOURCES - ONLY these files, NOT the _test.cpp files
TB_SOURCES = $(SRC_DIR)/testbench.cpp
TB_SOURCES += $(SRC_DIR)/scratchpad.cpp
TB_SOURCES += $(SRC_DIR)/sysarr.cpp
TB_SOURCES += $(SRC_DIR)/schedular.cpp
TB_SOURCES += $(SRC_DIR)/veggie.cpp
# DO NOT include sysarr_test.cpp or scratch_test.cpp here!

# Verilate the design
verilate:
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module $(TOP_MODULE) \
		--Mdir $(VERILATOR_OBJ_DIR) \
		$(RTL_SOURCES) \
		$(TB_SOURCES) 2>&1 | tee $(VERILATOR_LOG)

# Run verilated simulation
run_verilator: verilate
	./$(VERILATOR_OBJ_DIR)/V$(TOP_MODULE)

# Make directories
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# Compile objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build sysarr_test
compile_sysarr: $(OBJ_DIR)/sysarr.o $(OBJ_DIR)/sysarr_test.o $(OBJ_DIR)/scratchpad.o | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $(SYSARR_EXE)

# Build scratch_test
compile_scratch: $(OBJ_DIR)/sysarr.o $(OBJ_DIR)/scratch_test.o $(OBJ_DIR)/scratchpad.o | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $(SCRATCH_EXE)

compile_schedular: $(OBJ_DIR)/sysarr.o $(OBJ_DIR)/schedular.o $(OBJ_DIR)/schedular_test.o $(OBJ_DIR)/scratchpad.o | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $(SCHED_EXE)
	
compile_veggie: $(OBJ_DIR)/veggie_test.o  $(OBJ_DIR)/veggie.o | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $(VEGGIE_EXE)
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(VERILATOR_OBJ_DIR) $(VERILATOR_LOG)
	rm *.txt
	rm *.vcd