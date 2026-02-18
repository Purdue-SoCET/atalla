#include <scratchpad.hpp>

scratchpad::scratchpad()
{
    sp1.setZero();
    sp2.setZero();

    clk = 0;
    rst_n = 1;
    cycle_count = 0;
    valid_in_sp1 = 0;
    valid_in_sp2 = 0;
    write_sp1 = 0;
    write_sp2 = 0;
    sp_addr_sp1 = 0;
    sp_addr_sp2 = 0;
    num_rows_sp1 = 0;
    num_rows_sp2 = 0;
    num_cols_sp1 = 0;
    num_cols_sp2 = 0;
    col_id_sp1 = 0;
    col_id_sp2 = 0;
    row_id_sp1 = 0;
    row_id_sp2 = 0;
    row_or_col_sp1 = 0;
    row_or_col_sp2 = 0;
    std::fill(std::begin(wdata_sp1),std::end(wdata_sp1), 0);
    std::fill(std::begin(wdata_sp2),std::end(wdata_sp2), 0);

    valid_out_sp1 = 0;
    valid_out_sp2 = 0;
    std::fill(std::begin(rdata_sp1),std::end(rdata_sp1), 0);
    std::fill(std::begin(rdata_sp2),std::end(rdata_sp2), 0);
}

void scratchpad::tick()
{
    static uint8_t last_clk = 0;

    if (clk && !last_clk) {
         if (!rst_n)
         {
            sp1.setZero();
            sp2.setZero();

            clk = 0;
            rst_n = 1;
            last_clk = 0;
            cycle_count = 0;
            valid_in_sp1 = 0;
            valid_in_sp2 = 0;
            write_sp1 = 0;
            write_sp2 = 0;
            sp_addr_sp1 = 0;
            sp_addr_sp2 = 0;
            num_rows_sp1 = 0;
            num_rows_sp2 = 0;
            num_cols_sp1 = 0;
            num_cols_sp2 = 0;
            col_id_sp1 = 0;
            col_id_sp2 = 0;
            row_id_sp1 = 0;
            row_id_sp2 = 0;
            row_or_col_sp1 = 0;
            row_or_col_sp2 = 0;
            std::fill(std::begin(wdata_sp1),std::end(wdata_sp1), 0);
            std::fill(std::begin(wdata_sp2),std::end(wdata_sp2), 0);
            valid_out_sp1 = 0;
            valid_out_sp2 = 0;
            std::fill(std::begin(rdata_sp1),std::end(rdata_sp1), 0);
            std::fill(std::begin(rdata_sp2),std::end(rdata_sp2), 0);
         }
         else 
         {
            valid_out_sp1 = 0;
            valid_out_sp2 = 0;
            std::fill(std::begin(rdata_sp1),std::end(rdata_sp1), 0);
            std::fill(std::begin(rdata_sp2),std::end(rdata_sp2), 0);

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

            //latency handling
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
         }

        cycle_count++;
    }
    last_clk = clk;
}


void scratchpad::load_row(uint8_t sp_id, uint8_t addr, uint8_t row_id, uint8_t num_cols, Eigen::Matrix<Eigen::bfloat16, 32, 1> wdata)
{
    Eigen::Matrix<Eigen::bfloat16, 32, 1> wdata_copy = wdata;
    if (sp_id == 1)
        sp1.row(addr + row_id).head(num_cols) = wdata_copy.head(num_cols).transpose();
    else if (sp_id == 2)
        sp2.row(addr + row_id).head(num_cols) = wdata_copy.head(num_cols).transpose();
}

void scratchpad::load_col(uint8_t sp_id, uint8_t addr, uint8_t col_id, uint8_t num_rows, Eigen::Matrix<Eigen::bfloat16, 32, 1> wdata)
{   
    Eigen::Matrix<Eigen::bfloat16, 32, 1> wdata_copy = wdata;
    if (sp_id == 1)
        sp1.col(col_id).segment(addr, num_rows) = wdata_copy.head(num_rows);
    else if (sp_id == 2)
        sp2.col(col_id).segment(addr, num_rows) = wdata_copy.head(num_rows);
}

Eigen::Matrix<Eigen::bfloat16, 32, 1> scratchpad::read_row(uint8_t sp_id, uint8_t addr, uint8_t row_id, uint8_t num_cols)
{
    Eigen::Matrix<Eigen::bfloat16, 32, 1> result;
    result.setZero();
    
    if (sp_id == 1)
        result.head(num_cols) = sp1.row(addr + row_id).head(num_cols).transpose();
    else if (sp_id == 2)
        result.head(num_cols) = sp2.row(addr + row_id).head(num_cols).transpose();
    
    return result;
}

Eigen::Matrix<Eigen::bfloat16, 32, 1> scratchpad::read_col(uint8_t sp_id, uint8_t addr, uint8_t col_id, uint8_t num_rows)
{
    Eigen::Matrix<Eigen::bfloat16, 32, 1> result;
    result.setZero();
    
    if (sp_id == 1)
        result.head(num_rows) = sp1.col(col_id).segment(addr, num_rows);
    else if (sp_id == 2)
        result.head(num_rows) = sp2.col(col_id).segment(addr, num_rows);
    
    return result;
}