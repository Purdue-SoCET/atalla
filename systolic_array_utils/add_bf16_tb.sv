`timescale 1ns/1ps
/* verilator lint_off UNUSEDSIGNAL */
module add_bf16_tb;

    localparam CLK_PERIOD = 1;

    logic tb_clk, tb_nrst;
    always begin
        tb_clk = 0; #(CLK_PERIOD/2.0);
        tb_clk = 1; #(CLK_PERIOD/2.0);
    end

    logic [15:0] tb_a, tb_b;
    logic        tb_sub;
    logic [15:0] tb_result;
    logic        tb_overflow, tb_underflow, tb_invalid;

    addsub_bf16 dut (
        .clk       (tb_clk),
        .nRST      (tb_nrst),
        .sub       (tb_sub),
        .bf1_in    (tb_a),
        .bf2_in    (tb_b),
        .bf_out    (tb_result),
        .overflow  (tb_overflow),
        .underflow (tb_underflow),
        .invalid   (tb_invalid)
    );

    function automatic logic is_nan(input logic [15:0] v);
        return (v[14:7] == 8'hFF) && (v[6:0] != 0);
    endfunction

    function automatic logic is_zero_equiv(input logic [15:0] a, input logic [15:0] b);
        return ((a == 16'h0000 || a == 16'h8000) &&
                (b == 16'h0000 || b == 16'h8000));
    endfunction

    function automatic logic match(input logic [15:0] got, input logic [15:0] exp);
        if (is_nan(got) && is_nan(exp)) return 1'b1;
        if (is_zero_equiv(got, exp))   return 1'b1;
        return (got === exp);
    endfunction

    task automatic apply_and_wait(
        input logic [15:0] a,
        input logic [15:0] b,
        input logic        sub
    );
        @(negedge tb_clk);
        tb_a   = a;
        tb_b   = b;
        tb_sub = sub;
        @(posedge tb_clk);
        #1ps;
    endtask

    // Directed test vectors
    logic [15:0] A [0:24];
    logic [15:0] B [0:24];
    logic [15:0] EXP [0:24];
    integer idx, i;

    localparam logic [15:0]
        QNAN     = 16'h7FC0,
        POS_INF  = 16'h7F80,
        NEG_INF  = 16'hFF80,
        POS_ZERO = 16'h0000,
        NEG_ZERO = 16'h8000,
        MAX_POS  = 16'h7F7F,
        MAX_NEG  = 16'hFF7F;

    // CSV
    integer fd;
    string header;
    logic [15:0] csv_a, csv_b, csv_exp;
    int csv_sub_i;
    logic csv_sub;

    integer pass_cnt, fail_cnt;

    initial begin
        $dumpfile("systolic_array_utils/waves/add_bf16_waves.vcd");
        $dumpvars(0, add_bf16_tb);

        pass_cnt = 0;
        fail_cnt = 0;
        idx = 0;

        tb_nrst = 0;
        tb_a = 0; tb_b = 0; tb_sub = 0;
        #CLK_PERIOD;
        tb_nrst = 1;

        // Manual Edge Cases 
        A[idx]=16'h3FC0; B[idx]=16'h4020; EXP[idx]=16'h4080; idx++;
        A[idx]=16'h4200; B[idx]=16'h3F00; EXP[idx]=16'h4202; idx++;
        A[idx]=16'h4100; B[idx]=16'h4100; EXP[idx]=16'h4180; idx++;
        A[idx]=16'h4480; B[idx]=16'h4100; EXP[idx]=16'h4481; idx++;

        A[idx]=POS_ZERO; B[idx]=POS_ZERO; EXP[idx]=POS_ZERO; idx++;
        A[idx]=NEG_ZERO; B[idx]=POS_ZERO; EXP[idx]=POS_ZERO; idx++;
        A[idx]=NEG_ZERO; B[idx]=NEG_ZERO; EXP[idx]=NEG_ZERO; idx++;
        A[idx]=POS_ZERO; B[idx]=16'h4100; EXP[idx]=16'h4100; idx++;

        A[idx]=POS_INF; B[idx]=16'h4080; EXP[idx]=POS_INF; idx++;
        A[idx]=POS_INF; B[idx]=NEG_INF;  EXP[idx]=QNAN; idx++;
        A[idx]=NEG_INF; B[idx]=16'h4080; EXP[idx]=NEG_INF; idx++;
        A[idx]=NEG_INF; B[idx]=NEG_INF;  EXP[idx]=NEG_INF; idx++;
        A[idx]=POS_INF; B[idx]=POS_INF;  EXP[idx]=POS_INF; idx++;

        A[idx]=QNAN; B[idx]=16'h3F80; EXP[idx]=QNAN; idx++;
        A[idx]=QNAN; B[idx]=QNAN;     EXP[idx]=QNAN; idx++;

        A[idx]=MAX_POS; B[idx]=16'h7F00; EXP[idx]=POS_INF; idx++;
        A[idx]=MAX_NEG; B[idx]=MAX_NEG;  EXP[idx]=NEG_INF; idx++;

        A[idx]=16'h0080; B[idx]=16'h0080; EXP[idx]=16'h0100; idx++;
        A[idx]=16'h0001; B[idx]=16'h0001; EXP[idx]=POS_ZERO; idx++;
        A[idx]=16'h0081; B[idx]=16'h8080; EXP[idx]=POS_ZERO; idx++;

        A[idx]=16'h7000; B[idx]=16'h3000; EXP[idx]=16'h7000; idx++;
        A[idx]=16'h5A00; B[idx]=16'h0001; EXP[idx]=16'h5A00; idx++;

        A[idx]=16'h4000; B[idx]=16'hC000; EXP[idx]=POS_ZERO; idx++;
        A[idx]=16'h4200; B[idx]=16'hC1FC; EXP[idx]=16'h3F00; idx++;
        A[idx]=16'hC000; B[idx]=16'h3F80; EXP[idx]=16'hBF80; idx++;

        // Prime pipeline
        apply_and_wait(16'h0,16'h0,1'b0);

        // Directed tests
        $display("BF16 Manual Edge Cases");
        for (i=0;i<idx;i++) begin
            apply_and_wait(A[i], B[i], 1'b0);
            if (match(tb_result, EXP[i])) begin
                pass_cnt++;
                $display("PASS [%0d] A=%h B=%h OUT=%h",
                         i, A[i], B[i], tb_result);
            end else begin
                fail_cnt++;
                $display("FAIL [%0d] A=%h B=%h GOT=%h EXP=%h",
                         i, A[i], B[i], tb_result, EXP[i]);
            end
        end

        // CSV random tests
        fd = $fopen("test_data/random_bf16_cases.csv","r");
        if (fd==0) $finish;
        void'($fgets(header,fd));

        while (!$feof(fd)) begin
            if ($fscanf(fd,"%h,%h,%d,%h\n",
                        csv_a,csv_b,csv_sub_i,csv_exp)==4) begin
                csv_sub = csv_sub_i[0];
                apply_and_wait(csv_a, csv_b, csv_sub);
                if (match(tb_result, csv_exp)) pass_cnt++;
                else                           fail_cnt++;
            end
        end
        $fclose(fd);

        // Final summary
        $display("");
        $display("BF16 ADD/SUB TEST SUMMARY");
        $display("PASSED : %0d", pass_cnt);
        $display("FAILED : %0d", fail_cnt);
        if (fail_cnt==0) $display("STATUS : PASS");
        else             $display("STATUS : FAIL");

        #CLK_PERIOD;
        $finish;
    end
endmodule
