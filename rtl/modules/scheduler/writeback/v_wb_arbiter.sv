// Vector Writeback Arbiter Module ============================================
// Author: Jaideep Dadi
// Email: djaideep@purdue.edu
// TODO 
// Check vector core stall-related inputs & modify code accordingly. Banks can be associative, no?
// ============================================================================
`include "v_wb_arbiter_if.vh"
`include "vector_pkg.vh"

module v_wb_arbiter #(
    parameter INPUTS      = vector_pkg::LANE_FU_COUNT //the number of input sources (FU lanes (5) + reduction + GSAU). Is it 9?
)(
    input logic CLK, nRST,
    v_wb_arbiter_if.v_wb_arbiter_if vif,
    output logic [INPUTS-1:0] stallSignal // Indicate which input is causing the stall
); 
    import vector_pkg::*;

    logic [INPUTS-1:0] vectorOut_valid;
    vsel_t [INPUTS-1:0] vectorOut_destReg;
    vreg_t [INPUTS-1:0] vectorOut_result;

    assign vectorOut_valid = {vif.vector_out.valid_o}; //, vif.vector_out.reduction_valid, vif.vector_out.gsau.wb_valid};
    assign vectorOut_destReg = {vif.vector_out.vd}; //, vif.vector_out.reduction_vd, vif.vector_out.gsau.wb_wbdst};
    assign vectorOut_result = {vif.vector_out.result}; //, vif.vector_out.reduction_result, vif.vector_out.gsau.wb_psum};

    logic [2:0] banks [0:3]; // {valid, index[1:0]} for each port
    logic [$clog2(INPUTS)-1:0] inputIndex; // For the for loop

    //assign vif.veggie_in.WEN[0]   = |g[0];
    //assign vif.veggie_in.vd[0]    = g[0][0] ? vds[0] : g[0][1] ? vds[1] : g[0][2] ? vds[2] : g[0][3] ? vds[3] : g[0][4] ? vds[4] : g[0][5] ? vds[5] : vds[6];
    //assign vif.veggie_in.vdata[0] = g[0][0] ? datas[0] : g[0][1] ? datas[1] : g[0][2] ? datas[2] : g[0][3] ? datas[3] : g[0][4] ? datas[4] : g[0][5] ? datas[5] : datas[6];

    always_comb begin
        stallSignal = '0;
        vif.veggie_in.WEN   = '0;
        vif.veggie_in.vd    = '0;
        vif.veggie_in.vdata = '0;

        if (!vif.veggie_out.ready) begin
            stallSignal = '1; // If Veggie is not ready, stall the entire pipeline?
        end else begin
            stallSignal = '0;
            //clear bank when veggie ready to accept new data
            banks[0] = 3'b0;
            banks[1] = 3'b0;
            banks[2] = 3'b0;
            banks[3] = 3'b0;

            //This is synthesizable, right? Coz we can unroll it to 8 inputs. Also, how many inputs again?
            for (inputIndex = 0; inputIndex < INPUTS; inputIndex++) begin
                if (vectorOut_valid[inputIndex]) begin
                    case (vectorOut_destReg[inputIndex][7:6]) // Bank ID
                    2'b00: 
                        if (!banks[0][2]) begin // Bank is not used by a higher-priority port
                            banks[0] = {1'b1, vectorOut_destReg[inputIndex][7:6]}; // Mark bank as used and store index
                            //The above line can be used later. Currently, banks are address exclusive. In future, I want to make this associative.
                            vif.veggie_in.vd[0]   = vectorOut_destReg[inputIndex];
                            vif.veggie_in.vdata[0] = vectorOut_result[inputIndex];
                            vif.veggie_in.WEN[0] = 1;
                        end else begin
                            stallSignal[inputIndex] = 1; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
                        end
                    2'b01: 
                        if (!banks[1][2]) begin // Bank is not used by a higher-priority port
                            banks[1] = {1'b1, vectorOut_destReg[inputIndex][7:6]}; // Mark bank as used and store index
                            vif.veggie_in.vd[1]   = vectorOut_destReg[inputIndex];
                            vif.veggie_in.vdata[1] = vectorOut_result[inputIndex];
                            vif.veggie_in.WEN[1] = 1;
                        end else begin
                            stallSignal[inputIndex] = 1; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
                        end
                    2'b10:
                        if (!banks[2][2]) begin // Bank is not used by a higher-priority port
                            banks[2] = {1'b1, vectorOut_destReg[inputIndex][7:6]}; // Mark bank as used and store index
                            vif.veggie_in.vd[2]   = vectorOut_destReg[inputIndex];
                            vif.veggie_in.vdata[2] = vectorOut_result[inputIndex];
                            vif.veggie_in.WEN[2] = 1;
                        end else begin
                            stallSignal[inputIndex] = 1; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
                        end
                    2'b11:
                        if (!banks[3][2]) begin // Bank is not used by a higher-priority port
                            banks[3] = {1'b1, vectorOut_destReg[inputIndex][7:6]}; // Mark bank as used and store index
                            vif.veggie_in.vd[3]   = vectorOut_destReg[inputIndex];
                            vif.veggie_in.vdata[3] = vectorOut_result[inputIndex];
                            vif.veggie_in.WEN[3] = 1;
                        end else begin
                            stallSignal[inputIndex] = 1; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
                        end
                    endcase
                end
            end
        end
    end
endmodule