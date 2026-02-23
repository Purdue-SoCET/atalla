onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /tb_top/clk
add wave -noupdate /tb_top/n_rst
add wave -noupdate /tb_top/mem_in
add wave -noupdate /tb_top/mem_in_addr
add wave -noupdate /tb_top/mem_in_rw_mode
add wave -noupdate /tb_top/mem_in_store_value
add wave -noupdate /tb_top/dp_in_halt
add wave -noupdate /tb_top/mem_out_uuid
add wave -noupdate /tb_top/stall
add wave -noupdate /tb_top/hit
add wave -noupdate /tb_top/hit_load
add wave -noupdate /tb_top/block_status
add wave -noupdate /tb_top/uuid_block
add wave -noupdate /tb_top/dp_out_flushed
add wave -noupdate /tb_top/ram_mem_data
add wave -noupdate /tb_top/ram_mem_complete
add wave -noupdate /tb_top/ram_mem_REN
add wave -noupdate /tb_top/ram_mem_WEN
add wave -noupdate /tb_top/ram_mem_addr
add wave -noupdate /tb_top/ram_mem_store
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {670 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
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
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ns} {1271 ns}
