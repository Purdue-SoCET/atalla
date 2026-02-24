import torch.nn as nn
import torch


def main():
    input = torch.arange(1,17,  dtype=torch.bfloat16).reshape((4,4))
    layer_norm = nn.LayerNorm([4,4], dtype=torch.bfloat16)
    output = layer_norm(input)
    print(output)
if __name__ == '__main__':
    main()
