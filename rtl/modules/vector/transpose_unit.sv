`include "transpose_unit_if.vh"
`include "xbar_if.vh"

module transpose_unit (
    input logic CLK, nRST,
    transpose_unit_if.transpose tif
);

    xbar_if #(.SIZE(tif.VEC_LEN), .DWIDTH(tif.DATA_W)) xif();

    group_t input_matrix [SIZE];

    // Input CLOS Network (Barrel Shifter)
    assign xif.clk = CLK;
    assign xif.n_rst = nRST;
    assign xif.en = tif.valid_in;
    always_comb begin : assign_vector
    for (int i = 0; i < tif.VEC_LEN; i++) begin
        xif.in[i].din   = tif.vec_in[i];
        xif.in[i].shift = '0; // Or whatever logic you determine later TODO: FIX THIS
        end
    end

    clos #(.CLOS_SIZE(tif.VEC_LEN)) clos_inst (.xif(xif));

    typedef enum logic [1:0] {
        IDLE, 
        PUSHING, 
        POPPING
    } state_t;

    state_t state, n_state;
    logic [4:0] count, n_count; 

    // --- Control FSM ---
    always_comb begin : next_state
        n_state = state;
        n_count = count;
        unique case(state)
            IDLE: begin 
                if(tif.in.valid_in && tif.in.push_req) begin 
                    n_state = PUSHING;
                    n_count = count + 1; 
                end
            end
            PUSHING: begin
                if(tif.out.ready_out && tif.in.pop_req) begin 
                    n_state = POPPING;
                    n_count = 30; // TODO: Decide if this is right
                end
                if(tif.in.valid_in && tif.in.push_req) n_count = count + 1;
            end
            POPPING: begin
                if(count == 0) begin 
                    n_state = IDLE;
                    n_count = 0;
                end
                if(tif.out.ready_out && tif.in.pop_req) n_count = count - 1;
            end
        endcase
    end

    always_ff @(posedge CLK or negedge nRST) begin : general_ff
        if (!nRST) begin
            state <= IDLE;
            count <= '0;
        end else begin
            state <= n_state;
            count <= n_count;
        end
    end

    assign tif.valid_out  = (state == PUSHING);
    assign tif.ready_out  = (state == POPPING);

    // --- AGU and Bank Logic ---
    genvar b;
    integer i;
    generate
        for (b = 0; b < tif.VEC_LEN; b++) begin : gen_banks
            logic [4:0] bank_addr;
            logic [tif.DATA_W-1:0] rdata, wdata;
            logic rdone;

            // assign bank_addr = (state == POPPING) ? 
            //                    (b + tif.VEC_LEN - count) % tif.VEC_LEN : 
            //                    count;
            sram_bank #(
                .WIDTH(tif.DATA_W), 
                .HEIGHT(32)
            ) bank_inst (
                .clk(CLK), 
                .n_rst(nRST),
                .ren(state == POPPING),
                .raddr(bank_addr),
                .rdata(rdata),
                .rdone(rdone),
                .wen(state == PUSHING),
                .waddr(bank_addr),
                .wdata(wdata),
                .busy(),
                .wdone()
            );

            for(i = 0; i < tif.VEC_LEN; i++) begin
                assign bank_addr = i;
                assign wdata = xif.out[i];
            end

            assign xif.in[b].din   = rdata;
            assign xif.in[b].shift = (b + tif.VEC_LEN - count) % tif.VEC_LEN;
            
            // Only need to track rdone from one bank if they are synchronized
            if (b == 0) assign tif.vec_out_valid = (state == POPPING) && rdone;
        end
        
    endgenerate

    assign tif.vec_out = {>>{xif.out}};

endmodule
