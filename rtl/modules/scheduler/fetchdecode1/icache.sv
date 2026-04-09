module icache (
  input logic CLK, nRST,
  datapath_cache_if.icache dcif,
  caches_if.icache cif
);
    import cpu_types_pkg::*;

    // Two separate cache banks
    icache_frame [15:0] bank0_cache, n_bank0_cache;
    icache_frame [15:0] bank1_cache, n_bank1_cache;
    
    // Address parsing
    logic [31:0] base_addr, next_addr;
    logic is_bank1_start;
    
    assign base_addr = dcif.imemaddr;
    assign next_addr = base_addr + 16; // +16 bytes pushes to the next 128-bit block
    
    // Determine which bank holds the start of the 160-bit instruction
    // Assuming 16-byte blocks, bit [4] determines even/odd block (Bank 0 vs Bank 1)
    assign is_bank1_start = base_addr[4]; 
    
    // Route addresses to the correct banks
    logic [31:0] addr_b0, addr_b1;
    assign addr_b0 = is_bank1_start ? next_addr : base_addr;
    assign addr_b1 = is_bank1_start ? base_addr : next_addr;

    // Extract Index and Tag for each bank (Assumes 5:4 is index if 4 blocks per bank, adjust to your exact sizing)
    // Format: [31:X] Tag, [X-1:5] Index, [4] Bank, [3:0] Byte Offset
    logic [31:0] tag_b0, tag_b1;
    logic [3:0]  idx_b0, idx_b1; // Adjust index width based on cache size

    assign tag_b0 = addr_b0[31:5]; // Simplification: replace with your exact tag slice
    assign idx_b0 = addr_b0[8:5];  // Simplification: replace with your exact index slice
    
    assign tag_b1 = addr_b1[31:5];
    assign idx_b1 = addr_b1[8:5];

    // Hit Logic
    logic hit_b0, hit_b1, full_hit;
    assign hit_b0 = bank0_cache[idx_b0].valid && (bank0_cache[idx_b0].tag == tag_b0);
    assign hit_b1 = bank1_cache[idx_b1].valid && (bank1_cache[idx_b1].tag == tag_b1);
    assign full_hit = hit_b0 && hit_b1;

    // STATE MACHINE
    typedef enum logic [1:0] {REQ, FETCH_B0, FETCH_B1} istate;
    istate state, n_state;

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            state <= REQ;
            bank0_cache <= '0;
            bank1_cache <= '0;
        end else begin
            state <= n_state;
            bank0_cache <= n_bank0_cache;
            bank1_cache <= n_bank1_cache;
        end
    end

    always_comb begin
        // Defaults
        n_bank0_cache = bank0_cache;
        n_bank1_cache = bank1_cache;
        n_state = state;
        cif.iREN = 0;
        cif.iaddr = 32'b0;

        case (state)
            REQ: begin
                if (!full_hit) begin
                    // Decide which bank to fetch first based on which one missed
                    if (!hit_b0)      n_state = FETCH_B0;
                    else if (!hit_b1) n_state = FETCH_B1;
                end
            end
            
            FETCH_B0: begin
                cif.iREN = 1;
                cif.iaddr = {addr_b0[31:4], 4'b0000}; // Block aligned memory address
                
                if (!cif.iwait) begin
                    n_bank0_cache[idx_b0].valid = 1;
                    n_bank0_cache[idx_b0].tag   = tag_b0;
                    n_bank0_cache[idx_b0].data  = cif.iload; // 128-bit load
                    
                    // If Bank 1 also missed, fetch it next. Otherwise, return to REQ.
                    if (!hit_b1) n_state = FETCH_B1;
                    else         n_state = REQ;
                end
            end
            
            FETCH_B1: begin
                cif.iREN = 1;
                cif.iaddr = {addr_b1[31:4], 4'b0000}; // Block aligned memory address
                
                if (!cif.iwait) begin
                    n_bank1_cache[idx_b1].valid = 1;
                    n_bank1_cache[idx_b1].tag   = tag_b1;
                    n_bank1_cache[idx_b1].data  = cif.iload; // 128-bit load
                    
                    n_state = REQ; // Both banks are now valid
                end
            end
        endcase
    end

    // DATA READOUT LOGIC
    logic [255:0] merged_data;
    logic [1:0]   word_offset;
    
    always_comb begin
        dcif.ihit = (state == REQ) ? full_hit : 0;
        
        // Concatenate the two 128-bit blocks appropriately
        if (is_bank1_start) begin
            merged_data = {bank0_cache[idx_b0].data, bank1_cache[idx_b1].data};
        end else begin
            merged_data = {bank1_cache[idx_b1].data, bank0_cache[idx_b0].data};
        end

        // Shift the merged 256-bit bus based on the starting word offset
        // Extract the exact 160 bits needed
        word_offset = base_addr[3:2]; 
        dcif.imemload = merged_data >> (word_offset * 32); 
        // Note: dcif.imemload must be explicitly defined as logic [159:0] in your interface
    end

endmodule