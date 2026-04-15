// `include "caches_pkg.sv"

// module icache_wrapper #(
//     parameter ADDR_WIDTH = 32,
//     parameter INSTR_WIDTH = 160,
//     parameter ROB_DEPTH = 16,
//     parameter FRQ_DEPTH = 8,
//     parameter MRQ_DEPTH = 8,
//     parameter ROB_IDX_WIDTH = $clog2(ROB_DEPTH)
// )(
//     input  logic clk, rst_n,

//     // CPU Fetch Interface
//     input  logic                   cpu_fetch_valid,
//     input  logic [ADDR_WIDTH-1:0]  cpu_fetch_pc,
//     output logic                   cpu_fetch_ready,

//     // CPU Receive Interface
//     output logic                   cpu_instr_valid,
//     output logic [INSTR_WIDTH-1:0] cpu_instr_data,
//     output logic [ADDR_WIDTH-1:0]  cpu_instr_pc,
//     input  logic                   cpu_instr_ready,

//     // Cache RAM Interface (Passthrough to Main Memory)
//     output logic [NUM_BANKS-1:0]           ram_mem_REN,
//     output logic [NUM_BANKS-1:0]           ram_mem_WEN,
//     output logic [NUM_BANKS-1:0][ADDR_WIDTH-1:0] ram_mem_addr,
//     output logic [NUM_BANKS-1:0][CACHE_RW_SIZE-1:0] ram_mem_store,
//     input  logic [NUM_BANKS-1:0][CACHE_RW_SIZE-1:0] ram_mem_data,
//     input  logic [NUM_BANKS-1:0]           ram_mem_complete
// );

//     // ====================================================================
//     // Internal Types & Signals
//     // ====================================================================
    
//     // --- Cache Interface Signals ---
//     logic cache_mem_in, cache_stall, cache_hit;
//     logic [ADDR_WIDTH-1:0] cache_mem_in_addr;
//     logic [CACHE_RW_SIZE-1:0] cache_hit_load; 
//     logic [UUID_SIZE-1:0] cache_mem_out_uuid;
//     logic [NUM_BANKS-1:0] cache_block_status;
//     logic [NUM_BANKS-1:0][UUID_SIZE-1:0] cache_uuid_block;

//     // --- FRQ Signals ---
//     logic [ADDR_WIDTH-1:0] frq_mem [FRQ_DEPTH-1:0];
//     logic [$clog2(FRQ_DEPTH)-1:0] frq_wr_ptr, frq_rd_ptr;
//     logic [$clog2(FRQ_DEPTH):0] frq_count;
//     logic frq_empty, frq_full, frq_push, frq_pop;
//     logic [ADDR_WIDTH-1:0] frq_out_addr;

//     // --- IROB Signals ---
//     typedef struct packed {
//         logic valid_A;
//         logic valid_B;
//         logic is_split;
//         logic [5:0] offset;
//         logic [ADDR_WIDTH-1:0] pc;
//         logic [INSTR_WIDTH-1:0] instr;
//     } rob_entry_t;
    
//     rob_entry_t irob_mem [ROB_DEPTH-1:0];
//     logic [ROB_IDX_WIDTH-1:0] irob_head, irob_tail;
//     logic [$clog2(ROB_DEPTH):0] irob_count;
//     logic irob_full, irob_empty;
//     logic irob_alloc_en, irob_write_en, irob_commit_en;
//     logic irob_write_is_part_b;
//     logic [ROB_IDX_WIDTH-1:0] irob_write_idx;
//     logic [CACHE_RW_SIZE-1:0] irob_write_data;

//     // --- MRQ Signals ---
//     typedef enum logic [1:0] {INVALID, WAITING, READY} mrq_state_e;
//     mrq_state_e               mrq_state      [MRQ_DEPTH-1:0];
//     logic [UUID_SIZE-1:0]     mrq_uuid       [MRQ_DEPTH-1:0];
//     logic [ADDR_WIDTH-1:0]    mrq_addr       [MRQ_DEPTH-1:0];
//     logic [ROB_IDX_WIDTH-1:0] mrq_rob_idx    [MRQ_DEPTH-1:0];
//     logic                     mrq_is_part_b  [MRQ_DEPTH-1:0];
    
