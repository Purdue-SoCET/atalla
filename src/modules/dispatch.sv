`include "dispatch_if.vh"
`include "types_pkg.vh"

module dispatch(
    input logic CLK, nRST,
    dispatch_if.DI diif
);

    import types_pkg::*;

    dispatch_t dispatch;

    always_ff @ (posedge CLK, negedgs nRST) begin: Pipeline Latching
      if (~nRST)
        diif.dispatch_p <= '0;
    	else if (diif.flush)
        diif.dispatch_p <= '0;
      else if (diif.freeze)
        diif.dispatch_p <= diif.dispatch_p;
      else if (dispatch.ihit)
        diif.dispatch_p <= dispatch;
    	else
        diif.dispatch_p <= diif.dispatch_p;

    // need control logic to determine which FU to dispatch, compare to fu_busy
    // to determine if possible to dispatch, stall PC if not possible to dispatch

endmodule
