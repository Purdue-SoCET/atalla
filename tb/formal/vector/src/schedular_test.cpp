#include "schedular.hpp"
#include <iostream>
#include <cassert>

class SchedulerTestbench {
private:
    schedular* dut; // Device Under Test
    int cycle_count;
    
    void clock_tick() {
        dut->clk = 1;
        dut->tick();
        dut->clk = 0;
        dut->tick();
        cycle_count++;
    }
    
    void reset_dut() {
        std::cout << "\n=== RESET ===" << std::endl;
        dut->rst_n = 0;
        clock_tick();
        dut->rst_n = 1;
        cycle_count = 0;
    }
    
    void set_all_ready(bool ready) {
        uint8_t val = ready ? 1 : 0;
        dut->lane_alu_ready.fill(val);
        dut->lane_exp_ready.fill(val);
        dut->lane_sqrt_ready.fill(val);
        dut->lane_mul_ready.fill(val);
        dut->lane_div_ready.fill(val);
        dut->sys_ready.fill(val);
        dut->sp_ready.fill(val);
    }
    
    void print_state(const std::string& msg = "") {
        if (!msg.empty()) {
            std::cout << msg << std::endl;
        }
        std::cout << "Cycle " << cycle_count << ":" << std::endl;
        std::cout << "  lane_valid_in: [" << +dut->lane_valid_in[0] << ", " << +dut->lane_valid_in[1] << "]" << std::endl;
        std::cout << "  sys_valid_in: " << +dut->sys_valid_in << std::endl;
        std::cout << "  sp_valid_in: [" << +dut->sp_valid_in[0] << ", " << +dut->sp_valid_in[1] << "]" << std::endl;
        std::cout << "  all_issued: " << dut->all_issued << std::endl;
        std::cout << std::endl;
    }
    
public:
    SchedulerTestbench() {
        dut = new schedular();
        cycle_count = 0;
    }
    
    ~SchedulerTestbench() {
        delete dut;
    }
    
    // Test 1: Basic reset functionality
    void test_reset() {
        std::cout << "\n========================================" << std::endl;
        std::cout << "TEST 1: Reset Functionality" << std::endl;
        std::cout << "========================================" << std::endl;
        
        // Set some signals high
        dut->lane_valid_in[0] = 1;
        dut->sys_valid_in = 1;
        
        reset_dut();
        
        // Verify all signals are zero after reset
        assert(dut->lane_valid_in[0] == 0 && dut->lane_valid_in[1] == 0);
        assert(dut->sys_valid_in == 0);
        assert(dut->sp_valid_in[0] == 0 && dut->sp_valid_in[1] == 0);
        assert(dut->all_issued == false);
        
        std::cout << "✓ Reset test PASSED" << std::endl;
    }
    
    // Test 2: Issue instruction when all ready
    void test_issue_when_ready() {
        std::cout << "\n========================================" << std::endl;
        std::cout << "TEST 2: Issue Instruction When Ready" << std::endl;
        std::cout << "========================================" << std::endl;
        
        reset_dut();
        
        // Create a simple test program with proper instruction names
        // add.vv v0, v1, v2 | mul.vv v3, v4, v5 | nop.s | nop.s
        dut->parse_packet("add.vv,0,1,2,0,0|mul.vv,3,4,5,0,0|nop.s|nop.s");
        
        // Set all functional units ready
        set_all_ready(true);
        
        std::cout << "Before issue:" << std::endl;
        print_state();
        
        // Tick clock - should issue instruction
        clock_tick();
        
        print_state("After issue:");
        
        // Verify lane instructions were issued
        assert(dut->lane_valid_in[0] == 1 || dut->lane_valid_in[1] == 1);
        
        std::cout << "✓ Issue when ready test PASSED" << std::endl;
    }
    
    // Test 3: Stall when not ready
    void test_stall_when_not_ready() {
        std::cout << "\n========================================" << std::endl;
        std::cout << "TEST 3: Stall When Not Ready" << std::endl;
        std::cout << "========================================" << std::endl;
        
        reset_dut();
        
        // Load a test instruction: add.vv v0, v1, v2 | sub.vv v3, v4, v5 | nop.s | nop.s
        dut->parse_packet("add.vv,0,1,2,0,0|sub.vv,3,4,5,0,0|nop.s|nop.s");
        
        // Set one unit NOT ready
        set_all_ready(true);
        dut->lane_alu_ready[0] = 0; // One lane not ready
        
        print_state("Before stall:");
        
        // Tick clock - should stall and deassert valids
        clock_tick();
        
        print_state("After stall (cycle 1):");
        
        // Verify all valids are deasserted during stall
        assert(dut->lane_valid_in[0] == 0 && dut->lane_valid_in[1] == 0);
        assert(dut->sys_valid_in == 0);
        assert(dut->sp_valid_in[0] == 0 && dut->sp_valid_in[1] == 0);
        
        // Now make all ready
        set_all_ready(true);
        clock_tick();
        
        print_state("After ready (cycle 2):");
        
        std::cout << "✓ Stall when not ready test PASSED" << std::endl;
    }
    
