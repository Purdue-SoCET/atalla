/*
general_Lane_tb.sv
This is a general testbench to test any lane FU for timing
This does NOT validate arithmetic as each unit should have that already
This will not have toggle or branch coverage cause i dont have time
Owner: Jacob Walter

Make commands:
Sqrt:
make test tb_file=general_fu_tb.sv modules=/vector/lane_FUs/sqrt_FU.sv,/vector/lane_sequencer.sv,/vector/lane_FUs/lane_unit_fifo.sv,/common/arithmetic/sqrt/sqrt_bf16.sv,/common/arithmetic/adders/add_bf16.sv,/common/arithmetic/adders/left_shift_add_bf16.sv,/common/arithmetic/multipliers/mul_bf16.sv,/common/arithmetic/multipliers/wallacetree_8b.sv,/common/arithmetic/adders/adder_8b.sv,/common/arithmetic/multipliers/fa.sv,/common/arithmetic/multipliers/ha.sv packages=/vector/vector_pkg.vh GUI=ON
Multiplier:
make test tb_file=general_fu_tb.sv modules=/vector/lane_FUs/mul_FU.sv,/vector/lane_sequencer.sv,/vector/lane_FUs/lane_unit_fifo.sv,/common/arithmetic/multipliers/mul_bf16_fu.sv,/common/arithmetic/multipliers/mul_bf16.sv,/common/arithmetic/multipliers/wallacetree_8b.sv,/common/arithmetic/multipliers/fa.sv,/common/arithmetic/multipliers/ha.sv,/common/arithmetic/adders/adder_8b.sv packages=/vector/vector_pkg.vh GUI=ON

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

    functional_unit_if fuif();
    //DUT instanciation
    /*
    
    sqrt_FU DUT (
        .CLK(CLK),
        .nRST(nRST),
        .fuif(fuif)
    );
    */
    mul_fu DUT (
        .CLK(CLK),
        .nRST(nRST),
        .fuif(fuif)
    );


    task automatic reset_dut();
        // Assert reset
        nRST = 1'b0;

        // Initialize all FU interface inputs
        fuif.in.wb_ready = 1'b1;

        for (int i = 0; i < LANE_ISSUE_W; i++) begin
            fuif.in.ports[i].input_valid = 1'b0;
            fuif.in.ports[i].v1         = '0;
            fuif.in.ports[i].v2         = '0;
            fuif.in.ports[i].usel       = VALU;
            fuif.in.ports[i].vd         = '0;
            fuif.in.ports[i].rm         = '0;
            fuif.in.ports[i].mask       = '0;
            fuif.in.ports[i].alu_op     = VR_SUM;
        end

        repeat (2) @(posedge CLK);
        nRST = 1'b1;
        repeat (2) @(posedge CLK);
    endtask

    // Sets all signals for a port, clocking is the responsibility of the caller
    task automatic issue_from_port(
        input int port_num,
        input logic [SLICE_W-1:0][15:0] v1,
        input logic [SLICE_W-1:0][15:0] v2,
        input fu_t usel,
        input logic [7:0] vd,
        input logic rm,
        input logic [SLICE_W-1:0] mask,
        input valu_op_t alu_op
    );
        fuif.in.ports[port_num].input_valid = 1'b1;
        fuif.in.ports[port_num].v1 = v1;
        fuif.in.ports[port_num].v2 = v2;
        fuif.in.ports[port_num].usel = usel;
        fuif.in.ports[port_num].vd = vd;
        fuif.in.ports[port_num].rm = rm;
        fuif.in.ports[port_num].mask = mask;
        fuif.in.ports[port_num].alu_op = alu_op;
    endtask

    task automatic clear_port(
        input int port_num
    );
        fuif.in.ports[port_num].input_valid = 1'b0;
        fuif.in.ports[port_num].v1         = '0;
        fuif.in.ports[port_num].v2         = '0;
        fuif.in.ports[port_num].usel       = VALU;
        fuif.in.ports[port_num].vd         = '0;
        fuif.in.ports[port_num].rm         = '0;
        fuif.in.ports[port_num].mask       = '0;
        fuif.in.ports[port_num].alu_op     = VR_SUM;
    endtask

    // Generic test: issue operation and wait for writeback
    task automatic test_issue_port(
        input int port_num,
        input logic [SLICE_W-1:0][15:0] v1,
        input logic [SLICE_W-1:0][15:0] v2,
        input fu_t usel,
        input logic [7:0] vd,
        input logic rm,
        input logic [SLICE_W-1:0] mask,
        input valu_op_t alu_op,
        input int timeout_cycles = 100
    );
        int wb_count = 0;
        int timeout = 0;
        
        fuif.in.wb_ready = 1'b1;
        issue_from_port(port_num, v1, v2, usel, vd, rm, mask, alu_op);
        @(posedge CLK);
        clear_port(port_num);

        while (wb_count < SLICE_W) begin
            @(posedge CLK);
            if (fuif.out.wb_valid) begin
                wb_count++;
            end
            timeout++;
            assert (timeout < timeout_cycles) else 
                $fatal("Timeout waiting for writeback on port %0d", port_num);
        end
    endtask

    task automatic test_max_issue(
        input int port_num,
        input fu_t usel,
        input logic rm,
        input logic [SLICE_W-1:0] mask,
        input valu_op_t alu_op,
        input int num_issues = 10,
        input logic [SLICE_W-1:0][15:0] base_v1 = '{16'h4000, 16'h4080},
        input logic [SLICE_W-1:0][15:0] base_v2 = '0,
        input int v1_increment = 16,
        input int v2_increment = 0,
        input int timeout_cycles = 1000
    );
        logic [SLICE_W-1:0][15:0] v1, v2;
        int issued_count = 0;
        int timeout = 0;
        
        v1 = base_v1;
        v2 = base_v2;
        fuif.in.wb_ready = 1'b1;
        
        while (issued_count < num_issues) begin
            // Wait for unit to be ready
            timeout = 0;
            do begin
                @(posedge CLK);
                timeout++;
                assert(timeout < timeout_cycles)
                    else $fatal("Timeout waiting for input_ready");
            end while (!fuif.out.input_ready);
            
            // Generate unique data for each issue
            for (int i = 0; i < SLICE_W; i++) begin
                v1[i] = base_v1[i] + (issued_count * v1_increment);
                v2[i] = base_v2[i] + (issued_count * v2_increment);
            end
            
            issue_from_port(port_num, v1, v2, usel, issued_count[7:0], rm, mask, alu_op);
            
            $display("[Max Issue] Issued operation %0d on port %0d", issued_count, port_num);
            
            @(posedge CLK);
            issued_count++;
            clear_port(port_num);
        end
    endtask

    // Generic backpressure test
    task automatic test_backpressure(
        input int port_num,
        input logic [SLICE_W-1:0][15:0] v1,
        input logic [SLICE_W-1:0][15:0] v2,
        input fu_t usel,
        input logic [7:0] vd,
        input logic rm,
        input logic [SLICE_W-1:0] mask,
        input valu_op_t alu_op,
        input int backpressure_cycles = 5,
        input int timeout_cycles = 100
    );
        int wb_count = 0;
        int timeout = 0;

        // Issue with backpressure applied
        fuif.in.wb_ready = 1'b0;
        issue_from_port(port_num, v1, v2, usel, vd, rm, mask, alu_op);
        @(posedge CLK);
        clear_port(port_num);

        // Wait for the first element to assert valid (NOT handshake yet)
        timeout = 0;
        while (!fuif.out.wb_valid) begin
            @(posedge CLK);
            timeout++;
            assert (timeout < timeout_cycles) else 
                $fatal("Timeout waiting for first valid");
        end
        
        // Hold backpressure for specified cycles
        repeat(backpressure_cycles) @(posedge CLK);
        
        // Release backpressure
        fuif.in.wb_ready = 1'b1;
        
        // Now count actual handshakes
        timeout = 0;
        while (wb_count < SLICE_W) begin
            @(posedge CLK);
            if (fuif.out.wb_valid && fuif.in.wb_ready) begin  // Check HANDSHAKE
                wb_count++;
            end
            timeout++;
            assert (timeout < timeout_cycles) else 
                $fatal("Timeout waiting for writeback during backpressure test");
        end
    endtask

    // Generic masking test - test with specific mask pattern
    task automatic test_masking(
        input int port_num,
        input logic [SLICE_W-1:0][15:0] v1,
        input logic [SLICE_W-1:0][15:0] v2,
        input fu_t usel,
        input logic [7:0] vd,
        input logic rm,
        input logic [SLICE_W-1:0] mask,
        input valu_op_t alu_op,
        input int timeout_cycles = 1000
    );
        int wb_count = 0;
        int timeout = 0;
        
        fuif.in.wb_ready = 1'b1;
        issue_from_port(port_num, v1, v2, usel, vd, rm, mask, alu_op);
        @(posedge CLK);
        clear_port(port_num);

        while (wb_count < SLICE_W) begin
            @(posedge CLK);
            if (fuif.out.wb_valid) begin
                wb_count++;
            end
            timeout++;
            assert (timeout < timeout_cycles) else 
                $fatal("Timeout waiting for writeback in masking test");
        end
    endtask

    task automatic sqrt_test_issue_port_0();
        logic [SLICE_W-1:0][15:0] v1, v2;
        v1 = '{16'h4110, 16'h4080}; //9,4
        v2 = '0;
        test_issue_port(0, v1, v2, SQRT, 1, 0, '1, VR_SUM);
    endtask

    task automatic sqrt_test_issue_port_1();
        logic [SLICE_W-1:0][15:0] v1, v2;
        v1 = '{16'h4110, 16'h4080}; //9,4
        v2 = '0;
        test_issue_port(1, v1, v2, SQRT, 2, 0, '1, VR_SUM);
    endtask

    task automatic sqrt_test_masking_1();
        logic [SLICE_W-1:0][15:0] v1, v2;
        v1 = '{16'h4110, 16'h4080}; //9,4
        v2 = '0;
        test_masking(0, v1, v2, SQRT, 1, 0, 2'b01, VR_SUM);
    endtask

    task automatic sqrt_test_masking_2();
        logic [SLICE_W-1:0][15:0] v1, v2;
        v1 = '{16'h4110, 16'h4080}; //9,4
        v2 = '0;
        test_masking(0, v1, v2, SQRT, 1, 0, 2'b10, VR_SUM);
    endtask

    task automatic sqrt_backpressure();
        logic [SLICE_W-1:0][15:0] v1, v2;
        v1 = '{16'h4110, 16'h4080}; //9,4
        v2 = '0;
        test_backpressure(0, v1, v2, SQRT, 10, 0, 2'b11, VR_SUM, 5);
    endtask

    task automatic sqrt_max_issue();
        test_max_issue(0, SQRT, 0, '1, VR_SUM, 10);
    endtask

    task automatic test_all_sqrt();
        sqrt_test_issue_port_0();
        sqrt_test_issue_port_1();
        sqrt_max_issue();
        sqrt_test_masking_1();
        sqrt_test_masking_2();
        sqrt_backpressure();
    endtask

    task automatic mul_test_issue_port_0();
        logic [SLICE_W-1:0][15:0] v1, v2;
        v1 = '{16'h4000, 16'h4080}; // 2.0, 4.0
        v2 = '{16'h3F80, 16'h4000}; // 1.0, 2.0
        test_issue_port(0, v1, v2, MUL, 1, 0, '1, VR_SUM);
    endtask

    task automatic mul_test_issue_port_1();
        logic [SLICE_W-1:0][15:0] v1, v2;
        v1 = '{16'h4000, 16'h4080}; // 2.0, 4.0
        v2 = '{16'h3F80, 16'h4000}; // 1.0, 2.0
        test_issue_port( 1, v1, v2, MUL, 2, 0, '1, VR_SUM);
    endtask

    task automatic mul_test_masking_1();
        logic [SLICE_W-1:0][15:0] v1, v2;
        v1 = '{16'h4000, 16'h4080}; // 2.0, 4.0
        v2 = '{16'h3F80, 16'h4000}; // 1.0, 2.0
        test_masking(0, v1, v2, MUL, 1, 0, 2'b01, VR_SUM);
    endtask

    task automatic mul_test_masking_2();
        logic [SLICE_W-1:0][15:0] v1, v2;
        v1 = '{16'h4000, 16'h4080}; // 2.0, 4.0
        v2 = '{16'h3F80, 16'h4000}; // 1.0, 2.0
        test_masking(0, v1, v2, MUL, 1, 0, 2'b10, VR_SUM);
    endtask

    task automatic mul_backpressure();
        logic [SLICE_W-1:0][15:0] v1, v2;
        v1 = '{16'h4000, 16'h4080}; // 2.0, 4.0
        v2 = '{16'h3F80, 16'h4000}; // 1.0, 2.0
        test_backpressure(0, v1, v2, MUL, 10, 0, 2'b11, VR_SUM, 5);
    endtask

    task automatic mul_max_issue();
        test_max_issue(0, MUL, 0, '1, VR_SUM, 10);
    endtask

    task automatic test_all_mul();
        mul_test_issue_port_0();
        mul_test_issue_port_1();
        mul_max_issue();
        mul_test_masking_1();
        mul_test_masking_2();
        mul_backpressure();
    endtask

    initial begin
        reset_dut();
        //test_all_sqrt();
        //test_all_mul();
        mul_max_issue();
        repeat(3) @(posedge CLK);
        $stop;
    end
endmodule