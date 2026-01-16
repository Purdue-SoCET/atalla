`timescale 1ns / 1ps
`include "gsau_control_unit_if.vh"

module systolic_array_simple_tb();

// Parameters
localparam CLK_PERIOD = 10;

// Testbench Signals
logic tb_clk;
logic tb_nrst;

logic tb_read_en, tb_write_en, tb_has_space, tb_empty;

// Clk init
always
begin
    tb_clk = 1'b0;
    #(CLK_PERIOD/2.0);
    tb_clk = 1'b1;
    #(CLK_PERIOD/2.0);
end

gsau_control_unit_if sa_interface();
systolic_array_simple DUT (.nRST(tb_nrst), .clk(tb_clk), .gsau_if(sa_interface));

logic [15:0] out1_0, out1_1, out1_2, out1_3;

// Test scenarios
always begin
    $dumpfile("waves/systolic_array_simple_waves.vcd");
    $dumpvars();

    // Initialize
    sa_interface.sa_array_in <= '0;
    sa_interface.sa_array_in_partials <= '0;
    sa_interface.sa_input_en <= '0;
    sa_interface.sa_weight_en <= '0;
    sa_interface.sa_partial_en <= '0;
    sa_interface.sa_output_ready <= '0;
    tb_nrst <= 0;
    #CLK_PERIOD;
    tb_nrst <= 1;
    #CLK_PERIOD;

    // ========== TEST 1: 2x4 Matrix ==========
    // Load weights
    @(posedge tb_clk)
    sa_interface.sa_array_in <= 64'h3c00_3c00_3c00_3c00;
    sa_interface.sa_weight_en <= 1'b1;
    #(CLK_PERIOD*4);
    sa_interface.sa_weight_en <= 1'b0;

    // Load inputs
    sa_interface.sa_input_en <= 1'b1;
    sa_interface.sa_array_in <= 64'h0000_3c00_4000_4200; // 0 1 2 3 
    @(posedge tb_clk);
    sa_interface.sa_array_in <= 64'h0000_3c00_4000_4200; // 0 1 2 3 
    @(posedge tb_clk);
    sa_interface.sa_array_in <= 64'h4400_4500_4600_4700; // 4 5 6 7 
    @(posedge tb_clk);
    sa_interface.sa_array_in <= 64'h4400_4500_4600_4700; // 4 5 6 7
    @(posedge tb_clk);
    sa_interface.sa_input_en <= 1'b0;

    // Read output
    @(posedge sa_interface.sa_out_valid);
    sa_interface.sa_output_ready <= 1'b1;
    
    $display("\n=== TEST 1: 2x4 Matrix ===");
    $display("Input:    [[0,1,2,3], [4,5,6,7]]");
    $display("Weights:  All 1.0");
    $display("Expected: [6, 22]");
    $display("Actual:   [0x%h, 0x%h]", sa_interface.sa_array_output[0], sa_interface.sa_array_output[1]);
    
    if (sa_interface.sa_array_output[0] == 16'h4600 && 
        sa_interface.sa_array_output[1] == 16'h4D80) begin
        $display("Result:   PASS\n");
    end else begin
        $display("Result:   FAIL\n");
    end

    #CLK_PERIOD;
    @(posedge tb_clk)
    sa_interface.sa_output_ready <= 1'b0;
    #(CLK_PERIOD*10);

    // Reset
    tb_nrst <= 0;
    sa_interface.sa_array_in <= '0;
    sa_interface.sa_array_in_partials <= '0;
    sa_interface.sa_input_en <= '0;
    sa_interface.sa_weight_en <= '0;
    sa_interface.sa_partial_en <= '0;
    sa_interface.sa_output_ready <= '0;
    #(CLK_PERIOD*2);
    tb_nrst <= 1;
    #(CLK_PERIOD*2);

    // ========== TEST 2: 4x4 Matrix (Batch 1) ==========
    // Load weights
    @(posedge tb_clk)
    sa_interface.sa_array_in <= 64'h3c00_3c00_3c00_3c00;
    sa_interface.sa_weight_en <= 1'b1;
    #(CLK_PERIOD*4);
    sa_interface.sa_weight_en <= 1'b0;

    // Load rows 0-1
    sa_interface.sa_input_en <= 1'b1;
    @(posedge tb_clk);
    sa_interface.sa_array_in <= 64'h4400_4200_4000_3c00; // [1, 2, 3, 4]
    @(posedge tb_clk);
    sa_interface.sa_array_in <= 64'h4800_4700_4600_4500; // [5, 6, 7, 8]
    @(posedge tb_clk);
    sa_interface.sa_input_en <= 1'b0;
    
    // Read output
    @(posedge sa_interface.sa_out_valid);
    sa_interface.sa_output_ready <= 1'b1;
    out1_0 = sa_interface.sa_array_output[0];
    out1_1 = sa_interface.sa_array_output[1];
    #CLK_PERIOD;
    @(posedge tb_clk)
    sa_interface.sa_output_ready <= 1'b0;
    repeat(20) @(posedge tb_clk);
    
    // Reset for batch 2
    tb_nrst <= 0;
    sa_interface.sa_array_in <= '0;
    sa_interface.sa_array_in_partials <= '0;
    sa_interface.sa_input_en <= '0;
    sa_interface.sa_weight_en <= '0;
    sa_interface.sa_partial_en <= '0;
    sa_interface.sa_output_ready <= '0;
    #(CLK_PERIOD*2);
    tb_nrst <= 1;
    #(CLK_PERIOD*2);
    
    // ========== TEST 2: 4x4 Matrix (Batch 2) ==========
    // Reload weights
    @(posedge tb_clk)
    sa_interface.sa_array_in <= 64'h3c00_3c00_3c00_3c00;
    sa_interface.sa_weight_en <= 1'b1;
    #(CLK_PERIOD*4);
    sa_interface.sa_weight_en <= 1'b0;
    #(CLK_PERIOD*2);
    
    // Load rows 2-3
    sa_interface.sa_input_en <= 1'b1;
    @(posedge tb_clk);
    sa_interface.sa_array_in <= 64'h4a00_4980_4900_4880; // [9, 10, 11, 12]
    @(posedge tb_clk);
    sa_interface.sa_array_in <= 64'h4c00_4b80_4b00_4a80; // [13, 14, 15, 16]
    @(posedge tb_clk);
    sa_interface.sa_input_en <= 1'b0;

    // Read output
    @(posedge sa_interface.sa_out_valid);
    sa_interface.sa_output_ready <= 1'b1;
    out1_2 = sa_interface.sa_array_output[0];
    out1_3 = sa_interface.sa_array_output[1];
    #CLK_PERIOD;
    @(posedge tb_clk)
    sa_interface.sa_output_ready <= 1'b0;
    
    $display("\n=== TEST 2: 4x4 Matrix ===");
    $display("Input:    [[1,2,3,4], [5,6,7,8], [9,10,11,12], [13,14,15,16]]");
    $display("Weights:  All 1.0");
    $display("Expected: [10, 26, 42, 58]");
    $display("Actual:   [0x%h, 0x%h, 0x%h, 0x%h]", out1_0, out1_1, out1_2, out1_3);
    
    if (out1_0 == 16'h4900 && out1_1 == 16'h4E80 && 
        out1_2 == 16'h5140 && out1_3 == 16'h5340) begin
        $display("Result:   PASS\n");
    end else begin
        $display("Result:   FAIL\n");
    end

    #(CLK_PERIOD*8);
    $finish;
end

endmodule
