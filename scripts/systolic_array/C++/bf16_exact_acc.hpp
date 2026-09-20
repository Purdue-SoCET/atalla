// bf16_exact_acc.hpp
// Non-synthesizable reference model for correctly-rounded bf16 GEMM.
// Represents the exact mathematical value of any sum of bf16*bf16 products
// using a 576-bit two's-complement fixed-point accumulator, then rounds
// once to bf16 with round-to-nearest-ties-to-even.
//
// Format:
//   - 576-bit signed two's complement, stored as 9 x uint64_t (little-endian).
//   - Value represented = ACC * 2^-266.
//   - Bit 266 has weight 2^0; bit 0 has weight 2^-266; bit 575 is sign (two's comp).
//   - Extended with sticky flags for NaN / +Inf / -Inf handling.
//
// bf16 encoding (no FTZ; all subnormals supported):
//   sign(1) | exp(8) | mant(7)
//   exp=0, mant=0         -> signed zero
//   exp=0, mant!=0        -> subnormal: value = (-1)^s * mant * 2^-133
//   1<=exp<=254           -> normal:    value = (-1)^s * (128+mant) * 2^(exp-134)
//   exp=255, mant=0       -> signed infinity
//   exp=255, mant!=0      -> NaN

#pragma once
#include <cstdint>
#include <array>
#include <cassert>

// ============================================================
// Accumulator constants
// ============================================================

static constexpr int ACC_WORDS = 9;
static constexpr int ACC_BITS  = ACC_WORDS * 64;   // 576
static constexpr int ACC_SCALE = 266;              // binary-point bias

using AccWords = std::array<uint64_t, ACC_WORDS>;

// Canonical bf16 special encodings
static constexpr uint16_t BF16_POS_ZERO = 0x0000;
static constexpr uint16_t BF16_NEG_ZERO = 0x8000;
static constexpr uint16_t BF16_POS_INF  = 0x7F80;
static constexpr uint16_t BF16_NEG_INF  = 0xFF80;
static constexpr uint16_t BF16_QNAN     = 0x7FC0; // sign=0, exp=0xFF, mant MSB set

// ============================================================
// Big-int helpers on 576-bit two's complement
// ============================================================

static inline void acc_zero(AccWords& a) { a.fill(0); }

static inline bool acc_is_negative(const AccWords& a) {
    return (a[ACC_WORDS - 1] >> 63) & 1ULL;
}

static inline void acc_negate(AccWords& a) {
    // Two's complement: invert then +1
    uint64_t carry = 1;
    for (int i = 0; i < ACC_WORDS; ++i) {
        uint64_t v = ~a[i];
        uint64_t s = v + carry;
        carry = (s < v) ? 1ULL : 0ULL;
        a[i] = s;
    }
}

static inline void acc_add(AccWords& a, const AccWords& b) {
    uint64_t carry = 0;
    for (int i = 0; i < ACC_WORDS; ++i) {
        __uint128_t s = (__uint128_t)a[i] + (__uint128_t)b[i] + carry;
        a[i]  = (uint64_t)s;
        carry = (uint64_t)(s >> 64);
    }
}

static inline void acc_sub(AccWords& a, const AccWords& b) {
    AccWords nb = b;
    acc_negate(nb);
    acc_add(a, nb);
}

// Place a small unsigned value (up to 16 bits) at bit position bit_pos,
// producing a fresh 576-bit unsigned word array. Caller handles sign.
static inline AccWords acc_from_shifted_mant(uint64_t mant, int bit_pos) {
    AccWords r{};
    assert(bit_pos >= 0);
    assert(bit_pos + 16 <= ACC_BITS);
    int word  = bit_pos / 64;
    int shift = bit_pos % 64;
    r[word] = mant << shift;
    if (shift != 0 && word + 1 < ACC_WORDS) {
        r[word + 1] = mant >> (64 - shift);
    }
    return r;
}

// Read bit `pos` of a (unsigned interpretation).
static inline int acc_bit(const AccWords& a, int pos) {
    if (pos < 0 || pos >= ACC_BITS) return 0;
    return (int)((a[pos >> 6] >> (pos & 63)) & 1ULL);
}

// Return position of highest set bit, or -1 if a == 0 (unsigned interpretation).
static inline int acc_msb_pos(const AccWords& a) {
    for (int w = ACC_WORDS - 1; w >= 0; --w) {
        if (a[w] != 0) {
            uint64_t v = a[w];
            int hi = 63;
            while (((v >> hi) & 1ULL) == 0) --hi;
            return w * 64 + hi;
        }
    }
    return -1;
}

// Return 1 if any bit in [0, upto_exclusive) is set; 0 otherwise.
static inline int acc_any_bits_below(const AccWords& a, int upto_exclusive) {
    if (upto_exclusive <= 0) return 0;
    if (upto_exclusive > ACC_BITS) upto_exclusive = ACC_BITS;
    int full_words = upto_exclusive / 64;
    int rem        = upto_exclusive % 64;
    for (int w = 0; w < full_words; ++w) {
        if (a[w] != 0) return 1;
    }
    if (rem > 0) {
        uint64_t mask = (rem == 64) ? ~0ULL : ((1ULL << rem) - 1);
        if (a[full_words] & mask) return 1;
    }
    return 0;
}

