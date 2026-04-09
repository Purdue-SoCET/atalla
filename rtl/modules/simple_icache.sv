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
        IDLE,
        SEND_REQ,
        WAIT_RAM,
        CAPTURE,
        RESP
    } state_t;

    state_t state;

    logic [31:0] base_addr_reg;
    logic [2:0]  word_idx;

    logic [31:0] word0, word1, word2, word3, word4;

    assign busy = (state != IDLE);

    always_comb begin
        req_ready     = 1'b0;
        resp_valid    = 1'b0;

        mem_req_valid = 1'b0;
        mem_req_we    = 1'b0;
        mem_req_addr  = 32'h0;
        mem_req_wdata = 32'h0;

        case (state)
            IDLE: begin
                req_ready = 1'b1;
            end

            SEND_REQ: begin
                mem_req_valid = 1'b1;
                mem_req_we    = 1'b0;
                mem_req_addr  = base_addr_reg + (word_idx << 2);
            end

            RESP: begin
                resp_valid = 1'b1;
            end

            default: begin
            end
        endcase
    end

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state         <= IDLE;
            base_addr_reg <= 32'h0;
            word_idx      <= 3'd0;
            word0         <= 32'h0;
            word1         <= 32'h0;
            word2         <= 32'h0;
            word3         <= 32'h0;
            word4         <= 32'h0;
            resp_data     <= 160'h0;
        end
        else begin
            case (state)
                IDLE: begin
                    if (req_valid) begin
                        base_addr_reg <= req_base_addr;
                        word_idx      <= 3'd0;
                        state         <= SEND_REQ;
                    end
                end

                SEND_REQ: begin
                    // Request is visible to RAM during this cycle.
                    // RAM captures it on this edge.
                    state <= CAPTURE;
                end

                WAIT_RAM: begin
                    // RAM updates mem_resp_* on this edge.
                    // Icache still cannot safely use the new value on this same edge.
                    state <= CAPTURE;
                end

                CAPTURE: begin
                    if (mem_resp_hit) begin
                        case (word_idx)
                            3'd0: word0 <= mem_resp_rdata;
                            3'd1: word1 <= mem_resp_rdata;
                            3'd2: word2 <= mem_resp_rdata;
                            3'd3: word3 <= mem_resp_rdata;
                            3'd4: word4 <= mem_resp_rdata;
                            default: ;
                        endcase

                        if (word_idx == 3'd4) begin
                            // resp_data <= {
                            //     word0,
                            //     word1,
                            //     word2,
                            //     word3,
                            //     mem_resp_rdata
                            // };
                            resp_data <= {
                                mem_resp_rdata,
                                word3,
                                word2,
                                word1,
                                word0
                            };
                            state <= RESP;
                        end
                        else begin
                            word_idx <= word_idx + 3'd1;
                            state    <= SEND_REQ;
                        end
                    end
                    else begin
                        // stay here if RAM did not return a valid response
                        state <= CAPTURE;
                    end
                end

                RESP: begin
                    state <= IDLE;
                end

                default: begin
                    state <= IDLE;
                end
            endcase
        end
    end

endmodule