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
add wave -noupdate /sysarr_MEISSA_top_tb/gsau_if/sa_ready_out
add wave -noupdate /sysarr_MEISSA_top_tb/gsau_if/sa_array_output
add wave -noupdate /sysarr_MEISSA_top_tb/gsau_if/sa_valid_in
add wave -noupdate /sysarr_MEISSA_top_tb/gsau_if/sa_ready_in
add wave -noupdate -divider {TB Signals}
add wave -noupdate /sysarr_MEISSA_top_tb/temp_weights
add wave -noupdate /sysarr_MEISSA_top_tb/temp_inputs
add wave -noupdate /sysarr_MEISSA_top_tb/temp_partials
add wave -noupdate -divider psum_buffer
add wave -noupdate -divider {Control Unit}
add wave -noupdate -divider output_buffer
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/wr_en
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/wr_data
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/rd_en
add wave -noupdate /sysarr_MEISSA_top_tb/genblk1/DUT/output_buffer/rd_data
add wave -noupdate -divider {Array COlumn 0}
add wave -noupdate -expand -subitemconfig {{/sysarr_MEISSA_top_tb/genblk1/DUT/in_pipe[0]} -expand} /sysarr_MEISSA_top_tb/genblk1/DUT/in_pipe
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
add wave -noupdate /sysarr_MEISSA_top_tb/gsau_if/sa_weight_en
add wave -noupdate -divider {Control Unit}
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/N
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/GROUP_SIZE
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/ADD_2_INPUT_LATENCY
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/ADD_4_INPUT_LATENCY
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/MUL_LATENCY
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/NUM_GROUPS
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/OUT_START
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/IN_CNTR_W
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/OUT_CNTR_W
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/in_buffer_empty
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/sa_output
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/in_rd_en
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/out_wr_en
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/ready_in
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/credits
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/next_credits
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/group_en
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/next_group_en
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/in_cnt
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/next_in_cnt
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/out_cnt
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/next_out_cnt
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/out_start_cnt
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/next_out_start_cnt
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/next_out_wr_en
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/pending_rows
add wave -noupdate -group {Control Unit} /sysarr_MEISSA_top_tb/genblk1/DUT/control_unit/next_pending_rows
add wave -noupdate -divider {Input Buffer}
add wave -noupdate -expand -group {Input Buffer} -group Parameters /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/NUM_COLS
add wave -noupdate -expand -group {Input Buffer} -group Parameters /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/DATA_WIDTH
add wave -noupdate -expand -group {Input Buffer} -group Parameters /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/IN_OUT
add wave -noupdate -expand -group {Input Buffer} -group Parameters /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/READ_LATENCY
add wave -noupdate -expand -group {Input Buffer} -group Parameters /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/WRITE_LATENCY
add wave -noupdate -expand -group {Input Buffer} -group Parameters /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/SRAM_DEPTH
add wave -noupdate -expand -group {Input Buffer} -group Parameters /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/PTR_WIDTH
add wave -noupdate -expand -group {Input Buffer} /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/wr_en
add wave -noupdate -expand -group {Input Buffer} /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/wr_data
add wave -noupdate -expand -group {Input Buffer} /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/rd_en
add wave -noupdate -expand -group {Input Buffer} -expand /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/rd_data
add wave -noupdate -expand -group {Input Buffer} /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/lane0_empty
add wave -noupdate -expand -group {Input Buffer} /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/wr_ptr
add wave -noupdate -expand -group {Input Buffer} /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/next_wr_ptr
add wave -noupdate -expand -group {Input Buffer} /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/rd_ptr
add wave -noupdate -expand -group {Input Buffer} /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/next_rd_ptr
add wave -noupdate -expand -group {Input Buffer} /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/rdone
add wave -noupdate -expand -group {Input Buffer} /sysarr_MEISSA_top_tb/genblk1/DUT/input_buffer/used
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {320211 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 225
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
WaveRestoreZoom {0 ps} {211512 ps}
