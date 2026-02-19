/*
Full testbench for the vector datapath
Testscases can be found in the test_cases folder
Owner: Jacob Walter

One horrindus make command coming up
make test tb_file=vector_datapath_tb.sv packages=/vector/vector_pkg.vh,/memory/scratchpad/scpad_pkg.sv,/common/xbar/xbar_pkg.sv modules=/vector/vector_datapath.sv,/vector/slicer.sv,/vector/lane.sv,/vector/lane_sequencer.sv,/vector/result_collector.sv,/vector/result_collector_counter.sv,/common/arithmetic/adders,/common/arithmetic/multipliers,/common/arithmetic/sqrt,/vector/lane_FUs/mul_FU.sv,/vector/lane_FUs/sqrt_FU.sv,/vector/lane_FUs/lane_unit_fifo.sv GUI=ON


*/

`timescale 1ns/1ps

`include "vector_pkg.vh"
`include "vector_if.vh"

module vector_datapath_tb;
    import vector_pkg::*;

    logic CLK;
    logic nRST;

    localparam int CLK_PERIOD      = 10;

    initial begin
        CLK = 1'b0;
        forever #(CLK_PERIOD/2) CLK = ~CLK;
    end



    //instanciation
    vector_if vif();

    vector_datapath dut (
        .CLK (CLK),
        .nRST(nRST),
        .vif (vif)
    );

    //task to drive the signals to one of the vector issue ports
    task automatic issue_to_lane_port(
        input int port,
        input vreg_t v1,
        input vreg_t v2,
        input fu_t usel,
        input logic [7:0] vd,
        input logic rm,
        input vmask_t mask,
        input valu_op_t alu_op
    );
        
        vif.lanes_in.lane_issue_ports[port].v1 = v1;
        vif.lanes_in.lane_issue_ports[port].v2 = v2;
        vif.lanes_in.lane_issue_ports[port].usel = usel;
        vif.lanes_in.lane_issue_ports[port].vd = vd;
        vif.lanes_in.lane_issue_ports[port].rm = rm;
        vif.lanes_in.lane_issue_ports[port].mask = mask;
        vif.lanes_in.lane_issue_ports[port].alu_op = alu_op;
        vif.lanes_in.lane_issue_ports[port].input_valid = 1;
    endtask

    task automatic clear_lane_port(
        input int port
    );
        vif.lanes_in.lane_issue_ports[port].v1 = 'b0;
        vif.lanes_in.lane_issue_ports[port].v2 = 'b0;
        vif.lanes_in.lane_issue_ports[port].usel = VALU;
        vif.lanes_in.lane_issue_ports[port].vd = 'b0;
        vif.lanes_in.lane_issue_ports[port].rm = 0;
        vif.lanes_in.lane_issue_ports[port].mask = 'b0;
        vif.lanes_in.lane_issue_ports[port].alu_op = VR_SUM;
        vif.lanes_in.lane_issue_ports[port].input_valid = 0;
    endtask



    //used to set the ready state of each FU, set the bits for the index of the FU you want to make ready or not ready
    task automatic set_lane_wb_ready(
        input logic [LANE_FU_COUNT-1:0] status
    );
        vif.lanes_in.wb_ready = status;
    endtask

    task automatic single_fu_test(
        input int port,
        input vreg_t v1,
        input vreg_t v2,
        input fu_t usel,
        input logic [7:0] vd,
        input logic rm,
        input vmask_t mask,
        input valu_op_t alu_op
    );
        issue_to_lane_port(port, v1, v2, usel, vd, rm, mask, alu_op);
        @(posedge CLK);
        clear_lane_port(port);

    endtask

    task automatic apply_reset;
        begin
            nRST = 1'b0;
            clear_lane_port(0);
            clear_lane_port(1);
            set_lane_wb_ready(5'b11111);
            repeat (5) @(posedge CLK);
            nRST = 1'b1;
            repeat (5) @(posedge CLK);
        end
    endtask


    initial begin
        apply_reset();
        

        single_fu_test(
            .port   (0),
            .v1     ('1),
            .v2     ('1),
            .usel   (MUL),
            .vd     (8'h01),
            .rm     (1'b0),
            .mask   ('1),
            .alu_op (VR_SUM)
        );

        repeat (50) @(posedge CLK);
        $stop;
    end

endmodule
