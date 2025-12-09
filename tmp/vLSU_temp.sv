`include "vlsu_if_temp.vh"
`include "../include/scpad_params.svh"

module vLSU_temp #(
    parameter int FIFO_DEPTH = 13,
    parameter int VD_BITS = 8
) (
    input  logic                CLK,
    input  logic                nRST,
    vlsu_if_temp.vlsu           vlsuif,     // instruction-level interface (temp)
    scpad_if.frontend_vec       scpad_sp0,  // connect to SP0 frontend_vec modport
    scpad_if.frontend_vec       scpad_sp1   // connect to SP1 frontend_vec modport
);

  import scpad_pkg::*;

  // FIFO signals for SP0
  logic                    fifo0_wr, fifo0_shift;
  logic [VD_BITS-1:0]      fifo0_din, fifo0_dout;
  logic                    fifo0_empty, fifo0_full;

  // FIFO signals for SP1
  logic                    fifo1_wr, fifo1_shift;
  logic [VD_BITS-1:0]      fifo1_din, fifo1_dout;
  logic                    fifo1_empty, fifo1_full;

  // FIFOs track pending loads (store does not use FIFO)
  sync_fifo #(.FIFODEPTH(FIFO_DEPTH), .DATAWIDTH(VD_BITS)) sp0_fifo (
    .nRST(nRST), .CLK(CLK),
    .wr_en(fifo0_wr), .shift(fifo0_shift),
    .din(fifo0_din), .dout(fifo0_dout),
    .empty(fifo0_empty), .full(fifo0_full)
  );

  sync_fifo #(.FIFODEPTH(FIFO_DEPTH), .DATAWIDTH(VD_BITS)) sp1_fifo (
    .nRST(nRST), .CLK(CLK),
    .wr_en(fifo1_wr), .shift(fifo1_shift),
    .din(fifo1_din), .dout(fifo1_dout),
    .empty(fifo1_empty), .full(fifo1_full)
  );

  always_comb begin
    // defaults
    fifo0_wr = 1'b0; fifo0_shift = 1'b0; fifo0_din = '0;
    fifo1_wr = 1'b0; fifo1_shift = 1'b0; fifo1_din = '0;

    scpad_sp0.vec_req = '0;
    scpad_sp1.vec_req = '0;

    // clear pass-through outputs
    vlsuif.req_valid    = 1'b0;
    vlsuif.req_op       = '0;
    vlsuif.req_sid      = '0;
    vlsuif.req_rc       = '0;
    vlsuif.req_rc_id    = '0;
    vlsuif.req_num_rows = '0;
    vlsuif.req_num_cols = '0;
    vlsuif.req_rs1      = '0;
    vlsuif.req_vd       = '0;

    // clear writeback notifications
    vlsuif.sp0_load_valid = 1'b0;
    vlsuif.sp0_veg_dst_idx = '0;
    vlsuif.sp1_load_valid = 1'b0;
    vlsuif.sp1_veg_dst_idx = '0;

    // ready: stores (op==0) don't require FIFO; loads (op==1) require selected FIFO not full
    vlsuif.ready = vlsuif.valid &&
                   (!vlsuif.op || (vlsuif.sid ? !fifo1_full : !fifo0_full));

    // accept & forward instruction
    if (vlsuif.valid && vlsuif.ready) begin
      vlsuif.req_valid    = 1'b1;
      vlsuif.req_op       = vlsuif.op;
      vlsuif.req_sid      = vlsuif.sid;
      vlsuif.req_rc       = vlsuif.rc;
      vlsuif.req_rc_id    = vlsuif.rc_id;
      vlsuif.req_num_rows = vlsuif.num_rows;
      vlsuif.req_num_cols = vlsuif.num_cols;
      vlsuif.req_rs1      = vlsuif.rs1;
      vlsuif.req_vd       = vlsuif.vd;

      // forward to selected scratchpad frontend (scratchpad computes addresses)
      if (vlsuif.sid) begin
        scpad_sp1.vec_req.valid = 1'b1;
        scpad_sp1.vec_req.write = ~vlsuif.op; // op==1 -> load -> write=0
        scpad_sp1.vec_req.num_rows = vlsuif.num_rows;
        scpad_sp1.vec_req.num_cols = vlsuif.num_cols;
        scpad_sp1.vec_req.row_or_col = vlsuif.rc;
        scpad_sp1.vec_req.row_id = vlsuif.rc_id;
        scpad_sp1.vec_req.col_id = '0;
        if (vlsuif.op) begin
          fifo1_din = vlsuif.vd;
          fifo1_wr = 1'b1;
        end
      end else begin
        scpad_sp0.vec_req.valid = 1'b1;
        scpad_sp0.vec_req.write = ~vlsuif.op;
        scpad_sp0.vec_req.num_rows = vlsuif.num_rows;
        scpad_sp0.vec_req.num_cols = vlsuif.num_cols;
        scpad_sp0.vec_req.row_or_col = vlsuif.rc;
        scpad_sp0.vec_req.row_id = vlsuif.rc_id;
        scpad_sp0.vec_req.col_id = '0;
        if (vlsuif.op) begin
          fifo0_din = vlsuif.vd;
          fifo0_wr = 1'b1;
        end
      end
    end

    // when scratchpad returns data and FIFO has pending dst, pop FIFO and notify veggie-file
    if (scpad_sp0.vec_res.valid && !fifo0_empty) begin
      fifo0_shift = 1'b1;
      vlsuif.sp0_load_valid = 1'b1;
      vlsuif.sp0_veg_dst_idx = fifo0_dout;
      // scpad_sp0.vec_res.rdata contains the returned scpad_data_t to be written to veggie-file
    end

    if (scpad_sp1.vec_res.valid && !fifo1_empty) begin
      fifo1_shift = 1'b1;
      vlsuif.sp1_load_valid = 1'b1;
      vlsuif.sp1_veg_dst_idx = fifo1_dout;
      // scpad_sp1.vec_res.rdata contains the returned scpad_data_t to be written to veggie-file
    end
  end

endmodule
