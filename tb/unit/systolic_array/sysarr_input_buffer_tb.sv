`timescale 1ns / 1ps

module sysarr_input_buffer_tb();

// Parameters
localparam CLK_PERIOD = 1;

// Testbench Signals
logic tb_clk;
logic tb_nrst;

logic [63:0] tb_in;
logic [63:0] tb_out;

logic tb_read_en, tb_write_en, tb_has_space;

// Clk init
always
begin
    tb_clk = 1'b0;
    #(CLK_PERIOD/2.0);
    tb_clk = 1'b1;
    #(CLK_PERIOD/2.0);
end

sysarr_input_buffer DUT (.nRST(tb_nrst), .clk(tb_clk), .in(tb_in), .out(tb_out), .read_en(tb_read_en), .write_en(tb_write_en), .has_space(tb_has_space));

integer i;
// Test scenarios
initial begin

    $dumpfile("waves/sysarr_input_buffer_waves.vcd");
    $dumpvars();

    tb_nrst = 0;
    #CLK_PERIOD;
    tb_nrst = 1;

    // Initialize signals
    tb_write_en = 0;
    tb_read_en = 0;
    // tb_clk = 0;
    tb_in = 64'hA123456789ABCDEF;

    // tb_nrst = 0;

    // #CLK_PERIOD;
    // tb_nrst = 1;
    // #CLK_PERIOD;

    tb_in = 64'hA123456789ABCDEF;
    @(posedge tb_clk)
    #(CLK_PERIOD * 4);

    
    tb_write_en = 1'b1;
    #CLK_PERIOD;
    tb_write_en = 1'b0;

    #(CLK_PERIOD);

    tb_read_en = 1'b1;
    #CLK_PERIOD;
    tb_read_en = 1'b0;


    

    

    #(CLK_PERIOD * 4);
    $finish;
end

endmodule
