`timescale 1ps/1ps

`include "cache_types_pkg.svh"

module RAM (
    input logic CLK, nRST,
    input logic [31:0] ram_addr,
    input logic [31:0] ram_store,
    input logic ram_REN, ram_WEN,
    input logic[BANKS_LEN-1:0] bank_id,
    output logic[31:0] ram_load,
    output logic ram_ready
);

    localparam cycle_delay = 5;

    logic[31:0] ram_data [logic [31:0]];
    logic [31:0] current_addr, prev_addr;
    logic[31:0] counter, next_counter;
    typedef enum logic [5:0] { start, ram_read, ram_write } state_t;
    state_t state, next_state;

    assign current_addr = ram_addr;

    always_ff @ (posedge CLK, negedge nRST) begin
        if (!nRST) begin
            counter <= 0;
            state <= start;
            prev_addr <= 0;
        end else begin
            counter <= next_counter;
            state <= next_state;
            prev_addr <= current_addr;
        end
    end

    always_comb begin
        next_state = state;

        case (state)
            start: begin
                if (ram_REN) begin
                    next_state = ram_read;
                end
                if (ram_WEN) begin
                    next_state = ram_write;
                end
            end
            ram_read: begin
                if (!ram_REN) begin
                    next_state = ram_WEN ? ram_write : start;
                end
                if (current_addr != prev_addr) begin
                    next_state = ram_WEN ? ram_write : (ram_REN ? ram_read : start);
                end
            end
            ram_write: begin
                if (!ram_WEN) begin
                    next_state = ram_REN ? ram_read : start;
                end
                if (current_addr != prev_addr) begin
                    next_state = ram_WEN ? ram_write : (ram_REN ? ram_read : start);
                end
            end
        endcase
    end

    always_comb begin
        next_counter = counter;
        ram_ready = 0;
        ram_load = 0;

        case (state)
            start: begin
                if (!ram_WEN && !ram_REN) ram_ready = 1; 
            end
            ram_read: begin
                if (!ram_REN || current_addr != prev_addr) begin
                    next_counter = 0;
                end else if (counter == cycle_delay) begin
                    ram_ready = 1;
                    if (ram_data.exists(current_addr)) begin
                        ram_load = ram_data[current_addr]; 
                    end else begin
                        ram_load = 32'd0;
                    end            
                    $display("RAM ID:%d -- read from %08x: %08x", bank_id, current_addr, ram_load);     
                end else begin
                    next_counter = counter + 1;
                end
            end
            ram_write: begin
                if (!ram_WEN || ram_REN || current_addr != prev_addr) begin
                    next_counter = 0;
                end else if (counter == cycle_delay) begin
                    ram_ready = 1;
                    ram_data[current_addr] = ram_store;
                    $display("RAM ID:%d -- write to %08x: %08x", bank_id, current_addr, ram_store);
                end else begin
                    next_counter = counter + 1;
                end
            end   
        endcase
    end
endmodule

