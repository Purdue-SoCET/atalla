onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /dispatch_tb/DUT/CLK
add wave -noupdate /dispatch_tb/DUT/nRST
add wave -noupdate -divider {Inputs and Outputs}
add wave -noupdate /dispatch_tb/diif/fetch
add wave -noupdate /dispatch_tb/diif/flush
add wave -noupdate /dispatch_tb/diif/freeze
add wave -noupdate /dispatch_tb/diif/fust_s
add wave -noupdate /dispatch_tb/diif/fust_m
add wave -noupdate /dispatch_tb/diif/fust_g
add wave -noupdate /dispatch_tb/diif/wb
add wave -noupdate /dispatch_tb/diif/ihit
add wave -noupdate /dispatch_tb/diif/out
add wave -noupdate -expand /dispatch_tb/diif/n_fust_s
add wave -noupdate /dispatch_tb/diif/n_fust_m
add wave -noupdate /dispatch_tb/diif/n_fust_g
add wave -noupdate /dispatch_tb/diif/n_fu_s
add wave -noupdate /dispatch_tb/diif/n_fust_s_en
add wave -noupdate /dispatch_tb/diif/n_fust_m_en
add wave -noupdate /dispatch_tb/diif/n_fust_g_en
add wave -noupdate -divider DUT
add wave -noupdate /dispatch_tb/DUT/WAW
add wave -noupdate /dispatch_tb/DUT/s_busy
add wave -noupdate /dispatch_tb/DUT/m_busy
add wave -noupdate /dispatch_tb/DUT/hazard
add wave -noupdate /dispatch_tb/DUT/instr
add wave -noupdate -radix unsigned /dispatch_tb/DUT/s_rd
add wave -noupdate -radix unsigned /dispatch_tb/DUT/s_rs1
add wave -noupdate -radix unsigned /dispatch_tb/DUT/s_rs2
add wave -noupdate /dispatch_tb/DUT/m_rd
add wave -noupdate /dispatch_tb/DUT/m_rs1
add wave -noupdate /dispatch_tb/DUT/m_rs2
add wave -noupdate /dispatch_tb/DUT/m_rs3
add wave -noupdate /dispatch_tb/DUT/flush
add wave -noupdate /dispatch_tb/DUT/n_dispatch
add wave -noupdate /dispatch_tb/DUT/dispatch
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/alu_op
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/stride
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/halt
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/i_flag
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/m_reg_write
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/s_reg_write
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/jalr
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/jal
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/mem_to_reg
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/s_mem_type
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/branch_op
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/imm
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/instr
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/u_type
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/fu_s
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/fu_m
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/m_mem_type
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/matrix_rd
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/matrix_rs1
add wave -noupdate -group {Control Unit} /dispatch_tb/DUT/CU/cu_if/fu_t
add wave -noupdate -divider Matrix
add wave -noupdate /dispatch_tb/DUT/RSTM/status
add wave -noupdate -divider Scalar
add wave -noupdate /dispatch_tb/DUT/RSTS/status
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {40810 ps} 0}
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
configure wave -timelineunits ps
update
WaveRestoreZoom {32890 ps} {71160 ps}
