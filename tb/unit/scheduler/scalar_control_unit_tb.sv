//Navya Datla 2/12/2026
`timescale 1ns / 10ps
`include "scalar_control_unit_if.vh"

module scalar_control_unit_tb;
    import atalla_isa_pkg::*;

    parameter PERIOD = 2;
    parameter NUM_INSTRUCTIONS = 4;
    logic CLK = 0;

    always #(PERIOD/2) CLK++;

    scalar_control_unit_if cuif ();
    scalar_control_unit DUT (.clk(CLK), .cuif(cuif));

    int casenum;
    string casename;
    integer i, j;

    typedef struct {
        scalar_fu_type_t exp_fu_type;
        logic exp_halt;
        control_op_t exp_CONTROLOP;
        logic exp_mem_read;
        logic exp_mem_write;
        logic exp_half_word;
        alu_op_t exp_ALUOP;
        logic exp_alu_src;
        logic exp_reg_write;
        word_t exp_imm;
    } decoded_expected_t;

    typedef struct {
        instr_t instructions [NUM_INSTRUCTIONS];
        decoded_expected_t expected [NUM_INSTRUCTIONS];
    } testVec_struct;

    testVec_struct testVec [100];

    task set_tv;
        input instr_t tv_instr0, tv_instr1, tv_instr2, tv_instr3;
        input decoded_expected_t tv_exp0, tv_exp1, tv_exp2, tv_exp3;
        input integer idx;
    begin
        testVec[idx].instructions[0] = tv_instr0;
        testVec[idx].instructions[1] = tv_instr1;
        testVec[idx].instructions[2] = tv_instr2;
        testVec[idx].instructions[3] = tv_instr3;
        testVec[idx].expected[0] = tv_exp0;
        testVec[idx].expected[1] = tv_exp1;
        testVec[idx].expected[2] = tv_exp2;
        testVec[idx].expected[3] = tv_exp3;
    end
    endtask

    initial begin
        casenum = '0;
        casename = "RESET";
        
        // Initialize all instruction slots to NOP
        for (i = 0; i < NUM_INSTRUCTIONS; i++) begin
            cuif.scalar_instrs[i] = '0;
        end
        
        #(PERIOD);

        // Slot 0: ADD_S, Slot 1: SUB_S, Slot 2: MUL_S, Slot 3: DIV_S
        set_tv(
            .tv_instr0(48'h000001008181), // ADD_S rd=3, rs1=1, rs2=2
            .tv_instr1(48'h000000810202), // SUB_S rd=4, rs1=2, rs2=1
            .tv_instr2(48'h000001008283), // MUL_S rd=5, rs1=1, rs2=2
            .tv_instr3(48'h000000810304), // DIV_S rd=6, rs1=2, rs2=1
            .tv_exp0('{FU_INT_ALU, 1'b0, CTRL_NOP, 1'b0, 1'b0, 1'b0, ALU_ADD, 1'b0, 1'b1, 32'h0}),
            .tv_exp1('{FU_INT_ALU, 1'b0, CTRL_NOP, 1'b0, 1'b0, 1'b0, ALU_SUB, 1'b0, 1'b1, 32'h0}),
            .tv_exp2('{FU_INT_MULT, 1'b0, CTRL_NOP, 1'b0, 1'b0, 1'b0, ALU_MUL, 1'b0, 1'b1, 32'h0}),
            .tv_exp3('{FU_INT_DIVMOD, 1'b0, CTRL_NOP, 1'b0, 1'b0, 1'b0, ALU_DIV, 1'b0, 1'b1, 32'h0}),
            .idx(0)
        );

        // Test 1:MOD, OR, AND, XOR
        set_tv(
            .tv_instr0(48'h000001008385), // MOD_S rd=7, rs1=1, rs2=2
            .tv_instr1(48'h000001008406), // OR_S rd=8, rs1=1, rs2=2
            .tv_instr2(48'h000001008487), // AND_S rd=9, rs1=1, rs2=2
            .tv_instr3(48'h000001008508), // XOR_S rd=10, rs1=1, rs2=2
            .tv_exp0('{FU_INT_DIVMOD, 1'b0, CTRL_NOP, 1'b0, 1'b0, 1'b0, ALU_MOD, 1'b0, 1'b1, 32'h0}),
            .tv_exp1('{FU_INT_ALU, 1'b0, CTRL_NOP, 1'b0, 1'b0, 1'b0, ALU_OR, 1'b0, 1'b1, 32'h0}),
            .tv_exp2('{FU_INT_ALU, 1'b0, CTRL_NOP, 1'b0, 1'b0, 1'b0, ALU_AND, 1'b0, 1'b1, 32'h0}),
            .tv_exp3('{FU_INT_ALU, 1'b0, CTRL_NOP, 1'b0, 1'b0, 1'b0, ALU_XOR, 1'b0, 1'b1, 32'h0}),
            .idx(1)
        );

        // Test 2: SLL, SRL, SRA and SLT
        set_tv(
            .tv_instr0(48'h000000810589), // SLL_S rd=11, rs1=2, rs2=1
            .tv_instr1(48'h00000100860a), // SRL_S rd=12, rs1=1, rs2=2
            .tv_instr2(48'h00000100868b), // SRA_S rd=13, rs1=1, rs2=2
            .tv_instr3(48'h00000100870c), // SLT_S rd=14, rs1=1, rs2=2
            .tv_exp0('{FU_INT_ALU, 1'b0, CTRL_NOP, 1'b0, 1'b0, 1'b0, ALU_SLL, 1'b0, 1'b1, 32'h0}),
            .tv_exp1('{FU_INT_ALU, 1'b0, CTRL_NOP, 1'b0, 1'b0, 1'b0, ALU_SRL, 1'b0, 1'b1, 32'h0}),
            .tv_exp2('{FU_INT_ALU, 1'b0, CTRL_NOP, 1'b0, 1'b0, 1'b0, ALU_SRA, 1'b0, 1'b1, 32'h0}),
            .tv_exp3('{FU_INT_ALU, 1'b0, CTRL_NOP, 1'b0, 1'b0, 1'b0, ALU_SLT, 1'b0, 1'b1, 32'h0}),
            .idx(2)
        );

        //Test 3: SLTU, LW, SW, HALT
        set_tv(
            .tv_instr0(48'h00000081078d), // SLTU_S rd=15, rs1=2, rs2=1
            .tv_instr1(48'h00000000002F), // NOP
            .tv_instr2(48'h00000000002F), // NOP
            .tv_instr3(48'h00000000002F), // NOP
            .tv_exp0('{FU_INT_ALU, 1'b0, CTRL_NOP, 1'b0, 1'b0, 1'b0, ALU_SLTU, 1'b0, 1'b1, 32'h0}),
            .tv_exp1('{FU_NONE, 1'b0, CTRL_NOP, 1'b0, 1'b0, 1'b0, ALU_NOP, 1'b0, 1'b0, 32'h0}),
            .tv_exp2('{FU_NONE, 1'b0, CTRL_NOP, 1'b0, 1'b0, 1'b0, ALU_NOP, 1'b0, 1'b0, 32'h0}),
            .tv_exp3('{FU_NONE, 1'b0, CTRL_NOP, 1'b0, 1'b0, 1'b0, ALU_NOP, 1'b0, 1'b0, 32'h0}),
            .idx(3)
        );

        // Run test cases
        for (i = 0; i < 4; i++) begin
            casename = $sformatf("Test Case %0d", i);
            casenum = i;
            
            // Load all 4 instructions into packet
            for (j = 0; j < NUM_INSTRUCTIONS; j++) begin
                cuif.scalar_instrs[j] = testVec[i].instructions[j];
            end
            
            #(PERIOD);
            
            $display("=== %s ===", casename);
            
            // Check decoded output for all 4 slots
            for (j = 0; j < NUM_INSTRUCTIONS; j++) begin
                // $display("--- Slot %0d ---", j);
                // $display("Instruction: 0x%h", testVec[i].instructions[j]);
                // $display("Expected FU: %s, Got: %s", 
                //     testVec[i].expected[j].exp_fu_type.name(), 
                //     cuif.decoded_scalar_instrs[j].fu_type.name());
                // $display("Expected ALUOP: %s, Got: %s", 
                //     testVec[i].expected[j].exp_ALUOP.name(), 
                //     cuif.decoded_scalar_instrs[j].ALUOP.name());
                // $display("Expected reg_write: %b, Got: %b", 
                //     testVec[i].expected[j].exp_reg_write, 
                //     cuif.decoded_scalar_instrs[j].reg_write);
                
                // Assertions
                assert(cuif.decoded_scalar_instrs[j].fu_type == testVec[i].expected[j].exp_fu_type) 
                    else $error("Slot %0d: FU_TYPE mismatch!", j);
                assert(cuif.decoded_scalar_instrs[j].halt == testVec[i].expected[j].exp_halt) 
                    else $error("Slot %0d: HALT mismatch!", j);
                assert(cuif.decoded_scalar_instrs[j].CONTROLOP == testVec[i].expected[j].exp_CONTROLOP) 
                    else $error("Slot %0d: CONTROLOP mismatch!", j);
                assert(cuif.decoded_scalar_instrs[j].mem_read == testVec[i].expected[j].exp_mem_read) 
                    else $error("Slot %0d: MEM_READ mismatch!", j);
                assert(cuif.decoded_scalar_instrs[j].mem_write == testVec[i].expected[j].exp_mem_write) 
                    else $error("Slot %0d: MEM_WRITE mismatch!", j);
                assert(cuif.decoded_scalar_instrs[j].half_word == testVec[i].expected[j].exp_half_word) 
                    else $error("Slot %0d: HALF_WORD mismatch!", j);
                assert(cuif.decoded_scalar_instrs[j].ALUOP == testVec[i].expected[j].exp_ALUOP) 
                    else $error("Slot %0d: ALUOP mismatch!", j);
                assert(cuif.decoded_scalar_instrs[j].alu_src == testVec[i].expected[j].exp_alu_src) 
                    else $error("Slot %0d: ALU_SRC mismatch!", j);
                assert(cuif.decoded_scalar_instrs[j].reg_write == testVec[i].expected[j].exp_reg_write) 
                    else $error("Slot %0d: REG_WRITE mismatch!", j);
                assert(cuif.decoded_scalar_instrs[j].imm == testVec[i].expected[j].exp_imm) 
                    else $error("Slot %0d: IMM mismatch!", j);
            end
            
            $display("");
        end

        $display("All tests completed!");
        $finish;
    end

endmodule