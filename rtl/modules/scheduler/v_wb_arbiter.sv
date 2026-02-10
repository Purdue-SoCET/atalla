// Vector Writeback Arbiter Module ============================================
// Author: Michael Lee
// Email: lee4279@purdue.edu
// Arbitrates vector core vector writeback to remove bank conflicts and 
// prioritize GSAU->Reduction->Lanes 
// TODO 
// insert VLSU?? (as lanes) 
// fix handshake timing
// check priority
// ============================================================================
`include "v_wb_arbiter_if.vh"
`include "vector_pkg.vh"

module v_wb_arbiter (
    input logic CLK, nRST,
    v_wb_arbiter_if.v_wb_arbiter vif
); 
    import vector_pkg::*;
    logic [6:0] req; 
    vsel_t [6:0] vds;
    vreg_t [6:0] datas;

    logic [3:0][6:0] g;
    logic [1:0][1:0] banksused

    // priority is encoded here lsb is high msb is low lanes are same but cannot be prioed here easily
    assign req = {vif.vector_out.valid_o, vif.vector_out.reduction_valid, vif.vector_out.gsau.wb_valid};
    assign vds = {vif.vector_out.vd, vif.vector_out.reduction_vd, vif.vector_out.gsau.wb_wbdst};
    assign datas = {vif.vector_out.result, vif.vector_out.reduction_result, vif.vector_out.gsau.wb_psum};

    // Extract bank ID for each request (Need to split like this?)
    assign banks[0] = vds[0][7:6]; 
    assign banks[1] = vds[1][7:6];
    assign banks[2] = vds[2][7:6]; 
    assign banks[3] = vds[3][7:6];
    assign banks[4] = vds[4][7:6]; 
    assign banks[5] = vds[5][7:6];
    assign banks[6] = vds[6][7:6];

    // Grant ports to a request g[port][source req]
    // A source is granted a port if it is requesting AND not taken by a higher port
    // AND has no bank conflict with registers chosen by higher-priority ports.
    
    // TODO update bank logic after every grant check its port then set mask? NEED TO CHANGE MASK STRUCTURE
    always_comb begin
        // Port 0 Priority encoder (no conflicts possible)
        g[0][0] = req[0];
        g[0][1] = req[1] && !g[0][0];
        g[0][2] = req[2] && !(|g[0][1:0]);
        g[0][3] = req[3] && !(|g[0][2:0]);
        g[0][4] = req[4] && !(|g[0][3:0]);
        g[0][5] = req[5] && !(|g[0][4:0]);
        g[0][6] = req[6] && !(|g[0][5:0]);

        
        // Port 1 Check bank conflict with port 0
        banksused[0] = banks[g[0]]

        g[1][0] = req[0] && (banks[req[0]] != banksused [0x]);
        g[1][1] = req[1] && !m1[1] && !g[1][0];
        g[1][2] = req[2] && !m1[2] && !(|g[1][1:0]);
        g[1][3] = req[3] && !m1[3] && !(|g[1][2:0]);
        g[1][4] = req[4] && !m1[4] && !(|g[1][3:0]);
        g[1][5] = req[5] && !m1[5] && !(|g[1][4:0]);
        g[1][6] = req[6] && !m1[6] && !(|g[1][5:0]);

        // Port 2 Check bank conflict with port 0 1
        
        g[2][0] = req[0] && !m2[0];
        g[2][1] = req[1] && !m2[1] && !g[2][0];
        g[2][2] = req[2] && !m2[2] && !(|g[2][1:0]);
        g[2][3] = req[3] && !m2[3] && !(|g[2][2:0]);
        g[2][4] = req[4] && !m2[4] && !(|g[2][3:0]);
        g[2][5] = req[5] && !m2[5] && !(|g[2][4:0]);
        g[2][6] = req[6] && !m2[6] && !(|g[2][5:0]);

        // Port 2 Check bank conflict with port 0 1 2
        
        g[3][0] = req[0] && !m3[0];
        g[3][1] = req[1] && !m3[1] && !g[3][0];
        g[3][2] = req[2] && !m3[2] && !(|g[3][1:0]);
        g[3][3] = req[3] && !m3[3] && !(|g[3][2:0]);
        g[3][4] = req[4] && !m3[4] && !(|g[3][3:0]);
        g[3][5] = req[5] && !m3[5] && !(|g[3][4:0]);
        g[3][6] = req[6] && !m3[6] && !(|g[3][5:0]);
    end

    // Output Mapping
    // Port 0 Assignments
    assign vif.veggie_in.WEN[0]   = |g[0];
    assign vif.veggie_in.vd[0]    = g[0][0] ? vds[0] : g[0][1] ? vds[1] : g[0][2] ? vds[2] : g[0][3] ? vds[3] : g[0][4] ? vds[4] : g[0][5] ? vds[5] : vds[6];
    assign vif.veggie_in.vdata[0] = g[0][0] ? datas[0] : g[0][1] ? datas[1] : g[0][2] ? datas[2] : g[0][3] ? datas[3] : g[0][4] ? datas[4] : g[0][5] ? datas[5] : datas[6];

    // Port 1 Assignments
    assign vif.veggie_in.WEN[1]   = |g[1];
    assign vif.veggie_in.vd[1]    = g[1][0] ? vds[0] : g[1][1] ? vds[1] : g[1][2] ? vds[2] : g[1][3] ? vds[3] : g[1][4] ? vds[4] : g[1][5] ? vds[5] : vds[6];
    assign vif.veggie_in.vdata[1] = g[1][0] ? datas[0] : g[1][1] ? datas[1] : g[1][2] ? datas[2] : g[1][3] ? datas[3] : g[1][4] ? datas[4] : g[1][5] ? datas[5] : datas[6];

    // Port 2 Assignments
    assign vif.veggie_in.WEN[2]   = |g[2];
    assign vif.veggie_in.vd[2]    = g[2][0] ? vds[0] : g[2][1] ? vds[1] : g[2][2] ? vds[2] : g[2][3] ? vds[3] : g[2][4] ? vds[4] : g[2][5] ? vds[5] : vds[6];
    assign vif.veggie_in.vdata[2] = g[2][0] ? datas[0] : g[2][1] ? datas[1] : g[2][2] ? datas[2] : g[2][3] ? datas[3] : g[2][4] ? datas[4] : g[2][5] ? datas[5] : datas[6];

    // Port 3 Assignments
    assign vif.veggie_in.WEN[3]   = |g[3];
    assign vif.veggie_in.vd[3]    = g[3][0] ? vds[0] : g[3][1] ? vds[1] : g[3][2] ? vds[2] : g[3][3] ? vds[3] : g[3][4] ? vds[4] : g[3][5] ? vds[5] : vds[6];
    assign vif.veggie_in.vdata[3] = g[3][0] ? datas[0] : g[3][1] ? datas[1] : g[3][2] ? datas[2] : g[3][3] ? datas[3] : g[3][4] ? datas[4] : g[3][5] ? datas[5] : datas[6];

    // TODO Ready feedback FIX FIX FIX
    assign vif.vector_out.gsau.veg_ready = g[0][0] | g[1][0] | g[2][0] | g[3][0];
    assign vif.vector_out.ready_o        = g[0][6:2] | g[1][6:2] | g[2][6:2] | g[3][6:2];

endmodule
    
