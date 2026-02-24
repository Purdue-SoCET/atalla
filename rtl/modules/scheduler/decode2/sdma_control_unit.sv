// //Navya Datla 2/12/2026

// `include "sdma_control_unit_if.vh"

// module sdma_control_unit
//     import atalla_isa_pkg::*;
// #(
//     parameter NUM_INSTRUCTIONS = 2
// ) (
//     input logic clk, 
//     sdma_control_unit.cu cuif
// );


//     always_comb begin : decode_packet
//         int i;

//         for (i = 0; i < NUM_INSTRUCTIONS; i++) begin
//             cuif.decoded_sdma_instrs[i] = '0;
            
//             casez (opcode_t'(cuif.sdma_instrs[i][OP_W-1:0]))
//                 SCPAD_LD:  begin
//                     cuif.decoded_scalar_instrs[i].valid = 1'b1;
//                     cuif.decoded_scalar_instrs[i].sid = cuif.sdma_instrs[i][33];
//                     cuif.decoded_scalar_instrs[i].store = 1'b0;
//                     cuif.decoded_scalar_instrs[i].num_rows = cuif.sdma_instrs[i][32:28];
//                     cuif.decoded_scalar_instrs[i].num_cols = cuif.sdma_instrs[i][27:23];
//                     cuif.decoded_scalar_instrs[i].rs1_rd = cuif.sdma_instrs[i][14:7];
//                     cuif.decoded_scalar_instrs[i].rs2 = cuif.sdma_instrs[i][22:15];

//                 end

//                 SCPAD_ST:  begin
//                     cuif.decoded_scalar_instrs[i].valid = 1'b1;
//                     cuif.decoded_scalar_instrs[i].sid = cuif.sdma_instrs[i][33];
//                     cuif.decoded_scalar_instrs[i].store = 1'b1;
//                     cuif.decoded_scalar_instrs[i].num_rows = cuif.sdma_instrs[i][32:28];
//                     cuif.decoded_scalar_instrs[i].num_cols = cuif.sdma_instrs[i][27:23];
//                     cuif.decoded_scalar_instrs[i].rs1_rd = cuif.sdma_instrs[i][14:7];
//                     cuif.decoded_scalar_instrs[i].rs2 = cuif.sdma_instrs[i][22:15];
//                 end


//                 default: 
//                     begin
//                     cuif.decoded_scalar_instrs[i].valid = 1'b0;
//                     cuif.decoded_scalar_instrs[i].sid = 1'b0;
//                     cuif.decoded_scalar_instrs[i].store = 1'b0;
//                     cuif.decoded_scalar_instrs[i].num_rows = '0;
//                     cuif.decoded_scalar_instrs[i].num_cols = '0;
//                     cuif.decoded_scalar_instrs[i].rs1_rd = '0;
//                     cuif.decoded_scalar_instrs[i].rs2 = '0;

//                 end


                
                
//             endcase
            
//         end
        
//     end
    
// endmodule