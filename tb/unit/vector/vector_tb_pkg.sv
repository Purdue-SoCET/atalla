// // ------------------------------------------------------------
// // vector_tb_pkg.sv
// // Structured TB environment with assertions for debug
// // ------------------------------------------------------------
// `ifndef VECTOR_TB_PKG_SV
// `define VECTOR_TB_PKG_SV

// `include "vector_pkg.vh"
// `include "vector_if.vh"

// package vector_tb_pkg;
//   import vector_pkg::*;

//   // ----------------------------------------------------------
//   // Basic sampled types
//   // ----------------------------------------------------------
//   typedef struct {
//     vector_in_t               vin;          // issue payload
//     logic [LANE_ISSUE_W-1:0]  slot_accept;  // per-slot "accepted" mask
//   } issue_sample_t;

//   typedef struct {
//     vector_out_t vout;
//   } output_sample_t;

//   // One FU output "event" (one FU channel firing)
//   typedef struct {
//     int unsigned fu_idx;    // 0 .. LANE_FU_COUNT-1 (DUT channel index)
//     vsel_t       vd;
//     vreg_t       result;
//   } fu_output_sample_t;

//   // One reduction output "event"
//   typedef struct {
//     vsel_t  vd;
//     vreg_t  reduction_result;
//   } reduction_output_sample_t;

//   // Internal expected-event record (per accepted op)
//   typedef struct {
//     int unsigned fu_idx;       // DUT FU index (matches channel)
//     vsel_t       vd;
//     bit          is_reduction; // 1 = VALU rm reduction (ignored for now)
//   } expected_event_t;

//   // ----------------------------------------------------------
//   // Per-slot transaction
//   // ----------------------------------------------------------
//   class vector_issue_txn;
//     rand int unsigned slot;          // 0 .. LANE_ISSUE_W-1
//     rand fu_t        fu_sel;
//     rand logic       rm;
//     rand valu_op_t   vop;            // VALU op enum
//     rand vsel_t      vd;
//     rand vreg_t      v1;
//     rand vreg_t      v2;
//     rand vmask_t     vmask;
//     rand logic       valid;

//     bit is_reduction;

//     constraint c_slot {
//       slot inside {[0:LANE_ISSUE_W-1]};
//     }

//     constraint c_valid_bias {
//       valid dist {1 := 80, 0 := 20};
//     }

//     function void post_randomize();
//       is_reduction = (fu_sel == VALU) && rm;
//     endfunction

//     function string sprint();
//       return $sformatf("slot=%0d fu=%0d rm=%0b vd=%0d valid=%0b",
//                        slot, fu_sel, rm, vd, valid);
//     endfunction
//   endclass : vector_issue_txn

//   // ----------------------------------------------------------
//   // Cycle-level transaction (all issue slots)
//   // ----------------------------------------------------------
//   class vector_cycle_txn;
//     vector_issue_txn issues[LANE_ISSUE_W];

//     function new();
//       foreach (issues[i]) issues[i] = new();
//     endfunction

//     function bit any_valid();
//       foreach (issues[i]) if (issues[i].valid) return 1;
//       return 0;
//     endfunction

//     function string sprint();
//       string s = "";
//       foreach (issues[i]) s = {s, "[", i, "] ", issues[i].sprint(), "\n"};
//       return s;
//     endfunction
//   endclass : vector_cycle_txn

//   // ----------------------------------------------------------
//   // Driver
//   // ----------------------------------------------------------
//   class vector_driver;
//     virtual vector_if vif;
//     mailbox #(vector_cycle_txn) mbx;

//     function new(virtual vector_if vif, mailbox #(vector_cycle_txn) mbx);
//       this.vif = vif;
//       this.mbx = mbx;
//     endfunction

//     task drive_reset();
//       vif.vector_in = '0;
//     endtask

//     task run();
//       vector_cycle_txn txn;
//       forever begin
//         mbx.get(txn);
//         drive_one_cycle(txn);
//       end
//     endtask

//     task drive_one_cycle(vector_cycle_txn txn);
//       @(posedge vif.CLK);

//       // Only drive true inputs; never touch any ready_* here
//       vif.vector_in.valid_in = '0;
//       vif.vector_in.rm       = '0;

//       // Default fu_sel / vop / regs
//       vif.vector_in.fu_sel   = '{default: VALU};
//       vif.vector_in.vop      = '{default: valu_op_t'(0)};
//       vif.vector_in.vd       = '0;
//       vif.vector_in.v1       = '{default:'0};
//       vif.vector_in.v2       = '{default:'0};
//       vif.vector_in.vmask    = '0;

