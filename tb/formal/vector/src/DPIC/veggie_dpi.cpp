// ============================================================================
// veggie_dpi.cpp
// DPI-C implementation wrapping the existing veggie C++ model.
// Owner: Vedant Sharma
//
// SV calls these each cycle for veggie sim
// ============================================================================

#include "veggie_dpi.h"
#include "veggie.hpp"

#include <cstdio>
#include <cstring>

static veggie* g_veg = nullptr;

static void sv_arr_to_cpp(svOpenArrayHandle arr, std::array<uint16_t, 32>& out)
{
    for (int i = 0; i < 32; i++) {
        svBitVecVal bv;
        svGetBitArrElem1VecVal(&bv, arr, i);
        out[i] = (uint16_t)(bv & 0xFFFF);
    }
}

static void cpp_to_sv_arr(const std::array<uint16_t, 32>& in, svOpenArrayHandle arr)
{
    for (int i = 0; i < 32; i++) {
        svBitVecVal bv = (svBitVecVal)in[i];
        svPutBitArrElem1VecVal(arr, &bv, i);
    }
}


void dpi_veggie_init()
{
    if (g_veg) delete g_veg;
    g_veg = new veggie();
    fprintf(stdout, "[DPI] Veggie (VRF) initialized.\n");
}

void dpi_veggie_destroy()
{
    if (g_veg) { delete g_veg; g_veg = nullptr; }
    fprintf(stdout, "[DPI] Veggie (VRF) destroyed.\n");
}



// Tick
void dpi_veggie_tick(svBit rst_n)
{
    if (!g_veg) return;
    g_veg->rst_n = rst_n;
    g_veg->clk = 1;
    g_veg->tick();
    g_veg->clk = 0;
    g_veg->tick();
}




void dpi_veggie_set_lane_vs(int idx, uint8_t vs)
{
    if (!g_veg || idx < 0 || idx > 3) return;
    g_veg->lane_input_if.vs[idx] = vs;
}

void dpi_veggie_set_lane_ren(int idx, svBit ren)
{
    if (!g_veg || idx < 0 || idx > 1) return;
    g_veg->lane_input_if.ren[idx] = ren;
}

void dpi_veggie_set_lane_vd(int idx, uint8_t vd)
{
    if (!g_veg || idx < 0 || idx > 4) return;
    g_veg->lane_input_if.vd[idx] = vd;
}

void dpi_veggie_set_lane_wen(int idx, svBit wen)
{
    if (!g_veg || idx < 0 || idx > 4) return;
    g_veg->lane_input_if.wen[idx] = wen;
}

void dpi_veggie_set_lane_wdata(int idx, svOpenArrayHandle vec)
{
    if (!g_veg || idx < 0 || idx > 0) return; // only 1 wdata port
    sv_arr_to_cpp(vec, g_veg->lane_input_if.wdata[idx]);
}

svBit dpi_veggie_get_lane_valid(int idx)
{
    if (!g_veg || idx < 0 || idx > 1) return 0;
    return g_veg->lane_output_if.valid[idx];
}

void dpi_veggie_get_lane_rdata(int idx, svOpenArrayHandle arr)
{
    if (!g_veg || idx < 0 || idx > 1) return;
    cpp_to_sv_arr(g_veg->lane_output_if.rdata[idx], arr);
}




void dpi_veggie_set_sys_vs(int idx, uint8_t vs)
{
    if (!g_veg || idx < 0 || idx > 1) return;
    g_veg->sys_input_if.vs[idx] = vs;
}

void dpi_veggie_set_sys_ren(int idx, svBit ren)
{
    if (!g_veg || idx < 0 || idx > 1) return;
    g_veg->sys_input_if.ren[idx] = ren;
}

void dpi_veggie_set_sys_vd(int idx, uint8_t vd)
{
    if (!g_veg || idx < 0 || idx > 0) return;
    g_veg->sys_input_if.vd[idx] = vd;
}

void dpi_veggie_set_sys_wen(int idx, svBit wen)
{
    if (!g_veg || idx < 0 || idx > 0) return;
    g_veg->sys_input_if.wen[idx] = wen;
}

void dpi_veggie_set_sys_wdata(int idx, svOpenArrayHandle vec)
{
    if (!g_veg || idx < 0 || idx > 0) return;
    sv_arr_to_cpp(vec, g_veg->sys_input_if.wdata[idx]);
}

svBit dpi_veggie_get_sys_valid(int idx)
{
    if (!g_veg || idx < 0 || idx > 1) return 0;
    return g_veg->sys_output_if.valid[idx];
}

void dpi_veggie_get_sys_rdata(int idx, svOpenArrayHandle arr)
{
    if (!g_veg || idx < 0 || idx > 1) return;
    cpp_to_sv_arr(g_veg->sys_output_if.rdata[idx], arr);
}




