`include "fu_scalar_ls_if.vh"


module fu_scalar_ls (
    input logic CLK, nRST,
    fu_scalar_ls_if.sls sls_if
);

    import types_pkg::*;
    import cpu_types::*;

    typedef enum logic [1:0] { 
        idle, latched
    } state_t;

    state_t state, next_state;

    word_t lacthed_dmemaddr, latched_dmemstore;
    logic latched_dmemREN, latched_dmemWEN;

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            state <= idle;
            lacthed_dmemaddr <= '0;
            latched_dmemstore <= '0;
            latched_dmemREN <= '0;
            latched_dmemWEN <= '0;
        end
        else begin
            state <= next_state;
            lacthed_dmemaddr <= addr;
            latched_dmemstore <= sls_if.rs2;
            latched_dmemREN <= read;
            latched_dmemWEN <= write;
        end
    end
     
    assign addr = sls_if.imm + sls_if.rs1;
    assign write = (sls_if.mem_type == STORE);
    assign read = (sls_if.mem_type == LOAD);

    always_comb begin
        next_state = state;
        sls_if.dmemaddr = '0;
        sls_if.dmemstore = '0;
        sls_if.dmemWEN = '0;
        sls_if.dmemstore = '0;
        sls_if.dhit = '0;
        casez (state) 
            idle: begin
                if (sls_if.mem_type == STORE) begin
                    sls_if.dmemaddr = addr;
                    next_state = latched;
                    sls_if.dmemWEN = write;
                    sls_if.dmemstore = sls_if.rs2;
                    if (sls_if.dhit_in) begin
                        next_state = idle;
                        sls_if.dmemWEN = '0;
                        sls_if.dhit = '1;
                    end
                end 
                else if (sls_if.mem_type == LOAD) begin
                    sls_if.dmemaddr = addr;
                    next_state = latched;
                    sls_if.dmemREN = read;
                    if (sls_if.dhit_in) begin
                        next_state = idle;
                        sls_if.dmemload = sls_if.dmem_in;
                        sls_if.dmemREN = '0;
                        sls_if.dhit = '1;
                    end
                end
                else begin
                    next_state = idle;
                end
            end
            latched: begin
                if (sls_if.mem_type == STORE) begin
                    sls_if.dmemaddr = latched_dmemaddr;
                    sls_if.dmemWEN = latched_dmemWEN;
                    sls_if.dmemstore = sls_if.rs2;
                    if (sls_if.dhit_in) begin
                        next_state = idle;
                        sls_if.dmemWEN = '0;
                        sls_if.dhit = '1;
                    end
                end 
                else if (sls_if.mem_type == LOAD) begin
                    sls_if.dmemaddr = latched_dmemaddr;
                    sls_if.dmemREN = latched_dmemREN;
                    if (sls_if.dhit_in) begin
                        next_state = idle;
                        sls_if.dmemload = sls_if.dmem_in;
                        sls_if.dmemREN = '0;
                        sls_if.dhit = '1;
                    end
                end
                else begin
                    next_state = latched;
                end
            end

        endcase
    end




endmodule