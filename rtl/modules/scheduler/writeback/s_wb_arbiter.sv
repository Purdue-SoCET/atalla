// Scalar Writeback Arbiter Module ============================================
// Author: Michael Lee
// Email: lee4279@purdue.edu
// Arbitrates scalar writeback to remove bank conflicts and prioritize writebacks
// SCALAR Functional Units
// Control/Branch, Scalar LS, Scalar ALU, Div/Mod, Mult, BF16 ALU, BF16 Mod/Div,
// BF16 Mult, Type Conversion
// ============================================================================
`include "s_wb_arbiter_if.vh"
`include "scalar_wb_pkg.vh"

module s_wb_arbiter #(
    parameter NUM_FUS   = 6,
    parameter NUM_BANKS = 4
) (
    input logic CLK, nRST,
    s_wb_arbiter_if.s_wb_arbiter vif
); 
    logic [NUM_FUS-1:0][NUM_BANKS-1:0] banks;
    logic [NUM_FUS-1:0][NUM_BANKS-1:0] temp_banks;

    always_comb begin
        banks = '0;
        vif.scalar_wb_out.data  = '0;
        vif.scalar_wb_out.rd    = '0;
        vif.scalar_wb_out.WEN   = '0;
        vif.scalar_wb_out.ready = '1;

        if (vif.scalar_wb_in.valid[0]) begin
            vif.scalar_wb_out.data[vif.scalar_wb_in.rd[0][1:0]]  = vif.scalar_wb_in.data[0];
            vif.scalar_wb_out.rd[vif.scalar_wb_in.rd[0][1:0]]    = vif.scalar_wb_in.rd[0];
            vif.scalar_wb_out.WEN[vif.scalar_wb_in.rd[0][1:0]]   = 1'b1;
            banks[0][vif.scalar_wb_in.rd[0][1:0]] = 1'b1;
        end
        // else if (vif.scalar_wb_in.valid[0]) begin
        //     vif.scalar_wb_out.ready[0] = 1'b0;
        // end

        if (vif.scalar_wb_in.valid[1] && (!banks[0][vif.scalar_wb_in.rd[1][1:0]]) && vif.scalar_wb_in.maskornotscalar) begin
            vif.scalar_wb_out.data[vif.scalar_wb_in.rd[1][1:0]]  = vif.scalar_wb_in.data[1];
            vif.scalar_wb_out.rd[vif.scalar_wb_in.rd[1][1:0]]    = vif.scalar_wb_in.rd[1];
            vif.scalar_wb_out.WEN[vif.scalar_wb_in.rd[1][1:0]]   = 1'b1;
            temp_banks[1][vif.scalar_wb_in.rd[1][1:0]] = 1'b1;  
        end
        else if (vif.scalar_wb_in.valid[1] && banks[0][vif.scalar_wb_in.rd[1][1:0]]) begin
            vif.scalar_wb_out.ready[1] = 1'b0;
        end
        banks[1] = temp_banks[1] | banks[0];


        if (vif.scalar_wb_in.valid[2] && (!banks[1][vif.scalar_wb_in.rd[2][1:0]])) begin
            vif.scalar_wb_out.data[vif.scalar_wb_in.rd[2][1:0]]  = vif.scalar_wb_in.data[2];
            vif.scalar_wb_out.rd[vif.scalar_wb_in.rd[2][1:0]]    = vif.scalar_wb_in.rd[2];
            vif.scalar_wb_out.WEN[vif.scalar_wb_in.rd[2][1:0]]   = 1'b1;
            temp_banks[2][vif.scalar_wb_in.rd[2][1:0]] = 1'b1;
            
        end
        else if (vif.scalar_wb_in.valid[2] && banks[1][vif.scalar_wb_in.rd[2][1:0]]) begin
            vif.scalar_wb_out.ready[2] = 1'b0;
        end
        banks[2] = temp_banks[2] | banks[1];


        if (vif.scalar_wb_in.valid[3] && (!banks[2][vif.scalar_wb_in.rd[3][1:0]])) begin
            vif.scalar_wb_out.data[vif.scalar_wb_in.rd[3][1:0]]  = vif.scalar_wb_in.data[3];
            vif.scalar_wb_out.rd[vif.scalar_wb_in.rd[3][1:0]]    = vif.scalar_wb_in.rd[3];
            vif.scalar_wb_out.WEN[vif.scalar_wb_in.rd[3][1:0]]   = 1'b1;
            temp_banks[3][vif.scalar_wb_in.rd[3][1:0]] = 1'b1;
        end
        else if (vif.scalar_wb_in.valid[3] && banks[2][vif.scalar_wb_in.rd[3][1:0]]) begin
            vif.scalar_wb_out.ready[3] = 1'b0;
        end
        banks[3] = temp_banks[3] | banks[2];

        if (vif.scalar_wb_in.valid[4] && (!banks[3][vif.scalar_wb_in.rd[4][1:0]])) begin
            vif.scalar_wb_out.data[vif.scalar_wb_in.rd[4][1:0]]  = vif.scalar_wb_in.data[4];
            vif.scalar_wb_out.rd[vif.scalar_wb_in.rd[4][1:0]]    = vif.scalar_wb_in.rd[4];
            vif.scalar_wb_out.WEN[vif.scalar_wb_in.rd[4][1:0]]   = 1'b1;
            temp_banks[4][vif.scalar_wb_in.rd[4][1:0]] = 1'b1;
        end
        else if (vif.scalar_wb_in.valid[4] && banks[3][vif.scalar_wb_in.rd[4][1:0]]) begin
            vif.scalar_wb_out.ready[4] = 1'b0;
        end
        banks[4] = temp_banks[4] | banks[3];

        if (vif.scalar_wb_in.valid[5] && (!banks[4][vif.scalar_wb_in.rd[5][1:0]])) begin
            vif.scalar_wb_out.data[vif.scalar_wb_in.rd[5][1:0]]  = vif.scalar_wb_in.data[5];
            vif.scalar_wb_out.rd[vif.scalar_wb_in.rd[5][1:0]]    = vif.scalar_wb_in.rd[5];
            vif.scalar_wb_out.WEN[vif.scalar_wb_in.rd[5][1:0]]   = 1'b1;
            temp_banks[5][vif.scalar_wb_in.rd[5][1:0]] = 1'b1;
        end
        else if (vif.scalar_wb_in.valid[5] && banks[4][vif.scalar_wb_in.rd[5][1:0]]) begin
            vif.scalar_wb_out.ready[5] = 1'b0;
        end
        banks[5] = temp_banks[5] | banks[4];

        // if (vif.scalar_wb_in.valid[6] && (!banks[5][vif.scalar_wb_in.rd[6][1:0]])) begin
        //     vif.scalar_wb_out.data[vif.scalar_wb_in.rd[6][1:0]]  = vif.scalar_wb_in.data[6];
        //     vif.scalar_wb_out.rd[vif.scalar_wb_in.rd[6][1:0]]    = vif.scalar_wb_in.rd[6];
        //     vif.scalar_wb_out.WEN[vif.scalar_wb_in.rd[6][1:0]]   = 1'b1;
        //     banks[6][vif.scalar_wb_in.rd[6][1:0]] = 1'b1;
        // end
        // else if (!vif.scalar_wb_in.valid[6] && banks[5][vif.scalar_wb_in.rd[6][1:0]]) begin
        //     vif.scalar_wb_out.ready[6] = 1'b0;
        // end
        // banks[6] = banks[6] | banks[5];

        // if (vif.scalar_wb_in.valid[7] && (!banks[6][vif.scalar_wb_in.rd[7][1:0]])) begin
        //     vif.scalar_wb_out.data[vif.scalar_wb_in.rd[7][1:0]]  = vif.scalar_wb_in.data[7];
        //     vif.scalar_wb_out.rd[vif.scalar_wb_in.rd[7][1:0]]    = vif.scalar_wb_in.rd[7];
        //     vif.scalar_wb_out.WEN[vif.scalar_wb_in.rd[7][1:0]]   = 1'b1;
        //     banks[7][vif.scalar_wb_in.rd[7][1:0]] = 1'b1;
        // end
        // else if (!vif.scalar_wb_in.valid[7] && banks[6][vif.scalar_wb_in.rd[7][1:0]]) begin
        //     vif.scalar_wb_out.ready[7] = 1'b0;
        // end
        // banks[7] = banks[7] | banks[6];

        // if (vif.scalar_wb_in.valid[8] && (!banks[7][vif.scalar_wb_in.rd[8][1:0]])) begin
        //     vif.scalar_wb_out.data[vif.scalar_wb_in.rd[8][1:0]]  = vif.scalar_wb_in.data[8];
        //     vif.scalar_wb_out.rd[vif.scalar_wb_in.rd[8][1:0]]    = vif.scalar_wb_in.rd[8];
        //     vif.scalar_wb_out.WEN[vif.scalar_wb_in.rd[8][1:0]]   = 1'b1;
        //     banks[8][vif.scalar_wb_in.rd[8][1:0]] = 1'b1;
        // end
        // else if (!vif.scalar_wb_in.valid[8] && banks[7][vif.scalar_wb_in.rd[8][1:0]]) begin
        //     vif.scalar_wb_out.ready[8] = 1'b0;
        // end
        // banks[8] = banks[8] | banks[7];
        
    end

    // always_comb begin
    //     banks = '0;
    //     vif.scalar_wb_out.data  = '0;
    //     vif.scalar_wb_out.rd    = '0;
    //     vif.scalar_wb_out.WEN   = '0;
    //     vif.scalar_wb_out.ready = '1;

    //     // functional units (priority 0 is highest)
    //     for (int f = 0; f < NUM_FUS; f++) begin
    //         // Banks
    //         if ((banks[vif.scalar_wb_in.rd[f][1:0]]) || (banks = 4'b1111)) begin
    //                 vif.scalar_wb_out.ready[f] = 1'b0;
    //         end
    //         for (int b = 0; b < NUM_BANKS; b++) begin
                
    //             // If FU is valid AND targets this specific bank
    //             if (vif.scalar_wb_in.valid[f] && (vif.scalar_wb_in.rd[f][1:0] == b[1:0])) begin
    //                 if (!banks[b]) begin
    //                     vif.scalar_wb_out.data[b]  = vif.scalar_wb_in.data[f];
    //                     vif.scalar_wb_out.rd[b]    = vif.scalar_wb_in.rd[f];
    //                     vif.scalar_wb_out.WEN[b]   = 1'b1;

    //                     // vif.scalar_wb_out.ready[f] = 1'b1;
    //                     banks[b] = 1'b1;
    //                 end
    //             end
    //         end
    //     end 
    // end

endmodule

