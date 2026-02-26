`include "atalla_isa_types.vh"
`include "if_dec1_if.vh"
import atalla_isa_pkg::*;

module if_dec1_reg (
    input logic CLK, nRST,
    if_dec1_if.latch_view ifdec1_if
);

  always_ff @(posedge CLK or negedge nRST) begin
    if (!nRST) begin
      ifdec1_if.pc_out            <= '0;
      ifdec1_if.inst_packet_out   <= '0;
      ifdec1_if.predict_taken_out <= '0;
      ifdec1_if.pc_pred_addr_out  <= '0;
    end
    else begin
      if (ifdec1_if.flush && ifdec1_if.ihit) begin
        ifdec1_if.pc_out            <= '0;
        ifdec1_if.inst_packet_out   <= '0; 
        ifdec1_if.predict_taken_out <= '0;
        ifdec1_if.pc_pred_addr_out  <= '0;
      end

      else if (ifdec1_if.ihit && ifdec1_if.ready) begin
        ifdec1_if.pc_out            <= ifdec1_if.pc_in;
        ifdec1_if.inst_packet_out   <= ifdec1_if.inst_packet_in;
        ifdec1_if.predict_taken_out <= ifdec1_if.predict_taken_in;
        ifdec1_if.pc_pred_addr_out  <= ifdec1_if.pc_pred_addr_in;
      end

    end
  end

endmodule