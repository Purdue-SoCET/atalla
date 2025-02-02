`include "isa_types.vh"
`include "datapath_types.vh"
`include "fu_gemm_if.vh"

module fu_gemm (
    input logic CLK,nRST, 
                fu_gemm_if.GEMM fugif
);

logic [3:0] next_reg1, next_reg2, next_reg3, next_regd;
logic ready, next_ready;
logic prev_rs1; // previous weights register
logic next_new_weights;
logic weights_flag, next_weights_flag;

always_ff @(posedge CLK, negedge nRST) begin
    if(nRST == 0) begin
        fugif.rs1 <= '0;
        fugif.rs2 <= '0;
        fugif.rs3 <= '0;
        fugif.rd <= '0;
        ready <= '0;

        prev_rs1 <= 0;
        new_weights <= 0;
    end
    else begin
        fugif.rs1 <= next_reg1;
        fugif.rs2 <= next_reg2;
        fugif.rs3 <= next_reg3;
        fugif.rd <= next_regd;
        ready <= next_ready;

        prev_rs1 <= next_reg1; 
        new_weights <= next_new_weights;
    end
end

always_comb begin
    next_reg1 = fugif.rs1;
    next_reg2 = fugif.rs2;
    next_reg3 = fugif.rs3;
    next_regd = fugif.rd;
    ready = next_ready;

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
    else if (fugif.GEMM_enable) begin // GEMM instr ready
        next_reg1 = fugif.fetchp[10:7]; 
        next_reg2 = fugif.fetchp[14:11];
        next_reg3 = fugif.fetchp[18:15];
        next_regd = fugif.fetchp[22:19];
        next_ready = 1;
    end
end

//set the new weights signal
always_comb begin
    next_new_weights = new_weights;

    if(fugif.fetchp[22:19] == prev_rs1) begin //if rs1 is same
        next_new_weights = '0;
    end
    else if(fugif.fetchp[22:19] != prev_rs1) begin //if rs1 is differnt than prev, new weights
        next_new_weights = '1;
    end

    if(ls_enable && ls_in[1]) begin //STORE matrix instruction
        if(fugif.fetchp[22:19] = prev_rs1) begin //writing to previous weights
            next_weights_flag = '1;
        end
    end
end

endmodule