#ifndef TESTBENCH_HPP
#define TESTBENCH_HPP

#include "veggie.hpp"
#include "scratchpad.hpp"
#include "sysarr.hpp"
#include "schedular.hpp"
#include "Vvector_datapath_wrapper.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <memory>
#include <array>

class top
{
private:
    
    std::unique_ptr<VerilatedVcdC> tfp; //trace file pointer "for waves"
    
public:
    std::unique_ptr<Vvector_datapath_wrapper> dut;
    schedular sc;
    sysarr sys;
    veggie veg;
    scratchpad sp;

    int cycle;

    top(bool enable_trace = false);
    ~top();

    //helpers   
    std::array<uint16_t, 32> verilator_vector_to_cpp_vector(const uint32_t* vec);                       //used to read from vreg_t ports
    void cpp_vector_to_verilator_vector(const std::array<uint16_t, 32>& vec, uint32_t* result);        //used to write to any vreg_t ports
    std::array<uint16_t, 32> read_vector_from_idx(uint32_t* result, size_t idx);                        //reads a specific result vector from the lane outputs (only used with cpp std arrays) DOES NOT HANDLE OOB
    void write_vector_to_idx(const std::array<uint16_t, 32>& vec, uint32_t* result, size_t idx);        //writes a cpp vector to a DUT vector. DOES NOT HANDLE OOB

    //testbench functions
    void clock();
    void reset();
    void propogate();

    void generate_report(const std::string& filename);

    //testcases
    void test_add_vv();
};

#endif