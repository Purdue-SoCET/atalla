`include "ld_st_unit_if.sv"

module ld_st_unit #()
(
    input logic CLK,
    ld_st_unit_if.ld_st ld_st_if
);

    assign ld_st_if.data_addr = ld_st_if.addr;
    assign ld_st_if.data_store = ld_st_if.data_in;
    assign ld_st_if.WEN = ld_st_if.st;
    assign ld_st_if.REN = ld_st_if.ld;
    assign ld_st_if.rdOut = ld_st_if.rdIn;
    assign ld_st_if.halfWord_dcache = ld_st_if.halfWord;


    assign ld_st_if.data_out = ld_st_if.halfWord ? {16'b0, ld_st_if.data_load[15:0]} : ld_st_if.data_load;

    assign ld_st_if.valid_out = ld_st_if.ld ? ld_st_if.hit : 1'b0;

    always_comb begin
        if(ld_st_if.valid_in) begin
            if(ld_st_if.ld) begin
                ld_st_if.ready_in = ld_st_if.ready_out && ld_st_if.hit;
            end else begin
                ld_st_if.ready_in = ld_st_if.hit;
            end
        end else begin
            ld_st_if.ready_in = 1'b1;
        end
        
    end


endmodule