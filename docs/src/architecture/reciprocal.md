This implementation was largely based off this research paper

Roy, T. D. (2019). Implementation of Goldschmidt's algorithm with hardware reduction. arXiv preprint arXiv:1909.10154. [https://doi.org/10.48550/arXiv.1909.10154](https://doi.org/10.48550/arXiv.1909.10154)

# Reciprocal Unit Documentation

The Reciprocal Unit largely follows the implemenation outlined in `divider.md`

### Algorithm & LUT
The main difference between the reciprocal unit and the divider lies in the handling of the numerator. Because the numerator is guaranteed to be 1, the need for a multiplier for the numerator is eliminated and the N1 can be effectively written as F0 (the initial guess). With this new area, we can use a small 16-entry LUT to get an initial guess for the factor that will guarantee a max ULP of 1. The initial guess is indexed using the most significant bits of the denominator's manitssa. Below is a code snippet of the generation used to create the LUT.

```
entries = 16
def generate_lut(size):
    step = 1.0 / size
    seeds = torch.zeros(size, dtype=torch.bfloat16)
    for i in range(size):
        a = 1.0 + (i * step)
        b = 1.0 + ((i + 1) * step)
        seeds[i] = 2.0 / (a + b)
    return seeds

lut = generate_lut(entries)

with open("lut_values.txt", "w") as f:
    for value in lut:
        raw_bits = value.view(torch.int16).item()
        hex_val = f"0x{raw_bits & 0xFFFF:04x}"
        f.write(f"{hex_val}\n")
```

**The Iteration 2 Optimization:**
Because the algorithm only requires 2 iterations, the mathematical sequence looks like this:
```
* **Iteration 1:** F0 = LUT guess   
                   D1 = D * F0      
                   F1 = 2.0 - D1

* **Iteration 2:** Result = F0 * F1 
```
### 2 Multiplier Design
*Primary Author: Brian Zhuang*

This architecture instantiates **2 Multipliers and 1 Subtractor** and is completely pipelined. 

#### Hardware Architecture
Data makes two total multiplication processes:
* The `common/arithmetic/multipliers/mul_bf16` Wallace tree multipliers compute in **1 clock cycle**.
* The `common/arithmetic/multipliers/add_bf16` subtractor computes in **2 clock cycles**.

To match the timing requirement, the pipeline is split up to **9 Stages**:
* **Stage 1, 2:** Initial exponent difference calculated. Data enters the multiplier, and is multiplied by the LUT value. Output is latched in stage 2 for next process.
* **Stage 3, 4, 5:** Data (The denominator) enters, traverses the internal registers, and exits the subtractor. Latches output value at stage 5.
* **Stage 6, 7:** The result from stage 2 is multiplied by the new "guess" from stage 5. Latches output value at stage 7.
registers, and exits the subtractor. Latches output value at stage 5.
* **Stage 8, 9:** Final exponent is calculated from initial exponent calculation in stage 1. Final answer then is latched in stage 9 where it is outputted.

Included below is a block diagram (top) and a RTL diagram (below)
![img](img/Recip_unit_diagrams.png)

#### Traffic Control
Backpressure occurs when the downstream consumer (writeback in our case) is not ready to accept the divider's output. When this occurs, the pipe enable signals goes low and stalls through to the upstream producer.

#### Performance
The reciprocal unit being fully pipelined achieves an **Effective CPI of 1.0** with max throughput. It also acheieves a max ULP of 1.0 and a average ULP of around 0.5, a value slightly lower than predicted.

### Results
Below is a table of results for the reciprocal unit. The ULP numbers are pulled from a test of all possible BF16 values (65,536).

| # of 0 ULP | # of 1 ULP | # of 2 ULP | Avg ULP | Max ULP | Total Area (um^2) |
|---|---|---|---|---|---|
| 44,368 | 21,168 | 0 | 0.65 | 1 | 15030.467 |

### Simulation
Below is a picture of the simulated ULP error at each iteration of the Goldschmidt division algorithm using both a magic number and LUT approach. This was simulated using the PyTorch library in Python.

![img](../img/Goldschmidt_ULP_Analysis.jpg)
