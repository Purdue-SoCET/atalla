onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /valu_tb/CLK
add wave -noupdate /valu_tb/nRST
add wave -noupdate /valu_tb/errors
add wave -noupdate -expand -group Inputs -color Yellow /valu_tb/valuif/in.valid_in
add wave -noupdate -expand -group Inputs -color Yellow /valu_tb/valuif/in.ready_out
add wave -noupdate -expand -group Inputs -color Yellow /valu_tb/valuif/in.operand1
add wave -noupdate -expand -group Inputs -color Yellow /valu_tb/valuif/in.operand2
add wave -noupdate -expand -group Inputs -color Yellow /valu_tb/valuif/in.alu_op
add wave -noupdate -expand -group Outputs -color Cyan /valu_tb/valuif/out.valid_out
add wave -noupdate -expand -group Outputs -color Cyan /valu_tb/valuif/out.ready_in
add wave -noupdate -expand -group Outputs -color Cyan /valu_tb/valuif/out.result
add wave -noupdate -color Magenta /valu_tb/expected_result
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {298294 ps} 0}
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
WaveRestoreZoom {168190 ps} {468204 ps}
