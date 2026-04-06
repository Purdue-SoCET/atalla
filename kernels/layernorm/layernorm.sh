#!/usr/bin/env bash
# =============================================================================
# layernorm.sh — End-to-end kernel emulation + PyTorch comparison for LayerNorm
#
# Usage:
#   bash kernels/layernorm/layernorm.sh [--n 4] [--debug]
#
# This script:
#   1. Generates random N×N tile data as CSV (bf16-bounded, seed 67)
#   2. Builds the parameterized emulator input image via build_layernorm_param.py
#   3. Runs the emulator on that image
#   4. Compares the emulator output against a PyTorch golden reference
# =============================================================================
set -euo pipefail

# ---------- Resolve project root (atalla/) from this script's location ------
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ATALLA_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

# ---------- Run from project root for module-based execution -----------------
cd "$ATALLA_ROOT"

# ---------- Detect Python ---------------------------------------------------
if command -v python3 &>/dev/null; then
    PYTHON=python3
elif command -v python &>/dev/null; then
    PYTHON=python
else
    echo "[ERROR] No python3 or python found on PATH"; exit 1
fi

# ---------- Ensure required Python packages are installed -------------------
REQUIRED_PACKAGES=(numpy torch)
MISSING=()
for pkg in "${REQUIRED_PACKAGES[@]}"; do
    if ! $PYTHON -c "import $pkg" &>/dev/null; then
        MISSING+=("$pkg")
    fi
done
if [ ${#MISSING[@]} -gt 0 ]; then
    echo "[SETUP] Installing missing Python packages: ${MISSING[*]} ..."
    $PYTHON -m pip install --quiet "${MISSING[@]}" || {
        echo "[ERROR] pip install failed. Try: $PYTHON -m ensurepip --upgrade"
        exit 1
    }
    echo "[SETUP] Done."
    echo ""
fi

# ---------- Defaults --------------------------------------------------------
KERNEL="layernorm"
BUILD_NAME="layernorm_param"
N=32
DEBUG_FLAG=""

# bf16 practical bounds for stable layernorm computation.
# bf16 max ≈ 3.39e38, but variance calculation (sum of squares over N^2
# elements) overflows float32 at large magnitudes. Use ±100 which is
# exactly representable in bf16 and safe for tiles up to 32×32.
BF16_MAX=100
BF16_MIN=-100
DATA_SEED=67

# ---------- Argument parsing ------------------------------------------------
while [[ $# -gt 0 ]]; do
    case "$1" in
        --n)
            N="$2"; shift 2 ;;
        --debug)
            DEBUG_FLAG="--debug"; shift ;;
        -h|--help)
            echo "Usage: bash $0 [--n N] [--debug]"
            echo ""
            echo "  --n N          Tile dimension N×N (default: 4)"
            echo "  --debug        Enable verbose emulator output"
            exit 0 ;;
        *)
            echo "[ERROR] Unknown argument: $1"; exit 1 ;;
    esac
done

# ---------- Derived paths ---------------------------------------------------
DATA="$SCRIPT_DIR/layernorm_data.csv"
OUTPUT_DIR="$SCRIPT_DIR/${BUILD_NAME}_output"
IN_FILE="$SCRIPT_DIR/${BUILD_NAME}.in"

OUT_MEM="$OUTPUT_DIR/output_mem.out"
OUT_SREGS="$OUTPUT_DIR/output_sregs.out"
OUT_VREGS="$OUTPUT_DIR/output_vregs.out"
OUT_MREGS="$OUTPUT_DIR/output_mregs.out"
OUT_SCPAD0="$OUTPUT_DIR/output_scpad0.out"
OUT_SCPAD1="$OUTPUT_DIR/output_scpad1.out"
OUT_PERF="$OUTPUT_DIR/output_perf_metrics.out"

echo "============================================================"
echo "  Kernel Emulation Pipeline: $BUILD_NAME  (${N}×${N})"
echo "============================================================"
echo ""

# ---------- Step 0: Generate tile data --------------------------------------
echo "[GEN_DATA] Generating ${N}×${N} random tile (seed=$DATA_SEED, bf16 bounds) ..."
echo "  Output    : $DATA"
echo ""

$PYTHON -m kernels.utils.gen_data \
    --n "$N" \
    --mode random \
    --seed "$DATA_SEED" \
    --low="$BF16_MIN" \
    --high="$BF16_MAX" \
    --output "$DATA"

echo ""

# ---------- Step 1: Build ---------------------------------------------------
echo "[BUILD] Running functional_sim.build_${BUILD_NAME} ..."
echo "  Data file : $DATA"
echo "  Output    : $IN_FILE"
echo ""

$PYTHON -m "functional_sim.build_${BUILD_NAME}" \
    --data "$DATA" \
    --n "$N" \
    --output "$IN_FILE"

echo "[BUILD] Done."
echo ""

# ---------- Step 2: Emulate -------------------------------------------------
echo "[EMULATE] Running functional_sim ..."
mkdir -p "$OUTPUT_DIR"

$PYTHON -m functional_sim.run \
    --input_file "$IN_FILE" \
    --output_mem_file   "$OUT_MEM" \
    --output_sreg_file  "$OUT_SREGS" \
    --output_vreg_file  "$OUT_VREGS" \
    --output_mreg_file  "$OUT_MREGS" \
    --output_scpad_file0 "$OUT_SCPAD0" \
    --output_scpad_file1 "$OUT_SCPAD1" \
    --output_perf_file  "$OUT_PERF"
    $DEBUG_FLAG

echo "[EMULATE] Done.  Outputs in $OUTPUT_DIR"
echo ""

# ---------- Step 3: Compare -------------------------------------------------
echo "[COMPARE] Running PyTorch comparison ..."
echo ""

$PYTHON -m kernels.utils.compare_pytorch \
    --kernel "$KERNEL" \
    --n "$N" \
    --data "$DATA" \
    --output_scpad_file0 "$OUT_SCPAD0" \
    --output_mem_file    "$OUT_MEM" \
    --output_sreg_file   "$OUT_SREGS" \
    --output_vreg_file   "$OUT_VREGS" \
    --output_mreg_file   "$OUT_MREGS" \
    --output_scpad_file1 "$OUT_SCPAD1" \
    && COMPARE_EXIT=0 || COMPARE_EXIT=$?

echo ""
echo "============================================================"
if [ $COMPARE_EXIT -eq 0 ]; then
    echo "  Pipeline PASSED"
else
    echo "  Pipeline FAILED"
fi
echo "============================================================"

exit $COMPARE_EXIT
