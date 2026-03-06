`include "vreduction_if.vh"
`include "functional_unit_if.vh"
`include "vector_pkg.vh"

module reduction_FU (
    input logic CLK,
    input logic nRST,
    reduction_FU_if.ruif ruif
);
    import vector_pkg::*;
    
    // Metadata registers
    logic broadcast, broadcast_n, clear, clear_n;
    alu_op_t rtype, rtype_n;
    logic [4:0] imm, imm_n;
    logic [VIDX_W-1:0] vd, vd_n;
    vreg_t initial_vec, initial_vec_n;
    logic busy, busy_n;
    
    // Reduction unit interface
    vreduction_if vrif();
    
    vreduction #(
        .LANES(NUM_LANES)
    ) reduction (
        .CLK(CLK),
        .nRST(nRST),
        .vruif(vrif)
    );

    // Metadata registers
    always_ff @(posedge CLK, negedge nRST) begin : metadata_registering
        if (!nRST) begin
            broadcast <= 'b0;
            clear <= 'b0;
            rtype <= ALU_ADD;
            initial_vec <= 'b0;
            imm <= 'b0;
            vd <= 'b0;
            busy <= 1'b0;
        end
        else begin
            broadcast <= broadcast_n;
            clear <= clear_n;
            rtype <= rtype_n;
            initial_vec <= initial_vec_n;
            imm <= imm_n;
            vd <= vd_n;
            busy <= busy_n;
        end
    end

    // Capture metadata on input handshake
    always_comb begin : metadata_registering_comb
        initial_vec_n = initial_vec;
        clear_n = clear;
        broadcast_n = broadcast;
        rtype_n = rtype;
        imm_n = imm;
        vd_n = vd;
        busy_n = busy;
        
        // Check all input ports for valid reduction operation
        for (int i = 0; i < LANE_ISSUE_W; i++) begin
            if (ruif.in.ports[i].input_valid & ruif.out.input_ready & ruif.in.ports[i].rm) begin
                // Capture metadata from the input port
                initial_vec_n = ruif.in.ports[i].v1;
                broadcast_n = ruif.in.ports[i].v2[6]; 
                clear_n = ruif.in.ports[i].v2[5];
                rtype_n = ruif.in.ports[i].alu_op;
                imm_n = ruif.in.ports[i].v2[4:0];
                vd_n = ruif.in.ports[i].vd;
                busy_n = 1'b1;
            end
        end
        
        // Clear busy when output handshake completes
        if (ruif.out.wb_valid && ruif.in.wb_ready) begin
            busy_n = 1'b0;
        end 
    end
    
    // Connect to internal reduction unit
    always_comb begin : interface_connections
        // Inputs to reduction unit
        vrif.in.vector_input = initial_vec;
        vrif.in.lane_input = ruif.in.lane_input;
        vrif.in.imm = imm;
        vrif.in.clear = clear;
        vrif.in.broadcast = broadcast;
        vrif.in.reduction_type = rtype;
        vrif.in.valid_in = ruif.in.lane_valid;
        vrif.in.ready_out = ruif.in.wb_ready;
        
        // Outputs from reduction unit
        ruif.out.vector_output = vrif.out.vector_output;
        ruif.out.wb_valid = vrif.out.valid_out;
        ruif.out.vd_output = vd;
        ruif.out.input_ready = !busy;
    end

endmodule