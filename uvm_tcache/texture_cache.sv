`ifndef TEXTURE_CACHE_SVH
`define TEXTURE_CACHE_SVH

`include "tc_types.sv"

module texture_cache(
  input logic clk, n_rst,
  input logic batch_id,
  input logic [3:0][S_T_WIDTH-1:0] s, t,
  input logic [3:0][TEXEL_WIDTH-1:0] tex_width,
  input logic [3:0][TEXEL_HEIGHT-1:0] tex_height,
  input logic [3:0][ADDR_WIDTH-1:0] base_addr,
  input logic tmu_valid,

  input logic mem_ready,
  input logic [DATA_WIDTH-1:0] mem_data,

  output logic [3:0][TEXEL_RETURN_WIDTH-1:0] texel_return,
  output logic cache_ready,

  output logic [ADDR_WIDTH-1:0] mem_addr,
  output logic mem_valid
);

endmodule

`endif
