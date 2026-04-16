
`include "atalla_isa_types.vh"

import atalla_isa_pkg::*;

module icache (
  input logic CLK, nRST,
  //to/from scheduler (fetch)
  input word_t imemaddr,
  input logic imemREN,
  output logic ihit,
  output logic imemready,
  output instruction_packet_t imemload,
  //to/from memory
  input logic iwait,
  input logic [63:0] iload,
  output logic iREN,
  output logic [31:0] iaddr
);
    typedef struct packed {
        logic valid;
        logic [18:0] tag;
        logic [511:0] data;
    } icache_frame;

    icache_frame [127:0] cache, n_cache;

    // --- Address Parsing (Directly from CPU for Same-Cycle Hits) ---
    logic [31:0] addr_a, addr_b;
    assign addr_a = imemaddr;
    assign addr_b = addr_a + 32'd64; 

    logic [18:0] tag_a, tag_b;
    logic [6:0]  idx_a, idx_b;
    logic [5:0]  off_a;

    assign {tag_a, idx_a, off_a} = addr_a;
    assign {tag_b, idx_b}        = addr_b[31:6];

    // --- FSM Registers ---
    typedef enum logic {IDLE, FILL} state_t;
    state_t state, n_state;
    logic [2:0] fill_count, n_fill_count;
    
    // Latched fill targets (Protects memory state if CPU flushes/changes addr mid-miss)
    logic [6:0]  active_fill_idx, n_active_fill_idx;
    logic [18:0] active_fill_tag, n_active_fill_tag;
    logic [31:0] active_fill_addr, n_active_fill_addr;

    // --- Safe & Elegant Chunk Calculation ---
    logic [6:0] end_byte;
    assign end_byte = {1'b0, off_a} + 7'd19; 

    logic is_split;
    assign is_split = end_byte[6]; 

    logic [2:0] last_chunk_a, last_chunk_b;
    assign last_chunk_a = is_split ? 3'd7 : end_byte[5:3]; 
    assign last_chunk_b = end_byte[5:3];

    // --- Strictly Registered Hit Logic ---
    logic hit_a, hit_b, full_hit;

    // Hit A: True if already in cache, OR if it just finished latching during a fill
    assign hit_a = (cache[idx_a].valid && (cache[idx_a].tag == tag_a)) ||
                   (state == FILL && (active_fill_idx == idx_a) && (active_fill_tag == tag_a) &&
                    (fill_count > last_chunk_a)); // > ensures data is safely latched!

    // Hit B: True if already in cache, OR if it just finished latching during a fill
    assign hit_b = (cache[idx_b].valid && (cache[idx_b].tag == tag_b)) ||
                   (state == FILL && (active_fill_idx == idx_b) && (active_fill_tag == tag_b) &&
                    (fill_count > last_chunk_b));

    assign full_hit = is_split ? (hit_a && hit_b) : hit_a;

    // --- Sequential Logic ---
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            state <= IDLE;
            cache <= '0;
            fill_count <= '0;
            active_fill_idx <= '0;
            active_fill_tag <= '0;
            active_fill_addr <= '0;
        end else begin
            state <= n_state;
            cache <= n_cache;
            fill_count <= n_fill_count;
            active_fill_idx <= n_active_fill_idx;
            active_fill_tag <= n_active_fill_tag;
            active_fill_addr <= n_active_fill_addr;
        end
    end

    // --- Next State and Control Logic ---
    always_comb begin
        n_state = state;
        n_cache = cache;
        n_fill_count = fill_count;
        n_active_fill_idx = active_fill_idx;
        n_active_fill_tag = active_fill_tag;
        n_active_fill_addr = active_fill_addr;
        
        iREN   = (state == FILL);
        iaddr  = active_fill_addr; 
        
        // ihit combinationally gated by CPU Read Enable
        ihit  = (imemREN && full_hit);

        case (state)
            IDLE: begin
                if (imemREN) begin
                    if (!hit_a) begin
                        n_state = FILL;
                        n_fill_count = 0;
                        n_active_fill_idx = idx_a;
                        n_active_fill_tag = tag_a;
                        n_active_fill_addr = {addr_a[31:6], 6'b0};
                        n_cache[idx_a].valid = 0; 
                    end else if (is_split && !hit_b) begin
                        n_state = FILL;
                        n_fill_count = 0;
                        n_active_fill_idx = idx_b;
                        n_active_fill_tag = tag_b;
                        n_active_fill_addr = {addr_b[31:6], 6'b0};
                        n_cache[idx_b].valid = 0;
                    end
                end
            end

            FILL: begin
                if (!iwait) begin
                    n_cache[active_fill_idx].data[(fill_count*64) +: 64] = iload;
                    n_fill_count = fill_count + 1;
                end

                if (!iwait && fill_count == 3'd7) begin
                    n_cache[active_fill_idx].valid = 1;
                    n_cache[active_fill_idx].tag = active_fill_tag;
                    
                    // If CPU still wants this split instruction, queue up the next block
                    if (imemREN && is_split && !hit_b && (idx_a == active_fill_idx)) begin
                        n_fill_count = 0;
                        n_active_fill_idx = idx_b;
                        n_active_fill_tag = tag_b;
                        n_active_fill_addr = {addr_b[31:6], 6'b0};
                        n_cache[idx_b].valid = 0;
                    end else begin
                        n_state = IDLE;
                        n_fill_count = 0;
                    end
                end
            end
        endcase
    end

    // --- Strictly Registered Data Output ---
    logic [1023:0] virtual_window;
    always_comb begin
        // CRITICAL PATH CUT: Output strictly reads from the physical flip-flops.
        // It never reads directly from iload or n_cache.
        virtual_window = {cache[idx_b].data, cache[idx_a].data};
        imemload = virtual_window[(off_a * 8) +: 160];
    end

endmodule