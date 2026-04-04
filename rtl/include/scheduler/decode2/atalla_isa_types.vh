`ifndef ATALLA_PKG_VH
`define ATALLA_PKG_VH

package atalla_isa_pkg;

  // ============================================================
  // 1. GLOBAL WIDTH PARAMETERS
  // ============================================================

  parameter WORD_W        = 32;
  parameter INST_W        = 48;
  parameter PACKET_SIZE   = 4;
  parameter PACKET_W      = INST_W * PACKET_SIZE; // 192 bits
  parameter PACKET_BYTE_W = PACKET_W / 8;

  parameter PC_WIDTH      = 32;

  parameter OP_W          = 7;
  parameter REG_W         = 8;
  parameter SCALAR_REG_W  = REG_W;
  parameter VECTOR_REG_W  = 8;
  parameter MASK_REG_W    = 4;
  parameter VECTOR_LEN   = 32;

  parameter IMM_W_I       = 12;
  parameter IMM_W_MI      = 25;

  parameter NUM_ROWS      = 5;
  parameter NUM_COLS      = 5;

  parameter SCALAR_SLOTS = 4;
  parameter VECTOR_SLOTS = 4;
  parameter SCRATCH_SLOTS = 2;

  // ============================================================
  // 2. BRANCH PREDICTION (BTB)
  // ============================================================

  parameter BTB_ENTRIES = 64;
  parameter BTB_OFFSET  = $clog2(PACKET_BYTE_W & -PACKET_BYTE_W);
  parameter BTB_IDX_W   = $clog2(BTB_ENTRIES);
  parameter BTB_TAG_W   = PC_WIDTH - BTB_IDX_W - BTB_OFFSET;

  // ============================================================
  // 3. COMMON TYPES
  // ============================================================

  typedef logic [WORD_W-1:0] word_t;
  typedef logic [INST_W-1:0] instr_t;
  typedef logic [15:0]       half_word_t;
  typedef logic [PC_WIDTH-1:0] address_t;
  typedef half_word_t [VECTOR_LEN-1:0] vector_t; // 32x16b vector
  typedef logic [VECTOR_LEN-1:0] mask_t; // 32 bit mask

  // ============================================================
  // 4. OPCODES (FULL SUPERSET – SCALAR + VECTOR + SDMA)
  // ============================================================

  typedef enum logic [OP_W-1:0] {

    // ---- Scalar R-Type ----
    ADD_S=7'd1,  SUB_S=7'd2,  MUL_S=7'd3,  DIV_S=7'd4,  MOD_S=7'd5,
    OR_S=7'd6,   AND_S=7'd7,  XOR_S=7'd8,
    SLL_S=7'd9,  SRL_S=7'd10, SRA_S=7'd11,
    SLT_S=7'd12, SLTU_S=7'd13,

    // ---- BF16 Scalar ----
    ADD_BF=7'd14, SUB_BF=7'd15, MUL_BF=7'd16,
    RCP_BF=7'd17, SLT_BF=7'd18, SLTU_BF=7'd19,
    STBF_S=7'd20, BFTS_S=7'd21,

    // ---- Scalar Immediate ----
    ADDI_S=7'd22, SUBI_S=7'd23, MULI_S=7'd24,
    DIVI_S=7'd25, MODI_S=7'd26,
    ORI_S=7'd27,  ANDI_S=7'd28, XORI_S=7'd29,
    SLLI_S=7'd30, SRLI_S=7'd31, SRAI_S=7'd32,
    SLTI_S=7'd33, SLTUI_S=7'd34,

    // ---- Branch / Jump ----
    BEQ_S=7'd35, BNE_S=7'd36, BLT_S=7'd37,
    BGE_S=7'd38, BGT_S=7'd39, BLE_S=7'd40,
    LW_S=7'd41,  SW_S=7'd42,
    JAL=7'd43,   JALR=7'd44,
    LI_S=7'd45,
    LUI_S=7'd46,
    NOP_S=7'd47,
    HALT_S=7'd48,
    // BARRIER_S=7'd49,

    // ---- Vector VV ----
    ADD_VV=7'd50, SUB_VV=7'd51, MUL_VV=7'd52,
    DIV_VV=7'd53, AND_VV=7'd54, OR_VV=7'd55,
    XOR_VV=7'd56, GEMM_VV=7'd57,

    // ---- Vector Mask VV ----
    MGT_MVV=7'd58, MLT_MVV=7'd59,
    MEQ_MVV=7'd60, MNEQ_MVV=7'd61,

    // ---- Vector Immediate ----
    ADDI_VI=7'd62, SUBI_VI=7'd63,
    MULI_VI=7'd64, DIVI_VI=7'd65,
    EXPI_VI=7'd66, SQRTI_VI=7'd67,
    NOT_VI=7'd68, SHIFT_VI=7'd69,
    LW_VI=7'd70,
    RSUM_VI=7'd71, RMIN_VI=7'd72, RMAX_VI=7'd73,

    // ---- Vector Scalar ----
    SHIFT_VS=7'd74,
    MV_MTS=7'd75, MV_STM=7'd76,
    VREG_LD=7'd77, VREG_ST=7'd78,
    VMOV_VTS=7'd79,
    ADD_VS=7'd80, SUB_VS=7'd81,
    MUL_VS=7'd82, DIV_VS=7'd83,
    MGT_MVS=7'd84, MLT_MVS=7'd85,
    MEQ_MVS=7'd86, MNEQ_MVS=7'd87,

    // ---- Scratchpad DMA ----
    SCPAD_LD=7'd88,
    SCPAD_ST=7'd89,

    // ---- Halfword ----
    LHW_S=7'd90,
    SHW_S=7'd91

  } opcode_t;

  // ============================================================
  // 5. SCALAR FU ENABLE
  // ============================================================

  typedef enum logic [3:0] {
    alu_valid=4'd0,
    control_valid=4'd1,
    bf_add_valid=4'd2,
    bf_sub_valid=4'd3,
    bf_mult_valid=4'd4,
    bf_slt_valid=4'd5,
    bf_div_valid=4'd6,
    s_div_valid=4'd7,
    s_mod_valid=4'd8,
    BF_to_int_valid=4'd9,
    int_to_BF_valid=4'd10,
    ld_valid=4'd11,
    st_valid=4'd12,
    sMult_valid=4'd13, 
    halt_valid=4'd14
  } scalar_fu_enable_t;


  typedef enum logic [3:0] {
    ALU_ADD = 4'b0000, // BF16 addition
    ALU_SUB = 4'b0001, // BF16 subtraction
    ALU_AND = 4'b0010, // Bitwise AND
    ALU_OR = 4'b0011, // Bitwise OR
    ALU_XOR = 4'b0100, // Bitwise XOR
    ALU_NOT = 4'b0101, // Bitwise NOT (v1 only)
    ALU_MGT = 4'b0110, // Mask greater than (v1 > v2)
    ALU_MLT = 4'b0111, // Mask less than (v1 < v2)
    ALU_MEQ = 4'b1000, // Mask equal (v1 == v2)
    ALU_MNEQ = 4'b1001 // Mask not equal (v1 != v2)
    MUL = 4'b1010, // BF16 multiplication
    EXP = 4'b1011, // Exponential
    VLSU = 4'b1100, // Vector load/store unit
    GSAU = 4'b1101 // GEMM unit 
    REDU = 4'b1110 // Reduction unit (this is technically not a separate FU but we need this signal to check structural hazards for reduction ops)
  } vector_fu_enable_t; //check rm flag for reduction ops

  // ============================================================
  // 6. INSTRUCTION FORMATS (R / I / BR / MI)
  // ============================================================

  typedef struct packed {
    logic [16:0] reserved;
    logic [REG_W-1:0] rs2;
    logic [REG_W-1:0] rs1;
    logic [REG_W-1:0] rd;
    opcode_t opcode;
  } r_t;

  typedef struct packed {
    logic [12:0] reserved;
    logic [IMM_W_I-1:0] imm;
    logic [REG_W-1:0] rs1;
    logic [REG_W-1:0] rd;
    opcode_t opcode;
  } i_t;

  typedef struct packed {
    logic [7:0] reserved;
    logic [8:0] imm9;
    logic [REG_W-1:0] rs2;
    logic [REG_W-1:0] rs1;
    logic imm1;
    logic [6:0] incr_imm7;
    opcode_t opcode;
  } br_t;

  typedef struct packed {
    logic [7:0] reserved;
    logic [IMM_W_MI-1:0] imm25;
    logic [REG_W-1:0] rd;
    opcode_t opcode;
  } mi_t;

  // ============================================================
  // 7. VLIW PACKET
  // ============================================================

  typedef struct packed {
    logic [INST_W-1:0] inst3;
    logic [INST_W-1:0] inst2;
    logic [INST_W-1:0] inst1;
    logic [INST_W-1:0] inst0;
  } instruction_packet_t;

  // ============================================================
  // 7. VLIW PACKET
  // ============================================================

  parameter r_t NOP_R = '{reserved:'0, rs2:'0, rs1:'0, rd:'0, opcode:NOP_S};
  parameter instr_t NOP_INST = instr_t'(NOP_R);
  parameter instruction_packet_t NOP_PACKET = '{inst0: NOP_INST, inst1: NOP_INST, inst2: NOP_INST, inst3: NOP_INST};

  // ============================================================
  // 8. DECODE STRUCTURES (Scalar / Vector / SDMA)
  // ============================================================

  typedef struct packed {
    scalar_fu_enable_t fu_enable;
    logic valid_in;
    logic imm_src;
    logic halfword;
    logic branch_flag;
    word_t imm;
    word_t incr7;
    opcode_t op;
    logic halt;

    logic [SCALAR_REG_W-1:0] rs1, rs2, rdIn;
    word_t r1_data, r2_data;

    logic use_rs1, use_rs2;
    logic reg_write;
  } decoded_scalar_instr_t;


  typedef struct packed {
    vector_fu_enable_t fu_enable;
    opcode_t op;
    logic valid_in;
    logic [7:0] imm;
    logic [1:0] op2_src; // 0=vs2, 1=immediate, 2=scalar

    //actual reg nums 
    logic [MASK_REG_W-1:0] vms, vmd; 
    logic [VECTOR_REG_W-1:0] vs1, vs2, vd;
    logic [SCALAR_REG_W-1:0] rs1, rs2, rd;

    //TODO actual data (vmd, vd, rd)
    vector_t vs1_data, vs2_data;
    word_t rs1_data, rs2_data;
    mask_t vms_data; //mask

    logic [1:0] sid;
    logic [4:0] num_cols;

    logic use_vms, use_vs1, use_vs2, use_rs1, use_rs2;
    logic mask_reg_write, vector_reg_write, scalar_reg_write;

    logic rm; //reduction mode flag

  } decoded_vector_instr_t;


  typedef struct packed {
    logic valid_in;
    logic store;
    logic [SCALAR_REG_W-1:0] rs1_rd;
    logic [SCALAR_REG_W-1:0] rs2;
    logic [SCALAR_REG_W-1:0] rs3;
    logic use_rs1, use_rs2, use_rs3;
    word_t rs1_rd_data;
    word_t rs2_data;
    word_t rs3_data;

     
  } decoded_SDMA_instr_t;

endpackage

`endif