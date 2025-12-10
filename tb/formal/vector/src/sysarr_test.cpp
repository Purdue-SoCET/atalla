#include "sysarr.hpp"
#include <iostream>
#include <fstream>
#include <array>

// Toggle clock helper
void toggle_clock(sysarr &sa) {
    sa.clk = 0;
    sa.tick();
    sa.clk = 1;
    sa.tick();
}

void write_matrix_to_file(const Eigen::Matrix<Eigen::bfloat16,32,32>& mat, const std::string& filename) {
    std::ofstream ofs(filename);
    for(int i=0;i<32;i++){
        for(int j=0;j<32;j++){
            ofs << float(mat(i,j)) << "\t";
        }
        ofs << "\n";
    }
    ofs.close();
}

int main() {
    sysarr sa;

    // Reset the module
    sa.rst_n = 0;
    toggle_clock(sa);
    sa.rst_n = 1;
    toggle_clock(sa);

    std::cout << "Module reset complete. Initial state: " << sa.get_state_name() << std::endl;

    // Create test matrices (weights, activations, partial sums)
    Eigen::Matrix<Eigen::bfloat16,32,32> weights, activations, psums, ref_result;

    for(int i=0;i<32;i++){
        for(int j=0;j<32;j++){
            weights(i,j) = Eigen::bfloat16((i+1)*(j+1));       // simple integer pattern
            activations(i,j) = Eigen::bfloat16(i+j+1);        // simple sum pattern
            psums(i,j) = Eigen::bfloat16(0);                 // start with zero
        }
    }
    
    // Debug: Check what bfloat16 values actually are
    std::cout << "TB: Test bfloat16 values:" << std::endl;
    std::cout << "  weights(0,0) = " << float(weights(0,0)) << " (should be 1)" << std::endl;
    std::cout << "  weights(0,0) as bits = 0x" << std::hex << std::bit_cast<uint16_t>(weights(0,0)) << std::dec << std::endl;
    std::cout << "  activations(0,0) = " << float(activations(0,0)) << " (should be 1)" << std::endl;
    std::cout << "  activations(1,0) = " << float(activations(1,0)) << " (should be 2)" << std::endl;

    // Compute reference result
    ref_result = weights * activations + psums;

    // Load weights (cycle-accurate)
    sa.sa_weight_en = 1;
    for(int col=0; col<32; col++){
        for(int i=0;i<32;i++) sa.sa_array_in[i] = std::bit_cast<uint16_t>(weights(i,col));
        if (col == 0) {
            std::cout << "TB: Sending weight column 0: [0]=" << float(weights(0,0))
                      << " [1]=" << float(weights(1,0))
                      << " [2]=" << float(weights(2,0)) << std::endl;
        }
        toggle_clock(sa);
        std::cout << "Weight column " << col << " loaded, state: " << sa.get_state_name() << std::endl;
    }
    toggle_clock(sa); // Extra cycle for state machine to process
    sa.sa_weight_en = 0;
    toggle_clock(sa);

    // Load partial sums
    sa.sa_partial_en = 1;
    for(int row=0; row<32; row++){
        for(int i=0;i<32;i++) sa.sa_array_in_partials[i] = std::bit_cast<uint16_t>(psums(row,i));
        toggle_clock(sa);
        std::cout << "PSUM row " << row << " loaded, state: " << sa.get_state_name() << std::endl;
    }
    toggle_clock(sa); // Extra cycle for state machine to process
    sa.sa_partial_en = 0;
    toggle_clock(sa);

    // Load activations
    sa.sa_input_en = 1;
    for(int col=0; col<32; col++){
        for(int i=0;i<32;i++) sa.sa_array_in[i] = std::bit_cast<uint16_t>(activations(i,col));
        if (col == 0) {
            std::cout << "TB: Sending activation column 0: [0]=" << float(activations(0,0))
                      << " [1]=" << float(activations(1,0))
                      << " [2]=" << float(activations(2,0)) << std::endl;
        }
        toggle_clock(sa);
        std::cout << "Activation column " << col << " loaded, state: " << sa.get_state_name() << std::endl;
    }
    toggle_clock(sa); // Extra cycle for state machine to process completion
    sa.sa_input_en = 0;
    
    // Give time for: transition to COMPUTING (1 cycle) + computation (1 cycle) + transition to OUTPUTTING (1 cycle)
    toggle_clock(sa);
    toggle_clock(sa);
    toggle_clock(sa);

    // Read back results (cycle-accurate)
    Eigen::Matrix<Eigen::bfloat16, 32, 32> result;
    sa.sa_output_ready = 1;
    int row_idx = 0;
    for(int row=0; row<32; row++) {
        toggle_clock(sa);
        
        if(sa.sa_out_valid) {
            for(int i=0;i<32;i++) {
                result(row_idx,i) = std::bit_cast<Eigen::bfloat16>(sa.sa_array_output[i]);
            }
            // Debug: print first few values received
            if (row_idx < 2) {
                std::cout << "TB: Read row " << row_idx 
                          << ": [0]=" << float(result(row_idx, 0))
                          << " [1]=" << float(result(row_idx, 1))
                          << " [2]=" << float(result(row_idx, 2)) << std::endl;
                std::cout << "TB: Expected: [0]=" << float(ref_result(row_idx, 0))
                          << " [1]=" << float(ref_result(row_idx, 1))
                          << " [2]=" << float(ref_result(row_idx, 2)) << std::endl;
            }
            row_idx++;
            std::cout << "Read result row " << row_idx << std::endl;
        }
    }
    sa.sa_output_ready = 0;

    sa.sa_output_ready = 0;
    toggle_clock(sa);

    // Compare result
    float max_diff = 0.0f;
    for(int i=0;i<32;i++){
        for(int j=0;j<32;j++){
            float d = std::abs(float(result(i,j)) - float(ref_result(i,j)));
            if(d > max_diff) max_diff = d;
        }
    }

    std::cout << "Maximum difference vs reference: " << max_diff << std::endl;
    if(max_diff < 1e-3f) std::cout << "Test PASSED" << std::endl;
    else std::cout << "Test FAILED" << std::endl;

    // Write matrices to file
    write_matrix_to_file(result, "result.txt");
    write_matrix_to_file(ref_result, "ref_result.txt");

    return 0;
}