`include "alu_control_if.sv"
`include "scalar_alu_if.sv"
`include "control_if.sv"
`include "atalla_isa_types.vh"
import atalla_isa_pkg::*;

module alu_control #()
(
    input logic CLK, nRST,
    alu_control_if.mainport portmap
);

    typedef enum {start, latch} state;
    state n_state, cur_state;

    logic [31:0] cur_rs1_value, cur_rs2_value, rs1_value_latch, rs2_value_latch, rs1_value_nlatch, rs2_value_nlatch;
    logic [31:0] cur_imm, imm_latch, imm_nlatch;
    logic [31:0] cur_incr7, incr7_latch, incr7_nlatch;
    logic [31:0] cur_pc, pc_latch, pc_nlatch;
    logic [7:0] cur_rdIn, rdIn_latch, rdIn_nlatch;
    logic [7:0] cur_rs1_idx, rs1_idx_latch, rs1_idx_nlatch;
    logic [6:0] cur_op, op_latch, op_nlatch;
    logic cur_alu_valid, alu_valid_latch, alu_valid_nlatch;
    logic cur_control_valid, control_valid_latch, control_valid_nlatch;


    scalar_alu_if alu_if ();
    control_if cont_if ();

    control CONT (.CLK(CLK), .nRST(nRST), .ctrl_if(cont_if));
    scalar_alu ALU (.CLK(CLK), .nRST(nRST), .salu_if(alu_if));

    assign alu_if.srcA = cur_rs1_value;
    assign alu_if.srcB = cur_rs2_value;
    assign alu_if.imm = cur_imm;
    assign alu_if.rdIn = cur_rdIn;
    assign alu_if.salu_op = cur_op;

    assign cont_if.rs1_value = cur_rs1_value;
    assign cont_if.rs2_value = cur_rs2_value;
    assign cont_if.rd_idx_in = cur_rdIn;
    assign cont_if.rs1_idx = cur_rs1_idx;
    assign cont_if.imm = cur_imm;
    assign cont_if.incr7 = cur_incr7;
    assign cont_if.pc = cur_pc;
    assign cont_if.ctrl_opcode = cur_op;


    always_comb begin
        portmap.rd_value = 32'b0;
        portmap.rdOut = 8'b0;
        portmap.redirect_valid = 1'b0;
        portmap.redirect_target = 32'b0;
        if(cur_alu_valid == 1) begin
            portmap.rd_value = alu_if.rdResult;
            portmap.rdOut = alu_if.rdOut;
        end else if(cur_control_valid == 1) begin
            portmap.rd_value = cont_if.rd_value;
            portmap.rdOut = cont_if.rd_idx_out;
            portmap.redirect_valid = cont_if.redirect_valid && portmap.ready_out;
            portmap.redirect_target = cont_if.redirect_target;
        end
    end



    always_comb begin
        portmap.ready_in = 1'b1;
        portmap.valid_out = 1'b0;

        cur_rs1_value = portmap.rs1_value;
        rs1_value_nlatch = rs1_value_latch;
        cur_rs2_value = portmap.rs2_value;
        rs2_value_nlatch = rs2_value_latch;
        imm_nlatch = imm_latch;
        cur_imm = portmap.imm;
        incr7_nlatch = incr7_latch;
        cur_incr7 = portmap.incr7;
        pc_nlatch = pc_latch;
        cur_pc = portmap.pc;
        rdIn_nlatch = rdIn_latch;
        cur_rdIn = portmap.rdIn;
        rs1_idx_nlatch = rs1_idx_latch;
        cur_rs1_idx = portmap.rs1_idx;
        op_nlatch = op_latch;
        cur_op = portmap.op;
        alu_valid_nlatch = alu_valid_latch;
        cur_alu_valid = portmap.valid_in && (alu_valid == portmap.scalar_type_enable) ? 1 : 0;
        control_valid_nlatch = control_valid_latch;
        cur_control_valid = portmap.valid_in && (control_valid == portmap.scalar_type_enable) ? 1 : 0;


        case (cur_state)
            start: begin
                if(portmap.valid_in && !portmap.ready_out) begin
                    n_state = latch;
                end
                portmap.ready_in = 1'b1;
                portmap.valid_out = portmap.valid_in;

                rs1_value_nlatch = portmap.rs1_value;
                rs2_value_nlatch = portmap.rs2_value;
                imm_nlatch = portmap.imm;
                incr7_nlatch = portmap.incr7;
                pc_nlatch = portmap.pc;
                rdIn_nlatch = portmap.rdIn;
                rs1_idx_nlatch = portmap.rs1_idx;
                op_nlatch = portmap.op;
                alu_valid_nlatch = portmap.valid_in && (alu_valid == portmap.scalar_type_enable) ? 1 : 0;
                control_valid_nlatch = portmap.valid_in && (control_valid == portmap.scalar_type_enable) ? 1 : 0;

            end
            latch: begin
                if(portmap.ready_out) begin
                    n_state = start;
                end
                portmap.valid_out = 1'b1;
                portmap.ready_in = 1'b0;

                cur_rs1_value = rs1_value_latch;
                cur_rs2_value = rs2_value_latch;
                cur_imm = imm_latch;
                cur_incr7 = incr7_latch;
                cur_pc = pc_latch;
                cur_rdIn = rdIn_latch;
                cur_rs1_idx = rs1_idx_latch;
                cur_op = op_latch;
                cur_alu_valid = alu_valid_latch;
                cur_control_valid = control_valid_latch;

            end
        endcase
    end

    always_ff @(posedge CLK, negedge nRST) begin
        if(!nRST) begin
            cur_state <= start;
            rs1_value_latch <= 32'b0;
            rs2_value_latch <= 32'b0;
            imm_latch <= 32'b0;
            incr7_latch <= 32'b0;
            pc_latch <= 32'b0;
            rdIn_latch <= 8'b0;
            rs1_idx_latch <= 8'b0;
            op_latch <= 7'b0;
            alu_valid_latch <= 1'b0;
            control_valid_latch <= 1'b0;
        end
        else begin
            cur_state <= n_state;
            rs1_value_latch <= rs1_value_nlatch;
            rs2_value_latch <= rs2_value_nlatch;
            imm_latch <= imm_nlatch;
            incr7_latch <= incr7_nlatch;
            pc_latch <= pc_nlatch;
            rdIn_latch <= rdIn_nlatch;
            rs1_idx_latch <= rs1_idx_nlatch;
            op_latch <= op_nlatch;
            alu_valid_latch <= alu_valid_nlatch;
            control_valid_latch <= control_valid_nlatch;
        end
    end


endmodule