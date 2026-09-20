// ============================================================================
// meissa_top_wrapper.sv
// Flat-port wrapper around meissa_top for cocotb testability.
// Cocotb cannot drive SystemVerilog interface ports directly, so this
// module instantiates the interface internally and exposes plain logic ports.
// ============================================================================

`include "sys_arr_pkg.vh"
`include "vector_pkg.vh"
`include "gsau_control_interface.vh"

module meissa_top_wrapper #(
    parameter int N            = 32,
    parameter int MULT_LATENCY = 2,
    parameter int ADD_LATENCY  = 1
)(
    input  logic         clk,
    input  logic         nRST,

    // Systolic-array facing signals (directly from gsau_control_unit_if)
    input  logic [511:0] sa_array_in,
    input  logic [511:0] sa_array_in_partials,
    input  logic         sa_input_en,
    input  logic         sa_weight_en,
    input  logic         sa_partial_en,
    input  logic         sa_ready_out,

    output logic [511:0] sa_array_output,
    output logic         sa_valid_in,
    output logic         sa_ready_in
);

    // Instantiate the interface
    gsau_control_unit_if gsau_if ();

    // ---- Drive interface inputs from wrapper ports ----
    assign gsau_if.sa_array_in          = sa_array_in;
    assign gsau_if.sa_array_in_partials = sa_array_in_partials;
    assign gsau_if.sa_input_en          = sa_input_en;
    assign gsau_if.sa_weight_en         = sa_weight_en;
    assign gsau_if.sa_partial_en        = sa_partial_en;
    assign gsau_if.sa_ready_out         = sa_ready_out;

    // ---- Drive wrapper outputs from interface outputs ----
    assign sa_array_output = gsau_if.sa_array_output;
    assign sa_valid_in     = gsau_if.sa_valid_in;
    assign sa_ready_in     = gsau_if.sa_ready_in;

    // ---- Tie off unused interface signals (veggie / scheduler / wb) ----
    // These are inputs on other modports but outputs on the interface.
    // We drive them to safe defaults so the interface is fully connected.
    assign gsau_if.veg_vdata1  = '0;
    assign gsau_if.veg_vdata2  = '0;
    assign gsau_if.sb_vdst     = '0;
    assign gsau_if.sb_valid_in = 1'b0;
    assign gsau_if.sb_weight   = 1'b0;
    assign gsau_if.wb_ready_in = 1'b1;

    // ---- DUT ----
    meissa_top #(
        .N            (N),
        .MULT_LATENCY (MULT_LATENCY),
        .ADD_LATENCY  (ADD_LATENCY)
    ) u_dut (
        .clk     (clk),
        .nRST    (nRST),
        .gsau_if (gsau_if)
    );

endmodule