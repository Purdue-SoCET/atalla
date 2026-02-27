// ============================================================================
// scratchpad_dpi.cpp
// DPI-C implementation wrapping the existing scratchpad C++ model.
// Owner: Vedant Sharma
//
// SV calls each cycle simulating scratchpad memory with
// (13-cycle) read latency. Maps to scpad_if signals for RTL tb.
// ============================================================================

#include "scratchpad_dpi.h"
#include "scratchpad.hpp"

#include <cstdio>
#include <cstring>

static scratchpad* g_sp = nullptr;

// Lifecycle
void dpi_scratchpad_init()
{
    if (g_sp) delete g_sp;
    g_sp = new scratchpad();
    fprintf(stdout, "[DPI] Scratchpad initialized.\n");
}

void dpi_scratchpad_destroy()
{
    if (g_sp) { delete g_sp; g_sp = nullptr; }
    fprintf(stdout, "[DPI] Scratchpad destroyed.\n");
}




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




// Per-cycle
void dpi_scratchpad_set_request(
    int     port,
    svBit   valid,
    svBit   wen,
    uint8_t addr,
    uint8_t row_id,
    uint8_t col_id,
    uint8_t num_rows,
    uint8_t num_cols,
    svBit   row_or_col)
{
    if (!g_sp || port < 0 || port > 1) return;

    g_sp->sp_input_if[port].valid_in   = valid;
    g_sp->sp_input_if[port].wen        = wen;
    g_sp->sp_input_if[port].addr       = addr;
    g_sp->sp_input_if[port].row_id     = row_id;
    g_sp->sp_input_if[port].col_id     = col_id;
    g_sp->sp_input_if[port].num_rows   = num_rows;
    g_sp->sp_input_if[port].num_cols   = num_cols;
    g_sp->sp_input_if[port].row_or_col = row_or_col;
}

void dpi_scratchpad_set_wdata(int port, svOpenArrayHandle vec)
{
    if (!g_sp || port < 0 || port > 1) return;
    sv_arr_to_cpp(vec, g_sp->sp_input_if[port].wdata);
}




void dpi_scratchpad_tick(svBit rst_n)
{
    if (!g_sp) return;
    g_sp->rst_n = rst_n;
    g_sp->clk = 1;
    g_sp->tick();
    g_sp->clk = 0;
    g_sp->tick();
}




// Output read back
svBit dpi_scratchpad_get_valid(int port)
{
    if (!g_sp || port < 0 || port > 1) return 0;
    return g_sp->sp_output_if[port].valid;
}

void dpi_scratchpad_get_rdata(int port, svOpenArrayHandle arr)
{
    if (!g_sp || port < 0 || port > 1) return;
    cpp_to_sv_arr(g_sp->sp_output_if[port].rdata, arr);
}