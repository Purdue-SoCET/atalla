//Navya Datla 2/23/2026

`include "atalla_isa_types.vh"
`include "source_reg_allocator_if.vh"

module source_reg_allocator_minimized
    import atalla_isa_pkg::*;
#(
    parameter NUM_INSTRUCTIONS = 4,
    parameter READ_PORTS       = 4
)(
    source_reg_allocator_if.allocator saif
);

    localparam INSTR_IDX = $clog2(NUM_INSTRUCTIONS);

    logic [INSTR_IDX-1:0] port_instr [READ_PORTS];  // tells which instruction owns each port
    logic                 port_src   [READ_PORTS];  // 0 for rs1, 1 for rs2
    logic                 port_valid [READ_PORTS];  //whether port is being used

    int next_port;

    always_comb begin : allocate_ports
     
        // Defaults
        for (int p = 0; p < READ_PORTS; p++) begin
            saif.REN[p]   = 1'b0;
            saif.rsel[p]  = '0;
            port_instr[p] = '0;
            port_src[p]   = 1'b0;
            port_valid[p] = 1'b0;
        end

        for (int i = 0; i < NUM_INSTRUCTIONS; i++) begin
            saif.instrs_out[i]         = saif.instrs_in[i]; //initializes everything else to what decoded instrs came from ctrl unit
            saif.instrs_out[i].r1_data = '0;
            saif.instrs_out[i].r2_data = '0;
        end

        // walk instructions in order, assign next free port to each source
        next_port = 0;
        for (int i = 0; i < NUM_INSTRUCTIONS; i++) begin
            //assigning rs1 to a read port
            if (saif.instrs_in[i].use_rs1 && next_port < READ_PORTS) begin
                saif.REN[next_port]   = 1'b1;
                saif.rsel[next_port]  = saif.instrs_in[i].rs1;
                port_instr[next_port] = INSTR_IDX'(i);
                port_src[next_port]   = 1'b0; //rs1
                port_valid[next_port] = 1'b1;
                next_port++;
            end
            //assigning rs2 to a read port
            if (saif.instrs_in[i].use_rs2 && next_port < READ_PORTS) begin
                saif.REN[next_port]   = 1'b1;
                saif.rsel[next_port]  = saif.instrs_in[i].rs2;
                port_instr[next_port] = INSTR_IDX'(i);
                port_src[next_port]   = 1'b1; //rs2
                port_valid[next_port] = 1'b1;
                next_port++;
            end
        end
    end

endmodule