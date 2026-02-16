onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /lane_sequencer_tb/DUT/CLK
add wave -noupdate /lane_sequencer_tb/DUT/nRST
add wave -noupdate /lane_sequencer_tb/DUT/elem_idx
add wave -noupdate /lane_sequencer_tb/DUT/elem_idx_n
add wave -noupdate /lane_sequencer_tb/DUT/v1_reg
add wave -noupdate /lane_sequencer_tb/DUT/v2_reg
add wave -noupdate /lane_sequencer_tb/DUT/v1_reg_n
add wave -noupdate /lane_sequencer_tb/DUT/v2_reg_n
add wave -noupdate /lane_sequencer_tb/DUT/mask_reg
add wave -noupdate /lane_sequencer_tb/DUT/mask_reg_n
add wave -noupdate /lane_sequencer_tb/DUT/valid_reg
add wave -noupdate /lane_sequencer_tb/DUT/valid_reg_n
add wave -noupdate /lane_sequencer_tb/DUT/ready_reg
add wave -noupdate /lane_sequencer_tb/DUT/ready_reg_n
add wave -noupdate /lane_sequencer_tb/DUT/last_elem
add wave -noupdate /lane_sequencer_tb/DUT/seq_if/in
add wave -noupdate /lane_sequencer_tb/DUT/seq_if/out
add wave -noupdate /lane_sequencer_tb/test_name
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {724148 ps} 0}
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
WaveRestoreZoom {0 ps} {761250 ps}
