// `include "isa_types.vh"
// `include "datapath_types.vh"
// `include "fu_gemm_if.vh"

module fu_gemm(
    input logic CLK, 
    input logic nRST, 
    fu_gemm_if.GEMM fugif
);

always_comb begin: //if there is enable, and hit (mem is ready)
    if(fugif.gemm_enable) begin
        fugif.gemm_matrix_num.rd = fugif.rd_in
        fugif.gemm_matrix_num.rs1 = fugif.rs1_in
        fugif.gemm_matrix_num.rs2 = fugif.rs2_in
        fugif.gemm_matrix_num.rs3 = fugif.rs3_in
        //if rs1 != prev OR LS to prev_rs1
        fugif.new_weights = (fugif.rs1_in != prev_rs1) | (fugif.ls_enable && (fugif.rs1_in == prev_rs1));
    end
end

//Previous rs1 logic
logic rs1, prev_rs1; // previous weights register

always_ff @(negedge fugif.gemm_enable, negedge nRST) begin
    if(!nRST) begin
        prev_rs1 <= '0;
    end
    else begin //on the negative edge of enable we store the rs1 value for comparison for next enable
        prev_rs1 <= fugif.rs1;
    end
end



endmodule