module rom_bank #(
  parameter int DWIDTH = 144,
  parameter int DEPTH = 1024,
  parameter string INIT_FILE = "./controlbits.mem"
) (
  input logic clk, en,
  input logic [$clog2(DEPTH)-1:0] addr,
  output logic [DWIDTH-1:0] data
);
  logic [DWIDTH-1:0] mem [0:DEPTH-1];

  initial begin
    $readmemh(INIT_FILE, mem);
  end

  always_ff @ (posedge clk) begin
    if (en) data <= mem[addr];
  end

endmodule
