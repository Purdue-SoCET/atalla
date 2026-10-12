onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /reduction_FU_tb/dut/CLK
add wave -noupdate /reduction_FU_tb/dut/nRST
add wave -noupdate /reduction_FU_tb/ruif/in
add wave -noupdate /reduction_FU_tb/ruif/out
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {334182 ps} 0}
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
WaveRestoreZoom {334050 ps} {335050 ps}
