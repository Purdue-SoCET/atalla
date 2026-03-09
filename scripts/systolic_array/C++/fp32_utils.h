#ifndef FP32_UTILS_H
#define FP32_UTILS_H

#include <vector>
#include <cstdint> // For uint32_t

// Function declarations

// Generate random FP32 bits
uint32_t random_fp32_bits();

// // Convert FP32 bits to float
// float fp32_from_bits(uint32_t bits);

// // Convert float to FP32 bits
// uint32_t bits_from_fp32(float val);

// // Check if FP32 value is subnormal
// inline bool is_subnormal(uint32_t bits);

// // Apply DAZ (Denormals Are Zero)
// inline uint32_t apply_daz(uint32_t bits);

// // Apply FTZ (Flush To Zero)
// inline uint32_t apply_ftz(uint32_t bits);

// // Check if FP32 value is NaN
// inline bool is_nan(uint32_t bits);

// // Canonicalize NaN
// inline uint32_t canonicalize_nan(uint32_t bits);

// // Normalize zero
// inline uint32_t normalize_zero(uint32_t bits);

// FP32 hardware-like multiplication
uint32_t fp32_mul_hw(uint32_t a_bits, uint32_t b_bits);

// FP32 hardware-like addition
uint32_t fp32_add_hw(uint32_t a_bits, uint32_t b_bits);
uint32_t fp32_4_input_add_hw(uint32_t a_bits, uint32_t b_bits, uint32_t c_bits, uint32_t d_bits);

uint32_t bf16_to_ui32(uint16_t bits);

// // Generate random FP32 value within the FP32 exponent of a specified exponent range [min_exponent, max_exponent]
// uint32_t random_fp32(int min_exponent, int max_exponent);

// // Generate a random matrix of FP32 values with exponents in [min_exponent, max_exponent]
// std::vector<std::vector<uint32_t>> generate_random_matrix_fp32(int rows, int cols, int min_exponent, int max_exponent);

#endif // FP32_UTILS_H