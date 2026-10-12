#include <scratchpad.hpp>

scratchpad::scratchpad()
{

}

void scratchpad::tick()
{
    static uint8_t last_clk = 0;

    if (clk && !last_clk) {
         if (!rst_n)
         {
            sp[0].setZero();
            sp[1].setZero();

            clk = 0;
            rst_n = 1;
            last_clk = 0;
            cycle_count = 0;

            for (size_t i = 0; i < sp_input_if.size(); i++)
            {
                sp_input_if[i].valid_in = 0;
                sp_input_if[i].wen = 0;
                sp_input_if[i].addr = 0;
                sp_input_if[i].num_rows = 0;
                sp_input_if[i].num_cols = 0;
                sp_input_if[i].row_id = 0;
                sp_input_if[i].col_id = 0;
                sp_input_if[i].row_or_col = 0;
                std::fill(sp_input_if[i].wdata.begin(), sp_input_if[i].wdata.end(), 0);

                sp_output_if[i].valid = 0;
                std::fill(sp_output_if[i].rdata.begin(), sp_output_if[i].rdata.end(), 0);

                wb_queue[i] = std::queue<std::array<uint16_t, 32>>();
                completion_cycles[i] = std::queue<int>();
            }

         }
         else 
         {
            for (size_t i = 0; i < sp_output_if.size(); i++) {
                sp_output_if[i].valid = 0;
                std::fill(sp_output_if[i].rdata.begin(), sp_output_if[i].rdata.end(), 0);
            }
            

            /* Depriciated Block, keeping for now
            if (valid_in_sp1)
            {
               if (write_sp1)
               {
                    Eigen::Matrix<Eigen::bfloat16, 32, 1> wdata_sp1_cast;
                    for (int i = 0; i < wdata_sp1_cast.rows(); i++)
                    {
                        wdata_sp1_cast[i] = std::bit_cast<Eigen::bfloat16>(wdata_sp1[i]);
                    }
                    if (row_or_col_sp1){
                        load_col(1, sp_addr_sp1, col_id_sp1, num_rows_sp1, wdata_sp1_cast);
                    }
                    else
                    {
                        load_row(1, sp_addr_sp1, row_id_sp1, num_cols_sp1, wdata_sp1_cast);
                    }
               }
               else
               {
                   Eigen::Matrix<Eigen::bfloat16, 32, 1> read_data_sp1;
                   if (row_or_col_sp1)
                   {
                       read_data_sp1 = read_col(1, sp_addr_sp1, col_id_sp1, num_rows_sp1);
                       wb_queue_sp1.push(read_data_sp1);
                       read_completion_cycles_sp1.push(cycle_count + 13);
                   }
                   else
                   {
                       read_data_sp1 = read_row(1, sp_addr_sp1, row_id_sp1, num_cols_sp1);
                       wb_queue_sp1.push(read_data_sp1);
                       read_completion_cycles_sp1.push(cycle_count + 13);
                   }
               }
            }
            if (valid_in_sp2)
            {
               if (write_sp2)
               {
                    Eigen::Matrix<Eigen::bfloat16, 32, 1> wdata_sp2_cast;
                    for (int i = 0; i < wdata_sp2_cast.rows(); i++)
                    {
                        wdata_sp2_cast[i] = std::bit_cast<Eigen::bfloat16>(wdata_sp2[i]);
                    }
                    if (row_or_col_sp2){
                       load_col(2, sp_addr_sp2, col_id_sp2, num_rows_sp2, wdata_sp2_cast);
                    }
                    else
                    {
                        load_row(2, sp_addr_sp2, row_id_sp2, num_cols_sp2, wdata_sp2_cast);
                    }
               }
               else
               {
                   Eigen::Matrix<Eigen::bfloat16, 32, 1> read_data_sp2;
                   if (row_or_col_sp2)
                   {
                       read_data_sp2 = read_col(2, sp_addr_sp2, col_id_sp2, num_rows_sp2);
                       wb_queue_sp2.push(read_data_sp2);
                       read_completion_cycles_sp2.push(cycle_count + 13);
                   }
                   else
                   {
                       read_data_sp2 = read_row(2, sp_addr_sp2, row_id_sp2, num_cols_sp2);
                       wb_queue_sp2.push(read_data_sp2);
                       read_completion_cycles_sp2.push(cycle_count + 13);
                   }
               }
            }
            */

            //iterative scratchpad reading and writing
            for (size_t i = 0; i < sp_input_if.size(); i++)
            {
                sp_input_if_t curr_sp = sp_input_if[i];
                if (curr_sp.valid_in)
                {
                    if (curr_sp.wen)
                    {
                        if (curr_sp.row_or_col)
                        {
                            load_col(i, curr_sp.addr, curr_sp.col_id, curr_sp.num_rows, curr_sp.wdata);
                        }
                        else
                        {
                            load_row(i, curr_sp.addr, curr_sp.row_id, curr_sp.num_cols, curr_sp.wdata);
                        }
                    }
                    else
                    {
                        std::array<uint16_t, 32> read_data;
                        if (curr_sp.row_or_col)
                        {
                            read_data = read_col(i, curr_sp.addr, curr_sp.col_id, curr_sp.num_rows);
                            wb_queue[i].push(read_data);
                            completion_cycles[i].push(cycle_count + 13);
                        }
                        else
                        {
                            read_data = read_row(i, curr_sp.addr, curr_sp.row_id, curr_sp.num_cols);
                            wb_queue[i].push(read_data);
                            completion_cycles[i].push(cycle_count + 13);
                        }
                    }
                }
            }
            //iterative latency handling
            for (size_t i = 0; i < sp_input_if.size(); i++)
            {
                std::queue<std::array<uint16_t, 32>>& curr_queue = wb_queue[i];
                std::queue<int>& curr_cycle = completion_cycles[i];

                if (!curr_cycle.empty() && curr_cycle.front() == cycle_count)
                {
                    sp_output_if[i].rdata = curr_queue.front();
                    sp_output_if[i].valid = 1;
                    curr_queue.pop();
                    curr_cycle.pop();
                }
            }

            /* depriciated block keeping for now
            if (!read_completion_cycles_sp1.empty() && read_completion_cycles_sp1.front() == cycle_count)
            {
                for (int i = 0; i < rdata_sp1.size(); i++)
                {
                    rdata_sp1[i] = std::bit_cast<uint16_t>(wb_queue_sp1.front()[i]);
                }
                valid_out_sp1 = 1;  // Signal valid data available
                wb_queue_sp1.pop();
                read_completion_cycles_sp1.pop();
            }
            if (!read_completion_cycles_sp2.empty() && read_completion_cycles_sp2.front() == cycle_count)
            {
                for (int i = 0; i < rdata_sp2.size(); i++)
                {
                    rdata_sp2[i] = std::bit_cast<uint16_t>(wb_queue_sp2.front()[i]);
                }
                valid_out_sp2 = 1;  // Signal valid data available
                wb_queue_sp2.pop();
                read_completion_cycles_sp2.pop();
            }
            */
         }

        cycle_count++;
    }
    last_clk = clk;
}


