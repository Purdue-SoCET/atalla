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

   - Main DRAM Branch: https://github.com/Purdue-SoCET/atalla/tree/ddr_cntrl

  **Architecture Overview**
  The design of Non-blocking Memory Controller was based around using queues and arbiters to maximize the throughput of data. Memory requests flow in from the split-transaction AXI, which then connect to the Read ID and Load Queue (Load Requests), as well as the Write Data and Store Queue (Store Requests). These requests are processed through a frontend arbiter, which balances the ratio of request types, and the backend arbiter, which uses a Command FSM to determine the timing of bank/bank group activation and readiness. This then allows for multiple requests to occur in flight.

  **Key Files**

  ```
  └── rtl/
      ├── include/
      │   └── ddr_cntrl/
      │       ├── dram_pkg.svh           # Package definitions (timings, commands)
      │       └── ddr_controller_if.sv   # Top-level interface for the controller
      ├── modules/
      │   ├── common/
      │   │   └── general/
      │   │       └── fifo.sv            # Generic FIFO utility
      │   └── ddr_cntrl/
      │       ├── ddr_controller_wrapper.sv # Top-level module integration
      │       ├── frontend_arb_nb.sv     # AXI front-end arbitration logic
      │       ├── address_mapper.sv      # AXI address to DRAM Rank/Bank/Row/Col
      │       ├── nb_store_queue.sv      # Store queue for non-blocking writes
      │       ├── load_queue_nb.sv       # Load queue for non-blocking reads
      │       ├── nb_bank_queue.sv       # Bank-specific transaction tracking
      │       ├── cmd_fsm_nb.sv          # Main Command FSM for DDR protocols
      │       ├── fsm_module.sv          # Sub-FSM logic components
      │       ├── nb_barb.sv             # Bank Arbiter for Command Generator
      │       ├── refresh_counter.sv     # Periodic refresh management
      │       ├── nb_wdata_wrapper.sv    # Write data path integration
      │       ├── nb_wdata_queue.sv      # Buffering for write data
      │       ├── nb_read_id_queue.sv    # Tracking AXI IDs for out-of-order reads
      │       ├── flex_counter.sv        # Parametric counter utility (With rollover)
      │       ├── flex_sr.sv             # Parametric shift register
      │       ├── priority_enc.sv        # Priority encoder for arbiters
      │       └── enum_compare.sv        # Comparison logic for FSM states
  └── tb/
    └── unit/
        └── ddr_cntrl/
            └── testbench/               
                ├── dram_top_tb.sv            # Top - this connects to Micron TB  
                ├── frontend_tb.sv            # Frontend
                ├── init_state_tb.sv          # State Machine tb
                ├── nb_barb_tb.sv             # Backend Arbiter
                ├── nb_wdata_queue_tb.sv      # Write Path Queue
                └── refresh_counter_tb.sv     # Simulation
  ```

  **Usage**
  Within the scripts folder(`scripts/ddr_cntrl`), there are TCL scripts to run the various modules as well as the top level. Using them only requires that the same Makefile that is found in the branch to be used, specifically the section that reads
  ```
  ## Example: 
  ## 		make run FILE=./scripts/xbar/benes_rom/verify.tcl
  ## 		make run FILE=./scripts/memory/scratchpad/swizzle/verify.tcl
  run:
    vsim -do "source $(FILE)"
  run_sim:
    vsim -c -do "source $(FILE)"
  ```
  - Use the scripts as a base to iterate, with -c to test for command line only (i.e. debugging compilation/elaboration errors) 
  - This model uses the Micron TB found within the protected_modelsim folder, so it is necessary for the folder to be in the branch during operation - **WARNING: THE TOP LEVEL CAN ONLY BE RAN WITH A SPECIFIC BASHRC WRITTEN BELOW**
  ```
    # Check that shell is interactive
    [[ $- == *i* ]] || return
    HOSTNAME=$(hostname)

    if [ ${HOSTNAME} == "asicfab.ecn.purdue.edu" ]; then
      source /package/asicfab/AccountSetup/init.bash

      alias ls="ls --color"
      alias ll="ls -la"


      export COPYBUFFER=/package/asicfab/CopyBuffer
      export MODULEPATH=/package/asicfab/AccountSetup/modulefiles:$MODULEPATH
      export PATH=$HOME/.local/bin:$PATH # for python packages
      unset PYTHONPATH
      # For fusesoc + Questa usage
      export MODEL_TECH="$(dirname $(which vsim))"

      ###### CUSTOM CHANGES BELOW THIS LINE #######
      module load git/2.18.0 gcc/11.2.0 python3/3.11
      module load riscv-gcc verilator/5.028 gtkwave
      module load cadence/xcelium/23.03 siemens/questa/2021.4 intel/quartus-std
      module load lcov
    elif [ ${HOSTNAME} == "asicfabu.ecn.purdue.edu" ]; then
      module load verilator gtkwave surfer lcov
    else
      echo "Unknown host ${HOSTNAME}; not loading modules"
    fi



    # Set prompt
    source $HOME/.bash/git-prompt.sh
    export GIT_PS1_SHOWDIRTYSTATE=true
    export GIT_PS1_SHOWSTASHSTATE=true
    export GIT_PS1_SHOWCOLORHINTS=true
    export PROMPT_COMMAND='__git_ps1 "\[\e]0;\u@\h: \w\a\]\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]" "\$ "'
  ```
  - The assumption is made that the regular asicfab setup as already been completed for this to work. Note - while the bashrc may look similar, no work has been done to truly determine why top doesn't work with the regular bashrc. Future work can be done to check why before iterating on this design.

  **Design Documentation/Resources**

  This section links any documentation or resources that was used specific for this design. This includes meeting notes, design logs, research papers, etc. 

  - https://ieeexplore.ieee.org/document/7108455
  - https://cdn.discordapp.com/attachments/1412834335983272129/1421965427600392203/dram_controller_non_block_idea.pdf?ex=69792800&is=6977d680&hm=67a75be2ec3b113caa3017cc4007acdce61c7919d64f179cc3b22d7cfcef2005&
  - DDR4 MICRON Model: https://drive.google.com/file/d/1CKYhZJe7rzhp_2ATkkAfWrufMl-Lt6jW/view?usp=sharing

