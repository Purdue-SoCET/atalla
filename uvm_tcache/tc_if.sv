`ifndef TCACHE_IF_SVH
`define TCACHE_IF_SVH

interface tc_if (input logic clk);

  logic n_rst;

	// TODO: define widths
	logic v;
	logic u;
	logic tex_width;
	logic base_addr;

	// TODO: define widths
	logic [31:0] mem_addr;
	logic [31:0] mem_data;

	modport tmu
	(
		input clk, n_rst, v, u, tex_width, base_addr,
		output hit_way, hit
	);

	modport mem
	(
		input clk, n_rst, mem_addr,
		output mem_data
	);

endinterface

`endif
