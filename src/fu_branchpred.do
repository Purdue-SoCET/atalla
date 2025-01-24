onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -color Salmon /fu_branchpred_tb/tb_test_case
add wave -noupdate -expand -group Inputs -color Cyan /fu_branchpred_tb/fubpif/update_btb
add wave -noupdate -expand -group Inputs -color Cyan /fu_branchpred_tb/fubpif/branch_outcome
add wave -noupdate -expand -group Inputs -color Cyan /fu_branchpred_tb/fubpif/branch_target
add wave -noupdate -expand -group Inputs -color Cyan /fu_branchpred_tb/fubpif/pc
add wave -noupdate -expand -group Inputs -color Cyan /fu_branchpred_tb/fubpif/pc_fetch
add wave -noupdate -expand -group Outputs -color Magenta /fu_branchpred_tb/fubpif/pred_outcome
add wave -noupdate -expand -group Outputs -color {Slate Blue} /fu_branchpred_tb/fubpif/pred_target
add wave -noupdate -expand -group Outputs -color {Slate Blue} /fu_branchpred_tb/fubpif/hit
add wave -noupdate -divider DUT
add wave -noupdate /fu_branchpred_tb/DUT/ihit
add wave -noupdate /fu_branchpred_tb/DUT/pc_idx
add wave -noupdate /fu_branchpred_tb/DUT/pc_fetch_idx
add wave -noupdate /fu_branchpred_tb/DUT/pc_tag
add wave -noupdate /fu_branchpred_tb/DUT/pc_fetch_tag
add wave -noupdate /fu_branchpred_tb/DUT/buffer
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {2760 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 142
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
WaveRestoreZoom {0 ps} {120390 ps}
