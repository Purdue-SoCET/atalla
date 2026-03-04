#!/bin/bash
set -e

# which conv build (edit these two; keep in sync)
BUILD_SCRIPT="build_conv.py"
OUT_FILE="conv_sa.in"
# Data: ifmap = 0,1,2,... (NHWC), weights = 100,101,... (RSCK), C = zeros. See build_conv.py.

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
EMULATOR_DIR="$(dirname "$SCRIPT_DIR")"
PROJECT_ROOT="$(dirname "$EMULATOR_DIR")"

echo "=== Conv: build, run, validate ==="
echo "  $BUILD_SCRIPT -> $OUT_FILE"
echo

echo "[1/3] Build conv test image ($OUT_FILE)..."
cd "$EMULATOR_DIR"
python3 "$BUILD_SCRIPT" -o "$OUT_FILE"
echo "  Created $OUT_FILE"
echo

echo "[2/3] Run emulator on $OUT_FILE..."
python3 run.py --input_file "$OUT_FILE"
echo "  Emulator finished"
echo "  Outputs in: $EMULATOR_DIR/out/ (mem/sregs/vregs/scpad)"
echo

echo "[3/3] Validate emulator conv vs NumPy reference..."
cd "$PROJECT_ROOT"
python3 emulator/validate_conv_vs_pytorch.py --mem "$EMULATOR_DIR/out/output_mem.out"
echo

echo "Conv pipeline completed. Check above for MATCH/MISMATCH and error stats."

