#!/usr/bin/env bash
# =============================================================================
# layernorm.sh — End-to-end kernel emulation + PyTorch comparison for LayerNorm
#
# Usage:
#   bash kernels/layernorm/layernorm.sh [--n 4] [--data kernels/layernorm/layernorm_data.csv] [--debug]
#
# This script:
#   1. Builds the emulator input image via build_layernorm.py
#   2. Runs the emulator on that image
#   3. Compares the emulator output against a PyTorch golden reference
# =============================================================================
set -euo pipefail

# ---------- Resolve project root (atalla/) from this script's location ------
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ATALLA_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

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
N=4
DATA="$SCRIPT_DIR/layernorm_data.csv"
DEBUG_FLAG=""

# ---------- Argument parsing ------------------------------------------------
while [[ $# -gt 0 ]]; do
    case "$1" in
        --n)
            N="$2"; shift 2 ;;
        --data)
            DATA="$2"; shift 2 ;;
        --debug)
            DEBUG_FLAG="--debug"; shift ;;
        -h|--help)
            echo "Usage: bash $0 [--n N] [--data DATA_CSV] [--debug]"
            echo ""
            echo "  --n N          Tile dimension N×N (default: 4)"
            echo "  --data PATH    Path to tile data CSV (default: kernels/layernorm/layernorm_data.csv)"
            echo "  --debug        Enable verbose emulator output"
            exit 0 ;;
        *)
            echo "[ERROR] Unknown argument: $1"; exit 1 ;;
    esac
done

# ---------- Derived paths ---------------------------------------------------
OUTPUT_DIR="$SCRIPT_DIR/${KERNEL}_output"
BUILD_SCRIPT="$ATALLA_ROOT/emulator/build_${KERNEL}.py"
IN_FILE="$SCRIPT_DIR/${KERNEL}.in"
COMPARE_SCRIPT="$ATALLA_ROOT/kernels/utils/compare_pytorch.py"

OUT_MEM="$OUTPUT_DIR/output_mem.out"
OUT_SREGS="$OUTPUT_DIR/output_sregs.out"
OUT_VREGS="$OUTPUT_DIR/output_vregs.out"
OUT_MREGS="$OUTPUT_DIR/output_mregs.out"
OUT_SCPAD0="$OUTPUT_DIR/output_scpad0.out"
OUT_SCPAD1="$OUTPUT_DIR/output_scpad1.out"

echo "============================================================"
echo "  Kernel Emulation Pipeline: $KERNEL  (${N}×${N})"
echo "============================================================"
echo ""

# ---------- Step 1: Build ---------------------------------------------------
echo "[BUILD] Running build_${KERNEL}.py ..."
echo "  Data file : $DATA"
echo "  Output    : $IN_FILE"
echo ""

cd "$ATALLA_ROOT/emulator"
$PYTHON "build_${KERNEL}.py" \
    --data "$DATA" \
    --n "$N" \
    --output "$IN_FILE"

echo "[BUILD] Done."
echo ""

# ---------- Step 2: Emulate -------------------------------------------------
echo "[EMULATE] Running emulator ..."
mkdir -p "$OUTPUT_DIR"

cd "$ATALLA_ROOT/emulator"
$PYTHON -m run \
    --input_file "$IN_FILE" \
    --output_mem_file   "$OUT_MEM" \
    --output_sreg_file  "$OUT_SREGS" \
    --output_vreg_file  "$OUT_VREGS" \
    --output_mreg_file  "$OUT_MREGS" \
    --output_scpad_file0 "$OUT_SCPAD0" \
    --output_scpad_file1 "$OUT_SCPAD1" \
    $DEBUG_FLAG

echo "[EMULATE] Done.  Outputs in $OUTPUT_DIR"
echo ""

# ---------- Step 3: Compare -------------------------------------------------
echo "[COMPARE] Running PyTorch comparison ..."
echo ""

cd "$ATALLA_ROOT"
$PYTHON "$COMPARE_SCRIPT" \
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
