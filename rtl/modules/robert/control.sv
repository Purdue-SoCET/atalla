`include "control_if.sv"

module control (
    input  logic       CLK,
    input  logic       nRST,
    control_if.dut     ctrl_if
);

    // -----------------------------
    // Opcodes (from your table)
    // -----------------------------
    localparam logic [6:0] OP_BEQ  = 7'b0100011; // beq.s
    localparam logic [6:0] OP_BNE  = 7'b0100100; // bne.s
    localparam logic [6:0] OP_BLT  = 7'b0100101; // blt.s (signed)
    localparam logic [6:0] OP_BGE  = 7'b0100110; // bge.s (signed)
    localparam logic [6:0] OP_BGT  = 7'b0100111; // bgt.s (signed)
    localparam logic [6:0] OP_BLE  = 7'b0101000; // ble.s (signed)

    localparam logic [6:0] OP_JAL  = 7'b0101011; // jal
    localparam logic [6:0] OP_JALR = 7'b0101100; // jalr

    // -----------------------------
    // Combinational results
    // -----------------------------
    logic        taken_comb;
    logic [31:0] redirect_target_comb;
    logic        redirect_valid_comb;

    logic        rd_write_en_comb;
    logic [31:0] rd_value_comb;
    logic [7:0]  rd_idx_out_comb;

    // Convenience
    logic [31:0] pc_plus4;
    assign pc_plus4 = ctrl_if.pc + 32'd4;

    // -----------------------------
    // Branch condition evaluation
    // -----------------------------
    always_comb begin
        taken_comb = 1'b0;

        unique case (ctrl_if.ctrl_opcode)
            OP_BEQ: taken_comb = (ctrl_if.rs1_value == ctrl_if.rs2_value);
            OP_BNE: taken_comb = (ctrl_if.rs1_value != ctrl_if.rs2_value);

            // Treat these as signed compares (matches typical ISA intent)
            OP_BLT: taken_comb = ($signed(ctrl_if.rs1_value) <  $signed(ctrl_if.rs2_value));
            OP_BGE: taken_comb = ($signed(ctrl_if.rs1_value) >= $signed(ctrl_if.rs2_value));
            OP_BGT: taken_comb = ($signed(ctrl_if.rs1_value) >  $signed(ctrl_if.rs2_value));
            OP_BLE: taken_comb = ($signed(ctrl_if.rs1_value) <= $signed(ctrl_if.rs2_value));

            default: taken_comb = 1'b0;
        endcase
    end

    // -----------------------------
    // Redirect + Writeback generation
    // -----------------------------
    always_comb begin
        // defaults
        redirect_valid_comb  = 1'b0;
        redirect_target_comb = 32'd0;

        rd_write_en_comb = 1'b0;
        rd_value_comb    = 32'd0;
        rd_idx_out_comb      = ctrl_if.rd_idx_in; // default to passthrough (for non-branch/jump instructions)

        unique case (ctrl_if.ctrl_opcode)

            // -------------------------
            // Jumps
            // -------------------------
            OP_JAL: begin
                rd_write_en_comb     = 1'b1;
                rd_idx_out_comb      = ctrl_if.rd_idx_in; 
                rd_value_comb        = pc_plus4;
                redirect_target_comb = ctrl_if.pc + ctrl_if.imm;
                if(ctrl_if.predict_pc && ctrl_if.predict_taken && redirect_target_comb == ctrl_if.predict_pc) begin
                    // Perfectly predicted jump - no redirect needed
                    redirect_valid_comb = 1'b0;
                end else begin
                    redirect_valid_comb  = 1'b1;
                end
            end

            OP_JALR: begin
                rd_write_en_comb     = 1'b1;
                rd_idx_out_comb      = ctrl_if.rd_idx_in; 
                rd_value_comb        = pc_plus4;
                redirect_valid_comb  = 1'b1;
                redirect_target_comb = ctrl_if.rs1_value + ctrl_if.imm;
                if(ctrl_if.predict_pc && ctrl_if.predict_taken && redirect_target_comb == ctrl_if.predict_pc) begin
                    // Perfectly predicted jump - no redirect needed
                    redirect_valid_comb = 1'b0;
                end else begin
                    redirect_valid_comb  = 1'b1;
                end
            end

            // -------------------------
            // Branches (redirect only if taken)
            // -------------------------
            OP_BEQ, OP_BNE, OP_BLT, OP_BGE, OP_BGT, OP_BLE: begin
                rd_write_en_comb     = 1'b1;
                rd_value_comb        = ctrl_if.rs1_value + ctrl_if.incr7;
                rd_idx_out_comb      = ctrl_if.rs1_idx; 
                redirect_target_comb = ctrl_if.pc + ctrl_if.imm;
            
                if (taken_comb) begin
                    redirect_target_comb = ctrl_if.pc + ctrl_if.imm;
                end else begin
                    redirect_target_comb = pc_plus4;
                end

                if (ctrl_if.predict_taken != taken_comb) begin
                    redirect_valid_comb = 1'b1;
                end else if (ctrl_if.predict_taken && (ctrl_if.predict_pc != redirect_target_comb)) begin
                    redirect_valid_comb = 1'b1;
                end else begin
                    redirect_valid_comb = 1'b0;
                end
            end

            default: begin
                // nothing
            end
        endcase
    end


    assign ctrl_if.valid_out = ctrl_if.valid_in;
    assign ctrl_if.ready_out = ctrl_if.ready_in;

    // -----------------------------
    // Drive outputs
    // -----------------------------
    assign ctrl_if.rd_idx_out      = rd_idx_out_comb;
    assign ctrl_if.rd_write_en     = rd_write_en_comb;
    assign ctrl_if.rd_value        = rd_value_comb;

    assign ctrl_if.redirect_valid  = redirect_valid_comb;
    assign ctrl_if.redirect_target = redirect_target_comb;

endmodule
