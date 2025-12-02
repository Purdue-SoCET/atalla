`timescale 1ns / 1ns

module benes_rom_tb;

    localparam int PERIOD   = 10;
    localparam int SIZE     = 32;
    localparam int DWIDTH   = 16;
    localparam int TAGWIDTH = $clog2(SIZE);
    localparam int STAGES   = (2 * TAGWIDTH) - 1;
    localparam int BITWIDTH = STAGES * (SIZE >> 1);  
    localparam int ROM_DEPTH = 1024;
    localparam int ADDR_BITS = $clog2(ROM_DEPTH);

    localparam int TEST_ROWS = 5;
    localparam int TEST_COLS = 7;
    localparam int TEST_ADDR = ((TEST_ROWS - 1) << 5) | TEST_COLS;

    logic clk, n_rst;

    logic [ADDR_BITS-1:0] addr;
    logic [BITWIDTH-1:0]  rom_control_bits;
    logic [BITWIDTH-1:0]  control_bit;

    initial clk = 1'b0;
    always #(PERIOD/2) clk = ~clk;

    xbar_if #(.SIZE(SIZE), .DWIDTH(DWIDTH)) xif (
        .clk(clk),
        .n_rst(n_rst)
    );

    benes #(.SIZE(SIZE), .DWIDTH (DWIDTH)) DUT (
        .xif(xif),
        .control_bit(control_bit)
    );

    rom_bank #(.DWIDTH(BITWIDTH), .DEPTH(ROM_DEPTH), .INIT_FILE("./rtl/modules/common/xbar/controlbits.mem")
    ) u_ctrl_rom (
        .clk(clk),
        .en('1),
        .addr(addr),
        .data(rom_control_bits)
    );

    assign control_bit = rom_control_bits;

    integer i;
    logic [DWIDTH-1:0] exp_out [SIZE-1:0];
    logic [DWIDTH-1:0] val;

    initial begin
        n_rst = 1'b0;
        addr = TEST_ADDR;
        xif.en = 1; 

        @(posedge clk);
        @(posedge clk);

        $display("ERROR: index %0d: got %b", addr, control_bit);

        n_rst = 1'b1;

        // Drive inputs: in[i] = i
        for (i = 0; i < SIZE; i = i + 1) begin
            xif.in[i] = DWIDTH'(i);
        end

        exp_out = '{
            16'd2,  16'd3,  16'd0,  16'd1,
            16'd30, 16'd31, 16'd28, 16'd29,
            16'd10, 16'd11, 16'd8,  16'd9,
            16'd6,  16'd7,  16'd4,  16'd5,
            16'd18, 16'd19, 16'd16, 16'd17,
            16'd14, 16'd15, 16'd12, 16'd13,
            16'd26, 16'd27, 16'd24, 16'd25,
            16'd22, 16'd23, 16'd20, 16'd21
        };

        repeat (10) #(PERIOD);

        for (i = 0; i < SIZE; i = i + 1) begin
            if (xif.out[i] !== exp_out[i]) begin
                $display("ERROR: index %0d: got %0d, expected %0d",
                         i, xif.out[i], exp_out[i]);
            end
        end

        $display("benes_rom_tb finished.");
        $finish;
    end

endmodule
