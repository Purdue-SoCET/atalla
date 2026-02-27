#include <iostream>
#include <thread>
#include <fstream>
#include <vector>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include "generate_test_vectors.h"

std::string PATH_TO_INPUT = "/scripts/systolic_array/systolic_array_tb_input.csv";
std::string PATH_TO_EXPECTED_RESULT = "/scripts/systolic_array/systolic_array_tb_expected_result.csv";

// Function to write a 2D vector of uint16_t to a file
void write_matrix_to_file(const std::vector<std::vector<uint16_t>>& matrix, const std::string& file_path) {
    std::ofstream file(file_path, std::ios::app); // Open the file in append mode

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << file_path << " for writing." << std::endl;
        return;
    }

    for (const auto& row : matrix) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << "0x" << std::hex << std::setfill('0') << std::setw(4) << row[i];
            if (i < row.size() - 1) {
                file << ","; // Add a comma between values
            }
        }
        file << "\n"; // Newline after each row
    }

    file.close(); // Close the file
}

void progress_bar(std::size_t iteration,
    std::size_t total,
    std::size_t width)
{
    if (total == 0) return;

    double percent = static_cast<double>(iteration) /
        static_cast<double>(total);

    std::size_t filled =
    static_cast<std::size_t>(width * percent);

    std::string bar(filled, '#');
    bar += std::string(width - filled, '-');

    std::cout << '\r'
    << '[' << bar << "] "
    << std::fixed << std::setw(6)
    << std::setprecision(2)
    << percent * 100.0 << "% ("
    << iteration << '/' << total << ')'
    << std::flush;

    if (iteration == total) {
        std::cout << '\n';
    }
}

uint16_t sim_2_input_add(uint16_t a, uint16_t b, bool is_fp16) {
    if (is_fp16) {
        return fp16_add_hw(a, b);
    } else {
        return bf16_add_hw(a, b);
    }
}

uint16_t sim_4_input_add(uint16_t a, uint16_t b, uint16_t c, uint16_t d, bool is_fp16) {
    if (is_fp16) {
        return fp16_4_input_add_hw(a, b, c, d);
    } else {
        return bf16_4_input_add_hw(a, b, c, d);
    }
}

uint16_t sim_mul(uint16_t a, uint16_t b, bool is_fp16) {
    if (is_fp16) {
        return fp16_mul_hw(a, b);
    } else {
        return bf16_mul_hw(a, b);
    }
}

uint16_t sim_adder_tree(const std::vector<uint16_t>& in, uint16_t psum, bool is_fp16) {
    std::vector<uint16_t> cur = in;          // working copy
    std::vector<uint16_t> next;              // next level

    if(ADDER_INPUT_NUM == 2)
    {
        while (cur.size() > 1) {
            size_t n = cur.size();
            next.resize((n + 1) / 2);

            for (size_t j = 0; j + 1 < n; j += 2) {
                next[j / 2] = sim_2_input_add(cur[j], cur[j + 1], is_fp16);
            }
            if (n & 1) { // odd tail
                next[n / 2] = cur[n - 1];
            }

            cur.swap(next);
        }
    }
    else if(ADDER_INPUT_NUM == 4)
    {
        while (cur.size() > 1) {
            size_t n = cur.size();
            next.resize((n + 3) / 4);

            for (size_t j = 0; j + 3 < n; j += 4) {
                next[j / 4] = sim_4_input_add(cur[j], cur[j + 1], cur[j + 2], cur[j + 3], is_fp16);
            }
            size_t tail = n % 4;
            if (tail > 0) {
                uint16_t sum = cur[n - tail];
                for (size_t k = n - tail + 1; k < n; ++k) {
                    sum = sim_2_input_add(sum, cur[k], is_fp16);
                }
                next[n / 4] = sum;
            }

            cur.swap(next);
        }
    }
    else
    {
        std::cerr << "Error: Unsupported ADDER_INPUT_NUM value: " << ADDER_INPUT_NUM << " ADDER_INPUT_NUM must be 2 or 4" << std::endl;
        return 0;
    }

    // add psum at the end
    return sim_2_input_add(cur[0], psum, is_fp16);
}

uint16_t sim_MEISSA_col(
                        const std::vector<uint16_t>& input_row, 
                        const std::vector<uint16_t>& weight_col, 
                        uint16_t psum, 
                        bool is_fp16) 
{
    std::vector<uint16_t> mul_results(input_row.size());

    for (size_t i = 0; i < input_row.size(); ++i) {
        mul_results[i] = sim_mul(input_row[i], weight_col[i], is_fp16);
    }

    return sim_adder_tree(mul_results, psum, is_fp16);
}

std::vector<std::vector<uint16_t>> sim_MEISSA(
                                    const std::vector<std::vector<uint16_t>>& input, 
                                    const std::vector<std::vector<uint16_t>>& weight, 
                                    const std::vector<std::vector<uint16_t>>& psum, 
                                    bool is_fp16) 
{
    std::vector<std::vector<uint16_t>> output(input.size(), std::vector<uint16_t>(input[0].size()));

    for(int row = 0; row < input.size(); ++row)
    {
        for(int col = 0; col < input[0].size(); ++col)
        {
            std::vector<uint16_t> weight_col(weight.size());
            for(int i = 0; i < weight.size(); ++i)
            {
                weight_col[i] = weight[i][col];
            }

            output[row][col] = sim_MEISSA_col(input[row], weight_col, psum[row][col], is_fp16);
        }
    }

    return output;
}

