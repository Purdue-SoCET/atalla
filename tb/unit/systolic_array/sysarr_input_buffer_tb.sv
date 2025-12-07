`timescale 1ns / 1 ns


module sysarr_input_buffer_tb();

// Parameters
parameter PERIOD = 10;

// Testbench Signals
logic tb_clk = 0;
logic tb_nrst;

logic [63:0] tb_in;
logic [63:0] tb_out;

logic tb_read_en, tb_write_en, tb_has_space;

// Clk init
always
begin
    tb_clk = 1'b0;
    #(PERIOD/2.0);
    tb_clk = 1'b1;
    #(PERIOD/2.0);
end

sysarr_input_buffer DUT (.nRST(tb_nrst), .clk(tb_clk), .in(tb_in), .out(tb_out), .read_en(tb_read_en), .write_en(tb_write_en), .has_space(tb_has_space));

integer i;
// Test scenarios
initial begin

    $dumpfile("waves/sysarr_input_buffer_waves.vcd");
    $dumpvars();

    // Initialize signals
    tb_clk = 0;
    tb_nrst = 0;
    #PERIOD;
    tb_nrst = 1;
    #PERIOD;

    tb_in = 64'hA123456789ABCDEF;
    #(PERIOD * 4);

    @(posedge tb_clk);
    tb_write_en = 1'b1;
    #PERIOD;
    tb_write_en = 1'b0;

    #(PERIOD);

    tb_read_en = 1'b1;
    #PERIOD;
    tb_read_en = 1'b0;


    

    

    #(PERIOD * 4);
    $finish;
end

endmodule
