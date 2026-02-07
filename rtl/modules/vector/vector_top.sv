module vector_top
    import vector_pkg::*;
    import scpad_pkg::*;
#(
    parameter int VLSU_FIFO_DEPTH = 13,
    parameter int NUM_VREGS       = 256
) (
    input  logic             CLK,
    input  logic             nRST,
    vlsu_if                  vif,
    scpad_if.vec_frontend    sif
);
    genvar gi;
    generate
        for (gi = 0; gi < NUM_SCPADS; gi++) begin : gen_vlsu
            vlsu #(
                .FIFO_DEPTH (VLSU_FIFO_DEPTH),
                .NUM_VREGS  (NUM_VREGS),
                .IDX        (gi[SCPAD_ID_WIDTH-1:0])
            ) u_vlsu (
                .vif (vif),
                .sif (sif)
            );
        end
    endgenerate

endmodule