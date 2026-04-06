`include "axi_bus_pkg.sv"
import axi_bus_pkg::*;

module axi_write_arbiter_sva(
    input logic               CLK,
    input logic               nRST,
    input logic               sp0_req_w,
    input logic               sp1_req_w,
    input logic               d_req_w, 
    input logic [AWLEN-1:0]   sp0_len_w,
    input logic [AWLEN-1:0]   sp1_len_w,
    input logic [AWLEN-1:0]   d_len_w, 
    input logic               skid_ready_w,
    input logic [AWGRANT-1:0] aw_grant,
    input logic [3:0]         counter,
    input logic [2:0]         state               
);

    // TEST CASE 1: RESET INIT STATE
    // property reset_init_state;
    //     @(posedge CLK)
    //     (!nRST) |=> (state == IDLE && counter == '0 && aw_grant == 3'b000);
    // endproperty

    // assert property (reset_init_state)
    //     else $error("FAILED TEST CASE 1: RESET INIT STATE");


endmodule