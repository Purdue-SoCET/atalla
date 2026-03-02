onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /axi_read_arbiter_tb/PROG/CLK
add wave -noupdate /axi_read_arbiter_tb/PROG/nRST
add wave -noupdate -expand -group {input signals} /axi_read_arbiter_tb/PROG/sp0_req
add wave -noupdate -expand -group {input signals} /axi_read_arbiter_tb/PROG/sp1_req
add wave -noupdate -expand -group {input signals} /axi_read_arbiter_tb/PROG/d_req
add wave -noupdate -expand -group {input signals} /axi_read_arbiter_tb/PROG/i_req
add wave -noupdate -expand -group {input signals} /axi_read_arbiter_tb/PROG/ready
add wave -noupdate -expand -group {output signals} /axi_read_arbiter_tb/PROG/grant_sel
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {809691 ps} 0}
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
WaveRestoreZoom {803761 ps} {815592 ps}