void scratchpad::load_row(uint8_t sp_id, uint8_t addr, uint8_t row_id, uint8_t num_cols, std::array<uint16_t, 32> wdata)
{
    uint16_t col_offset = addr * 32;
    sp[sp_id].row(row_id).segment(col_offset, num_cols) = Eigen::Map<Eigen::Matrix<uint16_t, 32, 1>>(wdata.data()).head(num_cols).transpose();
}

void scratchpad::load_col(uint8_t sp_id, uint8_t addr, uint8_t col_id, uint8_t num_rows, std::array<uint16_t, 32> wdata)
{   
    uint16_t col_offset = addr * 32 + col_id;
    sp[sp_id].col(col_offset).head(num_rows) = Eigen::Map<Eigen::Matrix<uint16_t, 32, 1>>(wdata.data()).head(num_rows);
}

std::array<uint16_t, 32> scratchpad::read_row(uint8_t sp_id, uint8_t addr, uint8_t row_id, uint8_t num_cols)
{
    std::array<uint16_t, 32> result = {0};
    
    uint16_t col_offset = addr * 32;
    Eigen::Matrix<uint16_t, 32, 1> temp;
    temp.head(num_cols) = sp[sp_id].row(row_id).segment(col_offset, num_cols).transpose();

    std::copy(temp.data(), temp.data() + num_cols, result.data());    
    return result;
}

std::array<uint16_t, 32> scratchpad::read_col(uint8_t sp_id, uint8_t addr, uint8_t col_id, uint8_t num_rows)
{
    std::array<uint16_t, 32> result = {0};

    uint16_t col_offset = addr * 32 + col_id;
    Eigen::Matrix<uint16_t, 32, 1> temp = sp[sp_id].col(col_offset).head(num_rows);
    std::copy(temp.data(), temp.data() + num_rows, result.data());
    
    return result;
}