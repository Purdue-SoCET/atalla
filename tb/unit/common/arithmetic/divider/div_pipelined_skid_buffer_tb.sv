// make test tb_file=div_pipelined_tb.sv modules=/common/arithmetic/adders,/common/arithmetic/multipliers,/common/arithmetic/divider packages=/vector/vector_pkg.vh,/memory/scratchpad/scpad_pkg.sv,/common/xbar/xbar_pkg.sv GUI=ON VLOG_FLAGS="-sv -compile_uselibs -cover bst -sv -pedanticerrors -lint -mfcu" VSIM_FLAGS='-coverage -c -voptargs="+acc"'
`include "div_if.vh"
`timescale 1 ns / 1 ns

module div_pipelined_skid_buffer_tb;
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
  div_if #(
    .EXP_WIDTH(EXP_WIDTH),
    .MANT_WIDTH(MANT_WIDTH)
  ) divif();

  div_pipelined_skid_buffer DUT (
    .CLK(CLK),
    .nRST(nRST),
    .divif(divif)
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
    input [WIDTH-1:0] a_in,
    input [WIDTH-1:0] b_in,
    input [WIDTH-1:0] expected_in
  );
  begin
    // Wait until DUT is ready to accept input
    @(posedge CLK);
    while (!divif.out.ready_in) @(posedge CLK);
    
    // Apply inputs and assert valid_in
    divif.in.operand1 = a_in;
    divif.in.operand2 = b_in;
    divif.in.valid_in = 1;
    
    @(posedge CLK);
    while (!divif.out.ready_in) @(posedge CLK);
    
    // Deassert valid_in after handshake
    divif.in.valid_in = 0;
    
    timeout_counter = 0;
    while (!divif.out.valid_out) begin
      @(posedge CLK);
      timeout_counter++;
      if (timeout_counter > 500) begin 
        $display("FATAL ERROR @%0t: Timeout waiting for valid_out.", $time);
        errors++; break;
      end
    end
    
    abs_diff = (divif.out.result > expected_in) ? (divif.out.result - expected_in) : (expected_in - divif.out.result);
    if (is_nan(divif.out.result) && is_nan(expected_in)) begin
      // Pass
    end else if (divif.out.result !== expected_in) begin
      if ((divif.out.result[15] == expected_in[15]) && (abs_diff <= 2)) begin 
        // Pass ULP
      end else begin
         $display("ERROR @%0t [%s]: %h / %h = %h (expected %h)", 
                  $time, tb_test_case, a_in, b_in, divif.out.result, expected_in);
         errors++;
      end
    end
        
    divif.in.ready_out = 1;
    @(posedge CLK);
    divif.in.ready_out = 0;
  end
  endtask

  //-----------------------------------------------
  // Task: Run File Tests (FULL DUPLEX PIPELINE)
  //-----------------------------------------------
  task automatic run_file_tests(input string filename, input string test_name, input string traffic_mode);
    integer fd, r;
    string format_str;
    
    logic [WIDTH-1:0] op1, op2, exp_val;
    logic [WIDTH-1:0] q_op1 [$], q_op2 [$], q_exp [$];
    
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
    
    format_str = (WIDTH == 16) ? "%h,%h,%h\n" : "%h,%h,%h\n";
    
    start_time = $time;
    fork
      // ===================================================================
      // THREAD 1: THE DRIVER
      // ===================================================================
      begin
        while (!$feof(fd)) begin
          r = $fscanf(fd, format_str, op1, op2, exp_val);
          if (r == 3) begin
            // Inject FRONT PRESSURE (Bubbles / Input Starvation)
            if (traffic_mode == "FRONT_PRESSURE" || traffic_mode == "RANDOM") begin
              if ($urandom_range(0, 100) < 25) begin // 25% chance to stall
                divif.in.valid_in = 0;
                repeat($urandom_range(1, 4)) @(posedge CLK);
              end
            end

            divif.in.operand1 = op1;
            divif.in.operand2 = op2;
            divif.in.valid_in = 1;

            do begin @(posedge CLK); end while (!divif.out.ready_in);

            q_op1.push_back(op1); q_op2.push_back(op2); q_exp.push_back(exp_val);
            tests_fed++;
          end
        end
        divif.in.valid_in = 0;
        driver_done = 1; 
      end

      // ===================================================================
      // THREAD 2: THE RECEIVER
      // ===================================================================
      begin
        while (!driver_done || q_exp.size() > 0) begin
          
          // Inject BACK PRESSURE (Output Stalls / Skid Buffer Stress)
          if (traffic_mode == "BACK_PRESSURE" || traffic_mode == "RANDOM") begin
            if ($urandom_range(0, 100) < 25) begin // 25% chance to pause reading
              divif.in.ready_out = 0;
              repeat($urandom_range(1, 5)) @(posedge CLK);
            end
          end

          divif.in.ready_out = 1;
          @(posedge CLK);

          if (divif.out.valid_out && divif.in.ready_out) begin
            rx_timeout = 0; 
            
            if (q_exp.size() == 0) begin
              $display("FATAL ERROR: Pipeline output an answer but Queue is empty!");
              errors++;
            end else begin
              logic [WIDTH-1:0] c_op1 = q_op1.pop_front();
              logic [WIDTH-1:0] c_op2 = q_op2.pop_front();
              logic [WIDTH-1:0] c_exp = q_exp.pop_front();
              logic [WIDTH-1:0] c_act = divif.out.result;
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
                end else begin
                   $display("ERROR @%0t [%s]: %h / %h = %h (expected %h)", 
                            $time, tb_test_case, c_op1, c_op2, c_act, c_exp);
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
        divif.in.ready_out = 0;
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
    logic [WIDTH-1:0] POS_TWO, NEG_TWO;
    logic [WIDTH-1:0] QNAN, SNAN;
    logic [WIDTH-1:0] POS_MIN_NORM, NEG_MIN_NORM;
    logic [WIDTH-1:0] POS_MAX_NORM, NEG_MAX_NORM;
    logic [WIDTH-1:0] POS_MIN_SUB, NEG_MIN_SUB;
    logic [WIDTH-1:0] POS_MAX_SUB, NEG_MAX_SUB;
  begin
    // Initialize constants based on format
    POS_ZERO     = {WIDTH{1'b0}};
    NEG_ZERO     = {1'b1, {(WIDTH-1){1'b0}}};
    POS_INF      = {{1'b0}, {EXP_WIDTH{1'b1}}, {MANT_WIDTH{1'b0}}};
    NEG_INF      = {{1'b1}, {EXP_WIDTH{1'b1}}, {MANT_WIDTH{1'b0}}};
    QNAN         = {{1'b0}, {EXP_WIDTH{1'b1}}, 1'b1, {(MANT_WIDTH-1){1'b0}}};
    SNAN         = {{1'b0}, {EXP_WIDTH{1'b1}}, 1'b0, {(MANT_WIDTH-1){1'b1}}};
    
    // Normal boundaries
    POS_MIN_NORM = {{1'b0}, {{(EXP_WIDTH-1){1'b0}}, 1'b1}, {MANT_WIDTH{1'b0}}};
    NEG_MIN_NORM = {{1'b1}, {{(EXP_WIDTH-1){1'b0}}, 1'b1}, {MANT_WIDTH{1'b0}}};
    POS_MAX_NORM = {{1'b0}, {{(EXP_WIDTH-1){1'b1}}, 1'b0}, {MANT_WIDTH{1'b1}}};
    NEG_MAX_NORM = {{1'b1}, {{(EXP_WIDTH-1){1'b1}}, 1'b0}, {MANT_WIDTH{1'b1}}};
    
    // Subnormal boundaries
    POS_MIN_SUB  = {{1'b0}, {EXP_WIDTH{1'b0}}, {{(MANT_WIDTH-1){1'b0}}, 1'b1}};
    NEG_MIN_SUB  = {{1'b1}, {EXP_WIDTH{1'b0}}, {{(MANT_WIDTH-1){1'b0}}, 1'b1}};
    POS_MAX_SUB  = {{1'b0}, {EXP_WIDTH{1'b0}}, {MANT_WIDTH{1'b1}}};
    NEG_MAX_SUB  = {{1'b1}, {EXP_WIDTH{1'b0}}, {MANT_WIDTH{1'b1}}};
    
    // One and Two (using bias = 2^(EXP_WIDTH-1) - 1)
    // For FP16: bias=15, exp(1.0)=15, exp(2.0)=16
    // For BF16: bias=127, exp(1.0)=127, exp(2.0)=128
    POS_ONE      = {{1'b0}, get_exponent(2**(EXP_WIDTH-1)-1), {MANT_WIDTH{1'b0}}};
    NEG_ONE      = {{1'b1}, get_exponent(2**(EXP_WIDTH-1)-1), {MANT_WIDTH{1'b0}}};
    POS_TWO      = {{1'b0}, get_exponent(2**(EXP_WIDTH-1)), {MANT_WIDTH{1'b0}}};
    NEG_TWO      = {{1'b1}, get_exponent(2**(EXP_WIDTH-1)), {MANT_WIDTH{1'b0}}};
    
    tb_test_case = "EDGE_CASES";
    $display("Running explicit edge case tests...");
    
    // Division by zero
    tb_test_case = "ZERO_CASES";
    apply_vector(POS_ONE, POS_ZERO, POS_INF);
    apply_vector(POS_ZERO, POS_ONE, POS_ZERO);
    apply_vector(POS_ZERO, POS_ZERO, QNAN);
    
    // Infinity cases
    tb_test_case = "INF_CASES";
    apply_vector(POS_INF, POS_ONE, POS_INF);
    apply_vector(POS_ONE, POS_INF, POS_ZERO);
    apply_vector(POS_INF, POS_ZERO, POS_INF);
    apply_vector(POS_ZERO, POS_INF, POS_ZERO);
    apply_vector(POS_INF, POS_INF, QNAN);
    
    // NaN propagation
    tb_test_case = "NAN_PROPAGATION";
    apply_vector(QNAN, POS_ONE, QNAN);
    apply_vector(POS_ONE, QNAN, QNAN);
    apply_vector(QNAN, QNAN, QNAN);
    apply_vector(SNAN, POS_ONE, QNAN);
    apply_vector(QNAN, POS_INF, QNAN);
    apply_vector(POS_INF, QNAN, QNAN);
    apply_vector(QNAN, POS_ZERO, QNAN);
    apply_vector(POS_ZERO, QNAN, QNAN);
    
    // Normal boundaries
    tb_test_case = "NORM_BOUNDARY";
    apply_vector(POS_MAX_NORM, POS_ONE, POS_MAX_NORM);
    apply_vector(POS_MIN_NORM, POS_ONE, POS_MIN_NORM);
    apply_vector(POS_MAX_NORM, POS_MAX_NORM, POS_ONE);
    apply_vector(POS_MIN_NORM, POS_MIN_NORM, POS_ONE);

    // Subnormal boundaries
    tb_test_case = "SUBNORM_BOUNDARY";
    apply_vector(POS_MIN_SUB, POS_ONE, POS_ZERO);
    apply_vector(POS_MAX_SUB, POS_ONE, POS_ZERO);
    apply_vector(POS_MIN_SUB, POS_TWO, POS_ZERO);
    apply_vector(POS_ONE, POS_MAX_NORM, POS_ZERO);
    
    // Overflow
    tb_test_case = "OVERFLOW";
    apply_vector(POS_MAX_NORM, POS_MIN_SUB, POS_INF);
    apply_vector(NEG_MAX_NORM, POS_MIN_SUB, NEG_INF);
    
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
    divif.in.valid_in = 0;
    divif.in.ready_out = 0;
    divif.in.operand1 = 0;
    divif.in.operand2 = 0;
    errors = 0;
    normal_tests = 0;
    subnormal_input_tests = 0;
    subnormal_output_tests = 0;
    edge_tests = 0;

    // Power-on reset test
    tb_test_case = "POWER_ON_RESET";
    $display("Running power-on reset test...");
    
    @(posedge CLK);
    if (divif.out.valid_out !== 0) begin
      $display("ERROR @%0t [POWER_ON_RESET]: valid_out should be 0 during reset, got %b", 
                $time, divif.out.valid_out);
      errors++;
    end
    if (divif.out.ready_in !== 0) begin
      $display("ERROR @%0t [POWER_ON_RESET]: ready_in should be 0 during reset, got %b", 
                $time, divif.out.ready_in);
      errors++;
    end
    
    if (errors == 0) begin
      $display("Power-on reset test passed");
    end
    
    #20 nRST = 1;
    #20;  // Settle
    
    // Check that ready_in goes high after reset
    @(posedge CLK);
    if (divif.out.ready_in !== 1) begin
      $display("ERROR @%0t [POST_RESET]: ready_in should be 1 after reset, got %b", 
                $time, divif.out.ready_in);
      errors++;
    end

    // ---------------------------------------------------------
    // MID-FLIGHT RESET TEST (Asynchronous Flush)
    // ---------------------------------------------------------
    tb_test_case = "MID_FLIGHT_RESET";
    $display("Running Mid-Flight Reset test...");
    
    // 1. Jam 4 items into the pipeline as fast as possible
    divif.in.operand1 = 16'h4000; // 2.0
    divif.in.operand2 = 16'h4000; // 2.0
    divif.in.valid_in = 1;
    for (int i=0; i<4; i++) begin
      do begin @(posedge CLK); end while (!divif.out.ready_in);
    end
    divif.in.valid_in = 0;
    
    // 2. Wait 2 clock cycles so they are deep inside the math units
    repeat(2) @(posedge CLK); 
    
    // 3. Brutally yank the reset low mid-calculation!
    nRST = 0;
    repeat(2) @(posedge CLK);
    
    // 4. Release reset and verify the pipeline completely died
    nRST = 1;
    @(posedge CLK);
    if (divif.out.valid_out !== 0) begin
      $display("ERROR @%0t [MID_FLIGHT_RESET]: Ghost data survived the reset! FIFO is not empty.", $time);
      errors++;
    end
    if (divif.out.ready_in !== 1) begin
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
      // MAX THROUGHPUT
      run_file_tests("tb/unit/common/arithmetic/divider/test_cases/div_bf16_normal_tests_10K.csv", "BF16_NORM_STABLE", "STABLE");

      // Front Pressure
      run_file_tests("tb/unit/common/arithmetic/divider/test_cases/div_bf16_normal_tests_10K.csv", "BF16_FRONT_PRESS", "FRONT_PRESSURE");
      
      // Back Pressure
      run_file_tests("tb/unit/common/arithmetic/divider/test_cases/div_bf16_normal_tests_10K.csv", "BF16_BACK_PRESS", "BACK_PRESSURE");

      // Full Random
      run_file_tests("tb/unit/common/arithmetic/divider/test_cases/div_bf16_normal_tests_10K.csv", "BF16_RANDOM", "RANDOM");

      // MAX THROUGHPUT
      run_file_tests("tb/unit/common/arithmetic/divider/test_cases/div_bf16_all_mantissas.csv", "BF16_NORM_STABLE_ALL", "STABLE");

      // Front Pressure
      run_file_tests("tb/unit/common/arithmetic/divider/test_cases/div_bf16_all_mantissas.csv", "BF16_FRONT_PRESS_ALL", "FRONT_PRESSURE");
      
      // Back Pressure
      run_file_tests("tb/unit/common/arithmetic/divider/test_cases/div_bf16_all_mantissas.csv", "BF16_BACK_PRESS_ALL", "BACK_PRESSURE");

      // Full Random
      run_file_tests("tb/unit/common/arithmetic/divider/test_cases/div_bf16_all_mantissas.csv", "BF16_RANDOM_ALL", "RANDOM");

      normal_tests = errors;
      run_file_tests("tb/unit/common/arithmetic/divider/test_cases/div_bf16_subnormal_input_tests_10K.csv", "BF16_SUBNORMAL_INPUT_TESTS", "RANDOM");
      subnormal_input_tests = errors - normal_tests;

      run_file_tests("tb/unit/common/arithmetic/divider/test_cases/div_bf16_subnormal_output_tests_10K.csv", "BF16_SUBNORMAL_OUTPUT_TESTS", "RANDOM");
      subnormal_output_tests = errors - normal_tests - subnormal_input_tests;
    end else begin
      $display("INFO: No file-based tests available for this custom format");
    end

    run_edge_case_tests();

    // Summary
    $display("\n========== TEST SUMMARY ==========");
    $display("Normal tests errors:           %0d", normal_tests);
    $display("Subnormal input tests errors:  %0d", subnormal_input_tests);
    $display("Subnormal output tests errors: %0d", subnormal_output_tests);
    $display("Edge case tests errors:        %0d", errors - (normal_tests + subnormal_input_tests + subnormal_output_tests));
    $display("Total errors:                  %0d", errors);
    $display("==================================\n");
    
    if (errors == 0)
      $display("*** ALL TESTS PASSED ***");
    else
      $display("*** TEST FAILED: %0d total errors ***", errors);
    
    $stop;
  end
endmodule