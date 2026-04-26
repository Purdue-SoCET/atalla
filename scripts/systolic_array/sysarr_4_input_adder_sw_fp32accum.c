#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef uint16_t bf16;

/* Compile with:
gcc -O3 -march=native -flto gen_tpu_test.c -o gen_tpu_test
*/

// Convert bf16 to standard 32-bit float
float bf16_to_f32(bf16 b) {
    uint32_t bits = (uint32_t)b << 16;
    float f;
    memcpy(&f, &bits, sizeof(f));
    return f;
}

// Convert 32-bit float to bf16 with Round-to-Nearest, Ties-to-Even (RNE)
bf16 f32_to_bf16_rne(float f) {
    uint32_t bits;
    memcpy(&bits, &f, sizeof(bits));

    if ((bits & 0x7FFFFFFF) > 0x7F800000) {
        return (bits >> 16) | 0x0040;
    }

    uint32_t lsb = (bits >> 16) & 1;
    bits += 0x7FFF + lsb;

    return (bf16)(bits >> 16);
}

// Unpacked 32-bit float
typedef struct {
    uint32_t sign;
    int32_t exp;
    uint32_t mant; // 24 bits (includes hidden bit)
} UnpackedFP32;

UnpackedFP32 unpack_fp32(float f) {
    uint32_t bits;
    memcpy(&bits, &f, sizeof(bits));
    UnpackedFP32 p;
    p.sign = bits >> 31;
    p.exp = (bits >> 23) & 0xFF;
    p.mant = bits & 0x7FFFFF;
    if (p.exp == 0) {
        p.mant = 0; // Flush denormals
    } else {
        p.mant |= 0x800000; // Add hidden bit
    }
    return p;
}

// Hardware-Accurate 4-Input fp32 Adder (Simulating US10514891)
float hw_fused_add_4_fp32(float f0, float f1, float f2, float f3) {
    uint32_t b[4];
    memcpy(&b[0], &f0, 4); 
    memcpy(&b[1], &f1, 4);
    memcpy(&b[2], &f2, 4); 
    memcpy(&b[3], &f3, 4);

    bool is_nan = false;
    bool pos_inf = false;
    bool neg_inf = false;

    // --- 1. SPECIAL CASE HARDWARE LOGIC ---
    for(int i = 0; i < 4; i++) {
        uint32_t exp = (b[i] >> 23) & 0xFF;
        uint32_t mant = b[i] & 0x7FFFFF;
        uint32_t sign = b[i] >> 31;

        if (exp == 0xFF) {
            if (mant != 0) is_nan = true;
            else if (sign == 0) pos_inf = true;
            else neg_inf = true;
        }
    }

    if (is_nan || (pos_inf && neg_inf)) {
        uint32_t nan = 0x7FC00000; // Quiet NaN
        float f; memcpy(&f, &nan, 4); return f;
    } else if (pos_inf) {
        uint32_t inf = 0x7F800000; // +Inf
        float f; memcpy(&f, &inf, 4); return f;
    } else if (neg_inf) {
        uint32_t inf = 0xFF800000; // -Inf
        float f; memcpy(&f, &inf, 4); return f;
    }

    // --- 2. UNPACK FOR NORMAL ADDITION ---
    UnpackedFP32 op[4];
    for(int i = 0; i < 4; i++) {
        op[i].sign = b[i] >> 31;
        op[i].exp = (b[i] >> 23) & 0xFF;
        op[i].mant = b[i] & 0x7FFFFF;
        if (op[i].exp == 0) op[i].mant = 0; // flush denormals
        else op[i].mant |= 0x800000; // add hidden bit
    }

    // 3. Identify operand with the largest exponent
    int max_exp = -1;
    int index_of_x = 0;
    for (int i = 0; i < 4; i++) {
        if (op[i].mant > 0 && op[i].exp > max_exp) {
            max_exp = op[i].exp;
            index_of_x = i;
        }
    }
    
    if (max_exp == -1) return 0.0f; // All inputs are zero
    
    uint64_t aligned_mant[4] = {0, 0, 0, 0};
    int sticky[4] = {0, 0, 0, 0};
    
    // 4. Alignment & Precision/Sticky Bit Generation
    // Internal space: 24 mantissa + 3 precision + 1 sticky = 28 bits
    for (int i = 0; i < 4; i++) {
        if (op[i].mant == 0) continue;
        int S = max_exp - op[i].exp;
        uint64_t m_shifted = (uint64_t)op[i].mant << 3; 
        
        if (S >= 27) {
            aligned_mant[i] = 0;
            sticky[i] = 1;
        } else if (S > 0) {
            aligned_mant[i] = m_shifted >> S;
            uint64_t mask = (1ULL << S) - 1;
            sticky[i] = ((m_shifted & mask) > 0) ? 1 : 0;
        } else {
            aligned_mant[i] = m_shifted;
            sticky[i] = 0;
        }
        
        if (sticky[i]) {
            sticky[i] = (op[i].sign == op[index_of_x].sign) ? 1 : -1;
        }
    }
    
    // 5. Overall Sticky Bit Calculation
    int sticky_pos_count = 0;
    int sticky_neg_count = 0;
    for (int i = 0; i < 4; i++) {
        if (i != index_of_x) {
            if (sticky[i] == 1) sticky_pos_count++;
            if (sticky[i] == -1) sticky_neg_count++;
        }
    }
    
    int overall_sticky = 0;
    if (sticky_pos_count > 0 && sticky_neg_count > 0) {
        overall_sticky = 0; 
    } else if (sticky_pos_count > 0) {
        overall_sticky = 1;
    } else if (sticky_neg_count > 0) {
        overall_sticky = -1;
    }
    
    // 6. Summation
    int64_t sum = 0;
    for (int i = 0; i < 4; i++) {
        if (op[i].mant == 0) continue;
        int64_t val = aligned_mant[i] << 1; 
        
        if (op[i].sign != op[index_of_x].sign) sum -= val; 
        else sum += val;
    }
    
    sum += overall_sticky;
    if (sum == 0) return 0.0f;
    
    // 7. Inversion 
    uint32_t final_sign = op[index_of_x].sign;
    if (sum < 0) {
        final_sign = !final_sign;
        sum = -sum;
    }
    
    // 8. Leading Zero Detection and Normalization
    int32_t final_exp = max_exp;
    int msb = 63 - __builtin_clzll(sum);
    int shift_amt = 27 - msb; 
    
    if (shift_amt < 0) { 
        while (sum >= (1ULL << 28)) {
            int sticky_overflow = sum & 1;
            sum >>= 1;
            sum |= sticky_overflow;
            final_exp++;
        }
    } else if (shift_amt > 0) { 
        sum <<= shift_amt;
        final_exp -= shift_amt;
        if (shift_amt >= 4) sum &= ~(1ULL << shift_amt);
    }
    
    // 9. Rounding
    uint32_t truncated = sum & 0xF; 
    uint32_t mantissa = sum >> 4;
    
    if (truncated > 8) mantissa++;
    else if (truncated < 8) {} 
    else if (mantissa & 1) mantissa++; 
    
    if (mantissa >= (1 << 24)) { 
        mantissa >>= 1;
        final_exp++;
    }
    
    if (final_exp <= 0) return 0.0f; 
    if (final_exp >= 255) { 
        uint32_t inf = (final_sign << 31) | (0xFF << 23);
        float f_inf;
        memcpy(&f_inf, &inf, sizeof(f_inf));
        return f_inf;
    }
    
    uint32_t final_mant = mantissa & 0x7FFFFF;
    uint32_t bits = (final_sign << 31) | ((final_exp & 0xFF) << 23) | final_mant;
    float final_result;
    memcpy(&final_result, &bits, sizeof(final_result));
    
    return final_result;
}

