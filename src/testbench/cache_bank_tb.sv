`timescale 1ps/1ps
`include "cache_types_pkg.svh"

module RAM (
    input logic CLK, nRST,
    input logic[31:0] ram_addr,
    input logic[31:0] ram_store,
    input logic ram_REN, ram_WEN,
    output logic [31:0] ram_load,
    output logic ram_ready
);

    localparam cycle_delay = 5;

    logic [31:0] next_ram_data [logic[31:0]];
    logic[31:0] ram_data [logic [31:0]];
    logic[31:0] current_addr, prev_addr;
    logic[31:0] counter, next_counter;
    typedef enum logic[5:0] { start, ram_read, ram_write } state_t;
    state_t state, next_state;

    assign current_addr = ram_addr;

    always_ff @ (posedge CLK, negedge nRST) begin
        if (!nRST) begin
            counter <= 0;
            state <= start;
            prev_addr <= 0;
            ram_data <= '{default: '{default: 1}}; 
        end else begin
            counter <= next_counter;
            state <= next_state;
            prev_addr <= current_addr;
            ram_data <= next_ram_data; 
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
        next_ram_data = ram_data;

        case (state)
            start: begin
                if (counter == cycle_delay) begin 
                    ram_ready = 1;
                    next_counter = 0;
                end else begin 
                    next_counter = counter + 1;
                end  

            end
            ram_read: begin
                if (!ram_REN || current_addr != prev_addr) begin
                    next_counter = 0;
                end else if (counter == cycle_delay) begin
                    ram_ready = 1;
                    ram_load = ram_data[current_addr];               
                end else begin
                    next_counter = counter + 1;
                end
            end
            ram_write: begin
                if (!ram_WEN || current_addr != prev_addr) begin
                    next_counter = 0;
                end else if (counter == cycle_delay) begin
                    ram_ready = 1;
                    next_ram_data[current_addr] = ram_store;
                end else begin
                    next_counter = counter + 1;
                end
            end   
        endcase
    end
endmodule


