onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -expand -group {TB Signals} /vexp_tb/CLK
add wave -noupdate -expand -group {TB Signals} /vexp_tb/nRST
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/operand
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/result
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/valid_in
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/valid_out
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/ready_in
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/ready_out
add wave -noupdate -expand -group ADDER /vexp_tb/dut/BF16_ADDER/bf1_in
add wave -noupdate -expand -group ADDER /vexp_tb/dut/BF16_ADDER/bf2_in
add wave -noupdate -expand -group ADDER /vexp_tb/dut/BF16_ADDER/op
add wave -noupdate -expand -group ADDER /vexp_tb/dut/BF16_ADDER/bf_out
add wave -noupdate -expand -group {BF16 MUL} /vexp_tb/dut/BF16_MULTIPLIER/start
add wave -noupdate -expand -group {BF16 MUL} /vexp_tb/dut/BF16_MULTIPLIER/a
add wave -noupdate -expand -group {BF16 MUL} /vexp_tb/dut/BF16_MULTIPLIER/b
add wave -noupdate -expand -group {BF16 MUL} /vexp_tb/dut/BF16_MULTIPLIER/result
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/operand
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/valid_in
add wave -noupdate -expand -group FSM /vexp_tb/dut/mul_a_fp
add wave -noupdate -expand -group FSM /vexp_tb/dut/mul_b_fp
add wave -noupdate -expand -group FSM /vexp_tb/dut/mul_result_fp
add wave -noupdate -expand -group FSM /vexp_tb/dut/mul_a_bf
add wave -noupdate -expand -group FSM /vexp_tb/dut/mul_b_bf
add wave -noupdate -expand -group FSM /vexp_tb/dut/mul_result_bf
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/int_part
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/fraction
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/add_a
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/add_b
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/add_out
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/sub
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/x_div_ln2
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/result
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/valid_out
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/current_state
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/next_state
add wave -noupdate -expand -group {FP16 MUL} /vexp_tb/dut/ONE_LN2_FP16_MULTIPLIER/a
add wave -noupdate -expand -group {FP16 MUL} /vexp_tb/dut/ONE_LN2_FP16_MULTIPLIER/b
add wave -noupdate -expand -group {FP16 MUL} /vexp_tb/dut/ONE_LN2_FP16_MULTIPLIER/result
add wave -noupdate -expand -group {FRACTION CONV} /vexp_tb/dut/FP16_TO_BF16_FRACTION_CONVERTER/fp16_in
add wave -noupdate -expand -group {FRACTION CONV} /vexp_tb/dut/FP16_TO_BF16_FRACTION_CONVERTER/int_u32
add wave -noupdate -expand -group {FRACTION CONV} /vexp_tb/dut/FP16_TO_BF16_FRACTION_CONVERTER/frac_bf16
add wave -noupdate -expand -group BF->FP /vexp_tb/dut/BF16_TO_FP16_CONVERTER/bf16_in
add wave -noupdate -expand -group BF->FP /vexp_tb/dut/BF16_TO_FP16_CONVERTER/fp16_out
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {32281 ps} 0}
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
WaveRestoreZoom {10375 ps} {167875 ps}