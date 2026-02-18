onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -color Thistle /result_collector_tb/u_result_collector/nRST
add wave -noupdate -color Thistle /result_collector_tb/cur_test_name
add wave -noupdate -color Thistle /result_collector_tb/u_result_collector/CLK
add wave -noupdate -expand /result_collector_tb/u_result_collector/rc_in
add wave -noupdate -expand /result_collector_tb/u_result_collector/rc_out
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {2934278 ps} 0}
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
WaveRestoreZoom {0 ps} {3081750 ps}
