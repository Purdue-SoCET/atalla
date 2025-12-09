`ifndef VLS_IF_TEMP_VH
`define VLS_IF_TEMP_VH

`include "vector_types.vh"
`include "vector_pkg.vh"

interface vls_if_temp();
  import vector_pkg::*;

  // Control & instruction fields (mirrors original vls_if usage)
  logic        valid;
  logic [6:0]  op;
  logic [7:0]  imm_a, imm_b;
  logic [3:0]  vd_a, vd_b;
  logic [4:0]  rs1_a, rs1_b;     // original used 5(??) — kept as 5 bits to match code above; adjust if needed
  logic        row_col_a, row_col_b;
  logic [5:0]  num_rows_a, num_rows_b;
  logic [5:0]  num_cols_a, num_cols_b;
  logic        id_a, id_b;
  logic [3:0]  v2_a, v2_b;

  // Handshake & flow control
  logic        vec_res;          // scratchpad / vector data valid
  logic        ready_in;         // downstream ready
  logic        ready_out;        // upstream ready

  // Vector element widths / counts (keep same names as original)
  // VEC_ELEMS = 32, ELEM_W = 16 in original file; expose as parameters in package typically
  // Here provide packed arrays used in original vls.sv:
  logic [15:0] load_data_a [31]; // incoming per-element data from scratchpad frontend
  logic [15:0] load_data_b [31];
  logic [15:0] sp_load_data_a [31]; // outputs to scratchpad (after buffering/drain)
  logic [15:0] sp_load_data_b [31];

  // Store path (write into scratchpad)
  logic [15:0] sp_store_data_a [31];
  logic [15:0] sp_store_data_b [31];

  // Scratchpad address outputs (32-bit in original)
  logic [31:0] sp_addr_a;
  logic [31:0] sp_addr_b;

  // sp control outputs
  logic [6:0]  sp_op;
  logic        sp_row_col_a;
  logic        sp_row_col_b;
  logic [5:0]  sp_num_rows_a, sp_num_rows_b;
  logic [5:0]  sp_num_cols_a, sp_num_cols_b;
  logic        sp_id_a, sp_id_b;

  // Writeback VD outputs (when vec_res occurs)
  logic [3:0]  wb_vd_a;
  logic [3:0]  wb_vd_b;

  // Modport used by simplified vls
  modport vls (
    input  valid, op, imm_a, imm_b, vd_a, vd_b, rs1_a, rs1_b,
           row_col_a, row_col_b, num_rows_a, num_rows_b, num_cols_a, num_cols_b,
           id_a, id_b, v2_a, v2_b, vec_res, ready_in,
    output ready_out, sp_load_data_a, sp_load_data_b, sp_store_data_a, sp_store_data_b,
           sp_addr_a, sp_addr_b, sp_op, sp_row_col_a, sp_row_col_b,
           sp_num_rows_a, sp_num_rows_b, sp_num_cols_a, sp_num_cols_b,
           sp_id_a, sp_id_b, wb_vd_a, wb_vd_b
  );
endinterface

`endif
