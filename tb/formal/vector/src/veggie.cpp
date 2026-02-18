#include "veggie.hpp"

veggie::veggie() : vrf{}, vrmf{}
{
    // Arrays are already zero-initialized by the initializer list
}

veggie::~veggie()
{

}

std::array<uint16_t,32> veggie::read_vector(uint8_t idx)
{
    return vrf[idx];
}

void veggie::write_vector(std::array<uint16_t,32> data, uint8_t idx)
{
    vrf[idx] = data;
}

uint32_t veggie::read_mask(uint8_t idx)
{
    return vrmf[idx];
}

void veggie::write_mask(uint32_t data, uint8_t idx)
{
    vrmf[idx] = data;
}

void veggie::tick() {
    static uint8_t last_clk = 0;

    if (clk && !last_clk) {
        if (!rst_n)
        {
            vrf_lane_vd.fill(0);
            vrf_lane_vs.fill(0);
            vrf_lane_ren.fill(0);
            vrf_lane_wen.fill(0);
            for (auto& arr : vrf_lane_vwdata) arr.fill(0);

            vrf_sys_vd.fill(0);
            vrf_sys_vs.fill(0);
            vrf_sys_ren.fill(0);
            vrf_sys_wen.fill(0);
            for (auto& arr : vrf_sys_vwdata) arr.fill(0);

            vrf_sp_vd.fill(0);
            vrf_sp_vs.fill(0);
            vrf_sp_ren.fill(0);
            vrf_sp_wen.fill(0);
            for (auto& arr : vrf_sp_vwdata) arr.fill(0);

            for (auto& arr : vrf_lane_vrdata) arr.fill(0);
            vfr_lane_dvalid.fill(0);

            for (auto& arr : vrf_sys_vrdata) arr.fill(0);
            vfr_sys_dvalid.fill(0);

            for (auto& arr : vrf_sp_vrdata) arr.fill(0);
            vfr_sp_dvalid.fill(0);

            vmrf_vd.fill(0);
            vmrf_vs.fill(0);
            vmrf_mwen.fill(0);
            vmrf_mren.fill(0);
            vmrf_wdata.fill(0);
            vmrf_rdata.fill(0);
            vmrf_mvalid.fill(0);
        }
        else
        {
            // LANES
            for (size_t i = 0; i < vrf_lane_wen.size(); i++) {
                if (vrf_lane_wen[i]) {
                    write_vector(vrf_lane_vwdata[i], vrf_lane_vd[i]);
                }
            }
            for (size_t i = 0; i < vrf_lane_ren.size(); i++) {
                if (vrf_lane_ren[i]) {
                    vrf_lane_vrdata[i] = read_vector(vrf_lane_vs[i]);
                    vfr_lane_dvalid[i] = 1;
                } else {
                    vfr_lane_dvalid[i] = 0;
                }
            }
            
            // SYSARR
            for (size_t i = 0; i < vrf_sys_wen.size(); i++) {
                if (vrf_sys_wen[i]) {
                    write_vector(vrf_sys_vwdata[i], vrf_sys_vd[i]);
                }
            }
            for (size_t i = 0; i < vrf_sys_ren.size(); i++) {
                if (vrf_sys_ren[i]) {
                    vrf_sys_vrdata[i] = read_vector(vrf_sys_vs[i]);
                    vfr_sys_dvalid[i] = 1;
                } else {
                    vfr_sys_dvalid[i] = 0;
                }
            }
            
            // SCRATCHPAD
            for (size_t i = 0; i < vrf_sp_wen.size(); i++) {
                if (vrf_sp_wen[i]) {
                    write_vector(vrf_sp_vwdata[i], vrf_sp_vd[i]);
                }
            }
            for (size_t i = 0; i < vrf_sp_ren.size(); i++) {
                if (vrf_sp_ren[i]) {
                    vrf_sp_vrdata[i] = read_vector(vrf_sp_vs[i]);
                    vfr_sp_dvalid[i] = 1;
                } else {
                    vfr_sp_dvalid[i] = 0;
                }
            }
            
            // MASK
            for (size_t i = 0; i < vmrf_mren.size(); i++)
            {
                if (vmrf_mren[i])
                {
                    vmrf_rdata[i] = read_mask(vmrf_vs[i]);
                    vmrf_mvalid[i] = 1;
                }
                else
                {
                    vmrf_mvalid[i] = 0;
                }
            }
            for (size_t i = 0; i < vmrf_mwen.size(); i++)
            {
                if (vmrf_mwen[i])
                {
                    write_mask(vmrf_wdata[i], vmrf_vd[i]);
                }
            }
            
            // REDUCTION
            if (reduction_valid)
            {
                write_vector(reduction_wdata, reduction_vd);
            }
        }
    }
    
    last_clk = clk;
}