// ============================================================
// bf16 decode
// ============================================================

enum bf16_class_t { BF16_ZERO, BF16_FINITE, BF16_INF, BF16_NAN };

struct Bf16Parts {
    bf16_class_t cls;
    int sign;        // 0 or 1
    uint32_t mant;   // integer mantissa (valid only for FINITE): 1..127 sub, 128..255 normal
    int p;           // power-of-two scale: value = (-1)^sign * mant * 2^p
};

static inline Bf16Parts bf16_decode(uint16_t b) {
    Bf16Parts r{};
    r.sign = (b >> 15) & 1;
    uint32_t e = (b >> 7) & 0xFF;
    uint32_t m = b & 0x7F;

    if (e == 0xFF) {
        r.cls = (m == 0) ? BF16_INF : BF16_NAN;
        return r;
    }
    if (e == 0 && m == 0) {
        r.cls = BF16_ZERO;
        return r;
    }
    r.cls = BF16_FINITE;
    if (e == 0) {
        // Subnormal: value = (-1)^s * m * 2^-133 , m in [1, 127]
        r.mant = m;
        r.p    = -133;
    } else {
        // Normal: value = (-1)^s * (128+m) * 2^(e-134)
        r.mant = 128u | m;
        r.p    = (int)e - 134;
    }
    return r;
}

// ============================================================
// Extended accumulator with special-value sticky flags
// ============================================================

struct ExactAcc {
    AccWords words;
    bool is_nan;
    bool seen_pos_inf;
    bool seen_neg_inf;
};

static inline void eacc_zero(ExactAcc& a) {
    acc_zero(a.words);
    a.is_nan = false;
    a.seen_pos_inf = false;
    a.seen_neg_inf = false;
}

// Seed accumulator from a single bf16 value.
static inline void eacc_set_bf16(ExactAcc& acc, uint16_t b_bits) {
    eacc_zero(acc);
    Bf16Parts p = bf16_decode(b_bits);
    switch (p.cls) {
        case BF16_ZERO:
            return;
        case BF16_NAN:
            acc.is_nan = true;
            return;
        case BF16_INF:
            if (p.sign) acc.seen_neg_inf = true;
            else        acc.seen_pos_inf = true;
            return;
        case BF16_FINITE: {
            int bit_pos = p.p + ACC_SCALE;      // always in [0, 373]
            AccWords term = acc_from_shifted_mant(p.mant, bit_pos);
            if (p.sign) acc_sub(acc.words, term);
            else        acc_add(acc.words, term);
            return;
        }
    }
}

// Multiply-accumulate one bf16 * bf16 product into acc.
// Handles: NaN propagation, 0*Inf -> NaN, Inf*finite_nonzero -> signed Inf,
// Inf + (-Inf) -> NaN, 0*finite -> no-op, finite*finite -> exact integer add.
static inline void eacc_madd_bf16(ExactAcc& acc, uint16_t a_bits, uint16_t b_bits) {
    if (acc.is_nan) return; // absorbing

    Bf16Parts a = bf16_decode(a_bits);
    Bf16Parts b = bf16_decode(b_bits);

    // Any NaN input -> NaN result
    if (a.cls == BF16_NAN || b.cls == BF16_NAN) {
        acc.is_nan = true;
        return;
    }

    // 0 * Inf (either order) -> NaN
    if ((a.cls == BF16_INF  && b.cls == BF16_ZERO) ||
        (a.cls == BF16_ZERO && b.cls == BF16_INF)) {
        acc.is_nan = true;
        return;
    }

    // Inf * anything-nonzero -> signed infinity
    if (a.cls == BF16_INF || b.cls == BF16_INF) {
        int prod_sign = a.sign ^ b.sign;
        if (prod_sign == 0) acc.seen_pos_inf = true;
        else                acc.seen_neg_inf = true;
        if (acc.seen_pos_inf && acc.seen_neg_inf) acc.is_nan = true;
        return;
    }

    // 0 * finite -> no-op
    if (a.cls == BF16_ZERO || b.cls == BF16_ZERO) return;

    // Both finite nonzero (normal or subnormal)
    uint32_t prod_mant = a.mant * b.mant;     // up to 16 bits
    int prod_sign      = a.sign ^ b.sign;
    int prod_shift     = a.p + b.p;           // range [-266, +240]
    int bit_pos        = prod_shift + ACC_SCALE; // range [0, 506]

    AccWords term = acc_from_shifted_mant(prod_mant, bit_pos);
    if (prod_sign) acc_sub(acc.words, term);
    else           acc_add(acc.words, term);
}

// ============================================================
// Correctly-rounded bf16 output (round-to-nearest-ties-to-even)
// ============================================================

