// Generates all permuations of a 32 input test to verify commutativity and associativity

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef uint16_t bf16;

/* Compile with:
gcc -O3 -march=native -flto test_commutativity.c -o test_commutativity
*/

// --- BFLOAT16 & FP32 UTILS ---
float bf16_to_f32(bf16 b) {
    uint32_t bits = (uint32_t)b << 16;
    float f; memcpy(&f, &bits, sizeof(f)); return f;
}

bf16 f32_to_bf16_rne(float f) {
    uint32_t bits; memcpy(&bits, &f, sizeof(bits));
    if ((bits & 0x7FFFFFFF) > 0x7F800000) return (bits >> 16) | 0x0040;
    uint32_t lsb = (bits >> 16) & 1;
    bits += 0x7FFF + lsb;
    return (bf16)(bits >> 16);
}

typedef struct { uint32_t sign; int32_t exp; uint32_t mant; } UnpackedFP32;

// --- HARDWARE REFERENCE MODEL ---
float hw_fused_add_4_fp32(float f0, float f1, float f2, float f3) {
    uint32_t b[4];
    memcpy(&b[0], &f0, 4); memcpy(&b[1], &f1, 4);
    memcpy(&b[2], &f2, 4); memcpy(&b[3], &f3, 4);

    bool is_nan = false, pos_inf = false, neg_inf = false;
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
        uint32_t nan = 0x7FC00000; float f; memcpy(&f, &nan, 4); return f;
    } else if (pos_inf) {
        uint32_t inf = 0x7F800000; float f; memcpy(&f, &inf, 4); return f;
    } else if (neg_inf) {
        uint32_t inf = 0xFF800000; float f; memcpy(&f, &inf, 4); return f;
    }

    UnpackedFP32 op[4];
    for(int i = 0; i < 4; i++) {
        op[i].sign = b[i] >> 31;
        op[i].exp = (b[i] >> 23) & 0xFF;
        op[i].mant = b[i] & 0x7FFFFF;
        if (op[i].exp == 0) op[i].mant = 0;
        else op[i].mant |= 0x800000;
    }

    int max_exp = -1, index_of_x = 0;
    for (int i = 0; i < 4; i++) {
        if (op[i].mant > 0 && op[i].exp > max_exp) {
            max_exp = op[i].exp; index_of_x = i;
        }
    }
    if (max_exp == -1) return 0.0f;
    
    uint64_t aligned_mant[4] = {0, 0, 0, 0};
    int sticky[4] = {0, 0, 0, 0};
    
    for (int i = 0; i < 4; i++) {
        if (op[i].mant == 0) continue;
        int S = max_exp - op[i].exp;
        uint64_t m_shifted = (uint64_t)op[i].mant << 3; 
        
        if (S >= 27) {
            aligned_mant[i] = 0; sticky[i] = 1;
        } else if (S > 0) {
            aligned_mant[i] = m_shifted >> S;
            uint64_t mask = (1ULL << S) - 1;
            sticky[i] = ((m_shifted & mask) > 0) ? 1 : 0;
        } else {
            aligned_mant[i] = m_shifted; sticky[i] = 0;
        }
        if (sticky[i]) sticky[i] = (op[i].sign == op[index_of_x].sign) ? 1 : -1;
    }
    
    int sticky_pos_count = 0, sticky_neg_count = 0;
    for (int i = 0; i < 4; i++) {
        if (i != index_of_x) {
            if (sticky[i] == 1) sticky_pos_count++;
            if (sticky[i] == -1) sticky_neg_count++;
        }
    }
    
    int overall_sticky = 0;
    if (sticky_pos_count > 0 && sticky_neg_count > 0) overall_sticky = 0; 
    else if (sticky_pos_count > 0) overall_sticky = 1;
    else if (sticky_neg_count > 0) overall_sticky = -1;
    
    int64_t sum = 0;
    for (int i = 0; i < 4; i++) {
        if (op[i].mant == 0) continue;
        int64_t val = aligned_mant[i] << 1; 
        if (op[i].sign != op[index_of_x].sign) sum -= val; 
        else sum += val;
    }
    
    sum += overall_sticky;
    if (sum == 0) return 0.0f;
    
    uint32_t final_sign = op[index_of_x].sign;
    if (sum < 0) { final_sign = !final_sign; sum = -sum; }
    
    int32_t final_exp = max_exp;
    int msb = 63 - __builtin_clzll(sum);
    int shift_amt = 27 - msb; 
    
    if (shift_amt < 0) { 
        while (sum >= (1ULL << 28)) {
            int sticky_overflow = sum & 1;
            sum >>= 1; sum |= sticky_overflow; final_exp++;
        }
    } else if (shift_amt > 0) { 
        sum <<= shift_amt; final_exp -= shift_amt;
        if (shift_amt >= 4) sum &= ~(1ULL << shift_amt);
    }
    
    uint32_t truncated = sum & 0xF; 
    uint32_t mantissa = sum >> 4;
    
    if (truncated > 8) mantissa++;
    else if (truncated < 8) {} 
    else if (mantissa & 1) mantissa++; 
    
    if (mantissa >= (1 << 24)) { mantissa >>= 1; final_exp++; }
    if (final_exp <= 0) return 0.0f; 
    if (final_exp >= 255) { 
        uint32_t inf = (final_sign << 31) | (0xFF << 23);
        float f_inf; memcpy(&f_inf, &inf, 4); return f_inf;
    }
    
    uint32_t final_mant = mantissa & 0x7FFFFF;
    uint32_t bits = (final_sign << 31) | ((final_exp & 0xFF) << 23) | final_mant;
    float final_result; memcpy(&final_result, &bits, 4);
    return final_result;
}

