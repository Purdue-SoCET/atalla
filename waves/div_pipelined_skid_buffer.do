onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /div_bf16_goldschmidt_1mul_tb/DUT/CLK
add wave -noupdate /div_bf16_goldschmidt_1mul_tb/DUT/nRST
add wave -noupdate /div_bf16_goldschmidt_1mul_tb/DUT/state
add wave -noupdate /div_bf16_goldschmidt_1mul_tb/DUT/muln_1
add wave -noupdate /div_bf16_goldschmidt_1mul_tb/DUT/muld_1
add wave -noupdate /div_bf16_goldschmidt_1mul_tb/DUT/f_1
add wave -noupdate /div_bf16_goldschmidt_1mul_tb/divif/in.operand1
add wave -noupdate /div_bf16_goldschmidt_1mul_tb/divif/in.operand2
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {90890 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 190
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
WaveRestoreZoom {0 ps} {261 ns}
