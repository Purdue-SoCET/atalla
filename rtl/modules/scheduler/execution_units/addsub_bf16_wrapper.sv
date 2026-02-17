`timescale 1ns/1ps
`include "addsub_bf16_wrapper_if.sv"

module addsub_bf16_wrapper (
    input  logic        clk,
    input  logic        nRST,

    addsub_bf16_wrapper_if.bf16_addsub addsub_if
);

logic [15:0] updated_bf_2_in;

assign addsub_if.rdOut = addsub_if.rdIn;
assign addsub_if.ready_in = addsub_if.ready_out;


add_bf16 adder_subber (.clk(clk), .nRST(nRST), .bf1_in(addsub_if.bf1_in), .bf2_in(updated_bf_2_in), .bf_out(addsub_if.bf_out), .overflow(), .underflow(), .invalid());


always_comb begin
    updated_bf_2_in = addsub_if.bf2_in;

    if(addsub_if.add_sub) begin
        updated_bf_2_in[15] = ~addsub_if.bf2_in[15];
    end
end

always_ff @(posedge clk, negedge nRST) begin
    if(!nRST) begin
        addsub_if.valid_out <= 1'b0;
    end
    else begin
        addsub_if.valid_out <= addsub_if.valid_in;
    end
end



endmodule