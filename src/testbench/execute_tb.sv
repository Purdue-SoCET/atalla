`timescale 1ns / 10ps
`include "execute_if.vh"
`include "cpu_types.vh"

module execute_tb;

    parameter PERIOD = 10;
    logic CLK = 0, nRST;

    always #(PERIOD/2) CLK++;

    execute_if eif ();

    test PROG (.CLK(CLK), .nRST(nRST), .tbif(eif));

    execute DUT (.CLK(CLK), .nRST(nRST), .eif(eif));

endmodule

program test (
    input logic CLK, 
    output logic nRST,
    execute_if.tbif tbif
);
    import isa_pkg::*;
    import datapath_pkg::*;
    task reset_dut;
        begin
            nRST = 1'b0;

            @(posedge CLK);
            @(posedge CLK);

            @(negedge CLK);
            nRST = 1'b1;

            @(negedge CLK);
            @(negedge CLK);
        end
    endtask

    task reset_in;
        begin
            // Branch FU
            tbif.ihit = '0;
            tbif.bfu_branch_outcome = '0;
            tbif.bfu_update_btb = '0;
            tbif.bfu_branch_target = '0;
            tbif.bfu_pc = '0;
            tbif.bfu_pc_fetch = '0;
            // Scalar ALU FU
            tbif.salu_aluop = '0;
            tbif.salu_port_a = '0;
            tbif.salu_port_b = '0;
            tbif.imm = '0;
            // Scalar Load/Store FU
            tbif.sls_mem_type = '0;
            tbif.sls_rs1 = '0;
            tbif.sls_rs2 = '0;
            tbif.sls_dmem_in = '0;
            tbif.sls_dhit_in = '0;
            // MLS FU
            tbif.mls_mhit = '0;
            tbif.mls_enable = '0;
            tbif.mls_ls_in = '0;
            tbif.mls_rd_in = '0;
            tbif.mls_rs_in = '0;
            tbif.mls_stride_in = '0;
            tbif.mls_imm_in = '0;
            // GEMM FU
            tbif.gemm_fetch_p = '0;
            tbif.gemm_flush = '0;
            tbif.gemm_freeze = '0;

            @(posedge CLK);
        end
    endtask

    parameter string tb_test_case = "INIT";

    initial begin

        reset_in();
        reset_dut();

        @(posedge CLK);

        // test case 1 - SALU
        tb_test_case = "SALU ADD";
        tbif.salu_port_a  = 32'd2;
        tbif.salu_port_b = 32'd3;
        tbif.salu_aluop = 4'd3;
        #(100);

        reset_in();

        // test case 2 - branch fu
        tb_test_case = "Brach FU (BEQ 1)";
        fubif.branch_type = 2'd0;
        fubif.branch_gate_sel = 1'b0;
        fubif.reg_a = 32'd10;
        fubif.reg_b = 32'd10;
        #(100);

        reset_in();

        // Test Case 3 - scalar load/store
        tb_test_case = "Scalar Load/Store";
        tbif.sls_imm = 32'd400;
        tbif.sls_mem_type = LOAD;
        tbif.sls_rs1 = 32'd440;
       #(100);

        reset_in();

        // Test Case 4 - gemm  
        tb_test_case = "GEMM";
        fugif.gemm_enable = '1;
        fugif.new_weight_in = '0;
        fugif.rs1_in = 'h1;
        fugif.rs2_in = 'h2;
        fugif.rs3_in = 'h3;
        fugif.rd_in = 'h4;
        #(100);

        reset_in();

        // Test Case 5 - matrix load/store
        tb_test_case = "Matrix Load/Store";
        mlsif.enable    = 1;         // Enable the module
        mlsif.ls_in     = 2'b01;     // LOAD operation selected (bit0 high)
        mlsif.rd_in     = 5'd15;     // Example destination register value
        mlsif.rs_in     = 32'd100;   // Example source register value (assume word_t is 32-bit)
        mlsif.stride_in = 32'd5;     // Example stride value
        mlsif.imm_in    = 11'd20;    // Immediate value (address = rs_in + imm_in)
        mlsif.mhit      = 1;         // Scratchpad ready; done should be 1
        #(100);

        reset_in();


        $finish;
    end


endprogram
