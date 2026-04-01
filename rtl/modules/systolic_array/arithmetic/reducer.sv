`timescale 1ps/1ps

// reducer code shrinks the weird fp32 to fp16
// should've reduced to to fp4 to 10x performance 

module reducer #(
    parameter IN_EXP_W   = 8,
    parameter IN_MANT_W  = 23,
    parameter OUT_EXP_W  = 5,
    parameter OUT_MANT_W = 10,
    localparam IN_W  = 1 + IN_EXP_W + IN_MANT_W,
    localparam OUT_W = 1 + OUT_EXP_W + OUT_MANT_W,
    localparam BIAS_DIFF = (1 << (IN_EXP_W-1)) - (1 << (OUT_EXP_W-1)),
    localparam DROP = IN_MANT_W - OUT_MANT_W
) (
    input  logic [IN_W-1:0]  fp_in,
    output logic [OUT_W-1:0] fp_out
);

    logic sign;
    logic [IN_EXP_W-1:0]  in_exp;
    logic [IN_MANT_W-1:0] in_mant;
    assign {sign, in_exp, in_mant} = fp_in;

    logic signed [IN_EXP_W+1:0] new_exp;
    logic [OUT_MANT_W:0] rounded;
    logic guard, rnd, sticky, round_up;

    always_comb begin
        // bits from dropped mantissa 
        guard = in_mant[DROP-1];
        rnd = (DROP > 1) ? in_mant[DROP-2] : 1'b0;
        sticky = (DROP > 2) ? |in_mant[DROP-3:0] : 1'b0;

        // round nearest even
        round_up = guard & (rnd | sticky | in_mant[DROP]);
        rounded = {1'b0, in_mant[IN_MANT_W-1 -: OUT_MANT_W]} + {{OUT_MANT_W{1'b0}}, round_up};

        // rebias and carry
        new_exp = $signed({{2{1'b0}}, in_exp}) - BIAS_DIFF + $signed({{(IN_EXP_W+1){1'b0}}, rounded[OUT_MANT_W]});

        // pack
        if (&in_exp) begin  // nan and if pass thru 
            fp_out = {sign, {OUT_EXP_W{1'b1}}, |in_mant ? {1'b1, {(OUT_MANT_W-1){1'b0}}} : {OUT_MANT_W{1'b0}}};
        end else if (new_exp >= $signed({{(IN_EXP_W+2-OUT_EXP_W){1'b0}}, {OUT_EXP_W{1'b1}}})) begin  // overflow to inf 
            fp_out = {sign, {OUT_EXP_W{1'b1}}, {OUT_MANT_W{1'b0}}};
        end else if (new_exp <= 0) begin // underflow to ftz
            fp_out = {sign, {(OUT_W-1){1'b0}}};
        end else begin
            fp_out = {sign, new_exp[OUT_EXP_W-1:0], rounded[OUT_MANT_W] ? {OUT_MANT_W{1'b0}} : rounded[OUT_MANT_W-1:0]};
        end
    end

endmodule
