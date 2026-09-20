# --- Configuration ---
set TB_FILE ./tb/unit/ddr_cntrl/testbench/dram_top_tb.sv
set TB_TOP  dram_top_tb

# Non-encrypted Micron sources (packages + interface) — compiled with design
set DRAM_SRCS [list \
    ./protected_modelsim/arch_package.sv \
    ./protected_modelsim/proj_package.sv \
    ./protected_modelsim/interface.sv \
]

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
    "+incdir+./protected_modelsim" \
]

# --- Design RTL Sources ---
set DESIGN_SRCS {
    ./rtl/include/ddr_cntrl/dram_pkg.svh
    ./rtl/include/ddr_cntrl/ddr_controller_if.sv
    ./rtl/modules/ddr_cntrl/flex_counter.sv
    ./rtl/modules/ddr_cntrl/flex_sr.sv
    ./rtl/modules/ddr_cntrl/priority_enc.sv
    ./rtl/modules/ddr_cntrl/enum_compare.sv
    ./rtl/modules/ddr_cntrl/address_mapper.sv
    ./rtl/modules/ddr_cntrl/fsm_module.sv
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
    ./rtl/modules/ddr_cntrl/signal_gen.sv
    ./rtl/modules/ddr_cntrl/ddr_controller_wrapper.sv
    ./rtl/modules/common/general/fifo.sv
}

# --- Assemble: Micron non-encrypted + design + testbench ---
set SRC_FILES [concat $DRAM_SRCS $DESIGN_SRCS [list $TB_FILE]]

puts "INC_FLAGS  : $INC_FLAGS"
puts "SRC_FILES  : $SRC_FILES"
puts "Num sources: [llength $SRC_FILES]"

# --- Library Setup ---
if {![file exists work]} {
    vlib work
}
vmap work work

# --- Step 1: Compile Micron encrypted model (.svp files) ---
# These must be compiled from inside protected_modelsim/ using the
# original Micron vlog invocation. They go into the same work library.
set PROJ_ROOT [pwd]
puts "Step 1: Compiling Micron DDR4 encrypted model..."
cd ./protected_modelsim
vlog -work $PROJ_ROOT/work +acc -sv \
    +define+DDR4_8G_X8 +define+FIXED_2400 \
    flexcounter.sv StateTable.svp MemoryArray.svp ddr4_model.svp
cd $PROJ_ROOT

# --- Step 2: Compile non-encrypted Micron + design RTL + testbench ---
puts "Step 2: Compiling design sources..."
vlog -sv -mfcu +acc -svinputport=var \
    +define+DDR4_8G_X8 +define+FIXED_2400 \
    {*}$INC_FLAGS {*}$SRC_FILES

puts "=============================================================="
puts "Compilation complete. Launching simulation for $TB_TOP"
puts "=============================================================="

# --- Elaboration & Simulation ---
vsim -voptargs="+acc" work.$TB_TOP -onfinish stop

# --- Waveform Setup ---
if {[file exists "./waves/dram_top_tb.do"]} {
    puts "Applying wave configurations from ./waves/dram_top_tb.do"
    do ./waves/dram_top_tb.do
} else {
    puts "WARNING: No .do file found at ./waves/dram_top_tb.do"
}

puts "=============================================================="
puts "Starting Simulation..."
puts "=============================================================="

run -all

# --- Coverage ---
coverage save dram_top_sim.ucdb
vcover report -cvg -details dram_top_sim.ucdb
