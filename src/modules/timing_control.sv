`include "dram_pkg.vh"
`include "timing_signals_if.vh"
`include "command_fsm_if.vh"

module timing_control (
    input logic clk, nRST,
    timing_signals_if.timing_ctrl timif,
    command_fsm_if.timing_ctrl cfsmif
);
    import dram_pkg::*;
      
    // time counter signals
    parameter N = 10;
    logic [N-1:0] time_load, time_count;
    logic time_counter_en, time_count_done;

    // dREN and dWEN edge detect
    logic prev_dREN, prev_dWEN;
    logic dREN_edge, dWEN_edge;

    always_ff @(posedge clk, negedge nRST) begin : EDGE_DET_REG
        if (~nRST) begin
            prev_dREN <= 1'b0;
            prev_dWEN <= 1'b0;
        end
        else begin
            prev_dREN <= cfsmif.dREN;
            prev_dWEN <= cfsmif.dWEN;
        end
    end

    always_comb begin : EDGE_DET_COMB
        dREN_edge = cfsmif.dREN && (~prev_dREN);
        dWEN_edge = cfsmif.dWEN && (~prev_dWEN);
    end

    always_comb begin
        timif.tACT_done = 1'b0;
        timif.tWRITE_done = 1'b0;
        timif.tRD_done = 1'b0;
        timif.tPRE_done = 1'b0;
        timif.tREF_done = 1'b0;
        timif.tWR_done = 1'b0;
        timif.tWTR_done = 1'b0;
        timif.tRAS_done = 1'b0;
        
        time_counter_en = 1'b0;
        time_load = '0;
        timif.wr_en = 1'b0;
        timif.rd_en = 1'b0;

        case (cfsmif.cmd_state)
            ACTIVATE : begin
                time_counter_en = 1'b1;
                time_load = tRAS;
                
            end

            ACTIVATING : begin
                if (time_count <= tRAS - (tRCD - tAL)) begin
                    timif.tACT_done = 1'b1;
                end

                timif.tRAS_done = time_count_done;
            end

            READ : begin
                time_counter_en = 1'b1;
                time_load = tRL + tBURST;
            end

            READING : begin
                if (time_count == tBURST) begin
                    timif.rd_en = 1'b1;
                end

                if (time_count_done == 1'b1) begin
                    timif.tRD_done = 1'b1;
                end
            end

            WRITE : begin
                time_counter_en = 1'b1;
                time_load = tWL + tBURST + tWR;
            end

            WRITING : begin
                if (time_count <= tBURST + tWR) begin
                    timif.wr_en = 1'b1;
                end

                if (time_count <= tWR) begin
                    timif.tWRITE_done = 1'b1;
                end
                
                if (time_count <= (tWR - tWTR)) begin
                    timif.tWTR_done = 1'b1;
                end
	                
	            timif.tWR_done = time_count_done;
            end

            PRECHARGE : begin
                time_counter_en = 1'b1;
                time_load = tRP;
            end

            PRECHARGING : begin
                if (time_count_done == 1'b1) begin
                    timif.tPRE_done = 1'b1;
                end
            end

            PRECHARGING_ALL : begin
                if (time_count_done == 1'b1) begin
                    timif.tPRE_done = 1'b1;
                end
            end

            REFRESH : begin
                time_counter_en = 1'b1;
                time_load = tRFC;
            end

            REFRESHING : begin
                if (time_count_done == 1'b1) begin
                    timif.tREF_done = 1'b1;
                end
            end

        endcase
    end

    assign timif.clear = timif.tRD_done || timif.tWRITE_done;

    //////////// REFRESH ////////////
    logic [N-1:0] refresh_limit, next_refresh_limit;
    logic [N-1:0] refresh_count, next_refresh_count;

    always_ff @(posedge clk, negedge nRST) begin : REFRESH_REG_LOGIC
        if (~nRST) begin
            refresh_count <= '0;
            refresh_limit <= tREFI;
        end

        else begin
            refresh_count <= next_refresh_count;
            refresh_limit <= next_refresh_limit;
        end
    end

    always_comb begin : REFRESH_COMB_LOGIC
        timif.rf_req = 1'b0;

        // REFRESH command is required every tREFI on average.
        // If refresh counter is over the tREFI limit, subtract the
        // additional time from tREFI for next refresh limit.
        
        next_refresh_limit = refresh_limit;

        if (cfsmif.cmd_state == REFRESH) begin
            if (refresh_count < tREFI) begin
                next_refresh_limit = tREFI;
            end
        end
        else begin
            if (refresh_count > tREFI) begin
                next_refresh_limit = tREFI - (refresh_count - tREFI);
            end
        end

        
        // Set the refresh counter to 0 in the REFRESH state.
        // Otherwise, the refresh counter is always incrementing.

        next_refresh_count = refresh_count;
        if (cfsmif.init_done == 1'b1) begin
            next_refresh_count = refresh_count + 1;
        end
        if (cfsmif.cmd_state == REFRESH || cfsmif.cmd_state == REFRESHING) begin
            next_refresh_count = '0;
        end

        // Maximum time between refreshes is 9 * tREFI.
        // if (refresh_count == MAX_tREFRESH_LIMIT - (tWL + tRP) || refresh_count == tREFRESH_LIMIT - (tRL + tRP)) begin
        //     timif.rf_req = 1'b1;
        // end
        // Set the refresh request high when refresh count over or equal the refresh limit.
        if ((refresh_count >= refresh_limit) && (cfsmif.cmd_state != REFRESH)) begin
            timif.rf_req = 1'b1;
        end

        // disabling rf_req for testing control unit
        // timif.rf_req = 1'b0;
    end 

    flex_counter #(.N(N)) time_counter (.clk(clk), .nRST(nRST), .enable(time_counter_en),
                                        .count_load(time_load), .count(time_count), 
                                        .count_done(time_count_done));

    


endmodule