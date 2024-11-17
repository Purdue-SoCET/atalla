// control unit

// need to include matrix related instructions, gemm, ld.m, sw.m

`include "types_pkg.vh"
`include "control_unit_if.vh"

module control_unit(
    control_unit_if.ctrl ctrl_if
);

    import types_pkg::*;

    word_t instr;

    // u type
    parameter LOAD = 0;
    parameter ADD = 1;

    assign instr = ctrl_if.instr;

    always_comb begin
      ctrl_if.halt = '0;
      ctrl_if.i_flag = '0;
      ctrl_if.s_mem_type = '0;
      ctrl_if.reg_write = '0;
      ctrl_if.jalr = '0;
      ctrl_if.jal = '0;
      ctrl_if.u_type = '0;
      ctrl_if.alu_op = '0;
      ctrl_if.branch_type = '0;
      ctrl_if.imm = '0;
      ctrl_if.stride = '0;
      ctrl_if.fu_s = '0;
      ctrl_if.fu_m = '0;
      ctrl_if.m_mem_type = '0;
      ctrl_if.matrix_rd = '0;
      ctrl_if.matrix_rs1 = '0;
      casez (instr[6:0])
        RTYPE:
            begin 
                ctrl_if.reg_write = '1;
                ctrl_if.fu_s = ALU;
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
                ctrl_if.fu_s = ALU;
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
                    // ctrl_if.alu_op = ALU_ADD;
                    ctrl_if.s_mem_type = MEM_TO_REG;
                    ctrl_if.s_mem_type = LOAD;
                    ctrl_if.fu_s = LD_ST;
                end
            end
        JALR:
            begin 
                ctrl_if.imm = $signed({instr[31:20]});
                ctrl_if.reg_write = '1;
                ctrl_if.jalr = '1;
                ctrl_if.alu_op = ALU_ADD;
                ctrl_if.i_flag = '1;
                ctrl_if.fu_s = ALU;
            end
        STYPE:
            begin
                if (instr[14:12] == 3'h2) begin 
                    ctrl_if.imm = $signed({instr[31:25], instr[11:7]});
                    ctrl_if.i_flag = '1;
                    // ctrl_if.alu_op = ALU_ADD
                    ctrl_if.s_mem_type = STORE;
                    ctrl_if.fu_s = LD_ST;
                end 
            end
        BTYPE:
            begin 
                // ctrl_if.reg_write = '1;
                ctrl_if.imm = $signed({instr[31], instr[7], instr[30:25], instr[11:8], 1'b0});
                ctrl_if.fu_s = BRANCH;
                casez(instr[14:12])
                    BEQ: 
                        begin 
                            ctrl_if.branch_type = BEQ; 
                            // ctrl_if.alu_op = ALU_SUB;
                            // ctrl_if.branch_type = 3'd1;
                        end
                    BNE: 
                        begin 
                            ctrl_if.branch_type = BNE; 
                            // ctrl_if.alu_op = ALU_SUB;
                            // ctrl_if.branch_type = 3'd2;
                        end
                    BLT: 
                        begin 
                            ctrl_if.branch_type = BLT; 
                            // ctrl_if.alu_op = ALU_SUB;
                            // ctrl_if.branch_type = 3'd3;
                        end
                    BGE: 
                        begin 
                            ctrl_if.branch_type = BGE; 
                            // ctrl_if.alu_op = ALU_SUB;
                            // ctrl_if.branch_type = 3'd4;
                        end
                    BLTU: 
                        begin 
                            ctrl_if.branch_type = BLTU; 
                            // ctrl_if.alu_op = ALU_SLTU;
                            // ctrl_if.branch_type = 3'd5;
                        end
                    BGEU: 
                        begin 
                            ctrl_if.branch_type = BGEU; 
                            // ctrl_if.alu_op = ALU_SLTU;
                            // ctrl_if.branch_type = 3'd6;
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
                ctrl_if.fu_s = ALU;
            end
        LUI:
            begin
                ctrl_if.imm = {instr[31:12], 12'b0};
                ctrl_if.u_type = LOAD;
                ctrl_if.reg_write = '1;
            end
        // AUIPC:
        //     begin 
        //         ctrl_if.u_type = ADD;
        //         ctrl_if.reg_write = '1;
        //         ctrl_if.imm = {instr[31:12], 12'b0};
        //     end
        HALT: ctrl_if.halt = '1;
        7'b1000111: // ld.m
            begin 
                ctrl_if.imm = $signed({instr[17:7]});
                // ctrl_if.i_flag = '1;
                // ctrl_if.alu_op = ALU_ADD;
                ctrl_if.stride = instr[22:18]; // register
                ctrl_if.fu = LD_ST;
                ctrl_if.m_mem_type = LOAD;
                ctrl_if.matrix_rd = instr[31:28];
                ctrl_if.matrix_rs1 = instr[27:23];
            end
        7'b1010111: //st.m
            begin
                ctrl_if.imm = $signed({instr[17:7]});
                // ctrl_if.i_flag = '1;
                // ctrl_if.alu_op = ALU_ADD;
                ctrl_if.stride = instr[22:18]; // register
                ctrl_if.fu_m = LD_ST;
                ctrl_if.m_mem_type = STORE;
                ctrl_if.matrix_rd = instr[31:28];
                ctrl_if.matrix_rs1 = instr[27:23];
            end
        7'b1110111: // gemm.m "md = ma @ mb + mc"
            begin
                ctrl_if.fu_m = GEMM;
                //i think thats it?
            end
      endcase
    end

endmodule