#include "sysarr.hpp"
#include <iostream>

sysarr::sysarr() {
    // Initialize matrices
    weights.setZero();
    activations.setZero();
    psums.setZero();
    result.setZero();
    
    // Initialize counters
    weight_col_idx = 0;
    activation_col_idx = 0;
    psum_row_idx = 0;
    result_row_idx = 0;
    cycle_count = 0;
    
    // Initialize signals
    clk = 0;
    rst_n = 1;
    
    // Initialize input interface
    std::fill(sys_input_if.weight_vec.begin(), sys_input_if.weight_vec.end(), 0);
    std::fill(sys_input_if.activation_vec.begin(), sys_input_if.activation_vec.end(), 0);
    std::fill(sys_input_if.psum_vec.begin(), sys_input_if.psum_vec.end(), 0);
    sys_input_if.weight_valid = 0;
    sys_input_if.activation_valid = 0;
    sys_input_if.psum_valid = 0;
    
    // Initialize output interface
    std::fill(sys_output_if.output_vec.begin(), sys_output_if.output_vec.end(), 0);
    sys_output_if.valid = 0;
    sys_output_if.ready = 1;
}

void sysarr::tick() {
    static uint8_t last_clk = 0;
    
    // Rising edge detection
    if (clk && !last_clk) {
        if (!rst_n) {
            // Reset
            weights.setZero();
            activations.setZero();
            psums.setZero();
            result.setZero();
            
            weight_col_idx = 0;
            activation_col_idx = 0;
            psum_row_idx = 0;
            result_row_idx = 0;
            cycle_count = 0;
            
            // Clear queues
            while(!completion_cycles.empty()) completion_cycles.pop();
            while(!output_queue.empty()) output_queue.pop();
            
            std::fill(sys_input_if.weight_vec.begin(), sys_input_if.weight_vec.end(), 0);
            std::fill(sys_input_if.activation_vec.begin(), sys_input_if.activation_vec.end(), 0);
            std::fill(sys_input_if.psum_vec.begin(), sys_input_if.psum_vec.end(), 0);
            sys_input_if.weight_valid = 0;
            sys_input_if.activation_valid = 0;
            sys_input_if.psum_valid = 0;
            
            std::fill(sys_output_if.output_vec.begin(), sys_output_if.output_vec.end(), 0);
            sys_output_if.valid = 0;
            sys_output_if.ready = 1;
        } else {
            // Clear output valid by default
            sys_output_if.valid = 0;
            std::fill(sys_output_if.output_vec.begin(), sys_output_if.output_vec.end(), 0);
            
            // Load weights (one column per cycle)
            if (sys_input_if.weight_valid && weight_col_idx < 32) {
                for (int i = 0; i < 32; i++) {
                    weights(i, weight_col_idx) = std::bit_cast<Eigen::bfloat16>(sys_input_if.weight_vec[i]);
                }
                weight_col_idx++;
            }
            
            // Load activations (one column per cycle)
            if (sys_input_if.activation_valid && activation_col_idx < 32) {
                for (int i = 0; i < 32; i++) {
                    activations(i, activation_col_idx) = std::bit_cast<Eigen::bfloat16>(sys_input_if.activation_vec[i]);
                }
                activation_col_idx++;
                
                // When all activations are loaded, trigger computation
                if (activation_col_idx == 32) {
                    // Compute result
                    result = weights * activations + psums;
                    psums = result;  // Update partial sums
                    
                    // Schedule outputs with 64-cycle latency from start of loading
                    // Outputs start appearing at cycle 64
                    for (int row = 0; row < 32; row++) {
                        std::array<uint16_t, 32> row_data;
                        for (int col = 0; col < 32; col++) {
                            row_data[col] = std::bit_cast<uint16_t>(result(row, col));
                        }
                        output_queue.push(row_data);
                        completion_cycles.push(cycle_count + 64 + row);  // 64 base latency + row offset
                    }
                    
                    // Reset counters for next computation
                    weight_col_idx = 0;
                    activation_col_idx = 0;
                    sys_output_if.ready = 0;  // Busy outputting
                }
            }
            
            // Load partial sums (one row per cycle)
            if (sys_input_if.psum_valid && psum_row_idx < 32) {
                for (int i = 0; i < 32; i++) {
                    psums(psum_row_idx, i) = std::bit_cast<Eigen::bfloat16>(sys_input_if.psum_vec[i]);
                }
                psum_row_idx++;
                
                if (psum_row_idx == 32) {
                    psum_row_idx = 0;  // Reset for next load
                }
            }
            
            // Handle outputs with latency
            if (!completion_cycles.empty() && completion_cycles.front() == cycle_count) {
                sys_output_if.output_vec = output_queue.front();
                sys_output_if.valid = 1;
                output_queue.pop();
                completion_cycles.pop();
                
                // If all outputs done, ready for next computation
                if (output_queue.empty()) {
                    sys_output_if.ready = 1;
                }
            }
        }
        
        cycle_count++;
    }
    
    last_clk = clk;
}

void sysarr::clear_psums() {
    psums.setZero();
    psum_row_idx = 0;
}

sysarr::~sysarr() {
    // Cleanup if needed
}