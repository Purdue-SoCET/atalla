// Vector Writeback Testbench ============================================
// Author: Jaideep Dadi
// Email: djaideep@purdue.edu
// TODO 
// Check vector core stall-related inputs & modify code accordingly. Banks can be associative, no?
// ============================================================================
`timescale 1ns/1ps
//`include "v_wb_arbiter_if.vh"
//`include "vector_pkg.vh"

`include "vector_pkg.vh"
`include "vector_if.vh"
`include "gsau_control_unit_if.vh"

module tb;

  logic CLK;
  logic nRST;

  // interface instance
  vector_if vif();
  scpad_if sif();
  gsau_control_unit_if gsauif();

  // DUT
  vector_execute_wb_top dut (
      .CLK(CLK),
      .nRST(nRST),
      .vif(vif),
	.sif(sif),
	.gsauif(gsauif)
  );

initial CLK = 0;
always #5 CLK = ~CLK;

initial begin

nRST = 0;
#5;
nRST = 1;

#5;
vif.wb_ready_signals = '1;

//vector_pkg::vreg_t bf16_v1 = '{0: 16'h4120, 1: 16'h4140, 2: 16'h4160, 3: 16'h4180,
//                    4: 16'h41a0, 5: 16'h41c0, 6: 16'h41e0, 7: 16'h4200,
//                    8: 16'h4210, 9: 16'h4220, 10: 16'h4230, 11: 16'h4240,
//                    12: 16'h4250, 13: 16'h4260, 14: 16'h4270, 15: 16'h4280,
//                    16: 16'h4290, 17: 16'h42a0, 18: 16'h42b0, 19: 16'h42c0,
  //                  20: 16'h42d0, 21: 16'h42e0, 22: 16'h42f0, 23: 16'h4300,
    //                24: 16'h4308, 25: 16'h4310, 26: 16'h4318, 27: 16'h4320,
      //              28: 16'h4328, 29: 16'h4330, 30: 16'h4338, 31: 16'h4340};

//vector_pkg::vreg_t bf16_v2 = '{0: 16'h41a0, 1: 16'h41c0, 2: 16'h41e0, 3: 16'h4200,
  //                  4: 16'h4210, 5: 16'h4220, 6: 16'h4230, 7: 16'h4240,
    //                8: 16'h4250, 9: 16'h4260, 10: 16'h4270, 11: 16'h4280,
      //              12: 16'h4290, 13: 16'h42a0, 14: 16'h42b0, 15: 16'h42c0,
        //            16: 16'h42d0, 17: 16'h42e0, 18: 16'h42f0, 19: 16'h4300,
          //          20: 16'h4308, 21: 16'h4310, 22: 16'h4318, 23: 16'h4320,
            //        24: 16'h4328, 25: 16'h4330, 26: 16'h4338, 27: 16'h4340,
              //      28: 16'h4348, 29: 16'h4350, 30: 16'h4358, 31: 16'h4360};

vif.lanes_in.lane_issue_ports[0].input_valid = 1;
vif.lanes_in.lane_issue_ports[0].v1 = '1;
vif.lanes_in.lane_issue_ports[0].v2 = '0;
vif.lanes_in.lane_issue_ports[0].usel = '0; //VALU
vif.lanes_in.lane_issue_ports[0].vd = '1;
vif.lanes_in.lane_issue_ports[0].rm = 0;
vif.lanes_in.lane_issue_ports[0].mask = '1;
vif.lanes_in.lane_issue_ports[0].alu_op = '0; //BF16 Add

#150;
$stop;

end
endmodule
