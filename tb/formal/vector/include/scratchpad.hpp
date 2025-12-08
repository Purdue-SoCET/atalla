#ifndef SCRATCHPAD_H
#define SCRATHPAD_H

#include <Eigen/Core>
#include <Eigen/src/Core/arch/Default/BFloat16.h>
#include <Eigen/Dense>
#include <queue>
#include <array>
#include <bit>
#include <algorithm>

class scratchpad {
    
    private:
        Eigen::Matrix<Eigen::bfloat16, 32, 256> sp1;
        Eigen::Matrix<Eigen::bfloat16, 32, 256> sp2; 
        
    public:
        uint8_t clk;
        uint8_t rst_n;
        std::queue<int> read_completion_cycles_sp1;
        std::queue<int> read_completion_cycles_sp2;
        int cycle_count = 0;
        //input
        uint8_t valid_in_sp1;
        uint8_t write_sp1;
        uint8_t sp_addr_sp1;
        uint8_t num_rows_sp1;
        uint8_t num_cols_sp1;
        uint8_t row_id_sp1;
        uint8_t col_id_sp1;
        uint8_t row_or_col_sp1;
        std::array<uint16_t, 32> wdata_sp1; 
        //output
        uint8_t valid_out_sp1;
        std::array<uint16_t, 32> rdata_sp1;

        std::queue<Eigen::Matrix<Eigen::bfloat16, 32, 1>> wb_queue_sp1;

        uint8_t valid_in_sp2;
        uint8_t write_sp2;
        uint8_t sp_addr_sp2;
        uint8_t num_rows_sp2;
        uint8_t num_cols_sp2;
        uint8_t row_id_sp2;
        uint8_t col_id_sp2;
        uint8_t row_or_col_sp2;
        std::array<uint16_t, 32> wdata_sp2; 
        //output
        uint8_t valid_out_sp2;
        std::array<uint16_t, 32> rdata_sp2;

        std::queue<Eigen::Matrix<Eigen::bfloat16, 32, 1>> wb_queue_sp2;

        scratchpad();

        void tick();

        void load_row(uint8_t sp_id, uint8_t addr, uint8_t row_id, uint8_t num_cols, Eigen::Matrix<Eigen::bfloat16, 32, 1> wdata);
        void load_col(uint8_t sp_id, uint8_t addr, uint8_t col_id, uint8_t num_rows, Eigen::Matrix<Eigen::bfloat16, 32, 1> wdata);
        Eigen::Matrix<Eigen::bfloat16, 32, 1> read_row(uint8_t sp_id, uint8_t addr, uint8_t row_id, uint8_t num_cols);
        Eigen::Matrix<Eigen::bfloat16, 32, 1> read_col(uint8_t sp_id, uint8_t addr, uint8_t col_id, uint8_t num_rows);
    };


#endif