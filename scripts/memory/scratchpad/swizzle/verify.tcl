set ROOT_DIR "."

set INC_FLAGS [list \
    "+incdir+$ROOT_DIR/rtl/include/common/memory" \
    "+incdir+$ROOT_DIR/rtl/include/common/xbar" \
    "+incdir+$ROOT_DIR/rtl/include/memory/scratchpad" \
]

set SRC_FILES [list \
    $ROOT_DIR/rtl/include/common/xbar/xbar_pkg.sv \
    $ROOT_DIR/rtl/include/common/xbar/xbar_if.sv \
    $ROOT_DIR/rtl/include/memory/scratchpad/scpad_pkg.sv \
    $ROOT_DIR/rtl/include/memory/scratchpad/scpad_if.sv \
    $ROOT_DIR/rtl/include/memory/scratchpad/golden_swizzle_pkg.sv \
    $ROOT_DIR/rtl/modules/memory/scratchpad/swizzle.sv \
    $ROOT_DIR/tb/unit/memory/scratchpad/swizzle_tb.sv \
]

puts "INC_FLAGS  : $INC_FLAGS"
puts "SRC_FILES  : $SRC_FILES"
puts "Num sources: [llength $SRC_FILES]"

set DPI_OUT_DIR "$ROOT_DIR/build/dpi"

file mkdir $DPI_OUT_DIR
set DPI_LIB_BASENAME "golden_swizzle"
set DPI_SO "$DPI_OUT_DIR/lib${DPI_LIB_BASENAME}.so"

set DPI_SRCS [list \
    "$ROOT_DIR/rtl/modules/memory/scratchpad/golden_swizzle.cpp" \
]

set DPI_INC [list \
    "-I$ROOT_DIR/rtl/include/memory/scratchpad" \
]

set DPI_DEFS [list]

set DPI_CMD [concat g++ -std=c++17 -O2 -fPIC -shared {*}$DPI_INC {*}$DPI_DEFS {*}$DPI_SRCS -o $DPI_SO]

puts "DPI compile command:"
puts $DPI_CMD

if {[catch {eval exec $DPI_CMD} dpi_err]} {
    puts "ERROR: DPI compilation failed:"
    puts $dpi_err
    quit -f
} else {
    puts "DPI compiled OK: $DPI_SO"
}

if {![file exists work]} {
    vlib work
}
vmap work work

# Compile SystemVerilog
# -mfcu helps with packages/compile ordering; -lint optional
set VLOG_CMD [list vlog -sv -mfcu {*}$INC_FLAGS {*}$SRC_FILES]
puts "SV compile command:"
puts $VLOG_CMD

if {[catch {eval $VLOG_CMD} vlog_err]} {
    puts "ERROR: SV compilation failed:"
    puts $vlog_err
    quit -f
} else {
    puts "SV compilation complete."
}

