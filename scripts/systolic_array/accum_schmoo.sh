#!/bin/bash

# Description: This script performs a comprehensive schmoo testing process for the add32_fp32accum_bf16 module. 
# It generates random test cases, modifies the testbench for different mantissa sizes, compiles with Verilator, 
# and organizes results in output directories based on the random seed used for generation.

# Accept number of random sets from command-line argument 1.
# If no argument is passed, it defaults to 1 set.
NUM_SETS=${1:-1}
NUM_CASES=10000000

# Define base directories and files
ATALLA_DIR="/Users/aryankarani/Documents/GitHub/atalla"
SCRIPTS_DIR="$ATALLA_DIR/scripts/systolic_array"
TB_FILE="$ATALLA_DIR/tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv"

echo "=================================================="
echo "Initializing Schmoo Testing"
echo "Target Sets: $NUM_SETS ($NUM_CASES cases per set)"
echo "=================================================="

# Move to the scripts directory to check/compile the generator
cd "$SCRIPTS_DIR" || { echo "Error: Could not cd to $SCRIPTS_DIR"; exit 1; }

# Compile gen_drift_test if it doesn't exist or isn't executable
if [[ ! -x "gen_drift_test" ]]; then
    echo "gen_drift_test not found. Compiling..."
    gcc -O2 -I ~/berkeley-softfloat-3/source/include \
        -I ~/berkeley-testfloat-3/build/Linux-x86_64-GCC \
        gen_drift_test.c \
        ~/berkeley-softfloat-3/build/Linux-x86_64-GCC/softfloat.a \
        -lm \
        -o gen_drift_test

    if [[ $? -ne 0 ]]; then
        echo "Error: Compilation of gen_drift_test failed."
        exit 1
    fi
fi

# Track total script execution time
TOTAL_START=$SECONDS

# Outer Loop: Run the entire process NUM_SETS times
for set_idx in $(seq 1 "$NUM_SETS"); do
    
    # Start timer for this specific set
    SET_START=$SECONDS

    echo ""
    echo "##################################################"
    echo "Starting Random Data Set $set_idx of $NUM_SETS"
    echo "##################################################"
    
    # --- PHASE 1: GENERATE DATA ---
    echo "Phase 1: Generating $NUM_CASES test cases..."
    cd "$SCRIPTS_DIR" || exit 1

    ./gen_drift_test -n "$NUM_CASES" --fp64accum --unconstrained > testfloat_cases_32_pure_bf16.csv 2> temp_stderr.log

    # Extract the hex seed from stderr
    SEED=$(grep "Reproducible Seed:" temp_stderr.log | grep -oEi "0x[0-9a-f]+")

    if [[ -z "$SEED" ]]; then
        echo "Warning: Could not extract seed from stderr. Using timestamp instead."
        SEED="unknown_seed_$(date +%s)"
    else
        echo "Successfully extracted seed: $SEED"
    fi

    # Clean up the temporary log file
    rm temp_stderr.log


    # --- PHASE 2: SCHMOO TESTING ---
    echo "Phase 2: Schmoo Testing for Seed $SEED"
    cd "$ATALLA_DIR" || exit 1

    # Verify the testbench file exists before starting
    if [[ ! -f "$TB_FILE" ]]; then
        echo "Error: Could not find the file at $TB_FILE"
        exit 1
    fi

    # Create the output directory based on the seed
    OUT_DIR="schmoo_adder_tree_${SEED}"
    mkdir -p "$OUT_DIR"
    echo "Created output directory: $OUT_DIR"

    # Inner Loop: Mantissa sizes 23 to 30
    for i in {23..30}; do
        echo "  --- Testing MANTISSA_SIZE = $i ---"
        
        # Start timer for this specific mantissa run
        MANTISSA_START=$SECONDS

        # 1. Modify the file
        sed -i '' -E "s/(localparam MANTISSA_SIZE = )[0-9]+/\1$i/" "$TB_FILE"

        # 2. Run Verilator compilation
        verilator -Irtl/include/systolic_array \
            --binary -j 6 --threads 2 -Wall -Wno-fatal --timing \
            --top-module add32_fp32accum_bf16_tb_softfloat \
            tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv \
            rtl/modules/systolic_array/reducer.sv \
            rtl/modules/systolic_array/sysarr_4_input_fp_adder.sv \
            rtl/modules/systolic_array/add32_FPADD4.sv \
            --trace > /dev/null 2>&1

        # Check if Verilator succeeded
        if [[ $? -ne 0 ]]; then
            echo "Error: Verilator compilation failed for MANTISSA_SIZE = $i. Stopping script."
            exit 1
        fi

        # 3. Run the compiled executable and route output
        ./obj_dir/Vadd32_fp32accum_bf16_tb_softfloat > "$OUT_DIR/output_mantissa_${i}.txt"

        # 4. Save the tree_failures.csv file for this specific run
        if [[ -f "tree_failures.csv" ]]; then
            mv tree_failures.csv "$OUT_DIR/tree_failures_mantissa_${i}.csv"
            echo "  Saved failures to $OUT_DIR/tree_failures_mantissa_${i}.csv"
        else
            echo "  Note: tree_failures.csv not found (0 failures!)"
        fi

        # Calculate how long this mantissa size took
        MANTISSA_DURATION=$(( SECONDS - MANTISSA_START ))
        MANTISSA_MINS=$(( MANTISSA_DURATION / 60 ))
        MANTISSA_SECS=$(( MANTISSA_DURATION % 60 ))
        echo "  -> Time for MANTISSA_SIZE=$i: ${MANTISSA_MINS}m ${MANTISSA_SECS}s"
        echo ""

    done
    
    # Calculate how long this entire set took
    SET_DURATION=$(( SECONDS - SET_START ))
    SET_MINS=$(( SET_DURATION / 60 ))
    SET_SECS=$(( SET_DURATION % 60 ))

    echo "Finished Set $set_idx. Results saved in $OUT_DIR/"
    echo "-> Total time taken for Set $set_idx: ${SET_MINS}m ${SET_SECS}s"
done

# Calculate total script execution time
TOTAL_DURATION=$(( SECONDS - TOTAL_START ))
TOTAL_MINS=$(( TOTAL_DURATION / 60 ))
TOTAL_SECS=$(( TOTAL_DURATION % 60 ))

echo ""
echo "=================================================="
echo "All $NUM_SETS sets completed successfully!"
echo "Total Time Elapsed for all sets: ${TOTAL_MINS}m ${TOTAL_SECS}s"
echo "=================================================="