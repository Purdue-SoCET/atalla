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
`include "gsau_control_unit_if.vh"

module vector_datapath_tb;
    `include "scpad_params.svh"
    import vector_pkg::*;
    import scpad_pkg::*;

    logic CLK;
    logic nRST;

    localparam int CLK_PERIOD      = 10;

    initial begin
        CLK = 1'b0;
        forever #(CLK_PERIOD/2) CLK = ~CLK;
    end



    //instanciation
    vector_if vif();
    gsau_control_unit_if gsauif();
    scpad_if sif(CLK, nRST);

    vector_datapath dut (
        .CLK (CLK),
        .nRST(nRST),
        .vif (vif),
        .sif(sif),
        .gsauif(gsauif)
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
        input alu_op_t alu_op
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

    task automatic issue_to_gsau_port(
        input vreg_t v1,
        input vreg_t v2,
        input logic [7:0] vd,
        input logic weight
    );
        vif.gsau_in.veg_vdata1 = v1;
        vif.gsau_in.veg_vdata2 = v2;
        vif.gsau_in.vd = vd;
        vif.gsau_in.weight = weight;
        vif.gsau_in.valid_in = 'b1;
    endtask

    task automatic issue_to_vlsu_port(
        input int port,
        input logic write,
        input logic [SCPAD_ADDR_WIDTH-1:0] spad_addr,
        input logic [VIDX_W-1:0]          vd,
        input logic [MAX_DIM_WIDTH-1:0]   num_rows,
        input logic [MAX_DIM_WIDTH-1:0]   num_cols,
        input logic [MAX_DIM_WIDTH-1:0]   row_id,
        input logic [MAX_DIM_WIDTH-1:0]   col_id,
        input logic                       row_or_col,

        input vreg_t                      data                 
    );
        vif.vlsu_in.sched_req[port].valid       = 'b1;
        vif.vlsu_in.sched_req[port].write       = write;
        vif.vlsu_in.sched_req[port].spad_addr   = spad_addr;
        vif.vlsu_in.sched_req[port].vdst        = vd;
        vif.vlsu_in.sched_req[port].num_rows    = num_rows;
        vif.vlsu_in.sched_req[port].num_cols    = num_cols;
        vif.vlsu_in.sched_req[port].row_id      = row_id;
        vif.vlsu_in.sched_req[port].col_id      = col_id;
        vif.vlsu_in.sched_req[port].row_or_col  = row_or_col;

        vif.vlsu_in.vrf_data[port].data         = data;
        vif.vlsu_in.vrf_data[port].valid        = 'b1;
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
        vif.lanes_in.lane_issue_ports[port].alu_op = ALU_ADD;
        vif.lanes_in.lane_issue_ports[port].input_valid = 0;
    endtask

    task automatic clear_vlsu_port(
        input int port
    );
        vif.vlsu_in.sched_req[port] = 'b0;
        vif.vlsu_in.vrf_data[port] = 'b0;
    endtask

    task automatic clear_gsau_port();
        vif.gsau_in.veg_vdata1 = 'b0;
        vif.gsau_in.veg_vdata2 = 'b0;
        vif.gsau_in.vd = 'b0;
        vif.gsau_in.valid_in = 'b0;
        vif.gsau_in.weight = 'b0;
    endtask

    task automatic drive_gsau_from_sys(
        input vreg_t data = '0,
        input logic valid = 'b0,
        input logic ready = 'b0
    );
        gsauif.sa_array_output = data;
        gsauif.sa_valid_in = valid;
        gsauif.sa_ready_in = ready;
        
    endtask

    task automatic drive_vlsu_from_sp(
        input int port,
        input logic valid = 'b0,
        input logic write = 'b0,
        input vreg_t data = 'b0,
        input logic stall = 'b0
    );
        sif.vec_res[port].valid = valid;
        sif.vec_res[port].write = write;
        sif.vec_res[port].rdata = data;
        sif.fe_vec_stall[port] = stall;
    endtask

    //used to set the ready state of each FU, set the bits for the index of the FU you want to make ready or not ready
    task automatic set_wb_ready(
        input logic [LANE_FU_COUNT-1:0] lane_status,
        input logic [NUM_SCPADS-1:0] vlsu_status,
        input logic gsau_status,
        input logic reduction_status
    );
        vif.wb_ready_signals.lanes_wb_ready = lane_status;
        vif.wb_ready_signals.vlsu_wb_ready = vlsu_status;
        vif.wb_ready_signals.gsau_wb_ready = gsau_status;
        vif.wb_ready_signals.reduction_wb_ready = reduction_status;
    endtask

    task automatic single_fu_test(
        input int port,
        input vreg_t v1,
        input vreg_t v2,
        input fu_t usel,
        input logic [7:0] vd,
        input logic rm,
        input vmask_t mask,
        input alu_op_t alu_op
    );
        issue_to_lane_port(port, v1, v2, usel, vd, rm, mask, alu_op);
        @(posedge CLK);
        clear_lane_port(port);

    endtask

    task automatic single_gsau_test(
        input vreg_t v1,
        input vreg_t v2,
        input logic [7:0] vd,
        input logic weight
    );
        issue_to_gsau_port(v1, v2, vd, weight);
        @(posedge CLK);
        clear_gsau_port();
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        drive_gsau_from_sys(v1, 1, 1);
        @(posedge CLK);
        drive_gsau_from_sys(.ready('b1));
        @(posedge CLK);
    endtask

    task automatic single_vlsu_test(
        input int port,
        input logic write,
        input logic [SCPAD_ADDR_WIDTH-1:0] spad_addr,
        input logic [VIDX_W-1:0]          vd,
        input logic [MAX_DIM_WIDTH-1:0]   num_rows,
        input logic [MAX_DIM_WIDTH-1:0]   num_cols,
        input logic [MAX_DIM_WIDTH-1:0]   row_id,
        input logic [MAX_DIM_WIDTH-1:0]   col_id,
        input logic                       row_or_col,
        input vreg_t                      data
    );
        issue_to_vlsu_port(port, write, spad_addr, vd, num_rows, num_cols, row_id, col_id, row_or_col, data);
        @(posedge CLK);
        clear_vlsu_port(port);
        
    endtask

    task automatic apply_reset;
        begin
            nRST = 1'b0;
            clear_lane_port(0);
            clear_lane_port(1);
            clear_vlsu_port(0);
            clear_vlsu_port(1);
            clear_gsau_port();
            set_wb_ready(5'b11111, 2'b11, 1'b1, 1'b1);

            //set the interface inputs to defaults
            sif.fe_vec_stall[0] = 'b0;
            sif.fe_vec_stall[1] = 'b0;
            sif.vec_res[0] = 'b0;
            sif.vec_res[1] = 'b0;

            gsauif.sa_ready_in = 'b1;
            gsauif.sa_valid_in = 'b0;
            gsauif.sa_array_output = 'b0;


            repeat (5) @(posedge CLK);
            nRST = 1'b1;
            repeat (5) @(posedge CLK);
        end
    endtask

    task automatic basic_test_case_loop(
        
    );

    while(1) begin //while we still have instructions that we need to issue
        //check to see if we need to respond to the VLSU

        //check to see if we need to respond to the GSAU

        //writeback any valid data

        //decode the new packet from the testcase file

        //issue the new packet to whichever port it needs to go to
        
        //clock

        //clear all the ports
    end

    //dump the ram.sv

    endtask

    vreg_t bf16_v1 = '{0: 16'h4120, 1: 16'h4140, 2: 16'h4160, 3: 16'h4180,
                    4: 16'h41a0, 5: 16'h41c0, 6: 16'h41e0, 7: 16'h4200,
                    8: 16'h4210, 9: 16'h4220, 10: 16'h4230, 11: 16'h4240,
                    12: 16'h4250, 13: 16'h4260, 14: 16'h4270, 15: 16'h4280,
                    16: 16'h4290, 17: 16'h42a0, 18: 16'h42b0, 19: 16'h42c0,
                    20: 16'h42d0, 21: 16'h42e0, 22: 16'h42f0, 23: 16'h4300,
                    24: 16'h4308, 25: 16'h4310, 26: 16'h4318, 27: 16'h4320,
                    28: 16'h4328, 29: 16'h4330, 30: 16'h4338, 31: 16'h4340};

    vreg_t bf16_v2 = '{0: 16'h41a0, 1: 16'h41c0, 2: 16'h41e0, 3: 16'h4200,
                    4: 16'h4210, 5: 16'h4220, 6: 16'h4230, 7: 16'h4240,
                    8: 16'h4250, 9: 16'h4260, 10: 16'h4270, 11: 16'h4280,
                    12: 16'h4290, 13: 16'h42a0, 14: 16'h42b0, 15: 16'h42c0,
                    16: 16'h42d0, 17: 16'h42e0, 18: 16'h42f0, 19: 16'h4300,
                    20: 16'h4308, 21: 16'h4310, 22: 16'h4318, 23: 16'h4320,
                    24: 16'h4328, 25: 16'h4330, 26: 16'h4338, 27: 16'h4340,
                    28: 16'h4348, 29: 16'h4350, 30: 16'h4358, 31: 16'h4360};

    initial begin
        apply_reset();
        /*single_fu_test (
            .port   (0),
            .v1     (bf16_v1),
            .v2     (bf16_v2),
            .usel   (SQRT),
            .vd     (8'h01),
            .rm     (1'b0),
            .mask   ('1),
            .alu_op (ALU_ADD)
        );
        */
        single_gsau_test(bf16_v1, bf16_v2, 8'd1, 1'b0);
        //single_vlsu_test(0, 1'b1, 'h10, 8'd1, 'h0, 'h20, 'h4, 'h0, 1'b0, bf16_v1);

        repeat (100) @(posedge CLK);
        $stop;
    end

endmodule
