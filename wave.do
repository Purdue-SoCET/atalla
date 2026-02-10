onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -expand -group {DUT inputs} /tb_top/DUT/CLK
add wave -noupdate -expand -group {DUT inputs} /tb_top/DUT/nRST
add wave -noupdate -expand -group {DUT inputs} /tb_top/DUT/mem_in
add wave -noupdate -expand -group {DUT inputs} /tb_top/DUT/mem_in_addr
add wave -noupdate -expand -group {DUT inputs} /tb_top/DUT/mem_in_rw_mode
add wave -noupdate -expand -group {DUT inputs} /tb_top/DUT/mem_in_store_value
add wave -noupdate -expand -group {DUT inputs} /tb_top/DUT/dp_in_halt
add wave -noupdate -expand -group {DUT inputs} /tb_top/DUT/ram_mem_data
add wave -noupdate -expand -group {DUT inputs} /tb_top/DUT/ram_mem_complete
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/mem_out_uuid
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/stall
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/hit
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/hit_load
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/block_status
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/uuid_block
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/dp_out_flushed
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/ram_mem_REN
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/ram_mem_WEN
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/ram_mem_addr
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/ram_mem_store
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/hit_check_instr
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/hit_check
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/miss
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/new_miss
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/internal_halt_banks
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/bank_hit
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/bank_stall
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/bank_busy
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/buffer_empty
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/internal_flushed_banks
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/hit_return_load
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/bank_uuids
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/mshr_out
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/bank_id
add wave -noupdate /uvm_root/uvm_test_top/env/lfc_predictor/ram_imp
add wave -noupdate /uvm_root/uvm_test_top/env/lfc_predictor/pred_ram_ap
add wave -noupdate /uvm_root/uvm_test_top/env/lfc_predictor/pred_cpu_ap
add wave -noupdate /uvm_root/uvm_test_top/env/lfc_predictor/cpu_imp
add wave -noupdate /uvm_root/uvm_test_top/env/lfc_predictor/completed_addr
add wave -noupdate /uvm_root/uvm_test_top/env/lfc_predictor/completed_uuid
add wave -noupdate /uvm_root/uvm_test_top/env/lfc_predictor/bank_id
add wave -noupdate /uvm_root/uvm_test_top/env/lfc_predictor/next_uuid
add wave -noupdate /uvm_root/uvm_test_top/env/lfc_predictor/uuid_addr_map
add wave -noupdate /uvm_root/uvm_test_top/env/lfc_predictor/uuid_in_flight
add wave -noupdate /uvm_root/uvm_test_top/env/lfc_predictor/data_is_in_cache
add wave -noupdate /uvm_root/uvm_test_top/env/lfc_predictor/data_model
add wave -noupdate /uvm_root/uvm_test_top/env/lfc_predictor/MSHR_occupancy
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {887 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 178
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
WaveRestoreZoom {0 ns} {2867 ns}
