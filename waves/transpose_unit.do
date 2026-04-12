onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -divider System
add wave -noupdate /transpose_unit_tb/DUT/CLK
add wave -noupdate /transpose_unit_tb/DUT/nRST
add wave -noupdate -divider FSM
add wave -noupdate /transpose_unit_tb/DUT/state
add wave -noupdate -radix unsigned /transpose_unit_tb/DUT/count
add wave -noupdate /transpose_unit_tb/DUT/ren
add wave -noupdate /transpose_unit_tb/DUT/wen
add wave -noupdate -divider Inputs
add wave -noupdate /transpose_unit_tb/tif/in.valid_in
add wave -noupdate /transpose_unit_tb/tif/in.push_req
add wave -noupdate /transpose_unit_tb/tif/in.pop_req
add wave -noupdate -radix unsigned /transpose_unit_tb/tif/in.vec_in
add wave -noupdate -divider Outputs
add wave -noupdate /transpose_unit_tb/tif/out.valid_out
add wave -noupdate -radix unsigned /transpose_unit_tb/tif/out.vec_out
add wave -noupdate -divider Xif
add wave -noupdate -radix unsigned /transpose_unit_tb/DUT/xif/in
add wave -noupdate -radix unsigned /transpose_unit_tb/DUT/xif/out
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {2155340 ps} 0}
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
WaveRestoreZoom {0 ps} {271104 ps}
