`timescale 1ns / 10ps
`include "execution_unit_if.sv"
`include "scheduler_pkg.sv"
`include "atalla_isa_types.vh"


module scheduler_icache_tb;
    import execution_unit_types_pkg::*;
    import atalla_isa_pkg::*;

    parameter PERIOD = 2;
    logic CLK = 0, nRST;
    always #(PERIOD/2) CLK++;
    string casename;

    logic dhit;
    logic [31:0] data_load;
    logic ready_DEC2_out;
    logic iwait;
    instruction_packet_t iload;


    scheduler_core DUT (.CLK(CLK), .nRST(nRST), .hit(dhit), .data_load(data_load), .iwait(iwait), .iload(iload), .ready(ready_DEC2_out));

    // ---------------------------------------------------------
    // PRE-PACKED INSTRUCTION STREAM
    // 320 bits total (2 packets x 160 bits)
    // LSB (Slot 0) is at the bottom, MSB (Slot 7) is at the top.
    // ---------------------------------------------------------
    logic [319:0] instr_stream = {
        // --- Packet 2 (Upper 160 bits) ---
        40'h000000002F, // NOP
        40'h000000002F, // NOP
        40'h000000002F, // NOP
        40'h0000000030, // HALT
        
        // --- Packet 1 (Lower 160 bits) ---
        40'h000000002F, // NOP
        40'h000000002F, // NOP
        40'h000000002F, // NOP
        40'h0000800096  // ADD_I
    };

    initial begin
        casename = "rst";
        data_load = 32'b0;
        dhit = 1'b0;
        iwait = 1'b1;
        iload = 'b0;
        nRST = 1'b0;

        @(posedge CLK);
        @(posedge CLK);
        nRST = 1'b1;
        @(posedge CLK);
        @(posedge CLK);

// ---------------------------------------------------------
        // MEMORY TRANSACTION 1: Block 0 (Bits [127:0])
        // Contains: ADD_I, 2 NOPs, and the bottom 8 bits of NOP 3
        // ---------------------------------------------------------
        casename = "fetch_block0";
        $display("Loading Memory Block 0...");
        
        iwait = 1'b1;
        repeat(2) @(posedge CLK); 
        
        iload = instr_stream[127:0]; 
        
        iwait = 1'b0; 
        @(posedge CLK); 
        iwait = 1'b1;   
        
        // ---------------------------------------------------------
        // MEMORY TRANSACTION 2: Block 1 (Bits [255:128])
        // Contains: Top 32 bits of NOP 3, HALT, 1 NOP, bottom 16 bits of NOP 6
        // ---------------------------------------------------------
        casename = "fetch_block1";
        $display("Loading Memory Block 1...");
        
        repeat(2) @(posedge CLK); 
        
        iload = instr_stream[255:128]; 
        
        iwait = 1'b0; 
        @(posedge CLK); 
        iwait = 1'b1;

        // ---------------------------------------------------------
        // MEMORY TRANSACTION 3: Block 2 (Bits [319:256])
        // Contains: Top 24 bits of NOP 6, NOP 7, and 64 bits of padding
        // ---------------------------------------------------------
        casename = "fetch_block2";
        $display("Loading Memory Block 2...");
        
        repeat(2) @(posedge CLK); 
        
        // Pad the remaining 64 bits with 0s to complete the 128-bit bus
        iload = {64'b0, instr_stream[319:256]}; 
        
        iwait = 1'b0; 
        @(posedge CLK); 
        iwait = 1'b1;

        // Wait for the pipeline to execute the packets
        repeat(20) @(posedge CLK);

        $display("DONE");
        $finish;
    end


endmodule