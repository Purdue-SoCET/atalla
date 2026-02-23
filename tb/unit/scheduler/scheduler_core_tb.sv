`timescale 1ns / 10ps
`include "execution_unit_if.sv"
`include "scheduler_pkg.sv"

module scheduler_core_tb;
    import execution_unit_types_pkg::*;

    parameter PERIOD = 2;
    logic CLK = 0, nRST;
    always #(PERIOD/2) CLK++;
    string casename;

    execution_unit_types_pkg::in_DEC_t slot_1, slot_2, slot_3, slot_4;
    scheduler_pkg::EXEC_WB_LATCH WB_output;
    logic hit;
    logic [31:0] data_load;

    scheduler_core DUT (.CLK(CLK), .nRST(nRST), .slot_1(slot_1), .slot_2(slot_2), .slot_3(slot_3), .slot_4(slot_4), .WB_output(WB_output), .hit(hit), .data_load(data_load));


    initial begin
        casename = "rst";
        slot_1 = '{default: '0};
        slot_2 = '{default: '0};
        slot_3 = '{default: '0};
        slot_4 = '{default: '0};
        data_load = 32'b0;
        nRST = 1'b0;

        @(posedge CLK);
        @(posedge CLK);
        nRST = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        slot_1.ld_valid = 1'b1;
        slot_1.valid_in = 1'b1;
        slot_1.rs1_value = 32'hBEEEEEEF;
        slot_1.rdIn = 8'd1;

        slot_2.bf_add_valid = 1'b1;
        slot_2.valid_in = 1'b1;
        slot_2.rs1_value = 32'h0000412c;
        slot_2.rs2_value = 32'h00004114;
        slot_2.rdIn = 8'd1;

        slot_3.int_to_BF_valid = 1'b1;
        slot_3.valid_in = 1'b1;
        slot_3.rs1_value = 32'd194;
        slot_3.rdIn = 8'd1;
        hit = 1'b1;
        data_load = 32'hDEADBEEF;
        @(negedge CLK);
        slot_1 = '{default: '0};
        slot_2 = '{default: '0};
        slot_3 = '{default: '0};
        slot_4 = '{default: '0};
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