# Copyright 2023 ETH Zurich and University of Bologna.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
#
# Andrea Belano <andrea.belano@studio.unibo.it>
#

import numpy as np
import torch
import argparse

parser = argparse.ArgumentParser()

parser.add_argument("--fpformat"    ,   type = str,     default = "BFLOAT16"    )
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
            width   = 2
else:
    match fx_len:
        case 8:
            dtype   = np.uint8
            inttype = np.uint8
            width   = 1

        case 16:
            dtype   = np.uint16
            inttype = np.uint16
            width   = 2

        case 32:
            dtype   = np.uint32
            inttype = np.uint32
            width   = 4

    step    = step * 2**(width - i_int_bits - i_is_signed)

final_scores_np     = np.empty(0, dtype = inttype)
final_baseline_np   = np.empty(0, dtype = inttype)
denominators        = []

# if the format we are using is BF16 flush denormal numbers
if fpformat == "BFLOAT16":
    torch.set_flush_denormal(True)

for i in np.arange(0, vectors):
    if fixed_point == 0:
        if monotonic == 0:
            scores = torch.empty(length, dtype = dtype).uniform_(0, range)
        else:
            scores = torch.arange(0, length * step, step, dtype = dtype)

        scores_64 = scores.double()

        denominator = (scores_64 - scores_64.max()).exp().sum()

        denominators.append(denominator.item())

        baseline = (scores_64 - scores_64.max()).exp() /denominator

        if fpformat == "BFLOAT16":
            scores_np   = (np.frombuffer(scores.float().numpy(), np.uint32) >> 16).astype(inttype)
            baseline_np = (np.frombuffer(baseline.to(dtype).float().numpy(), np.uint32) >> 16).astype(inttype)
        else:
            scores_np   = np.frombuffer(scores.numpy(), inttype)
            baseline_np = np.frombuffer(baseline.to(dtype).numpy(), inttype)

        final_scores_np    = np.append(final_scores_np, scores_np)
        final_baseline_np  = np.append(final_baseline_np, baseline_np)
    else:
        if monotonic == 0:
            scores = (np.random.uniform(0, range, length) * 2**(fx_len - i_int_bits - i_is_signed)).astype(dtype)
        else:
            scores = torch.arange(0, length * step, step, dtype = dtype)

        scores_64 = (torch.from_numpy(scores.astype(np.float64)) / 2**(fx_len - i_int_bits - i_is_signed)).bfloat16().double()

        print(scores_64)

        denominator = (scores_64 - scores_64.max()).exp().sum()

        denominators.append(denominator.item())

        baseline = (((scores_64 - scores_64.max()).exp() / denominator).numpy() * 2**(fx_len - o_int_bits - o_is_signed)).round().astype(dtype)

        baseline_np = baseline

        scores_np = scores

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
