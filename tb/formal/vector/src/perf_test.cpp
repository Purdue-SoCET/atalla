#include "Vlane_wrapper.h"
#include <iostream>
#include <memory>
#include <verilated.h>

#if VM_TRACE
#include <verilated_vcd_c.h>
#endif

// Counters
struct FUCounters {
  uint64_t work = 0;
  uint64_t stall = 0;
  uint64_t starve = 0;
};

struct LaneCounters {
  FUCounters valu;
  FUCounters sqrt;
  FUCounters mul;
  FUCounters div;
};

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
    if (tfp)
      tfp->close();
#endif
    top->final();
  }

  void reset() {
    top->nRST = 0;
    top->CLK = 0;
    // Initialize inputs
    for (int i = 0; i < 14; ++i)
      top->lane_in[i] = 0;
    top->valid_in_mask = 0;

    for (int i = 0; i < 5; ++i)
      cycle();
    top->nRST = 1;
    cycle();
  }

  void cycle() {
    // Rising Edge
    top->CLK = 1;
    top->eval();
    main_time++;
#if VM_TRACE
    if (tfp)
      tfp->dump(main_time);
#endif
    sample_counters();

    // Falling Edge
    top->CLK = 0;
    top->eval();
    main_time++;
#if VM_TRACE
    if (tfp)
      tfp->dump(main_time);
#endif
  }

  void sample_counters() {
    if (!top->nRST)
      return;

    uint32_t p = top->perf;

    // Struct is packed: VALU(11:9), SQRT(8:6), MUL(5:3), DIV(2:0)
    // Each 3-bit group: [2:Work, 1:Stall, 0:Starve]
    
    auto update = [&](FUCounters &c, int offset) {
      bool work   = (p >> (offset + 2)) & 1;
      bool stall  = (p >> (offset + 1)) & 1;
      bool starve = (p >> (offset + 0)) & 1;

      if (work)   c.work++;
      if (stall)  c.stall++;
      if (starve) c.starve++;
    };

    update(counters.div, 0);
    update(counters.mul, 3);
    update(counters.sqrt, 6);
    update(counters.valu, 9);
  }

  void run(int cycles, int injection_rate, int print_interval) {
    reset();

    std::cout << "Starting Simulation for " << cycles
              << " cycles with injection rate " << injection_rate << "%..."
              << std::endl;

    for (int i = 0; i < cycles; ++i) {
      bool valid_cycle = (rand() % 100) < injection_rate;
      top->valid_in_mask = valid_cycle ? 1 : 0;

      for (int k = 0; k < 14; ++k) {
        top->lane_in[k] = rand();
      }

      cycle();
      
      if (print_interval > 0 && (i + 1) % print_interval == 0) {
          std::cout << "--- Cycle " << (i+1) << " ---" << std::endl;
          print_stats("VALU", counters.valu);
          print_stats("SQRT", counters.sqrt);
          print_stats("MUL", counters.mul);
          print_stats("DIV", counters.div);
      }
    }

    std::cout << "Lane Simulation Complete." << std::endl;
    print_stats("VALU", counters.valu);
    print_stats("SQRT", counters.sqrt);
    print_stats("MUL", counters.mul);
    print_stats("DIV", counters.div);
  }

  void print_stats(std::string_view name, const FUCounters &c) {
    std::cout << "[" << name << "]" << std::endl;
    std::cout << "  Work:       " << c.work << std::endl;
    std::cout << "  Stall:      " << c.stall << std::endl;
    std::cout << "  Starve:     " << c.starve << std::endl;
    std::cout << "--------------------------------" << std::endl;
  }
};

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);

  int cycles = 10000;
  int rate = 100;
  int interval = 1000;

  if (argc > 1) cycles = atoi(argv[1]);
  if (argc > 2) rate = atoi(argv[2]);
  if (argc > 3) interval = atoi(argv[3]);

  Testbench tb;
  tb.run(cycles, rate, interval);
  return 0;
}
