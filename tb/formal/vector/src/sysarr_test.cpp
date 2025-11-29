#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include "sysarr.hpp"

// Helper to print matrix to terminal
template<typename T>
void printMatrix(const Eigen::Matrix<T, 32, 32> &mat, const std::string &name) {
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
template<typename T>
void writeMatrixToFile(const Eigen::Matrix<T, 32, 32> &mat, const std::string &filename) {
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

int main() {
    sysarr sa;

    Eigen::Matrix<Eigen::bfloat16, 32, 32> weights;
    Eigen::Matrix<Eigen::bfloat16, 32, 32> activations;
    Eigen::Matrix<Eigen::bfloat16, 32, 32> psums;

    Eigen::Matrix<float, 32, 32> weights_f, activations_f, psums_f;

    // Initialize matrices
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            weights(i,j) = Eigen::bfloat16((i+1)*(j+1)*0.01f);
            activations(i,j) = Eigen::bfloat16((i+1+j+1)*0.02f);
            psums(i,j) = Eigen::bfloat16(0.0f);

            weights_f(i,j) = float(weights(i,j));
            activations_f(i,j) = float(activations(i,j));
            psums_f(i,j) = float(psums(i,j));
        }
    }

    // Compute reference result
    Eigen::Matrix<float, 32, 32> ref = weights_f * activations_f + psums_f;

    // Load matrices into sysarr
    for (int i = 0; i < 32; ++i) sa.load_psum_vec(psums.row(i));
    for (int col = 0; col < 32; ++col) sa.load_weight_vec(weights.col(col));
    for (int col = 0; col < 32; ++col) sa.load_activation_vec(activations.col(col));

    // Read back result
    Eigen::Matrix<float, 32, 32> result_float;
    for (int i = 0; i < 32; ++i) {
        auto row = sa.writeback_to_veggie(i);
        for (int j = 0; j < 32; ++j) {
            result_float(i,j) = float(row(0,j));
        }
    }

    // Print matrices to terminal
    printMatrix(weights_f, "Weights (float)");
    printMatrix(activations_f, "Activations (float)");
    printMatrix(psums_f, "PSums (float)");
    printMatrix(result_float, "Sysarr result");
    printMatrix(ref, "Reference result");

    // Optionally write to files
    writeMatrixToFile(result_float, "result.txt");
    writeMatrixToFile(ref, "ref.txt");

    // Compare
    float max_diff = (result_float - ref).cwiseAbs().maxCoeff();
    std::cout << "Maximum difference vs reference: " << max_diff << std::endl;
    if (max_diff < 5e-2f) {
        std::cout << "Test PASSED" << std::endl;
    } else {
        std::cout << "Test FAILED" << std::endl;
    }

    return 0;
}