    // Test 4: Multiple instructions
    void test_multiple_instructions() {
        std::cout << "\n========================================" << std::endl;
        std::cout << "TEST 4: Multiple Instructions" << std::endl;
        std::cout << "========================================" << std::endl;
        
        reset_dut();
        
        // Load multiple packets with different instruction types
        // Packet 1: add.vv, mul.vv (both lane ops)
        dut->parse_packet("add.vv,0,1,2,0,0|mul.vv,3,4,5,0,0|nop.s|nop.s");
        // Packet 2: sub.vv, div.vv (both lane ops)
        dut->parse_packet("sub.vv,6,7,8,0,0|div.vv,9,10,11,0,0|nop.s|nop.s");
        // Packet 3: expi.vi (VI type), gemm.vv (sys), vreg.ld (SP)
        dut->parse_packet("expi.vi,12,13,0,0,0|nop.s|gemm.vv,1,2,3,0,0|vreg.ld,4,100,2,2,0,0,0");
        
        std::cout << "Loaded 3 packets" << std::endl;
        dut->dump_program_queue();
        
        set_all_ready(true);
        
        // Issue all instructions
        for (int i = 0; i < 3; i++) {
            std::cout << "\n--- Issuing packet " << i << " ---" << std::endl;
            clock_tick();
            print_state();
        }
        
        // One more tick should set all_issued
        clock_tick();
        print_state("After all instructions issued:");
        
        assert(dut->all_issued == true);
        
        std::cout << "✓ Multiple instructions test PASSED" << std::endl;
    }
    
    // Test 5: Stall and resume
    void test_stall_and_resume() {
        std::cout << "\n========================================" << std::endl;
        std::cout << "TEST 5: Stall and Resume" << std::endl;
        std::cout << "========================================" << std::endl;
        
        reset_dut();
        
        // Load instructions
        dut->parse_packet("add.vv,0,1,2,0,0|sub.vv,3,4,5,0,0|nop.s|nop.s");
        dut->parse_packet("mul.vv,6,7,8,0,0|nop.s|nop.s|nop.s");
        
        set_all_ready(true);
        
        // Issue first instruction
        std::cout << "Issuing first packet..." << std::endl;
        clock_tick();
        print_state();
        
        // Stall for a few cycles
        set_all_ready(false);
        std::cout << "Stalling for 3 cycles..." << std::endl;
        for (int i = 0; i < 3; i++) {
            clock_tick();
            print_state();
            // Verify valids stay deasserted
            assert(dut->lane_valid_in[0] == 0 && dut->lane_valid_in[1] == 0);
        }
        
        // Resume
        std::cout << "Resuming..." << std::endl;
        set_all_ready(true);
        clock_tick();
        print_state();
        
        // Empty queue
        clock_tick();
        assert(dut->all_issued == true);
        
        std::cout << "✓ Stall and resume test PASSED" << std::endl;
    }
    
    // Test 6: Valid signals deasserted every cycle
    void test_valid_deassert_every_cycle() {
        std::cout << "\n========================================" << std::endl;
        std::cout << "TEST 6: Valids Deasserted Every Cycle" << std::endl;
        std::cout << "========================================" << std::endl;
        
        reset_dut();
        
        // Load one instruction: add.vv v0, v1, v2 | nop.s | nop.s | nop.s
        dut->parse_packet("add.vv,0,1,2,0,0|nop.s|nop.s|nop.s");
        
        set_all_ready(true);
        
        // Issue instruction
        clock_tick();
        print_state("After issuing:");
        
        // Next cycle should deassert valids (queue empty)
        clock_tick();
        print_state("Next cycle (queue empty):");
        
        assert(dut->lane_valid_in[0] == 0 && dut->lane_valid_in[1] == 0);
        assert(dut->sys_valid_in == 0);
        assert(dut->sp_valid_in[0] == 0 && dut->sp_valid_in[1] == 0);
        
        std::cout << "✓ Valid deassert every cycle test PASSED" << std::endl;
    }
    
