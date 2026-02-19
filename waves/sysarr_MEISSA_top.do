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
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/psum_buffer/clk
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/psum_buffer/n_rst
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/psum_buffer/stall
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/psum_buffer/wr_data
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/psum_buffer/rd_data
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/psum_buffer/wr_ptr
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/psum_buffer/rd_ptr
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/psum_buffer/next_wr_ptr
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/psum_buffer/next_rd_ptr
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/psum_buffer/waddr
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/psum_buffer/waddr_wrapped
add wave -noupdate -divider output_buffer
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/output_buffer/wr_data
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/output_buffer/rd_data
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/output_buffer/wr_ptr
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/output_buffer/rd_ptr
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/output_buffer/next_wr_ptr
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/output_buffer/next_rd_ptr
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/output_buffer/waddr
add wave -noupdate /sysarr_MEISSA_top_tb/DUT/output_buffer/waddr_wrapped
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {40919 ps} 0}
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
WaveRestoreZoom {0 ps} {599814 ps}
