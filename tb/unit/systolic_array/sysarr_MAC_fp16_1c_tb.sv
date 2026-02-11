`timescale 1ns/1ps

`include "systolic_array_MAC_if.vh"

// Testbench for sysarr_MAC_fp16_1c (1-cycle MAC unit, no output latch)
// Result is combinational off registered inputs: valid after input_x and weight are latched.
// 2-cycle sequence: load weight -> load input+accumulate -> result available combinationally.
// to run - verilator --binary --sv --timing -Wno-UNUSEDSIGNAL -Wno-UNUSEDPARAM -Wno-IMPORTSTAR -Wno-TIMESCALEMOD -Wno-WIDTHEXPAND -Wno-WIDTHTRUNC -Wno-CASEINCOMPLETE -Wno-LATCH -o sysarr_MAC_fp16_1c_tb sysarr_MAC_fp16_1c_tb.sv sysarr_MAC_fp16_1c.sv mul_fp16_nolatch.sv add_fp16_nolatch.sv wallacetree_11b.sv adder_5b.sv left_shift.sv fa.sv ha.sv systolic_array_MAC_if.vh sys_arr_pkg.vh
// then ./obj_dir/sysarr_MAC_fp16_1c_tb
// dont forget to run python generator 
/* verilator lint_off UNUSEDSIGNAL */
module sysarr_MAC_fp16_1c_tb;

    localparam CLK_PERIOD = 2;

    logic tb_clk;
    logic tb_nrst;

    always begin
        tb_clk = 1'b0;
        #(CLK_PERIOD/2.0);
        tb_clk = 1'b1;
        #(CLK_PERIOD/2.0);
    end

    systolic_array_MAC_if mac_if();
    sysarr_MAC_fp16_1c dut (.clk(tb_clk), .nRST(tb_nrst), .mac_if(mac_if.MAC));

    int pass_count, fail_count;

    function automatic logic is_nan(input logic [15:0] val);
        return (val[14:10] == 5'b11111) && (val[9:0] != 10'b0);
    endfunction

    function automatic logic is_zero(input logic [15:0] val);
        return (val[14:0] == 15'b0);
    endfunction

    function automatic logic results_match(input logic [15:0] got, input logic [15:0] exp_val);
        if (is_nan(got) && is_nan(exp_val)) return 1'b1;
        if (is_zero(got) && is_zero(exp_val)) return 1'b1;
        return (got === exp_val);
    endfunction

    // 2-cycle MAC task:
    //   cycle 1 posedge: load weight
    //   cycle 2 posedge: input_x latched -> mul+add settle combinationally -> check result
    task automatic run_mac(
        input logic [15:0] w, x, acc,
        input logic [15:0] expected,
        input string casename
    );
        // Load weight
        @(negedge tb_clk);
        mac_if.in_value = w;
        mac_if.weight_en = 1'b1;
        mac_if.MAC_shift = 1'b0;
        mac_if.start = 1'b0;
        @(posedge tb_clk);

        // load input + accumulate, assert start
        @(negedge tb_clk);
        mac_if.weight_en = 1'b0;
        mac_if.in_value = x;
        mac_if.in_accumulate = acc;
        mac_if.MAC_shift = 1'b1;
        mac_if.start = 1'b1;
        @(posedge tb_clk);

        // input_x now latched, combinational result settles
        @(negedge tb_clk);
        mac_if.MAC_shift = 1'b0;
        mac_if.start = 1'b0;

        #1;
        if (!results_match(mac_if.out_accumulate, expected)) begin
            $display("FAIL %s: w=%h x=%h acc=%h got=%h exp=%h", casename, w, x, acc, mac_if.out_accumulate, expected);
            fail_count++;
        end else begin
            $display("PASS %s: w=%h x=%h acc=%h -> %h", casename, w, x, acc, mac_if.out_accumulate);
            pass_count++;
        end
    endtask

    task automatic run_mac_fast(
        input logic [15:0] w, x, acc,
        input logic [15:0] expected
    );
        @(negedge tb_clk);
        mac_if.in_value = w;
        mac_if.weight_en = 1'b1;
        mac_if.MAC_shift = 1'b0;
        mac_if.start = 1'b0;
        @(posedge tb_clk);

        @(negedge tb_clk);
        mac_if.weight_en = 1'b0;
        mac_if.in_value = x;
        mac_if.in_accumulate = acc;
        mac_if.MAC_shift = 1'b1;
        mac_if.start = 1'b1;
        @(posedge tb_clk);

        @(negedge tb_clk);
        mac_if.MAC_shift = 1'b0;
        mac_if.start = 1'b0;

        #1;
        if (!results_match(mac_if.out_accumulate, expected)) begin
            $display("FAIL: w=%h x=%h acc=%h got=%h exp=%h", w, x, acc, mac_if.out_accumulate, expected);
            fail_count++;
        end else begin
            pass_count++;
        end
    endtask

    localparam logic [15:0] P_ZERO = 16'h0000;
    localparam logic [15:0] ONE    = 16'h3C00;
    localparam logic [15:0] TWO    = 16'h4000;
    localparam logic [15:0] THREE  = 16'h4200;
    localparam logic [15:0] FIVE   = 16'h4500;
    localparam logic [15:0] P_INF  = 16'h7C00;
    localparam logic [15:0] QNAN   = 16'h7E00;

    integer fd;
    string header;
    logic [15:0] csv_a, csv_b, csv_c, csv_exp;

    initial begin
        pass_count = 0;
        fail_count = 0;

        tb_nrst = 0;
        mac_if.start = 0;
        mac_if.stall_sa = 0;
        mac_if.weight_en = 0;
        mac_if.MAC_shift = 0;
        mac_if.in_value = 0;
        mac_if.in_accumulate = 0;

        @(posedge tb_clk);
        @(posedge tb_clk);
        tb_nrst = 1;
        @(posedge tb_clk);
        @(posedge tb_clk);

        $display("=== sysarr_MAC_fp16_1c Testbench ===");
        $display("");
        $display("--- basic mac: (x * w) + acc ---");

        run_mac(ONE, ONE, P_ZERO, ONE, "1*1+0=1");
        run_mac(ONE, TWO, THREE, FIVE, "2*1+3=5");
        run_mac(TWO, TWO, P_ZERO, 16'h4400, "2*2+0=4");
        run_mac(ONE, P_ZERO, THREE, THREE, "0*1+3=3");
        run_mac(ONE, QNAN, P_ZERO, QNAN, "NaN*1+0=NaN");
        run_mac(ONE, P_INF, P_ZERO, P_INF, "Inf*1+0=Inf");

        $display("");
        $display("=== Random MAC Cases from CSV ===");

        fd = $fopen("scripts/systolic_array/random_mac_cases.csv", "r");
        if (fd == 0) begin
            $display("check if csv is in right dir");
            $finish;
        end

        void'($fgets(header, fd));

        while (!$feof(fd)) begin
            int ret;
            ret = $fscanf(fd, "%h,%h,%h,%h\n", csv_a, csv_b, csv_c, csv_exp);
            if (ret != 4) continue;
            run_mac_fast(csv_b, csv_a, csv_c, csv_exp);
        end

        $fclose(fd);

        $display("");
        $display("=== test summary ===");
        $display("PASSED: %0d", pass_count);
        $display("FAILED: %0d", fail_count);

        if (fail_count == 0)
            $display("ALL TESTS PASSED!");
        else
            $display("SOME TESTS FAILED!");

        $finish;
    end

endmodule
