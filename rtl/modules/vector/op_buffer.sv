// Operand Buffer Module ==================================================
// Author: Joseph Ghanem
// Email: jghanem@purdue.edu
// Operand Buffer to keep read values during conflict
// ========================================================================
`include "vector_if.vh"
`include "vector_types.vh"

module op_buffer (
    input  logic CLK, nRST, accomplished,
    vector_if.op_buffer vif
);
    import vector_pkg::*;

    logic [READ_PORTS-1:0] dready, dready_nxt;
    logic [MASK_PORTS-1:0] mready, mready_nxt;
    logic no_conflict, done;

    vmask_t [MASK_PORTS-1:0] vmask_tmp;
    vreg_t  [READ_PORTS-1:0] vreg_tmp;

    logic [MASK_PORTS-1:0] pair_dready_nxt;
    logic [MASK_PORTS-1:0] ivalid_nxt, ivalid;

    // "Accept" when ALL groups are valid and the consumer is ready
    logic accept_all;

    // WILL CHANGE THIS LATER LOLLLLL
    logic [MASK_PORTS-1:0] ivalid_pt;

    assign ivalid_pt[0] =
        ( (vif.opbuff_in.dvalid[0] | dready[0]) &
        (vif.opbuff_in.dvalid[1] | dready[1]) &
        (vif.opbuff_in.mvalid[0] | mready[0]) );

    assign ivalid_pt[1] =
        ( (vif.opbuff_in.dvalid[2] | dready[2]) &
        (vif.opbuff_in.dvalid[3] | dready[3]) &
        (vif.opbuff_in.mvalid[1] | mready[1]) );

    always_comb begin
        dready_nxt = dready | vif.opbuff_in.dvalid;
        mready_nxt = mready | vif.opbuff_in.mvalid;

        for (int i = 0; i < MASK_PORTS; i++) begin
            pair_dready_nxt[i] = dready_nxt[2*i] & dready_nxt[2*i + 1];
            ivalid_nxt[i]      = pair_dready_nxt[i] & mready_nxt[i];
        end

        //accept_all = accomplished; //vif.opbuff_in.ready & accomplished;

        done = no_conflict & (&ivalid_nxt);
        vif.opbuff_out.ivalid = (no_conflict) ? ivalid_pt : ivalid;

        for (int i = 0; i < MASK_PORTS; i++) begin
            vif.opbuff_out.vmask[i] = (no_conflict) ? vif.opbuff_in.vmask[i] : vmask_tmp[i];
        end
        for (int i = 0; i < READ_PORTS; i++) begin
            vif.opbuff_out.vreg[i]  = (no_conflict) ? vif.opbuff_in.vreg[i]  : vreg_tmp[i];
        end
    end

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            dready    <= '0;
            mready    <= '0;
            ivalid   <= '0;
            vmask_tmp <= '{default:'0};
            vreg_tmp  <= '{default:'0};
        end else begin
            // Clear stickies ONLY after the op is actually accepted
            if (done) begin
                dready <= '0;
                mready <= '0;
                ivalid <= '0;
                vmask_tmp <= '{default:'0};
                vreg_tmp  <= '{default:'0};
            end else begin
                dready <= dready_nxt;
                ivalid <= ivalid_nxt;
                mready <= mready_nxt;
            end

            no_conflict = vif.opbuff_in.ready;

            // Capture any arriving fields
            for (int i = 0; i < MASK_PORTS; i++) begin
                if (vif.opbuff_in.mvalid[i]) vmask_tmp[i] <= vif.opbuff_in.vmask[i];
            end
            for (int i = 0; i < READ_PORTS; i++) begin
                if (vif.opbuff_in.dvalid[i]) vreg_tmp[i]  <= vif.opbuff_in.vreg[i];
            end
        end
    end
endmodule
