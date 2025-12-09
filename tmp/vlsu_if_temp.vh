`ifndef VLSU_IF_TEMP_VH
`define VLSU_IF_TEMP_VH

interface vlsu_if_temp();
  // Instruction inputs (from decoder)
  logic        valid;       // instruction valid
  logic        op;          // operation: 1 = load, 0 = store
  logic        sid;         // scratchpad id: 0 = SP0, 1 = SP1
  logic        rc;          // row/col selector: 0 = row, 1 = column
  logic [4:0]  rc_id;       // row/col index
  logic [4:0]  num_rows;    // number of rows
  logic [4:0]  num_cols;    // number of cols
  logic [7:0]  rs1;         // base row
  logic [7:0]  vd;          // vector destination register

  // vLSU signals it can accept the instruction
  logic        ready_in;
  logic       ready_out; // FIFO full signals (from internal FIFOs)

  // -------------------------------------------------------------------
  // Pass-through request outputs: vLSU asserts these when it accepts an instruction.
  // Scratchpad logic can monitor these fields to compute addresses / control transfers.
  // -------------------------------------------------------------------
  logic        req_valid;
  logic        req_op;
  logic        req_sid;
  logic        req_rc;
  logic [4:0]  req_rc_id;
  logic [4:0]  req_num_rows;
  logic [4:0]  req_num_cols;
  logic [7:0]  req_rs1;
  logic [7:0]  req_vd;

  // ===== Load Writeback Outputs =====
  logic        sp0_load_valid;
  logic [7:0]  sp0_veg_dst_idx;
  logic        sp1_load_valid;
  logic [7:0]  sp1_veg_dst_idx;

  modport vlsu (
    // inputs: instruction fields
    input valid, op, sid, rc, rc_id, num_rows, num_cols, rs1, vd,
    // outputs: handshake / pass-through / writeback notifications
    output ready,
    output req_valid, req_op, req_sid, req_rc, req_rc_id, req_num_rows, req_num_cols, req_rs1, req_vd,
    output sp0_load_valid, sp0_veg_dst_idx, sp1_load_valid, sp1_veg_dst_idx
  );
endinterface

`endif