static inline uint16_t eacc_to_bf16_rne(const ExactAcc& acc_in) {
    // Specials have priority
    if (acc_in.is_nan) return BF16_QNAN;
    if (acc_in.seen_pos_inf && acc_in.seen_neg_inf) return BF16_QNAN; // redundant
    if (acc_in.seen_pos_inf) return BF16_POS_INF;
    if (acc_in.seen_neg_inf) return BF16_NEG_INF;

    AccWords mag = acc_in.words;
    int sign = 0;
    if (acc_is_negative(mag)) { sign = 1; acc_negate(mag); }

    int k = acc_msb_pos(mag);
    if (k < 0) return (uint16_t)(sign << 15); // signed zero

    int E = k - ACC_SCALE; // unbiased exponent of true value

    // Magnitude > largest finite bf16 -> infinity with sign
    if (E > 127) return sign ? BF16_NEG_INF : BF16_POS_INF;

    uint32_t mantissa_field;
    uint32_t exp_field;

    if (E >= -126) {
        // ---- Normal range ----
        // Keep 8 bits at positions [k-7 .. k]. Round using bit (k-8) as guard,
        // OR of bits below as sticky.
        int guard_pos = k - 8;
        int kept_bot  = k - 7;

        uint32_t kept = 0;
        for (int i = 0; i < 8; ++i) {
            kept |= (uint32_t)acc_bit(mag, kept_bot + i) << i;
        }
        // kept is in [0x80, 0xFF] since bit k is set.

        int round_up = 0;
        if (guard_pos >= 0) {
            int g        = acc_bit(mag, guard_pos);
            int sticky   = acc_any_bits_below(mag, guard_pos);
            int kept_lsb = kept & 1;
            if (g == 1 && (sticky == 1 || kept_lsb == 1)) round_up = 1;
        }
        // If guard_pos < 0, there are no bits below the kept field -> exact.

        if (round_up) {
            kept += 1;
            if (kept == 0x100) {        // carried out
                kept >>= 1;             // back to 0x80
                E    += 1;
                if (E > 127) return sign ? BF16_NEG_INF : BF16_POS_INF;
            }
        }

        mantissa_field = kept & 0x7F;     // drop hidden bit
        exp_field      = (uint32_t)(E + 127);
    } else {
        // ---- Subnormal range (E < -126) ----
        // bf16 subnormal LSB has weight 2^-133 -> accumulator bit 133 (= -133 + 266).
        // Kept integer = bits [133 .. k] of mag (0 to 7 bits of magnitude).
        const int sub_lsb_pos = -133 + ACC_SCALE;  // 133
        const int guard_pos   = sub_lsb_pos - 1;   // 132

        uint32_t kept = 0;
        if (k >= sub_lsb_pos) {
            int nbits = k - sub_lsb_pos + 1;       // 1..7
            for (int i = 0; i < nbits; ++i) {
                kept |= (uint32_t)acc_bit(mag, sub_lsb_pos + i) << i;
            }
        }
        // If k < sub_lsb_pos, kept == 0 and the entire magnitude lives below the
        // subnormal LSB -> guard/sticky determined by bits of mag.

        int round_up = 0;
        if (guard_pos >= 0) {
            int g        = acc_bit(mag, guard_pos);
            int sticky   = acc_any_bits_below(mag, guard_pos);
            int kept_lsb = kept & 1;
            if (g == 1 && (sticky == 1 || kept_lsb == 1)) round_up = 1;
        }

        if (round_up) {
            kept += 1;
            if (kept == 0x80) {
                // Rounded up into the smallest normal: exp=1, mant=0
                return (uint16_t)((sign << 15) | (1u << 7));
            }
        }

        if (kept == 0) return (uint16_t)(sign << 15); // signed zero

        mantissa_field = kept & 0x7F;
        exp_field      = 0;
    }

    return (uint16_t)((sign << 15) | (exp_field << 7) | mantissa_field);
}

// ============================================================
// GEMM driver: C = A * B, all in bf16, with correctly-rounded outputs.
// A is M x K row-major, B is K x N row-major, C is M x N row-major.
// ============================================================

static inline void gemm_bf16_golden(const uint16_t* A,
                                    const uint16_t* B,
                                    uint16_t*       C,
                                    int M, int N, int K) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            ExactAcc acc; eacc_zero(acc);
            for (int kk = 0; kk < K; ++kk) {
                eacc_madd_bf16(acc, A[i * K + kk], B[kk * N + j]);
            }
            C[i * N + j] = eacc_to_bf16_rne(acc);
        }
    }
}

// ============================================================
// ULP error measurement between hardware and golden bf16 outputs.
// Treats bf16 bit patterns as ordered integers so signed distances
// are meaningful across zero.
// ============================================================

static inline int32_t bf16_ulp_diff(uint16_t hw, uint16_t golden) {
    auto to_ordered = [](uint16_t b) -> int32_t {
        if (b & 0x8000) return -(int32_t)(b & 0x7FFF);
        return (int32_t)(b & 0x7FFF);
    };
    return to_ordered(hw) - to_ordered(golden);
}