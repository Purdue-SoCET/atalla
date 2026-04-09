/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

parameter int unsigned SCPAD_SIZE_BYTES = 1*1024*1024;
parameter int unsigned NUM_COLS = 32;
parameter int unsigned NUM_ROWS = 32;
parameter int unsigned ELEM_BITS = 16;
parameter int unsigned SRAM_VERT_FOLD_FACTOR = 2; // how many elements to pack horizontally to make AR ~~ 1; (ensure height !>>> width)
parameter int unsigned MAX_SRAM_DELAY = 3;
parameter int unsigned DRAM_ADDR_WIDTH  = 32;
parameter int unsigned MAX_DRAM_BUS_BITS = 64; // Our dram can only handle 64 bits at a time
<<<<<<< HEAD
parameter string XBAR_TYPE = "NAIVE";
parameter int unsigned NUM_SCPADS   = 2;
parameter int unsigned DRAM_ID_WIDTH  = 8;
parameter int unsigned MAX_REQ  = 8;
parameter int LATCH_INT = 0; // 1, to ignore latches in the hot path. 
=======
parameter int unsigned NUM_SCPADS   = 4;
parameter int unsigned DRAM_ID_WIDTH  = 8;
parameter int unsigned MAX_REQ  = 8;
parameter int LATCH_INT = 0; // 1, to ignore latches in the hot path. 
parameter int FULL_MATRIX_DIM_WIDTH = 20; // width of the full matrix column count field from SDMA ISA encoding
>>>>>>> origin/Vector_S26_L1_TB
