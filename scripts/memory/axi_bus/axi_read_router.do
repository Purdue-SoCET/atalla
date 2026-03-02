onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /axi_read_router_tb/PROG/CLK
add wave -noupdate /axi_read_router_tb/PROG/nRST
add wave -noupdate -expand -group {input signals} /axi_read_router_tb/PROG/r_sp0_o_ready
add wave -noupdate -expand -group {input signals} /axi_read_router_tb/PROG/r_sp1_o_ready
add wave -noupdate -expand -group {input signals} /axi_read_router_tb/PROG/r_i_o_ready
add wave -noupdate -expand -group {input signals} /axi_read_router_tb/PROG/r_d_o_ready
add wave -noupdate -expand -group {input signals} /axi_read_router_tb/PROG/r_i
add wave -noupdate -expand -group {input signals} /axi_read_router_tb/PROG/r_valid
add wave -noupdate -expand -group {output signals} /axi_read_router_tb/PROG/r_sp0_o
add wave -noupdate -expand -group {output signals} /axi_read_router_tb/PROG/r_sp1_o
add wave -noupdate -expand -group {output signals} /axi_read_router_tb/PROG/r_i_o
add wave -noupdate -expand -group {output signals} /axi_read_router_tb/PROG/r_d_o
add wave -noupdate -expand -group {output signals} /axi_read_router_tb/PROG/r_sp0_o_valid
add wave -noupdate -expand -group {output signals} /axi_read_router_tb/PROG/r_sp1_o_valid
add wave -noupdate -expand -group {output signals} /axi_read_router_tb/PROG/r_i_o_valid
add wave -noupdate -expand -group {output signals} /axi_read_router_tb/PROG/r_d_o_valid
add wave -noupdate -expand -group {output signals} /axi_read_router_tb/PROG/r_ready
add wave -noupdate -expand -group {internal signals} /axi_read_router_tb/DUT/sp0_sel
add wave -noupdate -expand -group {internal signals} /axi_read_router_tb/DUT/sp1_sel
add wave -noupdate -expand -group {internal signals} /axi_read_router_tb/DUT/i_sel
add wave -noupdate -expand -group {internal signals} /axi_read_router_tb/DUT/d_sel
add wave -noupdate -expand -group {internal signals} /axi_read_router_tb/DUT/sp0_o
add wave -noupdate -expand -group {internal signals} /axi_read_router_tb/DUT/sp1_o
add wave -noupdate -expand -group {internal signals} /axi_read_router_tb/DUT/i_o
add wave -noupdate -expand -group {internal signals} /axi_read_router_tb/DUT/d_o
add wave -noupdate -expand -group {skid buffer internal} /axi_read_router_tb/DUT/SKID_I/ready
add wave -noupdate -expand -group {skid buffer internal} /axi_read_router_tb/DUT/SKID_I/selected
add wave -noupdate -expand -group {skid buffer internal} /axi_read_router_tb/DUT/SKID_I/in_val
add wave -noupdate -expand -group {skid buffer internal} /axi_read_router_tb/DUT/SKID_I/out_reg
add wave -noupdate -expand -group {skid buffer internal} /axi_read_router_tb/DUT/SKID_I/n_out_reg
add wave -noupdate -expand -group {skid buffer internal} /axi_read_router_tb/DUT/SKID_I/full
add wave -noupdate -expand -group {skid buffer internal} /axi_read_router_tb/DUT/SKID_I/n_full
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {75 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 122
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
WaveRestoreZoom {51 ps} {135 ps}
