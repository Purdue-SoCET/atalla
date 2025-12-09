`include "../tmp/vls_if_temp.vh"
`include "../include/scpad_params.svh"

module vLS_temp #(
  parameter int FIFO_DEPTH_VD   = 8,      // VD FIFO depth (tracks pending destinations)
  parameter int FIFO_DEPTH_DATA = 8       // Data FIFO depth (vector storage)
) (
  input  logic       CLK,
  input  logic       nRST,
  vls_if_temp.vls   vlsif
);

  import vector_pkg::*;
  import scpad_pkg::*;

  // local parameters matching original file
  localparam int VEC_ELEMS = 32;
  localparam int ELEM_W    = 16;
  localparam int VEC_W     = VEC_ELEMS * ELEM_W;

  // VD FIFOs (per lane)
  logic vd_wr_a, vd_shift_a;
  logic [3:0] vd_din_a, vd_dout_a;
  logic vd_empty_a, vd_full_a;

  logic vd_wr_b, vd_shift_b;
  logic [3:0] vd_din_b, vd_dout_b;
  logic vd_empty_b, vd_full_b;

  // Data FIFOs (per lane) store packed vectors
  logic d_wr_a, d_shift_a;
  logic [VEC_W-1:0] d_din_a, d_dout_a;
  logic d_empty_a, d_full_a;

  logic d_wr_b, d_shift_b;
  logic [VEC_W-1:0] d_din_b, d_dout_b;
  logic d_empty_b, d_full_b;

  // Instantiate small FIFOs (user sync_fifo style)
  vls_fifo #(.FIFODEPTH(FIFO_DEPTH_VD), .DATAWIDTH(4)) qVDa (
    .nRST(nRST), .CLK(CLK),
    .wr_en(vd_wr_a), .shift(vd_shift_a),
    .din(vd_din_a), .dout(vd_dout_a),
    .empty(vd_empty_a), .full(vd_full_a)
  );

  vls_fifo #(.FIFODEPTH(FIFO_DEPTH_VD), .DATAWIDTH(4)) qVDb (
    .nRST(nRST), .CLK(CLK),
    .wr_en(vd_wr_b), .shift(vd_shift_b),
    .din(vd_din_b), .dout(vd_dout_b),
    .empty(vd_empty_b), .full(vd_full_b)
  );

  vls_fifo #(.FIFODEPTH(FIFO_DEPTH_DATA), .DATAWIDTH(VEC_W)) qDA (
    .nRST(nRST), .CLK(CLK),
    .wr_en(d_wr_a), .shift(d_shift_a),
    .din(d_din_a), .dout(d_dout_a),
    .empty(d_empty_a), .full(d_full_a)
  );

  vls_fifo #(.FIFODEPTH(FIFO_DEPTH_DATA), .DATAWIDTH(VEC_W)) qDB (
    .nRST(nRST), .CLK(CLK),
    .wr_en(d_wr_b), .shift(d_shift_b),
    .din(d_din_b), .dout(d_dout_b),
    .empty(d_empty_b), .full(d_full_b)
  );

  // pack incoming element array into VEC_W for data FIFO
  integer i;
  always_comb begin
    for (i = 0; i < VEC_ELEMS; i++) begin
      d_din_a[i*ELEM_W +: ELEM_W] = vlsif.load_data_a[i];
      d_din_b[i*ELEM_W +: ELEM_W] = vlsif.load_data_b[i];
    end
  end

  // Default control signals
  always_comb begin
    // default clears
    vd_wr_a = 1'b0; vd_wr_b = 1'b0;
    d_wr_a  = 1'b0; d_wr_b  = 1'b0;
    vd_shift_a = 1'b0; vd_shift_b = 1'b0;
    d_shift_a  = 1'b0; d_shift_b  = 1'b0;

    // default outputs to scratchpad/control
    vlsif.sp_op = vlsif.op;
    vlsif.sp_row_col_a = vlsif.row_col_a;
    vlsif.sp_row_col_b = vlsif.row_col_b;
    vlsif.sp_num_rows_a = vlsif.num_rows_a;
    vlsif.sp_num_rows_b = vlsif.num_rows_b;
    vlsif.sp_num_cols_a = vlsif.num_cols_a;
    vlsif.sp_num_cols_b = vlsif.num_cols_b;
    vlsif.sp_id_a = vlsif.id_a;
    vlsif.sp_id_b = vlsif.id_b;

    // ready_out: assert if downstream ready and data FIFOs not full
    vlsif.ready_out = vlsif.ready_in && !d_full_a && !d_full_b;

    // If vec_res occurs (scratchpad produced vector), decide whether to buffer or passthrough:
    // simplified policy: if downstream is stalled (ready_in==0) then buffer incoming vectors,
    // else pass them through or drain from FIFO first
    if (vlsif.vec_res) begin
      if (!vlsif.ready_in) begin
        // capture incoming vectors into data FIFOs (if space)
        if (!d_full_a) d_wr_a = 1'b1;
        if (!d_full_b) d_wr_b = 1'b1;
      end else begin
        // passing through: if we have buffered vectors, output them (shift)
        if (!d_empty_a) d_shift_a = 1'b1;
        if (!d_empty_b) d_shift_b = 1'b1;
      end
    end

    // Issue new instruction from vlsif.valid:
    // simplified: when valid, push destination VD into VD FIFO for loads, forward sp_addr and store data for stores.
    if (vlsif.valid) begin
      // Example op check: use original op codes used in original vls.sv
      if (vlsif.op == 7'b0100111 || vlsif.op == 7'b0101000) begin
        // This is a load/store class in original file — treat loads (0100111) as reads, stores (0101000) as writes
        // For loads, push vd into VD FIFO (track expected writeback)
        // (Note: original code had dual-issue; we accept both A and B as separate lanes if present)
        vd_din_a = vlsif.vd_a;
        vd_din_b = vlsif.vd_b;
        if (/*load opcode?*/ vlsif.op == 7'b0100111) begin
          if (!vd_full_a) vd_wr_a = 1'b1;
          if (!vd_full_b) vd_wr_b = 1'b1;
        end

        // Compute sp_addr using simpler scheme: use rs1 + imm (like original)
        vlsif.sp_addr_a = {24'b0, vlsif.rs1_a} + {24'b0, vlsif.imm_a};
        vlsif.sp_addr_b = {24'b0, vlsif.rs1_b} + {24'b0, vlsif.imm_b};

        // For stores, forward sp_store_data (assume load_data arrays contain data for store path)
        if (vlsif.op == 7'b0101000) begin
          for (i = 0; i < VEC_ELEMS; i++) begin
            vlsif.sp_store_data_a[i] = vlsif.load_data_a[i];
            vlsif.sp_store_data_b[i] = vlsif.load_data_b[i];
          end
        end
      end
    end

    // When a vec_res occurs and VD FIFO has entries, pop and present wb_vd
    if (vlsif.vec_res) begin
      if (!vd_empty_a) begin
        vd_shift_a = 1'b1;
        vlsif.wb_vd_a = vd_dout_a;
      end else begin
        vlsif.wb_vd_a = '0;
      end
      if (!vd_empty_b) begin
        vd_shift_b = 1'b1;
        vlsif.wb_vd_b = vd_dout_b;
      end else begin
        vlsif.wb_vd_b = '0;
      end
    end
  end

  // Unpack outputs (if we are outputting data from FIFO or passthrough)
  always_comb begin
    // If there is a buffered vector to output (drain), use that, else passthrough current incoming vector
    logic [VEC_W-1:0] out_a, out_b;
    if (!d_empty_a) out_a = d_dout_a; else out_a = d_din_a;
    if (!d_empty_b) out_b = d_dout_b; else out_b = d_din_b;

    for (i = 0; i < VEC_ELEMS; i++) begin
      vlsif.sp_load_data_a[i] = out_a[i*ELEM_W +: ELEM_W];
      vlsif.sp_load_data_b[i] = out_b[i*ELEM_W +: ELEM_W];
    end
  end

endmodule
