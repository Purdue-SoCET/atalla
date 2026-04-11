// make test   tb_file=transpose_unit_tb.sv   folder=/vector   packages=/common/xbar/xbar_pkg.sv   modules=/vector/transpose_unit.sv,/common/xbar/clos.sv,/common/memory/sram_bank.sv,/common/xbar/param_switch.sv GUI=ON

`timescale 1ns/1ps

module transpose_unit_tb;

    // Parameters
    localparam int VEC_LEN = 32;
    localparam int DATA_W  = 16;
    localparam PERIOD = 10;

    // Signals
    logic CLK = 0; // Initialize CLK to 0 to allow toggling
    logic nRST;

    // 1. Instantiate the Interface
    // Ensure your interface definition accepts (CLK, nRST)
    transpose_unit_if #(.VEC_LEN(VEC_LEN), .DATA_W(DATA_W)) tif();

    // 2. Instantiate the DUT
    transpose_unit DUT (
        .CLK(CLK),
        .nRST(nRST),
        .tif(tif.transpose) // Matching the modport name
    );

    // 3. Clock Generation
    always #(PERIOD/2) CLK = ~CLK;

    // 4. Test Logic
    initial begin
        // --- Initialization ---
        nRST         = 0;
        tif.valid_in = 0;
        tif.push_req = 0;
        tif.pop_req  = 0;
        tif.vec_in   = '0;

        // --- Reset Sequence ---
        repeat (5) @(posedge CLK);
        nRST = 1;
        repeat (2) @(posedge CLK);

        // --- STEP 1: PUSH 32 VECTORS (ROW-MAJOR) ---
        $display("[%0t] Starting PUSH phase...", $time);
        
        for (int row = 0; row < 32; row++) begin
            tif.push_req = 1;
            tif.valid_in = 1;
            for (int col = 0; col < 32; col++) begin
                // Data Pattern: (Row * 100) + Column
                tif.vec_in[col] = (row * 100) + col;
            end
            
            @(posedge CLK);
            // If the design is not ready to accept more (busy), wait
            // while (tif.ready_in == 0) @(posedge CLK); 
        end
        
        tif.push_req = 0;
        tif.valid_in = 0;

        // Buffer time between Push and Pop
        repeat (10) @(posedge CLK);

        // --- STEP 2: POP 32 VECTORS (TRANSPOSED) ---
        $display("[%0t] Starting POP phase...", $time);
        
        // We set pop_req high to begin the popping sequence
        tif.pop_req = 1;

        for (int col_idx = 0; col_idx < 32; col_idx++) begin
            // Wait for the valid signal for the current vector
            // This loop ensures we don't skip data if there's latency
            while (!tif.valid_out) @(posedge CLK);
            
            $display("[%0t] Verifying Transposed Vector %0d...", $time, col_idx);
            
            // Verification Logic:
            // Element 'i' of popped vector 'col_idx' should be (i * 100) + col_idx
            for (int i = 0; i < 32; i++) begin
                automatic int expected = (i * 100) + col_idx;
                if (tif.vec_out[i] !== expected) begin
                    $error("Mismatch at Vector %0d, Index %0d! Expected %0d, Got %h", 
                            col_idx, i, expected, tif.vec_out[i]);
                end
            end
            
            @(posedge CLK);
        end

        tif.pop_req = 0;
        
        repeat (5) @(posedge CLK);
        $display("[%0t] Testbench Completed.", $time);
        $finish;
    end

    // --- Watchdog Timer ---
    // Safety net: If the FSM gets stuck, this kills the sim after 2000 cycles
    initial begin
        repeat (2000) @(posedge CLK);
        $display("TIMEOUT: Simulation ended by watchdog.");
        $finish;
    end

    // --- Waveform Dumping (for GTKWave/Vivado/Questasim) ---
    initial begin
        $dumpfile("transpose_unit.vcd");
        $dumpvars(0, transpose_unit_tb);
    end

endmodule