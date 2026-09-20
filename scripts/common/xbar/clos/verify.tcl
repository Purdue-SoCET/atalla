set INC_FLAGS [list \
    "+incdir+./rtl/modules/common/memory" \
    "+incdir+./rtl/include/common/xbar" \
]

set SRC_FILES [list \
    ./rtl/include/common/xbar/xbar_if.sv \
    ./rtl/include/common/xbar/xbar_params.svh \
    ./rtl/include/common/xbar/xbar_pkg.sv \
    ./rtl/modules/common/xbar/param_switch.sv \
    ./rtl/modules/common/xbar/clos.sv \
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
