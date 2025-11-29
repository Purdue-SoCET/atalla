// testbench.cpp
#include "Vsqrt_bf16_wrapper.h"      // Generated header for your module
#include "verilated.h"               // Verilator's main header
#include "verilated_vcd_c.h"         // For VCD waveform generation

int main(int argc, char** argv) {
    // Initialize Verilator
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);  // Enable tracing
    
    // Instantiate the design
    Vsqrt_bf16_wrapper* dut = new Vsqrt_bf16_wrapper;
    
    // Setup VCD tracing
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);           // Trace 99 levels of hierarchy
    tfp->open("waveform.vcd");     // Output file
    
    // Simulation time
    vluint64_t sim_time = 0;
    
    // Initialize inputs
    dut->CLK = 0;
    dut->nRST = 0;
    dut->sqrt_valid_in = 0;
    dut->sqrt_ready_out = 1;
    dut->sqrt_operand = 0;
    
    // Reset
    for (int i = 0; i < 5; i++) {
        dut->CLK = 0;
        dut->eval();
        tfp->dump(sim_time++);
        
        dut->CLK = 1;
        dut->eval();
        tfp->dump(sim_time++);
    }
    
    dut->nRST = 1;  // Release reset
    
    // Run simulation
    for (int cycle = 0; cycle < 1000; cycle++) {
        // Falling edge
        dut->CLK = 0;
        dut->eval();
        tfp->dump(sim_time++);
        
        // Rising edge
        dut->CLK = 1;
        
        // Apply stimulus (example)
        if (cycle == 10) {
            dut->sqrt_valid_in = 1;
            dut->sqrt_operand = 0x4000;  // Example BF16 value
        }
        
        dut->eval();
        tfp->dump(sim_time++);
        
        // Read outputs
        if (dut->sqrt_valid_out) {
            printf("Result: 0x%04x at cycle %d\n", dut->sqrt_result, cycle);
        }
        
        // Check for finish condition
        if (Verilated::gotFinish()) break;
    }
    
    // Cleanup
    tfp->close();
    delete tfp;
    delete dut;
    
    return 0;
}