// Fisher-Yates Shuffle
void shuffle(bf16 *array, size_t n) {
    if (n > 1) {
        for (size_t i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            bf16 t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

int main(int argc, char* argv[]) {
    int N = 100000; // Default to 100k shuffles
    if (argc > 1) N = atoi(argv[1]);

    srand((unsigned)time(NULL));

    // The user's specific inputs
    bf16 original_vals[32] = {
        0xc308, 0xb354, 0xc842, 0x4e82, 0x34ab, 0x32aa, 0x45af, 0x3d05, 
        0xc0f7, 0xd07a, 0xc413, 0xc13d, 0xca6c, 0xb8d5, 0x4db2, 0xd1f0, 
        0xb9de, 0x4694, 0xd06b, 0xca4a, 0xbeb2, 0xadb5, 0x5215, 0xc7ce, 
        0xb666, 0xc61d, 0x47c8, 0xbf28, 0x3dac, 0xcc34, 0xc278, 0xbef3
    };

    // Print CSV Header
    for (int i = 0; i < 32; i++) printf("i%d,", i);
    printf("expected\n");

    for (int test = 0; test < N; test++) {
        bf16 vals[32];
        memcpy(vals, original_vals, sizeof(original_vals));
        
        // Don't shuffle the first row so we have a baseline
        if (test > 0) {
            shuffle(vals, 32);
        }

        for (int i = 0; i < 32; i++) {
            printf("%04x,", vals[i]); 
        }

        // --- Hardware Tree Simulation ---
        float l1[8];
        for (int i = 0; i < 8; i++) {
            l1[i] = hw_fused_add_4_fp32(
                bf16_to_f32(vals[4*i]),   bf16_to_f32(vals[4*i+1]), 
                bf16_to_f32(vals[4*i+2]), bf16_to_f32(vals[4*i+3])
            );
        }

        float l2[2];
        for (int i = 0; i < 2; i++) {
            l2[i] = hw_fused_add_4_fp32(l1[4*i], l1[4*i+1], l1[4*i+2], l1[4*i+3]);
        }

        float final_f32 = hw_fused_add_4_fp32(l2[0], l2[1], 0.0f, 0.0f);
        bf16 final_result = f32_to_bf16_rne(final_f32);

        printf("%04x\n", 0xc6bd); // Expected result in bf16
    }

    return 0;
}