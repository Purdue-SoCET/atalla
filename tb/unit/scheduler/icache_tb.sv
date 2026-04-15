`timescale 1ns/1ps
`include "caches_if.vh"
`include "datapath_cache_if.vh"

module icache_tb;
    logic CLK = 0, nRST;
    always #5 CLK = ~CLK;

    datapath_cache_if dcif();
    caches_if cif();

    icache DUT (
        .CLK(CLK),
        .nRST(nRST),
        .dcif(dcif.icache),
        .cif(cif.icache)
    );

    task automatic memory_respond(logic [511:0] full_block_data);
        cif.iwait = 1; 
        repeat(2) @(posedge CLK);
        for (int i = 0; i < 8; i++) begin
            cif.iwait = 0;
            cif.iload = full_block_data[i*64 +: 64];
            @(posedge CLK);
            cif.iwait = 1;
        end
    endtask

    initial begin
        // --- Initialization ---
        nRST = 0; dcif.imemREN = 0; dcif.imemaddr = '0; cif.iwait = 1; cif.iload = '0;
        @(posedge CLK); nRST = 1;
        repeat(2) @(posedge CLK);

        $display("@%0t: Starting Reactive B2B Test", $time);
        
        // Initial Miss
        dcif.imemREN = 1;
        dcif.imemaddr = 32'h0;

        fork
            // Process 1: Memory Controller
            begin
                // Provide Block 0
                wait(cif.iREN && cif.iaddr == 32'h0);
                memory_respond({64'h7, 64'h6, 64'h5, 64'h4, 64'h3, 64'h2, 64'h1, 64'h0});
                
                // Provide Block 1 for the wrap-around later
                // wait(cif.iREN && cif.iaddr == 32'h40);
                // memory_respond({64'hF, 64'hE, 64'hD, 64'hC, 64'hB, 64'hA, 64'h9, 64'h8});
            end

            // Process 2: Reactive CPU (Only moves if ihit is high)
            begin
                int requests_completed = 0;
                
                while (requests_completed < 8) begin
                    @(posedge CLK);
                    // Only update address if the cache actually signaled a hit on THIS edge
                    if (dcif.ihit) begin
                        requests_completed++;
                        
                        // Toggle logic or sequential logic
                        if (dcif.imemaddr == 32'h0)
                            dcif.imemaddr <= 32'h14;
                        else if (dcif.imemaddr == 32'h14)
                            dcif.imemaddr <= 32'h0;
                        else
                            dcif.imemaddr <= dcif.imemaddr + 32'h14; // Continue sequence
                            
                        $display("@%0t: Hit observed! Moving to next address: %h", $time, dcif.imemaddr);
                    end else begin
                        // If no hit, we hold the address (do nothing)
                        $display("@%0t: No hit, waiting...", $time);
                    end
                end
                
                @(posedge CLK);
                dcif.imemREN <= 0;
            end
        join

        repeat(10) @(posedge CLK);
        $finish;
    end
endmodule