//       foreach (txn.issues[i]) begin
//         vif.vector_in.valid_in[i] = txn.issues[i].valid;
//         vif.vector_in.rm[i]       = txn.issues[i].rm;
//         vif.vector_in.fu_sel[i]   = txn.issues[i].fu_sel;
//         vif.vector_in.vd[i]       = txn.issues[i].vd;
//         vif.vector_in.vop[i]      = txn.issues[i].vop;
//         vif.vector_in.v1[i]       = txn.issues[i].v1;
//         vif.vector_in.v2[i]       = txn.issues[i].v2;
//         vif.vector_in.vmask[i]    = txn.issues[i].vmask;
//       end
//     endtask

//   endclass : vector_driver

//   // ----------------------------------------------------------
//   // Monitor
//   // ----------------------------------------------------------
//   class vector_monitor;
//     virtual vector_if vif;

//     mailbox #(issue_sample_t)            issue_mbx;
//     mailbox #(fu_output_sample_t)        fu_out_mbx;
//     mailbox #(reduction_output_sample_t) red_out_mbx;

//     function new(virtual vector_if vif,
//                  mailbox #(issue_sample_t)            issue_mbx,
//                  mailbox #(fu_output_sample_t)        fu_out_mbx,
//                  mailbox #(reduction_output_sample_t) red_out_mbx);
//       this.vif         = vif;
//       this.issue_mbx   = issue_mbx;
//       this.fu_out_mbx  = fu_out_mbx;
//       this.red_out_mbx = red_out_mbx;
//     endfunction

//     task run();
//       forever begin
//         @(posedge vif.CLK);
//         sample_issue();
//         sample_output();
//       end
//     endtask

//     // ------------------------------------------------------
//     // Handshake-aware sampling (simplified):
//     // For now, treat any valid_in as "accepted".
//     // This removes dependence on ready_o and focuses on VD bugs.
//     // ------------------------------------------------------
//     task sample_issue();
//       issue_sample_t s;
//       logic [LANE_ISSUE_W-1:0] accept;

//       accept = '0;
//       for (int slot = 0; slot < LANE_ISSUE_W; slot++) begin
//         if (vif.vector_in.valid_in[slot]) begin
//           accept[slot] = 1'b1;
//         end
//       end

//       if (|accept) begin
//         s.vin         = vif.vector_in;
//         s.slot_accept = accept;
//         issue_mbx.put(s);
//       end
//     endtask

//     // Normal FU outputs and reduction outputs
//     task sample_output();
//       fu_output_sample_t        fu_s;
//       reduction_output_sample_t red_s;

//       // ASSERTION 1: valid_o must not contain X/Z
//       assert (!$isunknown(vif.vector_out.valid_o))
//         else $error("[MON] ASSERTION FAIL: valid_o contains X or Z!");

//       // Normal FU outputs: capture *all* FU channels [0..LANE_FU_COUNT-1]
//       if (|vif.vector_out.valid_o) begin
//         for (int fu_idx = 0; fu_idx < LANE_FU_COUNT; fu_idx++) begin
//           if (vif.vector_out.valid_o[fu_idx]) begin
//             // ASSERTION 2: VD known when valid
//             assert (!$isunknown(vif.vector_out.vd[fu_idx]))
//               else $error("[MON] ASSERTION FAIL: FU[%0d] valid but VD is X!", fu_idx);

//             // ASSERTION 3: Result[0] not X/Z (sanity check)
//             assert (!$isunknown(vif.vector_out.result[fu_idx][0]))
//               else $warning("[MON] WARNING: FU[%0d] Result[0] is X/Z!", fu_idx);

//             fu_s.fu_idx = fu_idx;
//             fu_s.vd     = vif.vector_out.vd[fu_idx];
//             fu_s.result = vif.vector_out.result[fu_idx];
//             fu_out_mbx.put(fu_s);
//           end
//         end
//       end

//       // Reduction outputs (just count them for now)
//       if (vif.vector_out.reduction_valid) begin
//         red_s.vd               = vif.vector_out.reduction_vd;
//         red_s.reduction_result = vif.vector_out.reduction_result;
//         red_out_mbx.put(red_s);
//       end
//     endtask
//   endclass : vector_monitor

