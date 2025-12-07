#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include "sysarr.hpp"

// Helper to print matrix to terminal
void printMatrix(const Eigen::Matrix<Eigen::bfloat16, 32, 32> &mat, const std::string &name) {
    std::cout << "Matrix: " << name << std::endl;
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            std::cout << float(mat(i,j)) << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Helper to write matrix to a text file
void writeMatrixToFile(const Eigen::Matrix<Eigen::bfloat16, 32, 32> &mat, const std::string &filename) {
    std::ofstream ofs(filename);
    if (!ofs.is_open()) {
        std::cerr << "Failed to open " << filename << " for writing." << std::endl;
        return;
    }
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            ofs << float(mat(i,j)) << "\t";
        }
        ofs << "\n";
    }
    ofs.close();
    std::cout << "Matrix written to " << filename << std::endl;
}

// Helper to toggle clock
void tick(sysarr &sa) {
    sa.clk = 0;
    sa.eval();
    sa.clk = 1;
    sa.eval();
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Test 1: Simple API (non-cycle-accurate)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    sysarr sa;

    Eigen::Matrix<Eigen::bfloat16, 32, 32> weights;
    Eigen::Matrix<Eigen::bfloat16, 32, 32> activations;
    Eigen::Matrix<Eigen::bfloat16, 32, 32> psums;

    // Initialize matrices
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            weights(i,j) = Eigen::bfloat16((i+1)*(j+1)*0.01f);
            activations(i,j) = Eigen::bfloat16((i+1+j+1)*0.02f);
            psums(i,j) = Eigen::bfloat16(0.0f);
        }
    }

    // Compute reference result in BF16
    Eigen::Matrix<Eigen::bfloat16, 32, 32> ref = weights * activations + psums;

    // Load weights (column by column)
    for (int col = 0; col < 32; ++col) {
        sa.load_weight_vec(weights.col(col));
    }

    // Load activations (column by column)
    for (int col = 0; col < 32; ++col) {
        sa.load_activation_vec(activations.col(col));
    }

    // Load partial sums (row by row)
    for (int row = 0; row < 32; ++row) {
        sa.load_psum_vec(psums.row(row));
    }

    // Read back result (row by row)
    Eigen::Matrix<Eigen::bfloat16, 32, 32> result;
    for (int row = 0; row < 32; ++row) {
        result.row(row) = sa.read_result_vec(row);
    }

    // Compare
    Eigen::Matrix<Eigen::bfloat16, 32, 32> diff = result - ref;
    float max_diff = 0.0f;
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            float d = std::abs(float(diff(i,j)));
            if (d > max_diff) max_diff = d;
        }
    }
    
    std::cout << "Maximum difference vs reference: " << max_diff << std::endl;
    if (max_diff < 5e-2f) {
        std::cout << "Test 1 PASSED" << std::endl;
    } else {
        std::cout << "Test 1 FAILED" << std::endl;
    }

    // Test 2: Second computation WITHOUT loading new partial sums
    std::cout << "\n========================================" << std::endl;
    std::cout << "Test 2: Persistent partial sums" << std::endl;
    std::cout << "========================================" << std::endl;
    
    Eigen::Matrix<Eigen::bfloat16, 32, 32> weights2;
    Eigen::Matrix<Eigen::bfloat16, 32, 32> activations2;
    
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            weights2(i,j) = Eigen::bfloat16(0.5f);
            activations2(i,j) = Eigen::bfloat16(0.1f);
        }
    }
    
    // Load new weights and activations
    for (int col = 0; col < 32; ++col) {
        sa.load_weight_vec(weights2.col(col));
    }
    for (int col = 0; col < 32; ++col) {
        sa.load_activation_vec(activations2.col(col));
    }
    // Note: NOT loading partial sums - they should persist from previous result
    
    // Read back result
    Eigen::Matrix<Eigen::bfloat16, 32, 32> result2;
    for (int row = 0; row < 32; ++row) {
        result2.row(row) = sa.read_result_vec(row);
    }
    
    // Reference: W2 * A2 + previous_result
    Eigen::Matrix<Eigen::bfloat16, 32, 32> ref2 = weights2 * activations2 + result;
    
    // Compare
    Eigen::Matrix<Eigen::bfloat16, 32, 32> diff2 = result2 - ref2;
    float max_diff2 = 0.0f;
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            float d = std::abs(float(diff2(i,j)));
            if (d > max_diff2) max_diff2 = d;
        }
    }
    
    std::cout << "Maximum difference vs reference: " << max_diff2 << std::endl;
    if (max_diff2 < 5e-2f) {
        std::cout << "Test 2 PASSED (partial sums persisted correctly)" << std::endl;
    } else {
        std::cout << "Test 2 FAILED" << std::endl;
    }

    // Test 3: Cycle-accurate simulation
    std::cout << "\n========================================" << std::endl;
    std::cout << "Test 3: Cycle-accurate simulation" << std::endl;
    std::cout << "========================================" << std::endl;
    
    sysarr sa_cycle;
    
    // Create simple test matrices
    Eigen::Matrix<Eigen::bfloat16, 32, 32> w3, a3, p3;
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            w3(i,j) = Eigen::bfloat16(0.1f);
            a3(i,j) = Eigen::bfloat16(0.2f);
            p3(i,j) = Eigen::bfloat16(0.0f);
        }
    }
    
    Eigen::Matrix<Eigen::bfloat16, 32, 32> ref3 = w3 * a3 + p3;
    
    int cycle = 0;
    std::cout << "Starting cycle-accurate simulation..." << std::endl;
    
    // Reset
    sa_cycle.rst_n = 0;
    tick(sa_cycle);
    sa_cycle.rst_n = 1;
    tick(sa_cycle);
    cycle += 2;
    std::cout << "Cycle " << cycle << ": Reset complete, state=" << sa_cycle.get_state_name() << std::endl;
    
    // Load weights (32 cycles)
    sa_cycle.sa_weight_en = 1;
    for (int col = 0; col < 32; ++col) {
        sa_cycle.sa_array_in = w3.col(col);
        tick(sa_cycle);
        cycle++;
    }
    sa_cycle.sa_weight_en = 0;
    std::cout << "Cycle " << cycle << ": Weights loaded, state=" << sa_cycle.get_state_name() << std::endl;
    tick(sa_cycle);
    cycle++;
    
    // Load partial sums (32 cycles)
    sa_cycle.sa_partial_en = 1;
    for (int row = 0; row < 32; ++row) {
        sa_cycle.sa_array_in_partials = p3.row(row).transpose();
        tick(sa_cycle);
        cycle++;
    }
    sa_cycle.sa_partial_en = 0;
    std::cout << "Cycle " << cycle << ": Partial sums loaded, state=" << sa_cycle.get_state_name() << std::endl;
    tick(sa_cycle);
    cycle++;
    
    // Load activations (32 cycles)
    sa_cycle.sa_input_en = 1;
    for (int col = 0; col < 32; ++col) {
        sa_cycle.sa_array_in = a3.col(col);
        tick(sa_cycle);
        cycle++;
    }
    sa_cycle.sa_input_en = 0;
    std::cout << "Cycle " << cycle << ": Activations loaded, computation complete (instant), state=" << sa_cycle.get_state_name() << std::endl;
    
    // Read outputs (32 cycles)
    Eigen::Matrix<Eigen::bfloat16, 32, 32> result3;
    sa_cycle.sa_output_ready = 1;
    for (int row = 0; row < 32; ++row) {
        tick(sa_cycle);
        cycle++;
        if (sa_cycle.sa_out_valid) {
            result3.row(row) = sa_cycle.sa_array_output.transpose();
        }
    }
    sa_cycle.sa_output_ready = 0;
    std::cout << "Cycle " << cycle << ": All outputs read, state=" << sa_cycle.get_state_name() << std::endl;
    
    std::cout << "Total cycles: " << cycle << std::endl;
    std::cout << "Expected: ~2 (reset) + 32 (weights) + 1 (idle) + 32 (psums) + 1 (idle) + 32 (acts+compute) + 32 (output) = 132 cycles" << std::endl;
    
    // Compare
    Eigen::Matrix<Eigen::bfloat16, 32, 32> diff3 = result3 - ref3;
    float max_diff3 = 0.0f;
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            float d = std::abs(float(diff3(i,j)));
            if (d > max_diff3) max_diff3 = d;
        }
    }
    
    std::cout << "Maximum difference vs reference: " << max_diff3 << std::endl;
    if (max_diff3 < 5e-2f) {
        std::cout << "Test 3 PASSED (cycle-accurate)" << std::endl;
    } else {
        std::cout << "Test 3 FAILED" << std::endl;
    }
    
    // Write results to files
    writeMatrixToFile(result, "result_test1.txt");
    writeMatrixToFile(ref, "ref_test1.txt");

    return 0;
}