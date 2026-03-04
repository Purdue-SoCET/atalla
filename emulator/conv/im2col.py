from dataclasses import dataclass
import numpy as np

# Atalla fixed 32×32 systolic array.
SYSTOLIC_ARRAY_SIZE = 32

"""
Tiling (32×32 array, inference mapping = K-rows / C_out-cols):
- Kernel (K) tiling: rows tile in chunks of 32 (k_start, k_end).
- Output-channel (N/C_out) tiling: cols tile in chunks of 32 (n_start, n_end).
- Output spatial tiling: M = N*Ho*Wo streamed in tiles of SPATIAL_TILE_SIZE to structure reuse.
"""
SPATIAL_TILE_SIZE = 32  # output positions per spatial tile (same kernel reused)


@dataclass
class SimConfig:
    N: int
    H: int
    W: int
    C: int
    K: int
    R: int
    S: int
    stride: int = 1
    pad: int = 0
    seed: int = 0
    use_sequential_init: bool = True
    """If True: fill IFMap/weights with 0,1,2,... for deterministic debugging. If False: random integers from seed."""

    @property
    def array_size(self) -> int:
        return SYSTOLIC_ARRAY_SIZE


class ImplicitIm2colSystolicSim:
    def __init__(self, cfg: SimConfig, ifmap=None, weights=None):
        self.cfg = cfg
        self._validate()
        self.Ho = (cfg.H + 2 * cfg.pad - cfg.R) // cfg.stride + 1
        self.Wo = (cfg.W + 2 * cfg.pad - cfg.S) // cfg.stride + 1

        rng = np.random.default_rng(cfg.seed)
        if ifmap is None:
            if cfg.use_sequential_init:
                self.ifmap = np.arange(cfg.N * cfg.H * cfg.W * cfg.C).reshape(
                    cfg.N, cfg.H, cfg.W, cfg.C
                )
            else:
                self.ifmap = rng.integers(0, 10, (cfg.N, cfg.H, cfg.W, cfg.C))
        else:
            self.ifmap = np.array(ifmap, copy=True)

        if weights is None:
            if cfg.use_sequential_init:
                self.weights = np.arange(cfg.R * cfg.S * cfg.C * cfg.K).reshape(
                    cfg.R, cfg.S, cfg.C, cfg.K
                )
            else:
                self.weights = rng.integers(0, 10, (cfg.R, cfg.S, cfg.C, cfg.K))
        else:
            self.weights = np.array(weights, copy=True)

        self.ofmap = np.zeros((cfg.N, self.Ho, self.Wo, cfg.K), dtype=float)

    def _validate(self):
        cfg = self.cfg
        if cfg.H + 2 * cfg.pad < cfg.R or cfg.W + 2 * cfg.pad < cfg.S:
            raise ValueError("Kernel larger than padded input.")
        if cfg.stride <= 0:
            raise ValueError("stride must be >= 1.")

    def _pad_ifmap(self):
        cfg = self.cfg
        return np.pad(
            self.ifmap,
            ((0, 0), (cfg.pad, cfg.pad), (cfg.pad, cfg.pad), (0, 0)),
            mode="constant",
        )

    def explicit_im2col_channel_first(self):
        cfg = self.cfg
        padded = self._pad_ifmap()
        rows = []
        for n in range(cfg.N):
            for oh in range(self.Ho):
                for ow in range(self.Wo):
                    cols = []
                    for r in range(cfg.R):
                        for s in range(cfg.S):
                            ih = oh * cfg.stride + r
                            iw = ow * cfg.stride + s
                            cols.extend(padded[n, ih, iw, :].tolist())
                    rows.append(cols)
        return np.array(rows)

    def weight_tile(self, r, s):
        cfg = self.cfg
        tile = np.zeros((cfg.array_size, cfg.array_size), dtype=float)
        cin_limit = min(cfg.C, cfg.array_size)
        kout_limit = min(cfg.K, cfg.array_size)
        tile[:cin_limit, :kout_limit] = self.weights[r, s, :cin_limit, :kout_limit]
        return tile

    def input_word(self, padded_ifmap, n, ih, iw):
        cfg = self.cfg
        word = padded_ifmap[n, ih, iw, :]
        if word.shape[0] < cfg.array_size:
            padded = np.zeros((cfg.array_size,), dtype=word.dtype)
            padded[: word.shape[0]] = word
            return padded
        return word[: cfg.array_size]

    def _receptive_flat(self, padded_ifmap, n, oh, ow):
        """Receptive field at (oh, ow) for batch n, flattened in (r,s,c) order. Shape (R*S*C,)."""
        cfg = self.cfg
        out = np.zeros((cfg.R * cfg.S * cfg.C,), dtype=float)
        for r in range(cfg.R):
            for s in range(cfg.S):
                ih, iw = oh * cfg.stride + r, ow * cfg.stride + s
                idx = r * cfg.S * cfg.C + s * cfg.C
                out[idx : idx + cfg.C] = padded_ifmap[n, ih, iw, :]
        return out

    def simulate(self, trace=True, max_logs=None, mapping=None):
        if mapping is None:
            mapping = "k_rows_n_cols"
        if mapping == "k_rows_n_cols":
            return self.simulate_k_rows_n_cols(trace=trace, max_logs=max_logs)
        return self._simulate_batch_parallel(trace, max_logs)

    def _simulate_batch_parallel(self, trace=True, max_logs=None):
        """Rows = kernel dims, cols = batch. Best when N is large."""
        cfg = self.cfg
        self.ofmap = np.zeros((cfg.N, self.Ho, self.Wo, cfg.K), dtype=float)
        padded_ifmap = self._pad_ifmap()
        kernel_flatten = cfg.R * cfg.S * cfg.C
        batch_tile = min(cfg.N, cfg.array_size)
        step_logs = []
        total_pe_cycles = 0
        total_possible_pe_cycles = 0

        for oh in range(self.Ho):
            for ow in range(self.Wo):
                for k in range(cfg.K):
                    kernel_flat = self.weights[:, :, :, k].flatten()
                    for batch_start in range(0, cfg.N, batch_tile):
                        batch_end = min(batch_start + batch_tile, cfg.N)
                        n_batch = batch_end - batch_start
                        for row_start in range(0, kernel_flatten, cfg.array_size):
                            row_end = min(row_start + cfg.array_size, kernel_flatten)
                            n_rows = row_end - row_start
                            total_possible_pe_cycles += cfg.array_size * cfg.array_size

                            W_block = np.zeros((cfg.array_size, cfg.array_size), dtype=float)
                            W_block[:n_rows, :n_batch] = np.broadcast_to(
                                kernel_flat[row_start:row_end, None], (n_rows, n_batch)
                            )
                            A_block = np.zeros((cfg.array_size, cfg.array_size), dtype=float)
                            for j, n in enumerate(range(batch_start, batch_end)):
                                rf = self._receptive_flat(padded_ifmap, n, oh, ow)
                                A_block[:n_rows, j] = rf[row_start:row_end]

                            partial = np.zeros((n_batch,), dtype=float)
                            for j in range(n_batch):
                                partial[j] = float(np.dot(A_block[:n_rows, j], W_block[:n_rows, j]))

                            for j, n in enumerate(range(batch_start, batch_end)):
                                self.ofmap[n, oh, ow, k] += partial[j]

                            active_pe = n_rows * n_batch
                            total_pe_cycles += active_pe
                            pe_util = active_pe / (cfg.array_size * cfg.array_size)

                            do_log = trace and (max_logs is None or len(step_logs) < max_logs)
                            if do_log:
                                running_psum = np.zeros((cfg.array_size,), dtype=float)
                                timeline = []
                                for t in range(cfg.array_size):
                                    row_in = [0.0] * cfg.array_size
                                    if t < n_rows:
                                        row_in[:n_batch] = A_block[t, :n_batch]
                                        for j in range(n_batch):
                                            running_psum[j] += A_block[t, j] * W_block[t, j]
                                    timeline.append({
                                        "t": t,
                                        "row_inputs": row_in[:],
                                        "partial_sums": running_psum.copy(),
                                    })
                                step_logs.append({
                                    "oh": oh, "ow": ow, "k": k, "batch_start": batch_start, "row_start": row_start,
                                    "n_rows": n_rows, "n_batch": n_batch,
                                    "weight_block": W_block[:n_rows, :n_batch].copy(),
                                    "input_block": A_block[:n_rows, :n_batch].copy(),
                                    "partial_sums": partial.copy(),
                                    "pe_util": pe_util,
                                    "active_pe": active_pe,
                                    "timeline": timeline,
                                })

        util_stats = {
            "total_pe_cycles": total_pe_cycles,
            "total_possible_pe_cycles": total_possible_pe_cycles,
            "utilization": total_pe_cycles / total_possible_pe_cycles if total_possible_pe_cycles else 0,
            "mapping": "batch_parallel",
        }
        return self.ofmap, step_logs, util_stats

    def simulate_k_rows_n_cols(self, trace=True, max_logs=None):
        """
        K tiling + N (C_out) tiling + output spatial tiling
        Rows = kernel dims, cols = output channels; M = N*Ho*Wo streamed in spatial tiles
        """
        cfg = self.cfg
        self.ofmap = np.zeros((cfg.N, self.Ho, self.Wo, cfg.K), dtype=float)
        padded_ifmap = self._pad_ifmap()
        K_flat = cfg.R * cfg.S * cfg.C
        M = cfg.N * self.Ho * self.Wo
        sz = cfg.array_size
        step_logs = []
        total_pe, total_possible = 0, 0

        for k_start in range(0, K_flat, sz):
            k_end = min(k_start + sz, K_flat)
            k_tile = k_end - k_start
            for n_start in range(0, cfg.K, sz):
                n_end = min(n_start + sz, cfg.K)
                n_tile = n_end - n_start
                W_tile = np.zeros((sz, sz), dtype=float)
                W_block = self.weights[:, :, :, n_start:n_end].reshape(K_flat, -1)
                W_tile[:k_tile, :n_tile] = W_block[k_start:k_end, :]

                for m_tile_start in range(0, M, SPATIAL_TILE_SIZE):
                    m_tile_end = min(m_tile_start + SPATIAL_TILE_SIZE, M)
                    for m in range(m_tile_start, m_tile_end):
                        n_b = m // (self.Ho * self.Wo)
                        oh = (m // self.Wo) % self.Ho
                        ow = m % self.Wo
                        rf = self._receptive_flat(padded_ifmap, n_b, oh, ow)
                        in_row = np.zeros((sz,), dtype=float)
                        in_row[:k_tile] = rf[k_start:k_end]
                        out_row = in_row[:k_tile] @ W_tile[:k_tile, :n_tile]
                        self.ofmap[n_b, oh, ow, n_start:n_end] += out_row

                        total_pe += k_tile * n_tile
                        total_possible += sz * sz

                        do_log = trace and (max_logs is None or len(step_logs) < max_logs)
                        if do_log and m == m_tile_start:
                            row_inputs = [float(in_row[i]) if i < k_tile else np.nan for i in range(sz)]
                            psum_pad = list(out_row) + [np.nan] * (sz - len(out_row))
                            step_logs.append({
                                "k_start": k_start, "n_start": n_start,
                                "m": m, "n_b": n_b, "oh": oh, "ow": ow,
                                "n_rows": k_tile, "n_batch": n_tile,
                                "weight_block": W_tile[:k_tile, :n_tile].copy(),
                                "input_block": in_row[:k_tile].reshape(-1, 1),
                                "partial_sums": out_row.copy(),
                                "pe_util": (k_tile * n_tile) / (sz * sz),
                                "active_pe": k_tile * n_tile,
                                "k": n_start,
                                "timeline": [{"t": 0, "row_inputs": row_inputs, "partial_sums": psum_pad[:sz]}],
                            })

        util_stats = {
            "total_pe_cycles": total_pe,
            "total_possible_pe_cycles": total_possible,
            "utilization": total_pe / total_possible if total_possible else 0,
            "mapping": "k_rows_n_cols",
        }
        return self.ofmap, step_logs, util_stats


def utilization_batch_parallel(cfg: SimConfig):
    """map rows=kernel, cols=batch"""
    K_flat = cfg.R * cfg.S * cfg.C
    Ho = (cfg.H + 2 * cfg.pad - cfg.R) // cfg.stride + 1
    Wo = (cfg.W + 2 * cfg.pad - cfg.S) // cfg.stride + 1
    sz = SYSTOLIC_ARRAY_SIZE
    total_pe, total_possible = 0, 0
    for _oh in range(Ho):
        for _ow in range(Wo):
            for _k in range(cfg.K):
                for batch_start in range(0, cfg.N, sz):
                    n_batch = min(sz, cfg.N - batch_start) # active cols (batch)
                    for row_start in range(0, K_flat, sz):
                        n_rows = min(sz, K_flat - row_start) # active rows (kernel)
                        total_pe += n_rows * n_batch
                        total_possible += sz * sz
    return (total_pe / total_possible) if total_possible else 0, total_pe, total_possible

""" k rows/cout cols = (R*S*Cin / ([R * S * Cin / Sz] * Sz)) * Cout / ([Cout / Sz] * Sz)
    batch parallel = (R*S*Cin / ([R * S * Cin / Sz] * Sz)) * N / ([N / Sz] * Sz)"""
def utilization_k_rows_n_cols(cfg: SimConfig):
    """map rows=kernel, cols=C_out """
    K_flat = cfg.R * cfg.S * cfg.C
    Ho = (cfg.H + 2 * cfg.pad - cfg.R) // cfg.stride + 1
    Wo = (cfg.W + 2 * cfg.pad - cfg.S) // cfg.stride + 1
    M = cfg.N * Ho * Wo
    N_out = cfg.K  # C_out
    sz = SYSTOLIC_ARRAY_SIZE
    total_pe, total_possible = 0, 0
    for k_start in range(0, K_flat, sz):
        k_tile = min(sz, K_flat - k_start) # active rows per k tile
        for n_start in range(0, N_out, sz):
            n_tile = min(sz, N_out - n_start) # active cols per c out tile
            total_pe += M * (k_tile * n_tile)
            total_possible += M * (sz * sz)
    return (total_pe / total_possible) if total_possible else 0, total_pe, total_possible


def best_mapping(cfg: SimConfig):
    """picks best of batch_parallel|k_rows_n_cols"""
    u_bp, _, _ = utilization_batch_parallel(cfg)
    u_kn, _, _ = utilization_k_rows_n_cols(cfg)
    if u_kn >= u_bp:
        return "k_rows_n_cols", u_kn
    return "batch_parallel", u_bp


def direct_conv_hwc(ifmap, weights, stride=1, pad=0):
    n, h, w, c = ifmap.shape
    r, s, c2, k = weights.shape
    if c != c2:
        raise ValueError("IFMap C and weight C mismatch.")
    ho = (h + 2 * pad - r) // stride + 1
    wo = (w + 2 * pad - s) // stride + 1
    padded = np.pad(ifmap, ((0, 0), (pad, pad), (pad, pad), (0, 0)), mode="constant")
    out = np.zeros((n, ho, wo, k), dtype=float)
    for nn in range(n):
        for oh in range(ho):
            for ow in range(wo):
                acc = np.zeros((k,), dtype=float)
                for rr in range(r):
                    for ss in range(s):
                        ih = oh * stride + rr
                        iw = ow * stride + ss
                        acc += padded[nn, ih, iw, :] @ weights[rr, ss, :, :]
                out[nn, oh, ow, :] = acc
    return out


def main():
    cfg = SimConfig(N=2, H=4, W=4, C=3, K=2, R=2, S=2, stride=1, pad=0, use_sequential_init=True)
    sim = ImplicitIm2colSystolicSim(cfg)
    ref = direct_conv_hwc(sim.ifmap, sim.weights, stride=cfg.stride, pad=cfg.pad)
    ofmap, step_logs, util_stats = sim.simulate(trace=True, max_logs=6)
    print(f"Utilization: {util_stats['utilization']:.4f}")
    print("  total_pe_cycles:", util_stats["total_pe_cycles"], " total_possible:", util_stats["total_possible_pe_cycles"])
    for i, entry in enumerate(step_logs):
        print(f"  step {i}: (oh,ow)=({entry['oh']},{entry['ow']}) k={entry['k']} n_rows={entry['n_rows']} n_batch={entry['n_batch']} pe_util={entry['pe_util']:.4f}")
    diff = np.max(np.abs(ref - ofmap))
    print("Verify:", "PASS" if diff < 1e-6 else "FAIL", f" max_abs_diff={diff}")


if __name__ == "__main__":
    main()