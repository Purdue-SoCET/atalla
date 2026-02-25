#include <cstdlib> // For std::srand and std::rand
#include <cstdint>
#include <cmath>
#include <bitset>
#include <vector>
#include "fp16_utils.h"

// Generate random FP16 bits
uint16_t random_fp16_bits() {
    return static_cast<uint16_t>(std::rand() % 0x10000); // Random 16-bit value
}

// Convert FP16 bits to float
float fp16_from_bits(uint16_t bits) {
    union {
        uint32_t i;
        float f;
    } u;

    uint32_t sign = (bits & 0x8000) << 16;
    uint32_t exponent = (bits & 0x7C00) << 13;
    uint32_t mantissa = (bits & 0x03FF) << 13;
    u.i = sign | exponent | mantissa;

    return u.f;
}

// Convert float to FP16 bits
uint16_t bits_from_fp16(float val) {
    union {
        uint32_t i;
        float f;
    } u;
    u.f = val;

    uint16_t sign = (u.i >> 16) & 0x8000;
    uint16_t exponent = (u.i >> 13) & 0x7C00;
    uint16_t mantissa = (u.i >> 13) & 0x03FF;

    return sign | exponent | mantissa;
}

// Check if FP16 value is subnormal
bool is_subnormal(uint16_t bits) {
    uint16_t exponent = (bits >> 10) & 0x1F;
    uint16_t mantissa = bits & 0x3FF;
    return exponent == 0 && mantissa != 0;
}

// Apply DAZ (Denormals Are Zero)
uint16_t apply_daz(uint16_t bits) {
    if (is_subnormal(bits)) {
        return bits & 0x8000; // Preserve the sign bit
    }
    return bits;
}

// Apply FTZ (Flush To Zero)
uint16_t apply_ftz(uint16_t bits) {
    if (is_subnormal(bits)) {
        return bits & 0x8000; // Preserve the sign bit
    }
    return bits;
}

// Check if FP16 value is NaN
bool is_nan(uint16_t bits) {
    uint16_t exponent = (bits >> 10) & 0x1F;
    uint16_t mantissa = bits & 0x3FF;
    return exponent == 0x1F && mantissa != 0;
}

// Canonicalize NaN
uint16_t canonicalize_nan(uint16_t bits) {
    if (is_nan(bits)) {
        return 0x7E00; // Canonical NaN
    }
    return bits;
}

// Normalize zero
uint16_t normalize_zero(uint16_t bits) {
    if ((bits & 0x7FFF) == 0) {
        return 0x0000; // Normalize to positive zero
    }
    return bits;
}

// FP16 hardware-like multiplication
uint16_t fp16_mul_hw(uint16_t a_bits, uint16_t b_bits) {
    uint16_t a_daz = apply_daz(a_bits);
    uint16_t b_daz = apply_daz(b_bits);

    float a_val = fp16_from_bits(a_daz);
    float b_val = fp16_from_bits(b_daz);

    float prod = a_val * b_val;
    uint16_t prod_bits = bits_from_fp16(prod);

    prod_bits = apply_ftz(prod_bits);
    prod_bits = canonicalize_nan(prod_bits);

    return prod_bits;
}

// FP16 hardware-like addition
uint16_t fp16_add_hw(uint16_t a_bits, uint16_t b_bits) {
    uint16_t a_daz = apply_daz(a_bits);
    uint16_t b_daz = apply_daz(b_bits);

    float a_val = fp16_from_bits(a_daz);
    float b_val = fp16_from_bits(b_daz);

    float sum = a_val + b_val;
    uint16_t sum_bits = bits_from_fp16(sum);

    sum_bits = apply_ftz(sum_bits);
    sum_bits = canonicalize_nan(sum_bits);

    return sum_bits;
}

// Generate random FP16 value within the fp16 exponent of specified exponent range
// i.e. for max_exponent = 3, the random value will be in the range of [-8, 8] with random decimal part
uint16_t random_fp16(int max_exponent)
{
    // Clamp parameter into safe fp16-normal range
    if (max_exponent < 1)  max_exponent = 1;
    if (max_exponent > 31) max_exponent = 31;

    uint16_t sign = std::rand() % 2; // Random sign bit
    uint16_t exponent = std::rand() % (max_exponent + 1);
    uint16_t mantissa = std::rand() % 0x400; // Random mantissa (10 bits for fp16)

    return (sign << 15) | (exponent << 10) | mantissa;
}

// Generates a random matrix of fp16
std::vector<std::vector<uint16_t>> generate_random_matrix_fp16(int rows, int cols, int max_exponent)
{
    std::vector<std::vector<uint16_t>> matrix(rows, std::vector<uint16_t>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = random_fp16(max_exponent);
        }
    }
    return matrix;
}
