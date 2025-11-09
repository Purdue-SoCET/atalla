###########################################################################################
# STARS 2025 - Makefile for SystemVerilog Projects
# By Miguel Isrrael Teran, Alex Weyer, Johnny Hazboun, Ben Miller
# 
# Set tab spacing to 2 spaces per tab for best viewing results
###########################################################################################

export PATH := /home/shay/a/ece270/bin:$(PATH)
export LD_LIBRARY_PATH := /home/shay/a/ece270/lib:$(LD_LIBRARY_PATH)

YOSYS=yosys
NEXTPNR=nextpnr-ice40
SHELL=bash

MAP = mapped
TB	=  testbench
SRC = source
BUILD = build

FPGA_TOP = top
ICE   	= support/ice40hx8k.sv
UART	= support/uart*.v
PINMAP = support/pinmap.pcf
FPGA_TIMING_CELLS = support/*.v

DEVICE  = 8k
TIMEDEV = hx8k
FOOTPRINT = ct256

help:
	@echo -e "Help..."
	@cat support/help.txt

# *******************************************************************************
# COMPILATION & SIMULATION TARGETS
# *******************************************************************************

# sv2v target
.PHONY: sv2v_%
sv2v_%:
	@mkdir -p $(SRC)/converted_modules
	@sv2v -y $(SRC) -w $(SRC)/converted_modules $(SRC)/$*.sv

.PHONY: sim_%_src_converted
sim_%_src_converted:
	@echo -e "Creating executable for source simulation...\n"
	@mkdir -p $(BUILD) && rm -rf $(BUILD)/*
	@iverilog -g2012 -o $(BUILD)/$*_tb -Y .v -y $(SRC)/converted_modules $(TB)/$*_tb.sv
	@echo -e "\nSource Compilation complete!\n"
	@echo -e "Simulating source...\n"
	@vvp -l vvp_sim.log $(BUILD)/$*_tb
	@echo -e "\nSimulation complete!\n"
	@echo -e "\nOpening waveforms...\n"
	@if [ -f waves/$*.gtkw ]; then \
		gtkwave waves/$*.gtkw; \
	else \
		gtkwave waves/$*.vcd; \
	fi


# Source Compilation and simulation of Design
.PHONY: sim_%_src
sim_%_src: 
	@echo -e "Creating executable for source simulation...\n"
	@mkdir -p $(BUILD) && rm -rf $(BUILD)/*
	@iverilog -g2012 -o $(BUILD)/$*_tb -Y .sv -y $(SRC) $(TB)/$*_tb.sv
	@echo -e "\nSource Compilation complete!\n"
	@echo -e "Simulating source...\n"
	@vvp -l vvp_sim.log $(BUILD)/$*_tb
	@echo -e "\nSimulation complete!\n"
	@echo -e "\nOpening waveforms...\n"
	@if [ -f waves/$*.gtkw ]; then \
		gtkwave waves/$*.gtkw; \
	else \
		gtkwave waves/$*.vcd; \
	fi


# Run synthesis on Design
.PHONY: syn_%
syn_%:
	@echo -e "Synthesizing design...\n"
	@mkdir -p $(MAP)
	$(YOSYS) -p "read_verilog -sv -noblackbox $(SRC)/*; synth_ice40 -top $*; clean; write_verilog $(MAP)/$*.v"
	@echo -e "\nSynthesis complete!\n"


# Compile and simulate synthesized design
.PHONY: sim_%_syn
sim_%_syn: syn_%
	@echo -e "Compiling synthesized design...\n"
	@mkdir -p $(BUILD) && rm -rf $(BUILD)/*
	@iverilog -g2012 -o $(BUILD)/$*_tb -DFUNCTIONAL -DUNIT_DELAY=#1 $(TB)/$*_tb.sv $(MAP)/$*.v $(FPGA_TIMING_CELLS)
	@echo -e "\nCompilation complete!\n"
	@echo -e "Simulating synthesized design...\n\n"
	@vvp -l vvp_sim.log $(BUILD)/$*_tb
	@echo -e "\nSimulation complete!\n"
	@echo -e "\nOpening waveforms...\n"
	@if [ -f waves/$*.gtkw ]; then \
		gtkwave waves/$*.gtkw; \
	else \
		gtkwave waves/$*.vcd; \
	fi


# Lint Design Only
.PHONY: vlint_%
vlint_%:
	@verilator --lint-only -Wall --timing -y $(SRC) $(SRC)/$*.sv $(TB)/$*_tb.sv
	@echo -e "\nNo linting errors found!\n"
 	

# Compile and simulate synthesized design
.PHONY: cells_%
cells_%: $(ICE) $(SRC) $(PINMAP)
	# lint with Verilator
	verilator --lint-only --top-module top -Werror-latch -y $(SRC) $(SRC)/top.sv
	# if build folder doesn't exist, create it
	mkdir -p $(BUILD)
	# synthesize using Yosys
	$(YOSYS) -p "read_verilog -sv -noblackbox $(ICE) $(UART) $(SRC)/*; synth -top $*; cd $*; show -format svg -viewer gimp"

# *******************************************************************************
# FPGA TARGETS
# *******************************************************************************

# Check code and synthesize design into a JSON netlist
$(BUILD)/$(FPGA_TOP).json : $(ICE) $(SRC)/* $(PINMAP)
	# lint with Verilator
	verilator --lint-only --top-module top -Werror-latch -y $(SRC) $(SRC)/top.sv
	# if build folder doesn't exist, create it
	mkdir -p $(BUILD)
	# synthesize using Yosys
	$(YOSYS) -p "read_verilog -sv -noblackbox $(ICE) $(UART) $(SRC)/*; synth_ice40 -top ice40hx8k -json $(BUILD)/$(FPGA_TOP).json"


# Place and route design using nextpnr
$(BUILD)/$(FPGA_TOP).asc : $(BUILD)/$(FPGA_TOP).json
	# Place and route using nextpnr
	$(NEXTPNR) --hx8k --package ct256 --placer-heap-cell-placement-timeout 0 --pcf $(PINMAP) --asc $(BUILD)/$(FPGA_TOP).asc --json $(BUILD)/$(FPGA_TOP).json 2> >(sed -e 's/^.* 0 errors$$//' -e '/^Info:/d' -e '/^[ ]*$$/d' 1>&2)


# Convert to bitstream using IcePack
$(BUILD)/$(FPGA_TOP).bin : $(BUILD)/$(FPGA_TOP).asc
	# Convert to bitstream using IcePack
	icepack $(BUILD)/$(FPGA_TOP).asc $(BUILD)/$(FPGA_TOP).bin


# Perform timing analysis on FPGA design
time: $(BUILD)/$(FPGA_TOP).asc
	# Re-synthesize
	$(YOSYS) -p "read_verilog -sv -noblackbox $(ICE) $(UART) $(SRC)/*; synth_ice40 -top ice40hx8k -json $(BUILD)/$(FPGA_TOP).json"
	# Place and route using nextpnr
	$(NEXTPNR) --hx8k --package ct256 --placer-heap-cell-placement-timeout 0 --asc $(BUILD)/$(FPGA_TOP).asc --json $(BUILD)/$(FPGA_TOP).json 2> >(sed -e 's/^.* 0 errors$$//' -e '/^Info:/d' -e '/^[ ]*$$/d' 1>&2)
	icetime -tmd hx8k $(BUILD)/$(FPGA_TOP).asc


# Upload design to the FPGA's flash memory
flash: $(BUILD)/$(FPGA_TOP).bin
	# Program non-volatile flash memory with FPGA bitstream using iceprog
	iceprog $(BUILD)/$(FPGA_TOP).bin


# Upload design to the FPGA's non-volatile RAM
cram: $(BUILD)/$(FPGA_TOP).bin
	# Program volatile FPGA Configuration RAM (CRAM) with bitstream using iceprog
	iceprog -S $(BUILD)/$(FPGA_TOP).bin

#Show the synthesied diagram
cells : $(ICE) $(SRC) $(PINMAP)
	# lint with Verilator
	verilator --lint-only --top-module top -Werror-latch -y $(SRC) $(SRC)/top.sv
	# if build folder doesn't exist, create it
	mkdir -p $(BUILD)
	# synthesize using Yosys
	$(YOSYS) -p "read_verilog -sv -noblackbox $(ICE) $(UART) $(SRC)/*; synth -top top; cd top; show -format svg -viewer gimp"

#Show the synthesied diagram
fpga-cells : $(ICE) $(SRC) $(PINMAP)
	# lint with Verilator
	verilator --lint-only --top-module top -Werror-latch -y $(SRC) $(SRC)/top.sv
	# if build folder doesn't exist, create it
	mkdir -p $(BUILD)
	# synthesize using Yosys
	$(YOSYS) -p "read_verilog -sv -noblackbox $(ICE) $(UART) $(SRC)/*; synth_ice40 -top top; show -format svg -viewer gimp"

# Combination Lock Demo
.PHONY: lock_demo
lock_demo:
	mkdir -p $(BUILD)
	$(YOSYS) -p "read_verilog -sv $(ICE) support/lock_bb_top.sv support/blackbox_lock.v $(UART); synth_ice40 -top ice40hx8k; write_json $(BUILD)/$(FPGA_TOP).json"
	$(NEXTPNR) --hx8k --package ct256 --placer-heap-cell-placement-timeout 0 --pcf $(PINMAP) --asc $(BUILD)/$(FPGA_TOP).asc --json $(BUILD)/$(FPGA_TOP).json 2> >(sed -e 's/^.* 0 errors$$//' -e '/^Info:/d' -e '/^[ ]*$$/d' 1>&2)
	icepack $(BUILD)/$(FPGA_TOP).asc $(BUILD)/$(FPGA_TOP).bin
	iceprog -S $(BUILD)/$(FPGA_TOP).bin

# Clean temporary files
clean:
	rm -rf build/ mapped/ *.log waves/*.vcd
