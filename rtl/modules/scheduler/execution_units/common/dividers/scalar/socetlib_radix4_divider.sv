module socetlib_radix4_divider #(
    parameter int NUM_BITS = 32
) (
    input logic CLK,
    input logic nRST,
    input logic start,
    input logic is_signed,  //new
    input logic [NUM_BITS-1:0] dividend,
    input logic [NUM_BITS-1:0] divisor,
    output logic [NUM_BITS-1:0] quotient,
    output logic [NUM_BITS-1:0] remainder,
    output logic finished

);
    logic [NUM_BITS-1:0]
        next_remainder,
        next_quotient,
        shifted_remainder,
        shifted_quotient,
        temp_quotient,
        temp_remainder;
    logic [NUM_BITS:0] Result1, Result2, Result3;
    logic [NUM_BITS-1:0] DivisorX2, DivisorX3;
    logic [4:0] count, next_count;

    logic [NUM_BITS-1:0] usign_divisor, usign_dividend;
    logic adjustment_possible, adjust_quotient, adjust_remainder, abort;

    logic div_finished, start_div;

    socetlib_divider_control #(
        .NUM_BITS(NUM_BITS)
    ) divider_control (
        .is_signed(is_signed),
        .start_in(start),
        .div_finished(div_finished),
        .dividend(dividend),
        .divisor(divisor),
        .quotient_in(temp_quotient),
        .remainder_in(temp_remainder),
        .start(start_div),
        .finished(finished),
        .quotient_out(quotient),
        .remainder_out(remainder)
    );

    assign usign_divisor       = is_signed & divisor[NUM_BITS-1] ? (~divisor) + 1 : divisor;
    assign usign_dividend      = is_signed & dividend[NUM_BITS-1] ? (~dividend) + 1 : dividend;
    assign adjustment_possible = is_signed && (divisor[NUM_BITS-1] ^ dividend[NUM_BITS-1]);
    assign adjust_quotient     = adjustment_possible && ~quotient[NUM_BITS-1];
    assign adjust_remainder    = is_signed && dividend[NUM_BITS-1];
    assign div_finished        = start_div && (count == 0);

    //initialize d2 d3
    assign DivisorX2 = usign_divisor << 1;  //Divisor*2
    assign DivisorX3 = (usign_divisor << 1) + usign_divisor;  //Divisor*3
    always_ff @(posedge CLK, negedge nRST) begin
        if (nRST == 0) begin
            count <= 5'd17;
            temp_quotient <= '0;
            temp_remainder <= '0;
        end else begin
            temp_quotient <= next_quotient;
            temp_remainder <= next_remainder;
            count <= next_count;
        end
    end

    always_comb begin
        next_quotient = temp_quotient;
        next_remainder = temp_remainder;
        next_count = count;
        shifted_remainder = '0;
        shifted_quotient = '0;
        Result1 = '0;
        Result2 = '0;
        Result3 = '0;

        if (~abort) begin
            if (start_div && count == 'd17) begin
                next_quotient = usign_dividend;
                next_remainder = '0;
                next_count = count - 1;
            end else if (start_div && count != '0) begin
                next_count = count - 1;
                shifted_remainder = (temp_remainder << 2) | temp_quotient[NUM_BITS-1:NUM_BITS-2];
                shifted_quotient = temp_quotient << 2;
                Result1 = shifted_remainder - usign_divisor;
                Result2 = shifted_remainder - DivisorX2;
                Result3 = shifted_remainder - DivisorX3;
                if (Result1[NUM_BITS-1] | Result1[NUM_BITS]) begin
                    next_remainder = shifted_remainder;
                    next_quotient  = shifted_quotient | 0;
                    if (count == 1 && adjust_quotient) next_quotient = ~next_quotient + 1;

                    if (count == 1 && adjust_remainder) next_remainder = ~next_remainder + 1;
                end else if (Result2[NUM_BITS-1] | Result2[NUM_BITS]) begin
                    next_remainder = Result1[NUM_BITS-1:0];
                    next_quotient  = shifted_quotient | 1;
                    if (count == 1 && adjust_quotient) next_quotient = ~next_quotient + 1;

                    if (count == 1 && adjust_remainder) next_remainder = ~next_remainder + 1;
                end else if (Result3[NUM_BITS-1] | Result3[NUM_BITS]) begin
                    next_remainder = Result2[NUM_BITS-1:0];
                    next_quotient  = shifted_quotient | 2;
                    if (count == 1 && adjust_quotient) next_quotient = ~next_quotient + 1;

                    if (count == 1 && adjust_remainder) next_remainder = ~next_remainder + 1;
                end else begin
                    next_remainder = Result3[NUM_BITS-1:0];
                    next_quotient  = shifted_quotient | 3;
                    if (count == 1 && adjust_quotient) next_quotient = ~next_quotient + 1;

                    if (count == 1 && adjust_remainder) next_remainder = ~next_remainder + 1;
                end
            end
        end else begin
            next_count = 'd17;
        end
    end
endmodule