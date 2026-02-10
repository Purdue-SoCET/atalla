`ifndef DDR_CONTROL_PROP
`define DDR_CONTROL_PROP

`include "dram_pkg.vh"
`include "cpu_types_pkg.vh"

module ddr_control_prop;
    import dram_pkg::*;
    import cpu_types_pkg::*;
    // Stores properties to be used 

    task check_one_hot(
        input logic smth;
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

endmodule 
`endif // DDR_CONTROL_PROP

