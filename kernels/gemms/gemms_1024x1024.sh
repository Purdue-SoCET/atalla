#!/usr/bin/env bash

#   bash kernels/gemms/gemms_1024x1024.sh

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ATALLA_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
cd "$ATALLA_ROOT"

LOG_FILE="$ATALLA_ROOT/out/run_1024x1024.log"
mkdir -p "$ATALLA_ROOT/out"
exec > >(tee "$LOG_FILE") 2>&1
echo "Logging to $LOG_FILE"
echo ""

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

OUTPUT_DIR="$ATALLA_ROOT/out"
IN_FILE="$SCRIPT_DIR/gemms_1024x1024.in"
OUT_MEM="$OUTPUT_DIR/output_mem.out"
OUT_SREGS="$OUTPUT_DIR/output_sregs.out"
OUT_VREGS="$OUTPUT_DIR/output_vregs.out"
OUT_MREGS="$OUTPUT_DIR/output_mregs.out"
OUT_SCPAD0="$OUTPUT_DIR/output_scpad0.out"
OUT_SCPAD1="$OUTPUT_DIR/output_scpad1.out"
OUT_PERF="$OUTPUT_DIR/output_perf_metrics.out"

echo "============================================================"
echo "  GEMM Emulation Pipeline: 1024x1024"
echo "============================================================"
echo ""

echo "[BUILD] Running kernels.gemms.build_gemms_1024x1024 ..."
echo "  Output: $IN_FILE"
echo ""

$PYTHON -m kernels.gemms.build_gemms_1024x1024 --output "$IN_FILE"

echo ""
echo "[BUILD] Done."
echo ""

echo "[EMULATE] Running functional_sim ..."

$PYTHON -m functional_sim.run \
    --input_file         "$IN_FILE"    \
    --output_mem_file    "$OUT_MEM"    \
    --output_sreg_file   "$OUT_SREGS"  \
    --output_vreg_file   "$OUT_VREGS"  \
    --output_mreg_file   "$OUT_MREGS"  \
    --output_scpad_file0 "$OUT_SCPAD0" \
    --output_scpad_file1 "$OUT_SCPAD1" \
    --output_perf_file   "$OUT_PERF"

echo "[EMULATE] Done.  Outputs in $OUTPUT_DIR"
echo ""

echo "[COMPARE] Running float32 comparison ..."
echo ""

$PYTHON -m kernels.gemms.compare_gemms_1024x1024 \
    --output_mem_file "$OUT_MEM" \
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