onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /div_pipeline_bf16_tb/DUT/CLK
add wave -noupdate /div_pipeline_bf16_tb/DUT/nRST
add wave -noupdate -expand /div_pipeline_bf16_tb/divif/in
add wave -noupdate -expand /div_pipeline_bf16_tb/divif/out
add wave -noupdate /div_pipeline_bf16_tb/DUT/exp_diff
add wave -noupdate /div_pipeline_bf16_tb/DUT/n_mul1Tfin1
add wave -noupdate /div_pipeline_bf16_tb/DUT/n_fin1Tsub1
add wave -noupdate /div_pipeline_bf16_tb/DUT/n_sub1Tsub2
add wave -noupdate /div_pipeline_bf16_tb/DUT/n_sub2Tfin2
add wave -noupdate /div_pipeline_bf16_tb/DUT/n_fin2Tmul2
add wave -noupdate /div_pipeline_bf16_tb/DUT/n_mul2Tfin3
add wave -noupdate /div_pipeline_bf16_tb/DUT/n_fin3Texp
add wave -noupdate /div_pipeline_bf16_tb/DUT/n_expTout
add wave -noupdate /div_pipeline_bf16_tb/DUT/mul1Tfin1
add wave -noupdate /div_pipeline_bf16_tb/DUT/fin1Tsub1
add wave -noupdate /div_pipeline_bf16_tb/DUT/sub1Tsub2
add wave -noupdate /div_pipeline_bf16_tb/DUT/sub2Tfin2
add wave -noupdate /div_pipeline_bf16_tb/DUT/fin2Tmul2
add wave -noupdate /div_pipeline_bf16_tb/DUT/mul2Tfin3
add wave -noupdate /div_pipeline_bf16_tb/DUT/fin3Texp
add wave -noupdate /div_pipeline_bf16_tb/DUT/expTout
add wave -noupdate /div_pipeline_bf16_tb/DUT/muln
add wave -noupdate /div_pipeline_bf16_tb/DUT/muld
add wave -noupdate /div_pipeline_bf16_tb/DUT/f_1
add wave -noupdate /div_pipeline_bf16_tb/DUT/outn
add wave -noupdate /div_pipeline_bf16_tb/DUT/outd
add wave -noupdate /div_pipeline_bf16_tb/DUT/subd
add wave -noupdate /div_pipeline_bf16_tb/DUT/subout
add wave -noupdate /div_pipeline_bf16_tb/DUT/f_2
add wave -noupdate /div_pipeline_bf16_tb/DUT/mulfin
add wave -noupdate /div_pipeline_bf16_tb/DUT/outfin
add wave -noupdate /div_pipeline_bf16_tb/DUT/raw_exp
add wave -noupdate /div_pipeline_bf16_tb/DUT/final_exp
add wave -noupdate /div_pipeline_bf16_tb/DUT/fin
add wave -noupdate /div_pipeline_bf16_tb/DUT/special_result
add wave -noupdate /div_pipeline_bf16_tb/DUT/result
add wave -noupdate -color {Blue Violet} /div_pipeline_bf16_tb/DUT/flush
add wave -noupdate -color {Blue Violet} /div_pipeline_bf16_tb/DUT/pipe_en
add wave -noupdate /div_pipeline_bf16_tb/DUT/startn
add wave -noupdate /div_pipeline_bf16_tb/DUT/startd
add wave -noupdate /div_pipeline_bf16_tb/DUT/startsub
add wave -noupdate /div_pipeline_bf16_tb/DUT/startfin
add wave -noupdate /div_pipeline_bf16_tb/DUT/donen
add wave -noupdate /div_pipeline_bf16_tb/DUT/doned
add wave -noupdate /div_pipeline_bf16_tb/DUT/donefin
add wave -noupdate /div_pipeline_bf16_tb/DUT/sign
add wave -noupdate /div_pipeline_bf16_tb/DUT/is_subnormal_boundary
add wave -noupdate /div_pipeline_bf16_tb/DUT/op1_is_zero
add wave -noupdate /div_pipeline_bf16_tb/DUT/op1_is_inf
add wave -noupdate /div_pipeline_bf16_tb/DUT/op1_is_nan
add wave -noupdate /div_pipeline_bf16_tb/DUT/op2_is_zero
add wave -noupdate /div_pipeline_bf16_tb/DUT/op2_is_inf
add wave -noupdate /div_pipeline_bf16_tb/DUT/op2_is_nan
add wave -noupdate /div_pipeline_bf16_tb/DUT/op1_op2_same
add wave -noupdate /div_pipeline_bf16_tb/DUT/op2_is_one
add wave -noupdate /div_pipeline_bf16_tb/DUT/is_special
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {2203211243 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 134
configure wave -valuecolwidth 64
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
WaveRestoreZoom {0 ps} {328425 ps}
