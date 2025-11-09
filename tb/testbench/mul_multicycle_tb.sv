`timescale 1ns/1ps

`include "systolic_array_MAC_if.vh"

// to run this: verilator --binary -j 0 -Wall -Wno-fatal MAC_unit_tb -IMAC_unit -Itestbench -Iinclude --hierarchical --trace
// ./obj_dir/VMAC_unit_tb
// gtkwave waves.vcd --save=mac_debug.gtkw

// to run this: verilator --binary -j 0 -Wall -Wno-fatal MAC_unit_tb -Imodules -Itestbench -Iinclude --hierarchical --trace; ./obj_dir/VMAC_unit_tb; gtkwave waves.vcd --save=mac_debug.gtkw


/* verilator lint_off UNUSEDSIGNAL */
module mul_multicycle_tb;

    // Parameters
    localparam CLK_PERIOD = 1;

    // Testbench Signals
    logic tb_clk;
    logic tb_nrst;


    // Clk init
    always
    begin
        tb_clk = 1'b0;
        #(CLK_PERIOD/2.0);
        tb_clk = 1'b1;
        #(CLK_PERIOD/2.0);
    end
    
    // sysarr_control_unit_if instance
    // systolic_array_MAC_if mac_if();
    logic count, next_count;
    logic[12:0] op1, op2, out;
    logic start, stop, overflow, round_loss;

    mul_multicycle idkwhattocallyou (tb_clk, tb_nrst, start, stop, op1, op2, out, overflow, round_loss);

    
    // Test sequence
    initial begin
        // Initialize interface signals
        $dumpfile("waves.vcd");
        $dumpvars();
        tb_nrst = 0;
        #CLK_PERIOD;
        tb_nrst = 1;

        @(posedge tb_clk);
        #(CLK_PERIOD * 2);
        stop = 0;
        op1 = 34;
        op2 = 42;
        start = 1;
        #CLK_PERIOD;
        start = 0;
        #(CLK_PERIOD*13)
        stop = 1;
        #CLK_PERIOD;


        #(CLK_PERIOD * 6) 

        $finish;
    end

endmodule

