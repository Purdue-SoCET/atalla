#!/bin/bash

# Tests the performance of the auto-generated 32 input fused adders for verification of the design
# Compare against sysarr_32_adder which is manually made 

# Usage:
# 1) Generate the fused adders with gen_sysarr_fused_adder.py (make sure to set NUM_INPUTS=32 and UNCONSTRAINED if you want unconstrained cases)
# 2) Run this script: ./sysarr_adder_schmoo_master.sh
# 3) Analyze results with analyze_sysarr_adder.py

# --- Default Configuration ---
NUM_INPUTS=32
NUM_CASES=100000
MAX_JOBS=4
UNCONSTRAINED_FLAG=""
MODE_TEXT="Constrained"
RESET_DELAY=5 # Testbench #(PERIOD * 5) offset

while [[ $# -gt 0 ]]; do
    case $1 in
        -c|--cases)
            NUM_CASES="$2"
            shift 2
            ;;
        -j|--jobs)
            MAX_JOBS="$2"
            shift 2
            ;;
        --unconstrained)
            UNCONSTRAINED_FLAG="--unconstrained"
            MODE_TEXT="Unconstrained"
            shift
            ;;
        *)
            echo "Unknown argument: $1"
            exit 1
            ;;
    esac
done

ATALLA_DIR="/Users/aryankarani/Documents/GitHub/atalla"
SCRIPTS_DIR="$ATALLA_DIR/scripts/systolic_array"
WRAPPER_DIR="$SCRIPTS_DIR/master_modules_${NUM_INPUTS}" # Directory where your python script outputs
REDUCER_SV="$ATALLA_DIR/rtl/modules/systolic_array/reducer.sv"

echo "======================================================="
echo "Initializing Dynamic DSE Schmoo Testing"
echo "Target Inputs: $NUM_INPUTS"
echo "Test Cases:    $NUM_CASES ($MODE_TEXT)"
echo "Concurrency:   $MAX_JOBS simultaneous jobs"
echo "Target Dir:    $WRAPPER_DIR"
echo "======================================================="

if [[ ! -d "$WRAPPER_DIR" ]]; then
    echo "Error: Directory $WRAPPER_DIR not found! Generate the wrappers first."
    exit 1
fi

TOTAL_START=$SECONDS

# =====================================================================
# PHASE 1: GENERATE DATASET
# =====================================================================
echo ""
echo "Phase 1: Compiling Generator & Producing $NUM_CASES Test Cases..."
cd "$SCRIPTS_DIR" || exit 1

if [[ ! -x "gen_drift_test" ]]; then
    gcc -O2 -I ~/berkeley-softfloat-3/source/include \
        -I ~/berkeley-testfloat-3/build/Linux-x86_64-GCC \
        gen_drift_test.c \
        ~/berkeley-softfloat-3/build/Linux-x86_64-GCC/softfloat.a \
        -lm -o gen_drift_test || { echo "Compile failed"; exit 1; }
fi

CSV_FILE="testfloat_cases_${NUM_INPUTS}_pure_bf16.csv"

# Generating data. (Make sure gen_drift_test accepts -i for num inputs!)
./gen_drift_test -n "$NUM_CASES" -i "$NUM_INPUTS" $UNCONSTRAINED_FLAG > "$CSV_FILE" 2> temp_stderr.log

SEED=$(grep "Reproducible Seed:" temp_stderr.log | grep -oEi "0x[0-9a-f]+")
[[ -z "$SEED" ]] && SEED="unknown_seed_$(date +%s)"
rm temp_stderr.log

cd "$ATALLA_DIR" || exit 1
RESULTS_DIR="schmoo_dse_${NUM_INPUTS}in_${SEED}_${MODE_TEXT}"
mkdir -p "$RESULTS_DIR"

# Pre-calculate the dynamic $fscanf string elements
MAX_IDX=$((NUM_INPUTS - 1))
EXPECTED_RET=$((NUM_INPUTS + 1))

FMT_STR=""
VARS_STR=""
for i in $(seq 1 $NUM_INPUTS); do FMT_STR="${FMT_STR}%h,"; done
FMT_STR="${FMT_STR}%h\\n"