### Split-Transaction Interconnect

  **Description**: The goal of this project is to design a split-transaction memory bus that can manage simultaneous in-flight requests from caches/scratchpad and simultaneous in-flight responses from the DRAM controller.

  **Contributors**

  - Aryan Kadakia (kadakia0@purdue.edu)
  - Xinyu Liu (liu3680@purdue.edu)

  **RTL Diagrams**
  
  This sections links the location of all Block-/RTL-diagrams that were made for this design: https://app.diagrams.net/#G18bqekF9I8oZJpSTm-BcsDvPkOPy_cdul#%7B%22pageId%22%3A%22fpKTT8HEuwSpTkvlEaWT%22%7D

  **Active Branches**

  This section links the location of active branches that are being used for the design: 

  - Aryan Kadakia's Branch: https://github.com/Purdue-SoCET/atalla/tree/memory_subsystem_aryan#
  - Main DRAM Branch: https://github.com/Purdue-SoCET/atalla/tree/memory_subsystem_dram

  **Verification**

  This section links the location of verification related documents like verification plans: 

  **Design Documentation/Resources**

  This section links any documentation or resources that was used specific for this design. This includes meeting notes, design logs, research papers, etc. 

  - https://developer.arm.com/documentation/102202/0300/AXI-protocol-overview
  - https://www.cis.upenn.edu/~cis5710/spring2024/slides/13_axi.pdf

    
