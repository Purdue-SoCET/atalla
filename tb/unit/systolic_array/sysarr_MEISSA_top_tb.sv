`include "systolic_array_MAC_if.vh"
`include "systolic_array_tb_pkg.sv"
`include "gsau_control_unit_if.vh"

`timescale 1 ns / 1 ns

// =============================================================================
// sysarr_MEISSA_top_tb
//
//   1. Output backpressure: sa_ready_out is randomly deasserted (mostly short
//      stalls, occasionally long enough to fill the output buffer) so the
//      credit / output-buffer flow control is exercised. Disable with
//      +NO_BACKPRESSURE. A watchdog fails the run if outputs stop arriving.
//   2. Every actual output is compared to the correctly-rounded bf16 expected
//      output in ULP units (treating the 16-bit bit pattern as sign-magnitude
//      distance across zero). Any value with |ULP| >= 1 is logged to
//      scripts/systolic_array/systolic_array_tb_ulp_report.txt, along with the
//      running max |ULP|.
// =============================================================================

module sysarr_MEISSA_top_tb();
    import systolic_array_tb_pkg::*;

    integer total_passed_tests = 0;
    integer total_tests        = 0;

    // ULP accounting
    integer total_elements_compared   = 0;
    integer total_ulp_mismatches      = 0;   // elements with |ULP| >= 1
    integer max_abs_ulp               = 0;
    integer total_abs_ulp_accumulator = 0;   // for mean |ULP|

    // clk/reset
    logic nRST;

    // Systolic Array Interface
    gsau_control_unit_if gsau_if();

    // Clock gen
    parameter PERIOD = 10;
    logic CLK = 0;
    always #(PERIOD/2) CLK++;

    // FILE I/O
    int expected_out_file, file, actual_output_file, ulp_report_file;
    /* verilator lint_off UNUSEDSIGNAL */
    string line, test_name;
    /* verilator lint_on UNUSEDSIGNAL */

    // Report path: reuse PATH_TO_PROJ from the auto-generated package.
    localparam string PATH_TO_ULP_REPORT =
        {PATH_TO_PROJ, "/scripts/systolic_array/systolic_array_tb_ulp_report.txt"};

    logic [DATA_WIDTH-1:0] temp_weights[ARRAY_DIM][ARRAY_DIM];
    logic [DATA_WIDTH-1:0] temp_inputs[ARRAY_DIM][ARRAY_DIM];
    logic [DATA_WIDTH-1:0] temp_partials[ARRAY_DIM][ARRAY_DIM];
    logic [DATA_WIDTH-1:0] temp_exp_outputs[ARRAY_DIM][ARRAY_DIM];
    logic [DATA_WIDTH-1:0] temp_act_outputs[ARRAY_DIM][ARRAY_DIM];

    logic [(ARRAY_DIM*DATA_WIDTH)-1:0] m_weights[ARRAY_DIM];
    logic [(ARRAY_DIM*DATA_WIDTH)-1:0] m_inputs[ARRAY_DIM];
    logic [(ARRAY_DIM*DATA_WIDTH)-1:0] m_partials[ARRAY_DIM];
    logic [(ARRAY_DIM*DATA_WIDTH)-1:0] m_exp_outputs[ARRAY_DIM];
    logic [(ARRAY_DIM*DATA_WIDTH)-1:0] m_act_outputs[ARRAY_DIM];
    int loaded_weights;
    int pending_gemms = 0;
    string test_name_queue[$];
    bit input_eof = 0;
    event gemm_completed;

    // -------------------------------------------------------------------------
    // Race-free handshake with the DUT. Driving DUT inputs or reading DUT
    // outputs exactly at the rising edge races with the DUT's registers, and
    // the simulators resolve it differently: under Verilator the DUT saw
    // sa_input_en a cycle early, so sa_ready_in (|next_credits) double-counted
    // the issue and the TB issued rows with no credit left. So:
    //   - DUT inputs are driven 1 time unit after the rising edge (tick()).
    //   - DUT outputs are sampled on the falling edge (below).
    // At each rising edge ready_in_s is sa_ready_in from the cycle just ended,
    // so a row may be issued in the next cycle iff ready_in_s is 1.
    // -------------------------------------------------------------------------
    logic                              ready_in_s = 1'b0;
    logic                              valid_in_s = 1'b0;
    logic [ARRAY_DIM*DATA_WIDTH-1:0]   array_output_s = '0;

    always @(negedge CLK) begin
        if (nRST && gsau_if.sa_input_en && !ready_in_s)
            $fatal(1, "Protocol violation: sa_input_en asserted while sa_ready_in was low");
        ready_in_s     <= gsau_if.sa_ready_in;
        valid_in_s     <= gsau_if.sa_valid_in;
        array_output_s <= gsau_if.sa_array_output;
    end

    task automatic tick();
        @(posedge CLK);
        #1;
    endtask

    // -------------------------------------------------------------------------
    // Signed-magnitude ULP distance for bf16.
    // Maps each 16-bit pattern to a monotone signed integer so distances
    // across zero are well-defined. Matches bf16_ulp_diff() in
    // scripts/systolic_array/C++/bf16_exact_acc.hpp.
    // -------------------------------------------------------------------------
    function automatic int bf16_ulp_diff(input logic [15:0] hw,
                                         input logic [15:0] golden);
        int hw_ord, gl_ord;
        hw_ord = hw[15]     ? -int'({1'b0, hw[14:0]})     : int'({1'b0, hw[14:0]});
        gl_ord = golden[15] ? -int'({1'b0, golden[14:0]}) : int'({1'b0, golden[14:0]});
        return hw_ord - gl_ord;
    endfunction

    function automatic int abs_i(input int x);
        return (x < 0) ? -x : x;
    endfunction

    task reset();
        begin
        nRST = 1'b0;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        #1;
        nRST = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        end
    endtask

    task get_matrices(output int weights, input int has_weights);
        string token;
        string section;
        weights = 0;

        // Read section header: Weight
        void'($fgets(line, file));
        section = line.toupper();

        if (section.len() >= 5 && section.substr(0,5) == "WEIGHT") begin
            weights = 1;
            for (int i = 0; i < ARRAY_DIM; i++) begin
                void'($fgets(line, file));
                for (int j = 0; j < ARRAY_DIM; j++) begin
                    token = line.substr(j*7, (j*7)+6); // "0xXXXX"
                    void'($sscanf(token, "%h", temp_weights[i][j]));
                end
            end
            void'($fgets(line, file)); // blank
            void'($fgets(line, file)); // "Input"
        end

        for (int i = 0; i < ARRAY_DIM; i++) begin
            void'($fgets(line, file));
            for (int j = 0; j < ARRAY_DIM; j++) begin
                token = line.substr(j*7, (j*7)+6);
                void'($sscanf(token, "%h", temp_inputs[i][j]));
            end
        end

        void'($fgets(line, file)); // blank
        void'($fgets(line, file)); // "Psum"

        for (int i = 0; i < ARRAY_DIM; i++) begin
            void'($fgets(line, file));
            for (int j = 0; j < ARRAY_DIM; j++) begin
                token = line.substr(j*7, (j*7)+6);
                void'($sscanf(token, "%h", temp_partials[i][j]));
            end
        end

        for (int i = 0; i < ARRAY_DIM; i++) begin
            m_weights[i]  = {>>{temp_weights[i]}};
            m_inputs[i]   = {>>{temp_inputs[i]}};
            m_partials[i] = {>>{temp_partials[i]}};
        end
    endtask

    task get_m_expected_output();
        string token;
        for (int i = 0 ; i < ARRAY_DIM; i++) begin
            void'($fgets(line, expected_out_file));
            for (int j = 0; j < ARRAY_DIM; j++) begin
                token = line.substr(j * 7, (j*7)+6);
                void'($sscanf(token, "%h", temp_exp_outputs[i][j]));
            end
        end
    endtask

    task load_weights();
        /* verilator lint_off INITIALDLY */
        gsau_if.sa_input_en   <= 1'b0;
        gsau_if.sa_partial_en <= 1'b0;
        gsau_if.sa_weight_en  <= 1'b0;
        gsau_if.sa_array_in   <= '0;

        for (int column = ARRAY_DIM - 1; column >= 0; column--) begin
            gsau_if.sa_weight_en <= 1'b0;
            gsau_if.sa_array_in  <= '0;

            while (!ready_in_s) tick();

            gsau_if.sa_array_in <= '0;
            for (int row = 0; row < ARRAY_DIM; row++) begin
                gsau_if.sa_array_in[DATA_WIDTH*row +: DATA_WIDTH] <= temp_weights[row][column];
            end

            gsau_if.sa_weight_en <= 1'b1;
            tick();
        end

        gsau_if.sa_weight_en <= 1'b0;
        gsau_if.sa_array_in  <= '0;
        /* verilator lint_on INITIALDLY */
    endtask

    task write_matrix(input string tname);
        $fwrite(actual_output_file, "%s", tname);

        for (int row = 0; row < ARRAY_DIM; row++) begin
            for (int column = 0; column < ARRAY_DIM; column++) begin
                $fwrite(actual_output_file, "0x%04H", temp_act_outputs[row][column]);
                if (column != ARRAY_DIM - 1) $fwrite(actual_output_file, ",");
            end
            $fwrite(actual_output_file, "\n");
        end
        $fwrite(actual_output_file, "\n");
    endtask

