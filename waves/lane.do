onerror {resume}
quietly virtual signal -install {/lane_tb/DUT/fu_interfaces[3]} { (context /lane_tb/DUT/fu_interfaces[3] )&{in , out }} exp
quietly WaveActivateNextPane {} 0
add wave -noupdate /lane_tb/DUT/CLK
add wave -noupdate /lane_tb/DUT/nRST
add wave -noupdate -expand -group lif /lane_tb/lif/in
add wave -noupdate -expand -group lif -expand -subitemconfig {/lane_tb/lif/out.units -expand {/lane_tb/lif/out.units[1]} -expand} /lane_tb/lif/out
add wave -noupdate -expand -group ALU {/lane_tb/DUT/fu_interfaces[0]/in}
add wave -noupdate -expand -group ALU {/lane_tb/DUT/fu_interfaces[0]/out}
add wave -noupdate -expand -group mul -expand -subitemconfig {{/lane_tb/DUT/fu_interfaces[1]/in.ports} -expand {/lane_tb/DUT/fu_interfaces[1]/in.ports[0]} -expand} {/lane_tb/DUT/fu_interfaces[1]/in}
add wave -noupdate -expand -group mul -expand {/lane_tb/DUT/fu_interfaces[1]/out}
add wave -noupdate -expand -group div {/lane_tb/DUT/fu_interfaces[2]/in}
add wave -noupdate -expand -group div {/lane_tb/DUT/fu_interfaces[2]/out}
add wave -noupdate -expand -group exp {/lane_tb/DUT/fu_interfaces[3]/in}
add wave -noupdate -expand -group exp {/lane_tb/DUT/fu_interfaces[3]/out}
add wave -noupdate -expand -group sqrt {/lane_tb/DUT/fu_interfaces[4]/in}
add wave -noupdate -expand -group sqrt {/lane_tb/DUT/fu_interfaces[4]/out}
add wave -noupdate /lane_tb/current_test
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {451377 ps} 0}
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
WaveRestoreZoom {378483 ps} {555097 ps}