std::vector<std::vector<uint16_t>> generate_random_matrix(int rows, int cols, int min_exponent, int max_exponent, bool is_fp16) {
    if (is_fp16) {
        return generate_random_matrix_fp16(rows, cols, min_exponent, max_exponent);
    } else {
        return generate_random_matrix_bf16(rows, cols, min_exponent, max_exponent);
    }
}

void create_new_test(int test_num, int min_exponent, int max_exponent, const std::string& file_path, std::vector<std::vector<uint16_t>> *weight)
{
    // Write test number
    std::ofstream file(file_path, std::ios::app); // Open the file in append mode
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << file_path << " for writing." << std::endl;
        return;
    }

    file << "Test " << test_num << std::endl;

    // Conditionally generate new weight
    if(std::rand() % 1000 < PROBABILITY_OF_NEW_WEIGHT) {
        file << "Weight" << std::endl;
        std::vector<std::vector<uint16_t>> weight_matrix = generate_random_matrix(ROW, COL, min_exponent, max_exponent, IS_FP16);
        write_matrix_to_file(weight_matrix, file_path);
        file << "\n";

        *weight = weight_matrix; // Update the weight matrix for the next tests
    }

    // Generate Input matrix
    file << "Input" << std::endl;
    std::vector<std::vector<uint16_t>> input_matrix = generate_random_matrix(ROW, COL, min_exponent, max_exponent, IS_FP16);
    write_matrix_to_file(input_matrix, file_path);
    file << "\n";

    // Generate Psum matrix
    file << "Psum" << std::endl;
    std::vector<std::vector<uint16_t>> psum_matrix = generate_random_matrix(ROW, COL, min_exponent, max_exponent, IS_FP16);
    write_matrix_to_file(psum_matrix, file_path);
    file << "\n";

    std::ofstream expected_file(PATH_TO_EXPECTED_RESULT, std::ios::app);
    expected_file << "Test " << test_num << std::endl;
    std::vector<std::vector<uint16_t>> output_matrix = sim_MEISSA(input_matrix, *weight, psum_matrix, IS_FP16);
    write_matrix_to_file(output_matrix, PATH_TO_EXPECTED_RESULT);
    expected_file << "\n";
    expected_file.close();

    file.close();
}

int main() {
    // unsigned int n = std::thread::hardware_concurrency();
    // std::cout << "available logical threads: " << n << std::endl;

    std::string input_path_env = std::getenv("ATALLA_ROOT");
    if (!input_path_env.empty()) {
        PATH_TO_INPUT = input_path_env + PATH_TO_INPUT;
        PATH_TO_EXPECTED_RESULT = input_path_env + PATH_TO_EXPECTED_RESULT;
    }
    else {
        std::cerr << "Error: ATALLA_ROOT environment variable not set." << std::endl;
    }

    auto start = std::chrono::steady_clock::now();

    std::ofstream file1(PATH_TO_INPUT, std::ios::trunc);
    std::ofstream expected_file1(PATH_TO_EXPECTED_RESULT, std::ios::trunc);
    file1.close();
    expected_file1.close();

    std::ofstream file(PATH_TO_INPUT, std::ios::app);
    std::ofstream expected_file(PATH_TO_EXPECTED_RESULT, std::ios::app);

    // Initial weight matrix
    file << "Test " << "0" << std::endl;
    file << "Weight" << std::endl;
    std::vector<std::vector<uint16_t>> weight_matrix = generate_random_matrix(ROW, COL, 0, 3, IS_FP16); 
    write_matrix_to_file(weight_matrix, PATH_TO_INPUT);
    file << std::endl;

    // Generate Input matrix
    file << "Input" << std::endl;
    std::vector<std::vector<uint16_t>> input_matrix = generate_random_matrix(ROW, COL, 0, 3, IS_FP16);
    write_matrix_to_file(input_matrix, PATH_TO_INPUT);
    file << "\n";

    // Generate Psum matrix
    file << "Psum" << std::endl;
    std::vector<std::vector<uint16_t>> psum_matrix = generate_random_matrix(ROW, COL, 0, 3, IS_FP16);
    write_matrix_to_file(psum_matrix, PATH_TO_INPUT);
    file << std::endl;

    expected_file << "Test " << "0" << std::endl;
    std::vector<std::vector<uint16_t>> output_matrix = sim_MEISSA(input_matrix, weight_matrix, psum_matrix, true);
    write_matrix_to_file(output_matrix, PATH_TO_EXPECTED_RESULT);
    expected_file << std::endl;

    for (int i = 0; i < TOTAL_TEST_NUM; i++) {
        // Set the max exponent for random value range
        create_new_test(i + 1, 0, 19, PATH_TO_INPUT, &weight_matrix);
        progress_bar(i + 1, TOTAL_TEST_NUM);
    }

    auto end   = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Adder input num: " << ADDER_INPUT_NUM << std::endl;
    std::cout << "Data type: " << (IS_FP16 ? "FP16" : "BF16") << std::endl;
    PATH_TO_INPUT = PATH_TO_INPUT.erase(0, input_path_env.length());
    PATH_TO_EXPECTED_RESULT = PATH_TO_EXPECTED_RESULT.erase(0, input_path_env.length());
    std::cout << "Created "  << TOTAL_TEST_NUM << " random test cases to " << PATH_TO_INPUT << " and " << PATH_TO_EXPECTED_RESULT << std::endl;
    std::cout << "Elapsed: " << ms << " ms\n";

    return 0;
}