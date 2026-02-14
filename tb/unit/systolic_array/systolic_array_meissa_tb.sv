`include "systolic_array_if.vh"
`include "systolic_array_control_unit_if.vh"
`include "systolic_array_MAC_if.vh"
`include "systolic_array_add_if.vh"
`include "systolic_array_FIFO_if.vh"
`include "systolic_array_tb_pkg.sv"

`timescale 1 ns / 1 ns

module systolic_array_tb();
    import systolic_array_tb_pkg::*;

    // Parameters
    // parameter int N = 4;
    // parameter WIDTH = 16;

    // clk/reset
    logic tb_nRST;

    // Memory interface instance
    systolic_array_if #(.array_dim(ARRAY_DIM), .data_w(DATA_WIDTH)) memory_if();

    // Clock gen
    parameter PERIOD = 10;
    logic tb_clk = 0;
    always #(PERIOD/2) tb_clk++;
    // FILE I/O
    int out_file, file;
    /* verilator lint_off UNUSEDSIGNAL */
    string line;
    /* verilator lint_off UNUSEDSIGNAL */
    logic [DATA_WIDTH-1:0] temp_weights[ARRAY_DIM][ARRAY_DIM];
    logic [DATA_WIDTH-1:0] temp_inputs[ARRAY_DIM][ARRAY_DIM];
    logic [DATA_WIDTH-1:0] temp_partials[ARRAY_DIM][ARRAY_DIM];
    logic [DATA_WIDTH-1:0] temp_outputs[ARRAY_DIM][ARRAY_DIM];

    logic [(ARRAY_DIM*DATA_WIDTH)-1:0] m_weights[ARRAY_DIM];
    logic [(ARRAY_DIM*DATA_WIDTH)-1:0] m_inputs[ARRAY_DIM];
    logic [(ARRAY_DIM*DATA_WIDTH)-1:0] m_partials[ARRAY_DIM];
    logic [(ARRAY_DIM*DATA_WIDTH)-1:0] m_outputs[ARRAY_DIM];
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

  // 
  task row_load(
    input logic [1:0] rtype,
    input logic [$clog2(ARRAY_DIM)-1:0] rinnum,
    input logic [$clog2(ARRAY_DIM)-1:0] rpsnum,
    input logic [(ARRAY_DIM*DATA_WIDTH)-1:0] rinput,
    input logic [(ARRAY_DIM*DATA_WIDTH)-1:0] rpartial
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
    string token;
    string section;
    weights = 0;

    // Read section header: Weight
    void'($fgets(line, file));
    section = line.toupper();

    if (section.find("WEIGHT") != -1) begin
        weights = 1;
        // Read Weights
        for (int i = 0; i < ARRAY_DIM; i++) begin
            void'($fgets(line, file));
            for (int j = 0; j < ARRAY_DIM; j++) begin
                token = line.substr(j*7, 6); // "0xXXXX"
                $sscanf(token, "%h", temp_weights[i][j]);
            end
        end
        // Skip blank line
        void'($fgets(line, file));

        // Read Input header
        void'($fgets(line, file));
    end
    
    // Reads Inputs
    for (int i = 0; i < ARRAY_DIM; i++) begin
        void'($fgets(line, file));
        for (int j = 0; j < ARRAY_DIM; j++) begin
            token = line.substr(j*7, 6);
            $sscanf(token, "%h", temp_inputs[i][j]);
        end
    end

    // Skip blank line
    void'($fgets(line, file));

    // Read Psum header
    void'($fgets(line, file));

    // Read Psums
    for (int i = 0; i < ARRAY_DIM; i++) begin
        void'($fgets(line, file));
        for (int j = 0; j < ARRAY_DIM; j++) begin
            token = line.substr(j*7, 6);
            $sscanf(token, "%h", temp_partials[i][j]);
        end
    end

    // Pack rows into wide buses
    for (int i = 0; i < ARRAY_DIM; i++) begin
        m_weights[i]  = {>>{temp_weights[i]}};
        m_inputs[i]   = {>>{temp_inputs[i]}};
        m_partials[i] = {>>{temp_partials[i]}};
    end
endtask

    task get_m_output();
        string token;
        for (int i = 0 ; i < ARRAY_DIM; i++) begin
            void'($fgets(line, out_file));
            for (int j = 0; j < ARRAY_DIM; j++) begin
                token = line.substr(j * 7, 6);
                $sscanf(token, "%h", temp_outputs[i][j]);
            end
            m_outputs[i] = {>>{temp_outputs[i]}};
        end
    endtask

  task load_weights();
    for (int r = 0; r < ARRAY_DIM; r++)begin
      /* verilator lint_off WIDTHTRUNC */
      row_load(.rtype(2'b00), .rinnum(r), .rpsnum('0), .rinput(m_weights[r]), .rpartial('0));
      /* verilator lint_off WIDTHTRUNC */
    end
  endtask

  task load_in_ps(input int delay);
    for (int in = 0; in < ARRAY_DIM; in++)begin
      /* verilator lint_off WIDTHTRUNC */
      row_load(.rtype(2'b11), .rinnum(in), .rpsnum(in), .rinput(m_inputs[in]), .rpartial(m_partials[in]));
      /* verilator lint_off WIDTHTRUNC */
      repeat(delay) @(posedge tb_clk); // everyone else iteration delay
    end
  endtask

  // Instantiate the DUT
  systolic_array #(
    .N(ARRAY_DIM),
    .WIDTH(DATA_WIDTH)
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
        $display("Our Output is");
        for (int y = 0; y < ARRAY_DIM; y++)begin
          $write("%d, ", memory_if.array_output[(y+1)*DATA_WIDTH-1-:DATA_WIDTH]);
        end
        $display("");
      end
      $display("Correct Output is");
      for (int z = 0; z < ARRAY_DIM; z++)begin
          $write("%d, ", m_outputs[memory_if.row_out][(z+1)*DATA_WIDTH-1-:DATA_WIDTH]);
      end
      $display("");
      /* verilator lint_off WIDTHEXPAND */
      if (memory_if.row_out == ARRAY_DIM-1)begin
      /* verilator lint_off WIDTHEXPAND */
        get_m_output();
      end
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
    
    // any file
    file = $fopen(PATH_TO_INPUT, "r");
    out_file = $fopen(PATH_TO_EXPECTED_RESULT, "r");
    reset();

    while (!$feof(file)) begin
        // Go through All test cases in File
        do begin
            $fgets(line, file);
        end while ((line.substr(0, 3) != "Test") || (line.substr(0, 3) != "Input") && !$feof(file));
        if (!$feof(file)) begin
            loaded_weights = 0;
            get_matrices(.weights(loaded_weights));
            get_m_output();
            if (loaded_weights == 1)begin
            // LOAD WEIGHTS
            load_weights();
            end
            load_in_ps(.delay(1));

            wait(memory_if.drained == 1'b1);
        end
    end

    $display("array should be drained %d", memory_if.drained);
    $display("fifos should have space  %d", memory_if.fifo_has_space);

    $fclose(file);
    $fclose(out_file);
    #50;
    $stop;
  end

endmodule


