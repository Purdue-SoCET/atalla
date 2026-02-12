#include "Vgsau_wrapper.h"
#include "perf_testbench_base.h"
#include <iostream>

struct GSAUCounters {
    uint64_t issue_work = 0;
    uint64_t issue_stall = 0;
    uint64_t issue_starve = 0;

    uint64_t wb_work = 0;
    uint64_t wb_stall = 0;
    uint64_t wb_starve = 0;
};

struct Testbench : public PerfTestbenchBase<Testbench, Vgsau_wrapper> {
    GSAUCounters counters;

    Testbench() : PerfTestbenchBase{} {}

    void reset() override {
        top->nRST = 0;
        top->CLK = 0;
        top->sb_valid_in = 0;
        top->wb_ready_in = 0;
        top->sa_ready_in = 0;
        top->sa_valid_in = 0;
        
        for (int i = 0; i < 5; ++i) cycle();
        top->nRST = 1;
        cycle();
    }

    void sample_counters() override {
        if (!top->nRST) return;

        uint32_t p = top->perf;
        // Packed struct:
        // wb_starve(0), wb_stall(1), wb_work(2)
        // dispatch_starve(3), dispatch_stall(4), dispatch_work(5)
        // issue_starve(6), issue_stall(7), issue_work(8)

        bool i_work   = (p >> 8) & 1;
        bool i_stall  = (p >> 7) & 1;
        bool i_starve = (p >> 6) & 1;

        bool w_work   = (p >> 2) & 1;
        bool w_stall  = (p >> 1) & 1;
        bool w_starve = (p >> 0) & 1;

        if (i_work)   counters.issue_work++;
        if (i_stall)  counters.issue_stall++;
        if (i_starve) counters.issue_starve++;

        if (w_work)   counters.wb_work++;
        if (w_stall)  counters.wb_stall++;
        if (w_starve) counters.wb_starve++;
    }

    void run(int cycles, int sb_rate, int sa_ready_rate, int wb_ready_rate, int print_interval) {
        reset();
        
        std::cout << "Starting GSAU Simulation for " << cycles << " cycles..." << std::endl;
        std::cout << "  SB Injection Rate: " << sb_rate << "%" << std::endl;
        std::cout << "  SA Ready Rate:     " << sa_ready_rate << "%" << std::endl;
        std::cout << "  WB Ready Rate:     " << wb_ready_rate << "%" << std::endl;

        for (int i = 0; i < cycles; ++i) {
            // Randomize Inputs
            top->sb_valid_in = (rand() % 100) < sb_rate;
            top->sa_ready_in = (rand() % 100) < sa_ready_rate;
            top->wb_ready_in = (rand() % 100) < wb_ready_rate;
            
            top->sa_valid_in = (rand() % 100) < 50; 

            cycle();

            if (print_interval > 0 && (i + 1) % print_interval == 0) {
                 std::cout << "--- Cycle " << (i+1) << " ---" << std::endl;
                 print_stats();
            }
        }
        std::cout << "GSAU Simulation Complete." << std::endl;
    }

    void print_stats() {
        print_stage("ISSUE", counters.issue_work, counters.issue_stall, counters.issue_starve);
        print_stage("WB", counters.wb_work, counters.wb_stall, counters.wb_starve);
    }
    
    void print_stage(std::string_view name, uint64_t work, uint64_t stall, uint64_t starve) {
        std::cout << "[" << name << "]" << std::endl;
        std::cout << "  Work:       " << work << std::endl;
        std::cout << "  Stall:      " << stall << std::endl;
        std::cout << "  Starve:     " << starve << std::endl;
        std::cout << "--------------------------------" << std::endl;
    }
};

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    
    int cycles = 10000;
    int sb_rate = 50;
    int sa_ready = 90;
    int wb_ready = 90;
    int interval = 1000;

    if (argc > 1) cycles = atoi(argv[1]);
    if (argc > 2) sb_rate = atoi(argv[2]);
    if (argc > 3) sa_ready = atoi(argv[3]);
    if (argc > 4) wb_ready = atoi(argv[4]);
    if (argc > 5) interval = atoi(argv[5]);

    Testbench tb;
    tb.run(cycles, sb_rate, sa_ready, wb_ready, interval);
    return 0;
}
