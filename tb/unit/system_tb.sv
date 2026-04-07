module system_tb;

  parameter PERIOD = 2;
  logic CLK = 0, nRST;
  always #(PERIOD/2) CLK = ~CLK;

    logic [NUM_BANKS-1:0] ram_mem_REN;
    logic [NUM_BANKS-1:0] ram_mem_WEN;
    logic [NUM_BANKS-1:0][31:0] ram_mem_addr;
    logic [NUM_BANKS-1:0][31:0] ram_mem_store;
    logic [NUM_BANKS-1:0][31:0] ram_mem_data;
    logic [NUM_BANKS-1:0] ram_mem_complete;

    system ATALLA
    (
        .CLK(CLK), .nRST(nRST), .ram_mem_REN(ram_mem_REN), .ram_mem_WEN(ram_mem_WEN),
        .ram_mem_addr(ram_mem_addr), .ram_mem_store(ram_mem_store), .ram_mem_data(ram_mem_data), .ram_mem_complete(ram_mem_complete)
    );

    initial begin
        @(posedge CLK);
        $finish;
    end

endmodule