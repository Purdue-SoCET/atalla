`ifndef TEXTURE_CACHE_SVH
`define TEXTURE_CACHE_SVH

module texture_cache(
  input logic clk, n_rst,
  input logic v, u,
  input logic tex_width,
  input logic base_addr,
  input logic mem_addr,
  output logic hit_way,
  output logic hit,
  output logic mem_data
);

endmodule

`endif
