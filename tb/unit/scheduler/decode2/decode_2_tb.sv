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
        return 40'h0; //this isn't a nop but just easier to look at imo
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

    task wb_scalar(input logic [1:0] i, input logic [7:0] reg_addr, input logic [31:0] data);
        d2if.scalar_WB_WEN[i]   = 1'b1;
        d2if.scalar_WB_wsel[i]  = reg_addr;
        d2if.scalar_WB_wdata[i] = data;
    endtask

    task wb_vector(input logic [1:0] i, input logic [7:0] reg_addr, input vector_t data);
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
        casename = "rst + writing stuff back";
        do_reset();

        // wb_scalar(2'b0, 8'h0, 32'hDEADBEEF); // Write to scalar reg 0 (shouldn't work)
        wb_scalar(2'b0, 8'h3, 32'hFFFFFFFF); // Write to scalar reg 3 
        wb_scalar(2'b1, 8'h1, 32'hBABEBEEF); // Write to scalar reg 1
        wb_scalar(2'd2, 8'h2, 32'hDEADBEEF); // Write to scalar reg 2 
        wb_scalar(2'd3, 8'h4, 32'hF0F0F0F0); // Write to scalar reg 4

        // wb_vector(2'b0, 8'd0, '{default: 16'hDEAD}); // Write to vector reg 0 (shouldn't work)
        wb_vector(2'b0, 8'd1, '{default: 16'hDEAD}); // Write to vector reg 1
        wb_vector(2'b1, 8'd4, '{default: 16'hBEEF}); // Write to vector reg 4
        wb_vector(2'd2, 8'd8, '{default: 16'hDADE}); // Write to vector reg 8
        wb_vector(2'd3, 8'd12, '{default: 16'hBAEF}); // Write to vector reg 12

        // wb_mask(2'b0, 4'h0, 32'hFFFF0000); // Write to mask reg 0 (shouldn't work)
        wb_mask(1'b0, 4'h2, 32'hFFFF0000); // Write to mask reg 2
        wb_mask(1'b1, 4'h1, 32'h0000FFFF); // Write to mask reg 1
        
        repeat(3) @(posedge CLK); //vector write bank conflicts resolving
        @(negedge CLK);
        clear_wb();
        drive_nop_packet();

        @(negedge CLK);
        casename = "first 4 instructions";
        d2if.vector_instrs[0] = 40'h1201008245; //VM VREG_ST(sid = 1, num_cols = 4, rs2 = 2(data = hDEADBEEF), rs1 = 1 (data = hBABEBEEF), vd = 4 (actually the vs, data = hBEEF), opcode = 69)
        d2if.vector_instrs[1] = 40'h00840601BD; //VMV MLT (vms=1 (data = h0000FFFF), vs2=8 (data = hDADE), vs1=12 (data = hBAEF), vmd=3, opcode =61)
        d2if.vector_instrs[2] = 40'h010180824D; //VS MUL_VS (vms = 2 (data = hFFFF0000), rs1 = 3 (data = hFFFFFFFF), vs1=1 (data = hDEAD), vd=4, opcode=77)
        d2if.scalar_instrs[3] = 40'h007F82039A; //I MODI imm12=0xFF, rs1=4 (data = hF0F0F0F0), rd=7, opcode=26

        @(posedge CLK iff d2if.ready);
        casename = "ready high";
        drive_nop_packet();

        @(negedge CLK);
        casename = "second 4 instructions";
        d2if.vector_instrs[1] = 40'h8603C8; //VMOV_VTS (imm=1, vs1=12 (hBAEF), rd=7, opcode=72) 
        d2if.SDMA_instrs[3] = 40'h3808146; //SCPAD LD, rs3=7 (?), rs2=1 (data = hBABEBEEF), rs1/rd=2 (data = hDEADBEEF), opcode = 70
        //will be blocked because rd=7 busy

        repeat (5) @(posedge CLK);
        @(negedge CLK);
        casename = "write back to busy scalar reg 7";
        wb_scalar(2'b0, 8'h7, 32'h12345678); // Write to scalar reg 7
        //instr should be unblocked but then 7 will be busy again after ready 

        @(posedge CLK iff d2if.ready);
        casename = "ready high";
        clear_wb();
        drive_nop_packet();


        repeat (5) @(posedge CLK);





        

        $finish;
    end


endmodule