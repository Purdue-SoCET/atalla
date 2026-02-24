//Navya Datla 2/12/2026
`ifndef ATALLA_ISA_PKG_VH
`define ATALLA_ISA_PKG_VH

package atalla_isa_pkg;
  parameter INSTR_W = 48; //instr width
  parameter OP_W = 7; // opcode widths
  parameter REG_W = 8; //256 registers
  parameter SCALAR_FU_W = 4; //9 FUs (for now)
  parameter ALUOP_W = 4; // alu op width
  parameter CONTROLOP_W = 4; //control op width (code for which branch instr)

  // types
  typedef logic [31:0] word_t;
  typedef logic [INSTR_W-1:0] instr_t;

  // Functional Unit Types
  typedef enum logic [SCALAR_FU_W-1:0] {
    FU_NONE       = 4'b0000,  // 0 - No operation
    FU_CONV_STBF  = 4'b0001,  // 1 - Conversion (STBF)
    FU_CONV_BFTS  = 4'b0010,  // 2 - Conversion (BFTS)
    FU_INT_ALU    = 4'b0011,  // 3 - Int ALU
    FU_INT_DIVMOD = 4'b0100,  // 4 - Int Div/Mod
    FU_INT_MULT   = 4'b0101,  // 5 - Int Mult
    FU_CONTROL    = 4'b0110,  // 6 - Control
    FU_MEM        = 4'b0111,  // 7 - Scalar L/S
    FU_BF16_ALU   = 4'b1000,  // 8 - BF16 ALU
    FU_BF16_DIVMOD= 4'b1001,  // 9 - BF16 Div/Mod
    FU_BF16_MULT  = 4'b1010   // 10 - BF16 Mult
  } scalar_fu_type_t;

  //alu ops
  typedef enum logic [ALUOP_W-1:0] {
    ALU_ADD  = 4'b0000,
    ALU_SUB  = 4'b0001,
    ALU_MUL  = 4'b0010,
    ALU_DIV  = 4'b0011,
    ALU_MOD  = 4'b0100,
    ALU_OR   = 4'b0101,
    ALU_AND  = 4'b0110,
    ALU_XOR  = 4'b0111,
    ALU_SLL  = 4'b1000,
    ALU_SRL  = 4'b1001,
    ALU_SRA  = 4'b1010,
    ALU_SLT  = 4'b1011,
    ALU_SLTU = 4'b1100,
    ALU_NOP  = 4'b1111
  } alu_op_t;

  // ctrl ops (for Control functional unit)
  typedef enum logic [CONTROLOP_W-1:0] {
    CTRL_BEQ  = 4'b0000,
    CTRL_BNE  = 4'b0001,
    CTRL_BLT  = 4'b0010,
    CTRL_BGE  = 4'b0011,
    CTRL_BGT  = 4'b0100,
    CTRL_BLE  = 4'b0101,
    CTRL_JAL  = 4'b0110,
    CTRL_JALR = 4'b0111,
    CTRL_HALT = 4'b1000,
    CTRL_NOP  = 4'b1111
  } control_op_t;

  // opcodes
  typedef enum logic [OP_W-1:0] {
    ADD_S     = 7'b0000001, //Add
    SUB_S     = 7'b0000010, //Sub
    MUL_S     = 7'b0000011, //Multiply
    DIV_S     = 7'b0000100, //Divide
    MOD_S      = 7'b0000101, // Modular
    OR_S       = 7'b0000110, // Or
    AND_S      = 7'b0000111, // And
    XOR_S      = 7'b0001000, // Xor
    SLL_S      = 7'b0001001, // Shift left logical
    SRL_S      = 7'b0001010, // Shift Right Logical
    SRA_S      = 7'b0001011, // Shift Right Arith
    SLT_S      = 7'b0001100, // Set Less Than
    SLTU_S     = 7'b0001101, // Set Less Than (U)
    ADD_BF     = 7'b0001110, // Add BF16
    SUB_BF     = 7'b0001111, // Sub BF16
    MUL_BF     = 7'b0010000, // Multiply BF16
    DIV_BF     = 7'b0010001, // Divide BF16
    SLT_BF     = 7'b0010010, // Set Less Than BF16
    // SLTU_BF    = 7'b0010011, // Set Less Than (U) BF16
    STBF_S     = 7'b0010100, // Converts Scalar to BF16
    BFTS_S     = 7'b0010101, // Converts BF16 to Scalar
    ADDI_S     = 7'b0010110, // Add
    SUBI_S     = 7'b0010111, // Sub
    MULI_S     = 7'b0011000, // Multiply
    DIVI_S     = 7'b0011001, // Divide
    MODI_S     = 7'b0011010, // Modular
    ORI_S      = 7'b0011011, // Or
    ANDI_S     = 7'b0011100, // And
    XORI_S     = 7'b0011101, // Xor
    SLLI_S     = 7'b0011110, // Shift left logical
    SRLI_S     = 7'b0011111, // Shift Right Logical
    SRAI_S     = 7'b0100000, // Shift Right Arith
    SLTI_S     = 7'b0100001, // Set Less Than
    SLTUI_S    = 7'b0100010, // Set Less Than (U)
    BEQ_S      = 7'b0100011, // Branch Equal
    BNE_S      = 7'b0100100, // Branch Not Equal
    BLT_S      = 7'b0100101, // Branch Less Than
    BGE_S      = 7'b0100110, // Branch Greater Than or Equal
    BGT_S      = 7'b0100111, // Branch Greater Than
    BLE_S      = 7'b0101000, // Branch Less Than or Equal
    LW_S       = 7'b0101001, // load word
    SW_S       = 7'b0101010, // store word
    JAL        = 7'b0101011, // jump and link
    JALR       = 7'b0101100, // jump and link register
    // LI_S       = 7'b0101101, // load immediate
    LUI_S      = 7'b0101110, // load upper immediate
    NOP_S      = 7'b0101111, // no operation
    HALT_S     = 7'b0110000, // halt program
    // BARRIER_S  = 7'b0110001, // force all prior packets to complete
    LHW_S      = 7'b1011010, //load half word
    SHW_S      = 7'b1011011 //store half word
  } opcode_t;

  typedef struct packed {
    scalar_fu_type_t fu_type;
    logic halt;
    control_op_t CONTROLOP;
    logic mem_read; 
    logic mem_write;
    logic half_word;
    alu_op_t ALUOP;
    logic alu_src;
    logic reg_write;
    word_t imm;
    
  } decoded_scalar_instr_t;


endpackage
`endif
