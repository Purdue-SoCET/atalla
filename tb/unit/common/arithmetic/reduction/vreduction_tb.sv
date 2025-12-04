`timescale 1ns/1ps

`include "vreduction_if.vh"
`include "vreduction_alu_if.vh"
`include "reduction_types.vh"

module vreduction_tb;

    // Clock + reset
    logic CLK = 0;
    logic nRST = 0;

    // Instantiate interface
    vreduction_if vruif();

    // Instantiate DUT
    vreduction #(
        .LANES(16)
    ) dut (
        .CLK(CLK),
        .nRST(nRST),
        .vruif(vruif)
    );

    // Clock gen
    always #5 CLK = ~CLK;   // 100 MHz

    // Test vectors
    logic [15:0] input_vectors [0:31];
    logic [15:0] expected_vectors [0:31];
    logic [4:0] imm;
    logic clear;
    logic broadcast;
    string reduction_type_str;
    reduction_pkg::reduction_op reduction_type;
    
    // Test tracking
    int test_count = 0;
    int pass_count = 0;
    int fail_count = 0;
    
    // File handles
    int input_file;
    int expected_file;
    int output_file;
    
    // Helper function to convert string to reduction type
    function reduction_pkg::reduction_op str_to_reduction_type(string s);
        case (s)
            "sum": return reduction_pkg::VR_SUM;  // 2'b10
            "min": return reduction_pkg::VR_MIN;  // 2'b01
            "max": return reduction_pkg::VR_MAX;  // 2'b00
            default: begin
                $error("Unknown reduction type: %s", s);
                return reduction_pkg::VR_SUM;
            end
        endcase
    endfunction
    
    // Task to read one test vector
    task automatic read_test_vector();
        string line;
        int status;
        
        // Read input line
        status = $fgets(line, input_file);
        if (status == 0) return;
        
        // Parse 32 BF16 hex values, imm (5 bits), clear, broadcast, reduction_type
        status = $sscanf(line, "%h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %b %b %b %s",
            input_vectors[0], input_vectors[1], input_vectors[2], input_vectors[3],
            input_vectors[4], input_vectors[5], input_vectors[6], input_vectors[7],
            input_vectors[8], input_vectors[9], input_vectors[10], input_vectors[11],
            input_vectors[12], input_vectors[13], input_vectors[14], input_vectors[15],
            input_vectors[16], input_vectors[17], input_vectors[18], input_vectors[19],
            input_vectors[20], input_vectors[21], input_vectors[22], input_vectors[23],
            input_vectors[24], input_vectors[25], input_vectors[26], input_vectors[27],
            input_vectors[28], input_vectors[29], input_vectors[30], input_vectors[31],
            imm, clear, broadcast, reduction_type_str);
        
        if (status != 36) begin
            $error("Failed to parse input line, got %0d fields", status);
        end
        
        reduction_type = str_to_reduction_type(reduction_type_str);
        
        // Read expected line
        status = $fgets(line, expected_file);
        if (status == 0) begin
            $error("Expected file ended prematurely");
            return;
        end
        
        status = $sscanf(line, "%h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h",
            expected_vectors[0], expected_vectors[1], expected_vectors[2], expected_vectors[3],
            expected_vectors[4], expected_vectors[5], expected_vectors[6], expected_vectors[7],
            expected_vectors[8], expected_vectors[9], expected_vectors[10], expected_vectors[11],
            expected_vectors[12], expected_vectors[13], expected_vectors[14], expected_vectors[15],
            expected_vectors[16], expected_vectors[17], expected_vectors[18], expected_vectors[19],
            expected_vectors[20], expected_vectors[21], expected_vectors[22], expected_vectors[23],
            expected_vectors[24], expected_vectors[25], expected_vectors[26], expected_vectors[27],
            expected_vectors[28], expected_vectors[29], expected_vectors[30], expected_vectors[31]);
        
        if (status != 32) begin
            $error("Failed to parse expected line, got %0d fields", status);
        end
    endtask
    
    // Task to run one test
    task automatic run_test();
        logic mismatch;
        logic [31:0][15:0] vec_input_packed;
        logic [15:0][15:0] lane_input_packed;
        logic [31:0][15:0] vec_output_packed;
        int i;
        
        test_count++;
        mismatch = 0;
        
        // Convert unpacked to packed array for vector input
        for (i = 0; i < 32; i++) begin
            vec_input_packed[i] = input_vectors[i];
        end
        
        // Convert first 16 elements to lane input
        for (i = 0; i < 16; i++) begin
            lane_input_packed[i] = input_vectors[i];
        end
        
        // Apply inputs
        vruif.in.valid_in = 0;
        vruif.in.clear = clear;
        vruif.in.broadcast = broadcast;
        vruif.in.imm = imm;
        vruif.in.reduction_type = reduction_type;
        vruif.in.vector_input = vec_input_packed;
        vruif.in.lane_input = lane_input_packed;
        
        @(posedge CLK);
        vruif.in.valid_in = 1;
        
        @(posedge CLK);
        vruif.in.valid_in = 0;
        
        // Wait for valid_out
        wait (vruif.out.valid_out == 1);
        
        // Get output as packed array
        vec_output_packed = vruif.out.vector_output;
        
        // Check output
        for (i = 0; i < 32; i++) begin
            if (vec_output_packed[i] !== expected_vectors[i]) begin
                mismatch = 1;
                $fdisplay(output_file, "FAIL: Test %0d, Lane %0d: Expected %h, Got %h", 
                    test_count, i, expected_vectors[i], vec_output_packed[i]);
            end
        end
        
        if (mismatch) begin
            fail_count++;
            $fdisplay(output_file, "Test %0d: FAILED (type=%s, imm=%0d, clear=%b, broadcast=%b)", 
                test_count, reduction_type_str, imm, clear, broadcast);
        end else begin
            pass_count++;
            $fdisplay(output_file, "Test %0d: PASSED (type=%s, imm=%0d, clear=%b, broadcast=%b)", 
                test_count, reduction_type_str, imm, clear, broadcast);
        end
        
        // Wait a bit before next test
        repeat(2) @(posedge CLK);
    endtask

    initial begin
        // Open files
        input_file = $fopen("inputs.txt", "r");
        if (input_file == 0) begin
            $fatal("Could not open inputs.txt");
        end
        
        expected_file = $fopen("expected.txt", "r");
        if (expected_file == 0) begin
            $fatal("Could not open expected.txt");
        end
        
        output_file = $fopen("test_results.txt", "w");
        if (output_file == 0) begin
            $fatal("Could not open test_results.txt");
        end
        
        // Initialize interface
        vruif.in.valid_in   = 0;
        vruif.in.ready_out  = 1;
        vruif.in.clear      = 0;
        vruif.in.broadcast  = 0;
        vruif.in.imm        = 0;
        vruif.in.reduction_type = reduction_pkg::VR_SUM;
        vruif.in.vector_input = '{default:16'h0000};

        // Reset sequence
        nRST = 0;
        repeat(4) @(posedge CLK);
        nRST = 1;
        repeat(2) @(posedge CLK);
        
        $fdisplay(output_file, "Starting BF16 Reduction Tests");
        $fdisplay(output_file, "================================");
        
        // Run all tests
        while (!$feof(input_file)) begin
            read_test_vector();
            if (!$feof(input_file)) begin
                run_test();
            end
        end
        
        // Print summary
        $fdisplay(output_file, "================================");
        $fdisplay(output_file, "Test Summary:");
        $fdisplay(output_file, "  Total:  %0d", test_count);
        $fdisplay(output_file, "  Passed: %0d", pass_count);
        $fdisplay(output_file, "  Failed: %0d", fail_count);
        
        $display("================================");
        $display("Test Summary:");
        $display("  Total:  %0d", test_count);
        $display("  Passed: %0d", pass_count);
        $display("  Failed: %0d", fail_count);
        $display("Results written to test_results.txt");
        
        // Close files
        $fclose(input_file);
        $fclose(expected_file);
        $fclose(output_file);
        
        $finish;
    end

endmodule