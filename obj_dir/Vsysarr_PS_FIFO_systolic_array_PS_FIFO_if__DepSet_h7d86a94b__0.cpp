// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsysarr_PS_FIFO.h for the primary calling header

#include "Vsysarr_PS_FIFO__pch.h"
#include "Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if.h"

std::string VL_TO_STRING(const Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vsysarr_PS_FIFO_systolic_array_PS_FIFO_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
