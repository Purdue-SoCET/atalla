#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
EMULATOR_DIR="$(dirname "$SCRIPT_DIR")"
PROJECT_ROOT="$(dirname "$EMULATOR_DIR")"

echo "compare emulator and pytorch"
echo

echo "Step 1: GEMM assembly..."
cd "$EMULATOR_DIR"
python3 build_gemms_branches.py -o gemms.in           #MODIFY FILE NAME HERE 
echo "create gemms.in"
echo

echo "Step 2: Run emulator..."
python3 run.py --input_file ./gemms.in
echo "emulator finished"
echo "  Output files: out/output_vregs.out, out/output_scpad0.out, out/output_scpad1.out"
echo

echo "Step 3: Run PyTorch GEMM..."
cd "$PROJECT_ROOT"
python3 emulator/pytorch_gemm.py
echo "pyTorch finished"
echo

echo "compare"
echo "Check emulator outputs in $EMULATOR_DIR/out/ for vregs/scpad"