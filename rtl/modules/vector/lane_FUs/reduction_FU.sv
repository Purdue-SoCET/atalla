`include "vreduction_if.vh"
`include "functional_unit_if.vh"
`include "vector_pkg.vh"

module reduction_FU (
    input logic CLK,
    input logic nRST,
    reduction_FU_if.ruif ruif
);
    import vector_pkg::*;
    logic broadcast, broadcast_n, clear, clear_n;
    alu_op_t rtype, rtype_n;
    logic [4:0] imm, imm_n;
    logic [VIDX_W-1:0] vd, vd_n;
    vreg_t inital_vec, inital_vec_n;
    logic busy, busy_n;
    
    //module instanciation
    vreduction_if vrif();
    vreduction reduction (
        .CLK(CLK),
        .nRST(nRST),
        .vruif(vrif)
    );

    always_ff @(posedge CLK, negedge nRST) begin : metadata_registerting
        if (!nRST) begin
            broadcast <= 'b0;
            clear <= 'b0;
            rtype <= ALU_ADD;
            inital_vec <= 'b0;
            imm <= 'b0;
            vd <= 'b0;
            busy <= 1'b0;
        end
        else begin
            broadcast <= broadcast_n;
            clear <= clear_n;
            rtype <= rtype_n;
            inital_vec <= inital_vec_n;
            imm <= imm_n;
            vd <= vd_n;
            busy <= busy_n;
        end
    end

    always_comb begin : metadata_registering_comb
        inital_vec_n = inital_vec;
        clear_n = clear;
        broadcast_n = broadcast;
        rtype_n = rtype;
        imm_n = imm;
        vd_n = vd;
        busy_n = busy;
        for (int i = 0; i < LANE_ISSUE_W; i++) begin
            if (ruif.in.ports[i].input_valid & ruif.out.input_ready & ruif.in.ports[i].rm) begin //if we are ready, there is valid data, and schedular says its a reduction op, register metadata
                inital_vec_n = ruif.in.ports[i].v1;
                broadcast_n = ruif.in.ports[i].v2[6]; 
                clear_n = ruif.in.ports[i].v2[5];
                rtype_n = ruif.in.ports[i].alu_op;
                imm_n = ruif.in.ports[i].v2[4:0];
                vd_n = ruif.in.ports[i].vd;
                busy_n = 1'b1;
            end
        end
        if (ruif.out.wb_valid && ruif.in.wb_ready) begin
            busy_n = 1'b0;
        end 
    end
    
    
    always_comb begin : interface_connections
        vrif.in.vector_input = inital_vec;
        vrif.in.lane_input = ruif.in.lane_input;
        vrif.in.imm = imm;
        vrif.in.clear = clear;
        vrif.in.broadcast = broadcast;
        vrif.in.valid_in = ruif.in.lane_valid;
        vrif.in.ready_out = ruif.in.wb_ready;
        
        ruif.out.result = vrif.out.vector_output;
        ruif.out.wb_valid = vrif.out.valid_out;
        ruif.out.rm = 'b0; //unused
        ruif.out.vd = vd;
        ruif.out.input_ready = !busy;
        ruif.out.mask = 'b0; //unused
    end



endmodule