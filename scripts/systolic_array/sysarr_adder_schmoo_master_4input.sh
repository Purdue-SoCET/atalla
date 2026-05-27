#!/bin/bash

# Comparison script for 4-input adder tree vs 32-input fused adder across a large dataset of random test cases, for 
# different number of precision bits (fused) / accumulation width (tree)

# Usage: 
# 1) Generate the test cases with gen_drift_test.c (make sure to set -n 10000000 and --unconstrained if you want unconstrained cases)
# 2) Run this script: ./sysarr_adder_schmoo_master.sh [--unconstrained] [-j MAX_JOBS] [-m MODE] [NUM_SETS]
#    - --unconstrained: If set, generates unconstrained random FP values (including NaNs, Infs, denormals). If not set, generates only "normal" FP values.
#    - -j MAX_JOBS: Maximum number of concurrent Verilator jobs to run in parallel (default: 3)
#    - -m MODE: Which architecture(s) to test: "tree" for 4-input adder tree only, "fused" for 32-input fused adder only, "both" for both architectures (default: "both")
#    - NUM_SETS: Optional positional argument to specify how many times to repeat the entire process with different random datasets (default: 1). Each set generates a new dataset and runs all tests, allowing for statistical analysis across multiple random seeds.      

# Description: UNIFIED PARALLELIZED schmoo testing for Systolic Array FP Adders.
# Supports testing the 4-Input Tree Adder, the 32-Input Fused Adder, or BOTH simultaneously 
# on the exact same dataset for 1:1 architectural comparisons. Includes comprehensive timing diagnostics.

NUM_CASES=10000

# --- Advanced Argument Parsing ---
NUM_SETS=1
UNCONSTRAINED_FLAG=""
MODE_TEXT="Constrained"
MAX_JOBS=3 # Default to 3 concurrent jobs
RUN_MODE="both" # Default mode

set -e

while [[ $# -gt 0 ]]; do
    case $1 in
        --unconstrained)
            UNCONSTRAINED_FLAG="--unconstrained"
            MODE_TEXT="Unconstrained"
            shift
            ;;
        -j|--jobs)
            MAX_JOBS="$2"
            shift 2
            ;;
        -m|--mode)
            RUN_MODE="$2"
            if [[ "$RUN_MODE" != "cc" && "$RUN_MODE" != "no_cc" && "$RUN_MODE" != "both" ]]; then
                echo "Error: --mode must be 'cc', 'no_cc', or 'both'"
                exit 1
            fi
            shift 2
            ;;
        *)
            # If it's just a standalone number, assume it's NUM_SETS
            if [[ "$1" =~ ^[0-9]+$ ]]; then
                NUM_SETS="$1"
            fi
            shift
            ;;
    esac
done

# Define base directories and files
# NOTE: Update this path if moving from macOS to RHEL
ATALLA_DIR="/home/asicfab/a/karania/atalla"
SCRIPTS_DIR="$ATALLA_DIR/scripts/systolic_array"

TB_TREE="$ATALLA_DIR/tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv"
TB_FUSED="$ATALLA_DIR/tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv"

echo "=================================================="
echo "Initializing MASTER Schmoo Testing"
echo "Architecture: $RUN_MODE"
echo "Target Sets:  $NUM_SETS ($NUM_CASES cases per set)"
echo "Data Mode:    $MODE_TEXT"
echo "Concurrency:  $MAX_JOBS simultaneous jobs"
echo "=================================================="

# Move to the scripts directory to check/compile the generator
cd "$SCRIPTS_DIR" || { echo "Error: Could not cd to $SCRIPTS_DIR"; exit 1; }

if [[ ! -x "gen_fp_tests" ]]; then
    echo "gen_fp_tests not found. Compiling..."
    gcc -O2 -I ~/berkeley-softfloat-3/source/include \
        -I ~/berkeley-testfloat-3/build/Linux-x86_64-GCC \
        gen_fp_tests.c \
        ~/berkeley-softfloat-3/build/Linux-x86_64-GCC/softfloat.a \
        -lm -o gen_fp_tests || exit 1
fi

TOTAL_START=$SECONDS

