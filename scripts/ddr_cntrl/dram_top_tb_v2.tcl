# --- Configuration ---
set TB_TOP  dram_top_tb

# Save project root (script must be launched from project root)
set PROJ_ROOT [pwd]

puts "Top module     : $TB_TOP"
puts "Project root   : $PROJ_ROOT"

# --- Micron DDR4 model sources (from protected_modelsim/) ---
# Modeled after the working Makefile dram_top target.
# These are bare filenames resolved from inside protected_modelsim/.
set DRAM_SRCS [list \
    arch_defines.v \
    dimm.vh \
    arch_package.sv \
    proj_package.sv \
    interface.sv \
    ddr4_model.svp \
]

# --- Design RTL Sources (absolute paths so they resolve from any CWD) ---
set DESIGN_SRCS [list \
    $PROJ_ROOT/rtl/include/ddr_cntrl/dram_pkg.svh \
    $PROJ_ROOT/rtl/include/ddr_cntrl/ddr_controller_if.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/flex_counter.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/flex_sr.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/priority_enc.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/enum_compare.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/address_mapper.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/fsm_module.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/cmd_fsm_nb.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/init_state.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/refresh_counter.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/load_queue_nb.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/nb_store_queue.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/nb_bank_queue.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/nb_wdata_queue.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/nb_wdata_wrapper.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/nb_read_id_queue.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/nb_barb.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/frontend_arb_nb.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/frontend_wrapper.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/signal_gen.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/data_transfer.sv \
    $PROJ_ROOT/rtl/modules/ddr_cntrl/ddr_controller_wrapper.sv \
    $PROJ_ROOT/rtl/modules/common/general/fifo.sv \
]

set TB_FILE $PROJ_ROOT/tb/unit/ddr_cntrl/testbench/dram_top_tb.sv

# --- Include directories (absolute paths) ---
set INC_FLAGS [list \
    "+incdir+$PROJ_ROOT/rtl/include/ddr_cntrl" \
    "+incdir+./include" \
    "+incdir+." \
]

# --- Assemble all sources: Micron first, then design, then TB ---
set ALL_SRCS [concat $DRAM_SRCS $DESIGN_SRCS [list $TB_FILE]]

puts "INC_FLAGS  : $INC_FLAGS"
puts "Num sources: [llength $ALL_SRCS]"

# --- cd into protected_modelsim so bare Micron filenames resolve ---
cd $PROJ_ROOT/protected_modelsim

# --- Library Setup (work library in project root) ---
if {![file exists $PROJ_ROOT/work]} {
    vlib $PROJ_ROOT/work
}
vmap work $PROJ_ROOT/work

# --- Single vlog call — matches the working Makefile pattern ---
# The Makefile does: vlog +cover -work work +acc -sv +incdir+./include
#   +define+ DDR4_4G_X8 +define+ TS_1500 $(DRAM_define) $(EXTRA) ./tb/dram_top_tb.sv
vlog +cover -work $PROJ_ROOT/work +acc -l $PROJ_ROOT/vcs.log -sv \
    +define+DDR4_4G_X8 +define+TS_1500 \
    {*}$INC_FLAGS {*}$ALL_SRCS

# --- Return to project root ---
cd $PROJ_ROOT

puts "=============================================================="
puts "Compilation complete. Launching simulation for $TB_TOP"
puts "=============================================================="

# --- Elaboration & Simulation ---
vsim -coverage -voptargs="+acc" work.$TB_TOP -onfinish stop

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
