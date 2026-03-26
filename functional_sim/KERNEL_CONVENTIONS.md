# functional_sim kernel conventions

Use this format for all future kernels so build/run/validate is predictable.

## file layout
- `build_<kernel>.py` builds a `.in` image into `tests/`.
- `validate_<kernel>.py` compares simulator output vs reference.
- `run_and_compare_<kernel>.sh` runs build -> run -> validate.
- Generated images live in `tests/<kernel>.in` (or `<kernel>_pipelined.in`).

## import and execution contract
- Kernel builders should import shared helpers from local `build.py`.
- Do not import from top-level sibling folders (for example `../kernels`).
- `run.py` and `build.py` support both:
  - module mode from repo root: `python3 -m functional_sim.run ...`
  - script mode from `functional_sim/`: `python3 run.py ...`

## required smoke test
From `functional_sim/`, every new kernel should pass:

```bash
python3 build_<kernel>.py -o tests/<kernel>.in
python3 run.py --input_file tests/<kernel>.in
python3 validate_<kernel>.py --mem out/output_mem.out
```

## conv naming
- Baseline builder: `build_conv.py`
- Pipelined builder: `build_conv_pipelined.py`
- Unrolled+pipelined builder: `build_conv_unrolled_pipelined.py`
- Runner switch:
  - `BUILD_SCRIPT="build_conv.py"` + `OUT_FILE="tests/conv_sa.in"`
  - `BUILD_SCRIPT="build_conv_pipelined.py"` + `OUT_FILE="tests/conv_sa_pipelined.in"`
  - `BUILD_SCRIPT="build_conv_unrolled_pipelined.py"` + `OUT_FILE="tests/conv_sa_unrolled_pipelined.in"`
