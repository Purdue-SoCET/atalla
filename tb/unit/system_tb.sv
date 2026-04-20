module system_tb;

    localparam int ADDR_WIDTH = 32;
    localparam int MEM_BYTES  = 256;

    parameter PERIOD = 2;
    logic CLK = 0, nRST;
    always #(PERIOD/2) CLK = ~CLK;

    logic ram_mem_REN_d;
    logic ram_mem_WEN_d;
    logic [31:0] ram_mem_addr_d;
    logic [63:0] ram_mem_store_d;
    logic [63:0] ram_mem_data_d;
    logic ram_mem_complete_d;

    logic ram_mem_valid_i;
    logic ram_mem_WEN_i;
    logic [31:0] ram_mem_addr_i;
    logic [63:0] ram_mem_store_i;
    logic [63:0] ram_mem_data_i;
    logic ram_mem_complete_i;

    logic halt;
    logic dcache_flushed;

    system ATALLA
    (
        .CLK(CLK), .nRST(nRST),
        //from dcache
        .ram_mem_REN_d(ram_mem_REN_d),
        .ram_mem_WEN_d(ram_mem_WEN_d),
        .ram_mem_addr_d(ram_mem_addr_d),
        .ram_mem_store_d(ram_mem_store_d),
        //to dcache
        .ram_mem_data_d(ram_mem_data_d),
        .ram_mem_complete_d(ram_mem_complete_d),

        //from icache
        .mem_req_valid_i(ram_mem_valid_i),
        .mem_req_addr_i(ram_mem_addr_i),
        .mem_resp_rdata_i(ram_mem_data_i),
        .mem_resp_hit_i(ram_mem_complete_i),

        .halt(halt),
        .dp_out_flushed(dcache_flushed)
    );

    sim_ram_rr #(
        .ADDR_WIDTH (ADDR_WIDTH),
        .MEM_BYTES  (MEM_BYTES),
        .INIT_FILE  ("tb/unit/mem_files/recp_bf.hex"),
        .INIT_IS_HEX(1'b1),
        .DUMP_FILE  ("tb/unit/mem_files/final_mem.hex"),
        .BIG_ENDIAN (1'b0)
    ) RAM_SIM (
        .clk(CLK), .rst_n(nRST),
        // I-cache
        .ic_req_valid(ram_mem_valid_i),
        .ic_req_we(1'b0),
        .ic_req_addr(ram_mem_addr_i),
        .ic_req_wdata(64'b0),
        .ic_resp_rdata(ram_mem_data_i),
        .ic_resp_hit(ram_mem_complete_i),
        // D-cache
        .dc_req_valid(ram_mem_WEN_d | ram_mem_REN_d),
        .dc_req_we(ram_mem_WEN_d),
        .dc_req_addr(ram_mem_addr_d),
        .dc_req_wdata(ram_mem_store_d),
        .dc_resp_rdata(ram_mem_data_d),
        .dc_resp_hit(ram_mem_complete_d)
    );

    initial begin
        nRST = 1'b0;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        nRST = 1'b1;

        while(dcache_flushed != 1'b1) begin
            @(posedge CLK);
        end

        @(posedge CLK);
        @(posedge CLK);

        $finish;
    end

endmodule