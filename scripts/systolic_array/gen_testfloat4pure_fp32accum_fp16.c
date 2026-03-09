/*
 * 4-input FP16 adder test vector generator using Berkeley SoftFloat.
 *
 * single rounding version 
 *
 * Build:
    gcc -O2 -I ~/berkeley-softfloat-3/source/include         -I ~/berkeley-testfloat-3/build/Linux-x86_64-GCC         gen_testfloat4pure_fp32accum_fp16.c         ~/berkeley-softfloat-3/build/Linux-x86_64
    -GCC/softfloat.a         -o gen_testfloat4pure_fp32accum_fp16
 *
 * Usage:
 *   ./gen_testfloat4pure [options] > testfloat_cases_4_pure.csv
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


static int ENABLE_DAZ = 1;  /* <<< TOGGLE DAZ HERE: 1 = flush subnormal inputs to +/-0 */
static int ENABLE_FTZ = 1;  /* <<< TOGGLE FTZ HERE: 1 = flush subnormal outputs to +/-0 */

/* FP16 helpers */
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

static int is_subnormal_f16(uint16_t bits) {
    uint16_t exp = (bits >> 10) & 0x1F;
    uint16_t man = bits & 0x3FF;
    return (exp == 0) && (man != 0);
}

static int is_nan_f16(uint16_t bits) {
    uint16_t exp = (bits >> 10) & 0x1F;
    uint16_t man = bits & 0x3FF;
    return (exp == 0x1F) && (man != 0);
}

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


static uint32_t canonicalize_nan(uint32_t bits) {
    if (is_nan_f32(bits))
        return 0x7FC00000; // Standard QNaN
    return bits;
}

/*
 * this should be single rounding so pure a + b + c + d 
 * convert all inputs to FP32, sums in FP32
 * then converts back to FP16 (single rounding point).
 */
static uint32_t true_4input_add(uint16_t a_bits, uint16_t b_bits,
                                uint16_t c_bits, uint16_t d_bits) {
    float16_t a16, b16, c16, d16;
    float64_t a64, b64, c64, d64, sum;
    float32_t a32, b32, c32, d32; 
    float32_t result;

    a16.v = a_bits;
    b16.v = b_bits;
    c16.v = c_bits;
    d16.v = d_bits;

    softfloat_roundingMode = softfloat_round_minMag;
    softfloat_exceptionFlags = 0;

    if (is_nan_f16(a16.v) || is_nan_f16(b16.v) ||
        is_nan_f16(c16.v) || is_nan_f16(d16.v))
        return 0x7FC00000; // Canonical QNaN in FP32

    /* convert to FP32 */
    a32 = f16_to_f32(a16);
    b32 = f16_to_f32(b16);
    c32 = f16_to_f32(c16);
    d32 = f16_to_f32(d16);

    // Check DAZ and NaN
    a32.v = apply_daz(a32.v);
    b32.v = apply_daz(b32.v);
    c32.v = apply_daz(c32.v);
    d32.v = apply_daz(d32.v);

    // Convert to fp64
    a64 = f32_to_f64(a32);
    b64 = f32_to_f64(b32);
    c64 = f32_to_f64(c32);
    d64 = f32_to_f64(d32);

    /* sum in fp32 */
    sum = f64_add(a64, b64);
    sum = f64_add(sum, c64);
    sum = f64_add(sum, d64);

    // truncate to fp32 wihtout rounding
    result = f64_to_f32(sum);
    /*apply FTZ and canonicalize NaN */
    result.v = apply_ftz(result.v);
    result.v = canonicalize_nan(result.v);

    return result.v;
}

/* Simple xorshift64 PRNG */
static uint64_t rng_state = 0x123456789ABCDEF0ULL;

static uint64_t xorshift64(void) {
    uint64_t x = rng_state;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    rng_state = x;
    return x;
}

static uint16_t random_f16(void) {
    return (uint16_t)(xorshift64() & 0xFFFF);
}

int main(int argc, char *argv[]) {
    int n = 1000000;
    int i;

    /* Parse args */
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
            n = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--no-daz") == 0) {
            ENABLE_DAZ = 0;
        } else if (strcmp(argv[i], "--no-ftz") == 0) {
            ENABLE_FTZ = 0;
        }
    }

    /* Seed PRNG */
    rng_state = 0x123456789ABCDEF0ULL ^ (uint64_t)time(NULL);

    /* CSV header */
    printf("a,b,c,d,expected\n");

    for (i = 0; i < n; i++) {
        uint16_t a = random_f16();
        uint16_t b = random_f16();
        uint16_t c = random_f16();
        uint16_t d = random_f16();

        /* True 4-input add: single rounding via FP64 */
        uint32_t result = true_4input_add(a, b, c, d);

        printf("%04x,%04x,%04x,%04x,%08x\n", a, b, c, d, result);
    }

    return 0;
}