### Ramulator Integration and Verification

  **Description**

  The Ramulator Integration project builds an AXI4-compliant wrapper around the Ramulator2 cycle-accurate DRAM simulator, allowing the full Atalla memory subsystem (caches, scratchpads, AXI bus) to be verified against realistic DRAM timing without designing a new memory controller for each DRAM standard. Swapping a YAML configuration file is all that is required to switch between DDR4, HBM3, or any other standard that Ramulator2 supports, making it the primary verification and design-space exploration vehicle for the DRAM team.

  **Why This Was Built**

  Every time the team wanted to test a different DRAM standard or configuration, a new RTL controller had to be designed and verified from scratch. This project eliminates that cost by wrapping Ramulator2 — which already models DDR4, HBM2, HBM3, LPDDR5, and others — behind a fixed AXI4 interface. The rest of the system never changes; only the YAML config changes. The wrapper is also intended to become the long-term DRAM interface for the Atalla TPU as the project matures.

  **Architecture Overview**

  The integration consists of two tightly coupled layers:

  - **SV Wrapper** (`rtl/modules/memory/ramulator_wrapper/ramulator_sv_wrapper.sv`): An AXI4 subordinate that accepts AR/R/AW/W/B channel traffic from the memory bus. It manages a Re-Order Buffer (ROB) for burst reads, a serial FIFO for single-beat reads, and all flow-control backpressure signals. It communicates with Ramulator exclusively through DPI-C function calls.

  - **C DPI Bridge** (`rtl/modules/memory/ramulator_wrapper/ramulator_dpi.cpp`): Implements all DPI-C functions called by the SV wrapper. It instantiates Ramulator2, maintains a functional memory model for immediate write forwarding and partial-write merging, and coalesces burst read beats into single DRAM CAS commands to reduce row activations.

  The DRAM standard and timing parameters are fully specified by a YAML configuration file passed at simulation start. No RTL changes are needed when switching standards.

  **Tools and Frameworks**

  | Tool | Purpose |
  |------|---------|
  | [Ramulator2](https://github.com/CMU-SAFARI/ramulator2) | Cycle-accurate DRAM simulator (C++); models DDR4, HBM2, HBM3, LPDDR5, and more |
  | QuestaSim / ModelSim | SystemVerilog simulator; runs the SV wrapper and testbenches |
  | DPI-C | IEEE standard mechanism for calling C/C++ functions from SystemVerilog |
  | CMake + gcc-toolset-14 | Builds `libramulator_dpi.so` from `ramulator_dpi.cpp` and the Ramulator2 sources |
  | Python 3 | Utility scripts: `gen_sdma_meminit.py`, `sweep.sh` result parser |

  **Environment Setup**

  These steps need to be done once per machine before running any simulation.

  1. **Run the setup script** — appends `ATALLA_ROOT` and `UVM_HOME` to your `~/.bashrc`:
     ```bash
     make setup
     source ~/.bashrc
     ```

  2. **Verify gcc-toolset-14 is accessible** — the build requires GCC 14, installed at `/opt/rh/gcc-toolset-14/`. No manual `scl enable` is needed; the Makefile invokes the compiler by absolute path automatically.

  3. **Build the Ramulator DPI shared library** — this compiles `ramulator_dpi.cpp` and all Ramulator2 sources into `libramulator_dpi.so`:
     ```bash
     make ram_lib
     ```
     This step is required before any simulation target and is run automatically by `make sim` and `make sdma`. Expect it to take several minutes on first build; subsequent builds are incremental.

  4. **Generate the SDMA memory init file** — needed only for the SDMA testbench; produces `configs/sdma_meminit.bin`:
     ```bash
     make gen_sdma_meminit
     ```

  **Key Files**

  ```
  rtl/modules/memory/ramulator_wrapper/
  ├── ramulator_sv_wrapper.sv      # AXI4 SV wrapper
  ├── ramulator_dpi.cpp            # C DPI bridge to Ramulator2
  ├── ramulator_dpi.h              # DPI-C function declarations
  ├── gen_sdma_meminit.py          # Generates binary meminit for SDMA test
  └── configs/
      ├── ddr4_config.yaml         # Default DDR4 config
      ├── hbm3_config.yaml         # Default HBM3 config
      ├── ddr4_1ch_128b.yaml       # DDR4 sweep variant: 1 channel, 128-bit bus
      ├── ddr4_1ch_256b.yaml       # DDR4 sweep variant: 1 channel, 256-bit bus
      ├── ddr4_2ch_128b.yaml       # DDR4 sweep variant: 2 channels, 128-bit bus
      ├── ddr4_1ch_512b.yaml       # DDR4 sweep variant: 1 channel, 512-bit bus
      ├── ddr4_4ch_128b.yaml       # DDR4 sweep variant: 4 channels, 128-bit bus
      ├── hbm3_1ch_2pc_32b.yaml    # HBM3: 1 physical channel, 2 pseudochannels
      ├── hbm3_8ch_2pc_32b.yaml    # HBM3: 8 physical channels, 2 pseudochannels
      ├── hbm3_16ch_2pc_32b.yaml   # HBM3: 16 physical channels, 2 pseudochannels
      └── sdma_meminit.bin         # Pre-built 1024×1024 int16 matrix binary

  tb/unit/memory/ramulator_wrapper/
  ├── test_ramulator.sv            # Basic wrapper functional test
  └── test_sdma.sv                 # SDMA matrix-load benchmark

  scripts/
  ├── sweep.sh                     # Runs make sdma across all configs; saves logs to results/
  └── parse_results.py             # Parses results/*.log and writes results/summary.csv
  ```

  **Running Examples**

  All targets build `libramulator_dpi.so` automatically if it is out of date.

  *Basic wrapper test (single config):*
  ```bash
  make sim                                    # DDR4, batch mode
  make sim DRAM=hbm3                          # HBM3, batch mode
  make sim CFG=rtl/modules/memory/ramulator_wrapper/configs/ddr4_1ch_256b.yaml
  make sim GUI=ON                             # open QuestaSim waveform viewer
  ```

  *SDMA matrix-load benchmark (requires meminit):*
  ```bash
  make sdma SDMA_MEMINIT=rtl/modules/memory/ramulator_wrapper/configs/sdma_meminit.bin
  make sdma SDMA_MEMINIT=... BURST=1          # burst read mode
  make sdma SDMA_MEMINIT=... CFG=rtl/modules/memory/ramulator_wrapper/configs/hbm3_config.yaml
  ```

  *Configuration sweep across all DDR4 and HBM3 variants:*
  ```bash
  bash scripts/sweep.sh          # single-beat mode; logs saved to results/*_single.log
  bash scripts/sweep.sh 1        # burst mode;       logs saved to results/*_burst.log
  python3 scripts/parse_results.py results/   # parse logs, print summary table, write results/summary.csv
  ```

  **YAML Configuration**

  Each YAML file fully specifies the simulated DRAM. The key parameters are:

  ```yaml
  MemorySystem:
    DRAM:
      impl: DDR4          # or HBM3, HBM2, LPDDR5, ...
      org:
        preset: DDR4_8Gb
        channel: 1        # number of channels (HBM: counts pseudochannels)
        channel_width: 128  # bus width in bits per channel
      timing:
        preset: DDR4_2400R
  ```

  To add a new configuration, copy an existing YAML from `configs/`, change `impl`, `channel`, `channel_width`, and `timing`, then pass it via `CFG=<path>`.

  **Contributors**

  - Heng-I (Ivor) Chu (chu244@purdue.edu) — SV wrapper, C DPI bridge, functional memory model, testbench, AXI transaction emulator
  - Akram Mohamed (mahmoud6@purdue.edu) — HBM3 support, Ramulator interface

  **Active Branches**

  - Ivor's Branch: https://github.com/Purdue-SoCET/atalla/tree/axi_ramulator_ivor
  - Main Ramulator Branch: https://github.com/Purdue-SoCET/atalla/tree/axi_ramulator_main

  **Verification**

  - `test_ramulator.sv`: Exercises read/write correctness and backpressure handling for the SV wrapper. Tests include read-after-write, raw reads, read/write backpressure, simultaneous read/write, multiple outstanding transactions, all three AXI burst types (INCR, FIXED, WRAP), and byte-strobe partial writes. All read data is checked against a shadow memory reference model.
  - `test_sdma.sv`: Loads a 1024×1024 int16 matrix in both row-major (1024-element rows) and tile-major (32×32-element tiles) order. Reports total cycles, wall time at 800 MHz, cycles per matrix row, cycles per 8-beat transfer, cycles between beats, effective bandwidth in B/cycle, and AR stall percentage.

  **Benchmark Results Summary**

  The SDMA benchmark was run across 8 memory configurations at 800 MHz. Key findings:

  - **More channels beats wider interface**: Going from 1→2→4 DDR4 channels at 128-bit width nearly doubles throughput each step, while widening the interface from 128b to 512b at 1 channel actually *reduces* throughput (wider bus without more parallelism increases stall).
  - **Burst mode helps most under bandwidth pressure**: DDR4 1ch 128b jumps from ~11 B/cycle to ~30 B/cycle switching from single-beat to burst mode. High-bandwidth configs (DDR4 4ch, all HBM3) show little additional gain from burst mode since they are already near peak.
  - **HBM3 reaches ~32 B/cycle with 0% stall even at 1 channel**, comparable to DDR4 4-channel, due to its pseudo-channel architecture and strong bank-level parallelism. Adding more HBM3 channels beyond 1 shows no further improvement on this workload, indicating the memory system is no longer the bottleneck.
  - **Tile-major access helps on bandwidth-limited DDR4** (better row locality reduces bank conflicts) but has negligible impact on high-bandwidth configs where the workload is already compute-bound.

  **Design Documentation/Resources**

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

