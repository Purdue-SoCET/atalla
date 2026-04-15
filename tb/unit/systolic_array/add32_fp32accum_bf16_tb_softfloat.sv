`timescale 1ns/1ps
`include "systolic_array_4_input_adder_if.vh"

module add32_fp32accum_bf16_tb_softfloat;

    // --- Params ---
    localparam PERIOD = 2;
    localparam LATENCY = 14; // Adjusted for pipeline depth
    localparam GRS = 1;
    localparam PRECISION_BITS = 100;
    localparam MANTISSA_SIZE = 23;

    logic tb_clk = 0;
    logic tb_nrst;

    // Clock Generation
    always #(PERIOD/2.0) tb_clk = ~tb_clk;

    // --- Scoreboard Structures ---
    typedef struct {
        logic [31:0][15:0] inputs;
        logic [15:0] expected;
        int id;
    } scoreboard_entry_t;

    scoreboard_entry_t scoreboard_queue [$];

    // Diagnostics Variables
    int pass_count, fail_count; 
    longint total_ulp_diff;
    int ulp_big_count;
    int largest_ulp; 
    integer fail_fd;
    int total_processed = 0;

    // DUT Signals
    logic [31:0][15:0] tb_inputs;
    logic [15:0] tb_result;

    add32_FPADD4 #(
        .MANTISSA_SIZE(MANTISSA_SIZE), 
        .PRECISION_BITS(PRECISION_BITS), 
        .GRS(GRS)
    ) dut (
        .clk(tb_clk),
        .nRST(tb_nrst),
        .inputs(tb_inputs),
        .out_bf16(tb_result)
    );

    // --- Helper Functions ---
    function automatic logic is_nan(input logic [15:0] val);
        return (val[14:7] == 8'hFF) && (val[6:0] != 7'h0);
    endfunction

    function automatic longint get_ulp_distance(logic [15:0] a, logic [15:0] b);
        longint int_a, int_b;
        int_a = (a[15]) ? (64'h7FFFFFFF - a[14:0]) : (64'h80000000 + a[14:0]);
        int_b = (b[15]) ? (64'h7FFFFFFF - b[14:0]) : (64'h80000000 + b[14:0]);
        return (int_a > int_b) ? (int_a - int_b) : (int_b - int_a);
    endfunction

    // --- Driver Process ---
    // --- Driver Process ---
    initial begin
        integer fd;
        string header;
        int ret;
        scoreboard_entry_t entry;
        
        // Temporary storage to help Verilator's $fscanf
        logic [15:0] temp_inputs [31:0];
        logic [15:0] temp_expected;

        tb_nrst = 1'b0;
        tb_inputs = '0;
        #(PERIOD * 5);
        tb_nrst = 1'b1;

        fd = $fopen("scripts/systolic_array/testfloat_cases_32_pure_bf16.csv", "r");
        fail_fd = $fopen("tree_failures.csv", "w");
        if (fd == 0) begin $display("FATAL: CSV not found"); $finish; end
        
        void'($fgets(header, fd));

        $display("Starting Continuous Simulation with Full Diagnostics...");

        while (!$feof(fd)) begin
            // 1. Read into simple temporary variables
            ret = $fscanf(fd, "%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h\n",
                temp_inputs[0],  temp_inputs[1],  temp_inputs[2],  temp_inputs[3], 
                temp_inputs[4],  temp_inputs[5],  temp_inputs[6],  temp_inputs[7],
                temp_inputs[8],  temp_inputs[9],  temp_inputs[10], temp_inputs[11], 
                temp_inputs[12], temp_inputs[13], temp_inputs[14], temp_inputs[15],
                temp_inputs[16], temp_inputs[17], temp_inputs[18], temp_inputs[19], 
                temp_inputs[20], temp_inputs[21], temp_inputs[22], temp_inputs[23],
                temp_inputs[24], temp_inputs[25], temp_inputs[26], temp_inputs[27], 
                temp_inputs[28], temp_inputs[29], temp_inputs[30], temp_inputs[31],
                temp_expected);

            if (ret == 33) begin
                @(posedge tb_clk);
                // 2. Transfer from temp to struct/DUT
                for(int k=0; k<32; k++) begin
                    tb_inputs[k]     <= temp_inputs[k];
                    entry.inputs[k]   = temp_inputs[k];
                end
                entry.expected = temp_expected;
                entry.id       = total_processed;
                
                scoreboard_queue.push_back(entry);
                total_processed++;
            end
        end

        repeat (LATENCY + 5) @(posedge tb_clk);
        $display("\nSimulation Completed.");
        print_final_report();
        $finish;
    end

    // --- Monitor & Diagnostics Process ---
    initial begin
        scoreboard_entry_t check_entry;
        longint ulp;
        logic match;

        repeat (LATENCY) @(posedge tb_clk);

        forever begin
            @(negedge tb_clk);
            if (scoreboard_queue.size() > 0) begin
                check_entry = scoreboard_queue.pop_front();
                
                // ULP and Match Logic
                if (is_nan(tb_result) && is_nan(check_entry.expected)) begin
                    match = 1'b1;
                    ulp = 0;
                end else begin
                    match = (tb_result === check_entry.expected);
                    ulp = get_ulp_distance(tb_result, check_entry.expected);
                end

                // Update Stats
                total_ulp_diff += ulp;
                if (ulp > 1) ulp_big_count++;
                if (ulp > largest_ulp) largest_ulp = int'(ulp);

                if (!match) begin
                    if (fail_count < 20)
                        $display("FAIL: Row %0d | Got=%h Exp=%h | ULP=%0d", check_entry.id, tb_result, check_entry.expected, ulp);
                    
                    if (fail_fd != 0) begin
                        for (int k=0; k<32; k++) $fwrite(fail_fd, "%h,", check_entry.inputs[k]);
                        $fwrite(fail_fd, "%h,%h,%0d\n", check_entry.expected, tb_result, ulp);
                    end
                    fail_count++;
                end else begin
                    pass_count++;
                end

                if (check_entry.id % 100000 == 0 && check_entry.id != 0)
                    $display("Processed %0d cases...", check_entry.id);
            end
        end
    end

    task automatic print_final_report();
        $display("\n========================================");
        $display("FINAL REPORT");
        $display("TOTAL CASES: %0d", total_processed);
        $display("PASSED:      %0d", pass_count);
        $display("FAILED:      %0d", fail_count);
        if (total_processed > 0)
            $display("AVG ULP ERR: %0f", total_ulp_diff * 1.0 / total_processed);
        $display("MAX ULP ERR: %0d", largest_ulp);
        $display("ULP > 1:     %0d", ulp_big_count);
        $display("========================================\n");
    endtask

endmodule