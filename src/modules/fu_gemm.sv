`include "types_pkg.vh"
`include "fu_gemm_if.vh"

module fu_gemm (input logic CLK, nRST, fu_gemm_if.GEMM fugif);

logic [3:0] reg1, reg2, reg3, regd;
logic [3:0] next_reg1, next_reg2, next_reg3, next_regd;
logic ready, next_ready;

always_ff @(posedge CLK, negedge nRST) begin
    if(nRST == 0) begin
        reg1 <= '0;
        reg2 <= '0;
        reg3 <= '0;
        regd <= '0;
        ready <= '0;
    end
    else begin
        reg1 <= next_reg1;
        reg2 <= next_reg2;
        reg3 <= next_reg3;
        regd <= next_regd;
        ready <= next_ready;
    end
end

always_comb begin
    next_reg1 = reg1;
    next_reg2 = reg2;
    next_reg3 = reg3;
    next_regd = regd;

    if(fugif.flush) begin
        next_reg1 = '0;
        next_reg2 = '0;
        next_reg3 = '0;
        next_regd = '0;
    end
    else if (fugif.freeze) begin
        next_ready = 0; //want to not assert a ready value in case there is a freeze
    end //no need for setting the next_regs because, default case takes care of this
    else begin
        next_reg1 = fugif.fetchp[10:7]; 
        next_reg2 = fugif.fetchp[14:11];
        next_reg3 = fugif.fetchp[18:15];
        next_regd = fugif.fetchp[22:19];
        next_ready = 1;
    end

end
        


endmodule