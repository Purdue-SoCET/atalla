`timescale 1ns / 1ns

import xbar_pkg::*;
import scpad_pkg::*;

module benes_rom_tb;

    localparam int PERIOD  = 10;
    localparam int SIZE = 32;
    localparam int DWIDTH  = 16;
    localparam int TAGWIDTH = $clog2(SIZE);
    localparam int STAGES   = (2 * TAGWIDTH) - 1;
    localparam int BITWIDTH = STAGES * (SIZE >> 1);  
    localparam int ROM_DEPTH = 512;
    localparam int ROM_DWIDTH = 144;
    localparam int ROM_ID_WIDTH = 2*COL_IDX_WIDTH - 1;

    initial begin 
        if (BITWIDTH != ROM_DWIDTH) begin 
             $fatal(1, "BITWIDTH (%0d) and ROM_DWIDTH don't match?!", BITWIDTH, ROM_DWIDTH);
        end 
    end

    logic clk, n_rst;

    initial clk = 1'b0;
    always #(PERIOD/2) clk = ~clk;

    scpad_if swizz_if(.clk(clk), .n_rst(n_rst));  
    xbar_if #(.SIZE(SIZE), .DWIDTH(DWIDTH)) xif (.clk(clk), .n_rst(n_rst));
    
    swizzle dut (.swizz(swizz_if.swizzle));

    logic rom_en;
    logic [ROM_ID_WIDTH-1:0] rom_addr;
    logic [ROM_DWIDTH-1:0] rom_control_bits;

    rom_bank #(.DWIDTH(ROM_DWIDTH), .DEPTH(ROM_DEPTH), .INIT_FILE("./rtl/modules/common/xbar/controlbits.mem")) rom_i (
        .clk(clk),
        .en(rom_en),
        .addr(rom_addr),
        .data(rom_control_bits)
    );

    benes #(.SIZE(SIZE), .DWIDTH(DWIDTH)) DUT_BENES (xif, {>>{rom_control_bits}});

    localparam int NUM_CASES = 5;

    localparam int CASE_ROM_ID [NUM_CASES] = '{104, 152, 259, 324, 436};

    localparam int CASE_NUM_ROWS [NUM_CASES] = '{ 11,  4,  3,  9,  2 };
    localparam int CASE_NUM_COLS [NUM_CASES] = '{ 14, 24, 11, 19, 31 };

    localparam int CASE_BASE_ROW [NUM_CASES] = '{ 323, 116,  72, 266,  61 };
    localparam int CASE_COL_ID   [NUM_CASES] = '{ 8, 8, 3, 4, 4 };

    localparam logic [ROM_DWIDTH-1:0] CASE_CTRL [NUM_CASES] = '{
        144'hFFFFAAAA7777F8F807000000000000000000, // rom_id 104
        144'h00000000FFFFF0F0F0FF0000000000000000, // rom_id 152
        144'hFFFFFFFF0000FFFF00FF0000000000000000, // rom_id 259
        144'h0000FFFFCCCCCFCF30FF0000000000000000, // rom_id 324
        144'hFFFF555511110E0E0E000000000000000000  // rom_id 436
    };

    int CASE_PI [NUM_CASES][NUM_COLS];

    initial begin
        CASE_PI[0] = '{
        11, 12, 13, 14, 15,  0,  1,  2,
        3,  4,  5,  6,  7, 24, 25, 26,
        27, 28, 29, 30, 31, 16, 17, 18,
        19, 20, 21, 22, 23,  8,  9, 10
        };

        CASE_PI[1] = '{
        28, 29, 30, 31, 16, 17, 18, 19,
        20, 21, 22, 23,  8,  9, 10, 11,
        12, 13, 14, 15,  0,  1,  2,  3,
        4,  5,  6,  7, 24, 25, 26, 27
        };

        CASE_PI[2] = '{
        11, 10,  9,  8, 15, 14, 13, 12,
        19, 18, 17, 16, 23, 22, 21, 20,
        27, 26, 25, 24, 31, 30, 29, 28,
        3,  2,  1,  0,  7,  6,  5,  4
        };

        CASE_PI[3] = '{
        14, 15,  8,  9, 10, 11, 20, 21,
        22, 23, 16, 17, 18, 19, 28, 29,
        30, 31, 24, 25, 26, 27,  4,  5,
        6,  7,  0,  1,  2,  3, 12, 13
        };

        CASE_PI[4] = '{
        25, 26, 27,  4,  5,  6,  7,  0,
        1,  2,  3, 12, 13, 14, 15,  8,
        9, 10, 11, 20, 21, 22, 23, 16,
        17, 18, 19, 28, 29, 30, 31, 24
        };
    end

    task automatic run_case(input int idx);
        logic [15:0] val;
        int mismatches = 0; 
        int golden[SIZE];

        swizz_if.swizz_req.row_or_col = 1'b0;                       
        swizz_if.swizz_req.spad_addr = CASE_BASE_ROW[idx];      
        swizz_if.swizz_req.num_rows = CASE_NUM_ROWS[idx];
        swizz_if.swizz_req.num_cols = CASE_NUM_COLS[idx];
        swizz_if.swizz_req.row_id = '0;
        swizz_if.swizz_req.col_id = CASE_COL_ID[idx];

        #1;

        if (swizz_if.swizz_res.xbar_desc.rom_id !== ROM_ID_WIDTH'(CASE_ROM_ID[idx])) begin
            $error("    [CASE %0d] rom_id mismatch: got %0d, expected %0d", idx, swizz_if.swizz_res.xbar_desc.rom_id, CASE_ROM_ID[idx]);
        end else begin
            $display("  [CASE %0d] rom_id OK: %0d", idx, CASE_ROM_ID[idx]);
        end

        for (int i = 0; i < NUM_COLS; i++) begin
            if (swizz_if.swizz_res.xbar_desc.shift_mask[i] !== CASE_PI[idx][i][COL_IDX_WIDTH-1:0]) begin
                $error("    [CASE %0d] shift_mask mismatch at lane %0d: got %0d, expected %0d", idx, i, swizz_if.swizz_res.xbar_desc.shift_mask[i], CASE_PI[idx][i]);
            end
        end

        rom_en = 1'b1;
        rom_addr = ROM_ID_WIDTH'(CASE_ROM_ID[idx]);

        @(posedge clk);

        for (int lane = 0; lane < SIZE; lane++) begin
            xif.in[lane].din = lane[DWIDTH-1:0];
            xif.in[lane].shift = CASE_PI[idx][lane]; 
            golden[lane] = CASE_PI[idx][lane];
        end

        @(posedge clk);

        if (rom_control_bits !== CASE_CTRL[idx]) begin
            $error("    [CASE %0d] ROM data mismatch: got %h, expected %h", idx, rom_control_bits, CASE_CTRL[idx]);
        end else begin
            $display("  [CASE %0d] ROM data OK: rom_control_bits = %h", idx, rom_control_bits);
        end

        rom_en = 1'b0;

        repeat (9) @(posedge clk);

        for (int bank = 0; bank < SIZE; bank++) begin
            if (xif.out[bank] !== golden[bank]) begin
                mismatches++;
            end
        end
        if (mismatches === 0) begin 
            $display("  [CASE %0d] Benes OK", idx); 
        end else begin 
            $display("  [CASE %0d] Benes Mismatch --", idx); 
        end 

        $display("  [CASE %0d]  Benes output = { %p }", idx, xif.out);
        $display("  [CASE %0d]  Expected = { %p }", idx, golden);

        #1;
    endtask

    initial begin
        rom_en = 1'b0;
        rom_addr = '0;
        n_rst = 1'b1;
        @(posedge clk);
        n_rst = 1'b0;
        repeat (2) @(posedge clk);
        n_rst = 1'b1;
        @(posedge clk);

        $display("[TB] Starting swizzle + ROM tests...");

        for (int c = 0; c < NUM_CASES; c++) begin
        $display("[TB] ================== Running CASE %0d (rom_id=%0d) =========", c, CASE_ROM_ID[c]);
        run_case(c);
        end

        $display("[TB] All cases completed.");
        $finish;
    end

endmodule
