// `timescale 1ns/1ps

// `include "atalla_types_pkg.vh"
// `include "datapath_cache_if.vh"
// `include "dec1_dec2_if.vh"

// import atalla_types_pkg::*;

// module fetch_decode1_tb();

//   // -----------------------------------------------------------------------
//   // 1. Clock & Reset Generation
//   // -----------------------------------------------------------------------
//   logic clk;
//   logic rst_n;

//   always #5 clk = ~clk; // 100MHz clock

//   // -----------------------------------------------------------------------
//   // 2. Interfaces & DUT Signals
//   // -----------------------------------------------------------------------
//   logic     flush;
//   logic     ready;
//   word_t    pc_branch;

//   logic     btb_update_en;
//   address_t btb_pc_update;
//   address_t btb_true_target;

//   // Instantiate interfaces
//   datapath_cache_if dc_if();
//   dec1_dec2_if      dec12_if();

//   // Instantiate DUT (Device Under Test)
//   fetch_decode1 dut (
//     .clk             (clk),
//     .rst_n           (rst_n),
//     .flush           (flush),
//     .ready           (ready),
//     .pc_branch       (pc_branch),
//     .btb_update_en   (btb_update_en),
//     .btb_pc_update   (btb_pc_update),
//     .btb_true_target (btb_true_target),
//     .dc_if           (dc_if.dp),
//     .dec12_if        (dec12_if.src)
//   );

//   // -----------------------------------------------------------------------
//   // 3. Mock Instruction Cache
//   // -----------------------------------------------------------------------
//   // Intercept dc_if requests and manually assign ihit and imemload
//   always_ff @(posedge clk) begin
//     if (!rst_n) begin
//       dc_if.ihit <= 1'b0;
//       dc_if.imemload <= '0;
//     end else begin
//       // Respond when Fetch requests a read (imemREN == 1)
//       if (dc_if.imemREN) begin
//         dc_if.ihit <= 1'b1; // Assume always hit
        
//         // Insert dummy instructions to test decode classification
//         // Slot 0: ADD_S (Scalar)  - opcode 7'd1
//         // Slot 1: ADD_VV (Vector) - opcode 7'd50
//         // Slot 2: SCPAD_LD (SCPAD) - opcode 7'd88
//         // Slot 3: NOP_S (Scalar)  - opcode 7'd47
//         dc_if.imemload.inst0 <= {17'd0, 8'd2, 8'd1, 8'd3, ADD_S};
//         dc_if.imemload.inst1 <= {17'd0, 8'd5, 8'd4, 8'd6, ADD_VV};
//         dc_if.imemload.inst2 <= {17'd0, 8'd0, 8'd0, 8'd0, SCPAD_LD};
//         dc_if.imemload.inst3 <= {17'd0, 8'd0, 8'd0, 8'd0, NOP_S};
//       end else begin
//         dc_if.ihit <= 1'b0;
//       end
//     end
//   end

//   // -----------------------------------------------------------------------
//   // 4. Test Stimulus
//   // -----------------------------------------------------------------------
//   initial begin
//     // Generate waveform file
//     $dumpfile("fetch_decode1.vcd");
//     $dumpvars(0, fetch_decode1_tb);

//     // Initialize signals
//     clk             = 0;
//     rst_n           = 0;
//     flush           = 0;
//     ready           = 0;
//     pc_branch       = 0;
//     btb_update_en   = 0;
//     btb_pc_update   = 0;
//     btb_true_target = 0;

//     // Reset system
//     #15;
//     rst_n = 1;
//     #10;

//     // Scenario 1: Normal Fetch
//     $display("[%0t] Scenario 1: Normal Fetch", $time);
//     ready = 1; // Allow pipeline to advance
//     #30;

//     // Scenario 2: Trigger Branch Flush
//     $display("[%0t] Scenario 2: Trigger Branch Flush to PC 0x100", $time);
//     flush = 1;
//     pc_branch = 32'h100;
//     #10;
//     flush = 0; // Resume normal execution
//     #30;

//     // Scenario 3: Update BTB (Simulate backward branch from Execute)
//     $display("[%0t] Scenario 3: Update BTB (Map PC 0x118 to 0x050)", $time);
//     btb_update_en   = 1;
//     btb_pc_update   = 32'h118; // Branch at 0x118
//     btb_true_target = 32'h050; // Jump backward to 0x050
//     #10;
//     btb_update_en   = 0;
//     #40;

//     // End test
//     $display("[%0t] Test Finished!", $time);
//     $finish;
//   end

//   // -----------------------------------------------------------------------
//   // 5. Monitor Outputs
//   // -----------------------------------------------------------------------
//   always_ff @(posedge clk) begin
//     if (rst_n && ready) begin
//       // Check decoded instructions sent to dec1_dec2_if (all slots)
//       $display(
//         "[%0t] PC_IN=%h | S={%h,%h,%h,%h} | V={%h,%h,%h,%h} | SCP={%h,%h}",
//         $time,
//         dec12_if.pc_in,

//         dec12_if.scalar_inst_in[0],
//         dec12_if.scalar_inst_in[1],
//         dec12_if.scalar_inst_in[2],
//         dec12_if.scalar_inst_in[3],

//         dec12_if.vector_inst_in[0],
//         dec12_if.vector_inst_in[1],
//         dec12_if.vector_inst_in[2],
//         dec12_if.vector_inst_in[3],

//         dec12_if.scpad_inst_in[0],
//         dec12_if.scpad_inst_in[1]
//         //dec12_if.scpad_inst_in[2],
//         //dec12_if.scpad_inst_in[3]
//       );
//     end
//   end

// endmodule