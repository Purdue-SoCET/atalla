// ============================================================================
// sysarr_dpi.cpp
// DPI-C implementation wrapping the existing sysarr C++ model.
// Owner: Vedant Sharma
//
// SV calls these each cycle to simulate systolic array behavior.
// Maps to gsau_control_unit_if signals in the RTL testbench.
// ============================================================================

#include "sysarr_dpi.h"
#include "sysarr.hpp"

#include <cstdio>
#include <cstring>

static sysarr* g_sa = nullptr;

// Lifecycle: init/destroy
void dpi_sysarr_init()
{
    if (g_sa) delete g_sa;
    g_sa = new sysarr();
    fprintf(stdout, "[DPI] Systolic array initialized.\n");
}

void dpi_sysarr_destroy()
{
    if (g_sa) { delete g_sa; g_sa = nullptr; }
    fprintf(stdout, "[DPI] Systolic array destroyed.\n");
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



// Per-cycle: push inputs from DUT into sysarr sim
void dpi_sysarr_set_weight(svOpenArrayHandle vec, svBit valid)
{
    if (!g_sa) return;
    g_sa->sys_input_if.weight_valid = valid;
    if (valid) {
        sv_arr_to_cpp(vec, g_sa->sys_input_if.weight_vec);
    }
}

void dpi_sysarr_set_activation(svOpenArrayHandle vec, svBit valid)
{
    if (!g_sa) return;
    g_sa->sys_input_if.activation_valid = valid;
    if (valid) {
        sv_arr_to_cpp(vec, g_sa->sys_input_if.activation_vec);
    }
}

void dpi_sysarr_set_psum(svOpenArrayHandle vec, svBit valid)
{
    if (!g_sa) return;
    g_sa->sys_input_if.psum_valid = valid;
    if (valid) {
        sv_arr_to_cpp(vec, g_sa->sys_input_if.psum_vec);
    }
}

// Per-cycle
void dpi_sysarr_tick(svBit rst_n)
{
    if (!g_sa) return;
    g_sa->rst_n = rst_n;
    g_sa->clk = 1;
    g_sa->tick();
    g_sa->clk = 0;
    g_sa->tick();
}


// Read back outputs
svBit dpi_sysarr_get_valid()
{
    if (!g_sa) return 0;
    return g_sa->sys_output_if.valid;
}

svBit dpi_sysarr_get_ready()
{
    if (!g_sa) return 1;
    return g_sa->sys_output_if.ready;
}

void dpi_sysarr_get_output(svOpenArrayHandle arr)
{
    if (!g_sa) return;
    cpp_to_sv_arr(g_sa->sys_output_if.output_vec, arr);
}

// Clear
void dpi_sysarr_clear_psums()
{
    if (!g_sa) return;
    g_sa->clear_psums();
}