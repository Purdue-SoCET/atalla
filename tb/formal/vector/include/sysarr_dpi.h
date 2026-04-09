// ============================================================================
// sysarr_dpi.h
// DPI-C function signatures for the systolic array C++ model.
// Owner: Vedant Sharma
//
// SV testbench sims systolic array to RTL of GSAU control unit
// ============================================================================
#ifndef SYSARR_DPI_H
#define SYSARR_DPI_H

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


void dpi_sysarr_init();
void dpi_sysarr_destroy();

void dpi_sysarr_set_weight(svOpenArrayHandle vec, svBit valid);
void dpi_sysarr_set_activation(svOpenArrayHandle vec, svBit valid);
void dpi_sysarr_set_psum(svOpenArrayHandle vec, svBit valid);

void dpi_sysarr_tick(svBit rst_n);

svBit dpi_sysarr_get_valid();
svBit dpi_sysarr_get_ready();

void dpi_sysarr_get_output(svOpenArrayHandle arr);

void dpi_sysarr_clear_psums();

void dpi_sysarr_set_weight_elem(int elem, unsigned short val);
void dpi_sysarr_set_activation_elem(int elem, unsigned short val);
void dpi_sysarr_set_weight_valid(svBit valid);
void dpi_sysarr_set_activation_valid(svBit valid);
uint16_t dpi_sysarr_get_output_elem(int elem);

#ifdef __cplusplus
}
#endif

#endif