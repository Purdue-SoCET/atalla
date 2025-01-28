// `include "isa_types.vh"
// `include "datapath_types.vh"
// `include "fu_gemm_if.vh"

module fu_gemm(
    input logic CLK, 
    input logic nRST, 
    fu_gemm_if.GEMM fugif
);

logic [3:0] next_reg1, next_reg2, next_reg3, next_regd;
logic ready, next_ready;

//pipeline later with weights
always_ff @(posedge CLK, negedge nRST) begin
    if(nRST == 0) begin
        fugif.rs1 <= '0;
        fugif.rs2 <= '0;
        fugif.rs3 <= '0;
        fugif.rd <= '0;
        ready <= '0;
    end
    else begin
        fugif.rs1 <= next_reg1;
        fugif.rs2 <= next_reg2;
        fugif.rs3 <= next_reg3;
        fugif.rd <= next_regd;
        ready <= next_ready;
    end
end

always_comb begin
    next_reg1 = fugif.rs1;
    next_reg2 = fugif.rs2;
    next_reg3 = fugif.rs3;
    next_regd = fugif.rd;
    next_ready = ready;

    if(fugif.flush) begin
        next_reg1 = '0;
        next_reg2 = '0;
        next_reg3 = '0;
        next_regd = '0;
        next_ready = '0;
    end
    else if (fugif.freeze) begin
        next_ready = 0; //want to not assert a ready value in case there is a freeze
    end //no need for setting the next_regs because, default case takes care of this
    else begin
        next_reg1 = fugif.fetch_p[10:7]; 
        next_reg2 = fugif.fetch_p[14:11];
        next_reg3 = fugif.fetch_p[18:15];
        next_regd = fugif.fetch_p[22:19];
        next_ready = 1;
    end

end

endmodule