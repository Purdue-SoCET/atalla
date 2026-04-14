/*
 * 4-input BF16 adder test vector generator using Berkeley SoftFloat.
 *
 * single rounding version 
 *
 * Build:
    gcc -O2 -I ~/berkeley-softfloat-3/source/include \
        -I ~/berkeley-testfloat-3/build/Linux-x86_64-GCC \
        gen_drift_test.c \
        ~/berkeley-softfloat-3/build/Linux-x86_64-GCC/softfloat.a \
        -o gen_drift_test
 *
 * Usage:
 *   ./gen_drift_test [options] > testfloat_drift_test.csv
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

/* BF16 helpers */
static int is_subnormal_bf16(uint16_t bits) {
    uint16_t exp = (bits >> 7) & 0xFF;
    uint16_t man = bits & 0x7F;
    return (exp == 0) && (man != 0);
}

static int is_nan_bf16(uint16_t bits) {
    uint16_t exp = (bits >> 7) & 0xFF;
    uint16_t man = bits & 0x7F;
    return (exp == 0xFF) && (man != 0);
}

/* DAZ: flush subnormal input to signed zero */
static uint16_t apply_daz(uint16_t bits) {
    if (ENABLE_DAZ && is_subnormal_bf16(bits))
        return bits & 0x8000;
    return bits;
}

/* FTZ: flush subnormal result to signed zero */
static uint16_t apply_ftz(uint16_t bits) {
    if (ENABLE_FTZ && is_subnormal_bf16(bits))
        return bits & 0x8000;
    return bits;
}

/* Canonicalize NaN to 0x7E00 (positive quiet NaN) */
static uint16_t canonicalize_nan(uint16_t bits) {
    if (is_nan_bf16(bits))
        return 0x7FC0;
    return bits;
}

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
static uint32_t apply_daz32(uint32_t bits) {
    if (ENABLE_DAZ && is_subnormal_f32(bits))
        return bits & 0x80000000; // Preserve sign, clear magnitude
    return bits;
}

/* FTZ: Flush To Zero (Output) */
static uint32_t apply_ftz32(uint32_t bits) {
    if (ENABLE_FTZ && is_subnormal_f32(bits))
        return bits & 0x80000000;
    return bits;
}

/* Canonicalize NaN to a standard quiet NaN pattern */
static uint32_t canonicalize_nan32(uint32_t bits) {
    if (is_nan_f32(bits))
        return 0x7FC00000; // Standard QNaN
    return bits;
}

/*
 * this should be single rounding so pure a + b + c + d 
 * convert all inputs to FP32, sums in FP32
 * then converts back to BF16 (single rounding point).
 */
static uint16_t true_32input_tree_add_fp64(uint16_t *inputs) {
    bfloat16_t a16, b16, c16, d16;
    float32_t a32, b32, c32, d32;
    float32_t sum;
    bfloat16_t result;

    float32_t stage1[8];
    float32_t stage2[2];
    
    softfloat_roundingMode = softfloat_round_near_even; 
    for (int i = 0; i < 8; i++) {
        a16.v = apply_daz(inputs[i*4]);
        b16.v = apply_daz(inputs[i*4 + 1]);
        c16.v = apply_daz(inputs[i*4 + 2]);
        d16.v = apply_daz(inputs[i*4 + 3]);

        /* Check for NaN inputs — propagate immediately */
        if (is_nan_bf16(a16.v) || is_nan_bf16(b16.v) ||
            is_nan_bf16(c16.v) || is_nan_bf16(d16.v))
            return 0x7FC0;

        softfloat_exceptionFlags = 0;

        /* convert to FP32 */
        a32 = bf16_to_f32(a16);
        b32 = bf16_to_f32(b16);
        c32 = bf16_to_f32(c16);
        d32 = bf16_to_f32(d16);

        /* sum in fp32 */
        sum = f32_add(a32, b32);
        sum = f32_add(sum, c32);
        sum = f32_add(sum, d32);

        sum.v = apply_ftz32(sum.v);
        sum.v = canonicalize_nan32(sum.v);

        stage1[i] = sum;
    }

    for (int i = 0; i < 2; i++) {
        float32_t s1 = stage1[i*4];
        float32_t s2 = stage1[i*4 + 1];
        float32_t s3 = stage1[i*4 + 2];
        float32_t s4 = stage1[i*4 + 3];

        /* Check for NaN inputs — propagate immediately */
        if (is_nan_f32(s1.v) || is_nan_f32(s2.v) ||
            is_nan_f32(s3.v) || is_nan_f32(s4.v))
            return 0x7FC0;

        softfloat_exceptionFlags = 0;

        float64_t s1_64 = f32_to_f64(s1);
        float64_t s2_64 = f32_to_f64(s2);
        float64_t s3_64 = f32_to_f64(s3);
        float64_t s4_64 = f32_to_f64(s4);

        float64_t sum64 = f64_add(s1_64, s2_64);
        sum64 = f64_add(sum64, s3_64);
        sum64 = f64_add(sum64, s4_64);

        sum = f64_to_f32(sum64);

        sum.v = apply_ftz32(sum.v);
        sum.v = canonicalize_nan32(sum.v);

        stage2[i] = sum;
    }

    float32_t s1 = stage2[0];
    float32_t s2 = stage2[1];

    /* Check for NaN inputs — propagate immediately */
    if (is_nan_f32(s1.v) || is_nan_f32(s2.v))
        return 0x7FC0;

    softfloat_exceptionFlags = 0;

    float64_t s1_64 = f32_to_f64(s1);
    float64_t s2_64 = f32_to_f64(s2);

    float64_t sum64 = f64_add(s1_64, s2_64);


    sum = f64_to_f32(sum64);
    
    softfloat_roundingMode = softfloat_round_near_even;
    /* Apply DAZ to inputs */
    /* single rounding: FP32 -> BF16 */
    result = f32_to_bf16(sum);

    /*apply FTZ and canonicalize NaN */
    result.v = apply_ftz(result.v);
    result.v = canonicalize_nan(result.v);

    return result.v;
}

