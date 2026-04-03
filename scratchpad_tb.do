onerror {resume}
quietly WaveActivateNextPane {} 0
delete wave *

# ── Clock & Reset ─────────────────────────────────────────
add wave -noupdate -divider {Clock & Reset}
add wave -noupdate /scratchpad_tb/clk
add wave -noupdate /scratchpad_tb/n_rst

# ── Vector Core Interface (FE, scpad[0]) ──────────────────
add wave -noupdate -divider {Vector Core [0]}
add wave -noupdate /scratchpad_tb/sif/vec_req[0].valid
add wave -noupdate /scratchpad_tb/sif/vec_req[0].write
add wave -noupdate -radix unsigned /scratchpad_tb/sif/vec_req[0].spad_addr
add wave -noupdate -radix unsigned /scratchpad_tb/sif/vec_req[0].num_cols
add wave -noupdate -radix unsigned /scratchpad_tb/sif/vec_req[0].row_id
add wave -noupdate /scratchpad_tb/sif/fe_vec_stall[0]
add wave -noupdate /scratchpad_tb/sif/vec_res[0].valid
add wave -noupdate /scratchpad_tb/sif/vec_res[0].write
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/vec_res[0].rdata

# ── Vector Core Interface (FE, scpad[1]) ──────────────────
add wave -noupdate -divider {Vector Core [1]}
add wave -noupdate /scratchpad_tb/sif/vec_req[1].valid
add wave -noupdate /scratchpad_tb/sif/vec_req[1].write
add wave -noupdate -radix unsigned /scratchpad_tb/sif/vec_req[1].spad_addr
add wave -noupdate -radix unsigned /scratchpad_tb/sif/vec_req[1].num_cols
add wave -noupdate -radix unsigned /scratchpad_tb/sif/vec_req[1].row_id
add wave -noupdate /scratchpad_tb/sif/fe_vec_stall[1]
add wave -noupdate /scratchpad_tb/sif/vec_res[1].valid
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/vec_res[1].rdata

# ── Scheduler / DMA Control ───────────────────────────────
add wave -noupdate -divider {Scheduler [0]}
add wave -noupdate /scratchpad_tb/sif/sched_req[0].valid
add wave -noupdate /scratchpad_tb/sif/sched_req[0].write
add wave -noupdate -radix unsigned /scratchpad_tb/sif/sched_req[0].num_rows
add wave -noupdate -radix unsigned /scratchpad_tb/sif/sched_req[0].num_cols
add wave -noupdate -radix unsigned /scratchpad_tb/sif/sched_req[0].full_num_cols
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/sched_req[0].spad_addr
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/sched_req[0].dram_addr
add wave -noupdate /scratchpad_tb/sif/sched_res[0].ready
add wave -noupdate /scratchpad_tb/sif/sched_stall[0]

# ── Backend Internals [0] ────────────────────────────────
add wave -noupdate -divider {Backend Internals [0]}
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/busy
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/uuid
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/sub_uuid
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/schedule_request_counter
add wave -noupdate -radix unsigned /scratchpad_tb/DUT/g_scpad[0]/backend/num_request
add wave -noupdate -radix hexadecimal /scratchpad_tb/DUT/g_scpad[0]/backend/row_base_addr
add wave -noupdate -radix hexadecimal /scratchpad_tb/DUT/g_scpad[0]/backend/nxt_row_base_addr
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/initial_request_done
add wave -noupdate -radix binary /scratchpad_tb/DUT/g_scpad[0]/backend/dram_vector_mask

# ── DRAM Interface [0] ────────────────────────────────────
add wave -noupdate -divider {DRAM [0]}
add wave -noupdate /scratchpad_tb/sif/be_dram_req[0].valid
add wave -noupdate /scratchpad_tb/sif/be_dram_req[0].write
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/be_dram_req[0].dram_addr
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/be_dram_req[0].id
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/be_dram_req[0].wdata
add wave -noupdate -radix binary /scratchpad_tb/sif/be_dram_req[0].dram_vector_mask
add wave -noupdate /scratchpad_tb/sif/dram_be_res[0].valid
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/dram_be_res[0].id
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/dram_be_res[0].rdata
add wave -noupdate /scratchpad_tb/sif/dram_be_stall[0]
add wave -noupdate /scratchpad_tb/sif/be_dram_stall[0]

# ── DRAM Request Queue Internals [0] ─────────────────────
add wave -noupdate -divider {DRAM Req Queue [0]}
add wave -noupdate -radix hexadecimal /scratchpad_tb/DUT/g_scpad[0]/backend/be_internal/be_dr_req_q_in.dram_addr
add wave -noupdate -radix hexadecimal /scratchpad_tb/DUT/g_scpad[0]/backend/be_internal/be_dr_req_q_in.id
add wave -noupdate -radix hexadecimal /scratchpad_tb/DUT/g_scpad[0]/backend/be_internal/be_dr_req_q_in.sub_id
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/be_internal/be_dr_req_q_out.burst_complete
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/be_internal/be_dr_req_q_out.transaction_complete
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/be_internal/be_dr_req_q_out.dram_queue_full

# ── SRAM Write Latch [0] ─────────────────────────────────
add wave -noupdate -divider {SRAM Write Latch [0]}
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/be_internal/sr_wr_l_out.sram_write_req_latched
add wave -noupdate /scratchpad_tb/DUT/g_scpad[0]/backend/be_internal/sr_wr_l_out.latch_full
add wave -noupdate -radix hexadecimal /scratchpad_tb/DUT/g_scpad[0]/backend/be_internal/sr_wr_l_out.sram_write_req.spad_addr

# ── Internal Pipeline [0] ─────────────────────────────────
add wave -noupdate -divider {Pipeline [0]}
add wave -noupdate /scratchpad_tb/sif/fe_req[0].valid
add wave -noupdate /scratchpad_tb/sif/fe_stall[0]
add wave -noupdate /scratchpad_tb/sif/be_req[0].valid
add wave -noupdate /scratchpad_tb/sif/be_req[0].write
add wave -noupdate /scratchpad_tb/sif/be_stall[0]
add wave -noupdate /scratchpad_tb/sif/head_stomach_req[0].valid
add wave -noupdate /scratchpad_tb/sif/head_stomach_req[0].write
add wave -noupdate /scratchpad_tb/sif/head_stomach_req[0].src
add wave -noupdate /scratchpad_tb/sif/w_stall[0]
add wave -noupdate /scratchpad_tb/sif/r_stall[0]
add wave -noupdate /scratchpad_tb/sif/xbar_cntrl_req[0].valid
add wave -noupdate /scratchpad_tb/sif/cntrl_spad_req[0].valid
add wave -noupdate /scratchpad_tb/sif/cntrl_spad_req[0].write
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/cntrl_spad_req[0].xbar
add wave -noupdate /scratchpad_tb/sif/spad_xbar_req[0].valid
add wave -noupdate /scratchpad_tb/sif/stomach_tail_res[0].valid
add wave -noupdate /scratchpad_tb/sif/stomach_tail_res[0].src
add wave -noupdate /scratchpad_tb/sif/fe_vec_res_stall[0]

TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {0 ps} 0}
configure wave -namecolwidth 340
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
WaveRestoreZoom {0 ps} {2000 ps}
