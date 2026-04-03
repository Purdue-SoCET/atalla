onerror {resume}
quietly WaveActivateNextPane {} 0

# ---- CLK / RST ----
add wave -noupdate -group CLK_RST /vector_core_L2_tb/CLK
add wave -noupdate -group CLK_RST /vector_core_L2_tb/nRST
add wave -noupdate -group CLK_RST /vector_core_L2_tb/cycle_count

# ---- LANES_IN ----
add wave -noupdate -group LANES_IN /vector_core_L2_tb/vif/lanes_in
add wave -noupdate -group LANES_IN -expand /vector_core_L2_tb/vif/lanes_in/lane_issue_ports
add wave -noupdate -group LANES_IN -expand /vector_core_L2_tb/dut/vif/lanes_in/lane_issue_ports[0]
add wave -noupdate -group LANES_IN -expand /vector_core_L2_tb/dut/vif/lanes_in/lane_issue_ports[1]

# ---- LANES_OUT ----
add wave -noupdate -group LANES_OUT /vector_core_L2_tb/vif/lanes_out
add wave -noupdate -group LANES_OUT -expand /vector_core_L2_tb/vif/lanes_out/result_collectors
add wave -noupdate -group LANES_OUT -expand /vector_core_L2_tb/vif/lanes_out/reduction

# ---- READY_STATUS ----
add wave -noupdate -group READY_STATUS /vector_core_L2_tb/vif/unit_ready_signals
add wave -noupdate -group READY_STATUS /vector_core_L2_tb/vif/wb_ready_signals

# ---- GSAU_IN ----
add wave -noupdate -group GSAU_IN /vector_core_L2_tb/vif/gsau_in

# ---- GSAU_OUT ----
add wave -noupdate -group GSAU_OUT /vector_core_L2_tb/gsauif/wb_valid_out
add wave -noupdate -group GSAU_OUT /vector_core_L2_tb/gsauif/wb_psum
add wave -noupdate -group GSAU_OUT /vector_core_L2_tb/gsauif/wb_wbdst

# ---- GSAU_SA ----
add wave -noupdate -group GSAU_SA /vector_core_L2_tb/gsauif/sa_array_in
add wave -noupdate -group GSAU_SA /vector_core_L2_tb/gsauif/sa_input_en
add wave -noupdate -group GSAU_SA /vector_core_L2_tb/gsauif/sa_weight_en
add wave -noupdate -group GSAU_SA /vector_core_L2_tb/gsauif/sa_partial_en
add wave -noupdate -group GSAU_SA /vector_core_L2_tb/gsauif/sa_ready_out
add wave -noupdate -group GSAU_SA /vector_core_L2_tb/gsauif/sa_array_output
add wave -noupdate -group GSAU_SA /vector_core_L2_tb/gsauif/sa_valid_in
add wave -noupdate -group GSAU_SA /vector_core_L2_tb/gsauif/sa_ready_in
add wave -noupdate -group GSAU_SA /vector_core_L2_tb/gsauif/sb_ready_out
add wave -noupdate -group GSAU_SA /vector_core_L2_tb/gsauif/sb_valid_in
add wave -noupdate -group GSAU_SA /vector_core_L2_tb/gsauif/sb_vdst
add wave -noupdate -group GSAU_SA /vector_core_L2_tb/gsauif/sb_weight

# ---- VLSU_IN ----
add wave -noupdate -group VLSU_IN /vector_core_L2_tb/vif/vlsu_in
add wave -noupdate -group VLSU_IN -expand /vector_core_L2_tb/vif/vlsu_in/sched_req

# ---- VLSU_OUT ----
add wave -noupdate -group VLSU_OUT /vector_core_L2_tb/vif/vlsu_out
add wave -noupdate -group VLSU_OUT -expand /vector_core_L2_tb/vif/vlsu_out/wb

# ---- SCRATCHPAD (sif) ----
add wave -noupdate -group SCRATCHPAD /vector_core_L2_tb/sif/vec_req
add wave -noupdate -group SCRATCHPAD /vector_core_L2_tb/sif/vec_res
add wave -noupdate -group SCRATCHPAD -expand /vector_core_L2_tb/sif/vec_req[0]
add wave -noupdate -group SCRATCHPAD -expand /vector_core_L2_tb/sif/vec_req[1]
add wave -noupdate -group SCRATCHPAD -expand /vector_core_L2_tb/sif/vec_res[0]
add wave -noupdate -group SCRATCHPAD -expand /vector_core_L2_tb/sif/vec_res[1]
add wave -noupdate -group SCRATCHPAD /vector_core_L2_tb/sif/fe_vec_stall
add wave -noupdate -group SCRATCHPAD /vector_core_L2_tb/sif/fe_stall

# ---- DRAM (backpressure) ----
add wave -noupdate -group DRAM /vector_core_L2_tb/dram_stall_inject
add wave -noupdate -group DRAM /vector_core_L2_tb/sif/dram_be_stall
add wave -noupdate -group DRAM /vector_core_L2_tb/sif/be_dram_stall
add wave -noupdate -group DRAM /vector_core_L2_tb/sif/be_dram_req

TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {0 ps} 0}
configure wave -namecolwidth 280
configure wave -valuecolwidth 200
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
WaveRestoreZoom {0 ps} {2000 ns}
