onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /result_collector_tb/DUT/CLK
add wave -noupdate /result_collector_tb/DUT/nRST
add wave -noupdate /result_collector_tb/rcif/in
add wave -noupdate /result_collector_tb/rcif/out
add wave -noupdate /result_collector_tb/DUT/collection_arrays
add wave -noupdate /result_collector_tb/DUT/array_full
add wave -noupdate /result_collector_tb/DUT/count_array
add wave -noupdate /result_collector_tb/DUT/vd
add wave -noupdate /result_collector_tb/DUT/ready
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {57075 ps} 0}
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
WaveRestoreZoom {0 ps} {183750 ps}
