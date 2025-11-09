/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

`ifndef SCPAD_PKG_SV
`define SCPAD_PKG_SV

package scpad_pkg;
    `include "scpad_params.svh"
    `include "xbar_params.svh"
    
    //////////////////////////////////////////////////////////////////////
    ///////////////////////// Derived Parameters /////////////////////////
    //////////////////////////////////////////////////////////////////////

    localparam int MAX_DIM_WIDTH  = $clog2(NUM_COLS); // bit length
    localparam int MAX_REQ_WIDTH  = $clog2(MAX_REQ); // bit length
    localparam int XBAR_LATENCY = (XBAR_TYPE == "BENES") ? BENES_LATENCY : 
                                (XBAR_TYPE == "BATCHER") ? BATCHER_LATENCY :  NAIVE_LATENCY;
    localparam int ELEM_BYTES  = ELEM_BITS/8;     
    localparam int ROW_BYTES = (NUM_COLS * ELEM_BITS)/8;   
    localparam int SRAM_HEIGHT = (SCPAD_SIZE_BYTES / ROW_BYTES);  // num slots in each bank 
    
    localparam int SRAM_SUBARRAY_HEIGHT = (SRAM_HEIGHT / SRAM_VERT_FOLD_FACTOR);
    localparam int SRAM_SUBARRAY_HEIGHT_BITS = $clog2(SRAM_SUBARRAY_HEIGHT); 
    localparam int SRAM_SUBARRAY_WIDTH_BITS = $clog2(SRAM_VERT_FOLD_FACTOR);

    localparam int SCPAD_ADDR_WIDTH = $clog2(SCPAD_SIZE_BYTES); // imagine scpad is flattened, and then addressable. 

    localparam int ROW_IDX_WIDTH  = $clog2(SRAM_HEIGHT);
    localparam int COL_IDX_WIDTH = $clog2(NUM_COLS);

    localparam int ROW_SHIFT = $clog2(ROW_BYTES);    
    localparam int ELEM_SHIFT = $clog2(ELEM_BYTES);        

    localparam int SCPAD_ID_WIDTH = $clog2(NUM_SCPADS);

    localparam int DRAM_VECTOR_MASK_LANES = MAX_DRAM_BUS_BITS/ELEM_BITS; // (64 bits / 16 bits) means 4 elements, lanes, per request. 
    localparam int DRAM_VECTOR_MASK_LANES_SHIFT = $clog2(DRAM_VECTOR_MASK_LANES);

    //////////////////////////////////////////////////////////////////////
    /////////////////////////// Helper Functions /////////////////////////
    //////////////////////////////////////////////////////////////////////

    function automatic void addr_to_row_col(
        input  logic [SCPAD_ADDR_WIDTH-1:0]      byte_addr,
        output logic [ROW_IDX_WIDTH-1:0]   row_idx,
        output logic [COL_IDX_WIDTH-1:0]   col_idx
    );
        row_idx = byte_addr[SCPAD_ADDR_WIDTH-1:ROW_SHIFT];
        col_idx = byte_addr[ROW_SHIFT-1:ELEM_SHIFT];
    endfunction

    function automatic logic [SCPAD_ADDR_WIDTH-1:0] row_col_to_addr(
        input logic [ROW_IDX_WIDTH-1:0] row_idx,
        input logic [COL_IDX_WIDTH-1:0] col_idx
    );
        return (row_idx << ROW_SHIFT) | (col_idx << ELEM_SHIFT);
    endfunction

    //////////////////////////////////////////////////////////////////////
    ////////////////////////////////// Enums /////////////////////////////
    //////////////////////////////////////////////////////////////////////

    typedef logic [NUM_COLS-1:0] mask_t;    
    typedef logic [NUM_COLS-1:0][ELEM_BITS-1:0] scpad_data_t;      
    typedef logic [NUM_COLS-1:0][COL_IDX_WIDTH-1:0] shift_mask_t; 
    typedef logic [NUM_COLS-1:0][ROW_IDX_WIDTH-1:0] slot_mask_t; 

    typedef enum logic { SRC_FE = 1'b0, SRC_BE = 1'b1 } src_t;

    // Scheduler FU <=> Backend
    typedef struct packed {
        logic valid; 
        logic write;
        logic [SCPAD_ADDR_WIDTH-1:0] spad_addr;
        logic [DRAM_ADDR_WIDTH-1:0] dram_addr;
        logic [MAX_DIM_WIDTH-1:0] num_rows;
        logic [MAX_DIM_WIDTH-1:0] num_cols;
        logic [SCPAD_ID_WIDTH-1:0] scpad_id;
    } sched_req_t;

    typedef struct packed {
        logic valid;
    } sched_res_t;

    typedef struct packed {
        logic valid; 
        logic write;
        logic [DRAM_ID_WIDTH-1:0]    id;
        logic [DRAM_ADDR_WIDTH-1:0]  dram_addr;
        logic [DRAM_VECTOR_MASK_LANES-1:0] dram_vector_mask;
        scpad_data_t wdata;
    } dram_req_q_t;

    typedef struct packed {
        logic valid; 
        logic write;
        logic [DRAM_ID_WIDTH-1:0]    id;
        logic [DRAM_ADDR_WIDTH-1:0]  dram_addr;
        logic [DRAM_VECTOR_MASK_LANES-1:0] dram_vector_mask;
        logic [MAX_DRAM_BUS_BITS-1:0] wdata;
    } dram_req_t;

    typedef struct packed {
        logic valid; 
        logic [DRAM_ADDR_WIDTH-1:0]   dram_addr;
        logic [DRAM_VECTOR_MASK_LANES-1:0]  dram_vector_mask;
        logic [MAX_DRAM_BUS_BITS-1:0] wdata;
    } dram_write_req_t;

    typedef struct packed {
        logic valid; 
        logic write; 
        logic [DRAM_ID_WIDTH-1:0] id;
        logic [MAX_DRAM_BUS_BITS-1:0] rdata;
    } dram_res_t;

    // Crossbar descriptors
    typedef struct packed {
        slot_mask_t slot_mask;
        shift_mask_t shift_mask;
        mask_t valid_mask;
    } xbar_desc_t;

    typedef struct packed {
        logic valid;
        logic [SCPAD_ADDR_WIDTH-1:0] spad_addr;
        scpad_data_t wdata;
        xbar_desc_t xbar;
    } sram_write_req_t;

    // FE/BE request/response structures
    typedef struct packed {
        logic valid;
        logic write; 
        logic [SCPAD_ADDR_WIDTH-1:0] spad_addr;
        logic [MAX_DIM_WIDTH-1:0] num_rows;
        logic [MAX_DIM_WIDTH-1:0] num_cols;
        logic [MAX_DIM_WIDTH-1:0] row_id;
        logic [MAX_DIM_WIDTH-1:0] col_id;
        logic row_or_col;
        xbar_desc_t xbar;
        scpad_data_t wdata;
    } req_t;

    typedef struct packed {
        logic valid;
        logic write; 
        scpad_data_t rdata;
    } res_t;

    // Router BE > FE selected requests/responses
    typedef struct packed {
        logic valid;
        logic write; 
        src_t  src;
        xbar_desc_t  xbar;
        scpad_data_t wdata;
    } sel_req_t;

    typedef struct packed {
        logic valid; 
        logic write; 
        src_t src;
        scpad_data_t rdata;
    } sel_res_t;

    // Swizzle Input
    typedef struct packed {
        logic row_or_col; 
        logic [SCPAD_ADDR_WIDTH-1:0] spad_addr;
        logic [MAX_DIM_WIDTH-1:0]    num_rows;
        logic [MAX_DIM_WIDTH-1:0]    num_cols;
        logic [MAX_DIM_WIDTH-1:0]    row_id;
        logic [MAX_DIM_WIDTH-1:0]    col_id;
    } swizz_req_t;

    // Swizzle Output
    typedef struct packed {
        xbar_desc_t xbar_desc;
    } swizz_res_t;

    // Backend DRAM Request Queue Input
    typedef struct packed {
        logic [DRAM_ADDR_WIDTH-1:0] dram_addr;
        logic [MAX_DIM_WIDTH-1:0]   id;
        logic [MAX_REQ_WIDTH-1:0]   sub_id;
        logic [MAX_REQ_WIDTH-1:0]   num_request;
        logic [DRAM_VECTOR_MASK_LANES-1:0]   dram_vector_mask;
        scpad_data_t sram_rdata;
        logic sram_res_valid;
        logic sched_valid;
        logic sched_write;
        logic be_stall;
        logic initial_request_done;
        logic dram_be_stall;
    } be_dram_request_queue_in_t;

    // Backend DRAM Request Queue Output
    typedef struct packed {
        dram_req_t dram_req;
        logic dram_queue_full;
        logic burst_complete;
        logic transaction_complete;
    } be_dram_request_queue_out_t;

    // Backend SRAM Write Latch Input
    typedef struct packed {
        logic [DRAM_ID_WIDTH-1:0] dram_id;
        logic dram_res_valid;
        xbar_desc_t xbar;
        logic [MAX_DRAM_BUS_BITS-1:0] dram_rddata;
        logic [MAX_REQ_WIDTH-1:0] num_request;
        logic be_stall;
        logic [SCPAD_ADDR_WIDTH-1:0] spad_addr;
    } be_sram_write_latch_in_t;

    // Backend SRAM Write Latch Output
    typedef struct packed {
        sram_write_req_t sram_write_req;
        logic sram_write_req_latched;
    } be_sram_write_latch_out_t;

endpackage

`endif