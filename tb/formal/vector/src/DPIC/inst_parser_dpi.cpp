// ============================================================================
// inst_parser_dpi.cpp
// DPI-C implementation: wraps scheduler class so SV can drive cycle-by-cycle.
// Owner: Vedant Sharma
//
// file reuses scheduler class directly. 
// The only addition is a DPI wrapper that has init/tick/readback functions.
// ============================================================================

#include "inst_parser_dpi.h"
#include "schedular.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>

static uint8_t cpp_fu_to_rtl(uint8_t f)
{
    switch (f) {
        case 0: return 0; // VALU
        case 1: return 3; // EXP
        case 2: return 4; // SQRT
        case 3: return 1; // MUL
        case 4: return 2; // DIV
        default: return 0;
    }
}


static uint8_t cpp_aluop_to_rtl(uint8_t op)
{
    switch (op) {
        case 2: return 0x0; // add -> ALU_ADD
        case 3: return 0x1; // sub -> ALU_SUB
        default: return 0x0;
    }
}


// Check w Akshath if this is the right way to do it.
// scheduler instance
static schedular* g_sc = nullptr;



// Sched init/destroy
void dpi_scheduler_init(const char* program_path)
{
    if (g_sc) {
        delete g_sc;
    }
    g_sc = new schedular();
    g_sc->load_program(std::string(program_path));

    fprintf(stdout, "[DPI] Scheduler initialized, program loaded: %s\n", program_path);
    g_sc->dump_program_queue();
}

void dpi_scheduler_destroy()
{
    if (g_sc) {
        delete g_sc;
        g_sc = nullptr;
        fprintf(stdout, "[DPI] Scheduler destroyed.\n");
    }
}




// Per cycle interface
void dpi_set_ready_signals(
    svBit lane_alu_ready,
    svBit lane_exp_ready,
    svBit lane_sqrt_ready,
    svBit lane_mul_ready,
    svBit lane_div_ready,
    svBit sys_ready,
    svBit sp_ready)
{
    if (!g_sc) return;

    g_sc->ready_signals.lane_alu_ready = lane_alu_ready;
    g_sc->ready_signals.lane_exp_ready = lane_exp_ready;
    g_sc->ready_signals.lane_sqrt_ready = lane_sqrt_ready;
    g_sc->ready_signals.lane_mul_ready = lane_mul_ready;
    g_sc->ready_signals.lane_div_ready = lane_div_ready;
    g_sc->ready_signals.sys_ready = sys_ready;
    g_sc->ready_signals.sp_ready = sp_ready;
}

// posedge and nedge, cuz i learned my lesson lol, i think this is fine, ill have to chcek w akshath
void dpi_scheduler_tick(svBit rst_n)
{
    if (!g_sc) return;

    g_sc->rst_n = rst_n;

    // posedge for checking outs
    // Rising edge: clk 0->1 
    g_sc->clk = 1;
    g_sc->tick();

    // negedge for asserting ins
    // Falling edge: clk 1->0  (prepares for next cycle)
    g_sc->clk = 0;
    g_sc->tick();
}



// Signal readback
svBit dpi_get_all_issued()
{
    if (!g_sc) return 1;
    return g_sc->all_issued ? 1 : 0;
}



// Lane signals
svBit dpi_get_lane_valid_in(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_lane_signals[idx].lane_valid_in;
}

uint8_t dpi_get_lane_vd(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_lane_signals[idx].lane_vd;
}

uint8_t dpi_get_lane_fu_sel(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return cpp_fu_to_rtl(g_sc->sc_lane_signals[idx].fu_sel);
}

uint8_t dpi_get_lane_alu_op(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return cpp_aluop_to_rtl(g_sc->sc_lane_signals[idx].alu_op);
}

svBit dpi_get_lane_broadcast_v2(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_lane_signals[idx].broadcast_v2;
}

svBit dpi_get_lane_broadcast(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_lane_signals[idx].broadcast;
}

svBit dpi_get_lane_clear(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_lane_signals[idx].clear;
}

uint8_t dpi_get_lane_imm8(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_lane_signals[idx].imm8;
}

uint8_t dpi_get_lane_imm5(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_lane_signals[idx].imm5;
}

void dpi_get_lane_v2_broadcast(int idx, svOpenArrayHandle arr)
{
    if (!g_sc || idx < 0 || idx > 1) return;

    for (int i = 0; i < 32; i++) {
        uint16_t val = g_sc->sc_lane_signals[idx].lane_v2_broadcast[i];
        svBitVecVal bv = (svBitVecVal)val;
        svPutBitArrElem1VecVal(arr, &bv, i);
    }
}

svBit dpi_get_lane_rm(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_reduction_signals.reduction_mode;
}



// Reduction signals
svBit dpi_get_reduction_mode()
{
    if (!g_sc) return 0;
    return g_sc->sc_reduction_signals.reduction_mode;
}

uint8_t dpi_get_reduction_imm()
{
    if (!g_sc) return 0;
    return g_sc->sc_reduction_signals.reudction_imm;
}



// Systolic array signals
svBit dpi_get_sys_valid_in()
{
    if (!g_sc) return 0;
    return g_sc->sc_sys_signals.valid_in;
}

uint8_t dpi_get_sys_vd()
{
    if (!g_sc) return 0;
    return g_sc->sc_sys_signals.vd;
}

svBit dpi_get_sys_weight()
{
    if (!g_sc) return 0;
    return g_sc->sc_sys_signals.weight;
}

uint8_t dpi_get_sys_vs1()
{
    if (!g_sc) return 0;
    return g_sc->sc_sys_signals.vs1;
}

uint8_t dpi_get_sys_vs2()
{
    if (!g_sc) return 0;
    return g_sc->sc_sys_signals.vs2;
}

svBit dpi_get_sys_ren(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_sys_signals.ren[idx];
}



// Scratchpad signals
svBit dpi_get_sp_valid_in(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_sp_signals[idx].valid_in;
}

uint8_t dpi_get_sp_vd(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_sp_signals[idx].vd;
}

uint8_t dpi_get_sp_rs1(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_sp_signals[idx].rs1;
}

uint8_t dpi_get_sp_num_cols(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_sp_signals[idx].num_cols;
}

uint8_t dpi_get_sp_num_rows(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_sp_signals[idx].num_rows;
}

uint8_t dpi_get_sp_sid(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_sp_signals[idx].sid;
}

uint8_t dpi_get_sp_rc(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_sp_signals[idx].rc;
}

uint8_t dpi_get_sp_rcid(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_sp_signals[idx].rcid;
}



// Veggie signals
uint8_t dpi_get_veggie_vs1(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_veggie_signals[idx].vs1;
}

uint8_t dpi_get_veggie_vs2(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_veggie_signals[idx].vs2;
}

uint8_t dpi_get_veggie_rs1(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_veggie_signals[idx].rs1;
}

svBit dpi_get_veggie_ren(int idx)
{
    if (!g_sc || idx < 0 || idx > 1) return 0;
    return g_sc->sc_veggie_signals[idx].ren;
}



// Mask signals
uint8_t dpi_get_mask_vmrf_vs(int idx)
{
    if (!g_sc || idx < 0 || idx > 2) return 0;
    return g_sc->sc_mask_signals[idx].vmrf_vs;
}

svBit dpi_get_mask_vmrf_mren(int idx)
{
    if (!g_sc || idx < 0 || idx > 2) return 0;
    return g_sc->sc_mask_signals[idx].vmrf_mren;
}
