// Nikhil Vaidyanath - nvaidyan@purdue.edu
// Testbench for Shifting Unit
// Tests all 64 shift types (32 left + 32 right shifts)

`timescale 1ns/1ps

`include "vector_pkg.sv"
`include "shifting_unit_if.sv"
`include "shifting_unit_pkg.sv"

module shifting_unit_tb;
    import vector_pkg::*;
    import shifting_unit_pkg::*;

    // Clock and Reset
    logic clk;
    logic n_rst;

    // Interface instantiation
    shifting_unit_if sh_if();

    // DUT instantiation
    shifting_unit dut (
        .clk(clk),
        .n_rst(n_rst),
        .sh_unit(sh_if)
    );

    // Clock generation (10ns period = 100MHz)
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // Test variables
    int test_count;
    int pass_count;
    int fail_count;
    string test_name;
    int rand_shift;
    int rand_dir_bit;

    // Test input vector - populate with incrementing values for easy verification
    vreg_t test_vector;
    vreg_t expected_output;
    vreg_t actual_output;

    logic valid_now;

    // Initialize test vector with sequential values [0, 1, 2, ..., 31]
    initial begin
        for (int i = 0; i < NUM_ELEMENTS; i++) begin
            test_vector[i] = i;  // Each element contains its index
        end
    end

    // Task: Reset DUT
    task reset_dut();
        begin
            n_rst = 0;
            sh_if.veg_vdata = '0;
            sh_if.direction = LEFT;
            sh_if.shift_amount = '0;
            sh_if.valid_in = 0;
            sh_if.ready_in = 0;
            @(posedge clk);
            @(posedge clk);
            n_rst = 1;
            @(posedge clk);
        end
    endtask

    // Task: Compute expected output for a shift operation
    task compute_expected(
        input shift_direction_t direction,  // Imported from vector_pkg
        input logic [$clog2(NUM_ELEMENTS)-1:0] shift_amt,
        input vreg_t input_vec,
        output vreg_t expected_vec
    );
        begin
            // Initialize all elements to zero
            for (int i = 0; i < NUM_ELEMENTS; i++) begin
                expected_vec[i] = '0;
            end

            if (direction == LEFT) begin
                // Left shift: element at index i comes from index (i - shift_amt)
                for (int i = 0; i < NUM_ELEMENTS; i++) begin
                    if (i >= shift_amt) begin
                        expected_vec[i] = input_vec[i - shift_amt];
                    end else begin
                        expected_vec[i] = '0;  // Zero fill
                    end
                end
            end else begin // RIGHT shift
                // Right shift: element at index i comes from index (i + shift_amt)
                for (int i = 0; i < NUM_ELEMENTS; i++) begin
                    if ((i + shift_amt) < NUM_ELEMENTS) begin
                        expected_vec[i] = input_vec[i + shift_amt];
                    end else begin
                        expected_vec[i] = '0;  // Zero fill
                    end
                end
            end
        end
    endtask

    // Task: Apply shift operation and check result
    task test_shift(
        input shift_direction_t direction,  // Imported from vector_pkg
        input logic [$clog2(NUM_ELEMENTS)-1:0] shift_amt,
        input string dir_name
    );
        begin
            test_count++;
            test_name = $sformatf("%s shift by %0d", dir_name, shift_amt);
            
            // Apply inputs
            sh_if.veg_vdata = test_vector;
            sh_if.direction = direction;
            sh_if.shift_amount = shift_amt;
            sh_if.valid_in = 1;
            sh_if.ready_in = 1;

            // Compute expected output
            compute_expected(direction, shift_amt, test_vector, expected_output);

            // Wait for one clock cycle to latch inputs
            @(posedge clk);
            sh_if.valid_in = 0;
            
            // Wait for ROM and Benes network to process (remaining cycles)
            @(posedge sh_if.valid_out);
            #1;

            // Capture actual output
            actual_output = sh_if.shifted_vdata;

            // Check result
            if (actual_output === expected_output) begin
                $display("[PASS] Test %0d: %s", test_count, test_name);
                pass_count++;
            end else begin
                $display("[FAIL] Test %0d: %s", test_count, test_name);
                $display("       Expected: %p", expected_output);
                $display("       Got:      %p", actual_output);
                
                // Show which elements differ
                for (int i = 0; i < NUM_ELEMENTS; i++) begin
                    if (actual_output[i] !== expected_output[i]) begin
                        $display("       Element[%0d]: Expected=%h, Got=%h", 
                                 i, expected_output[i], actual_output[i]);
                    end
                end
                fail_count++;
            end

            // Deassert valid (already done)
            @(posedge clk);
        end
    endtask

    // Task: Test random backpressure
    task test_random_backpressure(input int iterations);
        int stall_cycles;
        begin
            $display("\n--- Testing RANDOM shifts with BACKPRESSURE (%0d iterations) ---", iterations);
            
            for (int k = 0; k < iterations; k++) begin
                test_count++;
                
                // Randomize inputs
                for (int i = 0; i < NUM_ELEMENTS; i++) begin
                    test_vector[i] = $urandom();
                end
                rand_shift = $urandom_range(0, NUM_ELEMENTS-1);
                rand_dir_bit = $urandom_range(0, 1);
                
                if (rand_dir_bit) begin
                    test_name = $sformatf("RANDOM RIGHT %0d (Backpressure)", rand_shift);
                    sh_if.direction = RIGHT;
                end else begin
                    test_name = $sformatf("RANDOM LEFT %0d (Backpressure)", rand_shift);
                    sh_if.direction = LEFT;
                end
                sh_if.shift_amount = rand_shift;
                sh_if.veg_vdata = test_vector;
                sh_if.valid_in = 1;
                
                // Initially ready
                sh_if.ready_in = 1;
                
                // Compute expected
                compute_expected(sh_if.direction, sh_if.shift_amount, test_vector, expected_output);
                
                // Wait one clock edge to let data enter pipeline
                @(posedge clk);
                sh_if.valid_in = 0;
                // Randomly decide to wait one additional cycle (50% chance)
                if ($urandom_range(0,1) == 1) begin
                    @(posedge clk);
                end
                
                // Apply backpressure
                sh_if.ready_in = 0;
                stall_cycles = $urandom_range(1, 5);
                
                // Verify ready_out goes low immediately (combinatorial)
                #1; 
                if (sh_if.ready_out == 1) begin
                    $error("[FAIL] Backpressure propagation failed! ready_in=0 but ready_out=1");
                    fail_count++;
                end
                
                // Hold for random cycles
                repeat(stall_cycles) @(posedge clk);
                
                // Release backpressure
                sh_if.ready_in = 1;
                #1;
                if (sh_if.valid_out) begin
                    valid_now = 1;
                    actual_output = sh_if.shifted_vdata;
                end

                // Wait for processing
                @(posedge clk);
                if (valid_now) begin
                    sh_if.ready_in = 0;  // pulsing only for one clock cycle
                end
                #1;
                
                // Capture and check
                if (!valid_now) begin
                    wait (sh_if.valid_out == 1);
                    actual_output = sh_if.shifted_vdata;
                    @(posedge clk);
                    sh_if.ready_in = 0;
                end else begin
                    valid_now = 0;
                end
                
                
                if (actual_output === expected_output) begin
                    $display("[PASS] Test %0d: %s (Stalled %0d cycles)", test_count, test_name, stall_cycles);
                    pass_count++;
                end else begin
                    $display("[FAIL] Test %0d: %s", test_count, test_name);
                    $display("       Expected: %p", expected_output);
                    $display("       Got:      %p", actual_output);
                    fail_count++;
                end
                
                // Deassert valid for next iteration (already done)
                @(posedge clk);
            end
        end
    endtask

    // Assertion: Check for valid shift amounts
    property valid_shift_amount;
        @(posedge clk) disable iff (!n_rst)
        sh_if.valid_in |-> 
            (sh_if.shift_amount < NUM_ELEMENTS);
    endproperty
    assert_valid_shift_amount: assert property(valid_shift_amount)
        else $error("Shift amount exceeds NUM_ELEMENTS!");

    // Main test sequence
    initial begin
        $display("========================================");
        $display("  Shifting Unit Testbench");
        $display("  Testing %0d shift operations", NUM_ELEMENTS * 2);
        $display("========================================");

        // Initialize counters
        test_count = 0;
        pass_count = 0;
        fail_count = 0;

        // Reset DUT
        reset_dut();

        $display("\n[INFO] Input test vector: %p", test_vector);
        $display("\n--- Testing LEFT shifts (0 to %0d) ---", NUM_ELEMENTS-1);
        
        // Test all left shift amounts (0 to NUM_ELEMENTS-1)
        for (int shift_amt = 0; shift_amt < NUM_ELEMENTS; shift_amt++) begin
            test_shift(LEFT, shift_amt, "LEFT");
        end

        $display("\n--- Testing RIGHT shifts (0 to %0d) ---", NUM_ELEMENTS-1);
        
        // Test all right shift amounts (0 to NUM_ELEMENTS-1)
        for (int shift_amt = 0; shift_amt < NUM_ELEMENTS; shift_amt++) begin
            test_shift(RIGHT, shift_amt, "RIGHT");
        end

        $display("\n--- Testing RANDOM shifts (10 iterations) ---");
        for (int k = 0; k < 10; k++) begin
            // Randomize input vector
            for (int i = 0; i < NUM_ELEMENTS; i++) begin
                test_vector[i] = $urandom();
            end
            
            // Randomize shift amount and direction
            rand_shift = $urandom_range(0, NUM_ELEMENTS-1);
            rand_dir_bit = $urandom_range(0, 1);
            
            if (rand_dir_bit) begin
                test_shift(RIGHT, rand_shift, "RANDOM RIGHT");
            end else begin
                test_shift(LEFT, rand_shift, "RANDOM LEFT");
            end
        end

        // Test backpressure
        test_random_backpressure(10);

        // Test summary
        $display("\n========================================");
        $display("  Test Summary");
        $display("========================================");
        $display("  Total Tests: %0d", test_count);
        $display("  Passed:      %0d", pass_count);
        $display("  Failed:      %0d", fail_count);
        $display("========================================");

        if (fail_count == 0) begin
            $display("[SUCCESS] All tests passed!");
        end else begin
            $display("[FAILURE] %0d test(s) failed!", fail_count);
        end

        // End simulation
        $display("\nSimulation complete at time %0t", $time);
        $finish;
    end

    // Timeout watchdog (prevents infinite simulation)
    initial begin
        #100000; // 100us timeout
        $display("\n[ERROR] Simulation timeout!");
        $finish;
    end

endmodule
