#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
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

/* --------------------------------------------------------------------------
 * REFERENCE ADDER: FP128 EXACT FUSED ACCUMULATION
 * -------------------------------------------------------------------------- */
int compare_bf16_mag(const void *a, const void *b) {
    uint16_t ua = *(const uint16_t *)a;
    uint16_t ub = *(const uint16_t *)b;
    uint16_t mag_a = ua & 0x7FFF;
    uint16_t mag_b = ub & 0x7FFF;
    
    if (mag_a > mag_b) return -1; 
    if (mag_a < mag_b) return 1;
    return 0;
}

static uint16_t exact_n_input_fused_add_f128(uint16_t *inputs, int n, uint64_t *exact_f64_out) {
    uint16_t sorted_inputs[32]; 
    for (int i = 0; i < n; i++) sorted_inputs[i] = inputs[i];
    qsort(sorted_inputs, n, sizeof(uint16_t), compare_bf16_mag);

    float128_t sum128;
    ui32_to_f128M(0, &sum128); 
    softfloat_roundingMode = softfloat_round_near_even;

    for (int i = 0; i < n; i++) {
        uint16_t raw = apply_daz(sorted_inputs[i]); 
        if (is_nan_bf16(raw)) {
            *exact_f64_out = 0x7FF8000000000000ULL; // 64-bit Quiet NaN
            return 0x7FC0;
        }
        
        bfloat16_t in_bf = {raw};
        float32_t in_f32 = bf16_to_f32(in_bf);
        float128_t op128;
        f32_to_f128M(in_f32, &op128);
        
        f128M_add(&sum128, &op128, &sum128);
    }

    // Extract the mathematically unrounded result downcast safely to 64-bit IEEE float
    float64_t sum64 = f128M_to_f64(&sum128);
    *exact_f64_out = sum64.v;

    uint64_t ui64h = sum128.v[1]; 
    uint64_t ui64l = sum128.v[0]; 

    uint16_t sign = (ui64h >> 63) & 0x1;
    int32_t  exp128 = (ui64h >> 48) & 0x7FFF;
    uint64_t mant128_high = ui64h & 0x0000FFFFFFFFFFFFULL; 

    if (exp128 == 0x7FFF) { 
        if (mant128_high == 0 && ui64l == 0) return (sign << 15) | 0x7F80;
        return 0x7FC0; 
    }
    if (exp128 == 0 && mant128_high == 0 && ui64l == 0) return sign << 15;

    int32_t exp_bf = exp128 - 16383 + 127;

    if (exp_bf <= 0) return sign << 15; 
    if (exp_bf >= 0xFF) return (sign << 15) | 0x7F80;

    uint32_t mant_bf = (mant128_high >> 41) & 0x7F; 
    bool lsb    = (mant_bf & 1);
    bool guard  = (mant128_high >> 40) & 1;
    bool sticky = (mant128_high & 0xFFFFFFFFFFULL) != 0 || (ui64l != 0);

    bool round_up = guard && (sticky || lsb);

    if (round_up) {
        mant_bf++;
        if (mant_bf & 0x80) { 
            mant_bf = 0;
            exp_bf++;
        }
    }

    if (exp_bf >= 0xFF) return (sign << 15) | 0x7F80;

    return (sign << 15) | (exp_bf << 7) | (mant_bf & 0x7F);
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

static uint16_t random_bf16_constrained(void) {
    uint16_t sign = (xorshift64() & 0x1) << 15;
    uint16_t exp = (90 + (xorshift64() % 75)) << 7; 
    uint16_t man = xorshift64() & 0x7F;
    return sign | exp | man;
}

static uint16_t random_bf16_unconstrained(void) {
    return (uint16_t)(xorshift64() & 0xFFFF);
}

static uint16_t random_bf16_subnormal(void) {
    uint16_t sign = (xorshift64() & 0x1) << 15;
    uint16_t man = (xorshift64() % 0x7F) + 1; 
    return sign | man; 
}

/* --------------------------------------------------------------------------
 * Main Execution & Targeted Injection Loop
 * -------------------------------------------------------------------------- */
int main(int argc, char *argv[]) {
    int n_cases = 10000;
    int num_inputs = 8; 
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

    fprintf(stderr, "Configuration: Inputs=%d, DAZ=%d, FTZ=%d, Total Cases=%d\n", num_inputs, ENABLE_DAZ, ENABLE_FTZ, n_cases);
    fprintf(stderr, "Reproducible Seed: -s 0x%016llX\n", (unsigned long long)rng_state);

    for (int j = 0; j < num_inputs; j++) {
        printf("i%d,", j);
    }
    printf("expected,exact_f64\n");

    uint16_t *inputs = malloc(num_inputs * sizeof(uint16_t));
    if (!inputs) {
        fprintf(stderr, "Fatal: Could not allocate memory for inputs.\n");
        return 1;
    }

    // UPDATED: Using modulo for even distribution across the file
    int num_categories = 7;

    for (int i = 0; i < n_cases; i++) {
        int category = i % num_categories;

        switch (category) {
            case 0: {
                // 1. PURE RANDOM (The Baseline)
                for (int j = 0; j < num_inputs; j++) {
                    inputs[j] = use_unconstrained ? random_bf16_unconstrained() : random_bf16_constrained();
                }
                break;
            }
            case 1: {
                // 2. SUBNORMAL & DAZ/FTZ CRASH COURSE
                for (int j = 0; j < num_inputs; j++) {
                    int roll = xorshift64() % 4;
                    if (roll == 0)      inputs[j] = random_bf16_subnormal();
                    else if (roll == 1) inputs[j] = random_bf16_subnormal() | 0x8000; 
                    else                inputs[j] = (random_bf16_constrained() & 0x807F) | (1 << 7); // Min normal
                }
                break;
            }
            case 2: {
                // 3. THE GRS BOUNDARY STRADDLE (Aligner Test)
                // Forces small numbers to land EXACTLY on the Guard, Round, and Sticky bit boundaries
                uint16_t max_exp = 100 + (xorshift64() % 100); 
                uint16_t sign_max = (xorshift64() & 0x1) << 15;
                inputs[0] = sign_max | (max_exp << 7) | (xorshift64() & 0x7F);
                
                for (int j = 1; j < num_inputs; j++) {
                    // Exponent deltas between 11 and 15 (Targeting PRECISION_BITS bounds)
                    uint16_t boundary_delta = 11 + (xorshift64() % 5);
                    uint16_t small_exp = (max_exp > boundary_delta) ? (max_exp - boundary_delta) : 1;
                    uint16_t sign_small = (xorshift64() & 0x1) << 15;
                    inputs[j] = sign_small | (small_exp << 7) | ((xorshift64() % 0x7E) + 1);
                }
                break;
            }
            case 3: {
                // 4. THE OFF-BY-ONE CANCELLATION (The "Sweet Spot" Stress Test)
                // Exponents differ by EXACTLY 0 or 1, forcing heavy LZD use and multi-operand subtractions
                uint16_t base_exp = 120 + (xorshift64() % 60);
                for (int j = 0; j < num_inputs; j++) {
                    uint16_t sign = (j % 2 == 0) ? 0x0000 : 0x8000; // Alternating signs
                    uint16_t exp_tweak = xorshift64() & 0x1;        // Offset 0 or 1
                    inputs[j] = sign | ((base_exp + exp_tweak) << 7) | (xorshift64() & 0x7F);
                }
                break;
            }
            case 4: {
                // 5. THE ZOMBIE RESCUE (Dropped Lane Recovery Test)
                // Anchor and primary subtractor perfectly cancel. Remaining numbers are tiny and must be rescued.
                uint16_t massive_exp = 150 + (xorshift64() % 50);
                uint16_t massive_man = xorshift64() & 0x7F;
                
                inputs[0] = 0x0000 | (massive_exp << 7) | massive_man; // +X
                if (num_inputs > 1) {
                    inputs[1] = 0x8000 | (massive_exp << 7) | massive_man; // -X (Perfect cancellation)
                }
                
                for (int j = 2; j < num_inputs; j++) {
                    uint16_t shift_amount = 20 + (xorshift64() % 20);
                    uint16_t tiny_exp = (massive_exp > shift_amount) ? (massive_exp - shift_amount) : 1; 
                    inputs[j] = ((xorshift64() & 0x1) << 15) | (tiny_exp << 7) | (xorshift64() & 0x7F);
                }
                break;
            }
            case 5: {
                // 6. NEGATIVE ZERO LEAK TESTER
                // Forces a perfect sum to 0.0 with a negative anchor to ensure output correctly clamps to +0.0
                uint16_t exp = 100 + (xorshift64() % 100);
                uint16_t man = xorshift64() & 0x7F;
                
                inputs[0] = 0x8000 | (exp << 7) | man; // Anchor is negative
                if (num_inputs > 1) {
                    inputs[1] = 0x0000 | (exp << 7) | man; // Exactly cancels anchor
                }
                for (int j = 2; j < num_inputs; j++) {
                    inputs[j] = 0x0000; // The rest are exact +0.0
                }
                break;
            }
            case 6: {
                // 7. IEEE-754 ARCHITECTURAL EDGE CASES
                // Blasts multiplexers with NaNs, Infs, and zeroes.
                int trap_type = xorshift64() % 4;
                for (int j = 0; j < num_inputs; j++) {
                    if (trap_type == 0)      inputs[j] = (xorshift64() & 1) ? 0x7F80 : 0xFF80; // +/- Inf
                    else if (trap_type == 1) inputs[j] = (xorshift64() & 1) ? 0x0000 : 0x8000; // +/- 0.0
                    else if (trap_type == 2) inputs[j] = 0x7FC0;                               // Quiet NaN
                    else                     inputs[j] = (xorshift64() & 1) ? 0x7F80 : random_bf16_constrained();
                }
                break;
            }
        }

        for (int j = 0; j < num_inputs; j++) {
            printf("%04x,", inputs[j]);
        }
        
        // Compute and print expected BF16 result alongside unrounded FP64 true outcome
        uint64_t exact_f64_val;
        uint16_t result = exact_n_input_fused_add_f128(inputs, num_inputs, &exact_f64_val);
        printf("%04x,%016lx\n", result, (unsigned long)exact_f64_val);
    }

    free(inputs);
    return 0;
}