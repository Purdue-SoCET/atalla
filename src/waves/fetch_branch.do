onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /fetch_branch_tb/DUT/CLK
add wave -noupdate /fetch_branch_tb/DUT/nRST
add wave -noupdate /fetch_branch_tb/PROG/tb_testcase
add wave -noupdate -expand -group {TOP LEVEL (FETCH BRANCH)} /fetch_branch_tb/fbif/reg_a
add wave -noupdate -expand -group {TOP LEVEL (FETCH BRANCH)} /fetch_branch_tb/fbif/reg_b
add wave -noupdate -expand -group {TOP LEVEL (FETCH BRANCH)} /fetch_branch_tb/fbif/current_pc
add wave -noupdate -expand -group {TOP LEVEL (FETCH BRANCH)} /fetch_branch_tb/fbif/imm
add wave -noupdate -expand -group {TOP LEVEL (FETCH BRANCH)} /fetch_branch_tb/fbif/imemload
add wave -noupdate -expand -group {TOP LEVEL (FETCH BRANCH)} /fetch_branch_tb/fbif/instr
add wave -noupdate -expand -group {TOP LEVEL (FETCH BRANCH)} /fetch_branch_tb/fbif/pc
add wave -noupdate -expand -group {TOP LEVEL (FETCH BRANCH)} /fetch_branch_tb/fbif/branch_type
add wave -noupdate -expand -group {TOP LEVEL (FETCH BRANCH)} /fetch_branch_tb/fbif/branch
add wave -noupdate -expand -group {TOP LEVEL (FETCH BRANCH)} /fetch_branch_tb/fbif/branch_gate_sel
add wave -noupdate -expand -group {TOP LEVEL (FETCH BRANCH)} /fetch_branch_tb/fbif/dispatch_free
add wave -noupdate -expand -group {TOP LEVEL (FETCH BRANCH)} /fetch_branch_tb/fbif/flush
add wave -noupdate -expand -group {TOP LEVEL (FETCH BRANCH)} /fetch_branch_tb/fbif/stall
add wave -noupdate -expand -group {TOP LEVEL (FETCH BRANCH)} /fetch_branch_tb/fbif/predicted_outcome
add wave -noupdate -expand -group FIF /fetch_branch_tb/DUT/FETCH/ihit
add wave -noupdate -expand -group FIF /fetch_branch_tb/DUT/FETCH/pc_reg
add wave -noupdate -expand -group FIF /fetch_branch_tb/DUT/FETCH/next_pc
add wave -noupdate -expand -group FIF /fetch_branch_tb/DUT/fif/flush
add wave -noupdate -expand -group FIF /fetch_branch_tb/DUT/fif/stall
add wave -noupdate -expand -group FIF /fetch_branch_tb/DUT/fif/dispatch_free
add wave -noupdate -expand -group FIF /fetch_branch_tb/DUT/fif/misprediction
add wave -noupdate -expand -group FIF /fetch_branch_tb/DUT/fif/imemload
add wave -noupdate -expand -group FIF /fetch_branch_tb/DUT/fif/pc_prediction
add wave -noupdate -expand -group FIF /fetch_branch_tb/DUT/fif/instr
add wave -noupdate -expand -group FIF /fetch_branch_tb/DUT/fif/pc
add wave -noupdate -expand -group FIF /fetch_branch_tb/DUT/fif/correct_target
add wave -noupdate -expand -group FIF /fetch_branch_tb/DUT/fif/correct_pc
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/fubif/branch
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/BRANCH/zero
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/BRANCH/actual_outcome
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/fubif/branch_gate_sel
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/fubif/branch_outcome
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/fubif/predicted_outcome
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/fubif/misprediction
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/fubif/update_btb
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/fubif/branch_type
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/fubif/reg_a
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/fubif/reg_b
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/fubif/current_pc
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/fubif/imm
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/fubif/updated_pc
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/fubif/correct_pc
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/fubif/update_pc
add wave -noupdate -expand -group BRANCH /fetch_branch_tb/DUT/fubif/branch_target
add wave -noupdate -expand -group {BRANCH PRED} /fetch_branch_tb/DUT/PRED/CLK
add wave -noupdate -expand -group {BRANCH PRED} /fetch_branch_tb/DUT/PRED/nRST
add wave -noupdate -expand -group {BRANCH PRED} /fetch_branch_tb/DUT/fubpif/branch_outcome
add wave -noupdate -expand -group {BRANCH PRED} /fetch_branch_tb/DUT/fubpif/update_btb
add wave -noupdate -expand -group {BRANCH PRED} /fetch_branch_tb/DUT/fubpif/predicted_outcome
add wave -noupdate -expand -group {BRANCH PRED} /fetch_branch_tb/DUT/fubpif/pc
add wave -noupdate -expand -group {BRANCH PRED} /fetch_branch_tb/DUT/fubpif/update_pc
add wave -noupdate -expand -group {BRANCH PRED} /fetch_branch_tb/DUT/fubpif/branch_target
add wave -noupdate -expand -group {BRANCH PRED} /fetch_branch_tb/DUT/fubpif/predicted_target
add wave -noupdate -expand -group {BRANCH PRED} /fetch_branch_tb/DUT/PRED/pc_idx
add wave -noupdate -expand -group {BRANCH PRED} /fetch_branch_tb/DUT/PRED/update_pc_idx
add wave -noupdate -expand -group {BRANCH PRED} /fetch_branch_tb/DUT/PRED/pc_tag
add wave -noupdate -expand -group {BRANCH PRED} /fetch_branch_tb/DUT/PRED/update_pc_tag
add wave -noupdate -expand -group {BRANCH PRED} /fetch_branch_tb/DUT/PRED/btb_hit
add wave -noupdate -expand -group {BRANCH PRED} /fetch_branch_tb/DUT/PRED/btb_target
add wave -noupdate -expand -group {BRANCH PRED} /fetch_branch_tb/DUT/PRED/buffer
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {0 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 333
configure wave -valuecolwidth 93
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
WaveRestoreZoom {0 ps} {108380 ps}
