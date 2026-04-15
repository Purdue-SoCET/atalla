`timescale 1ns/1ps
`include "icaches_if.vh"
`include "datapath_cache_if.vh"

module icache_fetch_tb;
    logic CLK = 0, nRST;
    always #5 CLK = ~CLK;

    
    icaches_if cif();

    // icache DUT (
    //     .CLK(CLK),
    //     .nRST(nRST),
    //     .dcif(dcif.icache),
    //     .cif(cif.icache)
    // );

    scheduler_core DUT (
        .CLK(CLK),
        .nRST(nRST),
        //.hit(dhit),
        //.data_load(data_load),
        .cif(cif)
        //.ready(ready_DEC2_out)
    );


    // ========================================================================
    // MEMORY CONTROLLER (always_ff FSM)
    // Serves 4 distinct blocks of memory to rigorously test wrap-around logic
    // ========================================================================
    logic [3:0] mem_cnt;
    logic [511:0] mem_data_reg;

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            mem_cnt <= 0;
            cif.iwait <= 1;
            cif.iload <= '0;
        end else begin
            if (mem_cnt == 0) begin
                cif.iwait <= 1;
                // Idle state: Wait for read enable
                if (cif.iREN) begin
                    mem_cnt <= 1;
                    $display("@%0t: MEMORY - Fill requested for Block Address %h", $time, cif.iaddr);
                    

                    if (cif.iaddr == 32'h00)
                        mem_data_reg <= 512'h00000000_0000000031_0000000031_0000000031_07810081a3_0000000031_0000000031_0000000031_0026800116_0000000031_0000000031_0000000031_0026800096;
                    else if (cif.iaddr == 32'h40)
                        mem_data_reg <= 512'h 0000000031_0000000031_0000000031_0000000032_31_0000000031_0000000031_006400012a;
                    else if (cif.iaddr == 32'h80)
                        mem_data_reg <= 512'h00000000000000000000000000000000000000;
                end
            end 
            else if (mem_cnt <= 2) begin
                // Latency cycles (mimics repeat(2) @posedge CLK)
                cif.iwait <= 1;
                if (mem_cnt == 2) begin
                    cif.iwait <= 0;
                    cif.iload <= mem_data_reg[0 +: 64];
                end
                mem_cnt <= mem_cnt + 1;
            end 
            else if (mem_cnt <= 10) begin
                // Burst cycles (mimics the 8-cycle loop)
                if (mem_cnt == 10) begin
                    cif.iwait <= 1;
                    mem_cnt <= 0; // Return to idle
                end else begin
                    cif.iwait <= 0;
                    cif.iload <= mem_data_reg[ (mem_cnt-2)*64 +: 64 ];
                    mem_cnt <= mem_cnt + 1;
                end
            end
        end
    end

    // ========================================================================
    // CPU STIMULUS: Max-Speed Combinational Loop
    // ========================================================================
    initial begin
        // --- Initialization ---
        nRST = 0; 
        
        @(posedge CLK); nRST = 1;
        repeat(2) @(posedge CLK);

        $display("--------------------------------------------------");
        $display("@%0t: Starting 12-Instruction Sequential Fetch Test", $time);
        $display("--------------------------------------------------");
        
        // Initial Request
        // dcif.imemREN = 1;
        // dcif.imemaddr = 32'h0;

        // // Loop runs until 12 successful requests are completed
        // for (int reqs = 0; reqs < 12; ) begin
        //     @(posedge CLK);
            
        //     // Because the cache is combinational, we can trust ihit immediately
        //     // and don't need artificial stall cycles.
        //     if (dcif.ihit && dcif.imemREN) begin
        //         reqs++; 
                
        //         $display("@%0t: HIT %0d! Addr: %h | Data (lower 32b): %h", 
        //                  $time, reqs, dcif.imemaddr, dcif.imemload[31:0]); 
                
        //         // Advance PC by 20 bytes (0x14) to fetch the next sequential instruction
        //         dcif.imemaddr <= dcif.imemaddr + 32'h14; 
        //     end
        // end
        
        // Cleanup
        @(posedge CLK);
        

        repeat(2000) @(posedge CLK);
        $display("--------------------------------------------------");
        $display("Simulation Finished Successfully.");
        $finish;
    end
endmodule