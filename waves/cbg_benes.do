onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /benes_full_tb/xif/in
add wave -noupdate /benes_full_tb/DUT_BENES/in_latch
add wave -noupdate /benes_full_tb/DUT_BENES/reg_latch
add wave -noupdate /benes_full_tb/DUT_BENES/out_latch
add wave -noupdate /benes_full_tb/xif/out
add wave -noupdate /benes_full_tb/DUT_BENES/REGISTER_MASK
add wave -noupdate /benes_full_tb/DUT_BENES/control_bit
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {12 ns} 0}
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
WaveRestoreZoom {72 ns} {112 ns}
