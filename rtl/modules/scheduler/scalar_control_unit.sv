//Navya Datla 2/12/2026

`include "scalar_control_unit_if.vh"

module scalar_control_unit
    import atalla_isa_pkg::*;
#(
    parameter NUM_INSTRUCTIONS = 4
) (
    input logic clk, 
    scalar_control_unit_if.cu cuif
);


    always_comb begin : decode_packet
        int i;

        for (i = 0; i < NUM_INSTRUCTIONS; i++) begin
            cuif.decoded_scalar_instrs[i] = '0;
            
            casez (opcode_t'(cuif.scalar_instrs[i][OP_W-1:0]))
                ADD_S: begin //1
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_ADD;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;  // Use rs2 (not immediate)
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end

                SUB_S: begin //2
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_SUB;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end

                MUL_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_MULT;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_MUL;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end

                DIV_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_DIVMOD;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_DIV;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end

                MOD_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_DIVMOD;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_MOD;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end
                
                OR_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_OR;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end
                
                AND_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_AND;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end
                
                XOR_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_XOR;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end
                
                SLL_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_SLL;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end
                
                SRL_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_SRL;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end
                
                SRA_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_SRA;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end
                
                SLT_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_SLT;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end
                
                SLTU_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_SLTU;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end


                //BF16 OPS
                ADD_BF: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_BF16_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b1;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_ADD;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end

                SUB_BF: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_BF16_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b1;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_SUB;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end

                MUL_BF: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_BF16_MULT;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b1;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_MUL;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end

                DIV_BF: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_BF16_DIVMOD;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b1;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_DIV;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end

                SLT_BF: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_BF16_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b1;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_SLT;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end

                //CONVERSION OPS
                STBF_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_CONV_STBF;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b1;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end

                BFTS_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_CONV_BFTS;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end

                // Integer ALU ops w immediate
                ADDI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_ADD;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;  // use immediate
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                SUBI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_SUB;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                MULI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_MULT;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_MUL;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                DIVI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_DIVMOD;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_DIV;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                MODI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_DIVMOD;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_MOD;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                ORI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_OR;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                ANDI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_AND;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                XORI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_XOR;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                SLLI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_SLL;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                SRLI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_SRL;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                SRAI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_SRA;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                SLTI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_SLT;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                SLTUI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_SLTU;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                // Control Ops
                BEQ_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_CONTROL;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_BEQ;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm = {{22{cuif.scalar_instrs[i][14]}}, cuif.scalar_instrs[i][14], cuif.scalar_instrs[i][39:31]};
                end

                BNE_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_CONTROL;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_BNE;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm = {{22{cuif.scalar_instrs[i][14]}}, cuif.scalar_instrs[i][14], cuif.scalar_instrs[i][39:31]};
                end

                BLT_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_CONTROL;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_BLT;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm = {{22{cuif.scalar_instrs[i][14]}}, cuif.scalar_instrs[i][14], cuif.scalar_instrs[i][39:31]};
                end

                BGE_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_CONTROL;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_BGE;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm = {{22{cuif.scalar_instrs[i][14]}}, cuif.scalar_instrs[i][14], cuif.scalar_instrs[i][39:31]};
                end

                BGT_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_CONTROL;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_BGT;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm = {{22{cuif.scalar_instrs[i][14]}}, cuif.scalar_instrs[i][14], cuif.scalar_instrs[i][39:31]};
                end

                BLE_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_CONTROL;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_BLE;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm = {{22{cuif.scalar_instrs[i][14]}}, cuif.scalar_instrs[i][14], cuif.scalar_instrs[i][39:31]};
                end

                JAL: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_CONTROL;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_JAL;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;  // Write return address
                    cuif.decoded_scalar_instrs[i].imm = {{7{cuif.scalar_instrs[i][39]}}, cuif.scalar_instrs[i][39:15]};
                end

                JALR: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_CONTROL;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_JALR;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;  // Write return address
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                LW_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_MEM;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b1;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;  // not needed for address calculation
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                SW_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_MEM;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;  // not needed for for address calculation
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                LHW_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_MEM;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b1;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b1;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;  // not needed for address calculation
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                SHW_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_MEM;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b1;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;  // not needed for for address calculation
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                end

                //other
                LUI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_INT_ALU;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_ADD;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm = {{7{cuif.scalar_instrs[i][39]}}, cuif.scalar_instrs[i][39:15]};
                end

                NOP_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_NONE;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end

                HALT_S: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_NONE;
                    cuif.decoded_scalar_instrs[i].halt = 1'b1;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end

                // default
                default: begin
                    cuif.decoded_scalar_instrs[i].fu_type = FU_NONE;
                    cuif.decoded_scalar_instrs[i].halt = 1'b0;
                    cuif.decoded_scalar_instrs[i].CONTROLOP = CTRL_NOP;
                    cuif.decoded_scalar_instrs[i].mem_read = 1'b0;
                    cuif.decoded_scalar_instrs[i].mem_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].half_word = 1'b0;
                    cuif.decoded_scalar_instrs[i].ALUOP = ALU_NOP;
                    cuif.decoded_scalar_instrs[i].alu_src = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm = '0;
                end
                
            endcase
            
        end
        
    end
    
endmodule