#!/usr/bin/env bash
#
# kernels/gemms/gemm_unrolled.sh
#
#
#   bash kernels/gemms/gemm_unrolled.sh [--no-graph]

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ATALLA_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
cd "$ATALLA_ROOT"

NO_GRAPH=""
for arg in "$@"; do
    case "$arg" in
        --no-graph) NO_GRAPH="--no-graph" ;;
        *) echo "[ERROR] Unknown argument: $arg"; exit 1 ;;
    esac
done

if   command -v python3 &>/dev/null; then PYTHON=python3
elif command -v python  &>/dev/null; then PYTHON=python
else echo "[ERROR] No python3 or python found on PATH"; exit 1
fi

REQUIRED_PACKAGES=(numpy torch)
MISSING=()
for pkg in "${REQUIRED_PACKAGES[@]}"; do
    $PYTHON -c "import $pkg" &>/dev/null || MISSING+=("$pkg")
done
if [ ${#MISSING[@]} -gt 0 ]; then
    echo "[SETUP] Installing: ${MISSING[*]}"
    $PYTHON -m pip install --quiet "${MISSING[@]}" || { echo "[ERROR] pip install failed"; exit 1; }
    echo "[SETUP] Done."
    echo ""
fi

OUTPUT_DIR="$ATALLA_ROOT/out"
IN_FILE="$ATALLA_ROOT/tests/gemms_unrolled.in"  

OUT_MEM="$OUTPUT_DIR/output_mem.out"
OUT_SREGS="$OUTPUT_DIR/output_sregs.out"
OUT_VREGS="$OUTPUT_DIR/output_vregs.out"
OUT_MREGS="$OUTPUT_DIR/output_mregs.out"
OUT_SCPAD0="$OUTPUT_DIR/output_scpad0.out"
OUT_SCPAD1="$OUTPUT_DIR/output_scpad1.out"
OUT_PERF="$OUTPUT_DIR/output_perf_metrics.out"

echo "============================================================"
echo "  GEMM unrolled: 32x32 single tile"
if [ -n "$NO_GRAPH" ]; then
    echo "  Packet scheduling: disabled (--no-graph)"
else
    echo "  Packet scheduling: dependency graph"
fi
echo "============================================================"
echo ""

echo "[BUILD] Generating test file ..."
echo "  Module : kernels.gemms.build_gemms_pipelined_loop_unroll"
echo "  Output : $IN_FILE"
echo ""

$PYTHON -m kernels.gemms.build_gemms_pipelined_loop_unroll \
    --output "$IN_FILE" \
    $NO_GRAPH

echo ""
echo "[BUILD] Done."
echo ""

echo "[EMULATE] Running functional_sim ..."
echo "  Input  : $IN_FILE"
echo "  Outputs: $OUTPUT_DIR/"
echo ""

mkdir -p "$OUTPUT_DIR"

$PYTHON -m functional_sim.run \
    --input_file         "$IN_FILE"    \
    --output_mem_file    "$OUT_MEM"    \
    --output_sreg_file   "$OUT_SREGS"  \
    --output_vreg_file   "$OUT_VREGS"  \
    --output_mreg_file   "$OUT_MREGS"  \
    --output_scpad_file0 "$OUT_SCPAD0" \
    --output_scpad_file1 "$OUT_SCPAD1" \
    --output_perf_file   "$OUT_PERF"

echo ""
echo "[EMULATE] Done."
echo ""

echo "[COMPARE] Checking output against PyTorch bfloat16 golden ..."
echo ""

COMPARE_EXIT=0
$PYTHON -m kernels.gemms.compare_gemms_unrolled \
    --output_mem_file "$OUT_MEM" \
    || COMPARE_EXIT=$?

echo ""
if [ -f "$OUT_PERF" ]; then
    echo "[PERF]"
    cat "$OUT_PERF"
    echo ""
fi

echo "============================================================"
if [ $COMPARE_EXIT -eq 0 ]; then
    echo "  Pipeline PASSED"
else
    echo "  Pipeline FAILED  (compare exit code: $COMPARE_EXIT)"
fi
echo "============================================================"

exit $COMPARE_EXIT