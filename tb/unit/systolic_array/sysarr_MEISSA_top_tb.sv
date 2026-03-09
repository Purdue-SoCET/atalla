//`include "systolic_array_if.vh"
//`include "systolic_array_control_unit_if.vh"
`include "systolic_array_MAC_if.vh"
//`include "systolic_array_add_if.vh"
//`include "systolic_array_FIFO_if.vh"
`include "systolic_array_tb_pkg.sv"
`include "gsau_control_unit_if.vh"

`timescale 1 ns / 1 ns

module sysarr_MEISSA_top_tb();
    import systolic_array_tb_pkg::*;

    // Parameters
    // parameter int N = 4;
    // parameter WIDTH = 16;

    integer total_passed_tests = 0;
    integer total_tests = 0;

    // clk/reset
    logic nRST;

    // Systolic Array Interface
    gsau_control_unit_if gsau_if();

    // Clock gen
    parameter PERIOD = 10;
    logic CLK = 0;
    always #(PERIOD/2) CLK++;
    // FILE I/O
    int expected_out_file, file, actual_output_file;
    /* verilator lint_off UNUSEDSIGNAL */
    string line, test_name;
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
    int pending_gemms = 0;
    string test_name_queue[$];
    bit input_eof = 0;
    event gemm_completed;

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

    task get_matrices(output int weights, input int has_weights);
        string token;
        string section;
        weights = 0;


        // Read section header: Weight
        void'($fgets(line, file));
        section = line.toupper();

        if (section.len() >= 5 && section.substr(0,5) == "WEIGHT") begin
            weights = 1;
            // Read Weights
            for (int i = 0; i < ARRAY_DIM; i++) begin
                void'($fgets(line, file));
                for (int j = 0; j < ARRAY_DIM; j++) begin
                    token = line.substr(j*7, (j*7)+6); // "0xXXXX"
                    void'($sscanf(token, "%h", temp_weights[i][j]));
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
                token = line.substr(j*7, (j*7)+6);
                void'($sscanf(token, "%h", temp_inputs[i][j]));
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
                token = line.substr(j*7, (j*7)+6);
                void'($sscanf(token, "%h", temp_partials[i][j]));
            end
        end

        // Pack rows into wide buses
        for (int i = 0; i < ARRAY_DIM; i++) begin
            m_weights[i]  = {>>{temp_weights[i]}};
            m_inputs[i]   = {>>{temp_inputs[i]}};
            m_partials[i] = {>>{temp_partials[i]}};
        end
    endtask

    task get_m_expected_output();
        string token;
        for (int i = 0 ; i < ARRAY_DIM; i++) begin
            void'($fgets(line, expected_out_file));
            for (int j = 0; j < ARRAY_DIM; j++) begin
                token = line.substr(j * 7, (j*7)+6);
                void'($sscanf(token, "%h", temp_exp_outputs[i][j]));
            end
            // m_exp_outputs[i] = {>>{temp_exp_outputs[i]}};
        end
    endtask

    task load_weights();
        gsau_if.sa_input_en   = 1'b0;
        gsau_if.sa_partial_en = 1'b0;
        gsau_if.sa_weight_en  = 1'b0;
        gsau_if.sa_array_in   = '0;

        for (int column = ARRAY_DIM - 1; column >= 0; column--) begin
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

        for (int row = 0; row < ARRAY_DIM; row++) begin
            while (!gsau_if.sa_ready_in) @(posedge CLK);

            gsau_if.sa_array_in = '0;
            for (int column = 0; column < ARRAY_DIM; column++) begin
                gsau_if.sa_array_in[DATA_WIDTH * column +: DATA_WIDTH] = temp_inputs[row][column];
                gsau_if.sa_array_in_partials[DATA_WIDTH * column +: DATA_WIDTH] = temp_partials[row][column];
            end
            gsau_if.sa_partial_en = 1;
            gsau_if.sa_input_en = 1'b1;
            @(posedge CLK);
        end

        // for (int column = 0; column < ARRAY_DIM; column++) begin
        //     while (!gsau_if.sa_ready_in) @(posedge CLK);

        //     gsau_if.sa_array_in = '0;
        //     for (int row = 0; row < ARRAY_DIM; row++) begin
        //         gsau_if.sa_array_in[DATA_WIDTH * row +: DATA_WIDTH] = temp_inputs[row][column];
        //         gsau_if.sa_array_in_partials[DATA_WIDTH * row +: DATA_WIDTH] = temp_partials[row][column];
        //     end
        //     gsau_if.sa_partial_en = 1;
        //     gsau_if.sa_input_en = 1'b1;
        //     @(posedge CLK);
        // end

        gsau_if.sa_input_en = 1'b0;
        gsau_if.sa_array_in = '0;
        gsau_if.sa_partial_en = 1'b0;
        gsau_if.sa_array_in_partials = '0;
    endtask

    task load_psums();
        gsau_if.sa_weight_en = 1'b0;
        gsau_if.sa_input_en = 1'b0;
        gsau_if.sa_partial_en = 1'b0;
        gsau_if.sa_array_in_partials = '0;

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

        gsau_if.sa_partial_en = 1'b0;
        gsau_if.sa_array_in_partials = '0;
    endtask

    task write_matrix(input string test_name);
        $fwrite(actual_output_file, "%s", test_name);

        for (int row = 0; row < ARRAY_DIM; row++) begin
            for (int column = 0; column < ARRAY_DIM; column++) begin
                $fwrite(actual_output_file, "0x%04H", temp_act_outputs[row][column]);
                
                if (column != ARRAY_DIM - 1) begin
                    $fwrite(actual_output_file, ",");
                end
            end
            $fwrite(actual_output_file, "\n");
        end
        $fwrite(actual_output_file, "\n");
    endtask

generate
    if(VERSION == "MEISSA" || VERSION == "MEISSA32") begin
        // DUT Instantiation: MIXED ADDER TREE
        // sysarr_MEISSA_top #(.USE_MIXED_ADDER(1)) DUT (CLK, nRST, gsau_if);

        // DUT Instantiation: 2-INPUT ADDER TREE
        sysarr_MEISSA_top DUT (CLK, nRST, gsau_if);
    end
    else if (VERSION == "TPU") begin
        TPU_top DUT(CLK, nRST, gsau_if);
    end
    else begin
        initial $fatal("Unsupported VERSION: %s", VERSION);
    end
endgenerate

  // Simulation timeout
//   initial begin
//     // #2;
//     $display("TIMEOUT: Simulation exceeded 50000 ns");
//     $finish;
//   end

// Initialize signals and files
initial begin
    gsau_if.sa_array_in        = '0;
    gsau_if.sa_array_in_partials = '0;
    gsau_if.sa_input_en        = 1'b0;
    gsau_if.sa_weight_en       = 1'b0;
    gsau_if.sa_partial_en      = 1'b0;
    gsau_if.sa_ready_out       = 1'b1;

    file               = $fopen(PATH_TO_INPUT, "r");
    expected_out_file  = $fopen(PATH_TO_EXPECTED_RESULT, "r");
    actual_output_file = $fopen(PATH_TO_RESULT, "w");
end

// Process 1: Feed inputs
initial begin
    int input_row;
    bit found_test;
    bit found_input;
    bit loaded_weights;
    input_row = 0;

    reset();

    forever begin
        @(posedge CLK);
        if (gsau_if.sa_ready_in) begin

            if (input_row == 0) begin
                // Find next test or input label
                found_test  = 0;
                found_input = 0;
                gsau_if.sa_input_en   = 1'b0;
                gsau_if.sa_partial_en = 1'b0;
                gsau_if.sa_array_in = '0;
                gsau_if.sa_array_in_partials = '0;
                while (!found_test) begin
                    if ($fgets(line, file) == 0) begin
                        break;
                    end
                    if (line.len() >= 4 && line.substr(0,3) == "Test") begin
                        // test_name  = line;
                        test_name_queue.push_front(line);
                        test_name = line;
                        found_test = 1;
                    end 
                end

                if (!found_test) begin
                    input_eof = 1'b1;
                    gsau_if.sa_input_en   = 1'b0;
                    gsau_if.sa_partial_en = 1'b0;
                    gsau_if.sa_array_in = '0;
                    gsau_if.sa_array_in_partials = '0;
                    break; // EOF
                end
                

                // Load weights/inputs from file
                loaded_weights = 0;
                if (found_test) begin
                    get_matrices(.weights(loaded_weights), .has_weights(1));
                    if (loaded_weights) begin
                        while (pending_gemms != 0) begin
                            @(gemm_completed);
                        end
                        load_weights();
                    end
                end

                pending_gemms++;
            end


            gsau_if.sa_input_en   = 1'b0;
            gsau_if.sa_partial_en = 1'b0;
            // Drive inputs for current row
            for (int col = 0; col < ARRAY_DIM; col++) begin
                gsau_if.sa_array_in[DATA_WIDTH*col +: DATA_WIDTH] = temp_inputs[input_row][col];
                gsau_if.sa_array_in_partials[DATA_WIDTH*col +: DATA_WIDTH] = temp_partials[input_row][col];
            end
            gsau_if.sa_input_en   = 1'b1;
            gsau_if.sa_partial_en = 1'b1;

            input_row++;
            if (input_row == ARRAY_DIM) input_row = 0;

        end else begin
            gsau_if.sa_input_en   = 1'b0;
            gsau_if.sa_partial_en = 1'b0;
        end
    end
end

// Process 2: Collect and check outputs
initial begin
    int result_row;
    bit found_expected_result;
    bit is_result_correct;
    result_row = 0;

    for (int i = 0; i < ARRAY_DIM; i++) begin
        m_act_outputs[i] = '0;
        for (int j = 0; j < ARRAY_DIM; j++) begin
            temp_act_outputs[i][j] = '0;
        end
    end

    forever begin
        @(posedge CLK);
        if (input_eof && test_name_queue.size() == 0 && result_row == 0) begin
            $display("All queued tests processed. Ending simulation.");
            break;
        end

        if (gsau_if.sa_valid_in) begin
            // Collect output row
            m_act_outputs[result_row] = gsau_if.sa_array_output;
            for (int col = 0; col < ARRAY_DIM; col++) begin
                temp_act_outputs[result_row][col] = gsau_if.sa_array_output[DATA_WIDTH*col +: DATA_WIDTH];
            end

            result_row++;

            if (result_row == ARRAY_DIM) begin
                result_row = 0;

                // Read expected result
                found_expected_result = 0;
                while (!found_expected_result) begin
                    if ($fgets(line, expected_out_file) == 0) begin
                        break;
                    end
                    if (line.len() >= 4 && line.substr(0,3) == "Test")
                        found_expected_result = 1;
                end

                if (found_expected_result) begin
                    get_m_expected_output();
                end else begin
                    $display("Reached EOF in expected result file. Ending simulation.");
                    break;
                end

                // Compare actual vs expected
                is_result_correct = 1;
                for (int i = 0; i < ARRAY_DIM; i++) begin
                    for (int j = 0; j < ARRAY_DIM; j++) begin
                        if (temp_act_outputs[i][j] == 16'h8000) temp_act_outputs[i][j] = 16'h0000;
                        if (temp_exp_outputs[i][j] == 16'h8000) temp_exp_outputs[i][j] = 16'h0000;
                        if (temp_act_outputs[i][j] !== temp_exp_outputs[i][j]) begin
                            is_result_correct = 0;
                            $display("Test %s Failed at [%0d][%0d]: Expected 0x%04H Got 0x%04H",
                                test_name_queue[$ - 1], i, j, temp_exp_outputs[i][j], temp_act_outputs[i][j]);
                        end
                    end
                end

                total_tests++;
                // if (!is_result_correct) write_matrix(test_name);
                write_matrix(test_name_queue.pop_back());
                if (is_result_correct) begin 
                    total_passed_tests++;
                end
                if (pending_gemms > 0) begin
                    pending_gemms--;
                end
                -> gemm_completed;

                for (int i = 0; i < ARRAY_DIM; i++) begin
                    m_act_outputs[i] = '0;
                    for (int j = 0; j < ARRAY_DIM; j++) begin
                        temp_act_outputs[i][j] = '0;
                    end
                end
            end
        end
    end 

    $fclose(file);
    $fclose(expected_out_file);
    $fclose(actual_output_file);
    #50;
    $display("Passed Tests: %0d / %0d", total_passed_tests, total_tests);
    $finish;
end

endmodule
