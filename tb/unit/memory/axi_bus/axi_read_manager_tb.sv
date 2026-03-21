/*  
    Xinyu Liu - liuxinyujames@gmail.com
*/
`timescale 1ps/1ps
`include "axi_bus_pkg.sv"

import axi_bus_pkg::*;

module axi_read_manager_tb ();

    localparam CLK_PERIOD = 10ns;

    logic CLK, nRST;
    
    logic                 arvalid;
    master_ar_channel_t   master_in;
    logic                 arready;
    logic                 pop;
    sub_ar_channel_t      manager_out;
    logic                 req;

    axi_read_manager #(
        .MASTER_ID(3)
    ) DUT (
        .CLK(CLK),
        .nRST(nRST),
        .arready(arready),
        .master_in(master_in),
        .arvalid(arvalid),
        .pop(pop),
        .manager_out(manager_out),
        .req(req)
    );

    // clock gen 
    always begin
        CLK = 0;
        #(CLK_PERIOD/2);
        CLK = 1;
        #(CLK_PERIOD/2);
    end

    test PROG (
        .CLK(CLK),
        .nRST(nRST),
        .arready(arready),
        .master_in(master_in),
        .arvalid(arvalid),
        .pop(pop),
        .manager_out(manager_out),
        .req(req)
    );

    

endmodule

