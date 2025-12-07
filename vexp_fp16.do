onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -expand -group TB /vexp_tb/PERIOD
add wave -noupdate -expand -group TB /vexp_tb/CLK
add wave -noupdate -expand -group TB /vexp_tb/nRST
add wave -noupdate -expand -group TB /vexp_tb/casenum
add wave -noupdate -expand -group TB /vexp_tb/casename
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/operand
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/result
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/valid_in
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/valid_out
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/ready_in
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/ready_out
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/operand
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/valid_in
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/mul_valid_in
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/mul_a
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/mul_b
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/mul_out
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/sub
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/add_a
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/add_b
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/add_out
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/int_part
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/fraction
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/x_div_ln2
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/result
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/valid_out
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/current_state
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/next_state
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/t
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/r
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/r1
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/r_ln2
add wave -noupdate -expand -group FSM /vexp_tb/dut/FP16_FSM/int_part_reg
add wave -noupdate -expand -group Multiplier /vexp_tb/dut/FP16_MULTIPLIER/start
add wave -noupdate -expand -group Multiplier /vexp_tb/dut/FP16_MULTIPLIER/a
add wave -noupdate -expand -group Multiplier /vexp_tb/dut/FP16_MULTIPLIER/b
add wave -noupdate -expand -group Multiplier /vexp_tb/dut/FP16_MULTIPLIER/result
add wave -noupdate -expand -group Multiplier /vexp_tb/dut/FP16_MULTIPLIER/done
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {116366 ps} 0}
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
WaveRestoreZoom {0 ps} {19576 ps}
