`timescale 1ns / 10ps
`include "bf_to_int_if.sv"

module bf_to_int_tb;


    parameter PERIOD = 2;
    parameter TESTCASES = 10;
    logic CLK = 0, nRST;
    logic [31:0] f32_bits;
    shortreal    sr;

    always #(PERIOD/2) CLK++;

    bf_to_int_if bf_intif ();
    bf_to_int DUT (.CLK(CLK), .bf_intif(bf_intif));

    int casenum;
    string casename;
    integer i;

    typedef struct {
        logic [15:0] BFin;
        logic rd;
        logic [31:0] expInt;
    } testVec_struct;

    testVec_struct testVec [80];

    task set_tv;
        input logic [15:0] tv_BFin;
        input logic tv_rd;
        input logic [31:0] tv_expInt;
        input integer idx;
    begin
        testVec[idx].BFin = tv_BFin;
        testVec[idx].rd = tv_rd;
        testVec[idx].expInt = tv_expInt;
    end
    endtask


initial begin
    casenum = '0;
    casename = "nRST";
    bf_intif.inputBF = '0;
    bf_intif.ready_out = '0;
    bf_intif.valid_in = '0;
    bf_intif.rdIn = '0;
    nRST = '0;
    #(PERIOD);
    nRST = 1;
    #(PERIOD);

    set_tv(.tv_BFin(16'h42c8), .tv_rd(1), .tv_expInt(100), .idx(0)); //100
    set_tv(.tv_BFin(16'hc2c8), .tv_rd(1), .tv_expInt(-100), .idx(1)); //-100
    set_tv(.tv_BFin(16'h3fc0), .tv_rd(1), .tv_expInt(2), .idx(2)); //1.5
    set_tv(.tv_BFin(16'h3f80), .tv_rd(1), .tv_expInt(1), .idx(3)); //1
    set_tv(.tv_BFin(16'h3f00), .tv_rd(1), .tv_expInt(1), .idx(4)); //0.5
    set_tv(.tv_BFin(16'hbfc0), .tv_rd(1), .tv_expInt(-2), .idx(5)); //-1.5
    set_tv(.tv_BFin(16'hbf80), .tv_rd(1), .tv_expInt(-1), .idx(6)); //-1
    set_tv(.tv_BFin(16'hbf00), .tv_rd(1), .tv_expInt(-1), .idx(7)); //-0.5
    set_tv(.tv_BFin(16'h0000), .tv_rd(1), .tv_expInt(0), .idx(8)); //0
    set_tv(.tv_BFin(16'h3f19), .tv_rd(1), .tv_expInt(1), .idx(9)); //0.57
    set_tv(.tv_BFin(16'h3eff), .tv_rd(1), .tv_expInt(0), .idx(10)); //0.49
    set_tv(.tv_BFin(16'h4e93), .tv_rd(1), .tv_expInt(1233125376), .idx(11)); //1234812312
    set_tv(.tv_BFin(16'h5512), .tv_rd(1), .tv_expInt(32'sh7FFF_FFFF), .idx(11)); //OVERFLOW
    set_tv(.tv_BFin(16'h7f80), .tv_rd(1), .tv_expInt(32'sh7FFF_FFFF), .idx(12)); //Infinity (should saturate)
    set_tv(.tv_BFin(16'hff80), .tv_rd(1), .tv_expInt(32'sh8000_0000), .idx(13)); //Neg Infinity (should saturate)
    set_tv(.tv_BFin(16'hd369), .tv_rd(1), .tv_expInt(32'sh8000_0000), .idx(14)); //Neg OVERFLOW
    set_tv(.tv_BFin(16'h7F80), .tv_rd(1), .tv_expInt(32'sh7FFF_FFFF), .idx(15));
    set_tv(.tv_BFin(16'hFF80), .tv_rd(1), .tv_expInt(32'sh8000_0000), .idx(16));
    set_tv(.tv_BFin(16'h7FC1), .tv_rd(1), .tv_expInt(32'sh7FFF_FFFF), .idx(17));
    set_tv(.tv_BFin(16'hFFC1), .tv_rd(1), .tv_expInt(32'sh8000_0000), .idx(18));
    set_tv(.tv_BFin(16'h8000), .tv_rd(1), .tv_expInt(32'h0), .idx(19));
    set_tv(.tv_BFin(16'h0001), .tv_rd(1), .tv_expInt(32'h0), .idx(20));
    set_tv(.tv_BFin(16'h007F), .tv_rd(1), .tv_expInt(32'h0), .idx(21));
    set_tv(.tv_BFin(16'h8001), .tv_rd(1), .tv_expInt(32'h0), .idx(22));
    set_tv(.tv_BFin(16'h807F), .tv_rd(1), .tv_expInt(32'h0), .idx(23));
    set_tv(.tv_BFin(16'h3F00), .tv_rd(1), .tv_expInt(32'd1), .idx(24));
    set_tv(.tv_BFin(16'h3F40), .tv_rd(1), .tv_expInt(32'd1), .idx(25));
    set_tv(.tv_BFin(16'hBF00), .tv_rd(1), .tv_expInt(-1), .idx(26));
    set_tv(.tv_BFin(16'hBF40), .tv_rd(1), .tv_expInt(-1), .idx(27));
    set_tv(.tv_BFin(16'h3F7F), .tv_rd(1), .tv_expInt(1), .idx(28));
    set_tv(.tv_BFin(16'h3F80), .tv_rd(1), .tv_expInt(1), .idx(29));
    set_tv(.tv_BFin(16'h4000), .tv_rd(1), .tv_expInt(2), .idx(30));
    set_tv(.tv_BFin(16'h4040), .tv_rd(1), .tv_expInt(3), .idx(31));
    set_tv(.tv_BFin(16'h40A0), .tv_rd(1), .tv_expInt(5), .idx(32));
    set_tv(.tv_BFin(16'h4380), .tv_rd(1), .tv_expInt(256), .idx(33));
    set_tv(.tv_BFin(16'h43C0), .tv_rd(1), .tv_expInt(384), .idx(34));
    set_tv(.tv_BFin(16'h4400), .tv_rd(1), .tv_expInt(512), .idx(35));
    set_tv(.tv_BFin(16'h4480), .tv_rd(1), .tv_expInt(1024), .idx(36));
    set_tv(.tv_BFin(16'hC480), .tv_rd(1), .tv_expInt(-1024), .idx(37));
    set_tv(.tv_BFin(16'hC3C0), .tv_rd(1), .tv_expInt(-384), .idx(38));
    set_tv(.tv_BFin(16'h4F00), .tv_rd(1), .tv_expInt(2147483647), .idx(39));
    set_tv(.tv_BFin(16'h4F7F), .tv_rd(1), .tv_expInt(2147483647), .idx(40));
    set_tv(.tv_BFin(16'hCF00), .tv_rd(1), .tv_expInt(-2147483648), .idx(41));
    set_tv(.tv_BFin(16'hCF7F), .tv_rd(1), .tv_expInt(-2147483648), .idx(42));
    set_tv(.tv_BFin(16'h4f00), .tv_rd(1), .tv_expInt(2147483647), .idx(43));
    set_tv(.tv_BFin(16'h3FFF), .tv_rd(1), .tv_expInt(2), .idx(44));
    set_tv(.tv_BFin(16'h407F), .tv_rd(1), .tv_expInt(4), .idx(45));
    set_tv(.tv_BFin(16'h41FF), .tv_rd(1), .tv_expInt(32), .idx(46));
    set_tv(.tv_BFin(16'hC1FF), .tv_rd(1), .tv_expInt(-32), .idx(47));
    set_tv(.tv_BFin(16'h4100), .tv_rd(1), .tv_expInt(8), .idx(48));
    set_tv(.tv_BFin(16'h4180), .tv_rd(1), .tv_expInt(16), .idx(49));
    set_tv(.tv_BFin(16'h41C0), .tv_rd(1), .tv_expInt(24), .idx(50));
    set_tv(.tv_BFin(16'h4220), .tv_rd(1), .tv_expInt(40), .idx(51));
    set_tv(.tv_BFin(16'h42F0), .tv_rd(1), .tv_expInt(120), .idx(52));
    set_tv(.tv_BFin(16'h4980), .tv_rd(1), .tv_expInt(1048576), .idx(53));
    set_tv(.tv_BFin(16'h4A40), .tv_rd(1), .tv_expInt(3145728), .idx(54));
    set_tv(.tv_BFin(16'h4B00), .tv_rd(1), .tv_expInt(8388608), .idx(55));
    set_tv(.tv_BFin(16'h4E80), .tv_rd(1), .tv_expInt(1073741824), .idx(56));
    set_tv(.tv_BFin(16'h4F00), .tv_rd(1), .tv_expInt(2147483647), .idx(57));
    set_tv(.tv_BFin(16'h4F7F), .tv_rd(1), .tv_expInt(2147483647), .idx(58));
    set_tv(.tv_BFin(16'hCE80), .tv_rd(1), .tv_expInt(-1073741824), .idx(59));
    set_tv(.tv_BFin(16'hCF00), .tv_rd(1), .tv_expInt(-2147483648), .idx(60));
    set_tv(.tv_BFin(16'h5E00), .tv_rd(1), .tv_expInt(2147483647), .idx(61));
    set_tv(.tv_BFin(16'h5F00), .tv_rd(1), .tv_expInt(2147483647), .idx(62));
    set_tv(.tv_BFin(16'h5FFF), .tv_rd(1), .tv_expInt(2147483647), .idx(63));
    set_tv(.tv_BFin(16'hDE00), .tv_rd(1), .tv_expInt(-2147483648), .idx(64));
    set_tv(.tv_BFin(16'hDFFF), .tv_rd(1), .tv_expInt(-2147483648), .idx(65));
    set_tv(.tv_BFin(16'h4fff), .tv_rd(1), .tv_expInt(2147483647), .idx(66));
    set_tv(.tv_BFin(16'h53ff), .tv_rd(1), .tv_expInt(2147483647), .idx(67));
    set_tv(.tv_BFin(16'h4e7c), .tv_rd(1), .tv_expInt(1056964608), .idx(68));
    set_tv(.tv_BFin(16'h48ff), .tv_rd(1), .tv_expInt(522240), .idx(69));
    set_tv(.tv_BFin(16'h4a00), .tv_rd(1), .tv_expInt(2097152), .idx(70));
    set_tv(.tv_BFin(16'h4a80), .tv_rd(1), .tv_expInt(4194304), .idx(71));
    set_tv(.tv_BFin(16'h4900), .tv_rd(1), .tv_expInt(524288), .idx(72));
    set_tv(.tv_BFin(16'hcec0), .tv_rd(1), .tv_expInt(-1610612736), .idx(73));
    set_tv(.tv_BFin(16'h5bff), .tv_rd(1), .tv_expInt(2147483647), .idx(74));
    set_tv(.tv_BFin(16'h57ff), .tv_rd(1), .tv_expInt(2147483647), .idx(75));
    set_tv(.tv_BFin(16'h47ff), .tv_rd(1), .tv_expInt(130560), .idx(76));

    for(i = 0; i < 77; i++) begin
        bf_intif.inputBF = testVec[i].BFin;
        bf_intif.rdIn = testVec[i].rd;
        bf_intif.ready_out = 1;
        bf_intif.valid_in = 1;
        #(PERIOD);
        bf_intif.ready_out = 0;
        bf_intif.valid_in = 0;
        f32_bits = {testVec[i].BFin, 16'h0000};
        sr = $bitstoshortreal(f32_bits);
        $display("BF16 in: %f, INT32 out: %d", sr, $signed(bf_intif.outputInt));
        if(bf_intif.outputInt != testVec[i].expInt) begin
            $display("INCORRECT OUTPUT at %d\n", i);
        end
    end
    $display("DONE");
    $finish;
end

endmodule