generate
    if(VERSION == "MEISSA" || VERSION == "MEISSA32") begin
        sysarr_MEISSA_top #(.USE_MIXED_ADDER(0)) DUT (CLK, nRST, gsau_if);
    end
    else if (VERSION == "TPU") begin
        TPU_top DUT(CLK, nRST, gsau_if);
    end
    else if (VERSION == "STANDARD") begin
        initial $fatal(1, "VERSION STANDARD: sysarr_STANDARD is not instantiated in this testbench");
    end
    else begin
        initial $fatal("Unsupported VERSION: %s", VERSION);
    end
endgenerate

// -----------------------------------------------------------------------------
// Output backpressure: randomly deassert sa_ready_out. Mostly short stalls,
// with 1 in 4 long enough to fill the output buffer. +NO_BACKPRESSURE disables.
// -----------------------------------------------------------------------------
localparam int STALL_START_PER_MILLE = 20;  // chance per cycle of starting a stall
localparam int SHORT_STALL_MIN = 1,  SHORT_STALL_MAX = 8;
localparam int LONG_STALL_MIN  = 60, LONG_STALL_MAX  = 200;
localparam int DEADLOCK_CYCLES = 10000;

bit   backpressure_en;
logic ready_out_r = 1'b1;
int   stall_left   = 0;
int   stall_cycles = 0;
int   idle_cycles  = 0;

