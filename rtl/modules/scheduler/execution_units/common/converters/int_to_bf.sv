`include "int_to_bf_if.sv"

module int_to_bf #()
(
    input logic [31:0] inputInt,
    output logic [15:0] outputBF
);

    localparam int signed I32_MAX = 32'sh7FFF_FFFF;
    localparam int signed I32_MIN = 32'sh8000_0000;

    logic sign;
    logic guard, sticky, lsb, round_up;
    logic [7:0] frac_plus;
    logic [31:0] abs_u;
    logic [4:0] msb;
    logic [7:0] exp_field;
    logic [6:0] shifted;
    logic [7:0] tmp_guard;
    logic [6:0] frac_field;
    logic [4:0] i;
    logic [5:0] k;

    assign sign = inputInt[31];

    always_comb begin : conversion

        if (inputInt == I32_MIN) begin
            abs_u = I32_MIN;
        end
        else begin
            abs_u = sign ? (~inputInt + 1) : inputInt; 
        end

        if(abs_u == 0) begin
            outputBF = 16'b0;
        end else begin
            for (k = 0; k < 32; k++) begin
                if (abs_u[k]) begin
                    msb = k[4:0];
                end
            end

            exp_field = msb + 8'd127;

            if (msb <= 7) begin
                shifted = abs_u << (7 - msb);
                frac_field = shifted[6:0];
            end else begin
                shifted = abs_u >> (msb - 7);
                frac_field = shifted[6:0];
                tmp_guard = abs_u >> (msb - 8);
                guard = tmp_guard[0];
                sticky = 1'b0;
                for (i = 0; i < (msb-8); i++) begin
                    sticky |= abs_u[i];
                end
                lsb = frac_field[0];
                round_up = guard & (sticky | lsb);
                frac_plus = {1'b0, frac_field} + round_up;
                if (frac_plus[7]) begin
                    exp_field  = exp_field + 8'd1;
                    frac_field = 7'h00;
                end else begin
                    frac_field = frac_plus[6:0];
                end
            end
            outputBF = {sign, exp_field, frac_field};
        end
        
    end


endmodule