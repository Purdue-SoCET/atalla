module mant_divider #(
    parameter MANT_WIDTH = 10
)(
    input logic CLK, nRST, en,
    input logic [MANT_WIDTH:0] x, y,
    output logic [MANT_WIDTH+2:0] result,
    output logic done
);

localparam A_WIDTH = MANT_WIDTH * 2 + 3;

typedef enum logic {IDLE, DIV} state_t;
state_t state, next_state;

logic [MANT_WIDTH+2:0] q, next_q;
logic [A_WIDTH:0] a, next_a;
logic [MANT_WIDTH:0] m, next_m;
logic [$clog2(MANT_WIDTH+2):0] n, next_n;
always_ff @(posedge CLK) begin
    if (~nRST) begin
        state <= IDLE;
        q <= 0;
        m <= 0;
        a <= 0;
        n <= 0;
    end else begin
        state <= next_state;
        q <= next_q;
        m <= next_m;
        a <= next_a;
        n <= next_n;
    end
end

always_comb begin
    next_state = state;
    next_q = q;
    next_m = m;
    next_a = a;
    next_n = n;
    case (state)
        IDLE: begin
            if (en) begin
                next_state = DIV;
                next_m = {1'b0, y};
                next_n = MANT_WIDTH + 1;
                // Do first iteration immediately
                next_a = x - next_m;
                next_q = {1'b0, ~next_a[A_WIDTH]};
            end
        end
        DIV: begin
            next_a = a[A_WIDTH] ? {a[A_WIDTH-1:0], q[MANT_WIDTH+2]} + m : {a[A_WIDTH-1:0], q[MANT_WIDTH+2]} - m;
            next_q = {q[MANT_WIDTH+1:0], ~next_a[A_WIDTH]};
            next_n = n - 1;
            if (n == 0) next_state = IDLE;
        end
    endcase
end

assign result = next_q[MANT_WIDTH+2:0];
assign done = (state == DIV && n == 0);

endmodule