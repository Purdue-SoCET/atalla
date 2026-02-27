// ============================================================================
// scratchpad_dpi.h
// DPI-C function signatures for the scratchpad C++ model.
// Owner: Vedant Sharma
//
// SV calls each cycle simulating scratchpad memory responses
// to VLSU thru scpad_if.
// ============================================================================
#ifndef SCRATCHPAD_DPI_H
#define SCRATCHPAD_DPI_H

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif

void dpi_scratchpad_init();
void dpi_scratchpad_destroy();


void dpi_scratchpad_set_request(
    int   port,
    svBit valid,
    svBit wen,
    uint8_t addr,
    uint8_t row_id,
    uint8_t col_id,
    uint8_t num_rows,
    uint8_t num_cols, // Still adding j bc akshath said do it anyway
    svBit row_or_co     // 0 = row mode, 1 = col mode
);

void dpi_scratchpad_set_wdata(int port, svOpenArrayHandle vec);

void dpi_scratchpad_tick(svBit rst_n);

svBit dpi_scratchpad_get_valid(int port);

void dpi_scratchpad_get_rdata(int port, svOpenArrayHandle arr);

#ifdef __cplusplus
}
#endif

#endif