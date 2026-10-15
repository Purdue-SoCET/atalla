onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -expand -group {TB Signals} /vector_top_tb/tb_if/lanes_in
add wave -noupdate -expand -group {TB Signals} /vector_top_tb/tb_if/lanes_out
add wave -noupdate -expand -group {DUT Signals} -subitemconfig {/vector_top_tb/dut/vif/lanes_in.lane_issue_ports -expand {/vector_top_tb/dut/vif/lanes_in.lane_issue_ports[0]} -expand} /vector_top_tb/dut/vif/lanes_in
add wave -noupdate -expand -group {DUT Signals} -subitemconfig {/vector_top_tb/dut/vif/lanes_out.result_collectors -expand {/vector_top_tb/dut/vif/lanes_out.result_collectors[2]} -expand {/vector_top_tb/dut/vif/lanes_out.result_collectors[1]} -expand {/vector_top_tb/dut/vif/lanes_out.result_collectors[0]} -expand {/vector_top_tb/dut/vif/lanes_out.result_collectors[0].vector_output} -expand} /vector_top_tb/dut/vif/lanes_out
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {107418 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 235
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
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
WaveRestoreZoom {0 ps} {115500 ps}
