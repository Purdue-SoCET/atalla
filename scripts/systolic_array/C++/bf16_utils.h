#ifndef BF16_UTILS_H
#define BF16_UTILS_H

#include <vector>
#include <cstdint> // For uint16_t

// Function declarations

// Generate random BF16 bits
uint16_t random_bf16_bits();

// Check if BF16 value is subnormal
inline bool is_subnormal(uint16_t bits);

// Apply DAZ (Denormals Are Zero)
inline uint16_t apply_daz(uint16_t bits);

// Apply FTZ (Flush To Zero)
inline uint16_t apply_ftz(uint16_t bits);

// Check if BF16 value is NaN
inline bool is_nan(uint16_t bits);

// Canonicalize NaN
inline uint16_t canonicalize_nan(uint16_t bits);

// Normalize zero
inline uint16_t normalize_zero(uint16_t bits);

// BF16 hardware-like multiplication
uint16_t bf16_mul_hw(uint16_t a_bits, uint16_t b_bits);

// BF16 hardware-like addition
uint16_t bf16_add_hw(uint16_t a_bits, uint16_t b_bits);
uint16_t bf16_4_input_add_hw(uint16_t a_bits, uint16_t b_bits, uint16_t c_bits, uint16_t d_bits);

// Generate random BF16 value within the BF16 exponent of a specified exponent range [min_exponent, max_exponent]
uint16_t random_bf16(int min_exponent, int max_exponent);

// Generate a random matrix of BF16 values with exponents in [min_exponent, max_exponent]
std::vector<std::vector<uint16_t>> generate_random_matrix_bf16(int rows, int cols, int min_exponent, int max_exponent);

#endif // BF16_UTILS_H