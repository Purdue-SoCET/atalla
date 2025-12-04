set INC_FLAGS [list \
    "+incdir+./rtl/modules/common/memory" \
    "+incdir+./rtl/include/common/xbar" \
]

set SRC_FILES [list \
    ./rtl/modules/common/xbar/crossover_switch.sv \
    ./rtl/modules/common/xbar/benes.sv \
    ./rtl/modules/common/memory/rom_bank.sv \
    ./rtl/modules/common/xbar/benes_rom.sv \
]

puts "INC_FLAGS  : $INC_FLAGS"
puts "SRC_FILES  : $SRC_FILES"
puts "Num sources: [llength $SRC_FILES]"

if {![file exists work]} {
    vlib work
}
vmap work work

vlog -sv -mfcu -lint {*}$INC_FLAGS {*}$SRC_FILES


puts "Compilation/lint complete."
quit -f
