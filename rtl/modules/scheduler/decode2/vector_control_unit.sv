//Navya Datla 2/12/2026

`include "vector_control_unit_if.vh"

module vector_control_unit
    import atalla_isa_pkg::*;
#(
    parameter NUM_INSTRUCTIONS = 4
) (
    input logic clk,                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    vector_control_unit_if.cu cuif
);


    always_comb begin : decode_packet
        int i;

        for (i = 0; i < NUM_INSTRUCTIONS; i++) begin
            cuif.decoded_vector_instrs[i] = '0;
            cuif.decoded_vector_instrs[i].op    = opcode_t'(cuif.vector_instrs[i][OP_W-1:0]);

            casez (opcode_t'(cuif.vector_instrs[i][OP_W-1:0]))
                // ----------------------------------------------------------------
                // Vector VV (reg-reg)
                // ----------------------------------------------------------------
                ADD_VV: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = ALU_ADD;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31]; 
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15]; 
                    cuif.decoded_vector_instrs[i].vs2 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].vd = cuif.vector_instrs[i][14:7];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs2 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b1;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b0;

                end

                SUB_VV: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = ALU_SUB;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31]; 
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15]; 
                    cuif.decoded_vector_instrs[i].vs2 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].vd = cuif.vector_instrs[i][14:7];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs2 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b1;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b0;

                end

                MUL_VV: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = MUL;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31]; 
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15]; 
                    cuif.decoded_vector_instrs[i].vs2 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].vd = cuif.vector_instrs[i][14:7];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs2 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b1;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b0;

                end

                GEMM_VV: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = GSAU;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31]; 
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15]; 
                    // cuif.decoded_vector_instrs[i].vs2 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].vd = cuif.vector_instrs[i][14:7];
                    // cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    // cuif.decoded_vector_instrs[i].use_vs2 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b1;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b0;

                end

                // ----------------------------------------------------------------
                // Vector Mask VV
                // ----------------------------------------------------------------
                MGT_MVV: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = ALU_MGT;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31];
                    cuif.decoded_vector_instrs[i].vmd = cuif.vector_instrs[i][10:7];
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15];
                    cuif.decoded_vector_instrs[i].vs2 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs2 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b1;
                end

                MLT_MVV: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = ALU_MLT;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31];
                    cuif.decoded_vector_instrs[i].vmd = cuif.vector_instrs[i][10:7];
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15];
                    cuif.decoded_vector_instrs[i].vs2 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs2 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b1;
                end

                MEQ_MVV: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = ALU_MEQ;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31];
                    cuif.decoded_vector_instrs[i].vmd = cuif.vector_instrs[i][10:7];
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15];
                    cuif.decoded_vector_instrs[i].vs2 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs2 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b1;
                end

                MNEQ_MVV: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = ALU_MNEQ;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31];
                    cuif.decoded_vector_instrs[i].vmd = cuif.vector_instrs[i][10:7];
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15];
                    cuif.decoded_vector_instrs[i].vs2 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs2 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b1;
                end

                // ----------------------------------------------------------------
                // Vector Immediate 
                // ----------------------------------------------------------------
                EXPI_VI: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = EXP;
                    cuif.decoded_vector_instrs[i].imm = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].op2_src = 2'd1;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31]; 
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15]; 
                    cuif.decoded_vector_instrs[i].vd = cuif.vector_instrs[i][14:7];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b1;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b0;
                end

                LW_VI: begin //load weights for GEMM
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = GSAU;
                    cuif.decoded_vector_instrs[i].imm = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].op2_src = 2'd1;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31]; 
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15]; 
                    cuif.decoded_vector_instrs[i].vd = cuif.vector_instrs[i][14:7];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b0;
                end

                
                // ----------------------------------------------------------------
                // Vector Reduction
                // ----------------------------------------------------------------
                RSUM_VI, RMIN_VI, RMAX_VI: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = REDU;
                    cuif.decoded_vector_instrs[i].imm = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].op2_src = 2'd1;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31]; 
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15]; 
                    cuif.decoded_vector_instrs[i].vd = cuif.vector_instrs[i][14:7];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].rm =  1'b1; // reduction mode
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b1;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b0;

                end

                // ----------------------------------------------------------------
                // Vector Scalar 
                // ----------------------------------------------------------------
                ADD_VS: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = ALU_ADD;
                    cuif.decoded_vector_instrs[i].op2_src = 2'd2;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31]; 
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15]; 
                    cuif.decoded_vector_instrs[i].vd = cuif.vector_instrs[i][14:7];
                    cuif.decoded_vector_instrs[i].rs1 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_rs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b1;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b0;

                end

                SUB_VS: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = ALU_SUB;
                    cuif.decoded_vector_instrs[i].op2_src = 2'd2;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31]; 
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15]; 
                    cuif.decoded_vector_instrs[i].vd = cuif.vector_instrs[i][14:7];
                    cuif.decoded_vector_instrs[i].rs1 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_rs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b1;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b0;

                end

                MUL_VS: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = MUL;
                    cuif.decoded_vector_instrs[i].op2_src = 2'd2;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31]; 
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15]; 
                    cuif.decoded_vector_instrs[i].vd = cuif.vector_instrs[i][14:7];
                    cuif.decoded_vector_instrs[i].rs1 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_rs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b1;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b0;

                end

                // ----------------------------------------------------------------
                // MVS
                // ----------------------------------------------------------------
                MGT_MVS: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = ALU_MGT;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31];
                    cuif.decoded_vector_instrs[i].vmd = cuif.vector_instrs[i][10:7];
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15];
                    cuif.decoded_vector_instrs[i].rs1 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_rs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b1;

                end

                MLT_MVS:  begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = ALU_MLT;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31];
                    cuif.decoded_vector_instrs[i].vmd = cuif.vector_instrs[i][10:7];
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15];
                    cuif.decoded_vector_instrs[i].rs1 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_rs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b1;

                end
                MEQ_MVS:  begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = ALU_MEQ;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31];
                    cuif.decoded_vector_instrs[i].vmd = cuif.vector_instrs[i][10:7];
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15];
                    cuif.decoded_vector_instrs[i].rs1 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_rs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b1;

                end

                MNEQ_MVS:  begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = ALU_MNEQ;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][34:31];
                    cuif.decoded_vector_instrs[i].vmd = cuif.vector_instrs[i][10:7];
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15];
                    cuif.decoded_vector_instrs[i].rs1 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_rs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b1;

                end

                // ----------------------------------------------------------------
                // VTS
                // ----------------------------------------------------------------
                VMOV_VTS: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = MVMT;
                    cuif.decoded_vector_instrs[i].imm = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].op2_src = 1'b1;
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][22:15];
                    cuif.decoded_vector_instrs[i].rd = cuif.vector_instrs[i][14:7];
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b1;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b0;

                end

                // ----------------------------------------------------------------
                // MTS
                // ----------------------------------------------------------------
                MV_MTS: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = MVMT;
                    cuif.decoded_vector_instrs[i].vms = cuif.vector_instrs[i][18:15];
                    cuif.decoded_vector_instrs[i].rd = cuif.vector_instrs[i][14:7];
                    cuif.decoded_vector_instrs[i].use_vms = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b1;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b0;

                end


                // ----------------------------------------------------------------
                // VM
                // ----------------------------------------------------------------
                VREG_LD: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = VLSU;
                    cuif.decoded_vector_instrs[i].vd = cuif.vector_instrs[i][14:7];
                    cuif.decoded_vector_instrs[i].rs1 = cuif.vector_instrs[i][22:15];
                    cuif.decoded_vector_instrs[i].rs2 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].sid = cuif.vector_instrs[i][37:36];
                    cuif.decoded_vector_instrs[i].num_cols = cuif.vector_instrs[i][35:31];
                    cuif.decoded_vector_instrs[i].use_rs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_rs2 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b1;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b0;
                end

                VREG_ST: begin
                    cuif.decoded_vector_instrs[i].valid_in = 1'b1;
                    cuif.decoded_vector_instrs[i].fu_enable = VLSU;
                    cuif.decoded_vector_instrs[i].vs1 = cuif.vector_instrs[i][14:7];
                    cuif.decoded_vector_instrs[i].rs1 = cuif.vector_instrs[i][22:15];
                    cuif.decoded_vector_instrs[i].rs2 = cuif.vector_instrs[i][30:23];
                    cuif.decoded_vector_instrs[i].sid = cuif.vector_instrs[i][37:36];
                    cuif.decoded_vector_instrs[i].num_cols = cuif.vector_instrs[i][35:31];
                    cuif.decoded_vector_instrs[i].use_rs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_rs2 = 1'b1;
                    cuif.decoded_vector_instrs[i].use_vs1 = 1'b1;
                    cuif.decoded_vector_instrs[i].scalar_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].vector_reg_write = 1'b0;
                    cuif.decoded_vector_instrs[i].mask_reg_write = 1'b0;
                end
                

                default: begin
                    cuif.decoded_vector_instrs[i] = '0;
                end

            endcase

        end

    end

endmodule