//   // ----------------------------------------------------------
//   // Scoreboard
//   // ----------------------------------------------------------
//   class vector_scoreboard;
//     mailbox #(issue_sample_t)            issue_mbx;
//     mailbox #(fu_output_sample_t)        fu_out_mbx;
//     mailbox #(reduction_output_sample_t) red_out_mbx;

//     // Per-FU expected-event queues (indexed by DUT FU index)
//     expected_event_t expected_fu_q[LANE_FU_COUNT][$];
//     expected_event_t expected_red_q[$];

//     int unsigned num_errors;
//     int unsigned num_issue_samples;
//     int unsigned num_expected_fu;
//     int unsigned num_expected_red;
//     int unsigned num_observed_fu;
//     int unsigned num_observed_red;

//     function new(mailbox #(issue_sample_t)            issue_mbx,
//                  mailbox #(fu_output_sample_t)        fu_out_mbx,
//                  mailbox #(reduction_output_sample_t) red_out_mbx);
//       this.issue_mbx   = issue_mbx;
//       this.fu_out_mbx  = fu_out_mbx;
//       this.red_out_mbx = red_out_mbx;

//       num_errors        = 0;
//       num_issue_samples = 0;
//       num_expected_fu   = 0;
//       num_expected_red  = 0;
//       num_observed_fu   = 0;
//       num_observed_red  = 0;
//     endfunction

//     task run();
//       fork
//         build_expected_loop();
//         check_fu_loop();
//         check_reduction_loop();
//       join_none
//     endtask

//     // ------------------------------------------------------
//     // 1) Build expectations from *accepted* issues
//     // ------------------------------------------------------
//     task build_expected_loop();
//       issue_sample_t s;
//       forever begin
//         issue_mbx.get(s);
//         num_issue_samples++;
//         build_expected_from_issue(s);
//       end
//     endtask

//     task build_expected_from_issue(issue_sample_t is);
//       int              slot;
//       vsel_t           vd;
//       bit              is_rm_reduction;
//       expected_event_t evt;
//       int              fu_idx_int;

//       for (slot = 0; slot < LANE_ISSUE_W; slot++) begin
//         if (is.slot_accept[slot]) begin
//           fu_idx_int = int'(is.vin.fu_sel[slot]); // fu_t encodes channel index
//           vd         = is.vin.vd[slot];

//           // Bounds check on FU index
//           if (fu_idx_int < 0 || fu_idx_int >= LANE_FU_COUNT) begin
//             continue;
//           end

//           // VALU reduction? -> handled via reduction_valid, not FU channel
//           is_rm_reduction = (is.vin.fu_sel[slot] == VALU) &&
//                             (is.vin.rm[slot] == 1'b1);

//           if (is_rm_reduction) begin
//             // Could push into expected_red_q when you want to check reductions
//             continue;
//           end

//           // ALL-ZERO MASKED VALU: lane never fires FU
//           if ((is.vin.fu_sel[slot] == VALU) && (is.vin.vmask[slot] == '0)) begin
//             continue;
//           end

//           evt.fu_idx       = fu_idx_int;
//           evt.vd           = vd;
//           evt.is_reduction = 1'b0;

//           expected_fu_q[fu_idx_int].push_back(evt);
//           num_expected_fu++;
//         end
//       end
//     endtask

//     // ------------------------------------------------------
//     // 2) Match normal FU outputs
//     // ------------------------------------------------------
//     task check_fu_loop();
//       fu_output_sample_t out_s;
//       forever begin
//         fu_out_mbx.get(out_s);
//         num_observed_fu++;
//         check_one_fu(out_s);
//       end
//     endtask

//     task check_one_fu(fu_output_sample_t out_s);
//       int              fu_idx;
//       expected_event_t evt;

//       fu_idx = out_s.fu_idx;

//       // Check if we even expected an output from this FU
//       if (fu_idx < 0 || fu_idx >= LANE_FU_COUNT ||
//           expected_fu_q[fu_idx].size() == 0) begin
//         num_errors++;
//         $error("[SB] FATAL: FU %0d produced output (vd=%0d) with no expected event queued",
//                fu_idx, out_s.vd);
//         return;
//       end

//       // Enforced in-order per FU
//       evt = expected_fu_q[fu_idx].pop_front();

//       // VD check
//       if (out_s.vd !== evt.vd) begin
//         num_errors++;
//         $error("[SB] VD MISMATCH: FU %0d expected vd=%0d (0x%0h), got vd=%0d (0x%0h)",
//                fu_idx, evt.vd, evt.vd, out_s.vd, out_s.vd);
//       end

