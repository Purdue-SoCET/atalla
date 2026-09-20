`include "atalla_isa_types.vh"
`include "move_to_scalar_if.vh"

import atalla_isa_pkg::*;

module move_to_scalar (
    input logic CLK, nRST,
    move_to_scalar_if.mainport mvmt_if
);

    typedef enum logic { START, LATCH } state_t;
    state_t cur_state, n_state;

    // Latch storage
    logic [7:0] rdIn_latch,   rdIn_nlatch;
    word_t      data_latch,   data_nlatch;
    logic       valid_latch,  valid_nlatch;

    // Current-cycle values fed to outputs
    logic [7:0] cur_rdIn;
    word_t      cur_data;
    logic       cur_valid;

    // -----------------------------------------------------------------------
    // Combinational
    // -----------------------------------------------------------------------
    always_comb begin
        // Default: next-latch holds current latch
        n_state       = cur_state;
        rdIn_nlatch   = rdIn_latch;
        data_nlatch   = data_latch;
        valid_nlatch  = valid_latch;

        // Default: drive from inputs
        cur_rdIn  = mvmt_if.rdIn;
        cur_data  = mvmt_if.data_in;
        cur_valid = mvmt_if.valid_in;

        mvmt_if.d2_ready  = 1'b1;
        mvmt_if.valid_out = 1'b0;

        case (cur_state)
            START: begin
                mvmt_if.d2_ready  = 1'b1;
                mvmt_if.valid_out = mvmt_if.valid_in;

                if (mvmt_if.valid_in && !mvmt_if.ready_WB) begin
                    // WB not ready — latch and stall
                    n_state      = LATCH;
                    mvmt_if.d2_ready = 1'b0;

                    rdIn_nlatch  = mvmt_if.rdIn;
                    data_nlatch  = mvmt_if.data_in;
                    valid_nlatch = mvmt_if.valid_in;
                end
            end

            LATCH: begin
                // Hold latched values until WB accepts
                cur_rdIn  = rdIn_latch;
                cur_data  = data_latch;
                cur_valid = valid_latch;

                mvmt_if.d2_ready  = 1'b0;
                mvmt_if.valid_out = 1'b1;

                if (mvmt_if.ready_WB) begin
                    n_state      = START;
                    mvmt_if.d2_ready = 1'b1;
                end
            end
        endcase
    end

    // -----------------------------------------------------------------------
    // Output assignments
    // -----------------------------------------------------------------------
    assign mvmt_if.rdOut    = cur_rdIn;
    assign mvmt_if.data_out = cur_data;

    // -----------------------------------------------------------------------
    // Sequential
    // -----------------------------------------------------------------------
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            cur_state  <= START;
            rdIn_latch  <= '0;
            data_latch  <= '0;
            valid_latch <= '0;
        end else begin
            cur_state  <= n_state;
            rdIn_latch  <= rdIn_nlatch;
            data_latch  <= data_nlatch;
            valid_latch <= valid_nlatch;
        end
    end

endmodule