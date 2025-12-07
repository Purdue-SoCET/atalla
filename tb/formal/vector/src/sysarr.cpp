#include "sysarr.hpp"
#include <iostream>

sysarr::sysarr() {
    // Initialize matrices to zero
    weights.setZero();
    activations.setZero();
    psums.setZero();
    result.setZero();
    
    // Initialize counters
    weight_col_idx = 0;
    activation_col_idx = 0;
    psum_row_idx = 0;
    result_row_idx = 0;
    
    // Initialize state
    state = IDLE;
    
    // Initialize signals
    clk = 0;
    rst_n = 1;
    sa_array_in.setZero();
    sa_array_in_partials.setZero();
    sa_weight_en = 0;
    sa_input_en = 0;
    sa_partial_en = 0;
    sa_output_ready = 0;
    sa_array_output.setZero();
    sa_out_valid = 0;
    sa_ready = 1;
}

void sysarr::eval() {
    static uint8_t last_clk = 0;
    
    // Rising edge detection
    if (clk && !last_clk) {
        if (!rst_n) {
            // Reset
            state = IDLE;
            weight_col_idx = 0;
            activation_col_idx = 0;
            psum_row_idx = 0;
            result_row_idx = 0;
            sa_out_valid = 0;
            sa_ready = 1;
            weights.setZero();
            activations.setZero();
            psums.setZero();
            result.setZero();
        } else {
            switch (state) {
                case IDLE:
                    sa_out_valid = 0;
                    sa_ready = 1;
                    
                    // Check what operation to start
                    if (sa_weight_en) {
                        state = LOADING_WEIGHTS;
                        weight_col_idx = 0;
                        sa_ready = 0;
                    } else if (sa_input_en) {
                        state = LOADING_ACTS;
                        activation_col_idx = 0;
                        sa_ready = 0;
                    } else if (sa_partial_en) {
                        state = LOADING_PSUMS;
                        psum_row_idx = 0;
                        sa_ready = 0;
                    }
                    break;
                    
                case LOADING_WEIGHTS:
                    if (sa_weight_en) {
                        // Load one column of weights
                        weights.col(weight_col_idx) = sa_array_in;
                        weight_col_idx++;
                        
                        if (weight_col_idx >= 32) {
                            // All weights loaded
                            state = IDLE;
                            sa_ready = 1;
                        }
                    } else {
                        // Weight enable dropped - return to idle
                        state = IDLE;
                        sa_ready = 1;
                    }
                    break;
                    
                case LOADING_ACTS:
                    if (sa_input_en) {
                        // Load one column of activations
                        activations.col(activation_col_idx) = sa_array_in;
                        activation_col_idx++;
                        
                        if (activation_col_idx >= 32) {
                            // All activations loaded - computation happens "instantly" as data flows
                            // In real hardware, this happens as weights shift through the array
                            result = weights * activations + psums;
                            psums = result;
                            
                            
                            state = OUTPUTTING;
                            result_row_idx = 0;
                            sa_ready = 0;
                        }
                    } else {
                        // Input enable dropped - return to idle
                        state = IDLE;
                        sa_ready = 1;
                    }
                    break;
                    
                case LOADING_PSUMS:
                    if (sa_partial_en) {
                        // Load one row of partial sums (note: input is a column, we transpose it)
                        psums.row(psum_row_idx) = sa_array_in_partials.transpose();
                        psum_row_idx++;
                        
                        if (psum_row_idx >= 32) {
                            // All psums loaded
                            state = IDLE;
                            sa_ready = 1;
                        }
                    } else {
                        // Partial enable dropped - return to idle
                        state = IDLE;
                        sa_ready = 1;
                    }
                    break;
                    
                case COMPUTING:
                    // Perform computation (takes 1 cycle)
                    result = weights * activations + psums;
                    
                    // Update partial sums for next operation
                    psums = result;
                    
                    // Move to output state
                    state = OUTPUTTING;
                    result_row_idx = 0;
                    sa_ready = 0;
                    break;
                    
                case OUTPUTTING:
                    if (sa_output_ready) {
                        // Output one row per cycle
                        sa_array_output = result.row(result_row_idx).transpose();
                        sa_out_valid = 1;
                        result_row_idx++;
                        
                        if (result_row_idx >= 32) {
                            // All outputs sent
                            state = IDLE;
                            sa_ready = 1;
                            sa_out_valid = 0;
                        }
                    } else {
                        sa_out_valid = 0;
                    }
                    break;
            }
        }
    }
    
    last_clk = clk;
}

// Helper functions for simplified testbench (non-cycle-accurate)
void sysarr::load_weight_vec(const Eigen::Matrix<Eigen::bfloat16, 32, 1>& col) {
    weights.col(weight_col_idx) = col;
    weight_col_idx++;
    
    if (weight_col_idx >= 32) {
        weight_col_idx = 0;
    }
}

void sysarr::load_activation_vec(const Eigen::Matrix<Eigen::bfloat16, 32, 1>& col) {
    activations.col(activation_col_idx) = col;
    activation_col_idx++;
    
    if (activation_col_idx >= 32) {
        activation_col_idx = 0;
        
        // Compute result
        result = weights * activations + psums;
        
        // Update partial sums for next operation
        psums = result;
        
    }
}

void sysarr::load_psum_vec(const Eigen::Matrix<Eigen::bfloat16, 1, 32>& row) {
    psums.row(psum_row_idx) = row;
    psum_row_idx++;
    
    if (psum_row_idx >= 32) {
        psum_row_idx = 0;
    }
}

Eigen::Matrix<Eigen::bfloat16, 1, 32> sysarr::read_result_vec(int row_idx) {
    if (row_idx < 0 || row_idx >= 32) {
        return Eigen::Matrix<Eigen::bfloat16, 1, 32>::Zero();
    }
    return result.row(row_idx);
}

void sysarr::clear_psums() {
    psums.setZero();
    psum_row_idx = 0;
}

const char* sysarr::get_state_name() const {
    switch (state) {
        case IDLE: return "IDLE";
        case LOADING_WEIGHTS: return "LOADING_WEIGHTS";
        case LOADING_ACTS: return "LOADING_ACTS";
        case LOADING_PSUMS: return "LOADING_PSUMS";
        case COMPUTING: return "COMPUTING";
        case OUTPUTTING: return "OUTPUTTING";
        default: return "UNKNOWN";
    }
}

sysarr::~sysarr() {
    // Cleanup if needed
}