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

            cuif.decoded_scalar_instrs[i].rs1   = cuif.scalar_instrs[i][22:15];
            cuif.decoded_scalar_instrs[i].rs2   = cuif.scalar_instrs[i][30:23];
            cuif.decoded_scalar_instrs[i].rdIn  = cuif.scalar_instrs[i][14:7];
            cuif.decoded_scalar_instrs[i].op    = opcode_t'(cuif.scalar_instrs[i][OP_W-1:0]);

            casez (opcode_t'(cuif.scalar_instrs[i][OP_W-1:0]))

                // ----------------------------------------------------------------
                // Integer ALU ops (reg-reg)
                // ----------------------------------------------------------------
                ADD_S, SUB_S,
                OR_S, AND_S, XOR_S,
                SLL_S, SRL_S, SRA_S,
                SLT_S, SLTU_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = alu_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b0;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = '0;
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                // ----------------------------------------------------------------
                // Integer Multiply
                // ----------------------------------------------------------------
                MUL_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = sMult_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b0;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = '0;
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                // ----------------------------------------------------------------
                // Integer Divide
                // ----------------------------------------------------------------
                DIV_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = s_div_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b0;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = '0;
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                // ----------------------------------------------------------------
                // Integer Modulo
                // ----------------------------------------------------------------
                MOD_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = s_mod_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b0;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = '0;
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                // ----------------------------------------------------------------
                // BF16 ALU ops
                // ----------------------------------------------------------------
                ADD_BF: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = bf_add_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b0;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm        = '0;
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                SUB_BF: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = bf_sub_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b0;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm        = '0;
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                MUL_BF: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = bf_mult_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b0;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm        = '0;
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                RCP_BF: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = bf_div_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b0;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm        = '0;
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                SLT_BF: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = bf_slt_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b0;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm        = '0;
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                SQRT_BF: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = sqrt_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b0;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm        = '0;
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                
                // ----------------------------------------------------------------
                // STM
                // ----------------------------------------------------------------
                MV_STM: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = BF_to_int_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].mask_reg_write  = 1'b1;

                end

                // ----------------------------------------------------------------
                // Conversion ops
                // ----------------------------------------------------------------
                STBF_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = int_to_BF_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b0;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm        = '0;
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                BFTS_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = BF_to_int_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b0;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = '0;
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                // ----------------------------------------------------------------
                // Integer ALU ops w/ immediate
                // ----------------------------------------------------------------
                ADDI_S, SUBI_S,
                ORI_S, ANDI_S, XORI_S,
                SLLI_S, SRLI_S, SRAI_S,
                SLTI_S, SLTUI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = alu_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b1;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                MULI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = sMult_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b1;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                DIVI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = s_div_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b1;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                MODI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = s_mod_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b1;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                // ----------------------------------------------------------------
                // Branch ops — no reg_write
                // ----------------------------------------------------------------
                BEQ_S, BNE_S,
                BLT_S, BGE_S,
                BGT_S, BLE_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = control_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b1;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = {{22{cuif.scalar_instrs[i][14]}}, cuif.scalar_instrs[i][14], cuif.scalar_instrs[i][39:31]};
                    cuif.decoded_scalar_instrs[i].incr7      = {{25{cuif.scalar_instrs[i][13]}}, cuif.scalar_instrs[i][13:7]};
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b1;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                    cuif.decoded_scalar_instrs[i].rdIn       = cuif.scalar_instrs[i][22:15];
                end

                // ----------------------------------------------------------------
                // JAL / JALR — write return address
                // ----------------------------------------------------------------
                JAL: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = control_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b1;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = {{7{cuif.scalar_instrs[i][39]}}, cuif.scalar_instrs[i][39:15]};
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b0;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                JALR: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = control_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b1;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                // ----------------------------------------------------------------
                // Memory ops
                // ----------------------------------------------------------------
                LW_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = ld_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b1;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1; // base
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                SW_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = st_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b1;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1; // base
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b1; // data
                    cuif.decoded_scalar_instrs[i].rs2   = cuif.scalar_instrs[i][14:7];                    
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b0;
                end

                LHW_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = ld_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b1;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm        = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1; // base
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                SHW_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = st_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b1;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm        = {{20{cuif.scalar_instrs[i][34]}}, cuif.scalar_instrs[i][34:23]};
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b1; // base
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b1; // data
                    cuif.decoded_scalar_instrs[i].rs2   = cuif.scalar_instrs[i][14:7];                    
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b0;
                end

                // ----------------------------------------------------------------
                // LUI
                // ----------------------------------------------------------------
                LUI_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = alu_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b1;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = {{7{1'b0}}, cuif.scalar_instrs[i][39:15]};
                    cuif.decoded_scalar_instrs[i].use_rs1    = 1'b0;
                    cuif.decoded_scalar_instrs[i].use_rs2    = 1'b0;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b1;
                end

                // ----------------------------------------------------------------
                // NOP
                // ----------------------------------------------------------------
                NOP_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = alu_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b0;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = '0;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b0;
                end

                // ----------------------------------------------------------------
                // HALT
                // ----------------------------------------------------------------
                HALT_S: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = halt_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b1;
                    cuif.decoded_scalar_instrs[i].halt       = 1'b1;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b0;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = '0;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b0;
                end

                // ----------------------------------------------------------------
                // Default
                // ----------------------------------------------------------------
                default: begin
                    cuif.decoded_scalar_instrs[i].fu_enable  = alu_valid;
                    cuif.decoded_scalar_instrs[i].valid_in   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm_src    = 1'b0;
                    cuif.decoded_scalar_instrs[i].halfword   = 1'b0;
                    cuif.decoded_scalar_instrs[i].imm        = '0;
                    cuif.decoded_scalar_instrs[i].reg_write  = 1'b0;
                end

            endcase

        end

    end

endmodule