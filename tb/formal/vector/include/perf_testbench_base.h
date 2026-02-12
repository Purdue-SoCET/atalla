#pragma once

#include <memory>
#include <verilated.h>
#if VM_TRACE
#include <verilated_vcd_c.h>
#endif

vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

template <class Derived, class TopModule>
class PerfTestbenchBase {
public:
    std::unique_ptr<TopModule> top;

#if VM_TRACE
    std::unique_ptr<VerilatedVcdC> tfp;
#endif

    PerfTestbenchBase(const char* trace_file = nullptr) {
        top = std::make_unique<TopModule>();

#if VM_TRACE
        Verilated::traceEverOn(true);
        if (trace_file) {
            tfp = std::make_unique<VerilatedVcdC>();
            top->trace(tfp.get(), 99);
            tfp->open(trace_file);
        }
#endif
    }

    virtual ~PerfTestbenchBase() {
#if VM_TRACE
        if (tfp) tfp->close();
#endif
        top->final();
    }

    virtual void sample_counters() = 0; 
    
    virtual void reset() = 0;

    void cycle() {
        top->CLK = 1;
        top->eval();
        main_time++;
#if VM_TRACE
        if (tfp) tfp->dump(main_time);
#endif
        sample_counters();

        top->CLK = 0;
        top->eval();
        main_time++;
#if VM_TRACE
        if (tfp) tfp->dump(main_time);
#endif
    }
};
