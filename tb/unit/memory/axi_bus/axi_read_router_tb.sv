`timescale 1ps/1ps

import axi_bus_pkg::*;
module axi_read_router_tb;
    import axi_bus_pkg::*;

    parameter PERIOD = 10;

    logic CLK=0, nRST;
    always #(PERIOD/2) CLK++;

    axi_bus_if rif ();
    axi_read_router DUT (CLK, nRST, rif);

// `ifndef MAPPED
//     axi_read_router DUT (CLK, nRST, rif);
// `else
//     axi_read_router DUT (
//         .CLK (CLK),
//         .nRST (nRST),
//         .\rif\.r_sp0_o_ready (rif.r_sp0_o_ready),
//         .\rif\.r_sp1_o_ready (rif.r_sp1_o_ready),
//         .\rif\.r_i_o_ready (rif.r_i_o_ready),
//         .\rif\.r_d_o_ready (rif.r_d_o_ready),
//         // From Controller
//         .\rif\.r_valid (rif.r_valid),
//         .\rif\.r_i (rif.r_i),
//         // To Master
//         .\rif\.r_sp0_o (rif.r_sp0_o),
//         .\rif\.r_sp1_o (rif.r_sp1_o),
//         .\rif\.r_i_o (rif.r_i_o),
//         .\rif\.r_d_o (rif.r_d_o),
//         .\rif\.r_sp0_o_valid (rif.r_sp0_o_valid),
//         .\rif\.r_sp1_o_valid (rif.r_sp1_o_valid),
//         .\rif\.r_i_o_valid (rif.r_i_o_valid),
//         .\rif\.r_d_o_valid (rif.r_d_o_valid),
//         // To Controller
//         .\rif\.r_ready (rif.r_ready)
//     );
// `endif

    test PROG (
        .CLK (CLK),
        .nRST (nRST),
        .r_sp0_o_ready (rif.r_sp0_o_ready),
        .r_sp1_o_ready (rif.r_sp1_o_ready),
        .r_i_o_ready (rif.r_i_o_ready),
        .r_d_o_ready (rif.r_d_o_ready),
        // From Controller
        .r_valid (rif.r_valid),
        .r_i (rif.r_i),
        // To Master
        .r_sp0_o (rif.r_sp0_o),
        .r_sp1_o (rif.r_sp1_o),
        .r_i_o (rif.r_i_o),
        .r_d_o (rif.r_d_o),
        .r_sp0_o_valid (rif.r_sp0_o_valid),
        .r_sp1_o_valid (rif.r_sp1_o_valid),
        .r_i_o_valid (rif.r_i_o_valid),
        .r_d_o_valid (rif.r_d_o_valid),
        // To Controller
        .r_ready (rif.r_ready)
    );

endmodule

