onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /scoreboard_tb/DUT/sbif/fetch
add wave -noupdate /scoreboard_tb/DUT/sbif/flush
add wave -noupdate /scoreboard_tb/DUT/sbif/freeze
add wave -noupdate /scoreboard_tb/DUT/sbif/wb
add wave -noupdate /scoreboard_tb/DUT/sbif/out
add wave -noupdate -divider Dispatch
add wave -noupdate -expand /scoreboard_tb/DUT/diif/fetch
add wave -noupdate /scoreboard_tb/DUT/diif/flush
add wave -noupdate /scoreboard_tb/DUT/diif/freeze
add wave -noupdate /scoreboard_tb/DUT/diif/fust_s
add wave -noupdate /scoreboard_tb/DUT/diif/fust_m
add wave -noupdate /scoreboard_tb/DUT/diif/fust_g
add wave -noupdate /scoreboard_tb/DUT/diif/wb
add wave -noupdate /scoreboard_tb/DUT/diif/ihit
add wave -noupdate /scoreboard_tb/DUT/diif/out
add wave -noupdate -childformat {{/scoreboard_tb/DUT/diif/n_fust_s.rd -radix decimal} {/scoreboard_tb/DUT/diif/n_fust_s.rs1 -radix decimal} {/scoreboard_tb/DUT/diif/n_fust_s.rs2 -radix decimal}} -expand -subitemconfig {/scoreboard_tb/DUT/diif/n_fust_s.rd {-height 16 -radix decimal} /scoreboard_tb/DUT/diif/n_fust_s.rs1 {-height 16 -radix decimal} /scoreboard_tb/DUT/diif/n_fust_s.rs2 {-height 16 -radix decimal}} /scoreboard_tb/DUT/diif/n_fust_s
add wave -noupdate /scoreboard_tb/DUT/diif/n_fust_m
add wave -noupdate /scoreboard_tb/DUT/diif/n_fust_g
add wave -noupdate /scoreboard_tb/DUT/diif/n_fu_s
add wave -noupdate /scoreboard_tb/DUT/diif/n_fust_s_en
add wave -noupdate /scoreboard_tb/DUT/diif/n_fust_m_en
add wave -noupdate /scoreboard_tb/DUT/diif/n_fust_g_en
add wave -noupdate -divider Issue
add wave -noupdate /scoreboard_tb/DUT/isif/dispatch
add wave -noupdate -childformat {{/scoreboard_tb/DUT/isif/n_fust_s.rd -radix decimal} {/scoreboard_tb/DUT/isif/n_fust_s.rs1 -radix decimal} {/scoreboard_tb/DUT/isif/n_fust_s.rs2 -radix decimal}} -expand -subitemconfig {/scoreboard_tb/DUT/isif/n_fust_s.rd {-height 16 -radix decimal} /scoreboard_tb/DUT/isif/n_fust_s.rs1 {-height 16 -radix decimal} /scoreboard_tb/DUT/isif/n_fust_s.rs2 {-height 16 -radix decimal}} /scoreboard_tb/DUT/isif/n_fust_s
add wave -noupdate /scoreboard_tb/DUT/isif/n_fust_m
add wave -noupdate /scoreboard_tb/DUT/isif/n_fust_g
add wave -noupdate /scoreboard_tb/DUT/isif/n_fu_s
add wave -noupdate /scoreboard_tb/DUT/isif/n_fust_s_en
add wave -noupdate /scoreboard_tb/DUT/isif/n_fust_m_en
add wave -noupdate /scoreboard_tb/DUT/isif/n_fust_g_en
add wave -noupdate /scoreboard_tb/DUT/isif/flush
add wave -noupdate /scoreboard_tb/DUT/isif/freeze
add wave -noupdate /scoreboard_tb/DUT/isif/wb
add wave -noupdate /scoreboard_tb/DUT/isif/out
add wave -noupdate /scoreboard_tb/DUT/isif/fust_s
add wave -noupdate /scoreboard_tb/DUT/isif/fust_m
add wave -noupdate /scoreboard_tb/DUT/isif/fust_g
add wave -noupdate -divider {Control Unit}
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/alu_op
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/stride
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/halt
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/i_flag
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/m_reg_write
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/s_reg_write
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/jalr
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/jal
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/s_mem_type
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/branch_op
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/imm
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/instr
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/u_type
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/fu_s
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/fu_m
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/m_mem_type
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/matrix_rd
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/matrix_rs1
add wave -noupdate /scoreboard_tb/DUT/DI/cuif/fu_t
add wave -noupdate -divider {Reg Status Scalar}
add wave -noupdate /scoreboard_tb/CLK
add wave -noupdate /scoreboard_tb/nRST
add wave -noupdate /scoreboard_tb/DUT/DI/WAW
add wave -noupdate /scoreboard_tb/DUT/DI/flush
add wave -noupdate /scoreboard_tb/DUT/DI/rstsif/di_sel
add wave -noupdate /scoreboard_tb/DUT/DI/rstsif/di_write
add wave -noupdate /scoreboard_tb/DUT/DI/rstsif/di_tag
add wave -noupdate /scoreboard_tb/DUT/DI/rstsif/wb_sel
add wave -noupdate /scoreboard_tb/DUT/DI/rstsif/wb_write
add wave -noupdate -expand -subitemconfig {/scoreboard_tb/DUT/DI/rstsif/status.idx -expand} /scoreboard_tb/DUT/DI/rstsif/status
add wave -noupdate -divider {Reg Status Matrix}
add wave -noupdate /scoreboard_tb/DUT/DI/rstmif/di_sel
add wave -noupdate /scoreboard_tb/DUT/DI/rstmif/di_write
add wave -noupdate /scoreboard_tb/DUT/DI/rstmif/di_tag
add wave -noupdate /scoreboard_tb/DUT/DI/rstmif/wb_sel
add wave -noupdate /scoreboard_tb/DUT/DI/rstmif/wb_write
add wave -noupdate /scoreboard_tb/DUT/DI/rstmif/status
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {62470 ps} 0}
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
WaveRestoreZoom {10220 ps} {99470 ps}
