`ifndef VLSU_IF_VH
`define VLSU_IF_VH

interface vlsu_if();
  // Instruction is valid, ready to be processed
  logic valid;
  
  // Operation: 1 = load from scratchpad, 0 = store to scratchpad
  // (renamed from "mask" to avoid confusion)
  logic op;
  
  // Which scratchpad: 0 = SP0, 1 = SP1
  logic sid;
  
  // Row or column operation: 0 = row, 1 = column
  logic rc;
  
  // Which row/column index
  logic [4:0] rc_id;
  
  // Number of rows to transfer
  logic [4:0] num_rows;
  
  // Number of columns to transfer
  logic [4:0] num_cols;
  
  // Base row address in scratchpad (passed through; scratchpad will compute final addresses)
  logic [7:0] rs1;
  
  // Vector destination register (vd)
  logic [7:0] vd;
  
  // VLSU signals it can accept this instruction
  logic ready;

  // -------------------------------------------------------------------
  // Pass-through request outputs
  // VLSU asserts these when it issues a request to the scratchpad.
  // Scratchpad will consume these fields and perform address computation.
  // -------------------------------------------------------------------
  logic req_valid;        // VLSU asserted request (accepted instruction forwarded)
  logic req_op;           // forwarded operation (1 load / 0 store)
  logic req_sid;          // forwarded scratchpad id
  logic req_rc;           // forwarded row/col flag
  logic [4:0] req_rc_id;  // forwarded row/col id
  logic [4:0] req_num_rows;
  logic [4:0] req_num_cols;
  logic [7:0] req_rs1;
  logic [7:0] req_vd;
  // (VLSU sets these; scratchpad monitors them)

  // ===== Load Writeback Outputs =====
  
  // Load data valid from scratchpad 0 (VLSU asserts when vec_res arrives and FIFO pop gives dst index)
  logic sp0_load_valid;
  
  // Veggie destination register index for SP0 load writeback (popped from FIFO)
  logic [7:0] sp0_veg_dst_idx;
  
  // Load data valid from scratchpad 1
  logic sp1_load_valid;
  
  // Veggie destination register index for SP1 load writeback
  logic [7:0] sp1_veg_dst_idx;

  modport vlsu (
    // Inputs: instruction fields from decoder
    input valid, op, sid, rc, rc_id, num_rows, num_cols, rs1, vd,
    // Outputs: ready, pass-through request, and writeback notifications
    output ready,
    output req_valid, req_op, req_sid, req_rc, req_rc_id, req_num_rows, req_num_cols, req_rs1, req_vd,
    output sp0_load_valid, sp0_veg_dst_idx, sp1_load_valid, sp1_veg_dst_idx
  );
endinterface

`endif