    // Test 7: Different functional units
    void test_different_functional_units() {
        std::cout << "\n========================================" << std::endl;
        std::cout << "TEST 7: Different Functional Units" << std::endl;
        std::cout << "========================================" << std::endl;
        
        reset_dut();
        
        // Test ALU operations (add, sub)
        dut->parse_packet("add.vv,0,1,2,0,0|sub.vv,3,4,5,0,0|nop.s|nop.s");
        
        // Test multiplier
        dut->parse_packet("mul.vv,6,7,8,0,0|nop.s|nop.s|nop.s");
        
        // Test divider
        dut->parse_packet("div.vv,9,10,11,0,0|nop.s|nop.s|nop.s");
        
        // Test exp and sqrt
        dut->parse_packet("expi.vi,12,13,5,0,0|sqrti.vi,14,15,3,0,0|nop.s|nop.s");
        
        // Test reduction operations
        dut->parse_packet("rsum.vi,16,17,0,0,0|rmin.vi,18,19,0,0,0|nop.s|nop.s");
        
        set_all_ready(true);
        
        // Issue all packets and verify different FU signals are set
        for (int i = 0; i < 5; i++) {
            std::cout << "\n--- Packet " << i << " ---" << std::endl;
            clock_tick();
            print_state();
            
            // Print FU selection for debugging
            std::cout << "  fu_sel: [" << +dut->fu_sel[0] << ", " << +dut->fu_sel[1] << "]" << std::endl;
            std::cout << "  alu_op: [" << +dut->alu_op[0] << ", " << +dut->alu_op[1] << "]" << std::endl;
        }
        
        clock_tick();
        assert(dut->all_issued == true);
        
        std::cout << "✓ Different functional units test PASSED" << std::endl;
    }
    
    // Test 8: System and scratchpad operations
    void test_sys_and_sp_ops() {
        std::cout << "\n========================================" << std::endl;
        std::cout << "TEST 8: System and Scratchpad Operations" << std::endl;
        std::cout << "========================================" << std::endl;
        
        reset_dut();
        
        // Test GEMM operation (sys unit)
        dut->parse_packet("nop.s|nop.s|gemm.vv,1,2,3,0,0|nop.s");
        
        // Test load weight operation (sys unit)
        dut->parse_packet("nop.s|nop.s|lw.vi,0,4,0,0,0|nop.s");
        
        // Test scratchpad load
        dut->parse_packet("nop.s|nop.s|vreg.ld,5,100,4,4,1,0,0|nop.s");
        
        // Test scratchpad store
        dut->parse_packet("nop.s|nop.s|vreg.st,6,200,4,4,1,0,0|nop.s");
        
        // Test dual scratchpad ops
        dut->parse_packet("nop.s|nop.s|vreg.ld,7,300,2,2,0,0,0|vreg.st,8,400,2,2,0,0,0");
        
        set_all_ready(true);
        
        for (int i = 0; i < 5; i++) {
            std::cout << "\n--- Packet " << i << " ---" << std::endl;
            clock_tick();
            print_state();
            
            // Print sys and sp signals
            std::cout << "  sys_ren: [" << +dut->sys_ren[0] << ", " << +dut->sys_ren[1] << "]" << std::endl;
            std::cout << "  sys_weight: " << +dut->sys_weight << std::endl;
        }
        
        clock_tick();
        assert(dut->all_issued == true);
        
        std::cout << "✓ System and scratchpad operations test PASSED" << std::endl;
    }
    
    void run_all_tests() {
        std::cout << "\n" << std::endl;
        std::cout << "╔════════════════════════════════════════╗" << std::endl;
        std::cout << "║   SCHEDULER TESTBENCH - RUNNING TESTS  ║" << std::endl;
        std::cout << "╚════════════════════════════════════════╝" << std::endl;
        
        test_reset();
        test_issue_when_ready();
        test_stall_when_not_ready();
        test_multiple_instructions();
        test_stall_and_resume();
        test_valid_deassert_every_cycle();
        
        std::cout << "\n" << std::endl;
        std::cout << "╔════════════════════════════════════════╗" << std::endl;
        std::cout << "║       ALL TESTS PASSED! ✓✓✓            ║" << std::endl;
        std::cout << "╚════════════════════════════════════════╝" << std::endl;
    }
};

int main() {
    SchedulerTestbench tb;
    tb.run_all_tests();
    return 0;
}