//       // Result sanity (Catch X-propagation)
//       if ($isunknown(out_s.result)) begin
//         $warning("[SB] WARNING: FU %0d returned result with X/Z values at vd=%0d",
//                  fu_idx, out_s.vd);
//       end
//     endtask

//     // ------------------------------------------------------
//     // 3) Reduction outputs – just count them for now
//     // ------------------------------------------------------
//     task check_reduction_loop();
//       reduction_output_sample_t red_s;
//       forever begin
//         red_out_mbx.get(red_s);
//         num_observed_red++;
//         // Optionally, add strict checking later once reduction path is done.
//       end
//     endtask

//     // ------------------------------------------------------
//     // Final report / consistency checks
//     // ------------------------------------------------------
//     task report();
//       int pending_fu;
//       int fu;

//       pending_fu  = 0;
//       for (fu = 0; fu < LANE_FU_COUNT; fu++) begin
//         pending_fu += expected_fu_q[fu].size();
//         if (expected_fu_q[fu].size() > 0) begin
//           $display("[SB] PENDING: FU %0d has %0d dropped instructions. First dropped vd=%0d",
//                    fu, expected_fu_q[fu].size(), expected_fu_q[fu][0].vd);
//         end
//       end

//       if (pending_fu != 0) begin
//         num_errors++;
//         $error("[SB] %0d FU events still expected but never observed (Pipeline Drop/Hang)",
//                pending_fu);
//       end

//       $display("  issue_samples   = %0d", num_issue_samples);
//       $display("  exp_fu_events   = %0d, obs_fu_events   = %0d",
//                num_expected_fu, num_observed_fu);
//       $display("  exp_red_events  = %0d, obs_red_events  = %0d",
//                num_expected_red, num_observed_red);
//       $display("  errors          = %0d", num_errors);
//     endtask
//   endclass : vector_scoreboard

//   // ----------------------------------------------------------
//   // Environment: driver + monitor + scoreboard + tests
//   // ----------------------------------------------------------
//   class vector_env;
//     virtual vector_if vif;

//     vector_driver       drv;
//     vector_monitor      mon;
//     vector_scoreboard   sb;

//     mailbox #(vector_cycle_txn)           drv_mbx;
//     mailbox #(issue_sample_t)             issue_mbx;
//     mailbox #(fu_output_sample_t)         fu_out_mbx;
//     mailbox #(reduction_output_sample_t)  red_out_mbx;

//     function new(virtual vector_if vif);
//       this.vif = vif;

//       drv_mbx     = new();
//       issue_mbx   = new();
//       fu_out_mbx  = new();
//       red_out_mbx = new();

//       drv = new(vif, drv_mbx);
//       mon = new(vif, issue_mbx, fu_out_mbx, red_out_mbx);
//       sb  = new(issue_mbx, fu_out_mbx, red_out_mbx);
//     endfunction

//     task run();
//       fork
//         drv.run();
//         mon.run();
//         sb.run();
//       join_none

//       run_directed_tests();
//       run_random_tests(2000);

//       // Drain pipeline a bit
//       repeat (200) @(posedge vif.CLK);

//       $display("====================================================");
//       $display("Scoreboard summary:");
//       sb.report();
//       if (sb.num_errors == 0)
//         $display("TB PASS (no functional mismatches flagged).");
//       else
//         $display("TB FAIL (see errors above).");
//       $display("====================================================");
//       $finish;
//     endtask

//     // ------------------------------------------------------
//     // Helper: emit N idle cycles (no valids)
//     // ------------------------------------------------------
//     task send_idle_cycles(int num_cycles);
//       vector_cycle_txn idle_txn;
//       int              c;
//       int              i;

//       for (c = 0; c < num_cycles; c++) begin
//         idle_txn = new();
//         for (i = 0; i < LANE_ISSUE_W; i++) begin
//           idle_txn.issues[i].slot   = i;
//           idle_txn.issues[i].valid  = 1'b0;
//           idle_txn.issues[i].rm     = 1'b0;
//           idle_txn.issues[i].fu_sel = VALU;
//           idle_txn.issues[i].vd     = '0;
//           idle_txn.issues[i].vop    = valu_op_t'(0);
//           idle_txn.issues[i].v1     = '{default:'0};
//           idle_txn.issues[i].v2     = '{default:'0};
//           idle_txn.issues[i].vmask  = '0;
//         end
//         drv_mbx.put(idle_txn);
//       end
//     endtask

