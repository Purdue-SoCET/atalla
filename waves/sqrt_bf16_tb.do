onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /sqrt_bf16_tb/dut/CLK
add wave -noupdate /sqrt_bf16_tb/dut/nRST
add wave -noupdate -expand -group inputs /sqrt_bf16_tb/srif/in.operand
add wave -noupdate -expand -group inputs /sqrt_bf16_tb/srif/in.valid_in
add wave -noupdate -expand -group inputs /sqrt_bf16_tb/srif/in.ready_out
add wave -noupdate -expand -group {Latched Signals} /sqrt_bf16_tb/dut/sign
add wave -noupdate -expand -group {Latched Signals} /sqrt_bf16_tb/dut/exp
add wave -noupdate -expand -group {Latched Signals} /sqrt_bf16_tb/dut/frac
add wave -noupdate -expand -group {Latched Signals} /sqrt_bf16_tb/dut/slope
add wave -noupdate -expand -group {Latched Signals} /sqrt_bf16_tb/dut/intercept
add wave -noupdate -expand -group multiplier /sqrt_bf16_tb/dut/mul_a
add wave -noupdate -expand -group multiplier /sqrt_bf16_tb/dut/mul_b
add wave -noupdate -expand -group multiplier /sqrt_bf16_tb/dut/mul_start
add wave -noupdate -expand -group multiplier /sqrt_bf16_tb/dut/mul_out
add wave -noupdate -expand -group multiplier /sqrt_bf16_tb/dut/mul_done
add wave -noupdate -expand -group Adder /sqrt_bf16_tb/dut/mul_out_reg
add wave -noupdate -expand -group Adder /sqrt_bf16_tb/dut/intercept
add wave -noupdate -expand -group Adder /sqrt_bf16_tb/dut/add_out
add wave -noupdate -expand -group Adder /sqrt_bf16_tb/dut/add_start
add wave -noupdate -expand -group pass /sqrt_bf16_tb/dut/second_pass
add wave -noupdate -expand -group pass /sqrt_bf16_tb/dut/third_pass
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {343041 ps} 0}
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
WaveRestoreZoom {0 ps} {616415 ps}
