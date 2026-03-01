`include "exp_if.sv"
`include "vector_types.vh"
`timescale 1 ns / 1 ns

module exponential_unit_tb;
    import vector_pkg::*;
    
    localparam MULT_LATENCY = 2;
    localparam int MAX_ULP_TOL = 1;

    // Signals
    logic clk, rst_n;

    // Interface instantiation
    exp_if ex_if();
    
    // Instantiate DUT
    exponential_unit dut (
        .clk(clk),
        .rst_n(rst_n),
        .ex_if(ex_if.exif)
    );

    // Clock
    initial clk = 0;
    always #5 clk = ~clk;

    integer input_file, output_file;
    string line;
    logic [15:0] input_val, expected_val, output_val;
    integer ulp_error;
    integer test_count;
    integer pass_count, fail_count;
    integer total_abs_ulp, max_abs_ulp;

    string input_str, expected_str;
    integer comma_pos;
    real avg_ulp;

    function integer calc_ulp(input logic [15:0] expected, input logic [15:0] actual);
        integer exp_int, act_int;
        exp_int = signed'({1'b0, expected});
        act_int = signed'({1'b0, actual});
        return act_int - exp_int;
    endfunction

    function logic [15:0] parse_hex(input string hex_str);
        string trimmed;
        logic [15:0] result;
        
        if (hex_str.len() > 2 && (hex_str.substr(0, 1) == "0x" || hex_str.substr(0, 1) == "0X")) begin
            trimmed = hex_str.substr(2, hex_str.len()-1);
        end else begin
            trimmed = hex_str;
        end
        
        result = trimmed.atohex();
        return result;
    endfunction
    
    initial begin
        rst_n = 0;
        ex_if.in.operand = 16'd0;
        ex_if.in.valid_in = 0;
        ex_if.in.ready_out = 1;
        test_count = 0;
        pass_count = 0;
        fail_count = 0;
        total_abs_ulp = 0;
        max_abs_ulp = 0;

        #12 rst_n = 1;

        // Open input CSV file
        input_file = $fopen("bf16_exp_full_sweep.csv", "r");
        if (input_file == 0) begin
            $display("ERROR: Could not open bf16_exp_full_sweep.csv!");
            $finish;
        end

        // Open output CSV file
        output_file = $fopen("exp_bf16_test_results.csv", "w");
        if (output_file == 0) begin
            $display("ERROR: Could not create output file!");
            $fclose(input_file);
            $finish;
        end
        
        // Write CSV header
        $fwrite(output_file, "Input,Expected,Output,ULP\n");

        // Skip header line
        if ($fgets(line, input_file) == 0) begin
            $display("ERROR: Could not read header from input file!");
            $fclose(input_file);
            $fclose(output_file);
            $finish;
        end

        $display("\n=== Starting BF16 Full Sweep Exponential Unit Tests ===\n");

        // Main loop
        while (!$feof(input_file)) begin
            // Reset temporary variables each iteration
            input_str = "";
            expected_str = "";
            comma_pos = 0;
            
            // Read line
            if ($fgets(line, input_file) == 0) break;
            if (line.len() == 0) continue;

            // Find comma
            for (int i = 0; i < line.len(); i++) begin
                if (line[i] == ",") begin
                    comma_pos = i;
                    break;
                end
            end
            if (comma_pos == 0) continue;

            input_str = line.substr(0, comma_pos-1);
            expected_str = line.substr(comma_pos+1, line.len()-1);
            
            input_val = parse_hex(input_str);
            expected_val = parse_hex(expected_str);
            
            // Wait for ready_input
            while (!ex_if.out.ready_in) @(posedge clk);
            
            @(posedge clk);
            ex_if.in.operand = input_val;
            ex_if.in.valid_in = 1;
            @(posedge clk);
            ex_if.in.valid_in = 0;
            
            // Wait for valid output
            while (!ex_if.out.valid_out) @(posedge clk);            
            output_val = ex_if.out.result;
            ulp_error = calc_ulp(expected_val, output_val);

            // ULP tracking
            total_abs_ulp += (ulp_error < 0) ? -ulp_error : ulp_error;
            if ((ulp_error < 0 ? -ulp_error : ulp_error) > max_abs_ulp)
                max_abs_ulp = (ulp_error < 0) ? -ulp_error : ulp_error;

            // Log CSV
            $fwrite(output_file, "0x%04h,0x%04h,0x%04h,%0d\n",
                    input_val, expected_val, output_val, ulp_error);
            
            test_count++;
            if ((ulp_error >= -MAX_ULP_TOL) && (ulp_error <= MAX_ULP_TOL)) begin
                pass_count++;
            end else begin
                fail_count++;
                $display("MISMATCH: Input=0x%04h, Expected=0x%04h, Got=0x%04h, ULP=%0d",
                         input_val, expected_val, output_val, ulp_error);
            end
        end

        repeat (10) @(posedge clk);

        $fclose(input_file);
        $fclose(output_file);

        $display("\n=== BF16 Exponential Unit Test Results ===");
        $display("Total tests: %0d", test_count);
        $display("Passed: %0d", pass_count);
        $display("Failed: %0d", fail_count);
        $display("=====================================\n");
        
        $finish;
    end

endmodule