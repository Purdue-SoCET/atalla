/*
 * FP16 multiplier test vector generator using Berkeley SoftFloat.
 *
 * Computes: result = a * b using IEEE-754 compliant softfloat,
 * with configurable DAZ and FTZ.
 *
 * Build:
 *   gcc -O2 -I ../berkeley-softfloat-3/source/include \
 *       -I ../berkeley-softfloat-3/build/Linux-x86_64-GCC \
 *       gen_testfloat_mul.c \
 *       ../berkeley-softfloat-3/build/Linux-x86_64-GCC/softfloat.a \
 *       -o gen_testfloat_mul
 *
 * Usage:
 *   ./gen_testfloat_mul [options] > testfloat_cases_mul.csv
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

static uint16_t apply_daz(uint16_t bits) {
    if (ENABLE_DAZ && is_subnormal_f16(bits))
        return bits & 0x8000;
    return bits;
}

static uint16_t apply_ftz(uint16_t bits) {
    if (ENABLE_FTZ && is_subnormal_f16(bits))
        return bits & 0x8000;
    return bits;
}

static uint16_t canonicalize_nan(uint16_t bits) {
    if (is_nan_f16(bits))
        return 0x7E00;
    return bits;
}

static uint16_t hw_mul_f16(uint16_t a_bits, uint16_t b_bits) {
    float16_t a, b, result;

    a.v = apply_daz(a_bits);
    b.v = apply_daz(b_bits);

    softfloat_roundingMode = softfloat_round_near_even;
    softfloat_exceptionFlags = 0;
    result = f16_mul(a, b);

    result.v = apply_ftz(result.v);
    result.v = canonicalize_nan(result.v);

    return result.v;
}

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

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
            n = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--no-daz") == 0) {
            ENABLE_DAZ = 0;
        } else if (strcmp(argv[i], "--no-ftz") == 0) {
            ENABLE_FTZ = 0;
        }
    }

    rng_state = 0x123456789ABCDEF0ULL ^ (uint64_t)time(NULL);

    printf("a,b,expected\n");

    for (i = 0; i < n; i++) {
        uint16_t a = random_f16();
        uint16_t b = random_f16();
        uint16_t result = hw_mul_f16(a, b);

        printf("%04x,%04x,%04x\n", a, b, result);
    }

    return 0;
}
