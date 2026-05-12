#!/bin/bash

# Description: UNIFIED PARALLELIZED schmoo testing for Systolic Array FP Adders.
# Supports testing the 4-Input Tree Adder, the 32-Input Fused Adder, or BOTH simultaneously 
# on the exact same dataset for 1:1 architectural comparisons. Includes comprehensive timing diagnostics.

NUM_CASES=10000000

# --- Advanced Argument Parsing ---
NUM_SETS=1
UNCONSTRAINED_FLAG=""
MODE_TEXT="Constrained"
MAX_JOBS=3 # Default to 3 concurrent jobs (Optimal for M4 Air)
RUN_MODE="both" # Default mode

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
            if [[ "$RUN_MODE" != "tree" && "$RUN_MODE" != "fused" && "$RUN_MODE" != "both" ]]; then
                echo "Error: --mode must be 'tree', 'fused', or 'both'"
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
ATALLA_DIR="/Users/aryankarani/Documents/GitHub/atalla"
SCRIPTS_DIR="$ATALLA_DIR/scripts/systolic_array"

TB_TREE="$ATALLA_DIR/tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv"
TB_FUSED="$ATALLA_DIR/tb/unit/systolic_array/add32_32input_fused_tb_softfloat.sv"

echo "=================================================="
echo "Initializing MASTER Schmoo Testing"
echo "Architecture: $RUN_MODE"
echo "Target Sets:  $NUM_SETS ($NUM_CASES cases per set)"
echo "Data Mode:    $MODE_TEXT"
echo "Concurrency:  $MAX_JOBS simultaneous jobs"
echo "=================================================="

# Move to the scripts directory to check/compile the generator
cd "$SCRIPTS_DIR" || { echo "Error: Could not cd to $SCRIPTS_DIR"; exit 1; }

