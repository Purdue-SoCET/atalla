set TB_FILE ./tb/unit/memory/axi_bus/axi_tb.sv
set TB_TOP  axi_tb

puts "Testbench file : $TB_FILE"
puts "Top module     : $TB_TOP"

set INC_FLAGS [list \
    "+incdir+./rtl/include/memory/axi_bus" \
]

set DESIGN_SRCS [list \
    ./rtl/include/memory/axi_bus/axi_bus_pkg.sv \
    ./rtl/include/memory/axi_bus/axi_bus_if.sv \
    ./rtl/modules/memory/axi_bus/axi_skid_buffer.sv \
    ./rtl/modules/memory/axi_bus/axi_write_driver.sv \
    ./rtl/modules/memory/axi_bus/axi_write_arbiter.sv \
    ./rtl/modules/memory/axi_bus/axi_write_router.sv \
    ./rtl/modules/memory/axi_bus/axi_write_manager.sv \
    ./rtl/modules/memory/axi_bus/axi_write_top.sv \
    ./rtl/modules/memory/axi_bus/axi_read_arbiter.sv \
    ./rtl/modules/memory/axi_bus/axi_read_router.sv \
    ./rtl/modules/memory/axi_bus/axi_read_manager.sv \
    ./rtl/modules/memory/axi_bus/axi_read.sv \
    ./rtl/modules/memory/axi_bus/axi.sv \
]

set SRC_FILES [concat $DESIGN_SRCS [list $TB_FILE]]

puts "INC_FLAGS  : $INC_FLAGS"
puts "SRC_FILES  : $SRC_FILES"
puts "Num sources: [llength $SRC_FILES]"

if {![file exists work]} {
    vlib work
}

vlog -sv -mfcu -cover bcesft {*}$INC_FLAGS {*}$SRC_FILES

puts "=============================================================="
puts "Compilation complete. Launching simulation for $TB_TOP"
puts "=============================================================="

vsim -coverage -voptargs=+acc work.$TB_TOP

if {![batch_mode]} {
    do ./waves/axi.do
}

onfinish stop
run -all

puts "=============================================================="
puts "Simulation finished."
puts "=============================================================="

coverage save axi_tb.ucdb
coverage report -details -cvg -directive -code bcesft -output coverage_report.txt
coverage report -summary -cvg -directive -code bcesft

puts "Coverage report saved to coverage_report.txt"

quit -f
