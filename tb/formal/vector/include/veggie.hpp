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
#include <stdexcept>
#include <filesystem>

/*
Emulated VRF

*/





class veggie
{
private:
    std::array<std::array<uint16_t,32>,256> vrf;
    std::array<uint32_t,16> vrmf;
public:
    //structs
    struct vrf_lane_in_t { //lanes WB to veggie
        std::array<uint8_t,5> vd = {};
        std::array<uint8_t,4> vs = {};
        std::array<uint8_t,2> ren = {};
        std::array<uint8_t,5> wen = {};
        std::array<std::array<uint16_t,32>,1> wdata = {};
    };

    struct vrf_sys_in_t { //sys WB to veggie
        std::array<uint8_t,1> vd = {};
        std::array<uint8_t,2> vs = {};
        std::array<uint8_t,2> ren = {};
        std::array<uint8_t,1> wen = {};
        std::array<std::array<uint16_t,32>,1> wdata = {};
    };

    struct vrf_sp_in_t { //sp WB to veggie
        std::array<uint8_t,2> vd = {};
        std::array<uint8_t,2> vs = {};
        std::array<uint8_t,2> ren = {};
        std::array<uint8_t,2> wen = {};
        std::array<std::array<uint16_t,32>,2> wdata = {};
    };

    struct vrf_lane_out_t { //veggie data to lanes
        std::array<std::array<uint16_t,32>,2> rdata = {};
        std::array<uint8_t,2> valid = {};
    };

    struct vrf_sys_out_t { //veggie data to sys
        std::array<std::array<uint16_t,32>,2> rdata = {};
        std::array<uint8_t,2> valid = {};
    };

    struct vrf_sp_out_t { //veggie data to sp
        std::array<std::array<uint16_t,32>,2> rdata = {};
        std::array<uint8_t,2> valid = {};
    };
    
    struct vmrf_in_t { //general inputs to vector mask
        std::array<uint8_t, 3> vs = {};
        std::array<uint8_t, 3> vd = {};
        std::array<uint8_t, 3> wen = {};
        std::array<uint8_t, 3> ren = {};
        std::array<uint32_t, 3> wdata = {};
    };

    struct vmrf_out_t { //outputs from the mask unit
        std::array<uint32_t, 3> rdata = {};
        std::array<uint8_t, 3> valid = {};
    };

    struct reduction_in_t { //reduction WB to veggie
        std::array<uint16_t,32> wdata = {};
        uint8_t valid;
        uint8_t vd;
    };

    //inputs
    uint8_t clk;
    uint8_t rst_n;
    vrf_lane_in_t lane_input_if;
    vrf_sys_in_t sys_input_if;
    vrf_sp_in_t sp_input_if;
    vmrf_in_t mask_input_if;
    reduction_in_t reduction_input_if;

    /* depriciated, switched to structs
    std::array<uint8_t,5> vrf_lane_vd = {};
    std::array<uint8_t,4> vrf_lane_vs = {};
    std::array<uint8_t,2> vrf_lane_ren = {};
    std::array<uint8_t,5> vrf_lane_wen = {};
    std::array<std::array<uint16_t,32>,5> vrf_lane_vwdata = {}; //vdata

    std::array<uint8_t,1> vrf_sys_vd = {};
    std::array<uint8_t,2> vrf_sys_vs = {};
    std::array<uint8_t,2> vrf_sys_ren = {};
    std::array<uint8_t,1> vrf_sys_wen = {};
    std::array<std::array<uint16_t,32>,1> vrf_sys_vwdata = {};

    std::array<uint8_t,2> vrf_sp_vd = {};
    std::array<uint8_t,2> vrf_sp_vs = {};
    std::array<uint8_t,2> vrf_sp_ren = {};
    std::array<uint8_t,2> vrf_sp_wen = {};
    std::array<std::array<uint16_t,32>,2> vrf_sp_vwdata = {};
    */

    //outputs
    vrf_lane_out_t lane_output_if;
    vrf_sys_out_t sys_output_if;
    vrf_sp_out_t sp_output_if;
    vmrf_out_t mask_output_if;
    uint8_t vrf_ready = 1;
    /* depriciated, switched to structs
    std::array<std::array<uint16_t,32>,2> vrf_lane_vrdata = {};
    std::array<uint8_t,2> vfr_lane_dvalid = {};

    std::array<std::array<uint16_t,32>,2> vrf_sys_vrdata = {};
    std::array<uint8_t,2> vfr_sys_dvalid = {};
    
    std::array<std::array<uint16_t,32>,2> vrf_sp_vrdata = {};
    std::array<uint8_t,2> vfr_sp_dvalid = {};
    
    std::array<uint8_t, 3> vmrf_vd = {};
    std::array<uint8_t, 3> vmrf_vs = {};
    std::array<uint8_t, 3> vmrf_mwen = {};
    std::array<uint8_t, 3> vmrf_mren = {};
    std::array<uint32_t, 3> vmrf_wdata = {};

    std::array<uint32_t, 3> vmrf_rdata = {};
    std::array<uint8_t, 3> vmrf_mvalid = {};

    std::array<uint16_t,32> reduction_wdata = {};
    uint8_t reduction_valid;
    uint8_t reduction_vd;

    */

    std::array<uint8_t, 8> scalars  = {0, 1, 2, 3, 4, 5, 6, 7};

    
    static inline const std::string default_folder = "./results/";

    void dump(const std::string& filename) const {
        // Ensure folder exists
        std::filesystem::create_directories(default_folder);

        // Append "_results.txt" to filename
        std::string full_path = default_folder + filename + "_results.txt";

        std::ofstream out(full_path);
        if (!out.is_open()) {
            throw std::runtime_error("Failed to open dump file: " + full_path);
        }

        for (size_t row = 0; row < vrf.size(); row++) {
            out << "VRF[" << row << "]: ";
            for (size_t col = 0; col < vrf[row].size(); col++) {
                out << vrf[row][col];
                if (col + 1 < vrf[row].size())
                    out << ", ";
            }
            out << "\n";
        }
    }
    
    
    

    veggie();
    ~veggie();
    std::array<uint16_t,32> read_vector(uint8_t idx);
    void write_vector(std::array<uint16_t,32> data, uint8_t idx);
    uint32_t read_mask(uint8_t idx);
    void write_mask(uint32_t data, uint8_t idx);
    void tick();
    
};


#endif