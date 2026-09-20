
module flex_counter #(SIZE = 4) (
    input logic CLK,
    input logic nRST,
    input logic clear,
    input logic count_enable,
    input logic [SIZE - 1:0] rollover_val,
    //output logic [SIZE - 1: 0] count_out,
    output logic rollover_flag
);

    logic [SIZE - 1: 0] count_out;
    logic [SIZE - 1:0] next_count;
    logic next_rollover_flag;
    always_ff @(posedge CLK, negedge nRST) begin
        if(!nRST) begin
            count_out <= 0;
            rollover_flag <= 0;
        end else begin 
            count_out <= next_count;
            rollover_flag <= next_rollover_flag;
        end
    end

    always_comb begin
        if(clear) begin
            next_count = 0;
        end else if(count_enable) begin
            next_count = (count_out >= rollover_val) ? 'b0 : count_out + 1;
        end else begin
            next_count = count_out;
        end
    end

    assign next_rollover_flag = (clear) ? 'b0 : (count_out >= rollover_val) ? 'b1 : rollover_flag;
                    
endmodule