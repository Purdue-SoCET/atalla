/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

`include "xbar_if.sv"

module wxbar #(parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0) (scpad_if wif); 

    import scpad_pkg::*;

    // Metadata structure - includes shift_mask for tracking through pipeline
    typedef struct packed {
        logic valid;
        logic write;
        src_t src;
        slot_mask_t  slot_mask;
        mask_t valid_mask;
        shift_mask_t shift_mask;  // Need to track for rxbar un-swizzling
    } pass_t;

    // Crossbar interface
    xbar_if #(.SIZE(NUM_COLS), .DWIDTH(ELEM_BITS)) wxbar_vif (.clk(wif.clk), .n_rst(wif.n_rst));

    // Connect crossbar inputs
    // Check if shift_mask appears uninitialized (all zeros except possibly index 0)
    logic shift_mask_is_zero;
    always_comb begin
        shift_mask_is_zero = 1'b1;
        for (int i = 1; i < NUM_COLS; i++) begin
            if (wif.head_stomach_req[IDX].xbar.shift_mask[i] != '0)
                shift_mask_is_zero = 1'b0;
        end
    end
    
    always_comb begin 
        wxbar_vif.en = wif.head_stomach_req[IDX].valid && !wif.w_stall[IDX];
        for (int i = 0; i < NUM_COLS; i++) begin 
            wxbar_vif.in[i].din = wif.head_stomach_req[IDX].wdata[i];
            // If shift_mask appears uninitialized, use identity permutation
            // Otherwise use the provided shift_mask for actual swizzling
            if (shift_mask_is_zero) begin
                wxbar_vif.in[i].shift = i[$clog2(NUM_COLS)-1:0];
            end else begin
                wxbar_vif.in[i].shift = wif.head_stomach_req[IDX].xbar.shift_mask[i];
            end
        end 
    end

    // Instantiate crossbar
    generate
        case (XBAR_TYPE)
            "NAIVE": begin : gen_naive
                naive_xbar #(.SIZE(NUM_COLS), .DWIDTH(ELEM_BITS)) u_wxbar (.xif(wxbar_vif));
            end
            "BENES": begin : gen_benes
                localparam int TAGWIDTH = $clog2(NUM_COLS);
                localparam int STAGES = (2 * TAGWIDTH) - 1;
                localparam int HALF = (NUM_COLS >> 1);
                localparam int BITWIDTH = STAGES * HALF;
                logic [BITWIDTH-1:0] control_bit;
                assign control_bit = '0;  // TODO: ROM lookup
                benes #(.SIZE(NUM_COLS), .DWIDTH(ELEM_BITS)) u_wxbar (
                    .xif(wxbar_vif), .control_bit(control_bit)
                );
            end
            "BATCHER": begin : gen_batcher
                batcher #(.SIZE(NUM_COLS), .DWIDTH(ELEM_BITS)) u_wxbar (.xif(wxbar_vif));
            end
            default: begin : gen_default
                naive_xbar #(.SIZE(NUM_COLS), .DWIDTH(ELEM_BITS)) u_wxbar (.xif(wxbar_vif));
            end
        endcase
    endgenerate

    // Use FIFO-based approach for all crossbar types
    // For BENES/BATCHER with internal pipeline, delay metadata to match crossbar latency first
    localparam FIFO_DEPTH = 16;
    
    logic fifo_empty, fifo_full;
    logic rd_en, rd_valid;
    pass_t fifo_in, fifo_out;
    scpad_data_t wdata_fifo_in, wdata_fifo_out;
    
    // Input metadata (before any delay)
    pass_t meta_in;
    always_comb begin
        meta_in.valid      = wif.head_stomach_req[IDX].valid && !wif.w_stall[IDX] && !fifo_full;
        meta_in.write      = wif.head_stomach_req[IDX].write;
        meta_in.src        = wif.head_stomach_req[IDX].src;
        meta_in.slot_mask  = wif.head_stomach_req[IDX].xbar.slot_mask;
        meta_in.valid_mask = wif.head_stomach_req[IDX].xbar.valid_mask;
        meta_in.shift_mask = wif.head_stomach_req[IDX].xbar.shift_mask;
    end
    
    generate
        if (XBAR_TYPE == "NAIVE") begin : gen_naive_path
            // NAIVE: No crossbar delay - direct to FIFO
            assign fifo_in = meta_in;
            assign wdata_fifo_in = wif.head_stomach_req[IDX].wdata;
            
        end else begin : gen_pipelined_path
            // BENES/BATCHER: Crossbar has internal pipeline
            // Delay metadata by XBAR_LATENCY to match crossbar output timing
            
            pass_t meta_delay [XBAR_LATENCY];
            
            always_ff @(posedge wif.clk or negedge wif.n_rst) begin
                if (!wif.n_rst) begin
                    for (int i = 0; i < XBAR_LATENCY; i++)
                        meta_delay[i] <= '0;
                end else begin
                    meta_delay[0] <= meta_in;
                    for (int i = 1; i < XBAR_LATENCY; i++)
                        meta_delay[i] <= meta_delay[i-1];
                end
            end
            
            // Delayed metadata aligns with crossbar output
            assign fifo_in = meta_delay[XBAR_LATENCY-1];
            
            // Capture crossbar output (already delayed by XBAR_LATENCY internally)
            always_comb begin
                for (int i = 0; i < NUM_COLS; i++)
                    wdata_fifo_in[i] = wxbar_vif.out[i];
            end
        end
    endgenerate
    
    assign rd_en = !wif.w_stall[IDX] && !fifo_empty;
    
    // Metadata FIFO
    sync_fifo #(.DEPTH(FIFO_DEPTH), .DWIDTH($bits(pass_t))) meta_fifo (
        .clk(wif.clk), .rstn(wif.n_rst),
        .wr_en(fifo_in.valid),
        .din(fifo_in),
        .rd_en(rd_en),
        .dout(fifo_out),
        .full(fifo_full),
        .empty(fifo_empty)
    );
    
    // Wdata FIFO
    sync_fifo #(.DEPTH(FIFO_DEPTH), .DWIDTH($bits(scpad_data_t))) wdata_fifo (
        .clk(wif.clk), .rstn(wif.n_rst),
        .wr_en(fifo_in.valid),
        .din(wdata_fifo_in),
        .rd_en(rd_en),
        .dout(wdata_fifo_out),
        .full(),
        .empty()
    );
    
    always_ff @(posedge wif.clk or negedge wif.n_rst) begin
        if (!wif.n_rst) rd_valid <= 1'b0;
        else rd_valid <= rd_en;
    end
    
    // Outputs
    assign wif.xbar_cntrl_req[IDX].valid           = rd_valid && fifo_out.valid;
    assign wif.xbar_cntrl_req[IDX].write           = fifo_out.write;
    assign wif.xbar_cntrl_req[IDX].src             = fifo_out.src;
    assign wif.xbar_cntrl_req[IDX].xbar.slot_mask  = fifo_out.slot_mask;
    assign wif.xbar_cntrl_req[IDX].xbar.valid_mask = fifo_out.valid_mask;
    assign wif.xbar_cntrl_req[IDX].xbar.shift_mask = fifo_out.shift_mask;
    assign wif.xbar_cntrl_req[IDX].xbar.rom_id     = '0;
    assign wif.xbar_cntrl_req[IDX].wdata           = wdata_fifo_out;

endmodule

`ifndef SYNTHESIS



`endif