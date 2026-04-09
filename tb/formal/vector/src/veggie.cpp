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
            lane_input_if = {};
            sys_input_if = {};
            sp_input_if = {};
            mask_input_if = {};
            reduction_input_if = {};
            lane_output_if = {};
            sys_output_if = {};
            sp_output_if = {};
            mask_output_if = {};
            vrf_ready = 1;
        }
        else
        {
            // LANES
            //write
            for (size_t i = 0; i < lane_input_if.wen.size(); i++) {
                if (lane_input_if.wen[i]) {
                    write_vector(lane_input_if.wdata[i], lane_input_if.vd[i]);
                }
            }
            //read
            for (size_t i = 0; i < lane_input_if.ren.size(); i++) {
                if (lane_input_if.ren[i]) {
                    lane_output_if.rdata[i] = read_vector(lane_input_if.vs[i]);
                    lane_output_if.valid[i] = 1;
                } else {
                    lane_output_if.valid[i] = 0;
                }
            }
            
            // SYSARR
            //write
            for (size_t i = 0; i < sys_input_if.wen.size(); i++) {
                if (sys_input_if.wen[i]) {
                    write_vector(sys_input_if.wdata[i], sys_input_if.vd[i]);
                }
            }
            //read
            for (size_t i = 0; i < sys_input_if.ren.size(); i++) {
                if (sys_input_if.ren[i]) {
                    sys_output_if.rdata[i] = read_vector(sys_input_if.vs[i]);
                    sys_output_if.valid[i] = 1;
                } else {
                    sys_output_if.valid[i] = 0;
                }
            }
            
            // SCRATCHPAD
            //write
            for (size_t i = 0; i < sp_input_if.wen.size(); i++) {
                if (sp_input_if.wen[i]) {
                    write_vector(sp_input_if.wdata[i], sp_input_if.vd[i]);
                }
            }
            //read
            for (size_t i = 0; i < sp_input_if.ren.size(); i++) {
                if (sp_input_if.ren[i]) {
                    sp_output_if.rdata[i] = read_vector(sp_input_if.vs[i]);
                    sp_output_if.valid[i] = 1;
                } else {
                    sp_output_if.valid[i] = 0;
                }
            }
            
            // MASK
            //read
            for (size_t i = 0; i < mask_input_if.ren.size(); i++)
            {
                if (mask_input_if.ren[i])
                {
                    mask_output_if.rdata[i] = read_mask(mask_input_if.vs[i]);
                    mask_output_if.valid[i] = 1;
                }
                else
                {
                    mask_output_if.valid[i] = 0;
                }
            }
            //wrote
            for (size_t i = 0; i < mask_input_if.wen.size(); i++)
            {
                if (mask_input_if.wen[i])
                {
                    write_mask(mask_input_if.wdata[i], mask_input_if.vd[i]);
                }
            }
            
            // REDUCTION
            if (reduction_input_if.valid)
            {
                write_vector(reduction_input_if.wdata, reduction_input_if.vd);
            }
        }
    }
    
    last_clk = clk;
}