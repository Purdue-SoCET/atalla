// first dradt of interface
//

`ifndef SYSTOLIC_ARRAY_IF_SV
`define SYSTOLIC_ARRAY_IF_SV
interface systolic_array_if #(parameter N = 4, parameter WIDTH = 16)(input_logic clk, input logic n_rst);
	// control signals
	logic weight_en;
	logic input_en;
	logic partial_en;
	logic [$clog2(N)-1:0] row_in_en;
	logic [$clog2(N)-1:0] row_ps_en;
	
	// data
	logic [N*WIDTH-1:0] array_in;
    	logic [N*WIDTH-1:0] array_in_partials;


	// sampled by monitor
	logic out_en;
    	logic drained;
    	logic fifo_has_space;
    	logic [$clog2(N)-1:0] row_out;
    	logic [N*WIDTH-1:0] array_output;

	clocking driver @(posedge clk);
		default input #1step output #1ns;

		output weight_en, input_en, partial_en, row_in_en, row_ps_en;
		input fifo_has_space; // needs to make sure there is room in fifo before loaading
	endclocking

        clocking monitor @(posedge clk);
                default input #1step output #1ns;

                input  weight_en, input_en, partial_en, row_in_en, row_ps_en;
                input out_en, drained, fifo_has_space, row_out, array_output;
        endclocking
endinterface



`endif
