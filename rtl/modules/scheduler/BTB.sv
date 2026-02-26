`include "atalla_isa_types.vh"
`include "BTB_if.vh"
import atalla_isa_pkg::*;

module BTB (
    input logic CLK, 
    input logic nRST,
    BTB_if.btb_view  btb_if
);

  typedef struct packed {
    logic                 valid;    // Valid bit
    logic [BTB_TAG_W-1:0] tag;      // Tag
    word_t                target;   // Target Address
  } btb_entry_t;

  btb_entry_t btb_table [BTB_ENTRIES-1:0];

  logic [BTB_IDX_W-1:0] read_idx, write_idx;
  logic [BTB_TAG_W-1:0] read_tag, write_tag;

  // Read Port (Fetch)
  assign read_idx = btb_if.pc_fetch[BTB_IDX_W + BTB_OFFSET - 1 : BTB_OFFSET];
  assign read_tag = btb_if.pc_fetch[31 : 32 - BTB_TAG_W];

  // Write Port (Branch Unit)
  assign write_idx = btb_if.pc_update[BTB_IDX_W + BTB_OFFSET - 1 : BTB_OFFSET];
  assign write_tag = btb_if.pc_update[31 : 32 - BTB_TAG_W];

  always_comb begin
    btb_if.bhit           = 1'b0;
    btb_if.predict_target = 32'b0;

    if (btb_table[read_idx].valid && (btb_table[read_idx].tag == read_tag)) begin
      btb_if.bhit           = 1'b1;
      btb_if.predict_target = btb_table[read_idx].target;
    end
  end

  always_ff @(posedge CLK, negedge nRST) begin
    if (!nRST) begin
      for (int i = 0; i < BTB_ENTRIES; i++) begin
        btb_table[i] <= '0;
      end
    end 
    else if (btb_if.update_en) begin
      btb_table[write_idx].valid  <= 1'b1;
      btb_table[write_idx].tag    <= write_tag;
      btb_table[write_idx].target <= btb_if.true_target;
    end
  end

endmodule
//