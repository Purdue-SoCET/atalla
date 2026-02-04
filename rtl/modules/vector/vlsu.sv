`include "vector_pkg.vh"
`include "scpad_params.svh"
`include "scpad_pkg.sv"

module vlsu #(
    parameter int FIFO_DEPTH = 13,       // Matches scratchpad latency
    parameter int NUM_VREGS  = 256       // Number of vector registers
) (
    input  logic        CLK,
    input  logic        nRST,

    input  logic                                    sched_valid_in,
    output logic                                    sched_ready_out,
    input  logic                                    sched_write,     // 1=store, 0=load
    input  logic [scpad_pkg::SCPAD_ADDR_WIDTH-1:0]  sched_addr,      // Scratchpad address
    input  logic [scpad_pkg::SCPAD_ID_WIDTH-1:0]    sched_sp_sel,    // Scratchpad select
    input  logic [vector_pkg::VIDX_W-1:0]           sched_vdst,      // Dest register (loads)
    
    // Swizzle parameters for scratchpad
    input  logic [scpad_pkg::MAX_DIM_WIDTH-1:0]     sched_num_rows,
    input  logic [scpad_pkg::MAX_DIM_WIDTH-1:0]     sched_num_cols,
    input  logic [scpad_pkg::MAX_DIM_WIDTH-1:0]     sched_row_id,
    input  logic [scpad_pkg::MAX_DIM_WIDTH-1:0]     sched_col_id,
    input  logic                                    sched_row_or_col,

    input  vector_pkg::vreg_t                       vrf_store_data,
    input  logic                                    vrf_store_valid,

    output scpad_pkg::req_t                         sp_req  [scpad_pkg::NUM_SCPADS],
    input  logic                                    sp_stall [scpad_pkg::NUM_SCPADS],
    input  scpad_pkg::res_t                         sp_res  [scpad_pkg::NUM_SCPADS],

    output vector_pkg::vreg_t                       wb_load_data,
    output logic [vector_pkg::VIDX_W-1:0]           wb_vdst,
    output logic                                    wb_valid_out,
    input  logic                                    wb_ready_in,

    output logic                                    vlsu_busy,
    output logic                                    load_queue_full [scpad_pkg::NUM_SCPADS]
);

    import vector_pkg::*;
    import scpad_pkg::*;

    localparam int VDST_WIDTH = VIDX_W;
    
    logic [NUM_SCPADS-1:0]                   fifo_wr_en;
    logic [NUM_SCPADS-1:0]                   fifo_shift;
    logic [NUM_SCPADS-1:0][VDST_WIDTH-1:0]   fifo_din;
    logic [NUM_SCPADS-1:0][VDST_WIDTH-1:0]   fifo_dout;
    logic [NUM_SCPADS-1:0]                   fifo_empty;
    logic [NUM_SCPADS-1:0]                   fifo_full;
    
    genvar gi;
    generate
        for (gi = 0; gi < NUM_SCPADS; gi++) begin : gen_load_queues
            sync_fifo #(
                .FIFODEPTH(FIFO_DEPTH),
                .DATAWIDTH(VDST_WIDTH)
            ) load_queue (
                .nRST   (nRST),
                .CLK    (CLK),
                .wr_en  (fifo_wr_en[gi]),
                .shift  (fifo_shift[gi]),
                .din    (fifo_din[gi]),
                .dout   (fifo_dout[gi]),
                .empty  (fifo_empty[gi]),
                .full   (fifo_full[gi])
            );
        end
    endgenerate
    
    logic is_load;
    logic is_store;
    logic [SCPAD_ID_WIDTH-1:0] sp_select;  // Which scratchpad (parameterized width)
    logic can_accept_load;
    logic can_accept_store;
    logic can_accept_req;
    logic [NUM_SCPADS-1:0] sp_res_pending;  // Response pending per scratchpad
    
    // For response arbitration - find first pending response
    logic found_pending;
    logic [SCPAD_ID_WIDTH-1:0] pending_sp_idx;
    
    always_comb begin
        fifo_wr_en = '0;
        fifo_shift = '0;
        fifo_din   = '0;
        
        // Scratchpad request defaults
        for (int i = 0; i < NUM_SCPADS; i++) begin
            sp_req[i].valid      = 1'b0;
            sp_req[i].write      = 1'b0;
            sp_req[i].spad_addr  = '0;
            sp_req[i].num_rows   = '0;
            sp_req[i].num_cols   = '0;
            sp_req[i].row_id     = '0;
            sp_req[i].col_id     = '0;
            sp_req[i].row_or_col = 1'b0;
            sp_req[i].xbar       = '0;
            sp_req[i].wdata      = '0;
        end
        
        // Writeback defaults
        wb_load_data  = '0;
        wb_vdst       = '0;
        wb_valid_out  = 1'b0;
        
        // Response pending defaults
        sp_res_pending = '0;
        found_pending  = 1'b0;
        pending_sp_idx = '0;
        
        is_load   = sched_valid_in && !sched_write;
        is_store  = sched_valid_in && sched_write;
        sp_select = sched_sp_sel;  // Use full width for scratchpad selection
        
        
        // For loads: target scratchpad's FIFO must not be full, and SP not stalled
        can_accept_load = !fifo_full[sp_select] && !sp_stall[sp_select];
        
        // For stores: SP must not be stalled, and VRF must have valid data
        can_accept_store = !sp_stall[sp_select] && vrf_store_valid;
        
        // Can accept when conditions met or no valid request
        can_accept_req = is_load  ? can_accept_load  : 
                         is_store ? can_accept_store : 1'b1;
        

        sched_ready_out = can_accept_req;

        if (is_load && can_accept_load) begin
            // Push destination register to appropriate FIFO
            fifo_wr_en[sp_select] = 1'b1;
            fifo_din[sp_select]   = sched_vdst;
            
            // Send load request to scratchpad
            sp_req[sp_select].valid      = 1'b1;
            sp_req[sp_select].write      = 1'b0;  // Read
            sp_req[sp_select].spad_addr  = sched_addr;
            sp_req[sp_select].num_rows   = sched_num_rows;
            sp_req[sp_select].num_cols   = sched_num_cols;
            sp_req[sp_select].row_id     = sched_row_id;
            sp_req[sp_select].col_id     = sched_col_id;
            sp_req[sp_select].row_or_col = sched_row_or_col;
        end

        if (is_store && can_accept_store) begin
            // Send store request with data from VRF
            sp_req[sp_select].valid      = 1'b1;
            sp_req[sp_select].write      = 1'b1;  // Write
            sp_req[sp_select].spad_addr  = sched_addr;
            sp_req[sp_select].num_rows   = sched_num_rows;
            sp_req[sp_select].num_cols   = sched_num_cols;
            sp_req[sp_select].row_id     = sched_row_id;
            sp_req[sp_select].col_id     = sched_col_id;
            sp_req[sp_select].row_or_col = sched_row_or_col;
            sp_req[sp_select].wdata      = vrf_store_data;
        end

        for (int i = 0; i < NUM_SCPADS; i++) begin
            sp_res_pending[i] = sp_res[i].valid && !sp_res[i].write && !fifo_empty[i];
        end
        
 
        for (int i = 0; i < NUM_SCPADS; i++) begin
            if (sp_res_pending[i] && !found_pending) begin
                found_pending  = 1'b1;
                pending_sp_idx = i[SCPAD_ID_WIDTH-1:0];
            end
        end

        if (found_pending && wb_ready_in) begin
            wb_load_data  = sp_res[pending_sp_idx].rdata;
            wb_vdst       = fifo_dout[pending_sp_idx];
            wb_valid_out  = 1'b1;
            fifo_shift[pending_sp_idx] = 1'b1;  // Pop FIFO
        end

        vlsu_busy = |(~fifo_empty);  // Busy if any FIFO is not empty
        for (int i = 0; i < NUM_SCPADS; i++) begin
            load_queue_full[i] = fifo_full[i];
        end
    end

endmodule