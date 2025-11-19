#!/usr/bin/env python3
import argparse
import numpy as np
import tensorflow as tf
import csv

def gen_bf16_add_vectors(num_vectors: int,
                         out_path: str,
                         seed: int = 1337,
                         chunk_size: int = 100_000):
    """
    Generate (a, b, expected) BF16 add test vectors using TensorFlow as golden model.

    - Inputs and outputs are raw BF16 bit patterns (uint16).
    - Arithmetic is performed by TensorFlow's bfloat16 add:
        * Round-to-nearest-even (RNE)
        * FTZ on outputs (no BF16 subnormals)
    """
    rng = np.random.default_rng(seed)

    with open(out_path, "w", newline="") as csvfile:
        writer = csv.writer(csvfile)
        # Header row
        writer.writerow(["a_hex", "b_hex", "expected_hex"])

        remaining = num_vectors
        total_done = 0

        while remaining > 0:
            n = min(remaining, chunk_size)

            # Random raw 16-bit patterns for operands
            a_bits = rng.integers(0, 2**16, size=n, dtype=np.uint16)
            b_bits = rng.integers(0, 2**16, size=n, dtype=np.uint16)

            # Convert to TensorFlow tensors as BF16 via bitcast
            a_u16 = tf.constant(a_bits, dtype=tf.uint16)
            b_u16 = tf.constant(b_bits, dtype=tf.uint16)

            a_bf16 = tf.bitcast(a_u16, tf.bfloat16)
            b_bf16 = tf.bitcast(b_u16, tf.bfloat16)

            # Golden model: BF16 add (TensorFlow handles RNE + FTZ behavior)
            c_bf16 = a_bf16 + b_bf16

            # Bitcast result back to uint16 (raw BF16 encoding)
            c_u16 = tf.bitcast(c_bf16, tf.uint16).numpy().astype(np.uint16)

            # Write rows as zero-padded 4-digit hex (lowercase)
            for i in range(n):
                writer.writerow([
                    f"{int(a_bits[i]):04x}",
                    f"{int(b_bits[i]):04x}",
                    f"{int(c_u16[i]):04x}",
                ])

            total_done += n
            remaining -= n
            print(f"Generated {total_done}/{num_vectors} vectors", flush=True)


def main():
    
    parser = argparse.ArgumentParser(description="Generate BF16 add golden-model test vectors using TensorFlow.")

    parser.add_argument("-n", "--num_vectors",
        type=int,
        default=1_000_000,
        help="Number of random test vectors to generate (default: 1_000_000).",)

    parser.add_argument("-o", "--output",
        type=str,
        default="bf16_add_vectors.csv",
        help="Output CSV path (default: bf16_add_vectors.csv).",)

    parser.add_argument("--seed",
        type=int,
        default=1337,
        help="RNG seed for reproducibility (default: 1337).",)


    parser.add_argument("--chunk_size",
        type=int,
        default=100_000,
        help="Number of vectors to process per chunk (default: 100_000).",)

    args = parser.parse_args()

    print(f"Generating {args.num_vectors} BF16 add vectors "
        f"to {args.output} (seed={args.seed}, chunk_size={args.chunk_size})")

    gen_bf16_add_vectors(
        num_vectors=args.num_vectors,
        out_path=args.output,
        seed=args.seed,
        chunk_size=args.chunk_size,)
    print("Done.")


if __name__ == "__main__":
    main()
