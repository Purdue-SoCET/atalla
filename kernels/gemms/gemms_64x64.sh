#!/usr/bin/env bash

#   bash kernels/gemms/gemms_64x64.sh [--debug]

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ATALLA_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
cd "$ATALLA_ROOT"

if command -v python3 &>/dev/null; then
    PYTHON=python3
elif command -v python &>/dev/null; then
    PYTHON=python
else
    echo "[ERROR] No python3 or python found on PATH"; exit 1
fi

REQUIRED_PACKAGES=(numpy torch)
MISSING=()
for pkg in "${REQUIRED_PACKAGES[@]}"; do
    if ! $PYTHON -c "import $pkg" &>/dev/null; then
        MISSING+=("$pkg")
    fi
done
if [ ${#MISSING[@]} -gt 0 ]; then
    echo "[SETUP] Installing: ${MISSING[*]} ..."
    $PYTHON -m pip install --quiet "${MISSING[@]}" || {
        echo "[ERROR] pip install failed."; exit 1
    }
    echo "[SETUP] Done."; echo ""
fi

DEBUG_FLAG=""
DEBUG_ARG="False"

while [[ $# -gt 0 ]]; do
    case "$1" in
        --debug)
            DEBUG_FLAG="--debug"
            DEBUG_ARG="True"
            shift ;;
        -h|--help)
            echo "Usage: bash $0 [--debug]"
            echo "  --debug    Single-tile k=2 debug mode"
            exit 0 ;;
        *)
            echo "[ERROR] Unknown argument: $1"; exit 1 ;;
    esac
done


OUTPUT_DIR="$ATALLA_ROOT/out"
IN_FILE="$SCRIPT_DIR/gemms_64x64.in"
OUT_MEM="$OUTPUT_DIR/output_mem.out"
OUT_SREGS="$OUTPUT_DIR/output_sregs.out"
OUT_VREGS="$OUTPUT_DIR/output_vregs.out"
OUT_MREGS="$OUTPUT_DIR/output_mregs.out"
OUT_SCPAD0="$OUTPUT_DIR/output_scpad0.out"
OUT_SCPAD1="$OUTPUT_DIR/output_scpad1.out"
OUT_PERF="$OUTPUT_DIR/output_perf_metrics.out"

echo "============================================================"
if [ "$DEBUG_ARG" = "True" ]; then
    echo "  GEMM Emulation Pipeline: DEBUG (single tile, k=2)"
else
    echo "  GEMM Emulation Pipeline: 64x64"
fi
echo "============================================================"
echo ""


echo "[BUILD] Running kernels.gemms.build_gemms_64x64 ..."
echo "  Output: $IN_FILE"
echo ""

BUILD_ARGS="--output $IN_FILE"
if [ "$DEBUG_ARG" = "True" ]; then
    BUILD_ARGS="$BUILD_ARGS --debug"
fi

$PYTHON -m kernels.gemms.build_gemms_64x64 $BUILD_ARGS

echo ""
echo "[BUILD] Done."
echo ""


echo "[EMULATE] Running functional_sim ..."
mkdir -p "$OUTPUT_DIR"

$PYTHON -m functional_sim.run \
    --input_file         "$IN_FILE"    \
    --output_mem_file    "$OUT_MEM"    \
    --output_sreg_file   "$OUT_SREGS"  \
    --output_vreg_file   "$OUT_VREGS"  \
    --output_mreg_file   "$OUT_MREGS"  \
    --output_scpad_file0 "$OUT_SCPAD0" \
    --output_scpad_file1 "$OUT_SCPAD1" \
    --output_perf_file   "$OUT_PERF"   \
    $DEBUG_FLAG

echo "[EMULATE] Done.  Outputs in $OUTPUT_DIR"
echo ""


echo "[COMPARE] Running PyTorch comparison ..."
echo ""

$PYTHON -m kernels.gemms.compare_gemms \
    --output_mem_file "$OUT_MEM" \
    --debug "$DEBUG_ARG" \
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