from math import ceil
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.colors import ListedColormap
from matplotlib.patches import Patch
from typing import List, Dict, Any, Optional

NUM_BANKS = 32
LOG2B = 5  
H = NUM_BANKS >> 1

class AddressBlock:
    def _xor(abs_row: int, col_id: int) -> int:
        low5 = abs_row & (NUM_BANKS - 1)
        return (col_id ^ low5) & (NUM_BANKS - 1)

    @staticmethod
    def _row_lane(abs_row: int, cols: int):
        banks = [] 
        slots = [] 
        valid = []
        for lane in range(NUM_BANKS):
            banks.append(AddressBlock._xor(abs_row, lane))
            slots.append(abs_row)
            valid.append(lane < cols)
        return banks, slots, valid

    @staticmethod
    def _col_lane(base_row: int, col_id: int, rows: int):
        banks = []
        slots = []
        valid = []
        for lane in range(NUM_BANKS):
            abs_row = base_row + lane
            banks.append(AddressBlock._xor(abs_row, col_id))
            slots.append(abs_row)
            valid.append(lane < rows)
        return banks, slots, valid

    @staticmethod
    def gen_masks_row(base_row: int, row_id: int, cols: int):
        abs_row = base_row + row_id
        lane_bank, lane_slot, lane_valid = AddressBlock._row_lane(abs_row, cols)

        shift_mask_lane2bank = [(lane_bank[i] if lane_valid[i] else None) for i in range(NUM_BANKS)]
        slot_mask = [None] * NUM_BANKS
        for i in range(NUM_BANKS):
            if lane_valid[i]:
                b = lane_bank[i]
                slot_mask[b] = lane_slot[i] 


        return shift_mask_lane2bank, slot_mask, lane_bank, lane_slot, lane_valid

    @staticmethod
    def gen_masks_col(base_row: int, col_id: int, rows: int):
        lane_bank, lane_slot, lane_valid = AddressBlock._col_lane(base_row, col_id, rows)

        shift_mask_lane2bank = [(lane_bank[i] if lane_valid[i] else None) for i in range(NUM_BANKS)]
        slot_mask = [None] * NUM_BANKS
        for i in range(NUM_BANKS):
            if lane_valid[i]:
                b = lane_bank[i]
                slot_mask[b] = lane_slot[i]  

        return shift_mask_lane2bank, slot_mask, lane_bank, lane_slot, lane_valid


def _parse_cell_triplet(cell: str):
    if not cell:
        return "", None, None
    parts = cell.split("_")
    if len(parts) < 3:
        return "", None, None
    try:
        r = int(parts[-2])
        c = int(parts[-1])
    except ValueError:
        return "", None, None
    tid = "_".join(parts[:-2])
    return tid, r, c

def save_png(sc0, path: str, annotate: bool=True, grid: bool=True):
    B, S = sc0.B, sc0.S

    tile_grid = [["" for _ in range(B)] for _ in range(S)]
    rc_grid = [[(None, None) for _ in range(B)] for _ in range(S)]
    tile_ids = set()

    for b in range(B):
        for s in range(S):
            tid, r, c = _parse_cell_triplet(sc0.banks[b][s])
            tile_grid[s][b] = tid
            rc_grid[s][b] = (r, c)
            if tid:
                tile_ids.add(tid)

    tile_ids = sorted(list(tile_ids))
    tid_to_idx = {tid: i+1 for i, tid in enumerate(tile_ids)}  

    idx_grid = np.zeros((S, B), dtype=int)
    for s in range(S):
        for b in range(B):
            tid = tile_grid[s][b]
            idx_grid[s, b] = tid_to_idx.get(tid, 0)

    base_colors = list(plt.cm.tab20.colors) + list(plt.cm.tab20b.colors) + list(plt.cm.tab20c.colors)
    if len(tile_ids) > len(base_colors):
        extra = len(tile_ids) - len(base_colors)
        hsv = [matplotlib.colors.hsv_to_rgb((h/max(1, extra), 0.5, 0.95)) for h in range(extra)]
        base_colors += hsv
    colors = ["white"] + base_colors[:len(tile_ids)]
    cmap = ListedColormap(colors)

    fig_w = max(20, B * 0.55) # 32 = B  -> banks
    fig_h = max(14, S * 0.35)  # 64 = S -> slots 
    fig, ax = plt.subplots(figsize=(fig_w, fig_h), dpi=350)
    im = ax.imshow(idx_grid, cmap=cmap, aspect="auto", interpolation="nearest", origin="upper")

    ax.set_xlabel("Bank (0..{})".format(B-1))
    ax.set_ylabel("Slot (0..{})".format(S-1))
    ax.set_xticks(np.arange(0, B, max(1, B//16)))
    ax.set_yticks(np.arange(0, S, max(1, S//16)))

    if grid:
        ax.set_xticks(np.arange(-0.5, B, 1), minor=True)
        ax.set_yticks(np.arange(-0.5, S, 1), minor=True)
        ax.grid(which="minor", linestyle="-", linewidth=0.2, alpha=0.4)

    if annotate:
        for s in range(S):
            for b in range(B):
                tid = tile_grid[s][b]
                if tid:
                    r, c = rc_grid[s][b]
                    # two-line text: tile_id on top, (r,c) below
                    ax.text(b, s-0.22, tid, ha='center', va='center', fontsize=5, fontweight='bold')
                    if r is not None and c is not None:
                        ax.text(b, s+0.22, f"({r},{c})", ha='center', va='center', fontsize=5)

    if tile_ids:
        patches = [Patch(facecolor=colors[tid_to_idx[tid]], edgecolor='black', label=tid) for tid in tile_ids]
        leg_cols = 1 if len(patches) < 12 else 2
        ax.legend(handles=patches, bbox_to_anchor=(1.02, 1), loc='upper left',
                  borderaxespad=0., ncol=leg_cols, title="Tile IDs")

    ax.set_title("Scratch0 Overview with Logical (row,col) per Cell")
    plt.tight_layout()
    plt.savefig(path, bbox_inches="tight")
    plt.close(fig)
    return path