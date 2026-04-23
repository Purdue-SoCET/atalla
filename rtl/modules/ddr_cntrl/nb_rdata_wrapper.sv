`timescale 1ns/1ps
`include "ddr_controller_if.sv"
`include "dram_pkg.svh"

// Read Data Wrapper
//
// Captures DDR4 read data from the DRAM DQ/DQS bus and returns it on the
// AXI R channel.
//
// Flow:
//   1. be_push_id fires  →  latch beat_max/axi_max, restart tRL countdown
//   2. Countdown expires →  assert rd_en
//   3. negedge CLKx2     →  sample DQS_t; edge_flag fires on every transition
//                            during the burst; store rdw.DQ into cap_buf[]
//   4. beat_cnt==beat_max → cap_done goes high (level, held until drain_active)
//   5. posedge CLK+1     →  dqs_done pulse (rising edge of cap_done in CLK
//                            domain); nb_read_id_queue sets enable→rq_rid valid
//   6. posedge CLK+2     →  drain_active set; AXI R beats presented from
//                            cap_buf[] back-to-back, one per CLK cycle
//   7. axi_cnt==axi_max  →  rlast fires on the last beat

module nb_rdata_wrapper (
    input logic CLK, CLKx2, nRST,
    ddr_controller_if.rdata_wrapper rdw
);
    import dram_pkg::*;

    // ── Read-latency countdown (CLK domain) ──────────────────────────────────
    localparam int RL_W = $clog2(tRL + 2);

    logic [RL_W-1:0] rl_cnt;
    logic            rd_en;
    logic [2:0]      beat_max;
    logic [2:0]      axi_max;

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            rl_cnt   <= '0;
            rd_en    <= 1'b0;
            beat_max <= '0;
            axi_max  <= '0;
        end else if (rdw.be_push_id) begin
            rl_cnt   <= RL_W'(tRL - 1);
            rd_en    <= 1'b0;
            beat_max <= rdw.be_rlen;
            axi_max  <= rdw.be_rlen;
        end else if (rl_cnt != '0) begin
            rl_cnt <= rl_cnt - 1;
        end else begin
            rd_en <= 1'b1;   // stays high; cap_cnt auto-resets after each burst
        end
    end

    // ── DQS edge detection (negedge CLKx2 domain) ────────────────────────────
    // Sample DQS_t at negedge CLKx2: this is the stable midpoint between DQS
    // transitions, which occur near CLKx2 posedge (aligned to DRAM CK).
    // The comparison fires at every negedge CLKx2 once DRAM starts toggling.
    logic DQS_prev;
    logic edge_flag;

    always_ff @(negedge CLKx2, negedge nRST) begin
        if (!nRST) DQS_prev <= 1'b0;
        else       DQS_prev <= rdw.DQS_t;
    end
    // Guard against X/Z on DQS_t (bus is tristate between bursts)
    assign edge_flag = (rdw.DQS_t !== 1'bx) && (rdw.DQS_t !== 1'bz) &&
                       (rdw.DQS_t !== DQS_prev);

    // ── DQ burst capture into 8-slot buffer (negedge CLKx2 domain) ───────────
    // cap_done is a level signal: goes high when the last beat is stored and
    // stays high until the CLK-domain drain_active handshake clears it.
    // This avoids CDC pulse-width issues between the two domains.
    logic [7:0][WORD_W-1:0] cap_buf;
    logic [2:0]              cap_cnt;
    logic                    cap_done;
    logic                    drain_active;   // read-back from CLK domain

    always_ff @(negedge CLKx2, negedge nRST) begin
        if (!nRST) begin
            cap_buf  <= '0;
            cap_cnt  <= '0;
            cap_done <= 1'b0;
        end else begin
            if (drain_active) begin
                cap_done <= 1'b0;   // CLK domain acknowledged — clear flag
            end else if (rd_en && edge_flag) begin
                cap_buf[cap_cnt] <= rdw.DQ;
                if (cap_cnt == beat_max) begin
                    cap_done <= 1'b1;
                    cap_cnt  <= '0;
                end else begin
                    cap_cnt <= cap_cnt + 3'd1;
                end
            end
        end
    end

    // ── dqs_done: 1-CLK pulse to nb_read_id_queue ────────────────────────────
    // Detect rising edge of cap_done in the CLK domain.
    // nb_read_id_queue registers enable on the next posedge CLK after dqs_done,
    // so rq_rid becomes valid one CLK after dqs_done fires.
    logic cap_done_d1, cap_done_d2;

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            cap_done_d1 <= 1'b0;
            cap_done_d2 <= 1'b0;
        end else begin
            cap_done_d1 <= cap_done;
            cap_done_d2 <= cap_done_d1;
        end
    end

    assign rdw.dqs_done = cap_done && !cap_done_d1;   // fires 1 CLK after capture

    // ── AXI R drain (CLK domain) ──────────────────────────────────────────────
    // Start draining on cap_done_d2 (2 CLK cycles after capture completes).
    // By then nb_read_id_queue has registered enable=1 and rq_rid is valid,
    // so the first AXI beat is presented with the correct rid.
    logic [WORD_W-1:0] rdata_reg;
    logic              rvalid_reg;
    logic [2:0]        axi_cnt;

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            rdata_reg    <= '0;
            rvalid_reg   <= 1'b0;
            axi_cnt      <= '0;
            drain_active <= 1'b0;
        end else begin
            if (cap_done_d2 && !drain_active) begin
                // First beat: load beat 0 and start presenting
                drain_active <= 1'b1;
                axi_cnt      <= '0;
                rdata_reg    <= cap_buf[0];
                rvalid_reg   <= 1'b1;
            end else if (drain_active && rvalid_reg && rdw.rready) begin
                if (axi_cnt == axi_max) begin
                    // Last beat handshaked — drain complete
                    rvalid_reg   <= 1'b0;
                    drain_active <= 1'b0;
                    axi_cnt      <= '0;
                end else begin
                    // Present next beat immediately (back-to-back, no gap)
                    axi_cnt    <= axi_cnt + 3'd1;
                    rdata_reg  <= cap_buf[axi_cnt + 3'd1];
                    rvalid_reg <= 1'b1;
                end
            end
        end
    end

    assign rdw.rvalid = rvalid_reg;
    assign rdw.rdata  = rdata_reg;
    assign rdw.rid    = rdw.rq_rid;
    assign rdw.rlast  = rvalid_reg && (axi_cnt == axi_max);
    assign rdw.rresp  = 2'b00;

endmodule
