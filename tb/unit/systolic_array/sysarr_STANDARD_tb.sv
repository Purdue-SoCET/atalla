`include "systolic_array_MAC_if.vh"
`include "systolic_array_tb_pkg.sv"
`include "gsau_control_unit_if.vh"

`timescale 1 ns / 1 ns

module sysarr_STANDARD_tb();
    import systolic_array_tb_pkg::*;

    integer total_passed_tests = 0;
    integer total_tests = 0;

    logic nRST;
    gsau_control_unit_if gsau_if();

    parameter PERIOD = 10;
    logic CLK = 0;
    always #(PERIOD/2) CLK++;

    // FILE I/O
    int expected_out_file, file, actual_output_file;
    /* verilator lint_off UNUSEDSIGNAL */
    string line, test_name;
    /* verilator lint_on UNUSEDSIGNAL */
    logic [DATA_WIDTH-1:0] temp_weights[ARRAY_DIM][ARRAY_DIM];
    logic [DATA_WIDTH-1:0] temp_inputs[ARRAY_DIM][ARRAY_DIM];
    logic [DATA_WIDTH-1:0] temp_partials[ARRAY_DIM][ARRAY_DIM];
    logic [DATA_WIDTH-1:0] temp_exp_outputs[ARRAY_DIM][ARRAY_DIM];
    logic [DATA_WIDTH-1:0] temp_act_outputs[ARRAY_DIM][ARRAY_DIM];

    int pending_gemms = 0;
    string test_name_queue[$];
    bit input_eof = 0;
    event gemm_completed;

    // ----------------------------------------------------------------
    // Tasks
    // ----------------------------------------------------------------

    task reset();
        nRST = 1'b0;
        gsau_if.sa_array_in          = '0;
        gsau_if.sa_array_in_partials = '0;
        gsau_if.sa_input_en          = 1'b0;
        gsau_if.sa_weight_en         = 1'b0;
        gsau_if.sa_partial_en        = 1'b0;
        gsau_if.sa_ready_out         = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        nRST = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
    endtask

    task get_matrices(output int weights, input int has_weights);
        string token;
        string section;
        weights = 0;

        void'($fgets(line, file));
        section = line.toupper();

        if (section.len() >= 5 && section.substr(0,5) == "WEIGHT") begin
            weights = 1;
            for (int i = 0; i < ARRAY_DIM; i++) begin
                void'($fgets(line, file));
                for (int j = 0; j < ARRAY_DIM; j++) begin
                    token = line.substr(j*7, (j*7)+6);
                    void'($sscanf(token, "%h", temp_weights[i][j]));
                end
            end
            void'($fgets(line, file)); // blank
            void'($fgets(line, file)); // Input header
        end

        for (int i = 0; i < ARRAY_DIM; i++) begin
            void'($fgets(line, file));
            for (int j = 0; j < ARRAY_DIM; j++) begin
                token = line.substr(j*7, (j*7)+6);
                void'($sscanf(token, "%h", temp_inputs[i][j]));
            end
        end

        void'($fgets(line, file)); // blank
        void'($fgets(line, file)); // Psum header

        for (int i = 0; i < ARRAY_DIM; i++) begin
            void'($fgets(line, file));
            for (int j = 0; j < ARRAY_DIM; j++) begin
                token = line.substr(j*7, (j*7)+6);
                void'($sscanf(token, "%h", temp_partials[i][j]));
            end
        end
    endtask

    task get_m_expected_output();
        string token;
        for (int i = 0; i < ARRAY_DIM; i++) begin
            void'($fgets(line, expected_out_file));
            for (int j = 0; j < ARRAY_DIM; j++) begin
                token = line.substr(j * 7, (j*7)+6);
                void'($sscanf(token, "%h", temp_exp_outputs[i][j]));
            end
        end
    endtask

    // Load weights column-by-column in reverse order (col N-1 first)
    task load_weights();
        gsau_if.sa_input_en  = 1'b0;
        gsau_if.sa_partial_en = 1'b0;
        gsau_if.sa_weight_en = 1'b0;
        gsau_if.sa_array_in  = '0;

        for (int col = ARRAY_DIM - 1; col >= 0; col--) begin
            gsau_if.sa_weight_en = 1'b1;
            for (int row = 0; row < ARRAY_DIM; row++)
                gsau_if.sa_array_in[DATA_WIDTH*row +: DATA_WIDTH] = temp_weights[row][col];
            @(posedge CLK);
        end

        gsau_if.sa_weight_en = 1'b0;
        gsau_if.sa_array_in  = '0;
    endtask

    // Feed activation rows — one per cycle, check sa_ready_in
    task load_inputs();
        gsau_if.sa_weight_en  = 1'b0;
        gsau_if.sa_input_en   = 1'b0;
        gsau_if.sa_partial_en = 1'b0;
        gsau_if.sa_array_in   = '0;
        gsau_if.sa_array_in_partials = '0;

        for (int row = 0; row < ARRAY_DIM; row++) begin
            while (!gsau_if.sa_ready_in) @(posedge CLK);

            for (int col = 0; col < ARRAY_DIM; col++) begin
                gsau_if.sa_array_in[DATA_WIDTH*col +: DATA_WIDTH] = temp_inputs[row][col];
                gsau_if.sa_array_in_partials[DATA_WIDTH*col +: DATA_WIDTH] = temp_partials[row][col];
            end
            gsau_if.sa_input_en   = 1'b1;
            gsau_if.sa_partial_en = 1'b1;
            @(posedge CLK);
            gsau_if.sa_input_en   = 1'b0;
            gsau_if.sa_partial_en = 1'b0;
            gsau_if.sa_array_in   = '0;
            gsau_if.sa_array_in_partials = '0;
        end
    endtask

    task write_matrix(input string tname);
        $fwrite(actual_output_file, "%s", tname);
        for (int row = 0; row < ARRAY_DIM; row++) begin
            for (int col = 0; col < ARRAY_DIM; col++) begin
                $fwrite(actual_output_file, "0x%04H", temp_act_outputs[row][col]);
                if (col != ARRAY_DIM - 1) $fwrite(actual_output_file, ",");
            end
            $fwrite(actual_output_file, "\n");
        end
        $fwrite(actual_output_file, "\n");
    endtask

    // ----------------------------------------------------------------
    // DUT
    // ----------------------------------------------------------------
    sysarr_STANDARD #(.MAC_LATENCY(2)) DUT (
        .clk(CLK),
        .nRST(nRST),
        .gsau_if(gsau_if)
    );

    // ----------------------------------------------------------------
    // Init files
    // ----------------------------------------------------------------
    initial begin
        file               = $fopen(PATH_TO_INPUT, "r");
        expected_out_file  = $fopen(PATH_TO_EXPECTED_RESULT, "r");
        actual_output_file = $fopen(PATH_TO_RESULT, "w");
    end

    // ----------------------------------------------------------------
    // Process 1: Feed weights + inputs
    // ----------------------------------------------------------------
    initial begin
        int loaded_wts;
        bit found_test;

        reset();

        forever begin
            // Find next test
            found_test = 0;
            while (!found_test) begin
                if ($fgets(line, file) == 0) break;
                if (line.len() >= 4 && line.substr(0,3) == "Test") begin
                    test_name_queue.push_front(line);
                    test_name = line;
                    found_test = 1;
                end
            end

            if (!found_test) begin
                input_eof = 1;
                break;
            end

            // Parse matrices from file
            loaded_wts = 0;
            get_matrices(.weights(loaded_wts), .has_weights(1));

            // If new weights, wait for any in-flight gemm to finish first
            if (loaded_wts) begin
                while (pending_gemms != 0) @(gemm_completed);
                load_weights();
            end

            pending_gemms++;
            load_inputs();
        end
    end

    // ----------------------------------------------------------------
    // Process 2: Collect and check outputs
    // ----------------------------------------------------------------
    initial begin
        int result_row;
        bit found_expected_result;
        bit is_result_correct;
        result_row = 0;

        for (int i = 0; i < ARRAY_DIM; i++)
            for (int j = 0; j < ARRAY_DIM; j++)
                temp_act_outputs[i][j] = '0;

        // Keep sa_ready_out high (no backpressure for now)
        gsau_if.sa_ready_out = 1'b1;

        forever begin
            @(posedge CLK);

            if (input_eof && test_name_queue.size() == 0 && result_row == 0) begin
                $display("All queued tests processed. Ending simulation.");
                break;
            end

            if (gsau_if.sa_valid_in) begin
                for (int col = 0; col < ARRAY_DIM; col++)
                    temp_act_outputs[result_row][col] = gsau_if.sa_array_output[DATA_WIDTH*col +: DATA_WIDTH];

                result_row++;

                if (result_row == ARRAY_DIM) begin
                    result_row = 0;

                    // Read expected
                    found_expected_result = 0;
                    while (!found_expected_result) begin
                        if ($fgets(line, expected_out_file) == 0) break;
                        if (line.len() >= 4 && line.substr(0,3) == "Test")
                            found_expected_result = 1;
                    end

                    if (found_expected_result) begin
                        get_m_expected_output();
                    end else begin
                        $display("Reached EOF in expected result file. Ending simulation.");
                        break;
                    end

                    // Compare
                    is_result_correct = 1;
                    for (int i = 0; i < ARRAY_DIM; i++) begin
                        for (int j = 0; j < ARRAY_DIM; j++) begin
                            if (temp_act_outputs[i][j] == 16'h8000) temp_act_outputs[i][j] = 16'h0000;
                            if (temp_exp_outputs[i][j] == 16'h8000) temp_exp_outputs[i][j] = 16'h0000;
                            if (temp_act_outputs[i][j] != temp_exp_outputs[i][j]) begin
                                is_result_correct = 0;
                                $display("Test %s Failed at [%0d][%0d]: Expected 0x%04H Got 0x%04H",
                                    test_name_queue[$-1], i, j, temp_exp_outputs[i][j], temp_act_outputs[i][j]);
                            end
                        end
                    end

                    total_tests++;
                    write_matrix(test_name_queue.pop_back());
                    if (is_result_correct) total_passed_tests++;
                    if (pending_gemms > 0) pending_gemms--;
                    -> gemm_completed;

                    for (int i = 0; i < ARRAY_DIM; i++)
                        for (int j = 0; j < ARRAY_DIM; j++)
                            temp_act_outputs[i][j] = '0;
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
