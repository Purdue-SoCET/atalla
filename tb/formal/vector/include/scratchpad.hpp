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
        std::array<Eigen::Matrix<uint16_t, 32, 256>, 2> sp;
        
    public:
        struct sp_input_if_t
        {
            uint8_t valid_in;
            uint8_t wen;
            uint8_t addr;
            uint8_t num_rows;
            uint8_t num_cols;
            uint8_t row_id;
            uint8_t col_id;
            uint8_t row_or_col;
            std::array<uint16_t, 32> wdata;
        };

        struct sp_output_if_t
        {
            uint8_t valid;
            std::array<uint16_t, 32> rdata;
        };
        

        uint8_t clk;
        uint8_t rst_n;
        std::array<std::queue<int>, 2> completion_cycles;
        std::array<std::queue<std::array<uint16_t, 32>>, 2> wb_queue;
        int cycle_count = 0;
        
        std::array<sp_input_if_t, 2> sp_input_if;
        std::array<sp_output_if_t, 2> sp_output_if;
        std::queue<std::array<uint16_t, 32>> wb_queue_sp1;
        std::queue<std::array<uint16_t, 32>> wb_queue_sp2;        

        scratchpad();

        void tick();

        void load_row(uint8_t sp_id, uint8_t addr, uint8_t row_id, uint8_t num_cols, std::array<uint16_t, 32> wdata);
        void load_col(uint8_t sp_id, uint8_t addr, uint8_t col_id, uint8_t num_rows, std::array<uint16_t, 32> wdata);
        std::array<uint16_t, 32> read_row(uint8_t sp_id, uint8_t addr, uint8_t row_id, uint8_t num_cols);
        std::array<uint16_t, 32> read_col(uint8_t sp_id, uint8_t addr, uint8_t col_id, uint8_t num_rows);
    };


#endif