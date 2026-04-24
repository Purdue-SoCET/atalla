`timescale 1ns/1ps

//`include "ddr_controller_if.sv"
//`include "dram_pkg.svh"

module init_state (
    input logic CLK, nRST,
    ddr_controller_if.init_ctrl isif
);

    import dram_pkg::*;

    logic [11:0] timing_value;
    logic timing_clear, timing_cnt_en, timing_flag, n_timing_cnt_en;

    logic n_init_done;
    dram_state_t state, n_state;

    flex_counter #(.SIZE(12)) time_counter (
        .CLK(CLK),
        .nRST(nRST),
        .clear(timing_clear),
        .count_enable(timing_cnt_en),
        .rollover_val(timing_value),
        .rollover_flag(timing_flag)
    );

    assign isif.init_state = state;
    assign isif.next_init_state = n_state;

    always_ff @(posedge CLK, negedge nRST) begin : INIT_REG_LOGIC
        if (!nRST) begin
            state <= POWER_UP;
            timing_cnt_en <= 0;
            isif.init_done <= 0;
        end else begin
            state <= n_state;
            timing_cnt_en <= n_timing_cnt_en;
            isif.init_done <= n_init_done;
        end
    end

    always_comb begin : INIT_COMB_LOGIC
        n_state = state;
        timing_clear = 0;
        n_timing_cnt_en = timing_cnt_en;
        timing_value = 0;
        n_init_done = isif.init_done;

        case (state)
            POWER_UP: begin
                timing_value = tPWUP;
                if (isif.init_start) begin
                    n_timing_cnt_en = 1'b1;
                end
                if (timing_flag) begin
                    timing_clear = 1;
                    n_state = PRE_RESET;
                end
            end

            PRE_RESET: begin
                timing_value = tPWUP;
                if (timing_flag) begin
                    timing_clear = 1;
                    n_state = RESET;
                end
            end

            RESET: begin
                timing_value = tPWUP;
                if (timing_flag) begin
                    timing_clear = 1;
                    n_state = NOP;
                end
            end

            NOP: begin
                timing_value = tPDc + tXPR;
                if (timing_flag) begin
                    timing_clear = 1;
                    n_state = LOAD_MODE_DLL;
                end
            end

            LOAD_MODE_DLL: begin
                timing_value = tDLLKc;
                if (timing_flag) begin
                    timing_clear = 1;
                    n_state = LOAD_BG0_REG3;
                end
            end

            LOAD_BG0_REG3: begin
                timing_value = tMOD;
                if (timing_flag) begin
                    timing_clear = 1;
                    n_state = LOAD_BG1_REG6;
                end
            end

            LOAD_BG1_REG6: begin
                timing_value = tMOD;
                if (timing_flag) begin
                    timing_clear = 1;
                    n_state = LOAD_BG1_REG5;
                end
            end

            LOAD_BG1_REG5: begin
                timing_value = tMOD;
                if (timing_flag) begin
                    timing_clear = 1;
                    n_state = LOAD_BG1_REG4;
                end
            end

            LOAD_BG1_REG4: begin
                timing_value = tMOD;
                if (timing_flag) begin
                    timing_clear = 1;
                    n_state = LOAD_BG0_REG2;
                end
            end

            LOAD_BG0_REG2: begin
                timing_value = tMOD;
                if (timing_flag) begin
                    timing_clear = 1;
                    n_state = LOAD_BG0_REG1;
                end
            end

            LOAD_BG0_REG1: begin
                timing_value = tMOD;
                if (timing_flag) begin
                    timing_clear = 1;
                    n_state = LOAD_BG0_REG0;
                end
            end

            LOAD_BG0_REG0: begin
                timing_value = tMOD;
                if (timing_flag) begin
                    timing_clear = 1;
                    n_state = ZQ_CL;
                end
            end

            ZQ_CL: begin
                timing_value = tZQinitc;
                if (timing_flag) begin
                    timing_clear = 1;
                    n_init_done = 1;
                    n_timing_cnt_en = 1'b0;
                end
            end

            IDLE: begin
            end

            default: begin
            end
        endcase
    end

endmodule
