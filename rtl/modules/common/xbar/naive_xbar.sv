`include "xbar_params.svh"
`include "xbar_if.sv"

module naive_xbar #(
    parameter int SIZE = 32,
    parameter int DWIDTH = 16
) (xbar_if.xbar xif);

    genvar i;
    generate
      for (i = 0; i < SIZE; i++) begin : gen_route
        // Route: output[i] gets data from input[shift[i]]
        assign xif.out[i] = xif.en ? xif.in[xif.in[i].shift].din : '0;
      end
    endgenerate

endmodule