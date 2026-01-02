`timescale 1ps/1ps

module axi_read_arbiter(
    input logic        CLK,
    input logic        nRST,
    input logic        ready,
    input logic        sp0_req,
    input logic        sp1_req,
    input logic        d_req,
    input logic        i_req,
    output logic [2:0] grant_sel
);

    typedef enum logic [2:0] {
        IDLE,
        SP0_GRANTED,
        SP1_GRANTED,
        D_GRANTED,
        I_GRANTED
    } arbitration;

    arbitration state, next_state;

    always_ff @(posedge CLK, negedge nRST) begin
        if(!nRST) begin
            state <= IDLE;
        end
        else begin 
            state <= next_state;
        end
    end

    always_comb begin : NEXT_STATE_LOGIC
        next_state = state;
        case(state)
            IDLE: begin
                if      (sp0_req && ready) next_state = SP0_GRANTED;
                else if (sp1_req && ready) next_state = SP1_GRANTED;
                else if (d_req && ready)   next_state = D_GRANTED;
                else if (i_req && ready)   next_state = I_GRANTED;
                else                       next_state = IDLE;
            end
            SP0_GRANTED: begin
                if      (sp1_req && ready) next_state = SP1_GRANTED;
                else if (d_req && ready)   next_state = D_GRANTED;
                else if (i_req && ready)   next_state = I_GRANTED;
                else if (sp0_req && ready) next_state = SP0_GRANTED;
                else                       next_state = IDLE;
            end
            SP1_GRANTED: begin
                if      (d_req && ready)   next_state = D_GRANTED;
                else if (i_req && ready)   next_state = I_GRANTED;
                else if (sp0_req && ready) next_state = SP0_GRANTED;
                else if (sp1_req && ready) next_state = SP1_GRANTED;
                else                       next_state = IDLE;
            end
            D_GRANTED: begin
                if      (i_req && ready)   next_state = I_GRANTED;
                else if (sp0_req && ready) next_state = SP0_GRANTED;
                else if (sp1_req && ready) next_state = SP1_GRANTED;
                else if (d_req && ready)   next_state = D_GRANTED;
                else                       next_state = IDLE;
            end
            I_GRANTED: begin
                if      (sp0_req && ready) next_state = SP0_GRANTED;
                else if (sp1_req && ready) next_state = SP1_GRANTED;
                else if (d_req && ready)   next_state = D_GRANTED;
                else if (i_req && ready)   next_state = I_GRANTED;
                else                       next_state = IDLE;
            end 
        endcase
    end

    always_comb begin : OUTPUT_LOGIC
        grant_sel = '0;
        case(state)
            SP0_GRANTED: grant_sel = 3'b100;
            SP1_GRANTED: grant_sel = 3'b101;
            D_GRANTED:   grant_sel = 3'b110;
            I_GRANTED:   grant_sel = 3'b111; 
        endcase 
    end 

endmodule