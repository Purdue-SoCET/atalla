// ============================================================================
// perf_monitor.sv
// Passive performance monitor for vector core testbenches
//
// Instantiate alongside DUT monitors interfaces without driving anything.
// Prints comprehensive performance summary at end of simulation.
//
// Based off Mayanks perf counters in the lane and gsau wrappers.
// Location: tb/unit/vector/
//
// Usage in testbench:
//   perf_monitor perf_inst (
//       .CLK(CLK),
//       .nRST(nRST),
//       .vif(vif),
//       .gsauif(gsauif),
//       .sif(sif)
//   );
//   // Call at end: perf_inst.print_summary(cycle_count);
// ============================================================================

`include "vector_pkg.vh"
`include "vector_if.vh"
`include "gsau_control_unit_if.vh"

module perf_monitor (
    input logic CLK,
    input logic nRST,
    vector_if vif,
    gsau_control_unit_if gsauif,
    scpad_if sif
);
    `include "scpad_params.svh"
    import vector_pkg::*;
    import scpad_pkg::*;

    // -----------------------------------------------------------------------
    // Lane Counters (per issue port and per FU)
    // -----------------------------------------------------------------------
    int lane_issue_count [2];          // instructions issued per port
    int lane_alu_wb_count;             // ALU writeback count
    int lane_mul_wb_count;             // MUL writeback count
    int lane_idle_cycles;              // cycles with no lane issue

    // -----------------------------------------------------------------------
    // Reduction Counters
    // -----------------------------------------------------------------------
    int reduction_wb_count;

    // -----------------------------------------------------------------------
    // GSAU / Systolic Array Counters
    // -----------------------------------------------------------------------
    int gsau_issue_count;              // valid_in & ready accepted
    int gsau_stall_count;              // valid_in but not ready
    int gsau_starve_count;             // no valid_in
    int gsau_wb_count;                 // writeback from SA
    int gsau_weight_load_count;        // weight load cycles
    int gsau_activation_count;         // activation input cycles
    int sa_bp_count;                   // SA backpressure (sa_ready_in LOW)
    int sa_bp_max_consecutive;         // max consecutive BP cycles
    int sa_bp_current_streak;          // current streak tracker

    // -----------------------------------------------------------------------
    // VLSU / Scratchpad Counters
    // -----------------------------------------------------------------------
    int vlsu_issue_count [NUM_SCPADS]; // per-port issue count
    int vlsu_store_count [NUM_SCPADS]; // per-port store count
    int vlsu_load_count [NUM_SCPADS];  // per-port load count
    int vlsu_wb_count [NUM_SCPADS];    // per-port writeback count
    int vlsu_stall_count [NUM_SCPADS]; // per-port stall cycles
    int vlsu_total_stall;              // total stall across all ports

    // -----------------------------------------------------------------------
    // Timing
    // -----------------------------------------------------------------------
    int first_issue_cycle;             // cycle of first instruction issue
    int last_wb_cycle;                 // cycle of last writeback
    int total_active_cycles;           // cycles where at least something happened

    // -----------------------------------------------------------------------
    // Initialize
    // -----------------------------------------------------------------------
    initial begin
        for (int i = 0; i < 2; i++) lane_issue_count[i] = 0;
        lane_alu_wb_count = 0;
        lane_mul_wb_count = 0;
        lane_idle_cycles = 0;
        reduction_wb_count = 0;

        gsau_issue_count = 0;
        gsau_stall_count = 0;
        gsau_starve_count = 0;
        gsau_wb_count = 0;
        gsau_weight_load_count = 0;
        gsau_activation_count = 0;
        sa_bp_count = 0;
        sa_bp_max_consecutive = 0;
        sa_bp_current_streak = 0;

        for (int i = 0; i < NUM_SCPADS; i++) begin
            vlsu_issue_count[i] = 0;
            vlsu_store_count[i] = 0;
            vlsu_load_count[i] = 0;
            vlsu_wb_count[i] = 0;
            vlsu_stall_count[i] = 0;
        end
        vlsu_total_stall = 0;

        first_issue_cycle = -1;
        last_wb_cycle = 0;
        total_active_cycles = 0;
    end

    // -----------------------------------------------------------------------
    // Sample every posedge CLK
    // -----------------------------------------------------------------------
    int internal_cycle;
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            internal_cycle <= 0;
        end else begin
            internal_cycle <= internal_cycle + 1;
            sample();
        end
    end

    // -----------------------------------------------------------------------
    // Sample task — called every cycle
    // -----------------------------------------------------------------------
    task automatic sample();
        logic any_activity;
        any_activity = 0;

        // --- Lane Issue ---
        for (int p = 0; p < 2; p++) begin
            if (vif.lanes_in.lane_issue_ports[p].input_valid) begin
                lane_issue_count[p]++;
                any_activity = 1;
                if (first_issue_cycle == -1)
                    first_issue_cycle = internal_cycle;
            end
        end

        // Lane idle detection — only count after reset
        if (nRST) begin
            if (!vif.lanes_in.lane_issue_ports[0].input_valid &&
                !vif.lanes_in.lane_issue_ports[1].input_valid)
                lane_idle_cycles++;
        end

        // --- Lane WB ---
        if (LANE_FU_COUNT > 0 && vif.lanes_out.result_collectors[0].wb_valid) begin
            lane_alu_wb_count++;
            last_wb_cycle = internal_cycle;
            any_activity = 1;
        end
        if (LANE_FU_COUNT > 1 && vif.lanes_out.result_collectors[1].wb_valid) begin
            lane_mul_wb_count++;
            last_wb_cycle = internal_cycle;
            any_activity = 1;
        end

        // --- Reduction WB ---
        if (vif.lanes_out.reduction.wb_valid) begin
            reduction_wb_count++;
            last_wb_cycle = internal_cycle;
            any_activity = 1;
        end

        // --- GSAU Issue ---
        if (vif.gsau_in.valid_in) begin
            if (gsauif.sb_ready_out) begin
                gsau_issue_count++;
                any_activity = 1;
                if (first_issue_cycle == -1)
                    first_issue_cycle = internal_cycle;
            end else begin
                gsau_stall_count++;
            end
        end else begin
            gsau_starve_count++;
        end

        // --- GSAU Weight/Activation ---
        if (gsauif.sa_weight_en)
            gsau_weight_load_count++;
        if (gsauif.sa_input_en)
            gsau_activation_count++;

        // --- GSAU WB ---
        if (gsauif.wb_valid_out) begin
            gsau_wb_count++;
            last_wb_cycle = internal_cycle;
            any_activity = 1;
        end

        // --- SA Backpressure ---
        if (!gsauif.sa_ready_in) begin
            sa_bp_count++;
            sa_bp_current_streak++;
            if (sa_bp_current_streak > sa_bp_max_consecutive)
                sa_bp_max_consecutive = sa_bp_current_streak;
        end else begin
            sa_bp_current_streak = 0;
        end

        // --- VLSU ---
        for (int p = 0; p < NUM_SCPADS; p++) begin
            if (vif.vlsu_in.sched_req[p].valid) begin
                vlsu_issue_count[p]++;
                any_activity = 1;
                if (first_issue_cycle == -1)
                    first_issue_cycle = internal_cycle;
                if (vif.vlsu_in.sched_req[p].write)
                    vlsu_store_count[p]++;
                else
                    vlsu_load_count[p]++;
            end
            if (vif.vlsu_out.wb[p].valid) begin
                vlsu_wb_count[p]++;
                last_wb_cycle = internal_cycle;
                any_activity = 1;
            end
            if (sif.fe_vec_stall[p]) begin
                vlsu_stall_count[p]++;
                vlsu_total_stall++;
            end
        end

        if (any_activity)
            total_active_cycles++;
    endtask

    // -----------------------------------------------------------------------
    // Print Summary — call from testbench: perf_inst.print_summary(cycle_count);
    // -----------------------------------------------------------------------
    task automatic print_summary(input int total_cycles);
        int total_lane_issues, total_vlsu_issues, total_vlsu_wbs;
        int total_wbs;
        real utilization, ipc;

        total_lane_issues = lane_issue_count[0] + lane_issue_count[1];
        total_vlsu_issues = 0;
        total_vlsu_wbs = 0;
        for (int i = 0; i < NUM_SCPADS; i++) begin
            total_vlsu_issues += vlsu_issue_count[i];
            total_vlsu_wbs += vlsu_wb_count[i];
        end
        total_wbs = lane_alu_wb_count + lane_mul_wb_count + reduction_wb_count + gsau_wb_count + total_vlsu_wbs;

        if (total_cycles > 0)
            utilization = (real'(total_active_cycles) / real'(total_cycles)) * 100.0;
        else
            utilization = 0.0;

        if (total_cycles > 0)
            ipc = real'(total_lane_issues + gsau_issue_count + total_vlsu_issues) / real'(total_cycles);
        else
            ipc = 0.0;

        $display("");
        $display("[PERF] ================================================================");
        $display("[PERF]              PERFORMANCE COUNTER SUMMARY");
        $display("[PERF] ================================================================");
        $display("[PERF]  Total Cycles:          %0d", total_cycles);
        $display("[PERF]  Active Cycles:         %0d (%.1f%% utilization)", total_active_cycles, utilization);
        $display("[PERF]  First Issue Cycle:     %0d", first_issue_cycle);
        $display("[PERF]  Last WB Cycle:         %0d", last_wb_cycle);
        $display("[PERF]  Pipeline Latency:      %0d cycles", last_wb_cycle - first_issue_cycle);
        $display("[PERF]  IPC:                   %.3f", ipc);
        $display("[PERF] ----------------------------------------------------------------");
        $display("[PERF]  LANE STATISTICS");
        $display("[PERF]    Issue Port 0:        %0d instructions", lane_issue_count[0]);
        $display("[PERF]    Issue Port 1:        %0d instructions", lane_issue_count[1]);
        $display("[PERF]    Total Lane Issues:   %0d", total_lane_issues);
        $display("[PERF]    Idle Cycles:         %0d (%.1f%%)", total_cycles - total_active_cycles,
            total_cycles > 0 ? (real'(total_cycles - total_active_cycles) / real'(total_cycles)) * 100.0 : 0.0);
        $display("[PERF]    ALU Writebacks:      %0d", lane_alu_wb_count);
        $display("[PERF]    MUL Writebacks:      %0d", lane_mul_wb_count);
        $display("[PERF]    Reduction WBs:       %0d", reduction_wb_count);
        $display("[PERF] ----------------------------------------------------------------");
        $display("[PERF]  GSAU / SYSTOLIC ARRAY STATISTICS");
        $display("[PERF]    Issues Accepted:     %0d", gsau_issue_count);
        $display("[PERF]    Issue Stalls:        %0d (%.1f%%)", gsau_stall_count,
            (gsau_issue_count + gsau_stall_count) > 0 ?
            (real'(gsau_stall_count) / real'(gsau_issue_count + gsau_stall_count)) * 100.0 : 0.0);
        $display("[PERF]    Weight Loads:        %0d cycles", gsau_weight_load_count);
        $display("[PERF]    Activation Inputs:   %0d cycles", gsau_activation_count);
        $display("[PERF]    SA Writebacks:       %0d", gsau_wb_count);
        $display("[PERF]    SA Backpressure:     %0d cycles (max streak: %0d)", sa_bp_count, sa_bp_max_consecutive);
        $display("[PERF] ----------------------------------------------------------------");
        $display("[PERF]  VLSU / SCRATCHPAD STATISTICS");
        for (int p = 0; p < NUM_SCPADS; p++) begin
            if (vlsu_issue_count[p] > 0 || vlsu_stall_count[p] > 0)
                $display("[PERF]    Port %0d: issues=%0d (ld=%0d st=%0d) wb=%0d stall=%0d",
                    p, vlsu_issue_count[p], vlsu_load_count[p], vlsu_store_count[p],
                    vlsu_wb_count[p], vlsu_stall_count[p]);
        end
        $display("[PERF]    Total VLSU Stalls:   %0d cycles", vlsu_total_stall);
        $display("[PERF] ----------------------------------------------------------------");
        $display("[PERF]  TOTAL WRITEBACKS:      %0d", total_wbs);
        $display("[PERF] ================================================================");
        $display("");
    endtask

endmodule