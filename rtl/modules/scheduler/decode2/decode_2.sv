`include "decode_2_if.vh"
// `include "reg_file_if.vh"
`include "dummy_regfile_if.vh"
`include "atalla_isa_types.vh"


module decode_2 
    import atalla_isa_pkg::*;
#(
    parameter NUM_SCALAR_INSTRS    = 4,
    parameter NUM_VECTOR_INSTRS    = 4,
    parameter NUM_SDMA_INSTRS    = 2
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


//pass through signals 
assign d2if.pc_out           = d2if.pc_in;
assign d2if.pc_pred_addr_out = d2if.pc_pred_addr_in;
assign d2if.predict_taken_out = d2if.predict_taken_in;

assign scif.scalar_instrs = d2if.scalar_instrs;
assign d2if.decoded_scalar_instrs = scalarsraif.instrs_out;

//connecting to soruce reg allocator
assign scalarsraif.instrs_in = scif.decoded_scalar_instrs;
assign scalarsraif.rdata = srfif.rdata; 


assign srfif.REN = scalarsraif.REN;
assign srfif.rsel = scalarsraif.rsel;
assign srfif.WEN = d2if.scalar_WB_WEN;
assign srfif.wsel = d2if.scalar_WB_wsel;
assign srfif.wdata = d2if.scalar_WB_wdata;

assign dcif.scalar_WB_wsel = d2if.scalar_WB_wsel;
assign dcif.scalar_WB_WEN = d2if.scalar_WB_WEN;
assign dcif.scalar_SDMA_wsel = d2if.scalar_SDMA_wsel;
assign dcif.scalar_SDMA_WEN = d2if.scalar_SDMA_WEN;

// Check execute signals for structural hazards (scalar)
scalar_fu_enable_t fu_enables [NUM_SCALAR_INSTRS];
logic  reg_writes [NUM_SCALAR_INSTRS];
logic [7:0] rdIns [NUM_SCALAR_INSTRS];

// Per-unit need signals: does any instr in this packet need this unit?
logic need_ex1, need_ex2, need_ex3, need_ex4, need_ex5;

always_comb begin
    for (int i = 0; i < NUM_SCALAR_INSTRS; i++) begin
        fu_enables[i] = scif.decoded_scalar_instrs[i].fu_enable;
        reg_writes[i] = scif.decoded_scalar_instrs[i].reg_write;
        rdIns[i] = scif.decoded_scalar_instrs[i].rdIn;

    end

    // Determine which EX units are needed by this packet
    need_ex1 = 1'b0;
    need_ex2 = 1'b0;
    need_ex3 = 1'b0;
    need_ex4 = 1'b0;
    need_ex5 = 1'b0;

    for (int i = 0; i < NUM_SCALAR_INSTRS; i++) begin
        if (scif.decoded_scalar_instrs[i].valid_in) begin
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



//connections to dependency checker
assign dcif.scalar_rsel = scalarsraif.rsel;
assign dcif.scalar_REN = scalarsraif.REN;
assign dcif.scalar_wsel = rdIns;
assign dcif.scalar_WEN = reg_writes;


endmodule