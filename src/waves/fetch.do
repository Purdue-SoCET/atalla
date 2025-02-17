onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /fetch_tb/tb_test_case
add wave -noupdate /fetch_tb/CLK
add wave -noupdate /fetch_tb/nRST
add wave -noupdate -expand -group Inputs /fetch_tb/tb_ihit
add wave -noupdate -expand -group Inputs /fetch_tb/fif/imemload
add wave -noupdate -expand -group Inputs /fetch_tb/DUT/fif/correct_pc
add wave -noupdate -expand -group Inputs /fetch_tb/DUT/fif/pc_prediction
add wave -noupdate -expand -group Inputs /fetch_tb/fif/flush
add wave -noupdate -expand -group Inputs /fetch_tb/fif/stall
add wave -noupdate -expand -group Inputs /fetch_tb/fif/dispatch_free
add wave -noupdate -expand -group Inputs /fetch_tb/fif/misprediction
add wave -noupdate -expand -group Inputs /fetch_tb/fif/correct_target
add wave -noupdate -expand -group Outputs /fetch_tb/fif/instr
add wave -noupdate -expand -group Outputs /fetch_tb/fif/pc
add wave -noupdate -expand -group DUT /fetch_tb/DUT/next_pc
add wave -noupdate -expand -group DUT /fetch_tb/DUT/pc_reg
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {20 ns} 0}
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
WaveRestoreZoom {0 ns} {574 ns}
