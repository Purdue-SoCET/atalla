// Vector Writeback Testbench ============================================
// Author: Jaideep Dadi
// Email: djaideep@purdue.edu
// TODO 
// Check vector core stall-related inputs & modify code accordingly. Banks can be associative, no?
// ============================================================================
`timescale 1ns/1ps
//`include "v_wb_arbiter_if.vh"
//`include "vector_pkg.vh"

module tb_v_wb_arbiter;

    parameter INPUTS = vector_pkg::LANE_FU_COUNT;

    // Clock and reset
    logic CLK;
    logic nRST;

    // Arbiter interface
    v_wb_arbiter_if vif();

    // Outputs
    logic [INPUTS-1:0] stallSignal;

    // Instantiate the arbiter
    v_wb_arbiter #(
        .INPUTS(INPUTS)
    ) uut (
        .CLK(CLK),
        .nRST(nRST),
        .vif(vif),
        .stallSignal(stallSignal)
    );

    // Clock generator
    initial CLK = 0;
    always #5 CLK = ~CLK; // 100 MHz

    // Testbench variables
    logic [INPUTS-1:0] valid_in;
    vector_pkg::vsel_t vd_in   [0:INPUTS-1];   // one vsel_t per input
    vector_pkg::vreg_t data_in [0:INPUTS-1];   // one vreg_t per input


    // Initialize interface signals
    initial begin
        nRST = 0;
        vif.veggie_out.ready = 1;

        // Clear inputs
        

        vif.vector_out.result          = '0;
        vif.vector_out.valid_o         = '0;
        vif.vector_out.ready_o         = '0;

        vif.vector_out.vd              = '0;

        // Reduction Outputs
        vif.vector_out.reduction_result= '0;
        vif.vector_out.reduction_valid = '0;
        vif.vector_out.reduction_vd    = '0;
        vif.vector_out.gsau            = '0;

        #10 nRST = 1;

        $display("Starting arbiter test...");

        // Test 1: Single input to bank 0
        vif.vector_out.valid_o[0] = 1;
        vif.vector_out.vd[0]      = 8'h00; // Bank ID 00
        vif.vector_out.result[0]  = '1;
        #20;

        // Test 2: Conflict on bank 0 (input 1). Stall FU1?
        vif.vector_out.valid_o[1] = 1;
        vif.vector_out.vd[1]      = 8'h00; // Bank ID 00
        vif.vector_out.result[1]  = '1;
        #20;

        // Test 3: Different bank (input 2 to bank 1)
        vif.vector_out.valid_o[2] = 1;
        vif.vector_out.vd[2]      = 8'h40; // Bank ID 01
        vif.vector_out.result[2]  = '1;
        #20;

        // Test 4: Veggie not ready stalls all
        vif.veggie_out.ready = 0;
        #20;
        vif.veggie_out.ready = 1;

        $display("Testbench finished");
        $stop;
    end

endmodule
