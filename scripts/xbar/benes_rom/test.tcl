set TB_FILE ./tb/unit/common/xbar/benes_rom_tb.sv
set TB_TOP benes_rom_tb

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

set INC_FLAGS [list \
    "+incdir+./rtl/modules/common/memory" \
    "+incdir+./rtl/include/common/xbar" \
]

set DESIGN_SRCS [list \
    ./rtl/modules/common/xbar/benes.sv \
    ./rtl/modules/common/memory/rom_bank.sv \
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

vsim work.$TB_TOP

run -all

puts "=============================================================="
puts "Simulation finished."
puts "=============================================================="

quit -f
