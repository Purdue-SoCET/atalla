onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /axi_read_manager_tb/clk
add wave -noupdate /axi_read_manager_tb/nrst
add wave -noupdate /axi_read_manager_tb/test_case
add wave -noupdate -expand -group {From Master} /axi_read_manager_tb/arvalid
add wave -noupdate -expand -group {From Master} /axi_read_manager_tb/aready
add wave -noupdate -expand -group {From Master} /axi_read_manager_tb/araddr
add wave -noupdate -expand -group {From Master} /axi_read_manager_tb/arid
add wave -noupdate -expand -group {From Master} /axi_read_manager_tb/arsize
add wave -noupdate -expand -group {From Master} /axi_read_manager_tb/arlen
add wave -noupdate -expand -group {From Master} /axi_read_manager_tb/arburst
add wave -noupdate /axi_read_manager_tb/DUT/fifo
add wave -noupdate /axi_read_manager_tb/DUT/wr_ptr
add wave -noupdate /axi_read_manager_tb/DUT/rd_ptr
add wave -noupdate /axi_read_manager_tb/DUT/full
add wave -noupdate /axi_read_manager_tb/DUT/empty
add wave -noupdate /axi_read_manager_tb/DUT/push
add wave -noupdate /axi_read_manager_tb/pop
add wave -noupdate -expand -group {To Mux} /axi_read_manager_tb/head_valid
add wave -noupdate -expand -group {To Mux} /axi_read_manager_tb/head_id
add wave -noupdate -expand -group {To Mux} /axi_read_manager_tb/head_addr
add wave -noupdate -expand -group {To Mux} /axi_read_manager_tb/head_len
add wave -noupdate -expand -group {To Mux} /axi_read_manager_tb/head_size
add wave -noupdate -expand -group {To Mux} /axi_read_manager_tb/head_burst
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {103137 ps} 0}
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
WaveRestoreZoom {13219 ps} {268099 ps}
