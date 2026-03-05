# Vector-Core Documentation Homepage
Author: Vedant Sharma

Revision #: 0.1.0

Page Status: Under Active Development


## Introduction

Hello, and welcome to the Vector-Core Documentation page of Atalla. 

The Vector-Core is a custom datapath for the Atalla Accelerator created in order to take advantage of Data Level Parallelism (DLP). Vector-Core does this by performing compute upon vector-elements, effectively utilizing Single Instruction Multiple Data operations to increase performance. The design enables parallel execution of identical operations commonly used in AI workloads across multiple execution lanes.

This page serves as both a technical reference and centralized hub for the Architecture, RTL Diagrams, Verification Methodology, Synthesis Reports, Presentations, and Reports related to the Vector-Core Subsystem.

The goal of this page is to provide clear documentation of the work being done, onboarding material for new contributors, and detailed specifications for active development of Vector-Core.

 - **New to Vector-Core?**

    Take a look at the onboarding guide for a bit of background, architectural overview, and primer material resources to help get started. 

 - **Working on Vector-Core?**

    View and/or update active projects, development branches, and documentation tied to Vector-Core.

 - **View High-Level Architecture**

    View the current Vector-Core architecture.

 - **View Past Documentation**

    View prior reports, presentations, and posters created by the Vector-Core team.

-----------------------------------------------------------

## Onboarding Guide

This is for new students joining the Vector-Core in order to provide ample resources to catch up on the current state of Vector-Core and getting started. The material provided here is highly reccommended to review as it can aid in understanding of design choices and give you the knowledge to start contributing.

 1. Medium - SIMD Primer Article (Recommended Starting Point)

	An article covering starter concepts for SIMD Architecture, provides easy to follow visual examples. Gives a high-level explanation behind the basic premises of Vector-Core and why it's necessary in Atalla. Would recommend reading this article before diving in-depth through the Fall 2025 Report and the Onur Mutlu Lecture.

        https://medium.com/e4r/a-primer-to-simd-architecture-from-concept-to-code-d3cc470d6709

 2. Vector-Core Fall 2025 Report

    The Fall 2025 Vector-Core team's Final Report, if you want to be a master of understanding the base of vector-core, this is the place to look. Although certain designs may have changed it will still provide value in learning design processes. Try to see if you can figure out optimizations on your own, or compare the prior designs to current designs, observe the flaws and how they were fixed.

	    https://docs.google.com/document/d/1cg5F1VhrnKALM-ZJHYC2e-JDQ-3BDk2Ngdvvg9fJhPw/edit?usp=sharing

 3. **ETH Zürich Lecture: SIMD Architecture**

    A detailed lecture covering different SIMD architecures such as a Vector Processing Unit, the limitations & challenges that come with Vector-Processing, and key concepts such as Amdahl's Law. Note that this lecture covers many different topics and is generic, not *specific* to the Vector-Core.

        https://www.youtube.com/watch?v=S2pWIB7KO-A&list=PL5Q2soXY2Zi8tTLVb-9CUHcfKXLWESjOD&index=34

Once having sufficient background, take a look at some of the presentations or any of the latest design reviews/reports.

-----------------------------------------------------------


## Vector-Core Architecture

