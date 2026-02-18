`include "systolic_array_if.vh"
`include "systolic_array_control_unit_if.vh"
`include "systolic_array_MAC_if.vh"
`include "systolic_array_add_if.vh"
`include "systolic_array_FIFO_if.vh"
`include "systolic_array_tb_pkg.sv"
`include "gsau_control_interface.vh"

`timescale 1 ns / 1 ns

module systolic_array_tb();
    import systolic_array_tb_pkg::*;

    // Parameters
    // parameter int N = 4;
    // parameter WIDTH = 16;

    // clk/reset
    logic nRST;

    // Systolic Array Interface
    gsau_control_unit_if gsau_if();

    // Clock gen
    parameter PERIOD = 10;
    logic CLK = 0;
    always #(PERIOD/2) CLK++;
    // FILE I/O
    int out_file, file, actual_output_file;
    /* verilator lint_off UNUSEDSIGNAL */
    string line;
    /* verilator lint_off UNUSEDSIGNAL */
    logic [DATA_WIDTH-1:0] temp_weights[ARRAY_DIM][ARRAY_DIM];
    logic [DATA_WIDTH-1:0] temp_inputs[ARRAY_DIM][ARRAY_DIM];
    logic [DATA_WIDTH-1:0] temp_partials[ARRAY_DIM][ARRAY_DIM];
    logic [DATA_WIDTH-1:0] temp_exp_outputs[ARRAY_DIM][ARRAY_DIM];
    logic [DATA_WIDTH-1:0] temp_act_outputs[ARRAY_DIM][ARRAY_DIM];

    logic [(ARRAY_DIM*DATA_WIDTH)-1:0] m_weights[ARRAY_DIM];
    logic [(ARRAY_DIM*DATA_WIDTH)-1:0] m_inputs[ARRAY_DIM];
    logic [(ARRAY_DIM*DATA_WIDTH)-1:0] m_partials[ARRAY_DIM];
    logic [(ARRAY_DIM*DATA_WIDTH)-1:0] m_exp_outputs[ARRAY_DIM];
    logic [(ARRAY_DIM*DATA_WIDTH)-1:0] m_act_outputs[ARRAY_DIM];
    int loaded_weights;

    task reset();
        begin
        nRST = 1'b0;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        nRST = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        end
    endtask

    task get_matrices(output int weights);
        string token;
        string section;
        weights = 0;

        // Read section header: Weight
        void'($fgets(line, file));
        section = line.toupper();

        if (section.len() >= 5 && section.substr(0,4) == "WEIGHT") begin
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
                $sscanf(token, "%h", temp_exp_outputs[i][j]);
            end
            m_exp_outputs[i] = {>>{temp_exp_outputs[i]}};
        end
    endtask

    task load_weights();
        gsau_if.sa_input_en   = 1'b0;
        gsau_if.sa_partial_en = 1'b0;
        gsau_if.sa_weight_en  = 1'b0;
        gsau_if.sa_array_in   = '0;

        for (int column = 0; column < ARRAY_DIM; column++) begin
            while (!gsau_if.sa_ready_in) @(posedge CLK);

            // Pack column k of W into the bus
            gsau_if.sa_array_in = '0;
            for (int row = 0; row < ARRAY_DIM; row++) begin
                gsau_if.sa_array_in[DATA_WIDTH*row +: DATA_WIDTH] = temp_weights[row][column];
            end

            gsau_if.sa_weight_en = 1'b1;
            @(posedge CLK);
        end

        gsau_if.sa_weight_en = 1'b0;
        gsau_if.sa_array_in  = '0;
    endtask

    task load_inputs();
        gsau_if.sa_weight_en = 1'b0;
        gsau_if.sa_partial_en = 1'b0;
        gsau_if.sa_input_en = 1'b0;
        gsau_if.sa_array_in = '0;

        for (int column = 0; column < ARRAY_DIM; column++) begin
            while (!gsau_if.sa_ready_in) @(posedge CLK);

            gsau_if.sa_array_in = '0;
            for (int row = 0; row < ARRAY_DIM; row++) begin
                gsau_if.sa_array_in[DATA_WIDTH * row +: DATA_WIDTH] = temp_inputs[row][column];
                gsau_if.sa_array_in_partials[DATA_WIDTH * row +: DATA_WIDTH] = temp_partials[row][column];
            end
            gsau_if.sa_input_en = 1'b1;
            gsau_if.sa_partial_en = 1'b1;
            @(posedge CLK);
        end

        gsau_if.sa_input_en = 1'b0;
        gsau_if.sa_array_in = '0;
    endtask

    task load_psums();
        gsau_if.sa_weight_en = 1'b0;
        gsau_if.sa_input_en = 1'b0;
        gsau_if.sa_partial_en = 1'b0;
        gsau_if.sa_array_in_partial = '0;

        for (int column = 0; column < ARRAY_DIM; column++) begin
            while (!gsau_if.sa_ready_in) begin
                @(posedge CLK);
            end

            gsau_if.sa_array_in_partials = '0;
            for (int row = 0; row < ARRAY_DIM; row++) begin
                gsau_if.sa_array_in_partials[DATA_WIDTH * row +: DATA_WIDTH] = temp_partials[row][column];
            end

            gsau_if.sa_partial_en = 1'b1;
            @(posedge CLK);
        end

        gsau_if.sa_partials_en = 1'b0;
        gsau_if.sa_array_in_partials = '0;
    endtask

    task write_matrix(input string test_name);
        $fwrite(actual_output_file, "%s\n", test_name);

        for (int row = 0; row < ARRAY_DIM; row++) begin
            for (int column = 0; column < ARRAY_DIM; column++) begin
                $fwrite(actual_output_file, "0x%04h", temp_act_outputs[row][column]);
                
                if (column != ARRAY_DIM - 1) begin
                    $fwrite(actual_output_file, ",");
                end
            end
            $fwrite(actual_output_file, "\n");
        end
    endtask

    sysarr_MEISSA_top DUT (
        .clk(CLK),
        .nRST(nRST),
        .gsau_if(gsau_if.systolic_array)
    );

  // Test Stimulus
  initial begin
    $dumpfile("dump.vcd");  // For VCD format
    $dumpvars(0, systolic_array_tb);

    gsau_if.sa_array_in = '0;
    gsau_if.sa_array_in_partials = '0;
    gsau_if.sa_input_en = 1'b0;
    gsau_if.sa_weight_en = 1'b0;
    gsau_if.sa_partial_en = 1'b0;
    gsau_if.sa_ready_out = 1'b1;
    
    // any file
    file = $fopen(PATH_TO_INPUT, "r");
    out_file = $fopen(PATH_TO_EXPECTED_RESULT, "r");
    actual_output_file = $fopen(PATH_TO_RESULT, "w");
    reset();

    forever begin
        string test_name;
        bit found_test;
        found_test = 0;
        
        while (!found_test) begin
            if ($fgets(line, file) == 0) begin
               break;
            end

            if (line.len() >= 4 && line.substr(0,3) == "Test") begin
                test_name = line;
                found_test = 1;
            end
        end

        if (!found_test) begin
            break;
        end

        loaded_weights = 0;
        get_matrices(.weights(loaded_weights));
        // get_m_output();

        if (loaded_weights) begin
            load_weights();
        end

        // load_psums();

        load_inputs();

        for (int i = 0; i < ARRAY_DIM; i++) begin
            m_act_outputs[i] = '0;
            for (int j = 0; j < ARRAY_DIM; j++) begin
                temp_act_outputs[i][j] = '0;
            end
        end

        int row;
        row = 0;
        while (row < ARRAY_DIM) begin
            @(posedge CLK);
            if (gsau_if.sa_valid_in) begin
                m_act_outputs[row] = gsau_if.sa_array_output;
                for (int i = 0; i < ARRAY_DIM; i++) begin
                    temp_act_outputs[row][i] = gsau_if.sa_array_output[DATA_WIDTH*i +: DATA_WIDTH];
                end
                row++;
            end
        end
        write_matrix(test_name);
    end

    $fclose(file);
    $fclose(out_file);
    $fclose(actual_output_file);
    #50;
    $stop;
  end

endmodule


