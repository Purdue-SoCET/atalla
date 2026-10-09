`ifndef TCACHE_IF_SVH
`define TCACHE_IF_SVH

`include "tc_types.sv"

interface tc_if (input logic clk);

  logic n_rst;

	// TODO: define widths
  logic batch_id;
	logic [3:0][S_T_WIDTH-1:0] s;
	logic [3:0][S_T_WIDTH-1:0] t;
	logic [3:0][TEXEL_WIDTH-1:0] tex_width;
  logic [3:0][TEXEL_HEIGHT-1:0] tex_height;
	logic [3:0][ADDR_WIDTH-1:0] base_addr;
  logic tmu_valid;

  logic cache_ready;
  logic [3:0][TEXEL_RETURN_WIDTH-1:0] texel_return;

	// TODO: define widths
	logic [ADDR_WIDTH-1:0] mem_addr;
  logic mem_valid;

	logic [DATA_WIDTH-1:0] mem_data;
  logic mem_ready;

	modport tmu
	(
		input clk, n_rst, s, t, tex_width, tex_height, base_addr, tmu_valid,
		output cache_ready, texel_return
	);

	modport mem
	(
		input clk, n_rst, mem_addr, mem_valid,
		output mem_data, mem_ready
	);

endinterface

`endif
