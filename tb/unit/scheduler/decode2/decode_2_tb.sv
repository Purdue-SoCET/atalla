`timescale 1ns / 10ps
`include "atalla_isa_types.vh"
`include "decode_2_if.vh"

module decode_2_tb;
    import atalla_isa_pkg::*;

    parameter PERIOD = 2;
    logic CLK = 0, nRST;
    always #(PERIOD/2) CLK++;
    string casename;

    decode_2_if d2if ();
    decode_2 DUT (.CLK(CLK), .nRST(nRST), .d2if(d2if));

    // Build a NOP instruction
    function automatic instr_t make_nop();
        return instr_t'(NOP_R);
    endfunction

    task drive_nop_packet();
        for (int i = 0; i < 4; i++) d2if.scalar_instrs[i] = make_nop();
        for (int i = 0; i < 4; i++) d2if.vector_instrs[i] = make_nop();
        for (int i = 0; i < 4; i++) d2if.SDMA_instrs[i]   = make_nop();
    endtask

    task set_all_fu_ready(input logic val);
        d2if.ready_DEC2_ex1  = val;
        d2if.ready_DEC2_ex2  = val;
        d2if.ready_DEC2_ex3  = val;
        d2if.ready_DEC2_ex4  = val;
        d2if.ready_DEC2_ex5  = val;
        d2if.alu_ready       = val;
        d2if.mul_ready       = val;
        d2if.exp_ready       = val;
        d2if.reduction_ready = val;
        d2if.vlsu_ready      = val;
        d2if.gsau_ready      = val;
        d2if.sdma_ready      = val;
    endtask

    task wb_scalar(input logic i, input logic [7:0] reg_addr, input logic [31:0] data);
        d2if.scalar_WB_WEN[i]   = 1'b1;
        d2if.scalar_WB_wsel[i]  = reg_addr;
        d2if.scalar_WB_wdata[i] = data;
    endtask

    task wb_vector(input logic i, input logic [7:0] reg_addr, input vector_t data);
        d2if.vector_WB_WEN[i]   = 1'b1;
        d2if.vector_WB_wsel[i]  = reg_addr;
        d2if.vector_WB_wdata[i] = data;
    endtask

    task wb_mask(input logic i, input logic [3:0] reg_addr, input logic [31:0] data);
        d2if.mask_WB_WEN[i]   = 1'b1;
        d2if.mask_WB_wsel[i]  = reg_addr;
        d2if.mask_WB_wdata[i] = data;
    endtask

    task clear_wb();
        d2if.scalar_WB_WEN      = '0;
        d2if.scalar_WB_wsel     = '0;
        d2if.scalar_WB_wdata    = '0;
        d2if.vector_WB_WEN      = '0;
        d2if.vector_WB_wsel     = '0;
        d2if.vector_WB_wdata    = '0;
        d2if.mask_WB_WEN        = '0;
        d2if.mask_WB_wsel       = '0;
        d2if.mask_WB_wdata      = '0;
        d2if.scalar_SDMA_WB_WEN  = '0;
        d2if.scalar_SDMA_WB_wsel = '0;
    endtask
    
    task do_reset();
        nRST = 0;
        drive_nop_packet();
        clear_wb();
        set_all_fu_ready(1'b1);
        d2if.pc_in            = '0;
        d2if.pc_pred_addr_in  = '0;
        d2if.predict_taken_in = '0;
        @(posedge CLK); @(posedge CLK);
        nRST = 1;
        @(posedge CLK); #1;
    endtask

    initial begin
        casename = "rst";
        do_reset();

        wb_scalar(1'b0, 8'h0, 32'hDEADBEEF); // Write to scalar reg 0
        wb_scalar(1'b1, 8'h1, 32'hBABEBEEF); // Write to scalar reg 1
        wb_vector(1'b0, 8'h0, '{default: 16'hDEAD}); // Write to vector reg 0
        wb_vector(1'b1, 8'h1, '{default: 16'hBEEF}); // Write to vector reg 1
        wb_mask(1'b0, 4'h0, 32'hFFFF0000); // Write to mask reg 0
        @(posedge CLK);
        @(posedge CLK);


        

        $finish;
    end


endmodule