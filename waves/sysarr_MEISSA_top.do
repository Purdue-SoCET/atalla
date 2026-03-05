onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /sysarr_MEISSA_top_tb/test_name
add wave -noupdate /sysarr_MEISSA_top_tb/nRST
add wave -noupdate /sysarr_MEISSA_top_tb/CLK
add wave -noupdate -divider gsau_if
add wave -noupdate /sysarr_MEISSA_top_tb/gsau_if/sa_array_in
add wave -noupdate /sysarr_MEISSA_top_tb/gsau_if/sa_array_in_partials
add wave -noupdate /sysarr_MEISSA_top_tb/gsau_if/sa_input_en
add wave -noupdate /sysarr_MEISSA_top_tb/gsau_if/sa_partial_en
add wave -noupdate /sysarr_MEISSA_top_tb/gsau_if/sa_weight_en
add wave -noupdate /sysarr_MEISSA_top_tb/gsau_if/sa_ready_out
add wave -noupdate /sysarr_MEISSA_top_tb/gsau_if/sa_array_output
add wave -noupdate /sysarr_MEISSA_top_tb/gsau_if/sa_valid_in
add wave -noupdate /sysarr_MEISSA_top_tb/gsau_if/sa_ready_in
add wave -noupdate -divider {TB Signals}
add wave -noupdate /sysarr_MEISSA_top_tb/temp_weights
add wave -noupdate /sysarr_MEISSA_top_tb/temp_inputs
add wave -noupdate /sysarr_MEISSA_top_tb/temp_partials
add wave -noupdate -divider psum_buffer
add wave -noupdate -divider output_buffer
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/wr_en
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/wr_data
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/rd_en
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/rd_data
add wave -noupdate -divider {Array COlumn 0}
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/in_pipe
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/psum_pipe
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/next_psum_pipe
add wave -noupdate -divider MAC
add wave -noupdate {/sysarr_MEISSA_top_tb/genblk1/DUT/row[0]/col[0]/u_mac_4_input/add_4_input_out}
add wave -noupdate {/sysarr_MEISSA_top_tb/genblk1/DUT/row[0]/col[0]/u_mac_4_input/out}
add wave -noupdate {/sysarr_MEISSA_top_tb/genblk1/DUT/row[0]/col[0]/u_mac_4_input/mul_out}
add wave -noupdate -divider {Mul 3}
add wave -noupdate {/sysarr_MEISSA_top_tb/genblk1/DUT/row[0]/col[0]/u_mac_4_input/mul_cells[3]/u_mul_cell/in}
add wave -noupdate {/sysarr_MEISSA_top_tb/genblk1/DUT/row[0]/col[0]/u_mac_4_input/mul_cells[3]/u_mul_cell/weight_en}
add wave -noupdate {/sysarr_MEISSA_top_tb/genblk1/DUT/row[0]/col[0]/u_mac_4_input/mul_cells[3]/u_mul_cell/result}
add wave -noupdate {/sysarr_MEISSA_top_tb/genblk1/DUT/row[0]/col[0]/u_mac_4_input/mul_cells[3]/u_mul_cell/weight}
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {1679472 ps} 0}
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
WaveRestoreZoom {1079658 ps} {1679472 ps}
