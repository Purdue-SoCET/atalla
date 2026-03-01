onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /exponential_unit_tb/input_file
add wave -noupdate /exponential_unit_tb/ex_if/in
add wave -noupdate /exponential_unit_tb/ex_if/out
add wave -noupdate /exponential_unit_tb/dut/ex_if/in
add wave -noupdate /exponential_unit_tb/dut/ex_if/out
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {1297200 ns} 0}
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
WaveRestoreZoom {0 ns} {674 ns}
