#include "Vlane_wrapper.h"
#include <iostream>
#include <memory>
#include <verilated.h>

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

  uint64_t bubbles = 0;          // !valid_raw
  uint64_t skipped = 0;          // valid_raw && !mask_bit
  uint64_t retired = 0;          // retire signal
  uint64_t latency_acc = 0;      // accumulated in-flight count per cycle
  uint64_t raw_valid_cycles = 0; // cycles where valid_raw was high
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

  // Track in-flight instructions (simple counter: issue - retire)
  // This is an approximation. Ideally we tag instructions.
  int valu_inflight = 0;
  int sqrt_inflight = 0;
  int mul_inflight = 0;
  int div_inflight = 0;

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

  // Full clock cycle simulation
  void cycle() {
    // Rising Edge
    top->CLK = 1;
    top->eval();
    main_time++;
#if VM_TRACE
    if (tfp)
      tfp->dump(main_time);
#endif
    // Sample just after rising edge eval
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

    auto update = [&](FUCounters &c, int &inflight, int offset) {
      bool busy = (p >> (offset + 7)) & 1;
      bool issue = (p >> (offset + 6)) & 1;
      bool fire = (p >> (offset + 5)) & 1;
      bool stall_fifo = (p >> (offset + 4)) & 1;
      bool stall_wb = (p >> (offset + 3)) & 1;
      bool valid_raw = (p >> (offset + 2)) & 1;
      bool mask_bit = (p >> (offset + 1)) & 1;
      bool retire = (p >> (offset + 0)) & 1;

      if (busy)
        c.cycles_busy++;
      if (issue)
        c.cycles_issue++;
      if (fire)
        c.cycles_fire++;
      if (stall_fifo)
        c.stall_fifo++;
      if (stall_wb)
        c.stall_wb++;

      if (retire)
        c.retired++;
      if (!valid_raw)
        c.bubbles++;
      if (valid_raw)
        c.raw_valid_cycles++;
      if (valid_raw && !mask_bit)
        c.skipped++;

      // Latency tracking
      if (fire)
        inflight++;
      if (retire)
        inflight--;
      if (inflight < 0)
        inflight = 0;

      c.latency_acc += inflight;
    };

    update(counters.div, div_inflight, 0);
    update(counters.mul, mul_inflight, 8);
    update(counters.sqrt, sqrt_inflight, 16);
    update(counters.valu, valu_inflight, 24);
  }

  void run(int cycles, int injection_rate) {
    reset();

    std::cout << "Starting Simulation for " << cycles
              << " cycles with injection rate " << injection_rate << "%..."
              << std::endl;

    // Drive some traffic
    for (int i = 0; i < cycles; ++i) {
      bool valid_cycle = (rand() % 100) < injection_rate;
      top->valid_in_mask = valid_cycle ? 1 : 0;

      for (int k = 0; k < 14; ++k) {
        top->lane_in[k] = rand();
      }

      cycle();
    }

    // Drain functionality
    std::cout << "Draining pipeline..." << std::endl;
    top->valid_in_mask = 0;

    // Force ready_in to 1
    for (int k = 0; k < 14; ++k)
      top->lane_in[k] = 0xFFFFFFFF;

    bool drained = false;
    for (int i = 0; i < 1000; ++i) {
      cycle();

      if (valu_inflight == 0 && sqrt_inflight == 0 && mul_inflight == 0 &&
          div_inflight == 0) {
        std::cout << "Pipeline drained in " << i << " cycles." << std::endl;
        drained = true;
        break;
      }
    }

    if (!drained) {
      std::cout << "WARNING: Pipeline drain timed out!" << std::endl;
      std::cout << "Remaining In-flight: VALU=" << valu_inflight
                << " SQRT=" << sqrt_inflight << " MUL=" << mul_inflight
                << " DIV=" << div_inflight << std::endl;
    }

    std::cout << "Lane Simulation Complete." << std::endl;
    print_stats("VALU", counters.valu);
    print_stats("SQRT", counters.sqrt);
    print_stats("MUL", counters.mul);
    print_stats("DIV", counters.div);
  }

  void print_stats(std::string_view name, const FUCounters &c) {
    double avg_lat = (c.retired > 0) ? (double)c.latency_acc / c.retired : 0.0;

    std::cout << "[" << name << "]" << std::endl;
    std::cout << "  Busy:       " << c.cycles_busy << std::endl;
    std::cout << "  Issue:      " << c.cycles_issue << std::endl;
    std::cout << "  Fire:       " << c.cycles_fire << std::endl;
    std::cout << "   retired:    " << c.retired << std::endl;
    std::cout << "  Stall FIFO: " << c.stall_fifo << std::endl;
    std::cout << "  Stall WB:   " << c.stall_wb << std::endl;
    std::cout << "  Bubbles:    " << c.bubbles << std::endl;
    std::cout << "  Skipped:    " << c.skipped << std::endl;
    std::cout << "  Avg Latency:" << avg_lat << " cycles" << std::endl;
    std::cout << "--------------------------------" << std::endl;
  }
};

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);

  int rate = 100;
  if (argc > 1) {
    rate = atoi(argv[1]);
  }

  Testbench tb;
  tb.run(10000, rate);
  return 0;
}
