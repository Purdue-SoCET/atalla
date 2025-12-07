`timescale 1ns / 1ps
`include "gsau_control_unit_if.vh"


module sysarr_input_simple_tb();

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

integer i;
integer output_count;

// Test scenarios
always begin

    $dumpfile("waves/systolic_array_simple_waves.vcd");
    $dumpvars();
    
    output_count = 0;

    // Initialize all signals
    sa_interface.sa_array_in <= '0;
    sa_interface.sa_array_in_partials <= '0;
    sa_interface.sa_input_en <= '0;
    sa_interface.sa_weight_en <= '0;
    sa_interface.sa_partial_en <= '0;
    sa_interface.sa_output_ready <= '0;

    // Reset sequence
    tb_nrst <= 0;
    #CLK_PERIOD;
    tb_nrst <= 1;
    #CLK_PERIOD;

    // ========================================
    // STEP 1: Load weights (all 1.0 = 0x3c00)
    // ========================================
    // Load 4 columns of weights over 4 cycles to fill 4x4 array
    @(posedge tb_clk);
    sa_interface.sa_weight_en <= 1'b1;
    sa_interface.sa_array_in <= 64'h3c00_3c00_3c00_3c00;  // Column 0: all 1.0
    
    @(posedge tb_clk);
    sa_interface.sa_array_in <= 64'h3c00_3c00_3c00_3c00;  // Column 1: all 1.0
    
    @(posedge tb_clk);
    sa_interface.sa_array_in <= 64'h3c00_3c00_3c00_3c00;  // Column 2: all 1.0
    
    @(posedge tb_clk);
    sa_interface.sa_array_in <= 64'h3c00_3c00_3c00_3c00;  // Column 3: all 1.0
    
    @(posedge tb_clk);
    sa_interface.sa_weight_en <= 1'b0;
    sa_interface.sa_array_in <= '0;

    // Wait a couple cycles after weight loading
    #(CLK_PERIOD*2);
    
    $display("\n========================================");
    $display("WEIGHT LOADING COMPLETE");
    $display("All weights set to 1.0 (0x3c00)");
    $display("========================================\n");

    // ========================================
    // STEP 2: Load input columns
    // ========================================
    // Using simple distinct values for easy verification:
    // Column 0: [1.0, 2.0, 3.0, 4.0] = [0x3c00, 0x4000, 0x4200, 0x4400]
    // Column 1: [2.0, 2.0, 2.0, 2.0] = [0x4000, 0x4000, 0x4000, 0x4000]
    // Column 2: [3.0, 3.0, 3.0, 3.0] = [0x4200, 0x4200, 0x4200, 0x4200]
    // Column 3: [4.0, 4.0, 4.0, 4.0] = [0x4400, 0x4400, 0x4400, 0x4400]
    
    @(posedge tb_clk);
    sa_interface.sa_input_en <= 1'b1;
    sa_interface.sa_array_in <= 64'h4400_4200_4000_3c00;  // Column 0: [1.0, 2.0, 3.0, 4.0]
    
    @(posedge tb_clk);
    sa_interface.sa_array_in <= 64'h4000_4000_4000_4000;  // Column 1: [2.0, 2.0, 2.0, 2.0]
    
    @(posedge tb_clk);
    sa_interface.sa_array_in <= 64'h4200_4200_4200_4200;  // Column 2: [3.0, 3.0, 3.0, 3.0]
    
    @(posedge tb_clk);
    sa_interface.sa_array_in <= 64'h4400_4400_4400_4400;  // Column 3: [4.0, 4.0, 4.0, 4.0]
    
    @(posedge tb_clk);
    sa_interface.sa_input_en <= 1'b0;
    sa_interface.sa_array_in <= '0;
    
    $display("\n========================================");
    $display("INPUT LOADING COMPLETE");
    $display("Column 0: [1.0, 2.0, 3.0, 4.0]");
    $display("Column 1: [2.0, 2.0, 2.0, 2.0]");
    $display("Column 2: [3.0, 3.0, 3.0, 3.0]");
    $display("Column 3: [4.0, 4.0, 4.0, 4.0]");
    $display("========================================\n");

    // ========================================
    // STEP 3: Wait for and read outputs
    // ========================================
    $display("Waiting for outputs...\n");

    // Read all 4 output columns
    for (output_count = 0; output_count < 4; output_count++) begin
        @(posedge sa_interface.sa_out_valid);
        sa_interface.sa_output_ready <= 1'b1;
        
        $display("========================================");
        $display("OUTPUT COLUMN %0d", output_count);
        $display("========================================");
        $display("Raw output: 0x%h", sa_interface.sa_array_output);
        $display("Element [0]: 0x%h", sa_interface.sa_array_output[15:0]);
        $display("Element [1]: 0x%h", sa_interface.sa_array_output[31:16]);
        $display("Element [2]: 0x%h", sa_interface.sa_array_output[47:32]);
        $display("Element [3]: 0x%h", sa_interface.sa_array_output[63:48]);
        
        case(output_count)
            0: begin
                $display("\nEXPECTED: [1.0, 2.0, 3.0, 4.0]");
                $display("EXPECTED: [0x3c00, 0x4000, 0x4200, 0x4400]");
                if (sa_interface.sa_array_output == 64'h4400_4200_4000_3c00)
                    $display("✓ PASS: Output matches expected!");
                else
                    $display("✗ FAIL: Output does not match!");
            end
            1: begin
                $display("\nEXPECTED: [2.0, 2.0, 2.0, 2.0]");
                $display("EXPECTED: [0x4000, 0x4000, 0x4000, 0x4000]");
                if (sa_interface.sa_array_output == 64'h4000_4000_4000_4000)
                    $display("✓ PASS: Output matches expected!");
                else
                    $display("✗ FAIL: Output does not match!");
            end
            2: begin
                $display("\nEXPECTED: [3.0, 3.0, 3.0, 3.0]");
                $display("EXPECTED: [0x4200, 0x4200, 0x4200, 0x4200]");
                if (sa_interface.sa_array_output == 64'h4200_4200_4200_4200)
                    $display("✓ PASS: Output matches expected!");
                else
                    $display("✗ FAIL: Output does not match!");
            end
            3: begin
                $display("\nEXPECTED: [4.0, 4.0, 4.0, 4.0]");
                $display("EXPECTED: [0x4400, 0x4400, 0x4400, 0x4400]");
                if (sa_interface.sa_array_output == 64'h4400_4400_4400_4400)
                    $display("✓ PASS: Output matches expected!");
                else
                    $display("✗ FAIL: Output does not match!");
            end
        endcase
        $display("========================================\n");
        
        #CLK_PERIOD;
        @(posedge tb_clk);
        sa_interface.sa_output_ready <= 1'b0;
        #CLK_PERIOD;
    end

    $display("\n========================================");
    $display("TEST COMPLETE");
    $display("========================================\n");

    #(CLK_PERIOD*5);
    $finish;
end

endmodule