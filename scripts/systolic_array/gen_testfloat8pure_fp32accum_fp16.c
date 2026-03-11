/*
 * 8-input FP16 adder test vector generator using Berkeley SoftFloat.
 *
 * single rounding version 
 *
 * Build:
    gcc -O2 -I ~/berkeley-softfloat-3/source/include -I ~/berkeley-testfloat-3/build/Linux-x86_64-GCC  gen_testfloat8pure_fp32accum_fp16.c  ~/berkeley-softfloat-3/build/Linux-x86_64-GCC/softfloat.a -o gen_testfloat8pure_fp32accum_fp16
 *
 * Usage:
 * ./gen_testfloat8pure [options] > testfloat_cases_8_pure.csv
 *
 * Options:
 * -n COUNT     Number of test cases (default: 1000000)
 * --no-daz     Disable DAZ
 * --no-ftz     Disable FTZ
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "softfloat.h"


static int ENABLE_DAZ = 1;  /* <<< TOGGLE DAZ HERE: 1 = flush subnormal inputs to +/-0 */
static int ENABLE_FTZ = 1;  /* <<< TOGGLE FTZ HERE: 1 = flush subnormal outputs to +/-0 */

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

/* FP16 helpers */
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

/* DAZ: flush subnormal input to signed zero */
static uint16_t apply_daz_16(uint16_t bits) {
    if (ENABLE_DAZ && is_subnormal_f16(bits))
        return bits & 0x8000;
    return bits;
}

/* FTZ: flush subnormal result to signed zero */
static uint16_t apply_ftz_16(uint16_t bits) {
    if (ENABLE_FTZ && is_subnormal_f16(bits))
        return bits & 0x8000;
    return bits;
}

static uint32_t canonicalize_nan(uint32_t bits) {
    if (is_nan_f32(bits))
        return 0x7FC00000; // Standard QNaN
    return bits;
}

/* Canonicalize NaN to 0x7E00 (positive quiet NaN) */
static uint16_t canonicalize_nan_16(uint16_t bits) {
    if (is_nan_f16(bits))
        return 0x7E00;
    return bits;
}

/*
 * this should be single rounding so pure a + b + c + d + e + f + g + h
 * convert all inputs to FP64, sums in FP64
 * then converts back to FP16 (single rounding point).
 */
static uint16_t true_8input_add(uint16_t a_bits, uint16_t b_bits,
                                uint16_t c_bits, uint16_t d_bits,
                                uint16_t e_bits, uint16_t f_bits,
                                uint16_t g_bits, uint16_t h_bits) {
    float16_t a16, b16, c16, d16, e16, f16, g16, h16;
    float64_t a64, b64, c64, d64, e64, f64, g64, h64, sum; 
    float16_t result;

    a16.v = a_bits; b16.v = b_bits; c16.v = c_bits; d16.v = d_bits;
    e16.v = e_bits; f16.v = f_bits; g16.v = g_bits; h16.v = h_bits;

    softfloat_roundingMode = softfloat_round_near_even;
    softfloat_exceptionFlags = 0;

    if (is_nan_f16(a16.v) || is_nan_f16(b16.v) ||
        is_nan_f16(c16.v) || is_nan_f16(d16.v) ||
        is_nan_f16(e16.v) || is_nan_f16(f16.v) ||
        is_nan_f16(g16.v) || is_nan_f16(h16.v))
        return 0x7E00; // Canonical QNaN in FP16

    a16.v = apply_daz_16(a_bits); b16.v = apply_daz_16(b_bits);
    c16.v = apply_daz_16(c_bits); d16.v = apply_daz_16(d_bits);
    e16.v = apply_daz_16(e_bits); f16.v = apply_daz_16(f_bits);
    g16.v = apply_daz_16(g_bits); h16.v = apply_daz_16(h_bits);

    /* convert to FP64 for massive precision headroom during accumulation */
    a64 = f16_to_f64(a16); b64 = f16_to_f64(b16);
    c64 = f16_to_f64(c16); d64 = f16_to_f64(d16);
    e64 = f16_to_f64(e16); f64 = f16_to_f64(f16);
    g64 = f16_to_f64(g16); h64 = f16_to_f64(h16);

    /* sum in fp64 */
    sum = f64_add(a64, b64);
    sum = f64_add(sum, c64);
    sum = f64_add(sum, d64);
    sum = f64_add(sum, e64);
    sum = f64_add(sum, f64);
    sum = f64_add(sum, g64);
    sum = f64_add(sum, h64);

    // fp64 to fp16 with round to nearest even
    result = f64_to_f16(sum);
    
    /*apply FTZ and canonicalize NaN */
    result.v = apply_ftz_16(result.v);
    result.v = canonicalize_nan_16(result.v);

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

    /* CSV header (updated for 8 inputs) */
    printf("a,b,c,d,e,f,g,h,expected\n");

    for (i = 0; i < n; i++) {
        uint16_t a = random_f16();
        uint16_t b = random_f16();
        uint16_t c = random_f16();
        uint16_t d = random_f16();
        uint16_t e = random_f16();
        uint16_t f = random_f16();
        uint16_t g = random_f16();
        uint16_t h = random_f16();

        /* True 8-input add: single rounding via FP64 */
        uint16_t result = true_8input_add(a, b, c, d, e, f, g, h);

        printf("%04x,%04x,%04x,%04x,%04x,%04x,%04x,%04x,%04x\n", a, b, c, d, e, f, g, h, result);
    }

    return 0;
}