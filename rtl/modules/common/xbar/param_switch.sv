module param_switch #(
  parameter int N_IN  = 4,
  parameter int N_OUT  = 4,
  parameter int DATA_W  = 16
) (
  input  logic [DATA_W-1:0]       in_data  [N_IN-1:0],
  input  logic [$clog2(N_IN)-1:0] sel_in   [N_OUT-1:0],
  output logic [DATA_W-1:0]       out_data [N_OUT-1:0] 
);

  // genvar o;
  // generate
  // endgenerate
  always_comb begin
    for (int o = 0; o < N_OUT; o++) begin : g_out
      out_data[sel_in[o]] = in_data[o];
    end
  end

endmodule
