`timescale 1ns/1ps
//`include "ddr_controller_if.sv"
//`include "dram_pkg.svh"

module data_transfer (
    input logic CLK,
    input logic nRST,
    ddr_controller_if.data_transfer dtif
);
    import dram_pkg::*;

    parameter BURST    = 8;
    parameter DQS_BITS = 1;

    logic [DQS_BITS-1:0] DQS_t_1, DQS_t_2, nDQS_t;
    logic [3:0]          count_burst, ncount_burst, cnt1;
    logic [2:0]          COL_choice_tr;

    // Write data path
    logic [WORD_W-1:0] DQ_up;

    assign dtif.DQ    = dtif.wr_en ? DQ_up     : 'z;
    assign dtif.DQS_t = dtif.wr_en ? DQS_t_2   : 'z;
    assign dtif.DQS_c = dtif.wr_en ? ~DQS_t_2  : 'z;
    assign dtif.DM_n  = dtif.wr_en ? 1'b1       : 1'bz;

    assign COL_choice_tr = dtif.COL_choice + 3'd4;

    // Edge detection on DQS_t (single CLK version)
    logic DQS_t_prev;
    logic edge_flag_int;

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) DQS_t_prev <= 1'b1;
        else       DQS_t_prev <= dtif.DQS_t;
    end

    assign edge_flag_int  = (dtif.DQS_t !== DQS_t_prev);
    assign dtif.edge_flag = edge_flag_int;

    // Burst counter and DQS toggle
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            count_burst <= '0;
            cnt1        <= '0;
            DQS_t_2     <= 1'b1;
        end else begin
            if (dtif.wr_en || dtif.rd_en) begin
                count_burst <= ncount_burst;
                cnt1        <= count_burst;
                DQS_t_2     <= nDQS_t;
            end else begin
                count_burst <= '0;
                DQS_t_2     <= 1'b1;
            end
        end
    end

    // Write data latch (on falling edge for DDR alignment)
    always_ff @(negedge CLK, negedge nRST) begin
        if (!nRST) DQ_up <= '0;
        else begin
            if (dtif.wr_en && count_burst >= 4'd3)
                DQ_up <= dtif.memstore;
        end
    end

    // Read data capture
    logic [7:0][WORD_W-1:0] word_register;
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) word_register <= '0;
        else begin
            if (dtif.rd_en && edge_flag_int)
                word_register[count_burst] <= dtif.DQ;
        end
    end

    // Combinational outputs
    always_comb begin
        ncount_burst  = count_burst;
        nDQS_t        = DQS_t_2;
        dtif.memload  = '0;

        if (count_burst >= 4'd2)
            nDQS_t = ~DQS_t_2;

        if (dtif.wr_en || dtif.rd_en)
            ncount_burst = count_burst + 4'd1;

        if (dtif.clear)
            ncount_burst = '0;

        if (edge_flag_int)
            dtif.memload = dtif.DQ;
    end

endmodule
