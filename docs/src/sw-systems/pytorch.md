# PyTorch Infrastructure

This page is the docs guide for the Atalla PyTorch flow.

`atalla-graph` is the PyTorch front-end for Atalla. It takes a PyTorch model, traces it with `torch.fx`, lowers it into Atalla-supported ops, tiles tensors, and then either:

- emits a schedule (`graph_schedule.c`) and memory dump (`dram.bin`)for the schedule path, or
- compiles/emulates per-node kernels and compares against PyTorch reference outputs.

Implementation:

- https://github.com/Purdue-SoCET/atalla-models/tree/vihaanc-dev/atalla-graph

References:

- https://github.com/Purdue-SoCET/atalla-models/blob/vihaanc-dev/atalla-graph/README.md
- https://github.com/Purdue-SoCET/atalla-models/blob/vihaanc-dev/atalla-graph/run_graph.py

## Mode

`run_graph.py` supports:

- `schedule`: emit schedule artifacts (`graph_schedule.c`, `dram.bin`)
- `validate`: run compiler + emulator and compare outputs vs PyTorch
- `both`: run `schedule` and `validate`

## Validation Caveat

`validate` mode is not fully equivalent to validating schedule

- The schedule path assumes compute-only kernels, with SDMA movement emitted around those kernels.
- The validation path does per-node compile/emulate/compare against PyTorch.
- Because of this difference, validation is best used as functional correctness evidence, not a perfect runtime/performance model of full scheduled execution.

## Prerequisites

1. Python 3.11+ (recommended: 3.11)
2. `atalla-models` cloned with submodules
3. PyTorch dependencies installed in a virtual environment

Important:

- `validate` mode requires `functional_sim/` and `aihw-ppci-compiler/` submodules to be present.
- `schedule` mode does not require submodules beyond what is already in `atalla-models`.

## Example Commands

```bash
cd atalla-graph

# Schedule only
python3 run_graph.py --model basic --mode schedule --out-dir out/graph

# Validate only
python3 run_graph.py --model basic --mode validate

# Run both
python3 run_graph.py --model basic --mode both

# AlexNetSmall validation path
python3 run_graph.py --model alexnet_small --mode validate --scale 0.01

# Emit aggregate metrics JSON (for roofline/poster analysis)
python3 run_graph.py --model basic --mode validate --metrics-json metrics_basic.json
```

## Unit Tests

`atalla-graph` includes unit tests for the schedule

- `tests/test_op_steps.py`: unit-level operation step tests (`matmul`, `add`, `relu`) on simulated DRAM/SCPAD
- `tests/test_schedule_pipeline.py`: end-to-end schedule pipeline test (lowering, DRAM allocation/serialization, step generation, simulated execution, output vs PyTorch)

Run:

```bash
cd atalla-graph
python3 -m unittest -v tests/test_op_steps.py
python3 -m unittest -v tests/test_schedule_pipeline.py
```

## How To Add Your Own Model

1. Add model definition under `atalla-models/atalla-graph/model/`
2. Register it in `run_graph.py` model loader
3. Run `--mode schedule` first to ensure lowering/schedule emits
4. Run `--mode validate` to check emulator output vs PyTorch
5. If an op is unsupported, add lowering and/or kernel support

## Known Limitations

Current schedule path assumptions:

- `softmax` is tile-local (correct only when softmax axis fits in one tile)
- `maxpool` assumes one source tile per output tile
- `conv` schedule lowering is currently a stub tile-local call (not full lowering)

If you hit an unsupported op, schedule lowering raises:

- `Kernel does not exist for <op> (node <fx_node_name>)`
