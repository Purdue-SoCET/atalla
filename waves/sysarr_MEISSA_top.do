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
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/clk
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/nRST
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/wr_en
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/wr_data
add wave -noupdate -expand /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/rd_en
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/rd_data
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/rdone
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/lane0_empty
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/full
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/wr_ptr
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/next_wr_ptr
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/rd_ptr
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/next_rd_ptr
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/used
add wave -noupdate -divider {control logic}
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/credits
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/next_credits
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/shift_reg
add wave -noupdate -divider {New Divider}
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_data
add wave -noupdate -divider {mul grid}
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/u_mul_grid/clk
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/u_mul_grid/nRST
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/u_mul_grid/sa_inputs
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/u_mul_grid/act_en
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/u_mul_grid/weight_en
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/u_mul_grid/mul_stall
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/u_mul_grid/load_w
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/u_mul_grid/load_a
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/u_mul_grid/input_pipe
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/u_mul_grid/weight_pipe
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/u_mul_grid/prod_r
add wave -noupdate -divider {adder tree}
add wave -noupdate {/sysarr_MEISSA_top_tb/genblk1/DUT/col[0]/u_piped_addr_tree/clk}
add wave -noupdate {/sysarr_MEISSA_top_tb/genblk1/DUT/col[0]/u_piped_addr_tree/nRST}
add wave -noupdate {/sysarr_MEISSA_top_tb/genblk1/DUT/col[0]/u_piped_addr_tree/stall}
add wave -noupdate {/sysarr_MEISSA_top_tb/genblk1/DUT/col[0]/u_piped_addr_tree/terms_in}
add wave -noupdate {/sysarr_MEISSA_top_tb/genblk1/DUT/col[0]/u_piped_addr_tree/psum_in}
add wave -noupdate {/sysarr_MEISSA_top_tb/genblk1/DUT/col[0]/u_piped_addr_tree/stage_data}
add wave -noupdate -divider {reducer 31}
add wave -noupdate {/sysarr_MEISSA_top_tb/genblk1/DUT/reduce[31]/u_reducer/fp_in}
add wave -noupdate {/sysarr_MEISSA_top_tb/genblk1/DUT/reduce[31]/u_reducer/fp_out}
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {790444 ps} 0}
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