void dpi_veggie_set_sp_vs(int idx, uint8_t vs)
{
    if (!g_veg || idx < 0 || idx > 1) return;
    g_veg->sp_input_if.vs[idx] = vs;
}

void dpi_veggie_set_sp_ren(int idx, svBit ren)
{
    if (!g_veg || idx < 0 || idx > 1) return;
    g_veg->sp_input_if.ren[idx] = ren;
}

void dpi_veggie_set_sp_vd(int idx, uint8_t vd)
{
    if (!g_veg || idx < 0 || idx > 1) return;
    g_veg->sp_input_if.vd[idx] = vd;
}

void dpi_veggie_set_sp_wen(int idx, svBit wen)
{
    if (!g_veg || idx < 0 || idx > 1) return;
    g_veg->sp_input_if.wen[idx] = wen;
}

void dpi_veggie_set_sp_wdata(int idx, svOpenArrayHandle vec)
{
    if (!g_veg || idx < 0 || idx > 1) return;
    sv_arr_to_cpp(vec, g_veg->sp_input_if.wdata[idx]);
}

svBit dpi_veggie_get_sp_valid(int idx)
{
    if (!g_veg || idx < 0 || idx > 1) return 0;
    return g_veg->sp_output_if.valid[idx];
}

void dpi_veggie_get_sp_rdata(int idx, svOpenArrayHandle arr)
{
    if (!g_veg || idx < 0 || idx > 1) return;
    cpp_to_sv_arr(g_veg->sp_output_if.rdata[idx], arr);
}




void dpi_veggie_set_mask_vs(int idx, uint8_t vs)
{
    if (!g_veg || idx < 0 || idx > 2) return;
    g_veg->mask_input_if.vs[idx] = vs;
}

void dpi_veggie_set_mask_ren(int idx, svBit ren)
{
    if (!g_veg || idx < 0 || idx > 2) return;
    g_veg->mask_input_if.ren[idx] = ren;
}

void dpi_veggie_set_mask_vd(int idx, uint8_t vd)
{
    if (!g_veg || idx < 0 || idx > 2) return;
    g_veg->mask_input_if.vd[idx] = vd;
}

void dpi_veggie_set_mask_wen(int idx, svBit wen)
{
    if (!g_veg || idx < 0 || idx > 2) return;
    g_veg->mask_input_if.wen[idx] = wen;
}

void dpi_veggie_set_mask_wdata(int idx, uint32_t data)
{
    if (!g_veg || idx < 0 || idx > 2) return;
    g_veg->mask_input_if.wdata[idx] = data;
}

svBit dpi_veggie_get_mask_valid(int idx)
{
    if (!g_veg || idx < 0 || idx > 2) return 0;
    return g_veg->mask_output_if.valid[idx];
}

uint32_t dpi_veggie_get_mask_rdata(int idx)
{
    if (!g_veg || idx < 0 || idx > 2) return 0;
    return g_veg->mask_output_if.rdata[idx];
}



void dpi_veggie_set_reduction(uint8_t vd, svBit valid, svOpenArrayHandle vec)
{
    if (!g_veg) return;
    g_veg->reduction_input_if.vd = vd;
    g_veg->reduction_input_if.valid = valid;
    if (valid) {
        sv_arr_to_cpp(vec, g_veg->reduction_input_if.wdata);
    }
}




void dpi_veggie_write_vector(uint8_t idx, svOpenArrayHandle vec)
{
    if (!g_veg) return;
    std::array<uint16_t, 32> data;
    sv_arr_to_cpp(vec, data);
    g_veg->write_vector(data, idx);
}

void dpi_veggie_read_vector(uint8_t idx, svOpenArrayHandle arr)
{
    if (!g_veg) return;
    std::array<uint16_t, 32> data = g_veg->read_vector(idx);
    cpp_to_sv_arr(data, arr);
}

void dpi_veggie_write_mask(uint8_t idx, uint32_t data)
{
    if (!g_veg) return;
    g_veg->write_mask(data, idx);
}

uint32_t dpi_veggie_read_mask(uint8_t idx)
{
    if (!g_veg) return 0;
    return g_veg->read_mask(idx);
}




svBit dpi_veggie_get_ready()
{
    if (!g_veg) return 1;
    return g_veg->vrf_ready;
}

void dpi_veggie_write_vector_elem(uint8_t vr_idx, int elem_idx, unsigned short val)
{
    if (!g_veg || elem_idx < 0 || elem_idx >= 32) return;
    auto vec = g_veg->read_vector(vr_idx);
    vec[elem_idx] = val;
    g_veg->write_vector(vec, vr_idx);
}

uint16_t dpi_veggie_read_vector_elem(uint8_t vr_idx, int elem_idx)
{
    if (!g_veg || elem_idx < 0 || elem_idx >= 32) return 0;
    auto vec = g_veg->read_vector(vr_idx);
    return vec[elem_idx];
}