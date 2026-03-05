// op_buffer.sv ===========================================================
// Operand buffer — holds read values across bank-conflict cycles
// ========================================================================
module op_buffer #(
    parameter DREAD_PORTS = 4,
    parameter VREG_W      = 512,
    parameter LOG_BANKS   = 2       // BANK_COUNT / 2
)(
    input  logic CLK, nRST,
    reg_file_if.op_buffer rif
);

    logic [DREAD_PORTS-1:0]              dready, dready_nxt;
    logic [LOG_BANKS-1:0]                ivalid, ivalid_nxt;
    logic [LOG_BANKS-1:0]                ivalid_pt;
    logic [DREAD_PORTS-1:0][VREG_W-1:0] vreg_tmp;
    logic                                no_conflict;
    logic                                done;

    // -----------------------------------------------------------------------
    // Combinational pair-valid (live path)
    // -----------------------------------------------------------------------
    generate
        genvar gp;
        for (gp = 0; gp < LOG_BANKS; gp++) begin : GEN_IVALID_PT
            if ((2*gp + 1) < DREAD_PORTS) begin
                assign ivalid_pt[gp] = (rif.reggie_dvalid[2*gp]   | dready[2*gp])
                                     & (rif.reggie_dvalid[2*gp+1] | dready[2*gp+1]);
            end else begin
                assign ivalid_pt[gp] = (rif.reggie_dvalid[2*gp]   | dready[2*gp]);
            end
        end
    endgenerate

    // -----------------------------------------------------------------------
    // Combinational logic
    // -----------------------------------------------------------------------
    always_comb begin
        dready_nxt = dready | rif.reggie_dvalid;

        for (int i = 0; i < LOG_BANKS; i++) begin
            if ((2*i + 1) < DREAD_PORTS)
                ivalid_nxt[i] = dready_nxt[2*i] & dready_nxt[2*i+1];
            else
                ivalid_nxt[i] = dready_nxt[2*i];
        end

        done = no_conflict & (&ivalid_nxt);

        rif.opbuff_ivalid = no_conflict ? ivalid_pt : ivalid;

        for (int i = 0; i < DREAD_PORTS; i++)
            rif.opbuff_vreg[i] = no_conflict ? rif.reggie_vreg[i] : vreg_tmp[i];
    end

    // -----------------------------------------------------------------------
    // Sequential logic
    // -----------------------------------------------------------------------
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            dready      <= '0;
            ivalid      <= '0;
            vreg_tmp    <= '{default:'0};
            no_conflict <= 1'b0;
        end else begin
            no_conflict <= rif.reggie_ready;

            if (done) begin
                dready   <= '0;
                ivalid   <= '0;
                vreg_tmp <= '{default:'0};
            end else begin
                dready <= dready_nxt;
                ivalid <= ivalid_nxt;

                for (int i = 0; i < DREAD_PORTS; i++)
                    if (rif.reggie_dvalid[i]) vreg_tmp[i] <= rif.reggie_vreg[i];
            end
        end
    end

endmodule