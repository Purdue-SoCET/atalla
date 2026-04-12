`include "transpose_unit_if.vh"
`include "xbar_if.vh"

module transpose_unit (
    input logic CLK, nRST,
    transpose_unit_if.transpose tif
);  

    xbar_if #(.SIZE(tif.VEC_LEN), .DWIDTH(tif.DATA_W)) xif(.clk(CLK), .n_rst(nRST));

    typedef enum logic [2:0] {
        IDLE,
        WAIT_CLOS_WRITE,
        BUSY_WRITE,
        POPPING,
        WAIT_SRAM,
        WAIT_CLOS_READ,
        DONE
    } state_t;
    state_t state, n_state;
    logic [4:0] count, n_count; 

    // Latency counter to track the 3-cycle path (1 SRAM + 2 Clos)
    logic [1:0] lat_count, n_lat_count;

    // SRAM wires
    logic [tif.DATA_W-1:0] sram_rdata [tif.VEC_LEN-1:0];
    logic [tif.VEC_LEN-1:0] sram_rdone;
    logic [tif.VEC_LEN-1:0] sram_wdone;
    logic ren, wen;


    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            state <= IDLE;
            count <= '0;
            lat_count <= '0;
        end else begin
            state <= n_state;
            count <= n_count;
            lat_count <= n_lat_count;
        end
    end

    always_comb begin
        n_state = state;
        n_count = count;
        n_lat_count = lat_count;

        case(state)
            IDLE: begin 
                if(tif.in.valid_in && tif.in.push_req) begin
                    n_lat_count = 0;
                    n_state = WAIT_CLOS_WRITE;
                end else if (tif.in.pop_req) begin
                    n_count = 0;
                    n_state = POPPING;
                end
            end
            WAIT_CLOS_WRITE: begin
                // Wait 2 cycles for data to reach the end of the Clos network
                if (lat_count == 2'd2) begin
                    n_state = BUSY_WRITE;
                end else begin
                    n_lat_count = lat_count + 1;
                end
            end

            // PUSH PATH: Wait for SRAM to finish writing current vector
            BUSY_WRITE: begin
                if(sram_wdone[0]) begin
                    if(count == 31) begin
                        n_count = 0;
                        n_state = IDLE; // Or a 'READY_TO_POP' state
                    end else begin
                        n_count = count + 1;
                        n_state = IDLE; // Return to IDLE to handshake next vector
                    end
                end
            end

            POPPING: begin
                n_state = WAIT_SRAM;
            end

            WAIT_SRAM: begin
                // Wait for SRAM to finish its variable read latency
                if (sram_rdone[0]) begin
                    n_lat_count = 0;
                    n_state = WAIT_CLOS_READ;
                end
            end

            WAIT_CLOS_READ: begin
                // Once SRAM is done, we need 2 cycles to flush the Clos pipe
                if (lat_count == 2'd2) begin 
                    n_state = DONE;
                end else begin
                    n_lat_count = lat_count + 1;
                end
            end

            DONE: begin
                // Hold valid_out until consumer is ready
                if (tif.in.ready_out) begin
                    if (count == (tif.VEC_LEN - 1)) begin
                        n_count = 0;
                        n_state = IDLE;
                    end else begin
                        n_count = count + 1;
                        n_state = POPPING; // Return to IDLE for next request
                    end
                end
            end
        endcase
    end

    // --- Shared Clos Network Logic ---
    assign xif.en = (state != IDLE);

    always_comb begin : clos_input_mux
        for (int i = 0; i < tif.VEC_LEN; i++) begin
            if (state == BUSY_WRITE || state == WAIT_CLOS_WRITE) begin
                xif.in[i].din = tif.in.vec_in[i];
                xif.in[i].shift = (i + count) % tif.VEC_LEN;
            end else begin
                xif.in[i].din = sram_rdata[i];
                xif.in[i].shift = (i + (tif.VEC_LEN - count)) % tif.VEC_LEN;
            end
        end
    end

    clos #(.CLOS_SIZE(tif.VEC_LEN), .CLOS_DWIDTH(tif.DATA_W)) clos_inst (.xif(xif));

    assign wen = (state == WAIT_CLOS_WRITE && lat_count == 2'd2);
    assign ren = state == POPPING;

    // --- SRAM Bank Instantiation ---
    generate
        for (genvar b = 0; b < tif.VEC_LEN; b++) begin : gen_banks
            logic [4:0] bank_raddr;
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
                .wdone(sram_wdone[b]),
                .busy()
            );
        end
    endgenerate

    // --- Output Assignments ---
    assign tif.out.valid_out = (state == DONE);
    assign tif.out.ready_in = (state == IDLE);
    
    // The final output is the output of the Clos network during POPPING
    always_comb begin
        for(int i = 0; i < tif.VEC_LEN; i++) begin
            tif.out.vec_out[i] = (state == DONE) ? xif.out[i] : '0;
        end
    end

endmodule