module cache_bank_tb;
    localparam CLK_PERIOD = 10; 
    localparam int MAX_INIT_ADDR = 256;

    logic tb_clk;
    logic tb_nrst;
    logic[BANKS_LEN-1:0] tb_bank_id;
    logic tb_instr_valid;
    logic[CACHE_RW_SIZE-1:0] tb_ram_mem_data;
    mshr_reg tb_mshr_entry;
    in_mem_instr tb_mem_instr;
    logic tb_ram_mem_complete;
    logic tb_cache_bank_free;
    logic tb_scheduler_hit;
    logic tb_scheduler_miss;
    logic tb_hc_stall;
    logic tb_ram_mem_REN;
    logic tb_ram_mem_WEN;
    logic[CACHE_RW_SIZE-1:0] tb_ram_mem_store;
    addr_t tb_ram_mem_addr;
    logic[31:0] tb_scheduler_data_out;
    logic [3:0] tb_scheduler_uuid_out;
    logic tb_scheduler_uuid_ready; 
    logic tb_halt; 
    logic tb_flushed; 
    logic monitor_enable; 

    always begin
        tb_clk = 1'b0;
        #(CLK_PERIOD/2);
        tb_clk = 1'b1;
        #(CLK_PERIOD/2);
    end
    
    RAM u_RAM (
        .CLK(tb_clk),
        .nRST(tb_nrst),
        .ram_addr(tb_ram_mem_addr),
        .ram_store(tb_ram_mem_store),
        .ram_REN(tb_ram_mem_REN),
        .ram_WEN (tb_ram_mem_WEN),
        .ram_load(tb_ram_mem_data),
        .ram_ready(tb_ram_mem_complete)
    );

    logic tb_sram_ren;
    logic[NUM_SETS_PER_BANK_LEN-1:0] tb_sram_raddr;
    cache_set tb_sram_rdata;
    logic tb_sram_rdone;

    logic tb_sram_wen;
    logic[NUM_SETS_PER_BANK_LEN-1:0] tb_sram_waddr;
    cache_set tb_sram_wdata;
    logic tb_sram_wdone;
    logic tb_sram_busy;

    sram_bank #(
        .READ_LATENCY(2),
        .WRITE_LATENCY(4),
        .HEIGHT(NUM_SETS_PER_BANK),
        .WIDTH($bits(cache_set))
    ) u_sram (
        .clk(tb_clk),
        .n_rst(tb_nrst),
        .busy(tb_sram_busy),
        .ren(tb_sram_ren),
        .raddr(tb_sram_raddr),
        .rdata(tb_sram_rdata),
        .rdone(tb_sram_rdone),
        .wen(tb_sram_wen),
        .waddr(tb_sram_waddr),
        .wdata(tb_sram_wdata),
        .wdone(tb_sram_wdone)
    );

    cache_bank dut (
        .CLK(tb_clk),
        .nRST(tb_nrst),
        .bank_id(tb_bank_id),
        .instr_valid(tb_instr_valid),
        .ram_mem_data(tb_ram_mem_data),
        .mshr_entry_in(tb_mshr_entry),
        .mem_instr_in(tb_mem_instr),
        .ram_mem_complete(tb_ram_mem_complete),
        .halt(tb_halt),
        .cache_bank_free(tb_cache_bank_free),
        .scheduler_hit(tb_scheduler_hit),
        .scheduler_miss(tb_scheduler_miss),
        .hc_stall(tb_hc_stall),
        .ram_mem_REN(tb_ram_mem_REN),
        .ram_mem_WEN(tb_ram_mem_WEN),
        .ram_mem_store(tb_ram_mem_store),
        .ram_mem_addr(tb_ram_mem_addr),
        .scheduler_data_out(tb_scheduler_data_out),
        .scheduler_uuid_out(tb_scheduler_uuid_out),
        .scheduler_uuid_ready(tb_scheduler_uuid_ready),
        .flushed(tb_flushed),
        
        .sram_ren(tb_sram_ren),
        .sram_raddr(tb_sram_raddr),
        .sram_rdata(tb_sram_rdata),
        .sram_rdone(tb_sram_rdone),
        .sram_wen(tb_sram_wen),
        .sram_waddr(tb_sram_waddr),
        .sram_wdata(tb_sram_wdata),
        .sram_wdone(tb_sram_wdone),
        .sram_busy(tb_sram_busy)
    );

    cache_set[NUM_SETS_PER_BANK-1:0] tb_monitor_bank_view;
    assign tb_monitor_bank_view = u_sram.mem;

    cache_bank_monitor monitor_inst (
        .CLK(tb_clk),
        .nRST(tb_nrst),
        .bank(tb_monitor_bank_view), 
        .enable(monitor_enable)
    );


    test PROG (
        .tb_clk(tb_clk),
        .tb_nrst(tb_nrst),
        .tb_bank_id(tb_bank_id),
        .tb_instr_valid(tb_instr_valid),
        .tb_ram_mem_data(tb_ram_mem_data),
        .tb_mshr_entry(tb_mshr_entry),
        .tb_mem_instr(tb_mem_instr),
        .tb_halt(tb_halt),
        .monitor_enable(monitor_enable),
        .tb_ram_mem_complete(tb_ram_mem_complete),
        .tb_cache_bank_free(tb_cache_bank_free),
        .tb_scheduler_hit(tb_scheduler_hit),
        .tb_hc_stall(tb_hc_stall),
        .tb_ram_mem_REN(tb_ram_mem_REN),
        .tb_ram_mem_WEN(tb_ram_mem_WEN),
        .tb_ram_mem_store(tb_ram_mem_store),
        .tb_ram_mem_addr(tb_ram_mem_addr),
        .tb_scheduler_data_out(tb_scheduler_data_out),
        .tb_scheduler_uuid_out(tb_scheduler_uuid_out), 
        .tb_scheduler_uuid_ready(tb_scheduler_uuid_ready),
        .tb_flushed(tb_flushed)
    );

