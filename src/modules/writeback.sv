/* Writeback Module */

`include "datapath_types.vh"
`include "isa_types.vh"
`include "writeback_if.vh"

module writeback
(
    input logic CLK, 
    input logic nRST,
    writeback_if.wb wbif // MATRIX LOAD STORE IF
);

// importing types
import datapath_pkg::*;
import isa_pkg::*;

// Mostly just pass through, need to handle to uncommon case where there both 
// alu and scalar L/S unit is needed to write back (For now Priortize L/S)

always_comb begin : Writeback

    wbif.wb_out.s_rw_en = 0;
    wbif.wb_out.s_rw = '0;
    wbif.wb_out.s_wdata = '0;
    wbif.wb_out.load_done = 0;
    wbif.wb_out.alu_done = 1;  

    if(wbif.load_ready && wbif.alu_ready)
    // If both ALU and Load Functional Units Ready to WB
    {
        wbif.wb_out.s_rw_en = 1;
        wbif.wb_out.s_rw = wbif.reg_sel_load;
        wbif.wb_out.s_wdata = wbif.dmemload;
    }
    else if (wbif.load_ready)
    // If Load is ready to WB
    {
        wbif.wb_out.s_rw_en = 1;
        wbif.wb_out.s_rw = wbif.reg_sel_load;
        wbif.wb_out.s_wdata = wbif.dmemload;
        wbif.wb_out.load_done = 1;  
    }
    else if (wbif.alu_ready)
    // If ALU is ready to WB
    {
        wbif.wb_out.s_rw_en = 1;
        wbif.wb_out.s_rw = wbif.reg_sel_alu;
        wbif.wb_out.s_wdata = wbif.alu_out;
        wbif.wb_out.alu_done = 1;  
    }
end






endmodule