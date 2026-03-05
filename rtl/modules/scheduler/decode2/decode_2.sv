`include "decode_2_if.vh"
// `include "reg_file_if.vh"
// `include "dummy_regfile_if.vh"
`include "reg_file_if.sv"
`include "atalla_isa_types.vh"
`include "dependency_checker_if.vh"
`include "source_reg_allocator_if.vh"
`include "scalar_control_unit_if.vh"

module decode_2 
    import atalla_isa_pkg::*;
#(
    parameter NUM_SCALAR_INSTRS    = 4,
    parameter NUM_VECTOR_INSTRS    = 4,
    parameter NUM_SDMA_INSTRS    = 2,
    parameter NUM_INSTRUCTIONS = 4,
    parameter READ_PORTS       = 4
) (
  input logic CLK, nRST,
  decode_2_if.dec d2if
);

//just using scalar stuff for now

scalar_control_unit_if scif();
// vector_control_unit_if vcif();
// sdma_control_unit_if sdmacif();
// reg_file_if srfif ();
// dummy_regfile_if srfif (); // TODO currently using the dummy reg file
reg_file_if srfif();

// reg_file_if #(.DATA_WIDTH(16), .NUM_ELEMENTS(32)) vrfif ();
// reg_file_if #(.NUM_REGS(16), .NUM_BANKS(2), .READ_PORTS(2), .WRITE_PORTS(2)) mrfif ();
dependency_checker_if dcif();
source_reg_allocator_if scalarsraif ();
source_reg_allocator_if saif_temp ();

scalar_control_unit scu1(CLK, scif);
// vector_control_unit vcu1(CLK, nRST, vcif);
// sdma_control_unit sdmacu1(CLK, nRST, sdmacif);
reg_file srf1(CLK, nRST, srfif);

// reg_file vrf1(CLK, nRST, vrfif);
// reg_file mrf1(CLK, nRST, mrfif);
dependency_checker dc1 (CLK, nRST, dcif);
source_reg_allocator scalarsra1 (scalarsraif);

source_reg_allocator_minimized pre_src_allocator (saif_temp);

word_t pc_nlatch, pc_latch, pc_pred_addr_nlatch, pc_pred_addr_latch;
logic  predict_taken_nlatch, predict_taken_latch;
decoded_scalar_instr_t [NUM_INSTRUCTIONS-1:0] decoded_scalar_instrs_nlatch, decoded_scalar_instrs_latch;
logic [READ_PORTS-1:0] REN_nlatch, REN_latch;
logic [READ_PORTS-1:0][SCALAR_REG_W-1:0] rsel_nlatch, rsel_latch;


//pass through signals 
//should all be latched
assign d2if.pc_out           = pc_latch;
assign d2if.pc_pred_addr_out = pc_pred_addr_latch;
assign d2if.predict_taken_out = predict_taken_latch;

//dont latch
assign scif.scalar_instrs = d2if.scalar_instrs;
assign d2if.decoded_scalar_instrs = scalarsraif.instrs_out;

//connecting to soruce reg allocator
//latch
assign scalarsraif.instrs_in = decoded_scalar_instrs_latch;

//dont latch
assign scalarsraif.rdata = srfif.opbuff_vreg; //data read from reg file

//dont latch
assign saif_temp.instrs_in = scif.decoded_scalar_instrs;

//dont latch
assign srfif.REN = scalarsraif.REN;
assign srfif.vs = scalarsraif.rsel;
assign srfif.dependencies_ready = dcif.dependencies_ready;
assign srfif.accomplished = d2if.ready;

//comes from WB dont latch
assign srfif.WEN = d2if.scalar_WB_WEN;
assign srfif.vd = d2if.scalar_WB_wsel;
assign srfif.vdata = d2if.scalar_WB_wdata;

//from WB dont latch
assign dcif.scalar_WB_wsel = d2if.scalar_WB_wsel;
assign dcif.scalar_WB_WEN = d2if.scalar_WB_WEN;
assign dcif.scalar_SDMA_wsel = d2if.scalar_SDMA_wsel;
assign dcif.scalar_SDMA_WEN = d2if.scalar_SDMA_WEN;

// Check execute signals for structural hazards (scalar)
scalar_fu_enable_t [NUM_SCALAR_INSTRS-1:0] fu_enables_nlatch, fu_enables_latch;
logic [NUM_SCALAR_INSTRS-1:0] reg_writes_nlatch, reg_writes_latch;
logic [7:0][NUM_SCALAR_INSTRS-1:0] rdIns_nlatch, rdIns_latch;

// Per-unit need signals: does any instr in this packet need this unit?
logic need_ex1, need_ex2, need_ex3, need_ex4, need_ex5;

always_comb begin
    // Determine which EX units are needed by this packet
    //latch
    need_ex1 = 1'b0;
    need_ex2 = 1'b0;
    need_ex3 = 1'b0;
    need_ex4 = 1'b0;
    need_ex5 = 1'b0;

    for (int i = 0; i < NUM_SCALAR_INSTRS; i++) begin
        if (decoded_scalar_instrs_latch[i].valid_in) begin
            case (fu_enables_latch[i])
              //unit 1
              alu_valid, control_valid: need_ex1 = 1'b1;
              //unit 2
              bf_div_valid, s_div_valid, s_mod_valid, BF_to_int_valid, int_to_BF_valid: need_ex2 = 1'b1;
              //unit 3
              bf_mult_valid, bf_add_valid, bf_sub_valid, bf_slt_valid: need_ex3 = 1'b1;
              //unit 4
              sMult_valid: need_ex4 = 1'b1;
              //unit 5
              ld_valid, st_valid: need_ex5 = 1'b1;
              default: ;
            endcase
        end
    end
end

// Structural hazard check, all needed units must be ready
logic FU_ready;

//if we need and ready, not blocked. if don't need, we don't care about ready. if we need and not ready, blocked
assign FU_ready = (~need_ex1 | d2if.ready_DEC2_ex1) &
                         (~need_ex2 | d2if.ready_DEC2_ex2) &
                         (~need_ex3 | d2if.ready_DEC2_ex3) &
                         (~need_ex4 | d2if.ready_DEC2_ex4) &
                         (~need_ex5 | d2if.ready_DEC2_ex5);

assign d2if.ready = dcif.dependencies_ready & FU_ready & (srfif.vrf_ready);
//& srfif.opbuff_ivalid);



//connections to dependency checker
//all need to be latched
assign dcif.scalar_rsel = rsel_latch;
assign dcif.scalar_REN = REN_latch;
assign dcif.scalar_wsel = rdIns_latch;
assign dcif.scalar_WEN = reg_writes_latch;


always_comb begin
    if(d2if.ready) begin
        pc_nlatch = d2if.pc_in;
        pc_pred_addr_nlatch = d2if.pc_pred_addr_in;
        predict_taken_nlatch = d2if.predict_taken_in;
        decoded_scalar_instrs_nlatch = scif.decoded_scalar_instrs;
        REN_nlatch = saif_temp.REN;
        rsel_nlatch = saif_temp.rsel;
        for (int i = 0; i < NUM_SCALAR_INSTRS; i++) begin
            fu_enables_nlatch[i] = scif.decoded_scalar_instrs[i].fu_enable;
            reg_writes_nlatch[i] = scif.decoded_scalar_instrs[i].reg_write;
            rdIns_nlatch[i] = scif.decoded_scalar_instrs[i].rdIn;
        end
    end else begin
        pc_nlatch = pc_latch;
        pc_pred_addr_nlatch = pc_pred_addr_latch;
        predict_taken_nlatch = predict_taken_latch;
        decoded_scalar_instrs_nlatch = decoded_scalar_instrs_latch;
        REN_nlatch = REN_latch;
        rsel_nlatch = rsel_latch;
        fu_enables_nlatch = fu_enables_latch;
        reg_writes_nlatch = reg_writes_latch;
        rdIns_nlatch = rdIns_latch;
    end
end

always_ff @( posedge CLK, negedge nRST ) begin
    if(!nRST) begin
        pc_latch <= '0;
        pc_pred_addr_latch <= '0;
        predict_taken_latch <= '0;
        decoded_scalar_instrs_latch <= '0;
        REN_latch <= '0;
        rsel_latch <= '0;
        fu_enables_latch <= '0;
        reg_writes_latch <= '0;
        rdIns_latch <= '0;
    end else begin
        pc_latch <= pc_nlatch;
        pc_pred_addr_latch <= pc_pred_addr_nlatch;
        predict_taken_latch <= predict_taken_nlatch;
        decoded_scalar_instrs_latch <= decoded_scalar_instrs_nlatch;
        REN_latch <= REN_nlatch;
        rsel_latch <= rsel_nlatch;
        fu_enables_latch <= fu_enables_nlatch;
        reg_writes_latch <= reg_writes_nlatch;
        rdIns_latch <= rdIns_nlatch;
    end
end


endmodule