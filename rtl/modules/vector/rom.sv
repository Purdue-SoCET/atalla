// ROM model with FFs
// init data required in rom_init_data.svh
module rom #(
    parameter int ROMDEPTH = 16, // how many word entries in ROM
    parameter int WORDSIZE = 16 // size of word in BITS
) (
    input logic CLK, nRST,
    input logic [$clog2(ROMDEPTH)-1:0] addr,
    output logic [WORDSIZE-1:0] out
);

logic [ROMDEPTH-1:0][WORDSIZE-1:0] rom; // packed array

// Synthesizably assign rom contents
always_ff @(posedge CLK, negedge nRST) begin
    if (!nRST) begin
        rom <= '{
            `include "rom_init_data.svh"
        };
        out <= '0;
    end else begin
        out <= rom[addr];
    end
end
endmodule