# PSUM Buffer Routing Algorithm

**Datapath:** Sys.Array Output → PSUM Buffer → VREG File

---

## The Problem

The systolic array computes 32×32 matrix multiply tiles. Each output cycle, 32 partial sum values emerge from the bottom row — one per column. The question: **where does each value go?**

If two columns target the same buffer on the same cycle, you need a crossbar (expensive area/complexity). The goal was to find a routing scheme that avoids this.

## The Routing Rule

```
buffer_index = column_index
```

Column `c` of the systolic array always writes to PSUM buffer `c`. Direct wiring, no crossbar, no mux, no arbitration.

### Why This Is Conflict-Free

1. Each output cycle, exactly 32 values emerge (one per column)
2. Column indices are 0, 1, 2, ..., 31 — all distinct
3. `buffer_index = column_index` → all 32 targets are distinct every cycle
4. No two columns ever hit the same buffer in the same cycle ∎

This holds regardless of layer dimensions, tiling, or data values. It's a structural property of the mapping.

## K-Tile Accumulation

When K\_flat (= R × S × C\_in) exceeds 32, the convolution splits into multiple K-tiles. Each K-tile computes a partial dot product for the same output position; the buffer accumulates them in-place:

- **K-tile 0:** `buf[c] = input[0:32] @ weight[0:32, c]`
- **K-tile 1:** `buf[c] += input[32:64] @ weight[32:64, c]`
- **K-tile 2:** `buf[c] += input[64:90] @ weight[64:90, c]` (26 active, 6 idle — zero-padded)
- **Result:** `buf[c] = full dot product (length 90)` ✓

Same column → same buffer → partials add up. When K\_flat isn't divisible by 32, the last tile has idle rows (zero-padded, contribute nothing).

## Loop Ordering

```
for each C_out tile:                  # outer
    for each K tile:                  # inner — accumulate in same buffers
        for each output position:
            route column outputs → buffers
    drain all buffers → VREGs         # all K-tile partials accumulated
```

**C\_out must be the outer loop.** All K-tile partial sums accumulate in the same buffer set before draining. If K were outer, you'd need to read-modify-write VREGs for every K-tile, defeating the purpose of the buffers.

## Tiling

| Dimension | What | Tiles |
|---|---|---|
| K (rows) | R × S × C\_in flattened | ⌈K\_flat / 32⌉ |
| C\_out (cols) | Output channels | ⌈C\_out / 32⌉ |
| M (spatial) | N × H\_out × W\_out output positions | streamed through |

---

## Buffer Analysis

![PSUM Routing](psum_routing.png)

### (a) FIFO Buffer Depth per Layer

Shows how many entries each PSUM buffer must hold, equal to `H_out × W_out` (for N=1). Early layers (224→112) need ~12.5K entries; final layers (7×7) need only 49. This is the key hardware sizing parameter — buffer memory scales with spatial size, not channel count.

### (b) Accumulations per Buffer Entry

Number of times each buffer entry gets accumulated before drain (= K-tiles = ⌈K\_flat / 32⌉). Later layers with large K\_flat (e.g., 3×3 × 512 = 4608 → 144 K-tiles) accumulate heavily, demonstrating the accumulation mechanism working across many partial sums.

### (c) Buffer Depth Scaling

Parametric view: buffer depth = H\_out² regardless of channel dimensions. All three layer types (3×3 C=512, 1×1 C=256→1024, 3×3 C=64) follow the same curve. Final-layer buffers (7×7 = 49 entries, 1×1 = 1 entry) are very small — favorable for hardware.

### (d) Sim-Verified Configs

Diverse configs run through the full routing simulation (random data, actual convolution, verify against reference). All pass, including:
- Small spatial: 4×4, 2×2, 1×1 (global)
- Non-32-divisible K\_flat (=90)
- Strided + padded + multi-batch (N=2)
- High accumulation depth (144 K-tiles for 3×3 × 512)

---

## Mapping & Tiling (separate concern)

![Mapping Analysis](mapping_analysis.png)

PE utilization, tiling breakdown, and cross-model comparison for the K-rows / C\_out-cols mapping. This is about the mapping strategy, not the routing — included for reference.

---

## Verification Summary

All tested configs pass (routed output matches reference convolution to < 1e-6 error). This includes standard layers, all five ResNet-50 stages, non-32-divisible K\_flat, small spatial sizes (down to 1×1), multi-batch, stride > 1, and random data.

## What This Means for Hardware

- **No crossbar needed** — direct wiring is sufficient
- **Buffer count:** 32 (one per column)
- **Buffer behavior:** FIFO, accumulate-on-hit for K-tile partials, drain when all K-tiles done
- **Buffer depth:** bounded by M = H\_out × W\_out; 49 entries for 7×7 final layers, 1 for global
- **Routing is software-managed** via tiling loop order, not dynamic hardware arbitration

## Timing

Exact cycle counts depend on MEISSA systolic array latencies (pipeline depth, weight load time, etc.) which are being determined by the hardware team. The routing algorithm is correct regardless of those parameters.

---

## Files

| File | What |
|---|---|
| `psum_router.py` | PSUMBuffer, PSUMRouter, `simulate_with_routing()` |
| `sweep_routing.py` | Routing-specific figure (buffer analysis) |
| `sweep_mapping.py` | Mapping figure (utilization, tiling, cross-model) |
| `psum_routing.png/pdf` | Buffer depth, accumulations, scaling, verification |
| `mapping_analysis.png/pdf` | Utilization, tiling breakdown, cross-model |
| `im2col.py` | Core conv simulator |
| `streamlit_app.py` | Interactive visualization |
