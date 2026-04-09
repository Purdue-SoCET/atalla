// ============================================================================
// inst_parser_dpi.h
// DPI-C function signatures for the scheduler instruction parser.
// Owner: Vedant Sharma
//
// C++ implements, SV imports them to drive vector-core
//
// Note: might have to add definition comments later so ppl know what does what
// ============================================================================
#ifndef INST_PARSER_DPI_H
#define INST_PARSER_DPI_H

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif

void dpi_scheduler_init(const char* program_path);
void dpi_scheduler_destroy();

void dpi_set_ready_signals(
    svBit lane_alu_ready,
    svBit lane_exp_ready,
    svBit lane_sqrt_ready,
    svBit lane_mul_ready,
    svBit lane_div_ready,
    svBit sys_ready,
    svBit sp_ready
);

void dpi_scheduler_tick(svBit rst_n);

svBit dpi_get_all_issued();

svBit dpi_get_lane_valid_in(int idx);
uint8_t dpi_get_lane_vd(int idx);
uint8_t dpi_get_lane_fu_sel(int idx);
uint8_t dpi_get_lane_alu_op(int idx);
svBit dpi_get_lane_broadcast_v2(int idx);
svBit dpi_get_lane_broadcast(int idx);
svBit dpi_get_lane_clear(int idx);
uint8_t dpi_get_lane_imm8(int idx);
uint8_t dpi_get_lane_imm5(int idx);
svBit dpi_get_lane_rm(int idx);

void dpi_get_lane_v2_broadcast(int idx, svOpenArrayHandle arr);

svBit dpi_get_reduction_mode();
uint8_t dpi_get_reduction_imm();

uint8_t dpi_get_sp_wen(int idx);
uint16_t dpi_get_lane_v2_broadcast_elem(int idx, int elem);

svBit dpi_get_sys_valid_in();
uint8_t dpi_get_sys_vd();
svBit dpi_get_sys_weight();
uint8_t dpi_get_sys_vs1();
uint8_t dpi_get_sys_vs2();
svBit dpi_get_sys_ren(int idx);

svBit dpi_get_sp_valid_in(int idx);
uint8_t dpi_get_sp_vd(int idx);
uint8_t dpi_get_sp_rs1(int idx);
uint8_t dpi_get_sp_num_cols(int idx);
uint8_t dpi_get_sp_num_rows(int idx);
uint8_t dpi_get_sp_sid(int idx);
uint8_t dpi_get_sp_rc(int idx);
uint8_t dpi_get_sp_rcid(int idx);


uint8_t dpi_get_veggie_vs1(int idx);
uint8_t dpi_get_veggie_vs2(int idx);
uint8_t dpi_get_veggie_rs1(int idx);
svBit dpi_get_veggie_ren(int idx);


uint8_t dpi_get_mask_vmrf_vs(int idx);
svBit dpi_get_mask_vmrf_mren(int idx);

#ifdef __cplusplus
}
#endif

#endif