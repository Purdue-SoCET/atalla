`timescale 1ns / 1ps

module sysarr_input_buffer_tb();

// Parameters
localparam CLK_PERIOD = 10;

// Testbench Signals
logic tb_clk;
logic tb_nrst;

logic [63:0] tb_in;
logic [63:0] tb_out;

logic tb_read_en, tb_write_en, tb_has_space, tb_empty;

// Clk init
always
begin
    tb_clk = 1'b0;
    #(CLK_PERIOD/2.0);
    tb_clk = 1'b1;
    #(CLK_PERIOD/2.0);
end

sysarr_input_buffer DUT (.nRST(tb_nrst), .clk(tb_clk), .in(tb_in), .out(tb_out), .read_en(tb_read_en), .write_en(tb_write_en), .has_space(tb_has_space), .empty(tb_empty));

integer i;
// Test scenarios
always begin

    $dumpfile("waves/sysarr_input_buffer_waves.vcd");
    $dumpvars();

    tb_write_en <= 0;
    tb_read_en <= 0;
    // tb_clk = 0;
    tb_in <= 64'hA123456789ABCDEF;

    tb_nrst <= 0;
    #CLK_PERIOD;
    tb_nrst <= 1;
    #CLK_PERIOD;

    @(posedge tb_clk)

    // Write first value to buffer
    tb_in <= 64'h1111222233334444;
    tb_write_en <= 1'b1;
    #CLK_PERIOD;
    tb_write_en <= 1'b0;
    
    // for sanity sake, here
    #CLK_PERIOD;

    // Read first value out of buffer
    tb_read_en <= 1'b1;
    #CLK_PERIOD;
    tb_read_en <= 1'b0;

    // now hammer it
    tb_in <= 64'h5555666677778888;
    tb_write_en <= 1'b1;
    #CLK_PERIOD;
    // At this point buffer should have values, can start reading
    tb_read_en <= 1'b1;  // should read 
    tb_in <= 64'h9999AAAABBBBCCCC;
    #CLK_PERIOD;
    tb_in <= 64'hDDDDEEEEFFFF1221;
    #CLK_PERIOD;
    tb_write_en <= 0;

    @(posedge tb_empty);

    @(posedge tb_clk);
    tb_read_en <= 1'b0;

    // Now repeat process.

    tb_read_en <= 0;

    // GSAU writes in a vector. Expects it to go into the systolic array.
    // GSAU can send a stream of vectors as long as sys array can take it.

    tb_in <= 64'h1111222233334444;
    tb_write_en <= 1'b1;
    #CLK_PERIOD;
    tb_read_en = 1'b1;
    tb_in <= 64'h5555666677778888;
    #CLK_PERIOD;
    tb_in <= 64'h9999AAAABBBBCCCC;
    #CLK_PERIOD;
    tb_in <= 64'hDDDDEEEEFFFF1221;
    #CLK_PERIOD;
    tb_write_en <= 1'b0;

    // Wait for buffer to not have space
    wait(tb_has_space == 1'b0)
    @(posedge tb_clk);

    tb_read_en <= 1'b1;

    #(CLK_PERIOD*4)
    $finish;
end

endmodule
