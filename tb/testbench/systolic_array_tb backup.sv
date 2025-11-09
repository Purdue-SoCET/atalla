`include "systolic_array_if.vh"
`include "systolic_array_control_unit_if.vh"
`include "systolic_array_MAC_if.vh"
`include "systolic_array_add_if.vh"
`include "systolic_array_FIFO_if.vh"
`include "systolic_array_PS_FIFO_if.vh"

`timescale 1 ns / 1 ns

module systolic_array_tb();
  // Parameters
  parameter N     = 4;
  parameter WIDTH = 16;

  // clk/reset
  logic tb_nRST;

  // Memory interface instance
  systolic_array_if #(.array_dim(N), .data_w(WIDTH)) memory_if();

  // Clock gen
  parameter PERIOD = 10;
  logic tb_clk = 0;
  always #(PERIOD/2) tb_clk++;

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
    input logic [1:0] rnum,
    input logic [63:0] rinput,
    input logic [63:0] rpartial
  );
    begin
      if (rtype == 2'b00) begin
        memory_if.weight_en = 1'b1;
      end else if (|rtype) begin
        memory_if.input_en = rtype[0];
        memory_if.partial_en = rtype[1];
      end
      memory_if.row_en = rnum;
      memory_if.array_in = rinput;
      memory_if.array_in_partials = rpartial;
      @(posedge tb_clk);
      memory_if.array_in = '0;
      memory_if.array_in_partials = '0;
      memory_if.weight_en = 1'b0;
      memory_if.partial_en = 1'b0;
      memory_if.input_en = 1'b0;
      memory_if.row_en = 2'd0;
    end
  endtask
  

  // Instantiate the DUT
  systolic_array #(
    .N(N),
    .WIDTH(WIDTH)
  ) DUT (
    .clk    (tb_clk),
    .nRST   (tb_nRST),
    .memory (memory_if.memory_array)
  );
  always @(posedge tb_clk) begin
    if (memory_if.out_en == 1'b1)begin
      $display("output row is %d", memory_if.row_out);
      $display("output is %d, %d, %d, %d", memory_if.array_output[WIDTH-1:0],memory_if.array_output[2*WIDTH-1:WIDTH],memory_if.array_output[3*WIDTH-1:2*WIDTH],memory_if.array_output[4*WIDTH-1:3*WIDTH]);
    end
  end
  // Test Stimulus
  initial begin
    $dumpfile("dump.vcd");  // For VCD format
    $dumpvars(0, systolic_array_tb);
    memory_if.weight_en = '0;
    memory_if.input_en = '0;
    memory_if.partial_en = '0;
    memory_if.row_en = '0;
    memory_if.array_in = '0;
    memory_if.array_in_partials = '0;
    reset();
    //2x2 Example
    $display("BASIC 2X2 Example with Simple Partials");
    //LOAD WEIGHTS
    row_load(.rtype(2'b00), .rnum(2'd0), .rinput({16'd1, 16'd2, 16'd0, 16'd0}), .rpartial(64'b0));
    row_load(.rtype(2'b00), .rnum(2'd1), .rinput({16'd3, 16'd4, 16'd0, 16'd0}), .rpartial(64'b0));
    row_load(.rtype(2'b00), .rnum(2'd2), .rinput({16'd0, 16'd0, 16'd0, 16'd0}), .rpartial(64'b0));
    row_load(.rtype(2'b00), .rnum(2'd3), .rinput({16'd0, 16'd0, 16'd0, 16'd0}), .rpartial(64'b0));
    //LOAD INPUTS AND PARTIALS TOGETHER
    row_load(.rtype(2'b11), .rnum(2'd0), .rinput({16'd5, 16'd6, 16'd0, 16'd0}), .rpartial({16'd0, 16'd0, 16'd1, 16'd1}));
    repeat(2) @(posedge tb_clk); //iteration 0 delay of 6 for mul_len+add_len+1
    row_load(.rtype(2'b11), .rnum(2'd1), .rinput({16'd7, 16'd8, 16'd0, 16'd0}), .rpartial({16'd0, 16'd0, 16'd1, 16'd1}));
    repeat(5) @(posedge tb_clk); //iteration 1
    row_load(.rtype(2'b11), .rnum(2'd2), .rinput({16'd0, 16'd0, 16'd0, 16'd0}), .rpartial({16'd1, 16'd1, 16'd1, 16'd1}));
    repeat(5) @(posedge tb_clk); //iteration 2
    row_load(.rtype(2'b11), .rnum(2'd3), .rinput({16'd0, 16'd0, 16'd0, 16'd0}), .rpartial({16'd1, 16'd1, 16'd1, 16'd1}));
    repeat(6) @(posedge tb_clk); //iteration 3
    repeat(6) @(posedge tb_clk); //iteration 4
    repeat(6) @(posedge tb_clk); //iteration 5
    repeat(6) @(posedge tb_clk); //iteration 6
    repeat(6) @(posedge tb_clk); //iteration 7
    repeat(6) @(posedge tb_clk); //iteration 8
    repeat(6) @(posedge tb_clk); //iteration 9
    repeat(6) @(posedge tb_clk); //iteration 10
    repeat(6) @(posedge tb_clk); //iteration 11
    repeat(6) @(posedge tb_clk); //iteration 12
    $display("array should be drained %d", memory_if.drained);
    $display("fifos should have space  %d", memory_if.fifo_has_space);
    //BASIC 2x2 with different timing
    $display("BASIC 2X2 Example with timing changes Simple Partials");
    //LOAD WEIGHTS
    row_load(.rtype(2'b00), .rnum(2'd0), .rinput({16'd1, 16'd2, 16'd0, 16'd0}), .rpartial(64'b0));
    row_load(.rtype(2'b00), .rnum(2'd1), .rinput({16'd3, 16'd4, 16'd0, 16'd0}), .rpartial(64'b0));
    row_load(.rtype(2'b00), .rnum(2'd2), .rinput({16'd0, 16'd0, 16'd0, 16'd0}), .rpartial(64'b0));
    row_load(.rtype(2'b00), .rnum(2'd3), .rinput({16'd0, 16'd0, 16'd0, 16'd0}), .rpartial(64'b0));
    //LOAD INPUTS AND PARTIALS TOGETHER
    row_load(.rtype(2'b11), .rnum(2'd0), .rinput({16'd5, 16'd6, 16'd0, 16'd0}), .rpartial({16'd0, 16'd0, 16'd1, 16'd1}));
    repeat(2) @(posedge tb_clk); //iteration 0 delay of 6 for mul_len+add_len+1
    row_load(.rtype(2'b11), .rnum(2'd1), .rinput({16'd7, 16'd8, 16'd0, 16'd0}), .rpartial({16'd0, 16'd0, 16'd1, 16'd1}));
    repeat(5) @(posedge tb_clk); //iteration 1
    row_load(.rtype(2'b11), .rnum(2'd2), .rinput({16'd0, 16'd0, 16'd0, 16'd0}), .rpartial({16'd1, 16'd1, 16'd1, 16'd1}));
    repeat(5) @(posedge tb_clk); //iteration 2
    row_load(.rtype(2'b11), .rnum(2'd3), .rinput({16'd0, 16'd0, 16'd0, 16'd0}), .rpartial({16'd1, 16'd1, 16'd1, 16'd1}));
    repeat(6) @(posedge tb_clk); //iteration 3
    repeat(6) @(posedge tb_clk); //iteration 4
    repeat(6) @(posedge tb_clk); //iteration 5
    repeat(6) @(posedge tb_clk); //iteration 6
    repeat(6) @(posedge tb_clk); //iteration 7
    repeat(6) @(posedge tb_clk); //iteration 8
    repeat(6) @(posedge tb_clk); //iteration 9
    repeat(6) @(posedge tb_clk); //iteration 10
    repeat(6) @(posedge tb_clk); //iteration 11
    repeat(6) @(posedge tb_clk); //iteration 12
    $display("array should be drained %d", memory_if.drained);
    $display("fifos should have space  %d", memory_if.fifo_has_space);
    // FULL 4x4 Single Operation Example
    $display("Full 4X4 Example");
    // LOAD WEIGHTS
    row_load(.rtype(2'b00), .rnum(2'd0), .rinput({16'd7, 16'd4, 16'd8, 16'd5}), .rpartial(64'b0));
    row_load(.rtype(2'b00), .rnum(2'd1), .rinput({16'd7, 16'd3, 16'd7, 16'd8}), .rpartial(64'b0));
    row_load(.rtype(2'b00), .rnum(2'd2), .rinput({16'd5, 16'd4, 16'd8, 16'd8}), .rpartial(64'b0));
    row_load(.rtype(2'b00), .rnum(2'd3), .rinput({16'd3, 16'd6, 16'd5, 16'd2}), .rpartial(64'b0));
    // LOAD INPUTS + PARTIALS TOGETHER
    row_load(.rtype(2'b11), .rnum(2'd0), .rinput({16'd8, 16'd6, 16'd2, 16'd5}), .rpartial({16'd2, 16'd5, 16'd8, 16'd9}));
    repeat(2) @(posedge tb_clk); // example small initial delay
    row_load(.rtype(2'b11), .rnum(2'd1), .rinput({16'd1, 16'd6, 16'd9, 16'd1}), .rpartial({16'd9, 16'd1, 16'd9, 16'd7}));
    repeat(5) @(posedge tb_clk); // iteration 1 delay
    row_load(.rtype(2'b11), .rnum(2'd2), .rinput({16'd3, 16'd7, 16'd4, 16'd9}), .rpartial({16'd9, 16'd8, 16'd1, 16'd8}));
    repeat(5) @(posedge tb_clk); // iteration 2 delay
    row_load(.rtype(2'b11), .rnum(2'd3), .rinput({16'd3, 16'd5, 16'd3, 16'd7}), .rpartial({16'd8, 16'd3, 16'd1, 16'd8}));
    repeat(6) @(posedge tb_clk); // iteration 3
    repeat(6) @(posedge tb_clk); // iteration 4
    repeat(6) @(posedge tb_clk); // iteration 5
    repeat(6) @(posedge tb_clk); // iteration 6
    repeat(6) @(posedge tb_clk); // iteration 7
    repeat(6) @(posedge tb_clk); // iteration 8
    repeat(6) @(posedge tb_clk); // iteration 9
    repeat(6) @(posedge tb_clk); // iteration 10
    repeat(6) @(posedge tb_clk); // iteration 11
    repeat(6) @(posedge tb_clk); // iteration 12
    $display("array should be drained %d", memory_if.drained);
    $display("fifos should have space  %d", memory_if.fifo_has_space);
    reset();
    // PIPELINED EXAMPLE
    $display("Pipelined Example");
    // LOAD WEIGHTS
    row_load(.rtype(2'b00), .rnum(2'd0), .rinput({16'd7, 16'd4, 16'd8, 16'd5}), .rpartial(64'b0));
    row_load(.rtype(2'b00), .rnum(2'd1), .rinput({16'd7, 16'd3, 16'd7, 16'd8}), .rpartial(64'b0));
    row_load(.rtype(2'b00), .rnum(2'd2), .rinput({16'd5, 16'd4, 16'd8, 16'd8}), .rpartial(64'b0));
    row_load(.rtype(2'b00), .rnum(2'd3), .rinput({16'd3, 16'd6, 16'd5, 16'd2}), .rpartial(64'b0));
    // FIRST SET OF INPUTS + PARTIALS
    row_load(.rtype(2'b11), .rnum(2'd0), .rinput({16'd8, 16'd6, 16'd2, 16'd5}), .rpartial({16'd2, 16'd5, 16'd8, 16'd9}));
    repeat(2) @(posedge tb_clk); // iteration 0 delay
    row_load(.rtype(2'b11), .rnum(2'd1), .rinput({16'd1, 16'd6, 16'd9, 16'd1}), .rpartial({16'd9, 16'd1, 16'd9, 16'd7}));
    repeat(4) @(posedge tb_clk); // iteration 1 delay
    row_load(.rtype(2'b11), .rnum(2'd2), .rinput({16'd3, 16'd7, 16'd4, 16'd9}), .rpartial({16'd9, 16'd8, 16'd1, 16'd8}));
    $display("after iteration 1 of the first gemm, not all input rows have been loaded");
    $display("fifos should not have space  %d", memory_if.fifo_has_space);
    repeat(4) @(posedge tb_clk); // iteration 2 delay
    row_load(.rtype(2'b11), .rnum(2'd3), .rinput({16'd3, 16'd5, 16'd3, 16'd7}), .rpartial({16'd8, 16'd3, 16'd1, 16'd8}));
    repeat(4) @(posedge tb_clk); // iteration 3
    $display("after first array is fully loaded into array");
    $display("array should not be drained %d", memory_if.drained);
    $display("fifos should have space  %d", memory_if.fifo_has_space);
    // SECOND SET (PIPELINED) INPUTS + PARTIALS (no extra initial delay)
    row_load(.rtype(2'b11), .rnum(2'd0), .rinput({16'd5, 16'd9, 16'd7, 16'd2}), .rpartial({16'd3, 16'd3, 16'd1, 16'd5}));
    repeat(4) @(posedge tb_clk); // iteration 0
    row_load(.rtype(2'b11), .rnum(2'd1), .rinput({16'd4, 16'd9, 16'd2, 16'd9}), .rpartial({16'd7, 16'd9, 16'd7, 16'd9}));
    repeat(4) @(posedge tb_clk); // iteration 1
    row_load(.rtype(2'b11), .rnum(2'd2), .rinput({16'd5, 16'd2, 16'd4, 16'd7}), .rpartial({16'd8, 16'd2, 16'd1, 16'd7}));
    repeat(4) @(posedge tb_clk); // iteration 2
    row_load(.rtype(2'b11), .rnum(2'd3), .rinput({16'd8, 16'd3, 16'd1, 16'd4}), .rpartial({16'd7, 16'd8, 16'd5, 16'd3}));
    repeat(5) @(posedge tb_clk); // iteration 3
    repeat(5) @(posedge tb_clk); // iteration 4
    repeat(5) @(posedge tb_clk); // iteration 5
    repeat(5) @(posedge tb_clk); // iteration 6
    repeat(5) @(posedge tb_clk); // iteration 7
    repeat(5) @(posedge tb_clk); // iteration 8
    repeat(5) @(posedge tb_clk); // iteration 9
    repeat(5) @(posedge tb_clk); // iteration 10
    repeat(5) @(posedge tb_clk); // iteration 11
    repeat(5) @(posedge tb_clk); // iteration 12

    $display("array should be drained %d", memory_if.drained);
    $display("fifos should have space  %d", memory_if.fifo_has_space);
    #50;
    $stop;
  end

endmodule


