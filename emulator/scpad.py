from .common import * 
from typing import List, Dict, Any, Optional
from .xbar import Xbar

class Scratchpad:
    def __init__(self, slots_per_bank: int):
        self.B = NUM_BANKS
        self.S = slots_per_bank
        self.seen_masks = set()

        self.banks = [["" for _ in range(self.S)] for _ in range(self.B)]
        self.tiles = {} 

    def clear(self):
        for b in range(self.B):
            for s in range(self.S):
                self.banks[b][s] = ""

    def write_tile(self, tile_id: str, rows: int, cols: int, base_row: int, strict: bool = True):
        assert 0 <= cols <= NUM_BANKS, "Tile width must be <= NUM_BANKS (tile externally if wider)."

        stored = 0
        dropped = 0

        for r in range(rows):
            dram_vec: List[Optional[str]] = [None] * self.B

            for i in range(self.B):
                flat = r * cols + i
                rr = flat // cols if cols > 0 else 0
                cc = flat %  cols if cols > 0 else 0
                if rr < rows and cc < cols:
                    dram_vec[i] = f"{tile_id}_{rr}_{cc}"

            shift_mask, slot_mask, _, _, _ = AddressBlock.gen_masks_row(base_row=base_row, row_id=r, cols=cols)
            self.seen_masks.add(tuple(shift_mask))

            switch_out = Xbar.route(shift_mask, dram_vec)

            for bank, val in enumerate(switch_out):
                s = slot_mask[bank]
                if s is None: continue 

                if not (0 <= s < self.S):
                    raise ValueError(f"Out-of-range write: bank={bank}, slot={s}")
                    dropped += 1
                    continue

                self.banks[bank][s] = val
                stored += 1

        self.tiles[tile_id] = {"rows": rows, "cols": cols, "base_row": base_row}
        return {"stored": stored, "dropped": dropped}

    def read_tile(self, tile_id: str, base_row: int, row_id: int = 0, col_id: int = 0, row_based: bool = True):

        def _read(slot_mask): 
            bank_inputs = [0] * B
            for b in range(B):
                s = slot_mask[b]
                if s is not None:
                    bank_inputs[b] = self.banks[b][s]
            return bank_inputs

        assert tile_id in self.tiles
        rows = self.tiles[tile_id]["rows"]
        cols = self.tiles[tile_id]["cols"]
        B = self.B

        if row_based:
            assert 0 <= row_id < rows

            shift_lane2bank, slot_mask, _, _, _ = AddressBlock.gen_masks_row(base_row, row_id, cols)
            bank_inputs = _read(slot_mask)
            self.seen_masks.add(tuple(shift_lane2bank))

            # In hardware, we can just do bank_inputs[shift_lane2bank[i]]
            bank_to_lane = [None] * B
            for lane, bank in enumerate(shift_lane2bank):
                if bank is not None:
                    bank_to_lane[bank] = lane
            lane_out = Xbar.route(bank_to_lane, bank_inputs)

            golden = [(f"{tile_id}_{row_id}_{c}" if c < cols else 0) for c in range(NUM_BANKS)]
            mode = "row"

        else:
            assert 0 <= col_id < cols

            shift_lane2bank, slot_mask, _, _, _ = AddressBlock.gen_masks_col(base_row, col_id, rows)
            bank_inputs = _read(slot_mask)
            self.seen_masks.add(tuple(shift_lane2bank))

            # In hardware, we can just do bank_inputs[shift_lane2bank[i]]
            bank_to_lane = [None] * B
            for lane, bank in enumerate(shift_lane2bank):
                if bank is not None:
                    bank_to_lane[bank] = lane
            lane_out = Xbar.route(bank_to_lane, bank_inputs)

            golden = [ (f"{tile_id}_{r}_{col_id}" if r < rows else 0) for r in range(NUM_BANKS) ]
            mode = "col"

        mismatches = [(i, lane_out[i], golden[i]) for i in range(B) if lane_out[i] != golden[i]]

        return {
            "mode": mode,
            "slot_mask": slot_mask,
            "shift_mask_inv": shift_lane2bank,
            "bank_inputs": bank_inputs,
            "shift_mask": bank_to_lane,
            "lane_out": lane_out,
            "golden": golden,
            "pass": len(mismatches) == 0,
            "mismatches": mismatches
        }