module param_switch #(
  parameter int N  = 4,
  parameter int DATA_W  = 16
) (
  input  logic [DATA_W-1:0] in_data  [N-1:0],
  input  logic [$clog2(N)-1:0] sel_in   [N-1:0],
  output logic [DATA_W-1:0] out_data [N-1:0] 
);

  always_comb begin
    for (int o = 0; o < N; o++) begin 
      out_data[sel_in[o]] = in_data[o];
    end
  end

endmodule