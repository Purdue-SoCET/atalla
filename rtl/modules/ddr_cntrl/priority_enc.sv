// AI GENERATED PRIORITY ENCODER
// 16-to-4 Priority Encoder (Synthesizable)
// Lowest active bit has highest priority.
// Outputs:
//   out   [3:0] - encoded index of the highest-priority (lowest) active bit
//   valid       - high when at least one input bit is active; low when in == 16'h0

module priority_enc (
    input  logic [BANK_NUM-1:0] in,
    output logic [$clog2(BANK_NUM)-1:0]  out,
    output logic        valid
);

    function automatic logic [$clog2(BANK_NUM)-1:0] encode (input logic [BANK_NUM-1:0] in);
        for (int i = 0; i < BANK_NUM; i++) begin
            if (in[i]) return i[$clog2(BANK_NUM)-1:0];
        end
        return {BANK_NUM{1'b0}};
    endfunction

    always_comb begin
        valid = |in;
        out   = encode(in);
    end

endmodule
