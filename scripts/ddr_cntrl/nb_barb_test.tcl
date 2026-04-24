# --- Configuration ---
set TB_FILE ./tb/unit/ddr_cntrl/testbench/nb_barb_tb.sv
set TB_TOP  nb_barb_tb

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
# Using the ddr_cntrl folder where your .svh files live
set INC_FLAGS [list \
    "+incdir+./rtl/include/ddr_cntrl" \
]

# --- Design & Interface Sources ---
set DESIGN_SRCS {
    ./rtl/include/ddr_cntrl/dram_pkg.svh
    ./rtl/include/ddr_cntrl/ddr_controller_if.sv
    ./rtl/modules/ddr_cntrl/flex_counter.sv
    ./rtl/modules/ddr_cntrl/flex_sr.sv
    ./rtl/modules/ddr_cntrl/priority_enc.sv
    ./rtl/modules/ddr_cntrl/init_state.sv
    ./rtl/modules/ddr_cntrl/nb_barb.sv
}

# --- Verification / Bind Sources ---
# If you decide to use the bind file or a separate property module, add it here
# set VERIF_SRCS [list \
#   ./tb/unit/ddr_cntrl/testbench/nb_barb_prop.sv \
# ] 

# ADD $VERIF_SRCS 
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
# -mfcu (Multi-File Compilation Unit) is good here to resolve cross-file dependencies
vlog -sv -compile_uselibs -cover bst -coveropt 1 -sv -pedanticerrors -lint -mfcu {*}$INC_FLAGS {*}$SRC_FILES

puts "=============================================================="
puts "Compilation complete. Launching simulation for $TB_TOP"
puts "=============================================================="

# --- Elaboration & Simulation ---
# +acc enables visibility for waveform debugging
vsim -coverage -voptargs="+acc" work.$TB_TOP -onfinish stop;

if {[file exists "./waves/nb_barb_tb.do"]} {
    puts "Applying wave configurations from ./waves/nb_barb_tb.do"
    do ./waves/nb_barb_tb.do
} else {
    puts "WARNING: No .do file found at ./waves/nb_barb_tb.do"
    quit -f
}

# 4. Execution
# We use a small delay or manual run to ensure the GUI is ready
puts "=============================================================="
puts "Starting Simulation..."
puts "=============================================================="

run -all

# Save all coverage (Code + Functional) to a Unified Coverage Data Base
coverage save nbarb_sim.ucdb

# View the functional coverage summary in the transcript
vcover report -cvg -details nbarb_sim.ucdb
