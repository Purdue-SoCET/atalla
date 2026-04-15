`timescale 1ns/1ps

module simple_icache (
    input  logic         clk,
    input  logic         rst_n,

    // Request from fetch stage
    input  logic         req_valid,
    input  logic [31:0]  req_base_addr,
    output logic         req_ready,

    // Response back to fetch stage
    output logic         resp_valid,
    output logic [159:0] resp_data,
    output logic         busy,

    // Interface to memory
    output logic         mem_req_valid,
    output logic         mem_req_we,
    output logic [31:0]  mem_req_addr,
    output logic [31:0]  mem_req_wdata,
    input  logic [31:0]  mem_resp_rdata,
    input  logic         mem_resp_hit
);

    typedef enum logic [2:0] {
        IC_IDLE   = 3'd0,
        IC_GET_W0 = 3'd1,
        IC_GET_W1 = 3'd2,
        IC_GET_W2 = 3'd3,
        IC_GET_W3 = 3'd4,
        IC_GET_W4 = 3'd5,
        IC_RESP   = 3'd6
    } ic_state_t;

    ic_state_t state;

    logic [31:0] base_addr_reg;
    logic [31:0] word0_reg, word1_reg, word2_reg, word3_reg, word4_reg;

    assign busy = (state != IC_IDLE);

    always_comb begin
        req_ready     = 1'b0;
        resp_valid    = 1'b0;
        resp_data     = 160'h0;

        mem_req_valid = 1'b0;
        mem_req_we    = 1'b0;
        mem_req_addr  = 32'h0;
        mem_req_wdata = 32'h0;

        case (state)
            IC_IDLE: begin
                req_ready = 1'b1;
            end

            IC_GET_W0: begin
                mem_req_valid = 1'b1;
                mem_req_we    = 1'b0;
                mem_req_addr  = base_addr_reg + 32'd0;
            end

            IC_GET_W1: begin
                mem_req_valid = 1'b1;
                mem_req_we    = 1'b0;
                mem_req_addr  = base_addr_reg + 32'd4;
            end

            IC_GET_W2: begin
                mem_req_valid = 1'b1;
                mem_req_we    = 1'b0;
                mem_req_addr  = base_addr_reg + 32'd8;
            end

            IC_GET_W3: begin
                mem_req_valid = 1'b1;
                mem_req_we    = 1'b0;
                mem_req_addr  = base_addr_reg + 32'd12;
            end

            IC_GET_W4: begin
                mem_req_valid = 1'b1;
                mem_req_we    = 1'b0;
                mem_req_addr  = base_addr_reg + 32'd16;
            end

            IC_RESP: begin
                resp_valid = 1'b1;
                resp_data  = {
                    word4_reg,
                    word3_reg,
                    word2_reg,
                    word1_reg,
                    word0_reg
                };
            end

            default: begin
            end
        endcase
    end

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state         <= IC_IDLE;
            base_addr_reg <= 32'h0;
            word0_reg     <= 32'h0;
            word1_reg     <= 32'h0;
            word2_reg     <= 32'h0;
            word3_reg     <= 32'h0;
            word4_reg     <= 32'h0;
        end
        else begin
            case (state)
                IC_IDLE: begin
                    if (req_valid && req_ready) begin
                        base_addr_reg <= req_base_addr;
                        state         <= IC_GET_W0;
                    end
                end

                IC_GET_W0: begin
                    if (mem_resp_hit) begin
                        word0_reg <= mem_resp_rdata;
                        state     <= IC_GET_W1;
                    end
                end

                IC_GET_W1: begin
                    if (mem_resp_hit) begin
                        word1_reg <= mem_resp_rdata;
                        state     <= IC_GET_W2;
                    end
                end

                IC_GET_W2: begin
                    if (mem_resp_hit) begin
                        word2_reg <= mem_resp_rdata;
                        state     <= IC_GET_W3;
                    end
                end

                IC_GET_W3: begin
                    if (mem_resp_hit) begin
                        word3_reg <= mem_resp_rdata;
                        state     <= IC_GET_W4;
                    end
                end

                IC_GET_W4: begin
                    if (mem_resp_hit) begin
                        word4_reg <= mem_resp_rdata;
                        state     <= IC_RESP;
                    end
                end

                IC_RESP: begin
                    state <= IC_IDLE;
                end

                default: begin
                    state <= IC_IDLE;
                end
            endcase
            if(!req_valid) begin
                state <= IC_IDLE;
            end
        end
    end

endmodule