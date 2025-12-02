module param_switch #(
  parameter int N_IN  = 4,
  parameter int N_OUT  = 4,
  parameter int DATA_W  = 32
) (
  input logic [N_IN-1:0][DATA_W-1:0] in_data,
  input logic [N_OUT-1:0][$clog2(N_IN)-1:0] sel_in,
  output logic [N_OUT-1:0][DATA_W-1:0]  out_data
);

  genvar o;
  generate
    for (o = 0; o < N_OUT; o++) begin : g_out
      always_comb begin
        out_data[o] = in_data[ sel_in[o] ];
      end
    end
  endgenerate

endmodule