//     // ------------------------------------------------------
//     // Directed tests
//     // ------------------------------------------------------
//     task run_directed_tests();
//       int              i;
//       int              j;
//       vector_cycle_txn txn;

//       $display("[TB] Starting directed tests ...");

//       // 1) Single FU VALU on slot 0, rm=0, all-1 masks
//       for (i = 0; i < 8; i++) begin
//         txn = new();
//         for (j = 0; j < LANE_ISSUE_W; j++) begin
//           txn.issues[j].slot   = j;
//           txn.issues[j].valid  = 1'b0;
//           txn.issues[j].rm     = 1'b0;
//           txn.issues[j].fu_sel = VALU;
//           txn.issues[j].vd     = '0;
//           txn.issues[j].vop    = valu_op_t'(0);
//           txn.issues[j].v1     = '{default:'0};
//           txn.issues[j].v2     = '{default:'0};
//           txn.issues[j].vmask  = '0;
//         end

//         txn.issues[0].valid  = 1'b1;
//         txn.issues[0].rm     = 1'b0;
//         txn.issues[0].fu_sel = VALU;
//         txn.issues[0].vd     = vsel_t'(i);
//         txn.issues[0].vop    = valu_op_t'(0);
//         txn.issues[0].vmask  = '1;
//         txn.issues[0].v1     = '{default:'0};
//         txn.issues[0].v2     = '{default:'0};

//         drv_mbx.put(txn);
//       end

//       send_idle_cycles(20);

//       // 2) Dual-slot issue (slot0: VALU, slot1: MUL)
//       for (i = 0; i < 4; i++) begin
//         txn = new();
//         for (j = 0; j < LANE_ISSUE_W; j++) begin
//           txn.issues[j].slot   = j;
//           txn.issues[j].valid  = 1'b0;
//           txn.issues[j].rm     = 1'b0;
//           txn.issues[j].fu_sel = VALU;
//           txn.issues[j].vd     = '0;
//           txn.issues[j].vop    = valu_op_t'(0);
//           txn.issues[j].v1     = '{default:'0};
//           txn.issues[j].v2     = '{default:'0};
//           txn.issues[j].vmask  = '0;
//         end

//         // slot 0: VALU
//         txn.issues[0].valid  = 1'b1;
//         txn.issues[0].fu_sel = VALU;
//         txn.issues[0].vd     = vsel_t'(i);
//         txn.issues[0].vop    = valu_op_t'(0);
//         txn.issues[0].vmask  = '1;

//         // slot 1: MUL
//         txn.issues[1].valid  = 1'b1;
//         txn.issues[1].fu_sel = MUL;
//         txn.issues[1].vd     = vsel_t'(i + 8);
//         txn.issues[1].vop    = valu_op_t'(0);
//         txn.issues[1].vmask  = '1;

//         drv_mbx.put(txn);
//       end

//       send_idle_cycles(20);

//       // 3) Mask patterns
//       // 3a) all-0 mask
//       txn = new();
//       for (j = 0; j < LANE_ISSUE_W; j++) begin
//         txn.issues[j].slot   = j;
//         txn.issues[j].valid  = 1'b0;
//         txn.issues[j].rm     = 1'b0;
//         txn.issues[j].fu_sel = VALU;
//         txn.issues[j].vd     = '0;
//         txn.issues[j].vop    = valu_op_t'(0);
//         txn.issues[j].v1     = '{default:'0};
//         txn.issues[j].v2     = '{default:'0};
//         txn.issues[j].vmask  = '0;
//       end
//       txn.issues[0].valid  = 1'b1;
//       txn.issues[0].fu_sel = VALU;
//       txn.issues[0].vd     = 0;
//       txn.issues[0].vop    = valu_op_t'(0);
//       txn.issues[0].vmask  = '0;
//       drv_mbx.put(txn);

//       // 3b) all-1 mask
//       txn = new();
//       for (j = 0; j < LANE_ISSUE_W; j++) begin
//         txn.issues[j].slot   = j;
//         txn.issues[j].valid  = 1'b0;
//         txn.issues[j].rm     = 1'b0;
//         txn.issues[j].fu_sel = VALU;
//         txn.issues[j].vd     = '0;
//         txn.issues[j].vop    = valu_op_t'(0);
//         txn.issues[j].v1     = '{default:'0};
//         txn.issues[j].v2     = '{default:'0};
//         txn.issues[j].vmask  = '0;
//       end
//       txn.issues[0].valid  = 1'b1;
//       txn.issues[0].fu_sel = VALU;
//       txn.issues[0].vd     = 1;
//       txn.issues[0].vop    = valu_op_t'(0);
//       txn.issues[0].vmask  = '1;
//       drv_mbx.put(txn);

