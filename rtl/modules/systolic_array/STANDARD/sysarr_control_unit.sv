// sysarr_control_unit.sv
// rewrote it bc i couldnt get it to work on the other one sorry

module sysarr_control_unit #(
    parameter int N = 8,
    parameter int GROUP_SIZE = 1,
    parameter int ADD_2_INPUT_LATENCY = 2,
    parameter int ADD_4_INPUT_LATENCY = 0,
    parameter int MUL_LATENCY = 2
)(
    input logic clk, nRST,
    input logic sa_input_en,        // external write to input buffer this cycle
    input logic in_buffer_empty,    // lane0 of input buffer is empty
    input logic sa_output,          // credit return pulse (sa_valid_in)
    output logic [N-1:0] in_rd_en,
    output logic [N-1:0] out_wr_en, // unused, kept for interface compat
    output logic ready_in
);

    localparam int SKEW = 1;
    localparam int SR_LEN = (N - 1) * SKEW;

    // Credits: how many more input vectors we can accept
    logic [$clog2(N+1):0] credits, next_credits;

    // Skew shift register: lane0_rd enters at bit 0, propagates right.
    // Lane m taps bit (m*SKEW - 1).
    logic [SR_LEN-1:0] skew_sr;

    // Lane 0 reads whenever buffer has data
    logic lane0_rd;
    assign lane0_rd = !in_buffer_empty;

    // Per-lane read enables from shift register taps
    always_comb begin
        in_rd_en[0] = lane0_rd;
        for (int m = 1; m < N; m++) begin
            in_rd_en[m] = skew_sr[m * SKEW - 1];
        end
    end

    // Credit logic
    always_comb begin
        next_credits = credits;
        if (sa_input_en && !sa_output && credits > 0)
            next_credits = credits - 1;
        else if (!sa_input_en && sa_output && credits < N)
            next_credits = credits + 1;
    end

    // Registers
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            credits <= N;
            skew_sr <= '0;
        end else begin
            credits <= next_credits;
            skew_sr <= {skew_sr[SR_LEN-2:0], lane0_rd};
        end
    end

    assign ready_in  = |next_credits;
    assign out_wr_en = '0;

endmodule
  
