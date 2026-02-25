#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>

constexpr int ROW = 32;
constexpr int COL = 32;
constexpr int TOTAL_TEST_NUM = 100;
constexpr int PROBABILITY_OF_NEW_WEIGHT = 250; // 25% chance out of 1000

extern std::string PATH_TO_INPUT;
extern std::string PATH_TO_EXPECTED_RESULT;

void write_matrix_to_file(const std::vector<std::vector<uint16_t>>& matrix,
                          const std::string& file_path);

void progress_bar(std::size_t iteration,
                  std::size_t total,
                  std::size_t width = 40);

uint16_t sim_add(uint16_t a, uint16_t b, bool is_fp16);
uint16_t sim_mul(uint16_t a, uint16_t b, bool is_fp16);

uint16_t sim_adder_tree(const std::vector<uint16_t>& in,
                        uint16_t psum,
                        bool is_fp16);

uint16_t sim_MEISSA_col(const std::vector<uint16_t>& input_row,
                        const std::vector<uint16_t>& weight_col,
                        uint16_t psum,
                        bool is_fp16);

std::vector<std::vector<uint16_t>> sim_MEISSA(
    const std::vector<std::vector<uint16_t>>& input,
    const std::vector<std::vector<uint16_t>>& weight,
    const std::vector<std::vector<uint16_t>>& psum,
    bool is_fp16);

void create_new_test(int test_num,
                     int max_exponent,
                     const std::string& file_path,
                     std::vector<std::vector<uint16_t>>* weight);