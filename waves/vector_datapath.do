onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /vector_datapath_tb/CLK
add wave -noupdate /vector_datapath_tb/nRST
add wave -noupdate -divider <NULL>
add wave -noupdate -group status -expand -group {UNIT READIES} -label {FU READIES} -radix binary /vector_datapath_tb/vif/unit_ready_signals.fu_global_status
add wave -noupdate -group status -expand -group {UNIT READIES} -label {GSAU READY} /vector_datapath_tb/vif/unit_ready_signals.gsau_status
add wave -noupdate -group status -expand -group {UNIT READIES} -label {VLSU READY} -radix binary /vector_datapath_tb/vif/unit_ready_signals.vlsu_status
add wave -noupdate -group status -expand -group {UNIT READIES} -label {REDUCTION READY} /vector_datapath_tb/vif/unit_ready_signals.reduction_status
add wave -noupdate -group status -expand -group {WB READIES} -label {LANE WB READIES} -radix binary /vector_datapath_tb/vif/wb_ready_signals.lanes_wb_ready
add wave -noupdate -group status -expand -group {WB READIES} -label {GSAU WB READY} /vector_datapath_tb/vif/wb_ready_signals.gsau_wb_ready
add wave -noupdate -group status -expand -group {WB READIES} -label {VLSU WB READY} -radix binary /vector_datapath_tb/vif/wb_ready_signals.vlsu_wb_ready
add wave -noupdate -group status -expand -group {WB READIES} -label {REDUCTION WB READY} /vector_datapath_tb/vif/wb_ready_signals.reduction_wb_ready
add wave -noupdate -divider <NULL>
add wave -noupdate -group Lanes -divider {LANES IN}
add wave -noupdate -group Lanes -expand /vector_datapath_tb/vif/lanes_in.lane_issue_ports
add wave -noupdate -group Lanes -divider {LANES OUT}
add wave -noupdate -group Lanes /vector_datapath_tb/vif/lanes_out.result_collectors
add wave -noupdate -group Lanes /vector_datapath_tb/vif/lanes_out.reduction
add wave -noupdate -divider <NULL>
add wave -noupdate -group GSAU -group {GSAU IN} -label {veg vdata 1} /vector_datapath_tb/vif/gsau_in.veg_vdata1
add wave -noupdate -group GSAU -group {GSAU IN} -label {veg vdata 2} /vector_datapath_tb/vif/gsau_in.veg_vdata2
add wave -noupdate -group GSAU -group {GSAU IN} -label vd /vector_datapath_tb/vif/gsau_in.vd
add wave -noupdate -group GSAU -group {GSAU IN} -label {valid in} /vector_datapath_tb/vif/gsau_in.valid_in
add wave -noupdate -group GSAU -group {GSAU IN} -label weight /vector_datapath_tb/vif/gsau_in.weight
add wave -noupdate -group GSAU -group {GSAU OUT} -label sb_ready /vector_datapath_tb/vif/gsau_out.ready_out
add wave -noupdate -group GSAU -group {GSAU OUT} -label psum /vector_datapath_tb/vif/gsau_out.psum
add wave -noupdate -group GSAU -group {GSAU OUT} -label vd /vector_datapath_tb/vif/gsau_out.vd
add wave -noupdate -group GSAU -group {GSAU OUT} -label {wb valid} /vector_datapath_tb/vif/gsau_out.wb_valid
add wave -noupdate -divider <NULL>
add wave -noupdate -group VLSU -divider {VLSU IN}
add wave -noupdate -group VLSU -expand /vector_datapath_tb/vif/vlsu_in.sched_req
add wave -noupdate -group VLSU -expand /vector_datapath_tb/vif/vlsu_in.vrf_data
add wave -noupdate -group VLSU -divider {VLSU OUT}
add wave -noupdate -group VLSU -expand /vector_datapath_tb/vif/vlsu_out.wb
add wave -noupdate -group VLSU -expand /vector_datapath_tb/vif/vlsu_out.status
add wave -noupdate -divider <NULL>
add wave -noupdate -group sif.vec_frontend -divider <NULL>
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} -divider {REQ 0}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[0].valid}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[0].write}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[0].spad_addr}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[0].num_rows}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[0].num_cols}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[0].row_id}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[0].col_id}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[0].row_or_col}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[0].xbar}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[0].wdata}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} -divider {REQ 1}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[1].valid}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[1].write}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[1].spad_addr}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[1].num_rows}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[1].num_cols}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[1].row_id}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[1].col_id}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[1].row_or_col}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[1].xbar}
add wave -noupdate -group sif.vec_frontend -group {VEC REQ} {/vector_datapath_tb/sif/vec_req[1].wdata}
add wave -noupdate -group sif.vec_frontend -divider <NULL>
add wave -noupdate -group sif.vec_frontend -group {VEC RES} -divider {RES 0}
add wave -noupdate -group sif.vec_frontend -group {VEC RES} {/vector_datapath_tb/sif/vec_res[0].valid}
add wave -noupdate -group sif.vec_frontend -group {VEC RES} {/vector_datapath_tb/sif/vec_res[0].write}
add wave -noupdate -group sif.vec_frontend -group {VEC RES} {/vector_datapath_tb/sif/vec_res[0].rdata}
add wave -noupdate -group sif.vec_frontend -group {VEC RES} -divider {RES 1}
add wave -noupdate -group sif.vec_frontend -group {VEC RES} {/vector_datapath_tb/sif/vec_res[1].valid}
add wave -noupdate -group sif.vec_frontend -group {VEC RES} {/vector_datapath_tb/sif/vec_res[1].write}
add wave -noupdate -group sif.vec_frontend -group {VEC RES} {/vector_datapath_tb/sif/vec_res[1].rdata}
add wave -noupdate -group sif.vec_frontend -divider <NULL>
add wave -noupdate -group sif.vec_frontend -group {FE VEC STALL} {/vector_datapath_tb/sif/fe_vec_stall[0]}
add wave -noupdate -group sif.vec_frontend -group {FE VEC STALL} {/vector_datapath_tb/sif/fe_vec_stall[1]}
add wave -noupdate -divider <NULL>
add wave -noupdate -group gsauif.sa -expand -group gsau->sa /vector_datapath_tb/gsauif/sa_array_in
add wave -noupdate -group gsauif.sa -expand -group gsau->sa /vector_datapath_tb/gsauif/sa_array_in_partials
add wave -noupdate -group gsauif.sa -expand -group gsau->sa /vector_datapath_tb/gsauif/sa_input_en
add wave -noupdate -group gsauif.sa -expand -group gsau->sa /vector_datapath_tb/gsauif/sa_weight_en
add wave -noupdate -group gsauif.sa -expand -group gsau->sa /vector_datapath_tb/gsauif/sa_partial_en
add wave -noupdate -group gsauif.sa -expand -group gsau->sa /vector_datapath_tb/gsauif/sa_ready_out
add wave -noupdate -group gsauif.sa -expand -group sa->gsau /vector_datapath_tb/gsauif/sa_array_output
add wave -noupdate -group gsauif.sa -expand -group sa->gsau /vector_datapath_tb/gsauif/sa_valid_in
add wave -noupdate -group gsauif.sa -expand -group sa->gsau /vector_datapath_tb/gsauif/sa_ready_in
add wave -noupdate -divider <NULL>
add wave -noupdate -group {reduction unit} -expand -subitemconfig {/vector_datapath_tb/dut/ruif/in.ports -expand {/vector_datapath_tb/dut/ruif/in.ports[0]} -expand} /vector_datapath_tb/dut/ruif/in
add wave -noupdate -group {reduction unit} /vector_datapath_tb/dut/ruif/out
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {2001161230 ps} 0} {{Cursor 2} {86625 ps} 0}
quietly wave cursor active 2
configure wave -namecolwidth 363
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
configure wave -timelineunits ps
update
WaveRestoreZoom {0 ps} {1212750 ps}
