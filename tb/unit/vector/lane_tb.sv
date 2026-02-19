/*
Overall Lane Unit Testbench
Owner: Jacob Walter
This is the testbench for the new lane unit. This will do its best at being exaustive, but will likely lack coverage

Tests:
Individual FU tests
1. ALU add issued from port 1
2. ALU add issued from port 2
3. ALU Min reduction
4. ALU mask test
5. ALU max issue

6. Mult issued from port 1
7. Mult issued from port 2
8. Mult mask test
9. Mult max issue

10. Div issued from port 1
11. Div issued from port 2
12. Div Mask test
13. Div max issue

14. Exp issued from port 1
15. Exp issued from port 2
16. Exp mask test
17. Exp max issue

18. Sqrt Issued from port 1
19. Sqrt Issued from port 2
20. Sqrt mask test
21. Sqrt max issue

Multi Issue Tests:
22. Add and Mult same cycle
23. Mult and Sqrt same cycle
24. Exp and Sqrt same cycle

25. Backpressure all FUs at once
26. Constant Issuing to all FUs
27. Individual Backpressure Tests
*/

`timescale 1ns/1ps

`include "lane_if.vh"
`include "vector_pkg.vh"


module lane_tb;
    import vector_pkg::*;


    logic CLK;
    logic nRST;

    initial CLK = 1'b0;
    always #5 CLK = ~CLK;

    //instantiation
    lane_if lif();
    lane DUT (
        .CLK(CLK),
        .nRST(nRST),
        .lif(lif)
    );

    //Test visibility
    string current_test = "IDLE";

    //helper tasks

    //drives an input port, clocking is the responsibility of the caller.
    task automatic issue_to_port(
        input int port,
        input logic valid,
        input logic [SLICE_W-1:0][15:0] v1, v2,
        input fu_t usel,
        input logic [7:0] vd,
        input logic rm,
        input logic [SLICE_W-1:0] mask,
        input valu_op_t alu_op
    );
        lif.in.input_valid[port] = valid;
        lif.in.v1[port] = v1;
        lif.in.v2[port] = v2;
        lif.in.usel[port] = usel;
        lif.in.vd[port] = vd;
        lif.in.rm[port] = rm;
        lif.in.mask[port] = mask;
        lif.in.aluop[port] = alu_op;
    endtask

    //drives the ready signals from the RC for backpressure testing. Takes in bits and drives the input signals
    task automatic drive_ready(
        input logic [LANE_FU_COUNT-1:0] status 
    );
        lif.in.ready = status;
    endtask

    //clears an input port
    task automatic clear_port(input int port);
        lif.in.input_valid[port] = 0;
        lif.in.v1[port] = '0;
        lif.in.v2[port] = '0;
        lif.in.usel[port] = VALU;  // or whatever default
        lif.in.vd[port] = '0;
        lif.in.rm[port] = 0;
        lif.in.mask[port] = '0;
        lif.in.aluop[port] = VR_MAX;  // or whatever default
    endtask

    //clears all ports
    task automatic clear_all_ports();
        for (int i = 0; i < LANE_ISSUE_W; i++) begin
            clear_port(i);
        end
    endtask

    //this will delay until a specific FU is ready. 0 is ALU, 1 is mult, 2 is div, 3 is exp, and 4 is sqrt
    task automatic wait_for_fu_ready(
        input int fu_idx,
        input int timeout = 100
    );

        int cycles = 0;

        // Wait until ready is observed on a clock edge
        while (cycles < timeout) begin

            @(posedge CLK);

            if (lif.out.units[fu_idx].input_ready)
                return;

            cycles++;

        end

        $error("Timeout waiting for FU %0d to be ready", fu_idx);

    endtask

    //function waits for a specific FU to have valid data on the output
    task automatic wait_for_fu_valid(
        input int fu_idx,
        input int timeout = 100
    );
        int cycles = 0;

        while (!lif.out.units[fu_idx].wb_valid && cycles <= timeout) begin
            @(posedge CLK);
            cycles++;
        end

        if (cycles >= timeout) begin
            $error("Timeout waiting for FU %0d to be valid", fu_idx);
        end
    endtask

    //Issues to a port for 1 cycle and then clears itself. Useful for testing individual FUs
    task automatic issue_pulse(
        input int port,
        input logic [SLICE_W-1:0][15:0] v1, v2,
        input fu_t usel,
        input logic [7:0] vd,
        input logic rm,
        input logic [SLICE_W-1:0] mask,
        input valu_op_t alu_op
    );
        issue_to_port(port, 1, v1, v2, usel, vd, rm, mask, alu_op);
        @(posedge CLK);
        clear_port(port);
    endtask
    
    //issues to multiple FUs at once. Paramaterized in case more issue ports ever get added. This doesnt care about masking as it is tested on the unit level
    task automatic multi_issue(
        input int num_ports,
        input logic [LANE_ISSUE_W-1:0][SLICE_W-1:0][15:0] v1_array, v2_array,
        input fu_t [LANE_ISSUE_W-1:0] usel_array,
        input logic [LANE_ISSUE_W-1:0][7:0] vd_array,
        input valu_op_t [LANE_ISSUE_W-1:0] alu_op_array
    );
        for (int i = 0; i < num_ports; i++) begin
            issue_to_port(i, 1, v1_array[i], v2_array[i], usel_array[i], 
                        vd_array[i], 0, '1, alu_op_array[i]);
        end
    endtask


    task automatic reset_dut();
        nRST = 0;
        clear_all_ports();
        drive_ready('1);
        repeat(5) @(posedge CLK);
        nRST = 1;
        repeat(2) @(posedge CLK);
    endtask


    //tests

    //Issues an instruction to a FU from a port and verifies the output signals
    task automatic fu_issue_test(
        input int port, 
        input fu_t usel,
        input valu_op_t op,
        input logic [SLICE_W-1:0][15:0] v1,
        input logic [SLICE_W-1:0][15:0] v2,
        input logic [7:0] vd,
        input logic rm,
        input logic [SLICE_W-1:0] mask = '1
    );
        // Issue instruction to the FU
        issue_pulse(port, v1, v2, usel, vd, rm, mask, op);

        // Allow time for all slices to stream out
        repeat (SLICE_W) @(posedge CLK);

endtask


    //issues num_issues instructions to the FU as fast as the unit will accept them
    task automatic fu_max_issue(
        input int port,
        input fu_t fu,
        input valu_op_t op,
        input int num_issues,
        input logic [SLICE_W-1:0] mask = '1
    );

        logic [SLICE_W-1:0][15:0] v1, v2;
        logic [7:0] vd;

        drive_ready('1);

        for (int i = 0; i < num_issues; i++) begin

            vd = i[7:0];

            for (int slice = 0; slice < SLICE_W; slice++) begin
                v1[slice] = 16'h1000 + (i * 16) + slice;
                v2[slice] = 16'h2000 + (i * 16) + slice;
            end

            // Wait until FU ready
            wait_for_fu_ready(fu);

            // Issue instruction
            issue_to_port(port, 1, v1, v2, fu, vd, 0, mask, op);

            @(posedge CLK);
            clear_port(port);

            $display("Issued FU %0d operation: %0d", fu, i);

            

        end

        repeat(10) @(posedge CLK);

    endtask

    task automatic fu_backpressure_test(
        input int port,
        input fu_t fu,
        input valu_op_t op
    );

        logic [SLICE_W-1:0][15:0] v1, v2;
        logic [7:0] vd;

        logic [LANE_FU_COUNT-1:0] bp_mask;

        vd = 8'd42;

        for (int slice = 0; slice < SLICE_W; slice++) begin
            v1[slice] = 16'h1000 + slice;
            v2[slice] = 16'h2000 + slice;
        end

        // Apply backpressure (not ready)
        bp_mask = '1;
        bp_mask[fu] = 0;
        drive_ready(bp_mask);

        // Wait until unit can accept first instruction
        wait (lif.out.units[fu].input_ready == 1);

        issue_to_port(port, 1, v1, v2, fu, vd, 0, '1, op);
        @(posedge CLK);
        clear_port(port);

        $display("Issued operation 0");

        // Issue second instruction
        wait (lif.out.units[fu].input_ready == 1);

        issue_to_port(port, 1, v1, v2, fu, vd+1, 0, '1, op);
        @(posedge CLK);
        clear_port(port);

        $display("Issued operation 1");

        // Hold backpressure for several cycles
        repeat(6) @(posedge CLK);

        // Release backpressure
        drive_ready('1);

        // Allow pipeline to drain
        repeat(SLICE_W * 2) @(posedge CLK);

    endtask



    //this runs all the ALU testcases as defined at the top of the file
    task automatic test_alu();
        logic [SLICE_W-1:0][15:0] test_v1, test_v2;
        $display("\n=====================================================");
        $display("Starting ALU Tests");
        $display("=====================================================\n");

        test_v1 = {16'h3f80, 16'h4000};
        test_v2 = {16'h4000, 16'h4100};

        current_test = "ALU_ADD_PORT0";
        $display("=== Test 1: ALU ADD from Port 0 ===");
        fu_issue_test(0, VALU, VR_SUM, test_v1, test_v2, 8'd1, 0);
        $display("Test 1 Complete\n");

        current_test = "ALU_ADD_PORT1";
        $display("=== Test 2: ALU ADD from Port 1 ===");
        fu_issue_test(1, VALU, VR_SUM, test_v1, test_v2, 8'd2, 0);
        $display("Test 2 Complete\n");

        current_test = "ALU_MIN_REDUCTION";
        $display("=== Test 3: ALU MIN Reduction ===");
        test_v1 = {16'h4200, 16'h4100};
        test_v2 = {16'h4000, 16'h4300};
        fu_issue_test(0, VALU, VR_MIN, test_v1, test_v2, 8'd3, 1);
        $display("Test 3 Complete\n");

        current_test = "ALU_MASK_TEST";
        $display("=== Test 4: ALU Mask Test ===");
        test_v1 = {16'h3f80, 16'h4000};
        test_v2 = {16'h4000, 16'h4100};
        fu_issue_test(0, VALU, VR_SUM, test_v1, test_v2, 8'd4, 0, 2'b10);
        $display("Test 4 Complete\n");

        current_test = "ALU_MAX_ISSUE";
        $display("=== Test 5: ALU Maximum Issue Rate ===");
        fu_max_issue(0, VALU, VR_SUM, 10);
        $display("Test 5 Complete\n");

        current_test = "ALU_BACKPRESSURE";
        $display("=== Test 6: ALU Backpressure Test ===");
        fu_backpressure_test(0, VALU, VR_SUM);
        $display("Test 6 Complete\n");

        current_test = "ALU_COMPLETE";
        $display("ALU tests complete");
    endtask

    //this runs all the multiplier tests that are specified at the top of the file
    task automatic test_mult();
        logic [SLICE_W-1:0][15:0] test_v1, test_v2;
        $display("\n=====================================================");
        $display("Starting MULT Tests");
        $display("=====================================================\n");

        test_v1 = {16'h3f80, 16'h4000};
        test_v2 = {16'h4000, 16'h4100};

        current_test = "MULT_PORT0";
        $display("=== Test 1: MULT from Port 0 ===");
        fu_issue_test(0, MUL, VR_SUM, test_v1, test_v2, 8'd1, 0);
        $display("Test 1 Complete\n");

        current_test = "MULT_PORT1";
        $display("=== Test 2: MULT from Port 1 ===");
        fu_issue_test(1, MUL, VR_SUM, test_v1, test_v2, 8'd2, 0);
        $display("Test 2 Complete\n");

        current_test = "MULT_MASK_TEST";
        $display("=== Test 3: MULT Mask Test ===");
        test_v1 = {16'h3f80, 16'h4000};
        test_v2 = {16'h4000, 16'h4100};
        fu_issue_test(0, MUL, VR_SUM, test_v1, test_v2, 8'd3, 0, 2'b10);
        $display("Test 3 Complete\n");

        current_test = "MULT_MAX_ISSUE";
        $display("=== Test 4: MULT Maximum Issue Rate ===");
        fu_max_issue(0, MUL, VR_SUM, 10);
        $display("Test 4 Complete\n");

        current_test = "MULT_BACKPRESSURE";
        $display("=== Test 5: MULT Backpressure Test ===");
        fu_backpressure_test(0, MUL, VR_SUM);
        $display("Test 5 Complete\n");


        current_test = "MULT_COMPLETE";
        $display("MULT tests complete");
    endtask 

    //this runs all the divider tests that are specified at the top of the file
    task automatic test_div();
        logic [SLICE_W-1:0][15:0] test_v1, test_v2;
        $display("\n=====================================================");
        $display("Starting DIV Tests");
        $display("=====================================================\n");

        test_v1 = {16'h4000, 16'h4100};
        test_v2 = {16'h3f80, 16'h4000};

        current_test = "DIV_PORT0";
        $display("=== Test 1: DIV from Port 0 ===");
        fu_issue_test(0, DIV, VR_SUM, test_v1, test_v2, 8'd1, 0);
        $display("Test 1 Complete\n");

        current_test = "DIV_PORT1";
        $display("=== Test 2: DIV from Port 1 ===");
        fu_issue_test(1, DIV, VR_SUM, test_v1, test_v2, 8'd2, 0);
        $display("Test 2 Complete\n");

        current_test = "DIV_MASK_TEST";
        $display("=== Test 3: DIV Mask Test ===");
        test_v1 = {16'h4000, 16'h4100};
        test_v2 = {16'h3f80, 16'h4000};
        fu_issue_test(0, DIV, VR_SUM, test_v1, test_v2, 8'd3, 0, 2'b10);
        $display("Test 3 Complete\n");

        current_test = "DIV_MAX_ISSUE";
        $display("=== Test 4: DIV Maximum Issue Rate ===");
        fu_max_issue(0, DIV, VR_SUM, 10);
        $display("Test 4 Complete\n");

        current_test = "DIV_BACKPRESSURE";
        $display("=== Test 5: DIV Backpressure Test ===");
        fu_backpressure_test(0, DIV, VR_SUM);
        $display("Test 5 Complete\n");

        current_test = "DIV_COMPLETE";
        $display("DIV tests complete");
    endtask

    //this runs all the exp tests that are specified at the top of the file
    task automatic test_exp();
        logic [SLICE_W-1:0][15:0] test_v1, test_v2;
        $display("\n=====================================================");
        $display("Starting EXP Tests");
        $display("=====================================================\n");

        test_v1 = {16'h3f80, 16'h4000};
        test_v2 = '0;  // EXP only uses v1

        current_test = "EXP_PORT0";
        $display("=== Test 1: EXP from Port 0 ===");
        fu_issue_test(0, EXP, VR_SUM, test_v1, test_v2, 8'd1, 0);
        $display("Test 1 Complete\n");

        current_test = "EXP_PORT1";
        $display("=== Test 2: EXP from Port 1 ===");
        fu_issue_test(1, EXP, VR_SUM, test_v1, test_v2, 8'd2, 0);
        $display("Test 2 Complete\n");

        current_test = "EXP_MASK_TEST";
        $display("=== Test 3: EXP Mask Test ===");
        test_v1 = {16'h3f80, 16'h4000};
        fu_issue_test(0, EXP, VR_SUM, test_v1, test_v2, 8'd3, 0, 2'b10);
        $display("Test 3 Complete\n");

        current_test = "EXP_MAX_ISSUE";
        $display("=== Test 4: EXP Maximum Issue Rate ===");
        fu_max_issue(0, EXP, VR_SUM, 10);
        $display("Test 4 Complete\n");

        current_test = "EXP_BACKPRESSURE";
        $display("=== Test 5: EXP Backpressure Test ===");
        fu_backpressure_test(0, EXP, VR_SUM);
        $display("Test 5 Complete\n");

        current_test = "EXP_COMPLETE";
        $display("EXP tests complete");
    endtask

    //this runs all the sqrt tests that are specified at the top of the file
    task automatic test_sqrt();
        logic [SLICE_W-1:0][15:0] test_v1, test_v2;
        $display("\n=====================================================");
        $display("Starting SQRT Tests");
        $display("=====================================================\n");

        test_v1 = {16'h4000, 16'h4100};
        test_v2 = '0;  // SQRT only uses v1

        current_test = "SQRT_PORT0";
        $display("=== Test 1: SQRT from Port 0 ===");
        fu_issue_test(0, SQRT, VR_SUM, test_v1, test_v2, 8'd1, 0);
        $display("Test 1 Complete\n");

        current_test = "SQRT_PORT1";
        $display("=== Test 2: SQRT from Port 1 ===");
        fu_issue_test(1, SQRT, VR_SUM, test_v1, test_v2, 8'd2, 0);
        $display("Test 2 Complete\n");

        current_test = "SQRT_MASK_TEST";
        $display("=== Test 3: SQRT Mask Test ===");
        test_v1 = {16'h4000, 16'h4100};
        fu_issue_test(0, SQRT, VR_SUM, test_v1, test_v2, 8'd3, 0, 2'b10);
        $display("Test 3 Complete\n");

        current_test = "SQRT_MAX_ISSUE";
        $display("=== Test 4: SQRT Maximum Issue Rate ===");
        fu_max_issue(0, SQRT, VR_SUM, 10);
        $display("Test 4 Complete\n");
        
        current_test = "SQRT_BACKPRESSURE";
        $display("=== Test 5: SQRT Backpressure Test ===");
        fu_backpressure_test(0, SQRT, VR_SUM);
        $display("Test 5 Complete\n");

        current_test = "SQRT_COMPLETE";
        $display("SQRT tests complete");
    endtask

    task automatic test_multi_issue_alu_mult();

        logic [SLICE_W-1:0][15:0] test_v1_alu, test_v2_alu;
        logic [SLICE_W-1:0][15:0] test_v1_mult, test_v2_mult;

        $display("\n=====================================================");
        $display("Starting Multi-Issue Test: ALU + MULT");
        $display("=====================================================\n");

        current_test = "MULTI_ALU_MULT";

        // Setup test data
        test_v1_alu  = {16'h3f80, 16'h4000};
        test_v2_alu  = {16'h4000, 16'h4100};

        test_v1_mult = {16'h3f80, 16'h4000};
        test_v2_mult = {16'h4000, 16'h4100};

        // Wait until both units ready
        wait_for_fu_ready(VALU);
        wait_for_fu_ready(MUL);

        // Issue both in same cycle
        issue_to_port(0, 1, test_v1_alu,  test_v2_alu,  VALU, 8'd1, 0, '1, VR_SUM);
        issue_to_port(1, 1, test_v1_mult, test_v2_mult, MUL,  8'd2, 0, '1, VR_SUM);

        @(posedge CLK);

        clear_port(0);
        clear_port(1);

        $display("Issued ALU and MULT simultaneously");

        repeat(SLICE_W + 5) @(posedge CLK);

        $display("Multi-Issue ALU+MULT Test Complete\n");

    endtask

    task automatic test_multi_issue_mult_sqrt();

        logic [SLICE_W-1:0][15:0] test_v1_mult, test_v2_mult;
        logic [SLICE_W-1:0][15:0] test_v1_sqrt, test_v2_sqrt;

        $display("\n=====================================================");
        $display("Starting Multi-Issue Test: MULT + SQRT");
        $display("=====================================================\n");

        current_test = "MULTI_MULT_SQRT";

        test_v1_mult = {16'h3f80, 16'h4000};
        test_v2_mult = {16'h4000, 16'h4100};

        test_v1_sqrt = {16'h4000, 16'h4100};
        test_v2_sqrt = '0;

        wait_for_fu_ready(MUL);
        wait_for_fu_ready(SQRT);

        issue_to_port(0, 1, test_v1_mult, test_v2_mult, MUL,  8'd3, 0, '1, VR_SUM);
        issue_to_port(1, 1, test_v1_sqrt, test_v2_sqrt, SQRT, 8'd4, 0, '1, VR_SUM);

        @(posedge CLK);

        clear_port(0);
        clear_port(1);

        $display("Issued MULT and SQRT simultaneously");

        repeat(SLICE_W + 30) @(posedge CLK);

        $display("Multi-Issue MULT+SQRT Test Complete\n");

    endtask

    task automatic test_multi_issue_sqrt_exp();

        logic [SLICE_W-1:0][15:0] test_v1_sqrt, test_v2_sqrt;
        logic [SLICE_W-1:0][15:0] test_v1_exp,  test_v2_exp;

        $display("\n=====================================================");
        $display("Starting Multi-Issue Test: SQRT + EXP");
        $display("=====================================================\n");

        current_test = "MULTI_SQRT_EXP";

        test_v1_sqrt = {16'h4000, 16'h4100};
        test_v2_sqrt = '0;

        test_v1_exp  = {16'h3f80, 16'h4000};
        test_v2_exp  = '0;

        wait_for_fu_ready(SQRT);
        wait_for_fu_ready(EXP);

        issue_to_port(0, 1, test_v1_sqrt, test_v2_sqrt, SQRT, 8'd5, 0, '1, VR_SUM);
        issue_to_port(1, 1, test_v1_exp,  test_v2_exp,  EXP,  8'd6, 0, '1, VR_SUM);

        @(posedge CLK);

        clear_port(0);
        clear_port(1);

        $display("Issued SQRT and EXP simultaneously");

        repeat(SLICE_W + 15) @(posedge CLK);

        $display("Multi-Issue SQRT+EXP Test Complete\n");

    endtask


    //saturation test. Does not verify the outputs, visual debugging will be required
    task automatic lane_saturation();
         logic [SLICE_W-1:0][15:0] test_v1, test_v2, test_v2_zero;
        int num_issues_per_fu = 5;
        int total_issues = num_issues_per_fu * 5;
        int issue_count = 0;
        int fu_issue_count[5] = '{0, 0, 0, 0, 0};
        int port0_issued;
        int port1_issued;
        int fu_issued_port0;
        int fu_issued_port1;
        fu_t fu;

        $display("\n=====================================================");
        $display("Starting Lane Saturation Test");
        $display("=====================================================\n");
        current_test = "LANE_SATURATION";

        test_v1 = {16'h3f80, 16'h4000};
        test_v2 = {16'h4000, 16'h4100};
        test_v2_zero = '0;

        
            while (issue_count < total_issues) begin
                port0_issued = 0;
                port1_issued = 0;
                fu_issued_port0 = 0;
                fu_issued_port1 = 0;

            for (int i = 0; i < LANE_FU_COUNT; i++) begin //find a FU that we can issue to on port 0
                fu = fu_t'(i);
                if (fu_issue_count[fu] < num_issues_per_fu && (lif.out.units[fu].input_ready == 1)) begin
                    logic [SLICE_W-1:0][15:0] v2_to_use = (fu == 3 || fu == 4) ? test_v2_zero : test_v2; //FU is exp or sqrt
                    issue_to_port(0, 1, test_v1, v2_to_use, fu, (fu * 10 + fu_issue_count[fu]), 0, '1, VR_SUM);
                    fu_issue_count[fu]++;
                    issue_count++;
                    port0_issued = 1;
                    fu_issued_port0 = fu;
                    $display("Issued to FU %0d on port 0, operation %0d", fu, fu_issue_count[fu]-1);
                    break;
                end
            end
            for (int j = 0; j < LANE_FU_COUNT; j++) begin //find a differnt port we can issue to
                fu = fu_t'(j);
                if (port0_issued && fu == fu_issued_port0) continue; //if the current FU that we are looking at is already issued to port 1, skip

                if (fu_issue_count[fu] < num_issues_per_fu && lif.out.units[fu].input_ready == 1) begin
                    logic [SLICE_W-1:0][15:0] v2_to_use = (fu == EXP || fu == SQRT) ? test_v2_zero : test_v2;
                    valu_op_t op = (fu == VALU) ? VR_SUM : VR_SUM;
                    
                    issue_to_port(1, 1, test_v1, v2_to_use, fu, (fu * 10 + fu_issue_count[fu]), 0, '1, op);
                    fu_issue_count[fu]++;
                    issue_count++;
                    port1_issued = 1;
                    $display("Issued to FU %0d on port 1, operation %0d", fu, fu_issue_count[fu]-1);
                    break;
                end
            end

            @(posedge CLK);
            if (port0_issued) clear_port(0);
            if (port1_issued) clear_port(1); //clear the ports for the next issue
            end

    endtask //automatic

    initial begin
        reset_dut();
        @(posedge CLK);
        //test_mult();
        //test_sqrt();
        test_multi_issue_mult_sqrt();

        $stop;
    end

endmodule
