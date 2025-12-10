#ifndef VEGGIE_HPP
#define VEGGIE_HPP

#include <iostream>
#include <stdint.h>
#include <queue>
#include <unordered_map>
#include <string>
#include <sstream>
#include <fstream>
#include <array>
#include <algorithm>
#include <iomanip>
#include <cstring>

//256 by 32 memory
//16 by 32 masks

//4 write ports to the wb buffer
//4 read ports, 0,1 and 2,3 for VV operations
//valid signals
//2 mask read and write ports
//mvalid

//vd
//vector
//wen

//vs
//ren

//mvd
//mask
//mwen

//mvs
//mren

class veggie
{
private:
    std::array<std::array<uint16_t,32>,256> vrf;
    std::array<uint32_t,16> vrmf;
public:
    //inputs
    uint8_t clk;
    uint8_t rst_n;
    std::array<uint8_t,5> vrf_lane_vd = {};
    std::array<uint8_t,5> vrf_lane_vs = {};
    std::array<uint8_t,5> vrf_lane_ren = {};
    std::array<uint8_t,5> vrf_lane_wen = {};
    std::array<std::array<uint16_t,32>,5> vrf_lane_vwdata = {}; //vdata

    std::array<uint8_t,1> vrf_sys_vd = {};
    std::array<uint8_t,1> vrf_sys_vs = {};
    std::array<uint8_t,1> vrf_sys_ren = {};
    std::array<uint8_t,1> vrf_sys_wen = {};
    std::array<std::array<uint16_t,32>,1> vrf_sys_vwdata = {};

    std::array<uint8_t,2> vrf_sp_vd = {};
    std::array<uint8_t,2> vrf_sp_vs = {};
    std::array<uint8_t,2> vrf_sp_ren = {};
    std::array<uint8_t,2> vrf_sp_wen = {};
    std::array<std::array<uint16_t,32>,2> vrf_sp_vwdata = {};


    //outputs
    std::array<std::array<uint16_t,32>,2> vrf_lane_vrdata = {};
    std::array<uint8_t,2> vfr_lane_dvalid = {};

    std::array<std::array<uint16_t,32>,1> vrf_sys_vrdata = {};
    std::array<uint8_t,1> vfr_sys_dvalid = {};
    
    std::array<std::array<uint16_t,32>,2> vrf_sp_vrdata = {};
    std::array<uint8_t,2> vfr_sp_dvalid = {};

    
    std::array<uint8_t, 3> vmrf_vd = {};
    std::array<uint8_t, 3> vmrf_vs = {};
    std::array<uint8_t, 3> vmrf_mwen = {};
    std::array<uint8_t, 3> vmrf_mren = {};
    std::array<uint32_t, 3> vmrf_wdata = {};

    std::array<uint32_t, 3> vmrf_rdata = {};
    std::array<uint8_t, 3> vmrf_mvalid = {};

    uint8_t vrf_ready = 1;

    std::array<uint16_t,32> reduction_wdata = {};
    uint8_t reduction_valid;
    uint8_t reduction_vd;

    std::array<uint8_t, 8> scalars  = {0, 1, 2, 3, 4, 5, 6, 7};

    

    
    
    

    veggie();
    ~veggie();
    std::array<uint16_t,32> read_vector(uint8_t idx);
    void write_vector(std::array<uint16_t,32> data, uint8_t idx);
    uint32_t read_mask(uint8_t idx);
    void write_mask(uint32_t data, uint8_t idx);
    void tick();
    
};


#endif