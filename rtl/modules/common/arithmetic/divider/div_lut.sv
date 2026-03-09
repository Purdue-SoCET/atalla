module div_lut(
  input logic [6:0] index,
  output logic [15:0] reciprocal
);
always_comb begin
  case(index)
    7'h00: reciprocal = 16'h3f78;
    7'h01: reciprocal = 16'h3f6a;
    7'h02: reciprocal = 16'h3f5d;
    7'h03: reciprocal = 16'h3f52;
    7'h04: reciprocal = 16'h3f48;
    7'h05: reciprocal = 16'h3f3f;
    7'h06: reciprocal = 16'h3f36;
    7'h07: reciprocal = 16'h3f2e;
    7'h08: reciprocal = 16'h3f27;
    7'h09: reciprocal = 16'h3f21;
    7'h0A: reciprocal = 16'h3f1a;
    7'h0B: reciprocal = 16'h3f15;
    7'h0C: reciprocal = 16'h3f10;
    7'h0D: reciprocal = 16'h3f0b;
    7'h0E: reciprocal = 16'h3f06;
    7'h0F: reciprocal = 16'h3f02;
    // ... add more cases as needed
    default: reciprocal = 16'h0000;
  endcase
end
endmodule