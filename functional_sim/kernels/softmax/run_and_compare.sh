#!/usr/bin/env bash
set -euo pipefail

TEST_IN=./tests/complex/edit_mem.in
OUT_DIR=./out
SCPAD_OUT="$OUT_DIR/output_scpad0.out"
SCPAD_OUT1="$OUT_DIR/output_scpad1.out"
REF_OUT="$OUT_DIR/softmax_ref.out"

mkdir -p "$OUT_DIR"

echo "[0/3] Building testfile (assembling kernel)..."
python3 build_softmax.py -o "$TEST_IN"

echo "[1/3] Running emulator..."
# Run the emulator and explicitly set output files so we know where scratchpad is written
python3 run.py --input_file "$TEST_IN" \
	--output_scpad_file0 "$SCPAD_OUT" \
	--output_scpad_file1 "$SCPAD_OUT1" \
	--output_mem_file "$OUT_DIR/output_mem.out" \
	--output_sreg_file "$OUT_DIR/output_sregs.out" \
	--output_vreg_file "$OUT_DIR/output_vregs.out" \
	--output_mreg_file "$OUT_DIR/output_mregs.out"

echo "[2/3] Running PyTorch reference..."
python3 softmax_pytorch_ref.py > "$REF_OUT"

echo "[3/3] Comparing outputs..."
python3 compare_softmax.py "$SCPAD_OUT" "$REF_OUT"

echo "✅ Done"