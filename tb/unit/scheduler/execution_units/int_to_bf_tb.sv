`timescale 1ns / 10ps
`include "int_to_bf_if.sv"

module int_to_bf_tb;


    parameter PERIOD = 2;
    parameter TESTCASES = 10;
    logic CLK = 0, nRST;
    logic [31:0] f32_bits;
    shortreal    sr;

    localparam int signed I32_MAX = 32'sh7FFF_FFFF;
    localparam int signed I32_MIN = 32'sh8000_0000;

    always #(PERIOD/2) CLK++;

    int_to_bf_if int_bfif ();
    int_to_bf DUT (.CLK(CLK), .int_bfif(int_bfif));

    int casenum;
    string casename;
    integer i;

    typedef struct {
        logic [15:0] expBF;
        logic rd;
        logic [31:0] IntIn;
    } testVec_struct;

    testVec_struct testVec [40];

    task set_tv;
        input logic [15:0] tv_expBF;
        input logic tv_rd;
        input logic [31:0] tv_IntIn;
        input integer idx;
    begin
        testVec[idx].expBF = tv_expBF;
        testVec[idx].rd = tv_rd;
        testVec[idx].IntIn = tv_IntIn;
    end
    endtask


initial begin
    casenum = '0;
    casename = "nRST";
    int_bfif.inputInt = '0;
    int_bfif.ready_out = '0;
    int_bfif.valid_in = '0;
    int_bfif.rdIn = '0;
    nRST = '0;
    #(PERIOD);
    nRST = 1;
    #(PERIOD);

    set_tv(.tv_expBF(16'h4140), .tv_rd(1), .tv_IntIn(12), .idx(0));
    set_tv(.tv_expBF(16'hc21c), .tv_rd(1), .tv_IntIn(-39), .idx(1));
    set_tv(.tv_expBF(16'h4b1c), .tv_rd(1), .tv_IntIn(10223672), .idx(2));
    set_tv(.tv_expBF(16'h4b1c), .tv_rd(1), .tv_IntIn(10223253), .idx(3));
    set_tv(.tv_expBF(16'hcb1c), .tv_rd(1), .tv_IntIn(-10223253), .idx(4));
    set_tv(.tv_expBF(16'hcb1c), .tv_rd(1), .tv_IntIn(-10223672), .idx(5));
    set_tv(.tv_expBF(16'h0000), .tv_rd(1), .tv_IntIn(0), .idx(6));
    set_tv(.tv_expBF(16'h4f00), .tv_rd(1), .tv_IntIn(I32_MAX), .idx(7));
    set_tv(.tv_expBF(16'hcf00), .tv_rd(1), .tv_IntIn(I32_MIN), .idx(8));
    set_tv(.tv_expBF(16'h47f1), .tv_rd(1), .tv_IntIn(123392), .idx(9));
    set_tv(.tv_expBF(16'h4a71), .tv_rd(1), .tv_IntIn(3940682), .idx(10));
    set_tv(.tv_expBF(16'h4a70), .tv_rd(1), .tv_IntIn(3940352), .idx(11));
    set_tv(.tv_expBF(16'h4a72), .tv_rd(1), .tv_IntIn(3956736), .idx(12));
    set_tv(.tv_expBF(16'h4e7f), .tv_rd(1), .tv_IntIn(1069547520), .idx(13));
    set_tv(.tv_expBF(16'h3f80), .tv_rd(1), .tv_IntIn(1), .idx(14));
    set_tv(.tv_expBF(16'hbf80), .tv_rd(1), .tv_IntIn(-1), .idx(15));
    set_tv(.tv_expBF(16'h437f), .tv_rd(1), .tv_IntIn(255), .idx(16));
    set_tv(.tv_expBF(16'hc37f), .tv_rd(1), .tv_IntIn(-255), .idx(17));
    set_tv(.tv_expBF(16'hc380), .tv_rd(1), .tv_IntIn(-256), .idx(18));
    set_tv(.tv_expBF(16'h4380), .tv_rd(1), .tv_IntIn(257), .idx(19));
    set_tv(.tv_expBF(16'h4400), .tv_rd(1), .tv_IntIn(511), .idx(20));
    set_tv(.tv_expBF(16'h4400), .tv_rd(1), .tv_IntIn(512), .idx(21));
    set_tv(.tv_expBF(16'h4400), .tv_rd(1), .tv_IntIn(513), .idx(22));
    set_tv(.tv_expBF(16'h4480), .tv_rd(1), .tv_IntIn(1023), .idx(23));
    set_tv(.tv_expBF(16'h4480), .tv_rd(1), .tv_IntIn(1024), .idx(24));
    set_tv(.tv_expBF(16'h4480), .tv_rd(1), .tv_IntIn(1025), .idx(25));
    set_tv(.tv_expBF(16'hcf00), .tv_rd(1), .tv_IntIn(-2147483647), .idx(26));
    set_tv(.tv_expBF(16'h4580), .tv_rd(1), .tv_IntIn(4112), .idx(27));
    set_tv(.tv_expBF(16'h4581), .tv_rd(1), .tv_IntIn(4113), .idx(28));
    set_tv(.tv_expBF(16'h4582), .tv_rd(1), .tv_IntIn(4144), .idx(29));
    set_tv(.tv_expBF(16'hc580), .tv_rd(1), .tv_IntIn(-4112), .idx(30));
    set_tv(.tv_expBF(16'hc581), .tv_rd(1), .tv_IntIn(-4113), .idx(31));
    set_tv(.tv_expBF(16'h4600), .tv_rd(1), .tv_IntIn(8176), .idx(32));
    set_tv(.tv_expBF(16'hc600), .tv_rd(1), .tv_IntIn(-8176), .idx(33));
    set_tv(.tv_expBF(16'h4981), .tv_rd(1), .tv_IntIn(1052673), .idx(34));



    for(i = 0; i < 35; i++) begin
        int_bfif.inputInt = testVec[i].IntIn;
        int_bfif.rdIn = testVec[i].rd;
        int_bfif.ready_out = 1;
        int_bfif.valid_in = 1;
        #(PERIOD);
        int_bfif.ready_out = 0;
        int_bfif.valid_in = 0;
        f32_bits = {int_bfif.outputBF, 16'h0000};
        sr = $bitstoshortreal(f32_bits);
        $display("INT32 IN: %d, BF16 OUT: %f", $signed(testVec[i].IntIn), sr);
        if(int_bfif.outputBF != testVec[i].expBF) begin
            $display("INCORRECT OUTPUT\n");
        end
    end
    $display("DONE");
    $finish;
end

endmodule