import torch

def main():
    x = torch.arange(1, 17, dtype=torch.float32).reshape(4, 4)
    y = torch.softmax(x, dim=1)
    y_bf16 = y.to(torch.bfloat16).to(torch.float32)

    # Print as plain numbers
    for r in range(4):
        print(" ".join(f"{y_bf16[r, c].item():.9f}" for c in range(4)))

if __name__ == "__main__":
    main()