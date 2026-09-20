`timescale 1ns / 10ps
`include "execution_unit_if.sv"

module execution_unit_tb;

    parameter PERIOD = 2;
    logic CLK = 0, nRST;
    always #(PERIOD/2) CLK++;
    string casename;

    execution_unit_if ex_if ();

    execute_stage DUT (.clk(CLK), .nRST(nRST), .ex_if(ex_if));


    initial begin
        casename = "rst";
        ex_if.ready_WB_ex1 = 1'b1;
        ex_if.ready_WB_ex2 = 1'b1;
        ex_if.ready_WB_ex3 = 1'b1;
        ex_if.ready_WB_ex4 = 1'b1;
        ex_if.ready_WB_ex5 = 1'b1;
        ex_if.data_load = 32'd0;
        ex_if.hit = 1'b0;
        ex_if.slot_1 = '{default: '0};
        ex_if.slot_2 = '{default: '0};
        ex_if.slot_3 = '{default: '0};
        ex_if.slot_4 = '{default: '0};


        nRST = 1'b0;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);

        nRST = 1'b1;

        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        ex_if.slot_4.alu_valid = 1'b1;
        ex_if.slot_4.valid_in = 1'b1;
        ex_if.slot_4.rs1_value = 32'd125;
        ex_if.slot_4.rs2_value = 32'd250;
        ex_if.slot_4.rdIn = 8'd21;
        ex_if.slot_4.op = 7'b0000001;
        ex_if.ready_WB_ex1 = 1'b0;

        ex_if.slot_3.sMult_valid = 1'b1;
        ex_if.slot_3.valid_in = 1'b1;
        ex_if.slot_3.rs1_value = 32'd125;
        ex_if.slot_3.rs2_value = 32'd250;
        ex_if.slot_3.rdIn = 8'd91;
        ex_if.ready_WB_ex4 = 1'b0;

        ex_if.slot_2.s_div_valid = 1'b1;
        ex_if.slot_2.valid_in = 1'b1;
        ex_if.slot_2.rs1_value = 32'd1000;
        ex_if.slot_2.rs2_value = 32'd10;
        ex_if.slot_2.rdIn = 8'd83;
        ex_if.ready_WB_ex2 = 1'b1;

        ex_if.slot_1.bf_add_valid = 1'b1;
        ex_if.slot_1.valid_in = 1'b1;
        ex_if.slot_1.rs1_value = 32'h000042fa;
        ex_if.slot_1.rs2_value = 32'h0000437a;
        ex_if.slot_1.rdIn = 8'd45;
        ex_if.ready_WB_ex3 = 1'b0;
        @(negedge CLK);
        ex_if.slot_4 = '{default: '0};
        ex_if.slot_3 = '{default: '0};
        ex_if.slot_2 = '{default: '0};
        ex_if.slot_1 = '{default: '0};
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        ex_if.ready_WB_ex1 = 1'b1;
        @(negedge CLK);
        ex_if.slot_4.alu_valid = 1'b1;
        ex_if.slot_4.valid_in = 1'b1;
        ex_if.slot_4.rs1_value = 32'd125;
        ex_if.slot_4.imm = 32'd12;
        ex_if.slot_4.rdIn = 8'd35;
        ex_if.slot_4.op = 7'b0010110;
        ex_if.ready_WB_ex1 = 1'b0;
        @(negedge CLK);
        ex_if.slot_4 = '{default: '0};
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        ex_if.ready_WB_ex4 = 1'b1;
        @(negedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        ex_if.ready_WB_ex3 = 1'b1;
        @(negedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        ex_if.ready_WB_ex2 = 1'b1;
        @(negedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        ex_if.ready_WB_ex1 = 1'b1;
        @(negedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);

        $display("DONE");
        $finish;
    end


endmodule