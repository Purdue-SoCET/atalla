`timescale 1ns/1ps

`include "vector_pkg.vh"
`include "vector_if.vh"
`include "gsau_control_unit_if.vh"

module vector_top_tb;
    `include "scpad_params.svh"
    import vector_pkg::*;
    import scpad_pkg::*;
    import uvm_pkg::*;
    import vector_uvm_pkg::*;

    logic CLK;
    logic nRST;

    localparam int CLK_PERIOD      = 10;

    initial begin
        CLK = 1'b0;
        forever #(CLK_PERIOD/2) CLK = ~CLK;
    end

    //instanciation
    vector_tb_if tb_if();
    vector_if vif();
    gsau_control_unit_if gsauif();
    scpad_if sif(CLK, nRST);

    // Clock and reset
    assign tb_if.CLK  = CLK;
    assign tb_if.nRST = nRST;

    assign vif.lanes_in = tb_if.lanes_in; // UVM driver: Vector DUT
    assign tb_if.lanes_out = vif.lanes_out; // Vector DUT: UVM monitor
    assign tb_if.alu_ready = vif.unit_ready_signals.fu_global_status[0]; // ALU ready status
    assign vif.gsau_in = '0;
    assign vif.vlsu_in = '0;
    assign vif.transpose_in = '0;

    // Allow results to be written back
    assign vif.wb_ready_signals = '1;

    vector_datapath dut (
        .CLK (CLK),
        .nRST(nRST),
        .vif (vif),
        .sif(sif),
        .gsauif(gsauif)
    );

    // reset generation
    initial begin
        nRST = 1'b0;

        repeat (5) @(posedge CLK);

        @(negedge CLK);
        nRST = 1'b1;
    end

    // tmep
    initial begin
        #10000;
        $fatal(1, "Vector testbench timeout");
    end

    initial begin
    // Register the interface for the UVM components
        uvm_config_db#(virtual vector_tb_if)::set(
            null,
            "uvm_test_top*",
            "vif",
            tb_if
        );

        // Start the ADD test
        run_test("vector_add_test");
    end

    // initial begin
    //     #10;
    //     $display("Running TB");
    //     #10;
    //     $finish();
    // end

endmodule