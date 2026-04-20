`include "ddr_controller_if.sv"
`include "dram_pkg.svh"
import dram_pkg::*;

module refresh_counter #(
    parameter N = $clog2(9 * tREFI) + 1
)(
    input logic CLK, nRST,
    ddr_controller_if.refresh_cntrl rcif
);
    logic [N-1:0] refresh_limit, next_refresh_limit;
    logic [N-1:0] refresh_count, next_refresh_count;

    always_ff @(posedge CLK, negedge nRST) begin : REFRESH_REG_LOGIC
        if (~nRST) begin
            refresh_count <= '0;
            refresh_limit <= tREFI[N-1:0];
        end
        else begin
            refresh_count <= next_refresh_count;
            refresh_limit <= next_refresh_limit;
        end
    end

    always_comb begin : REFRESH_COMB_LOGIC
        rcif.fsm_ref = 1'b0;
        next_refresh_limit = refresh_limit;

        // When a refresh just completed, reset the limit.
        // If the counter ran past tREFI before the refresh finished,
        // subtract the overshoot from the next limit so average
        // refresh rate is maintained.
        if (rcif.rf_done) begin
            if (refresh_count < tREFI[N-1:0]) begin
                next_refresh_limit = tREFI[N-1:0];
            end
            else begin
                next_refresh_limit = tREFI[N-1:0] - (refresh_count - tREFI[N-1:0]);
            end
        end

        // Counter increments once rf_enable (init_done) is asserted.
        // Resets to 0 when a refresh completes.
        next_refresh_count = (!rcif.rf_enable) ? refresh_count : refresh_count + 1;
        if (rcif.rf_done) begin
            next_refresh_count = '0;
        end

        // Assert refresh request when the count meets or exceeds the limit.
        if (refresh_count >= refresh_limit) begin
            rcif.fsm_ref = 1'b1;
        end
    end

endmodule
