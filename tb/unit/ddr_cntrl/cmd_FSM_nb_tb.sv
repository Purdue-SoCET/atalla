`include "ddr_controller_if.sv"
`timescale 1 ns / 1 ps

module command_FSM_nb_tb();
    import dram_pkg::*;

    logic CLK, nRST;
    localparam PERIOD = 2;  // 2 ns clock period (500 MHz)
    string test_case;

    // Clock Generation
    always begin
        CLK = 1'b0;
        #(PERIOD / 2.0);
        CLK = 1'b1;
        #(PERIOD / 2.0);
    end

    // Interface Declaration
    ddr_controller_if ddrif();

    // DUT Instantiation
    cmd_fsm DUT(CLK, nRST, ddrif);

    // HELPER TASKS:
    
    // Reset Task
    task reset_dut;
        nRST = 1'b0;
        ddrif.bq_ready = '0; // Which bank has request
        ddrif.bq_slot  = '{default: '0}; // BQ Slot --> holds row, col, write, id data
        ddrif.be_arb   = '0; // Tells FSM which bank has been given bus
        ddrif.fsm_ref  = '0; // No refresh request
        repeat(2) @(posedge CLK);
        nRST = 1'b1;
        @(posedge CLK);
    endtask

    // Drive a request into a specific bank queue slot
    task drive_bq_request(
        input int                        bank,
        input logic [ROW_BITS-1:0]       row,
        input logic [COLUMN_BITS-1:0]    col,
        input logic                      write, // write = 1, read = 0
        input logic [$clog2(ID_NUM)-1:0] id // ID on request
    );
        // Drive data in bank queue slot
        ddrif.bq_slot[bank].row     = row;
        ddrif.bq_slot[bank].column  = col;
        ddrif.bq_slot[bank].write   = write;
        ddrif.bq_slot[bank].id_addr = id;
        ddrif.bq_ready[bank]        = 1'b1;
    endtask

    // Clear a pending bank queue request
    task clear_bq_request(input int bank);
        ddrif.bq_ready[bank] = 1'b0;
        ddrif.bq_slot[bank]  = '0;
    endtask

    // Test 1: Read Closed Row
    
    //   IDLE -> ACTIVATE -> ACTIVATING -> READ -> READING -> IDLE
   
   
    // Outputs to verify in waveform:
    //   be_cmd  should show ACTIVATE_CMD, then READ_CMD
    //   be_r    should carry the row address  (0x0010)
    //   be_c    should carry the col address   (0x020)
    //   be_b, be_bg should identify bank 0
    //   be_id   should carry the transaction ID (1)
    //
    task test_read_closed_row;
        test_case = "Read Closed Row";
        $display("\n[TEST] %s", test_case);

        //Drive read request on bank 0
        drive_bq_request(
            .bank  (0),
            .row   (15'h0010),
            .col   (10'h020),
            .write (1'b0),
            .id    (3'd1)
        );
        @(posedge CLK);

        // Backend arbiter grants bank 0 — FSM should issue ACTIVATE
        ddrif.be_arb = 4'd0;
        @(posedge CLK);

        // Wait tRCD cycles for the row open --> ACTIVATING
        repeat(tRCD) @(posedge CLK);

        // Grant Bank 0 after Activation, now state goes into READ
        ddrif.be_arb = 4'd0;
        @(posedge CLK);

        // Wait tRL + tBURST for read data to come back from DRAM.
        // FSM stays in READING state
        repeat(tRL + tBURST) @(posedge CLK);

        // Read complete --> IDLE
        clear_bq_request(0);
        ddrif.be_arb = '0;
    endtask

    // Test 2: Read Open Row
    // IDLE -> READ -> READING -> IDLE
    task test_read_open_row;
        test_case = "Read Open Row";
        $display("\n[TEST] %s", test_case);

        // Drive request to same row, different column (read)
        drive_bq_request(
            .bank  (0),
            .row   (15'h0010),  
            .col   (10'h040),   
            .write (1'b0),      
            .id    (3'd2)
        );
        @(posedge CLK);

        // READ -> READING when arbiter grants
        ddrif.be_arb = 4'd0;
        @(posedge CLK);

        // Finish read using appropriate timing
        $display("[INFO] Waiting tRL + tBURST = %0d + %0d = %0d cycles",
                 tRL, tBURST, tRL + tBURST);
        repeat(tRL + tBURST) @(posedge CLK);

        // Back to Idle
        clear_bq_request(0);
        ddrif.be_arb = '0;
    endtask

    // Test 3: Read after Write
    // Write: IDLE -> WRITE -> WRITING -> IDLE
    // Read: IDLE -> READ -> READING -> IDLE
    task test_read_after_write;
        test_case = "Read after Write";
        $display("\n[TEST] %s", test_case);

        // Write Request:
        drive_bq_request(
            .bank  (0),
            .row   (15'h0010),
            .col   (10'h060),
            .write (1'b1),      // Write = 1
            .id    (3'd3)
        );
        @(posedge CLK);

        // WRITE -> WRITING when arbiter grants
        ddrif.be_arb = 4'd0;
        @(posedge CLK);

        // tWL + tBURST + tWR for write to complete
        repeat(tWL + tBURST + tWR) @(posedge CLK);

        // Clear the write request
        clear_bq_request(0);
        ddrif.be_arb = '0;
        @(posedge CLK);

        // Read Request:
        drive_bq_request(
            .bank  (0),
            .row   (15'h0010),
            .col   (10'h080),
            .write (1'b0),      // Read = 0
            .id    (3'd4)
        );
        @(posedge CLK);

        // READ -> READING when arbiter grants
        ddrif.be_arb = 4'd0;
        @(posedge CLK);

        // Finish REad
        repeat(tRL + tBURST) @(posedge CLK);

        clear_bq_request(0);
        ddrif.be_arb = '0;
    endtask

    // Test 4: Write Closed Row
    // IDLE -> ACTIVATE -> ACTIVATING -> WRITE -> WRITING -> IDLE
    task test_write_closed_row;
        test_case = "Write Closed Row";
        $display("\n[TEST] %s", test_case);

        // Drive write request on bank 1 (all rows closed after reset)
        drive_bq_request(
            .bank  (1),
            .row   (15'h0020),
            .col   (10'h010),
            .write (1'b1),
            .id    (3'd5)
        );
        @(posedge CLK);

        // Grant bank 1 — Go to ACT 
        ddrif.be_arb = 4'd1;
        @(posedge CLK);

        // Wait tRCD cycles in ACTIVATING 
        repeat(tRCD) @(posedge CLK);

        // Transitions to WRITE, grant bank 1 to get to WRITING
        $display("[INFO] Granting backend arbitration to bank 1 (WRITE)");
        ddrif.be_arb = 4'd1;
        @(posedge CLK);

        // tWL + tBURST + tWR for write to complete 
        repeat(tWL + tBURST + tWR) @(posedge CLK);

        clear_bq_request(1);
        ddrif.be_arb = '0;
    endtask

    // Test 5: Write Open Row
    //   Bank 1 already has row 0x0020 open from the previous test
    //   IDLE -> WRITE -> WRITING -> IDLE
    task test_write_open_row;
        test_case = "Write Open Row";
        $display("\n[TEST] %s", test_case);

        // Drive write to bank 1, same row 0x0020 
        drive_bq_request(
            .bank  (1),
            .row   (15'h0020),  
            .col   (10'h030),   
            .write (1'b1),
            .id    (3'd6)
        );
        @(posedge CLK);

        // Go to WRITE, then grant, then WRITING
        ddrif.be_arb = 4'd1;
        @(posedge CLK);

        // Do Write
        repeat(tWL + tBURST + tWR) @(posedge CLK);

        clear_bq_request(1);
        ddrif.be_arb = '0;
    endtask

    // Test 6: Write After Read
    // Read: IDLE -> READ -> READING -> IDLE
    // Write: IDLE -> WRITE -> WRITING -> IDLE
    task test_write_after_read;
        test_case = "Write After Read";
        $display("\n[TEST] %s", test_case);

        // Read open row from before
        drive_bq_request(
            .bank  (1),
            .row   (15'h0020),
            .col   (10'h050),
            .write (1'b0),      
            .id    (3'd7)
        );
        @(posedge CLK);

        // Grant bank 1 READ -> READING
        ddrif.be_arb = 4'd1;
        @(posedge CLK);

        // Wait for read to complete
        repeat(tRL + tBURST) @(posedge CLK);

        clear_bq_request(1);
        ddrif.be_arb = '0;
        @(posedge CLK);

        // Write to same open row
        drive_bq_request(
            .bank  (1),
            .row   (15'h0020),
            .col   (10'h070),
            .write (1'b1),     
            .id    (3'd0)
        );
        @(posedge CLK);

        // Grant bank 1 WRITE -> WRITING
        ddrif.be_arb = 4'd1;
        @(posedge CLK);

        // Wait for write to complete
        repeat(tWL + tBURST + tWR) @(posedge CLK);

        clear_bq_request(1);
        ddrif.be_arb = '0;
    endtask
 
    // Test 7: Request Muxing
    task test_request_muxing;
        test_case = "Request Muxing";
        $display("\n[TEST] %s", test_case);

        // Reset to get clean row state across all banks.
        reset_dut();

        //Load requests into 3 banks simultaneously.
        drive_bq_request(.bank(0), .row(15'h0100), .col(10'h001), .write(1'b0), .id(3'd0));
        drive_bq_request(.bank(1), .row(15'h0200), .col(10'h002), .write(1'b1), .id(3'd1));
        drive_bq_request(.bank(2), .row(15'h0300), .col(10'h003), .write(1'b0), .id(3'd2));
        @(posedge CLK);

        // Grant bank 0 — verify outputs carry bank 0’s data
        // be_r = 0x0100, be_c = 0x001, be_id = 0
        ddrif.be_arb = 4'd0;
        @(posedge CLK);

        // Grant bank 1 
        // be_r = 0x0200, be_c = 0x002, be_id = 1
        ddrif.be_arb = 4'd1;
        @(posedge CLK);

        // Grant bank 2 
        // be_r = 0x0300, be_c = 0x003, be_id = 2
        ddrif.be_arb = 4'd2;
        @(posedge CLK);

        clear_bq_request(0);
        clear_bq_request(1);
        clear_bq_request(2);
        ddrif.be_arb = '0;
    endtask

    // Initial Block
    initial begin
        reset_dut();

        test_read_closed_row();
        repeat(5) @(posedge CLK);

        test_read_open_row();
        repeat(5) @(posedge CLK);

        test_read_after_write();
        repeat(5) @(posedge CLK);

        test_write_closed_row();
        repeat(5) @(posedge CLK);

        test_write_open_row();
        repeat(5) @(posedge CLK);

        test_write_after_read();
        repeat(5) @(posedge CLK);

        test_request_muxing();
        repeat(5) @(posedge CLK);
    end

endmodule