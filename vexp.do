onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -expand -group {TB Signals} /vexp_tb/CLK
add wave -noupdate -expand -group {TB Signals} /vexp_tb/nRST
add wave -noupdate -expand -group {TB Signals} /vexp_tb/casenum
add wave -noupdate -expand -group {TB Signals} /vexp_tb/casename
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/operand
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/result
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/valid_in
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/valid_out
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/ready_in
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/ready_out
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/operand
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/valid_in
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/mul_out
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/add_out
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/int_part
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/fraction
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/mul_a
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/mul_b
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/mul_valid_in
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/add_a
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/add_b
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/sub
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/x_div_ln2
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/result
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/current_state
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/next_state
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/t
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/r
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/r1
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/r_ln2
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/x_div_ln2_out
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/one_over_ln2
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/ln2
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/ln2_squared_div2
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/ln2_cubed_div6
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/ln2_quartic_div24
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/one
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/zero
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/e_biased
add wave -noupdate -expand -group FSM /vexp_tb/dut/BF16_FSM/sum
add wave -noupdate -expand -group ADDER /vexp_tb/dut/BF16_ADDER/bf1_in
add wave -noupdate -expand -group ADDER /vexp_tb/dut/BF16_ADDER/bf2_in
add wave -noupdate -expand -group ADDER /vexp_tb/dut/BF16_ADDER/op
add wave -noupdate -expand -group ADDER /vexp_tb/dut/BF16_ADDER/bf_out
add wave -noupdate -expand -group MULTIPLIER /vexp_tb/dut/BF16_MULTIPLIER/start
add wave -noupdate -expand -group MULTIPLIER /vexp_tb/dut/BF16_MULTIPLIER/a
add wave -noupdate -expand -group MULTIPLIER /vexp_tb/dut/BF16_MULTIPLIER/b
add wave -noupdate -expand -group MULTIPLIER /vexp_tb/dut/BF16_MULTIPLIER/result
add wave -noupdate -expand -group CONVERTER /vexp_tb/dut/BF16_CONVERTER/bf16_in
add wave -noupdate -expand -group CONVERTER /vexp_tb/dut/BF16_CONVERTER/int_u32
add wave -noupdate -expand -group CONVERTER /vexp_tb/dut/BF16_CONVERTER/frac_bf16
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {71800 ps} 0}
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
WaveRestoreZoom {625 ps} {77594 ps}
