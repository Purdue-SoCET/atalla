// FSM Module: Per-bank DDR4 command state machine
//
// Manages bank state and issues DRAM commands (ACT, READ, WRITE, PRE, REF)
// through a backend arbiter.  Tracks the activated row and enforces command
// timing constraints between states.
//
// Interface signals (fsm_mod modport):
//   Inputs:  fsm_rw      - Read(0) / Write(1) from bank queue head
//            fsm_r       - Row address from bank queue head
//            fsm_bqready - Bank queue has a pending request
//            fsm_arb     - Backend arbiter acknowledges this FSM's command
//            fsm_ref     - External refresh request (from system refresh counter)
//   Outputs: fsm_pop     - Pop front entry from bank queue (asserted on R/W completion)
//            fsm_ready   - Command eligible for arbiter scheduling (never in "ing" states)
//            fsm_cmd     - Current command (fsm_t encoding)
//
// Notes:
//   - The queue holds rw/row signals stable until fsm_pop; no latching needed.
//   - Refresh is triggered solely by the external fsm_ref signal; there is no
//     internal refresh counter.
//   - Row-hit detection avoids unnecessary ACT/PRE when the target row is
//     already open.
//   - A row must be closed (PRE) before REF can be issued.

`include "ddr_controller_if.sv"
`include "dram_pkg.svh"

module fsm_mod (
    input logic CLK, nRST,
    ddr_controller_if.fsm_mod fsm
);

    import dram_pkg::*;

    //------------------------------------------------------------------
    // Internal registers
    //------------------------------------------------------------------

    // FSM state
    fsm_t state, state_n;

    // Timing counter — enforces DRAM command timing
    logic [15:0] tim, tim_n;

    // Row state register: {valid, row[ROW_BITS-1:0]}
    // The valid bit indicates whether a row is currently activated.
    logic [ROW_BITS:0] rstate, rstate_n;

    // Refresh-pending flag: latches fsm_ref so the FSM can finish its
    // current command, precharge if needed, then issue REF.
    logic ref_pending, ref_pending_n;
    logic row_valid;
    logic row_hit;

    assign row_valid = rstate[ROW_BITS];
    assign row_hit   = row_valid && (rstate[ROW_BITS-1:0] == fsm.fsm_r);

    always_ff @(posedge CLK, negedge nRST) begin
        if (~nRST) begin
            state       <= FSM_IDLE;
            tim         <= '0;
            rstate      <= '0;
            ref_pending <= 1'b0;
        end else begin
            state       <= state_n;
            tim         <= tim_n;
            rstate      <= rstate_n;
            ref_pending <= ref_pending_n;
        end
    end

    always_comb begin
        // Defaults — hold current values, no pop, not ready for arbiter
        state_n       = state;
        tim_n         = tim;
        rstate_n      = rstate;
        ref_pending_n = ref_pending;

        fsm.fsm_pop   = 1'b0;
        fsm.fsm_ready = 1'b0;
        fsm.fsm_cmd   = state;

        // Latch external refresh request (sticky until serviced)
        if (fsm.fsm_ref) begin
            ref_pending_n = 1'b1;
        end

        case (state)
            FSM_IDLE: begin
                if (ref_pending) begin
                    // External refresh requested
                    if (row_valid) begin
                        // Must close the open row before refresh
                        state_n = PRE;
                    end else begin
                        // Row already closed — go straight to refresh
                        state_n = REF;
                    end
                end else if (fsm.fsm_bqready) begin
                    if (row_hit) begin
                        // Row already open and matches — skip ACT
                        state_n = fsm.fsm_rw ? FSM_WRITE : FSM_READ;
                    end else if (row_valid) begin
                        // Wrong row open — close it first
                        state_n = PRE;
                    end else begin
                        // No row open — activate the requested row
                        state_n = ACT;
                    end
                end
            end

            ACT: begin
                fsm.fsm_ready = 1'b1;
                if (fsm.fsm_arb) begin
                    state_n  = ACTing;
                    tim_n    = 16'(tRAS);           // TODO: tRCD timing
                    rstate_n = {1'b1, fsm.fsm_r};
                end
            end

            ACTing: begin
                if (tim > 16'd0) begin
                    tim_n = tim - 16'd1;
                end else begin
                    // tRCD elapsed — proceed to the queued command
                    state_n = fsm.fsm_rw ? FSM_WRITE : FSM_READ;
                end
            end

            FSM_READ: begin
                fsm.fsm_ready = 1'b1;
                if (fsm.fsm_arb) begin
                    state_n = READing;
                    tim_n   = 16'(tRL + tBURST + 1);            // TODO: read timing (tCL + tBURST)
                end
            end

            READing: begin
                if (tim > 16'd0) begin
                    tim_n = tim - 16'd1;
                end else begin
                    fsm.fsm_pop = 1'b1;
                    state_n     = FSM_IDLE;
                end
            end

            FSM_WRITE: begin
                fsm.fsm_ready = 1'b1;
                if (fsm.fsm_arb) begin
                    state_n = WRITEing;
                    tim_n   = 16'(tBURST + tWR + 2);            // TODO: write timing (tCWL + tBURST + tWR)
                end
            end

            WRITEing: begin
                if (tim > 16'd0) begin
                    tim_n = tim - 16'd1;
                end else begin
                    fsm.fsm_pop = 1'b1;
                    state_n     = FSM_IDLE;
                end
            end

            PRE: begin
                fsm.fsm_ready = 1'b1;
                if (fsm.fsm_arb) begin
                    state_n  = PREing;
                    tim_n    = 16'(tRP);           // TODO: tRP timing
                    rstate_n = '0;              // invalidate row
                end
            end

            PREing: begin
                if (tim > 16'd0) begin
                    tim_n = tim - 16'd1;
                end else begin
                    if (ref_pending) begin
                        // Precharge completed for pending refresh
                        state_n = REF;
                    end else if (fsm.fsm_bqready) begin
                        // Precharged for row miss — activate new row
                        state_n = ACT;
                    end else begin
                        state_n = FSM_IDLE;
                    end
                end
            end

            REF: begin
                fsm.fsm_ready = 1'b1;
                if (fsm.fsm_arb) begin
                    state_n       = REFing;
                    tim_n         = 16'(tRFC);
                    ref_pending_n = 1'b0;
                end
            end

            REFing: begin
                if (tim > 16'd0) begin
                    tim_n = tim - 16'd1;
                end else begin
                    state_n = FSM_IDLE;
                end
            end

            default: begin
                state_n = FSM_IDLE;
            end
        endcase
    end

endmodule