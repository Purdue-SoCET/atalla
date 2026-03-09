#include <cstdlib> // For std::srand and std::rand
#include <cstdint>
#include <cmath>
#include <bitset>
#include <vector>
#include <iostream>
extern "C" {
    #include "softfloat.h"
    }
// Generate random FP32 bits
uint32_t random_fp32_bits() {
    return static_cast<uint32_t>(std::rand() % 0x100000000); // Random 32-bit value
}


// Check if FP32 value is subnormal
static bool is_subnormal(uint32_t bits) {
    uint32_t exponent = (bits >> 23) & 0xFF;
    uint32_t mantissa = bits & 0x7FFFFF;
    return exponent == 0 && mantissa != 0;
}

// Apply DAZ (Denormals Are Zero)
static uint32_t apply_daz(uint32_t bits) {
    if (is_subnormal(bits)) {
        return bits & 0x80000000; // Preserve the sign bit
    }
    return bits;
}

// Apply FTZ (Flush To Zero)
static uint32_t apply_ftz(uint32_t bits) {
    if (is_subnormal(bits)) {
        return bits & 0x80000000; // Preserve the sign bit
    }
    return bits;
}

// Check if FP32 value is NaN
static bool is_nan(uint32_t bits) {
    uint32_t exponent = (bits >> 23) & 0xFF;
    uint32_t mantissa = bits & 0x7FFFFF;
    return exponent == 0xFF && mantissa != 0;
}

// Canonicalize NaN
static uint32_t canonicalize_nan(uint32_t bits) {
    if (is_nan(bits)) {
        return 0x7FC00000; // Canonical NaN
    }
    return bits;
}

// Normalize zero
static uint32_t normalize_zero(uint32_t bits) {
    if ((bits & 0x7FFFFFFF) == 0) {
        return 0x00000000; // Normalize to positive zero
    }
    return bits;
}

// FP32 hardware-like multiplication
uint32_t fp32_mul_hw(uint32_t a_bits, uint32_t b_bits) {
    float32_t a, b, result;

    /* Apply DAZ */
    a.v = apply_daz(a_bits);
    b.v = apply_daz(b_bits);

    /* IEEE-754 mul via softfloat (round to nearest even) */
    softfloat_roundingMode = softfloat_round_near_even;
    softfloat_exceptionFlags = 0;
    result = f32_mul(a, b);

    /* Apply FTZ and canonicalize NaN */
    result.v = apply_ftz(result.v);
    result.v = canonicalize_nan(result.v);

    return result.v;
}

// FP32 hardware-like addition
uint32_t fp32_add_hw(uint32_t a_bits, uint32_t b_bits) {
    float32_t a, b, result;

    /* Apply DAZ */
    a.v = apply_daz(a_bits);
    b.v = apply_daz(b_bits);

    /* IEEE-754 add via softfloat (round to nearest even) */
    softfloat_roundingMode = softfloat_round_near_even;
    softfloat_exceptionFlags = 0;
    result = f32_add(a, b);

    /* Apply FTZ and canonicalize NaN */
    result.v = apply_ftz(result.v);
    result.v = canonicalize_nan(result.v);

    return result.v;
}

uint32_t fp32_4_input_add_hw(uint32_t a_bits, uint32_t b_bits, uint32_t c_bits, uint32_t d_bits) {
    float32_t a32, b32, c32, d32;
    float64_t a64, b64, c64, d64, sum;
    float32_t result;

    /* Apply DAZ to inputs */
    a32.v = apply_daz(a_bits);
    b32.v = apply_daz(b_bits);
    c32.v = apply_daz(c_bits);
    d32.v = apply_daz(d_bits);

    /* Check for NaN inputs — propagate immediately */
    if (is_nan(a32.v) || is_nan(b32.v) ||
        is_nan(c32.v) || is_nan(d32.v))
        return 0x7FC00000;

    softfloat_roundingMode = softfloat_round_near_even;
    softfloat_exceptionFlags = 0;

    /* convert to FP64 */
    a64 = f32_to_f64(a32);
    b64 = f32_to_f64(b32);
    c64 = f32_to_f64(c32);
    d64 = f32_to_f64(d32);

    /* sum in fp64 */
    sum = f64_add(a64, b64);
    sum = f64_add(sum, c64);
    sum = f64_add(sum, d64);

    /* single rounding: FP64 -> FP32 */
    result = f64_to_f32(sum);

    /*apply FTZ and canonicalize NaN */
    result.v = apply_ftz(result.v);
    result.v = canonicalize_nan(result.v);

    return result.v;
}

uint32_t bf16_to_ui32(uint16_t bits)
{
    uint32_t value = bits;
    return value << 16;
}
