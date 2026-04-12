# Functional sim — kernel builders and scheduling

## Frozen user-facing modes

1. **Default (linear / structural)**  
   `assemble_file` + `emit_test_format`: one assembled statement per virtual row. No DAG stall rows. Use for correctness demos and static slot / structural metrics.

2. **`--dag-pack` (conv family only)**  
   Program-order wide VLIW packing, branch immediate patch, and BR10 preflight (`emit_test_format_latency_program_order` with `latency_stalls=False`). Better static packing without materializing long-latency wait rows.

3. **`--latency` (experimental)**  
   On branch-light kernels (softmax, layernorm*, attention): `build_dependency_graph` + `greedy_pack` inserts empty packet rows from modeled op latencies.  
   With **`--dag-pack`** on conv: same packer path with `latency_stalls=True` — often violates BR10 on loop back-edges; preflight fails with a clear error.

**`--bb-local`** (optional, **requires `--dag-pack`**): experimental basic-block–local program-order packing only; no new flags beyond this freeze.

## Deprecated CLI (hidden)

- **`--graph`** — silent alias for **`--latency`** (for old scripts).
- **`--no-graph`** — redundant with default; **`--no-graph` together with `--latency`** is rejected.

## Metrics artifacts

From `functional_sim/`:

```bash
PYTHONPATH="$(pwd)/..:$(pwd)" python3 collect_kernel_metrics.py
python3 plot_kernel_metrics.py
```

Writes `out/kernel_metrics.csv`, figures under `out/plots/` (including **`scheduling_metrics.png`** — static slot util % and static rows per dynamic op). Layernorm’s DAG-stall variant is labeled **`layernorm (latency)`** in the CSV.

## Not implemented here

Simulator-side latency (scoreboard / retire timing without growing static instr-mem) is future work; static **`--latency`** is layout-only.
