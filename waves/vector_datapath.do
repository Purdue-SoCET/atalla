onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -expand -group I/O /vector_datapath_tb/vif/CLK
add wave -noupdate -expand -group I/O /vector_datapath_tb/vif/nRST
add wave -noupdate -expand -group I/O -expand /vector_datapath_tb/vif/vector_in
add wave -noupdate -expand -group I/O -expand -subitemconfig {/vector_datapath_tb/vif/vector_out.ready_o -expand} /vector_datapath_tb/vif/vector_out
add wave -noupdate -expand -group Internal -expand -group MaskU /vector_datapath_tb/vif/masku_in
add wave -noupdate -expand -group Internal -expand -group MaskU /vector_datapath_tb/vif/masku_out
add wave -noupdate -expand -group Internal -group {VALU Lane} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/mul_hold_result}
add wave -noupdate -expand -group Internal -group {VALU Lane} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/valu_fire_valid}
add wave -noupdate -expand -group Internal -group {VALU Lane} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/valu_hold_elem}
add wave -noupdate -expand -group Internal -group {VALU Lane} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/valu_hold_last}
add wave -noupdate -expand -group Internal -group {VALU Lane} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/valu_hold_result}
add wave -noupdate -expand -group Internal -group {VALU Lane} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/valu_hold_valid}
add wave -noupdate -expand -group Internal -group {VALU Lane} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/valu_hold_vd}
add wave -noupdate -expand -group Internal -group {VALU Lane} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/valu_issue_valid}
add wave -noupdate -expand -group Internal -group {VALU Lane} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/valu_meta_in}
add wave -noupdate -expand -group Internal -group {VALU Lane} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/valu_meta_out}
add wave -noupdate -expand -group Internal -group {VALU Lane} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/valu_reduce_fire}
add wave -noupdate -expand -group Internal -group {VALU Lane} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/valu_retire}
add wave -noupdate -expand -group Internal -group {VALU Lane} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/valu_seq_in}
add wave -noupdate -expand -group Internal -group {VALU Lane} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/valu_seq_out}
add wave -noupdate -expand -group Internal -group {VALU Lane} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/valu_sync_ready}
add wave -noupdate -expand -group Internal -group {MUL Lane Pipeline} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/mul_fire_valid}
add wave -noupdate -expand -group Internal -group {MUL Lane Pipeline} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/mul_hold_elem}
add wave -noupdate -expand -group Internal -group {MUL Lane Pipeline} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/mul_hold_last}
add wave -noupdate -expand -group Internal -group {MUL Lane Pipeline} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/mul_hold_result}
add wave -noupdate -expand -group Internal -group {MUL Lane Pipeline} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/mul_hold_valid}
add wave -noupdate -expand -group Internal -group {MUL Lane Pipeline} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/mul_hold_vd}
add wave -noupdate -expand -group Internal -group {MUL Lane Pipeline} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/mul_issue_cnt}
add wave -noupdate -expand -group Internal -group {MUL Lane Pipeline} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/mul_meta_in}
add wave -noupdate -expand -group Internal -group {MUL Lane Pipeline} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/mul_meta_out}
add wave -noupdate -expand -group Internal -group {MUL Lane Pipeline} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/mul_retire}
add wave -noupdate -expand -group Internal -group {MUL Lane Pipeline} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/mul_seq_in}
add wave -noupdate -expand -group Internal -group {MUL Lane Pipeline} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/mul_seq_out}
add wave -noupdate -expand -group Internal -group {MUL Lane Pipeline} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/mul_sync_ready}
add wave -noupdate -expand -group Internal -group {MUL Lane Pipeline} {/vector_datapath_tb/dut/GEN_LANES[0]/u_lane/mul_wb_cnt}
add wave -noupdate -expand -group Internal -expand -group {Result Collector} /vector_datapath_tb/dut/u_result_collector/rc_in
add wave -noupdate -expand -group Internal -expand -group {Result Collector} /vector_datapath_tb/dut/u_result_collector/rc_out
add wave -noupdate /vector_datapath_tb/cur_test
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {2001161230 ps} 0} {{Cursor 2} {62344 ps} 0}
quietly wave cursor active 1
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
WaveRestoreZoom {24000231830 ps} {24002340430 ps}
