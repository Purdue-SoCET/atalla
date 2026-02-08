#include <iostream>
#include <memory>
#include <verilated.h>
#include "Vlane_wrapper.h"

#if VM_TRACE
#include <verilated_vcd_c.h>
#endif

// Counters
struct FUCounters {
    uint64_t cycles_busy = 0;
    uint64_t cycles_issue = 0;
    uint64_t cycles_fire = 0;
    uint64_t stall_fifo = 0;
    uint64_t stall_wb = 0;
};

struct LaneCounters {
    FUCounters valu;
    FUCounters sqrt;
    FUCounters mul;
    FUCounters div;
};

// Global time for legacy Verilator
vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

struct Testbench {
    std::unique_ptr<Vlane_wrapper> top;
    LaneCounters counters;
    
#if VM_TRACE
    std::unique_ptr<VerilatedVcdC> tfp;
#endif

    Testbench() {
        top = std::make_unique<Vlane_wrapper>();
        
#if VM_TRACE
        Verilated::traceEverOn(true);
        tfp = std::make_unique<VerilatedVcdC>();
        top->trace(tfp.get(), 99);
        tfp->open("lane_perf.vcd");
#endif
    }

    ~Testbench() {
#if VM_TRACE
        if (tfp) tfp->close();
#endif
        top->final();
    }

    void reset() {
        top->nRST = 0;
        top->CLK = 0;
        // Initialize inputs
        for (int i=0; i<14; ++i) top->lane_in[i] = 0; 
        
        for(int i=0; i<5; ++i) step();
        top->nRST = 1;
        step();
    }

    void step() {
        main_time++;
        top->CLK = !top->CLK;
        top->eval();
#if VM_TRACE
        if (tfp) tfp->dump(main_time);
#endif
        // Sampling on rising edge
        if (top->CLK == 1) sample_counters();
    }

    void sample_counters() {
        if (!top->nRST) return;

        uint32_t p = top->perf;

        auto update = [&](FUCounters& c, int offset) {
            if ((p >> (offset + 4)) & 1) c.cycles_busy++;
            if ((p >> (offset + 3)) & 1) c.cycles_issue++;
            if ((p >> (offset + 2)) & 1) c.cycles_fire++;
            if ((p >> (offset + 1)) & 1) c.stall_fifo++;
            if ((p >> (offset + 0)) & 1) c.stall_wb++;
        };

        update(counters.div,  0);
        update(counters.mul,  5);
        update(counters.sqrt, 10);
        update(counters.valu, 15);
    }

    void run(int cycles) {
        reset();
        
        std::cout << "Starting Simulation for " << cycles << " cycles..." << std::endl;

        // Drive some traffic
        for (int i=0; i<cycles; ++i) {
            // Randomly toggle bits in the wide input struct
            for (int k=0; k<14; ++k) {
                top->lane_in[k] = rand();
            } 
            
            step();
        }
        
        std::cout << "Lane Simulation Complete." << std::endl;
        print_stats("VALU", counters.valu);
        print_stats("SQRT", counters.sqrt);
        print_stats("MUL",  counters.mul);
        print_stats("DIV",  counters.div);
    }
    
    void print_stats(const char* name, const FUCounters& c) {
        std::cout << "[" << name << "] Busy: " << c.cycles_busy 
                  << " Issue: " << c.cycles_issue
                  << " Fire: " << c.cycles_fire
                  << " Stall FIFO: " << c.stall_fifo
                  << " Stall WB: " << c.stall_wb << std::endl;
    }
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Testbench tb;
    tb.run(1000);
    return 0;
}
