`include "atalla_isa_types.vh"
import atalla_isa_pkg::*;
`include "if_dec1_if.vh"
`include "dec1_dec2_if.vh"

module decode1_stage (
  if_dec1_if.dst       ifdec1_if,
  dec1_dec2_if.src     dec12_if
);

  typedef enum logic [1:0] {
    TYPE_NONE   = 2'b00,
    TYPE_SCALAR = 2'b01,
    TYPE_VECTOR = 2'b10,
    TYPE_SCPAD  = 2'b11
  } inst_cat_t;

  inst_cat_t         cat  [0:PACKET_SIZE-1];
  logic [INST_W-1:0] inst [0:PACKET_SIZE-1];
  
  localparam int SCPAD_WPTR_W = (SCRATCH_SLOTS <= 1) ? 1 : $clog2(SCRATCH_SLOTS + 1);
  logic [SCPAD_WPTR_W-1:0] scpad_wptr;

  assign inst[0] = ifdec1_if.inst_packet_out.inst0;
  assign inst[1] = ifdec1_if.inst_packet_out.inst1;
  assign inst[2] = ifdec1_if.inst_packet_out.inst2;
  assign inst[3] = ifdec1_if.inst_packet_out.inst3;


  always_comb begin

    for (int i = 0; i < PACKET_SIZE; i++) begin
      opcode_t op;
      op = opcode_t'(inst[i][OP_W-1:0]); 
      
      cat[i] = TYPE_NONE;
      if (inst[i] != '0) begin 
        if ((op >= ADD_S && op <= HALT_S) || (op == LHW_S) || (op == SHW_S)) begin
          cat[i] = TYPE_SCALAR;
        end 
        // else if (op >= ADD_VV && op <= MNEQ_MVS) begin
        //   cat[i] = TYPE_VECTOR;
        // end else if (op == SCPAD_LD || op == SCPAD_ST) begin
        //   cat[i] = TYPE_SCPAD;
        // end
      end
    end
  end


  always_comb begin
    scpad_wptr = '0;


    for (int i = 0; i < SCALAR_SLOTS; i++) dec12_if.scalar_inst_in[i] = '0;
    // for (int i = 0; i < VECTOR_SLOTS; i++) dec12_if.vector_inst_in[i] = '0;
    // for (int i = 0; i < SCRATCH_SLOTS; i++) dec12_if.scpad_inst_in[i]  = '0;


    for (int i = 0; i < PACKET_SIZE; i++) begin
      unique case (cat[i])
        TYPE_SCALAR: begin
          if (i < SCALAR_SLOTS)
            dec12_if.scalar_inst_in[i] = inst[i];
        end

        // TYPE_VECTOR: begin
        //   if (i < VECTOR_SLOTS)
        //     dec12_if.vector_inst_in[i] = inst[i];
        // end

        // TYPE_SCPAD: begin
        //   if (scpad_wptr < SCRATCH_SLOTS) begin
        //     dec12_if.scpad_inst_in[scpad_wptr] = inst[i];
        //     scpad_wptr = scpad_wptr + 1'b1;
        //   end
        // end

        default: ; // TYPE_NONE
      endcase
    end
  end


  assign dec12_if.pc_in            = ifdec1_if.pc_out;
  assign dec12_if.predict_taken_in = ifdec1_if.predict_taken_out;
  assign dec12_if.pc_pred_addr_in  = ifdec1_if.pc_pred_addr_out;

endmodule