package golden_swizzle_pkg;
  parameter int MAX_LANES = 32;

  import "DPI-C" function int dpi_gen_masks_row(
    int base_row, int row_id, int cols,
    output int lane2bank_out[MAX_LANES],
    output int slot_mask_out[MAX_LANES],
    output int unsigned lane_bank_out[MAX_LANES],
    output int unsigned lane_slot_out[MAX_LANES],
    output byte unsigned lane_valid_out[MAX_LANES]
  );

  import "DPI-C" function int dpi_gen_masks_col(
    int base_row, int col_id, int rows,
    output int lane2bank_out[MAX_LANES],
    output int slot_mask_out[MAX_LANES],
    output int unsigned lane_bank_out[MAX_LANES],
    output int unsigned lane_slot_out[MAX_LANES],
    output byte unsigned lane_valid_out[MAX_LANES]
  );

  import "DPI-C" function int unsigned dpi_canonical_row_coord(int base_row, int row_id);
  import "DPI-C" function int unsigned dpi_canonical_col_coord(int base_row, int col_id);

  import "DPI-C" function int dpi_swizzle_rtl_equivalent(
    int row_or_col,
    int spad_addr,
    int num_rows,
    int num_cols,
    int row_id,
    int col_id,
    output byte unsigned valid_mask_out[MAX_LANES],
    output int unsigned  shift_mask_out[MAX_LANES],
    output int unsigned  slot_mask_out[MAX_LANES],
    output int unsigned  rom_id_out
  );
endpackage
