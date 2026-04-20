# --- Configuration ---
set TB_FILE ./tb/unit/ddr_cntrl/testbench/frontend_tb.sv
set TB_TOP  frontend_tb

if {![info exists TB_FILE]} {
    puts "ERROR: TB_FILE not set. Use:  vsim -c -do \"set TB_FILE <path>; set TB_TOP <top>; do test.tcl\""
    quit -f
}
if {![info exists TB_TOP]} {
    puts "ERROR: TB_TOP not set. Use:  vsim -c -do \"set TB_FILE <path>; set TB_TOP <top>; do test.tcl\""
    quit -f
}

puts "Testbench file : $TB_FILE"
puts "Top module     : $TB_TOP"

# --- Include Directories ---
set INC_FLAGS [list \
    "+incdir+./rtl/include/ddr_cntrl" \
]

# --- Design & Interface Sources ---
set DESIGN_SRCS {
    ./rtl/include/ddr_cntrl/dram_pkg.svh
    ./rtl/include/ddr_cntrl/address_mapper_if.vh
    ./rtl/include/ddr_cntrl/ddr_controller_if.sv
    ./rtl/modules/ddr_cntrl/address_mapper.sv
    ./rtl/modules/ddr_cntrl/nb_store_queue.sv
    ./rtl/modules/ddr_cntrl/load_queue_nb.sv
    ./rtl/modules/ddr_cntrl/frontend_arb_nb.sv
    ./rtl/modules/ddr_cntrl/frontend_wrapper.sv
}

set SRC_FILES [concat $DESIGN_SRCS [list $TB_FILE]]

puts "INC_FLAGS  : $INC_FLAGS"
puts "SRC_FILES  : $SRC_FILES"
puts "Num sources: [llength $SRC_FILES]"

# --- Library Setup ---
if {![file exists work]} {
    vlib work
}
vmap work work

# --- Compilation (with coverage) ---
vlog -sv -mfcu -cover bcsxf {*}$INC_FLAGS {*}$SRC_FILES

puts "=============================================================="
puts "Compilation complete. Launching simulation for $TB_TOP"
puts "=============================================================="

# --- Elaboration & Simulation (with coverage) ---
vsim -voptargs="+acc" -coverage work.$TB_TOP

# --- Load Waveform Script ---
do ./waves/frontend.do

run -all

# --- Zoom waveform to show full run ---
catch {wave zoom full}

# --- Coverage Report ---
coverage report -detail -output ./reports/ddr_cntrl/frontend_coverage.txt
coverage save ./reports/ddr_cntrl/frontend_coverage.ucdb

puts "=============================================================="
puts "Coverage saved to ./reports/ddr_cntrl/frontend_coverage.ucdb"
puts "Coverage report: ./reports/ddr_cntrl/frontend_coverage.txt"
