onerror {resume}
quietly WaveActivateNextPane {} 0
delete wave *

# ── Clock & Reset ─────────────────────────────────────────
add wave -noupdate -divider {Clock & Reset}
add wave -noupdate /backend_tb/clk
add wave -noupdate /backend_tb/n_rst

# ── Scheduler Interface ───────────────────────────────────
add wave -noupdate -divider {Scheduler [0]}
add wave -noupdate /backend_tb/bif/sched_req[0].valid
add wave -noupdate /backend_tb/bif/sched_req[0].write
add wave -noupdate -radix unsigned /backend_tb/bif/sched_req[0].num_rows
add wave -noupdate -radix unsigned /backend_tb/bif/sched_req[0].num_cols
add wave -noupdate -radix unsigned /backend_tb/bif/sched_req[0].full_num_cols
add wave -noupdate -radix hexadecimal /backend_tb/bif/sched_req[0].spad_addr
add wave -noupdate -radix hexadecimal /backend_tb/bif/sched_req[0].dram_addr
add wave -noupdate /backend_tb/bif/sched_stall[0]
add wave -noupdate /backend_tb/bif/sched_accepted[0]
add wave -noupdate /backend_tb/bif/sdma_done[0]
add wave -noupdate -radix hexadecimal /backend_tb/bif/sdma_done_req[0].spad_addr
add wave -noupdate -radix hexadecimal /backend_tb/bif/sdma_done_req[0].dram_addr
add wave -noupdate -radix unsigned /backend_tb/bif/sdma_done_req[0].num_rows
add wave -noupdate -radix unsigned /backend_tb/bif/sdma_done_req[0].num_cols

# ── Backend Internals ─────────────────────────────────────
add wave -noupdate -divider {Backend Internals}
add wave -noupdate /backend_tb/DUT/busy
add wave -noupdate /backend_tb/DUT/nxt_busy
add wave -noupdate -radix unsigned /backend_tb/DUT/uuid
add wave -noupdate -radix unsigned /backend_tb/DUT/sub_uuid
add wave -noupdate -radix unsigned /backend_tb/DUT/schedule_request_counter
add wave -noupdate -radix unsigned /backend_tb/DUT/num_request
add wave -noupdate -radix hexadecimal /backend_tb/DUT/row_base_addr
add wave -noupdate -radix hexadecimal /backend_tb/DUT/nxt_row_base_addr
add wave -noupdate /backend_tb/DUT/initial_request_done
add wave -noupdate -radix binary /backend_tb/DUT/dram_vector_mask

# ── Latched Request ───────────────────────────────────────
add wave -noupdate -divider {Latched Request}
add wave -noupdate -radix hexadecimal /backend_tb/DUT/latched_req.spad_addr
add wave -noupdate -radix hexadecimal /backend_tb/DUT/latched_req.dram_addr
add wave -noupdate -radix unsigned /backend_tb/DUT/latched_req.num_rows
add wave -noupdate -radix unsigned /backend_tb/DUT/latched_req.num_cols
add wave -noupdate -radix unsigned /backend_tb/DUT/latched_req.full_num_cols
add wave -noupdate /backend_tb/DUT/latched_req.write
add wave -noupdate -radix hexadecimal /backend_tb/DUT/effective_req.spad_addr
add wave -noupdate -radix hexadecimal /backend_tb/DUT/effective_req.dram_addr

# ── DRAM Interface ────────────────────────────────────────
add wave -noupdate -divider {DRAM [0]}
add wave -noupdate /backend_tb/bif/be_dram_req[0].valid
add wave -noupdate /backend_tb/bif/be_dram_req[0].write
add wave -noupdate -radix hexadecimal /backend_tb/bif/be_dram_req[0].dram_addr
add wave -noupdate -radix hexadecimal /backend_tb/bif/be_dram_req[0].id
add wave -noupdate -radix hexadecimal /backend_tb/bif/be_dram_req[0].wdata
add wave -noupdate -radix binary /backend_tb/bif/be_dram_req[0].dram_vector_mask
add wave -noupdate /backend_tb/bif/dram_be_res[0].valid
add wave -noupdate -radix hexadecimal /backend_tb/bif/dram_be_res[0].id
add wave -noupdate -radix hexadecimal /backend_tb/bif/dram_be_res[0].rdata
add wave -noupdate /backend_tb/bif/dram_be_stall[0]
add wave -noupdate /backend_tb/bif/be_dram_stall[0]

# ── DRAM Request Queue ────────────────────────────────────
add wave -noupdate -divider {DRAM Req Queue}
add wave -noupdate -radix hexadecimal /backend_tb/DUT/be_internal/be_dr_req_q_in.dram_addr
add wave -noupdate -radix hexadecimal /backend_tb/DUT/be_internal/be_dr_req_q_in.id
add wave -noupdate -radix hexadecimal /backend_tb/DUT/be_internal/be_dr_req_q_in.sub_id
add wave -noupdate /backend_tb/DUT/be_internal/be_dr_req_q_in.sched_valid
add wave -noupdate /backend_tb/DUT/be_internal/be_dr_req_q_in.initial_request_done
add wave -noupdate /backend_tb/DUT/be_internal/be_dr_req_q_out.burst_complete
add wave -noupdate /backend_tb/DUT/be_internal/be_dr_req_q_out.transaction_complete
add wave -noupdate /backend_tb/DUT/be_internal/be_dr_req_q_out.dram_queue_full

# ── SRAM Write Latch ──────────────────────────────────────
add wave -noupdate -divider {SRAM Write Latch}
add wave -noupdate /backend_tb/DUT/be_internal/sr_wr_l_out.sram_write_req_latched
add wave -noupdate /backend_tb/DUT/be_internal/sr_wr_l_out.latch_full
add wave -noupdate -radix hexadecimal /backend_tb/DUT/be_internal/sr_wr_l_out.sram_write_req.spad_addr

# ── Body Interface ────────────────────────────────────────
add wave -noupdate -divider {Body [0]}
add wave -noupdate /backend_tb/bif/be_req[0].valid
add wave -noupdate /backend_tb/bif/be_req[0].write
add wave -noupdate -radix hexadecimal /backend_tb/bif/be_req[0].spad_addr
add wave -noupdate -radix unsigned /backend_tb/bif/be_req[0].row_id
add wave -noupdate -radix hexadecimal /backend_tb/bif/be_req[0].wdata
add wave -noupdate /backend_tb/bif/be_res[0].valid
add wave -noupdate -radix hexadecimal /backend_tb/bif/be_res[0].rdata
add wave -noupdate /backend_tb/bif/be_stall[0]

# ── Test Tracking ─────────────────────────────────────────
add wave -noupdate -divider {Test Tracking}
add wave -noupdate -radix unsigned /backend_tb/PROG/total_tests
add wave -noupdate -radix unsigned /backend_tb/PROG/passed_tests
add wave -noupdate -radix unsigned /backend_tb/PROG/failed_tests
add wave -noupdate /backend_tb/PROG/current_test_type

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
