onerror {resume}
quietly WaveActivateNextPane {} 0
delete wave *
# ── Clock & Reset ─────────────────────────────────────────
add wave -noupdate -divider {Clock & Reset}
add wave -noupdate /scratchpad_tb/clk
add wave -noupdate /scratchpad_tb/n_rst
# ── Scheduler Interface ───────────────────────────────────
add wave -noupdate -divider {Scheduler [0]}
add wave -noupdate /scratchpad_tb/sif/sched_req[0].valid
add wave -noupdate /scratchpad_tb/sif/sched_req[0].write
add wave -noupdate -radix unsigned /scratchpad_tb/sif/sched_req[0].num_rows
add wave -noupdate -radix unsigned /scratchpad_tb/sif/sched_req[0].num_cols
add wave -noupdate -radix unsigned /scratchpad_tb/sif/sched_req[0].full_num_cols
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/sched_req[0].spad_addr
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/sched_req[0].dram_addr
add wave -noupdate /scratchpad_tb/sif/sched_stall[0]
add wave -noupdate /scratchpad_tb/sif/sched_accepted[0]
add wave -noupdate /scratchpad_tb/sif/sdma_done[0]
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/sdma_done_req[0].spad_addr
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/sdma_done_req[0].dram_addr
add wave -noupdate -radix unsigned /scratchpad_tb/sif/sdma_done_req[0].num_rows
add wave -noupdate -radix unsigned /scratchpad_tb/sif/sdma_done_req[0].num_cols
# ── Backend Internals ─────────────────────────────────────
add wave -noupdate -divider {Backend [0] Internals}
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/busy
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/nxt_busy
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/uuid
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/sub_uuid
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/schedule_request_counter
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/num_request
add wave -noupdate -radix hexadecimal /scratchpad_tb/DUT/g_scpad[0]/backend/row_base_addr
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/initial_request_done
add wave -noupdate -radix binary /scratchpad_tb/DUT/g_scpad[0]/backend/dram_vector_mask
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/be_id
# ── Latched Request ───────────────────────────────────────
add wave -noupdate -divider {Backend Latched Request}
add wave -noupdate -radix hexadecimal /scratchpad_tb/DUT/g_scpad[0]/backend/latched_req.spad_addr
add wave -noupdate -radix hexadecimal /scratchpad_tb/DUT/g_scpad[0]/backend/latched_req.dram_addr
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/latched_req.num_rows
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/latched_req.num_cols
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/latched_req.full_num_cols
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/latched_req.write
add wave -noupdate -radix hexadecimal /scratchpad_tb/DUT/g_scpad[0]/backend/effective_req.spad_addr
add wave -noupdate -radix hexadecimal /scratchpad_tb/DUT/g_scpad[0]/backend/effective_req.dram_addr
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/effective_req.write
# ── DRAM Interface ────────────────────────────────────────
add wave -noupdate -divider {DRAM [0]}
add wave -noupdate /scratchpad_tb/sif/be_dram_req[0].valid
add wave -noupdate /scratchpad_tb/sif/be_dram_req[0].write
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/be_dram_req[0].dram_addr
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/be_dram_req[0].id
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/be_dram_req[0].wdata
add wave -noupdate -radix binary /scratchpad_tb/sif/be_dram_req[0].dram_vector_mask
add wave -noupdate -radix unsigned /scratchpad_tb/sif/be_dram_req[0].num_request
add wave -noupdate /scratchpad_tb/sif/be_dram_req[0].w_last
add wave -noupdate /scratchpad_tb/sif/dram_be_res[0].valid
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/dram_be_res[0].id
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/dram_be_res[0].rdata
add wave -noupdate -radix binary /scratchpad_tb/sif/dram_be_res[0].dram_vector_mask
add wave -noupdate /scratchpad_tb/sif/dram_be_stall[0]
add wave -noupdate /scratchpad_tb/sif/be_dram_stall[0]
# ── SRAM Write Latch ──────────────────────────────────────
add wave -noupdate -divider {SRAM Write Latch [0]}
add wave -noupdate -radix binary /scratchpad_tb/DUT/g_scpad[0]/backend/be_internal/sr_wr_l_in.dram_vector_mask
add wave -noupdate -radix hexadecimal /scratchpad_tb/DUT/g_scpad[0]/backend/be_sr_wr_latch/masked_rddata
# ── DRAM Request Queue Internals ──────────────────────────
add wave -noupdate -divider {DRAM Req Queue [0]}
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/dr_rd_req_q/fifo_head
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/dr_rd_req_q/fifo_tail
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/dr_rd_req_q/head_idx
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/dr_rd_req_q/tail_idx
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/dr_rd_req_q/fifo_full
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/dr_rd_req_q/fifo_empty
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/dr_rd_req_q/request_completed_counter
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/dr_rd_req_q/sram_res_valid
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/be_internal/be_dr_req_q_out.dram_queue_full
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/be_internal/be_dr_req_q_out.transaction_complete
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/be_internal/be_dr_req_q_out.burst_complete
# ── Body cntrl FIFO state ─────────────────────────────────
add wave -noupdate -divider {Body scpad_cntrl [0]}
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/scpad_cntrl/rd_fifo_full
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/scpad_cntrl/rd_fifo_empty
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/scpad_cntrl/wr_fifo_full
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/scpad_cntrl/wr_fifo_empty
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/scpad_cntrl/sram_rd_busy
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/scpad_cntrl/sram_wr_busy
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/scpad_cntrl/rd_en
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/scpad_cntrl/wr_en
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/scpad_cntrl/incoming_valid
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/scpad_cntrl/incoming_write
add wave -noupdate -radix binary /scratchpad_tb/DUT/g_scpad[0]/body/scpad_cntrl/rd_inflight_pipe
# ── Body SRAM-level signals (loss tracking) ───────────────
add wave -noupdate -divider {Body SRAM Req/Resp [0]}
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/sif/cntrl_spad_req[0].valid
add wave -noupdate -radix hexadecimal /scratchpad_tb/DUT/g_scpad[0]/sif/cntrl_spad_req[0].xbar.slot
add wave -noupdate -radix binary /scratchpad_tb/DUT/g_scpad[0]/body/bank_rdone
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/sif/spad_xbar_req[0].valid
add wave -noupdate -radix binary /scratchpad_tb/DUT/g_scpad[0]/body/meta_valid_pipe
# ── Body wxbar FIFO state ─────────────────────────────────
add wave -noupdate -divider {Body wxbar [0]}
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/sif/head_stomach_req[0].valid
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/wxbar/fifo_full
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/wxbar/fifo_empty
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/wxbar/rd_en
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/wxbar/fifo_in.valid
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/sif/xbar_cntrl_req[0].valid
# ── Body head grant ───────────────────────────────────────
add wave -noupdate -divider {Body head [0]}
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/head/grant_be
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/head/grant_fe
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/head/be_v
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/head/fe_v
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/head/pipe_busy
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/body/head/downstream_stall
add wave -noupdate /scratchpad_tb/sif/w_stall[0]
add wave -noupdate /scratchpad_tb/sif/r_stall[0]
# ── Body Interface (Backend ↔ Body) ───────────────────────
add wave -noupdate -divider {Body [0]}
add wave -noupdate /scratchpad_tb/sif/be_req[0].valid
add wave -noupdate /scratchpad_tb/sif/be_req[0].write
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/be_req[0].spad_addr
add wave -noupdate -radix unsigned /scratchpad_tb/sif/be_req[0].row_id
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/be_req[0].wdata
add wave -noupdate /scratchpad_tb/sif/be_res[0].valid
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/be_res[0].rdata
add wave -noupdate /scratchpad_tb/sif/be_stall[0]
# ── Vector / Frontend Interface ───────────────────────────
add wave -noupdate -divider {Vector / Frontend [0]}
add wave -noupdate /scratchpad_tb/sif/vec_req[0].valid
add wave -noupdate /scratchpad_tb/sif/vec_req[0].write
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/vec_req[0].spad_addr
add wave -noupdate /scratchpad_tb/sif/vec_res[0].valid
add wave -noupdate /scratchpad_tb/sif/fe_vec_stall[0]
add wave -noupdate /scratchpad_tb/sif/fe_vec_res_stall[0]
# ── Test Tracking ─────────────────────────────────────────
add wave -noupdate -divider {Test Tracking}
add wave -noupdate -radix unsigned /scratchpad_tb/total_tests
add wave -noupdate -radix unsigned /scratchpad_tb/passed_tests
add wave -noupdate -radix unsigned /scratchpad_tb/failed_tests
add wave -noupdate /scratchpad_tb/current_test_type
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {0 ps} 0}
configure wave -namecolwidth 380
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
configure wave -timelineunits ps
update
WaveRestoreZoom {0 ps} {5000 ps}