if [[ ! -x "gen_drift_test" ]]; then
    echo "gen_drift_test not found. Compiling..."
    gcc -O2 -I ~/berkeley-softfloat-3/source/include \
        -I ~/berkeley-testfloat-3/build/Linux-x86_64-GCC \
        gen_drift_test.c \
        ~/berkeley-softfloat-3/build/Linux-x86_64-GCC/softfloat.a \
        -lm -o gen_drift_test || exit 1
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

    ./gen_drift_test -i 32 -n "$NUM_CASES" $UNCONSTRAINED_FLAG > testfloat_cases_32_pure_bf16.csv 2> temp_stderr.log
    
    SEED=$(grep "Reproducible Seed:" temp_stderr.log | grep -oEi "0x[0-9a-f]+")
    [[ -z "$SEED" ]] && SEED="unknown_seed_$(date +%s)"
    rm temp_stderr.log

    cd "$ATALLA_DIR" || exit 1

    # Define Output Directories based on mode
    if [[ "$RUN_MODE" == "both" ]]; then
        BASE_OUT="schmoo_comparison_${SEED}_${MODE_TEXT}"
        TREE_DIR="$BASE_OUT/adder_tree"
        FUSED_DIR="$BASE_OUT/fused_adder"
        mkdir -p "$TREE_DIR" "$FUSED_DIR"
    elif [[ "$RUN_MODE" == "tree" ]]; then
        BASE_OUT="schmoo_adder_tree_${SEED}_${MODE_TEXT}"
        TREE_DIR="$BASE_OUT"
        mkdir -p "$TREE_DIR"
    elif [[ "$RUN_MODE" == "fused" ]]; then
        BASE_OUT="schmoo_fused_adder_${SEED}_${MODE_TEXT}"
        FUSED_DIR="$BASE_OUT"
        mkdir -p "$FUSED_DIR"
    fi
    echo "Output directory initialized: $BASE_OUT/"

    # =====================================================================
    # PHASE 2A: 4-INPUT TREE ADDER EXECUTION
    # =====================================================================
    if [[ "$RUN_MODE" == "tree" || "$RUN_MODE" == "both" ]]; then
        echo ""
        echo "Phase 2A: Launching TREE ADDER tests in batches of $MAX_JOBS..."
        if [[ ! -f "$TB_TREE" ]]; then echo "Error: Missing $TB_TREE"; exit 1; fi

        # 2. TREE ADDER TOTAL TIMER START
        TREE_PHASE_START=$SECONDS
        CURRENT_JOBS=0

        for m_size in {23..30}; do
            (
                # 1. PER-RUN TIMER START
                RUN_START=$SECONDS
                
                TEMP_TB="tb_sandbox_tree_${m_size}.sv"
                cp "$TB_TREE" "$TEMP_TB"

                sed -i '' -E "s/(localparam MANTISSA_SIZE = )[0-9]+/\1$m_size/" "$TEMP_TB"
                sed -i '' -E "s/tree_failures\.csv/tree_failures_mantissa_${m_size}.csv/" "$TEMP_TB"

                verilator -Irtl/include/systolic_array --Mdir obj_dir_tree_${m_size} \
                    --binary -j 3 --threads 2 -Wall -Wno-fatal --timing \
                    --top-module add32_fp32accum_bf16_tb_softfloat "$TEMP_TB" \
                    rtl/modules/systolic_array/reducer.sv \
                    rtl/modules/systolic_array/sysarr_4_input_fp_adder.sv \
                    rtl/modules/systolic_array/add32_FPADD4.sv > /dev/null 2>&1

                ./obj_dir_tree_${m_size}/Vadd32_fp32accum_bf16_tb_softfloat > "$TREE_DIR/output_mantissa_${m_size}.txt"

                # 1. PER-RUN TIMER END
                RUN_TIME=$(( SECONDS - RUN_START ))

                if grep -q "FINAL REPORT" "$TREE_DIR/output_mantissa_${m_size}.txt"; then
                    PASSED=$(grep -E "^PASSED:" "$TREE_DIR/output_mantissa_${m_size}.txt" | awk '{print $2}')
                    FAILED=$(grep -E "^FAILED:" "$TREE_DIR/output_mantissa_${m_size}.txt" | awk '{print $2}')
                    MAX_ULP=$(grep -E "^MAX ULP ERR:" "$TREE_DIR/output_mantissa_${m_size}.txt" | awk '{print $4}')
                    echo "  -> [TREE DONE] MANTISSA = $m_size | Time: $((RUN_TIME / 60))m $((RUN_TIME % 60))s | Pass: ${PASSED:-0} | Fail: ${FAILED:-0} | Max ULP: ${MAX_ULP:-N/A}"
                else
                    echo "  -> [TREE ERROR] MANTISSA = $m_size crashed! Time: $((RUN_TIME / 60))m $((RUN_TIME % 60))s"
                fi

                if [[ -f "tree_failures_mantissa_${m_size}.csv" ]]; then
                    mv "tree_failures_mantissa_${m_size}.csv" "$TREE_DIR/"
                fi

                rm -f "$TEMP_TB" && rm -rf "obj_dir_tree_${m_size}"
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
    # PHASE 2B: 32-INPUT FUSED ADDER EXECUTION
    # =====================================================================
    if [[ "$RUN_MODE" == "fused" || "$RUN_MODE" == "both" ]]; then
        echo ""
        echo "Phase 2B: Launching FUSED ADDER tests in batches of $MAX_JOBS..."
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

                sed -i '' -E "s/(localparam PRECISION_BITS = )[0-9]+/\1$p_bits/" "$TEMP_TB"
                sed -i '' -E "s/tree_failures\.csv/fused_failures_precision_${p_bits}.csv/" "$TEMP_TB"

                verilator -Irtl/include/systolic_array --Mdir obj_dir_fused_${p_bits} \
                    --binary -j 3 --threads 2 -Wall -Wno-fatal --timing \
                    --top-module add32_32input_fused_tb_softfloat "$TEMP_TB" \
                    rtl/modules/systolic_array/sysarr_32_adder/sysarr_32_input_adder.sv \
                    rtl/modules/systolic_array/reducer.sv \
                    rtl/modules/systolic_array/sysarr_32_adder/sysarr_32_input_fp_aligner.sv \
                    rtl/modules/systolic_array/sysarr_32_adder/V0_0_S1_cfg_00.sv > /dev/null 2>&1

                ./obj_dir_fused_${p_bits}/Vadd32_32input_fused_tb_softfloat > "$FUSED_DIR/output_precision_${p_bits}.txt"

                # 1. PER-RUN TIMER END
                RUN_TIME=$(( SECONDS - RUN_START ))

                if grep -q "FINAL REPORT" "$FUSED_DIR/output_precision_${p_bits}.txt"; then
                    PASSED=$(grep -E "^PASSED:" "$FUSED_DIR/output_precision_${p_bits}.txt" | awk '{print $2}')
                    FAILED=$(grep -E "^FAILED:" "$FUSED_DIR/output_precision_${p_bits}.txt" | awk '{print $2}')
                    MAX_ULP=$(grep -E "^MAX ULP ERR:" "$FUSED_DIR/output_precision_${p_bits}.txt" | awk '{print $4}')
                    echo "  -> [FUSED DONE] PRECISION = $p_bits | Time: $((RUN_TIME / 60))m $((RUN_TIME % 60))s | Pass: ${PASSED:-0} | Fail: ${FAILED:-0} | Max ULP: ${MAX_ULP:-N/A}"
                else
                    echo "  -> [FUSED ERROR] PRECISION = $p_bits crashed! Time: $((RUN_TIME / 60))m $((RUN_TIME % 60))s"
                fi

                if [[ -f "fused_failures_precision_${p_bits}.csv" ]]; then
                    mv "fused_failures_precision_${p_bits}.csv" "$FUSED_DIR/"
                fi

                rm -f "$TEMP_TB" && rm -rf "obj_dir_fused_${p_bits}"
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