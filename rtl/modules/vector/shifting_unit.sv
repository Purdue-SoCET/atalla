// Nikhil Vaidyanath - nvaidyan@purdue.edu

`include "vector_pkg.vh"
`include "shifting_unit_if.vh"
`include "xbar_if.vh"
`include "shifting_unit_pkg.vh"

module shifting_unit #(
) (
    input logic clk,
    input logic n_rst,
    shifting_unit_if.shift_u sh_unit
);
    import vector_pkg::*;
    import shifting_unit_pkg::*;

    localparam int ROM_WORD_SIZE = 10 * 8; // 10 bytes per element, compressed from 18 byte ctrl bits
    localparam int BENES_STAGES = (2 * $clog2(NUM_ELEMENTS)) - 1;
    localparam int BENES_HALF = NUM_ELEMENTS / 2;
    localparam int BENES_BITWIDTH = BENES_STAGES * BENES_HALF;
    localparam int PADDING_BITS = BENES_BITWIDTH - ROM_WORD_SIZE;

    shifting_unit_inputs_t inputs, inputs_q;
    shifting_unit_outputs_t outputs, outputs_q;

    assign inputs = sh_unit.inputs;
    assign sh_unit.outputs = outputs_q;

    always_ff @(posedge clk, negedge n_rst) begin
        if (~n_rst) begin
            inputs_q <= '0;
            outputs_q <= '0;
        end else begin
            // stall pipeline when output isn't ready
            if (inputs.ready_in) begin
                inputs_q <= inputs;
                outputs_q <= outputs;
            end
        end
    end

    always_comb begin
        sh_unit.ready_out = inputs.ready_in; // needs to be comb because need to immediately apply backpressure
        outputs.valid_out = inputs_q.valid_in;
    end

    `ifndef SYNTHESIS
        // observe signals in logic form for debugging, not included for synthesis
        logic [31:0][15:0] inputs_logic;
        assign inputs_logic = sh_unit.veg_vdata;
    `endif

    logic [$clog2(NUM_ELEMENTS)-1:0] rom_addr;
    logic [ROM_WORD_SIZE-1:0] ctrl_bits;
    vreg_t benes_out;

    assign rom_addr = (inputs_q.direction) ? (NUM_ELEMENTS - inputs_q.shift_amount) : inputs_q.shift_amount;

    rom #(
        .ROMDEPTH(NUM_ELEMENTS),
        .WORDSIZE(ROM_WORD_SIZE) // Assuming 10 bytes per element
    ) shift_rom (
        .CLK(clk),
        .nRST(n_rst),
        .addr(rom_addr),
        .out(ctrl_bits)
    );

    // Instantiate xbar interface for benes network
    xbar_if #(
        .SIZE(NUM_ELEMENTS),
        .DWIDTH(ESZ)
    ) benes_xif (
        .clk(clk),
        .n_rst(n_rst)
    );

    // Connect interface signals
    integer i;
    always_comb begin : inout_assignment
        for (i = 0; i < NUM_ELEMENTS; i++) begin
            benes_xif.in[i] = inputs_q.veg_vdata[i];
        end
        benes_out = benes_xif.out;
    end

    benes #(
        .SIZE(NUM_ELEMENTS),    // Number of elements in the vector from vector_pkg
        .DWIDTH(ESZ),           // Element Size from vector_pkg
        .REGISTER_MASK('0)      // Register mask of 0 makes benes single cycle
    ) sh_benes (
        .xif(benes_xif.xbar),
        .control_bit({ctrl_bits, {PADDING_BITS{1'b0}}})
    );

    logic [NUM_ELEMENTS-1:0] element_mask;

    always_comb begin : output_mask
        if (inputs_q.direction == LEFT) begin
            // Left shift: keep leftmost (NUM_ELEMENTS - shift_amount) elements
            // Mask bits [NUM_ELEMENTS-1 : shift_amount] = 1, rest = 0
            element_mask = ({NUM_ELEMENTS{1'b1}} << inputs_q.shift_amount);
        end else begin
            // Right shift: keep rightmost (NUM_ELEMENTS - shift_amount) elements  
            // Mask bits [NUM_ELEMENTS - shift_amount - 1 : 0] = 1, rest = 0
            element_mask = ({NUM_ELEMENTS{1'b1}} >> inputs_q.shift_amount);
        end
        
        // Apply mask element-wise
        for (int i = 0; i < NUM_ELEMENTS; i++) begin
            outputs.shifted_vdata[i] = element_mask[i] ? bf16_t'(benes_out[i]) : bf16_t'(ESZ'(0));
        end
    end
endmodule