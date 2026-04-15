
`include "scalar_alu_if.sv"

module scalar_alu (
    input  logic CLK,
    input  logic nRST,
    scalar_alu_if.dut salu_if
);

    // -----------------------------
    // Opcodes 
    // -----------------------------
    localparam logic [6:0] OP_ADD   = 7'b0000001; // add.s
    localparam logic [6:0] OP_SUB   = 7'b0000010; // sub.s
    localparam logic [6:0] OP_OR    = 7'b0000110; // or.s
    localparam logic [6:0] OP_AND   = 7'b0000111; // and.s
    localparam logic [6:0] OP_XOR   = 7'b0001000; // xor.s
    localparam logic [6:0] OP_SLL   = 7'b0001001; // sll.s
    localparam logic [6:0] OP_SRL   = 7'b0001010; // srl.s
    localparam logic [6:0] OP_SRA   = 7'b0001011; // sra.s
    localparam logic [6:0] OP_SLT   = 7'b0001100; // slt.s (signed)
    localparam logic [6:0] OP_SLTU  = 7'b0001101; // sltu.s (unsigned)

    localparam logic [6:0] OP_ADDI  = 7'b0010110; // addi.s
    localparam logic [6:0] OP_SUBI  = 7'b0010111; // subi.s
    localparam logic [6:0] OP_ORI   = 7'b0011011; // ori.s
    localparam logic [6:0] OP_ANDI  = 7'b0011100; // andi.s
    localparam logic [6:0] OP_XORI  = 7'b0011101; // xori.s
    localparam logic [6:0] OP_SLLI  = 7'b0011110; // slli.s
    localparam logic [6:0] OP_SRLI  = 7'b0011111; // srli.s
    localparam logic [6:0] OP_SRAI  = 7'b0100000; // srai.s
    localparam logic [6:0] OP_SLTI  = 7'b0100001; // slti.s (signed)
    localparam logic [6:0] OP_SLTUI = 7'b0100010; // sltui.s (unsigned)

    //TODO in future we should change this to please pull directly from atalla_isa_types so don't haev to manuall change it 
    localparam logic [6:0] OP_LUI   = 7'b0110000; // lui.s

    logic [31:0] result_comb;

    // -----------------------------
    // Combinational datapath
    // -----------------------------
    always_comb begin
        unique case (salu_if.salu_op)

            
            OP_ADD :  result_comb = salu_if.srcA + salu_if.srcB;
            OP_SUB :  result_comb = salu_if.srcA - salu_if.srcB;
            OP_OR  :  result_comb = salu_if.srcA | salu_if.srcB;
            OP_AND :  result_comb = salu_if.srcA & salu_if.srcB;
            OP_XOR :  result_comb = salu_if.srcA ^ salu_if.srcB;
            OP_SLL :  result_comb = salu_if.srcA << salu_if.srcB;
            OP_SRL :  result_comb = salu_if.srcA >> salu_if.srcB;
            OP_SRA :  result_comb = $signed(salu_if.srcA) >>> salu_if.srcB;
            OP_SLT :  result_comb = ($signed(salu_if.srcA) < $signed(salu_if.srcB)) ? 32'd1 : 32'd0;
            OP_SLTU:  result_comb = (salu_if.srcA < salu_if.srcB) ? 32'd1 : 32'd0;

            
            OP_ADDI:  result_comb = salu_if.srcA + salu_if.imm;
            OP_SUBI:  result_comb = salu_if.srcA - salu_if.imm;
            OP_ORI :  result_comb = salu_if.srcA | salu_if.imm;
            OP_ANDI:  result_comb = salu_if.srcA & salu_if.imm;
            OP_XORI:  result_comb = salu_if.srcA ^ salu_if.imm;
            OP_SLLI:  result_comb = salu_if.srcA << salu_if.imm[4:0];
            OP_SRLI:  result_comb = salu_if.srcA >> salu_if.imm[4:0];
            OP_SRAI:  result_comb = $signed(salu_if.srcA) >>> salu_if.imm[4:0];
            OP_SLTI:  result_comb = ($signed(salu_if.srcA) < $signed(salu_if.imm)) ? 32'd1 : 32'd0;
            OP_SLTUI: result_comb = (salu_if.srcA < salu_if.imm) ? 32'd1 : 32'd0;

            OP_LUI:   result_comb = {salu_if.imm[24:0], 7'b0};

            default:  result_comb = 32'd0;
        endcase
    end

    // -----------------------------
    // 0-cycle handshake passthrough
    // -----------------------------

    assign salu_if.rdOut     = salu_if.rdIn;
    assign salu_if.rdResult    = result_comb;

endmodule