#include <cstdlib> // For std::srand and std::rand
#include <cstdint>
#include <cmath>
#include <bitset>
#include <vector>
#include "fp16_utils.h"
extern "C" {
    #include "softfloat.h"
    }
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
static bool is_subnormal(uint16_t bits) {
    uint16_t exponent = (bits >> 10) & 0x1F;
    uint16_t mantissa = bits & 0x3FF;
    return exponent == 0 && mantissa != 0;
}

// Apply DAZ (Denormals Are Zero)
static uint16_t apply_daz(uint16_t bits) {
    if (is_subnormal(bits)) {
        return bits & 0x8000; // Preserve the sign bit
    }
    return bits;
}

// Apply FTZ (Flush To Zero)
static uint16_t apply_ftz(uint16_t bits) {
    if (is_subnormal(bits)) {
        return bits & 0x8000; // Preserve the sign bit
    }
    return bits;
}

// Check if FP16 value is NaN
static bool is_nan(uint16_t bits) {
    uint16_t exponent = (bits >> 10) & 0x1F;
    uint16_t mantissa = bits & 0x3FF;
    return exponent == 0x1F && mantissa != 0;
}

// Canonicalize NaN
static uint16_t canonicalize_nan(uint16_t bits) {
    if (is_nan(bits)) {
        return 0x7E00; // Canonical NaN
    }
    return bits;
}

// Normalize zero
static uint16_t normalize_zero(uint16_t bits) {
    if ((bits & 0x7FFF) == 0) {
        return 0x0000; // Normalize to positive zero
    }
    return bits;
}

// FP16 hardware-like multiplication
uint16_t fp16_mul_hw(uint16_t a_bits, uint16_t b_bits) {
    float16_t a, b, result;

    /* Apply DAZ */
    a.v = apply_daz(a_bits);
    b.v = apply_daz(b_bits);

    /* IEEE-754 mul via softfloat (round to nearest even) */
    softfloat_roundingMode = softfloat_round_near_even;
    softfloat_exceptionFlags = 0;
    result = f16_mul(a, b);

    /* Apply FTZ and canonicalize NaN */
    result.v = apply_ftz(result.v);
    result.v = canonicalize_nan(result.v);

    return result.v;
}

// FP16 hardware-like addition
uint16_t fp16_add_hw(uint16_t a_bits, uint16_t b_bits) {
    float16_t a, b, result;

    /* Apply DAZ */
    a.v = apply_daz(a_bits);
    b.v = apply_daz(b_bits);

    /* IEEE-754 add via softfloat (round to nearest even) */
    softfloat_roundingMode = softfloat_round_near_even;
    softfloat_exceptionFlags = 0;
    result = f16_add(a, b);

    /* Apply FTZ and canonicalize NaN */
    result.v = apply_ftz(result.v);
    result.v = canonicalize_nan(result.v);

    return result.v;
}

uint16_t fp16_4_input_add_hw(uint16_t a_bits, uint16_t b_bits, uint16_t c_bits, uint16_t d_bits) {
    float16_t a16, b16, c16, d16;
    float64_t a64, b64, c64, d64, sum;
    float16_t result;

    /* Apply DAZ to inputs */
    a16.v = apply_daz(a_bits);
    b16.v = apply_daz(b_bits);
    c16.v = apply_daz(c_bits);
    d16.v = apply_daz(d_bits);

    /* Check for NaN inputs — propagate immediately */
    if (is_nan(a16.v) || is_nan(b16.v) ||
        is_nan(c16.v) || is_nan(d16.v))
        return 0x7E00;

    softfloat_roundingMode = softfloat_round_near_even;
    softfloat_exceptionFlags = 0;

    /* convert to FP64 */
    a64 = f16_to_f64(a16);
    b64 = f16_to_f64(b16);
    c64 = f16_to_f64(c16);
    d64 = f16_to_f64(d16);

    /* sum in fp64 */
    sum = f64_add(a64, b64);
    sum = f64_add(sum, c64);
    sum = f64_add(sum, d64);

    /* single rounding: FP64 -> FP16 */
    result = f64_to_f16(sum);

    /*apply FTZ and canonicalize NaN */
    result.v = apply_ftz(result.v);
    result.v = canonicalize_nan(result.v);

    return result.v;
}

// Generate random FP16 value within the fp16 exponent of specified exponent range [min_exponent, max_exponent]
// i.e. for min_exponent = 1, max_exponent = 3, the random exponent will be in [1, 3]
uint16_t random_fp16(int min_exponent, int max_exponent)
{
    // Clamp parameters into safe fp16-normal range
    if (min_exponent < 0)  min_exponent = 0;
    if (min_exponent > 31) min_exponent = 31;
    if (max_exponent < 0)  max_exponent = 0;
    if (max_exponent > 31) max_exponent = 31;
    if (min_exponent > max_exponent) min_exponent = max_exponent;

    uint16_t sign = std::rand() % 2; // Random sign bit
    uint16_t exponent = min_exponent + std::rand() % (max_exponent - min_exponent + 1);
    uint16_t mantissa = std::rand() % 0x400; // Random mantissa (10 bits for fp16)

    return (sign << 15) | (exponent << 10) | mantissa;
}

// Generates a random matrix of fp16
std::vector<std::vector<uint16_t>> generate_random_matrix_fp16(int rows, int cols, int min_exponent, int max_exponent)
{
    std::vector<std::vector<uint16_t>> matrix(rows, std::vector<uint16_t>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = random_fp16(min_exponent, max_exponent);
        }
    }
    return matrix;
}
