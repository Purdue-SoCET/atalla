onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /dispatch_tb/DUT/CLK
add wave -noupdate /dispatch_tb/DUT/nRST
add wave -noupdate /dispatch_tb/DUT/WAW
add wave -noupdate /dispatch_tb/DUT/s_busy
add wave -noupdate /dispatch_tb/DUT/m_busy
add wave -noupdate /dispatch_tb/DUT/hazard
add wave -noupdate /dispatch_tb/DUT/instr
add wave -noupdate /dispatch_tb/DUT/s_rd
add wave -noupdate /dispatch_tb/DUT/s_rs1
add wave -noupdate /dispatch_tb/DUT/s_rs2
add wave -noupdate /dispatch_tb/DUT/m_rd
add wave -noupdate /dispatch_tb/DUT/m_rs1
add wave -noupdate /dispatch_tb/DUT/m_rs2
add wave -noupdate /dispatch_tb/DUT/m_rs3
add wave -noupdate /dispatch_tb/DUT/flush
add wave -noupdate -expand -subitemconfig {/dispatch_tb/DUT/n_dispatch.wb -expand} /dispatch_tb/DUT/n_dispatch
add wave -noupdate -expand -subitemconfig {/dispatch_tb/DUT/dispatch.wb -expand} /dispatch_tb/DUT/dispatch
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {7500 ps} 0}
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
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ps} {19830 ps}
