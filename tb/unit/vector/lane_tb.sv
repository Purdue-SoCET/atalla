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
    task automatic drive_rc_ready(
        input logic [LANE_FU_COUNT-1:0] status 
    );
        lif.in.rc_ready = status;
    endtask

    //clears an input port
    task automatic clear_port(input int port);
        lif.in.input_valid[port] = 0;
        lif.in.v1[port] = '0;
        lif.in.v2[port] = '0;
        lif.in.usel[port] = ALU_FU;  // or whatever default
        lif.in.vd[port] = '0;
        lif.in.rm[port] = 0;
        lif.in.mask[port] = '0;
        lif.in.aluop[port] = VADD;  // or whatever default
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

        while (!lif.out.units[fu_idx].input_ready && cycles <= timeout) begin
            @(posedge CLK);
            cycles++;
        end
        if (cycles >= timeout_cycles) begin
            $error("Timeout waiting for FU %0d to be ready", fu_idx);
        end
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

        if (cycles >= timeout_cycles) begin
            $error("Timeout waiting for FU %0d to be ready", fu_idx);
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
        drive_rc_ready('1);
        repeat(5) @(posedge CLK);
        nRST = 1;
        repeat(2) @(posedge CLK);
    endtask


    //tests

    //Issues an instruction to a FU from a port and verifies the output signals
    task automatic fu_issue_test(
        input int port, 
        input int fu,
        input valu_op_t op,
        input logic [SLICE_W-1:0][15:0] v1,
        input logic [SLICE_W-1:0][15:0] v2,
        input logic [7:0] vd,
        input logic rm,  // Reduction mode
        input logic [SLICE_W-1:0] mask = '1  // Default to all enabled
    );
        //issue instruction to the FU
        issue_pulse(port, v1, v2, fu, vd, rm, mask, op);
        
        // Check each slice as it streams out
        for (int slice = 0; slice < SLICE_W; slice++) begin
            wait_for_fu_valid(fu); 
            
            assert (lif.out.units[fu].valid == 1) else 
                $error("FU %0d Port %0d: Slice %0d - Valid not asserted", fu, port, slice);
            assert (lif.out.units[fu].rm == rm) else 
                $error("FU %0d Port %0d: Slice %0d - Reduction Mode Incorrect: got %0b, expected %0b", 
                    fu, port, slice, lif.out.units[fu].rm, rm);
            assert (lif.out.units[fu].mask[slice] == mask[slice]) else
                $error("FU %0d Port %0d: Slice %0d - Mask Incorrect: got %0b, expected %0b", 
                    fu, port, slice, lif.out.units[fu].mask[slice], mask[slice]);
            assert (lif.out.units[fu].vd == vd) else 
                $error("FU %0d Port %0d: Slice %0d - VD Incorrect: got %0d, expected %0d", 
                    fu, port, slice, lif.out.units[fu].vd, vd);            
            @(posedge CLK);
        end
    endtask

    //issues num_issues instructions to the FU as fast as the unit will accept them
    task automatic fu_max_issue(
        input int port,
        input int fu,
        input valu_op_t op,
        input int num_issues,
        input logic [SLICE_W-1:0] mask = '1
    );
        logic [SLICE_W-1:0][15:0] v1, v2;
        logic [7:0] vd;

        //have to fork-join as i need one constantly issuing and one validating the outputs
        fork
            // Issuing thread - issues as soon as ready
            begin
                for (int i = 0; i < num_issues; i++) begin
                    // Generate unique data for each issue
                    vd = i[7:0];
                    for (int slice = 0; slice < SLICE_W; slice++) begin
                        v1[slice] = 16'h1000 + (i * 16) + slice;
                        v2[slice] = 16'h2000 + (i * 16) + slice;
                    end
                    
                    // Wait for FU to be ready to accept new work
                    wait (lif.out.units[fu].ready == 1);
                    
                    // Issue the instruction
                    issue_to_port(port, 1, v1, v2, fu, vd, 0, mask, op);
                    @(posedge CLK);
                    clear_port(port);
                    
                    $display("Issued FU %0d operation: %0d", fu, i);
                end
            end
            
            // Validation thread
            begin
                for (int i = 0; i < num_issues; i++) begin
                    automatic logic [7:0] expected_vd = i[7:0];
                    
                    // Check each slice as it streams out
                    for (int slice = 0; slice < SLICE_W; slice++) begin
                        wait_for_fu_valid(fu); 
                        
                        assert (lif.out.units[fu].valid == 1) else 
                            $error("FU %0d Continuous Issue %0d Port %0d: Slice %0d - Valid not asserted", 
                                fu, i, port, slice);
                        assert (lif.out.units[fu].rm == 0) else 
                            $error("FU %0d Continuous Issue %0d Port %0d: Slice %0d - Reduction Mode Incorrect", 
                                fu, i, port, slice);
                        assert (lif.out.units[fu].mask[slice] == mask[slice]) else
                            $error("FU %0d Continuous Issue %0d Port %0d: Slice %0d - Mask Incorrect: got %0b, expected %0b", 
                                fu, i, port, slice, lif.out.units[fu].mask[slice], mask[slice]);
                        assert (lif.out.units[fu].vd == expected_vd) else 
                            $error("FU %0d Continuous Issue %0d Port %0d: Slice %0d - VD Incorrect: got %0d, expected %0d", 
                                fu, i, port, slice, lif.out.units[fu].vd, expected_vd);            
                        @(posedge CLK);
                    end
                    
                    $display("Validated FU %0d operation: %0d", fu, i);
                end
            end
        join
    endtask //automatic

    task automatic fu_backpressure_test(
        input int port,
        input int fu,
        input valu_op_t op
    );
        logic [SLICE_W-1:0][15:0] v1, v2;
        logic [7:0] vd;
        int issued_count = 0;
        int validated_count = 0;

        //data
        vd = 8'd42;
        for (int slice = 0; slice < SLICE_W; slice++) begin
            v1[slice] = 16'h1000 + slice;
            v2[slice] = 16'h2000 + slice;
        end

        //another fork join. This time with 3 threads. 1 to issue constantly, 1 to validate the outputs, and one to control the backpressure
        fork
            //issuing thread
            begin
                wait (lif.out.units[fu].ready == 1);
                issue_to_port(port, 1, v1, v2, fu, vd, 0, '1, op);
                @(posedge CLK);
                clear_port(port);
                issued_count++;
                $display("Issued operation %0d", issued_count);

                //issue second instruction as soon as ready
                wait (lif.out.units[fu].ready == 1);
                issue_to_port(port, 1, v1, v2, fu, vd + 1, 0, '1, op);
                @(posedge CLK);
                clear_port(port);
                issued_count++;
                $display("Issued operation %0d", issued_count);
            end

            //backpressure control thread
            begin
                logic [LANE_FU_COUNT-1:0] bp_mask = '1;
                bp_mask[fu] = 0;  // Set target FU to not ready
                drive_rc_ready(bp_mask);
                wait_for_fu_valid(fu); //wait until we get data from the unit
                repeat(3) @(posedge CLK); //wait a few more cycles to release pressure
                drive_rc_ready('1); //release backpressure
            end

            //validation thread
            begin
            // Validate both issued operations
                for (int op_num = 0; op_num < 2; op_num++) begin
                    automatic logic [7:0] expected_vd = vd + op_num;
                    
                    // Check each slice as it streams out
                    for (int slice = 0; slice < SLICE_W; slice++) begin
                        // Wait for valid AND wb_ready (handshake)
                        wait (lif.out.units[fu].valid == 1 && lif.in.rc_ready[fu] == 1);
                        
                        assert (lif.out.units[fu].valid == 1) else 
                            $error("FU %0d Backpressure Test Op %0d Port %0d: Slice %0d - Valid not asserted", 
                                fu, op_num, port, slice);
                        assert (lif.out.units[fu].rm == 0) else 
                            $error("FU %0d Backpressure Test Op %0d Port %0d: Slice %0d - Reduction Mode Incorrect", 
                                fu, op_num, port, slice);
                        assert (lif.out.units[fu].mask[slice] == 1) else
                            $error("FU %0d Backpressure Test Op %0d Port %0d: Slice %0d - Mask Incorrect: got %0b, expected 1", 
                                fu, op_num, port, slice, lif.out.units[fu].mask[slice]);
                        assert (lif.out.units[fu].vd == expected_vd) else 
                            $error("FU %0d Backpressure Test Op %0d Port %0d: Slice %0d - VD Incorrect: got %0d, expected %0d", 
                                fu, op_num, port, slice, lif.out.units[fu].vd, expected_vd);            
                        @(posedge CLK);
                    end
                    
                    validated_count++;
                    $display("Validated operation: %0d", validated_count);
                end
            end
        join
    endtask //automatic


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
        fu_issue_test(0, 0, VR_SUM, test_v1, test_v2, 8'd1, 0);
        $display("Test 1 Complete\n");

        current_test = "ALU_ADD_PORT1";
        $display("=== Test 2: ALU ADD from Port 1 ===");
        fu_issue_test(1, 0, VR_SUM, test_v1, test_v2, 8'd2, 0);
        $display("Test 2 Complete\n");

        current_test = "ALU_MIN_REDUCTION";
        $display("=== Test 3: ALU MIN Reduction ===");
        test_v1 = {16'h4200, 16'h4100};
        test_v2 = {16'h4000, 16'h4300};
        fu_issue_test(0, 0, VR_MIN, test_v1, test_v2, 8'd3, 1);
        $display("Test 3 Complete\n");

        current_test = "ALU_MASK_TEST";
        $display("=== Test 4: ALU Mask Test ===");
        test_v1 = {16'h3f80, 16'h4000};
        test_v2 = {16'h4000, 16'h4100};
        fu_issue_test(0, 0, VR_SUM, test_v1, test_v2, 8'd4, 0, 2'b10);
        $display("Test 4 Complete\n");

        current_test = "ALU_MAX_ISSUE";
        $display("=== Test 5: ALU Maximum Issue Rate ===");
        fu_max_issue(0, 0, VR_SUM, 10);
        $display("Test 5 Complete\n");

        current_test = "ALU_BACKPRESSURE";
        $display("=== Test 6: ALU Backpressure Test ===");
        fu_backpressure_test(0, 0, VR_SUM);
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
        fu_issue_test(0, 1, VR_SUM, test_v1, test_v2, 8'd1, 0);
        $display("Test 1 Complete\n");

        current_test = "MULT_PORT1";
        $display("=== Test 2: MULT from Port 1 ===");
        fu_issue_test(1, 1, VR_SUM, test_v1, test_v2, 8'd2, 0);
        $display("Test 2 Complete\n");

        current_test = "MULT_MASK_TEST";
        $display("=== Test 3: MULT Mask Test ===");
        test_v1 = {16'h3f80, 16'h4000};
        test_v2 = {16'h4000, 16'h4100};
        fu_issue_test(0, 1, VR_SUM, test_v1, test_v2, 8'd3, 0, 2'b10);
        $display("Test 3 Complete\n");

        current_test = "MULT_MAX_ISSUE";
        $display("=== Test 4: MULT Maximum Issue Rate ===");
        fu_max_issue(0, 1, VR_SUM, 10);
        $display("Test 4 Complete\n");

        current_test = "MULT_BACKPRESSURE";
        $display("=== Test 5: MULT Backpressure Test ===");
        fu_backpressure_test(0, 1, VR_SUM);
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
        fu_issue_test(0, 2, VR_SUM, test_v1, test_v2, 8'd1, 0);
        $display("Test 1 Complete\n");

        current_test = "DIV_PORT1";
        $display("=== Test 2: DIV from Port 1 ===");
        fu_issue_test(1, 2, VR_SUM, test_v1, test_v2, 8'd2, 0);
        $display("Test 2 Complete\n");

        current_test = "DIV_MASK_TEST";
        $display("=== Test 3: DIV Mask Test ===");
        test_v1 = {16'h4000, 16'h4100};
        test_v2 = {16'h3f80, 16'h4000};
        fu_issue_test(0, 2, VR_SUM, test_v1, test_v2, 8'd3, 0, 2'b10);
        $display("Test 3 Complete\n");

        current_test = "DIV_MAX_ISSUE";
        $display("=== Test 4: DIV Maximum Issue Rate ===");
        fu_max_issue(0, 2, VR_SUM, 10);
        $display("Test 4 Complete\n");

        current_test = "DIV_BACKPRESSURE";
        $display("=== Test 5: DIV Backpressure Test ===");
        fu_backpressure_test(0, 2, VR_SUM);
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
        fu_issue_test(0, 3, VR_SUM, test_v1, test_v2, 8'd1, 0);
        $display("Test 1 Complete\n");

        current_test = "EXP_PORT1";
        $display("=== Test 2: EXP from Port 1 ===");
        fu_issue_test(1, 3, VR_SUM, test_v1, test_v2, 8'd2, 0);
        $display("Test 2 Complete\n");

        current_test = "EXP_MASK_TEST";
        $display("=== Test 3: EXP Mask Test ===");
        test_v1 = {16'h3f80, 16'h4000};
        fu_issue_test(0, 3, VR_SUM, test_v1, test_v2, 8'd3, 0, 2'b10);
        $display("Test 3 Complete\n");

        current_test = "EXP_MAX_ISSUE";
        $display("=== Test 4: EXP Maximum Issue Rate ===");
        fu_max_issue(0, 3, VR_SUM, 10);
        $display("Test 4 Complete\n");

        current_test = "EXP_BACKPRESSURE";
        $display("=== Test 5: EXP Backpressure Test ===");
        fu_backpressure_test(0, 3, VR_SUM);
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
        fu_issue_test(0, 4, VR_SUM, test_v1, test_v2, 8'd1, 0);
        $display("Test 1 Complete\n");

        current_test = "SQRT_PORT1";
        $display("=== Test 2: SQRT from Port 1 ===");
        fu_issue_test(1, 4, VR_SUM, test_v1, test_v2, 8'd2, 0);
        $display("Test 2 Complete\n");

        current_test = "SQRT_MASK_TEST";
        $display("=== Test 3: SQRT Mask Test ===");
        test_v1 = {16'h4000, 16'h4100};
        fu_issue_test(0, 4, VR_SUM, test_v1, test_v2, 8'd3, 0, 2'b10);
        $display("Test 3 Complete\n");

        current_test = "SQRT_MAX_ISSUE";
        $display("=== Test 4: SQRT Maximum Issue Rate ===");
        fu_max_issue(0, 4, VR_SUM, 10);
        $display("Test 4 Complete\n");

        current_test = "SQRT_BACKPRESSURE";
        $display("=== Test 5: SQRT Backpressure Test ===");
        fu_backpressure_test(0, 4, VR_SUM);
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
        test_v1_alu = {16'h3f80, 16'h4000};
        test_v2_alu = {16'h4000, 16'h4100};
        test_v1_mult = {16'h3f80, 16'h4000};
        test_v2_mult = {16'h4000, 16'h4100};
        
        fork
            // Issue to ALU from port 0
            begin
                issue_pulse(0, test_v1_alu, test_v2_alu, 0, 8'd1, 0, '1, VR_SUM);
                
                // Validate ALU output
                for (int slice = 0; slice < SLICE_W; slice++) begin
                    wait_for_fu_valid(0);
                    assert (lif.out.units[0].valid == 1) else 
                        $error("Multi-Issue ALU+MULT: ALU Slice %0d - Valid not asserted", slice);
                    assert (lif.out.units[0].vd == 8'd1) else 
                        $error("Multi-Issue ALU+MULT: ALU Slice %0d - VD Incorrect", slice);
                    @(posedge CLK);
                end
                $display("ALU operation validated");
            end
            
            // Issue to MULT from port 1
            begin
                issue_pulse(1, test_v1_mult, test_v2_mult, 1, 8'd2, 0, '1, VR_SUM);
                
                // Validate MULT output
                for (int slice = 0; slice < SLICE_W; slice++) begin
                    wait_for_fu_valid(1);
                    assert (lif.out.units[1].valid == 1) else 
                        $error("Multi-Issue ALU+MULT: MULT Slice %0d - Valid not asserted", slice);
                    assert (lif.out.units[1].vd == 8'd2) else 
                        $error("Multi-Issue ALU+MULT: MULT Slice %0d - VD Incorrect", slice);
                    @(posedge CLK);
                end
                $display("MULT operation validated");
            end
        join
        
        $display("Multi-Issue ALU+MULT Test Complete\n");
    endtask //automatic

    task automatic test_multi_issue_mult_sqrt();
        logic [SLICE_W-1:0][15:0] test_v1_mult, test_v2_mult;
        logic [SLICE_W-1:0][15:0] test_v1_sqrt, test_v2_sqrt;
        
        $display("\n=====================================================");
        $display("Starting Multi-Issue Test: MULT + SQRT");
        $display("=====================================================\n");
        
        current_test = "MULTI_MULT_SQRT";
        
        // Setup test data
        test_v1_mult = {16'h3f80, 16'h4000};
        test_v2_mult = {16'h4000, 16'h4100};
        test_v1_sqrt = {16'h4000, 16'h4100};
        test_v2_sqrt = '0;  // SQRT only uses v1
        
        fork
            // Issue to MULT from port 0
            begin
                issue_pulse(0, test_v1_mult, test_v2_mult, 1, 8'd3, 0, '1, VR_SUM);
                
                // Validate MULT output
                for (int slice = 0; slice < SLICE_W; slice++) begin
                    wait_for_fu_valid(MULT);
                    assert (lif.out.units[1].valid == 1) else 
                        $error("Multi-Issue MULT+SQRT: MULT Slice %0d - Valid not asserted", slice);
                    assert (lif.out.units[1].vd == 8'd3) else 
                        $error("Multi-Issue MULT+SQRT: MULT Slice %0d - VD Incorrect", slice);
                    @(posedge CLK);
                end
                $display("MULT operation validated");
            end
            
            // Issue to SQRT from port 1
            begin
                issue_pulse(1, test_v1_sqrt, test_v2_sqrt, 4, 8'd4, 0, '1, VR_SUM);
                
                // Validate SQRT output
                for (int slice = 0; slice < SLICE_W; slice++) begin
                    wait_for_fu_valid(4);
                    assert (lif.out.units[4].valid == 1) else 
                        $error("Multi-Issue MULT+SQRT: SQRT Slice %0d - Valid not asserted", slice);
                    assert (lif.out.units[4].vd == 8'd4) else 
                        $error("Multi-Issue MULT+SQRT: SQRT Slice %0d - VD Incorrect", slice);
                    @(posedge CLK);
                end
                $display("SQRT operation validated");
            end
        join
        
        $display("Multi-Issue MULT+SQRT Test Complete\n");
    endtask //automatic

    task automatic test_multi_issue_sqrt_exp();
        logic [SLICE_W-1:0][15:0] test_v1_sqrt, test_v2_sqrt;
        logic [SLICE_W-1:0][15:0] test_v1_exp, test_v2_exp;
        
        $display("\n=====================================================");
        $display("Starting Multi-Issue Test: SQRT + EXP");
        $display("=====================================================\n");
        
        current_test = "MULTI_SQRT_EXP";
        
        // Setup test data
        test_v1_sqrt = {16'h4000, 16'h4100};
        test_v2_sqrt = '0;  // SQRT only uses v1
        test_v1_exp = {16'h3f80, 16'h4000};
        test_v2_exp = '0;   // EXP only uses v1
        
        fork
            // Issue to SQRT from port 0
            begin
                issue_pulse(0, test_v1_sqrt, test_v2_sqrt, 4, 8'd5, 0, '1, VR_SUM);
                
                // Validate SQRT output
                for (int slice = 0; slice < SLICE_W; slice++) begin
                    wait_for_fu_valid(4);
                    assert (lif.out.units[4].valid == 1) else 
                        $error("Multi-Issue SQRT+EXP: SQRT Slice %0d - Valid not asserted", slice);
                    assert (lif.out.units[4].vd == 8'd5) else 
                        $error("Multi-Issue SQRT+EXP: SQRT Slice %0d - VD Incorrect", slice);
                    @(posedge CLK);
                end
                $display("SQRT operation validated");
            end
            
            // Issue to EXP from port 1
            begin
                issue_pulse(1, test_v1_exp, test_v2_exp, 3, 8'd6, 0, '1, VR_SUM);
                
                // Validate EXP output
                for (int slice = 0; slice < SLICE_W; slice++) begin
                    wait_for_fu_valid(3);
                    assert (lif.out.units[3].valid == 1) else 
                        $error("Multi-Issue SQRT+EXP: EXP Slice %0d - Valid not asserted", slice);
                    assert (lif.out.units[3].vd == 8'd6) else 
                        $error("Multi-Issue SQRT+EXP: EXP Slice %0d - VD Incorrect", slice);
                    @(posedge CLK);
                end
                $display("EXP operation validated");
            end
        join
        
        $display("Multi-Issue SQRT+EXP Test Complete\n");
    endtask //automatic

    //saturation test. Does not verify the outputs, visual debugging will be required
    task automatic lane_saturation();
         logic [SLICE_W-1:0][15:0] test_v1, test_v2, test_v2_zero;
        int num_issues_per_fu = 5;
        int total_issues = num_issues_per_fu * 5;
        int issue_count = 0;

        $display("\n=====================================================");
        $display("Starting Lane Saturation Test");
        $display("=====================================================\n");
        current_test = "LANE_SATURATION";

        test_v1 = {16'h3f80, 16'h4000};
        test_v2 = {16'h4000, 16'h4100};
        test_v2_zero = '0;

        int fu_issue_count[5] = '{0, 0, 0, 0, 0};

            while (issue_count < total_issues) begin
            int port0_issued = 0;
            int port1_issued = 0;
            int fu_issued_port0 = 0;
            int fu_issued_port1 = 0;

            for (int fu = 0; fu < LANE_FU_COUNT; fu++) begin //find a FU that we can issue to on port 0
                if (fu_issue_count[fu] < num_issues_per_fu && (lif.out.units[fu].input_ready == 1)) begin
                    logic [SLICE_W-1:0][15:0] v2_to_use = (fu == 3 || fu == 4) ? test_v2_zero : test_v2; //FU is exp or sqrt
                    issue_to_port(0, 1, test_v1, v2_to_use, fu, (fu * 10 + fu_issue_count[fu])[7:0], 0, '1, VR_SUM);
                    fu_issue_count[fu]++;
                    issue_count++;
                    port0_issued = 1;
                    fu_issued_port0 = fu;
                    $display("Issued to FU %0d on port 0, operation %0d", fu, fu_issue_count[fu]-1);
                    break;
                end
            end
            for (int fu = 0; fu < LANE_FU_COUNT; fu++) begin //find a differnt port we can issue to
                if (port0_issued && fu == fu_issued_port0) continue; //if the current FU that we are looking at is already issued to port 1, skip

                if (fu_issue_count[fu] < num_issues_per_fu && lif.out.units[fu].ready == 1) begin
                    logic [SLICE_W-1:0][15:0] v2_to_use = (fu == EXP_FU || fu == SQRT_FU) ? test_v2_zero : test_v2;
                    valu_op_t op = (fu == ALU_FU) ? VADD : VR_SUM;
                    
                    issue_to_port(1, 1, test_v1, v2_to_use, fu, (fu * 10 + fu_issue_count[fu])[7:0], 0, '1, op);
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

endmodule
