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
    std::fill(std::begin(sa_array_in),std::end(sa_array_in), 0);
    std::fill(std::begin(sa_array_in_partials),std::end(sa_array_in_partials), 0);
    sa_weight_en = 0;
    sa_input_en = 0;
    sa_partial_en = 0;
    sa_output_ready = 0;
    std::fill(std::begin(sa_array_output),std::end(sa_array_output), 0);
    sa_out_valid = 0;
    sa_ready = 1;
}

void sysarr::tick() {
   static uint8_t last_clk = 0;
    
    // Rising edge detection
    if (clk && !last_clk) {
        if (!rst_n) {
            // Reset
            std::cout << "[SYSARR] Reset asserted" << std::endl;
            weights.setZero();
            activations.setZero();
            psums.setZero();
            result.setZero();
            weight_col_idx = 0;
            activation_col_idx = 0;
            psum_row_idx = 0;
            result_row_idx = 0;
            state = IDLE;
            std::fill(std::begin(sa_array_in),std::end(sa_array_in), 0);
            std::fill(std::begin(sa_array_in_partials),std::end(sa_array_in_partials), 0);
            sa_weight_en = 0;
            sa_input_en = 0;
            sa_partial_en = 0;
            sa_output_ready = 0;
            std::fill(std::begin(sa_array_output),std::end(sa_array_output), 0);
            sa_out_valid = 0;
            sa_ready = 1;
        } else {
            switch (state) {
                case IDLE:
                    sa_out_valid = 0;
                    sa_ready = 1;
                    
                    // Check what operation to start
                    if (sa_weight_en) {
                        std::cout << "[SYSARR] IDLE -> LOADING_WEIGHTS" << std::endl;
                        state = LOADING_WEIGHTS;
                        weight_col_idx = 0;
                        sa_ready = 0;
                    } else if (sa_input_en) {
                        std::cout << "[SYSARR] IDLE -> LOADING_ACTS" << std::endl;
                        state = LOADING_ACTS;
                        activation_col_idx = 0;
                        sa_ready = 0;
                    } else if (sa_partial_en) {
                        std::cout << "[SYSARR] IDLE -> LOADING_PSUMS" << std::endl;
                        state = LOADING_PSUMS;
                        psum_row_idx = 0;
                        sa_ready = 0;
                    }
                    break;
                    
                case LOADING_WEIGHTS:
                    if (sa_weight_en && weight_col_idx < 32) {
                        // Load one column of weights
                        for (int i = 0; i < weights.rows(); i++) {
                            weights(i, weight_col_idx) = std::bit_cast<Eigen::bfloat16>(sa_array_in[i]);
                        }
                        // Debug: print first column's first few values
                        if (weight_col_idx == 0) {
                            std::cout << "[SYSARR] First weight column: [0]=" << float(weights(0, 0))
                                      << " [1]=" << float(weights(1, 0))
                                      << " [2]=" << float(weights(2, 0)) << std::endl;
                        }
                        weight_col_idx++;
                        std::cout << "[SYSARR] Loading weights column " << (weight_col_idx-1) << "/32" << std::endl;
                    }
                    
                    // Check for state transition after loading (or if already done)
                    if (weight_col_idx >= 32) {
                        // All weights loaded - check if we can compute
                        if (activation_col_idx >= 32) {
                            std::cout << "[SYSARR] LOADING_WEIGHTS -> COMPUTING (weights done, acts already loaded)" << std::endl;
                            state = COMPUTING;
                            sa_ready = 0;
                        } else {
                            std::cout << "[SYSARR] LOADING_WEIGHTS -> IDLE (weights done, waiting for acts)" << std::endl;
                            state = IDLE;
                            sa_ready = 1;
                        }
                    } else if (!sa_weight_en) {
                        // Weight enable dropped before finishing - return to idle
                        std::cout << "[SYSARR] LOADING_WEIGHTS -> IDLE (enable dropped early)" << std::endl;
                        state = IDLE;
                        sa_ready = 1;
                    }
                    break;
                    
                case LOADING_ACTS:
                    if (sa_input_en && activation_col_idx < 32) {
                        // Load one column of activations
                        for (int i = 0; i < activations.rows(); i++)
                        {
                            activations(i, activation_col_idx) = std::bit_cast<Eigen::bfloat16>(sa_array_in[i]);
                        }
                        // Debug: print first column's first few values
                        if (activation_col_idx == 0) {
                            std::cout << "[SYSARR] First activation column: [0]=" << float(activations(0, 0))
                                      << " [1]=" << float(activations(1, 0))
                                      << " [2]=" << float(activations(2, 0)) << std::endl;
                        }
                        activation_col_idx++;
                        std::cout << "[SYSARR] Loading activations column " << (activation_col_idx-1) << "/32" << std::endl;
                    }
                    
                    // Check for state transition after loading (or if already done)
                    if (activation_col_idx >= 32) {
                        // All activations loaded - check if we can compute
                        if (weight_col_idx >= 32) {
                            std::cout << "[SYSARR] LOADING_ACTS -> COMPUTING (acts done, weights already loaded)" << std::endl;
                            state = COMPUTING;
                            sa_ready = 0;
                        } else {
                            std::cout << "[SYSARR] LOADING_ACTS -> IDLE (acts done, waiting for weights)" << std::endl;
                            state = IDLE;
                            sa_ready = 1;
                        }
                    } else if (!sa_input_en) {
                        // Input enable dropped before finishing - return to idle
                        std::cout << "[SYSARR] LOADING_ACTS -> IDLE (enable dropped early)" << std::endl;
                        state = IDLE;
                        sa_ready = 1;
                    }
                    
                    break;
                    
                case LOADING_PSUMS:
                    if (sa_partial_en) {
                        // Load one row of partial sums (note: input is a column, we transpose it)
                        Eigen::Matrix<Eigen::bfloat16, 32, 1> temp;
                        for (int i = 0; i < activations.rows(); i++)
                        {
                            temp[i] = std::bit_cast<Eigen::bfloat16>(sa_array_in_partials[i]);
                        }
                        psums.row(psum_row_idx) = temp.transpose();
                        psum_row_idx++;
                        std::cout << "[SYSARR] Loading psums row " << (psum_row_idx-1) << "/32" << std::endl;
                        
                        if (psum_row_idx >= 32) {
                            // All psums loaded
                            std::cout << "[SYSARR] LOADING_PSUMS -> IDLE (all psums loaded)" << std::endl;
                            state = IDLE;
                            sa_ready = 1;
                        }
                    } else {
                        // Partial enable dropped - return to idle
                        std::cout << "[SYSARR] LOADING_PSUMS -> IDLE (enable dropped)" << std::endl;
                        state = IDLE;
                        sa_ready = 1;
                    }
                    break;
                    
                case COMPUTING:
                    std::cout << "[SYSARR] COMPUTING matrix multiply" << std::endl;
                    // Perform computation (takes 1 cycle)
                    result = weights * activations + psums;
                    
                    // Debug: print a few values
                    std::cout << "[SYSARR] Sample result values: result(0,0)=" << float(result(0,0)) 
                              << " result(0,1)=" << float(result(0,1)) 
                              << " result(1,0)=" << float(result(1,0)) << std::endl;
                    
                    // Update partial sums for next operation
                    psums = result;
                    
                    // Move to output state
                    std::cout << "[SYSARR] COMPUTING -> OUTPUTTING" << std::endl;
                    state = OUTPUTTING;
                    result_row_idx = 0;
                    sa_ready = 0;
                    break;
                    
                case OUTPUTTING:
                    if (sa_output_ready) {
                        // Check if we've already output all rows
                        if (result_row_idx >= 32) {
                            // All outputs sent - transition to idle
                            std::cout << "[SYSARR] OUTPUTTING -> IDLE (all outputs sent)" << std::endl;
                            state = IDLE;
                            sa_ready = 1;
                            sa_out_valid = 0;
                        } else {
                            // Output one row per cycle
                            Eigen::Matrix<Eigen::bfloat16, 32, 1> temp;
                            temp = result.row(result_row_idx).transpose();
                            for (int i = 0; i < activations.rows(); i++)
                            {
                                sa_array_output[i] = std::bit_cast<uint16_t>(temp[i]);
                            }
                            sa_out_valid = 1;
                            
                            // Debug: print first few values of the row being output
                            if (result_row_idx < 2) {
                                std::cout << "[SYSARR] Outputting row " << result_row_idx 
                                          << ": [0]=" << float(temp[0])
                                          << " [1]=" << float(temp[1])
                                          << " [2]=" << float(temp[2]) << std::endl;
                            }
                            
                            std::cout << "[SYSARR] Outputting row " << result_row_idx << "/32" << std::endl;
                            result_row_idx++;
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