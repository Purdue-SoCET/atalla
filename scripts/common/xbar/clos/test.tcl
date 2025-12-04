set TB_FILE ./tb/unit/common/xbar/clos_tb.sv
set TB_TOP clos_tb

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
    ./rtl/include/common/xbar/xbar_if.sv \
    ./rtl/include/common/xbar/xbar_params.svh \
    ./rtl/include/common/xbar/xbar_pkg.sv \
    ./rtl/modules/common/xbar/param_switch.sv \
    ./rtl/modules/common/xbar/clos.sv \
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
