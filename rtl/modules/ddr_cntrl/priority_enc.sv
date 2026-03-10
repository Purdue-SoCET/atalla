// AI GENERATED PRIORITY ENCODER
// 16-to-4 Priority Encoder (Synthesizable)
// Lowest active bit has highest priority.
// Outputs:
//   out   [3:0] - encoded index of the highest-priority (lowest) active bit
//   valid       - high when at least one input bit is active; low when in == 16'h0

module priority_encoder_16to4 (
    input  logic [15:0] in,
    output logic [3:0]  out,
    output logic        valid
);

    function automatic logic [3:0] encode (input logic [15:0] in);
        for (int i = 0; i < 16; i++) begin
            if (in[i]) return 4'(i);
        end
        return 4'd0;
    endfunction

    always_comb begin
        valid = |in;
        out   = encode(in);
    end

endmodule
