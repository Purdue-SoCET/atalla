onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -divider {Clock / Reset}
add wave -noupdate /vlsu_tb/CLK
add wave -noupdate /vlsu_tb/nRST
add wave -noupdate -divider {Sched Ch0}
add wave -noupdate {/vlsu_tb/sched_valid_in[0]}
add wave -noupdate {/vlsu_tb/sched_ready_out[0]}
add wave -noupdate {/vlsu_tb/sched_write[0]}
add wave -noupdate -radix hexadecimal {/vlsu_tb/sched_addr[0]}
add wave -noupdate -radix unsigned {/vlsu_tb/sched_vdst[0]}
add wave -noupdate -divider {Sched Ch1}
add wave -noupdate {/vlsu_tb/sched_valid_in[1]}
add wave -noupdate {/vlsu_tb/sched_ready_out[1]}
add wave -noupdate {/vlsu_tb/sched_write[1]}
add wave -noupdate -radix hexadecimal {/vlsu_tb/sched_addr[1]}
add wave -noupdate -radix unsigned {/vlsu_tb/sched_vdst[1]}
add wave -noupdate -divider {SP Req/Res Ch0}
add wave -noupdate {/vlsu_tb/sp_req[0]}
add wave -noupdate {/vlsu_tb/sp_stall[0]}
add wave -noupdate {/vlsu_tb/sp_res[0]}
add wave -noupdate -divider {SP Req/Res Ch1}
add wave -noupdate {/vlsu_tb/sp_req[1]}
add wave -noupdate {/vlsu_tb/sp_stall[1]}
add wave -noupdate {/vlsu_tb/sp_res[1]}
add wave -noupdate -divider Writeback
add wave -noupdate /vlsu_tb/wb_valid_out
add wave -noupdate /vlsu_tb/wb_ready_in
add wave -noupdate -radix unsigned /vlsu_tb/wb_vdst
add wave -noupdate -divider Status
add wave -noupdate /vlsu_tb/vlsu_busy
add wave -noupdate /vlsu_tb/load_queue_full
add wave -noupdate -divider {DUT Arbitration}
add wave -noupdate -radix unsigned /vlsu_tb/DUT/rr_priority
add wave -noupdate /vlsu_tb/DUT/found_pending
add wave -noupdate -radix unsigned /vlsu_tb/DUT/winner_idx
add wave -noupdate /vlsu_tb/DUT/resp_pending
add wave -noupdate -divider {DUT Load Queue}
add wave -noupdate /vlsu_tb/DUT/fifo_wr_en
add wave -noupdate /vlsu_tb/DUT/fifo_shift
add wave -noupdate /vlsu_tb/DUT/fifo_empty
add wave -noupdate /vlsu_tb/DUT/fifo_full
add wave -noupdate -divider {DUT Resp Queue}
add wave -noupdate /vlsu_tb/DUT/resp_wr_en
add wave -noupdate /vlsu_tb/DUT/resp_shift
add wave -noupdate /vlsu_tb/DUT/resp_empty
add wave -noupdate /vlsu_tb/DUT/resp_full
add wave -noupdate -divider Test
add wave -noupdate -radix unsigned /vlsu_tb/test_num
add wave -noupdate -radix unsigned /vlsu_tb/errors
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {0 ns} 0}
quietly wave cursor active 0
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
WaveRestoreZoom {0 ns} {1 us}
