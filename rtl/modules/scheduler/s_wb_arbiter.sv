// Scalar Writeback Arbiter Module ============================================
// Author: Michael Lee
// Email: lee4279@purdue.edu
// Arbitrates scalar writeback to remove bank conflicts and prioritize writebacks
// 
// TODO 
// fix handshake timing
// HOW TO parameterize
// ============================================================================
`include "s_wb_arbiter_if.vh"
`include "scalar_wb_pkg.vh"

module s_wb_arbiter (
    s_wb_arbiter_if.s_wb_arbiter vif
); 
    import vector_pkg::*;

    logic [3:0] banks;

    always_comb begin
        if vif.scalar_wb_in.valid[0] begin
            case (vif.scalar_wb_in.rd[0][7:6])
                2'b00: banks[0] = 1;
                    vif.scalar_wb_out.data[0] = vif.scalar_wb_in.data[0];
                    vif.scalar_wb_out.rd[0] = vif.scalar_wb_in.rd[0];
                    vif.scalar_wb_out.WEN[0] = 1;
                2'b01: banks[1] = 1;
                    vif.scalar_wb_out.data[1] = vif.scalar_wb_in.data[0];
                    vif.scalar_wb_out.rd[1] = vif.scalar_wb_in.rd[0];
                    vif.scalar_wb_out.WEN[1] = 1;
                2'b10: banks[2] = 1;
                    vif.scalar_wb_out.data[2] = vif.scalar_wb_in.data[0];
                    vif.scalar_wb_out.rd[2] = vif.scalar_wb_in.rd[0];
                    vif.scalar_wb_out.WEN[2] = 1;
                2'b11: banks[3] = 1;
                    vif.scalar_wb_out.data[3] = vif.scalar_wb_in.data[0];
                    vif.scalar_wb_out.rd[3] = vif.scalar_wb_in.rd[0];
                    vif.scalar_wb_out.WEN[3] = 1;
                default:
            endcase
        end
        if vif.scalar_wb_in.valid[1] begin
            case (vif.scalar_wb_in.rd[1][7:6])
                2'b00: 
                    if ~banks[0] begin 
                        banks[0] = 1;
                        vif.scalar_wb_out.data[0] = vif.scalar_wb_in.data[1];
                        vif.scalar_wb_out.rd[0] = vif.scalar_wb_in.rd[1];
                        vif.scalar_wb_out.WEN[0] = 1;
                    end
                2'b01: 
                    if ~banks[1] begin 
                        banks[1] = 1;
                        vif.scalar_wb_out.data[1] = vif.scalar_wb_in.data[1];
                        vif.scalar_wb_out.rd[1] = vif.scalar_wb_in.rd[1];
                        vif.scalar_wb_out.WEN[1] = 1;
                    end
                2'b10: 
                    if ~banks[2] begin 
                        banks[2] = 1;
                        vif.scalar_wb_out.data[2] = vif.scalar_wb_in.data[1];
                        vif.scalar_wb_out.rd[2] = vif.scalar_wb_in.rd[1];
                        vif.scalar_wb_out.WEN[2] = 1;
                    end
                2'b11: 
                    if ~banks[3] begin 
                        banks[3] = 1;
                        vif.scalar_wb_out.data[3] = vif.scalar_wb_in.data[1];
                        vif.scalar_wb_out.rd[3] = vif.scalar_wb_in.rd[1];
                        vif.scalar_wb_out.WEN[3] = 1;
                    end
                default: 
            endcase
        end
        if vif.scalar_wb_in.valid[2] begin
            case (vif.scalar_wb_in.rd[2][7:6])
                2'b00: 
                    if ~banks[0] begin 
                        banks[0] = 1;
                        vif.scalar_wb_out.data[0] = vif.scalar_wb_in.data[2];
                        vif.scalar_wb_out.rd[0] = vif.scalar_wb_in.rd[2];
                        vif.scalar_wb_out.WEN[0] = 1;
                    end
                2'b01: 
                    if ~banks[1] begin 
                        banks[1] = 1;
                        vif.scalar_wb_out.data[1] = vif.scalar_wb_in.data[2];
                        vif.scalar_wb_out.rd[1] = vif.scalar_wb_in.rd[2];
                        vif.scalar_wb_out.WEN[1] = 1;
                    end
                2'b10: 
                    if ~banks[2] begin 
                        banks[2] = 1;
                        vif.scalar_wb_out.data[2] = vif.scalar_wb_in.data[2];
                        vif.scalar_wb_out.rd[2] = vif.scalar_wb_in.rd[2];
                        vif.scalar_wb_out.WEN[2] = 1;
                    end
                2'b11: 
                    if ~banks[3] begin 
                        banks[3] = 1;
                        vif.scalar_wb_out.data[3] = vif.scalar_wb_in.data[2];
                        vif.scalar_wb_out.rd[3] = vif.scalar_wb_in.rd[2];
                        vif.scalar_wb_out.WEN[3] = 1;
                    end
                default: 
            endcase
        end
        if vif.scalar_wb_in.valid[3] begin
            case (vif.scalar_wb_in.rd[3][7:6])
                2'b00: 
                    if ~banks[0] begin 
                        banks[0] = 1;
                        vif.scalar_wb_out.data[0] = vif.scalar_wb_in.data[3];
                        vif.scalar_wb_out.rd[0] = vif.scalar_wb_in.rd[3];
                        vif.scalar_wb_out.WEN[0] = 1;
                    end
                2'b01: 
                    if ~banks[1] begin 
                        banks[1] = 1;
                        vif.scalar_wb_out.data[1] = vif.scalar_wb_in.data[3];
                        vif.scalar_wb_out.rd[1] = vif.scalar_wb_in.rd[3];
                        vif.scalar_wb_out.WEN[1] = 1;
                    end
                2'b10: 
                    if ~banks[2] begin 
                        banks[2] = 1;
                        vif.scalar_wb_out.data[2] = vif.scalar_wb_in.data[3];
                        vif.scalar_wb_out.rd[2] = vif.scalar_wb_in.rd[3];
                        vif.scalar_wb_out.WEN[2] = 1;
                    end
                2'b11: 
                    if ~banks[3] begin 
                        banks[3] = 1;
                        vif.scalar_wb_out.data[3] = vif.scalar_wb_in.data[3];
                        vif.scalar_wb_out.rd[3] = vif.scalar_wb_in.rd[3];
                        vif.scalar_wb_out.WEN[3] = 1;
                    end
                default: 
            endcase
        end
        if vif.scalar_wb_in.valid[4] begin
            case (vif.scalar_wb_in.rd[4][7:6])
                2'b00: 
                    if ~banks[0] begin 
                        banks[0] = 1;
                        vif.scalar_wb_out.data[0] = vif.scalar_wb_in.data[4];
                        vif.scalar_wb_out.rd[0] = vif.scalar_wb_in.rd[4];
                        vif.scalar_wb_out.WEN[0] = 1;
                    end
                2'b01: 
                    if ~banks[1] begin 
                        banks[1] = 1;
                        vif.scalar_wb_out.data[1] = vif.scalar_wb_in.data[4];
                        vif.scalar_wb_out.rd[1] = vif.scalar_wb_in.rd[4];
                        vif.scalar_wb_out.WEN[1] = 1;
                    end
                2'b10: 
                    if ~banks[2] begin 
                        banks[2] = 1;
                        vif.scalar_wb_out.data[2] = vif.scalar_wb_in.data[4];
                        vif.scalar_wb_out.rd[2] = vif.scalar_wb_in.rd[4];
                        vif.scalar_wb_out.WEN[2] = 1;
                    end
                2'b11: 
                    if ~banks[3] begin 
                        banks[3] = 1;
                        vif.scalar_wb_out.data[3] = vif.scalar_wb_in.data[4];
                        vif.scalar_wb_out.rd[3] = vif.scalar_wb_in.rd[4];
                        vif.scalar_wb_out.WEN[3] = 1;
                    end
                default: 
            endcase
        end
    end

endmodule

