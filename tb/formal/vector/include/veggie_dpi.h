// ============================================================================
// veggie_dpi.h
// DPI-C function for the veggie C++ model
// Owner: Vedant Sharma
//
// SV tb uses to simulate veggie responses to vector_datapath
// ============================================================================
#ifndef VEGGIE_DPI_H
#define VEGGIE_DPI_H

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif

void dpi_veggie_init();
void dpi_veggie_destroy();

void dpi_veggie_tick(svBit rst_n);

void dpi_veggie_set_lane_vs(int idx, uint8_t vs);
void dpi_veggie_set_lane_ren(int idx, svBit ren);

void dpi_veggie_set_lane_vd(int idx, uint8_t vd);
void dpi_veggie_set_lane_wen(int idx, svBit wen);
void dpi_veggie_set_lane_wdata(int idx, svOpenArrayHandle vec);

svBit dpi_veggie_get_lane_valid(int idx);
void  dpi_veggie_get_lane_rdata(int idx, svOpenArrayHandle arr);

void dpi_veggie_set_sys_vs(int idx, uint8_t vs);
void dpi_veggie_set_sys_ren(int idx, svBit ren);

void dpi_veggie_set_sys_vd(int idx, uint8_t vd);
void dpi_veggie_set_sys_wen(int idx, svBit wen);
void dpi_veggie_set_sys_wdata(int idx, svOpenArrayHandle vec);

svBit dpi_veggie_get_sys_valid(int idx);
void  dpi_veggie_get_sys_rdata(int idx, svOpenArrayHandle arr);

void dpi_veggie_set_sp_vs(int idx, uint8_t vs);
void dpi_veggie_set_sp_ren(int idx, svBit ren);

void dpi_veggie_set_sp_vd(int idx, uint8_t vd);
void dpi_veggie_set_sp_wen(int idx, svBit wen);
void dpi_veggie_set_sp_wdata(int idx, svOpenArrayHandle vec);

svBit dpi_veggie_get_sp_valid(int idx);
void  dpi_veggie_get_sp_rdata(int idx, svOpenArrayHandle arr);

void dpi_veggie_set_mask_vs(int idx, uint8_t vs);
void dpi_veggie_set_mask_ren(int idx, svBit ren);

void dpi_veggie_set_mask_vd(int idx, uint8_t vd);
void dpi_veggie_set_mask_wen(int idx, svBit wen);
void dpi_veggie_set_mask_wdata(int idx, uint32_t data);

svBit    dpi_veggie_get_mask_valid(int idx);
uint32_t dpi_veggie_get_mask_rdata(int idx);

void dpi_veggie_set_reduction(uint8_t vd, svBit valid, svOpenArrayHandle vec);

void dpi_veggie_write_vector(uint8_t idx, svOpenArrayHandle vec);
void dpi_veggie_read_vector(uint8_t idx, svOpenArrayHandle arr);
void dpi_veggie_write_mask(uint8_t idx, uint32_t data);
uint32_t dpi_veggie_read_mask(uint8_t idx);

svBit dpi_veggie_get_ready();

#ifdef __cplusplus
}
#endif

#endif