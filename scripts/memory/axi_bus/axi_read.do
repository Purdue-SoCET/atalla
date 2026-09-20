onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /axi_read_tb/DUT/CLK
add wave -noupdate /axi_read_tb/DUT/nRST
add wave -noupdate -group {AR channel} /axi_read_tb/abif/ar_sp0_valid
add wave -noupdate -group {AR channel} /axi_read_tb/abif/ar_sp1_valid
add wave -noupdate -group {AR channel} /axi_read_tb/abif/ar_d_valid
add wave -noupdate -group {AR channel} /axi_read_tb/abif/ar_i_valid
add wave -noupdate -group {AR channel} /axi_read_tb/abif/ar_sp0_i
add wave -noupdate -group {AR channel} /axi_read_tb/abif/ar_sp1_i
add wave -noupdate -group {AR channel} /axi_read_tb/abif/ar_i_i
add wave -noupdate -group {AR channel} /axi_read_tb/abif/ar_d_i
add wave -noupdate -group {AR channel} /axi_read_tb/abif/ar_o_ready
add wave -noupdate -group {AR channel} /axi_read_tb/abif/ar_o_valid
add wave -noupdate -group {AR channel} /axi_read_tb/abif/ar_o
add wave -noupdate -group {R channel} /axi_read_tb/abif/r_sp0_o_valid
add wave -noupdate -group {R channel} /axi_read_tb/abif/r_sp1_o_valid
add wave -noupdate -group {R channel} /axi_read_tb/abif/r_i_o_valid
add wave -noupdate -group {R channel} /axi_read_tb/abif/r_d_o_valid
add wave -noupdate -group {R channel} /axi_read_tb/abif/r_sp0_o
add wave -noupdate -group {R channel} /axi_read_tb/abif/r_sp1_o
add wave -noupdate -group {R channel} /axi_read_tb/abif/r_i_o
add wave -noupdate -group {R channel} /axi_read_tb/abif/r_d_o
add wave -noupdate -group {R channel} /axi_read_tb/abif/r_sp0_o_ready
add wave -noupdate -group {R channel} /axi_read_tb/abif/r_sp1_o_ready
add wave -noupdate -group {R channel} /axi_read_tb/abif/r_i_o_ready
add wave -noupdate -group {R channel} /axi_read_tb/abif/r_d_o_ready
add wave -noupdate -group {R channel} /axi_read_tb/abif/r_valid
add wave -noupdate -group {R channel} /axi_read_tb/abif/r_i
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {171 ps} 0}
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
WaveRestoreZoom {0 ps} {756 ps}