This section provides a general overview of the structure of Atalla Ax01 and within it Vector-Core.
For detailed RTL diagrams regarding microarchitecture of the various units in Vector-Core visit the subsection called Microarchitecture. -> [Microarchitecture](#microarchitecture)

    * Note: Students currently working on Vector-Core, please try to keep this as up-to-date as possible. 

 ## Atalla Ax01

 (Insert Atalla Ax01 Top level here)

 ## Vector-Core Top Level

 (Insert Vector Top level here)

 Global Systolic Array Unit (GSAU):

 Reduction Unit:

 ### Microarchitecture

 ## Lane Top Level

 (Insert Lane Top level here)

 ## ALU

 ## Multiplier

 ## Divider
 The Vector-Core Divider is a fully pipelined floating-point division unit optimized for the BF16 (Brain Floating Point) format. Rather than using slow, traditional digit-recurrence algorithms (like SRT or restoring division) which require long and deep subtraction chains, the Vector-Core implements the **Goldschmidt Division Algorithm**. 

To optimize for different PPA (Power, Performance, Area) targets within the accelerator, the Vector-Core features two distinct divider architectures that share the same underlying algorithm: an Area-Optimized 2-Multiplier design, and a Throughput-Optimized 3-Multiplier design.

### Shared Algorithm & The "Magic Number"
The Goldschmidt algorithm computes N / D by repeatedly multiplying both the numerator (N) and denominator (D) by a sequence of factors (F) such that the denominator converges toward 1.0. As D approaches 1.0, N approaches the final quotient.

To minimize the hardware iterations required, the algorithm needs a highly accurate initial guess of the reciprocal (1/D). Instead of wasting silicon area on a large Lookup Table (LUT) for this initial guess, both divider architectures utilize a **Constant Subtraction Trick (Magic Number)**. By exploiting the structure of the IEEE-754 / BF16 floating-point format, we can approximate the inverse by subtracting the denominator from a magic constant:

`new_f = 16'h7EF3 - new_muld;`

This specific magic number (`16'h7EF3`) flips the mantissa bits to yield an initial approximation of 1/D that is accurate enough to require **only 2 hardware iterations** to achieve BF16 precision within a maximum of 2 ULP.

**The Iteration 2 Optimization:**
Because the algorithm only requires 2 iterations, the mathematical sequence looks like this:
* **Iteration 1:** N1 = N * F0 |
                   D1 = D * F0 |
                   F1 = 2.0 - D1

* **Iteration 2:** N2 = N1 * F1 |
                   D2 = D1 * F1

### 2 Multiplier Design
*Primary Author: Akhil Yada*

This architecture instantiates **2 Multipliers and 1 Subtractor** and utilizes a Loopback Pipeline Architecture (a "Carousel") to share the hardware across both iterations.

#### Hardware Architecture (The Carousel)
Data makes two passes through the same shared hardware blocks. The pipeline depth is meticulously tuned to match the internal latency of the locked arithmetic Hard IPs:
* The `mul_bf16` Wallace tree multipliers compute in **1 clock cycle**.
* The `add_bf16` subtractor computes in **2 clock cycles**.

To keep the control signals (exponents, signs, NaN flags) synchronized with the math, the wrapper shift registers are expanded to exactly **5 Stages**:
* **Stage 1 & 2:** Data enters and exits the multipliers.
* **Stage 3, 4, & 5:** Data (The denominator) enters, traverses the internal registers, and exits the subtractor. (The numerator rides a parallel 3-deep delay line `delay_n1_3:5` to stay synced).

#### Traffic Control & The FIFO
Traffic control was a challenge in this architecture. Because the pipeline holds 5 instructions in flight, data finishing its 5th stage must loop back to Stage 1, colliding with new input data. 

* **The Priority Arbiter:** A Stage 0 multiplexer gives absolute priority to Loopback traffic (`loopback_req`). If an instruction is looping back for Iteration 2, the Arbiter drops the `ready_in` signal, which stalls upstream to prevent data collision.
* **The FIFO:** To handle backpressure and decouple `ready_out` from `ready_in` a **8-Deep FIFO** was placed at the output. The math blocks are hardwired to free-run as they cannot stall in place. This comes with the benefit of being able to finish in flight operations during backpressure, increasing throughput.
* **Safety Throttle:** The FIFO monitors its own fullness. Because there are exactly 5 stages in flight inside the math units, the input throttle triggers the moment the FIFO holds 3 items (8 - 5 = 3). This guarantees that even if the input shuts off instantly, the 5 active instructions have a safe place to land.

#### Performance
Because every division must pass through the shared 1-cycle multipliers and 2-cycle subtractor twice (consuming 50% of the datapath's bandwidth for loopbacks), the theoretical maximum throughput is 0.5 instructions per cycle. In testing, the divider successfully achieves an **Effective CPI of 2.0**. It also acheieves a max ULP of 2.0 and a average ULP of around 0.5.

### 3 Multiplier Design
*Primary Author: Brian Zhuang*

This architecture instantiates **3 Multipliers and 1 Subtractor** and is completely pipelined. 

#### Hardware Architecture
Data makes two total multiplication processes, first through one pair of multipliers, then the final multiplier for the second iteration:
* The `mul_bf16` Wallace tree multipliers compute in **1 clock cycle**.
* The `add_bf16` subtractor computes in **2 clock cycles**.

To match the timing requirement, the pipeline is split up to **9 Stages**:
* **Stage 1, 2:** Initial exponent difference calculated. Data enters the multipliers, numerator and denominators getting their own multiplier, and is multiplied by the magic number. Output is latched in stage 2 for next process.
* **Stage 3, 4, 5:** Data (The denominator) enters, traverses the internal registers, and exits the subtractor. Latches output value at stage 5.
* **Stage 6, 7:** The numerator from stage 2 is multiplied by the new "guess" from stage 5. Latches output value at stage 7.
registers, and exits the subtractor. Latches output value at stage 5.
* **Stage 8, 9:** Final exponent is calculated from initial exponent calculation in stage 1. Final answer then is latched in stage 9, into a FIFO in case of back pressure. 

#### Traffic Control & The FIFO
The primary struggle with traffic control was the fact that the subtraction module lacked true stall capabilities. As such a FIFO was implemented to catch the latched output and ensure it is correctly outputted at the right time. 

* **The FIFO:** To handle backpressure and decouple `ready_out` from `ready_in` a **16-Deep FIFO** was placed at the output. The subtraction block doesn't properly stall, so the pipeline cannot stall conventionally. This comes with the benefit of being able to finish in flight operations during backpressure, increasing throughput.The FIFO monitors its own fullness. It will keep reading from the FIFO so long as there is a valid value inside, and write a value as long as its valid. When valid values are able to be outputted, but the reciever is not ready for a new value, pause is triggered.
* **Pause:** Pause will not stop the pipeline, merely introduce bubbles into and sends a low ready_in signal until it unpauses, which will not get written into the FIFO. The pause will only stop when new outputs are accepted.

#### Performance
he divider being fully pipelined achieves an **Effective CPI of 1.0** with max throughput. It also acheieves a max ULP of 2.0 and a average ULP of around 0.5, a value slightly lower than predicted.

 ## Exponential

 ## Square Root

### Integration Methodology

 ## L1 Integration

L1 Integration consists of coalesscing all the written SystemVerilog RTL that the Vector-Core consists of and making sure the datapath fully executes without any issues, this is formally done through the use of ready/valid handshaking. In L1 integration the Vector-Core team is simulating the other components of Atalla to drive inputs and propagate outputs, this include Scratchpad, Scheduler, and Systolic Array.

 ## L2 Integration

L2 Integration sits on top of L1, and consists of dropping in SystemVerilog RTL for the simulated Scratchpad and Systolic Array. The design will then be verified using the same test-cases with more add-ins to come for edge cases.

 ## L3 Integration

L3 Integration is the last step of the integration process where all of Atalla is properly being integrated and tested with performance counters running throughout the accelerator in order to get proper analysis for debugging and optimization purposes.

**Note:** Lots of documentation is yet to be inputted due to active branches being constantly reworked. Once base level of arithmetic units is complete this documentation page can truly be done. For noe I've written this abstracted template and saved the RTL's I'll be uploading. @Vector-Core Members, please let me know when active branches for arithmetic units are done so I can simply drop in your documentation and names of your dev branches, while linking the main branch with your working unit.