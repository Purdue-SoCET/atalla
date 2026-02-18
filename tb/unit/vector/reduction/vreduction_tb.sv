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

    // NEW variables for Test 7
    logic [31:0][15:0] expected_hold_output;
    logic [31:0][15:0] observed_output;


    // Helper function: ULP comparison
    function automatic logic within_ulp(logic [15:0] a, logic [15:0] b);
        logic signed [16:0] a_int, b_int;
        logic signed [16:0] diff;

        if (a === b) return 1;
        if ((a[14:7] == 8'hFF && a[6:0] != 0) ||
            (b[14:7] == 8'hFF && b[6:0] != 0))
            return (a === b);

        if (a[15]) a_int = $signed({1'b0, ~a});
        else       a_int = $signed({1'b0, a ^ 16'h8000});

        if (b[15]) b_int = $signed({1'b0, ~b});
        else       b_int = $signed({1'b0, b ^ 16'h8000});

        diff = a_int - b_int;
        if (diff < 0) diff = -diff;

        return (diff <= 8);
    endfunction


    // Helper function: string → enum
    function reduction_pkg::reduction_op str_to_reduction_type(string s);
        case (s)
            "sum": return reduction_pkg::SUM;
            "min": return reduction_pkg::MIN;
            "max": return reduction_pkg::MAX;
            default: begin
                $error("Unknown type: %s", s);
                return reduction_pkg::SUM;
            end
        endcase
    endfunction


    // Read one test vector
    task automatic read_test_vector();
        string line;
        int status;

        status = $fgets(line, input_file);
        if (status == 0) return;

        status = $sscanf(line,
            "%h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %b %b %b %s",
            input_vectors[0], input_vectors[1], input_vectors[2], input_vectors[3],
            input_vectors[4], input_vectors[5], input_vectors[6], input_vectors[7],
            input_vectors[8], input_vectors[9], input_vectors[10], input_vectors[11],
            input_vectors[12], input_vectors[13], input_vectors[14], input_vectors[15],
            input_vectors[16], input_vectors[17], input_vectors[18], input_vectors[19],
            input_vectors[20], input_vectors[21], input_vectors[22], input_vectors[23],
            input_vectors[24], input_vectors[25], input_vectors[26], input_vectors[27],
            input_vectors[28], input_vectors[29], input_vectors[30], input_vectors[31],
            imm, clear, broadcast, reduction_type_str
        );


        if (status != 36)
            $error("Failed to parse input line, got %0d fields", status);

        reduction_type = str_to_reduction_type(reduction_type_str);

        status = $fgets(line, expected_file);
        if (status == 0) $error("Expected file ended early");

        status = $sscanf(line,
            "%h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h %h",
            expected_vectors[0], expected_vectors[1], expected_vectors[2], expected_vectors[3],
            expected_vectors[4], expected_vectors[5], expected_vectors[6], expected_vectors[7],
            expected_vectors[8], expected_vectors[9], expected_vectors[10], expected_vectors[11],
            expected_vectors[12], expected_vectors[13], expected_vectors[14], expected_vectors[15],
            expected_vectors[16], expected_vectors[17], expected_vectors[18], expected_vectors[19],
            expected_vectors[20], expected_vectors[21], expected_vectors[22], expected_vectors[23],
            expected_vectors[24], expected_vectors[25], expected_vectors[26], expected_vectors[27],
            expected_vectors[28], expected_vectors[29], expected_vectors[30], expected_vectors[31]
        );


        if (status != 32)
            $error("Failed to parse expected line, got %0d fields", status);
    endtask


    // Run one BF16 test
    task automatic run_test();
        logic mismatch = 0;
        logic [31:0][15:0] vec_input_packed;
        logic [15:0][15:0] lane_input_packed;
        logic [31:0][15:0] vec_output_packed;

        test_count++;

        for (int i = 0; i < 32; i++)
            vec_input_packed[i] = input_vectors[i];

        for (int i = 0; i < 16; i++)
            lane_input_packed[i] = input_vectors[i];

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

        wait (vruif.out.valid_out);

        vec_output_packed = vruif.out.vector_output;

        for (int i = 0; i < 32; i++) begin
            if (!within_ulp(vec_output_packed[i], expected_vectors[i])) begin
                mismatch = 1;
                $fdisplay(output_file,
                    "FAIL: Test %0d Lane %0d expected %h got %h",
                    test_count, i,
                    expected_vectors[i], vec_output_packed[i]
                );
            end
        end

        if (mismatch) begin
            fail_count++;
            $fdisplay(output_file,
                "Test %0d FAILED (type=%s imm=%0d clr=%b bc=%b)",
                test_count, reduction_type_str, imm, clear, broadcast
            );
        end else begin
            pass_count++;
            $fdisplay(output_file,
                "Test %0d PASSED",
                test_count
            );
        end

        repeat (2) @(posedge CLK);
    endtask



    // ============================================
    // Ready/Valid Handshake Tests
    // ============================================
    task automatic run_ready_valid_tests();

        logic [31:0][15:0] test_vec;
        logic [15:0][15:0] test_lane;

        for (int i = 0; i < 32; i++) test_vec[i] = 16'h3f80;
        for (int i = 0; i < 16; i++) test_lane[i] = 16'h3f80;

        $fdisplay(output_file, "\n================================");
        $fdisplay(output_file, " Ready/Valid Handshake Tests");
        $fdisplay(output_file, "================================");

        // ---- Test 1 ----
        $fdisplay(output_file, "Test 1: Simple handshake");

        vruif.in.valid_in = 1;
        vruif.in.ready_out = 1;

        @(posedge CLK);
        vruif.in.valid_in = 0;

        wait(vruif.out.valid_out);
        @(posedge CLK);

        // ---- Test 7: valid_out HOLD ----
        $fdisplay(output_file, "\nTest 7: valid_out HOLD test");

        // 1. Feed a transaction
        vruif.in.valid_in = 1;
        vruif.in.ready_out = 1;
        vruif.in.vector_input = test_vec;
        vruif.in.lane_input = test_lane;

        @(posedge CLK);
        vruif.in.valid_in = 0;

        // 2. Wait for valid_out
        wait(vruif.out.valid_out);

        expected_hold_output = vruif.out.vector_output;

        // 3. Stall output
        vruif.in.ready_out = 0;

        repeat (5) begin
            @(posedge CLK);

            if (!vruif.out.valid_out)
                $fdisplay(output_file, "  FAIL: valid_out dropped during stall");

            if (vruif.out.vector_output !== expected_hold_output)
                $fdisplay(output_file, "  FAIL: vector_output changed during stall");
        end

        // 4. Release stall
        vruif.in.ready_out = 1;
        @(posedge CLK);

        if (!vruif.out.valid_out)
            $fdisplay(output_file, "  PASSED: valid_out held through stall");
        else begin
            @(posedge CLK);
            if (!vruif.out.valid_out)
                $fdisplay(output_file, "  PASSED: valid_out dropped after handshake");
            else
                $fdisplay(output_file, "  FAIL: valid_out did not drop after handshake");
        end

        $fdisplay(output_file, "\nReady/Valid Tests Complete");
        $fdisplay(output_file, "================================");
    endtask




    // ============================================
    // Main initial block
    // ============================================
    initial begin
        input_file    = $fopen("inputs.txt", "r");
        expected_file = $fopen("expected.txt", "r");
        output_file   = $fopen("test_results.txt", "w");

        if (!input_file)    $fatal("Could not open inputs.txt");
        if (!expected_file) $fatal("Could not open expected.txt");
        if (!output_file)   $fatal("Could not open test_results.txt");

        vruif.in.valid_in  = 0;
        vruif.in.ready_out = 1;
        vruif.in.clear     = 0;
        vruif.in.broadcast = 0;
        vruif.in.imm       = 0;
        vruif.in.reduction_type = reduction_pkg::SUM;

        vector_initialize: for (int i=0; i<32; i++)
            vruif.in.vector_input[i] = 16'h0000;

        // Reset
        nRST = 0;
        repeat(4) @(posedge CLK);
        nRST = 1;
        repeat(2) @(posedge CLK);

        $fdisplay(output_file, "Starting Tests");

        // BF16 tests
        while (!$feof(input_file)) begin
            read_test_vector();
            if (!$feof(input_file))
                run_test();
        end

        // Handshake tests
        run_ready_valid_tests();

        $fdisplay(output_file, "\nSummary: total=%0d pass=%0d fail=%0d",
            test_count, pass_count, fail_count);

        $finish;
    end

endmodule