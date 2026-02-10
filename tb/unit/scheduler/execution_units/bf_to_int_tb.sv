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
    bf_to_int DUT (.CLK(CLK), .nRST(nRST), .bf_intif(bf_intif));

    int casenum;
    string casename;
    integer i;

    typedef struct {
        logic [15:0] BFin;
        logic rd;
        logic [31:0] expInt;
    } testVec_struct;

    testVec_struct testVec [20];

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

    for(i = 0; i < 15; i++) begin
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
            $display("INCORRECT OUTPUT\n");
        end
    end
    $display("DONE");
    $finish;
end

endmodule