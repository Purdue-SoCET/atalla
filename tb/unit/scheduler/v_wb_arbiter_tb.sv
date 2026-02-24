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


    // Clock and reset
    logic CLK;
    logic nRST;

    // Arbiter interface
    v_wb_arbiter_if vif();


    // Instantiate the arbiter
    v_wb_arbiter uut (
        .CLK(CLK),
        .nRST(nRST),
        .vif(vif)
    );

    // Clock generator
    initial CLK = 0;
    always #5 CLK = ~CLK; // 100 MHz

    // Testbench variables
    logic [9-1:0] valid_in;
    vector_pkg::vsel_t vd_in   [0:9-1];   // one vsel_t per input
    vector_pkg::vreg_t data_in [0:9-1];   // one vreg_t per input


    // Initialize interface signals
    initial begin
        nRST = 0;
        vif.veggie_out.ready = 1;

        // Clear inputs

        vif.vector_if_reduction_out = '0;
        vif.vector_if_vlsu_out.wb = '0;
        vif.vector_if_gsau_out = '0;
        vif.vector_if_lanes_out.result_collectors = '0;
        vif.vector_if_lanes_out ='0;

        #10 nRST = 1;

        $display("Starting arbiter test...");

        // Test 1: Single input to bank 0
        vif.vector_if_vlsu_out.wb[0].valid = 1;
        vif.vector_if_vlsu_out.wb[0].vdst = 8'b00000001; // Bank ID 00
        vif.vector_if_vlsu_out.wb[0].load_data  = '1;

        #10; //Time taken for it to get written to the latch. As soon as it's taken in by veggie, let's say it goes to not ready
        vif.veggie_out.ready = 0; //Not ready while writing. Takes one cycle for instance

        //At the same time, we have something else writing something
        vif.vector_if_vlsu_out.wb[0].valid = 1;
        vif.vector_if_vlsu_out.wb[0].vdst = 8'b01000001; // Bank ID 01
        vif.vector_if_vlsu_out.wb[0].load_data  = '1;

        //Ideally, this should get stopped. Meaning, wb buffer won't send it anywhere

        #10;

        //Let's say veggie finished writing and is ready now

        vif.veggie_out.ready = 1;

        //Processor attempts again
        vif.vector_if_vlsu_out.wb[0].valid = 1;
        vif.vector_if_vlsu_out.wb[0].vdst = 8'b01000001; // Bank ID 01
        vif.vector_if_vlsu_out.wb[0].load_data  = '1;
        #10;

        vif.veggie_out.ready = 0;
        #10;

        vif.veggie_out.ready = 1;

        //Processor does 2nd attempts
        vif.vector_if_vlsu_out.wb[0] = '0; //clear
    
        vif.vector_if_lanes_out.result_collectors[4].wb_valid = 1;
        vif.vector_if_lanes_out.result_collectors[4].vd_output= 8'b01000010; // Bank ID 01
        vif.vector_if_lanes_out.result_collectors[4].vd_output  = '1;

        // Same input to bank 1
        vif.vector_if_lanes_out.result_collectors[1].wb_valid = 1;
        vif.vector_if_lanes_out.result_collectors[1].vd_output= 8'b01100011; // Bank ID 01
        vif.vector_if_lanes_out.result_collectors[1].vd_output  = '1;
        #10;

        //Ideally, in this period, result collector 4 gets a not ready

        vif.veggie_out.ready = 0;
        #10; //70th ns

        //result collector 1 successfully written
        vif.veggie_out.ready = 1;
        

        // Processor does another attempt
        vif.vector_if_lanes_out.result_collectors[1] = '0; //cleared

        vif.vector_if_lanes_out.result_collectors[4].wb_valid = 1;
        vif.vector_if_lanes_out.result_collectors[4].vd_output= 8'b01000100; // Bank ID 01
        vif.vector_if_lanes_out.result_collectors[4].vector_output  = '1;

        // Test 3: Single input to bank 2
        vif.vector_if_lanes_out.result_collectors[2].wb_valid = 1;
        vif.vector_if_lanes_out.result_collectors[2].vd_output= 8'b10000101; // Bank ID 10
        vif.vector_if_lanes_out.result_collectors[2].vector_output  = '1;

        vif.vector_if_vlsu_out.wb[1].valid = 1;
        vif.vector_if_vlsu_out.wb[1].vdst = 8'b00000110; // Bank ID 00
        vif.vector_if_vlsu_out.wb[1].load_data  = '1;

        vif.vector_if_vlsu_out.wb[0].valid = 1;
        vif.vector_if_vlsu_out.wb[0].vdst = 8'b11000111; // Bank ID 11
        vif.vector_if_vlsu_out.wb[0].load_data  = '1;

        //all four being used, but we don't send a full not ready unless veggie says not ready.
        //Until then, we do individual not readys
        #10;

        vif.vector_if_lanes_out.result_collectors[1].wb_valid = 1;
        vif.vector_if_lanes_out.result_collectors[1].vd_output= 8'b11001000; // Bank ID 11
        vif.vector_if_lanes_out.result_collectors[1].vector_output  = '1;

        vif.vector_if_lanes_out.result_collectors[3].wb_valid = 1;
        vif.vector_if_lanes_out.result_collectors[3].vd_output= 8'b00001001; // Bank ID 00
        vif.vector_if_lanes_out.result_collectors[3].vector_output  = '1;

        //Ideally, result collectors 1 and 3 should get blocked. Nothing else should.

        #20;
        vif.veggie_out.ready = 0; //Now, everything gets blocked

        #20;
        vif.veggie_out.ready = 1;
        
        // All cleared by processor
        vif.vector_if_lanes_out.result_collectors[1] = '0;
        vif.vector_if_lanes_out.result_collectors[2] = '0;
        vif.vector_if_lanes_out.result_collectors[3] = '0;
        vif.vector_if_lanes_out.result_collectors[4] = '0;
        vif.vector_if_vlsu_out.wb[0] = '0;
        vif.vector_if_vlsu_out.wb[1] = '0;

        //Single input to bank 2
        vif.vector_if_lanes_out.result_collectors[3].wb_valid = 1;
        vif.vector_if_lanes_out.result_collectors[3].vd_output= 8'b10001011; // Bank ID 10
        vif.vector_if_lanes_out.result_collectors[3].vector_output  = '1;
        #10;

        vif.veggie_out.ready = 0;
        #10;
        //Write successful
        vif.veggie_out.ready = 1;

        $display("Testbench finished");
        $stop;
    end

endmodule