program test (
    input logic CLK,
    output logic                 nRST,
    // From Master
    output logic                 arvalid, // master ready to send read request
    output master_ar_channel_t   master_in,
    // To Master
    input logic                arready, // manager valid to take signal
    // From Read Controller
    output  logic                pop, // AR channel ready to take 
    // To Read Mux
    input sub_ar_channel_t     manager_out,
    input logic req
);
    string test_case = "";
    task reset_dut;
    begin
        nRST = 0;
        repeat (3) @(negedge CLK);
        nRST = 1;
        repeat (3) @(negedge CLK);
    end
    endtask

    task reset_inputs;
    begin 
        arvalid = 0;
        master_in = '0;
        pop = 0;

        repeat (3) @(negedge CLK);
    end 
    endtask
    // assertion learn
    task check_output(
        sub_ar_channel_t exp_manager_out,
        logic exp_req
    );
        if (exp_manager_out != manager_out || exp_req != req) begin
            $display("FAIL: %s", test_case);

            if (exp_manager_out.valid != manager_out.valid) $display("VALID exp: %d, output: %d ", exp_manager_out.valid, manager_out.valid);
            if (exp_manager_out.addr  != manager_out.addr)  $display("ADDR exp: %h, output: %h " , exp_manager_out.addr , manager_out.addr);
            if (exp_manager_out.id != manager_out.id) $display("ID exp: %h, output: %h ", exp_manager_out.id, manager_out.id);
            if (exp_manager_out.mid != manager_out.mid) $display("MID exp: %h, output: %h ", exp_manager_out.mid, manager_out.mid);
            if (exp_manager_out.size != manager_out.size) $display("SIZE exp: %h, output: %h ", exp_manager_out.size, manager_out.size);
            if (exp_manager_out.len != manager_out.len) $display("LEN exp: %h, output: %h ", exp_manager_out.len, manager_out.len);
            if (exp_manager_out.burst != manager_out.burst) $display("BURST exp: %h, output: %h ", exp_manager_out.burst, manager_out.burst);
            if (exp_req != req) $display("REQ exp: %h, output: %h ", exp_req, req);
        end else begin
            $display("PASS: %s", test_case);
        end
    endtask

    // TEST CASE 1: Fill and Pop (1 payload)
    task fill_pop_one;
    begin 
        test_case = "Push Pop one";

        reset_inputs();
        repeat (3) @(negedge CLK);
        // master ready
        arvalid = 1;
        // fill master_in
        master_in.id    = 2'h2;
        master_in.addr  = 32'hDEADBEEF;
        master_in.size  = 3'b011;
        master_in.len   = 3'b111;
        master_in.burst = 3'b01;
        repeat (1) @(negedge CLK);
        reset_inputs;
        
        pop = 1;
        check_output('{
            valid: 1'h1,
            addr: 32'hDEADBEEF,
            id: 2'h2,
            mid: 2'h3,
            size: 3'h3,
            len: 3'h7,
            burst: 3'h1
        }, 1);
        @(negedge CLK);
        pop = 0; 
        repeat (3) @(negedge CLK);
    end
    endtask

    task fill_pop_three;
    begin
        test_case = "Push Pop three";
        arvalid = 1;

        // first master_in
        master_in.id    = 2'h1;
        master_in.addr  = 32'hBBBB_BBBB;
        master_in.size  = 3'b011;
        master_in.len   = 3'b111;
        master_in.burst = 3'b01;
        @(negedge CLK);

        // second master_in
        master_in.id    = 2'h2;
        master_in.addr  = 32'hCCCC_CCCC;
        master_in.size  = 3'b011;
        master_in.len   = 3'b111;
        master_in.burst = 3'b01;
        @(negedge CLK);

        // third master_in
        master_in.id    = 2'h3;
        master_in.addr  = 32'hDDDD_DDDD;
        master_in.size  = 3'b011;
        master_in.len   = 3'b111;
        master_in.burst = 3'b01;
        @(negedge CLK);

        reset_inputs;

        pop=1;
        test_case = "Push Pop three .1";
        check_output('{
            valid: 1'h1,
            addr: 32'hBBBB_BBBB,
            id: 2'h1,
            mid: 2'h3,
            size: 3'h3,
            len: 3'h7,
            burst: 3'h1
        }, 1);
        @(negedge CLK);

        test_case = "Push Pop three .2";
        check_output('{
            valid: 1'h1,
            addr: 32'hCCCC_CCCC,
            id: 2'h2,
            mid: 2'h3,
            size: 3'h3,
            len: 3'h7,
            burst: 3'h1
        }, 1);
        @(negedge CLK);

        test_case = "Push Pop three .3";
        check_output('{
            valid: 1'h1,
            addr: 32'hDDDD_DDDD,
            id: 2'h3,
            mid: 2'h3,
            size: 3'h3,
            len: 3'h7,
            burst: 3'h1
        }, 1);
        @(negedge CLK);
        pop=0;
        reset_inputs;
        repeat (3) @(negedge CLK);
    end
    endtask

    task endless_push;
    begin
        reset_dut;
        reset_inputs;

        arvalid = 1;
        // first master_in
        master_in.id    = 2'h1;
        master_in.addr  = 32'h1111_1111;
        master_in.size  = 3'b011;
        master_in.len   = 3'b111;
        master_in.burst = 3'b01;
        @(negedge CLK);

        // second master_in
        master_in.id    = 2'h2;
        master_in.addr  = 32'h2222_2222;
        master_in.size  = 3'b011;
        master_in.len   = 3'b111;
        master_in.burst = 3'b01;
        @(negedge CLK);

        // third master_in
        master_in.id    = 2'h3;
        master_in.addr  = 32'h3333_3333;
        master_in.size  = 3'b011;
        master_in.len   = 3'b111;
        master_in.burst = 3'b01;
        @(negedge CLK);

        // forth master_in
        master_in.id    = 2'h0;
        master_in.addr  = 32'h4444_4444;
        master_in.size  = 3'b011;
        master_in.len   = 3'b111;
        master_in.burst = 3'b01;
        @(negedge CLK);

        // fifth master_in
        master_in.id    = 2'h1;
        master_in.addr  = 32'h5555_5555;
        master_in.size  = 3'b011;
        master_in.len   = 3'b111;
        master_in.burst = 3'b01;
        @(negedge CLK);

        // sixth master_in
        master_in.id    = 2'h2;
        master_in.addr  = 32'h6666_6666;
        master_in.size  = 3'b011;
        master_in.len   = 3'b111;
        master_in.burst = 3'b01;
        @(negedge CLK);

        reset_inputs;
        repeat (3) @(negedge CLK);
    end
    endtask

    task push_pop_sametime; // cannot be full or empty, therefore only 1/2 in fifo
    begin
        reset_dut;
        reset_inputs;
        test_case = "Push Pop same time";

        arvalid = 1;
        // first master_in
        master_in.id    = 2'h1;
        master_in.addr  = 32'h1111_1111;
        master_in.size  = 3'b011;
        master_in.len   = 3'b111;
        master_in.burst = 3'b01;
        @(negedge CLK);

        // second master_in
        master_in.id    = 2'h2;
        master_in.addr  = 32'h2222_2222;
        master_in.size  = 3'b011;
        master_in.len   = 3'b111;
        master_in.burst = 3'b01;
        @(negedge CLK);

        // push and pop same time
        master_in.id    = 2'h3;
        master_in.addr  = 32'h3333_3333;
        master_in.size  = 3'b011;
        master_in.len   = 3'b111;
        master_in.burst = 3'b01;
        pop = 1;
        check_output('{
            valid: 1'h1,
            addr: 32'h1111_1111,
            id: 2'h1,
            mid: 2'h3,
            size: 3'h3,
            len: 3'h7,
            burst: 3'h1
        }, 1);
        @(negedge CLK);

        reset_inputs;
    end
    endtask
    

    initial begin 
        reset_dut;
        fill_pop_one;
        fill_pop_three;
        endless_push;
        push_pop_sametime;

        $finish;
    end 

endprogram