//     logic [$clog2(MRQ_DEPTH)-1:0] mrq_free_idx, mrq_ready_idx;
//     logic mrq_found_free, mrq_found_ready;
//     logic mrq_alloc_en, mrq_replay_pop;
//     logic [UUID_SIZE-1:0] mrq_alloc_uuid;
//     logic [ROB_IDX_WIDTH-1:0] mrq_alloc_rob_idx;
//     logic [ADDR_WIDTH-1:0] mrq_alloc_addr;
//     logic mrq_alloc_is_part_b;

//     // --- In-Flight Tracker Signals ---
//     logic [1:0]               inflight_timer; 
//     logic                     inflight_is_part_b;
//     logic [ROB_IDX_WIDTH-1:0] inflight_rob_idx;
//     logic [ADDR_WIDTH-1:0]    inflight_addr;

//     // --- Arbitration Signals ---
//     logic issue_replay, issue_fetch, safe_frq_valid;
//     logic split_req, split_phase;
//     logic [ROB_IDX_WIDTH-1:0] last_alloc_idx;
//     logic active_is_part_b;
//     logic [ROB_IDX_WIDTH-1:0] active_rob_idx;
//     logic [ADDR_WIDTH-1:0]    active_addr;

//     // ====================================================================
//     // Combinational Logic & Routing
//     // ====================================================================

//     // CPU Interfaces
//     assign cpu_fetch_ready = !frq_full;
//     assign frq_push = cpu_fetch_valid && cpu_fetch_ready;

//     // Instruction is valid if Part A is here, and (if split) Part B is here too
//     assign cpu_instr_valid = !irob_empty && 
//                              irob_mem[irob_head].valid_A && 
//                              (!irob_mem[irob_head].is_split || irob_mem[irob_head].valid_B);
                             
//     assign cpu_instr_pc    = irob_mem[irob_head].pc;
//     assign cpu_instr_data  = irob_mem[irob_head].instr;
//     assign irob_commit_en  = cpu_instr_ready && cpu_instr_valid;

//     // FRQ Status
//     assign frq_empty = (frq_count == 0);
//     assign frq_full  = (frq_count == FRQ_DEPTH);
//     assign frq_out_addr = frq_mem[frq_rd_ptr];

//     // IROB Status
//     assign irob_empty = (irob_count == 0);
//     assign irob_full  = (irob_count == ROB_DEPTH);

//     // Split Calculation (160 bits = 20 bytes. 64 - 20 = 44).
//     assign split_req = (frq_out_addr[5:0] > 6'd44);

//     // MRQ Priority Encoders
//     always_comb begin
//         mrq_free_idx = '0; mrq_found_free = 1'b0;
//         mrq_ready_idx = '0; mrq_found_ready = 1'b0;
//         for (int i = MRQ_DEPTH-1; i >= 0; i--) begin
//             if (mrq_state[i] == INVALID) begin mrq_free_idx = i; mrq_found_free = 1'b1; end
//             if (mrq_state[i] == READY)   begin mrq_ready_idx = i; mrq_found_ready = 1'b1; end
//         end
//     end

//     // Arbitration Logic & Safety Shields
//     assign safe_frq_valid = !frq_empty && (!irob_full || split_phase) && mrq_found_free;

//     // Issue strictly when the pipeline timer is 0 (IDLE).
//     assign issue_replay = mrq_found_ready && (inflight_timer == 0);
//     assign issue_fetch  = safe_frq_valid && !mrq_found_ready && (inflight_timer == 0);

//     assign mrq_replay_pop = issue_replay;
//     assign frq_pop        = issue_fetch && (!split_req || split_phase);
//     assign irob_alloc_en  = issue_fetch && !split_phase;

//     always_comb begin
//         if (issue_replay) begin
//             active_addr      = mrq_addr[mrq_ready_idx];
//             active_rob_idx   = mrq_rob_idx[mrq_ready_idx];
//             active_is_part_b = mrq_is_part_b[mrq_ready_idx];
//         end else begin
//             active_addr      = split_phase ? {frq_out_addr[ADDR_WIDTH-1:6] + 1'b1, 6'd0} : frq_out_addr;
//             active_rob_idx   = split_phase ? last_alloc_idx : irob_tail;
//             active_is_part_b = split_phase;
//         end
//     end

//     // 1-CYCLE PULSE: Trigger the cache FSM.
//     assign cache_mem_in = issue_replay || issue_fetch;
    
//     // SHIELD ADDRESS: Hold the address stable while the timer is running.
//     assign cache_mem_in_addr = (inflight_timer != 0) ? inflight_addr : active_addr;

//     // --- Fragment Stitching Wires (Combinational Extraction) ---
//     logic [9:0] write_off_bits;
//     logic [9:0] write_part_a_bits;

