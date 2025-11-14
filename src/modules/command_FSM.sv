`timescale 1ps/1ps
`include "command_fsm_if.vh"

module command_FSM (
    input logic CLK,
    input logic nRST,
    command_fsm_if.cmd_fsm mycmd,
    row_open_if.cmd_fsm polif,
    timing_signals_if.cmd_fsm timif
);
    import dram_pkg::*;
    localparam logic [1:0] IDLE_R = 2'b00;
    localparam logic [1:0] HIT = 2'b01;
    localparam logic [1:0] MISS = 2'b10;
    localparam logic [1:0] CONFLICT = 2'b11;
    logic nram_wait;

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            mycmd.cmd_state <= POWER_UP;
        end else begin
            mycmd.cmd_state <= mycmd.ncmd_state;
        end
    end

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            mycmd.ram_wait <= 1;
        end else begin
            mycmd.ram_wait <= nram_wait;
        end
    end

    // dREN and dWEN edge detect
    logic prev_dREN, prev_dWEN;
    logic dREN_edge, dWEN_edge;

    always_ff @(posedge CLK, negedge nRST) begin : EDGE_DET_REG
        if (~nRST) begin
            prev_dREN <= 1'b0;
            prev_dWEN <= 1'b0;
        end
        else begin
            prev_dREN <= mycmd.dREN;
            prev_dWEN <= mycmd.dWEN;
        end
    end

    always_comb begin : EDGE_DET_COMB
        dREN_edge = mycmd.dREN && (~prev_dREN);
        dWEN_edge = mycmd.dWEN && (~prev_dWEN);
    end
    // dREN and dWEN edge detect

    always_comb begin
        mycmd.ncmd_state = mycmd.cmd_state;
        mycmd.row_resolve = 1'b0;
        mycmd.init_req = 0;
        nram_wait = 1;
        casez (mycmd.cmd_state)

            POWER_UP: begin
                mycmd.init_req = 1;
                if (mycmd.init_done) mycmd.ncmd_state = IDLE;
            end

            REFRESH: begin
                mycmd.ncmd_state = REFRESHING;
                
            end

            REFRESHING: begin
                if (timif.tREF_done) begin
                    mycmd.ncmd_state = IDLE;     
                end
            end

            IDLE: begin
                // if (timif.rf_req) mycmd.ncmd_state = PRECHARGE;
                // else if (mycmd.dWEN || mycmd.dREN) begin
                //     if (polif.row_stat == HIT) mycmd.ncmd_state = mycmd.dWEN ? WRITE : READ;
                //     else if(polif.row_stat == CONFLICT) mycmd.ncmd_state = PRECHARGE;
                //     else if (polif.row_stat == MISS) mycmd.ncmd_state = ACTIVATE;
                // end
                if (timif.rf_req) begin
                    mycmd.ncmd_state = REFRESH;
                end
                
                else if (mycmd.dWEN || mycmd.dREN) begin
                    mycmd.ncmd_state = ACTIVATE;
                end
            end

            ACTIVATE: begin
                if (timif.rf_req) begin mycmd.ncmd_state = PRECHARGE;end
                else begin mycmd.ncmd_state = ACTIVATING; end
            end

            ACTIVATING: begin
                if (timif.tACT_done) begin
                    mycmd.ncmd_state = timif.rf_req ? PRECHARGE : mycmd.dWEN ? WRITE : READ;
                end
            end

            WRITE: begin mycmd.ncmd_state = timif.rf_req ? PRECHARGE : WRITING; end
            READ : begin mycmd.ncmd_state = timif.rf_req ? PRECHARGE : READING; end
            
            WRITING: begin
                if (timif.tWR_done) begin
                    nram_wait = 1'b0;
                    
                    /* Old logic begin
                    if (timif.rf_req) begin mycmd.ncmd_state = WAIT_AFTER_WRITE; end
                   
                    else begin
                        mycmd.ncmd_state = IDLE;
                    end 
                    Old logic end */
                    if (dWEN_edge && polif.row_stat == HIT) begin
                        mycmd.ncmd_state = WRITE;
                    end
                    else if (dREN_edge || timif.rf_req) begin
                        mycmd.ncmd_state = WAIT_AFTER_WRITE;
                    end 
                end
            end

            WAIT_AFTER_WRITE: begin mycmd.ncmd_state = WAITING_AFTER_WRITE; end

            WAITING_AFTER_WRITE: begin
                if (timif.tWRITE_WAIT_done) begin
                    mycmd.ncmd_state = PRECHARGE;
                end
            end

            READING: begin
                if (timif.tRD_done) begin
                    nram_wait = 1'b0;
                    
                    if ((dWEN_edge || dREN_edge) && polif.row_stat != HIT) begin 
                        mycmd.ncmd_state = PRECHARGE; 
                    end
                    else if (polif.row_stat == HIT) begin
                        if (dREN_edge) begin
                            mycmd.ncmd_state = READ;
                        end

                        else if (dWEN_edge) begin
                            mycmd.ncmd_state = WRITE;
                        end
                    end

                    if (timif.rf_req) begin
                        mycmd.ncmd_state = PRECHARGE;
                    end
                    // else if (mycmd.dWEN || mycmd.dREN) begin
                    //     if (polif.row_stat == HIT) mycmd.ncmd_state = mycmd.dWEN ? WRITE : READ;
                    //     else if(polif.row_stat == CONFLICT) mycmd.ncmd_state = PRECHARGE;
                    //     else if (polif.row_stat == MISS) mycmd.ncmd_state = ACTIVATE;
                    // end
                    // else begin
                    //     mycmd.ncmd_state = IDLE;
                    // end 
                end 
            end

            PRECHARGE: begin
                mycmd.ncmd_state = PRECHARGING;
            end

            PRECHARGING: begin
                if (timif.tPRE_done) begin
                    mycmd.row_resolve = 1'b1;
                    mycmd.ncmd_state = timif.rf_req ? REFRESH : IDLE;
                end

            end
        endcase
    end

endmodule