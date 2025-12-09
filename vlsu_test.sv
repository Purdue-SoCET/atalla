`include "vlsu_if.vh"
`include "scpad_params.svh"

// Vector Load Store Unit module
// Handles load/store operations between veggie file and scratchpads
module vlsu #(
    // Number of veggie registers available
    parameter int VEGGIEREGS = 256,
    // Scratchpad read latency in cycles (time for data to return)
    parameter int FIFO_DEPTH_CYCLES = 13
) (
    // Clock signal
    input  logic        clk,
    
    // Active-low reset
    input  logic        n_rst,
    
    // Instruction interface from decoder
    vlsu_if.vlsu vlsu_port,
    
    // Vector frontend connection to scratchpad 0
    scpad_if.vec_frontend scpad_sp0,
    
    // Vector frontend connection to scratchpad 1
    scpad_if.vec_frontend scpad_sp1
);
 
  import scpad_pkg::*;

  // Calculate bits needed to store veggie register index
  // log2(256) = 8 bits per entry
  localparam int ENTRY_BITS = $clog2(VEGGIEREGS);

  // FIFO depth based on scratchpad latency
  // Size FIFO to hold pending loads during read latency
  localparam int FIFO_DEPTH = FIFO_DEPTH_CYCLES;

  // ==================== FIFO 0 (Scratchpad 0) ====================
  
  // Write enable to FIFO0
  logic fifo0_wr, fifo0_shift;
  
  // Data input to FIFO0 (veggie destination register index)
  logic [ENTRY_BITS-1:0] fifo0_din, fifo0_dout;
  
  // FIFO0 empty flag
  logic fifo0_empty;
  
  // FIFO0 full flag
  logic fifo0_full;

  // ==================== FIFO 1 (Scratchpad 1) ====================
  
  // Write enable to FIFO1
  logic fifo1_wr, fifo1_shift;
  
  // Data input to FIFO1 (veggie destination register index)
  logic [ENTRY_BITS-1:0] fifo1_din, fifo1_dout;
  
  // FIFO1 empty flag
  logic fifo1_empty;
  
  // FIFO1 full flag
  logic fifo1_full;

  // ==================== FIFO Instantiations ====================
  
  sync_fifo #(
    .FIFODEPTH(FIFO_DEPTH),
    .DATAWIDTH(ENTRY_BITS)
  ) sp0_fifo (
    .nRST(n_rst),
    .CLK(clk),
    .wr_en(fifo0_wr),
    .shift(fifo0_shift),
    .din(fifo0_din),
    .dout(fifo0_dout),
    .empty(fifo0_empty),
    .full(fifo0_full)
  );

  sync_fifo #(
    .FIFODEPTH(FIFO_DEPTH),
    .DATAWIDTH(ENTRY_BITS)
  ) sp1_fifo (
    .nRST(n_rst),
    .CLK(clk),
    .wr_en(fifo1_wr),
    .shift(fifo1_shift),
    .din(fifo1_din),
    .dout(fifo1_dout),
    .empty(fifo1_empty),
    .full(fifo1_full)
  );

  // ==================== Combinational Logic ====================
  
  always_comb begin
    // Default: FIFO signals inactive
    fifo0_wr = 1'b0;
    fifo0_shift = 1'b0;
    fifo0_din = '0;
    fifo1_wr = 1'b0;
    fifo1_shift = 1'b0;
    fifo1_din = '0;

    // Default: No request to scratchpads
    scpad_sp0.vec_req = '0;
    scpad_sp1.vec_req = '0;

    // Default: clear pass-through request outputs
    vlsu_port.req_valid    = 1'b0;
    vlsu_port.req_op       = '0;
    vlsu_port.req_sid      = '0;
    vlsu_port.req_rc       = '0;
    vlsu_port.req_rc_id    = '0;
    vlsu_port.req_num_rows = '0;
    vlsu_port.req_num_cols = '0;
    vlsu_port.req_rs1      = '0;
    vlsu_port.req_vd       = '0;

    // Default: clear writeback notifications
    vlsu_port.sp0_load_valid = 1'b0;
    vlsu_port.sp0_veg_dst_idx = '0;
    vlsu_port.sp1_load_valid = 1'b0;
    vlsu_port.sp1_veg_dst_idx = '0;

    // Ready when instruction is valid AND appropriate FIFO is not full
    // Note: instr.op == 1 => load => need FIFO space, instr.op == 0 => store => no FIFO required
    vlsu_port.ready = vlsu_port.valid && 
                      (!vlsu_port.op ||                 // store: ok
                       (vlsu_port.sid ? !fifo1_full : !fifo0_full)); // load: check selected FIFO

    // Process instruction if valid and ready: forward fields to scratchpad (pass-through)
    if (vlsu_port.valid && vlsu_port.ready) begin
      // Assert pass-through request outputs for scratchpad to consume
      vlsu_port.req_valid    = 1'b1;
      vlsu_port.req_op       = vlsu_port.op;
      vlsu_port.req_sid      = vlsu_port.sid;
      vlsu_port.req_rc       = vlsu_port.rc;
      vlsu_port.req_rc_id    = vlsu_port.rc_id;
      vlsu_port.req_num_rows = vlsu_port.num_rows;
      vlsu_port.req_num_cols = vlsu_port.num_cols;
      vlsu_port.req_rs1      = vlsu_port.rs1;
      vlsu_port.req_vd       = vlsu_port.vd;

      // Build and forward the scratchpad req_t (scratchpad performs address calculation)
      if (vlsu_port.sid) begin
        // to scratchpad 1
        scpad_sp1.vec_req.valid = 1'b1;
        scpad_sp1.vec_req.write = !vlsu_port.op; // op==1 -> load -> write=0; op==0 -> store -> write=1
        // don't set spad_addr here; scratchpad computes address from row/col inputs
        scpad_sp1.vec_req.num_rows = vlsu_port.num_rows;
        scpad_sp1.vec_req.num_cols = vlsu_port.num_cols;
        scpad_sp1.vec_req.row_or_col = vlsu_port.rc;
        scpad_sp1.vec_req.row_id = vlsu_port.rc_id;
        scpad_sp1.vec_req.col_id = '0; // left for scratchpad or swizzle logic if needed
        // wdata should be driven by veggie-file -> external connection for stores
        // If load, push vd into FIFO1 for later writeback
        if (vlsu_port.op) begin
          fifo1_din = vlsu_port.vd;
          fifo1_wr = 1'b1;
        end
      end else begin
        // to scratchpad 0
        scpad_sp0.vec_req.valid = 1'b1;
        scpad_sp0.vec_req.write = !vlsu_port.op;
        scpad_sp0.vec_req.num_rows = vlsu_port.num_rows;
        scpad_sp0.vec_req.num_cols = vlsu_port.num_cols;
        scpad_sp0.vec_req.row_or_col = vlsu_port.rc;
        scpad_sp0.vec_req.row_id = vlsu_port.rc_id;
        scpad_sp0.vec_req.col_id = '0;
        if (vlsu_port.op) begin
          fifo0_din = vlsu_port.vd;
          fifo0_wr = 1'b1;
        end
      end
    end

    // ===== Load Writeback Logic =====
    // When scratchpad returns valid load data AND FIFO has pending loads, pop FIFO
    if (scpad_sp0.vec_res.valid && !fifo0_empty) begin
      fifo0_shift = 1'b1;
      vlsu_port.sp0_load_valid = 1'b1;
      vlsu_port.sp0_veg_dst_idx = fifo0_dout;
      // scpad_sp0.vec_res.rdata contains the returned scpad_data_t to be written to veggie file
    end

    if (scpad_sp1.vec_res.valid && !fifo1_empty) begin
      fifo1_shift = 1'b1;
      vlsu_port.sp1_load_valid = 1'b1;
      vlsu_port.sp1_veg_dst_idx = fifo1_dout;
      // scpad_sp1.vec_res.rdata contains the returned scpad_data_t to be written to veggie file
    end
  end

endmodule