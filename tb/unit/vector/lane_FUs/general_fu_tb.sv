/*
general_Lane_tb.sv
This is a general testbench to test any lane FU for timing
This does NOT validate arithmetic as each unit should have that already
This will not have toggle or branch coverage cause i dont have time
Owner: Jacob Walter

Make commands:
Sqrt:
make test tb_file=general_fu_tb.sv modules=/vector/lane_FUs/sqrt_FU.sv,/vector/lane_sequencer.sv,/vector/lane_FUs/lane_unit_fifo.sv,/common/arithmetic/sqrt/sqrt_bf16.sv,/common/arithmetic/adders/add_bf16.sv,/common/arithmetic/adders/left_shift_add_bf16.sv,/common/arithmetic/multipliers/ packages=/vector/vector_pkg.vh GUI=ON


Test Cases:
1. Power on reset
2. Issue from port 1
3. Issue from port 2
4. Mask Test 1
5. Mask Test 2
5. Output Backpressure test

*/

`timescale 1ns/1ps

`include "functional_unit_if.vh"
`include "vector_pkg.vh"

module general_fu_tb (
);
    

    import vector_pkg::*;

    //Clock setup
    logic CLK;
    logic nRST;

    initial CLK = 1'b0;
    always #5 CLK = ~CLK;   // 100 MHz

    //DUT instanciation
    functional_unit_if fuif();
    sqrt_FU DUT (
        .CLK(CLK),
        .nRST(nRST),
        .fuif(fuif)
    );

    task automatic reset_dut();
        // Assert reset
        nRST = 1'b0;

        // Initialize all FU interface inputs
        fuif.in.wb_ready = 1'b0;

        for (int i = 0; i < LANE_ISSUE_W; i++) begin
            fuif.in.ports[i].input_valid = 1'b0;
            fuif.in.ports[i].v1         = '0;
            fuif.in.ports[i].v2         = '0;
            fuif.in.ports[i].usel       = fu_t'(0);
            fuif.in.ports[i].vd         = '0;
            fuif.in.ports[i].rm         = '0;
            fuif.in.ports[i].mask       = '0;
            fuif.in.ports[i].alu_op     = valu_op_t'(0);
        end

        // Hold reset for a few clocks
        repeat (5) @(posedge CLK);

        // Deassert reset synchronously
        nRST = 1'b1;

        // Wait for DUT to stabilize
        repeat (5) @(posedge CLK);
    endtask

    //this only sets signals, clocking is the responsibility of the caller
        task automatic issue_from_port(
            input int i,
            input logic [SLICE_W-1:0][15:0] v1, v2,
            input fu_t usel,
            input logic [7:0] vd,
            input logic rm,
            input logic [SLICE_W-1:0] mask,
            input valu_op_t alu_op
        );
            fuif.in.ports[i].input_valid = 'b1;
            fuif.in.ports[i].v1 = v1;
            fuif.in.ports[i].v2 = v2;
            fuif.in.ports[i].usel = usel;
            fuif.in.ports[i].vd = vd;
            fuif.in.ports[i].rm = rm;
            fuif.in.ports[i].mask = mask;
            fuif.in.ports[i].alu_op = alu_op;
        endtask //automatic

        task automatic clear_port(
            input int i
        );
            fuif.in.ports[i].input_valid = 1'b0;
            fuif.in.ports[i].v1         = '0;
            fuif.in.ports[i].v2         = '0;
            fuif.in.ports[i].usel       = fu_t'(0);
            fuif.in.ports[i].vd         = '0;
            fuif.in.ports[i].rm         = '0;
            fuif.in.ports[i].mask       = '0;
            fuif.in.ports[i].alu_op     = valu_op_t'(0);
        endtask


    task automatic sqrt_test_issue_port_0();
        logic [SLICE_W-1:0][15:0] v1;
        logic [SLICE_W-1:0][15:0] v2;
        int wb_count = 0;
        int timeout = 0;
        v1 = '{16'h4110,16'h4080}; //9,4
        v2 = 'b0;
        
        fuif.in.wb_ready = 'b1;
        issue_from_port(0, v1, v2, SQRT, 1, 0, 2'b11, VR_SUM);
        @(posedge CLK);
        clear_port(0);

        while (wb_count < SLICE_W) begin
            @(posedge CLK);
            if (fuif.out.wb_valid) begin
                wb_count++;
            end
            timeout++;
            assert (timeout < 1000) else $fatal("Timeout waiting for writeback");
        end
    endtask

    task automatic sqrt_test_issue_port_1();
        logic [SLICE_W-1:0][15:0] v1;
        logic [SLICE_W-1:0][15:0] v2;
        int wb_count = 0;
        int timeout = 0;
        v1 = '{16'h4110,16'h4080}; //9,4
        v2 = 'b0;
        
        fuif.in.wb_ready = 'b1;
        issue_from_port(1, v1, v2, SQRT, 2, 0, 2'b11, VR_SUM);
        @(posedge CLK);
        clear_port(1);

        while (wb_count < SLICE_W) begin
            @(posedge CLK);
            if (fuif.out.wb_valid) begin
                wb_count++;
            end
            timeout++;
            assert (timeout < 1000) else $fatal("Timeout waiting for writeback");
        end
    endtask

    task automatic sqrt_test_masking_1();
        logic [SLICE_W-1:0][15:0] v1;
        logic [SLICE_W-1:0][15:0] v2;
        int wb_count = 0;
        int timeout = 0;
        v1 = '{16'h4110,16'h4080}; //9,4
        v2 = 'b0;
        
        fuif.in.wb_ready = 'b1;
        issue_from_port(0, v1, v2, SQRT, 1, 0, 2'b01, VR_SUM); // Only element 0 active
        @(posedge CLK);
        fuif.in.ports[0].input_valid = 'b0;

        while (wb_count < SLICE_W) begin
            @(posedge CLK);
            if (fuif.out.wb_valid) begin
                wb_count++;
            end
            timeout++;
            assert (timeout < 1000) else $fatal("Timeout waiting for writeback");
        end
    endtask

    task automatic sqrt_test_masking_2();
        logic [SLICE_W-1:0][15:0] v1;
        logic [SLICE_W-1:0][15:0] v2;
        int wb_count = 0;
        int timeout = 0;
        v1 = '{16'h4110,16'h4080}; //9,4
        v2 = 'b0;
        
        fuif.in.wb_ready = 'b1;
        issue_from_port(0, v1, v2, SQRT, 1, 0, 2'b10, VR_SUM); // Only element 1 active
        @(posedge CLK);
        fuif.in.ports[0].input_valid = 'b0;

        while (wb_count < SLICE_W) begin
            @(posedge CLK);
            if (fuif.out.wb_valid) begin
                wb_count++;
            end
            timeout++;
            assert (timeout < 1000) else $fatal("Timeout waiting for writeback");
        end
    endtask

    task automatic sqrt_backpressure();
        logic [SLICE_W-1:0][15:0] v1;
        logic [SLICE_W-1:0][15:0] v2;
        int wb_count = 0;
        int timeout = 0;
        v1 = '{16'h4110,16'h4080}; //9,4
        v2 = 'b0;

        fuif.in.wb_ready = 'b0;
        issue_from_port(0, v1, v2, SQRT, 10, 0, 2'b11, VR_SUM);
        @(posedge CLK);
        fuif.in.ports[0].input_valid = 'b0;

        //waiting for the first element of the slice to write back
        while (wb_count < 1) begin
            @(posedge CLK);
            if (fuif.out.wb_valid) begin
                wb_count++;
            end
            timeout++;
            assert (timeout < 1000) else $fatal("Timeout waiting for writeback");
        end
        @(posedge CLK); //5 clocks to simulate backpressure to make sure the whole unit keeps running until it backs up completly
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        fuif.in.wb_ready = 'b1;
        while (wb_count < SLICE_W) begin //begin waiting for the second element to writeback
            @(posedge CLK);
            if (fuif.out.wb_valid) begin
                wb_count++;
            end
            timeout++;
            assert (timeout < 1000) else $fatal("Timeout waiting for writeback");
        end
    endtask //automatic

    task automatic sqrt_max_issue();
        logic [SLICE_W-1:0][15:0] v1;
        logic [SLICE_W-1:0][15:0] v2;
        int num_issues = 10;
        int issued_count = 0;
        
        v2 = 'b0;
        fuif.in.wb_ready = 'b1;
        
        while (issued_count < num_issues) begin
            // Wait for unit to be ready
            wait (fuif.out.input_ready == 1);
            
            // Generate unique data for each issue
            v1[0] = 16'h4000 + (issued_count * 16);
            v1[1] = 16'h4080 + (issued_count * 16);
            
            issue_from_port(0, v1, v2, SQRT, issued_count[7:0], 0, 2'b11, VR_SUM);
            issued_count++;
            $display("Issued SQRT operation %0d", issued_count);
            
            @(posedge CLK);
            clear_port(0);
        end
        
        $display("Max issue test complete: issued %0d operations", issued_count);
    endtask //automatic


    initial begin
        reset_dut();
        //sqrt_test_issue_port_0();
        //sqrt_test_issue_port_1();
        //sqrt_max_issue();
        //sqrt_test_masking_1();
        //sqrt_test_masking_2();
        sqrt_backpressure();

        repeat(3) @(posedge CLK);
        $stop;
    end
endmodule