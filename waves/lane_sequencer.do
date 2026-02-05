onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /lane_sequencer_tb/dut/CLK
add wave -noupdate /lane_sequencer_tb/dut/nRST
add wave -noupdate /lane_sequencer_tb/dut/lane_in
add wave -noupdate /lane_sequencer_tb/dut/perf_seq_if/valid
add wave -noupdate /lane_sequencer_tb/dut/perf_seq_if/ready
add wave -noupdate /lane_sequencer_tb/dut/perf_seq_if/cnt_trans_cycles
add wave -noupdate /lane_sequencer_tb/dut/perf_seq_if/cnt_stall_cycles
add wave -noupdate /lane_sequencer_tb/dut/perf_seq_if/cnt_starve_cycles
add wave -noupdate /lane_sequencer_tb/dut/perf_seq_if/cnt_total_items
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {523367 ps} 0}
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
WaveRestoreZoom {0 ps} {171938 ps}
