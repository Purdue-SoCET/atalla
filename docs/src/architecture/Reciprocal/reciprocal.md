This implementation was largely based off this research paper

Roy, T. D. (2019). Implementation of Goldschmidt's algorithm with hardware reduction. arXiv preprint arXiv:1909.10154. [https://doi.org/10.48550/arXiv.1909.10154](https://doi.org/10.48550/arXiv.1909.10154)

# Reciprocal Unit Documentation

The Scalar-Core Reciprocal unit is a fully pipelined floating-point reciprocal unit optimized for the BF16 (Brain Floating Point) format. Rather than using slow, traditional digit-recurrence algorithms (like SRT or restoring division) which require long and deep subtraction chains, the Vector-Core implements the **Goldschmidt Division Algorithm**.
To optimize for different PPA (Power, Performance, Area) targets within the accelerator, the Scalar-Core features a 2 multiplier, fully pipelined design.

### Algorithm & LUT
The Goldschmidt algorithm computes N / D by repeatedly multiplying both the numerator (N) and denominator (D) by a sequence of factors (F) such that the denominator converges toward 1.0. As D approaches 1.0, N approaches the final quotient.

To minimize the hardware iterations required, the algorithm needs a highly accurate initial guess of the reciprocal (1/D). Instead of wasting silicon area on a large Lookup Table (LUT) for this initial guess, both divider architectures utilize a **Constant Subtraction Trick (Magic Number)**. By exploiting the structure of the IEEE-754 / BF16 floating-point format, we can approximate the inverse by subtracting the denominator from a magic constant:

**The Iteration 2 Optimization:**
Because the algorithm only requires 2 iterations, the mathematical sequence looks like this:
* **Iteration 1:** N1 = 1 * F0 |
                   D1 = D * F0 |
                   F1 = 2.0 - D1

* **Iteration 2:** N2 = N1 * F1 |
                   D2 = D1 * F1

### 2 Multiplier Design
*Primary Author: Brian Zhuang*
This architecture instantiates **2 Multipliers and 1 Subtractor** and is completely pipelined. 

#### Hardware Architecture
Data makes two total multiplication processes, first through one pair of multipliers, then the final multiplier for the second iteration:
* The `common/arithmetic/multipliers/mul_bf16` Wallace tree multipliers compute in **1 clock cycle**.
* The `common/arithmetic/multipliers/add_bf16` subtractor computes in **2 clock cycles**.

To match the timing requirement, the pipeline is split up to **9 Stages**:
* **Stage 1, 2:** Initial exponent difference calculated. Data enters the multiplier, and is multiplied by the LUT. Output is latched in stage 2 for next process.
* **Stage 3, 4, 5:** Data (The denominator) enters, traverses the internal registers, and exits the subtractor. Latches output value at stage 5.
* **Stage 6, 7:** The result from stage 2 is multiplied by the new "guess" from stage 5. Latches output value at stage 7.
registers, and exits the subtractor. Latches output value at stage 5.
* **Stage 8, 9:** Final exponent is calculated from initial exponent calculation in stage 1. Final answer then is latched in stage 9 where it is outputted.

#### Traffic Control
The pipe enable signals controls traffic and goes low when backpressure occurs (when the pipeline fills up).

#### Performance
The divider being fully pipelined achieves an **Effective CPI of 1.0** with max throughput. It also acheieves a max ULP of 2.0 and a average ULP of around 0.5, a value slightly lower than predicted.

### Results
Below is a table of results for the reciprocal unit. The ULP numbers are pulled from a test of all possible BF16 values (65,536).

| # of 0 ULP | # of 1 ULP | # of 2 ULP | Avg ULP | Max ULP | Total Area (um^2) |
|---|---|---|---|---|---|
| 44,368 | 21,168 | 0 | 0.65 | 1 | 15030.467 |

### Simulation
Below is a picture of the simulated ULP error at each iteration of the Goldschmidt division algorithm using both a magic number and LUT approach. This was simulated using the PyTorch library in Python.

![img](img/Goldschmidt_ULP_Analysis.jpg)