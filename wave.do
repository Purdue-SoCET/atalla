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
add wave -noupdate -expand -group {DUT outputs} -expand /tb_top/DUT/mem_out_uuid
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/stall
add wave -noupdate -expand -group {DUT outputs} -color {Dark Orchid} /tb_top/DUT/hit
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/hit_load
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/block_status
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/uuid_block
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/dp_out_flushed
add wave -noupdate -expand -group {DUT outputs} -color Salmon /tb_top/DUT/ram_mem_REN
add wave -noupdate -expand -group {DUT outputs} -color Salmon /tb_top/DUT/ram_mem_WEN
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/ram_mem_addr
add wave -noupdate -expand -group {DUT outputs} /tb_top/DUT/ram_mem_store
add wave -noupdate -expand -group {DUT internal} -expand /tb_top/DUT/hit_check_instr
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/hit_check
add wave -noupdate -expand -group {DUT internal} -color Salmon /tb_top/DUT/miss
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/new_miss
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/internal_halt_banks
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/bank_hit
add wave -noupdate -expand -group {DUT internal} -color Salmon /tb_top/DUT/bank_stall
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/bank_busy
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/buffer_empty
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/internal_flushed_banks
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/hit_return_load
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/bank_uuids
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/mshr_out
add wave -noupdate -expand -group {DUT internal} /tb_top/DUT/bank_id
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/CLK}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/nRST}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/bank_id}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/instr_valid}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/ram_mem_data}
add wave -noupdate -expand -group {bank 3} -expand -subitemconfig {{/tb_top/DUT/BANK_GEN[3]/u_cache_bank/mshr_entry.write_status} {-color {Slate Blue} -height 16}} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/mshr_entry}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/mem_instr_in}
add wave -noupdate -expand -group {bank 3} -color {Slate Blue} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/ram_mem_complete}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/halt}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/cache_bank_busy}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/scheduler_hit}
add wave -noupdate -expand -group {bank 3} -color {Slate Blue} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/ram_mem_REN}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/ram_mem_WEN}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/ram_mem_store}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/ram_mem_addr}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/scheduler_data_out}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/scheduler_uuid_out}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/scheduler_uuid_ready}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/flushed}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/bank}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/next_bank}
add wave -noupdate -expand -group {bank 3} -color {Slate Blue} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/mshr_hit}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/next_mshr_hit}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/curr_state}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/next_state}
add wave -noupdate -expand -group {bank 3} -color {Slate Blue} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/count_FSM}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/next_count_FSM}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/count_flush}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/latched_block_pull_buffer}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/latched_victim_eject_buffer}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/flush_count}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/next_flush_count}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/latched_victim_way_index}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/victim_way_index}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/hit_way_index}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/max_way}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/next_flush_way}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/flush_way}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/mshr_hit_way}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/latched_victim_set_index}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/set_index}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/victim_set_index}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/next_flush_set}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/flush_set}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/tree_lru}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/next_tree_lru}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/_node}
add wave -noupdate -expand -group {bank 3} {/tb_top/DUT/BANK_GEN[3]/u_cache_bank/__node}
add wave -noupdate -expand -group {MSHR 3} {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/CLK}
add wave -noupdate -expand -group {MSHR 3} {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/nRST}
add wave -noupdate -expand -group {MSHR 3} {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/miss}
add wave -noupdate -expand -group {MSHR 3} {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/bank_id}
add wave -noupdate -expand -group {MSHR 3} {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/mem_instr}
add wave -noupdate -expand -group {MSHR 3} -color {Slate Blue} {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/bank_empty}
add wave -noupdate -expand -group {MSHR 3} -expand {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/mshr_out}
add wave -noupdate -expand -group {MSHR 3} {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/stall}
add wave -noupdate -expand -group {MSHR 3} {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/uuid_out}
add wave -noupdate -expand -group {MSHR 3} {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/buffer_empty}
add wave -noupdate -expand -group {MSHR 3} -expand {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/buffer}
add wave -noupdate -expand -group {MSHR 3} {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/next_buffer}
add wave -noupdate -expand -group {MSHR 3} {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/buffer_copy}
add wave -noupdate -expand -group {MSHR 3} {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/secondary_misses}
add wave -noupdate -expand -group {MSHR 3} {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/mshr_new_miss}
add wave -noupdate -expand -group {MSHR 3} {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/uuid}
add wave -noupdate -expand -group {MSHR 3} {/tb_top/DUT/BANK_GEN[3]/mshr_buffer_i/next_uuid}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/CLK}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/nRST}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/bank_id}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/instr_valid}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/ram_mem_data}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/mshr_entry}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/mem_instr_in}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/ram_mem_complete}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/halt}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/cache_bank_busy}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/scheduler_hit}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/ram_mem_REN}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/ram_mem_WEN}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/ram_mem_store}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/ram_mem_addr}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/scheduler_data_out}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/scheduler_uuid_out}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/scheduler_uuid_ready}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/flushed}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/bank}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/next_bank}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/mshr_hit}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/next_mshr_hit}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/curr_state}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/next_state}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/count_FSM}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/next_count_FSM}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/count_flush}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/latched_block_pull_buffer}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/latched_victim_eject_buffer}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/flush_count}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/next_flush_count}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/latched_victim_way_index}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/victim_way_index}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/hit_way_index}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/max_way}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/next_flush_way}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/flush_way}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/mshr_hit_way}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/latched_victim_set_index}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/set_index}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/victim_set_index}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/next_flush_set}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/flush_set}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/tree_lru}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/next_tree_lru}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/_node}
add wave -noupdate -group {bank 2} {/tb_top/DUT/BANK_GEN[2]/u_cache_bank/__node}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/CLK}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/nRST}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/miss}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/bank_id}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/mem_instr}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/bank_empty}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/mshr_out}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/stall}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/uuid_out}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/buffer_empty}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/buffer}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/next_buffer}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/buffer_copy}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/secondary_misses}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/mshr_new_miss}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/uuid}
add wave -noupdate -group {MSHR 2} {/tb_top/DUT/BANK_GEN[2]/mshr_buffer_i/next_uuid}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/CLK}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/nRST}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/bank_id}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/instr_valid}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/ram_mem_data}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/mshr_entry}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/mem_instr_in}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/ram_mem_complete}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/halt}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/cache_bank_busy}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/scheduler_hit}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/ram_mem_REN}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/ram_mem_WEN}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/ram_mem_store}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/ram_mem_addr}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/scheduler_data_out}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/scheduler_uuid_out}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/scheduler_uuid_ready}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/flushed}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/bank}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/next_bank}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/mshr_hit}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/next_mshr_hit}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/curr_state}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/next_state}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/count_FSM}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/next_count_FSM}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/count_flush}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/latched_block_pull_buffer}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/latched_victim_eject_buffer}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/flush_count}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/next_flush_count}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/latched_victim_way_index}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/victim_way_index}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/hit_way_index}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/max_way}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/next_flush_way}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/flush_way}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/mshr_hit_way}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/latched_victim_set_index}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/set_index}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/victim_set_index}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/next_flush_set}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/flush_set}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/tree_lru}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/next_tree_lru}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/_node}
add wave -noupdate -group {bank 1} {/tb_top/DUT/BANK_GEN[1]/u_cache_bank/__node}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/CLK}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/nRST}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/bank_id}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/instr_valid}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/ram_mem_data}
add wave -noupdate -group {bank 0} -expand -subitemconfig {{/tb_top/DUT/BANK_GEN[0]/u_cache_bank/mshr_entry.write_status} {-color {Slate Blue} -height 16}} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/mshr_entry}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/mem_instr_in}
add wave -noupdate -group {bank 0} -color {Slate Blue} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/ram_mem_complete}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/halt}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/cache_bank_busy}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/scheduler_hit}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/ram_mem_REN}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/ram_mem_WEN}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/ram_mem_store}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/ram_mem_addr}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/scheduler_data_out}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/scheduler_uuid_out}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/scheduler_uuid_ready}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/flushed}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/bank}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/next_bank}
add wave -noupdate -group {bank 0} -color {Slate Blue} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/mshr_hit}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/next_mshr_hit}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/curr_state}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/next_state}
add wave -noupdate -group {bank 0} -color {Slate Blue} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/count_FSM}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/next_count_FSM}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/count_flush}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/latched_block_pull_buffer}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/latched_victim_eject_buffer}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/flush_count}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/next_flush_count}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/latched_victim_way_index}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/victim_way_index}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/hit_way_index}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/max_way}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/next_flush_way}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/flush_way}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/mshr_hit_way}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/latched_victim_set_index}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/set_index}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/victim_set_index}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/next_flush_set}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/flush_set}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/tree_lru}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/next_tree_lru}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/_node}
add wave -noupdate -group {bank 0} {/tb_top/DUT/BANK_GEN[0]/u_cache_bank/__node}
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 4} {89964 ns} 0} {{Cursor 2} {10688 ns} 0}
quietly wave cursor active 2
configure wave -namecolwidth 203
configure wave -valuecolwidth 234
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
WaveRestoreZoom {8016 ns} {9299 ns}