for set_idx in $(seq 1 "$NUM_SETS"); do
    # 3. SET TIMER START
    SET_START=$SECONDS

    echo ""
    echo "##################################################"
    echo "Starting Random Data Set $set_idx of $NUM_SETS"
    echo "##################################################"
    
    # --- PHASE 1: GENERATE DATA (Done ONCE per set) ---
    echo "Phase 1: Generating $NUM_CASES $MODE_TEXT test cases..."
    cd "$SCRIPTS_DIR" || exit 1

    ./gen_fp_tests -i 4 -n "$NUM_CASES" $UNCONSTRAINED_FLAG > testfloat_cases_4_pure_bf16.csv 2> temp_stderr.log
    
    SEED=$(grep "Reproducible Seed:" temp_stderr.log | grep -oEi "0x[0-9a-f]+")
    [[ -z "$SEED" ]] && SEED="unknown_seed_$(date +%s)"
    rm temp_stderr.log

    cd "$ATALLA_DIR" || exit 1

    # Define Output Directories based on mode
    if [[ "$RUN_MODE" == "both" ]]; then
        BASE_OUT="schmoo_comparison_${SEED}_${MODE_TEXT}"
        CC_DIR="$BASE_OUT/adder_cc"
        NO_CC_DIR="$BASE_OUT/adder_no_cc"
        mkdir -p "$CC_DIR" "$NO_CC_DIR"
    elif [[ "$RUN_MODE" == "cc" ]]; then
        BASE_OUT="schmoo_adder_cc_${SEED}_${MODE_TEXT}"
        CC_DIR="$BASE_OUT"
        mkdir -p "$CC_DIR"
    elif [[ "$RUN_MODE" == "no_cc" ]]; then
        BASE_OUT="schmoo_adder_no_cc_${SEED}_${MODE_TEXT}"
        NO_CC_DIR="$BASE_OUT"
        mkdir -p "$NO_CC_DIR"
    fi
    echo "Output directory initialized: $BASE_OUT/"

    # =====================================================================
    # PHASE 2A: 4-INPUT TREE ADDER EXECUTION (CC DET)
    # =====================================================================
    if [[ "$RUN_MODE" == "cc" || "$RUN_MODE" == "both" ]]; then
        echo ""
        echo "Phase 2A: Launching CC DET ADDER tests in batches of $MAX_JOBS..."
        if [[ ! -f "$TB_TREE" ]]; then echo "Error: Missing $TB_TREE"; exit 1; fi

        # 2. TREE ADDER TOTAL TIMER START
        TREE_PHASE_START=$SECONDS
        CURRENT_JOBS=0

        for m_size in {0..7}; do
            (
                # 1. PER-RUN TIMER START
                RUN_START=$SECONDS
                
                TEMP_TB="tb_sandbox_tree_${m_size}.sv"
                rm -f "$TEMP_TB"
                cp "$TB_TREE" "$TEMP_TB"

                sed -i -E "s/(localparam PRECISION_BITS = )[0-9]+/\1$m_size/" "$TEMP_TB"
                sed -i -E "s/(localparam CC_DET = )[01]/\1 1/" "$TEMP_TB"
                sed -i -E "s/tree_failures\.csv/cc_failures_precision_${m_size}.csv/" "$TEMP_TB"

                verilator -Irtl/include/systolic_array --Mdir obj_dir_cc_${m_size} \
                    --binary -j 3 --threads 2 -Wall -Wno-fatal --timing \
                    --top-module add4_fp32accum_bf16_tb_softfloat "$TEMP_TB" \
                    rtl/modules/systolic_array/reducer.sv \
                    rtl/modules/systolic_array/sysarr_4_input_fp_adder_cc_det.sv > /dev/null 2>&1

                ./obj_dir_cc_${m_size}/Vadd4_fp32accum_bf16_tb_softfloat > "$CC_DIR/output_precision_${m_size}.txt"

                # 1. PER-RUN TIMER END
                RUN_TIME=$(( SECONDS - RUN_START ))

                if grep -q "FINAL REPORT" "$CC_DIR/output_precision_${m_size}.txt"; then
                    PASSED=$(grep -E "^PASSED:" "$CC_DIR/output_precision_${m_size}.txt" | awk '{print $2}')
                    FAILED=$(grep -E "^FAILED:" "$CC_DIR/output_precision_${m_size}.txt" | awk '{print $2}')
                    MAX_ULP=$(grep -E "^MAX ULP ERR:" "$CC_DIR/output_precision_${m_size}.txt" | awk '{print $4}')
                    echo "  -> [TREE DONE] MANTISSA = $m_size | Time: $((RUN_TIME / 60))m $((RUN_TIME % 60))s | Pass: ${PASSED:-0} | Fail: ${FAILED:-0} | Max ULP: ${MAX_ULP:-N/A}"
                else
                    echo "  -> [TREE ERROR] MANTISSA = $m_size crashed! Time: $((RUN_TIME / 60))m $((RUN_TIME % 60))s"
                fi

                if [[ -f "cc_failures_precision_${m_size}.csv" ]]; then
                    mv "cc_failures_precision_${m_size}.csv" "$CC_DIR/"
                fi

                rm -f "$TEMP_TB" && rm -rf "obj_dir_cc_${m_size}"
            ) &
            
            ((CURRENT_JOBS++))
            if [[ $CURRENT_JOBS -ge $MAX_JOBS ]]; then wait; CURRENT_JOBS=0; fi
        done
        wait
        
        # 2. TREE ADDER TOTAL TIMER END
        TREE_PHASE_TIME=$(( SECONDS - TREE_PHASE_START ))
        echo "  => [TREE COMPLETE] All Mantissas finished in $((TREE_PHASE_TIME / 60))m $((TREE_PHASE_TIME % 60))s"
    fi

    # =====================================================================
    # PHASE 2B: 4-INPUT FUSED ADDER EXECUTION (NO CC DET)
    # =====================================================================
    if [[ "$RUN_MODE" == "no_cc" || "$RUN_MODE" == "both" ]]; then
        echo ""
        echo "Phase 2B: Launching NO CC ADDER tests in batches of $MAX_JOBS..."
        if [[ ! -f "$TB_FUSED" ]]; then echo "Error: Missing $TB_FUSED"; exit 1; fi

        # 2. FUSED ADDER TOTAL TIMER START
        FUSED_PHASE_START=$SECONDS
        CURRENT_JOBS=0

        for p_bits in {0..7}; do
            (
                # 1. PER-RUN TIMER START
                RUN_START=$SECONDS
                
                TEMP_TB="tb_sandbox_fused_${p_bits}.sv"
                cp "$TB_FUSED" "$TEMP_TB"

                sed -i -E "s/(localparam PRECISION_BITS = )[0-9]+/\1$p_bits/" "$TEMP_TB"
                sed -i -E "s/(localparam CC_DET = )[01]/\1 0/" "$TEMP_TB"
                sed -i -E "s/tree_failures\.csv/no_cc_failures_precision_${p_bits}.csv/" "$TEMP_TB"

                verilator -Irtl/include/systolic_array --Mdir obj_dir_no_cc_${p_bits} \
                    --binary -j 3 --threads 2 -Wall -Wno-fatal --timing \
                    --top-module add4_fp32accum_bf16_tb_softfloat "$TEMP_TB" \
                    rtl/modules/systolic_array/reducer.sv \
                    rtl/modules/systolic_array/sysarr_4_input_fp_adder.sv > /dev/null 2>&1

                ./obj_dir_no_cc_${p_bits}/Vadd4_fp32accum_bf16_tb_softfloat > "$NO_CC_DIR/output_precision_${p_bits}.txt"

                # 1. PER-RUN TIMER END
                RUN_TIME=$(( SECONDS - RUN_START ))

                if grep -q "FINAL REPORT" "$NO_CC_DIR/output_precision_${p_bits}.txt"; then
                    PASSED=$(grep -E "^PASSED:" "$NO_CC_DIR/output_precision_${p_bits}.txt" | awk '{print $2}')
                    FAILED=$(grep -E "^FAILED:" "$NO_CC_DIR/output_precision_${p_bits}.txt" | awk '{print $2}')
                    MAX_ULP=$(grep -E "^MAX ULP ERR:" "$NO_CC_DIR/output_precision_${p_bits}.txt" | awk '{print $4}')
                    echo "  -> [NO CC DONE] PRECISION = $p_bits | Time: $((RUN_TIME / 60))m $((RUN_TIME % 60))s | Pass: ${PASSED:-0} | Fail: ${FAILED:-0} | Max ULP: ${MAX_ULP:-N/A}"
                else
                    echo "  -> [NO CC ERROR] PRECISION = $p_bits crashed! Time: $((RUN_TIME / 60))m $((RUN_TIME % 60))s"
                fi

                if [[ -f "no_cc_failures_precision_${p_bits}.csv" ]]; then
                    mv "no_cc_failures_precision_${p_bits}.csv" "$NO_CC_DIR/"
                fi

                rm -f "$TEMP_TB" && rm -rf "obj_dir_no_cc_${p_bits}"
            ) &
            
            ((CURRENT_JOBS++))
            if [[ $CURRENT_JOBS -ge $MAX_JOBS ]]; then wait; CURRENT_JOBS=0; fi
        done
        wait
        
        # 2. FUSED ADDER TOTAL TIMER END
        FUSED_PHASE_TIME=$(( SECONDS - FUSED_PHASE_START ))
        echo "  => [FUSED COMPLETE] All Precisions finished in $((FUSED_PHASE_TIME / 60))m $((FUSED_PHASE_TIME % 60))s"
    fi

    # 3. SET TIMER END
    SET_DURATION=$(( SECONDS - SET_START ))
    echo ""
    echo "=================================================="
    echo "Finished Set $set_idx of $NUM_SETS."
    echo "Time taken for this set (Data + Simulation): $(( SET_DURATION / 60 ))m $(( SET_DURATION % 60 ))s"
    echo "=================================================="
done

# 4. TOTAL SCRIPT TIMER END
TOTAL_DURATION=$(( SECONDS - TOTAL_START ))
echo ""
echo "##################################################"
echo "ALL $NUM_SETS SET(S) COMPLETED SUCCESSFULLY!"
echo "Total Script Execution Time: $(( TOTAL_DURATION / 60 ))m $(( TOTAL_DURATION % 60 ))s"
echo "##################################################"