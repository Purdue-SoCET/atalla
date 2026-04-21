`include "s_wb_arbiter_if.vh"
`include "scalar_wb_pkg.vh"
`include "execution_unit_if.sv"
`include "scheduler_pkg.sv"
`include "decode_2_if.vh"
`include "atalla_isa_types.vh"
`include "if_dec1_if.vh"
`include "scpad_pkg.sv"
`include "scheduler_core_if.vh"

import execution_unit_types_pkg::*;
import scalar_wb_pkg::*;
import scheduler_pkg::*;
import atalla_isa_pkg::*;
import scpad_pkg::*;

module scheduler_core #(
    parameter NUM_SCALAR_INSTRS = 4, 
    parameter NUM_VECTOR_INSTRS = 4,
    parameter NUM_SDMA_INSTRS = 4
)
(
    input logic CLK, nRST,
    scheduler_core_if.sc scif,

    //to dcache
    output logic WEN, REN, mem_in_valid,
    output logic [31:0] data_store, data_addr,

    //from dcache
    input logic [31:0] data_load,
    input logic hit, block_status, stall, miss,

    //fetch in
    input logic ihit,
    input instruction_packet_t imemload,
    input logic imemready,
    output logic imemREN,
    output word_t imemaddr,

    //halt
    output logic halt

);

    scheduler_pkg::EXEC_WB_LATCH n_EX_WB_latch, EX_WB_latch;
    execution_unit_types_pkg::in_DEC2_EX_t  [NUM_SCALAR_INSTRS-1:0] n_DEC2_EX_latch, DEC2_EX_latch;
    scheduler_pkg::DEC2_WB_LATCH_PC n_DEC2_EX_PC_latch, DEC2_EX_PC_latch;
    scheduler_pkg::DEC1_DEC2_LATCH n_D1_D2_latch, D1_D2_latch;
    scheduler_pkg::DEC2_EX_VEC_SDMA_LATCH n_D2_EX_vec_sdma_latch, D2_EX_vec_sdma_latch;

    logic n_DEC2_EX_halt_latch, DEC2_EX_halt_latch;
    logic dec1_dec2_latch_ready;

    //interfaces
    s_wb_arbiter_if scalar_wb_if ();
    v_wb_arbiter_if vector_wb_if ();
    execution_unit_if scalar_ex_if ();
    decode_2_if decode_2_if ();
    datapath_cache_if datapath_cache_if ();
    dec1_dec2_if decode_1_if();
    // caches_if caches_if();

    //instantiations
    s_wb_arbiter S_WB_ARBITER(.CLK(CLK), .nRST(nRST), .vif(scalar_wb_if));
    v_wb_arbiter V_WB_ARBITER(.CLK(CLK), .nRST(nRST), .vif(vector_wb_if));
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
            n_D1_D2_latch.vector_instrs = decode_1_if.vector_inst_in;
            n_D1_D2_latch.SDMA_instrs = decode_1_if.scpad_inst_in;
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
    assign decode_2_if.vector_instrs = D1_D2_latch.vector_instrs;
    assign decode_2_if.SDMA_instrs = D1_D2_latch.SDMA_instrs;
    assign decode_2_if.pc_in = D1_D2_latch.pc;
    assign decode_2_if.pc_pred_addr_in = D1_D2_latch.pc_pred_addr;
    assign decode_2_if.predict_taken_in = D1_D2_latch.predict_taken;



    always_comb begin : DEC2_EX
        //continuous assignment for DEC2/EX
        //EX inputs from DEC2
        n_DEC2_EX_halt_latch = 1'b0;
        n_D2_EX_vec_sdma_latch = '0;
        if(decode_2_if.ready && !scalar_ex_if.redirect_valid && !scalar_ex_if.halt_out) begin
            n_D2_EX_vec_sdma_latch.decoded_vector_instrs = decode_2_if.decoded_vector_instrs;
            n_D2_EX_vec_sdma_latch.decoded_SDMA_instrs = decode_2_if.decoded_SDMA_instrs;
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
            n_D2_EX_vec_sdma_latch = '0;
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
    assign decode_2_if.scalar_WB_WEN = EX_WB_latch.s_WEN;
    assign decode_2_if.scalar_WB_wdata = EX_WB_latch.s_data;
    assign decode_2_if.scalar_WB_wsel = EX_WB_latch.s_rd;
    assign decode_2_if.vector_WB_WEN = EX_WB_latch.v_WEN;
    assign decode_2_if.vector_WB_wdata = EX_WB_latch.v_data;
    assign decode_2_if.vector_WB_wsel = EX_WB_latch.v_rd;
    assign decode_2_if.mask_WB_WEN = EX_WB_latch.m_WEN;
    assign decode_2_if.mask_WB_wdata = EX_WB_latch.m_data;
    assign decode_2_if.mask_WB_wsel = EX_WB_latch.m_rd;
    assign decode_2_if.scalar_SDMA_WB_WEN = EX_WB_latch.SDMA_s_WEN;
    assign decode_2_if.scalar_SDMA_WB_wsel = EX_WB_latch.SDMA_s_rd;


    //continuous assignment for EX/WB

    assign vector_wb_if.vector_wb_in = scif.vector_wb_in; //directly from scheduler core interface since it's coming from VC and going to the arbiter without needing to be latched

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
    assign n_EX_WB_latch.s_data = scalar_wb_if.scalar_wb_out.data;
    assign n_EX_WB_latch.s_rd = scalar_wb_if.scalar_wb_out.rd;
    assign n_EX_WB_latch.s_WEN = scalar_wb_if.scalar_wb_out.WEN;
    assign n_EX_WB_latch.v_data = vector_wb_if.vector_wb_out.vdata; 
    assign n_EX_WB_latch.v_rd = vector_wb_if.vector_wb_out.vd; 
    assign n_EX_WB_latch.v_WEN = vector_wb_if.vector_wb_out.WEN; 
    assign n_EX_WB_latch.m_data = vector_wb_if.vector_wb_out.mask_WB_wdata;
    assign n_EX_WB_latch.m_rd = vector_wb_if.vector_wb_out.mask_WB_wsel;
    assign n_EX_WB_latch.m_WEN = vector_wb_if.vector_wb_out.mask_WB_WEN;
    assign n_EX_WB_latch.SDMA_s_rd = scif.SDMA_scalar_rs1s;
    assign n_EX_WB_latch.SDMA_s_WEN = scif.SDMA_scalar_WEN;


    //back to vector core for write bank conflict prevention
    assign scif.vector_if_wb_ready = vector_wb_if.vector_wb_out.vector_if_wb_ready;

    //dcache in/outs
    //from dcache
    assign scalar_ex_if.hit = hit;
    assign scalar_ex_if.data_load = data_load;
    assign scalar_ex_if.block_status = block_status;
    assign scalar_ex_if.stall = stall;
    assign scalar_ex_if.miss = miss;
    //to dcache
    // assign scif.WEN = scalar_ex_if.WEN;
    // assign scif.REN = scalar_ex_if.REN;
    // assign scif.mem_in_valid = scalar_ex_if.mem_in_valid;
    // assign scif.data_store = scalar_ex_if.data_store;
    // assign scif.data_addr = scalar_ex_if.data_addr;
    assign WEN = scalar_ex_if.WEN;
    assign REN = scalar_ex_if.REN;
    assign mem_in_valid = scalar_ex_if.mem_in_valid;
    assign data_store = scalar_ex_if.data_store;
    assign data_addr = scalar_ex_if.data_addr;
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
            D2_EX_vec_sdma_latch <= '0;
            DEC2_EX_PC_latch <= '0;
            DEC2_EX_halt_latch <= '0;
            D1_D2_latch <= '0;
        end else begin
            EX_WB_latch <= n_EX_WB_latch;
            DEC2_EX_latch <= n_DEC2_EX_latch;
            D2_EX_vec_sdma_latch <= n_D2_EX_vec_sdma_latch;
            DEC2_EX_PC_latch <= n_DEC2_EX_PC_latch;
            DEC2_EX_halt_latch <= n_DEC2_EX_halt_latch;
            D1_D2_latch <= n_D1_D2_latch;
        end
    end

    ///VECTOR CORE INTEGRATION (converting output of D2/EX latch to their expected interfaces)
    decoded_vector_instr_t [NUM_VECTOR_INSTRUCTIONS-1:0] dec_vector_instrs;
    decoded_SDMA_instr_t   [NUM_SDMA_INSTRUCTIONS-1:0] dec_SDMA_instrs;

    assign dec_vector_instrs = D2_EX_vec_sdma_latch.decoded_vector_instrs;
    assign dec_SDMA_instrs = D2_EX_vec_sdma_latch.decoded_SDMA_instrs;

    int lane_idx;    // index into lane issue ports

    //Now that it has come out of the latch, need to put vector ops into their structs
    always_comb begin : ASSIGN_VECTOR_SPAD_INSTRS_TO_FUs
        scif.lanes_in = '0;  // clear all lanes
        scif.vlsu_in = '0;   
        scif.gsau_in = '0;    
        scif.scpad_in = '0;   
        lane_idx = 0;  

        // iterate over all decoded vector instructions
        for (int i = 0; i < NUM_VECTOR_INSTRS; i++) begin
            if (dec_vector_instrs[i].valid_in && dec_vector_instrs[i].fu_enable == atalla_isa_pkg::VLSU) begin
                scif.vlsu_in.sched_req[dec_vector_instrs[i].sid].valid = 1'b1;
                scif.vlsu_in.sched_req[dec_vector_instrs[i].sid].write = !(dec_vector_instrs[i].vector_reg_write); //if it's writing to a vec reg that means its a load (!vector_reg_write = vreg.st)
                scif.vlsu_in.sched_req[dec_vector_instrs[i].sid].spad_addr = dec_vector_instrs[i].rs1_data; 
                scif.vlsu_in.sched_req[dec_vector_instrs[i].sid].vdst = dec_vector_instrs[i].vd;
                scif.vlsu_in.sched_req[dec_vector_instrs[i].sid].row_id = dec_vector_instrs[i].rs2_data;
                scif.vlsu_in.sched_req[dec_vector_instrs[i].sid].num_cols = dec_vector_instrs[i].num_cols;

                scif.vlsu_in.vrf_data[dec_vector_instrs[i].sid].valid = 1'b1;
                scif.vlsu_in.vrf_data[dec_vector_instrs[i].sid].data = dec_vector_instrs[i].vs1_data; //vdata1 is source for store, destination for load
            end

            // check if this instruction should go into GSAU
            if (dec_vector_instrs[i].valid_in && dec_vector_instrs[i].fu_enable == atalla_isa_pkg::GSAU)            begin
                scif.gsau_in.valid_in = 1;
                scif.gsau_in.veg_vdata1 = dec_vector_instrs[i].vs1_data;
                scif.gsau_in.veg_vdata2 = dec_vector_instrs[i].vs2_data;
                scif.gsau_in.vd = dec_vector_instrs[i].vd;
                if (dec_vector_instrs[i].op == atalla_isa_pkg::LW_VI) begin
                    scif.gsau_in.weight = 1;
                end else begin
                    scif.gsau_in.weight = 0;
                end
            end

            // check if this instruction should go into LANES
            if (dec_vector_instrs[i].valid_in &&
                dec_vector_instrs[i].fu_enable != atalla_isa_pkg::GSAU &&
                dec_vector_instrs[i].fu_enable != atalla_isa_pkg::VLSU) 
            begin
                // only fill if there is an available lane
                if (lane_idx < vector_pkg::LANE_ISSUE_W) begin
                    scif.lanes_in.lane_issue_ports[lane_idx].input_valid = 1;
                    scif.lanes_in.lane_issue_ports[lane_idx].v1 = dec_vector_instrs[i].vs1_data;
                    
                    if (dec_vector_instrs[i].op2_src == 2'b00) begin //vv
                        scif.lanes_in.lane_issue_ports[lane_idx].v2 = dec_vector_instrs[i].vs2_data;
                    end else if (dec_vector_instrs[i].op2_src == 2'b01) begin //vi
                        scif.lanes_in.lane_issue_ports[lane_idx].v2 = '{32{{8'b0, dec_vector_instrs[i].imm}}};
                    end else if (dec_vector_instrs[i].op2_src == 2'b10) begin  //vs
                        scif.lanes_in.lane_issue_ports[lane_idx].v2 = '{32{dec_vector_instrs[i].rs1_data[15:0]}};
                    end
                    scif.lanes_in.lane_issue_ports[lane_idx].vd = dec_vector_instrs[i].vd;
                    scif.lanes_in.lane_issue_ports[lane_idx].rm = dec_vector_instrs[i].rm;
                    scif.lanes_in.lane_issue_ports[lane_idx].mask = dec_vector_instrs[i].vms_data;

                    // Map fu_enable to fu_t usel
                    unique case (dec_vector_instrs[i].fu_enable)
                        atalla_isa_pkg::MUL: scif.lanes_in.lane_issue_ports[lane_idx].usel = vector_pkg::MUL;
                        atalla_isa_pkg::EXP: scif.lanes_in.lane_issue_ports[lane_idx].usel = vector_pkg::EXP;
                        default:             scif.lanes_in.lane_issue_ports[lane_idx].usel = vector_pkg::VALU;
                    endcase

                    // Map fu_enable to alu_op_t
                    unique case (dec_vector_instrs[i].fu_enable)
                        atalla_isa_pkg::ALU_ADD:  scif.lanes_in.lane_issue_ports[lane_idx].alu_op = vector_pkg::ALU_ADD;
                        atalla_isa_pkg::ALU_SUB:  scif.lanes_in.lane_issue_ports[lane_idx].alu_op = vector_pkg::ALU_SUB;
                        atalla_isa_pkg::ALU_AND:  scif.lanes_in.lane_issue_ports[lane_idx].alu_op = vector_pkg::ALU_AND;
                        atalla_isa_pkg::ALU_OR:   scif.lanes_in.lane_issue_ports[lane_idx].alu_op = vector_pkg::ALU_OR;
                        atalla_isa_pkg::ALU_XOR:  scif.lanes_in.lane_issue_ports[lane_idx].alu_op = vector_pkg::ALU_XOR;
                        atalla_isa_pkg::ALU_MGT:  scif.lanes_in.lane_issue_ports[lane_idx].alu_op = vector_pkg::ALU_MGT;
                        atalla_isa_pkg::ALU_MLT:  scif.lanes_in.lane_issue_ports[lane_idx].alu_op = vector_pkg::ALU_MLT;
                        atalla_isa_pkg::ALU_MEQ:  scif.lanes_in.lane_issue_ports[lane_idx].alu_op = vector_pkg::ALU_MEQ;
                        atalla_isa_pkg::ALU_MNEQ: scif.lanes_in.lane_issue_ports[lane_idx].alu_op = vector_pkg::ALU_MNEQ;
                        atalla_isa_pkg::REDU: begin
                            casez (opcode_t'(dec_vector_instrs[i].op))
                                RSUM_VI: scif.lanes_in.lane_issue_ports[lane_idx].alu_op = vector_pkg::ALU_ADD;
                                RMIN_VI: scif.lanes_in.lane_issue_ports[lane_idx].alu_op = vector_pkg::ALU_MLT;
                                RMAX_VI: scif.lanes_in.lane_issue_ports[lane_idx].alu_op = vector_pkg::ALU_MGT;
                                default: scif.lanes_in.lane_issue_ports[lane_idx].alu_op = vector_pkg::ALU_ADD;
                            endcase
                        end
                        default: scif.lanes_in.lane_issue_ports[lane_idx].alu_op = vector_pkg::ALU_ADD;
                    endcase

                    lane_idx++; // move to next lane
                end
            end
        end

        for (int i = 0; i < NUM_SDMA_INSTRS; i++) begin
            // rs3 to be packed --> {31:30 - Scratchpad ID, 29:25 - num rows, 24:20 - num cols, 19:0 - num cols in full matrix}
            if (dec_SDMA_instrs[i].valid_in) begin
                // sid = dec_SDMA_instrs[i].rs3_data[31:30];
                scif.scpad_in[dec_SDMA_instrs[i].rs3_data[31:30]].valid = 1'b1;
                scif.scpad_in[dec_SDMA_instrs[i].rs3_data[31:30]].write = dec_SDMA_instrs[i].store;
                scif.scpad_in[dec_SDMA_instrs[i].rs3_data[31:30]].spad_addr = dec_SDMA_instrs[i].rs1_rd_data;
                scif.scpad_in[dec_SDMA_instrs[i].rs3_data[31:30]].dram_addr = dec_SDMA_instrs[i].rs2_data;
                scif.scpad_in[dec_SDMA_instrs[i].rs3_data[31:30]].num_rows = dec_SDMA_instrs[i].rs3_data[29:25];
                scif.scpad_in[dec_SDMA_instrs[i].rs3_data[31:30]].num_cols = dec_SDMA_instrs[i].rs3_data[24:20];
                scif.scpad_in[dec_SDMA_instrs[i].rs3_data[31:30]].full_num_cols = dec_SDMA_instrs[i].rs3_data[19:0];
                scif.scpad_in[dec_SDMA_instrs[i].rs3_data[31:30]].scpad_id = dec_SDMA_instrs[i].rs3_data[31:30];

            end
        end
    end

endmodule