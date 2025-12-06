// 2-24-2025: changed to read in hex fp16's instead of ints from data input file

`include "systolic_array_if.vh"
`include "systolic_array_control_unit_if.vh"
`include "systolic_array_MAC_if.vh"
`include "systolic_array_add_if.vh"
`include "systolic_array_FIFO_if.vh"
`include "sys_arr_pkg.vh"
/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */
`timescale 1 ns / 1 ns

module systolic_array_top_tb();
  // clk/reset
  logic tb_nRST;

  string testcase = "fp";
  string path_to_files = "/home/vinay/tensorcore/tensor-core/";
  string input_filename = {"systolic_array_utils/matops_", testcase, "_encoded.txt"};
  string output_filename = {"systolic_array_utils/matops_", testcase, "_encoded_result.txt"};
  string python_output_filename = {"systolic_array_utils/matops_", testcase, "_encoded_output.txt"};
  string python_command = {"/bin/python3 ", path_to_files, "systolic_array_utils/matrix_mul_fp.py systolic_array_utils/matops_", testcase, "_encoded"};
  string comparison_command = {"/bin/python3 ", path_to_files, "systolic_array_utils/compare_sysarr_output.py systolic_array_utils/matops_", testcase, "_encoded_result.txt systolic_array_utils/matops_", testcase, "_encoded_output.txt systolic_array_utils/matops_", testcase, "_comp.txt"};

  // Memory interface instance
  systolic_array_if memory_if();

  // Clock gen
  parameter PERIOD = 10;
  logic tb_clk = 0;
  always #(PERIOD/2) tb_clk++;
  // FILE I/O
  int out_file, file, k, i, j, z, y, r, in, which;
  int sysarr_dump_file;
  /* verilator lint_off UNUSEDSIGNAL */
  string line;
  /* verilator lint_off UNUSEDSIGNAL */
  logic [DW-1:0] temp_weights[N][N];
  logic [DW-1:0] temp_inputs[N][N];
  logic [DW-1:0] temp_partials[N][N];
  logic [DW-1:0] temp_outputs[N][N];

  logic [(N*DW)-1:0] m_weights[N];
  logic [(N*DW)-1:0] m_inputs[N];
  logic [(N*DW)-1:0] m_partials[N];
  logic [(N*DW)-1:0] m_outputs[N];
  int loaded_weights;
  // Reset task
  task reset;
    begin
      tb_nRST = 1'b0;
      @(posedge tb_clk);
      @(posedge tb_clk);
      @(negedge tb_clk);
      tb_nRST = 1'b1;
      @(posedge tb_clk);
      @(posedge tb_clk);
    end
  endtask

  task row_load(
    input logic [1:0] rtype,
    input logic [$clog2(N)-1:0] rinnum,
    input logic [$clog2(N)-1:0] rpsnum,
    input logic [(N*DW)-1:0] rinput,
    input logic [(N*DW)-1:0] rpartial
  );
    begin
      if (rtype == 2'b00) begin
        memory_if.weight_en = 1'b1;
      end else if (|rtype) begin
        memory_if.input_en = rtype[0];
        memory_if.partial_en = rtype[1];
      end
      memory_if.row_in_en = rinnum;
      memory_if.row_ps_en = rpsnum;
      memory_if.array_in = rinput;
      memory_if.array_in_partials = rpartial;
      @(posedge tb_clk);
      memory_if.array_in = '0;
      memory_if.array_in_partials = '0;
      memory_if.weight_en = 1'b0;
      memory_if.partial_en = 1'b0;
      memory_if.input_en = 1'b0;
      memory_if.row_in_en = '0;
      memory_if.row_ps_en = '0;
    end
  endtask

  task get_matrices(output int weights);
    begin
      int iterations;
      int rc;
      $display("In get matrices task");
      weights = 0;
      which = 0;
      $fgets(line, file);
      // $display("In get matrices task. just fgets'ed");
      // $display("Line read in: %s", line);
      if (line == "Weights\n") begin
        which = 1;
        iterations = 3;
        weights = 1;
      end else if (line == "Inputs\n") begin
        which = 2;
        iterations = 2;
      end
      // $display("In get matrices task. just read value type. which: ");
      $display("%d", which);
      for (k = 0; k < iterations; k++) begin
        for (i = 0; i < N; i = i + 1) begin
          for (j = 0; j < N; j = j + 1) begin
            if (which == 1)begin
              rc = $fscanf(file, "%x ", temp_weights[i][j]);
              if (rc != 1) $display("WARN: fscanf weights[%0d][%0d] rc=%0d", i, j, rc);
              // $display("i just read in weight %x", temp_weights[i][j]);
            end else if (which == 2) begin
              rc = $fscanf(file, "%x ", temp_inputs[i][j]);
              if (rc != 1) $display("WARN: fscanf inputs[%0d][%0d] rc=%0d", i, j, rc);
              // $display("i just read in input %x", temp_inputs[i][j]);
            end else begin
              rc = $fscanf(file, "%x ", temp_partials[i][j]);
              if (rc != 1) $display("WARN: fscanf partials[%0d][%0d] rc=%0d", i, j, rc);
              // $display("i just read in partial %x", temp_partials[i][j]);
            end
          end  
        end
        which = which + 1;
        $fgets(line, file);
      end
      for (i = 0; i < N; i++)begin
        m_weights[i] = {>>{temp_weights[i]}};
        m_inputs[i] = {>>{temp_inputs[i]}};
        m_partials[i] = {>>{temp_partials[i]}};
      end
      
      // Verify matrices are non-zero
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
      for (i = 0; i < N; i++)begin
        /* verilator lint_off WIDTHTRUNC */
        m_outputs[i] = {>>{temp_outputs[i]}};
        /* verilator lint_off WIDTHTRUNC */
      end
    end
  endtask

  task load_weights();
    $display("[%0t] Loading weights...", $time);
    for (r = N-1; r >= 0; r--)begin
      /* verilator lint_off WIDTHTRUNC */
      row_load(.rtype(2'b00), .rinnum(r), .rpsnum('0), .rinput(m_weights[r]), .rpartial('0));
      /* verilator lint_off WIDTHTRUNC */
    end
    $display("[%0t] Weights loaded", $time);
  endtask

  task load_in_ps(input int delay);
    $display("[%0t] Loading inputs and partials with delay=%0d...", $time, delay);
    for (in = 0; in < N; in++)begin
      /* verilator lint_off WIDTHTRUNC */
      row_load(.rtype(2'b11), .rinnum(in), .rpsnum(in), .rinput(m_inputs[in]), .rpartial(m_partials[in]));
      /* verilator lint_off WIDTHTRUNC */
      repeat(delay) @(posedge tb_clk); // everyone else iteration delay
    end
    $display("[%0t] Inputs and partials loaded", $time);
  endtask

  // Helper task to wait for array to drain (no more active computations)
  task wait_for_drained;
    int cycles;
    begin
      cycles = 0;
      while (memory_if.drained !== 1'b1 && cycles < 100000) begin
        @(posedge tb_clk);
        cycles++;
      end
      if (memory_if.drained !== 1'b1) begin
        $display("ERROR: timeout waiting for drained after %0d cycles", cycles);
        $display("  out_en=%b, row_out=%0d", memory_if.out_en, memory_if.row_out);
        $stop;
      end else begin
        $display("Array drained after %0d cycles", cycles);
      end
    end
  endtask

  // Instantiate the DUT - using systolic_array_top with 2-cycle MAC ;D
  systolic_array_top DUT (
    .clk    (tb_clk),
    .nRST   (tb_nRST),
    .memory (memory_if.memory_array)
  );

  // Debug monitoring
  always @(posedge tb_clk) begin
    if (memory_if.out_en)
      $display("[%0t] out_en=1 row_out=%0d", $time, memory_if.row_out);
    if (memory_if.drained)
      $display("[%0t] drained=1", $time);
  end

  always @(posedge tb_clk) begin
    if (memory_if.out_en == 1'b1)begin
      $display("output row is %d", memory_if.row_out);
      if (m_outputs[memory_if.row_out] != memory_if.array_output)begin
        $display("Output incorrect\n");
        $display("Our Output is");
        for (y = 0; y < N; y++)begin
          $write("%x, ", memory_if.array_output[(y+1)*DW-1-:DW]);
        end
        $display("");
      end
      for (y = 0; y < N-1; y++)begin
          $fwrite(sysarr_dump_file, "%x ", memory_if.array_output[(y+1)*DW-1-:DW]);
      end
      $fwrite(sysarr_dump_file, "%x\n", memory_if.array_output[(N)*DW-1-:DW]);
      // $fwrite(sysarr_dump_file, "\n");
      $display("Correct Output is");
      for (z = 0; z < N; z++)begin
          $write("%x ", m_outputs[memory_if.row_out][(z+1)*DW-1-:DW]);
      end
      $display("");
      /* verilator lint_off WIDTHEXPAND */
      if (memory_if.row_out == N-1)begin
      /* verilator lint_off WIDTHEXPAND */
        get_m_output();
      end
    end
  end
  // Test Stimulus
  initial begin
    $dumpfile("dump.vcd");  // For VCD format
    // Dump only key signals to keep VCD size manageable
    $dumpvars(0,
      systolic_array_top_tb.tb_clk,
      systolic_array_top_tb.tb_nRST,
      systolic_array_top_tb.memory_if.drained,
      systolic_array_top_tb.memory_if.out_en,
      systolic_array_top_tb.memory_if.row_out,
      systolic_array_top_tb.memory_if.array_output,
      systolic_array_top_tb.memory_if.weight_en,
      systolic_array_top_tb.memory_if.array_in,
      systolic_array_top_tb.DUT.control_unit_if.MAC_start,
      systolic_array_top_tb.DUT.control_unit_if.MAC_value_ready,
      systolic_array_top_tb.DUT.control_unit_if.iteration
    );
    memory_if.weight_en = '0;
    memory_if.input_en = '0;
    memory_if.partial_en = '0;
    memory_if.row_in_en = '0;
    memory_if.row_ps_en = '0;
    memory_if.array_in = '0;
    memory_if.array_in_partials = '0;
    memory_if.stall_sa = '0;  // No stalling for basic test
    loaded_weights = 0;
    
    // any file

    file = $fopen(input_filename, "r");
    $system(python_command);
    out_file = $fopen(python_output_filename, "r");
    sysarr_dump_file = $fopen(output_filename, "w");

    reset();
    
    // test 1: streaming mode with back-to-back inputs 
    // note - systolic_array_top is designed for streaming - no input FIFOs
    $display("test 1: Streaming mode - immediate computation");
    get_matrices(.weights(loaded_weights));
    get_m_output();
    if (loaded_weights == 1)begin
      // LOAD WEIGHTS - stream them in directly
      load_weights();
    end
    // Stream inputs with no delay - computation starts immediately
    load_in_ps (.delay(0)); 
    wait_for_drained();
    $display("test 1 complete - array drained: %d", memory_if.drained);

    // test 2: second matrix multiply 
    $display("test 2: Second streaming computation");
    get_matrices(.weights(loaded_weights));
    // stream inputs immediately !
    load_in_ps (.delay(0)); 
    wait_for_drained();
    $display("test 2 complete - array drained: %d", memory_if.drained);

    // test 3: third run with weight reload
    $display("test 3: Streaming with weight reload");
    get_matrices(.weights(loaded_weights));
    get_m_output();
    if (loaded_weights == 1)begin
      // LOAD WEIGHTS
      @(posedge tb_clk)
      load_weights();
    end
    // Max throughput streaming
    load_in_ps (.delay(0)); 
    wait_for_drained();
    $display("test 3 complete - array drained: %d", memory_if.drained);
    
    $fclose(file);
    $fclose(out_file);
    $fclose(sysarr_dump_file);
    $system(comparison_command);

    #50;
    $stop;
  end

endmodule
