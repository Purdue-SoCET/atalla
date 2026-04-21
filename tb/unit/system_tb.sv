`timescale 1ns/1ps
`include "scpad_params.svh"
import scpad_pkg::*;

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

    dram_req_t scpad_0_req;
    dram_req_t scpad_1_req;
    dram_req_t scpad_2_req;
    dram_req_t scpad_3_req;

    dram_res_t scpad_0_res;
    dram_res_t scpad_1_res;
    dram_res_t scpad_2_res;
    dram_res_t scpad_3_res;

    logic dram_scpad_stall [3:0];
    logic scpad_dram_stall [3:0];

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

        //scpad signals
        .dram_scpad_stall(dram_scpad_stall), //dram stalls the scpad
        .scpad_dram_stall(scpad_dram_stall), //scpad stalls the dram

        //to dram
        .scpad_0_req(scpad_0_req),
        .scpad_1_req(scpad_1_req),
        .scpad_2_req(scpad_2_req),
        .scpad_3_req(scpad_3_req),

        //from dram
        .scpad_0_res(scpad_0_res),
        .scpad_1_res(scpad_1_res),
        .scpad_2_res(scpad_2_res),
        .scpad_3_res(scpad_3_res),

        .halt(halt),
        .dp_out_flushed(dcache_flushed)
    );

    sim_ram_rr #(
        .ADDR_WIDTH (ADDR_WIDTH),
        .MEM_BYTES  (MEM_BYTES),
        .INIT_FILE  ("tb/unit/mem_files/sdma_ld.hex"),
        .INIT_IS_HEX(1'b1),
        .DUMP_FILE  ("tb/unit/mem_files/final_mem.hex"),
        .BIG_ENDIAN (1'b0),
        .REVERSE_MASK_MAP (1'b0)
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
        .dc_resp_hit(ram_mem_complete_d),

        // -----------------------------
        // Scratchpad 0
        // -----------------------------
        .sc0_req_valid(scpad_0_req.valid),
        .sc0_req_rw(scpad_0_req.write),       // 0=read, 1=write
        .sc0_req_addr(scpad_0_req.dram_addr),
        .sc0_req_wdata(scpad_0_req.wdata),
        .sc0_req_id(scpad_0_req.id),
        .sc0_req_mask(scpad_0_req.dram_vector_mask),
        .sc0_stall_in(scpad_dram_stall[3]),
        .sc0_resp_rdata(scpad_0_res.rdata),
        .sc0_resp_hit(scpad_0_res.valid),
        .sc0_resp_id(scpad_0_res.id),
        .sc0_resp_rw(scpad_0_res.write),
        //need one slot fo the response mask
        .sc0_stall_out(dram_scpad_stall[3]),

        // -----------------------------
        // Scratchpad 1
        // -----------------------------
        .sc1_req_valid(scpad_1_req.valid),
        .sc1_req_rw(scpad_1_req.write),
        .sc1_req_addr(scpad_1_req.dram_addr),
        .sc1_req_wdata(scpad_1_req.wdata),
        .sc1_req_id(scpad_1_req.id),
        .sc1_req_mask(scpad_1_req.dram_vector_mask),
        .sc1_stall_in(scpad_dram_stall[2]),
        .sc1_resp_rdata(scpad_1_res.rdata),
        .sc1_resp_hit(scpad_1_res.valid),
        .sc1_resp_id(scpad_1_res.id),
        .sc1_resp_rw(scpad_1_res.write),
        //need one slot fo the response mask
        .sc1_stall_out(dram_scpad_stall[2]),

        // -----------------------------
        // Scratchpad 2
        // -----------------------------
        .sc2_req_valid(scpad_2_req.valid),
        .sc2_req_rw(scpad_2_req.write),
        .sc2_req_addr(scpad_2_req.dram_addr),
        .sc2_req_wdata(scpad_2_req.wdata),
        .sc2_req_id(scpad_2_req.id),
        .sc2_req_mask(scpad_2_req.dram_vector_mask),
        .sc2_stall_in(scpad_dram_stall[1]),
        .sc2_resp_rdata(scpad_2_res.rdata),
        .sc2_resp_hit(scpad_2_res.valid),
        .sc2_resp_id(scpad_2_res.id),
        .sc2_resp_rw(scpad_2_res.write),
        //need one slot fo the response mask
        .sc2_stall_out(dram_scpad_stall[1]),

        // -----------------------------
        // Scratchpad 3
        // -----------------------------
        .sc3_req_valid(scpad_3_req.valid),
        .sc3_req_rw(scpad_3_req.write),
        .sc3_req_addr(scpad_3_req.dram_addr),
        .sc3_req_wdata(scpad_3_req.wdata),
        .sc3_req_id(scpad_3_req.id),
        .sc3_req_mask(scpad_3_req.dram_vector_mask),
        .sc3_stall_in(scpad_dram_stall[0]),
        .sc3_resp_rdata(scpad_3_res.rdata),
        .sc3_resp_hit(scpad_3_res.valid),
        .sc3_resp_id(scpad_3_res.id),
        .sc3_resp_rw(scpad_3_res.write),
        //need one slot fo the response mask
        .sc3_stall_out(dram_scpad_stall[0])
    );

    initial begin
        nRST = 1'b0;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        nRST = 1'b1;

        // while(dcache_flushed != 1'b1) begin
        //     @(posedge CLK);
        // end

        repeat(200) @(posedge CLK);

        @(posedge CLK);
        @(posedge CLK);

        $finish;
    end

endmodule