initial backpressure_en = !$test$plusargs("NO_BACKPRESSURE");

assign gsau_if.sa_ready_out = ready_out_r;

always @(posedge CLK) begin
    if (!ready_out_r) stall_cycles++;
    #1;
    if (stall_left > 0) begin
        stall_left--;
        ready_out_r <= (stall_left == 0);
    end else if (backpressure_en && $urandom_range(0, 999) < STALL_START_PER_MILLE) begin
        stall_left = ($urandom_range(0, 3) == 0) ? $urandom_range(LONG_STALL_MIN, LONG_STALL_MAX)
                                                 : $urandom_range(SHORT_STALL_MIN, SHORT_STALL_MAX);
        ready_out_r <= 1'b0;
    end else begin
        ready_out_r <= 1'b1;
    end
end

// Fail instead of hanging if outputs stop arriving.
always @(posedge CLK) begin
    if (!nRST || valid_in_s) idle_cycles = 0;
    else idle_cycles++;
    if (idle_cycles == DEADLOCK_CYCLES)
        $fatal(1, "No output for %0d cycles: possible deadlock", DEADLOCK_CYCLES);
end

// Initialize signals and files
initial begin
    /* verilator lint_off INITIALDLY */
    gsau_if.sa_array_in          <= '0;
    gsau_if.sa_array_in_partials <= '0;
    gsau_if.sa_input_en          <= 1'b0;
    gsau_if.sa_weight_en         <= 1'b0;
    gsau_if.sa_partial_en        <= 1'b0;

    file               = $fopen(PATH_TO_INPUT, "r");
    expected_out_file  = $fopen(PATH_TO_EXPECTED_RESULT, "r");
    actual_output_file = $fopen(PATH_TO_RESULT, "w");
    ulp_report_file    = $fopen(PATH_TO_ULP_REPORT, "w");

    $fwrite(ulp_report_file,
            "# ULP report (hw vs correctly-rounded bf16 golden)\n");
    $fwrite(ulp_report_file,
            "# VERSION=%s ARRAY_DIM=%0d\n", VERSION, ARRAY_DIM);
    $fwrite(ulp_report_file,
            "# Columns: test, row, col, expected, actual, ulp_diff\n");
    /* verilator lint_on INITIALDLY */
