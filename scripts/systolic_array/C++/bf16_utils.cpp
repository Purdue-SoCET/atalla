#include <cstdlib> // For std::srand and std::rand
#include <cstdint>
#include <cmath>
#include <bitset>
#include <vector>
#include "bf16_utils.h"
extern "C" {
    #include "softfloat.h"
    }
// Generate random BF16 bits
uint16_t random_bf16_bits() {
    return static_cast<uint16_t>(std::rand() % 0x10000); // Random 16-bit value
}

// Check if BF16 value is subnormal
static bool is_subnormal(uint16_t bits) {
    uint16_t exponent = (bits >> 7) & 0xFF;  // 8 exponent bits
    uint16_t mantissa = bits & 0x7F;         // 7 mantissa bits
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

static bool is_nan(uint16_t bits) {
    uint16_t exponent = (bits >> 7) & 0xFF;   // 8 exponent bits
    uint16_t mantissa = bits & 0x7F;          // 7 mantissa bits
    return exponent == 0xFF && mantissa != 0;
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

// BF16 hardware-like multiplication
uint16_t bf16_mul_hw(uint16_t a_bits, uint16_t b_bits) {
    bfloat16_t a, b, result;

    /* Apply DAZ */
    a.v = apply_daz(a_bits);
    b.v = apply_daz(b_bits);

    // Convert to fp32
    float32_t a_f32 = bf16_to_f32(a);
    float32_t b_f32 = bf16_to_f32(b);

    // calculate in fp32
    /* IEEE-754 mul via softfloat (round to nearest even) */
    softfloat_roundingMode = softfloat_round_near_even;
    // softfloat_detectTininess = softfloat_tininess_afterRounding;
    softfloat_exceptionFlags = 0;
    float32_t result_f32 = f32_mul(a_f32, b_f32);

    // Convert tp bf16
    result = f32_to_bf16(result_f32);

    /* Apply FTZ and canonicalize NaN */
    result.v = apply_ftz(result.v);
    result.v = canonicalize_nan(result.v);

    return result.v;
}

// BF16 hardware-like addition
uint16_t bf16_add_hw(uint16_t a_bits, uint16_t b_bits) {
    bfloat16_t a, b, result;

    /* Apply DAZ */
    a.v = apply_daz(a_bits);
    b.v = apply_daz(b_bits);

    // Convert to fp32
    float32_t a_f32 = bf16_to_f32(a);
    float32_t b_f32 = bf16_to_f32(b);

    // calculate in fp32
    /* IEEE-754 mul via softfloat (round to nearest even) */
    softfloat_roundingMode = softfloat_round_near_even;
    // softfloat_detectTininess = softfloat_tininess_afterRounding;
    softfloat_exceptionFlags = 0;
    float32_t result_f32 = f32_add(a_f32, b_f32);

    // Convert tp bf16
    result = f32_to_bf16(result_f32);

    /* Apply FTZ and canonicalize NaN */
    result.v = apply_ftz(result.v);
    result.v = canonicalize_nan(result.v);

    return result.v;
}

uint16_t bf16_4_input_add_hw(uint16_t a_bits, uint16_t b_bits, uint16_t c_bits, uint16_t d_bits) {
    bfloat16_t a16, b16, c16, d16;
    float32_t a32, b32, c32, d32, sum;
    bfloat16_t result;

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

    /* convert to BF64 */
    a32 = bf16_to_f32(a16);
    b32 = bf16_to_f32(b16);
    c32 = bf16_to_f32(c16);
    d32 = bf16_to_f32(d16);

    /* sum in bf64 */
    sum = f32_add(a32, b32);
    sum = f32_add(sum, c32);
    sum = f32_add(sum, d32);

    /* single rounding: BF64 -> BF16 */
    result = f32_to_bf16(sum);

    /*apply FTZ and canonicalize NaN */
    result.v = apply_ftz(result.v);
    result.v = canonicalize_nan(result.v);

    return result.v;
}

// Generate random BF16 value within the bf16 exponent of specified exponent range
// i.e. for max_exponent = 3, the random value will be in the range of [-8, 8] with random decimal part
uint16_t random_bf16(int min_exponent, int max_exponent)
{
    // Clamp parameters into safe BF16 exponent range (8-bit exponent: 0..255)
    if (min_exponent < 0)   min_exponent = 0;
    if (min_exponent > 255) min_exponent = 255;
    if (max_exponent < 0)   max_exponent = 0;
    if (max_exponent > 255) max_exponent = 255;
    if (min_exponent > max_exponent) min_exponent = max_exponent;

    uint16_t sign = std::rand() % 2; // Random sign bit
    uint16_t exponent = min_exponent + (std::rand() % (max_exponent - min_exponent + 1));
    uint16_t mantissa = std::rand() % 0x80; // 7-bit mantissa for BF16

    return (sign << 15) | (exponent << 7) | mantissa;
}

// Generates a random matrix of bf16
std::vector<std::vector<uint16_t>> generate_random_matrix_bf16(int rows, int cols, int min_exponent, int max_exponent)
{
    std::vector<std::vector<uint16_t>> matrix(rows, std::vector<uint16_t>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = random_bf16(min_exponent, max_exponent);
        }
    }
    return matrix;
}