class cache_line;
    logic[BLOCK_INDEX_BIT_LEN-1:0] set_index;
    rand logic[TAG_BIT_LEN-1:0] rand_tag_val;
    logic[TAG_BIT_LEN-1:0] tag;
    addr_t[BLOCK_SIZE-1:0] addr;
    rand logic [BLOCK_SIZE-1:0][31:0] data;
    rand logic[BLOCK_SIZE-1:0][31:0] data2;
    integer i;

    function new(logic[BLOCK_INDEX_BIT_LEN-1:0] set_index, integer way_index);
        this.set_index = set_index;
        void'(std::randomize(rand_tag_val) with { rand_tag_val != 0; });
        void'(std::randomize(data));
        void'(std::randomize(data2));
        this.tag = {rand_tag_val[TAG_BIT_LEN-1:4], 4'(way_index)};
        for (i = 0; i < BLOCK_SIZE; i++) begin
            addr[i].tag = tag;
            addr[i].index = set_index;
            addr[i].block_offset = i;
            addr[i].byte_offset = 0;
        end
    endfunction
endclass

module lockup_free_cache_tb;
    localparam CLK_PERIOD = 1;
    localparam PERF_INTERVAL = 100;

    logic tb_clk;
    logic tb_nrst;
    logic monitor_enable; 

    always begin
        tb_clk = 1'b0;
        #(CLK_PERIOD/2.0);
        tb_clk = 1'b1;
        #(CLK_PERIOD/2.0);
    end

    logic tb_mem_in;
    logic[UUID_SIZE-1:0] tb_mem_out_uuid;
    logic[31:0] tb_mem_in_addr;
    logic tb_mem_in_rw_mode;
    logic [31:0] tb_mem_in_store_value;
    logic tb_stall;
    logic tb_hit;
    logic tb_halt;
    logic tb_flushed;
    logic [31:0] tb_hit_load;
    logic[NUM_BANKS-1:0] tb_block_status;
    logic [NUM_BANKS-1:0][3:0] tb_uuid_block;
    logic [NUM_BANKS-1:0] tb_ram_mem_REN;
    logic [NUM_BANKS-1:0] tb_ram_mem_WEN;
    logic[NUM_BANKS-1:0][31:0] tb_ram_mem_addr;
    logic [NUM_BANKS-1:0][31:0] tb_ram_mem_store;
    logic [NUM_BANKS-1:0][31:0] tb_ram_mem_data;
    logic [NUM_BANKS-1:0] tb_ram_mem_complete;

    lockup_free_cache u_lockup_free_cache (
        .CLK                   (tb_clk),
        .nRST                  (tb_nrst),
        .mem_in                (tb_mem_in),
        .mem_out_uuid           (tb_mem_out_uuid),
        .mem_in_addr           (tb_mem_in_addr),
        .mem_in_rw_mode        (tb_mem_in_rw_mode),
        .mem_in_store_value    (tb_mem_in_store_value),
        .dp_in_halt            (tb_halt),
        .stall                 (tb_stall),
        .hit                   (tb_hit),
        .hit_load              (tb_hit_load),
        .block_status          (tb_block_status),
        .uuid_block            (tb_uuid_block),
        .dp_out_flushed        (tb_flushed),
        .ram_mem_REN           (tb_ram_mem_REN),
        .ram_mem_WEN           (tb_ram_mem_WEN),
        .ram_mem_addr          (tb_ram_mem_addr),
        .ram_mem_store         (tb_ram_mem_store),
        .ram_mem_data          (tb_ram_mem_data),
        .ram_mem_complete      (tb_ram_mem_complete)
    );

    genvar i;
    generate
        for (i = 0; i < NUM_BANKS; i++) begin : RAM_GEN
            RAM u_RAM (
                .CLK          (tb_clk),
                .nRST         (tb_nrst),
                .ram_addr     (tb_ram_mem_addr[i]),
                .ram_store    (tb_ram_mem_store[i]),
                .ram_REN      (tb_ram_mem_REN[i]),
                .ram_WEN      (tb_ram_mem_WEN[i]),
                .ram_load     (tb_ram_mem_data[i]),
                .ram_ready    (tb_ram_mem_complete[i]),
                .bank_id      (BANKS_LEN'(i))
            );

            cache_set [NUM_SETS_PER_BANK-1:0] monitor_bank_view;
            assign monitor_bank_view = u_lockup_free_cache.BANK_GEN[i].u_sram.mem;

            cache_bank_monitor u_monitor_inst (
                .CLK          (tb_clk),
                .nRST         (tb_nrst),
                .bank         (monitor_bank_view), 
                .enable       (monitor_enable)
            );
        end
    endgenerate

    import "DPI-C" function void cache_update_hit();
    import "DPI-C" function void cache_update_miss();
    import "DPI-C" function void cache_update_in_flight(int in_flight);
    import "DPI-C" function void print_cache_perf(int cycle);

    integer reqs_in_flight;
    integer cycle_count;
    int pending_reqs [int];

    logic [31:0] finished_block_addr[NUM_BANKS-1:0];
    generate
        for (genvar g = 0; g < NUM_BANKS; g++) begin : GEN_FIN_ADDR
            assign finished_block_addr[g] = u_lockup_free_cache.BANK_GEN[g].u_cache_bank.latched_mshr_entry.block_addr;
        end
    endgenerate

    always_ff @(posedge tb_clk or negedge tb_nrst) begin : PERF_COUNTER
        if (!tb_nrst) begin
            reqs_in_flight <= 0;
            cycle_count <= 0;
            pending_reqs.delete();
        end else begin
            int current_in_flight;
            current_in_flight = reqs_in_flight;
            
            if (tb_mem_in && !tb_stall && !tb_hit) begin
                int blk_addr;
                blk_addr = {tb_mem_in_addr[31:(BLOCK_OFF_BIT_LEN+BYTE_OFF_BIT_LEN)], {(BLOCK_OFF_BIT_LEN+BYTE_OFF_BIT_LEN){1'b0}}};
                if (pending_reqs.exists(blk_addr)) begin
                    pending_reqs[blk_addr]++;
                end else begin
                    pending_reqs[blk_addr] = 1;
                end
                current_in_flight++;
                cache_update_miss();
            end
            
            if (tb_mem_in && !tb_stall && tb_hit) begin
                cache_update_hit();
            end

            for (int j = 0; j < NUM_BANKS; j++) begin
                if (tb_block_status[j]) begin
                    int finished_blk;
                    finished_blk = finished_block_addr[j];
                    if (pending_reqs.exists(finished_blk)) begin
                        current_in_flight -= pending_reqs[finished_blk];
                        pending_reqs.delete(finished_blk);
                    end
                end
            end

            reqs_in_flight <= current_in_flight;
            cache_update_in_flight(current_in_flight);
            
            cycle_count <= cycle_count + 1;
            if (cycle_count > 0 && cycle_count % PERF_INTERVAL == 0) begin
                print_cache_perf(cycle_count);
            end
        end
    end

    task data_read(input logic[31:0] addr, output logic[31:0] data);
        tb_mem_in = 0;
        $display("Starting data read: %08x", addr);
        #1;
        while (tb_stall) begin
            $display("Cache stall!");
            @(posedge tb_clk);
            #1;
        end
        tb_mem_in = 1;
        tb_mem_in_addr = addr;
        tb_mem_in_rw_mode = 0;
        tb_mem_in_store_value = 0;
        
        @(posedge tb_clk);
        #1;
        while (tb_stall) begin
            @(posedge tb_clk);
            #1;
        end

        if (tb_hit) begin
            $display("Read hit on %08x! -> %08x", addr, tb_hit_load);
            data = tb_hit_load;
        end else begin
            $display("Read miss on %08x!", addr);
        end
        @(posedge tb_clk);
        tb_mem_in = 0;
    endtask

    task data_write(input logic [31:0] addr, input logic[31:0] data);
        tb_mem_in = 0;
        $display("Starting data write: %08x,%08x", addr, data);
        #1;
        while (tb_stall) begin
            $display("Cache stall!");
            @(posedge tb_clk);
            #1;
        end
        tb_mem_in = 1;
        tb_mem_in_addr = addr;
        tb_mem_in_rw_mode = 1;
        tb_mem_in_store_value = data;
        
        @(posedge tb_clk);
        #1;
        while (tb_stall) begin
            @(posedge tb_clk);
            #1;
        end

        if (tb_hit) begin
            $display("Write hit on %08x!", addr);
        end else begin
            $display("Write miss on %08x!", addr);
        end
        @(posedge tb_clk);
        tb_mem_in = 0;
    endtask

    task cycle_wait(input integer cycle_count);
        for (int lc = 0; lc < cycle_count; lc++) begin
            @(posedge tb_clk);
        end
    endtask


    logic[31:0] data_out;
    string testcase; 

    integer current_set_index;
    integer current_block_offset;
    integer current_way;

    cache_line line[NUM_SETS][7:0];

    localparam test_set_num = NUM_SETS;

    initial begin
        tb_nrst = 0;
        tb_mem_in = 0;
        tb_mem_in_addr = 0;
        tb_mem_in_rw_mode = 0;
        tb_mem_in_store_value = 0;
        tb_halt = 0;
        @(negedge tb_clk);
        tb_nrst = 1;
        testcase = "PART 1";
        @(posedge tb_clk);        
        for (current_set_index = 0; current_set_index < test_set_num; current_set_index++) begin
            line[current_set_index][0] = new(current_set_index, 0);
            line[current_set_index][1] = new(current_set_index, 1);
            line[current_set_index][2] = new(current_set_index, 2);
            line[current_set_index][3] = new(current_set_index, 3);
            line[current_set_index][4] = new(current_set_index, 4);
            line[current_set_index][5] = new(current_set_index, 5);
            line[current_set_index][6] = new(current_set_index, 6);
            line[current_set_index][7] = new(current_set_index, 7);

            for (current_way = 0; current_way < NUM_WAYS; current_way++) begin
                for (current_block_offset = 0; current_block_offset < 1; current_block_offset++) begin
                    data_read(line[current_set_index][current_way].addr[current_block_offset], data_out);                
                end
                for (current_block_offset = 0; current_block_offset < 1; current_block_offset++) begin
                    data_write(line[current_set_index][current_way].addr[current_block_offset], 32'h88888888);                
                end
            end
            for (current_way = 0; current_way < NUM_WAYS; current_way++) begin
                for (current_block_offset = 0; current_block_offset < 1; current_block_offset++) begin
                    data_write(line[current_set_index][current_way].addr[current_block_offset], 32'h88888888);                
                end
                for (current_block_offset = 0; current_block_offset < 1; current_block_offset++) begin
                    data_read(line[current_set_index][current_way].addr[current_block_offset], data_out);                
                end
            end
        end
        $display("hit check!");
        tb_mem_in = 0;
        cycle_wait(1500);
        $display("Done waiting for misses to finish!");
        for (current_set_index = 0; current_set_index < test_set_num; current_set_index++) begin
            for (current_way = 0; current_way < NUM_WAYS; current_way++) begin
                for (current_block_offset = 0; current_block_offset < 1; current_block_offset++) begin
                    data_write(line[current_set_index][current_way].addr[current_block_offset], line[current_set_index][current_way].data[current_block_offset]);                
                end
            end
            for (current_way = 0; current_way < NUM_WAYS; current_way++) begin
                for (current_block_offset = 0; current_block_offset < 1; current_block_offset++) begin
                    data_read(line[current_set_index][current_way].addr[current_block_offset], data_out);
                    if (data_out !== line[current_set_index][current_way].data[current_block_offset]) begin
                        $error("DATA MISMATCH at %08x: read %08x, expected %08x", line[current_set_index][current_way].addr[current_block_offset], data_out, line[current_set_index][current_way].data[current_block_offset]);
                    end
                end
            end
        end
        @(posedge tb_clk);
        tb_mem_in = 0;
        testcase = "FLUSHING";
        @(posedge tb_clk);
        tb_halt = 1; 
        wait(tb_flushed == 1);
        testcase = "FINISHED";
        @(posedge tb_clk);
        monitor_enable = 1; 
        @(posedge tb_clk);
        print_cache_perf(cycle_count);
        $finish;
    end

endmodule