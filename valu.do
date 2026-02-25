onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /valu_tb/CLK
add wave -noupdate /valu_tb/nRST
add wave -noupdate -expand -group TB /valu_tb/pass_count
add wave -noupdate -expand -group TB /valu_tb/fail_count
add wave -noupdate -expand -group TB /valu_tb/alu_if/in
add wave -noupdate -expand -group TB /valu_tb/alu_if/out
add wave -noupdate -group DUT /valu_tb/dut/CLK
add wave -noupdate -group DUT /valu_tb/dut/nRST
add wave -noupdate -group DUT /valu_tb/dut/skip_compute
add wave -noupdate -group DUT /valu_tb/dut/accept
add wave -noupdate -group DUT /valu_tb/dut/valid_s2
add wave -noupdate -group DUT /valu_tb/dut/stall
add wave -noupdate -group DUT /valu_tb/dut/is_mgt
add wave -noupdate -group DUT /valu_tb/dut/is_mlt
add wave -noupdate -group DUT /valu_tb/dut/is_meq
add wave -noupdate -group DUT /valu_tb/dut/is_mneq
add wave -noupdate -group DUT /valu_tb/dut/addsub_op
add wave -noupdate -group DUT /valu_tb/dut/addsub_out
add wave -noupdate -group DUT /valu_tb/dut/addsub_enable
add wave -noupdate -group DUT /valu_tb/dut/addsub_overflow
add wave -noupdate -group DUT /valu_tb/dut/addsub_underflow
add wave -noupdate -group DUT /valu_tb/dut/addsub_invalid
add wave -noupdate -group DUT /valu_tb/dut/v1_s1
add wave -noupdate -group DUT /valu_tb/dut/v2_s1
add wave -noupdate -group DUT /valu_tb/dut/is_mgt_s1
add wave -noupdate -group DUT /valu_tb/dut/is_mlt_s1
add wave -noupdate -group DUT /valu_tb/dut/is_meq_s1
add wave -noupdate -group DUT /valu_tb/dut/is_mneq_s1
add wave -noupdate -group DUT /valu_tb/dut/rm_s1
add wave -noupdate -group DUT /valu_tb/dut/skip_s1
add wave -noupdate -group DUT /valu_tb/dut/valid_s1
add wave -noupdate -group DUT /valu_tb/dut/v1_s2
add wave -noupdate -group DUT /valu_tb/dut/v2_s2
add wave -noupdate -group DUT /valu_tb/dut/is_mgt_s2
add wave -noupdate -group DUT /valu_tb/dut/is_mlt_s2
add wave -noupdate -group DUT /valu_tb/dut/is_meq_s2
add wave -noupdate -group DUT /valu_tb/dut/is_mneq_s2
add wave -noupdate -group DUT /valu_tb/dut/rm_s2
add wave -noupdate -group DUT /valu_tb/dut/skip_s2
add wave -noupdate -group DUT /valu_tb/dut/v1_lt_v2
add wave -noupdate -group DUT /valu_tb/dut/v1_eq_v2
add wave -noupdate -group DUT /valu_tb/dut/result_out
add wave -noupdate -group DUT /valu_tb/dut/alu_if/in
add wave -noupdate -group DUT /valu_tb/dut/alu_if/out
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/clk
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/nRST
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/start
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/stall
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/bf1_in
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/bf2_in
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/op
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/bf_out
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/overflow
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/underflow
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/invalid
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/bf2_eff
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/clk
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/nRST
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/start
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/stall
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/bf1
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/bf2
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/bf_out
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/overflow
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/underflow
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/invalid
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/done
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/bf1_in
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/bf2_in
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/is_nan
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/is_inf
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/smaller_exponent
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/larger_exponent
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/exp_select
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/frac_leading_bit_bf1
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/frac_leading_bit_bf2
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/exp_diff
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/exp_max
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/frac_shifted
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/frac_not_shifted
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/sign_shifted
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/sign_not_shifted
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/sticky_align
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/frac_to_shift
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/smaller_mantissa
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/larger_mantissa
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/mantissa_sum
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/larger_mantissa_sign
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/result_sign
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/signs_differ
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/mantissa_overflow
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/smaller_mantissa_l
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/larger_mantissa_l
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/larger_mantissa_sign_l
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/sign_shifted_l
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/sign_not_shifted_l
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/signs_differ_l
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/exp_max_l
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/exp_minus_shift_amount
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/normalized_mantissa_sum
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/norm_shift
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/u_exp1
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/u_shifted_amount
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/u_result
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/round_this
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/exp_out
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/rounded_fraction
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/exp_out_adj
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/G
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/R
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/sticky
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/lsb
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/round_sum
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/roundup
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/normalizer/fraction
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/normalizer/result
add wave -noupdate -group Adder /valu_tb/dut/u_addsub/add_sub/normalizer/shifted_amount
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {242193 ps} 0}
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
WaveRestoreZoom {0 ps} {1869 ns}
