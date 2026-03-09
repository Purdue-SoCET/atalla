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