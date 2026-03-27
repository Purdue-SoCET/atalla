`timescale 1ps/1ps
`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;

// RESPONSE TRANSACTIONS
class axi_write_rsp;
    rand logic [MID_BID-1:0] mid_id;
    rand logic [BID-1:0]     id;
    bresp_t             resp = B_OKAY;

    constraint id_match {
        mid_id[BID-1:0] == id;
    }
    constraint valid_master {
        mid_id[MID_BID-1:BID] inside {2'b00, 2'b01, 2'b10};
    }
endclass

// Generator
class axi_generator_rsp;
    // fucntion <return_type> <fucntion_name>()
    function axi_write_rsp generate_rsp();
        axi_write_rsp rsp; // creates handle
        rsp = new(); // constructs object
        if (!rsp.randomize()) begin
            $fatal("Randomization failed");
        end
        return rsp;
    endfunction
endclass

// Driver 
//class axi_driver;
    //virtual axi


module axi_write_response_tb ();
    parameter CLK_PERIOD = 10;
    logic CLK = 0, nRST;
    string test_case = "";

    // clock
    always #(CLK_PERIOD/2) CLK++;

    // interface
    axi_bus_if busif(.CLK(CLK), .nRST(nRST));

    // DUT 
    axi_write_response DUT (.CLK(CLK), 
                            .nRST(nRST),
                            .b_i_if(busif),
                            .sp0_b_o_if(busif),
                            .sp1_b_o_if(busif),
                            .d_b_o_if(busif));

    task reset_dut;
    begin
        test_case = "RESET ON DUT";
        nRST = 0;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        nRST = 1;
        $display("TB: reset released");
        @(posedge CLK);
        @(posedge CLK);
    end
    endtask


endmodule