`include "dram_pkg.sv"
`include "cpu_types_pkg.sv"
`include "ddr_controller_if.sv"


module nb_barb_tb;
    logic CLK, nRST;

    // clock
    always #(PERIOD/2) CLK++;
    
    ddr_controller_if ddrif;
    nb_barb DUT(CLK, nRST, ddrif);

    test PROG(CLK, nRST, ddrif);

    bind nb_barb nb_barb_prop barb_monitor(CLK, nRST, ddrif);

endmodule

program test(
    input logic CLK, nRST, 
    ddr_controller_if.backend_arb barb
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
        @(negedge CLK);


        $finish;
    end

endprogram