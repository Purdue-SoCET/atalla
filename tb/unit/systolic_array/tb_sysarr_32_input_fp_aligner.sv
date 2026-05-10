`timescale 1ns/1ps

module tb_sysarr_32_input_fp_aligner;

    // --- Parameters ---
    localparam int EXPONENT_SIZE = 8;
    localparam int MANTISSA_SIZE = 23;
    localparam int NEW_MANT_WIDTH = 27;
    localparam int FP_WIDTH = 1 + EXPONENT_SIZE + MANTISSA_SIZE;

    // --- Signals ---
    logic clk;
    logic nRST;
    logic [FP_WIDTH-1:0]       in_fp [0:31];
    logic [EXPONENT_SIZE-1:0]  out_max_exp;
    logic                      sign_out [0:31];
    logic [NEW_MANT_WIDTH-1:0] aligned_mant_out [0:31];

    // --- DUT Instantiation ---
    sysarr_32_input_fp_aligner #(
        .EXPONENT_SIZE(EXPONENT_SIZE),
        .MANTISSA_SIZE(MANTISSA_SIZE),
        .NEW_MANT_WIDTH(NEW_MANT_WIDTH)
    ) dut (
        .clk(clk),
        .nRST(nRST),
        .in_fp(in_fp),
        .out_max_exp(out_max_exp),
        .sign_out(sign_out),
        .aligned_mant_out(aligned_mant_out)
    );

    // --- Clock Generation ---
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // --- Data Structures for Verification ---
    typedef struct {
        logic [EXPONENT_SIZE-1:0]  max_exp;
        logic                      signs [0:31];
        logic [NEW_MANT_WIDTH-1:0] mants [0:31];
    } expected_data_t;

    // Pipeline to hold expected data to match DUT's 3-cycle latency
    expected_data_t exp_pipe [1:3]; 
    int cycle_cnt = 0;

    // --- Reference Model ---
    // Calculates the expected combinatorial result for a given input array
    function automatic expected_data_t get_expected(logic [FP_WIDTH-1:0] in [0:31]);
        expected_data_t exp_out;
        logic [EXPONENT_SIZE-1:0] max_e = 0;
        logic [EXPONENT_SIZE-1:0] e [0:31];
        logic [NEW_MANT_WIDTH-1:0] m [0:31];
        
        // 1. Unpack, format mantissas, and find max exponent
        for (int i = 0; i < 32; i++) begin
            exp_out.signs[i] = in[i][FP_WIDTH-1];
            e[i]             = in[i][MANTISSA_SIZE +: EXPONENT_SIZE];
            m[i]             = { (|e[i]), in[i][MANTISSA_SIZE-1:0], 3'b000 };
            if (e[i] > max_e) max_e = e[i];
        end
        
        exp_out.max_exp = max_e;
        
        // 2. Calculate alignment shift and sticky bit matching DUT logic
        for (int i = 0; i < 32; i++) begin
            int shift = max_e - e[i];
            
            if (shift >= NEW_MANT_WIDTH) begin
                exp_out.mants[i] = '0;
            end else begin
                // Sticky bit: bitwise OR of all bits shifted out
                logic [NEW_MANT_WIDTH-1:0] mask = ~({NEW_MANT_WIDTH{1'b1}} << shift);
                logic sticky = |(m[i] & mask);
                
                exp_out.mants[i] = (m[i] >> shift);
                exp_out.mants[i][0] = exp_out.mants[i][0] | sticky;
            end
        end
        return exp_out;
    endfunction

    // --- Helper to Generate FP32 Vectors ---
    function automatic logic [FP_WIDTH-1:0] rand_fp32(int min_exp, int max_exp);
        logic sign = $random;
        logic [EXPONENT_SIZE-1:0] exp = $urandom_range(max_exp, min_exp);
        logic [MANTISSA_SIZE-1:0] mant = $random;
        return {sign, exp, mant};
    endfunction

    // --- Pipeline Tracking & Checking ---
    always_ff @(posedge clk) begin
        if (!nRST) begin
            cycle_cnt <= 0;
        end else begin
            cycle_cnt <= cycle_cnt + 1;
            // Push new expected results into the pipeline
            exp_pipe[1] <= get_expected(in_fp);
            exp_pipe[2] <= exp_pipe[1];
            exp_pipe[3] <= exp_pipe[2];
        end
    end

    // Check DUT outputs against pipeline stage 3 (on negative edge to avoid races)
    always_ff @(negedge clk) begin
        if (nRST && cycle_cnt >= 3) begin
            if (out_max_exp !== exp_pipe[3].max_exp) begin
                $error("FAIL [Cycle %0d]: Max Exp mismatch. Expected %h, Got %h", cycle_cnt, exp_pipe[3].max_exp, out_max_exp);
            end
            for (int i = 0; i < 32; i++) begin
                if (sign_out[i] !== exp_pipe[3].signs[i]) begin
                    $error("FAIL [Cycle %0d]: Sign[%0d] mismatch. Expected %b, Got %b", cycle_cnt, i, exp_pipe[3].signs[i], sign_out[i]);
                end
                if (aligned_mant_out[i] !== exp_pipe[3].mants[i]) begin
                    $error("FAIL [Cycle %0d]: Mantissa[%0d] mismatch. Expected %h, Got %h", cycle_cnt, i, exp_pipe[3].mants[i], aligned_mant_out[i]);
                end
            end
        end
    end

    // --- Stimulus ---
    initial begin
        // 1. Reset
        nRST = 0;
        for (int i = 0; i < 32; i++) in_fp[i] = '0;
        #15;
        nRST = 1;

        $display("==================================================");
        $display("   STARTING TESTBENCH: FP32 32-way Aligner");
        $display("==================================================");

        // --------------------------------------------------------
        // TEST 1: Identical Exponents (No Shifting)
        // --------------------------------------------------------
        for (int i = 0; i < 32; i++) in_fp[i] = rand_fp32(127, 127);
        #10;

        // --------------------------------------------------------
        // TEST 2: Minor Variations (Normal shifting)
        // --------------------------------------------------------
        for (int test = 0; test < 5; test++) begin
            for (int i = 0; i < 32; i++) in_fp[i] = rand_fp32(120, 130);
            #10;
        end

        // --------------------------------------------------------
        // TEST 3: Extreme Shifts (Testing the shift >= 27 condition)
        // --------------------------------------------------------
        // Set one input to a huge exponent, the rest to small exponents
        for (int i = 0; i < 32; i++) begin
            if (i == 15) in_fp[i] = rand_fp32(200, 200); // Massive max exponent
            else         in_fp[i] = rand_fp32(100, 100); // Will be completely shifted out
        end
        #10;

        // --------------------------------------------------------
        // TEST 4: Fully Random Stress Test
        // --------------------------------------------------------
        for (int test = 0; test < 20; test++) begin
            for (int i = 0; i < 32; i++) in_fp[i] = rand_fp32(1, 254);
            #10;
        end

        // Wait 4 cycles to let the final data drain out of the pipeline
        #(10 * 4); 

        $display("==================================================");
        $display("   TESTS COMPLETE (Check terminal for Error messages)");
        $display("==================================================");
        $finish;
    end

endmodule