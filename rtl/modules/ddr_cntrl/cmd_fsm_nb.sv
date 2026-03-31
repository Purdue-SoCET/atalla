// CMD FSM Top Level
//
// Instantiates BANK_NUM per-bank FSM modules (fsm_mod).  Each FSM is
// fed by its bank's queue entry and controlled by the backend arbiter.
// When the arbiter acknowledges a bank (be_arb), that bank's address
// signals are routed to the backend arbiter outputs.

`include "ddr_controller_if.sv"
`include "dram_pkg.svh"

module cmd_fsm (
    input logic CLK, nRST,
    ddr_controller_if.command_fsm fsm
);

    import dram_pkg::*;

    logic [BANK_NUM-1:0] bank_ready;
    logic [BANK_NUM-1:0] bank_pop;
    logic [3:0]          bank_cmd [BANK_NUM-1:0];

    // Detect if any be_arb targets a bank in REF state
    logic any_ref_arb;
    always_comb begin
        any_ref_arb = 1'b0;
        for (int j = 0; j < BANK_NUM; j++) begin
            if (fsm.be_arb[j] && bank_cmd[j] == REF)
                any_ref_arb = 1'b1;
        end
    end

    genvar i;
    generate
        for (i = 0; i < BANK_NUM; i++) begin : gen_bank

            // Per-bank interface instance for fsm_mod connection
            ddr_controller_if bank_if();

            // --- Wire bank queue inputs to this bank's FSM ---
            assign bank_if.fsm_rw      = fsm.bq_slot[i].write;
            assign bank_if.fsm_r       = fsm.bq_slot[i].row;
            assign bank_if.fsm_bqready = fsm.bq_ready[i];

            // Refresh: fan out external refresh to every bank
            assign bank_if.fsm_ref     = fsm.fsm_ref;

            // Arbiter ack: per-bank arb OR broadcast when any REF bank is acked
            assign bank_if.fsm_arb     = fsm.be_arb[i] | (any_ref_arb && bank_cmd[i] == REF);

            // --- Instantiate per-bank FSM ---
            fsm_mod u_fsm_mod (
                .CLK  (CLK),
                .nRST (nRST),
                .fsm  (bank_if.fsm_mod)
            );

            // --- Collect per-bank outputs ---
            assign bank_pop[i]          = bank_if.fsm_pop;
            assign bank_ready[i]        = bank_if.fsm_ready;
            assign bank_cmd[i]          = bank_if.fsm_cmd;
        end
    endgenerate

    assign fsm.be_queue_ready = bank_ready;

    assign fsm.bq_pop = bank_pop;

    // One-hot be_arb to binary index for output mux
    logic [$clog2(BANK_NUM)-1:0] arb_sel;
    always_comb begin
        arb_sel = '0;
        for (int j = 0; j < BANK_NUM; j++) begin
            if (fsm.be_arb[j]) arb_sel = j[$clog2(BANK_NUM)-1:0];
        end
    end

    always_comb begin
        fsm.be_bg   = arb_sel[3:2];
        fsm.be_b    = arb_sel[1:0];
        fsm.be_r    = fsm.bq_slot[arb_sel].row;
        fsm.be_c    = fsm.bq_slot[arb_sel].column;
        fsm.be_id   = fsm.bq_slot[arb_sel].id_addr;
        fsm.be_rlen = '0;

        // be_cmd must carry ALL banks' commands so the arbiter can
        // inspect each bank's state independently for scheduling.
        for (int j = 0; j < BANK_NUM; j++) begin
            fsm.be_cmd[j] = fsm_t'(bank_cmd[j]);
        end
    end

endmodule