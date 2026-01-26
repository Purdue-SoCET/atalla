module param_switch #(
  parameter int N = 4,
  parameter int DATA_W = 16,
  localparam int SEL_W = (N <= 1) ? 1 : $clog2(N)
) (
  input logic [DATA_W-1:0] in_data  [N-1:0],
  input logic [SEL_W-1:0]  sel_in [N-1:0],
  output logic [DATA_W-1:0] out_data [N-1:0]
);

  always_comb begin
    for (int o = 0; o < N; o++) begin
      out_data[o] = '0;
    end

    for (int o = 0; o < N; o++) begin
      for (int i = 0; i < N; i++) begin
        unique if (sel_in[i] == o) begin
          out_data[o] = in_data[i];
        end
      end
    end
  end

`ifndef SYNTHESIS
  always_comb begin
    for (int a = 0; a < N; a++) begin
      for (int b = a+1; b < N; b++) begin
        if (sel_in[a] == sel_in[b]) begin
          $warning("param_switch: sel_in not unique: %0d and %0d both -> %0d", a, b, sel_in[a]);
        end
      end
    end
  end
`endif

endmodule
