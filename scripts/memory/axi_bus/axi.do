onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /axi_tb/DUT/CLK
add wave -noupdate /axi_tb/DUT/nRST
add wave -noupdate /axi_tb/abif/sp0_i_valid
add wave -noupdate /axi_tb/abif/sp0_wr_ready
add wave -noupdate /axi_tb/abif/sp1_i_valid
add wave -noupdate /axi_tb/abif/sp1_wr_ready
add wave -noupdate /axi_tb/abif/d_i_valid
add wave -noupdate /axi_tb/abif/d_wr_ready
add wave -noupdate -expand -group {AW inputs} /axi_tb/DUT/abif/aw_sp0_i
add wave -noupdate -expand -group {AW inputs} /axi_tb/DUT/abif/aw_sp1_i
add wave -noupdate -expand -group {AW inputs} /axi_tb/DUT/abif/aw_d_i
add wave -noupdate -expand -group {AW inputs} /axi_tb/DUT/abif/aw_o_ready
add wave -noupdate -expand -group {W inputs} /axi_tb/DUT/abif/w_d_i
add wave -noupdate -expand -group {W inputs} /axi_tb/DUT/abif/w_sp0_i
add wave -noupdate -expand -group {W inputs} /axi_tb/DUT/abif/w_sp1_i
add wave -noupdate -expand -group {W inputs} /axi_tb/DUT/abif/w_o_ready
add wave -noupdate -group {B inputs} /axi_tb/DUT/abif/b_d_o_ready
add wave -noupdate -group {B inputs} /axi_tb/DUT/abif/b_sp0_o_ready
add wave -noupdate -group {B inputs} /axi_tb/DUT/abif/b_sp1_o_ready
add wave -noupdate -group {B inputs} /axi_tb/DUT/abif/b_i
add wave -noupdate -group {B inputs} /axi_tb/DUT/abif/b_i_valid
add wave -noupdate -expand -group {AW outputs} /axi_tb/DUT/abif/aw_o
add wave -noupdate -expand -group {AW outputs} /axi_tb/DUT/abif/aw_o_valid
add wave -noupdate -expand -group {W outputs} -childformat {{/axi_tb/DUT/abif/w_o.mid_id -radix binary}} -expand -subitemconfig {/axi_tb/DUT/abif/w_o.mid_id {-height 16 -radix binary}} /axi_tb/DUT/abif/w_o
add wave -noupdate -expand -group {W outputs} /axi_tb/DUT/abif/w_o_valid
add wave -noupdate -group {B outputs} /axi_tb/DUT/abif/b_d_o
add wave -noupdate -group {B outputs} /axi_tb/DUT/abif/b_d_o_valid
add wave -noupdate -group {B outputs} /axi_tb/DUT/abif/b_sp0_o
add wave -noupdate -group {B outputs} /axi_tb/DUT/abif/b_sp0_o_valid
add wave -noupdate -group {B outputs} /axi_tb/DUT/abif/b_sp1_o
add wave -noupdate -group {B outputs} /axi_tb/DUT/abif/b_sp1_o_valid
add wave -noupdate /axi_tb/DUT/WR/drv_if/aw_grant
add wave -noupdate -expand /axi_tb/DUT/WR/WRITE_DRV/w_skid_buffer
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {235 ps} 0}
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
WaveRestoreZoom {177 ps} {389 ps}
