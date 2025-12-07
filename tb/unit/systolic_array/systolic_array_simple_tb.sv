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
// Test scenarios
always begin

    $dumpfile("waves/systolic_array_simple_waves.vcd");
    $dumpvars();

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

    @(posedge tb_clk); // all ones all hail wtm
    sa_interface.sa_array_in <= 64'h3c00_3c00_3c00_3c00;
    sa_interface.sa_weight_en <= 1'b1;
    #(CLK_PERIOD*4);
    sa_interface.sa_weight_en <= 1'b0;

    // input loading 
    @(posedge tb_clk);
    sa_interface.sa_input_en <= 1'b1;
    sa_interface.sa_array_in <= 64'h4200_4000_3c00_0000; // 0 1 2 3 
    
    @(posedge tb_clk);
    sa_interface.sa_array_in <= 64'h4200_4000_3c00_0000; // 0 1 2 3 
    
    @(posedge tb_clk);
    sa_interface.sa_array_in <= 64'h4700_4600_4500_4400; // 4 5 6 7 
    
    @(posedge tb_clk);
    sa_interface.sa_array_in <= 64'h4700_4600_4500_4400; // 4 5 6 7
    
    @(posedge tb_clk);
    sa_interface.sa_input_en <= 1'b0;

    @(posedge sa_interface.sa_out_valid);
    sa_interface.sa_output_ready <= 1'b1;
    
    #CLK_PERIOD;
    @(posedge tb_clk);
    sa_interface.sa_output_ready <= 1'b0;

    #(CLK_PERIOD*8);

    $finish;
end

endmodule

// expected outputs: [0,1,2,3], [0,1,2,3], [4,5,6,7], [4,5,6,7]