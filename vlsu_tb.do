onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -divider {Clock / Reset}
add wave -noupdate /vlsu_tb/CLK
add wave -noupdate /vlsu_tb/nRST
add wave -noupdate -divider {===== Channel 0 =====}
add wave -noupdate -divider {CH0 Scheduler}
add wave -noupdate {/vlsu_tb/vif/sched_req[0]}
add wave -noupdate {/vlsu_tb/vif/sched_res[0]}
add wave -noupdate -divider {CH0 VRF Store}
add wave -noupdate {/vlsu_tb/vif/vrf_store[0]}
add wave -noupdate -divider {CH0 Scratchpad}
add wave -noupdate {/vlsu_tb/sif/vec_req[0]}
add wave -noupdate {/vlsu_tb/sif/fe_vec_stall[0]}
add wave -noupdate {/vlsu_tb/sif/vec_res[0]}
add wave -noupdate -divider {CH0 Writeback}
add wave -noupdate {/vlsu_tb/vif/wb_out[0]}
add wave -noupdate {/vlsu_tb/vif/wb_ready[0]}
add wave -noupdate -divider {CH0 Status}
add wave -noupdate {/vlsu_tb/vif/status[0]}
add wave -noupdate -divider {CH0 DUT Internals}
add wave -noupdate /vlsu_tb/DUT0/lq_wr_en
add wave -noupdate /vlsu_tb/DUT0/lq_shift
add wave -noupdate /vlsu_tb/DUT0/lq_empty
add wave -noupdate /vlsu_tb/DUT0/lq_full
add wave -noupdate /vlsu_tb/DUT0/rq_wr_en
add wave -noupdate /vlsu_tb/DUT0/rq_shift
add wave -noupdate /vlsu_tb/DUT0/rq_empty
add wave -noupdate /vlsu_tb/DUT0/rq_full
add wave -noupdate -divider {===== Channel 1 =====}
add wave -noupdate -divider {CH1 Scheduler}
add wave -noupdate {/vlsu_tb/vif/sched_req[1]}
add wave -noupdate {/vlsu_tb/vif/sched_res[1]}
add wave -noupdate -divider {CH1 VRF Store}
add wave -noupdate {/vlsu_tb/vif/vrf_store[1]}
add wave -noupdate -divider {CH1 Scratchpad}
add wave -noupdate {/vlsu_tb/sif/vec_req[1]}
add wave -noupdate {/vlsu_tb/sif/fe_vec_stall[1]}
add wave -noupdate {/vlsu_tb/sif/vec_res[1]}
add wave -noupdate -divider {CH1 Writeback}
add wave -noupdate {/vlsu_tb/vif/wb_out[1]}
add wave -noupdate {/vlsu_tb/vif/wb_ready[1]}
add wave -noupdate -divider {CH1 Status}
add wave -noupdate {/vlsu_tb/vif/status[1]}
add wave -noupdate -divider {CH1 DUT Internals}
add wave -noupdate /vlsu_tb/DUT1/lq_wr_en
add wave -noupdate /vlsu_tb/DUT1/lq_shift
add wave -noupdate /vlsu_tb/DUT1/lq_empty
add wave -noupdate /vlsu_tb/DUT1/lq_full
add wave -noupdate /vlsu_tb/DUT1/rq_wr_en
add wave -noupdate /vlsu_tb/DUT1/rq_shift
add wave -noupdate /vlsu_tb/DUT1/rq_empty
add wave -noupdate /vlsu_tb/DUT1/rq_full
add wave -noupdate -divider Test
add wave -noupdate -radix unsigned /vlsu_tb/test_num
add wave -noupdate -radix unsigned /vlsu_tb/errors
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {2841 ns} 0}
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
WaveRestoreZoom {2005 ns} {3005 ns}
