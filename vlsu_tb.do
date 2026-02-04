onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -divider {Clock & Reset}
add wave -noupdate /vlsu_tb/clk
add wave -noupdate /vlsu_tb/n_rst
add wave -noupdate -divider {Scheduler Interface}
add wave -noupdate /vlsu_tb/sched_valid_in
add wave -noupdate /vlsu_tb/sched_ready_out
add wave -noupdate /vlsu_tb/sched_write
add wave -noupdate -radix hexadecimal /vlsu_tb/sched_addr
add wave -noupdate -radix unsigned /vlsu_tb/sched_sp_sel
add wave -noupdate -radix hexadecimal /vlsu_tb/sched_vdst
add wave -noupdate -divider {VRF Store}
add wave -noupdate /vlsu_tb/vrf_store_valid
add wave -noupdate -radix hexadecimal /vlsu_tb/vrf_store_data
add wave -noupdate -divider {SP0 Request}
add wave -noupdate {/vlsu_tb/sp_req[0].valid}
add wave -noupdate {/vlsu_tb/sp_req[0].write}
add wave -noupdate -radix hexadecimal {/vlsu_tb/sp_req[0].spad_addr}
add wave -noupdate {/vlsu_tb/sp_stall[0]}
add wave -noupdate -divider {SP1 Request}
add wave -noupdate {/vlsu_tb/sp_req[1].valid}
add wave -noupdate {/vlsu_tb/sp_req[1].write}
add wave -noupdate -radix hexadecimal {/vlsu_tb/sp_req[1].spad_addr}
add wave -noupdate {/vlsu_tb/sp_stall[1]}
add wave -noupdate -divider {SP0 Response}
add wave -noupdate {/vlsu_tb/sp_res[0].valid}
add wave -noupdate {/vlsu_tb/sp_res[0].write}
add wave -noupdate -radix hexadecimal {/vlsu_tb/sp_res[0].rdata}
add wave -noupdate -divider {SP1 Response}
add wave -noupdate {/vlsu_tb/sp_res[1].valid}
add wave -noupdate {/vlsu_tb/sp_res[1].write}
add wave -noupdate -radix hexadecimal {/vlsu_tb/sp_res[1].rdata}
add wave -noupdate -divider Writeback
add wave -noupdate /vlsu_tb/wb_valid_out
add wave -noupdate /vlsu_tb/wb_ready_in
add wave -noupdate -radix hexadecimal /vlsu_tb/wb_vdst
add wave -noupdate -radix hexadecimal /vlsu_tb/wb_load_data
add wave -noupdate -divider {VLSU Internals}
add wave -noupdate /vlsu_tb/DUT/is_load
add wave -noupdate /vlsu_tb/DUT/is_store
add wave -noupdate -radix unsigned /vlsu_tb/DUT/sp_select
add wave -noupdate /vlsu_tb/DUT/can_accept_load
add wave -noupdate /vlsu_tb/DUT/can_accept_store
add wave -noupdate /vlsu_tb/DUT/can_accept_req
add wave -noupdate -divider {FIFO Control}
add wave -noupdate /vlsu_tb/DUT/fifo_wr_en
add wave -noupdate /vlsu_tb/DUT/fifo_shift
add wave -noupdate /vlsu_tb/DUT/fifo_empty
add wave -noupdate /vlsu_tb/DUT/fifo_full
add wave -noupdate -radix hexadecimal /vlsu_tb/DUT/fifo_din
add wave -noupdate -radix hexadecimal /vlsu_tb/DUT/fifo_dout
add wave -noupdate -divider {Response Arb}
add wave -noupdate /vlsu_tb/DUT/sp_res_pending
add wave -noupdate /vlsu_tb/DUT/found_pending
add wave -noupdate -radix unsigned /vlsu_tb/DUT/pending_sp_idx
add wave -noupdate -divider Status
add wave -noupdate /vlsu_tb/vlsu_busy
add wave -noupdate {/vlsu_tb/load_queue_full[0]}
add wave -noupdate {/vlsu_tb/load_queue_full[1]}
add wave -noupdate -divider {SP Model Pipeline}
add wave -noupdate -radix binary {/vlsu_tb/sp_delay_valid[0]}
add wave -noupdate -radix binary {/vlsu_tb/sp_delay_valid[1]}
add wave -noupdate -divider {Test Status}
add wave -noupdate -radix ascii /vlsu_tb/current_test_type
add wave -noupdate -radix unsigned /vlsu_tb/total_tests
add wave -noupdate -radix unsigned /vlsu_tb/passed_tests
add wave -noupdate -radix unsigned /vlsu_tb/failed_tests
add wave -noupdate -expand {/vlsu_tb/DUT/gen_load_queues[0]/load_queue/fifo}
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {695 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 280
configure wave -valuecolwidth 150
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
WaveRestoreZoom {647 ps} {755 ps}
