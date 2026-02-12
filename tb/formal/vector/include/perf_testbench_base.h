#pragma once

#include <memory>
#include <verilated.h>

vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

template <class Derived, class TopModule>
class PerfTestbenchBase {
public:
    std::unique_ptr<TopModule> top;

    PerfTestbenchBase() {
        top = std::make_unique<TopModule>();
    }

    virtual ~PerfTestbenchBase() {
        top->final();
    }

    virtual void sample_counters() = 0; 
    
    virtual void reset() = 0;

    void cycle() {
        top->CLK = 1;
        top->eval();
        main_time++;
        sample_counters();

        top->CLK = 0;
        top->eval();
        main_time++;
    }
};
