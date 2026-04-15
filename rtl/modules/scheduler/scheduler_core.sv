`include "s_wb_arbiter_if.vh"
`include "scalar_wb_pkg.vh"
`include "execution_unit_if.sv"
`include "scheduler_pkg.sv"
`include "decode_2_if.vh"
`include "atalla_isa_types.vh"
`include "if_dec1_if.vh"

import execution_unit_types_pkg::*;
import scalar_wb_pkg::*;
import scheduler_pkg::*;
import atalla_isa_pkg::*;

module scheduler_core #(
    parameter NUM_SCALAR_INSTRS = 4
)
(
    input logic CLK, nRST,

    //to dcache
    output logic WEN, REN, mem_in_valid,
    output logic [31:0] data_store, data_addr,

    //from dcache
    input logic [31:0] data_load,
    input logic hit, block_status, stall, miss,

    //dec2 in
    // input instr_t [3:0] scalar_instrs,
    // input logic predict_taken_in,
    // input word_t pc_in, pc_pred_addr_in,
    // output logic ready

    //fetch in
    input logic ihit,
    input instruction_packet_t imemload,
    input logic imemready,
    output logic imemREN,
    output word_t imemaddr,

    //ready (idk if we need this)
    output logic ready,

    //halt
    output logic halt

);

    scheduler_pkg::EXEC_WB_LATCH n_EX_WB_latch, EX_WB_latch;
    execution_unit_types_pkg::in_DEC2_EX_t  [NUM_SCALAR_INSTRS-1:0] n_DEC2_EX_latch, DEC2_EX_latch;
    scheduler_pkg::DEC2_WB_LATCH_PC n_DEC2_EX_PC_latch, DEC2_EX_PC_latch;
    scheduler_pkg::DEC1_DEC2_LATCH n_D1_D2_latch, D1_D2_latch;

    logic n_DEC2_EX_halt_latch, DEC2_EX_halt_latch;
    logic dec1_dec2_latch_ready;

    //interfaces
    s_wb_arbiter_if scalar_wb_if ();
    execution_unit_if scalar_ex_if ();
    decode_2_if decode_2_if ();
    datapath_cache_if datapath_cache_if ();
    dec1_dec2_if decode_1_if();
    // caches_if caches_if();

    //instantiations
    //icache ICACHE(.CLK(CLK), .nRST(nRST), .dcif(datapath_cache_if), .cif(caches_if));
    s_wb_arbiter S_WB_ARBITER(.CLK(CLK), .nRST(nRST), .vif(scalar_wb_if));
    execute_stage S_EXECUTE(.clk(CLK), .nRST(nRST), .ex_if(scalar_ex_if));
    decode_2 S_V_DECODE_2(.CLK(CLK), .nRST(nRST), .d2if(decode_2_if));
    fetch_decode1 S_FETCH_DECODE_1 (.clk(CLK), .rst_n(nRST), .flush(scalar_ex_if.redirect_valid), 
                                    .ready(dec1_dec2_latch_ready), .pc_branch(scalar_ex_if.redirect_target), .halt(scalar_ex_if.halt_out),
                                    .btb_update_en(scalar_ex_if.redirect_valid), .btb_pc_update(scalar_ex_if.pc_out),
                                    .btb_true_target(scalar_ex_if.redirect_target), .dc_if(datapath_cache_if),
                                    .dec12_if(decode_1_if));



    //DEC1 outputs to latch
    always_comb begin
        if(scalar_ex_if.redirect_valid || scalar_ex_if.halt_out) begin
            n_D1_D2_latch.scalar_instrs = NOP_PACKET;
        end
        else if(dec1_dec2_latch_ready) begin
            n_D1_D2_latch.scalar_instrs = decode_1_if.scalar_inst_in;
            n_D1_D2_latch.pc = decode_1_if.pc_in;
            n_D1_D2_latch.predict_taken = decode_1_if.predict_taken_in;
            n_D1_D2_latch.pc_pred_addr = decode_1_if.pc_pred_addr_in;
            n_D1_D2_latch.valid = decode_1_if.valid_in;
        end else begin
            n_D1_D2_latch = D1_D2_latch;
        end
    end

    assign dec1_dec2_latch_ready = decode_2_if.ready || !D1_D2_latch.valid;

    //DEC2 inputs form D1_D2 latch
    assign decode_2_if.scalar_instrs = D1_D2_latch.scalar_instrs;
    assign decode_2_if.pc_in = D1_D2_latch.pc;
    assign decode_2_if.pc_pred_addr_in = D1_D2_latch.pc_pred_addr;
    assign decode_2_if.predict_taken_in = D1_D2_latch.predict_taken;



    always_comb begin : DEC2_EX
        //continuous assignment for DEC2/EX
        //EX inputs from DEC2
        n_DEC2_EX_halt_latch = 1'b0;
        if(decode_2_if.ready && !scalar_ex_if.redirect_valid && !scalar_ex_if.halt_out) begin
            for(int i = 0; i < NUM_SCALAR_INSTRS; i++) begin
                n_DEC2_EX_latch[i].scalar_type_enable = decode_2_if.decoded_scalar_instrs[i].fu_enable;
                n_DEC2_EX_latch[i].valid_in           = decode_2_if.decoded_scalar_instrs[i].valid_in;
                n_DEC2_EX_latch[i].imm_src            = decode_2_if.decoded_scalar_instrs[i].imm_src;
                n_DEC2_EX_latch[i].halfWord           = decode_2_if.decoded_scalar_instrs[i].halfword;
                n_DEC2_EX_latch[i].imm                = decode_2_if.decoded_scalar_instrs[i].imm;
                n_DEC2_EX_latch[i].incr7              = decode_2_if.decoded_scalar_instrs[i].incr7;
                n_DEC2_EX_latch[i].op                 = decode_2_if.decoded_scalar_instrs[i].op;
                n_DEC2_EX_latch[i].rs1_idx            = decode_2_if.decoded_scalar_instrs[i].rs1;
                n_DEC2_EX_latch[i].rs1_value          = decode_2_if.decoded_scalar_instrs[i].r1_data;
                n_DEC2_EX_latch[i].rs2_value          = decode_2_if.decoded_scalar_instrs[i].r2_data;
                n_DEC2_EX_latch[i].rdIn               = decode_2_if.decoded_scalar_instrs[i].rdIn;
            end
            n_DEC2_EX_PC_latch.pc                  = decode_2_if.pc_out;
            n_DEC2_EX_PC_latch.pc_pred_addr_out    = decode_2_if.pc_pred_addr_out;
            n_DEC2_EX_PC_latch.predict_taken_out   = decode_2_if.predict_taken_out;

            n_DEC2_EX_halt_latch = decode_2_if.decoded_scalar_instrs[0].halt || decode_2_if.decoded_scalar_instrs[1].halt || decode_2_if.decoded_scalar_instrs[2].halt || decode_2_if.decoded_scalar_instrs[3].halt;
        end else begin
            for(int i = 0; i < NUM_SCALAR_INSTRS; i++) begin
              n_DEC2_EX_latch[i] = '0;
              n_DEC2_EX_latch[i].op = 7'b0110001;
            end
            n_DEC2_EX_PC_latch = '0;
        end
        //EX inputs from DEC2
        scalar_ex_if.DEC2_inputs = DEC2_EX_latch;

        scalar_ex_if.halt = DEC2_EX_halt_latch;
        
        scalar_ex_if.pc = DEC2_EX_PC_latch.pc;
        scalar_ex_if.pc_pred_addr_out = DEC2_EX_PC_latch.pc_pred_addr_out;
        scalar_ex_if.predict_taken_out = DEC2_EX_PC_latch.predict_taken_out;
    end

    



    //DEC2 inputs from EX
    assign decode_2_if.ready_DEC2_ex1 = scalar_ex_if.ready_DEC2_ex1;
    assign decode_2_if.ready_DEC2_ex2 = scalar_ex_if.ready_DEC2_ex2;
    assign decode_2_if.ready_DEC2_ex3 = scalar_ex_if.ready_DEC2_ex3;
    assign decode_2_if.ready_DEC2_ex4 = scalar_ex_if.ready_DEC2_ex4;
    assign decode_2_if.ready_DEC2_ex5 = scalar_ex_if.ready_DEC2_ex5;

    //Dec2 inputs from WB
    assign decode_2_if.scalar_WB_WEN = EX_WB_latch.WEN;
    assign decode_2_if.scalar_WB_wdata = EX_WB_latch.data;
    assign decode_2_if.scalar_WB_wsel = EX_WB_latch.rd;

    //continuous assignment for EX/WB
    //ld/st unit
    //ex outputs
    assign scalar_wb_if.scalar_wb_in.data[0] = scalar_ex_if.ex5.data_out;
    assign scalar_wb_if.scalar_wb_in.rd[0] = scalar_ex_if.ex5.rdOut;
    assign scalar_wb_if.scalar_wb_in.valid[0] = scalar_ex_if.ex5.valid_out;
    //ex inputs
    assign scalar_ex_if.ready_WB_ex5 = scalar_wb_if.scalar_wb_out.ready[0];
    //control/alu unit
    //ex outputs
    assign scalar_wb_if.scalar_wb_in.data[1] = scalar_ex_if.ex1.data_out;
    assign scalar_wb_if.scalar_wb_in.rd[1] = scalar_ex_if.ex1.rdOut;
    assign scalar_wb_if.scalar_wb_in.valid[1] = scalar_ex_if.ex1.valid_out;
    //ex inputs
    assign scalar_ex_if.ready_WB_ex1 = scalar_wb_if.scalar_wb_out.ready[1];
    //scalar mult unit
    //ex outputs
    assign scalar_wb_if.scalar_wb_in.data[2] = scalar_ex_if.ex4.data_out;
    assign scalar_wb_if.scalar_wb_in.rd[2] = scalar_ex_if.ex4.rdOut;
    assign scalar_wb_if.scalar_wb_in.valid[2] = scalar_ex_if.ex4.valid_out;
    //ex inputs
    assign scalar_ex_if.ready_WB_ex4 = scalar_wb_if.scalar_wb_out.ready[2];
    //BF math unit unit
    //ex outputs
    assign scalar_wb_if.scalar_wb_in.data[3] = scalar_ex_if.ex3.data_out;
    assign scalar_wb_if.scalar_wb_in.rd[3] = scalar_ex_if.ex3.rdOut;
    assign scalar_wb_if.scalar_wb_in.valid[3] = scalar_ex_if.ex3.valid_out;
    //ex inputs
    assign scalar_ex_if.ready_WB_ex3 = scalar_wb_if.scalar_wb_out.ready[3];
    //Wacky unit unit
    //ex outputsdata
    assign scalar_wb_if.scalar_wb_in.data[4] = scalar_ex_if.ex2.data_out;
    assign scalar_wb_if.scalar_wb_in.rd[4] = scalar_ex_if.ex2.rdOut;
    assign scalar_wb_if.scalar_wb_in.valid[4] = scalar_ex_if.ex2.valid_out;
    //ex inputs
    assign scalar_ex_if.ready_WB_ex2 = scalar_wb_if.scalar_wb_out.ready[4];

    //continuous assignment for WB arbiter latch
    assign n_EX_WB_latch.data = scalar_wb_if.scalar_wb_out.data;
    assign n_EX_WB_latch.rd = scalar_wb_if.scalar_wb_out.rd;
    assign n_EX_WB_latch.WEN = scalar_wb_if.scalar_wb_out.WEN;

    //dcache in/outs
    //from dcache
    assign scalar_ex_if.hit = hit;
    assign scalar_ex_if.data_load = data_load;
    assign scalar_ex_if.block_status = block_status;
    assign scalar_ex_if.stall = stall;
    assign scalar_ex_if.miss = miss;
    //to dcache
    assign WEN = scalar_ex_if.WEN;
    assign REN = scalar_ex_if.REN;
    assign mem_in_valid = scalar_ex_if.mem_in_valid;
    assign data_store = scalar_ex_if.data_store;
    assign data_addr = scalar_ex_if.data_addr;
    // assign decode_2_if.scalar_instrs = scalar_instrs;
    // assign decode_2_if.predict_taken_in = predict_taken_in;
    // assign decode_2_if.pc_pred_addr_in = pc_pred_addr_in;
    // assign decode_2_if.pc_in = pc_in;
    assign ready = decode_2_if.ready;

    assign datapath_cache_if.ihit = ihit;
    assign datapath_cache_if.imemload = imemload;
    assign datapath_cache_if.imemready = imemready;
    assign imemaddr = datapath_cache_if.imemaddr;
    assign imemREN = datapath_cache_if.imemREN;
    // assign caches_if.iload = iload;
    // assign caches_if.iwait = iwait;

    assign halt = scalar_ex_if.halt_out;

    always_ff @( posedge CLK, negedge nRST ) begin : EX_WB_LATCH
        if(!nRST) begin
            EX_WB_latch <= '0;
            DEC2_EX_latch <= '0;
            DEC2_EX_PC_latch <= '0;
            DEC2_EX_halt_latch <= '0;
            D1_D2_latch <= '0;
        end else begin
            EX_WB_latch <= n_EX_WB_latch;
            DEC2_EX_latch <= n_DEC2_EX_latch;
            DEC2_EX_PC_latch <= n_DEC2_EX_PC_latch;
            DEC2_EX_halt_latch <= n_DEC2_EX_halt_latch;
            D1_D2_latch <= n_D1_D2_latch;
        end
    end


endmodule