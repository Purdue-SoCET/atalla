onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /lane_tb/dut/CLK
add wave -noupdate /lane_tb/dut/nRST
add wave -noupdate /lane_tb/main_test/testname
add wave -noupdate -expand -group {Sequence Stage} /lane_tb/dut/sqrt_seq_in
add wave -noupdate -expand -group {Sequence Stage} /lane_tb/dut/sqrt_seq_out
add wave -noupdate -expand -group {Execution Stage} /lane_tb/dut/meta_in
add wave -noupdate -expand -group {Execution Stage} /lane_tb/dut/meta_out
add wave -noupdate -expand -group {Execution Stage} /lane_tb/dut/fire_valid
add wave -noupdate -expand -group {Execution Stage} /lane_tb/dut/sqrt_bus/in
add wave -noupdate -expand -group {Execution Stage} /lane_tb/dut/sqrt_bus/out
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {12066 ps} 0}
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
configure wave -timelineunits ps
update
WaveRestoreZoom {0 ps} {687750 ps}
