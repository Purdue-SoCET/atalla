`include "dram_pkg.svh"
`include "ddr_controller_if.sv"
`timescale 1ns/1ps
// be_r, be_c, be_b, be_bg, be_cmd, be_id, be_queue_ready

module nb_barb_tb;
    import dram_pkg::*;

    logic CLK = 0, nRST;
    parameter PERIOD = 10;
    int test_num = 0;
    int passed_cnt = 0;
    localparam TEST_CNT = 1000;

    // clock
    always #(PERIOD/2) CLK++;
    
    ddr_controller_if ddrif();
    nb_barb DUT(CLK, nRST, ddrif);

    // test PROG(CLK, nRST, ddrif);

    // bind nb_barb nb_barb_prop barb_monitor(CLK, nRST, barb);

    // TEST VECTORS

    typedef struct packed {
        logic [BANK_GROUP_BITS-1:0] bg;
        logic [BANK_BITS-1:0]       b;
        fsm_t                       cmd;
        logic [ROW_BITS-1:0]        row;
        logic [COLUMN_BITS-1:0]     col;
        logic [2:0]                 len;
        logic [$clog2(ID_NUM)-1:0]  id;
    } input_t;

    typedef struct packed {
        logic                      push_id; 
        logic [$clog2(ID_NUM)-1:0] rid;
        logic [2:0]                rlen;
        logic [$clog2(ID_NUM)-1:0] wid, write; 
    } output_t;

    typedef struct packed {
        logic                      exp_push_id; 
        logic [$clog2(ID_NUM)-1:0] exp_rid;
        logic [2:0]                exp_rlen;   
        logic [$clog2(ID_NUM)-1:0] exp_wid, exp_write;     
    } exp_t;

    input_t    [TEST_CNT-1:0] input_vec;
    output_t   [TEST_CNT-1:0] output_vec;
    exp_t      [TEST_CNT-1:0] exp_vec;

    // TASKS

    task reset_dut();
        begin
            nRST = 0;
            repeat(2) @(negedge CLK);
            nRST = 1;
        end
    endtask

    task set_idle();
        begin 
            for (int j = 0; j < 16; j++) begin
                ddrif.be_cmd[j] = FSM_IDLE;
            end
        end
    endtask

    // Generate test vectors
    task sequencer;
        logic [$clog2(ID_NUM)-1:0] random_id;
        logic [2:0]               random_rlen;
        int                       cmd_choice;
        for (int i = 0; i < TEST_CNT; i++) begin
            input_vec[i].bg  = $urandom_range(0, 3);
            input_vec[i].b   = $urandom_range(0, 3);
            cmd_choice = $urandom_range(0, 2);
            case (cmd_choice)
                0: input_vec[i].cmd = FSM_READ;
                1: input_vec[i].cmd = FSM_WRITE;
                2: input_vec[i].cmd = REF;
            endcase

            input_vec[i].row = $urandom_range(0, (1 << ROW_BITS) - 1);
            input_vec[i].col = $urandom_range(0, (1 << COLUMN_BITS) - 1);
            input_vec[i].len = $urandom_range(0, 7);
            input_vec[i].id  = $urandom_range(0, ID_NUM - 1);

            if (input_vec[i].cmd == REF) begin
                exp_vec[i].exp_push_id = 1'b0;
                exp_vec[i].exp_rid     = '0;
                exp_vec[i].exp_rlen    = '0;
                exp_vec[i].exp_wid     = '0;
                exp_vec[i].exp_write   = 1'b0;
            end else begin
                exp_vec[i].exp_push_id = (input_vec[i].cmd == FSM_READ);
                exp_vec[i].exp_rid     = input_vec[i].id;
                exp_vec[i].exp_rlen    = 'b1;
                exp_vec[i].exp_wid     = input_vec[i].id;
                exp_vec[i].exp_write   = (input_vec[i].cmd == FSM_WRITE);
            end
        end
    endtask

    // Load a specific bank with a command
    task drive_bank_request(
        input int bank_id,
        input fsm_t cmd,
        input logic [ROW_BITS-1:0] row,
        input logic [COLUMN_BITS-1:0] col,
        input logic [$clog2(ID_NUM)-1:0] id
    );
        begin
            ddrif.be_queue_ready[bank_id] = 1'b1; // Setting the bit for this bank
            ddrif.be_cmd[bank_id]         = cmd;
            ddrif.be_r[bank_id]           = row;
            ddrif.be_c[bank_id]           = col;
            ddrif.be_id[bank_id]          = id;
        end
    endtask

    task drive_bank_case(
        input int case_num
    );
        int bank_id;
        fsm_t initial_cmd;
        begin
            bank_id = {input_vec[case_num].b, input_vec[case_num].bg};
            if (input_vec[case_num].cmd == REF) begin
                ddrif.be_queue_ready = {BANK_NUM{1'b1}};
                ddrif.be_cmd         = {BANK_NUM{REF}};
                ddrif.be_r           = '{default: '0};
                ddrif.be_c           = '{default: '0};
                ddrif.be_id          = '{default: '0};
                ddrif.be_len         = '{default: '0};
            end else begin
                initial_cmd = ACT;
                drive_bank_request(bank_id, initial_cmd,
                                   input_vec[case_num].row,
                                   input_vec[case_num].col,
                                   input_vec[case_num].id);
                ddrif.be_len[bank_id] = 'b1;
            end
        end
    endtask

    task check_write(
        input int                        test_num,
        input logic                      exp_write,
        input logic [$clog2(ID_NUM)-1:0] exp_wid
    );
        int error;
        begin
            error = 0;
            $display("Current write test #: %0d @ time %0t", test_num, $time);
            if (ddrif.be_write != exp_write) begin
                $display("Incorrect write enable, got %d instead of %d", ddrif.be_write, exp_write);
                error++;
            end
            if (ddrif.be_wid != exp_wid) begin
                $display("Incorrect write id, got %0d instead of %0d", ddrif.be_wid, exp_wid);
                error++;
            end
            if (error == 0) begin
                passed_cnt++;
                $display("Write case passed");
            end else begin
                $display("Write case failed");
            end
        end
    endtask

    task check_read(
        input int                        test_num,
        input logic                      exp_push_id, 
        input logic [$clog2(ID_NUM)-1:0] exp_rid,
        input logic [2:0]                exp_rlen
    );
        integer error;
        begin
            error = 0;
            $display("Current test #: %0d @ time %0t", test_num, $time);
            if (ddrif.be_push_id != exp_push_id) begin
                $display("Incorrect read push id, got %d instead of %d", ddrif.be_push_id, exp_push_id);
                error++;
            end 
            if (ddrif.be_rid != exp_rid) begin
                $display("Incorrect read id, got %0d instead of %0d", ddrif.be_rid, exp_rid);
                error++;
            end
            if (ddrif.be_rlen != exp_rlen) begin
                $display("Incorrect read length, got %0d instead of %0d", ddrif.be_rlen, exp_rlen);
                error++;
            end

            if (error == 0) passed_cnt++;
            else $display("Read case failed");
        end
    endtask

    task check_ref(
        input int test_num
    );
        integer error;
        begin
            error = 0;
            $display("Current REF test #: %0d @ time %0t", test_num, $time);
            if (ddrif.be_push_id != 1'b0) begin
                $display("Incorrect REF push id, got %d instead of 0", ddrif.be_push_id);
                error++;
            end
            if (error == 0) begin
                passed_cnt++;
                $display("REF case passed");
            end else begin
                $display("REF case failed");
            end
        end
    endtask

    task run_vector_tests;
        int bank_id;
        begin
            for (int i = 0; i < TEST_CNT; i++) begin
                bank_id = {input_vec[i].b, input_vec[i].bg};
                $display("T=%0t | Bank %0d Ready: Cmd=%s, Row=%h", $time, bank_id, input_vec[i].cmd.name(), input_vec[i].row);
                drive_bank_case(i);
                wait(ddrif.be_arb[bank_id] == 1);
                @(negedge CLK);
                ddrif.be_cmd[bank_id] = input_vec[i].cmd;
                @(negedge CLK);
                case (input_vec[i].cmd)
                    FSM_READ: check_read(i,
                                         exp_vec[i].exp_push_id,
                                         exp_vec[i].exp_rid,
                                         exp_vec[i].exp_rlen);
                    FSM_WRITE: check_write(i,
                                           exp_vec[i].exp_write,
                                           exp_vec[i].exp_wid);
                    REF: begin 
                        check_ref(i);
                        #(170); // DRAM TRFC rounded down  
                        set_idle();
                        repeat(5) @(negedge CLK);
                    end
                endcase
                ddrif.be_queue_ready[bank_id] = 0;
            end
        end
    endtask

    initial begin  
        // 1. Initialization
        nRST = 1;
        ddrif.be_queue_ready = '0;
        ddrif.be_b           = '0;
        ddrif.be_bg          = '0; 
        ddrif.be_cmd         =  PWR_UP;
        ddrif.be_r           = '0;
        ddrif.be_c           = '0;
        ddrif.be_id          = '0;
        ddrif.be_len         = '0;

        reset_dut();

        sequencer();

        // --- PHASE 1 : Roll Through all --- 
        $display("\n--- Running vector-driven sequencer tests ---");
        ddrif.be_queue_ready = '0;
        set_idle();
        passed_cnt = 0;
        run_vector_tests();
        $display("\n--- Vector-driven cases passed: %0d / %0d ---", passed_cnt, TEST_CNT);

        // --- PHASE 2 : FAW Testing ---
        $display("\n --- Running through FAW tests ---");
        drive_bank_request(0, ACT, 15'h1111, 10'h001, 4'h0);
        drive_bank_request(1, ACT, 15'h2222, 10'h002, 4'h1);
        drive_bank_request(2, ACT, 15'h3333, 10'h003, 4'h2);
        drive_bank_request(3, ACT, 15'h4444, 10'h004, 4'h3);



        if (passed_cnt == TEST_CNT) $display("\n--- All DRAM behavior tests passed ---");
        else $display("\n--- Passed %0d/%0d cases ---", passed_cnt, TEST_CNT);
        $finish;
    end

endmodule

/* program test(
    input logic CLK, nRST, 
    ddr_controller_if.backend_arb barb
);
        task reset_dut();
        begin
            nRST = 0;
            repeat (5) @(negedge CLK);
            nRST = 1;
        end
    endtask

    initial begin 
        nRST = 1;
        reset_dut();
        repeat(100) @(negedge CLK);

        $display ("Coverage = %0.2f %%", nbcg.get_inst_coverage());
        $finish;
    end

endprogram */