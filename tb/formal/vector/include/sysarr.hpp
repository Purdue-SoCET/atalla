#ifndef SYSARR_HPP
#define SYSARR_HPP

#include <Eigen/Core>
#include <Eigen/src/Core/arch/Default/BFloat16.h>
#include <Eigen/Dense>

class sysarr
{
private:
    Eigen::Matrix<Eigen::bfloat16, 32, 32> weights;
    Eigen::Matrix<Eigen::bfloat16, 32, 32> activations;
    Eigen::Matrix<Eigen::bfloat16, 32, 32> psums;
    Eigen::Matrix<Eigen::bfloat16, 32, 32> wb_buffer;
    int weights_idx = 0;
    int activations_idx = 0;
    int psums_idx = 0;
public:
    sysarr(/* args */);
    void load_weight_vec(Eigen::Matrix<Eigen::bfloat16, 32, 1> weights);
    void load_activation_vec(Eigen::Matrix<Eigen::bfloat16, 32, 1> activations);
    void load_psum_vec(Eigen::Matrix<Eigen::bfloat16, 1, 32> psums);
    void calculate();
    Eigen::Matrix<Eigen::bfloat16, 1, 32> writeback_to_veggie(int idx);
    ~sysarr();
};




#endif