onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -expand -group {input signals} /axi_read_manager_tb/DUT/CLK
add wave -noupdate -expand -group {input signals} /axi_read_manager_tb/DUT/nRST
add wave -noupdate -expand -group {input signals} /axi_read_manager_tb/DUT/arready
add wave -noupdate -expand -group {input signals} /axi_read_manager_tb/DUT/master_in
add wave -noupdate -expand -group {input signals} /axi_read_manager_tb/DUT/pop
add wave -noupdate -expand -group {output signals} /axi_read_manager_tb/DUT/arvalid
add wave -noupdate -expand -group {output signals} /axi_read_manager_tb/DUT/manager_out
add wave -noupdate -expand -group internal /axi_read_manager_tb/DUT/req
add wave -noupdate -expand -group internal /axi_read_manager_tb/DUT/fifo
add wave -noupdate -expand -group internal /axi_read_manager_tb/DUT/wr_ptr
add wave -noupdate -expand -group internal /axi_read_manager_tb/DUT/rd_ptr
add wave -noupdate -expand -group internal /axi_read_manager_tb/DUT/empty
add wave -noupdate -expand -group internal /axi_read_manager_tb/DUT/full
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {111563 ps} 0}
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
WaveRestoreZoom {0 ps} {220500 ps}
