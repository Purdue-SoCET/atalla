# --- Configuration ---
set TB_FILE ./tb/unit/ddr_cntrl/testbench/dram_top_tb.sv
set TB_TOP  dram_top_tb

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
    "+incdir+./protected_modelsim" \
]

# --- Design & Interface Sources ---
set DESIGN_SRCS {
    ./rtl/include/ddr_cntrl/dram_pkg.svh
    ./rtl/include/ddr_cntrl/ddr_controller_if.sv
    ./protected_modelsim/arch_defines.v
    ./protected_modelsim/dimm.vh
    ./protected_modelsim/ddr4_model.svp
    ./rtl/modules/ddr_cntrl/ddr_controller_wrapper.sv
    ./rtl/modules/ddr_cntrl/ddr_controller.sv
    ./rtl/modules/ddr_cntrl/nb_barb.sv
    ./rtl/modules/ddr_cntrl/flex_counter.sv
    ./rtl/modules/ddr_cntrl/flex_sr.sv
    ./rtl/modules/ddr_cntrl/priority_enc.sv
    ./rtl/modules/ddr_cntrl/enum_compare.sv
    ./rtl/modules/ddr_cntrl/command_scheduler.sv
    ./rtl/modules/ddr_cntrl/command_arbiter.sv
    ./rtl/modules/ddr_cntrl/command_generator.sv
    ./rtl/modules/ddr_cntrl/data_transfer.sv
    ./rtl/modules/ddr_cntrl/refresh_controller.sv
    ./rtl/modules/ddr_cntrl/timing_controller.sv
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

# --- Compilation ---
vlog -sv -compile_uselibs -cover bst -coveropt 1 -sv -pedanticerrors -lint -mfcu {*}$INC_FLAGS {*}$SRC_FILES

puts "=============================================================="
puts "Compilation complete. Launching simulation for $TB_TOP"
puts "=============================================================="

# --- Elaboration & Simulation ---
vsim -coverage -voptargs="+acc" work.$TB_TOP -onfinish stop;

if {[file exists "./waves/dram_top_tb.do"]} {
    puts "Applying wave configurations from ./waves/dram_top_tb.do"
    do ./waves/dram_top_tb.do
} else {
    puts "WARNING: No .do file found at ./waves/dram_top_tb.do"
}

# 4. Execution
puts "=============================================================="
puts "Starting Simulation..."
puts "=============================================================="

run -all

# Save all coverage (Code + Functional) to a Unified Coverage Data Base
coverage save dram_top_sim.ucdb

# View the functional coverage summary in the transcript
vcover report -cvg -details dram_top_sim.ucdb