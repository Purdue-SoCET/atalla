`include "transpose_unit_if.vh"

module transpose_unit (
    transpose_unit_if.unit tif // Using the 'unit' modport
);

    // 1. Clos Network Interface (Internal)
    xbar_if #(.SIZE(tif.VEC_LEN), .DWIDTH(tif.DATA_W)) xif(tif.clk, tif.n_rst);
    assign xif.en = tif.en;

    // 2. Internal Logic (FSM & Counters)
    typedef enum logic [1:0] {IDLE, PUSHING, POPPING} state_t;
    state_t state;
    logic [4:0] count; 

    // --- Control FSM ---
    always_ff @(posedge tif.clk or negedge tif.n_rst) begin
        if (!tif.n_rst) begin
            state <= IDLE;
            count <= '0;
        end else if (tif.en) begin
            case (state)
                IDLE: begin
                    if (tif.push_req) state <= PUSHING;
                    else if (tif.pop_req) state <= POPPING;
                    count <= '0;
                end
                PUSHING: if (count == 5'd31) state <= IDLE; else count <= count + 1'b1;
                POPPING: if (count == 5'd31) state <= IDLE; else count <= count + 1'b1;
            endcase
        end
    end

    // Status Assignment
    assign tif.busy  = (state != IDLE);
    assign tif.full  = (state == IDLE && count == 5'd31); // Simple logic example
    assign tif.empty = (state == IDLE && count == 5'd0);

    // --- AGU and Bank Logic ---
    genvar b;
    generate
        for (b = 0; b < tif.VEC_LEN; b++) begin : gen_banks
            logic [4:0] bank_addr;
            logic [tif.DATA_W-1:0] rdata;
            logic rdone;

            assign bank_addr = (state == POPPING) ? 
                               (b + tif.VEC_LEN - count) % tif.VEC_LEN : 
                               count;

            sram_bank #(
                .WIDTH(tif.DATA_W), 
                .HEIGHT(32)
            ) bank_inst (
                .clk(tif.clk), 
                .n_rst(tif.n_rst),
                .ren(state == POPPING),
                .raddr(bank_addr),
                .rdata(rdata),
                .rdone(rdone),
                .wen(state == PUSHING),
                .waddr(bank_addr),
                .wdata(tif.vec_in[(b + tif.VEC_LEN - count) % tif.VEC_LEN]),
                .busy(),
                .wdone()
            );

            assign xif.in[b].din   = rdata;
            assign xif.in[b].shift = (b + tif.VEC_LEN - count) % tif.VEC_LEN;
            
            // Only need to track rdone from one bank if they are synchronized
            if (b == 0) assign tif.vec_out_valid = (state == POPPING) && rdone;
        end
    endgenerate

    clos #(.CLOS_SIZE(tif.VEC_LEN)) clos_inst (.xif(xif));

    assign tif.vec_out = {>>{xif.out}};

endmodule