int main(int argc, char* argv[]) {
    int N = 10;
    if (argc > 1) {
        N = atoi(argv[1]);
    }

    srand((unsigned)time(NULL));

    // Print CSV Header
    for (int i = 0; i < 32; i++) {
        printf("i%d,", i);
    }
    printf("expected\n");

    for (int test = 0; test < N; test++) {
        bf16 vals[32];
        
        // Allow base_exp to hit 0 (Subnormals) and up to 255 (Inf/NaN)
        uint32_t base_exp = rand() % 256;

        for (int i = 0; i < 32; i++) {
            uint32_t sign = rand() % 2;
            
            // Add random offset, but strictly clamp at 255 so it remains valid bf16
            uint32_t exp = base_exp + (rand() % 20); 
            if (exp > 255) {
                exp = 255; 
            }
            
            uint32_t mant = rand() % 128; 
            
            vals[i] = (sign << 15) | (exp << 7) | mant;
            printf("%04x,", vals[i]); 
        }

        // --- Hardware Tree Simulation (bf16 inputs -> fp32 accumulation) ---
        
        // Level 1: 32 inputs (bf16 cast to fp32) -> 8 fp32 outputs
        float l1[8];
        for (int i = 0; i < 8; i++) {
            l1[i] = hw_fused_add_4_fp32(
                bf16_to_f32(vals[4*i]),     bf16_to_f32(vals[4*i+1]), 
                bf16_to_f32(vals[4*i+2]), bf16_to_f32(vals[4*i+3])
            );
        }

        // Level 2: 8 fp32 inputs -> 2 fp32 outputs
        float l2[2];
        for (int i = 0; i < 2; i++) {
            l2[i] = hw_fused_add_4_fp32(l1[4*i], l1[4*i+1], l1[4*i+2], l1[4*i+3]);
        }

        // Level 3: 2 fp32 inputs (padded with zeros) -> 1 fp32 output
        float final_f32 = hw_fused_add_4_fp32(l2[0], l2[1], 0.0f, 0.0f);

        // Convert the final fp32 result back to bf16
        bf16 final_result = f32_to_bf16_rne(final_f32);

        printf("%04x\n", final_result);
    }

    return 0;
}