#ifndef SYSARR_HPP
#define SYSARR_HPP

#include <Eigen/Core>
#include <Eigen/src/Core/arch/Default/BFloat16.h>
#include <Eigen/Dense>
#include <cstdint>
#include <bit>
#include <array>
#include <algorithm>
#include <queue>

class sysarr
{
private:
    // Internal computation matrices (32x32 BF16)
    Eigen::Matrix<Eigen::bfloat16, 32, 32> weights;
    Eigen::Matrix<Eigen::bfloat16, 32, 32> activations;
    Eigen::Matrix<Eigen::bfloat16, 32, 32> psums;
    Eigen::Matrix<Eigen::bfloat16, 32, 32> result;
    
    // Loading counters
    int weight_col_idx;
    int activation_col_idx;
    int psum_row_idx;
    
    // Output handling
    int result_row_idx;
    std::queue<int> completion_cycles;
    std::queue<std::array<uint16_t, 32>> output_queue;
    int cycle_count;
    
public:
    struct sys_input_if_t 
    {
        std::array<uint16_t, 32> weight_vec;      // Weight column input
        std::array<uint16_t, 32> activation_vec;  // Activation column input
        std::array<uint16_t, 32> psum_vec;        // Partial sum row input
        uint8_t weight_valid;     // Valid weight data
        uint8_t activation_valid; // Valid activation data
        uint8_t psum_valid;       // Valid partial sum data
    };
    
    struct sys_output_if_t 
    {
        std::array<uint16_t, 32> output_vec;  // Output row
        uint8_t valid;                        // Output valid
        uint8_t ready;                        // Ready for new computation
    };
    
    // Clock and control signals
    uint8_t clk;
    uint8_t rst_n;
    sys_input_if_t sys_input_if;
    sys_output_if_t sys_output_if;
    
    // Constructor
    sysarr();
    
    // Main tick function
    void tick();
    
    // Utility functions
    void clear_psums();
    Eigen::Matrix<Eigen::bfloat16, 32, 32> get_result() const { return result; }
    Eigen::Matrix<Eigen::bfloat16, 32, 32> get_psums() const { return psums; }
    Eigen::Matrix<Eigen::bfloat16, 32, 32> get_weights() const { return weights; }
    Eigen::Matrix<Eigen::bfloat16, 32, 32> get_activations() const { return activations; }
    
    // Destructor
    ~sysarr();
};

#endif