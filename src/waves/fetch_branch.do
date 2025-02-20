onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /fetch_branch_tb/FB/CLK
add wave -noupdate /fetch_branch_tb/FB/nRST
add wave -noupdate /fetch_branch_tb/FB/ihit
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
add wave -noupdate -expand -group {BRANCH UNIT} /fetch_branch_tb/fubif/branch
add wave -noupdate -expand -group {BRANCH UNIT} /fetch_branch_tb/fubif/branch_gate_sel
add wave -noupdate -expand -group {BRANCH UNIT} /fetch_branch_tb/fubif/branch_outcome
add wave -noupdate -expand -group {BRANCH UNIT} /fetch_branch_tb/fubif/predicted_outcome
add wave -noupdate -expand -group {BRANCH UNIT} /fetch_branch_tb/fubif/misprediction
add wave -noupdate -expand -group {BRANCH UNIT} /fetch_branch_tb/fubif/update_btb
add wave -noupdate -expand -group {BRANCH UNIT} /fetch_branch_tb/fubif/branch_type
add wave -noupdate -expand -group {BRANCH UNIT} /fetch_branch_tb/fubif/reg_a
add wave -noupdate -expand -group {BRANCH UNIT} /fetch_branch_tb/fubif/reg_b
add wave -noupdate -expand -group {BRANCH UNIT} /fetch_branch_tb/fubif/current_pc
add wave -noupdate -expand -group {BRANCH UNIT} /fetch_branch_tb/fubif/imm
add wave -noupdate -expand -group {BRANCH UNIT} /fetch_branch_tb/fubif/updated_pc
add wave -noupdate -expand -group {BRANCH UNIT} /fetch_branch_tb/fubif/correct_pc
add wave -noupdate -expand -group {BRANCH UNIT} /fetch_branch_tb/fubif/update_pc
add wave -noupdate -expand -group {BRANCH UNIT} /fetch_branch_tb/fubif/branch_target
add wave -noupdate -expand -group {BRANCH PREDICTOR} /fetch_branch_tb/fubpif/branch_outcome
add wave -noupdate -expand -group {BRANCH PREDICTOR} /fetch_branch_tb/fubpif/update_btb
add wave -noupdate -expand -group {BRANCH PREDICTOR} /fetch_branch_tb/fubpif/predicted_outcome
add wave -noupdate -expand -group {BRANCH PREDICTOR} /fetch_branch_tb/fubpif/pc
add wave -noupdate -expand -group {BRANCH PREDICTOR} /fetch_branch_tb/fubpif/update_pc
add wave -noupdate -expand -group {BRANCH PREDICTOR} /fetch_branch_tb/fubpif/branch_target
add wave -noupdate -expand -group {BRANCH PREDICTOR} /fetch_branch_tb/fubpif/predicted_target
add wave -noupdate -expand -group FETCH /fetch_branch_tb/fif/flush
add wave -noupdate -expand -group FETCH /fetch_branch_tb/fif/stall
add wave -noupdate -expand -group FETCH /fetch_branch_tb/fif/dispatch_free
add wave -noupdate -expand -group FETCH /fetch_branch_tb/fif/misprediction
add wave -noupdate -expand -group FETCH /fetch_branch_tb/fif/imemload
add wave -noupdate -expand -group FETCH /fetch_branch_tb/fif/pc_prediction
add wave -noupdate -expand -group FETCH /fetch_branch_tb/fif/instr
add wave -noupdate -expand -group FETCH /fetch_branch_tb/fif/pc
add wave -noupdate -expand -group FETCH /fetch_branch_tb/fif/correct_target
add wave -noupdate -expand -group FETCH /fetch_branch_tb/fif/correct_pc
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {90 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 298
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
WaveRestoreZoom {0 ps} {880 ps}
