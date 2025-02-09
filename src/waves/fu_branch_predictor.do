onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /fu_branch_predictor_tb/tb_test_num
add wave -noupdate /fu_branch_predictor_tb/tb_clk
add wave -noupdate /fu_branch_predictor_tb/tb_nrst
add wave -noupdate -expand -group Inputs /fu_branch_predictor_tb/fubpif/update_btb
add wave -noupdate -expand -group Inputs /fu_branch_predictor_tb/fubpif/branch_outcome
add wave -noupdate -expand -group Inputs /fu_branch_predictor_tb/fubpif/pc
add wave -noupdate -expand -group Inputs /fu_branch_predictor_tb/fubpif/update_pc
add wave -noupdate -expand -group Inputs /fu_branch_predictor_tb/fubpif/branch_target
add wave -noupdate -expand -group Outputs /fu_branch_predictor_tb/fubpif/predicted_outcome
add wave -noupdate -expand -group Outputs /fu_branch_predictor_tb/fubpif/predicted_target
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {0 ps} 0}
quietly wave cursor active 0
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
WaveRestoreZoom {0 ps} {1 ns}
