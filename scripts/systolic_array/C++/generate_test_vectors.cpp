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

uint32_t sim_2_input_add32(uint32_t a, uint32_t b, bool is_fp16) {
    return fp32_add_hw(a, b);
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

uint32_t sim_mul32(uint32_t a, uint32_t b)
{
    return fp32_mul_hw(a, b);
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

uint32_t sim_adder_tree32(const std::vector<uint32_t>& in, uint32_t psum, bool is_fp16) {
    std::vector<uint32_t> cur = in;          // working copy
    std::vector<uint32_t> next;              // next level

    if(ADDER_INPUT_NUM == 2)
    {
        while (cur.size() > 1) {
            size_t n = cur.size();
            next.resize((n + 1) / 2);

            for (size_t j = 0; j + 1 < n; j += 2) {
                next[j / 2] = sim_2_input_add32(cur[j], cur[j + 1], is_fp16);
            }
            if (n & 1) { // odd tail
                next[n / 2] = cur[n - 1];
            }

            cur.swap(next);
        }
    }
    else if(ADDER_INPUT_NUM == 4)
    {
        //
    }
    else
    {
        std::cerr << "Error: Unsupported ADDER_INPUT_NUM value: " << ADDER_INPUT_NUM << " ADDER_INPUT_NUM must be 2 or 4" << std::endl;
        return 0;
    }

    // add psum at the end
    return sim_2_input_add32(cur[0], psum, is_fp16);
}

uint32_t sim_MEISSA32_col(
                        const std::vector<uint16_t>& input_row, 
                        const std::vector<uint16_t>& weight_col, 
                        uint16_t psum, 
                        bool is_fp16) 
{
    std::vector<uint32_t> mul_results(input_row.size());

    for (size_t i = 0; i < input_row.size(); ++i) {
        uint32_t input32 = bf16_to_ui32(input_row[i]);
        uint32_t weight32 = bf16_to_ui32(weight_col[i]);
            
        mul_results[i] = sim_mul32(input32, weight32);
    }

    return sim_adder_tree32(mul_results, psum, is_fp16);
}

std::vector<std::vector<uint16_t>> sim_MEISSA32(
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

            output[row][col] = sim_MEISSA32_col(input[row], weight_col, psum[row][col], is_fp16);
        }
    }

    return output;
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

uint16_t sim_TPU_MAC(std::vector<uint16_t>& input, std::vector<uint16_t>& weight, uint16_t psum, bool is_fp16)
{
    if(input.size() != 4 || weight.size() != 4)
    {
        std::cerr << "Error: Invalid input/weight size for TPU mac input" << std::endl;
    }

    std::vector<uint16_t> mul_out(4);

    for(int i = 0; i < 4; ++i)
    {
        mul_out[i] = sim_mul(input[i], weight[i], is_fp16);
    }

    uint16_t add_out = sim_4_input_add(mul_out[0], mul_out[1], mul_out[2], mul_out[3], is_fp16);

    return sim_2_input_add(add_out, psum, is_fp16);
}

std::vector<std::vector<uint16_t>> sim_TPU(
                                    const std::vector<std::vector<uint16_t>>& input, 
                                    const std::vector<std::vector<uint16_t>>& weight, 
                                    const std::vector<std::vector<uint16_t>>& psum, 
                                    bool is_fp16)
{
    std::vector<std::vector<uint16_t>> output(input.size(), std::vector<uint16_t>(input[0].size()));

    const size_t M = input.size();
    const size_t K = input[0].size();
    // const size_t K_w = weight.size();
    const size_t N = weight[0].size();

    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
            uint16_t acc = psum[i][j];

            for (size_t k = 0; k < K; k += 4) {
                std::vector<uint16_t> in4 = {
                    input[i][k + 0],
                    input[i][k + 1],
                    input[i][k + 2],
                    input[i][k + 3]
                };
                std::vector<uint16_t> wt4 = {
                    weight[k + 0][j],
                    weight[k + 1][j],
                    weight[k + 2][j],
                    weight[k + 3][j]
                };

                acc = sim_TPU_MAC(in4, wt4, acc, is_fp16);
            }

            output[i][j] = acc;
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
    std::vector<std::vector<uint16_t>> psum_matrix(ROW, std::vector<uint16_t>(COL, 0));
    write_matrix_to_file(psum_matrix, file_path);
    file << "\n";

    std::ofstream expected_file(PATH_TO_EXPECTED_RESULT, std::ios::app);
    expected_file << "Test " << test_num << std::endl;
    std::vector<std::vector<uint16_t>> output_matrix;
    
    if(VERSION == "MEISSA")
    {
        output_matrix = sim_MEISSA(input_matrix, *weight, psum_matrix, IS_FP16);
    }
    else if (VERSION == "TPU")
    {
        output_matrix = sim_TPU(input_matrix, *weight, psum_matrix, IS_FP16);
    }
    else if (VERSION == "MEISSA32")
    {
        output_matrix = sim_MEISSA32(input_matrix, *weight, psum_matrix, IS_FP16);
    }
    else if (VERSION == "STANDARD")
    {
        // TODO: add standard simulation
    }
    else
    {
        std::cerr << "Error: Invalid systolic array version" << std::endl;
    }

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

    if(VERSION == "MEISSA32") 
    {
        IS_FP16 = false;
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
    std::vector<std::vector<uint16_t>> weight_matrix = generate_random_matrix(ROW, COL, 0, 19, IS_FP16); 
    write_matrix_to_file(weight_matrix, PATH_TO_INPUT);
    file << std::endl;

    // Generate Input matrix
    file << "Input" << std::endl;
    std::vector<std::vector<uint16_t>> input_matrix = generate_random_matrix(ROW, COL, 0, 19, IS_FP16);
    write_matrix_to_file(input_matrix, PATH_TO_INPUT);
    file << "\n";

    // Generate Psum matrix
    file << "Psum" << std::endl;
    std::vector<std::vector<uint16_t>> psum_matrix(ROW, std::vector<uint16_t>(COL, 0));
    write_matrix_to_file(psum_matrix, PATH_TO_INPUT);
    file << std::endl;

    expected_file << "Test " << "0" << std::endl;
    std::vector<std::vector<uint16_t>> output_matrix;
    if(VERSION == "MEISSA")
    {
        output_matrix = sim_MEISSA(input_matrix, weight_matrix, psum_matrix, IS_FP16);
    }
    else if (VERSION == "TPU")
    {
        output_matrix = sim_TPU(input_matrix, weight_matrix, psum_matrix, IS_FP16);
    }
    if(VERSION == "MEISSA32")
    {
        output_matrix = sim_MEISSA32(input_matrix, weight_matrix, psum_matrix, IS_FP16);
    }
    else if (VERSION == "STANDARD")
    {
        // TODO: add standard simulation
    }
    else
    {
        std::cerr << "Error: Invalid systolic array version" << std::endl;
    }
    write_matrix_to_file(output_matrix, PATH_TO_EXPECTED_RESULT);
    expected_file << std::endl;

    for (int i = 0; i < TOTAL_TEST_NUM; i++) {
        // Set the max exponent for random value range
        create_new_test(i + 1, 0, 19, PATH_TO_INPUT, &weight_matrix);
        progress_bar(i + 1, TOTAL_TEST_NUM);
    }

    auto end   = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Systolic array version: " << VERSION << std::endl;
    if(VERSION == "TPU")
    {
        std::cout << "Adder input num: " << "TPU is always " << 4 << std::endl;
    }
    else
    {
        std::cout << "Adder input num: " << ADDER_INPUT_NUM << std::endl;
    }

    if(VERSION == "MEISSA32")
    {
        std::cout << "Data type: " << "MEISSA32 is always bf16 with fp32 accumulation" << std::endl;
    }
    else
    {
        std::cout << "Data type: " << (IS_FP16 ? "FP16" : "BF16") << std::endl;
    }

    PATH_TO_INPUT = PATH_TO_INPUT.erase(0, input_path_env.length());
    PATH_TO_EXPECTED_RESULT = PATH_TO_EXPECTED_RESULT.erase(0, input_path_env.length());
    std::cout << "Created "  << TOTAL_TEST_NUM << " random test cases to " << PATH_TO_INPUT << " and " << PATH_TO_EXPECTED_RESULT << std::endl;
    std::string gen_pkg_command = "python3 ../Python/gen_systolic_array_pkg.py --version " + VERSION;
    system(gen_pkg_command.c_str());
    std::cout << "Elapsed: " << ms << " ms\n";

    return 0;
}