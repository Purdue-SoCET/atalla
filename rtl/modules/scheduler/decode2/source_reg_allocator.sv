// Navya Datla 3/25/26 (used claude to help update for vec/SDMA instrs)

`include "atalla_isa_types.vh"
`include "source_reg_allocator_if.vh"

module source_reg_allocator
    import atalla_isa_pkg::*;
#(
    parameter NUM_SCALAR_INSTRUCTIONS = 4,
    parameter NUM_VECTOR_INSTRUCTIONS = 4,
    parameter NUM_SDMA_INSTRUCTIONS   = 4,
    parameter SCALAR_READ_PORTS       = 4,
    parameter VECTOR_READ_PORTS       = 4,
    parameter MASK_READ_PORTS         = 2
)(
    source_reg_allocator_if.allocator saif
);

    localparam SCALAR_INSTR_IDX = $clog2(NUM_SCALAR_INSTRUCTIONS); 
    localparam VECTOR_INSTR_IDX = $clog2(NUM_VECTOR_INSTRUCTIONS);
    localparam SDMA_INSTR_IDX   = $clog2(NUM_SDMA_INSTRUCTIONS);

    // Scalar port tracking (TRACKING IS BY PORT FOR REG FILE)
    // port_src: 0=scalar rs1, 1=scalar rs2, 2=vector's rs1, 3=sdma rs1_rd, 4=sdma rs2, 5=sdma rs3, 6=vector's rs2
    logic [SCALAR_INSTR_IDX-1:0] scalar_port_instr  [SCALAR_READ_PORTS];   //the index of instruction that owns this port (position in VLIW packet)
    logic [2:0]                  scalar_port_src    [SCALAR_READ_PORTS];  
    logic                        scalar_port_valid   [SCALAR_READ_PORTS]; //is port being used
    logic                        scalar_port_is_vec  [SCALAR_READ_PORTS]; //indexes into vector_instrs_out
    logic                        scalar_port_is_sdma [SCALAR_READ_PORTS]; //indexes into sdma_instrs_out

    // Vector port tracking 
    // port_src: 0=vs1, 1=vs2
    logic [VECTOR_INSTR_IDX-1:0] vector_port_instr [VECTOR_READ_PORTS]; //the index of instruction that owns this port (position in VLIW packet)
    logic                        vector_port_src   [VECTOR_READ_PORTS]; //0=vs1, 1=vs2
    logic                        vector_port_valid  [VECTOR_READ_PORTS];

    // --- Mask port tracking 
    logic [VECTOR_INSTR_IDX-1:0] mask_port_instr [MASK_READ_PORTS]; //the index of instruction that owns this port (position in VLIW packet)
    logic                        mask_port_valid  [MASK_READ_PORTS];

    int next_scalar_port;
    int next_vector_port;
    int next_mask_port;

    always_comb begin : allocate_ports

        // Defaults
        for (int p = 0; p < SCALAR_READ_PORTS; p++) begin
            saif.scalar_REN[p]     = 1'b0;
            saif.scalar_rsel[p]    = '0;
            scalar_port_instr[p]   = '0;
            scalar_port_src[p]     = '0;
            scalar_port_valid[p]   = 1'b0;
            scalar_port_is_vec[p]  = 1'b0;
            scalar_port_is_sdma[p] = 1'b0;
        end

        for (int p = 0; p < VECTOR_READ_PORTS; p++) begin
            saif.vector_REN[p]   = 1'b0;
            saif.vector_rsel[p]  = '0;
            vector_port_instr[p] = '0;
            vector_port_src[p]   = 1'b0;
            vector_port_valid[p] = 1'b0;
        end

        for (int p = 0; p < MASK_READ_PORTS; p++) begin
            saif.mask_REN[p]   = 1'b0;
            saif.mask_rsel[p]  = '0;
            mask_port_instr[p] = '0;
            mask_port_valid[p] = 1'b0;
        end

        //initializing all values from instrs_out to instrs_in and data fields to 0, will overwrite with the valid ones below
        for (int i = 0; i < NUM_SCALAR_INSTRUCTIONS; i++) begin
            saif.scalar_instrs_out[i]         = saif.scalar_instrs_in[i];
            saif.scalar_instrs_out[i].r1_data = '0;
            saif.scalar_instrs_out[i].r2_data = '0;
        end

        for (int i = 0; i < NUM_VECTOR_INSTRUCTIONS; i++) begin
            saif.vector_instrs_out[i]          = saif.vector_instrs_in[i];
            saif.vector_instrs_out[i].vs1_data = '0;
            saif.vector_instrs_out[i].vs2_data = '0;
            saif.vector_instrs_out[i].rs1_data = '0;
            saif.vector_instrs_out[i].rs2_data = '0;
            saif.vector_instrs_out[i].vms_data = '0;
        end

        for (int i = 0; i < NUM_SDMA_INSTRUCTIONS; i++) begin
            saif.sdma_instrs_out[i]             = saif.sdma_instrs_in[i];
            saif.sdma_instrs_out[i].rs1_rd_data = '0;
            saif.sdma_instrs_out[i].rs2_data    = '0;
            saif.sdma_instrs_out[i].rs3_data    = '0;
        end

        // ---------------------------------------------------------------
        // Allocate scalar read ports
        // ---------------------------------------------------------------
        next_scalar_port = 0;

        // Scalar instructions: rs1, rs2
        for (int i = 0; i < NUM_SCALAR_INSTRUCTIONS; i++) begin
            if (saif.scalar_instrs_in[i].use_rs1 && next_scalar_port < SCALAR_READ_PORTS) begin
                saif.scalar_REN[next_scalar_port]   = 1'b1;
                saif.scalar_rsel[next_scalar_port]  = saif.scalar_instrs_in[i].rs1;
                scalar_port_instr[next_scalar_port] = SCALAR_INSTR_IDX'(i);
                scalar_port_src[next_scalar_port]   = 3'd0; // rs1
                scalar_port_valid[next_scalar_port] = 1'b1;
                next_scalar_port++;
            end
            if (saif.scalar_instrs_in[i].use_rs2 && next_scalar_port < SCALAR_READ_PORTS) begin
                saif.scalar_REN[next_scalar_port]   = 1'b1;
                saif.scalar_rsel[next_scalar_port]  = saif.scalar_instrs_in[i].rs2;
                scalar_port_instr[next_scalar_port] = SCALAR_INSTR_IDX'(i);
                scalar_port_src[next_scalar_port]   = 3'd1; // rs2
                scalar_port_valid[next_scalar_port] = 1'b1;
                next_scalar_port++;
            end
        end

        // Vector instructions: rs1 (scalar source)
        for (int i = 0; i < NUM_VECTOR_INSTRUCTIONS; i++) begin
            if (saif.vector_instrs_in[i].use_rs1 && next_scalar_port < SCALAR_READ_PORTS) begin
                saif.scalar_REN[next_scalar_port]    = 1'b1;
                saif.scalar_rsel[next_scalar_port]   = saif.vector_instrs_in[i].rs1;
                scalar_port_instr[next_scalar_port]  = SCALAR_INSTR_IDX'(i);
                scalar_port_src[next_scalar_port]    = 3'd2; // vector's rs1
                scalar_port_valid[next_scalar_port]  = 1'b1;
                scalar_port_is_vec[next_scalar_port] = 1'b1;
                next_scalar_port++;
                
            end
            if (saif.vector_instrs_in[i].use_rs2 && next_scalar_port < SCALAR_READ_PORTS) begin
                saif.scalar_REN[next_scalar_port]    = 1'b1;
                saif.scalar_rsel[next_scalar_port]   = saif.vector_instrs_in[i].rs2;
                scalar_port_instr[next_scalar_port]  = SCALAR_INSTR_IDX'(i);
                scalar_port_src[next_scalar_port]    = 3'd6; // vector's rs2
                scalar_port_valid[next_scalar_port]  = 1'b1;
                scalar_port_is_vec[next_scalar_port] = 1'b1;
                next_scalar_port++;
                
            end
        end

        // SDMA instructions: rs1_rd, rs2, rs3
        for (int i = 0; i < NUM_SDMA_INSTRUCTIONS; i++) begin
            if (saif.sdma_instrs_in[i].use_rs1 && next_scalar_port < SCALAR_READ_PORTS) begin
                saif.scalar_REN[next_scalar_port]     = 1'b1;
                saif.scalar_rsel[next_scalar_port]    = saif.sdma_instrs_in[i].rs1_rd;
                scalar_port_instr[next_scalar_port]   = SCALAR_INSTR_IDX'(i);
                scalar_port_src[next_scalar_port]     = 3'd3; // sdma rs1_rd
                scalar_port_valid[next_scalar_port]   = 1'b1;
                scalar_port_is_sdma[next_scalar_port] = 1'b1;
                next_scalar_port++;
            end
            if (saif.sdma_instrs_in[i].use_rs2 && next_scalar_port < SCALAR_READ_PORTS) begin
                saif.scalar_REN[next_scalar_port]     = 1'b1;
                saif.scalar_rsel[next_scalar_port]    = saif.sdma_instrs_in[i].rs2;
                scalar_port_instr[next_scalar_port]   = SCALAR_INSTR_IDX'(i);
                scalar_port_src[next_scalar_port]     = 3'd4; // sdma rs2
                scalar_port_valid[next_scalar_port]   = 1'b1;
                scalar_port_is_sdma[next_scalar_port] = 1'b1;
                next_scalar_port++;
            end
            if (saif.sdma_instrs_in[i].use_rs3 && next_scalar_port < SCALAR_READ_PORTS) begin
                saif.scalar_REN[next_scalar_port]     = 1'b1;
                saif.scalar_rsel[next_scalar_port]    = saif.sdma_instrs_in[i].rs3;
                scalar_port_instr[next_scalar_port]   = SCALAR_INSTR_IDX'(i);
                scalar_port_src[next_scalar_port]     = 3'd5; // sdma rs3
                scalar_port_valid[next_scalar_port]   = 1'b1;
                scalar_port_is_sdma[next_scalar_port] = 1'b1;
                next_scalar_port++;
            end
        end

        // ---------------------------------------------------------------
        // Allocate vector read ports: vs1, vs2
        // ---------------------------------------------------------------
        next_vector_port = 0;

        for (int i = 0; i < NUM_VECTOR_INSTRUCTIONS; i++) begin
            if (saif.vector_instrs_in[i].use_vs1 && next_vector_port < VECTOR_READ_PORTS) begin
                saif.vector_REN[next_vector_port]   = 1'b1;
                saif.vector_rsel[next_vector_port]  = saif.vector_instrs_in[i].vs1;
                vector_port_instr[next_vector_port] = VECTOR_INSTR_IDX'(i);
                vector_port_src[next_vector_port]   = 1'b0; // vs1
                vector_port_valid[next_vector_port] = 1'b1;
                next_vector_port++;
            end
            if (saif.vector_instrs_in[i].use_vs2 && next_vector_port < VECTOR_READ_PORTS) begin
                saif.vector_REN[next_vector_port]   = 1'b1;
                saif.vector_rsel[next_vector_port]  = saif.vector_instrs_in[i].vs2;
                vector_port_instr[next_vector_port] = VECTOR_INSTR_IDX'(i);
                vector_port_src[next_vector_port]   = 1'b1; // vs2
                vector_port_valid[next_vector_port] = 1'b1;
                next_vector_port++;
            end
        end

        // ---------------------------------------------------------------
        // Allocate mask read ports: vms
        // ---------------------------------------------------------------
        next_mask_port = 0;

        for (int i = 0; i < NUM_VECTOR_INSTRUCTIONS; i++) begin
            if (saif.vector_instrs_in[i].use_vms && next_mask_port < MASK_READ_PORTS) begin
                saif.mask_REN[next_mask_port]   = 1'b1;
                saif.mask_rsel[next_mask_port]  = saif.vector_instrs_in[i].vms;
                mask_port_instr[next_mask_port] = VECTOR_INSTR_IDX'(i);
                mask_port_valid[next_mask_port] = 1'b1;
                next_mask_port++;
            end
        end

        // ---------------------------------------------------------------
        // Route rdata back into the correct instruction's data fields
        // ---------------------------------------------------------------

        // Scalar read ports
        for (int p = 0; p < SCALAR_READ_PORTS; p++) begin
            if (scalar_port_valid[p]) begin
                if (scalar_port_is_vec[p]) begin
                    if      (scalar_port_src[p] == 3'd2) saif.vector_instrs_out[scalar_port_instr[p]].rs1_data = saif.scalar_rdata[p];
                    else if (scalar_port_src[p] == 3'd6) saif.vector_instrs_out[scalar_port_instr[p]].rs2_data = saif.scalar_rdata[p];
                end else if (scalar_port_is_sdma[p]) begin
                    if      (scalar_port_src[p] == 3'd3) saif.sdma_instrs_out[scalar_port_instr[p]].rs1_rd_data = saif.scalar_rdata[p];
                    else if (scalar_port_src[p] == 3'd4) saif.sdma_instrs_out[scalar_port_instr[p]].rs2_data    = saif.scalar_rdata[p];
                    else                                 saif.sdma_instrs_out[scalar_port_instr[p]].rs3_data    = saif.scalar_rdata[p]; //=3'd5 (rs3)
                end else begin
                    if (scalar_port_src[p] == 3'd0) saif.scalar_instrs_out[scalar_port_instr[p]].r1_data = saif.scalar_rdata[p];  //r1
                    else                            saif.scalar_instrs_out[scalar_port_instr[p]].r2_data = saif.scalar_rdata[p]; //r2
                end
            end
        end

        // Vector read ports
        for (int p = 0; p < VECTOR_READ_PORTS; p++) begin
            if (vector_port_valid[p]) begin
                if (vector_port_src[p] == 1'b0)
                    saif.vector_instrs_out[vector_port_instr[p]].vs1_data = saif.vector_rdata[p];
                else
                    saif.vector_instrs_out[vector_port_instr[p]].vs2_data = saif.vector_rdata[p];
            end
        end

        // Mask read ports
        for (int p = 0; p < MASK_READ_PORTS; p++) begin
            if (mask_port_valid[p])
                saif.vector_instrs_out[mask_port_instr[p]].vms_data = saif.mask_rdata[p];
        end

    end

endmodule