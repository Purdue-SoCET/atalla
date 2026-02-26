`timescale 1ns/1ps

module mul_fp16_VC_tb_full;

    logic clk, nRST, start;
    logic [15:0] a, b;
    logic [15:0] result_vc;
    logic done;

    // DUT - 3-cycle pipelined
    mul_fp16_VC dut (
        .clk(clk),
        .nRST(nRST),
        .start(start),
        .stall(1'b0),
        .a(a),
        .b(b),
        .result(result_vc),
        .done(done)
    );

    // Clock generation
    initial clk = 0;
    always #5 clk = ~clk;

    // Test data storage - circular buffer for pipeline
    logic [15:0] expected_queue [0:7];
    logic [15:0] a_queue [0:7];
    logic [15:0] b_queue [0:7];
    int wr_ptr, rd_ptr;
    int pass_count, fail_count;
    int test_count;

    // File handling
    int fd;
    string line;
    logic [15:0] file_a, file_b, file_expected;
    int scan_result;

    initial begin
        nRST = 0;
        start = 0;
        a = 0;
        b = 0;
        wr_ptr = 0;
        rd_ptr = 0;
        pass_count = 0;
        fail_count = 0;
        test_count = 0;

        // Reset
        repeat(3) @(posedge clk);
        nRST = 1;
        @(posedge clk);

        // Open CSV file
        fd = $fopen("random_mul_cases.csv", "r");
        if (fd == 0) begin
            $display("ERROR: Could not open random_mul_cases.csv");
            $finish;
        end

        // Skip header line
        scan_result = $fgets(line, fd);

        // Read and test all cases
        while (!$feof(fd)) begin
            scan_result = $fscanf(fd, "%h,%h,%h\n", file_a, file_b, file_expected);
            if (scan_result == 3) begin
                // Apply test
                @(posedge clk);
                a = file_a;
                b = file_b;
                start = 1;
                
                // Store expected result in queue
                expected_queue[wr_ptr % 8] = file_expected;
                a_queue[wr_ptr % 8] = file_a;
                b_queue[wr_ptr % 8] = file_b;
                wr_ptr++;
                test_count++;

                @(posedge clk);
                start = 0;

                // Progress indicator
                if (test_count % 50000 == 0) begin
                    $display("Progress: %0d tests, %0d passed, %0d failed", test_count, pass_count, fail_count);
                end
            end
        end

        $fclose(fd);

        // Wait for pipeline to drain
        repeat(10) @(posedge clk);

        // Final results
        $display("\n========================================");
        $display("Test Results: %0d passed, %0d failed out of %0d", pass_count, fail_count, test_count);
        $display("========================================\n");
        
        if (fail_count == 0)
            $display("ALL TESTS PASSED!");
        else
            $display("SOME TESTS FAILED!");

        $finish;
    end

    // Check results when done asserts (3 cycles after start)
    always @(posedge clk) begin
        if (done && nRST && rd_ptr < wr_ptr) begin
            if ((result_vc === expected_queue[rd_ptr % 8]) ||
                ((result_vc[14:0] == 15'b0) && (expected_queue[rd_ptr % 8][14:0] == 15'b0))) begin
                pass_count++;
            end
            else begin
                if (fail_count < 20) begin  // Only print first 20 failures
                    $display("FAIL: %h * %h = %h (expected %h)", 
                        a_queue[rd_ptr % 8], b_queue[rd_ptr % 8], 
                        result_vc, expected_queue[rd_ptr % 8]);
                end
                fail_count++;
            end
            rd_ptr++;
        end
    end

endmodule
