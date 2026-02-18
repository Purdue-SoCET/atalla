`include "axi_bus_if.sv"

module axi_skid_buffer 
import axi_bus_pkg::*;
(
    input logic CLK, nRST,
    input master_r_channel_t r_in,
    input logic ready, selected, in_val,
    output master_r_channel_t r_out,
    output logic out_val
);
    

    master_r_channel_t out_reg, n_out_reg;
    logic full, n_full;

    assign out_val = in_val & selected;

    always_ff @ ( posedge CLK, negedge nRST ) begin
        if (~nRST) begin
            out_reg <= '0;
            full <= 0;
        end 
        else begin
            out_reg <= n_out_reg;
            full <= n_full;
        end
    end

    always_comb begin
        n_full = 0;
        n_out_reg = '0;
        r_out = 0;

        if (~ready && selected) begin
            n_out_reg = r_in;
            n_full = 1;
        end

        // output logic: if full, get buffer data; else get in pass through
        if (ready && full) r_out = out_reg;
        else if (ready && ~full) r_out = r_in;
    end
    
endmodule