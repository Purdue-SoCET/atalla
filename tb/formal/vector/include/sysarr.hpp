#ifndef SYSARR_HPP
#define SYSARR_HPP

#include <Eigen/Core>
#include <Eigen/src/Core/arch/Default/BFloat16.h>
#include <Eigen/Dense>
#include <cstdint>

class sysarr
{
private:
    // Internal computation matrices (32x32 BF16)
    Eigen::Matrix<Eigen::bfloat16, 32, 32> weights;
    Eigen::Matrix<Eigen::bfloat16, 32, 32> activations;
    Eigen::Matrix<Eigen::bfloat16, 32, 32> psums;      // Persists between operations
    Eigen::Matrix<Eigen::bfloat16, 32, 32> result;
    
    // Internal counters to track loading progress
    int weight_col_idx;
    int activation_col_idx;
    int psum_row_idx;
    int result_row_idx;
    
    // State for cycle-accurate emulation
    enum State { IDLE, LOADING_WEIGHTS, LOADING_ACTS, LOADING_PSUMS, COMPUTING, OUTPUTTING };
    State state;
    
public:
    // Clock and control signals (driven by testbench)
    uint8_t clk;
    uint8_t rst_n;
    
    // Input signals
    Eigen::Matrix<Eigen::bfloat16, 32, 1> sa_array_in;          // Weight or activation input vector
    Eigen::Matrix<Eigen::bfloat16, 32, 1> sa_array_in_partials; // Partial sum input vector
    uint8_t sa_weight_en;      // Enable weight loading
    uint8_t sa_input_en;       // Enable activation loading
    uint8_t sa_partial_en;     // Enable partial sum loading
    uint8_t sa_output_ready;   // Ready to accept output
    
    // Output signals
    Eigen::Matrix<Eigen::bfloat16, 32, 1> sa_array_output;  // Output vector
    uint8_t sa_out_valid;      // Output valid flag
    uint8_t sa_ready;          // Ready to accept new inputs
    
    // Constructor
    sysarr();
    
    // Main evaluation function - call once per clock cycle
    // Implements cycle-accurate behavior based on control signals
    void eval();
    
    // Helper functions for simplified testbench (non-cycle-accurate mode)
    void load_weight_vec(const Eigen::Matrix<Eigen::bfloat16, 32, 1>& col);
    void load_activation_vec(const Eigen::Matrix<Eigen::bfloat16, 32, 1>& col);
    void load_psum_vec(const Eigen::Matrix<Eigen::bfloat16, 1, 32>& row);
    Eigen::Matrix<Eigen::bfloat16, 1, 32> read_result_vec(int row_idx);
    
    // Utility functions
    void clear_psums();
    const char* get_state_name() const;
    bool is_idle() const { return state == IDLE; }
    
    // Get full matrices (for verification/debugging)
    Eigen::Matrix<Eigen::bfloat16, 32, 32> get_result() const { return result; }
    Eigen::Matrix<Eigen::bfloat16, 32, 32> get_psums() const { return psums; }
    Eigen::Matrix<Eigen::bfloat16, 32, 32> get_weights() const { return weights; }
    Eigen::Matrix<Eigen::bfloat16, 32, 32> get_activations() const { return activations; }
    
    // Destructor
    ~sysarr();
};

#endif