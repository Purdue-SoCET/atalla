// PIPELINE PACKAGES
`include "pipeline_types.vh"

// INTERFACES
`include "fetch_if.vh"
`include "dispatch_if.vh"
`include "issue_if.vh"
`include "regfile_if.vh"
`include "fu_branch_if.vh"
`include "fu_alu_if.vh"
`include "fu_scalar_ls_if.vh"
`include "fu_scalar_ls_if.vh"
`include "fu_matrix_ls_if.vh"
`include "fu_gemm_if.vh"
`include "fu_branch_pred.vh"

module sc_datapath
(
    input logic CLK, nrst,
    datapath_cache_if.dp dpif
);
    fetch_if fif();
    fetch FETCH (CLK, nrst, fif);

    scoreboard_if sbif();
    scoreboard SCOREBOARD (CLK, nsrt, sbif);

    dispatch_if dif();
    dispatch DISPATCH (CLK, nrst, dif);
    
    issue_if isif();
    issue ISSUE (CLK, nrst, isif)
    
    regfile_if rfif();
    regfile REGFILE (CLK, nrst, fuif);

    fu_branch_if fubif();
    fu_branch FUBRANCH (CLK, nrst, fubif);

    fu_alu_if fualuif();
    fu_alu FUALU (CLK, nrst, fuaif);

    fu_scalar_ls_if fuslsif();
    fu_scalar_ls FUSCALARLS (CLK, nrst, fuslsif);

    fu_matrix_ls_if fumlsif();
    fu_matrix_ls FUMATRIXLS (CLK, nrst, fumlsif);

    fu_gemm_if fugif();
    fu_gemm FUGEMM (CLK, nrst, fugif);

    fu_branchpred_if fubpif();
    fu_branchpred FUBRANCHPRED (CLK, nrst, fubpif);

    writeback_if wbif();
    writeback WRITEBACK (CLK, nrst, wbif);

// IMPORT PACKAGE
    import pipeline_pkg::*;

// LATCH INSTANTIATIONS

    fd_t fd_fetch;
    fd_t fd_dispatch;

    ie_t ie_issue;
    ie_t ie_execute;

    ew_t ew_execute;
    ew_t ew_writeback;

//  FETCH/DISPATCH CONNECTIONS
    
    //BEFORE LATCH
    assign fd_fetch.instr = fif.instr;
    assign fd_fetch.pc = fif.pc;

    //AFTER LATCH CONNECTIONS
    assign sbif.fetch = fd_dispatch.instr;

    //DISPATCH TO ISSUE CONNECTIONS
    // assign dif.n_fust_s = isif.n_fust_s;
    // assign dif.n_fust_m = isif.n_fust_m;
    // assign dif.n_fust_g = isif.n_fust_g;
    // assign dif.n_fu_s = isif.n_fu_s;
    // assign dif.n_fust_s_en = isif.n_fust_s_en;
    // assign dif.n_fust_m_en = isif.n_fust_m_en;
    // assign dif.n_fust_g_en = isif.dif.n_fust_g_en;
    // assign dif.fust_s = isif.fust_s;
    // assign dif.fust_m = isif.fust_m;
    // assign dif.fust_g = isif.fust_g;

    // //ISSUE TO DISPATCH CONNECTIONS
    // assign isif.dispatch = diif.out;
    // assign isif.flush = sbif.flush;
    // assign isif.freeze = sbif.freeze;
    // assign isif.wb = sbif.wb;
    // assign isif.n_fust_s = diif.n_fust_s;
    // assign isif.n_fust_m = diif.n_fust_m;
    // assign isif.n_fust_g = diif.n_fust_g;
    // assign isif.n_fu_s = diif.n_fu_s;
    // assign isif.n_fust_s_en = diif.n_fust_s_en;
    // assign isif.n_fust_m_en = diif.n_fust_m_en;
    // assign isif.n_fust_g_en = diif.n_fust_g_en;

    // //REGISTER FILE TO ISSUE CONNECTIONS
    // rfif.WEN   = isif.wb.s_rw_en;
    // rfif.wsel  = isif.wb.s_rw;
    // rfif.wdata = isif.s_wdata;

//  ISSUE/EXECUTE CONNECTIONS

    //BEFORE LATCH
    assign ie_issue.rdat1 = rfif.rdat1;
    assign ie_issue.rdat2 = rfif.rdat2;
    assign ie_issue.out = sbif.out;
    assign ie_issue.fust_s = isif.fust_s;
    assign ie_issue.fust_m = isif.fust_m;
    assign ie_issue.fust_g = isif.fust_g;
    assign ie_issue.pc = fd_dispatch.pc;

    //AFTER LATCH CONNECTIONS
    assign fuslsif.rdat1 = ie_execute.rdat1;
    assign fuslsif.rdat2 = ie_execute.rdat2;
    assign fubif.pc = ie_execute.pc;
    
    //BRANCH FU TO FETCH CONNECTIONS
    assign fubif.pc_fetch = fif.pc; //maybe need this idk

    //FU TO

    //FETCH TO BRANCH FU CONNECTIONS
    assign fif.pc_prediction = fubif.pred_outcome;
    assign fif.correct_target = fubif.pred_target;
    
    //WRITEBACK TO SCALAR ALU FU CONNECTIONS
    assign wbif.wb_select = fuslsif.dmemaddr;
    assign wbif.store_out = fuslsif.dmemstore;
    
    //WRITEBACK TO SCALAR LOAD/STORE FU CONNECTIONS
    assign wbif.alu_out = fualuif.port_output;

//  EXECUTE/WRITEBACK CONNECTIONS
    
    //BEFORE LATCH
    assign ew_execute.wb_data = wbif.wb_out;

    //AFTER LATCH
    assign sbif.wb = ew_writeback.wb;

// FLIP-FLOP FOR LATCHES

    always_ff @ (posedge CLK, negedge nrst) begin
    {
        if (nrst == 0)
        {
            fd_dispatch <= 0;
            ie_execute <= 0;
            ew_writeback <= 0;
        }
        else
        {
            fd_dispatch <= fd_fetch;
            ie_execute <= ie_issue;
            ew_writeback <= ew_execute;
        }
    }
    end

endmodule