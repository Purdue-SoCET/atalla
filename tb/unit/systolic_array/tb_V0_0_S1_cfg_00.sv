`timescale 1ns/1ps

module tb_V0_0_S1_cfg_00;

    // --- Parameters ---
    localparam int WIDTH = 24;
    localparam int EXT_WIDTH = WIDTH + 5; // 29 bits

    // --- Signals ---
    logic clk;
    logic nRST;
    
    // Declared as signed so SV automatically handles the two's complement 
    // math correctly in our verification model
    logic signed [WIDTH-1:0]     in [0:31];
    logic signed [EXT_WIDTH-1:0] out_sum;
    logic signed [EXT_WIDTH-1:0] expected_sum;

    // --- DUT Instantiation ---
    V0_0_S1_cfg_00 #(
        .WIDTH(WIDTH)
    ) dut (
        .clk(clk),
        .nRST(nRST),
        .in(in),
        .out_sum(out_sum)
    );

    // --- Clock Generation ---
    // (DUT is purely combinational, but standard practice to drive it)
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // --- Self-Checking Verification Model ---
    // Continuously calculates the expected result
    always_comb begin
        expected_sum = 0;
        for (int i = 0; i < 32; i++) begin
            // Because 'in' is declared signed and 'expected_sum' is EXT_WIDTH,
            // SV automatically sign-extends 'in[i]' to 29 bits before adding.
            expected_sum = expected_sum + in[i];
        end
    end

    // --- Checker Task ---
    task check_result(input string test_name);
        #1; // Wait 1ns for combinational logic to settle
        if (out_sum !== expected_sum) begin
            $error("FAIL [%s]: Expected %0d, Got %0d", test_name, expected_sum, out_sum);
        end 
        else begin
            $display("PASS [%s]: Sum = %0d", test_name, out_sum);
        end
    endtask

    // --- Stimulus ---
    initial begin
        // 1. Initialize
        nRST = 0;
        for (int i = 0; i < 32; i++) in[i] = 0;
        #15;
        nRST = 1;
        #10;

        $display("==================================================");
        $display("   STARTING TESTBENCH: 32-way Adder (24-bit)");
        $display("==================================================");

        // --------------------------------------------------------
        // TEST 1: Random Signed Addition
        // --------------------------------------------------------
        $display("\n--- Running Random Signed Addition Tests ---");
        for (int test_idx = 0; test_idx < 100000; test_idx++) begin
            for (int i = 0; i < 32; i++) begin
                // $random generates a 32-bit signed integer. 
                // Assigning it truncates it to 24 bits while maintaining signedness.
                in[i] = $random;
            end
            check_result($sformatf("Random Test %0d", test_idx));
            #9; 
        end

        // --------------------------------------------------------
        // TEST 2: Overflow Protection
        // Adding 32 elements requires exactly log2(32) = 5 extra bits.
        // We verify this by feeding it 32 maximum possible values.
        // --------------------------------------------------------
        $display("\n--- Running Overflow Protection Tests ---");

        // Test 2A: Maximum Positive Values
        // Max 24-bit signed integer is 2^23 - 1 = 8,388,607 (24'h7FFFFF)
        for (int i = 0; i < 32; i++) begin
            in[i] = (1 << (WIDTH-1)) - 1; 
        end
        check_result("All MAX Positive Values");
        #9;

        // Test 2B: Maximum Negative Values
        // Min 24-bit signed integer is -(2^23) = -8,388,608 (24'h800000)
        for (int i = 0; i < 32; i++) begin
            in[i] = -(1 << (WIDTH-1));
        end
        check_result("All MAX Negative Values");
        #9;

        // Test 2C: Alternating Extremes
        for (int i = 0; i < 32; i++) begin
            if (i % 2 == 0)
                in[i] = (1 << (WIDTH-1)) - 1;
            else
                in[i] = -(1 << (WIDTH-1));
        end
        check_result("Alternating Max Pos/Neg");
        #9;

        $display("==================================================");
        $display("   TESTS COMPLETE");
        $display("==================================================");
        $finish;
    end

endmodule