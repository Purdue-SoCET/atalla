onerror {resume}
quietly WaveActivateNextPane {} 0

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
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/sched_req[0].spad_addr
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/sched_req[0].dram_addr
add wave -noupdate /scratchpad_tb/sif/sched_res[0].valid

# ── DRAM Interface [0] ────────────────────────────────────
add wave -noupdate -divider {DRAM [0]}
add wave -noupdate /scratchpad_tb/sif/be_dram_req[0].valid
add wave -noupdate /scratchpad_tb/sif/be_dram_req[0].write
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/be_dram_req[0].id
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/be_dram_req[0].wdata
add wave -noupdate /scratchpad_tb/sif/dram_be_res[0].valid
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/dram_be_res[0].id
add wave -noupdate -radix hexadecimal /scratchpad_tb/sif/dram_be_res[0].rdata
add wave -noupdate /scratchpad_tb/sif/dram_be_stall[0]
add wave -noupdate /scratchpad_tb/sif/be_dram_stall[0]

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
configure wave -namecolwidth 280
configure wave -valuecolwidth 120
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
WaveRestoreZoom {0 ps} {1000 ps}
