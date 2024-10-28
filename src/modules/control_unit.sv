`include "control_unit_if.vh"
`include "types_pkg.vh"

module control_unit (
    control_unit_if.cu cuif
);

    import types_pkg::*;

    always_comb begin: CONTROL_LOGIC
        cuif.JumpSel = 2'b0;
        cuif.jal = 1'b0;
        cuif.RegDst = 1'b0;
        cuif.RegWEN = 1'b0;
        cuif.ALUSrc = 1'b0;
        cuif.ALUctr = ALU_ADD;
        cuif.MemtoReg = 2'b0;
        cuif.ExtOP = 2'b01; // 0 = zero 1 = signed, 2 = LUI extend
        cuif.halt = 1'b0;
        cuif.iREN = 1'b1;
        cuif.dREN = 1'b0;
        cuif.dWEN = 1'b0;
        cuif.BEQ = 1'b0;
        cuif.BNE = 1'b0;
        cuif.atomic = 1'b0;
        case (cuif.opcode)
            // rtype
            RTYPE: begin
                cuif.RegDst = 1'b1;
                case (cuif.func)
                    ADDU: cuif.RegWEN = 1'b1;
                    ADD: cuif.RegWEN = 1'b1;
                    AND: begin 
                        cuif.RegWEN = 1'b1;
                        cuif.ALUctr = ALU_AND;
                    end
                    JR: cuif.JumpSel = 2'd2;
                    NOR: begin 
                        cuif.RegWEN = 1'b1;
                        cuif.ALUctr = ALU_NOR;
                    end
                    OR: begin
                        cuif.RegWEN = 1'b1;
                        cuif.ALUctr = ALU_OR;
                        cuif.ExtOP = 2'b00;
                    end
                    SLT: begin 
                        cuif.RegWEN = 1'b1;
                        cuif.ALUctr = ALU_SLT;
                    end
                    SLTU: begin
                        cuif.RegWEN = 1'b1;
                        cuif.ALUctr = ALU_SLTU;
                    end
                    SLLV: begin
                        cuif.RegWEN = 1'b1;
                        cuif.ALUctr = ALU_SLL;
                    end
                    SRLV: begin
                        cuif.RegWEN = 1'b1;
                        cuif.ALUctr = ALU_SRL;
                    end
                    SUBU: begin
                        cuif.RegWEN = 1'b1;
                        cuif.ALUctr = ALU_SUB;
                    end
                    SUB: begin
                        cuif.RegWEN = 1'b1;
                        cuif.ALUctr = ALU_SUB;
                    end
                    XOR: begin
                        cuif.RegWEN = 1'b1;
                        cuif.ALUctr = ALU_XOR;
                    end
                endcase
            end

            // itype
            ADDIU: begin
                cuif.RegWEN = 1'b1;
                cuif.ALUSrc = 1'b1;
            end
            ADDI: begin
                cuif.RegWEN = 1'b1;
                cuif.ALUSrc = 1'b1;
            end
            ANDI: begin
                cuif.RegWEN = 1'b1;
                cuif.ALUSrc = 1'b1;
                cuif.ALUctr = ALU_AND;
            end
            BEQ: begin
                cuif.ALUctr = ALU_SUB;
                cuif.BEQ = 1'b1;
            end
            BNE: begin
                cuif.ALUctr = ALU_SUB;
                cuif.BNE = 1'b1;
            end
            LUI: begin
                cuif.RegWEN = 1'b1;
                cuif.ALUSrc = 1'b1;
                cuif.MemtoReg = 2'd3;
                cuif.ALUctr = ALU_OR;
                cuif.ExtOP = 2'b10;
            end
            LW: begin
                cuif.RegWEN = 1'b1;
                cuif.dREN = 1'b1;
                cuif.ALUSrc = 1'b1;
                cuif.MemtoReg = 2'd2;
            end
            ORI: begin
                cuif.RegWEN = 1'b1;
                cuif.ALUSrc = 1'b1;
                cuif.ALUctr = ALU_OR;
                cuif.ExtOP = 2'b00;
            end
            SLTI: begin
                cuif.RegWEN = 1'b1;
                cuif.ALUSrc = 1'b1;
                cuif.ALUctr = ALU_SLT;
            end
            SLTIU: begin
                cuif.RegWEN = 1'b1;
                cuif.ALUSrc = 1'b1;
                cuif.ALUctr = ALU_SLTU;
            end
            SW: begin
                cuif.dWEN = 1'b1;
                cuif.ALUSrc = 1'b1;
            end           
            XORI: begin
                cuif.RegWEN = 1'b1;
                cuif.ALUSrc = 1'b1;
                cuif.ALUctr = ALU_XOR;
                cuif.ExtOP = 2'b00;
            end
            LL: begin
                cuif.RegWEN = 1'b1;
                cuif.dREN = 1'b1;
                cuif.ALUSrc = 1'b1;
                cuif.MemtoReg = 2'd2;
                cuif.atomic = 1'b1;
            end
            SC: begin
                cuif.RegWEN = 1'b1;
                cuif.MemtoReg = 2'd2;
                cuif.dWEN = 1'b1;
                cuif.ALUSrc = 1'b1;
                cuif.atomic = 1'b1;
            end

            // jtype
            J: cuif.JumpSel = 2'd1;
            JAL: begin
                cuif.RegWEN = 1'b1;
                cuif.JumpSel = 2'd1;
                cuif.MemtoReg = 2'd1;
                cuif.jal = 1'b1;
            end

            // other
            HALT: cuif.halt = 1'b1;
        endcase

    end

    endmodule
