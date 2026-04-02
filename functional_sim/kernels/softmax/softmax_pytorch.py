import torch
import torch.nn as nn

def main():
    x = torch.arange(1, 17, dtype=torch.float32).reshape(4, 4)

    softmax = nn.Softmax(dim=1)
    output = softmax(x)

    print(output)

if __name__ == '__main__':
    main()