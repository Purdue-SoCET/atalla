`timescale 1ns/1ps

module transpose_unit_tb;
    localparam int VEC_LEN = 32;
    localparam int DATA_W  = 16;
    localparam PERIOD = 10;

    logic CLK = 0; 
    logic nRST;

    transpose_unit_if #(.VEC_LEN(VEC_LEN), .DATA_W(DATA_W)) tif();

    transpose_unit DUT (
        .CLK(CLK), .nRST(nRST), .tif(tif.transpose)
    );

    always #(PERIOD/2) CLK = ~CLK;

    initial begin
        // --- Initialization ---
        nRST = 0;
        tif.tb.in = '0;
        tif.tb.in.ready_out = 1;

        repeat (5) @(posedge CLK);
        nRST = 1;
        repeat (2) @(posedge CLK);

        // --- STEP 1: PUSH 2 VECTORS ---
        for (int row = 0; row < 2; row++) begin
            while (!tif.tb.out.ready_in) @(posedge CLK);
            
            tif.tb.in.push_req = 1;
            tif.tb.in.valid_in = 1;
            for (int col = 0; col < 32; col++) begin
                tif.tb.in.vec_in[col] = (row * 100) + col;
            end
            
            @(posedge CLK);
            tif.tb.in.push_req = 0;
            tif.tb.in.valid_in = 0;
            @(posedge CLK); // Buffer to let FSM settle
        end

        // Wait a few cycles before popping
        repeat (5) @(posedge CLK);

        // --- STEP 2: POP ALL 32 VECTORS ---
        $display("[%0t] Starting POP phase...", $time);
        
        for (int col_idx = 0; col_idx < 32; col_idx++) begin
            tif.tb.in.pop_req = 1;
            
            // Wait for hardware latency
            while (!tif.tb.out.valid_out) @(posedge CLK);
            
            $display("[%0t] Popped Vector %0d: [0]=%0d, [1]=%0d", 
                     $time, col_idx, tif.tb.out.vec_out[0], tif.tb.out.vec_out[1]);
            
            // Verification: 
            // Element 0 should be Row 0, Col col_idx
            // Element 1 should be Row 1, Col col_idx
            if (tif.tb.out.vec_out[0] !== col_idx) 
                $error("Row 0 Mismatch! Expected %d, Got %d", col_idx, tif.tb.out.vec_out[0]);
            if (tif.tb.out.vec_out[1] !== (100 + col_idx)) 
                $error("Row 1 Mismatch! Expected %d, Got %d", 100+col_idx, tif.tb.out.vec_out[1]);

            @(posedge CLK);
            tif.tb.in.pop_req = 0;
            repeat(2) @(posedge CLK);
        end

        $finish;
    end
endmodule