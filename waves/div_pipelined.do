onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /div_pipelined_tb/DUT/CLK
add wave -noupdate /div_pipelined_tb/DUT/nRST
add wave -noupdate -divider Divif
add wave -noupdate -expand /div_pipelined_tb/divif/in
add wave -noupdate -expand /div_pipelined_tb/divif/out
add wave -noupdate -divider Internal
add wave -noupdate /div_pipelined_tb/DUT/accept_new
add wave -noupdate /div_pipelined_tb/DUT/global_stall
add wave -noupdate /div_pipelined_tb/DUT/loopback_req
add wave -noupdate -expand /div_pipelined_tb/DUT/p_valid
add wave -noupdate /div_pipelined_tb/DUT/p_is_iter2
add wave -noupdate -divider {Mul Numerator}
add wave -noupdate /div_pipelined_tb/DUT/mul_numerator/a_latched
add wave -noupdate /div_pipelined_tb/DUT/mul_numerator/b_latched
add wave -noupdate /div_pipelined_tb/DUT/mul_numerator/result
add wave -noupdate -divider Sub
add wave -noupdate /div_pipelined_tb/DUT/sub/add_sub/bf1_in
add wave -noupdate /div_pipelined_tb/DUT/sub/add_sub/bf2_in
add wave -noupdate /div_pipelined_tb/DUT/sub/add_sub/smaller_mantissa_l
add wave -noupdate /div_pipelined_tb/DUT/sub/add_sub/larger_mantissa_l
add wave -noupdate /div_pipelined_tb/DUT/sub/add_sub/bf_out
add wave -noupdate -divider Loopback
add wave -noupdate /div_pipelined_tb/DUT/delay_n1_5
add wave -noupdate /div_pipelined_tb/DUT/reg_subout
add wave -noupdate /div_pipelined_tb/DUT/nxt_muln
add wave -noupdate /div_pipelined_tb/DUT/nxt_f
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {236420 ps} 0}
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
WaveRestoreZoom {0 ps} {402282 ps}
