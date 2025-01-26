`ifndef CACHE_COHERENCE_IF_VH
`define CACHE_COHERENCE_IF_VH

`ifdef XCELIUM
`timescale 1ns/100ps
`endif

typedef enum logic[1:0] {  
    MODIFIED,
    EXCLUSIVE,
    SHARED,
    INVALID
} cc_end_state;

localparam BLOCK_SIZE = 2; //Need a way to overwrite this when instansiating module
localparam CACHE_SIZE         = 1024;
localparam ASSOC              = 1;
localparam N_TOTAL_BYTES      = CACHE_SIZE / 8;
localparam N_TOTAL_WORDS      = N_TOTAL_BYTES / 4;
localparam N_TOTAL_FRAMES     = N_TOTAL_WORDS / BLOCK_SIZE;
localparam N_SETS             = N_TOTAL_FRAMES / ASSOC;
//localparam N_TAG_BITS         = WORD_SIZE - N_SET_BITS - N_BLOCK_BITS - 2; //Will add later for tag IO
typedef logic [31:0] word_t;

typedef struct {
    integer invalidated_blocks; // How many times we were invalidated
    integer shared_blocks;      // How many times we send a block to be shared
    integer to_s_transitions;   // How many times we get to share with another cache
    integer to_e_transitions;   // How many times we get exclusive access
} cache_coherence_statistics_t;

interface cache_coherence_if();
    logic abort_bus;
    cc_end_state state_transfer;
    word_t addr;
    logic [32*BLOCK_SIZE-1:0] requested_data;
    logic valid, exclusive, dirty;
    logic write_req; //Cache signifies a read or write miss
    logic snoop_req; //Signifies the bus is trying to snoop
    logic snoop_busy; // Signifies that cache is currently writing to sram array and can't do a tag lookup right now
    logic snoop_hit; //Bus signifies if tag from SRAM array matches a snoop
    logic dWEN; //For write-back

    modport cache(
        input  addr, state_transfer, snoop_req,
        output valid, exclusive, dirty, requested_data, write_req, snoop_hit, dWEN, snoop_busy, abort_bus
    );
    modport coherency_unit(
        output addr, state_transfer, snoop_req,
        input  valid, exclusive, dirty, requested_data, write_req, snoop_hit, dWEN, snoop_busy, abort_bus
    );
endinterface
`endif // CACHE_COHERENCE_IF_VH