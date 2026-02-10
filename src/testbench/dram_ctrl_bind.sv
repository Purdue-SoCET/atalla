`include "dram_pkg.vh"
`include "cpu_types_pkg.vh"

module ddr_ctrl_confirm(
    input logic CLK,
    input logic nRST
);
    import dram_pkg::*;
    import cpu_types_pkg::*;

    // PROPERTIES
    task check_one_hot(
        input logic smth
    );
        assert one_hot();
    endtask

    property one_hot;
        @(posedge clk); disable iff (rst)
        $onehot(); // Put one hot signal
    endproperty

    property tccd;
    
    endproperty

    property tFAW;
    endproperty

    property write_response;
    endproperty

    // ASSERTIONS
    assert property (one_hot)
        else $error("I guess bro");
        
endmodule 

