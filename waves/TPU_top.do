onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /TPU_top_tb/test_name
add wave -noupdate /TPU_top_tb/nRST
add wave -noupdate /TPU_top_tb/CLK
add wave -noupdate -divider gsau_if
add wave -noupdate /TPU_top_tb/gsau_if/sa_array_in
add wave -noupdate /TPU_top_tb/gsau_if/sa_array_in_partials
add wave -noupdate /TPU_top_tb/gsau_if/sa_input_en
add wave -noupdate /TPU_top_tb/gsau_if/sa_weight_en
add wave -noupdate /TPU_top_tb/gsau_if/sa_partial_en
add wave -noupdate /TPU_top_tb/gsau_if/sa_ready_out
add wave -noupdate /TPU_top_tb/gsau_if/sa_array_output
add wave -noupdate /TPU_top_tb/gsau_if/sa_valid_in
add wave -noupdate /TPU_top_tb/gsau_if/sa_ready_in
add wave -noupdate -divider {TB Signals}
add wave -noupdate /TPU_top_tb/temp_weights
add wave -noupdate /TPU_top_tb/temp_inputs
add wave -noupdate /TPU_top_tb/temp_partials
add wave -noupdate -divider psum_buffer
add wave -noupdate -divider {Array COlumn 0}
add wave -noupdate /TPU_top_tb/genblk1/DUT/in_pipe
add wave -noupdate /TPU_top_tb/genblk1/DUT/psum_pipe
add wave -noupdate -divider {Control Unit}
add wave -noupdate -expand -group {Control Unit} -group {Control Unit Parameters} /TPU_top_tb/genblk1/DUT/control_unit/N
add wave -noupdate -expand -group {Control Unit} -group {Control Unit Parameters} /TPU_top_tb/genblk1/DUT/control_unit/GROUP_SIZE
add wave -noupdate -expand -group {Control Unit} -group {Control Unit Parameters} /TPU_top_tb/genblk1/DUT/control_unit/ADD_2_INPUT_LATENCY
add wave -noupdate -expand -group {Control Unit} -group {Control Unit Parameters} /TPU_top_tb/genblk1/DUT/control_unit/ADD_4_INPUT_LATENCY
add wave -noupdate -expand -group {Control Unit} -group {Control Unit Parameters} /TPU_top_tb/genblk1/DUT/control_unit/MUL_LATENCY
add wave -noupdate -expand -group {Control Unit} -group {Control Unit Parameters} /TPU_top_tb/genblk1/DUT/control_unit/PIPELINE_DEPTH
add wave -noupdate -expand -group {Control Unit} -group {Control Unit Parameters} /TPU_top_tb/genblk1/DUT/control_unit/NUM_GROUPS
add wave -noupdate -expand -group {Control Unit} -group {Control Unit Parameters} /TPU_top_tb/genblk1/DUT/control_unit/OUT_START
add wave -noupdate -expand -group {Control Unit} -group {Control Unit Parameters} /TPU_top_tb/genblk1/DUT/control_unit/IN_CNTR_W
add wave -noupdate -expand -group {Control Unit} -group {Control Unit Parameters} /TPU_top_tb/genblk1/DUT/control_unit/OUT_CNTR_W
add wave -noupdate -expand -group {Control Unit} /TPU_top_tb/genblk1/DUT/control_unit/in_buffer_empty
add wave -noupdate -expand -group {Control Unit} /TPU_top_tb/genblk1/DUT/control_unit/vector_in
add wave -noupdate -expand -group {Control Unit} /TPU_top_tb/genblk1/DUT/control_unit/ready_out
add wave -noupdate -expand -group {Control Unit} /TPU_top_tb/genblk1/DUT/control_unit/in_rd_en
add wave -noupdate -expand -group {Control Unit} /TPU_top_tb/genblk1/DUT/control_unit/out_wr_en
add wave -noupdate -expand -group {Control Unit} /TPU_top_tb/genblk1/DUT/control_unit/ready_in
add wave -noupdate -expand -group {Control Unit} /TPU_top_tb/genblk1/DUT/control_unit/out_rd_en
add wave -noupdate -expand -group {Control Unit} /TPU_top_tb/genblk1/DUT/control_unit/vector_out
add wave -noupdate -expand -group {Control Unit} /TPU_top_tb/genblk1/DUT/control_unit/vector_cnt
add wave -noupdate -expand -group {Control Unit} -radix unsigned /TPU_top_tb/genblk1/DUT/control_unit/credits
add wave -noupdate -expand -group {Control Unit} -radix binary /TPU_top_tb/genblk1/DUT/control_unit/group_en
add wave -noupdate -expand -group {Control Unit} -radix unsigned /TPU_top_tb/genblk1/DUT/control_unit/in_cnt
add wave -noupdate -expand -group {Control Unit} -radix unsigned /TPU_top_tb/genblk1/DUT/control_unit/out_cnt
add wave -noupdate -expand -group {Control Unit} -radix unsigned /TPU_top_tb/genblk1/DUT/control_unit/out_start_cnt
add wave -noupdate -expand -group {Control Unit} -radix unsigned /TPU_top_tb/genblk1/DUT/control_unit/pending_rows
add wave -noupdate -expand -group {Control Unit} -radix unsigned /TPU_top_tb/genblk1/DUT/control_unit/output_vector_counter
add wave -noupdate -expand -group {Control Unit} /TPU_top_tb/genblk1/DUT/control_unit/sa_valid_in
add wave -noupdate -divider {Input Buffer}
add wave -noupdate -expand -group {Input Buffer} -group Parameters /TPU_top_tb/genblk1/DUT/u_input_buffer/NUM_COLS
add wave -noupdate -expand -group {Input Buffer} -group Parameters /TPU_top_tb/genblk1/DUT/u_input_buffer/DATA_WIDTH
add wave -noupdate -expand -group {Input Buffer} -group Parameters /TPU_top_tb/genblk1/DUT/u_input_buffer/SRAM_DEPTH
add wave -noupdate -expand -group {Input Buffer} -group Parameters /TPU_top_tb/genblk1/DUT/u_input_buffer/READ_LATENCY
add wave -noupdate -expand -group {Input Buffer} -group Parameters /TPU_top_tb/genblk1/DUT/u_input_buffer/WRITE_LATENCY
add wave -noupdate -expand -group {Input Buffer} -group Parameters /TPU_top_tb/genblk1/DUT/u_input_buffer/PTR_WIDTH
add wave -noupdate -expand -group {Input Buffer} /TPU_top_tb/genblk1/DUT/u_input_buffer/stall
add wave -noupdate -expand -group {Input Buffer} /TPU_top_tb/genblk1/DUT/u_input_buffer/wr_en
add wave -noupdate -expand -group {Input Buffer} /TPU_top_tb/genblk1/DUT/u_input_buffer/wr_data
add wave -noupdate -expand -group {Input Buffer} /TPU_top_tb/genblk1/DUT/u_input_buffer/rd_en
add wave -noupdate -expand -group {Input Buffer} /TPU_top_tb/genblk1/DUT/u_input_buffer/rd_data
add wave -noupdate -expand -group {Input Buffer} /TPU_top_tb/genblk1/DUT/u_input_buffer/rdone
add wave -noupdate -expand -group {Input Buffer} /TPU_top_tb/genblk1/DUT/u_input_buffer/lane0_empty
add wave -noupdate -expand -group {Input Buffer} /TPU_top_tb/genblk1/DUT/u_input_buffer/wr_ptr
add wave -noupdate -expand -group {Input Buffer} /TPU_top_tb/genblk1/DUT/u_input_buffer/rd_ptr
add wave -noupdate -expand -group {Input Buffer} /TPU_top_tb/genblk1/DUT/u_input_buffer/used
add wave -noupdate -divider output_buffer
add wave -noupdate -expand -group {Output Buffer} -group Parameters /TPU_top_tb/genblk1/DUT/u_output_buffer/NUM_COLS
add wave -noupdate -expand -group {Output Buffer} -group Parameters /TPU_top_tb/genblk1/DUT/u_output_buffer/DATA_WIDTH
add wave -noupdate -expand -group {Output Buffer} -group Parameters /TPU_top_tb/genblk1/DUT/u_output_buffer/SRAM_DEPTH
add wave -noupdate -expand -group {Output Buffer} -group Parameters /TPU_top_tb/genblk1/DUT/u_output_buffer/READ_LATENCY
add wave -noupdate -expand -group {Output Buffer} -group Parameters /TPU_top_tb/genblk1/DUT/u_output_buffer/WRITE_LATENCY
add wave -noupdate -expand -group {Output Buffer} -group Parameters /TPU_top_tb/genblk1/DUT/u_output_buffer/PTR_WIDTH
add wave -noupdate -expand -group {Output Buffer} /TPU_top_tb/genblk1/DUT/u_output_buffer/stall
add wave -noupdate -expand -group {Output Buffer} /TPU_top_tb/genblk1/DUT/u_output_buffer/rd_en
add wave -noupdate -expand -group {Output Buffer} /TPU_top_tb/genblk1/DUT/u_output_buffer/wr_data
add wave -noupdate -expand -group {Output Buffer} /TPU_top_tb/genblk1/DUT/u_output_buffer/wr_en
add wave -noupdate -expand -group {Output Buffer} /TPU_top_tb/genblk1/DUT/u_output_buffer/rd_data
add wave -noupdate -expand -group {Output Buffer} /TPU_top_tb/genblk1/DUT/u_output_buffer/rd_ptr
add wave -noupdate -expand -group {Output Buffer} /TPU_top_tb/genblk1/DUT/u_output_buffer/next_rd_ptr
add wave -noupdate -expand -group {Output Buffer} /TPU_top_tb/genblk1/DUT/u_output_buffer/wr_ptr
add wave -noupdate -expand -group {Output Buffer} /TPU_top_tb/genblk1/DUT/u_output_buffer/used
add wave -noupdate /TPU_top_tb/#ublk#112448274#289/input_row
add wave -noupdate /TPU_top_tb/#ublk#112448274#374/result_row
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 13} {7053378 ps} 0}
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
WaveRestoreZoom {7011766 ps} {7236223 ps}
