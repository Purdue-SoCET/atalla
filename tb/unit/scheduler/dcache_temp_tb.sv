`timescale 1ns / 10ps
`include "lockup_free_cache.sv"


module dcache_temp_tb;

    parameter PERIOD = 2;
    logic CLK = 0, nRST;
    always #(PERIOD/2) CLK++;
    string casename;

    logic mem_in;
    logic [31:0] mem_in_addr;
    logic mem_in_rw_mode;
    logic [31:0] mem_in_store_value;
    logic dp_in_halt;
    logic [3:0] mem_out_uuid;
    logic stall;
    logic hit;
    logic [31:0] hit_load;
    logic [NUM_BANKS-1:0] block_status;
    logic [NUM_BANKS-1:0][UUID_SIZE-1:0] uuid_block;
    logic dp_out_flushed;
    logic [NUM_BANKS-1:0] ram_mem_REN;
    logic [NUM_BANKS-1:0] ram_mem_WEN;
    logic [NUM_BANKS-1:0][31:0] ram_mem_addr;
    logic [NUM_BANKS-1:0][31:0] ram_mem_store;
    logic [NUM_BANKS-1:0][31:0] ram_mem_data;
    logic [NUM_BANKS-1:0] ram_mem_complete;
    

    lockup_free_cache DUT (
        .CLK(CLK), .nRST(nRST),
        .mem_in(mem_in),
        .mem_in_addr(mem_in_addr),
        .mem_in_rw_mode(mem_in_rw_mode), // 0 = read, 1 = write
        .mem_in_store_value(mem_in_store_value),
        .dp_in_halt(dp_in_halt), 
        .mem_out_uuid(mem_out_uuid),
        .stall(stall),
        .hit(hit),
        .hit_load(hit_load),
        .block_status(block_status),
        .uuid_block(uuid_block),
        .dp_out_flushed(dp_out_flushed),

        // RAM Signals
        .ram_mem_REN(ram_mem_REN),
        .ram_mem_WEN(ram_mem_WEN),
        .ram_mem_addr(ram_mem_addr),
        .ram_mem_store(ram_mem_store),
        .ram_mem_data(ram_mem_data),
        .ram_mem_complete(ram_mem_complete)
    );

    ld_st_unit_if ld_st_if ();
    ld_st_unit LD_ST_DUT (.CLK(CLK), .nRST(nRST), .ld_st_if(ld_st_if));

    assign mem_in = ld_st_if.mem_in_valid;
    assign mem_in_addr = ld_st_if.data_addr;
    assign mem_in_rw_mode = ld_st_if.WEN;
    assign mem_in_store_value = ld_st_if.data_store;
    assign ld_st_if.hit = hit;
    assign ld_st_if.data_load = hit_load;
    assign ld_st_if.block_status = block_status[0] | block_status[1] | block_status[2] | block_status[3];

    initial begin
        nRST = 1'b0;
        ram_mem_data = '0;
        ram_mem_complete = '0;
        dp_in_halt = 1'b0;

        // mem_in = 1'b0;
        // mem_in_addr = 32'b0;
        // mem_in_rw_mode = 1'b0;
        // mem_in_store_value = 32'b0;

        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);

        // nRST = 1'b1;

        // @(posedge CLK);
        // mem_in = 1'b1;
        // mem_in_addr = 32'hC;
        // @(posedge CLK);
        // mem_in = 1'b1;
        // mem_in_addr = 32'h8;
        // @(posedge CLK);
        // mem_in = 1'b0;
        // mem_in_addr = 32'h0;
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // ram_mem_complete[0] = 1'b1;
        // ram_mem_data[0] = 32'hAAAAAAAA;
        // @(posedge CLK);
        // ram_mem_data[0] = 32'hBBBBBBBB;
        // @(posedge CLK);
        // ram_mem_data[0] = 32'hCCCCCCCC;
        // @(posedge CLK);
        // ram_mem_data[0] = 32'hDDDDDDDD;
        // @(posedge CLK);
        // ram_mem_complete[0] = 1'b0;
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // ram_mem_complete[0] = 1'b1;
        // ram_mem_data[0] = 32'hAAAAAAAA;
        // @(posedge CLK);
        // ram_mem_data[0] = 32'hBBBBBBBB;
        // @(posedge CLK);
        // ram_mem_data[0] = 32'hCCCCCCCC;
        // @(posedge CLK);
        // ram_mem_data[0] = 32'hDDDDDDDD;
        // @(posedge CLK);
        // ram_mem_complete[0] = 1'b0;
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // mem_in = 1'b1;
        // mem_in_addr = 32'd20;
        // @(posedge CLK);
        // mem_in = 1'b0;
        // mem_in_addr = 32'h0;
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // ram_mem_complete[1] = 1'b1;
        // ram_mem_data[1] = 32'hAAAAAAAA;
        // @(posedge CLK);
        // ram_mem_data[1] = 32'hBBBBBBBB;
        // @(posedge CLK);
        // ram_mem_data[1] = 32'hCCCCCCCC;
        // @(posedge CLK);
        // ram_mem_data[1] = 32'hDDDDDDDD;
        // @(posedge CLK);
        // ram_mem_complete[1] = 1'b0;
        // @(posedge CLK);
        // mem_in = 1'b1;
        // mem_in_addr = 32'd20;
        // @(posedge CLK);
        // mem_in = 1'b0;
        // mem_in_addr = 32'h0;
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // mem_in = 1'b1;
        // mem_in_addr = 32'h18;
        // @(posedge CLK);
        // mem_in = 1'b1;
        // mem_in_addr = 32'h1c;
        // @(posedge CLK);
        // mem_in = 1'b1;
        // mem_in_addr = 32'h14;
        // @(posedge CLK);
        // mem_in = 1'b1;
        // mem_in_addr = 32'h10;
        // @(posedge CLK);
        // mem_in = 1'b1;
        // mem_in_addr = 32'h8;
        // @(posedge CLK);
        // mem_in_rw_mode = 1'b1;
        // mem_in_store_value = 32'd69;
        // mem_in_addr = 32'h8;
        // @(posedge CLK);
        // mem_in = 1'b0;
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);
        // @(posedge CLK);

        ld_st_if.addr = 32'b0;
        ld_st_if.data_in = 32'b0;
        ld_st_if.rdIn = 8'b0;
        ld_st_if.halfWord = 1'b0;
        ld_st_if.valid_in = 1'b0;
        ld_st_if.scalar_type_enable = alu_valid;

        ld_st_if.ready_out = 1'b0;

        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);

        nRST = 1'b1;
    
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        ld_st_if.valid_in = 1'b1;
        ld_st_if.scalar_type_enable = ld_valid;
        ld_st_if.rdIn = 8'd7;
        ld_st_if.addr = 32'hc;
        @(posedge CLK);
        ld_st_if.valid_in = 1'b0;
        ld_st_if.scalar_type_enable = alu_valid;
        ld_st_if.rdIn = 8'b0;
        ld_st_if.addr = 32'b0;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        ram_mem_complete[0] = 1'b1;
        ram_mem_data[0] = 32'hAAAAAAAA;
        @(posedge CLK);
        ram_mem_data[0] = 32'hBBBBBBBB;
        @(posedge CLK);
        ram_mem_data[0] = 32'hCCCCCCCC;
        @(posedge CLK);
        ram_mem_data[0] = 32'hDDDDDDDD;
        @(posedge CLK);
        ram_mem_complete[0] = 1'b0;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK); 
        ld_st_if.ready_out = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK); 
        ld_st_if.valid_in = 1'b1;
        ld_st_if.scalar_type_enable = ld_valid;
        ld_st_if.rdIn = 8'd7;
        ld_st_if.addr = 32'h8;
        @(posedge CLK);
        ld_st_if.valid_in = 1'b1;
        ld_st_if.scalar_type_enable = ld_valid;
        ld_st_if.rdIn = 8'd9;
        ld_st_if.addr = 32'h4;
        @(posedge CLK);
        ld_st_if.valid_in = 1'b1;
        ld_st_if.scalar_type_enable = st_valid;
        ld_st_if.rdIn = 8'd9;
        ld_st_if.addr = 32'h4;
        ld_st_if.data_in = 32'hDEADBEEF;
        @(posedge CLK);
        ld_st_if.ready_out = 1'b0;
        ld_st_if.valid_in = 1'b1;
        ld_st_if.scalar_type_enable = st_valid;
        ld_st_if.rdIn = 8'd9;
        ld_st_if.addr = 32'h8;
        ld_st_if.data_in = 32'hDEADBEEF;
        @(posedge CLK);
        ld_st_if.valid_in = 1'b1;
        ld_st_if.scalar_type_enable = ld_valid;
        ld_st_if.rdIn = 8'd9;
        ld_st_if.addr = 32'h0;
        @(posedge CLK); 
        ld_st_if.valid_in = 1'b0;
        ld_st_if.scalar_type_enable = ld_valid;
        ld_st_if.rdIn = 8'd0;
        ld_st_if.addr = 32'h0;
        @(posedge CLK);
        @(posedge CLK);
        ld_st_if.ready_out = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        ld_st_if.ready_out = 1'b0;
        ld_st_if.valid_in = 1'b1;
        ld_st_if.scalar_type_enable = st_valid;
        ld_st_if.rdIn = 8'd9;
        ld_st_if.addr = 32'd20;
        ld_st_if.data_in = 32'hDEADBEEF;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        ram_mem_complete[1] = 1'b1;
        ram_mem_data[1] = 32'hAAAAAAAA;
        @(posedge CLK);
        ram_mem_data[1] = 32'hBBBBBBBB;
        @(posedge CLK);
        ram_mem_data[1] = 32'hCCCCCCCC;
        @(posedge CLK);
        ram_mem_data[1] = 32'hDDDDDDDD;
        @(posedge CLK);
        ram_mem_complete[1] = 1'b0;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK); 
        ld_st_if.ready_out = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);



        $display("DONE");
        $finish;
    end


endmodule