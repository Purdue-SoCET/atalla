`include "atalla_isa_types.vh"
`include "if_dec1_if.vh"
import atalla_isa_pkg::*;

module if_dec1_reg (
    input logic CLK, nRST, halt,
    if_dec1_if.latch_view ifdec1_if
);
  //localparam r_t NOP_R = '{reserved:'0, rs2:'0, rs1:'0, rd:'0, opcode:NOP_S};
  //localparam logic [INST_W-1:0] NOP_INST = logic'(NOP_R);
  //localparam instruction_packet_t NOP_PACKET = '{inst0: NOP_INST, inst1: NOP_INST, inst2: NOP_INST, inst3: NOP_INST};

  always_ff @(posedge CLK or negedge nRST) begin
    if (!nRST) begin
      ifdec1_if.pc_out            <= '0;
      ifdec1_if.inst_packet_out   <= '0;
      ifdec1_if.predict_taken_out <= '0;
      ifdec1_if.pc_pred_addr_out  <= '0;
      ifdec1_if.valid_out <= '0;
    end
    else begin
      if (ifdec1_if.flush || halt) begin
        ifdec1_if.pc_out            <= '0;
        ifdec1_if.inst_packet_out   <= NOP_PACKET;
        ifdec1_if.predict_taken_out <= '0; 
        ifdec1_if.pc_pred_addr_out  <= '0;
        ifdec1_if.valid_out <= '0;
      end

      else if (ifdec1_if.ready) begin
        ifdec1_if.pc_out            <= ifdec1_if.pc_in;
        ifdec1_if.inst_packet_out   <= ifdec1_if.inst_packet_in;
        ifdec1_if.predict_taken_out <= ifdec1_if.predict_taken_in;
        ifdec1_if.pc_pred_addr_out  <= ifdec1_if.pc_pred_addr_in;
        ifdec1_if.valid_out         <= ifdec1_if.valid_in;
      end

    end
  end

endmodule