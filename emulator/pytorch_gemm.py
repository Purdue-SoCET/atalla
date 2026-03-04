import torch
import torch.nn.functional as F
import argparse

def main():
    """
    GEMM: C = A * B/W + C
    where A is 4x4 of 1.0, W is 4x4 of 1.0, and initial C is 0.0
    Expected output: 4x4 matrix of 4.0 (since 4 columns times 1.0 each)
    """
    # dtype = torch.bfloat16
    
    # # A (4x4)
    # A = torch.ones(4, 4, dtype=dtype)
    
    # # W (4x4)
    # W = torch.ones(4, 4, dtype=dtype)
    
    # # C (4x4, initialized to 0)
    # C = torch.zeros(4, 4, dtype=dtype)
    
    # # Compute C = A * W + C
    # output = torch.matmul(A, W) + C
    
    # print("PyTorch GEMM Output (bfloat16):")
    # print(output)
    # print("\nExpected: All elements should be 4.0")


    #PARAMETRIZING
    parser = argparse.ArgumentParser()
    parser.add_argument("--rows", type=int, default=32)
    parser.add_argument("--cols", type=int, default=32)
    parser.add_argument("--tiles", type=int, default=1)
    args = parser.parse_args()


    dtype = torch.bfloat16

    W = torch.ones(args.rows, args.cols, dtype=dtype)
    C = torch.zeros(args.rows, args.cols, dtype=dtype)
    for t in range(args.tiles):
            tile_val = float(t + 1)
            A_tile = torch.full((args.rows, args.cols), tile_val, dtype=dtype)
            C = torch.matmul(A_tile, W) + C


    print(f"PyTorch Results ({args.rows}x{args.cols}, {args.tiles} tiles):")
    print(C)

    expected_val = args.cols * sum(float(i+1) for i in range(args.tiles))
    print(f"\nExpected: {expected_val}")
    
    if torch.all(C == expected_val):
        print("PyTorch matches expected")
    else:
        print("MISMATCH")

if __name__ == '__main__':
    main()