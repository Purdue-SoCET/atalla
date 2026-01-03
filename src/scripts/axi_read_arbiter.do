onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /axi_read_arbiter_tb/clk
add wave -noupdate /axi_read_arbiter_tb/nrst
add wave -noupdate /axi_read_arbiter_tb/test_case
add wave -noupdate /axi_read_arbiter_tb/ready
add wave -noupdate /axi_read_arbiter_tb/sp0_req
add wave -noupdate /axi_read_arbiter_tb/sp1_req
add wave -noupdate /axi_read_arbiter_tb/d_req
add wave -noupdate /axi_read_arbiter_tb/i_req
add wave -noupdate -radix binary /axi_read_arbiter_tb/grant_sel
add wave -noupdate /axi_read_arbiter_tb/DUT/state
add wave -noupdate /axi_read_arbiter_tb/DUT/next_state
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {75000 ps} 0}
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
WaveRestoreZoom {0 ps} {173250 ps}
