// make test tb_file=reciprocal_bf16_tb.sv modules=/common/arithmetic/adders,/common/arithmetic/multipliers,/common/arithmetic/divider packages=/vector/vector_pkg.vh,/memory/scratchpad/scpad_pkg.sv,/common/xbar/xbar_pkg.sv GUI=ON VLOG_FLAGS="-sv -compile_uselibs -cover bst -sv -pedanticerrors -lint -mfcu" VSIM_FLAGS='-coverage -c -voptargs="+acc"'
`include "reciprocal_if.vh"
`timescale 1 ns / 1 ns
module reciprocal_bf16_tb;
    //-----------------------------------------------
  // Configuration Parameters
  //-----------------------------------------------
  // Change these to switch between FP16 and BF16
  parameter int EXP_WIDTH = 8;
  parameter int MANT_WIDTH = 7;
  parameter int WIDTH = EXP_WIDTH + MANT_WIDTH + 1;
  
  // Testbench variables
  string tb_test_case = "INIT";
  logic CLK = 0;
  logic nRST = 0;
  parameter PERIOD = 10;
  
  // Testbench tracking variables
  integer errors;
  integer normal_tests, subnormal_input_tests, subnormal_output_tests, edge_tests;
  integer timeout_counter;
  logic [WIDTH-1:0] abs_diff;
  
  //-----------------------------------------------
  // Clock generation
  //-----------------------------------------------
  always #(PERIOD/2) CLK = ~CLK;

  //-----------------------------------------------
  // Interface and DUT instantiation
  //-----------------------------------------------
  reciprocal_if #(
    .EXP_WIDTH(EXP_WIDTH),
    .MANT_WIDTH(MANT_WIDTH)
  ) rif();

  reciprocal_bf16 DUT (
    .CLK(CLK),
    .nRST(nRST),
    .rif(rif)
  );

  //-----------------------------------------------
  // Helper Functions
  //-----------------------------------------------
  function automatic bit is_nan(input logic [WIDTH-1:0] val);
    logic [EXP_WIDTH-1:0] exponent = val[WIDTH-2:MANT_WIDTH];
    logic [MANT_WIDTH-1:0] mantissa = val[MANT_WIDTH-1:0];
    return (exponent == {EXP_WIDTH{1'b1}}) && (mantissa != {MANT_WIDTH{1'b0}});
  endfunction

  //-----------------------------------------------
  // Helper: convert integer to exponent field
  //-----------------------------------------------
  function automatic logic [EXP_WIDTH-1:0] get_exponent(input integer exp_value);
    return exp_value[EXP_WIDTH-1:0];
  endfunction

  //-----------------------------------------------
  // Task: Apply Single Vector (For Edge Cases)
  //-----------------------------------------------
  task automatic apply_vector(
    input [WIDTH-1:0] in_val,
    input [WIDTH-1:0] expected_in
  );
  begin
    // Wait until DUT is ready to accept input
    @(posedge CLK);
    while (!rif.out.ready_in) @(posedge CLK);
    
    // Apply inputs and assert valid_in
    rif.in.divisor = in_val;
    rif.in.valid_in = 1;
    
    @(posedge CLK);
    while (!rif.out.ready_in) @(posedge CLK);
    
    // Deassert valid_in after handshake
    rif.in.valid_in = 0;
    
    timeout_counter = 0;
    while (!rif.out.valid_out) begin
      @(posedge CLK);
      timeout_counter++;
      if (timeout_counter > 500) begin 
        $display("FATAL ERROR @%0t: Timeout waiting for valid_out.", $time);
        errors++; break;
      end
    end
    
    abs_diff = (rif.out.result > expected_in) ? (rif.out.result - expected_in) : (expected_in - rif.out.result);
    if (is_nan(rif.out.result) && is_nan(expected_in)) begin
      // Pass
    end else if (rif.out.result !== expected_in) begin
      if ((rif.out.result[15] == expected_in[15]) && (abs_diff <= 2)) begin 
        // Pass ULP
      end else begin
         $display("ERROR @%0t [%s]: Reciprocal of %h = %h (expected %h)",
                  $time, tb_test_case, in_val, rif.out.result, expected_in);
         errors++;
      end
    end
        
    rif.in.ready_out = 1;
    @(posedge CLK);
    rif.in.ready_out = 0;
  end
  endtask

  //-----------------------------------------------
  // Task: Run File Tests (FULL DUPLEX PIPELINE)
  //-----------------------------------------------
  task automatic run_file_tests(input string filename, input string test_name, input string traffic_mode);
    integer fd, r;
    string format_str;
    
    logic [WIDTH-1:0] in_val, exp_val;
    logic [WIDTH-1:0] q_in [$], q_exp [$];
    
    int ULP_0_count = 0, ULP_1_count = 0, ULP_2_count = 0;
    int tests_fed = 0, tests_received = 0, rx_timeout = 0;
    bit driver_done = 0;
    time start_time, end_time;
    real total_cycles, effective_cpi;

  begin
    tb_test_case = test_name;
    fd = $fopen(filename, "r");
    if (fd == 0) begin
      $display("INFO: Cannot open file: %s", filename);
      return;
    end
    
    $display("\n=======================================================");
    $display("Running %s", test_name);
    $display("File: %s", filename);
    $display("Traffic Mode: %s", traffic_mode);
    $display("=======================================================");
    
    format_str = "%h,%h\n";
    
    start_time = $time;
    fork
      // Driver Thread
      begin
        while (!$feof(fd)) begin
          r = $fscanf(fd, format_str, in_val, exp_val);
          if (r == 2) begin
            // FRONT PRESSURE (Bubbles / Input Starvation)
            if (traffic_mode == "FRONT_PRESSURE" || traffic_mode == "RANDOM") begin
              if ($urandom_range(0, 100) < 25) begin // 25% chance to stall
                rif.in.valid_in = 0;
                repeat($urandom_range(1, 4)) @(posedge CLK);
              end
            end

            rif.in.divisor = in_val;
            rif.in.valid_in = 1;

            do begin 
              @(posedge CLK); 
            end while 
              (!rif.out.ready_in);

            q_in.push_back(in_val); q_exp.push_back(exp_val);
            tests_fed++;
          end
        end
        rif.in.valid_in = 0;
        driver_done = 1; 
      end

      // Receiver Thread
      begin
        while (!driver_done || q_exp.size() > 0) begin
          
          // BACK PRESSURE (Output Stalls / Skid Buffer Stress)
          if (traffic_mode == "BACK_PRESSURE" || traffic_mode == "RANDOM") begin
            if ($urandom_range(0, 100) < 25) begin // 25% chance to pause reading
              rif.in.ready_out = 0;
              repeat($urandom_range(1, 5)) @(posedge CLK);
            end
          end

          rif.in.ready_out = 1;
          @(posedge CLK);

          if (rif.out.valid_out && rif.in.ready_out) begin
            rx_timeout = 0; 
            
            if (q_exp.size() == 0) begin
              $display("FATAL ERROR: Pipeline output an answer but Queue is empty!");
              errors++;
            end else begin
              logic [WIDTH-1:0] c_in = q_in.pop_front();
              logic [WIDTH-1:0] c_exp = q_exp.pop_front();
              logic [WIDTH-1:0] c_act = rif.out.result;
              logic [WIDTH-1:0] t_abs;

              // MATHEMATICAL COMPARISON AND ULP COUNTING
              if (is_nan(c_act) && is_nan(c_exp)) begin
                ULP_0_count++; // Both NaN is a perfect match
              end else begin
                t_abs = (c_act > c_exp) ? (c_act - c_exp) : (c_exp - c_act);
                
                if (c_act === c_exp) begin
                   ULP_0_count++;
                end else if ((c_act[15] == c_exp[15]) && (t_abs <= 2)) begin 
                   if (t_abs == 1) ULP_1_count++;
                   if (t_abs == 2) ULP_2_count++;
                end else if ((c_act[14:0] == 15'h0000) && (c_exp[14:0] <= 15'h0083) && (c_act[15] == c_exp[15])) begin
                   ULP_2_count++;
                end else begin
                    $display("ERROR @%0t [%s]: Reciprocal of %h = %h (expected %h)", 
                            $time, tb_test_case, c_in, c_act, c_exp);
                   errors++;
                end
              end
              tests_received++;
            end
          end else begin
            rx_timeout++;
            if (rx_timeout > 1500) begin // Give it extra time for the BACK_PRESSURE stalls
               $display("FATAL ERROR: Receiver timed out waiting for pipeline to flush!");
               errors++; break;
            end
          end
        end
        rif.in.ready_out = 0;
      end
    join

    end_time = $time;

    $fclose(fd);
    $display("Completed %s: Fed %0d, Received %0d tests", test_name, tests_fed, tests_received);
    $display("Accuracy Breakdown -> 0 ULP: %0d | 1 ULP: %0d | 2 ULP: %0d", ULP_0_count, ULP_1_count, ULP_2_count);
    if (tests_received > 0) begin
      total_cycles = (end_time - start_time) / PERIOD;
      effective_cpi = total_cycles / real'(tests_received);
      $display("Performance Metric -> Total Cycles: %0.0f | Effective CPI: %0.2f cycles/division\n", total_cycles, effective_cpi);
    end
    if (tests_fed != tests_received) begin
       $display("ERROR: Data mismatch! Fed %0d but Received %0d", tests_fed, tests_received);
       errors++;
    end
  end
  endtask

  //-----------------------------------------------
  // Task: run edge case tests
  //-----------------------------------------------
  task automatic run_edge_case_tests();
    // Floating point constants (generated based on parameters)
    logic [WIDTH-1:0] POS_ZERO, NEG_ZERO;
    logic [WIDTH-1:0] POS_INF, NEG_INF;
    logic [WIDTH-1:0] POS_ONE, NEG_ONE;
    logic [WIDTH-1:0] QNAN, SNAN;
  begin
    // Initialize constants based on format
    POS_ZERO     = {WIDTH{1'b0}};
    NEG_ZERO     = {1'b1, {(WIDTH-1){1'b0}}};
    POS_INF      = {{1'b0}, {EXP_WIDTH{1'b1}}, {MANT_WIDTH{1'b0}}};
    NEG_INF      = {{1'b1}, {EXP_WIDTH{1'b1}}, {MANT_WIDTH{1'b0}}};
    QNAN         = {{1'b0}, {EXP_WIDTH{1'b1}}, 1'b1, {(MANT_WIDTH-1){1'b0}}};
    SNAN         = {{1'b0}, {EXP_WIDTH{1'b1}}, 1'b0, {(MANT_WIDTH-1){1'b1}}};

    // One (using bias = 2^(EXP_WIDTH-1) - 1)
    POS_ONE      = {{1'b0}, get_exponent(2**(EXP_WIDTH-1)-1), {MANT_WIDTH{1'b0}}};
    NEG_ONE      = {{1'b1}, get_exponent(2**(EXP_WIDTH-1)-1), {MANT_WIDTH{1'b0}}};
    
    tb_test_case = "EDGE_CASES";
    $display("Running explicit edge case tests...");
    
    // Reciprocal of zero (1 / 0 = Inf)
    tb_test_case = "ZERO_CASES";
    apply_vector(POS_ZERO, POS_INF);
    apply_vector(NEG_ZERO, NEG_INF);

    // Reciprocal of infinity (1 / Inf = 0)
    tb_test_case = "INF_CASES";
    apply_vector(POS_INF, POS_ZERO);
    apply_vector(NEG_INF, NEG_ZERO);

    // NaN propagation (1 / NaN = NaN)
    tb_test_case = "NAN_PROPAGATION";
    apply_vector(QNAN, QNAN);
    apply_vector(SNAN, QNAN);

    // Reciprocal of One (1 / 1 = 1)
    tb_test_case = "ONE_CASES";
    apply_vector(POS_ONE, POS_ONE);
    apply_vector(NEG_ONE, NEG_ONE);
    
    $display("Edge case tests completed");
  end
  endtask

  //-----------------------------------------------
  // Main test sequence
  //-----------------------------------------------
  initial begin
    // Display configuration
    $display("\n========== TESTBENCH CONFIGURATION ==========");
    $display("Format:       %s", (EXP_WIDTH == 5) ? "FP16" : (EXP_WIDTH == 8) ? "BF16" : "CUSTOM");
    $display("EXP_WIDTH:    %0d", EXP_WIDTH);
    $display("MANT_WIDTH:   %0d", MANT_WIDTH);
    $display("TOTAL_WIDTH:  %0d", WIDTH);
    $display("=============================================\n");
    
    // Init handshake signals
    rif.in.valid_in = 0;
    rif.in.ready_out = 0;
    rif.in.divisor = 0;
    errors = 0;
    normal_tests = 0;
    subnormal_input_tests = 0;
    subnormal_output_tests = 0;
    edge_tests = 0;

    // Power-on reset test
    tb_test_case = "POWER_ON_RESET";
    $display("Running power-on reset test...");
    
    @(posedge CLK);
    if (rif.out.valid_out !== 0) begin
      $display("ERROR @%0t [POWER_ON_RESET]: valid_out should be 0 during reset, got %b", 
                $time, rif.out.valid_out);
      errors++;
    end
    if (rif.out.ready_in !== 0) begin
      $display("ERROR @%0t [POWER_ON_RESET]: ready_in should be 0 during reset, got %b", 
                $time, rif.out.ready_in);
      errors++;
    end
    
    if (errors == 0) begin
      $display("Power-on reset test passed");
    end
    
    #20 nRST = 1;
    #20;  // Settle
    
    // Check that ready_in goes high after reset
    @(posedge CLK);
    if (rif.out.ready_in !== 1) begin
      $display("ERROR @%0t [POST_RESET]: ready_in should be 1 after reset, got %b", 
                $time, rif.out.ready_in);
      errors++;
    end

    // MID-FLIGHT RESET TEST (Asynchronous Flush)
    tb_test_case = "MID_FLIGHT_RESET";
    $display("Running Mid-Flight Reset test...");
    
    // 1. Jam 4 items into the pipeline as fast as possible
    rif.in.divisor = 16'h4000; // 2.0
    rif.in.valid_in = 1;
    for (int i=0; i<4; i++) begin
      do begin 
        @(posedge CLK); 
      end while 
        (!rif.out.ready_in);
    end
    rif.in.valid_in = 0;
    
    // 2. Wait 2 clock cycles so they are deep inside the math units
    repeat(2) @(posedge CLK); 
    
    // 3. Pull reset low mid-calculation
    nRST = 0;
    repeat(2) @(posedge CLK);
    
    // 4. Release reset and verify the pipeline completely died
    nRST = 1;
    @(posedge CLK);
    if (rif.out.valid_out !== 0) begin
      $display("ERROR @%0t [MID_FLIGHT_RESET]: Ghost data survived the reset! FIFO is not empty.", $time);
      errors++;
    end
    if (rif.out.ready_in !== 1) begin
      $display("ERROR @%0t [MID_FLIGHT_RESET]: Pipeline didn't recover ready_in after flush.", $time);
      errors++;
    end
    $display("Mid-Flight Reset test passed.");
    // ---------------------------------------------------------

    // Run all test categories (adjust filenames for BF16 if needed)
    if (EXP_WIDTH == 5 && MANT_WIDTH == 10) begin
      // FP16 test files
      run_file_tests("tb/unit/vector/test_cases/div_fp16_normal_tests_10K.csv", "NORMAL_TESTS", "RANDOM");
      normal_tests = errors;

      run_file_tests("tb/unit/vector/test_cases/div_fp16_subnormal_input_tests_10K.csv", "SUBNORMAL_INPUT_TESTS", "RANDOM");
      subnormal_input_tests = errors - normal_tests;

      run_file_tests("tb/unit/vector/test_cases/div_fp16_subnormal_output_tests_10K.csv", "SUBNORMAL_OUTPUT_TESTS", "RANDOM");
      subnormal_output_tests = errors - normal_tests - subnormal_input_tests;
    end else if (EXP_WIDTH == 8 && MANT_WIDTH == 7) begin
      // BF16 test files (if available) --------------------------------------------------------------------------------------------------------------------------
      run_file_tests("tb/unit/common/arithmetic/divider/test_cases/recip_bf16_normal_tests_all.csv", "BF16_NORM_STABLE", "STABLE");
      run_file_tests("tb/unit/common/arithmetic/divider/test_cases/recip_bf16_normal_tests_all.csv", "BF16_FRONT_PRESS", "FRONT_PRESSURE");
      run_file_tests("tb/unit/common/arithmetic/divider/test_cases/recip_bf16_normal_tests_all.csv", "BF16_BACK_PRESS", "BACK_PRESSURE");
      run_file_tests("tb/unit/common/arithmetic/divider/test_cases/recip_bf16_normal_tests_all.csv", "BF16_RANDOM", "RANDOM");

      normal_tests = errors;
    end else begin
      $display("INFO: No file-based tests available for this custom format");
    end

    run_edge_case_tests();

    // Summary
    $display("\n========== TEST SUMMARY ==========");
    $display("Normal tests errors:           %0d", normal_tests);
    $display("Edge case tests errors:        %0d", errors - normal_tests);
    $display("Total errors:                  %0d", errors);
    $display("==================================\n");
    
    if (errors == 0)
      $display("*** ALL TESTS PASSED ***");
    else
      $display("*** TEST FAILED: %0d total errors ***", errors);
    
    $stop;
  end
endmodule