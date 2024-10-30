`include "dispatch_if.vh"
`include "types_pkg.vh"

module dispatch(
    input logic CLK, nRST,
    dispatch_if.DI diif
);

    import types_pkg::*;

    dispatch_t n_dispatch;

    always_ff @ (posedge CLK, negedge nRST) begin: Pipeline Latching
      if (~nRST)
        diif.out <= '0;
    	else
        diif.out <= n_dispatch;
    end

    always_comb begin : Pipeline Latching
      case (1'b1)
        diif.flush:  n_dispatch = '0;
        diif.freeze: n_dispatch = diif.out;
        diif.ihit:   n_dispatch = n_dispatch;
        default:     n_dispatch = diif.out;
      endcase
    end

    // need control logic to determine which FU to dispatch, compare to fu_busy
    // to determine if possible to dispatch, stall PC if not possible to dispatch

    always_comb begin : Next Dispatch
      //TODO
      n_dispatch = diif.out;
    end

endmodule
