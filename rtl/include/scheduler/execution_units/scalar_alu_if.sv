
`ifndef SCALAR_ALU_IF_VH
`define SCALAR_ALU_IF_VH

// ready/valid interface for scalar ALU
// valid_in  ->  ||  alu  || -> valid_out
// ready_out <-  ||  alu  || <- ready_in
//
// Input transfer  when (valid_in  && ready_out)
// Output transfer when (valid_out && ready_in)

interface scalar_alu_if;

    // -----------------------------
    // Inputs 
    // -----------------------------
    logic [31:0] srcA, srcB;
    logic [31:0] imm;          // NEW: immediate value for I-type ops
    logic [6:0]  salu_op;      // scalar ALU opcode
    logic [7:0]  rdIn;


    // -----------------------------
    // Outputs 
    // -----------------------------
    logic [31:0] rdResult;
    logic [7:0]  rdOut;


    // Execution unit view
    modport dut (
        input  srcA, srcB, imm, salu_op, rdIn,
        output rdResult, rdOut
    );

    // Testbench view
    modport tb (
        output srcA, srcB, imm, salu_op, rdIn,
        input  rdResult, rdOut
    );

endinterface

`endif