static uint16_t true_32input_tree_add(uint16_t *inputs) {
    bfloat16_t a16, b16, c16, d16;
    float32_t a32, b32, c32, d32;
    float32_t sum;
    bfloat16_t result;

    float32_t stage1[8];
    float32_t stage2[2];
    softfloat_roundingMode = softfloat_round_near_even;

    // --- STAGE 1: 32 BF16 -> 8 FP32 ---
    for (int i = 0; i < 8; i++) {
        a16.v = apply_daz(inputs[i*4]);
        b16.v = apply_daz(inputs[i*4 + 1]);
        c16.v = apply_daz(inputs[i*4 + 2]);
        d16.v = apply_daz(inputs[i*4 + 3]);

        if (is_nan_bf16(a16.v) || is_nan_bf16(b16.v) ||
            is_nan_bf16(c16.v) || is_nan_bf16(d16.v))
            return 0x7FC0;

        // Using Truncation to match RTL with no GRS/Precision bits
        softfloat_exceptionFlags = 0;

        a32 = bf16_to_f32(a16);
        b32 = bf16_to_f32(b16);
        c32 = bf16_to_f32(c16);
        d32 = bf16_to_f32(d16);

        // Pure FP32 accumulation
        sum = f32_add(a32, b32);
        sum = f32_add(sum, c32);
        sum = f32_add(sum, d32);

        sum.v = apply_ftz32(sum.v);
        sum.v = canonicalize_nan32(sum.v);

        stage1[i] = sum;
    }

    // --- STAGE 2: 8 FP32 -> 2 FP32 ---
    for (int i = 0; i < 2; i++) {
        float32_t s1 = stage1[i*4];
        float32_t s2 = stage1[i*4 + 1];
        float32_t s3 = stage1[i*4 + 2];
        float32_t s4 = stage1[i*4 + 3];

        if (is_nan_f32(s1.v) || is_nan_f32(s2.v) ||
            is_nan_f32(s3.v) || is_nan_f32(s4.v))
            return 0x7FC0;

        softfloat_exceptionFlags = 0;

        // REMOVED FP64: Summing directly in FP32 to match hardware saturation
        sum = f32_add(s1, s2);
        sum = f32_add(sum, s3);
        sum = f32_add(sum, s4);

        sum.v = apply_ftz32(sum.v);
        sum.v = canonicalize_nan32(sum.v);

        stage2[i] = sum;
    }

    // --- STAGE 3: Final 2 FP32 -> 1 FP32 ---
    float32_t final_s1 = stage2[0];
    float32_t final_s2 = stage2[1];

    if (is_nan_f32(final_s1.v) || is_nan_f32(final_s2.v))
        return 0x7FC0;

    softfloat_exceptionFlags = 0;

    // Final FP32 sum
    float32_t final_sum_f32 = f32_add(final_s1, final_s2);

    // --- REDUCTION: FP32 -> BF16 ---
    // If you plan to add Round-to-Nearest-Even to your RTL Reducer later,
    // change this to softfloat_round_near_even.
    softfloat_roundingMode = softfloat_round_near_even;
    
    result = f32_to_bf16(final_sum_f32);

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

static uint16_t random_bf16(void) {
    return (uint16_t)(xorshift64() & 0xFFFF);
}

static uint16_t random_bf16_constrained(void) {
    uint16_t sign = (xorshift64() & 0x1) << 15;
    
    // Unbiased range: 0 to 19
    // Biased range: (0 + 127) to (19 + 127) = 127 to 146
    // We use % 20 to get 20 possible values (0 through 19)
    uint16_t exp = (127 + (xorshift64() % 20)) << 7; 
    
    uint16_t man = xorshift64() & 0x7F;
    return sign | exp | man;
}

int main(int argc, char *argv[]) {
    int n = 10000;
    int fp64_accum = 0;
    int i;

    /* Parse args */
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
            n = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--no-daz") == 0) {
            ENABLE_DAZ = 0;
        } else if (strcmp(argv[i], "--no-ftz") == 0) {
            ENABLE_FTZ = 0;
        } else if (strcmp(argv[i], "--fp64accum") == 0) {
            fp64_accum = 1;
        }
    }

    /* Seed PRNG */
    rng_state = 0x123456789ABCDEF0ULL ^ (uint64_t)time(NULL);

    /* CSV header */
    printf("i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15,i16,i17,i18,i19,i20,i21,i22,i23,i24,i25,i26,i27,i28,i29,i30,i31,expected\n");

    uint16_t inputs[32];

    for (i = 0; i < n; i++) {
        for (int j = 0; j < 32; j++) {
            inputs[j] = random_bf16_constrained();
            printf("%04x", inputs[j]);
            if (j < 31) printf(",");
        }

        uint16_t result; 
        /* True 4-input add: single rounding via FP32 */
        if (fp64_accum) {
            result = true_32input_tree_add_fp64(inputs);
        } else {
            result = true_32input_tree_add(inputs);
        } 
        printf(",%04x\n", result);
    }

    return 0;
}
