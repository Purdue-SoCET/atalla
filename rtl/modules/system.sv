`include "atalla_isa_types.vh"
`include "vector_pkg.vh"
`include "vector_if.vh"
`include "gsau_control_unit_if.vh"
`include "scheduler_core_if.vh"
`include "scpad_params.svh"

import scheduler_pkg::*;
import atalla_isa_pkg::*;
import vector_pkg::*;
import scpad_pkg::*;
import inst_parser_dpi_pkg::*;

module system #()
(
    input logic CLK, nRST,
    //from dcache
    output logic ram_mem_REN_d,
    output logic ram_mem_WEN_d,
    output logic [31:0] ram_mem_addr_d,
    output logic [63:0] ram_mem_store_d,
    //to dcache
    input logic [63:0] ram_mem_data_d,
    input logic ram_mem_complete_d,

    //from icache
    output logic         mem_req_valid_i,
    output logic [31:0]  mem_req_addr_i,
    input  logic [63:0]  mem_resp_rdata_i,
    input  logic         mem_resp_hit_i,

    //scpad signals
    input logic dram_scpad_stall [3:0], //dram stalls the scpad
    output logic scpad_dram_stall [3:0], //scpad stalls the dram

    //to dram
    output dram_req_t scpad_0_req,
    output dram_req_t scpad_1_req,
    output dram_req_t scpad_2_req,
    output dram_req_t scpad_3_req,

    //from dram
    input dram_res_t scpad_0_res,
    input dram_res_t scpad_1_res,
    input dram_res_t scpad_2_res,
    input dram_res_t scpad_3_res,


    output logic halt,
    output logic dp_out_flushed
);

    scheduler_core_if scif ();
    vector_if vif();
    gsau_control_unit_if gsauif();
    scpad_if sif(CLK, nRST);

    logic mem_in;
    logic [31:0] mem_in_addr;
    logic mem_in_rw_mode;
    logic [31:0] mem_in_store_value;
    logic [3:0] mem_out_uuid;
    logic stall;
    logic miss;
    logic hit;
    logic [31:0] hit_load;
    logic block_status;
    logic uuid_block;

    logic ihit;
    instruction_packet_t imemload;
    logic imemREN;
    word_t imemaddr;

    assign vif.lanes_in = scif.lanes_in;
    assign vif.vlsu_in = scif.vlsu_in;
    assign vif.gsau_in = scif.gsau_in;
    assign sif.sched_req = scif.scpad_in;

    //READY SIGNALS
    assign scif.vector_unit_ready_signals = vif.unit_ready_signals;
    assign scif.scpad_busy = sif.sched_stall;

    //WB
    assign vif.wb_ready_signals = scif.vector_if_wb_ready;
    assign scif.vector_wb_in.vector_if_lanes_out = vif.lanes_out;
    assign scif.vector_wb_in.vector_if_vlsu_out = vif.vlsu_out;
    assign scif.vector_wb_in.vector_if_gsau_out = vif.gsau_out;
    assign scif.vector_wb_in.mvvOrMvs = vif.lanes_out.result_collectors[0].mop_out;

    //clear sdma dest reg in dependency tracker
    assign scif.SDMA_scalar_WEN[0] = sif.sdma_done[0];
    assign scif.SDMA_scalar_WEN[1] = sif.sdma_done[1];
    assign scif.SDMA_scalar_WEN[2] = sif.sdma_done[2];
    assign scif.SDMA_scalar_WEN[3] = sif.sdma_done[3];
    assign scif.SDMA_scalar_rs1s[0] = sif.sdma_done_req[0].rd;
    assign scif.SDMA_scalar_rs1s[1] = sif.sdma_done_req[1].rd;
    assign scif.SDMA_scalar_rs1s[2] = sif.sdma_done_req[2].rd;
    assign scif.SDMA_scalar_rs1s[3] = sif.sdma_done_req[3].rd;

    //dram to scpad
    assign sif.dram_be_stall = dram_scpad_stall;
    assign scpad_dram_stall = sif.be_dram_stall;

    assign scpad_0_req = sif.be_dram_req[0];
    assign scpad_1_req = sif.be_dram_req[1];
    assign scpad_2_req = sif.be_dram_req[2];
    assign scpad_3_req = sif.be_dram_req[3];

    assign sif.dram_be_res[0] = scpad_0_res;
    assign sif.dram_be_res[1] = scpad_1_res;
    assign sif.dram_be_res[2] = scpad_2_res;
    assign sif.dram_be_res[3] = scpad_3_res;


    scheduler_core CORE(
        .CLK(CLK), .nRST(nRST), .scif(scif),
        //dcache
        .WEN(mem_in_rw_mode), .REN(),
        .mem_in_valid(mem_in),
        .data_store(mem_in_store_value), 
        .data_addr(mem_in_addr),
        .data_load(hit_load),
        .hit(hit),
        .block_status(block_status),
        .stall(stall),
        .miss(miss),
        //icache
        .ihit(ihit),
        .imemload(imemload),
        .imemready(imemready),
        .imemREN(imemREN),
        .imemaddr(imemaddr),
        //stuff
        .halt(halt)
    );

    vector_datapath vec_datapath (
        .CLK    (CLK),
        .nRST   (nRST),
        .vif    (vif),
        .sif    (sif),
        .gsauif (gsauif)
    );

    scratchpad sp_inst (
        .sif(sif)
    );

    sysarr_MEISSA_top sa_inst (
        .clk    (CLK),
        .nRST   (nRST),
        .gsau_if(gsauif)
    );

    perf_monitor monitor (
        .CLK(CLK),
        .nRST(nRST),
        .sif(sif),
        .gsauif(gsauif),
        .vif(vif)
    );

    lockup_free_cache DCACHE (
        .CLK(CLK), .nRST(nRST),
        .mem_in(mem_in),
        .mem_in_addr(mem_in_addr),
        .mem_in_rw_mode(mem_in_rw_mode), // 0 = read, 1 = write
        .mem_in_store_value(mem_in_store_value),
        .dp_in_halt(halt), 
        .mem_out_uuid(mem_out_uuid),
        .stall(stall),
        .miss(miss),
        .hit(hit),
        .hit_load(hit_load),
        .block_status(block_status),
        .uuid_block(uuid_block),
        .dp_out_flushed(dp_out_flushed),

        // RAM Signals
        .ram_mem_REN(ram_mem_REN_d),
        .ram_mem_WEN(ram_mem_WEN_d),
        .ram_mem_addr(ram_mem_addr_d),
        .ram_mem_store(ram_mem_store_d),
        .ram_mem_data(ram_mem_data_d),
        .ram_mem_complete(ram_mem_complete_d)
    );

    icache ICACHE(
        .CLK(CLK), .nRST(nRST), .halt(halt),
        //to/from scheduler (fetch)
        .imemaddr(imemaddr),
        .imemREN(imemREN),
        .ihit(ihit),
        .imemready(imemready),
        .imemload(imemload),
        //to/from memory
        .iwait(!mem_resp_hit_i),
        .iload(mem_resp_rdata_i),
        .iREN(mem_req_valid_i),
        .iaddr(mem_req_addr_i)
    );


endmodule