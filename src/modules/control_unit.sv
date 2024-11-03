// control unit

// need to include matrix related instructions, gemm, ld.m, sw.m

`include "types_pkg.vh"
`include "control_unit_if.vh"

module control_unit(
    control_unit_if.ctrl ctrl_if
);

    import types_pkg::*;

    word_t instr;

    // mem
    parameter WRITE = 2;
    parameter READ = 1;
    parameter TO_REG = 0;

    // branch
    parameter B_BEQ = 0;
    parameter B_BNE = 1;
    parameter B_BLT = 2;
    parameter B_BGE = 3;
    parameter B_BLTU = 4;
    parameter B_BGEU = 5;

    // u type
    parameter LOAD = 0;
    parameter ADD = 1;

    assign instr = ctrl_if.instr;

    always_comb begin
      ctrl_if.halt_pre = '0;
      ctrl_if.i_flag = '0;
      ctrl_if.b_type = '0;
      ctrl_if.mem_type = '0;
      ctrl_if.reg_write = '0;
      ctrl_if.jalr = '0;
      ctrl_if.jal = '0;
      ctrl_if.u_type = '0;
      ctrl_if.alu_op = '0;
      ctrl_if.branch_type = '0;
      ctrl_if.imm = '0;
      casez (instr[6:0])
        RTYPE:
            begin 
                ctrl_if.reg_write = '1;
                casez(instr[14:12])
                    SLL: ctrl_if.alu_op = ALU_SLL;
                    SRL_SRA: ctrl_if.alu_op = (instr[31:25] == SRA) ? ALU_SRA : ALU_SRL;
                    ADD_SUB: ctrl_if.alu_op = (instr[31:25] == SUB) ? ALU_SUB : ALU_ADD;
                    AND: ctrl_if.alu_op = ALU_AND;
                    OR: ctrl_if.alu_op = ALU_OR;
                    XOR: ctrl_if.alu_op = ALU_XOR;
                    SLT: ctrl_if.alu_op = ALU_SLT;
                    SLTU: ctrl_if.alu_op = ALU_SLTU;
                endcase
            end
        ITYPE: 
            begin 
                ctrl_if.reg_write = '1;
                ctrl_if.i_flag = '1;
                ctrl_if.imm = $signed({instr[31:20]});
                casez(instr[14:12])
                    ADDI: ctrl_if.alu_op = ALU_ADD;
                    XORI: ctrl_if.alu_op = ALU_XOR;
                    ORI: ctrl_if.alu_op = ALU_OR;
                    ANDI: ctrl_if.alu_op = ALU_AND;
                    SLLI: ctrl_if.alu_op = ALU_SLL;
                    SRLI_SRAI: ctrl_if.alu_op = (instr[31:25] == 7'h20) ? ALU_SRA : ALU_SRL;
                    SLTI: ctrl_if.alu_op = ALU_SLT;
                    SLTIU: ctrl_if.alu_op = ALU_SLTU;
                endcase
            end
        ITYPE_LW:
            begin
                if (instr[14:12] == 3'h2) begin 
                    ctrl_if.imm = $signed({instr[31:20]});
                    ctrl_if.reg_write = '1;
                    ctrl_if.i_flag = '1;
                    ctrl_if.alu_op = ALU_ADD;
                    ctrl_if.mem_type[TO_REG] = '1;
                    ctrl_if.mem_type[READ] = '1;
                end
            end
        JALR:
            begin 
                ctrl_if.imm = $signed({instr[31:20]});
                ctrl_if.reg_write = '1;
                ctrl_if.jalr = '1;
                ctrl_if.alu_op = ALU_ADD;
                ctrl_if.i_flag = '1;
            end
        STYPE:
            begin
                if (instr[14:12] == 3'h2) begin 
                    // ctrl_if.reg_write = '1;
                    ctrl_if.imm = $signed({instr[31:25], instr[11:7]});
                    ctrl_if.i_flag = '1;
                    ctrl_if.alu_op = ALU_ADD;
                    ctrl_if.mem_type[WRITE] = '1;
                end 
            end
        BTYPE:
            begin 
                // ctrl_if.reg_write = '1;
                ctrl_if.imm = $signed({instr[31], instr[7], instr[30:25], instr[11:8], 1'b0});
                casez(instr[14:12])
                    BEQ: 
                        begin 
                            ctrl_if.b_type[B_BEQ] = '1; 
                            ctrl_if.alu_op = ALU_SUB;
                            ctrl_if.branch_type = 3'd1;
                        end
                    BNE: 
                        begin 
                            ctrl_if.b_type[B_BNE] = '1; 
                            ctrl_if.alu_op = ALU_SUB;
                            ctrl_if.branch_type = 3'd2;
                        end
                    BLT: 
                        begin 
                            ctrl_if.b_type[B_BLT] = '1; 
                            ctrl_if.alu_op = ALU_SUB;
                            ctrl_if.branch_type = 3'd3;
                        end
                    BGE: 
                        begin 
                            ctrl_if.b_type[B_BGE] = '1; 
                            ctrl_if.alu_op = ALU_SUB;
                            ctrl_if.branch_type = 3'd4;
                        end
                    BLTU: 
                        begin 
                            ctrl_if.b_type[B_BLTU] = '1; 
                            ctrl_if.alu_op = ALU_SLTU;
                            ctrl_if.branch_type = 3'd5;
                        end
                    BGEU: 
                        begin 
                            ctrl_if.b_type[B_BGEU] = '1; 
                            ctrl_if.alu_op = ALU_SLTU;
                            ctrl_if.branch_type = 3'd6;
                        end
                endcase
            end
        JAL:
            begin 
                ctrl_if.imm = $signed({instr[31], instr[19:12], instr[20], instr[30:21], 1'b0});
                ctrl_if.jal = '1;
                ctrl_if.reg_write = '1;
                ctrl_if.alu_op = ALU_ADD;
                ctrl_if.i_flag = '1;
            end
        LUI:
            begin
                ctrl_if.imm = {instr[31:12], 12'b0};
                ctrl_if.u_type[LOAD] = '1;
                ctrl_if.reg_write = '1;
            end
        AUIPC:
            begin 
                ctrl_if.u_type[ADD] = '1;
                ctrl_if.reg_write = '1;
                ctrl_if.imm = {instr[31:12], 12'b0};
            end
        HALT: ctrl_if.halt_pre = '1;
      endcase
    end

endmodule