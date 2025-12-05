set TB_FILE ./tb/unit/common/xbar/benes_rom_tb.sv
set TB_TOP  benes_rom_tb
set WAVEROOT ./waves/common/xbar/

if {![info exists GUI]} {
    set GUI OFF
}

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
puts "GUI mode       : $GUI"

set INC_FLAGS [list \
    "+incdir+./rtl/include/common/memory" \
    "+incdir+./rtl/include/common/xbar" \
    "+incdir+./rtl/include/memory/scratchpad" \
]

set DESIGN_SRCS [list \
    ./rtl/include/common/xbar/xbar_pkg.sv \
    ./rtl/include/common/xbar/xbar_if.sv \
    ./rtl/include/memory/scratchpad/scpad_pkg.sv \
    ./rtl/include/memory/scratchpad/scpad_if.sv \
    ./rtl/modules/common/xbar/crossover_switch.sv \
    ./rtl/modules/common/xbar/benes.sv \
    ./rtl/modules/common/memory/rom_bank.sv \
    ./rtl/modules/memory/scratchpad/swizzle.sv \
]

set SRC_FILES [concat $DESIGN_SRCS [list $TB_FILE]]

puts "INC_FLAGS  : $INC_FLAGS"
puts "SRC_FILES  : $SRC_FILES"
puts "Num sources: [llength $SRC_FILES]"

if {![file exists work]} {
    vlib work
}
vmap work work

vlog -sv -mfcu {*}$INC_FLAGS {*}$SRC_FILES

puts "=============================================================="
puts "Compilation complete. Launching simulation for $TB_TOP"
puts "=============================================================="

vsim -coverage -voptargs="+acc" work.$TB_TOP

if {$GUI eq "ON"} {
    puts "Running in GUI mode"

    view objects
    view wave

    if {[info exists WAVEROOT]} {
        if {![file exists $WAVEROOT/$TB_TOP.do]} {
            do $WAVEROOT/$TB_TOP.do
        } else { 
            add wave -r /*
        }
    } else {
        add wave -r /*
    }

    onfinish stop
    run -all

} else {
    puts "Running in batch/CLI mode"
    run -all

    puts "=============================================================="
    puts "Simulation finished (CLI mode)."
    puts "=============================================================="

    quit -f
}
