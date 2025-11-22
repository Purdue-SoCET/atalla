onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix binary /vexp_tb/dut/CLK
add wave -noupdate -radix binary /vexp_tb/dut/nRST
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/casenum
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/casename
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/valid_in
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/operand
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/ready_in
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/result
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/valid_out
add wave -noupdate -expand -group {VEXP Signals} /vexp_tb/vexpif/ready_out
add wave -noupdate -expand -group {Adder Signals} /vexp_tb/dut/vaddsubif/port_a
add wave -noupdate -expand -group {Adder Signals} /vexp_tb/dut/vaddsubif/port_b
add wave -noupdate -expand -group {Adder Signals} /vexp_tb/dut/vaddsubif/out
add wave -noupdate -expand -group {Adder Signals} /vexp_tb/dut/vaddsubif/sub
add wave -noupdate -expand -group {Adder Signals} /vexp_tb/dut/vaddsubif/enable
add wave -noupdate -expand -group {Adder Signals} /vexp_tb/dut/vaddsubif/overflow
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/operand
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/valid_in
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/mul_out
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/add_out
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/int_part
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/fraction
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/mul_a
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/mul_b
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/mul_valid_in
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/add_a
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/add_b
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/add_valid_in
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/sub
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/x_div_ln2
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/result
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/current_state
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/next_state
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/t
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/r
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/r1
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/r_ln2
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/x_div_ln2_out
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/e_biased
add wave -noupdate -expand -group {VEXP Internal Signals} /vexp_tb/dut/FSM/sum
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {196743 ps} 0}
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
WaveRestoreZoom {0 ps} {284800 ps}
