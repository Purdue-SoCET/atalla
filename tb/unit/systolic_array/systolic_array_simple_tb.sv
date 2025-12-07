// Enhanced testbench for systolic_array_simple with distinct value test cases
// Based on systolic_array_top_tb infrastructure
// Requirements: 1.1, 1.2, 1.3

`timescale 1ns / 1ps
`include "gsau_control_unit_if.vh"
`include "sys_arr_pkg.vh"

/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_on IMPORTSTAR */

module systolic_array_simple_tb();

// Parameters
localparam CLK_PERIOD = 10;

// Test configuration - use existing test files
string testcase = "fp";
string path_to_files = "/home/vinay/tensorcore/tensor-core/";
string input_filename = {"systolic_array_utils/matops_", testcase, "_encoded.txt"};
string output_filename = {"systolic_array_utils/matops_", testcase, "_simple_result.txt"};
string python_output_filename = {"systolic_array_utils/matops_", testcase, "_encoded_output.txt"};
string python_command = {"/bin/python3 ", path_to_files, "systolic_array_utils/matrix_mul_fp.py systolic_array_utils/matops_", testcase, "_encoded"};
string comparison_command = {"/bin/python3 ", path_to_files, "scripts/systolic_array/compare_sysarr_output.py systolic_array_utils/matops_", testcase, "_simple_result.txt systolic_array_utils/matops_", testcase, "_encoded_output.txt systolic_array_utils/matops_", testcase, "_simple_comp.txt"};

// Testbench Signals
logic tb_clk;
logic tb_nrst;

// FILE I/O
int out_file, file, k, i, j, z, y, r, in, which;
int sysarr_dump_file;
/* verilator lint_off UNUSEDSIGNAL */
string line;
/* verilator lint_on UNUSEDSIGNAL */
logic [DW-1:0] temp_weights[N][N];
logic [DW-1:0] temp_inputs[N][N];
logic [DW-1:0] temp_partials[N][N];
logic [DW-1:0] temp_outputs[N][N];

logic [(N*DW)-1:0] m_weights[N];
logic [(N*DW)-1:0] m_inputs[N];
logic [(N*DW)-1:0] m_partials[N];
logic [(N*DW)-1:0] m_outputs[N];
int loaded_weights;

// Test tracking
int test_pass_count;
int test_fail_count;
int total_comparisons;
int output_row_count;


// Clock generation
always begin
    tb_clk = 1'b0;
    #(CLK_PERIOD/2.0);
    tb_clk = 1'b1;
    #(CLK_PERIOD/2.0);
end

gsau_control_unit_if sa_interface();
systolic_array_simple DUT (.nRST(tb_nrst), .clk(tb_clk), .gsau_if(sa_interface));

// Reset task
task reset;
    begin
        tb_nrst = 1'b0;
        @(posedge tb_clk);
        @(posedge tb_clk);
        @(negedge tb_clk);
        tb_nrst = 1'b1;
        @(posedge tb_clk);
        @(posedge tb_clk);
    end
endtask

// Task to read matrices from file
task get_matrices(output int weights);
    begin
        int iterations;
        int rc;
        $display("In get matrices task");
        weights = 0;
        which = 0;
        $fgets(line, file);
        if (line == "Weights\n") begin
            which = 1;
            iterations = 3;
            weights = 1;
        end else if (line == "Inputs\n") begin
            which = 2;
            iterations = 2;
        end
        $display("Matrix type: %d", which);
        for (k = 0; k < iterations; k++) begin
            for (i = 0; i < N; i = i + 1) begin
                for (j = 0; j < N; j = j + 1) begin
                    if (which == 1) begin
                        rc = $fscanf(file, "%x ", temp_weights[i][j]);
                        if (rc != 1) $display("WARN: fscanf weights[%0d][%0d] rc=%0d", i, j, rc);
                    end else if (which == 2) begin
                        rc = $fscanf(file, "%x ", temp_inputs[i][j]);
                        if (rc != 1) $display("WARN: fscanf inputs[%0d][%0d] rc=%0d", i, j, rc);
                    end else begin
                        rc = $fscanf(file, "%x ", temp_partials[i][j]);
                        if (rc != 1) $display("WARN: fscanf partials[%0d][%0d] rc=%0d", i, j, rc);
                    end
                end  
            end
            which = which + 1;
            $fgets(line, file);
        end
        for (i = 0; i < N; i++) begin
            m_weights[i] = {>>{temp_weights[i]}};
            m_inputs[i] = {>>{temp_inputs[i]}};
            m_partials[i] = {>>{temp_partials[i]}};
        end
        
        $display("=== Matrix Data Verification ===");
        for (i = 0; i < N; i++) begin
            $display("Row %0d weights: %h", i, m_weights[i]);
            $display("Row %0d inputs : %h", i, m_inputs[i]);
            $display("Row %0d partial: %h", i, m_partials[i]);
        end
        $display("================================");
    end
endtask

task get_m_output;
    begin
        for (i = 0; i < N; i = i + 1) begin
            for (j = 0; j < N; j = j + 1) begin
                $fscanf(out_file, "%x ", temp_outputs[i][N-1-j]);
            end
        end
        for (i = 0; i < N; i++) begin
            m_outputs[i] = {>>{temp_outputs[i]}};
        end
    end
endtask


// Load weights - all rows of each column at once
// systolic_array_simple loads weights via sa_array_in when sa_weight_en is high
// Weights propagate horizontally through MAC units via weight_next_en
task load_weights();
    $display("[%0t] Loading weights...", $time);
    // Load all 4 columns of weights, one column per cycle
    // Column 0 weights go to MAC column 0, then propagate right
    for (int c = 0; c < N; c++) begin
        // Pack column c of weights: row 0 at LSB (sa_array_in[0]), row 3 at MSB
        sa_interface.sa_array_in[0] = temp_weights[0][c];
        sa_interface.sa_array_in[1] = temp_weights[1][c];
        sa_interface.sa_array_in[2] = temp_weights[2][c];
        sa_interface.sa_array_in[3] = temp_weights[3][c];
        sa_interface.sa_weight_en = 1'b1;
        $display("[%0t] Loading weight col %0d: [%h, %h, %h, %h]", $time, c,
            temp_weights[0][c], temp_weights[1][c], temp_weights[2][c], temp_weights[3][c]);
        @(posedge tb_clk);
    end
    sa_interface.sa_weight_en = 1'b0;
    sa_interface.sa_array_in = '0;
    $display("[%0t] Weights loaded", $time);
endtask

// Load inputs column-by-column into the input buffer
task load_inputs_streaming(input int delay);
    $display("[%0t] Loading inputs and partials (column-streaming) with delay=%0d...", $time, delay);
    
    for (int c = 0; c < N; c++) begin
        // Pack column c of inputs and partials
        sa_interface.sa_array_in[0] = temp_inputs[0][c];
        sa_interface.sa_array_in[1] = temp_inputs[1][c];
        sa_interface.sa_array_in[2] = temp_inputs[2][c];
        sa_interface.sa_array_in[3] = temp_inputs[3][c];
        
        sa_interface.sa_array_in_partials[0] = temp_partials[0][c];
        sa_interface.sa_array_in_partials[1] = temp_partials[1][c];
        sa_interface.sa_array_in_partials[2] = temp_partials[2][c];
        sa_interface.sa_array_in_partials[3] = temp_partials[3][c];
        
        sa_interface.sa_input_en = 1'b1;
        sa_interface.sa_partial_en = 1'b1;
        @(posedge tb_clk);
        
        sa_interface.sa_input_en = 1'b0;
        sa_interface.sa_partial_en = 1'b0;
        sa_interface.sa_array_in = '0;
        sa_interface.sa_array_in_partials = '0;
        
        repeat (delay) @(posedge tb_clk);
    end
    
    $display("[%0t] Inputs and partials loaded", $time);
endtask

// FP16 comparison with tolerance
function automatic bit compare_fp16_with_tolerance(
    input logic [DW-1:0] actual,
    input logic [DW-1:0] expected,
    input real tolerance_percent
);
    logic [4:0] actual_exp, expected_exp;
    logic [9:0] actual_mant, expected_mant;
    real actual_val, expected_val, error_percent;
    
    if (actual == expected) return 1'b1;
    if ((actual[14:0] == 15'h0) && (expected[14:0] == 15'h0)) return 1'b1;
    
    actual_exp = actual[14:10];
    actual_mant = actual[9:0];
    expected_exp = expected[14:10];
    expected_mant = expected[9:0];
    
    if (actual_exp == 0) actual_val = 0.0;
    else actual_val = (actual[15] ? -1.0 : 1.0) * (1.0 + real'(actual_mant)/1024.0) * (2.0 ** (int'(actual_exp) - 15));
    
    if (expected_exp == 0) expected_val = 0.0;
    else expected_val = (expected[15] ? -1.0 : 1.0) * (1.0 + real'(expected_mant)/1024.0) * (2.0 ** (int'(expected_exp) - 15));
    
    if (expected_val == 0.0) return (actual_val == 0.0);
    
    error_percent = ((actual_val - expected_val) / expected_val) * 100.0;
    if (error_percent < 0) error_percent = -error_percent;
    
    return (error_percent <= tolerance_percent);
endfunction


// Wait for outputs and compare
task wait_for_outputs();
    int cycles;
    int outputs_received;
    begin
        cycles = 0;
        outputs_received = 0;
        
        while (outputs_received < N && cycles < 10000) begin
            @(posedge tb_clk);
            cycles++;
            
            if (sa_interface.sa_out_valid) begin
                $display("========================================");
                $display("OUTPUT COLUMN %0d (cycle %0d)", outputs_received, cycles);
                $display("========================================");
                $display("Raw sa_array_output: %h", sa_interface.sa_array_output);
                
                $write("Systolic Array Output: ");
                for (y = 0; y < N; y++) begin
                    $write("%04h ", sa_interface.sa_array_output[y]);
                end
                $display("");
                
                $write("Expected Output:       ");
                for (z = 0; z < N; z++) begin
                    $write("%04h ", m_outputs[outputs_received][(z+1)*DW-1-:DW]);
                end
                $display("");
                
                // Compare
                for (z = 0; z < N; z++) begin
                    total_comparisons++;
                    if (compare_fp16_with_tolerance(
                            sa_interface.sa_array_output[z],
                            m_outputs[outputs_received][(z+1)*DW-1-:DW],
                            1.0)) begin
                        test_pass_count++;
                    end else begin
                        test_fail_count++;
                        $display(">>> MISMATCH at element %0d! <<<", z);
                    end
                end
                
                // Write to file
                for (y = 0; y < N-1; y++) begin
                    $fwrite(sysarr_dump_file, "%x ", sa_interface.sa_array_output[y]);
                end
                $fwrite(sysarr_dump_file, "%x\n", sa_interface.sa_array_output[N-1]);
                
                // Acknowledge
                sa_interface.sa_output_ready = 1'b1;
                @(posedge tb_clk);
                sa_interface.sa_output_ready = 1'b0;
                
                outputs_received++;
            end
        end
        
        if (outputs_received < N) begin
            $display("ERROR: timeout after %0d cycles (got %0d/%0d)", cycles, outputs_received, N);
        end else begin
            $display("All %0d outputs received after %0d cycles", outputs_received, cycles);
        end
    end
endtask

// Debug monitoring
always @(posedge tb_clk) begin
    if (sa_interface.sa_out_valid)
        $display("[%0t] sa_out_valid=1", $time);
end

// Test Stimulus
initial begin
    $dumpfile("waves/systolic_array_simple_waves.vcd");
    $dumpvars(0, systolic_array_simple_tb);
    
    sa_interface.sa_array_in = '0;
    sa_interface.sa_array_in_partials = '0;
    sa_interface.sa_input_en = '0;
    sa_interface.sa_weight_en = '0;
    sa_interface.sa_partial_en = '0;
    sa_interface.sa_output_ready = '0;
    loaded_weights = 0;
    test_pass_count = 0;
    test_fail_count = 0;
    total_comparisons = 0;
    
    file = $fopen(input_filename, "r");
    if (file == 0) begin
        $display("ERROR: Could not open input file: %s", input_filename);
        $finish;
    end
    $system(python_command);
    out_file = $fopen(python_output_filename, "r");
    if (out_file == 0) begin
        $display("ERROR: Could not open output file: %s", python_output_filename);
        $finish;
    end
    sysarr_dump_file = $fopen(output_filename, "w");
    
    reset();
    
    $display("========================================");
    $display("TEST 1: Matrix multiply");
    $display("========================================");
    get_matrices(.weights(loaded_weights));
    get_m_output();
    
    if (loaded_weights == 1) begin
        load_weights();
    end
    
    load_inputs_streaming(.delay(0));
    wait_for_outputs();
    
    $display("Test 1 complete");
    
    $fclose(file);
    $fclose(out_file);
    $fclose(sysarr_dump_file);
    
    $display("========================================");
    $display("TEST SUMMARY");
    $display("========================================");
    $display("Total comparisons: %0d", total_comparisons);
    $display("Passed: %0d", test_pass_count);
    $display("Failed: %0d", test_fail_count);
    if (test_fail_count == 0)
        $display(">>> ALL TESTS PASSED <<<");
    else
        $display(">>> SOME TESTS FAILED <<<");
    $display("========================================");
    
    #50;
    $finish;
end

endmodule