program test (
    input logic CLK,
    input master_r_channel_t r_sp0_o, r_sp1_o, r_i_o, r_d_o,
    input logic r_sp0_o_valid, r_sp1_o_valid, r_i_o_valid, r_d_o_valid,
    input logic r_ready,

    output logic nRST,
    output logic r_sp0_o_ready, r_sp1_o_ready, r_i_o_ready, r_d_o_ready,
    output sub_r_channel_t r_i,
    output logic r_valid
    
);

    parameter I_MID = 0;
    parameter D_MID = 1;
    parameter SP0_MID = 2;
    parameter SP1_MID = 3;

    string test_case = "";

    task reset_dut;
        nRST = 0;
        repeat (3) @(negedge CLK);
        nRST = 1;
        repeat (3) @(negedge CLK);
    endtask

    task reset_input;
        r_sp0_o_ready = 0;
        r_sp1_o_ready = 0;
        r_d_o_ready = 0;
        r_i_o_ready = 0;
        r_valid = 0;
        r_i = '0;
        @(negedge CLK);
    endtask

    

    task pass_through;
    begin
        reset_dut;
        reset_input;
        // i$ pass through
        test_case = "I$ Pass Through";
        r_i.mid = I_MID;
        r_i.data = 64'h1111_1111_1111_1111;
        r_i.id = 0;
        r_i.last = 1;
        r_i.resp = R_OKAY;

        r_valid = 1;
        r_i_o_ready = 1;
        @(negedge CLK);

        // D$ pass through
        reset_input;
        test_case = "D$ Pass Through";
        r_i.mid = D_MID;
        r_i.data = 64'h2222_2222_2222_2222;
        r_i.id = 1;
        r_i.last = 1;
        r_i.resp = R_OKAY;

        r_valid = 1;
        r_d_o_ready = 1;
        @(negedge CLK);

        // SP0 pass through
        reset_input;
        test_case = "SP0 Pass Through";
        r_i.mid = SP0_MID;
        r_i.data = 64'h3333_3333_3333_3333;
        r_i.id = 2;
        r_i.last = 1;
        r_i.resp = R_OKAY;

        r_valid = 1;
        r_sp0_o_ready = 1;
        @(negedge CLK);

        // SP1 pass through
        reset_input;
        test_case = "D$ Pass Through";
        r_i.mid = D_MID;
        r_i.data = 64'h4444_4444_4444_4444;
        r_i.id = 3;
        r_i.last = 1;
        r_i.resp = R_OKAY;

        r_valid = 1;
        r_sp1_o_ready = 1;
        @(negedge CLK);

    end
    endtask  

    task master_not_ready;
    begin
        reset_dut;
        reset_input;

        test_case = "I$ Two Response";
        r_i.mid = I_MID;
        r_i.data = 64'h1111_1111_1111_1111;
        r_i.id = 0;
        r_i.last = 0;
        r_i.resp = R_OKAY;

        r_valid = 1;
        // r_i_o_ready = 1;
        @(negedge CLK);

        r_i.mid = I_MID;
        r_i.data = 64'h2222_2222_2222_2222;
        r_i.id = 0;
        r_i.last = 1;
        r_i.resp = R_OKAY;

        r_valid = 1;
        // r_i_o_ready = 1;
        repeat (3) @(negedge CLK); // check r_ready

        r_i_o_ready = 1;
        repeat (1) @(negedge CLK); // two posedge will be experienced

        // D& two Response
        reset_input;
        test_case = "D$ Two Response";
        r_i.mid = D_MID;
        r_i.data = 64'h3333_3333_3333_3333;
        r_i.id = 1;
        r_i.last = 0;
        r_i.resp = R_OKAY;

        r_valid = 1;
        // r_i_o_ready = 1;
        @(negedge CLK);

        r_i.mid = D_MID;
        r_i.data = 64'h4444_4444_4444_4444;
        r_i.id = 1;
        r_i.last = 1;
        r_i.resp = R_OKAY;

        r_valid = 1;
        repeat (3) @(negedge CLK); // check r_ready

        r_d_o_ready = 1;
        repeat (1) @(negedge CLK); // two posedge will be experienced

        // SP0 two Response
        reset_input;
        test_case = "SP0 Two Response";
        r_i.mid = SP0_MID;
        r_i.data = 64'h5555_5555_5555_5555;
        r_i.id = 2;
        r_i.last = 0;
        r_i.resp = R_OKAY;

        r_valid = 1;
        // r_i_o_ready = 1;
        @(negedge CLK);

        r_i.mid = SP0_MID;
        r_i.data = 64'h6666_6666_6666_6666;
        r_i.id = 2;
        r_i.last = 1;
        r_i.resp = R_OKAY;

        r_valid = 1;
        repeat (3) @(negedge CLK); // check r_ready

        r_sp0_o_ready = 1;
        repeat (1) @(negedge CLK); // two posedge will be experienced

        // SP1 two Response
        reset_input;
        test_case = "SP1 Two Response";
        r_i.mid = SP1_MID;
        r_i.data = 64'h7777_7777_7777_7777;
        r_i.id = 3;
        r_i.last = 0;
        r_i.resp = R_OKAY;

        r_valid = 1;
        // r_i_o_ready = 1;
        @(negedge CLK);

        r_i.mid = SP1_MID;
        r_i.data = 64'h6666_6666_6666_6666;
        r_i.id = 3;
        r_i.last = 1;
        r_i.resp = R_OKAY;

        r_valid = 1;
        repeat (3) @(negedge CLK); // check r_ready

        r_sp1_o_ready = 1;
        repeat (1) @(negedge CLK); // two posedge will be experienced

    end
    endtask

    initial begin

        pass_through;

        master_not_ready;

        $finish;
    end


endprogram


