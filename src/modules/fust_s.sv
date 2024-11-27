`include "fust_s_if.vh"
`include "datapath_types.vh"

module fust_s (
    input logic CLK, nRST,
    fust_s_if.FUSTS fuif
);

  import datapath_pkg::*;

  fust_s_t fust;
  
  always_ff @(posedge CLK, negedge nRST) begin
    if (~nRST)
      fuif.fust <= '0;
    else
      fuif.fust <= fust;
  end

  always_comb begin
    fust = fuif.fust;
   
    if (fuif.en) begin
      fust.op[fuif.fu].busy = fuif.n_fust.busy;
      fust.op[fuif.fu].rd   = fuif.n_fust.rd;
      fust.op[fuif.fu].rs1  = fuif.n_fust.rs1;
      fust.op[fuif.fu].rs2  = fuif.n_fust.rs2;
      fust.op[fuif.fu].imm  = fuif.n_fust.imm;
      fust.op[fuif.fu].t1   = fuif.n_fust.t1;
      fust.op[fuif.fu].t2   = fuif.n_fust.t2;
    end
  end

endmodule
