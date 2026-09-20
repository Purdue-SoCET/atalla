onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /axi_write_top_tb/CLK
add wave -noupdate /axi_write_top_tb/nRST
add wave -noupdate /axi_write_top_tb/test_case
add wave -noupdate /axi_write_top_tb/busif/sp0_i_valid
add wave -noupdate /axi_write_top_tb/busif/sp1_i_valid
add wave -noupdate /axi_write_top_tb/busif/d_i_valid
add wave -noupdate /axi_write_top_tb/busif/sp0_wr_ready
add wave -noupdate /axi_write_top_tb/busif/sp1_wr_ready
add wave -noupdate /axi_write_top_tb/busif/d_wr_ready
add wave -noupdate /axi_write_top_tb/busif/b_sp0_o_valid
add wave -noupdate /axi_write_top_tb/busif/b_sp0_o_ready
add wave -noupdate /axi_write_top_tb/busif/b_sp1_o_valid
add wave -noupdate /axi_write_top_tb/busif/b_sp1_o_ready
add wave -noupdate /axi_write_top_tb/busif/b_d_o_valid
add wave -noupdate /axi_write_top_tb/busif/b_d_o_ready
add wave -noupdate /axi_write_top_tb/busif/d_wr_ready
add wave -noupdate /axi_write_top_tb/busif/aw_o
add wave -noupdate /axi_write_top_tb/busif/w_o
add wave -noupdate /axi_write_top_tb/busif/r_d_o_valid
add wave -noupdate /axi_write_top_tb/busif/aw_sp0_i
add wave -noupdate /axi_write_top_tb/busif/aw_sp1_i
add wave -noupdate /axi_write_top_tb/busif/aw_d_i
add wave -noupdate /axi_write_top_tb/busif/w_sp0_i
add wave -noupdate /axi_write_top_tb/busif/w_sp1_i
add wave -noupdate /axi_write_top_tb/busif/w_d_i
add wave -noupdate /axi_write_top_tb/busif/r_d_o_valid
add wave -noupdate /axi_write_top_tb/DUT/wr_path_if/aw_o_valid
add wave -noupdate /axi_write_top_tb/DUT/wr_path_if/aw_o_ready
add wave -noupdate /axi_write_top_tb/DUT/wr_path_if/w_o_valid
add wave -noupdate /axi_write_top_tb/DUT/wr_path_if/w_o_ready
add wave -noupdate /axi_write_top_tb/DUT/WRITE_DRV/w_skid_buffer
add wave -noupdate /axi_write_top_tb/DUT/WRITE_DRV/aw_skid_buffer
add wave -noupdate /axi_write_top_tb/DUT/WRITE_DRV/final_w_fire
add wave -noupdate /axi_write_top_tb/DUT/WRITE_DRV/aw_loaded
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {440 ps} 0}
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
WaveRestoreZoom {250 ps} {750 ps}
