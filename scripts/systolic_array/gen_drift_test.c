/*
 * 4-input BF16 adder test vector generator using Berkeley SoftFloat.
 *
 * single rounding version (ML Workload Bounded Distribution)
 *
 * Build:
    gcc -O2 -I ~/berkeley-softfloat-3/source/include \
        -I ~/berkeley-testfloat-3/build/Linux-x86_64-GCC \
        gen_drift_test.c \
        ~/berkeley-softfloat-3/build/Linux-x86_64-GCC/softfloat.a \
        -lm \
        -o gen_drift_test
 *
 * Usage:
 * ./gen_drift_test [options] > testfloat_drift_test.csv
 *
 * Options:
 * -n COUNT     Number of test cases (default: 10000)
 * --no-daz     Disable DAZ
 * --no-ftz     Disable FTZ
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <math.h>
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

/* * FP64 Accumulation Path (Strict reference testing)
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

        if (is_nan_bf16(a16.v) || is_nan_bf16(b16.v) ||
            is_nan_bf16(c16.v) || is_nan_bf16(d16.v))
            return 0x7FC0;

        softfloat_exceptionFlags = 0;

        a32 = bf16_to_f32(a16);
        b32 = bf16_to_f32(b16);
        c32 = bf16_to_f32(c16);
        d32 = bf16_to_f32(d16);

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

    if (is_nan_f32(s1.v) || is_nan_f32(s2.v))
        return 0x7FC0;

    softfloat_exceptionFlags = 0;

    float64_t s1_64 = f32_to_f64(s1);
    float64_t s2_64 = f32_to_f64(s2);

    float64_t sum64 = f64_add(s1_64, s2_64);

    sum = f64_to_f32(sum64);
    
    softfloat_roundingMode = softfloat_round_near_even;
    result = f32_to_bf16(sum);

    result.v = apply_ftz(result.v);
    result.v = canonicalize_nan(result.v);

    return result.v;
}

/*
 * FP32 Accumulation Path (Matches standard hardware tree)
 */
static uint16_t true_32input_tree_add(uint16_t *inputs) {
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

        if (is_nan_bf16(a16.v) || is_nan_bf16(b16.v) ||
            is_nan_bf16(c16.v) || is_nan_bf16(d16.v))
            return 0x7FC0;

        softfloat_exceptionFlags = 0;

        a32 = bf16_to_f32(a16);
        b32 = bf16_to_f32(b16);
        c32 = bf16_to_f32(c16);
        d32 = bf16_to_f32(d16);

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

        if (is_nan_f32(s1.v) || is_nan_f32(s2.v) ||
            is_nan_f32(s3.v) || is_nan_f32(s4.v))
            return 0x7FC0;

        softfloat_exceptionFlags = 0;

        sum = f32_add(s1, s2);
        sum = f32_add(sum, s3);
        sum = f32_add(sum, s4);

        sum.v = apply_ftz32(sum.v);
        sum.v = canonicalize_nan32(sum.v);

        stage2[i] = sum;
    }

    float32_t final_s1 = stage2[0];
    float32_t final_s2 = stage2[1];

    if (is_nan_f32(final_s1.v) || is_nan_f32(final_s2.v))
        return 0x7FC0;

    softfloat_exceptionFlags = 0;

    float32_t final_sum_f32 = f32_add(final_s1, final_s2);

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

/* Uniform double between 0.0 and 1.0 */
static double get_uniform(void) {
    return (double)(xorshift64() & 0xFFFFFF) / (double)0xFFFFFF;
}

/* Box-Muller transform for Normal Distribution */
static double generate_gaussian(double mean, double stddev) {
    static double n2 = 0.0;
    static int n2_cached = 0;
    
    if (!n2_cached) {
        double x, y, r;
        do {
            x = 2.0 * get_uniform() - 1.0;
            y = 2.0 * get_uniform() - 1.0;
            r = x * x + y * y;
        } while (r == 0.0 || r > 1.0);
        
        double d = sqrt(-2.0 * log(r) / r);
        double n1 = x * d;
        n2 = y * d;
        n2_cached = 1;
        return n1 * stddev + mean;
    } else {
        n2_cached = 0;
        return n2 * stddev + mean;
    }
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

/* Generates a strict ML workload constrained value */
static uint16_t generate_ml_workload_bf16(void) {
    // 1. Generate Weights (Mean=0.0, StdDev=0.05)
    double weight = generate_gaussian(0.0, 0.05);

    // 2. Generate Activations (Mean=0.0, StdDev=1.0)
    double activation = generate_gaussian(0.0, 1.0);

    // 3. Sparsity (Simulate ReLU by zeroing negatives)
    // if (activation < 0.0) {
    //     activation = 0.0;
    // }

    // 4. Clamping (Simulate bounded dynamic range)
    if (activation > 10.0) {
        activation = 10.0;
    }

    // 5. Product for the systolic lane
    double product = weight * activation;

    // 6. Cast safely to BF16
    union { float f; uint32_t i; } u;
    u.f = (float)product;
    
    float32_t f32_val;
    f32_val.v = u.i;

    uint_fast8_t saved_rm = softfloat_roundingMode;
    softfloat_roundingMode = softfloat_round_near_even;
    bfloat16_t bf16_val = f32_to_bf16(f32_val);
    softfloat_roundingMode = saved_rm;

    return bf16_val.v;
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
            // Replaced the random uniform generator with the ML bounds
            inputs[j] = random_bf16_constrained();
            printf("%04x", inputs[j]);
            if (j < 31) printf(",");
        }

        uint16_t result; 
        if (fp64_accum) {
            result = true_32input_tree_add_fp64(inputs);
        } else {
            result = true_32input_tree_add(inputs);
        } 
        printf(",%04x\n", result);
    }

    return 0;
}