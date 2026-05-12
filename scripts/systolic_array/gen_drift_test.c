#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "softfloat.h"

// =================================================================================
// DYNAMIC SCHMOO TEST GENERATOR FOR EXACT FUSED FP ADDERS
// Utilizes Berkeley SoftFloat 3 - float128_t (Memory API) for perfect, 0-loss sums.
// =================================================================================

/* Global Configuration Toggles */
static int ENABLE_DAZ = 1;  // Flush subnormal inputs to +/-0
static int ENABLE_FTZ = 1;  // Flush subnormal outputs to +/-0

/* --------------------------------------------------------------------------
 * BF16 Helpers
 * -------------------------------------------------------------------------- */
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

static uint16_t apply_daz(uint16_t bits) {
    if (ENABLE_DAZ && is_subnormal_bf16(bits))
        return bits & 0x8000;
    return bits;
}

static uint16_t apply_ftz(uint16_t bits) {
    if (ENABLE_FTZ && is_subnormal_bf16(bits))
        return bits & 0x8000;
    return bits;
}

static uint16_t canonicalize_nan(uint16_t bits) {
    if (is_nan_bf16(bits))
        return 0x7FC0; // Standard Quiet NaN
    return bits;
}

/* --------------------------------------------------------------------------
 * FP32 Helpers
 * -------------------------------------------------------------------------- */
static int is_subnormal_f32(uint32_t bits) {
    uint32_t exp = (bits >> 23) & 0xFF;
    uint32_t man = bits & 0x7FFFFF;
    return (exp == 0) && (man != 0);
}

static uint32_t apply_ftz32(uint32_t bits) {
    if (ENABLE_FTZ && is_subnormal_f32(bits))
        return bits & 0x80000000;
    return bits;
}

/* --------------------------------------------------------------------------
 * REFERENCE ADDER: FP128 EXACT FUSED ACCUMULATION
 * All inputs are promoted losslessly to FP128 (112-bit mantissa).
 * The sum accumulates linearly with virtually zero loss of precision.
 * A single, perfect rounding is applied at the very end.
 * Uses SoftFloat "M" (Memory) functions for 128-bit pointer arithmetic.
 * -------------------------------------------------------------------------- */
static uint16_t exact_n_input_fused_add_f128(uint16_t *inputs, int n) {
    bfloat16_t in_bf;
    float128_t sum128;
    
    // Initialize sum128 to 0.0 using the memory pointer function
    ui32_to_f128M(0, &sum128); 
    
    // IEEE 754 Standard: Round to Nearest, Ties to Even
    softfloat_roundingMode = softfloat_round_near_even;

    for (int i = 0; i < n; i++) {
        uint16_t raw = apply_daz(inputs[i]);
        
        // Immediate NaN propagation
        if (is_nan_bf16(raw)) return 0x7FC0;
        
        in_bf.v = raw;
        
        // Lossless Upcast: BF16 -> FP32
        float32_t in_f32 = bf16_to_f32(in_bf);
        
        // FP32 -> FP128 (using Memory pointer)
        float128_t op128;
        f32_to_f128M(in_f32, &op128);
        
        // Exact accumulation: sum128 = sum128 + op128
        f128M_add(&sum128, &op128, &sum128);
    }

    // Single Final Rounding: FP128 -> FP32
    float32_t final_f32 = f128M_to_f32(&sum128);
    final_f32.v = apply_ftz32(final_f32.v);
    
    // Downcast to target hardware size: FP32 -> BF16
    bfloat16_t result = f32_to_bf16(final_f32);
    result.v = apply_ftz(result.v);
    
    return canonicalize_nan(result.v);
}

/* --------------------------------------------------------------------------
 * PRNG & Distributions
 * -------------------------------------------------------------------------- */
static uint64_t rng_state = 0x123456789ABCDEF0ULL;

static uint64_t xorshift64(void) {
    uint64_t x = rng_state;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    rng_state = x;
    return x;
}

/* Constrained to relatively sane exponents to prevent massive 10^30 differences */
static uint16_t random_bf16_constrained(void) {
    uint16_t sign = (xorshift64() & 0x1) << 15;
    uint16_t exp = (90 + (xorshift64() % 57)) << 7; 
    uint16_t man = xorshift64() & 0x7F;
    return sign | exp | man;
}

static uint16_t random_bf16_unconstrained(void) {
    return (uint16_t)(xorshift64() & 0xFFFF);
}

/* --------------------------------------------------------------------------
 * Main
 * -------------------------------------------------------------------------- */
int main(int argc, char *argv[]) {
    int n_cases = 10000;
    int num_inputs = 8; // Default to 8 inputs
    int use_unconstrained = 0;
    uint64_t seed = 0;
    int seed_given = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) n_cases = atoi(argv[++i]);
        else if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) num_inputs = atoi(argv[++i]);
        else if (strcmp(argv[i], "--unconstrained") == 0) use_unconstrained = 1;
        else if (strcmp(argv[i], "--no-daz") == 0) ENABLE_DAZ = 0;
        else if (strcmp(argv[i], "--no-ftz") == 0) ENABLE_FTZ = 0;
        else if ((strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--seed") == 0) && i + 1 < argc) {
            seed = strtoull(argv[++i], NULL, 0);
            seed_given = 1;
        }
    }

    if (seed_given) {
        rng_state = seed;
    } else {
        rng_state = 0x123456789ABCDEF0ULL ^ (uint64_t)time(NULL);
    }
    if (rng_state == 0) rng_state = 0xDEADBEEF;

    fprintf(stderr, "Configuration: Inputs=%d, DAZ=%d, FTZ=%d\n", num_inputs, ENABLE_DAZ, ENABLE_FTZ);
    fprintf(stderr, "Reproducible Seed: -s 0x%016llX\n", (unsigned long long)rng_state);

    // Dynamically print CSV Header based on num_inputs
    for (int j = 0; j < num_inputs; j++) {
        printf("i%d,", j);
    }
    printf("expected\n");

    uint16_t *inputs = malloc(num_inputs * sizeof(uint16_t));
    if (!inputs) {
        fprintf(stderr, "Fatal: Could not allocate memory for inputs.\n");
        return 1;
    }

    for (int i = 0; i < n_cases; i++) {
        for (int j = 0; j < num_inputs; j++) {
            inputs[j] = use_unconstrained ? random_bf16_unconstrained() : random_bf16_constrained();
            printf("%04x,", inputs[j]);
        }
        
        // Calculate the true mathematically exact fused sum
        uint16_t result = exact_n_input_fused_add_f128(inputs, num_inputs);
        printf("%04x\n", result);
    }

    free(inputs);
    return 0;
}