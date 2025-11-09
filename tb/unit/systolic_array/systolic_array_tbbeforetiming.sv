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
  // FILE I/O
  int out_file, file, output_delay, k, i, j, z, y, r, in, which;
  /* verilator lint_off UNUSEDSIGNAL */
  string line;
  /* verilator lint_off UNUSEDSIGNAL */
  logic [WIDTH-1:0] temp_weights[N][N];
  logic [WIDTH-1:0] temp_inputs[N][N];
  logic [WIDTH-1:0] temp_partials[N][N];
  logic [WIDTH-1:0] temp_outputs[N][N];

  logic [(N*WIDTH)-1:0] m_weights[N];
  logic [(N*WIDTH)-1:0] m_inputs[N];
  logic [(N*WIDTH)-1:0] m_partials[N];
  logic [(N*WIDTH)-1:0] m_outputs[N];
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
    input logic [(N*WIDTH)-1:0] rinput,
    input logic [(N*WIDTH)-1:0] rpartial
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
      weights = 0;
      which = 0;
      $fgets(line, file);
      if (line == "Weights\n") begin
        which = 1;
        weights = 1;
      end else if (line == "Inputs\n") begin
        which = 2;
      end
      for (k = 0; k < 3; k++) begin
        for (i = 0; i < N; i = i + 1) begin
          for (j = 0; j < N; j = j + 1) begin
            if (which == 1)begin
              $fscanf(file, "%d ", temp_weights[i][j]);
            end else if (which == 2) begin
              $fscanf(file, "%d ", temp_inputs[i][j]);
            end else begin
              $fscanf(file, "%d ", temp_partials[i][j]);
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
    end
  endtask
  task get_m_output;
    begin
      for (i = 0; i < N; i = i + 1) begin
        for (j = 0; j < N; j = j + 1) begin
          $fscanf(out_file, "%d ", temp_outputs[i][N-1-j]);
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
    for (r = 0; r < N; r++)begin
      /* verilator lint_off WIDTHTRUNC */
      row_load(.rtype(2'b00), .rinnum(r), .rpsnum('0), .rinput(m_weights[r]), .rpartial('0));
      /* verilator lint_off WIDTHTRUNC */
    end
  endtask
  task load_in_ps(input int delay);
    for (in = 0; in < N; in++)begin
      /* verilator lint_off WIDTHTRUNC */
      row_load(.rtype(2'b11), .rinnum(in), .rpsnum(in), .rinput(m_inputs[in]), .rpartial(m_partials[in]));
      /* verilator lint_off WIDTHTRUNC */
      repeat(delay) @(posedge tb_clk); // everyone else iteration delay
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
      if (m_outputs[memory_if.row_out] != memory_if.array_output)begin
        $display("Output incorrect\n");
        $display("Our Output is\n");
        for (y = 0; y < N; y++)begin
          $write("%d, ", memory_if.array_output[(y+1)*WIDTH-1-:WIDTH]);
        end
        $display("");
      end
      $display("Correct Output is");
      for (z = 0; z < N; z++)begin
          $write("%d, ", m_outputs[memory_if.row_out][(z+1)*WIDTH-1-:WIDTH]);
      end
      $display("");
    end
  end
  // Test Stimulus
  initial begin
    $dumpfile("dump.vcd");  // For VCD format
    $dumpvars(0, systolic_array_tb);
    memory_if.weight_en = '0;
    memory_if.input_en = '0;
    memory_if.partial_en = '0;
    memory_if.row_in_en = '0;
    memory_if.row_ps_en = '0;
    memory_if.array_in = '0;
    memory_if.array_in_partials = '0;
    loaded_weights = 0;
    output_delay = 0;
    
    // any file
    file = $fopen("matops2.txt", "r");
    $system("/bin/python3 /home/asicfab/a/wagne329/tensor-core/matrix_mul.py matops2");
    out_file = $fopen("matops2_output.txt", "r");
    reset();
    while (!$feof(file)) begin
      get_matrices(.weights(loaded_weights));
      if (loaded_weights == 1)begin
        // LOAD WEIGHTS
        load_weights();
      end
      load_in_ps (.delay(N-1));
      if (output_delay == 1)begin
        get_m_output();
      end
      output_delay = 1;
    end
    repeat(N*(N+1)) @(posedge tb_clk); // first output drain
    get_m_output();
    repeat(N*(N+1)) @(posedge tb_clk); // last output drain
    $display("array should be drained %d", memory_if.drained);
    $display("fifos should have space  %d", memory_if.fifo_has_space);
    $fclose(file);
    $fclose(out_file);
    #50;
    $stop;
  end

endmodule