//       // 3c) alternating mask 1010...
//       txn = new();
//       for (j = 0; j < LANE_ISSUE_W; j++) begin
//         txn.issues[j].slot   = j;
//         txn.issues[j].valid  = 1'b0;
//         txn.issues[j].rm     = 1'b0;
//         txn.issues[j].fu_sel = VALU;
//         txn.issues[j].vd     = '0;
//         txn.issues[j].vop    = valu_op_t'(0);
//         txn.issues[j].v1     = '{default:'0};
//         txn.issues[j].v2     = '{default:'0};
//         txn.issues[j].vmask  = '0;
//       end
//       txn.issues[0].valid  = 1'b1;
//       txn.issues[0].fu_sel = VALU;
//       txn.issues[0].vd     = 2;
//       txn.issues[0].vop    = valu_op_t'(0);
//       for (i = 0; i < VLMAX; i++) begin
//         txn.issues[0].vmask[i] = i[0];
//       end
//       drv_mbx.put(txn);

//       send_idle_cycles(20);

//       // 4) Reduction SUM on VALU (rm=1, fu_sel=VALU)
//       // Scoreboard currently treats these as NOT generating normal FU events.
//       for (i = 0; i < 4; i++) begin
//         txn = new();
//         for (j = 0; j < LANE_ISSUE_W; j++) begin
//           txn.issues[j].slot   = j;
//           txn.issues[j].valid  = 1'b0;
//           txn.issues[j].rm     = 1'b0;
//           txn.issues[j].fu_sel = VALU;
//           txn.issues[j].vd     = '0;
//           txn.issues[j].vop    = valu_op_t'(0);
//           txn.issues[j].v1     = '{default:'0};
//           txn.issues[j].v2     = '{default:'0};
//           txn.issues[j].vmask  = '0;
//         end

//         txn.issues[0].valid  = 1'b1;
//         txn.issues[0].rm     = 1'b1;
//         txn.issues[0].fu_sel = VALU;
//         txn.issues[0].vd     = vsel_t'(16 + i);
//         txn.issues[0].vop    = valu_op_t'(0);
//         txn.issues[0].vmask  = '1;

//         drv_mbx.put(txn);
//       end

//       send_idle_cycles(40);

//       // 5) Simple "full-lane" stress: many back-to-back DIV operations
//       for (i = 0; i < 16; i++) begin
//         txn = new();
//         for (j = 0; j < LANE_ISSUE_W; j++) begin
//           txn.issues[j].slot   = j;
//           txn.issues[j].valid  = 1'b0;
//           txn.issues[j].rm     = 1'b0;
//           txn.issues[j].fu_sel = VALU;
//           txn.issues[j].vd     = '0;
//           txn.issues[j].vop    = valu_op_t'(0);
//           txn.issues[j].v1     = '{default:'0};
//           txn.issues[j].v2     = '{default:'0};
//           txn.issues[j].vmask  = '0;
//         end

//         txn.issues[0].valid  = 1'b1;
//         txn.issues[0].fu_sel = DIV;
//         txn.issues[0].vd     = vsel_t'(32 + i);
//         txn.issues[0].vop    = valu_op_t'(0);
//         txn.issues[0].vmask  = '1;

//         drv_mbx.put(txn);
//       end

//       send_idle_cycles(80);

//       $display("[TB] Directed tests complete.");
//     endtask

//     // ------------------------------------------------------
//     // Constrained random testing
//     // ------------------------------------------------------
//     task run_random_tests(int num_cycles);
//       int              cycle;
//       int              i;
//       vector_cycle_txn txn;

//       $display("[TB] Starting random tests for %0d cycles ...", num_cycles);

//       for (cycle = 0; cycle < num_cycles; cycle++) begin
//         txn = new();

//         for (i = 0; i < LANE_ISSUE_W; i++) begin
//           txn.issues[i].slot = i;
//           void'(txn.issues[i].randomize());
//         end

//         drv_mbx.put(txn);
//       end

//       $display("[TB] Random tests complete.");
//     endtask

//   endclass : vector_env

// endpackage : vector_tb_pkg

// `endif // VECTOR_TB_PKG_SV
