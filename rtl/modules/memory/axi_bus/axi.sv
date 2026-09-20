`include "axi_bus_if.sv"
`include "axi_bus_pkg.sv"

module axi(
    input logic CLK, nRST,
    axi_bus_if abif
);

    axi_read RD (CLK, nRST, abif);
    axi_write_top WR (CLK, nRST, abif);
    
endmodule