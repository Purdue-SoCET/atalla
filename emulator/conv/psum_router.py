"""
PSUM Buffer Routing Algorithm

Maps systolic array column outputs → 32 PSUM buffers (FIFOs).
Direct-mapped: column c → buffer c. No crossbar needed.

Conflict-freedom proof:
  Each output cycle, all 32 columns produce values simultaneously.
  buffer_index = column_index → all 32 targets are distinct.
  No two columns ever hit the same buffer in the same cycle.

Accumulation across K-tiles:
  Same column always maps to same buffer, so partial sums from
  successive K-tiles accumulate in-place. After all K-tiles for
  a C_out tile are done, buffers drain final results to VREGs.
"""
from __future__ import annotations

from dataclasses import dataclass, field
from typing import List, Optional, Dict

import numpy as np

ARRAY_SIZE = 32


@dataclass
class PSUMBuffer:
    """One of 32 PSUM FIFOs. Accumulates across K-tiles, drains when all K-tiles done."""
    column: int
    entries: Dict[int, float] = field(default_factory=dict)
    drain_order: List[int] = field(default_factory=list)

    def accumulate(self, spatial_pos: int, value: float):
        if spatial_pos in self.entries:
            self.entries[spatial_pos] += value
        else:
            self.entries[spatial_pos] = value
            self.drain_order.append(spatial_pos)

    def drain_one(self) -> Optional[tuple]:
        """Pop oldest entry. Returns (spatial_pos, accumulated_value) or None."""
        if not self.drain_order:
            return None
        sp = self.drain_order.pop(0)
        val = self.entries.pop(sp)
        return sp, val

    @property
    def occupancy(self) -> int:
        return len(self.entries)

    def reset(self):
        self.entries.clear()
        self.drain_order.clear()


@dataclass
class PSUMRouter:
    """
    Direct-mapped PSUM router for K-rows / C_out-cols mapping.
    column c → buffer c (no crossbar).
    """
    sz: int = ARRAY_SIZE
    buffers: List[PSUMBuffer] = field(default_factory=list)

    def __post_init__(self):
        if not self.buffers:
            self.buffers = [PSUMBuffer(column=c) for c in range(self.sz)]

    def reset(self):
        for buf in self.buffers:
            buf.reset()

    def route_output_row(self, column_values: np.ndarray, n_tile: int, spatial_pos: int):
        """Route one cycle's 32-column output to buffers. Direct-mapped: col c → buf c."""
        for c in range(min(n_tile, self.sz)):
            self.buffers[c].accumulate(spatial_pos, float(column_values[c]))

    def drain_all(self, n_tile: int) -> List[List[tuple]]:
        """Drain all buffers. Returns list of (cycle_results), each a list of (buf, spatial_pos, value)."""
        all_results = []
        while any(self.buffers[c].occupancy > 0 for c in range(n_tile)):
            cycle_results = []
            for c in range(n_tile):
                result = self.buffers[c].drain_one()
                if result:
                    sp, val = result
                    cycle_results.append((c, sp, val))
            if not cycle_results:
                break
            all_results.append(cycle_results)
        return all_results


def simulate_with_routing(sim) -> dict:
    """
    Run the K-rows/C_out-cols sim with PSUM buffer routing.
    Returns {ofmap, router, verified, max_abs_diff}.
    """
    from im2col import direct_conv_hwc

    cfg = sim.cfg
    sim.ofmap = np.zeros((cfg.N, sim.Ho, sim.Wo, cfg.K), dtype=float)
    padded = sim._pad_ifmap()
    K_flat = cfg.R * cfg.S * cfg.C
    M = cfg.N * sim.Ho * sim.Wo
    sz = cfg.array_size

    router = PSUMRouter(sz=sz)

    # C_out tiles outer, K tiles inner → accumulate in same buffers before draining
    for n_start in range(0, cfg.K, sz):
        n_end = min(n_start + sz, cfg.K)
        n_tile = n_end - n_start

        for k_start in range(0, K_flat, sz):
            k_end = min(k_start + sz, K_flat)
            k_tile = k_end - k_start
            W_tile = np.zeros((sz, sz), dtype=float)
            W_block = sim.weights[:, :, :, n_start:n_end].reshape(K_flat, -1)
            W_tile[:k_tile, :n_tile] = W_block[k_start:k_end, :]

            for m in range(M):
                n_b = m // (sim.Ho * sim.Wo)
                oh = (m // sim.Wo) % sim.Ho
                ow = m % sim.Wo
                rf = sim._receptive_flat(padded, n_b, oh, ow)
                in_row = np.zeros((sz,), dtype=float)
                in_row[:k_tile] = rf[k_start:k_end]
                out_row = in_row[:k_tile] @ W_tile[:k_tile, :n_tile]
                router.route_output_row(out_row, n_tile, m)

        # All K-tiles accumulated; drain buffers → ofmap
        drained = router.drain_all(n_tile)
        for cycle_results in drained:
            for col, sp, val in cycle_results:
                n_b = sp // (sim.Ho * sim.Wo)
                oh = (sp // sim.Wo) % sim.Ho
                ow = sp % sim.Wo
                sim.ofmap[n_b, oh, ow, n_start + col] = val

        router.reset()

    ref = direct_conv_hwc(sim.ifmap, sim.weights, stride=cfg.stride, pad=cfg.pad)
    diff = float(np.max(np.abs(ref - sim.ofmap)))

    return {
        "ofmap": sim.ofmap,
        "router": router,
        "max_abs_diff": diff,
        "verified": diff < 1e-6,
    }
