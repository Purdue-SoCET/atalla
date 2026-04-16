#pragma once
#include <stdint.h>
#include <string>
#include <vector>

#ifndef NUM_BANKS
#define NUM_BANKS 32
#endif

// If you want to mimic the current RTL bug (<=), set to 1.
#ifndef RTL_VALID_INCLUSIVE
#define RTL_VALID_INCLUSIVE 0
#endif

// Convenience: fixed maximum lanes/banks for DPI.
static constexpr int MAX_LANES = NUM_BANKS;

struct Masks {
  // lane-indexed
  int32_t lane2bank[MAX_LANES];   // -1 if invalid lane (Python None)
  uint32_t lane_bank[MAX_LANES];  // always computed bank (even if invalid)
  uint32_t lane_slot[MAX_LANES];  // abs_row for each lane
  uint8_t lane_valid[MAX_LANES];  // 0/1

  // bank-indexed
  int32_t slot_mask[MAX_LANES];   // -1 if no lane maps (Python None)
};

class AddressBlock {
public:
  static uint32_t xor_bank(uint32_t abs_row, uint32_t col_id) {
    uint32_t low5 = abs_row & (NUM_BANKS - 1);
    return (col_id ^ low5) & (NUM_BANKS - 1);
  }

  static void gen_masks_row(uint32_t base_row, uint32_t row_id, uint32_t cols, Masks &out) {
    const uint32_t abs_row = base_row + row_id;

    // init
    for (int i = 0; i < NUM_BANKS; i++) {
      out.lane2bank[i] = -1;
      out.lane_bank[i] = 0;
      out.lane_slot[i] = 0;
      out.lane_valid[i] = 0;
      out.slot_mask[i] = -1;
    }

    for (int lane = 0; lane < NUM_BANKS; lane++) {
      const uint32_t bank = xor_bank(abs_row, (uint32_t)lane);
      out.lane_bank[lane] = bank;
      out.lane_slot[lane] = abs_row;

#if RTL_VALID_INCLUSIVE
      const bool valid = ((uint32_t)lane <= cols);
#else
      const bool valid = ((uint32_t)lane < cols);
#endif
      out.lane_valid[lane] = valid ? 1 : 0;

      if (valid) {
        out.lane2bank[lane] = (int32_t)bank;
        out.slot_mask[bank] = (int32_t)abs_row;
      }
    }
  }

  static void gen_masks_col(uint32_t base_row, uint32_t col_id, uint32_t rows, Masks &out) {
    // init
    for (int i = 0; i < NUM_BANKS; i++) {
      out.lane2bank[i] = -1;
      out.lane_bank[i] = 0;
      out.lane_slot[i] = 0;
      out.lane_valid[i] = 0;
      out.slot_mask[i] = -1;
    }

    for (int lane = 0; lane < NUM_BANKS; lane++) {
      const uint32_t abs_row = base_row + (uint32_t)lane;
      const uint32_t bank = xor_bank(abs_row, col_id);

      out.lane_bank[lane] = bank;
      out.lane_slot[lane] = abs_row;

#if RTL_VALID_INCLUSIVE
      const bool valid = ((uint32_t)lane <= rows);
#else
      const bool valid = ((uint32_t)lane < rows);
#endif
      out.lane_valid[lane] = valid ? 1 : 0;

      if (valid) {
        out.lane2bank[lane] = (int32_t)bank;
        out.slot_mask[bank] = (int32_t)abs_row;
      }
    }
  }
};

class Scratchpad {
public:
  explicit Scratchpad(uint32_t slots_per_bank)
    : B(NUM_BANKS), S(slots_per_bank),
      banks(NUM_BANKS, std::vector<std::string>(slots_per_bank, "")) {}

  void clear() {
    for (auto &bank : banks) {
      for (auto &slot : bank) slot.clear();
    }
  }

  uint32_t canonical_row_coord(uint32_t base_row, uint32_t row_id) const {
    uint32_t abs_row = base_row + row_id;
    return abs_row & (NUM_BANKS - 1);
  }

  // NOTE: This depends on LOG2B/H; in SV H = NUM_COLS >> 1.
  // We'll assume NUM_BANKS==NUM_COLS and LOG2B=log2(NUM_BANKS)=5 for 32.
  uint32_t canonical_col_coord(uint32_t base_row, uint32_t col_id) const {
    constexpr uint32_t LOG2B = 5;
    constexpr uint32_t H = (NUM_BANKS >> 1);

    uint32_t base_low = base_row & (NUM_BANKS - 1);
    uint32_t base0 = base_low & (H - 1);
    uint32_t msb = (base_low >> (LOG2B - 1)) & 1;

    uint32_t canon_base, canon_col;
    if (msb == 0) {
      canon_base = base_low;
      canon_col = col_id;
    } else {
      canon_base = base0;
      canon_col = col_id ^ H;
    }
    uint32_t perm_id = (canon_base << LOG2B) | canon_col;
    return perm_id;
  }

private:
  uint32_t B;
  uint32_t S;
  std::vector<std::vector<std::string>> banks;
};
