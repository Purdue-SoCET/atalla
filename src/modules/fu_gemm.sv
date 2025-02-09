// `include "isa_types.vh"
// `include "datapath_types.vh"
// `include "fu_gemm_if.vh"

module fu_gemm(
    input logic CLK, 
    input logic nRST, 
    fu_gemm_if.GEMM fugif
);

logic ls_flag, nxt_ls_flag;
logic prev_rs1;

always_comb begin //if there is enable, and hit (mem is ready)
    fugif.gemm_matrix_num.rd = '0;
    fugif.gemm_matrix_num.rs1 = '0;
    fugif.gemm_matrix_num.rs2 = '0;
    fugif.gemm_matrix_num.rs3 = '0;
    fugif.new_weight = '0;
    
    if(fugif.gemm_enable) begin
        fugif.gemm_matrix_num.rd = fugif.rd_in;
        fugif.gemm_matrix_num.rs1 = fugif.rs1_in;
        fugif.gemm_matrix_num.rs2 = fugif.rs2_in;
        fugif.gemm_matrix_num.rs3 = fugif.rs3_in;
        //if rs1 != prev OR LS to prev_rs1
        fugif.new_weight = (fugif.rs1_in != prev_rs1) | ls_flag;
    end

    nxt_ls_flag = ls_flag | (fugif.ls_enable && (fugif.rs1_in == prev_rs1));
end

always_ff @(negedge fugif.gemm_enable, negedge nRST) begin
    if(!nRST) begin
        prev_rs1 <= '0;
    end
    else begin //on the negative edge of enable we store the rs1 value for comparison for next enable
        prev_rs1 <= fugif.rs1_in;
    end
end

always_ff @(posedge CLK, negedge fugif.gemm_enable, negedge nRST) begin
    if(!nRST || !fugif.gemm_enable) begin
        ls_flag <= '0;
    end
    else begin 
        ls_flag <= nxt_ls_flag;
    end
end
endmodule