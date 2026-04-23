onerror {resume}
quietly WaveActivateNextPane {} 0
delete wave *
# ── Clock / Reset ─────────────────────────────────────────
add wave -noupdate -divider {Clock / Reset}
add wave -noupdate /vlsu_tb/CLK
add wave -noupdate /vlsu_tb/nRST
# ── Channel 0 ─────────────────────────────────────────────
add wave -noupdate -divider {===== Channel 0 =====}
add wave -noupdate -divider {CH0 Scheduler}
add wave -noupdate {/vlsu_tb/vif/sched_req[0].valid}
add wave -noupdate {/vlsu_tb/vif/sched_req[0].write}
add wave -noupdate -radix hexadecimal {/vlsu_tb/vif/sched_req[0].spad_addr}
add wave -noupdate -radix unsigned {/vlsu_tb/vif/sched_req[0].vdst}
add wave -noupdate -radix unsigned {/vlsu_tb/vif/sched_req[0].num_cols}
add wave -noupdate -radix unsigned {/vlsu_tb/vif/sched_req[0].row_id}
add wave -noupdate {/vlsu_tb/vif/sched_res[0].ready}
add wave -noupdate -divider {CH0 VRF Store}
add wave -noupdate {/vlsu_tb/vif/vrf_store[0].valid}
add wave -noupdate -radix hexadecimal {/vlsu_tb/vif/vrf_store[0].data}
add wave -noupdate -divider {CH0 Scratchpad Request}
add wave -noupdate {/vlsu_tb/sif/vec_req[0].valid}
add wave -noupdate {/vlsu_tb/sif/vec_req[0].write}
add wave -noupdate -radix hexadecimal {/vlsu_tb/sif/vec_req[0].spad_addr}
add wave -noupdate -radix unsigned {/vlsu_tb/sif/vec_req[0].row_id}
add wave -noupdate -radix unsigned {/vlsu_tb/sif/vec_req[0].num_cols}
add wave -noupdate {/vlsu_tb/sif/fe_vec_stall[0]}
add wave -noupdate -divider {CH0 Scratchpad Response}
add wave -noupdate {/vlsu_tb/sif/vec_res[0].valid}
add wave -noupdate -radix hexadecimal {/vlsu_tb/sif/vec_res[0].rdata}
add wave -noupdate {/vlsu_tb/sif/fe_vec_res_stall[0]}
add wave -noupdate -divider {CH0 Writeback}
add wave -noupdate {/vlsu_tb/vif/wb_out[0].valid}
add wave -noupdate -radix unsigned {/vlsu_tb/vif/wb_out[0].vdst}
add wave -noupdate -radix hexadecimal {/vlsu_tb/vif/wb_out[0].data}
add wave -noupdate {/vlsu_tb/vif/wb_ready[0]}
add wave -noupdate -divider {CH0 Status}
add wave -noupdate {/vlsu_tb/vif/status[0].busy}
add wave -noupdate {/vlsu_tb/vif/status[0].load_queue_full}
# ── CH0 DUT Internals ────────────────────────────────────
add wave -noupdate -divider {CH0 DUT Internals}
add wave -noupdate /vlsu_tb/DUT0/is_load
add wave -noupdate /vlsu_tb/DUT0/is_store
add wave -noupdate /vlsu_tb/DUT0/can_accept
add wave -noupdate /vlsu_tb/DUT0/resp_incoming
# ── CH0 Load Queue (vdst FIFO) ───────────────────────────
add wave -noupdate -divider {CH0 Load Queue FIFO}
add wave -noupdate /vlsu_tb/DUT0/lq_wr_en
add wave -noupdate /vlsu_tb/DUT0/lq_shift
add wave -noupdate -radix unsigned /vlsu_tb/DUT0/lq_din
add wave -noupdate -radix unsigned /vlsu_tb/DUT0/lq_dout
add wave -noupdate /vlsu_tb/DUT0/lq_empty
add wave -noupdate /vlsu_tb/DUT0/lq_full
# ── CH0 Skid Buffer ──────────────────────────────────────
add wave -noupdate -divider {CH0 Skid Buffer}
add wave -noupdate /vlsu_tb/DUT0/skid_valid_r
add wave -noupdate /vlsu_tb/DUT0/skid_valid_next
add wave -noupdate -radix hexadecimal /vlsu_tb/DUT0/skid_data_r
# ── Channel 1 ─────────────────────────────────────────────
add wave -noupdate -divider {===== Channel 1 =====}
add wave -noupdate -divider {CH1 Scheduler}
add wave -noupdate {/vlsu_tb/vif/sched_req[1].valid}
add wave -noupdate {/vlsu_tb/vif/sched_req[1].write}
add wave -noupdate {/vlsu_tb/vif/sched_res[1].ready}
add wave -noupdate -divider {CH1 Scratchpad}
add wave -noupdate {/vlsu_tb/sif/vec_req[1].valid}
add wave -noupdate {/vlsu_tb/sif/fe_vec_stall[1]}
add wave -noupdate {/vlsu_tb/sif/vec_res[1].valid}
add wave -noupdate -divider {CH1 Writeback}
add wave -noupdate {/vlsu_tb/vif/wb_out[1].valid}
add wave -noupdate -radix unsigned {/vlsu_tb/vif/wb_out[1].vdst}
add wave -noupdate {/vlsu_tb/vif/wb_ready[1]}
add wave -noupdate -divider {CH1 Load Queue FIFO}
add wave -noupdate /vlsu_tb/DUT1/lq_wr_en
add wave -noupdate /vlsu_tb/DUT1/lq_shift
add wave -noupdate -radix unsigned /vlsu_tb/DUT1/lq_din
add wave -noupdate -radix unsigned /vlsu_tb/DUT1/lq_dout
add wave -noupdate /vlsu_tb/DUT1/lq_empty
add wave -noupdate /vlsu_tb/DUT1/lq_full
add wave -noupdate -divider {CH1 Skid Buffer}
add wave -noupdate /vlsu_tb/DUT1/skid_valid_r
add wave -noupdate /vlsu_tb/DUT1/skid_valid_next
# ── Test Tracking ─────────────────────────────────────────
add wave -noupdate -divider {Test Tracking}
add wave -noupdate -radix unsigned /vlsu_tb/test_num
add wave -noupdate -radix unsigned /vlsu_tb/errors
add wave -noupdate -radix unsigned /vlsu_tb/total_tests
add wave -noupdate /vlsu_tb/test_name
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {0 ns} 0}
quietly wave cursor active 0
configure wave -namecolwidth 300
configure wave -valuecolwidth 140
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
WaveRestoreZoom {0 ns} {1000 ns}
