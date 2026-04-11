`include "transpose_unit_if.vh"
`include "xbar_if.vh"

module transpose_unit (
    input logic CLK, nRST,
    transpose_unit_if.transpose tif
);  

    xbar_if #(.SIZE(tif.VEC_LEN), .DWIDTH(tif.DATA_W)) xif(.clk(CLK), .n_rst(nRST));

    typedef enum logic [1:0] {
        IDLE, 
        PUSHING, 
        POPPING
    } state_t;

    state_t state, n_state;
    logic [4:0] count, n_count; 
    logic ren;
    logic wen;

    // Buses to collect data from all SRAM banks
    logic [tif.DATA_W-1:0] sram_rdata [tif.VEC_LEN-1:0];
    logic [tif.VEC_LEN-1:0] sram_rdone;


    // --- Control FSM ---
    always_ff @(posedge CLK or negedge nRST) begin : general_ff
        if (!nRST) begin
            state <= IDLE;
            count <= '0;
        end else begin
            state <= n_state;
            count <= n_count;
        end
    end

    always_comb begin : next_state
        n_state = state;
        n_count = count;
        unique case(state)
            IDLE: begin 
                if(tif.valid_in && tif.push_req) begin 
                    n_state = PUSHING;
                    n_count = 0; 
                end
            end
            PUSHING: begin
                if(count == 31 && tif.push_req) begin
                    n_state = POPPING;
                    n_count = 0;
                end else if(tif.valid_in && tif.push_req) begin
                    n_count = count + 1;
                end
            end
            POPPING: begin
                if(count == 31 && tif.pop_req) begin 
                    n_state = IDLE;
                    n_count = 0;
                end else if(tif.ready_out && tif.pop_req) begin
                    n_count = count + 1;
                end
            end
        endcase
    end

    // --- Shared Clos Network Logic ---
    assign xif.en = (state == PUSHING && tif.valid_in) || (state == POPPING && tif.pop_req);

    always_comb begin : clos_input_mux
        for (int i = 0; i < tif.VEC_LEN; i++) begin
            if (state == PUSHING) begin
                xif.in[i].din = tif.vec_in[i];
                xif.in[i].shift = (i + count) % tif.VEC_LEN;
            end else begin
                xif.in[i].din = sram_rdata[i];
                xif.in[i].shift = (i + (tif.VEC_LEN - count)) % tif.VEC_LEN;
            end
        end
    end

    clos #(.CLOS_SIZE(tif.VEC_LEN), .CLOS_DWIDTH(tif.DATA_W)) clos_inst (.xif(xif));

    assign ren = state == POPPING;
    assign wen = tif.in.valid_in && state == PUSHING;

    // --- SRAM Bank Instantiation ---
    genvar b;
    integer i;
    generate
        for (b = 0; b < tif.VEC_LEN; b++) begin : gen_banks
            logic [4:0] bank_addr;
            logic [tif.DATA_W-1:0] rdata, wdata;
            logic rdone;

            assign bank_raddr = (b + (tif.VEC_LEN - count)) % tif.VEC_LEN;

            sram_bank #(
                .WIDTH(tif.DATA_W), 
                .HEIGHT(tif.VEC_LEN)
            ) bank_inst (
                .clk(CLK), 
                .n_rst(nRST),
                .ren(ren),
                .raddr(bank_raddr),
                .rdata(sram_rdata[b]),
                .rdone(sram_rdone[b]),
                .wen(wen),
                .waddr(count),
                .wdata(xif.out[b]),
                .busy(),
                .wdone()
            );
        end
    endgenerate

    // --- Output Assignments ---
    assign tif.valid_out = (state == POPPING) && sram_rdone[0];
    assign tif.ready_in = (state == IDLE || state == PUSHING);
    
    // The final output is the output of the Clos network during POPPING
    always_comb begin
        for(int i = 0; i < 32; i++) begin
            tif.vec_out[i] = (state == POPPING) ? xif.out[i] : '0;
        end
    end

endmodule
