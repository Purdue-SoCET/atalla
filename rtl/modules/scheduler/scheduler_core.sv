`include "s_wb_arbiter_if.vh"
`include "scalar_wb_pkg.vh"
`include "execution_unit_if.sv"
`include "scheduler_pkg.sv"

import execution_unit_types_pkg::*;
import scalar_wb_pkg::*;
import scheduler_pkg::*;

module scheduler_core #()
(
    input logic CLK, nRST,
    input execution_unit_types_pkg::in_DEC_t slot_1, slot_2, slot_3, slot_4,
    input logic hit,
    input logic [31:0] data_load,
    output scheduler_pkg::EXEC_WB_LATCH WB_output
);

    scheduler_pkg::EXEC_WB_LATCH n_EX_WB_latch, EX_WB_latch;

    //interfaces
    s_wb_arbiter_if scalar_wb_if ();
    execution_unit_if scalar_ex_if ();

    //instantiations
    s_wb_arbiter S_WB_ARBITER(.CLK(CLK), .nRST(nRST), .vif(scalar_wb_if));
    execute_stage S_EXECUTE(.clk(CLK), .nRST(nRST), .ex_if(scalar_ex_if));

    //continuous assignment for EX/WB
    //ld/st unit
    //ex outputs
    assign scalar_wb_if.scalar_wb_in.data[0] = scalar_ex_if.ex5.data_out;
    assign scalar_wb_if.scalar_wb_in.rd[0] = scalar_ex_if.ex5.rdOut;
    assign scalar_wb_if.scalar_wb_in.valid[0] = scalar_ex_if.ex5.valid_out;
    //ex inputs
    assign scalar_ex_if.ready_WB_ex5 = scalar_wb_if.scalar_wb_out.ready[0];
    //control/alu unit
    //ex outputs
    assign scalar_wb_if.scalar_wb_in.data[1] = scalar_ex_if.ex1.data_out;
    assign scalar_wb_if.scalar_wb_in.rd[1] = scalar_ex_if.ex1.rdOut;
    assign scalar_wb_if.scalar_wb_in.valid[1] = scalar_ex_if.ex1.valid_out;
    //ex inputs
    assign scalar_ex_if.ready_WB_ex1 = scalar_wb_if.scalar_wb_out.ready[1];
    //scalar mult unit
    //ex outputs
    assign scalar_wb_if.scalar_wb_in.data[2] = scalar_ex_if.ex4.data_out;
    assign scalar_wb_if.scalar_wb_in.rd[2] = scalar_ex_if.ex4.rdOut;
    assign scalar_wb_if.scalar_wb_in.valid[2] = scalar_ex_if.ex4.valid_out;
    //ex inputs
    assign scalar_ex_if.ready_WB_ex4 = scalar_wb_if.scalar_wb_out.ready[2];
    //BF math unit unit
    //ex outputs
    assign scalar_wb_if.scalar_wb_in.data[3] = scalar_ex_if.ex3.data_out;
    assign scalar_wb_if.scalar_wb_in.rd[3] = scalar_ex_if.ex3.rdOut;
    assign scalar_wb_if.scalar_wb_in.valid[3] = scalar_ex_if.ex3.valid_out;
    //ex inputs
    assign scalar_ex_if.ready_WB_ex3 = scalar_wb_if.scalar_wb_out.ready[3];
    //Wacky unit unit
    //ex outputsdata
    assign scalar_wb_if.scalar_wb_in.data[4] = scalar_ex_if.ex2.data_out;
    assign scalar_wb_if.scalar_wb_in.rd[4] = scalar_ex_if.ex2.rdOut;
    assign scalar_wb_if.scalar_wb_in.valid[4] = scalar_ex_if.ex2.valid_out;
    //ex inputs
    assign scalar_ex_if.ready_WB_ex2 = scalar_wb_if.scalar_wb_out.ready[4];

    //continuous assignment for WB arbiter latch
    assign n_EX_WB_latch.data = scalar_wb_if.scalar_wb_out.data;
    assign n_EX_WB_latch.rd = scalar_wb_if.scalar_wb_out.rd;
    assign n_EX_WB_latch.WEN = scalar_wb_if.scalar_wb_out.WEN;

    //temporary in/outs
    assign WB_output = EX_WB_latch;
    assign scalar_ex_if.slot_1 = slot_1;
    assign scalar_ex_if.slot_2 = slot_2;
    assign scalar_ex_if.slot_3 = slot_3;
    assign scalar_ex_if.slot_4 = slot_4;
    assign scalar_ex_if.hit = hit;
    assign scalar_ex_if.data_load = data_load;

    always_ff @( posedge CLK, negedge nRST ) begin : EX_WB_LATCH
        if(!nRST) begin
            EX_WB_latch <= '0;
        end else begin
            EX_WB_latch <= n_EX_WB_latch;
        end
    end


endmodule