`include "fust_m_if.vh"
`include "datapath_types.vh"

module fust_m (
    input logic CLK, nRST,
    fust_m_if.FUSTM fuif
);

  import datapath_pkg::*;

  fust_m_t fust;
  
  always_ff @(posedge CLK, negedge nRST) begin
    if (~nRST)
      fuif.fust <= '0;
    else
      fuif.fust <= fust;
  end

  always_comb begin
    fust = fuif.fust;
   
    if (fuif.en) begin
      fust.op.busy = fuif.n_fust.busy;
      fust.op.rd   = fuif.n_fust.rd;
      fust.op.rs1  = fuif.n_fust.rs1;
      fust.op.rs2  = fuif.n_fust.rs2;
      fust.op.imm  = fuif.n_fust.imm;
      fust.op.t1   = fuif.n_fust.t1;
      fust.op.t2   = fuif.n_fust.t2;
      fust.op.t3   = fuif.n_fust.t3;
    end
  end

endmodule
