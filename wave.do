onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -expand -group I/O /vector_datapath_tb/vif/CLK
add wave -noupdate -expand -group I/O /vector_datapath_tb/vif/nRST
add wave -noupdate -expand -group I/O -expand /vector_datapath_tb/vif/vector_in
add wave -noupdate -expand -group I/O -expand /vector_datapath_tb/vif/vector_out
add wave -noupdate -expand -group Internal -expand -group MaskU /vector_datapath_tb/vif/masku_in
add wave -noupdate -expand -group Internal -expand -group MaskU /vector_datapath_tb/vif/masku_out
add wave -noupdate -expand -group Internal -expand -group Lane0 -expand -subitemconfig {{/vector_datapath_tb/DUT/lane_if[0]/lane_in.valid_in} -expand {/vector_datapath_tb/DUT/lane_if[0]/lane_in.ready_in} -expand {/vector_datapath_tb/DUT/lane_if[0]/lane_in.vd} -expand {/vector_datapath_tb/DUT/lane_if[0]/lane_in.vmask} -expand {/vector_datapath_tb/DUT/lane_if[0]/lane_in.vop} -expand} {/vector_datapath_tb/DUT/lane_if[0]/lane_in}
add wave -noupdate -expand -group Internal -expand -group Lane0 -expand -group {VALU Path} {/vector_datapath_tb/DUT/GEN_LANES[0]/u_lane/valu_seq_in}
add wave -noupdate -expand -group Internal -expand -group Lane0 -expand -group {VALU Path} {/vector_datapath_tb/DUT/GEN_LANES[0]/u_lane/valu_seq_out}
add wave -noupdate -expand -group Internal -expand -group Lane0 -expand -group {VALU Path} {/vector_datapath_tb/DUT/GEN_LANES[0]/u_lane/valu_hold_vd}
add wave -noupdate -expand -group Internal -expand -group Lane0 -expand -subitemconfig {{/vector_datapath_tb/DUT/lane_if[0]/lane_out.vd} -expand} {/vector_datapath_tb/DUT/lane_if[0]/lane_out}
add wave -noupdate -expand -group Internal -expand -group {Result Collector} /vector_datapath_tb/DUT/u_result_collector/rc_in
add wave -noupdate -expand -group Internal -expand -group {Result Collector} /vector_datapath_tb/DUT/u_result_collector/rc_out
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {1385000 ps} 0} {{Cursor 2} {164854 ps} 0}
quietly wave cursor active 2
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
configure wave -timelineunits ps
update
WaveRestoreZoom {126156 ps} {162401 ps}
