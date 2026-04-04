`include "vector_pkg.sv"


module vector_ram.sv 
    import vector_pkg::*;
(
    input logic CLK,
    input logic nRST,
    //read ports
    input logic [4:0][7:0] vs1,
    input logic [4:0][7:0] vs2,
    output vreg_t [4:0] rdata1,
    output vreg_t [4:0] rdata2,
    //write ports
    input logic [8:0] wb_ready,
    input logic [8:0] wb_valid,
    input logic [8:0][7:0] vd,
    input vreg_t [8:0] wdata,
    //loading port
    input logic load_valid,
    input logic [7:0] load_addr,
    input vreg_t load_data
);

    vreg_t mem [NUM_VREGS-1:0];

    //reading, schedular handles the valid stuff
    always_comb begin
        rd_data[0] = mem[rd_addr[0]];
        rd_data[1] = mem[rd_addr[1]];
        rd_data[2] = mem[rd_addr[2]];
        rd_data[3] = mem[rd_addr[3]];
        rd_data[4] = mem[rd_addr[4]];
        rd_data[5] = mem[rd_addr[5]];
        rd_data[6] = mem[rd_addr[6]];
        rd_data[7] = mem[rd_addr[7]];
    end

    //writes capable of being stalled by changing ready status

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (int i = 0; i < NUM_VREGS; i++) begin
                mem[i] <= '0;
            end

        end else begin
            if (wb_valid[0] && wb_ready[0]) mem[wb_addr[0]] <= wb_data[0];
            if (wb_valid[1] && wb_ready[1]) mem[wb_addr[1]] <= wb_data[1];
            if (wb_valid[2] && wb_ready[2]) mem[wb_addr[2]] <= wb_data[2];
            if (wb_valid[3] && wb_ready[3]) mem[wb_addr[3]] <= wb_data[3];
            if (wb_valid[4] && wb_ready[4]) mem[wb_addr[4]] <= wb_data[4];
            if (wb_valid[5] && wb_ready[5]) mem[wb_addr[5]] <= wb_data[5];
            if (wb_valid[6] && wb_ready[6]) mem[wb_addr[6]] <= wb_data[6];
            if (wb_valid[7] && wb_ready[7]) mem[wb_addr[7]] <= wb_data[7];
            if (load_valid) mem[load_addr] <= load_data;
        end
    end


    
endmodule