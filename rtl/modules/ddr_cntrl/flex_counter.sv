
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
                                always_ff @(posedge clk, negedge n_rst) begin
                                    if(!n_rst) begin
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
                                        next_rollover_flag = (0 >= rollover_val);
                                    end else if(count_enable) begin
                                        next_count = (count_out >= rollover_val) ? 1 : count_out + 1;
                                        next_rollover_flag = (count_out >= rollover_val) ? (1 >= rollover_val) : (count_out + 1) >= rollover_val;
                                    end else begin
                                        next_count = count_out;
                                        next_rollover_flag = rollover_flag;
                                    end
                                    
                                end
                        


endmodule