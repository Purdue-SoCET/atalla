`timescale 1ns/1ps

`include "vector_types.vh"
`include "vector_if.vh"
`include "vexp_if.vh"
`include "vaddsub_if.vh"

module vexp_tb;
  parameter PERIOD  = 10;
  parameter LATENCY = 20;   // <-- set to your actual cycles from valid_in to result

  logic CLK = 0, nRST;

  always #(PERIOD/2) CLK = ~CLK;

  vexp_if vexpif();

  vexp dut (
    .CLK   (CLK),
    .nRST  (nRST),
    .vexpif(vexpif)
  );

  // ULP function
  function automatic int ulp_diff(input logic [15:0] a, input logic [15:0] b);
      int ai, bi;
      begin
          ai = int'(a);
          bi = int'(b);
          if (ai > bi) ulp_diff = ai - bi;
          else         ulp_diff = bi - ai;
      end
  endfunction

  // File handles
  integer fd_in, fd_out;

  // For parsing CSV
  logic  [15:0] input_hex, golden_hex;
  string        line;
  int           got, count;

  // For DUT result + ULP
  logic [15:0]  dut_res;
  int           ulp;

  initial begin
    // init
    vexpif.operand   = '0;
    vexpif.valid_in  = 0;
    vexpif.ready_out = 1;  // always ready

    // reset
    nRST = 0;
    repeat (5) @(posedge CLK);
    nRST = 1;

    // open files
    fd_in = $fopen("vexp_truth.csv", "r");
    if (fd_in == 0) begin
      $fatal("ERROR: cannot open vexp_truth.csv");
    end

    fd_out = $fopen("vexp_bf16_results.csv", "w");
    if (fd_out == 0) begin
      $fatal("ERROR: cannot open vexp_bf16_results.csv");
    end

    // optional header
    $fdisplay(fd_out, "input_hex,golden_hex,dut_hex,ulp_diff");

    // skip header from input CSV
    void'($fgets(line, fd_in));

    // main sweep loop
    count = 0;

    while (!$feof(fd_in)) begin
      line = "";
      got  = $fgets(line, fd_in);
      if (got == 0) break;
      if (line.len() == 0) continue;

      got = $sscanf(line, "%h,%h", input_hex, golden_hex);
      if (got != 2) continue;

      // drive input on next posedge
      @(posedge CLK);
      vexpif.operand <= input_hex;
      vexpif.valid_in <= 1'b1; // one-cycle valid pulse

      @(posedge CLK);
      vexpif.valid_in <= 1'b0;

      // wait for a clock where valid_out is high
      do @(posedge CLK); while (vexpif.valid_out !== 1'b1);

      // capture result **on that same cycle**
      dut_res = vexpif.result;
      ulp     = ulp_diff(dut_res, golden_hex);

      // if (input_hex == 16'h3F80) begin
      //   $display("[%0t] DEBUG 3F80: golden=%04h dut=%04h ulp=%0d",
      //     golden_hex, dut_res, ulp, $time);
      // end

      // log
      $fdisplay(fd_out, "%04h,%04h,%04h,%0d",
                input_hex, golden_hex, dut_res, ulp);

      count++;
      if ((count % 1000) == 0)
        $display("Processed %0d cases...", count);

    end

      $display("Full sweep done. Total cases: %0d", count);
      $fclose(fd_in);
      $fclose(fd_out);
      $stop;
  end

endmodule