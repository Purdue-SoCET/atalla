`include "ddr_controller_if.vh"
`timescale 1 ns / 1 ps

module nb_wdata_queue_fifo_tb;
    // parameters
    logic CLK, nRST;

    // clock
    always #(PERIOD/2) CLK++;

    // interfaces/modports
    ddr_controller_if ddrif();

    // instantiations
    wdata_queue_fifo DUT(CLK, nRST, ddrif);

    test PROG(CLK, nRST, ddrif);

    bind wdata_queue_fifo nb_wdata_queue_prop wdata_monitor(CLK, nRST, ddrif);
endmodule

program test(
    input logic CLK, nRST,
    ddr_controller_if.wdata_queue wdq
);
    task reset_dut();
        begin
            nRST = 0;
            repeat (5) @(negedge CLK);
            nRST = 1;
        end
    endtask

    initial begin 
        nRST = 1;
        reset_dut();


        $finish;
    end
endprogram