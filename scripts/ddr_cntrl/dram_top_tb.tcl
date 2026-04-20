# --- Configuration ---
set TB_FILE ./tb/unit/ddr_cntrl/testbench/dram_top_tb.sv
set TB_TOP  dram_top_tb

if {![info exists TB_FILE]} {
    puts "ERROR: TB_FILE not set."
    quit -f
}
if {![info exists TB_TOP]} {
    puts "ERROR: TB_TOP not set."
    quit -f
}

puts "Testbench file : $TB_FILE"
puts "Top module     : $TB_TOP"

# --- Include Directories ---
set INC_FLAGS [list \
    "+incdir+./rtl/include/ddr_cntrl" \
    "+incdir+./rtl/include/ddr_cntrl/micron" \
]

# --- DDR4 Density/Width Configuration ---
# The Micron model requires exactly one density+width define.
# Common options: DDR4_2G_X8, DDR4_4G_X8, DDR4_8G_X8, DDR4_8G_X16, etc.
set MICRON_DEFINES [list \
    "+define+DDR4_8G_X8" \
]

# --- Micron DDR4 Model Sources (handled by modelsim.do) ---
# The Micron encrypted model and related files are compiled by ./protected_modelsim/modelsim.do, not here.
set MICRON_SRCS {}

# --- Your DDR Controller RTL Sources ---
set DESIGN_SRCS {
    ./rtl/include/ddr_cntrl/dram_pkg.svh
    ./rtl/include/ddr_cntrl/ddr_controller_if.sv
    ./rtl/modules/ddr_cntrl/flex_counter.sv
    ./rtl/modules/ddr_cntrl/flex_sr.sv
    ./rtl/modules/ddr_cntrl/priority_enc.sv
    ./rtl/modules/ddr_cntrl/enum_compare.sv
    ./rtl/modules/ddr_cntrl/address_mapper.sv
    ./rtl/modules/ddr_cntrl/fsm_module.sv
    ./rtl/modules/ddr_cntrl/cmd_fsm.sv
    ./rtl/modules/ddr_cntrl/cmd_fsm_nb.sv
    ./rtl/modules/ddr_cntrl/init_state.sv
    ./rtl/modules/ddr_cntrl/refresh_counter.sv
    ./rtl/modules/ddr_cntrl/load_queue_nb.sv
    ./rtl/modules/ddr_cntrl/nb_store_queue.sv
    ./rtl/modules/ddr_cntrl/nb_bank_queue.sv
    ./rtl/modules/ddr_cntrl/nb_wdata_queue.sv
    ./rtl/modules/ddr_cntrl/nb_wdata_wrapper.sv
    ./rtl/modules/ddr_cntrl/nb_read_id_queue.sv
    ./rtl/modules/ddr_cntrl/nb_barb.sv
    ./rtl/modules/ddr_cntrl/frontend_arb_nb.sv
    ./rtl/modules/ddr_cntrl/frontend_wrapper.sv
}

# --- Assemble all sources (order matters: design, then arch_package, then Micron package, then TB) ---
set SRC_FILES [concat $DESIGN_SRCS [list ./rtl/include/ddr_cntrl/arch_package.sv ./rtl/include/ddr_cntrl/micron/proj_package.sv $TB_FILE]]

puts "INC_FLAGS  : $INC_FLAGS"
puts "DEFINES    : $MICRON_DEFINES"
puts "SRC_FILES  : $SRC_FILES"
puts "Num sources: [llength $SRC_FILES]"

# --- Library Setup ---
if {![file exists work]} {
    vlib work
}
vmap work work




# --- Always compile all sources (Micron model and user modules) ---
vlog -sv -mfcu +acc {*}$INC_FLAGS {*}$MICRON_DEFINES {*}$SRC_FILES

puts "=============================================================="
puts "Compilation complete. Launching simulation with Micron ModelSim flow"
puts "=============================================================="

if {[file exists "./protected_modelsim/modelsim.do"]} {
    puts "Launching: vsim -do ./protected_modelsim/modelsim.do"
    exec vsim -do ./protected_modelsim/modelsim.do
    puts "Micron model simulation launched."
    return
} else {
    puts "ERROR: Micron modelsim.do script not found at ./protected_modelsim/modelsim.do"
    quit -f
}

puts "=============================================================="
puts "Compilation complete. Launching simulation for $TB_TOP"
puts "=============================================================="

# --- Elaboration & Simulation ---
vsim -voptargs="+acc" work.$TB_TOP -onfinish stop

# --- Waveform Setup ---
# TODO: Create a matching .do waveform file once testbench signals are finalized
if {[file exists "./waves/dram_top_tb.do"]} {
    puts "Applying wave configurations from ./waves/dram_top_tb.do"
    do ./waves/dram_top_tb.do
} else {
    puts "WARNING: No .do waveform file found at ./waves/dram_top_tb.do — adding all signals"
    add wave -r /*
}

puts "=============================================================="
puts "Starting Simulation..."
puts "=============================================================="

run -all
