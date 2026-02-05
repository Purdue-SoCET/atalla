module perf_handshake #(
    parameter int SIG_WIDTH = 1, // Width of the valid/ready signals
    parameter int CNT_WIDTH = 32 // Width of the cycle count
) (
    input logic CLK,
    input logic nRST,
    input logic [SIG_WIDTH-1:0]     valid, ready,
    output logic [CNT_WIDTH-1:0]    cnt_trans_cycles, cnt_stall_cycles,
                                    cnt_starve_cycles, cnt_total_items,
    input logic enable = 1'b1,
    input logic clear = 1'b0
);

  logic [SIG_WIDTH-1:0] trans_bits, stall_bits, starve_bits;
  logic [$clog2(SIG_WIDTH)+1:0] item_count;

  always_comb begin : handshake_bits_comb
    trans_bits = valid & ready;
    stall_bits = valid & ~ready;
    starve_bits = ~valid & ready;
  end

  perf_counter #(
    .WIDTH(CNT_WIDTH)
  ) u_cnt_trans (
    .CLK(CLK),
    .nRST(nRST),
    .enable(enable && |trans_bits),
    .clear(clear),
    .count(cnt_trans_cycles)
  );

  perf_counter #(
    .WIDTH(CNT_WIDTH)
  ) u_cnt_stall (
    .CLK(CLK),
    .nRST(nRST),
    .enable(enable && |stall_bits),
    .clear(clear),
    .count(cnt_stall_cycles)
  );

  perf_counter #(
    .WIDTH(CNT_WIDTH)
  ) u_cnt_starve (
    .CLK(CLK),
    .nRST(nRST),
    .enable(enable && |starve_bits),
    .clear(clear),
    .count(cnt_starve_cycles)
  );

  always_comb begin : total_items_comb
    item_count = '0;
    for (int i = 0; i < SIG_WIDTH; i++) begin
      if (trans_bits[i]) begin
        item_count++;
      end
    end
  end

  always_ff @(posedge CLK, negedge nRST) begin : total_items_ff
    if (!nRST) begin
      cnt_total_items <= '0;
    end else if (clear) begin
      cnt_total_items <= '0;
    end else if (enable) begin
      cnt_total_items <= cnt_total_items + item_count;
    end
  end

endmodule