//     always_comb begin
//         write_off_bits = irob_mem[irob_write_idx].offset * 8;
//         write_part_a_bits = 512 - write_off_bits;
//     end

//     // Cache Resolution Logic
//     always_comb begin
//         irob_write_en        = 1'b0;
//         irob_write_is_part_b = 1'b0;
//         irob_write_idx       = '0;
//         irob_write_data      = '0;
        
//         mrq_alloc_en         = 1'b0;
//         mrq_alloc_uuid       = '0;
//         mrq_alloc_rob_idx    = '0;
//         mrq_alloc_addr       = '0;
//         mrq_alloc_is_part_b  = 1'b0;

//         if (inflight_timer != 0) begin
//             // 1. GREEDY HIT: Accept data on ANY cycle it arrives
//             if (cache_hit) begin
//                 irob_write_en        = 1'b1;
//                 irob_write_idx       = inflight_rob_idx;
//                 irob_write_is_part_b = inflight_is_part_b;
//                 irob_write_data      = cache_hit_load; 
//             end 
//             // 2. TIMEOUT MISS: Only log a miss if we hit cycle 2 and still have no hit
//             else if (inflight_timer == 2 && !cache_stall) begin
//                 mrq_alloc_en         = 1'b1;
//                 mrq_alloc_uuid       = cache_mem_out_uuid;
//                 mrq_alloc_rob_idx    = inflight_rob_idx;
//                 mrq_alloc_addr       = inflight_addr;
//                 mrq_alloc_is_part_b  = inflight_is_part_b;
//             end
//         end
//     end

//     // ====================================================================
//     // Sequential Logic
//     // ====================================================================
//     always_ff @(posedge clk or negedge rst_n) begin
//         if (!rst_n) begin
//             frq_wr_ptr <= '0; frq_rd_ptr <= '0; frq_count  <= '0;
            
//             irob_head <= '0; irob_tail <= '0; irob_count <= '0;
//             for (int i = 0; i < ROB_DEPTH; i++) begin
//                 irob_mem[i].valid_A <= 1'b0;
//                 irob_mem[i].valid_B <= 1'b0;
//             end
            
//             for (int i = 0; i < MRQ_DEPTH; i++) mrq_state[i] <= INVALID;
            
//             inflight_timer <= 0; inflight_is_part_b <= 1'b0; 
//             inflight_rob_idx <= '0; inflight_addr <= '0;
            
//             split_phase <= 1'b0; last_alloc_idx <= '0;
            
//         end else begin
//             // --- FRQ Updates ---
//             if (frq_push && !frq_full) begin
//                 frq_mem[frq_wr_ptr] <= cpu_fetch_pc;
//                 frq_wr_ptr <= frq_wr_ptr + 1;
//             end
//             if (frq_pop && !frq_empty) begin
//                 frq_rd_ptr <= frq_rd_ptr + 1;
//             end
//             if (frq_push && !frq_pop && !frq_full) frq_count <= frq_count + 1;
//             else if (!frq_push && frq_pop && !frq_empty) frq_count <= frq_count - 1;

//             // --- Split FSM Tracker ---
//             if (issue_fetch) begin
//                 if (split_req && !split_phase) begin
//                     split_phase <= 1'b1;
//                     last_alloc_idx <= irob_tail; // Latch index for part B
//                 end else if (split_phase) begin
//                     split_phase <= 1'b0;
//                 end
//             end

//             // --- IROB Alloc/Commit Updates ---
//             if (irob_alloc_en && !irob_full) begin
//                 irob_mem[irob_tail].valid_A  <= 1'b0;
//                 irob_mem[irob_tail].valid_B  <= 1'b0;
//                 irob_mem[irob_tail].is_split <= split_req;
//                 irob_mem[irob_tail].offset   <= frq_out_addr[5:0];
//                 irob_mem[irob_tail].pc       <= frq_out_addr;
//                 irob_tail                    <= irob_tail + 1;
//             end
//             if (irob_commit_en && cpu_instr_valid) begin
//                 irob_mem[irob_head].valid_A <= 1'b0;
//                 irob_mem[irob_head].valid_B <= 1'b0;
//                 irob_head                   <= irob_head + 1;
//             end
//             if (irob_alloc_en && !irob_commit_en) irob_count <= irob_count + 1;
//             else if (!irob_alloc_en && irob_commit_en) irob_count <= irob_count - 1;

