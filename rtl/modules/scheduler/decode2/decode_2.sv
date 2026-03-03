`include "decode_2_if.vh"
// `include "reg_file_if.vh"
`include "dummy_regfile_if.vh"
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
    parameter WRITE_PORTS = 4, 
    parameter SCALAR_REG_BITS = 8
) (
  input logic CLK, nRST,
  decode_2_if.dec d2if
);

//just using scalar stuff for now

scalar_control_unit_if scif();
// vector_control_unit_if vcif();
// sdma_control_unit_if sdmacif();
// reg_file_if srfif ();
dummy_regfile_if srfif (); // TODO currently using the dummy reg file

// reg_file_if #(.DATA_WIDTH(16), .NUM_ELEMENTS(32)) vrfif ();
// reg_file_if #(.NUM_REGS(16), .NUM_BANKS(2), .READ_PORTS(2), .WRITE_PORTS(2)) mrfif ();
dependency_checker_if dcif();
source_reg_allocator_if scalarsraif ();

scalar_control_unit scu1(CLK, scif);
// vector_control_unit vcu1(CLK, nRST, vcif);
// sdma_control_unit sdmacu1(CLK, nRST, sdmacif);
dummy_regfile srf1(CLK, nRST, srfif);
// reg_file vrf1(CLK, nRST, vrfif);
// reg_file mrf1(CLK, nRST, mrfif);
dependency_checker dc1 (CLK, nRST, dcif);
source_reg_allocator scalarsra1 (scalarsraif);

word_t pc_out_nlatch, pc_out_latch, pc_pred_addr_out_nlatch, pc_pred_addr_out_latch;
logic predict_taken_out_nlatch, predict_taken_out_latch;
logic [WRITE_PORTS-1:0][SCALAR_REG_BITS-1:0] scalar_WB_wsel_nlatch, scalar_WB_wsel_latch;
logic [WRITE_PORTS-1:0][31:0] scalar_WB_wdata_nlatch, scalar_WB_wdata_latch;
logic scalar_WB_WEN_nlatch, scalar_WB_WEN_latch;
logic scalar_SDMA_WEN_nlatch, scalar_SDMA_WEN_latch;
logic [SCALAR_REG_BITS-1:0] scalar_SDMA_wsel_nlatch, scalar_SDMA_wsel_latch;
decoded_scalar_instr_t [NUM_INSTRUCTIONS-1:0] decoded_scalar_instrs_nlatch, decoded_scalar_instrs_latch;

//pass through signals 
assign d2if.pc_out           = pc_out_latch;
assign d2if.pc_pred_addr_out = pc_pred_addr_out_latch;
assign d2if.predict_taken_out = predict_taken_out_latch;

assign scif.scalar_instrs = d2if.scalar_instrs;
assign d2if.decoded_scalar_instrs = scalarsraif.instrs_out;

//connecting to soruce reg allocator
assign scalarsraif.instrs_in = decoded_scalar_instrs_latch;
assign scalarsraif.rdata = srfif.rdata; 


assign srfif.REN = scalarsraif.REN;
assign srfif.rsel = scalarsraif.rsel;
assign srfif.WEN = scalar_WB_WEN_latch;
assign srfif.wsel = scalar_WB_wsel_latch;
assign srfif.wdata = scalar_WB_wdata_latch;

assign dcif.scalar_WB_wsel = scalar_WB_wsel_latch;
assign dcif.scalar_WB_WEN = scalar_WB_WEN_latch;
assign dcif.scalar_SDMA_wsel = scalar_SDMA_wsel_latch;
assign dcif.scalar_SDMA_WEN = scalar_SDMA_WEN_latch;

// Check execute signals for structural hazards (scalar)
scalar_fu_enable_t [NUM_SCALAR_INSTRS-1:0] fu_enables;
logic [NUM_SCALAR_INSTRS-1:0]  reg_writes;
logic [7:0][NUM_SCALAR_INSTRS-1:0]  rdIns;

// Per-unit need signals: does any instr in this packet need this unit?
logic need_ex1, need_ex2, need_ex3, need_ex4, need_ex5;

always_comb begin
    for (int i = 0; i < NUM_SCALAR_INSTRS; i++) begin
        fu_enables[i] = decoded_scalar_instrs_latch[i].fu_enable;
        reg_writes[i] = decoded_scalar_instrs_latch[i].reg_write;
        rdIns[i] = decoded_scalar_instrs_latch[i].rdIn;

    end

    // Determine which EX units are needed by this packet
    need_ex1 = 1'b0;
    need_ex2 = 1'b0;
    need_ex3 = 1'b0;
    need_ex4 = 1'b0;
    need_ex5 = 1'b0;

    for (int i = 0; i < NUM_SCALAR_INSTRS; i++) begin
        if (decoded_scalar_instrs_latch[i].valid_in) begin
            case (fu_enables[i])
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

assign d2if.ready = dcif.dependencies_ready & FU_ready;
//assign d2if.ready = FU_ready;



//connections to dependency checker
assign dcif.scalar_rsel = scalarsraif.rsel;
assign dcif.scalar_REN = scalarsraif.REN;
assign dcif.scalar_wsel = rdIns;
assign dcif.scalar_WEN = reg_writes;

always_comb begin
    if(d2if.ready) begin
        pc_out_nlatch = d2if.pc_in;
        pc_pred_addr_out_nlatch = d2if.pc_pred_addr_in;
        predict_taken_out_nlatch = d2if.predict_taken_in;
        scalar_WB_wsel_nlatch = d2if.scalar_WB_wsel;
        scalar_WB_wdata_nlatch = d2if.scalar_WB_wdata;
        scalar_WB_WEN_nlatch = d2if.scalar_WB_WEN;
        scalar_SDMA_WEN_nlatch = d2if.scalar_SDMA_WEN;
        scalar_SDMA_wsel_nlatch = d2if.scalar_SDMA_wsel;
        decoded_scalar_instrs_nlatch = scif.decoded_scalar_instrs;
    end else begin
        pc_out_nlatch = pc_out_latch;
        pc_pred_addr_out_nlatch = pc_pred_addr_out_latch;
        predict_taken_out_nlatch = predict_taken_out_latch;
        scalar_WB_wsel_nlatch = scalar_WB_wsel_latch;
        scalar_WB_wdata_nlatch = scalar_WB_wdata_latch;
        scalar_WB_WEN_nlatch = scalar_WB_WEN_latch;
        scalar_SDMA_WEN_nlatch = scalar_SDMA_WEN_latch;
        scalar_SDMA_wsel_nlatch = scalar_SDMA_wsel_latch;
        decoded_scalar_instrs_nlatch = decoded_scalar_instrs_latch;
    end
end

always_ff @( posedge CLK, negedge nRST ) begin
    if(!nRST) begin
        pc_out_latch <= '0;
        pc_pred_addr_out_latch <= '0;
        predict_taken_out_latch <= '0;
        scalar_WB_wsel_latch <= '0;
        scalar_WB_wdata_latch <= '0;
        scalar_WB_WEN_latch <= '0;
        scalar_SDMA_WEN_latch <= '0;
        scalar_SDMA_wsel_latch <= '0;
        decoded_scalar_instrs_latch <= '0;        
    end else begin
        pc_out_latch <= pc_out_nlatch;
        pc_pred_addr_out_latch <= pc_pred_addr_out_nlatch;
        predict_taken_out_latch <= predict_taken_out_nlatch;
        scalar_WB_wsel_latch <= scalar_WB_wsel_nlatch;
        scalar_WB_wdata_latch <= scalar_WB_wdata_nlatch;
        scalar_WB_WEN_latch <= scalar_WB_WEN_nlatch;
        scalar_SDMA_WEN_latch <= scalar_SDMA_WEN_nlatch;
        scalar_SDMA_wsel_latch <= scalar_SDMA_wsel_nlatch;
        decoded_scalar_instrs_latch <= decoded_scalar_instrs_nlatch;
    end  
end


endmodule