endmodule


program test (
    input logic  tb_clk,
    output logic  tb_nrst,
    output logic[BANKS_LEN-1:0] tb_bank_id,
    output logic  tb_instr_valid,
    output mshr_reg  tb_mshr_entry,
    output in_mem_instr  tb_mem_instr,
    output logic tb_halt, 
    output logic monitor_enable, 
    input logic[CACHE_RW_SIZE-1:0] tb_ram_mem_data,
    input logic  tb_ram_mem_complete,
    input logic  tb_cache_bank_free,
    input logic  tb_ram_mem_REN,
    input logic  tb_ram_mem_WEN,
    input logic[CACHE_RW_SIZE-1:0] tb_ram_mem_store,
    input addr_t  tb_ram_mem_addr,
    input logic[31:0] tb_scheduler_data_out,
    input logic [3:0] tb_scheduler_uuid_out,
    input logic  tb_scheduler_hit,
    input logic tb_hc_stall,
    input logic  tb_scheduler_uuid_ready,
    input logic tb_flushed
);

    addr_t address;
    mshr_reg tmp_mshr;
    string test_id; 
    logic SingleCycle_RW_Done, MSHR_Thread_Done;
    integer display_bit = 0; 
    logic [BLOCK_SIZE-1:0] write_status; 
    cache_block write_block;
    int count; 

    task automatic initiate_read_write(
        logic[TAG_BIT_LEN-1:0] tag,
        logic[BLOCK_INDEX_BIT_LEN-1:0] index,
        logic[BLOCK_OFF_BIT_LEN-1:0] block_offset,
        logic [BYTE_OFF_BIT_LEN-1:0] byte_offset,
        logic rw_mode,
        logic [31:0] store_value
    ); 
        tb_instr_valid = 1;
        address = addr_t'{ tag, index, block_offset, byte_offset }; 
        tb_mem_instr  = in_mem_instr'{ address, rw_mode, store_value };
        @(posedge tb_clk);
        #1;
        while (tb_hc_stall) begin
            @(posedge tb_clk);
            #1;
        end
        tb_instr_valid = 0;
        log_ram_inputs(1, tb_ram_mem_complete, tb_ram_mem_addr, tb_ram_mem_store, tb_ram_mem_WEN, tb_ram_mem_REN, tb_cache_bank_free, tb_scheduler_data_out, tb_scheduler_uuid_out, tb_scheduler_hit, tb_scheduler_uuid_ready);
        @(posedge tb_clk);
        @(posedge tb_clk);
    endtask

    task automatic set_mshr(
        logic valid,
        logic[UUID_SIZE-1:0] uuid,
        addr_t block_addr,
        logic[BLOCK_SIZE-1:0] write_status,
        cache_block write_block
    );
        tb_mshr_entry = {valid, uuid, block_addr, write_status, write_block};
        @(posedge tb_clk);
    endtask

    task automatic log_ram_inputs(
        integer cycles, 
        logic _tb_ram_mem_complete,
        logic[31:0] _tb_ram_mem_addr,
        logic[CACHE_RW_SIZE-1:0] _tb_ram_mem_store,
        logic _tb_ram_mem_WEN,
        logic _tb_ram_mem_REN,
        logic _tb_cache_bank_free, 
        logic[31:0] _tb_scheduler_data_out,
        logic[3:0] _tb_scheduler_uuid_out,
        logic  _tb_scheduler_hit, 
        logic _tb_scheduler_uuid_ready
    );
        for (integer i = 0; i < cycles; i++) begin 
            if (display_bit) $display("--> ram_mem_complete: %b, ram_mem_addr: %h, ram_mem_store: %h, ram_mem_WEN: %b, ram_mem_REN: %b, tb_cache_bank_free: %b", _tb_ram_mem_complete, _tb_ram_mem_addr, _tb_ram_mem_store, _tb_ram_mem_WEN, _tb_ram_mem_REN, _tb_cache_bank_free);
            if (display_bit) $display("      tb_scheduler_data_out: %d, tb_scheduler_uuid_out: %h, tb_scheduler_hit: %b, _tb_scheduler_uuid_ready: %b", _tb_scheduler_data_out, _tb_scheduler_uuid_out, _tb_scheduler_hit, _tb_scheduler_uuid_ready);
            @(posedge tb_clk);
        end 
    endtask

    task automatic reset();
        tb_nrst = 0;
        tb_bank_id = '0;
        tb_instr_valid = 0;
        tb_mshr_entry = '0;
        address = '0; 
        tb_mem_instr  = '0;
        SingleCycle_RW_Done = 1'b0; 
        MSHR_Thread_Done = 1'b0;
        monitor_enable = 1'b0; 
        @(posedge tb_clk);
        @(posedge tb_clk);
        tb_nrst = 1;
        tb_bank_id = BANKS_LEN'(4'd3);
        set_test_id("RESET DONE");
        @(posedge tb_clk);
    endtask

    task automatic fill_bank(
        logic random_valid, 
        logic random_dirty
    );
        cache_set s;
        for (integer set = 0; set < NUM_SETS_PER_BANK; set++) begin
            for (integer way = 0; way < NUM_WAYS; way++) begin
                s[way].valid = (random_valid) ? $urandom_range(0, 1) : 1'b1;
                s[way].dirty = (random_dirty) ? $urandom_range(0, 1) : 1'b0;
                s[way].tag   = '1; 
                for (integer b = 0; b < BLOCK_SIZE; b++) begin
                    s[way].block[b] = {
                        $urandom_range(0, 8'hFF), 
                        $urandom_range(0, 8'hFF), 
                        $urandom_range(0, 8'hFF), 
                        $urandom_range(0, 8'hFF)
                    };
                end
            end
            cache_bank_tb.u_sram.mem[set] = s;
        end
        @(posedge tb_clk);
        @(posedge tb_clk);
    endtask

    task automatic set_test_id(
        string test_in
    );
        test_id = test_in;
        $display(test_in);
    endtask

    task stall_for_ram; 
        wait(tb_scheduler_uuid_ready == 1); 
    endtask

    task automatic inject_directed_miss(
        logic[UUID_SIZE-1:0] uuid,
        addr_t addr
    );
        tb_mshr_entry = {1'b1, uuid, addr, BLOCK_SIZE'('0), cache_block'('0)};

        @(posedge tb_clk);
        tb_mshr_entry.valid = 0;

        stall_for_ram();
        @(posedge tb_clk);
    endtask

    task automatic test_lru_collision_bug();
        set_test_id("-------> Hit & Miss Finish Same Cycle");

        inject_directed_miss(4'd1, addr_t'{24'd1, 4'd0, 2'd0, 2'd0});

        inject_directed_miss(4'd10, addr_t'{24'd10, 4'd4, 2'd0, 2'd0}); // W0
        inject_directed_miss(4'd12, addr_t'{24'd12, 4'd4, 2'd0, 2'd0}); // W2
        inject_directed_miss(4'd11, addr_t'{24'd11, 4'd4, 2'd0, 2'd0}); // W1
        inject_directed_miss(4'd13, addr_t'{24'd13, 4'd4, 2'd0, 2'd0}); // W3

        fork
            begin : miss_thread
                inject_directed_miss(4'd14, addr_t'{24'd14, 4'd4, 2'd0, 2'd0});
            end
            begin : hit_thread
                wait(cache_bank_tb.dut.curr_state == FINISH);
 
                tb_instr_valid = 1;
                address = addr_t'{24'd1, 4'd0, 2'd0, 2'd0};
                tb_mem_instr  = in_mem_instr'{ address, 1'b0, 32'd0 };

                @(posedge tb_clk);
                #1;
                while (tb_hc_stall) begin
                    @(posedge tb_clk);
                    #1;
                end
                tb_instr_valid = 0;
            end
        join

        inject_directed_miss(4'd15, addr_t'{24'd15, 4'd4, 2'd0, 2'd0});

        if (cache_bank_tb.tb_monitor_bank_view[1][0].tag === 24'd15) begin
            $error("BUG DETECTED: Tag 15 overwrote Way 0. The concurrent Hit masked the Miss's LRU update.");
        end else if (cache_bank_tb.tb_monitor_bank_view[1][2].tag === 24'd15 && cache_bank_tb.tb_monitor_bank_view[1][0].tag === 24'd14) begin
            $display("SUCCESS: Tag 15 correctly went to Way 2.");
        end else begin
            $error("UNKNOWN STATE: Way 0: %0d, Way 2: %0d", cache_bank_tb.tb_monitor_bank_view[1][0].tag, cache_bank_tb.tb_monitor_bank_view[1][2].tag);
        end
    endtask

    initial begin

        set_test_id("-------> RESET");
        reset();

        test_lru_collision_bug();

        set_test_id("-------> Trying a WRITE - MISS");
        initiate_read_write(
            .tag(24'h1000), 
            .index(4'h9), 
            .block_offset(2'b00), 
            .byte_offset(2'b00), 
            .rw_mode(1'b1), 
            .store_value(32'd0)
        );

        set_test_id("-------> Filling MSHR Entry");
        set_mshr(
            .valid(1'b1), 
            .uuid(4'd9),
            .block_addr(address), 
            .write_status(BLOCK_SIZE'('0)), 
            .write_block(cache_block'('0))
        );

        set_test_id("-------> FSM Initiated");
        stall_for_ram();

        set_test_id("-------> Clearing MSHR Entry");
        set_mshr(
            .valid('0), 
            .uuid('0),
            .block_addr('0), 
            .write_status('0), 
            .write_block('0)
        );

        set_test_id("-------> Trying a READ - HIT");
        initiate_read_write(
            .tag(24'h1000), 
            .index(4'h9), 
            .block_offset(2'b00), 
            .byte_offset(2'b00), 
            .rw_mode(1'b0), 
            .store_value(32'd0)
        );

        ////////////////////////////////////////////////////

        set_test_id("-------> LOAD (WITHOUT SW MISSES) (INTO EMPTY) BANK");

        MSHR_Thread_Done = 0; 
        @(posedge tb_clk);

        count = 0; 
        for (int way = 0; way < NUM_WAYS; way++) begin
            for (int set = 0; set < NUM_SETS_PER_BANK; set++) begin
                for (int blk_offset = 0; blk_offset < BLOCK_SIZE; blk_offset++) begin 
                    for (int byte_offset = 0; byte_offset < WORD_SIZE; byte_offset++) begin 
                        MSHR_Thread_Done = 0; 

                        set_mshr(
                            .valid(1'b1), 
                            .uuid(('1)), 
                            .block_addr(addr_t'{ 
                                (count), 
                                (set[BLOCK_INDEX_BIT_LEN-1:0] << BANKS_LEN), 
                                blk_offset[BLOCK_OFF_BIT_LEN-1:0],
                                byte_offset[BYTE_OFF_BIT_LEN-1:0]
                            }), 
                            .write_status(BLOCK_SIZE'('0)), 
                            .write_block(cache_block'('0))
                        );

                        stall_for_ram();

                        MSHR_Thread_Done = 1; 
                        count = count + 1; 
                        @(posedge tb_clk);
                    end
                end 
            end
        end

        set_mshr(
            .valid('0), 
            .uuid('0),
            .block_addr('0), 
            .write_status('0), 
            .write_block('0)
        );

        MSHR_Thread_Done = 0; 
        @(posedge tb_clk);

        monitor_enable = 1'b1; 
        @(posedge tb_clk);
        monitor_enable = 1'b0; 
        @(posedge tb_clk);

        //////////////////////////////////////////////////////

        set_test_id("-------> OVERWRITE (INTO FULL, UNDIRTY) BANK");

        MSHR_Thread_Done = 0; 
        @(posedge tb_clk);

        count = 0; 
        for (int way = 0; way < NUM_WAYS; way++) begin
            for (int set = 0; set < NUM_SETS_PER_BANK; set++) begin
                for (int blk_offset = 0; blk_offset < BLOCK_SIZE; blk_offset++) begin 
                    for (int byte_offset = 0; byte_offset < WORD_SIZE; byte_offset++) begin 
                        SingleCycle_RW_Done = 0; 

                        initiate_read_write(
                            .tag(count), 
                            .index((set[BLOCK_INDEX_BIT_LEN-1:0] << BANKS_LEN)), 
                            .block_offset(blk_offset[BLOCK_OFF_BIT_LEN-1:0]), 
                            .byte_offset(byte_offset[BYTE_OFF_BIT_LEN-1:0]), 
                            .rw_mode(1'b1), 
                            .store_value($urandom_range(0, (1<<CACHE_RW_SIZE - 1)))
                        );

                        SingleCycle_RW_Done = 1; 
                        count = count + 1; 
                        @(posedge tb_clk);
                    end
                end
            end
        end

        set_mshr(
            .valid('0), 
            .uuid('0),
            .block_addr('0), 
            .write_status('0), 
            .write_block('0)
        );

        MSHR_Thread_Done = 0; 
        @(posedge tb_clk);

        monitor_enable = 1'b1; 
        @(posedge tb_clk);
        monitor_enable = 1'b0; 
        @(posedge tb_clk);

        //////////////////////////////////////////////////////

        set_test_id("-------> OVERWRITE (INTO FULL, DIRTY) BANK");

        MSHR_Thread_Done = 0; 
        @(posedge tb_clk);

        count = 0; 
        for (int way = 0; way < NUM_WAYS; way++) begin
            for (int set = 0; set < NUM_SETS_PER_BANK; set++) begin
                for (int blk_offset = 0; blk_offset < BLOCK_SIZE; blk_offset++) begin 
                    for (int byte_offset = 0; byte_offset < WORD_SIZE; byte_offset++) begin 
                        SingleCycle_RW_Done = 0; 

                        initiate_read_write(
                            .tag(count), 
                            .index((set[BLOCK_INDEX_BIT_LEN-1:0] << BANKS_LEN)), 
                            .block_offset(blk_offset[BLOCK_OFF_BIT_LEN-1:0]), 
                            .byte_offset(byte_offset[BYTE_OFF_BIT_LEN-1:0]), 
                            .rw_mode(1'b1), 
                            .store_value($urandom_range(0, (1<<CACHE_RW_SIZE - 1)))
                        );

                        SingleCycle_RW_Done = 1; 
                        count = count + 1; 
                        @(posedge tb_clk);
                    end
                end
            end
        end

        set_mshr(
            .valid('0), 
            .uuid('0),
            .block_addr('0), 
            .write_status('0), 
            .write_block('0)
        );

        MSHR_Thread_Done = 0; 
        @(posedge tb_clk);

        monitor_enable = 1'b1; 
        @(posedge tb_clk);
        monitor_enable = 1'b0; 
        @(posedge tb_clk);

        //////////////////////////////////////////////////////

        set_test_id("-------> LOAD (WITH SW MISSES) (INTO FULL, DIRTY) BANK");

        MSHR_Thread_Done = 0; 
        @(posedge tb_clk);

        count = 0; 
        for (int way = 0; way < NUM_WAYS; way++) begin
            for (int set = 0; set < NUM_SETS_PER_BANK; set++) begin
                write_block = '0; 
                write_status = '0; 
                for (int blk_offset = 0; blk_offset < BLOCK_SIZE; blk_offset++) begin 
                    write_status[blk_offset] = 1'b1; 
                    write_block[blk_offset] = $urandom_range(0, 32'hFFFFFFFF); 

                    for (int byte_offset = 0; byte_offset < WORD_SIZE; byte_offset++) begin 
                        MSHR_Thread_Done = 0; 

                        set_mshr(
                            .valid(1'b1), 
                            .uuid(('1)), 
                            .block_addr(addr_t'{ 
                                (count), 
                                (set[BLOCK_INDEX_BIT_LEN-1:0] << BANKS_LEN), 
                                blk_offset[BLOCK_OFF_BIT_LEN-1:0],
                                byte_offset[BYTE_OFF_BIT_LEN-1:0]
                            }), 
                            .write_status(write_status), 
                            .write_block(write_block)
                        );

                        stall_for_ram();

                        MSHR_Thread_Done = 1; 
                        count = count + 1; 
                        @(posedge tb_clk);
                    end
                end 
            end
        end

        set_mshr(
            .valid('0), 
            .uuid('0),
            .block_addr('0), 
            .write_status('0), 
            .write_block('0)
        );

        MSHR_Thread_Done = 0; 
        @(posedge tb_clk);

        monitor_enable = 1'b1; 
        @(posedge tb_clk);
        monitor_enable = 1'b0; 
        @(posedge tb_clk);

        ///////////////////////////////////////////////////////

        set_test_id("-------> PIPELINED REQUESTS OVERLAP TEST");
        
        set_mshr(
            .valid(1'b1), 
            .uuid(4'hA),
            .block_addr(addr_t'{24'hF00D, 4'h1, 2'b00, 2'b00}), 
            .write_status(4'b1111), 
            .write_block('{32'h11111111, 32'h22222222, 32'h33333333, 32'h44444444})
        );
        
        wait (cache_bank_tb.dut.curr_state == ADDRESS_READ || cache_bank_tb.dut.curr_state == FINISH); 
        
        @(posedge tb_clk);
        tb_mshr_entry = '{valid: 1'b1, uuid: 4'hB, block_addr: addr_t'{24'hBEEF, 4'h1, 2'b00, 2'b00}, write_status: 4'b1111, write_block: '{32'h55555555, 32'h66666666, 32'h77777777, 32'h88888888}};
        
        wait (cache_bank_tb.dut.curr_state == FINISH); 
        wait (cache_bank_tb.dut.curr_state == ADDRESS_READ); 
        
        @(posedge tb_clk);
        tb_mshr_entry = '{valid: 1'b1, uuid: 4'hC, block_addr: addr_t'{24'hCAFE, 4'h1, 2'b00, 2'b00}, write_status: 4'b1111, write_block: '{32'h99999999, 32'hAAAAAAAA, 32'hBBBBBBBB, 32'hCCCCCCCC}};
        
        wait (cache_bank_tb.dut.curr_state == FINISH);
        wait (cache_bank_tb.dut.curr_state == ADDRESS_READ);

        @(posedge tb_clk);
        tb_mshr_entry = '0; 
        wait (cache_bank_tb.dut.curr_state == FINISH);
        wait (cache_bank_tb.dut.curr_state == START);

        @(posedge tb_clk);

        ///////////////////////////////////////////////////////

        set_test_id("-------> FLUSHING");

        tb_halt = 1; 
        wait(tb_flushed);

        monitor_enable = 1'b1; 
        @(posedge tb_clk);
        monitor_enable = 1'b0; 
        @(posedge tb_clk);

        //////////////////////////////////////////////////////

        set_test_id("-------> FINISH");

        $finish;
    end
endprogram