# DRAM Subsystem Homepage

## Introduction
The DRAM subsystem exists to provide the Atalla accelerator with access to off-chip memory required by AI workloads that exceed on-chip SRAM limits. Because DRAM access involves strict command sequencing and long latencies, a controller and memory bus are required to manage these accesses. This subsystem's current goals are towards a non-blocking architecture that improves bandwidth by overlapping memory requests.

This page serves as the central home for the DRAM Subsystem. It consolidates RTL diagrams, active projects, reports, presentations, and ramp-up material. Use the links below to navigate based on what you are looking for.

- **New to the DRAM subsystem?**
  
    Follow the ramp-up guide for background, architecture context, and recommended resources -> [Ramp-Up Guide](#ramp-up-guide)

- **Working on the DRAM subsystem?**

    View active projects, current contributors, development branches, and documentation -> [Active Projects](#active-projects)

- **View Past Reports/Presentations?**

    View past reports, presentations, abstracts, and posters made by the DRAM subsystem -> [Past Reports and Presentations](#past-reports-and-presentations)

- **View completed projects?**

  View completed projects by the DRAM subsystem -> [Completed Projects](#completed-projects)
 
-----------------------------------------------------------

## Ramp-Up Guide
This section is for new students joining the DRAM subsystem and serves as a starting point for getting up to speed. It includes background material and resources to help you understand the design and begin contributing.

  1. **Introductory DRAM Overview (Recommended Starting Point)**

     A high-level video explaining the basic structure and operation of DRAM. This is an excellent first exposure and helps build intuition before diving into more technical material.

     https://www.youtube.com/watch?v=7J7X7aZvMXQ&t=47s
    
  2. **Memory Systems: Cache, DRAM, Disk – Jacob, Ng, and Wang**

     Chapters 10-13 are required reading as they provide depth on DRAM organization, timing, and memory system.

     https://purdue.primo.exlibrisgroup.com/discovery/fulldisplay?docid=alma99169138574101081
     
  3. **Understanding DDR4 Timing Parameters**

     A short reference page summarizing DDR4 timing parameters and constraints.

     https://www.systemverilog.io/design/understanding-ddr4-timing-parameters/
     
  4. **JEDEC DDR4 Standard (JESD79-4C)**

     The official DDR4 specification defining all command sequences, timing requirements, and constraints

     https://raw.githubusercontent.com/RAMGuide/TheRamGuide-WIP-/main/DDR4%20Spec%20JESD79-4C.pdf

  5. **ETH Zurich Lecture: DRAM Controllers (Prof. Onur Mutlu)**

     An in-depth lecture covering DRAM controller design, performance challenges, and architectural tradeoffs.

     https://www.youtube.com/watch?v=TeG773OgiMQ

-----------------------------------------------------------

## Active Projects
This section documents the currently active DRAM subsystem projects, including their purpose, implementation status, code locations, and points of contact.

### Non-Blocking DRAM Controller

  **Description**: The goal of this project is to design a non-blocking DRAM controller that allows multiple memory requests to be in flight simultaneously to improve bandwidth utilization. The design uses a row-open policy and bank-specific request queues to hide memory latency and enable memory-level parallelism.

  **Contributors**

  - Jason Lyst (jlyst@purdue.edu)
  - Adrian Buczkowski (abuczko@purdue.edu)
  - Eddie Hu (hu927@purdue.edu)
  - Shams Hoque (hoques@purdue.edu)

  **RTL Diagrams**
  
  This sections links the location of all Block-/RTL-diagrams that were made for this design: https://app.diagrams.net/#G18bqekF9I8oZJpSTm-BcsDvPkOPy_cdul#%7B%22pageId%22%3A%22fpKTT8HEuwSpTkvlEaWT%22%7D

  **Active Branches**

  This section links the location of active branches that are being used for the design: 

   - Main DRAM Branch: https://github.com/Purdue-SoCET/atalla/tree/memory_subsystem_dram

  **Verification**

  This section links the location of verification related documents like verification plans: 

  **Design Documentation/Resources**

  This section links any documentation or resources that was used specific for this design. This includes meeting notes, design logs, research papers, etc. 

  - https://ieeexplore.ieee.org/document/7108455
  - https://cdn.discordapp.com/attachments/1412834335983272129/1421965427600392203/dram_controller_non_block_idea.pdf?ex=69792800&is=6977d680&hm=67a75be2ec3b113caa3017cc4007acdce61c7919d64f179cc3b22d7cfcef2005&
  - DDR4 MICRON Model: https://drive.google.com/file/d/1CKYhZJe7rzhp_2ATkkAfWrufMl-Lt6jW/view?usp=sharing

### Split-Transaction Interconnect

  **Description**

  This is a non-blocing interconnect that borrows idea of AMBA AXI bus. we call it costomized AXI interconnect. It is designed to increase interconnect bandwidth from DRAM to on-chip peripherals. 
  
  The customized interconnect is designed from scratch, without using existing design.

  **Contributors**

  - Aryan Kadakia (kadakia0@purdue.edu)
  - Xinyu Liu (liu3680@purdue.edu)

  **RTL Diagrams**
  
  This draw.io link contains all the submodule and top level RTL diagram of the customized AXI interconnect. If you are asked for access, contact Aryan.

  https://app.diagrams.net/#G1ak1hnCkFTo_PjdCdB6iJGtsUCmu-5aql#%7B%22pageId%22%3A%22wfVu87Kw0Yh81MMMt9Ax%22%7D

  **Active Branches**

  - AXI main branch: https://github.com/Purdue-SoCET/atalla/tree/axi_bus_main
  - AXI Integration Testbench: https://github.com/Purdue-SoCET/atalla/blob/axi_bus_main/tb/unit/memory/axi_bus/axi_tb.sv
  - RTL Design: https://github.com/Purdue-SoCET/atalla/tree/axi_bus_main/rtl/modules/memory/axi_bus
  - Interface/Package: https://github.com/Purdue-SoCET/atalla/tree/axi_bus_main/rtl/include/memory/axi_bus

  **Verification**
  
  - Testbench Flowchart: https://app.diagrams.net/#G1ak1hnCkFTo_PjdCdB6iJGtsUCmu-5aql#%7B%22pageId%22%3A%22-i_NBzUPSbW4Tr8fWsaY%22%7D

  **Design Documentation/Resources**

  - ARM AMBA AXI SPEC: https://developer.arm.com/documentation/ihi0022/k/
  - Fall 2025 Report: https://docs.google.com/document/d/1fIBgyiB3g3OImUYkugq2czNFDmUUhIS_DO6sGcxqxDY/edit?tab=t.0
  - Spring 2026 Report: https://www.overleaf.com/3423373736xqbvxskksvrh#a71e11 
  - SV Testbench Study: https://www.chipverify.com/tutorials/systemverilog

  **What to Run**

  Goto cloned atalla `axi_bus_main` branch. In atalla folder:
  - Run `make axi.wav`. AXI integration testbench wave.
  - Run `make MODULE.wav`. MODULE testbench wave, where MODULE = {axi_read, axi_read_arbiter, axi_write_arbiter, ...}


### Ramulator Simulator

  **Description**: The goal of this project is to understand the ramulator simualtor and design an interface that can connect from the split-transaction bus into the simulator.

  **Contributors**

  - Heng-I (Ivor) Chu (chu244@purdue.edu)
  - Yichen Tian (tian182@purdue.edu)

  **RTL Diagrams**
  
  This sections links the location of all Block-/RTL-diagrams that were made for this design: 
  **Active Branches**

  This section links the location of active branches that are being used for the design: 

   - Main DRAM Branch: https://github.com/Purdue-SoCET/atalla/tree/memory_subsystem_dram

  **Verification**

  This section links the location of verification related documents like verification plans: 

  **Design Documentation/Resources**

  This section links any documentation or resources that was used specific for this design. This includes meeting notes, design logs, research papers, etc. 

  - https://github.com/CMU-SAFARI/ramulator2

-----------------------------------------------------------
## Past Reports and Presentations
This section lists all past final reports, presentations, abstracts, and any other resource that was made by the DRAM subsystem.

**Final Reports**

   - Fall 2025 Final Report: https://docs.google.com/document/d/1fIBgyiB3g3OImUYkugq2czNFDmUUhIS_DO6sGcxqxDY/edit?usp=sharing
   - Spring 2025 Final Report: https://docs.google.com/document/d/1J7sHHt2H2yTATN91Cda57GuU_zQYz0v8/edit?usp=sharing&ouid=112766930685277737014&rtpof=true&sd=true

**Design Review Presentations**

  - Fall 2025 Design Review 1: https://purdue0-my.sharepoint.com/:p:/g/personal/khatri12_purdue_edu/IQDGPSESbApgR6gN1-VNOP-jAaiWMO0WYFC02s4PZF21BJo?e=WBqsit
  - Fall 2025 Design Review 2: https://purdue0-my.sharepoint.com/:p:/g/personal/khatri12_purdue_edu/IQBl4rWfHvqdT4ZHBKWouYAqAawxNiz32_OpBjLJoTGnRlo?e=8q3a8d
  - Spring 2025 Design Review: https://purdue0-my.sharepoint.com/:p:/g/personal/khatri12_purdue_edu/IQCThlgQtvIaQbjwHBnV-sbAAddkki-xSmsUfsxGS6OnpZE?e=lCDwWu

**Abstracts**

  - Fall 2025 Abstract: https://purdue0-my.sharepoint.com/:w:/g/personal/khatri12_purdue_edu/IQANqWleEbkvT5E5I8LGPdeWAcWw7mlhg-Q2tpLF6bX1JFc?e=gO85O0

**Poster Presentation**

  - Fall 2025 Poster Presentation: https://purdue0-my.sharepoint.com/:p:/g/personal/khatri12_purdue_edu/IQC-xhWrYXVmSrW5sevR7zQ1AegyEuAUWBxusv5jGvgEdPo?e=OTz2Ys


-----------------------------------------------------------

## Completed Projects

### Blocking DRAM Controller

  **Description**: The goal of this project is to design a fully functional DRAM Controller that interfaces with a ddr4 model.

  **Contributors**

  - Tri Than (than0@purdue.edu)
  - Dhruv Khatri (khatri12@purdue.edu)

  **RTL Diagrams**
  
  This sections links the location of all Block-/RTL-diagrams that were made for this design: https://app.diagrams.net/#G18bqekF9I8oZJpSTm-BcsDvPkOPy_cdul#%7B%22pageId%22%3A%22fpKTT8HEuwSpTkvlEaWT%22%7D
  
  **Active Branches**

  This section links the location of active branches that are being used for the design: 

  - Tri's Branch: https://github.com/Purdue-SoCET/atalla/tree/memory_subsystem_tri
  - Dhruv's Branch: https://github.com/Purdue-SoCET/atalla/tree/memory_subsystem_dhruv
  - Main DRAM Branch: https://github.com/Purdue-SoCET/atalla/tree/memory_subsystem_dram

  **Verification**

  This section links the location of verification related documents like verification plans: 

  **Design Documentation/Resources**

  This section links any documentation or resources that was used specific for this design. This includes meeting notes, design logs, research papers, etc. 

  - DDR4 MICRON Model: https://drive.google.com/file/d/1CKYhZJe7rzhp_2ATkkAfWrufMl-Lt6jW/view?usp=sharing

  -----------------------------------------------------------

