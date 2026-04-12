onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /transpose_unit_tb/DUT/CLK
add wave -noupdate /transpose_unit_tb/DUT/nRST
add wave -noupdate /transpose_unit_tb/DUT/state
add wave -noupdate /transpose_unit_tb/DUT/count
add wave -noupdate /transpose_unit_tb/DUT/sram_rdata
add wave -noupdate /transpose_unit_tb/DUT/sram_rdone
add wave -noupdate /transpose_unit_tb/tif/in.push_req
add wave -noupdate /transpose_unit_tb/tif/in.pop_req
add wave -noupdate /transpose_unit_tb/tif/in.vec_in
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {133186 ps} 0}
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
WaveRestoreZoom {284655 ps} {555759 ps}
