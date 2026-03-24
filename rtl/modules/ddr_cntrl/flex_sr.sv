`timescale 1ns / 10ps

module flex_sr #(
                SIZE = 8,
                MSB_FIRST = 0,
                RING = 0
                ) (
                input logic CLK,
                input logic nRST,
                input logic shift_enable,
                input logic load_enable,
                input logic serial_in,
                input logic [SIZE - 1:0] parallel_in,
                //output logic serial_out,
                output logic [SIZE - 1:0] parallel_out
                );

    logic [SIZE - 1: 0] sr; //intermediate shift register. 
    logic serial_out;
    logic serial_in_feed;
    assign serial_in_feed = RING ? serial_out : serial_in;

    always_ff @(posedge CLK, negedge nRST) begin
        if(!nRST)
            sr <= RING ? 'b1 : 'b0;
        else  
            sr <= load_enable  ? parallel_in : (shift_enable ? (MSB_FIRST ? {sr[SIZE - 2:0], serial_in_feed} : {serial_in_feed, sr[SIZE - 1:1]}) : sr);
    end

    

    assign serial_out = MSB_FIRST ? sr[SIZE - 1] : sr[0];
    assign parallel_out = sr;
            


endmodule
