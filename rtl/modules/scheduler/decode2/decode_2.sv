`include "decode_2_if.vh"
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
    parameter NUM_SDMA_INSTRS    = 4, 
    parameter SCALAR_REG_BITS     = 8,
    parameter VECTOR_REG_BITS      = 8,
    parameter MASK_REG_BITS        = 4, 
    parameter SCALAR_READ_PORTS     = 4,
    parameter SCALAR_WRITE_PORTS    = 4,
    parameter VECTOR_READ_PORTS     = 4,
    parameter VECTOR_WRITE_PORTS    = 4,
    parameter MASK_READ_PORTS       = 2,    
    parameter MASK_WRITE_PORTS      = 2
) (
  input logic CLK, nRST,
  decode_2_if.dec d2if
);


scalar_control_unit_if scif();
vector_control_unit_if vcif();
sdma_control_unit_if sdmacif();

reg_file_if srfif();
reg_file_if #(.DATA_WIDTH(16), .NUM_ELEMENTS(32)) vrfif ();
reg_file_if #(.BANK_COUNT(2), .BANK_REGS(8), .DREAD_PORTS(2), .DWRITE_PORTS(2), .ZERO_REG_VAL(1)) mrfif ();


dependency_checker_if dcif();
source_reg_allocator_if sraif ();

scalar_control_unit scu1(CLK, scif);
vector_control_unit vcu1(CLK, vcif);
sdma_control_unit sdmacu1(CLK, sdmacif);

reg_file srf1(CLK, nRST, srfif);
reg_file #(.DATA_WIDTH(16), .NUM_ELEMENTS(32)) vrf1(CLK, nRST, vrfif);
reg_file #(.BANK_COUNT(2), .BANK_REGS(8), .DREAD_PORTS(2), .DWRITE_PORTS(2), .ZERO_REG_VAL(1)) mrf1(CLK, nRST, mrfif);

dependency_checker dc1 (CLK, nRST, dcif);
source_reg_allocator scalarsra1 (sraif);

//pass through signals 
assign d2if.pc_out           = d2if.pc_in;
assign d2if.pc_pred_addr_out = d2if.pc_pred_addr_in;
assign d2if.predict_taken_out = d2if.predict_taken_in;

assign scif.scalar_instrs = d2if.scalar_instrs;
assign vcif.vector_instrs = d2if.vector_instrs;
assign sdmacif.sdma_instrs = d2if.SDMA_instrs;

assign d2if.decoded_scalar_instrs = d2if.ready ? sraif.scalar_instrs_out : '0;
assign d2if.decoded_vector_instrs = d2if.ready ? sraif.vector_instrs_out : '0;
assign d2if.decoded_SDMA_instrs = d2if.ready ? sraif.sdma_instrs_out : '0;

//connecting to soruce reg allocator
assign sraif.scalar_instrs_in = scif.decoded_scalar_instrs;
assign sraif.vector_instrs_in = vcif.decoded_vector_instrs;
assign sraif.sdma_instrs_in = sdmacif.decoded_sdma_instrs;

//reg file
assign sraif.scalar_rdata = srfif.opbuff_vreg;
assign sraif.vector_rdata = vrfif.opbuff_vreg;
assign sraif.mask_rdata = mrfif.opbuff_vreg;

assign srfif.REN = sraif.scalar_REN;
assign srfif.vs = sraif.scalar_rsel;

assign vrfif.REN = sraif.vector_REN;
assign vrfif.vs = sraif.vector_rsel;

assign mrfif.REN = sraif.mask_REN;
assign mrfif.vs = sraif.mask_rsel;


assign srfif.dependencies_ready = dcif.dependencies_ready;
assign srfif.accomplished = d2if.ready;

assign vrfif.dependencies_ready = dcif.dependencies_ready;
assign vrfif.accomplished = d2if.ready;

assign mrfif.dependencies_ready = dcif.dependencies_ready;
assign mrfif.accomplished = d2if.ready;

//wb signals to register files
assign srfif.vd = d2if.scalar_WB_wsel;
assign srfif.vdata = d2if.scalar_WB_wdata;
assign srfif.WEN = d2if.scalar_WB_WEN;
assign vrfif.vd = d2if.vector_WB_wsel;
assign vrfif.vdata = d2if.vector_WB_wdata;
assign vrfif.WEN = d2if.vector_WB_WEN;
assign mrfif.vd = d2if.mask_WB_wsel;
assign mrfif.vdata = d2if.mask_WB_wdata;
assign mrfif.WEN = d2if.mask_WB_WEN;

//dependency checker connections to WB for clearing bits
assign dcif.scalar_WB_wsel = d2if.scalar_WB_wsel;
assign dcif.scalar_WB_WEN = d2if.scalar_WB_WEN;
assign dcif.vector_WB_wsel = d2if.vector_WB_wsel;
assign dcif.vector_WB_WEN = d2if.vector_WB_WEN;
assign dcif.mask_WB_wsel = d2if.mask_WB_wsel;
assign dcif.mask_WB_WEN = d2if.mask_WB_WEN;
assign dcif.scalar_SDMA_WB_wsel = d2if.scalar_SDMA_WB_wsel;
assign dcif.scalar_SDMA_WB_WEN = d2if.scalar_SDMA_WB_WEN;
assign dcif.ready = d2if.ready; 


scalar_fu_enable_t [NUM_SCALAR_INSTRS-1:0] scalar_fu_enables;
logic [NUM_SCALAR_INSTRS-1:0] scalar_reg_writes;
logic [NUM_SCALAR_INSTRS-1:0][SCALAR_REG_BITS-1:0] scalar_wsels;

vector_fu_enable_t [NUM_VECTOR_INSTRS-1:0] vector_fu_enables;
logic [NUM_VECTOR_INSTRS-1:0] vector_s_reg_writes;
logic [NUM_VECTOR_INSTRS-1:0] vector_v_reg_writes;
logic [NUM_VECTOR_INSTRS-1:0] vector_m_reg_writes;
logic [NUM_VECTOR_INSTRS-1:0][SCALAR_REG_BITS-1:0] vector_s_wsels;
logic [NUM_VECTOR_INSTRS-1:0][VECTOR_REG_BITS-1:0] vector_v_wsels;
logic [NUM_VECTOR_INSTRS-1:0][MASK_REG_BITS-1:0] vector_m_wsels;
logic [NUM_SDMA_INSTRS-1:0] SDMA_scalar_WEN;
logic [NUM_SDMA_INSTRS-1:0][SCALAR_REG_BITS-1:0] SDMA_scalar_rs1s;

// Per-unit need signals for struct hazard checking: does any instr in this packet need this unit?
    logic need_scalar_ex1, need_scalar_ex2, need_scalar_ex3, need_scalar_ex4, need_scalar_ex5;
    logic need_vector_alu, need_vector_mul, need_vector_exp, need_vector_reduction, need_vector_vlsu, need_vector_gsau;
    logic need_sdma_ex;

always_comb begin
    for (int i = 0; i < NUM_SCALAR_INSTRS; i++) begin
        scalar_fu_enables[i] = scif.decoded_scalar_instrs[i].fu_enable;
        scalar_reg_writes[i] = scif.decoded_scalar_instrs[i].reg_write;
        scalar_wsels[i] = scif.decoded_scalar_instrs[i].rdIn;
    end

    for (int i = 0; i < NUM_VECTOR_INSTRS; i++) begin
        vector_fu_enables[i] = vcif.decoded_vector_instrs[i].fu_enable;

        // vector reg writes
        vector_s_reg_writes[i] = vcif.decoded_vector_instrs[i].scalar_reg_write;
        vector_v_reg_writes[i] = vcif.decoded_vector_instrs[i].vector_reg_write;
        vector_m_reg_writes[i] = vcif.decoded_vector_instrs[i].mask_reg_write;
        vector_s_wsels[i] = vcif.decoded_vector_instrs[i].rd;
        vector_v_wsels[i] = vcif.decoded_vector_instrs[i].vd;
        vector_m_wsels[i] = vcif.decoded_vector_instrs[i].vmd;

    end

    for (int i = 0; i < NUM_SDMA_INSTRS; i++) begin
        // SDMA reg writes
        SDMA_scalar_WEN[i] = sdmacif.decoded_sdma_instrs[i].use_rs1;
        SDMA_scalar_rs1s[i] = sdmacif.decoded_sdma_instrs[i].rs1_rd; //rs1=rd for SDMA
    end

    //FOLLOWING BLOCK IS SETTING UP FOR CHECKING STRUCTURAL HAZARDS

    

    // Determine which execution units are needed by this packet
    need_scalar_ex1 = 1'b0;
    need_scalar_ex2 = 1'b0;
    need_scalar_ex3 = 1'b0;
    need_scalar_ex4 = 1'b0;
    need_scalar_ex5 = 1'b0;
    need_vector_alu = 1'b0;
    need_vector_mul = 1'b0;
    need_vector_exp = 1'b0;
    need_vector_reduction = 1'b0;
    need_vector_vlsu = 1'b0;
    need_vector_gsau = 1'b0;
    need_sdma_ex = 1'b0;

    for (int i = 0; i < NUM_SCALAR_INSTRS; i++) begin
        if (scif.decoded_scalar_instrs[i].valid_in) begin
            case (scalar_fu_enables[i])
              //unit 1
              alu_valid, control_valid: need_scalar_ex1 = 1'b1;
              //unit 2
              bf_div_valid, s_div_valid, s_mod_valid, BF_to_int_valid, int_to_BF_valid: need_scalar_ex2 = 1'b1;
              //unit 3
              bf_mult_valid, bf_add_valid, bf_sub_valid, bf_slt_valid: need_scalar_ex3 = 1'b1;
              //unit 4
              sMult_valid: need_scalar_ex4 = 1'b1;
              //unit 5
              ld_valid, st_valid: need_scalar_ex5 = 1'b1;
              default: ;
            endcase
        end
    end

    for (int i = 0; i < NUM_VECTOR_INSTRS; i++) begin
        if (vcif.decoded_vector_instrs[i].valid_in) begin
            case (vector_fu_enables[i])
                ALU_ADD, ALU_SUB, ALU_OR, ALU_AND, ALU_XOR, ALU_NOT, ALU_MGT, ALU_MLT, ALU_MEQ, ALU_MNEQ: need_vector_alu = 1'b1;
                MUL: need_vector_mul = 1'b1;
                EXP: need_vector_exp = 1'b1;
                VLSU: need_vector_vlsu = 1'b1;
                GSAU: need_vector_gsau = 1'b1;
                REDU: begin
                    need_vector_reduction = 1'b1;
                    need_vector_alu = 1'b1;                     
                end
              default: ;
            endcase
        end
    end

    need_sdma_ex = |SDMA_scalar_WEN; //this will only be 1 for a valid SDMA instr

end

// Structural hazard check, all needed units must be ready

logic scalar_FU_ready;
logic vector_FU_ready;
logic sdma_FU_ready;

//TODO figure out where vts, mts, stm are being handled 
//if we need and ready, not blocked. if don't need, we don't care about ready. if we need and not ready, blocked
assign scalar_FU_ready = (~need_scalar_ex1 | d2if.ready_DEC2_ex1) &
                         (~need_scalar_ex2 | d2if.ready_DEC2_ex2) &
                         (~need_scalar_ex3 | d2if.ready_DEC2_ex3) &
                         (~need_scalar_ex4 | d2if.ready_DEC2_ex4) &
                         (~need_scalar_ex5 | d2if.ready_DEC2_ex5);
assign vector_FU_ready = (~need_vector_alu | d2if.alu_ready) &
                         (~need_vector_mul | d2if.mul_ready) &
                         (~need_vector_exp | d2if.exp_ready) &
                         (~need_vector_reduction | d2if.reduction_ready) &
                         (~need_vector_vlsu | d2if.vlsu_ready) &
                         (~need_vector_gsau | d2if.gsau_ready);
assign sdma_FU_ready = (~need_sdma_ex | d2if.sdma_ready);

//dependencies ready, structural hazards cleared, and reg files ready = packet is ready to issue
assign d2if.ready = dcif.dependencies_ready & (scalar_FU_ready & vector_FU_ready & sdma_FU_ready) & (srfif.vrf_ready & vrfif.vrf_ready & mrfif.vrf_ready); 

//reg files only start trying to get data once structural/RAW/WAW hazards are cleared
assign srfif.dec2_ready = d2if.ready;
assign vrfif.dec2_ready = d2if.ready;
assign mrfif.dec2_ready = d2if.ready;

//Source reg connections to dependency checker for RAW/WAW checks
assign dcif.scalar_rsel = sraif.scalar_rsel;
assign dcif.scalar_REN = sraif.scalar_REN;
assign dcif.vector_rsel = sraif.vector_rsel;
assign dcif.vector_REN = sraif.vector_REN;
assign dcif.mask_rsel = sraif.mask_rsel;
assign dcif.mask_REN = sraif.mask_REN;

//Dest reg signals to dependency checker to set these bits as busy in checker
assign dcif.scalar_wsel = scalar_wsels;
assign dcif.scalar_WEN = scalar_reg_writes;
assign dcif.vector_s_wsels = vector_s_wsels;
assign dcif.vector_v_wsels = vector_v_wsels;
assign dcif.vector_m_wsels = vector_m_wsels;
assign dcif.vector_s_WEN = vector_s_reg_writes;
assign dcif.vector_v_WEN = vector_v_reg_writes;
assign dcif.vector_m_WEN = vector_m_reg_writes;
assign dcif.SDMA_scalar_rs1s = SDMA_scalar_rs1s;
assign dcif.SDMA_scalar_WEN = SDMA_scalar_WEN;


endmodule