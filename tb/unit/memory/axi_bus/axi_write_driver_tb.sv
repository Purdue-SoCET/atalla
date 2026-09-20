/*  Aryan Kadakia - kadakia0@purdue.edu */

`timescale 1ps/1ps
`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;
module axi_write_driver_tb ();
    parameter CLK_PERIOD = 10;

    logic CLK = 0, nRST;

    // clock
    always #(CLK_PERIOD/2) CLK++;

    // interface 
    axi_bus_if busif(.CLK(CLK), .nRST(nRST));

    // DUT
    axi_write_driver DUT (
        .CLK     (CLK),
        .nRST    (nRST),
        .wdrv_if (busif)
    );

    // test program
    test PROG (
        .CLK     (CLK),
        .nRST    (nRST),
        .wdrv_if (busif)
    );

endmodule

program test (
    input logic CLK,
    output logic nRST,
    axi_bus_if.write_driver_tb wdrv_if
);

    parameter CLK_PERIOD = 10;
    string test_case;
    int sp0_w_idx, sp1_w_idx, d_w_idx;
    int sp0_w_left, sp1_w_left, d_w_left;

    task reset_dut;
    begin
        nRST = 0;
        @(posedge CLK);
        @(posedge CLK);
        nRST = 1;
        @(posedge CLK);
        @(posedge CLK);
    end
    endtask

    task reset_inputs;
    begin 
        wdrv_if.aw_grant = '0;
        wdrv_if.head_sp0_awvalid = '0;
        wdrv_if.head_sp0_aw_o = '0;
        wdrv_if.head_sp0_wvalid = '0;
        wdrv_if.head_sp0_w_o = '0;
        wdrv_if.head_sp1_awvalid = '0;
        wdrv_if.head_sp1_aw_o = '0;
        wdrv_if.head_sp1_wvalid = '0;
        wdrv_if.head_sp1_w_o = '0;
        wdrv_if.head_d_awvalid = '0;
        wdrv_if.head_d_aw_o = '0;
        wdrv_if.head_d_wvalid = '0;
        wdrv_if.head_d_w_o = '0;
        wdrv_if.aw_o_ready = '0;
        wdrv_if.w_o_ready = '0;

        sp0_w_idx  = 0;
        sp1_w_idx  = 0;
        d_w_idx    = 0;
        sp0_w_left = 0;
        sp1_w_left = 0;
        d_w_left   = 0;
    end 
    endtask

    task set_sp0_aw;
        wdrv_if.head_sp0_awvalid = 1;
        wdrv_if.head_sp0_aw_o.addr = 32'hDEADBEEF;
        wdrv_if.head_sp0_aw_o.mid_id = 4'b0010;
        wdrv_if.head_sp0_aw_o.size = 3'b011;
        wdrv_if.head_sp0_aw_o.len = 4'h7;
        wdrv_if.head_sp0_aw_o.burst = 2'b01;
    endtask

    task set_sp0_w;
        sp0_w_idx  = 0;
        sp0_w_left = 8;
        wdrv_if.head_sp0_wvalid = 1;
        wdrv_if.head_sp0_w_o.data = 64'hAAAABBBBCCCCDDD0;
        wdrv_if.head_sp0_w_o.mid_id = 4'b0010;
        wdrv_if.head_sp0_w_o.last = 0;
        wdrv_if.head_sp0_w_o.strb = '0;
    endtask
        
    task set_sp1_aw;
        wdrv_if.head_sp1_awvalid = 1;
        wdrv_if.head_sp1_aw_o.addr = 32'hBEEFBEEF;
        wdrv_if.head_sp1_aw_o.mid_id = 4'b0101;
        wdrv_if.head_sp1_aw_o.size = 3'b011;
        wdrv_if.head_sp1_aw_o.len = 4'h7;
        wdrv_if.head_sp1_aw_o.burst = 2'b01;
    endtask

    task set_sp1_w;
        sp1_w_idx  = 0;
        sp1_w_left = 8;
        wdrv_if.head_sp1_wvalid = 1;
        wdrv_if.head_sp1_w_o.data = 64'hDDDDCCCCBBBBAAA0;
        wdrv_if.head_sp1_w_o.mid_id = 4'b0101;
        wdrv_if.head_sp1_w_o.last = 0;
        wdrv_if.head_sp1_w_o.strb = '0;
    endtask

    task set_dcache_aw;
        wdrv_if.head_d_awvalid = 1;
        wdrv_if.head_d_aw_o.addr = 32'hBEEFDEAD;
        wdrv_if.head_d_aw_o.mid_id = 4'b1011;
        wdrv_if.head_d_aw_o.size = 3'b011;
        wdrv_if.head_d_aw_o.len = 4'h7;
        wdrv_if.head_d_aw_o.burst = 2'b01;
    endtask

    task set_dcache_w;
        d_w_idx  = 0;
        d_w_left = 8;
        wdrv_if.head_d_wvalid = 1;
        wdrv_if.head_d_w_o.data = 64'hFFFFFFFFFFFFFFF0;
        wdrv_if.head_d_w_o.mid_id = 4'b1011;
        wdrv_if.head_d_w_o.last = 0;
        wdrv_if.head_d_w_o.strb = '0;
    endtask

    initial begin
        int next_idx;
        int next_left;

        forever begin
            @(posedge CLK or negedge nRST);
            if (!nRST) begin
                sp0_w_idx  = 0;
                sp1_w_idx  = 0;
                d_w_idx    = 0;
                sp0_w_left = 0;
                sp1_w_left = 0;
                d_w_left   = 0;
            end
            else begin
                // ---------------- SP0 ----------------
                if (wdrv_if.w_sp0_pop && (sp0_w_left > 0)) begin
                    next_idx  = sp0_w_idx + 1;
                    next_left = sp0_w_left - 1;

                    sp0_w_idx  = next_idx;
                    sp0_w_left = next_left;

                    if (next_left == 0) begin
                        wdrv_if.head_sp0_wvalid = 0;
                        wdrv_if.head_sp0_w_o    = '0;
                    end
                    else begin
                        wdrv_if.head_sp0_wvalid     = 1;
                        wdrv_if.head_sp0_w_o.data   = 64'hAAAABBBBCCCCDDD0 + next_idx;
                        wdrv_if.head_sp0_w_o.mid_id = 4'b0010;
                        wdrv_if.head_sp0_w_o.last   = (next_idx == 7);
                        wdrv_if.head_sp0_w_o.strb   = '0;
                    end
                end

                // ---------------- SP1 ----------------
                if (wdrv_if.w_sp1_pop && (sp1_w_left > 0)) begin
                    next_idx  = sp1_w_idx + 1;
                    next_left = sp1_w_left - 1;

                    sp1_w_idx  = next_idx;
                    sp1_w_left = next_left;

                    if (next_left == 0) begin
                        wdrv_if.head_sp1_wvalid = 0;
                        wdrv_if.head_sp1_w_o    = '0;
                    end
                    else begin
                        wdrv_if.head_sp1_wvalid     = 1;
                        wdrv_if.head_sp1_w_o.data   = 64'hDDDDCCCCBBBBAAA0 + next_idx;
                        wdrv_if.head_sp1_w_o.mid_id = 4'b0101;
                        wdrv_if.head_sp1_w_o.last   = (next_idx == 7);
                        wdrv_if.head_sp1_w_o.strb   = '0;
                    end
                end

                // ---------------- D$ ----------------
                if (wdrv_if.w_d_pop && (d_w_left > 0)) begin
                    next_idx  = d_w_idx + 1;
                    next_left = d_w_left - 1;

                    d_w_idx  = next_idx;
                    d_w_left = next_left;

                    if (next_left == 0) begin
                        wdrv_if.head_d_wvalid = 0;
                        wdrv_if.head_d_w_o    = '0;
                    end
                    else begin
                        wdrv_if.head_d_wvalid     = 1;
                        wdrv_if.head_d_w_o.data   = 64'hFFFFFFFFFFFFFFF0 + next_idx;
                        wdrv_if.head_d_w_o.mid_id = 4'b1011;
                        wdrv_if.head_d_w_o.last   = (next_idx == 7);
                        wdrv_if.head_d_w_o.strb   = '0;
                    end
                end
            end
        end
    end


    // TEST CASE 1: RESET INIT STATE
    task reset_init_state;
    begin 
        test_case = "TEST CASE 1: RESET INIT STATE";
        reset_inputs();
        reset_dut();
    end 
    endtask
    
    // TEST CASE 2: SEND SP0 REQUEST
    task send_sp0;
    begin 
        test_case = "TEST CASE 2: SEND SP0 REQUEST";
        reset_inputs();
        reset_dut();
        #(CLK_PERIOD*2);
        wdrv_if.aw_o_ready = 1;
        wdrv_if.w_o_ready = 1;
        set_sp0_aw();
        set_sp0_w();
        set_sp1_aw();
        set_sp1_w();
        set_dcache_aw();
        set_dcache_w();
        #(CLK_PERIOD);
        wdrv_if.aw_grant = 3'b100;
        #(CLK_PERIOD*3);
        wdrv_if.w_o_ready = 0;
        #(CLK_PERIOD*3)
        wdrv_if.w_o_ready = 1;
        #(CLK_PERIOD*12);
        reset_inputs();
        #(CLK_PERIOD);
    end
    endtask

    // TEST CASE 3: SEND SP1 REQUEST
    task send_sp1;
    begin 
        test_case = "TEST CASE 3: SEND SP1 REQUEST";
        reset_inputs();
        reset_dut();
        #(CLK_PERIOD*2);
        wdrv_if.aw_o_ready = 1;
        wdrv_if.w_o_ready = 1;
        set_sp0_aw();
        set_sp0_w();
        set_sp1_aw();
        set_sp1_w();
        set_dcache_aw();
        set_dcache_w();
        #(CLK_PERIOD);
        wdrv_if.aw_grant = 3'b101;
        #(CLK_PERIOD*3);
        wdrv_if.w_o_ready = 0;
        #(CLK_PERIOD*3)
        wdrv_if.w_o_ready = 1;
        #(CLK_PERIOD*12);
        reset_inputs();
        #(CLK_PERIOD);
    end
    endtask

    // TEST CASE 4: SEND D$ REQUEST
    task send_dcache;
    begin 
        test_case = "TEST CASE 4: SEND D$ REQUEST";
        reset_inputs();
        reset_dut();
        #(CLK_PERIOD*2);
        wdrv_if.aw_o_ready = 1;
        wdrv_if.w_o_ready = 1;
        set_sp0_aw();
        set_sp0_w();
        set_sp1_aw();
        set_sp1_w();
        set_dcache_aw();
        set_dcache_w();
        #(CLK_PERIOD);
        wdrv_if.aw_grant = 3'b110;
        #(CLK_PERIOD*3);
        wdrv_if.w_o_ready = 0;
        #(CLK_PERIOD*3)
        wdrv_if.w_o_ready = 1;
        #(CLK_PERIOD*12);
        reset_inputs();
        #(CLK_PERIOD);
    end
    endtask



    initial begin
        reset_init_state();
        send_sp0();
        send_sp1();
        send_dcache();

        $finish;
    end


endprogram