end

// -----------------------------------------------------------------------------
// Process 1: Feed inputs (weights, inputs, psums) into the array.
// -----------------------------------------------------------------------------
initial begin
    /* verilator lint_off INITIALDLY */
    int input_row;
    bit found_test;
    bit loaded_weights;
    input_row = 0;

    reset();

    forever begin
        tick();

        if (ready_in_s) begin

            if (input_row == 0) begin
                found_test  = 0;
                gsau_if.sa_input_en          <= 1'b0;
                gsau_if.sa_partial_en        <= 1'b0;
                gsau_if.sa_array_in          <= '0;
                gsau_if.sa_array_in_partials <= '0;

                while (!found_test) begin
                    if ($fgets(line, file) == 0) begin
                        break;
                    end
                    if (line.len() >= 4 && line.substr(0,3) == "Test") begin
                        test_name_queue.push_front(line);
                        test_name = line;
                        found_test = 1;
                    end
                end

                if (!found_test) begin
                    input_eof = 1'b1;
                    gsau_if.sa_input_en          <= 1'b0;
                    gsau_if.sa_partial_en        <= 1'b0;
                    gsau_if.sa_array_in          <= '0;
                    gsau_if.sa_array_in_partials <= '0;
                    break;
                end

                loaded_weights = 0;
                if (found_test) begin
                    get_matrices(.weights(loaded_weights), .has_weights(1));
                    if (loaded_weights) begin
                        while (pending_gemms != 0) begin
                            @(gemm_completed);
                            #1;
                        end
                        load_weights();
                        while (!ready_in_s) tick();
                    end
                end

                pending_gemms++;
            end

            gsau_if.sa_input_en   <= 1'b0;
            gsau_if.sa_partial_en <= 1'b0;
            for (int col = 0; col < ARRAY_DIM; col++) begin
                gsau_if.sa_array_in[DATA_WIDTH*col +: DATA_WIDTH]
                    <= temp_inputs[input_row][col];
                gsau_if.sa_array_in_partials[DATA_WIDTH*col +: DATA_WIDTH]
                    <= temp_partials[input_row][col];
            end
            gsau_if.sa_input_en   <= 1'b1;
            gsau_if.sa_partial_en <= 1'b1;

            input_row++;
            if (input_row == ARRAY_DIM) input_row = 0;

        end else begin
            gsau_if.sa_input_en   <= 1'b0;
            gsau_if.sa_partial_en <= 1'b0;
        end
    end
    /* verilator lint_on INITIALDLY */
end

