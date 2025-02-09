`include "fetch_if.vh"
`include "isa_types.vh"

module fetch(
    input logic CLK, nRST, ihit,
    fetch_if.ft fif
);
    import isa_pkg::*;

    parameter PC_INIT = 32'd0;
    word_t next_pc;

    always_comb begin
        if (fif.misprediction) begin
            next_pc = fif.correct_target;
        end else if (fif.stall || !fif.dispatch_free) begin
            next_pc = fif.pc;
        end else begin
            next_pc = fif.pc_prediction;
        end
    end

    always_ff @(posedge CLK, negedge nRST) begin : REG_LOGIC
        if (!nRST) begin
            fif.instr <= '0;
            fif.pc <= PC_INIT;
        end else begin
            if (ihit && !fif.stall && fif.dispatch_free) begin
                fif.instr <= fif.imemload;
                fif.pc <= next_pc;
            end
        end
    end
endmodule