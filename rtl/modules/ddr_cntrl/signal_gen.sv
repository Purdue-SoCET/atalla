`timescale 1ns/1ps
`include "ddr_controller_if.sv"
`include "dram_pkg.svh"

module signal_gen (
    input logic CLK,
    input logic nRST,
    ddr_controller_if.signal_gen sig
);
    import dram_pkg::*;

    logic [4:0] cmd_addr;
    logic issue;

    // issue is true when the state is transitioning — signals that a new
    // DDR4 command should be placed on the bus this cycle.
    assign issue = (sig.state != sig.nstate);

    always_comb begin : OUTPUT_VALUE
        // Default values — DESELECT (no operation)
        cmd_addr        = DESEL_CMD;
        sig.ALERT_n     = 1'b1;
        sig.PARITY      = 1'b0;
        sig.RESET_n     = 1'b1;
        sig.TEN         = 1'b0;
        sig.ODT         = 1'b0;
        sig.C           = '0;
        sig.BG          = '0;
        sig.BA          = '0;
        sig.ADDR        = '0;
        sig.CKE         = 1'b1;
        sig.ADDR_17     = 1'b0;
        sig.ZQ          = 1'b0;
        sig.PWR         = 1'b1;
        sig.VREF_CA     = 1'b1;
        sig.VREF_DQ     = 1'b1;

        // Case on nstate: the command for the INCOMING state is issued on the
        // cycle the transition occurs.  For init states without an `if(issue)`
        // guard (POWER_UP, PRE_RESET, RESET, NOP), the physical pin levels are
        // driven continuously while in that state — nstate == state on hold
        // cycles, so the case still matches.
        case (sig.nstate)
            POWER_UP: begin
                cmd_addr    = POWER_UP_PRG;
                sig.CKE     = 1'b0;
                sig.TEN     = 1'b0;
                sig.RESET_n = 1'b0;
                sig.PWR     = 1'b0;
                sig.VREF_CA = 1'b0;
                sig.VREF_DQ = 1'b0;
            end

            PRE_RESET: begin
                cmd_addr    = POWER_UP_PRG;
                sig.CKE     = 1'b0;
                sig.TEN     = 1'b0;
                sig.RESET_n = 1'b0;
                sig.PWR     = 1'b1;
                sig.VREF_CA = 1'b1;
                sig.VREF_DQ = 1'b1;
            end

            RESET: begin
                cmd_addr    = POWER_UP_PRG;
                sig.CKE     = 1'b0;
                sig.TEN     = 1'b0;
                sig.RESET_n = 1'b1;
            end

            NOP: begin
                cmd_addr = DESEL_CMD;
            end

            LOAD_MODE_DLL: begin
                if (issue) begin
                    cmd_addr  = LOAD_MODE_CMD;
                    sig.BG    = 2'h0;
                    sig.BA    = 2'h1;
                    sig.ADDR  = 14'h1;
                end
            end

            LOAD_BG0_REG3: begin
                if (issue) begin
                    cmd_addr  = LOAD_MODE_CMD;
                    sig.BG    = 2'h0;
                    sig.BA    = 2'h3;
                    sig.ADDR  = 14'h0;
                end
            end

            LOAD_BG1_REG6: begin
                if (issue) begin
                    cmd_addr  = LOAD_MODE_CMD;
                    sig.BG    = 2'h1;
                    sig.BA    = 2'h2;
                    sig.ADDR  = 14'h080F;
                end
            end

            LOAD_BG1_REG5: begin
                if (issue) begin
                    cmd_addr  = LOAD_MODE_CMD;
                    sig.BG    = 2'h1;
                    sig.BA    = 2'h1;
                    sig.ADDR  = 14'b0001000_0000000;
                end
            end

            LOAD_BG1_REG4: begin
                if (issue) begin
                    cmd_addr  = LOAD_MODE_CMD;
                    sig.BG    = 2'h1;
                    sig.BA    = 2'h0;
                    sig.ADDR  = 14'h1000;
                end
            end

            LOAD_BG0_REG2: begin
                if (issue) begin
                    cmd_addr  = LOAD_MODE_CMD;
                    sig.BG    = 2'h0;
                    sig.BA    = 2'h2;
                    sig.ADDR  = 14'h0088;
                end
            end

            LOAD_BG0_REG1: begin
                if (issue) begin
                    cmd_addr  = LOAD_MODE_CMD;
                    sig.BG    = 2'h0;
                    sig.BA    = 2'h1;
                    sig.ADDR  = 14'h0001;
                end
            end

            LOAD_BG0_REG0: begin
                if (issue) begin
                    cmd_addr  = LOAD_MODE_CMD;
                    sig.BG    = 2'h0;
                    sig.BA    = 2'h0;
                    sig.ADDR  = 14'h041d;
                end
            end

            ZQ_CL: begin
                if (issue) begin
                    cmd_addr  = ZQ_CMD;
                    sig.ADDR  = 14'h0400;
                end
            end

            ACTIVATE: begin
                if (issue && !sig.ref_re) begin
                    cmd_addr  = cmd_t'({2'b0, 1'b0, 1'b0, sig.R0[14]});
                    sig.BG    = sig.BG0;
                    sig.BA    = sig.BA0;
                    sig.ADDR  = sig.R0[13:0];
                end
            end

            WRITE: begin
                if (issue && !sig.ref_re) begin
                    cmd_addr      = WRITE_CMD;
                    sig.BG        = sig.BG0;
                    sig.BA        = sig.BA0;
                    sig.ADDR      = {1'b0, 1'b1, 1'b0, 1'b0, sig.C0};
                end
            end

            READ: begin
                if (issue && !sig.ref_re) begin
                    cmd_addr      = READ_CMD;
                    sig.BG        = sig.BG0;
                    sig.BA        = sig.BA0;
                    sig.ADDR      = {1'b0, 1'b1, 1'b0, 1'b0, sig.C0};
                end
            end

            PRECHARGE: begin
                if (issue) begin
                    cmd_addr      = PRECHARGE_CMD;
                    sig.BG        = sig.BG0;
                    sig.BA        = sig.BA0;
                    sig.ADDR[10]  = 1'b0;  // single-bank precharge
                end
            end

            PRECHARGE_RE: begin
                if (issue) begin
                    cmd_addr      = PRECHARGE_CMD;
                    sig.BG        = sig.BG0;
                    sig.BA        = sig.BA0;
                    sig.ADDR[10]  = 1'b1;  // precharge all banks (for refresh)
                end
            end

            REFRESH: begin
                if (issue) begin
                    cmd_addr = REFRESH_CMD;
                    sig.BG   = '0;
                    sig.BA   = '0;
                end
            end

            default: begin
                cmd_addr = DESEL_CMD;
            end
        endcase

        // Map 5-bit command word to DDR4 physical pins
        {sig.CS_n, sig.ACT_n, sig.RAS_n_A16, sig.CAS_n_A15, sig.WE_n_A14} = cmd_addr;
    end

endmodule