//             // --- IROB Fragment Stitching (Write) ---
//             if (irob_write_en) begin
//                 if (!irob_mem[irob_write_idx].is_split) begin
//                     for (int i = 0; i < INSTR_WIDTH; i++) begin
//                         irob_mem[irob_write_idx].instr[i] <= irob_write_data[(write_off_bits + i) % 512];
//                     end
//                     irob_mem[irob_write_idx].valid_A <= 1'b1;
//                 end 
//                 else if (!irob_write_is_part_b) begin
//                     for (int i = 0; i < INSTR_WIDTH; i++) begin
//                         if (i < write_part_a_bits) irob_mem[irob_write_idx].instr[i] <= irob_write_data[(write_off_bits + i) % 512];
//                     end
//                     irob_mem[irob_write_idx].valid_A <= 1'b1;
//                 end 
//                 else begin
//                     for (int i = 0; i < INSTR_WIDTH; i++) begin
//                         if (i >= write_part_a_bits) 
//                             irob_mem[irob_write_idx].instr[i] <= irob_write_data[ (i >= write_part_a_bits) ? (i - write_part_a_bits) : 0 ];
//                     end
//                     irob_mem[irob_write_idx].valid_B <= 1'b1;
//                 end
//             end

//             // --- MRQ Updates ---
//             if (mrq_replay_pop) begin
//                 mrq_state[mrq_ready_idx] <= INVALID;
//             end
//             if (mrq_alloc_en && mrq_found_free) begin
//                 mrq_state[mrq_free_idx]     <= WAITING;
//                 mrq_uuid[mrq_free_idx]      <= mrq_alloc_uuid;
//                 mrq_addr[mrq_free_idx]      <= mrq_alloc_addr;
//                 mrq_rob_idx[mrq_free_idx]   <= mrq_alloc_rob_idx;
//                 mrq_is_part_b[mrq_free_idx] <= mrq_alloc_is_part_b;
//             end
            
//             for (int i = 0; i < MRQ_DEPTH; i++) begin
//                 if (mrq_state[i] == WAITING) begin
//                     // Mathematically calculate which bank the missing address lives in
//                     int expected_bank;
//                     expected_bank = (mrq_addr[i] >> (BYTE_OFF_BIT_LEN + BLOCK_OFF_BIT_LEN)) & (NUM_BANKS - 1);
                    
//                     // ONLY snoop that specific bank
//                     if (cache_block_status[expected_bank] && (cache_uuid_block[expected_bank] == mrq_uuid[i])) begin
//                         mrq_state[i] <= READY;
//                     end
//                 end
//             end
            
//             // --- In-Flight Tracker Updates ---
//             if (issue_replay || issue_fetch) begin
//                 inflight_timer     <= 1;
//                 inflight_is_part_b <= active_is_part_b;
//                 inflight_rob_idx   <= active_rob_idx;
//                 inflight_addr      <= active_addr;
//             end else if (inflight_timer != 0) begin
//                 if (cache_hit) begin
//                     // EARLY EXIT: The cache bypassed the pipeline, close the request
//                     inflight_timer <= 0;
//                 end else if (!cache_stall) begin
//                     // Normal pipeline progression
//                     if (inflight_timer == 1) begin
//                         inflight_timer <= 2;
//                     end else if (inflight_timer == 2) begin
//                         inflight_timer <= 0; // Miss fully logged
//                     end
//                 end
//             end
//         end
//     end

//     // ====================================================================
//     // Lockup-Free Cache Instantiation
//     // ====================================================================
//     lockup_free_cache u_cache (
//         .CLK               (clk), 
//         .nRST              (rst_n),
//         .mem_in            (cache_mem_in),
//         .mem_in_addr       (cache_mem_in_addr),
//         .mem_in_rw_mode    (1'b0), // I-Cache is always read
//         .mem_in_store_value('0),
//         .dp_in_halt        (1'b0), 
//         .mem_out_uuid      (cache_mem_out_uuid),
//         .stall             (cache_stall),
//         .hit               (cache_hit),
//         .hit_load          (cache_hit_load), 
//         .block_status      (cache_block_status),
//         .uuid_block        (cache_uuid_block),
//         .dp_out_flushed    (),
        
//         .ram_mem_REN       (ram_mem_REN),
//         .ram_mem_WEN       (ram_mem_WEN),
//         .ram_mem_addr      (ram_mem_addr),
//         .ram_mem_store     (ram_mem_store),
//         .ram_mem_data      (ram_mem_data),
//         .ram_mem_complete  (ram_mem_complete)
//     );

// endmodule