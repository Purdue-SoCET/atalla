// fust gets written do in dispatch on clock edge
// issue should read registers and issue to execute by the next clock edge
`include "datapath_types.vh"
`include "issue_if.vh"
`include "regfile_if.vh"

module issue(
    input logic CLK, nRST,
    issue_if.IS isif
);

    import isa_pkg::*;
    import datapath_pkg::*;

    // Instantiations
    regfile_if rfif();
    regfile(CLK, nRST, rfif);

    // Local Variables
    logic hazard;
    fust_s_t fust_s;
    fust_m_t fust_m;
    fust_g_t fust_g;
    issue_t n_issue;
    issue_t issue;
    regbits_t s_rs1, s_rs2;
    fust_s_t fust_s;
    fust_m_t fust_m;
    fust_g_t fust_g;

    always_ff @ (posedge CLK, negedge nRST) begin: Pipeline_Latching
      if (~nRST)
        isif.out <= '0;
    	else
        isif.out <= n_issue;
    end

    always_comb begin : Regfile
      rfif.wen = isif.wb.s_rw_en;
      rfif.wsel = isif.wb.s_rw;
      rfif.wdata = isif.wb.s_wdata;
      rfif.rsel1 = s_rs1;
      rfif.rsel2 = s_rs2;
    end

    always_comb begin : Pipeline_Output
      case (1'b1)
        isif.freeze: n_issue = isif.out; //need to think of cases for freezes/flushes
        default:     n_issue = issue; //can issue regardless of ihit i think?
      endcase
    end

    always_comb begin : Hazard_Logic

    end

    always_comb begin : FUST //connected in datapath from dispatch.out.fust_s/m/g
      
    end

    always_comb begin : Issue_Out
      issue = isif.out;

    end
endmodule

