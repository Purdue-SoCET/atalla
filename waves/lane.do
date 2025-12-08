onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /lane_tb/dut/CLK
add wave -noupdate /lane_tb/dut/nRST
add wave -noupdate /lane_tb/cur_test
add wave -noupdate -expand -group {Sequence Stage} /lane_tb/dut/sqrt_seq_in
add wave -noupdate -expand -group {Sequence Stage} /lane_tb/dut/sqrt_seq_out
add wave -noupdate -expand -group {Sequence Stage} /lane_tb/dut/u_seq_sqrt/state
add wave -noupdate -expand -group {Sequence Stage} -expand /lane_tb/dut/u_seq_sqrt/elem_idx_q
add wave -noupdate -expand -group {Sequence Stage} /lane_tb/dut/u_seq_sqrt/elem_accepted
add wave -noupdate -expand -group {Execution Stage} /lane_tb/dut/sqrt_bus/in
add wave -noupdate -expand -group {Execution Stage} -expand -subitemconfig {/lane_tb/dut/sqrt_bus/out.valid_out {-color {Slate Blue}} /lane_tb/dut/sqrt_bus/out.ready_in {-color {Slate Blue}}} /lane_tb/dut/sqrt_bus/out
add wave -noupdate -expand -group I/O /lane_tb/dut/lif/lane_in
add wave -noupdate -expand -group I/O -expand -subitemconfig {/lane_tb/dut/lif/lane_out.ready_o {-color {Slate Blue} -expand} {/lane_tb/dut/lif/lane_out.ready_o[4]} {-color {Slate Blue}} {/lane_tb/dut/lif/lane_out.ready_o[3]} {-color {Slate Blue}} {/lane_tb/dut/lif/lane_out.ready_o[2]} {-color {Slate Blue}} {/lane_tb/dut/lif/lane_out.ready_o[1]} {-color {Slate Blue}} {/lane_tb/dut/lif/lane_out.ready_o[0]} {-color {Slate Blue}} /lane_tb/dut/lif/lane_out.valid_o {-color {Slate Blue} -expand} {/lane_tb/dut/lif/lane_out.valid_o[4]} {-color {Slate Blue}} {/lane_tb/dut/lif/lane_out.valid_o[3]} {-color {Slate Blue}} {/lane_tb/dut/lif/lane_out.valid_o[2]} {-color {Slate Blue}} {/lane_tb/dut/lif/lane_out.valid_o[1]} {-color {Slate Blue}} {/lane_tb/dut/lif/lane_out.valid_o[0]} {-color {Slate Blue}} /lane_tb/dut/lif/lane_out.elem_idx {-color {Slate Blue}}} /lane_tb/dut/lif/lane_out
add wave -noupdate -expand -group {Mul Pipeline} /lane_tb/dut/mul_fire_valid
add wave -noupdate -expand -group {Mul Pipeline} -expand /lane_tb/dut/mul_hold_elem
add wave -noupdate -expand -group {Mul Pipeline} -expand /lane_tb/dut/mul_hold_result
add wave -noupdate -expand -group {Mul Pipeline} /lane_tb/dut/mul_hold_valid
add wave -noupdate -expand -group {Mul Pipeline} -expand /lane_tb/dut/mul_hold_vd
add wave -noupdate -expand -group {Mul Pipeline} -expand /lane_tb/dut/mul_meta_in
add wave -noupdate -expand -group {Mul Pipeline} -expand /lane_tb/dut/mul_meta_out
add wave -noupdate -expand -group {Mul Pipeline} -expand /lane_tb/dut/mul_seq_in
add wave -noupdate -expand -group {Mul Pipeline} -expand /lane_tb/dut/mul_seq_out
add wave -noupdate -expand -group {Mul Pipeline} /lane_tb/dut/mul_sync_ready
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {6035931939 ps} 0}
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
configure wave -timelineunits ps
update
WaveRestoreZoom {6035845456 ps} {6036160971 ps}
