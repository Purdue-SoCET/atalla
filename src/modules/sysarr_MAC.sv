`include "systolic_array_MAC_if.vh"

module sysarr_MAC (
    /* verilator lint_off UNUSEDSIGNAL */
    input logic clk, nRST,
    /* verilator lint_off UNUSEDSIGNAL */
    systolic_array_MAC_if.MAC mac
);
   
   always_comb begin
    mac.out_accumulate = '0;
    if (mac.count == 4)begin
        mac.out_accumulate = (mac.in_value * mac.weight) + mac.in_accumulate;;
    end
end
endmodule