for i in $(seq 0 $MAX_IDX); do VARS_STR="${VARS_STR}temp_inputs[$i], "; done
VARS_STR="${VARS_STR}temp_expected"

# =====================================================================
# PHASE 2: PARALLEL WRAPPER TESTING
# =====================================================================
echo ""
echo "Phase 2: Launching tests across $WRAPPER_DIR..."
CURRENT_JOBS=0

for WRAPPER_SUBDIR in "$WRAPPER_DIR"/sysarr_${NUM_INPUTS}_TOP_*; do
    if [[ ! -d "$WRAPPER_SUBDIR" ]]; then continue; fi

    TOP_MOD=$(basename "$WRAPPER_SUBDIR")
    WRAPPER_SV="$WRAPPER_SUBDIR/${TOP_MOD}.sv"

    if [[ ! -f "$WRAPPER_SV" ]]; then continue; fi

    (
        WRAPPER_LATENCY=$(grep "TOTAL PIPELINE LATENCY:" "$WRAPPER_SV" | grep -oEi "[0-9]+")
        ALIGNER_MOD=$(grep -oEi "sysarr_${NUM_INPUTS}_aligner_tree_[01]+_reg_[01]" "$WRAPPER_SV" | head -n 1)
        ADDER_MOD=$(grep -oEi "add${NUM_INPUTS}_tree_[0-9_]+_pipe_[01]+_lat[0-9]+_var[0-9_]+" "$WRAPPER_SV" | head -n 1)        
        TOTAL_TB_WAIT=$(( WRAPPER_LATENCY + RESET_DELAY ))
        ALIGNER_SV="$WRAPPER_SUBDIR/${ALIGNER_MOD}.sv"
        ADDER_SV="$WRAPPER_SUBDIR/${ADDER_MOD}.sv"

        TEMP_TB="tb_sandbox_${TOP_MOD}.sv"

        # --- DYNAMIC TESTBENCH GENERATION ---
        cat << EOF > "$TEMP_TB"
\`timescale 1ns/1ps

module add32_32input_fused_tb_softfloat;

    localparam PERIOD = 2;
    localparam LATENCY = $TOTAL_TB_WAIT;
    localparam GRS = 1;
    localparam PRECISION_BITS = 3;
    
    localparam MANTISSA_SIZE = 23;
    localparam EXPONENT_SIZE = 8;
    localparam IN_MANTISSA_SIZE = 7;
    localparam IN_EXPONENT_SIZE = 8;

    logic tb_clk = 0;
    logic tb_nrst;

    always #(PERIOD/2.0) tb_clk = ~tb_clk;

    typedef struct {
        logic [15:0] inputs [$MAX_IDX:0];
        logic [15:0] expected;
        int id;
    } scoreboard_entry_t;

    scoreboard_entry_t scoreboard_queue [\$];

    int pass_count, fail_count; 
    longint total_ulp_diff;
    int ulp_big_count;
    int largest_ulp; 
    integer fail_fd;
    int total_processed = 0;

    real total_num_diff;
    real largest_num_diff;
    real num_diff; 

    logic [15:0] tb_inputs [$MAX_IDX:0];
    logic [31:0] fp32_result;      
    logic [15:0] tb_result;        

    $TOP_MOD #(
        .MANTISSA_SIZE(MANTISSA_SIZE), 
        .EXPONENT_SIZE(EXPONENT_SIZE),
        .IN_MANTISSA_SIZE(IN_MANTISSA_SIZE),
        .IN_EXPONENT_SIZE(IN_EXPONENT_SIZE),
        .PRECISION_BITS(PRECISION_BITS), 
        .GRS(GRS)
    ) dut_adder (
        .clk(tb_clk),
        .nRST(tb_nrst),
        .in(tb_inputs),
        .result(fp32_result)
    );

    reducer #(
        .IN_EXP_W(EXPONENT_SIZE),    
        .IN_MANT_W(MANTISSA_SIZE),   
        .OUT_EXP_W(IN_EXPONENT_SIZE),
        .OUT_MANT_W(IN_MANTISSA_SIZE)
    ) dut_reduce (
        .fp_in(fp32_result),
        .fp_out(tb_result)
    );

    function automatic logic is_nan(input logic [15:0] val);
        return (val[14:7] == 8'hFF) && (val[6:0] != 7'h0);
    endfunction

    function automatic longint unsigned get_ulp_distance(
        input logic [15:0] hw_out,  
        input logic [15:0] ref_out   
    );
        longint unsigned int_hw, int_ref;
        if (hw_out  == 16'h8000) hw_out  = 16'h0000;
        if (ref_out == 16'h8000) ref_out = 16'h0000;
        
        /* verilator lint_off WIDTHEXPAND */
        int_hw  = (hw_out[15])  ? (16'h7FFF - hw_out[14:0])  : (16'h8000 + hw_out[14:0]);
        int_ref = (ref_out[15]) ? (16'h7FFF - ref_out[14:0]) : (16'h8000 + ref_out[14:0]);
        /* verilator lint_on WIDTHEXPAND */
        
        return (int_hw > int_ref) ? (int_hw - int_ref) : (int_ref - int_hw);
    endfunction

    function automatic real get_bf16_numerical_difference(logic [15:0] a, logic [15:0] b);
        real float_a, float_b, diff;
        /* verilator lint_off SHORTREAL */
        float_a = \$bitstoshortreal({a, 16'h0000});
        float_b = \$bitstoshortreal({b, 16'h0000});
        /* verilator lint_on SHORTREAL */
        diff = float_a - float_b;
        if (diff < 0.0) return -diff;
        else return diff;
    endfunction

    initial begin
        integer fd;
        string header;
        int ret;
        scoreboard_entry_t entry;
        
        logic [15:0] temp_inputs [$MAX_IDX:0];
        logic [15:0] temp_expected;

        tb_nrst = 1'b0;
        for (int i=0; i<$NUM_INPUTS; i++) tb_inputs[i] = '0;
        #(PERIOD * 5);
        tb_nrst = 1'b1;

        fd = \$fopen("scripts/systolic_array/$CSV_FILE", "r");
        fail_fd = \$fopen("tree_failures.csv", "w");
        if (fd == 0) begin \$display("FATAL: CSV not found"); \$finish; end
        
        void'(\$fgets(header, fd));

        \$display("Starting Continuous Simulation with Full Diagnostics...");

        while (!\$feof(fd)) begin
            ret = \$fscanf(fd, "$FMT_STR", $VARS_STR);

            if (ret == $EXPECTED_RET) begin
                @(posedge tb_clk);
                for(int k=0; k<$NUM_INPUTS; k++) begin
                    tb_inputs[k]     <= temp_inputs[k];
                    entry.inputs[k]   = temp_inputs[k];
                end
                entry.expected = temp_expected;
                entry.id       = total_processed;
                
                scoreboard_queue.push_back(entry);
                total_processed++;
            end else begin
                // FIXED: Break instantly on blank lines or EOF to prevent 0-delay infinite loops!
                break;
            end
        end

        repeat (LATENCY + 5) @(posedge tb_clk);
        \$display("\nSimulation Completed.");
        print_final_report();
        \$finish;
    end

    initial begin
        scoreboard_entry_t check_entry;
        longint ulp;
        logic match;

        repeat (LATENCY) @(posedge tb_clk);

        forever begin
            @(negedge tb_clk);
            if (scoreboard_queue.size() > 0) begin
                check_entry = scoreboard_queue.pop_front();
                
                if (is_nan(tb_result) && is_nan(check_entry.expected)) begin
                    match = 1'b1;
                    ulp = 0;
                end else begin
                    match = (tb_result === check_entry.expected);
                    ulp = get_ulp_distance(tb_result, check_entry.expected);
                    num_diff = get_bf16_numerical_difference(tb_result, check_entry.expected);
                end

                total_ulp_diff += ulp;
                total_num_diff += num_diff; 
                if (ulp > 1) ulp_big_count++;
                
                /* verilator lint_off WIDTHEXPAND */
                if (ulp > largest_ulp) largest_ulp = int'(ulp);
                /* verilator lint_on WIDTHEXPAND */
                
                if (num_diff > largest_num_diff) largest_num_diff = num_diff;

                if (!match) begin
                    if (fail_count < 20)
                        \$display("FAIL: Row %0d | Got=%h Exp=%h | ULP=%0d", check_entry.id, tb_result, check_entry.expected, ulp);
                    
                    if (fail_fd != 0 && ulp > 1) begin
                        for (int k=0; k<$NUM_INPUTS; k++) \$fwrite(fail_fd, "%h,", check_entry.inputs[k]);
                        \$fwrite(fail_fd, "%h,%h,%0d\n", check_entry.expected, tb_result, ulp);
                        \$fwrite(fail_fd, "Exponent - Got: %h, Expected: %h\n", tb_result[14:7], check_entry.expected[14:7]);
                    end
                    fail_count++;
                end else begin
                    pass_count++;
                end

                if (check_entry.id % 10000 == 0 && check_entry.id != 0)
                    \$display("Processed %0d cases...", check_entry.id);
            end
        end
    end

    task automatic print_final_report();
        \$display("\n========================================");
        \$display("FINAL REPORT");
        \$display("TOTAL CASES: %0d", total_processed);
        \$display("PASSED:      %0d", pass_count);
        \$display("FAILED:      %0d", fail_count);
        if (total_processed > 0)
            \$display("AVG ULP ERR: %0f", total_ulp_diff * 1.0 / total_processed);
        \$display("MAX ULP ERR: %0d", largest_ulp);
        \$display("ULP > 1:     %0d", ulp_big_count);
        \$display("========================================\n");
    endtask

endmodule
EOF
        # -----------------------------------

        OBJ_DIR="obj_dir_${TOP_MOD}"
        mkdir -p "$OBJ_DIR"
        
        # FIXED: Reduced -j 0 to -j 2 to prevent Mac CPU thrashing with parallel jobs
        verilator -Irtl/include/systolic_array \
            --Mdir "$OBJ_DIR" \
            --binary -j 2 -threads 2 -Wall -Wno-fatal -Wno-SHORTREAL -Wno-WIDTHEXPAND -Wno-DECLFILENAME -Wno-EOFNEWLINE --timing --trace \
            --top-module add32_32input_fused_tb_softfloat \
            "$TEMP_TB" "$REDUCER_SV" "$ALIGNER_SV" "$WRAPPER_SV" "$ADDER_SV" > "$OBJ_DIR/build.log" 2>&1

        if [[ $? -ne 0 ]]; then
            echo " -> [BUILD ERROR] Verilator failed to compile $TOP_MOD!"
            echo "------------------- BUILD LOG -------------------"
            cat "$OBJ_DIR/build.log"
            echo "-------------------------------------------------"
            exit 1
        fi

        SIM_OUT="$RESULTS_DIR/sim_out_${TOP_MOD}.txt"
        
        if [[ -x "$OBJ_DIR/Vadd32_32input_fused_tb_softfloat" ]]; then
            ./"$OBJ_DIR"/Vadd32_32input_fused_tb_softfloat > "$SIM_OUT"

            if grep -q "FINAL REPORT" "$SIM_OUT"; then
                PASSED=$(grep -E "^PASSED:" "$SIM_OUT" | awk '{print $2}')
                FAILED=$(grep -E "^FAILED:" "$SIM_OUT" | awk '{print $2}')
                MAX_ULP=$(grep -E "^MAX ULP ERR:" "$SIM_OUT" | awk '{print $4}')
                echo " -> [DONE] HW Latency: ${WRAPPER_LATENCY}c | Pass: ${PASSED} | Fail: ${FAILED} | Max ULP: ${MAX_ULP} | Mod: $TOP_MOD"
            else
                echo " -> [CRASH] Simulation failed to complete for $TOP_MOD. Check $SIM_OUT"
            fi
        else
            echo " -> [EXEC ERROR] Binary not found for $TOP_MOD."
        fi

        rm -f "$TEMP_TB" && rm -rf "$OBJ_DIR"
    ) &

    ((CURRENT_JOBS++))
    if [[ $CURRENT_JOBS -ge $MAX_JOBS ]]; then
        wait
        CURRENT_JOBS=0
    fi
done

wait

TOTAL_DURATION=$(( SECONDS - TOTAL_START ))
echo ""
echo "##################################################"
echo "ALL TESTS COMPLETED SUCCESSFULLY!"
echo "Total Execution Time: $(( TOTAL_DURATION / 60 ))m $(( TOTAL_DURATION % 60 ))s"
echo "Results saved in: $RESULTS_DIR/"
echo "##################################################"