# --- Configuration ---
set TB_FILE ./tb/unit/ddr_cntrl/testbench/init_state_tb.sv
set TB_TOP  init_state_tb

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
    ./rtl/include/ddr_cntrl/ddr_controller_if.sv
    ./rtl/modules/ddr_cntrl/flex_counter.sv
    ./rtl/modules/ddr_cntrl/init_state.sv
}

set SRC_FILES [concat $DESIGN_SRCS [list $TB_FILE]]

puts "INC_FLAGS  : $INC_FLAGS"
puts "SRC_FILES  : $SRC_FILES"
puts "Num sources: [llength $SRC_FILES]"

# --- Library Setup ---
if {[file exists work]} {
    file delete -force work
}
vlib work
vmap work work

# --- Compilation ---
vlog -sv -mfcu +cover=sbceft {*}$INC_FLAGS {*}$SRC_FILES

puts "=============================================================="
puts "Compilation complete. Launching simulation for $TB_TOP"
puts "=============================================================="

# --- Elaboration & Simulation ---
vsim -voptargs="+acc" -coverage work.$TB_TOP

# --- Load Waveform Configuration ---
do ./waves/init_state_tb.do

run -all

# --- Coverage Report ---
file mkdir ./reports/ddr_cntrl
coverage save -onexit ./reports/ddr_cntrl/init_state_coverage.ucdb
coverage report -detail -output ./reports/ddr_cntrl/init_state_coverage.txt

puts "=============================================================="
puts "Simulation finished. Close the GUI manually when done."
puts "=============================================================="
