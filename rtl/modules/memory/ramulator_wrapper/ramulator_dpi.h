// ramulator_dpi.h
// Heng-I (Ivor) Chu - ivorchu@gmail.com


#ifndef RAMULATOR_DPI_WRAPPER_H
#define RAMULATOR_DPI_WRAPPER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// opaque pointer returned by ramulator_init
typedef void* ramulator_handle_t;

// Set up Ramulator from a YAML config file. Returns NULL if init fails.
ramulator_handle_t ramulator_init(const char* config_file);

// Try to send a request. Returns 1 if accepted, 0 if the queue is full.
// Write data is stored in the functional model immediately; for reads the
// data field is ignored.
int ramulator_send_request(
    ramulator_handle_t handle,
    unsigned long long addr,
    int req_type,        // 0 = Read, 1 = Write
    int source_id,
    uint64_t data        // write data; ignored for reads
);

// Tick the clock one cycle.
void ramulator_tick(ramulator_handle_t handle);

// Check for a completed read. Returns the 32-byte-aligned base address of the
// beat, or -1 if nothing has finished yet. data_out0..3 are filled with the
// four consecutive 8-byte words at base, base+8, base+16, base+24 from
// functional_mem (the 256-bit R beat). source_id_out echoes the source_id
// from ramulator_send_request.
long long ramulator_check_response(ramulator_handle_t handle,
                                   uint64_t* data_out0, uint64_t* data_out1,
                                   uint64_t* data_out2, uint64_t* data_out3,
                                   int* source_id_out);

// Peek at what's currently stored for an address without issuing a timing
// request. Returns 0 for addresses that were never written. No clock cost,
// so it's safe to call during a write to implement WSTRB read-modify-write.
uint64_t ramulator_read_mem(ramulator_handle_t handle, unsigned long long addr);

// Bulk-load a raw binary image into functional_mem starting at base_addr.
// Reads in 8-byte little-endian chunks; the last beat is zero-padded if the
// file size isn't a multiple of 8. Returns the beat count, or -1 on error.
long long ramulator_load_mem_bin(
    ramulator_handle_t handle,
    const char*        path,
    unsigned long long base_addr
);

// Load from a hex text file. Each data line should be: <addr_hex> <data_hex>
// Lines starting with # or // are skipped. Returns entry count, or -1 on error.
long long ramulator_load_mem_hex(
    ramulator_handle_t handle,
    const char*        path
);

// Returns the memory system clock ratio (DRAM ticks per ramulator_tick() call).
// DDR4 → 2, HBM2 → 1, HBM3 → 1. Use this to size the response drain loop.
int ramulator_get_clock_ratio(ramulator_handle_t handle);

// Cleanup — mostly a no-op, see comments in ramulator_dpi.cpp.
void ramulator_finalize(ramulator_handle_t handle);

// Call this instead of $finish. Ramulator2 leaves the heap in a bad state
// at shutdown, so we skip all destructors with _Exit().
void ramulator_exit(int code);

#ifdef __cplusplus
}
#endif

#endif
