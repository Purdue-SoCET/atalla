/*
 * 4-input FP16 adder test vector generator using Berkeley SoftFloat.
 *
 * Build:
 *   gcc -O2 -I berkeley-softfloat-3/source/include \
 *       -I berkeley-testfloat-3/build/Linux-x86_64-GCC \
 *       gen_testfloat4.c \
 *       berkeley-softfloat-3/build/Linux-x86_64-GCC/softfloat.a \
 *       -o gen_testfloat4
 *
 * Usage:
 *   ./gen_testfloat4 [options] > testfloat_cases_4.csv
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

/* DAZ: flush subnormal input to signed zero */
static uint16_t apply_daz(uint16_t bits) {
    if (ENABLE_DAZ && is_subnormal_f16(bits))
        return bits & 0x8000;
    return bits;
}

/* FTZ: flush subnormal result to signed zero */
static uint16_t apply_ftz(uint16_t bits) {
    if (ENABLE_FTZ && is_subnormal_f16(bits))
        return bits & 0x8000;
    return bits;
}

/* Canonicalize NaN to 0x7E00 (positive quiet NaN) */
static uint16_t canonicalize_nan(uint16_t bits) {
    if (is_nan_f16(bits))
        return 0x7E00;
    return bits;
}

/* Compute a + b using softfloat with DAZ/FTZ */
static uint16_t hw_add_f16(uint16_t a_bits, uint16_t b_bits) {
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

        /* Tree: (a+b) + (c+d) */
        uint16_t ab = hw_add_f16(a, b);
        uint16_t cd = hw_add_f16(c, d);
        uint16_t result = hw_add_f16(ab, cd);

        printf("%04x,%04x,%04x,%04x,%04x\n", a, b, c, d, result);
    }

    return 0;
}
