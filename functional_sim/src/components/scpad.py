from typing import List, Dict, Any, Optional
from collections import defaultdict

from ..misc.scpad_common import *
from .xbar import Xbar

class Scratchpad:
    def __init__(self, slots_per_bank: int):
        self.B = NUM_BANKS
        self.S = slots_per_bank
        self.seen_masks = defaultdict(set)
        self.seen_masks_desc = defaultdict(set)

        self.banks = [["" for _ in range(self.S)] for _ in range(self.B)]
        self.tiles = {} 

    def clear(self):
        for b in range(self.B):
            for s in range(self.S):
                self.banks[b][s] = ""

    def canonical_row_coord(self, base_row: int, row_id: int):
        abs_row = base_row + row_id
        r_low = abs_row & (NUM_BANKS - 1)  
        return r_low

    def canonical_col_coord(self, base_row, col_id):
        base_low = base_row & (NUM_BANKS - 1)
        base0 = base_low & (H - 1)
        msb = (base_low >> (LOG2B - 1)) & 1

        if msb == 0:
            canon_base = base_low
            canon_col = col_id
        else:
            canon_base = base0
            canon_col = col_id ^ H

        perm_id = (canon_base << LOG2B) | canon_col
        return perm_id

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

            shift_mask, slot_mask, uninvalidated_mask, _, _ = AddressBlock.gen_masks_row(base_row=base_row, row_id=r, cols=cols)
            self.seen_masks[str(tuple(uninvalidated_mask))].add(self.canonical_row_coord(base_row, r))
            self.seen_masks_desc[str(tuple(uninvalidated_mask))].add((rows, cols, base_row, r, 1))

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
 
    def write_vec(self, tile_id: str, base_row: int, row_id: int = 0, col_id: int = 0, row_based: bool = True):
        assert tile_id in self.tiles, f"Unknown tile_id {tile_id}"
        rows = self.tiles[tile_id]["rows"]
        cols = self.tiles[tile_id]["cols"]
        B = self.B

        if row_based:
            assert 0 <= row_id < rows

            lane_vec = [
                (f"{tile_id}_{row_id}_{c}" if c < cols else 0)
                for c in range(B)
            ]

            shift_lane2bank, slot_mask, uninvalidated_lane_mask, lane_slot, lane_valid = (
                AddressBlock.gen_masks_row(base_row, row_id, cols)
            )
            mode = "row"
            coord = self.canonical_row_coord(base_row, row_id)
            coord_desc = (rows, cols, base_row, row_id, 1)
        else:
            assert 0 <= col_id < cols

            # lane = row index along that column
            lane_vec = [
                (f"{tile_id}_{r}_{col_id}" if r < rows else 0)
                for r in range(B)
            ]

            shift_lane2bank, slot_mask, uninvalidated_lane_mask, lane_slot, lane_valid = (
                AddressBlock.gen_masks_col(base_row, col_id, rows)
            )
            mode = "col"
            coord = self.canonical_col_coord(base_row, col_id)
            coord_desc = (rows, cols, base_row, col_id, 0)

        self.seen_masks[str(tuple(uninvalidated_lane_mask))].add(coord)
        self.seen_masks_desc[str(tuple(uninvalidated_lane_mask))].add(coord_desc)
        
        seen_pairs = set()
        collisions = []
        for lane in range(B):
            if not lane_valid[lane]:
                continue
            bank = shift_lane2bank[lane]
            if bank is None:
                continue
            slot = slot_mask[bank]
            if slot is None:
                continue

            key = (bank, slot)
            if key in seen_pairs:
                collisions.add((lane, bank, slot))
            else:
                seen_pairs.add(key)

        if collisions:
            raise RuntimeError(f"Collision in write_vec: {collisions}")

        bank_vec = Xbar.route(shift_lane2bank, lane_vec)

        writes = []
        for bank in range(B):
            s = slot_mask[bank]
            if s is None:
                continue

            if not (0 <= s < self.S):
                raise ValueError(f"Out-of-range write: bank={bank}, slot={s}")

            self.banks[bank][s] = bank_vec[bank]
            writes.append((bank, s, bank_vec[bank]))

        return {
            "mode": mode,
            "shift_mask": shift_lane2bank, 
            "slot_mask": slot_mask,      
            "lane_vec": lane_vec,         
            "bank_vec": bank_vec,          
            "writes": writes,              
            "collisions": collisions,      
        }

    def read_vec(self, tile_id: str, base_row: int, row_id: int = 0, col_id: int = 0, row_based: bool = True):
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

            shift_lane2bank, slot_mask, un_invalidated_mask, _, _ = AddressBlock.gen_masks_row(base_row, row_id, cols)
            bank_inputs = _read(slot_mask)
            coord =  self.canonical_row_coord(base_row, row_id)
            coord_desc = (rows, cols, base_row, row_id, 1)

            bank_to_lane = [None] * B
            for lane, bank in enumerate(shift_lane2bank):
                if bank is not None:
                    bank_to_lane[bank] = lane
            lane_out = Xbar.route(bank_to_lane, bank_inputs)

            golden = [(f"{tile_id}_{row_id}_{c}" if c < cols else 0) for c in range(NUM_BANKS)]
            mode = "row"

        else:
            assert 0 <= col_id < cols

            shift_lane2bank, slot_mask, un_invalidated_mask, _, _ = AddressBlock.gen_masks_col(base_row, col_id, rows)
            bank_inputs = _read(slot_mask)
            coord =  self.canonical_col_coord(base_row, col_id)
            coord_desc = (rows, cols, base_row, col_id, 0)

            bank_to_lane = [None] * B
            for lane, bank in enumerate(shift_lane2bank):
                if bank is not None:
                    bank_to_lane[bank] = lane
            lane_out = Xbar.route(bank_to_lane, bank_inputs)

            golden = [ (f"{tile_id}_{r}_{col_id}" if r < rows else 0) for r in range(NUM_BANKS) ]
            mode = "col"

        self.seen_masks[str(tuple(un_invalidated_mask))].add(coord)
        self.seen_masks_desc[str(tuple(un_invalidated_mask))].add(coord_desc)
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