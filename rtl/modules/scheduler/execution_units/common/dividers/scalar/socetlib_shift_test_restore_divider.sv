
/*
*   Copyright 2016 Purdue University
*
*   Licensed under the Apache License, Version 2.0 (the "License");
*   you may not use this file except in compliance with the License.
*   You may obtain a copy of the License at
*
*       http://www.apache.org/licenses/LICENSE-2.0
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.
*
*
*   Filename:     socetlib_shift_test_restore_divider.sv
*
*   Created by:   John Skubic
*   Email:        jskubic@purdue.edu
*   Date Created: 02/21/2017
*   Description:  NxN bit divider using the shift-test-restore algorithm
*/

module socetlib_shift_test_restore_divider #(
    parameter int NUM_BITS = 32
) (
    input logic CLK,
    input logic nRST,
    input logic [NUM_BITS-1:0] divisor,
    input logic [NUM_BITS-1:0] dividend,
    input logic is_signed,
    input logic start,
    output logic [NUM_BITS-1:0] remainder,
    output logic [NUM_BITS-1:0] quotient,
    output logic finished
);

    localparam int COUNTER_BITS = $clog2(NUM_BITS) + 1;
    localparam int U_Q = NUM_BITS - 1;
    localparam int U_R = (2 * NUM_BITS) - 1;
    typedef enum logic [2:0] {
        STRD_RESET,
        STRD_IDLE,
        STRD_SHIFT_SUB,
        STRD_TEST,
        STRD_ADJUST,
        STRD_DONE
    } strd_state;

    strd_state state, next_state;
    logic [(2*NUM_BITS)+1:0] result, next_result;
    logic [NUM_BITS-1:0] temp_remainder, temp_quotient;
    assign {temp_remainder, temp_quotient} = result[(2*NUM_BITS)-1:0];
    logic [COUNTER_BITS-1:0] counter, next_counter;
    logic [NUM_BITS-1:0] corrected_divisor, corrected_dividend;
    logic adjust_quotient, adjust_remainder;
    logic busy, abort;

    socetlib_divider_control #(
        .NUM_BITS(NUM_BITS)
    ) divider_control (
        .is_signed(is_signed),
        .start_in(start),
        .div_finished(~busy),
        .dividend(dividend),
        .divisor(divisor),
        .quotient_in(temp_quotient),
        .remainder_in(temp_remainder),
        .start(start_div),
        .finished(finished),
        .abort(abort),
        .quotient_out(quotient),
        .remainder_out(remainder)
    );

    assign corrected_divisor  = is_signed & divisor[NUM_BITS-1] ? (~divisor) + 1 : divisor;
    assign corrected_dividend = is_signed & dividend[NUM_BITS-1] ? (~dividend) + 1 : dividend;
    assign adjust_quotient    = is_signed & (divisor[NUM_BITS-1] ^ dividend[NUM_BITS-1]) & ~temp_quotient[NUM_BITS-1];
    assign adjust_remainder   = is_signed & dividend[NUM_BITS-1];

    always_ff @(posedge CLK, negedge nRST) begin : STRD_FF
        if (~nRST) begin
            state <= STRD_RESET;
            result <= '0;
            counter <= NUM_BITS;
        end
        else begin
            state <= next_state;
            result <= next_result;
            counter <= next_counter;
        end
    end

    always_comb begin : STRD_STATE_LOGIC
        next_state = state;
        casez(state)
            STRD_RESET: next_state = STRD_IDLE;
            STRD_IDLE: if (start) next_state = STRD_SHIFT_SUB;
            STRD_SHIFT_SUB: next_state = STRD_TEST;
            STRD_TEST: begin
                next_state = STRD_SHIFT_SUB;
                if (counter == 1) next_state = STRD_ADJUST;
            end
            STRD_ADJUST: next_state = STRD_IDLE;
        endcase
        if (abort) next_state = STRD_IDLE;
    end

    always_comb begin : STRD_CTRL_LOGIC
        next_result = result;
        next_counter = counter;
        busy = 0;
        casez(state)
            STRD_IDLE: begin
                next_counter = NUM_BITS;
                if (start_div & ~abort) begin
                    next_result = {{(NUM_BITS - 1) {1'b0}}, corrected_dividend, 1'b0};
                end
            end
            STRD_SHIFT_SUB: begin
                busy = 1;
                next_result[U_R+1-:NUM_BITS+1] = result[U_R+1-:NUM_BITS+1] - corrected_divisor;
            end
            STRD_TEST: begin
                busy = 1;
                next_counter = counter - 1;
                if (result[U_R+1])
                    next_result = {(result[U_R+1-:NUM_BITS+1] + corrected_divisor), result[U_Q:0]} << 1;
                else
                    next_result = {result[U_R-1:0], 1'b1};
            end
            STRD_ADJUST: begin
                busy = 1;
                if (adjust_quotient)
                    next_result[U_Q:0] = (~result[U_Q:0]) + 1;

                if (adjust_remainder)
                    next_result[U_R-:NUM_BITS] = (~result[U_R+1-:NUM_BITS]) + 1;
                else
                    next_result[U_R-:NUM_BITS] = result[U_R+1-:NUM_BITS];
            end
        endcase
    end
endmodule
