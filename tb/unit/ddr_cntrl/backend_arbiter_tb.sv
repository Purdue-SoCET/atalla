`include "dram_pkg.sv"
`include "cpu_types_pkg.sv"
`include "ddr_controller_if.sv"


module backend_arbiter_tb;
    logic CLK, nRST;

    // clock
    always #(PERIOD/2) CLK++;
    
    ddr_controller_if ddrif;
    backend_arbiter DUT(

    );

    initial begin
        nRST = 0;
        repeat (5) @(negedge CLK);
        nRST = 1;
    end

    test PROG(.barb(ddrif));
endmodule

program test(ddr_controller_if.backend_arb barb);


endprogram