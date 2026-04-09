/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

<<<<<<< HEAD
import scpad_pkg::*;

module scratchpad (scpad_if.top sif); 

    generate
        if ((NUM_COLS & (NUM_COLS - 1)) != 0) initial $fatal(1, "NUM_COLS (%0d) must be a power of 2!", NUM_COLS);
        if ((SRAM_VERT_FOLD_FACTOR & (SRAM_VERT_FOLD_FACTOR - 1)) != 0) initial $fatal(1, "SRAM_VERT_FOLD_FACTOR (%0d) must be a power of 2!", SRAM_VERT_FOLD_FACTOR);
        if ((ELEM_BITS & (ELEM_BITS - 1)) != 0) initial $fatal(1, "ELEM_BITS (%0d) must be a power of 2!", ELEM_BITS);
=======
module scratchpad (scpad_if sif); 

    import scpad_pkg::*;

    generate
        `ifndef SYNTHESIS
        if ((NUM_COLS & (NUM_COLS - 1)) != 0) initial $fatal(1, "NUM_COLS (%0d) must be a power of 2!", NUM_COLS);
        if ((SRAM_VERT_FOLD_FACTOR & (SRAM_VERT_FOLD_FACTOR - 1)) != 0) initial $fatal(1, "SRAM_VERT_FOLD_FACTOR (%0d) must be a power of 2!", SRAM_VERT_FOLD_FACTOR);
        if ((ELEM_BITS & (ELEM_BITS - 1)) != 0) initial $fatal(1, "ELEM_BITS (%0d) must be a power of 2!", ELEM_BITS);
        `endif
>>>>>>> origin/Vector_S26_L1_TB
    endgenerate

    genvar ti;
    generate
        for (ti = 0; ti < NUM_SCPADS; ti++) begin : g_scpad
<<<<<<< HEAD
            frontend #(.IDX(ti)) frontend (.fcif(sif));
            backend #(.IDX(ti)) backend (.bif(sif));
=======
            frontend #(.IDX(ti)) frontend (.fvif(sif), .fsif(sif));
            backend #(.IDX(ti)) backend (.bshif(sif), .bbif(sif), .bdrif(sif));
>>>>>>> origin/Vector_S26_L1_TB
            body #(.IDX(ti)) body (.bif(sif));
        end
    endgenerate

<<<<<<< HEAD
endmodule
=======
endmodule
>>>>>>> origin/Vector_S26_L1_TB
