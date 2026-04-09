#include "sysarr.hpp"
#include <iostream>
#include <fstream>
#include <bit>
#include <Eigen/Dense>

void toggle_clock(sysarr &sa) {
    sa.clk = 0; sa.tick();
    sa.clk = 1; sa.tick();
}

int main() {
    sysarr sa;

    // Reset
    sa.rst_n = 0;
    toggle_clock(sa);
    sa.rst_n = 1;

    // Create matrices
    Eigen::Matrix<Eigen::bfloat16, 32, 32> W, A;

    // Example contents (change as desired)
    A.setRandom();
    W.setRandom();

    // Compute expected result in float for accuracy
    Eigen::Matrix<float, 32, 32> expected =
        W.cast<float>() * A.cast<float>();

    // Load weights (32 cycles)
    sa.sys_input_if.weight_valid = 1;
    for (int col = 0; col < 32; col++) {
        for (int i = 0; i < 32; i++) {
            sa.sys_input_if.weight_vec[i] =
                std::bit_cast<uint16_t>(W(i, col));
        }
        toggle_clock(sa);
    }
    sa.sys_input_if.weight_valid = 0;

    // Load activations (32 cycles, triggers computation)
    sa.sys_input_if.activation_valid = 1;
    for (int col = 0; col < 32; col++) {
        for (int i = 0; i < 32; i++) {
            sa.sys_input_if.activation_vec[i] =
                std::bit_cast<uint16_t>(A(i, col));
        }
        toggle_clock(sa);
    }
    sa.sys_input_if.activation_valid = 0;

    // Collect outputs
    Eigen::Matrix<Eigen::bfloat16, 32, 32> result;
    int row_count = 0;

    for (int i = 0; i < 200 && row_count < 32; i++) {
        toggle_clock(sa);
        if (sa.sys_output_if.valid) {
            for (int j = 0; j < 32; j++) {
                result(row_count, j) =
                    std::bit_cast<Eigen::bfloat16>(
                        sa.sys_output_if.output_vec[j]);
            }
            row_count++;
        }
    }

    std::cout << "Received " << row_count << " rows" << std::endl;

    // Write expected result
    std::ofstream exp_file("expected.txt");
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            exp_file << expected(i, j);
            if (j != 31) exp_file << " ";
        }
        exp_file << "\n";
    }
    exp_file.close();

    // Write hardware result
    std::ofstream res_file("result.txt");
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            res_file << float(result(i, j));
            if (j != 31) res_file << " ";
        }
        res_file << "\n";
    }
    res_file.close();

    std::cout << "Wrote expected.txt and result.txt" << std::endl;

    return 0;
}
