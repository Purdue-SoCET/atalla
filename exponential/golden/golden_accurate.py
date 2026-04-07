# Copyright 2023 ETH Zurich and University of Bologna.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
#
# Andrea Belano <andrea.belano@studio.unibo.it>
#

import numpy as np
import torch
import argparse

def decompose(x):
    if (x.dtype == torch.bfloat16):
        x = x.float()
    
    if (x.dtype == torch.float32):
        x = x.numpy()

    x_int = np.frombuffer(x.tobytes(), np.uint32)

    sign = x_int >> 31
    mant = np.bitwise_and(x_int >> 16, 0b000000001111111)
    exp = np.bitwise_and(x_int >> 23, 0b011111111)
    
    return sign, mant, exp

def mant_correction(vect, input_fraction = 7, coefficient_fraction = 4, constant_fraction = 7, alpha1 = 0.21875000, beta1 = 0.4101562500, gamma1 = 2.835937500, gamma2 = 2.1679687500, mul_surplus_bits = 1, not_surplus_bits = 0):
    alpha = np.round(alpha1 * 2 ** coefficient_fraction).astype(np.uint64)
    beta = np.round(beta1 * 2 ** coefficient_fraction).astype(np.uint64)

    sum_fraction = max(input_fraction, constant_fraction)

    gamma_1 = np.round(gamma1 * 2 ** constant_fraction).astype(np.int64) * 2 ** (sum_fraction - constant_fraction)
    gamma_2 = np.round(gamma2 * 2 ** constant_fraction).astype(np.int64) * 2 ** (sum_fraction - constant_fraction)

    mant_add = np.bitwise_and(np.frombuffer(vect.tobytes(), dtype = np.uint32) >> 16, 0x007F).astype(np.int64) * 2 ** (sum_fraction - 7)
    res_add_1 = np.where(mant_add < 2 ** (sum_fraction - 1), mant_add + gamma_1 , mant_add + gamma_2)
    
    mant_mul = np.bitwise_and(np.frombuffer(vect.tobytes(), dtype = np.uint32) >> 16, 0x007F).astype(np.int64) * 2 ** (mul_surplus_bits)
    res_mul_1 = np.where(mant_mul < 2 ** (mul_surplus_bits + input_fraction - 1), mant_mul * alpha, (beta * (2 ** (mul_surplus_bits + input_fraction) - mant_mul - 1)))

    res_mul_2 = (res_mul_1 * res_add_1) >> (sum_fraction + coefficient_fraction + mul_surplus_bits - not_surplus_bits)

    res = np.where(mant_add < 2 ** (sum_fraction - 1), res_mul_2, 2 ** (7 + not_surplus_bits) - res_mul_2 - 1) >> not_surplus_bits

    return np.frombuffer((np.bitwise_and(np.frombuffer(vect.tobytes(), dtype = np.uint32), 0xFF800000) + (res << 16)).astype(np.int32), dtype = np.float32)

def exponentiate(vect, input_fraction = 7, a_fraction = 14, coefficient_fraction = 7, constant_fraction = 8):
    a = np.round(1 / np.log(2) * 2 ** a_fraction).astype(np.int64)

    sign, mant, exp = decompose(vect)

    mant = 2 ** 7 + mant

    mant_comp = np.where(sign == 1, (mant.astype(np.int32)), mant.astype(np.int32))

    max_exp = 127

    shm = np.where(exp >= max_exp, (mant_comp * a) << (exp - max_exp), (mant_comp * a) >> (max_exp - exp))
    shm = (shm >> a_fraction) + np.bitwise_and(shm >> (a_fraction - 1), 0b1)
    shm = np.where(sign == 1, -shm, shm)
    
    nm = np.bitwise_and(shm, 0x007F)
    ne = (shm >> 7) + 127

    quant_score = (((ne << 7) + nm) << 16)
    
    exp_a = np.frombuffer(quant_score.astype(np.uint32).tobytes(), np.float32())

    exp_c = mant_correction(exp_a)
    
    exp_c = np.where(ne.astype(np.uint32) >= 255, 0, exp_c)
    
    return exp_c

parser = argparse.ArgumentParser()

parser.add_argument("--fpformat"    ,   type = str,     default = "BFLOAT16"    )
parser.add_argument("--bandwidth"   ,   type = int,     default = 128           )
parser.add_argument("--acc_regs"    ,   type = int,     default = 1             )
parser.add_argument("--length"      ,   type = int,     default = 1024          )
parser.add_argument("--range"       ,   type = int,     default = 128           )
parser.add_argument("--monotonic"   ,   type = int,     default = 0             )
parser.add_argument("--step"        ,   type = int,     default = 1             )
parser.add_argument("--vectors"     ,   type = int,     default = 1             )
parser.add_argument("--fixed_point" ,   type = int,     default = 0             )
parser.add_argument("--fx_len"      ,   type = int,     default = 8             )
parser.add_argument("--i_int_bits"  ,   type = int,     default = 4             )
parser.add_argument("--i_is_signed" ,   type = int,     default = 0             )
parser.add_argument("--o_int_bits"  ,   type = int,     default = -4            )
parser.add_argument("--o_is_signed" ,   type = int,     default = 0             )

args = parser.parse_args()

fpformat    = args.fpformat
bandwidth   = args.bandwidth
acc_regs    = args.acc_regs
length      = args.length
range       = args.range
monotonic   = args.monotonic
step        = args.step
vectors     = args.vectors
fixed_point = args.fixed_point
fx_len      = args.fx_len
i_int_bits  = args.i_int_bits
i_is_signed = args.i_is_signed
o_int_bits  = args.o_int_bits
o_is_signed = args.o_is_signed

