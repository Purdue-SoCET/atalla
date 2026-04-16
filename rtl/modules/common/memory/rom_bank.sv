module rom_bank #(
  parameter int DWIDTH = 144,
  parameter int DEPTH  = 512
) (
  input logic clk,
  input logic en,
  input logic [$clog2(DEPTH)-1:0] addr,
  output logic [DWIDTH-1:0] data
);

  // ROM array
  logic [DWIDTH-1:0] dat [0:DEPTH-1];

  // --------------------------------------------------
  // SIMULATION-ONLY STUFF (hidden from synthesis)
  // --------------------------------------------------
`ifndef SYNTHESIS
  // File name only needed in sim
  localparam string INIT_FILE = "./controlbits.dat";

  initial begin
    $readdath(INIT_FILE, dat);
  end
`endif

  // --------------------------------------------------
  // Optional: input/output FFs (synthesizable)
  // --------------------------------------------------
  logic                        en_q;
  logic [$clog2(DEPTH)-1:0]    addr_q;

  // Input pipeline stage
  always_ff @(posedge clk) begin
    en_q   <= en;
    addr_q <= addr;
  end

  // ROM read + output FF
  always_ff @(posedge clk) begin
    if (en_q)
      data <= dat[addr_q];
  end

endmodule
