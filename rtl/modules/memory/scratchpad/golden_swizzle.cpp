#include "golden_swizzle.hpp"
#include <string.h>

extern "C" {

// Return 0 on success.
int dpi_gen_masks_row(
    int base_row, int row_id, int cols,
    int lane2bank_out[MAX_LANES],
    int slot_mask_out[MAX_LANES],
    unsigned int lane_bank_out[MAX_LANES],
    unsigned int lane_slot_out[MAX_LANES],
    unsigned char lane_valid_out[MAX_LANES]
) {
  if (cols < 0 || cols > NUM_BANKS) return 1;

  Masks m;
  AddressBlock::gen_masks_row((uint32_t)base_row, (uint32_t)row_id, (uint32_t)cols, m);

  for (int i = 0; i < NUM_BANKS; i++) {
    lane2bank_out[i] = m.lane2bank[i];
    slot_mask_out[i] = m.slot_mask[i];
    lane_bank_out[i] = m.lane_bank[i];
    lane_slot_out[i] = m.lane_slot[i];
    lane_valid_out[i] = m.lane_valid[i];
  }
  return 0;
}

// Return 0 on success.
int dpi_gen_masks_col(
    int base_row, int col_id, int rows,
    int lane2bank_out[MAX_LANES],
    int slot_mask_out[MAX_LANES],
    unsigned int lane_bank_out[MAX_LANES],
    unsigned int lane_slot_out[MAX_LANES],
    unsigned char lane_valid_out[MAX_LANES]
) {
  if (rows < 0 || rows > NUM_BANKS) return 1;

  Masks m;
  AddressBlock::gen_masks_col((uint32_t)base_row, (uint32_t)col_id, (uint32_t)rows, m);

  for (int i = 0; i < NUM_BANKS; i++) {
    lane2bank_out[i] = m.lane2bank[i];
    slot_mask_out[i] = m.slot_mask[i];
    lane_bank_out[i] = m.lane_bank[i];
    lane_slot_out[i] = m.lane_slot[i];
    lane_valid_out[i] = m.lane_valid[i];
  }
  return 0;
}

unsigned int dpi_canonical_row_coord(int base_row, int row_id) {
  Scratchpad sp(1);
  return sp.canonical_row_coord((uint32_t)base_row, (uint32_t)row_id);
}

unsigned int dpi_canonical_col_coord(int base_row, int col_id) {
  Scratchpad sp(1);
  return sp.canonical_col_coord((uint32_t)base_row, (uint32_t)col_id);
}

// This function mirrors what your SV swizzle module *intends* to output:
// - valid_mask per bank_id
// - shift_mask per bank_id (lane2bank style)
// - slot_mask per bank_id
// - rom_id
//
// row_or_col: 1 = row-major, 0 = col-major (matches your SV)
int dpi_swizzle_rtl_equivalent(
    int row_or_col,
    int spad_addr,
    int num_rows,
    int num_cols,
    int row_id,
    int col_id,
    unsigned char valid_mask_out[MAX_LANES],
    unsigned int shift_mask_out[MAX_LANES],
    unsigned int slot_mask_out[MAX_LANES],
    unsigned int *rom_id_out
) {
  // rom_id logic (matches your SV structure / python canonical_col_coord idea)
  // Assumes NUM_BANKS==NUM_COLS and LOG2B=5 and H=NUM_BANKS>>1.
  constexpr uint32_t LOG2B = 5;
  constexpr uint32_t H = (NUM_BANKS >> 1);

  uint32_t rom_id = 0;

  if (row_or_col) {
    uint32_t abs_row = (uint32_t)spad_addr + (uint32_t)row_id;
    uint32_t canon_base = 0;
    uint32_t canon_col  = abs_row & (NUM_BANKS - 1);
    rom_id = (canon_base << LOG2B) | canon_col;
  } else {
    uint32_t base_low = (uint32_t)spad_addr & (NUM_BANKS - 1);
    uint32_t base0 = base_low & (H - 1);
    uint32_t msb = (base_low >> (LOG2B - 1)) & 1;

    uint32_t canon_base, canon_col;
    if (msb == 0) {
      canon_base = base_low & (H - 1); // matches your SV truncation to COL_IDX_WIDTH-2:0
      canon_col  = (uint32_t)col_id;
    } else {
      canon_base = base0;
      canon_col  = ((uint32_t)col_id) ^ H;
    }
    rom_id = (canon_base << LOG2B) | (canon_col & (NUM_BANKS - 1));
  }

  *rom_id_out = rom_id;

  // masks
  for (int bank_id = 0; bank_id < NUM_BANKS; bank_id++) {
    if (row_or_col) {
      uint32_t abs_row = (uint32_t)spad_addr + (uint32_t)row_id;

#if RTL_VALID_INCLUSIVE
      bool valid = ((uint32_t)bank_id <= (uint32_t)num_cols);
#else
      bool valid = ((uint32_t)bank_id < (uint32_t)num_cols);
#endif
      valid_mask_out[bank_id] = valid ? 1 : 0;

      uint32_t low = abs_row & (NUM_BANKS - 1);
      shift_mask_out[bank_id] = ((uint32_t)bank_id ^ low) & (NUM_BANKS - 1);
      slot_mask_out[bank_id]  = abs_row;
    } else {
      uint32_t abs_row = (uint32_t)spad_addr + (uint32_t)bank_id;

#if RTL_VALID_INCLUSIVE
      bool valid = ((uint32_t)bank_id <= (uint32_t)num_rows);
#else
      bool valid = ((uint32_t)bank_id < (uint32_t)num_rows);
#endif
      valid_mask_out[bank_id] = valid ? 1 : 0;

      uint32_t low = abs_row & (NUM_BANKS - 1);
      shift_mask_out[bank_id] = ((uint32_t)col_id ^ low) & (NUM_BANKS - 1);
      slot_mask_out[bank_id]  = abs_row;
    }
  }
  return 0;
}

} // extern "C"
