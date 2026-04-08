onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /axi_tb/DUT/CLK
add wave -noupdate /axi_tb/DUT/nRST
add wave -noupdate -group {AW inputs} /axi_tb/DUT/abif/aw_sp0_i
add wave -noupdate -group {AW inputs} /axi_tb/DUT/abif/aw_sp1_i
add wave -noupdate -group {AW inputs} /axi_tb/DUT/abif/aw_d_i
add wave -noupdate -group {AW inputs} /axi_tb/DUT/abif/aw_sp0_i_valid
add wave -noupdate -group {AW inputs} /axi_tb/DUT/abif/aw_sp1_i_valid
add wave -noupdate -group {AW inputs} /axi_tb/DUT/abif/aw_d_i_valid
add wave -noupdate -group {AW inputs} /axi_tb/DUT/abif/aw_o_ready
add wave -noupdate -group {W inputs} /axi_tb/DUT/abif/w_d_i
add wave -noupdate -group {W inputs} /axi_tb/DUT/abif/w_d_i_valid
add wave -noupdate -group {W inputs} /axi_tb/DUT/abif/w_sp0_i
add wave -noupdate -group {W inputs} /axi_tb/DUT/abif/w_sp0_i_valid
add wave -noupdate -group {W inputs} /axi_tb/DUT/abif/w_sp1_i
add wave -noupdate -group {W inputs} /axi_tb/DUT/abif/w_sp1_i_valid
add wave -noupdate -group {W inputs} /axi_tb/DUT/abif/w_o_ready
add wave -noupdate -group {B inputs} /axi_tb/DUT/abif/b_d_o_ready
add wave -noupdate -group {B inputs} /axi_tb/DUT/abif/b_sp0_o_ready
add wave -noupdate -group {B inputs} /axi_tb/DUT/abif/b_sp1_o_ready
add wave -noupdate -group {B inputs} /axi_tb/DUT/abif/b_i
add wave -noupdate -group {B inputs} /axi_tb/DUT/abif/b_i_valid
add wave -noupdate -group {AW outputs} /axi_tb/DUT/abif/aw_d_i_ready
add wave -noupdate -group {AW outputs} /axi_tb/DUT/abif/aw_sp0_i_ready
add wave -noupdate -group {AW outputs} /axi_tb/DUT/abif/aw_sp1_i_ready
add wave -noupdate -group {AW outputs} /axi_tb/DUT/abif/aw_o
add wave -noupdate -group {AW outputs} /axi_tb/DUT/abif/aw_o_valid
add wave -noupdate -group {W outputs} /axi_tb/DUT/abif/w_d_i_ready
add wave -noupdate -group {W outputs} /axi_tb/DUT/abif/w_sp0_i_ready
add wave -noupdate -group {W outputs} /axi_tb/DUT/abif/w_sp1_i_ready
add wave -noupdate -group {W outputs} /axi_tb/DUT/abif/w_o
add wave -noupdate -group {W outputs} /axi_tb/DUT/abif/w_o_valid
add wave -noupdate -group {B outputs} /axi_tb/DUT/abif/b_d_o
add wave -noupdate -group {B outputs} /axi_tb/DUT/abif/b_d_o_valid
add wave -noupdate -group {B outputs} /axi_tb/DUT/abif/b_sp0_o
add wave -noupdate -group {B outputs} /axi_tb/DUT/abif/b_sp0_o_valid
add wave -noupdate -group {B outputs} /axi_tb/DUT/abif/b_sp1_o
add wave -noupdate -group {B outputs} /axi_tb/DUT/abif/b_sp1_o_valid
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {1986 ps} 0}
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
WaveRestoreZoom {0 ps} {9746 ps}