// -----------------------------------------------------------------------------
// Process 2: Collect outputs, check them against the correctly-rounded golden
// expected outputs, accumulate ULP statistics, and log every |ULP| >= 1 entry.
// -----------------------------------------------------------------------------
initial begin
    /* verilator lint_off INITIALDLY */
    int result_row;
    bit found_expected_result;
    bit is_result_correct;
    string current_test_name;
    int ulp_diff;
    int abs_ulp;
    logic [15:0] hw_val;
    logic [15:0] gl_val;

    result_row = 0;

    for (int i = 0; i < ARRAY_DIM; i++) begin
        m_act_outputs[i] = '0;
        for (int j = 0; j < ARRAY_DIM; j++) begin
            temp_act_outputs[i][j] = '0;
        end
    end

    forever begin
        @(posedge CLK);

        if (input_eof && test_name_queue.size() == 0 && result_row == 0) begin
            $display("All queued tests processed. Ending simulation.");
            break;
        end

        if (valid_in_s) begin
            m_act_outputs[result_row] = array_output_s;
            for (int col = 0; col < ARRAY_DIM; col++) begin
                temp_act_outputs[result_row][col] =
                    array_output_s[DATA_WIDTH*col +: DATA_WIDTH];
            end

            result_row++;

            if (result_row == ARRAY_DIM) begin
                result_row = 0;

                found_expected_result = 0;
                while (!found_expected_result) begin
                    if ($fgets(line, expected_out_file) == 0) break;
                    if (line.len() >= 4 && line.substr(0,3) == "Test")
                        found_expected_result = 1;
                end

                if (found_expected_result) begin
                    get_m_expected_output();
                end else begin
                    $display("Reached EOF in expected result file. Ending simulation.");
                    break;
                end

                current_test_name = test_name_queue.pop_back();

                // Compare actual vs expected, compute ULP distances.
                is_result_correct = 1;
                for (int i = 0; i < ARRAY_DIM; i++) begin
                    for (int j = 0; j < ARRAY_DIM; j++) begin
                        hw_val = temp_act_outputs[i][j];
                        gl_val = temp_exp_outputs[i][j];
                        // Normalize -0 to +0 so signed zero never contributes ULP.
                        if (hw_val == 16'h8000) hw_val = 16'h0000;
                        if (gl_val == 16'h8000) gl_val = 16'h0000;

                        ulp_diff = bf16_ulp_diff(hw_val, gl_val);
                        abs_ulp  = abs_i(ulp_diff);

                        total_elements_compared++;
                        total_abs_ulp_accumulator += abs_ulp;

                        if (abs_ulp > max_abs_ulp) max_abs_ulp = abs_ulp;

                        if (abs_ulp >= 1) begin
                            string trimmed_name;
                            trimmed_name = current_test_name;
                            // Strip trailing newline from the test header so
                            // the report stays on one line per entry.
                            if (trimmed_name.len() > 0 &&
                                trimmed_name.getc(trimmed_name.len()-1) == "\n")
                                trimmed_name =
                                    trimmed_name.substr(0, trimmed_name.len()-2);

                            total_ulp_mismatches++;
                            is_result_correct = 0;
                            $fwrite(ulp_report_file,
                                "%s, [%0d][%0d], exp=0x%04H, act=0x%04H, ulp=%0d\n",
                                trimmed_name, i, j, gl_val, hw_val, ulp_diff);
                        end
                    end
                end

                total_tests++;
                write_matrix(current_test_name);
                if (is_result_correct) total_passed_tests++;

                if (pending_gemms > 0) pending_gemms--;
                -> gemm_completed;

                for (int i = 0; i < ARRAY_DIM; i++) begin
                    m_act_outputs[i] = '0;
                    for (int j = 0; j < ARRAY_DIM; j++) begin
                        temp_act_outputs[i][j] = '0;
                    end
                end
            end
        end
    end
    /* verilator lint_on INITIALDLY */

    // -------------------------------------------------------------------------
    // Final ULP summary, written to both stdout and the report file.
    // -------------------------------------------------------------------------
    $fwrite(ulp_report_file, "\n# ========== Summary ==========\n");
    $fwrite(ulp_report_file, "Total elements compared      : %0d\n",
            total_elements_compared);
    $fwrite(ulp_report_file, "Elements with |ULP| >= 1     : %0d\n",
            total_ulp_mismatches);
    $fwrite(ulp_report_file, "Max |ULP|                    : %0d\n",
            max_abs_ulp);
    if (total_elements_compared > 0) begin
        $fwrite(ulp_report_file,
            "Mean |ULP| (x1000, int)      : %0d\n",
            (total_abs_ulp_accumulator * 1000) / total_elements_compared);
    end
    $fwrite(ulp_report_file, "Exact-match tests / total    : %0d / %0d\n",
            total_passed_tests, total_tests);
    $fwrite(ulp_report_file, "Backpressure                 : %s (%0d stall cycles)\n",
            backpressure_en ? "on" : "off", stall_cycles);

    $fclose(file);
    $fclose(expected_out_file);
    $fclose(actual_output_file);
    $fclose(ulp_report_file);
    #50;
    $display("Passed Tests (exact match): %0d / %0d",
             total_passed_tests, total_tests);
    $display("Elements with |ULP| >= 1 : %0d / %0d",
             total_ulp_mismatches, total_elements_compared);
    $display("Max |ULP|                : %0d", max_abs_ulp);
    $display("Backpressure             : %s (%0d stall cycles)",
             backpressure_en ? "on" : "off", stall_cycles);
    $display("ULP report written to    : %s", PATH_TO_ULP_REPORT);
    $finish;
end

endmodule
