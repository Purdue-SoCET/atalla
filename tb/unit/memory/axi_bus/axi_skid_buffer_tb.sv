`timescale 1ps/1ps
`include "axi_bus_pkg.sv"

module axi_skid_buffer_tb;

    import axi_bus_pkg::*;

    parameter PERIOD = 10;

    logic CLK=0, nRST;
    always #(PERIOD/2) CLK++;

    // inputs
    // input master_r_channel_t in,
    // input logic ready, selected, in_val,
    // output master_r_channel_t out,
    // output logic out_val
    master_r_channel_t r_in, r_out;
    logic ready, selected, in_val, out_val;

    axi_skid_buffer DUT (
        .r_in(r_in),
        .r_out(r_out),
        .in_val(in_val),
        .out_val(out_val),
        .ready(ready),
        .selected(selected)
    );

    task reset;
        nRST = 0;
        repeat (3) @(negedge CLK);
        nRST = 1;
        repeat (3) @(negedge CLK);
    endtask

    initial begin
        reset;


        $finish;
    end

endmodule

