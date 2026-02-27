#ifndef FP16_UTILS_H
#define FP16_UTILS_H

#include <vector>
#include <cstdint> // For uint16_t

// Function declarations

// Generate random FP16 bits
uint16_t random_fp16_bits();

// Convert FP16 bits to float
float fp16_from_bits(uint16_t bits);

// Convert float to FP16 bits
uint16_t bits_from_fp16(float val);

// Check if FP16 value is subnormal
inline bool is_subnormal(uint16_t bits);

// Apply DAZ (Denormals Are Zero)
inline uint16_t apply_daz(uint16_t bits);

// Apply FTZ (Flush To Zero)
inline uint16_t apply_ftz(uint16_t bits);

// Check if FP16 value is NaN
inline bool is_nan(uint16_t bits);

// Canonicalize NaN
inline uint16_t canonicalize_nan(uint16_t bits);

// Normalize zero
inline uint16_t normalize_zero(uint16_t bits);

// FP16 hardware-like multiplication
uint16_t fp16_mul_hw(uint16_t a_bits, uint16_t b_bits);

// FP16 hardware-like addition
uint16_t fp16_add_hw(uint16_t a_bits, uint16_t b_bits);
uint16_t fp16_4_input_add_hw(uint16_t a_bits, uint16_t b_bits, uint16_t c_bits, uint16_t d_bits);

// Generate random FP16 value within the FP16 exponent of a specified exponent range [min_exponent, max_exponent]
uint16_t random_fp16(int min_exponent, int max_exponent);

// Generate a random matrix of FP16 values with exponents in [min_exponent, max_exponent]
std::vector<std::vector<uint16_t>> generate_random_matrix_fp16(int rows, int cols, int min_exponent, int max_exponent);

#endif // FP16_UTILS_H