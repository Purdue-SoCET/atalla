onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /lane_sequencer_tb/CLK
add wave -noupdate /lane_sequencer_tb/lane_in
add wave -noupdate /lane_sequencer_tb/lane_out
add wave -noupdate /lane_sequencer_tb/nRST
add wave -noupdate /lane_sequencer_tb/#ublk#41060786#623/testname
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {36704849141 ps} 0}
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
WaveRestoreZoom {36704849050 ps} {36704850050 ps}
