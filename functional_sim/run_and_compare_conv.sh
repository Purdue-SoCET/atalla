#!/bin/bash
set -e

# Edit these two lines (keep in sync)
# BUILD_SCRIPT: build_conv.py | build_conv_pipelined.py | build_conv_unrolled_pipelined.py
# OUT_FILE:     tests/conv_sa.in | tests/conv_sa_pipelined.in | tests/conv_sa_unrolled_pipelined.in
BUILD_SCRIPT="build_conv.py"
OUT_FILE="tests/conv_sa.in"

echo "=== Conv: build, run, validate (functional_sim) ==="
echo "  $BUILD_SCRIPT -> $OUT_FILE"
echo

echo "[1/3] Build conv test image..."
python3 "$BUILD_SCRIPT" -o "$OUT_FILE"
echo "  Created $OUT_FILE"
echo

echo "[2/3] Run functional_sim..."
python3 run.py --input_file "$OUT_FILE"
echo "  Outputs in: ./out/"
echo

echo "[3/3] Validate vs reference..."
python3 validate_conv_vs_pytorch.py --mem out/output_mem.out
echo
echo "Done."
