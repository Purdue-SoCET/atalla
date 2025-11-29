#include "sysarr.hpp"

sysarr::sysarr(/* args */)
{
}

sysarr::~sysarr()
{
}



void sysarr::load_weight_vec(Eigen::Matrix<Eigen::bfloat16, 32, 1> weight_vec)
{
    weights.col(weights_idx++) = weight_vec;
    calculate();
}

void sysarr::load_activation_vec(Eigen::Matrix<Eigen::bfloat16, 32, 1> act_vec)
{
    activations.col(activations_idx++) = act_vec;
    calculate();
}

void sysarr::load_psum_vec(Eigen::Matrix<Eigen::bfloat16, 1, 32> psum_vec)
{
    psums.row(psums_idx++) = psum_vec;
    if (psums_idx == 32)
    {
        psums_idx = 0;
    }
}

void sysarr::calculate()
{
    if (weights_idx == 32 && activations_idx == 32)
    {
        psums = weights * activations + psums;
        wb_buffer = psums;
        weights_idx = 0;
        activations_idx = 0;
    }
}

Eigen::Matrix<Eigen::bfloat16, 1, 32> sysarr::writeback_to_veggie(int idx)
{
    return wb_buffer.row(idx);
}
