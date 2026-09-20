onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /system_tb/ATALLA/CLK
add wave -noupdate /system_tb/ATALLA/nRST
add wave -noupdate /system_tb/ATALLA/halt
add wave -noupdate -expand -group icache /system_tb/ATALLA/ICACHE/state
add wave -noupdate -expand -group icache /system_tb/ATALLA/ICACHE/imemaddr
add wave -noupdate -expand -group icache /system_tb/ATALLA/ICACHE/imemREN
add wave -noupdate -expand -group icache /system_tb/ATALLA/ICACHE/ihit
add wave -noupdate -expand -group icache -expand /system_tb/ATALLA/ICACHE/imemload
add wave -noupdate -expand -group icache /system_tb/ATALLA/ICACHE/iwait
add wave -noupdate -expand -group icache /system_tb/ATALLA/ICACHE/iload
add wave -noupdate -expand -group icache /system_tb/ATALLA/ICACHE/iREN
add wave -noupdate -expand -group icache /system_tb/ATALLA/ICACHE/iaddr
add wave -noupdate -expand -group icache /system_tb/ATALLA/ICACHE/cache
add wave -noupdate -group dcache {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_sram/mem}
add wave -noupdate -group dcache /system_tb/ATALLA/DCACHE/dp_in_halt
add wave -noupdate -group dcache /system_tb/ATALLA/DCACHE/dp_out_flushed
add wave -noupdate -group dcache /system_tb/ATALLA/DCACHE/ram_mem_REN
add wave -noupdate -group dcache /system_tb/ATALLA/DCACHE/ram_mem_WEN
add wave -noupdate -group dcache -radix decimal /system_tb/ATALLA/DCACHE/ram_mem_addr
add wave -noupdate -group dcache /system_tb/ATALLA/DCACHE/ram_mem_store
add wave -noupdate -group dcache /system_tb/ATALLA/DCACHE/ram_mem_data
add wave -noupdate -group dcache /system_tb/ATALLA/DCACHE/ram_mem_complete
add wave -noupdate -group dcache /system_tb/ATALLA/DCACHE/mem_in
add wave -noupdate -group dcache -radix decimal /system_tb/ATALLA/DCACHE/mem_in_addr
add wave -noupdate -group dcache /system_tb/ATALLA/DCACHE/mem_in_rw_mode
add wave -noupdate -group dcache /system_tb/ATALLA/DCACHE/mem_in_store_value
add wave -noupdate -group dcache /system_tb/ATALLA/DCACHE/stall
add wave -noupdate -group dcache /system_tb/ATALLA/DCACHE/miss
add wave -noupdate -group dcache /system_tb/ATALLA/DCACHE/hit
add wave -noupdate -group dcache {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/curr_state}
add wave -noupdate -group dcache {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/count_FSM}
add wave -noupdate -group dcache {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/next_count_FSM}
add wave -noupdate -group dcache {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/latched_mshr_hit}
add wave -noupdate -group dcache -expand {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/latched_mshr_entry}
add wave -noupdate -group dcache {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/hc_state}
add wave -noupdate -group dcache {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/next_hc_state}
add wave -noupdate -group dcache -expand -subitemconfig {{/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/hc_latched_set[0]} -expand} {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/hc_latched_set}
add wave -noupdate -group dcache {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/found_hit}
add wave -noupdate -group dcache -expand -subitemconfig {{/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/mem_instr_in.addr} -expand} {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/mem_instr_in}
add wave -noupdate -group dcache {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/sram_ren}
add wave -noupdate -group dcache {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/sram_raddr}
add wave -noupdate -group dcache -expand {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/sram_rdata}
add wave -noupdate -group dcache {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/sram_rdone}
add wave -noupdate -group dcache {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/sram_wen}
add wave -noupdate -group dcache {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/main_sram_raddr}
add wave -noupdate -group dcache {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/hc_sram_raddr}
add wave -noupdate -group dcache {/system_tb/ATALLA/DCACHE/BANK_GEN[0]/u_cache_bank/hc_grant}
add wave -noupdate -group Memroy /system_tb/RAM_SIM/mem
add wave -noupdate -group Memroy /system_tb/RAM_SIM/sel_addr
add wave -noupdate -group Memroy /system_tb/RAM_SIM/ic_resp_rdata
add wave -noupdate -expand -group Fetch -group {cache interface} /system_tb/ATALLA/CORE/datapath_cache_if/ihit
add wave -noupdate -expand -group Fetch -group {cache interface} /system_tb/ATALLA/CORE/datapath_cache_if/imemready
add wave -noupdate -expand -group Fetch -group {cache interface} /system_tb/ATALLA/CORE/datapath_cache_if/imemREN
add wave -noupdate -expand -group Fetch -group {cache interface} /system_tb/ATALLA/CORE/datapath_cache_if/imemaddr
add wave -noupdate -expand -group Fetch -group {cache interface} -expand /system_tb/ATALLA/CORE/datapath_cache_if/imemload
add wave -noupdate -expand -group Fetch /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/fu/flush
add wave -noupdate -expand -group Fetch /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/fu/ready
add wave -noupdate -expand -group Fetch /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/fu/halt
add wave -noupdate -expand -group Fetch /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/fu/pc_branch
add wave -noupdate -expand -group Fetch /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/fu/pc
add wave -noupdate -expand -group Fetch /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/fu/next_pc
add wave -noupdate -expand -group Fetch /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/fu/pred_taken
add wave -noupdate -group {Dec 1} /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/dec12_if/pc_in
add wave -noupdate -group {Dec 1} /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/dec12_if/pc_out
add wave -noupdate -group {Dec 1} /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/dec12_if/predict_taken_in
add wave -noupdate -group {Dec 1} /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/dec12_if/predict_taken_out
add wave -noupdate -group {Dec 1} /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/dec12_if/pc_pred_addr_in
add wave -noupdate -group {Dec 1} /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/dec12_if/pc_pred_addr_out
add wave -noupdate -group {Dec 1} /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/dec12_if/scalar_inst_in
add wave -noupdate -group {Dec 1} /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/dec12_if/scalar_inst_out
add wave -noupdate -group {Dec 1} /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/dec12_if/ready
add wave -noupdate -group {Dec 1} /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/dec12_if/flush
add wave -noupdate -group {Dec 2} /system_tb/ATALLA/CORE/S_V_DECODE_2/scalar_fu_enables
add wave -noupdate -group {Dec 2} /system_tb/ATALLA/CORE/S_V_DECODE_2/scalar_reg_writes
add wave -noupdate -group {Dec 2} /system_tb/ATALLA/CORE/S_V_DECODE_2/scalar_wsels
add wave -noupdate -group {Dec 2} /system_tb/ATALLA/CORE/S_V_DECODE_2/need_scalar_ex1
add wave -noupdate -group {Dec 2} /system_tb/ATALLA/CORE/S_V_DECODE_2/need_scalar_ex2
add wave -noupdate -group {Dec 2} /system_tb/ATALLA/CORE/S_V_DECODE_2/need_scalar_ex3
add wave -noupdate -group {Dec 2} /system_tb/ATALLA/CORE/S_V_DECODE_2/need_scalar_ex4
add wave -noupdate -group {Dec 2} /system_tb/ATALLA/CORE/S_V_DECODE_2/need_scalar_ex5
add wave -noupdate -group {Dec 2} -expand -group {dep checker} /system_tb/ATALLA/CORE/S_V_DECODE_2/dcif/dependencies_ready
add wave -noupdate -group {Dec 2} -expand -group {dep checker} /system_tb/ATALLA/CORE/S_V_DECODE_2/dc1/scalar_dependency_table
add wave -noupdate -group {Dec 2} -expand -group {dep checker} /system_tb/ATALLA/CORE/S_V_DECODE_2/dc1/scalar_hit
add wave -noupdate -group {Dec 2} -expand -group {dep checker} /system_tb/ATALLA/CORE/S_V_DECODE_2/dc1/scalar_hazard
add wave -noupdate -group {Dec 2} -expand -group {dep checker} /system_tb/ATALLA/CORE/S_V_DECODE_2/dc1/scalar_RAW
add wave -noupdate -group {Dec 2} -expand -group {dep checker} /system_tb/ATALLA/CORE/S_V_DECODE_2/dc1/scalar_WAW
add wave -noupdate -expand -group EX -expand /system_tb/ATALLA/CORE/S_EXECUTE/post_xbar_ex1
add wave -noupdate -expand -group EX /system_tb/ATALLA/CORE/S_EXECUTE/post_xbar_ex2
add wave -noupdate -expand -group EX /system_tb/ATALLA/CORE/S_EXECUTE/post_xbar_ex3
add wave -noupdate -expand -group EX /system_tb/ATALLA/CORE/S_EXECUTE/post_xbar_ex4
add wave -noupdate -expand -group EX -childformat {{/system_tb/ATALLA/CORE/S_EXECUTE/post_xbar_ex5.imm -radix decimal}} -expand -subitemconfig {/system_tb/ATALLA/CORE/S_EXECUTE/post_xbar_ex5.imm {-height 16 -radix decimal}} /system_tb/ATALLA/CORE/S_EXECUTE/post_xbar_ex5
add wave -noupdate -expand -group EX -group branch /system_tb/ATALLA/CORE/S_EXECUTE/UNIT_1/CONT/taken_comb
add wave -noupdate -expand -group EX -group branch /system_tb/ATALLA/CORE/S_EXECUTE/UNIT_1/CONT/redirect_target_comb
add wave -noupdate -expand -group EX -group branch /system_tb/ATALLA/CORE/S_EXECUTE/UNIT_1/CONT/redirect_valid_comb
add wave -noupdate -expand -group EX -group branch /system_tb/ATALLA/CORE/S_EXECUTE/UNIT_1/CONT/rd_write_en_comb
add wave -noupdate -expand -group EX -group branch /system_tb/ATALLA/CORE/S_EXECUTE/UNIT_1/CONT/rd_value_comb
add wave -noupdate -expand -group EX -group branch /system_tb/ATALLA/CORE/S_EXECUTE/UNIT_1/CONT/rd_idx_out_comb
add wave -noupdate -expand -group EX -group branch /system_tb/ATALLA/CORE/S_EXECUTE/UNIT_1/CONT/pc_plus4
add wave -noupdate -expand -group EX -expand -group ALU /system_tb/ATALLA/CORE/S_EXECUTE/UNIT_1/ALU/result_comb
add wave -noupdate -expand -group WB -expand -subitemconfig {/system_tb/ATALLA/CORE/scalar_wb_if/scalar_wb_in.data -expand /system_tb/ATALLA/CORE/scalar_wb_if/scalar_wb_in.valid -expand /system_tb/ATALLA/CORE/scalar_wb_if/scalar_wb_in.rd -expand} /system_tb/ATALLA/CORE/scalar_wb_if/scalar_wb_in
add wave -noupdate -expand -group WB /system_tb/ATALLA/CORE/scalar_wb_if/scalar_wb_out
add wave -noupdate -group {scalar reg file} {/system_tb/ATALLA/CORE/S_V_DECODE_2/srf1/u_reggie/DATA_BANK_GEN[0]/u_bank/mem}
add wave -noupdate -group {scalar reg file} {/system_tb/ATALLA/CORE/S_V_DECODE_2/srf1/u_reggie/DATA_BANK_GEN[1]/u_bank/mem}
add wave -noupdate -group {scalar reg file} {/system_tb/ATALLA/CORE/S_V_DECODE_2/srf1/u_reggie/DATA_BANK_GEN[2]/u_bank/mem}
add wave -noupdate -group {scalar reg file} {/system_tb/ATALLA/CORE/S_V_DECODE_2/srf1/u_reggie/DATA_BANK_GEN[3]/u_bank/mem}
add wave -noupdate -expand -group {cascaded readys} /system_tb/ATALLA/CORE/decode_2_if/ready
add wave -noupdate -expand -group {cascaded readys} /system_tb/ATALLA/CORE/dec1_dec2_latch_ready
add wave -noupdate -expand -group {cascaded readys} /system_tb/ATALLA/CORE/D1_D2_latch.valid
add wave -noupdate -expand -group {cascaded readys} /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/ifdec1_if/valid_out
add wave -noupdate -expand -group {cascaded readys} /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/ifdec1_if/valid_in
add wave -noupdate -expand -group {cascaded readys} /system_tb/ATALLA/CORE/S_FETCH_DECODE_1/dec1_if_ready
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {7796 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 138
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
WaveRestoreZoom {0 ps} {29705 ps}
