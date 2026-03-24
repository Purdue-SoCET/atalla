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

            // Arbiter ack: decode be_arb to the matching bank
            assign bank_if.fsm_arb     = (fsm.be_arb == i[$clog2(BANK_NUM)-1:0]);

            // --- Instantiate per-bank FSM ---
            fsm_mod u_fsm_mod (
                .CLK  (CLK),
                .nRST (nRST),
                .fsm  (bank_if.fsm_mod)
            );

            // --- Collect per-bank outputs ---
            assign bank_pop[i]   = bank_if.fsm_pop;
            assign bank_ready[i] = bank_if.fsm_ready;
            assign bank_cmd[i]   = bank_if.fsm_cmd;
        end
    endgenerate

    assign fsm.be_queue_ready = bank_ready;

    assign fsm.bq_pop = bank_pop;

    always_comb begin
        fsm.be_bg   = fsm.bq_bg[fsm.be_arb];
        fsm.be_b    = fsm.bq_b[fsm.be_arb];
        fsm.be_r    = fsm.bq_slot[fsm.be_arb].row;
        fsm.be_c    = fsm.bq_slot[fsm.be_arb].column;
        fsm.be_id   = fsm.bq_slot[fsm.be_arb].id_addr;
        fsm.be_cmd  = bank_cmd[fsm.be_arb];
        fsm.be_rlen = '0;
    end

endmodule