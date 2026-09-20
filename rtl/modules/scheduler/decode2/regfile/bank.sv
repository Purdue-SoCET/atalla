// bank.sv ================================================================
// Parametrizable register bank
// No external package dependencies
// ========================================================================
module bank #(
    parameter NUM_ELEMENTS = 1,
    parameter DATA_WIDTH   = 32,
    parameter NUM_ROWS     = 128,
    parameter ADDR_WIDTH   = $clog2(NUM_ROWS), 
    parameter ZERO_REG_VAL = 0, 
    parameter IS_ZERO_BANK = 0
)(
    input  logic clk,
    input logic nRST,

    input  logic                                  ren,
    input  logic   [ADDR_WIDTH-1:0]               raddr,
    output logic   [DATA_WIDTH*NUM_ELEMENTS-1:0]  rdata,

    input  logic                                  wen,
    input  logic   [ADDR_WIDTH-1:0]               waddr,
    input  logic   [DATA_WIDTH*NUM_ELEMENTS-1:0]  wdata,
    input  logic   [NUM_ELEMENTS-1:0]             wstrb
);

    logic [DATA_WIDTH-1:0] mem [NUM_ROWS-1:0][NUM_ELEMENTS-1:0];
    logic [DATA_WIDTH-1:0] n_mem [NUM_ROWS-1:0][NUM_ELEMENTS-1:0];

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            // Clear the whole bank
            for (int r = 0; r < NUM_ROWS; r++) begin
                for (int i = 0; i < NUM_ELEMENTS; i++) begin
                    mem[r][i] <= (r == 0 && IS_ZERO_BANK) ? (ZERO_REG_VAL ? '1 : '0) : '0;
                end
            end
        end
        else begin
            for (int r = 0; r < NUM_ROWS; r++) begin
                for (int i = 0; i < NUM_ELEMENTS; i++) begin
                    mem[r][i] <= n_mem[r][i];
                end
            end
        end
    end


    always_comb begin
        rdata = '0;
        for (int r = 0; r < NUM_ROWS; r++) begin
            for (int i = 0; i < NUM_ELEMENTS; i++) begin
                n_mem[r][i] = mem[r][i];
            end
        end
        if (wen) begin
            for (int i = 0; i < NUM_ELEMENTS; i++) begin
                if (wstrb[i])
                    n_mem[waddr][i] = wdata[i*DATA_WIDTH +: DATA_WIDTH];
            end
        end
        if (ren) begin
            for (int i = 0; i < NUM_ELEMENTS; i++) begin
                rdata[i*DATA_WIDTH +: DATA_WIDTH] = mem[raddr][i];
            end
        end
    end
    

endmodule