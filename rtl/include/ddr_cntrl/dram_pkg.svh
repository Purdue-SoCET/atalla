`ifndef DRAM_PKG_SVH
`define DRAM_PKG_SVH

package dram_pkg;

    //Hoho

    parameter ID_NUM = 8; 
    parameter BANK_NUM = 16;
    parameter STQ_DEPTH = 8;
    parameter LQ_DEPTH = 8;
    

    // WORD SIZE
    parameter WORD_W            = 64;

    // CONFIGS
    parameter CONFIG_BITS = 2;
    
    // ADDRESS PARAMETERS
    parameter RANK_BITS         = 1;
    parameter BANK_GROUP_BITS   = 2;
    parameter BANK_BITS         = 2;
    parameter ROW_BITS          = 15;
    parameter COLUMN_BITS       = 10;
    parameter OFFSET_BITS       = 2;
    parameter IGNORE_BITS       = 1;
    parameter ADDR_BITS    = 14; //TODO: Need to take a look for ROW/COL/ADDR interface

    // TIMING PARAMETERS for x8
    parameter tRCD = 10;
    parameter tAL = 1;
    parameter tCL = 10;
    parameter tBURST = 4;
    parameter tCWL = 10;
    // parameter tREFI = 96000; //The actual value is ___, but we put __ for observing
    parameter tREFI = 250; //The actual value is ___, but we put __ for observing
    parameter tRP = 10;
    // parameter tRFC = 10;
    parameter tRFC = 172;  //This is not the actual __ value, but we put it for solving timing constraint
    parameter tRAS = 45; //tns 1.5ns -> 25 cycles
    parameter tRC = tRAS + tRP;
    parameter tRL = tAL + tCL;        // Read Latency
    parameter tCCD_L = 2; // 8 CLK, 800 MHz = 10ns -> 2CLK CYCLE FOR TESTING
    parameter tCCD_S = 1; // 4 CLK, 800 MHz = 5ns -> 1CLK CYCLE FOR TESTING 
    //Tri debug

    parameter tWR = 12;//tWR should be 10 but work for 12 //tCK 1.5ns -> 10, tCK 1.25ns 12 cycles, tCK 0.833ns 18 cycles
    parameter tWL = tAL + tCWL;       // Write Latency

    //INITIALIZE TIME
    parameter tRESET        = 80;
    parameter tPWUP         = 80;
    parameter tRESETCKE     = 80;
    parameter tPDc          = 3;
    parameter tXPR          = 217;
    parameter tDLLKc        = 597;
    parameter tZQinitc      = 1024;
    parameter tMOD          = 25;

    // BARB
    parameter tFAW          = 20; // DDR4-1600 20ns 16CLK(1kb page) 28CLK(2kb page)

    // word_t
    typedef logic [WORD_W-1:0] word_t;

    // configs_t - x4, x8, x16
    typedef enum logic [CONFIG_BITS-1:0] {
        x4  = 2'b00,
        x8  = 2'b01,
        x16 = 2'b10
    } configs_t;



    typedef enum logic [4:0] {
        POWER_UP,
        PRE_RESET,
        RESET,
        NOP,
        LOAD_MODE_DLL,
        LOAD_BG0_REG3,
        LOAD_BG1_REG6,
        LOAD_BG1_REG5,
        LOAD_BG1_REG4,
        LOAD_BG0_REG2,
        LOAD_BG0_REG1,
        LOAD_BG0_REG0,
        ZQ_CL,
        IDLE,
        ACTIVATE,
        ACTIVATING,
        WRITE,
        WRITING,
        PRECHARGE,
        PRECHARGING,
        READ,
        READING,
        REFRESH,
        REFRESHING
    } dram_state_t; 

    //CMD FSM States
    typedef enum logic [3:0] {
        PWR_UP,
        FSM_IDLE,
        ACT,
        ACTing,
        FSM_READ,
        READing,
        FSM_WRITE,
        WRITEing,
        PRE,
        PREing,
        REF,
        REFing
    } fsm_t;

    // {cs, act, ras, cas, we}
    typedef enum logic [4:0] {
        POWER_UP_PRG  = 5'b01111,
        LOAD_MODE_CMD = 5'b01000,
        REFRESH_CMD   = 5'b01001,
        PRECHARGE_CMD = 5'b01010,
        ACTIVATE_CMD  = 5'b00xxx,
        WRITE_CMD     = 5'b01100,
        READ_CMD      = 5'b01101,
        ZQ_CMD        = 5'b01110,
        DESEL_CMD     = 5'b11000
    } cmd_t;


// BQ -> FSM struct
typedef struct packed {
    logic [ROW_BITS-1:0]       row;
    logic [COLUMN_BITS-1:0]    column;
    logic                      write;
    logic [$clog2(ID_NUM)-1:0] id_addr;
} bq_slot_t;

// AXI -> LQ/STQ (LQ/STQ have the same struct, but diff signal names)
typedef struct packed {
    logic [3:0]                  len;
    logic [$clog2(ID_NUM) - 1:0] id;
    logic [31:0]                 addr;
} lstq_slot_t;

// AXI->WDQ
typedef struct packed {
    logic [7:0] wstrb; // -> WQ
    logic [63:0] wdata; // -> WQ
    logic [$clog2(ID_NUM)-1:0] wid; // WQ
    logic [2:0] wlen;
} wdq_slot_t; 


endpackage

`endif // DRAM_PKG_SVH
