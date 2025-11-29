CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g -Iinclude

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

SYSARR_EXE = $(BIN_DIR)/sysarr_test
SCRATCH_EXE = $(BIN_DIR)/scratch_test

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

# Pass C++ compiler flags to Verilator (for testbench compilation)
VERILATOR_FLAGS += -CFLAGS "-I$(INCLUDE_DIR) -std=c++17 -g -Wall -Wextra"

# RTL include directories
VERILATOR_FLAGS += -I$(RTL_INCLUDE)
VERILATOR_FLAGS += -I$(RTL_INCLUDE)/common/arithmetic/divider
VERILATOR_FLAGS += -I$(RTL_INCLUDE)/common/arithmetic/sqrt
VERILATOR_FLAGS += -I$(RTL_INCLUDE)/vector

TOP_MODULE = vector_top
VERILATOR_OBJ_DIR = obj_dir_verilator

# RTL sources
RTL_SOURCES = $(shell find $(RTL_MODULES)/common/arithmetic -name "*.sv")
RTL_SOURCES += $(wildcard $(RTL_MODULES)/vector/*.sv)

TB_SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Verilate the design
verilate:
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module $(TOP_MODULE) \
		--Mdir $(VERILATOR_OBJ_DIR) \
		$(RTL_SOURCES) \
		$(TB_SOURCES)

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

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(VERILATOR_OBJ_DIR)