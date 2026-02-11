/*
 * 4-input FP16 adder test vector generator using Berkeley SoftFloat.
 *
 * single rounding version 
 *
 * Build:
 *   gcc -O2 -I berkeley-softfloat-3/source/include \
 *       -I berkeley-testfloat-3/build/Linux-x86_64-GCC \
 *       gen_testfloat4pure.c \
 *       berkeley-softfloat-3/build/Linux-x86_64-GCC/softfloat.a \
 *       -o gen_testfloat4pure
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

/*
 * this should be single rounding so pure a + b + c + d 
 * convert all inputs to FP64, sums in FP64
 * then converts back to FP16 (single rounding point).
 */
static uint16_t true_4input_add(uint16_t a_bits, uint16_t b_bits,
                                uint16_t c_bits, uint16_t d_bits) {
    float16_t a16, b16, c16, d16;
    float64_t a64, b64, c64, d64, sum;
    float16_t result;

    /* Apply DAZ to inputs */
    a16.v = apply_daz(a_bits);
    b16.v = apply_daz(b_bits);
    c16.v = apply_daz(c_bits);
    d16.v = apply_daz(d_bits);

    /* Check for NaN inputs — propagate immediately */
    if (is_nan_f16(a16.v) || is_nan_f16(b16.v) ||
        is_nan_f16(c16.v) || is_nan_f16(d16.v))
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
        uint16_t result = true_4input_add(a, b, c, d);

        printf("%04x,%04x,%04x,%04x,%04x\n", a, b, c, d, result);
    }

    return 0;
}
