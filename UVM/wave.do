onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -expand -group top_if /tb_systolic/systolic_if/clk
add wave -noupdate -expand -group top_if /tb_systolic/systolic_if/weight_en
add wave -noupdate -expand -group top_if /tb_systolic/systolic_if/input_en
add wave -noupdate -expand -group top_if /tb_systolic/systolic_if/partial_en
add wave -noupdate -expand -group top_if /tb_systolic/systolic_if/out_en
add wave -noupdate -expand -group top_if /tb_systolic/systolic_if/drained
add wave -noupdate -expand -group top_if /tb_systolic/systolic_if/fifo_has_space
add wave -noupdate -expand -group top_if -radix unsigned /tb_systolic/systolic_if/row_in_en
add wave -noupdate -expand -group top_if -radix unsigned /tb_systolic/systolic_if/row_ps_en
add wave -noupdate -expand -group top_if /tb_systolic/systolic_if/row_out
add wave -noupdate -expand -group top_if /tb_systolic/systolic_if/array_in
add wave -noupdate -expand -group top_if /tb_systolic/systolic_if/array_in_partials
add wave -noupdate -expand -group top_if /tb_systolic/systolic_if/array_output
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/weight_en
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/input_en
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/partial_en
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/row_in_en
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/row_ps_en
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/fifo_has_space
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/input_load
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/partials_load
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/MAC_start
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/MAC_value_ready
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/add_start
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/add_value_ready
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/in_fifo_shift
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/ps_fifo_shift
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/MAC_shift
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/out_fifo_shift
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/input_row
add wave -noupdate -expand -group control_unit_if /tb_systolic/systolic/control_unit_if/partials_row
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {27782 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 1
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {27386 ps} {29149 ps}