if fixed_point == 0:
    match fpformat:
        case "BFLOAT16":
            dtype   = torch.bfloat16
            inttype = np.uint32
            bias    = 127
            width   = 2
else:
    match fx_len:
        case 8:
            inttype = np.uint8
            width   = 1

        case 16:
            inttype = np.uint16
            width   = 2

        case 32:
            inttype = np.uint32
            width   = 4

    step    = step * 2**(width - i_int_bits - i_is_signed)

final_scores_np     = np.empty(0, dtype = inttype)
final_baseline_np   = np.empty(0, dtype = inttype)
denominators        = []

# if the format we are using is BF16 flush denormal numbers
if fpformat == "BFLOAT16":
    torch.set_flush_denormal(True)

bw_el = (bandwidth // (width * 8))

for i in np.arange(0, vectors):
    fmax = float("-inf")
    sum32 = torch.Tensor([0]).float()
    partial_sums = torch.zeros(acc_regs, dtype = torch.float32)
    sum_index = 0

    if fixed_point == 0:
        if monotonic == 0:
            scores = torch.cat((torch.empty(length, dtype = dtype).uniform_(0, range), torch.zeros(length % bw_el, dtype = dtype)))
        else:
            scores = torch.cat(torch.arange(0, length * step, step, dtype = dtype), torch.zeros(length % bw_el, dtype = dtype))
    else:
        if monotonic == 0:
            scores = torch.cat((torch.empty(length, dtype = dtype).uniform_(0, range), torch.zeros(length % bw_el, dtype = dtype)))
        else:
            scores = torch.cat(torch.arange(0, length * step, step, dtype = dtype), torch.zeros(length % bw_el, dtype = dtype))

        (torch.from_numpy(scores.astype(np.float64)) / 2**(fx_len - i_int_bits - i_is_signed)).to(dtype)

    for k in np.arange(scores.shape[0] // bw_el):
        input = scores[bw_el * k : bw_el * (k + 1)]

        loc_max = input.max()

        if  loc_max > fmax:
            partial_sums = partial_sums * torch.Tensor(exponentiate((fmax - loc_max)))
            fmax = loc_max

        partial_sums[sum_index] += torch.from_numpy(exponentiate(input - fmax)).sum()
    
        if sum_index == acc_regs - 1:
            sum_index = 0
        else:
            sum_index += 1

    den = partial_sums.sum().numpy()

    denominators.append(den.item())

    den_sign, den_mant, den_exp = decompose(den)
    
    if den_mant == 0:
        inv_appr = np.frombuffer(((2 * bias - den_exp) << 23), np.float32)
    else:
        mant_inv = np.bitwise_and(np.bitwise_not(den_mant), 0b000000001111111, dtype = np.uint32)
        inv_appr = np.frombuffer(((2 * bias - den_exp - 1) << 23) + (mant_inv * ((mant_inv >> 1)) << 10) , np.float32)
    
    inv_appr = inv_appr * (2 - inv_appr * den) 
    inv_appr = inv_appr * (2 - inv_appr * den) 
    
    inv_appr = torch.from_numpy(inv_appr).bfloat16()
    
    res = torch.from_numpy(exponentiate(scores - fmax)).bfloat16() * inv_appr

    if fixed_point == 1:
        scores * 2**(fx_len - o_int_bits - o_is_signed)

    if fpformat == "BFLOAT16":
        scores_np   = (np.frombuffer(scores.float().numpy(), np.uint32) >> 16).astype(inttype)
        baseline_np = (np.frombuffer(res.to(dtype).float().numpy(), np.uint32) >> 16).astype(inttype)
    else:
        scores_np   = np.frombuffer(scores.numpy(), inttype)
        baseline_np = np.frombuffer(res.to(dtype).numpy(), inttype)

    final_scores_np    = np.append(final_scores_np, scores_np)
    final_baseline_np  = np.append(final_baseline_np, baseline_np)


with open("sw/golden-model/scores.h", "w") as file:
    file.write("#ifndef __SOFTEX_SCORES__\n")
    file.write("#define __SOFTEX_SCORES__\n\n")

    file.write(f"#define LENGTH  {length}\n\n")

    file.write(f"#define FMT_WIDTH  {width}\n\n")

    file.write(f"#define N_VECTORS  {vectors}\n\n")

    if fixed_point:
        file.write(f"#define INPUT_INT_BITS  {i_int_bits}\n\n")
        file.write(f"#define INPUT_SIGNED  {i_is_signed}\n\n")
        file.write(f"#define OUTPUT_INT_BITS  {o_int_bits}\n\n")
        file.write(f"#define OUTPUT_SIGNED  {o_is_signed}\n\n")
    
    file.write("#define SCORES {    \\\n")

    for i in final_scores_np:
        file.write(f"   0x{i:04x},    \\\n")

    file.write("}\n\n")

    file.write("#endif")

with open("sw/golden-model/golden.h", "w") as file:
    file.write("#ifndef __SOFTEX_GOLDEN__\n")
    file.write("#define __SOFTEX_GOLDEN__\n\n")
    
    file.write("#define GOLDEN {    \\\n")

    for i in final_baseline_np:
        file.write(f"   0x{i:04x},    \\\n")

    file.write("}\n\n")

    file.write("#endif")

with open("golden-model/golden_sum.txt", "w") as file:
    for i in denominators:
        file.write(f"{i}\n")

with open("golden-model/golden.txt", "w") as file:
    for i in final_baseline_np:
        file.write(f"{i}\n")
