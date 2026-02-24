// Dummy register file for testing — 256 scalar registers, 4R/4W ports

`include "atalla_isa_types.vh"
`include "dummy_regfile_if.vh"

module dummy_regfile (
    input logic CLK,
    input logic nRST,
    dummy_regfile_if.rf rf_if
);

    import atalla_isa_pkg::*;

    word_t [255:0] register, next_reg;

    // Sequential update
    always_ff @(negedge CLK, negedge nRST) begin
        if (!nRST) begin
            register <= '0;
        end else begin
            register <= next_reg;
        end
    end

    // Write logic — all 4 write ports, r0 hardwired to 0
    always_comb begin
        next_reg = register;
        for (int i = 0; i < 4; i++) begin
            if (rf_if.WEN[i] && (rf_if.wsel[i] != '0)) begin
                next_reg[rf_if.wsel[i]] = rf_if.wdata[i];
            end
        end
    end

    // Read logic — all 4 read ports, r0 always returns 0, output 0 if REN not asserted
    always_comb begin
        for (int i = 0; i < 4; i++) begin
            if (rf_if.REN[i]) begin
                rf_if.rdata[i] = (rf_if.rsel[i] == '0) ? '0 : register[rf_if.rsel[i]];
            end else begin
                rf_if.rdata[i] = '0;
            end
        end
    end

endmodule