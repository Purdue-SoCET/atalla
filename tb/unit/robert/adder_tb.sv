`timescale 1ns/1ps

module adder_tb;

    logic a, b;
    logic sum;

    // DUT
    adder dut (
        .a(a),
        .b(b),
        .sum(sum)
    );

    initial begin
        $display(" time | a b | sum");
        $display("------+-----+----");

        a = 0; b = 0; #1;
        $display("%4t | %0d %0d |  %0d", $time, a, b, sum);

        a = 0; b = 1; #1;
        $display("%4t | %0d %0d |  %0d", $time, a, b, sum);

        a = 1; b = 0; #1;
        $display("%4t | %0d %0d |  %0d", $time, a, b, sum);

        a = 1; b = 1; #1;
        $display("%4t | %0d %0d |  %0d", $time, a, b, sum);

        $display("TEST DONE");
        $finish;
    end

endmodule
