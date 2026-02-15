/*
 * 4-input FP32 adder test vector generator using Berkeley SoftFloat.
 *
 * single rounding version 
 *
 * Build:
    gcc -O2 -I ~/berkeley-softfloat-3/source/include \
        -I ~/berkeley-testfloat-3/build/Linux-x86_64-GCC \
        gen_testfloat4pure_fp32.c \
        ~/berkeley-softfloat-3/build/Linux-x86_64-GCC/softfloat.a \
        -o gen_testfloat4pure_fp32
 *
 * Usage:
 *   ./gen_testfloat4pure_fp32 [options] > testfloat_cases_4_pure_fp32.csv
 *
 *   Options:
 *     -n COUNT     Number of test cases (default: 1000000)
 *     --no-daz     Disable DAZ
 *     --no-ftz     Disable FTZ
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "softfloat.h"

static int ENABLE_DAZ = 1; 
static int ENABLE_FTZ = 1; 

/* FP32 helpers */
static int is_subnormal_f32(uint32_t bits) {
    uint32_t exp = (bits >> 23) & 0xFF;
    uint32_t man = bits & 0x7FFFFF;
    return (exp == 0) && (man != 0);
}

static int is_nan_f32(uint32_t bits) {
    uint32_t exp = (bits >> 23) & 0xFF;
    uint32_t man = bits & 0x7FFFFF;
    return (exp == 0xFF) && (man != 0);
}

/* DAZ: Denormals Are Zero (Input) */
static uint32_t apply_daz(uint32_t bits) {
    if (ENABLE_DAZ && is_subnormal_f32(bits))
        return bits & 0x80000000; // Preserve sign, clear magnitude
    return bits;
}

/* FTZ: Flush To Zero (Output) */
static uint32_t apply_ftz(uint32_t bits) {
    if (ENABLE_FTZ && is_subnormal_f32(bits))
        return bits & 0x80000000;
    return bits;
}

/* Canonicalize NaN to a standard quiet NaN pattern */
static uint32_t canonicalize_nan(uint32_t bits) {
    if (is_nan_f32(bits))
        return 0x7FC00000; // Standard QNaN
    return bits;
}

/*
 * Performs (a + b + c + d) with single rounding.
 * Inputs are promoted to FP64, summed, and rounded once back to FP32.
 */
static uint32_t true_4input_add_f32(uint32_t a_bits, uint32_t b_bits,
                                   uint32_t c_bits, uint32_t d_bits) {
    float32_t a32, b32, c32, d32;
    float64_t a64, b64, c64, d64, sum;
    float32_t result;

    /* Apply DAZ */
    a32.v = apply_daz(a_bits);
    b32.v = apply_daz(b_bits);
    c32.v = apply_daz(c_bits);
    d32.v = apply_daz(d_bits);

    /* NaN Propagation */
    if (is_nan_f32(a32.v) || is_nan_f32(b32.v) ||
        is_nan_f32(c32.v) || is_nan_f32(d32.v))
        return 0x7FC00000;

    softfloat_roundingMode = softfloat_round_near_even;
    softfloat_exceptionFlags = 0;

    /* Promote to FP64 for infinite precision relative to FP32 */
    a64 = f32_to_f64(a32);
    b64 = f32_to_f64(b32);
    c64 = f32_to_f64(c32);
    d64 = f32_to_f64(d32);

    /* Summing in FP64 prevents intermediate rounding errors */
    sum = f64_add(a64, b64);
    sum = f64_add(sum, c64);
    sum = f64_add(sum, d64);

    /* Single rounding point: FP64 -> FP32 */
    result = f64_to_f32(sum);

    /* Apply FTZ and Canonicalize */
    result.v = apply_ftz(result.v);
    result.v = canonicalize_nan(result.v);

    return result.v;
}

static uint64_t rng_state = 0x123456789ABCDEF0ULL;
static uint64_t xorshift64(void) {
    uint64_t x = rng_state;
    x ^= x << 13; x ^= x >> 7; x ^= x << 17;
    return rng_state = x;
}

static uint32_t random_f32(void) {
    return (uint32_t)(xorshift64() & 0xFFFFFFFF);
}

static uint32_t random_f32_clustered(uint32_t reference_exponent) {
    uint32_t sign = (xorshift64() & 0x1);
    // Keep exponent within +/- 10 of the reference to force alignment shifts
    uint32_t exp = reference_exponent + (uint32_t)(xorshift64() % 20) - 10;
    uint32_t mantissa = (uint32_t)(xorshift64() & 0x7FFFFF);
    
    return (sign << 31) | (exp << 23) | mantissa;
}

int main(int argc, char *argv[]) {
    int n = 1000000;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) n = atoi(argv[++i]);
        else if (strcmp(argv[i], "--no-daz") == 0) ENABLE_DAZ = 0;
        else if (strcmp(argv[i], "--no-ftz") == 0) ENABLE_FTZ = 0;
    }

    rng_state ^= (uint64_t)time(NULL);
    printf("a,b,c,d,expected\n");

    for (int i = 0; i < n/4; i++) {
        uint32_t a = random_f32_clustered(0x40);
        uint32_t b = random_f32_clustered(0x40);
        uint32_t c = random_f32_clustered(0x40);
        uint32_t d = random_f32_clustered(0x40);

        uint32_t result = true_4input_add_f32(a, b, c, d);
        printf("%08x,%08x,%08x,%08x,%08x\n", a, b, c, d, result);
    }

    for (int i = 0; i < 3*n/4; i++) {
        uint32_t a = random_f32();
        uint32_t b = random_f32();
        uint32_t c = random_f32();
        uint32_t d = random_f32();

        uint32_t result = true_4input_add_f32(a, b, c, d);
        printf("%08x,%08x,%08x,%08x,%08x\n", a, b, c, d, result);
    }
    return 0;
}