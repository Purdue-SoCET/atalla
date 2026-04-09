#include "veggie.hpp"
#include "scratchpad.hpp"
#include "sysarr.hpp"
#include "schedular.hpp"
#include <filesystem>

class top
{
    private:
    public:
    schedular sc;
    sysarr sys;
    veggie veg;
    scratchpad sp;
    //DUT

    int cycle = 0;

    void clock()
    {   
        //dut->clk = 0;
        sc.clk = 0;
        sys.clk = 0;
        veg.clk = 0;
        sp.clk = 0;

        propogate();
        //dut->eval();
        sc.tick();
        sys.tick();
        veg.tick();
        sp.tick();
        
        //dut->clk = 1;
        sc.clk = 1;
        sys.clk = 1;
        veg.clk = 1;
        sp.clk = 1;

        //dut->eval();
        propogate();
        sc.tick();
        sys.tick();
        veg.tick();
        sp.tick();

        cycle++;
    }

    void reset()
    {
        sc.rst_n = 0;
        sys.rst_n = 0;
        veg.rst_n = 0;
        sp.rst_n = 0;
        //dut->nRST = 1;
        clock();
        sc.rst_n = 1;
        sys.rst_n = 1;
        veg.rst_n = 1;
        sp.rst_n = 1;
        //dut->nRST = 1
        clock();
    }

    void propogate()
    {
        //asigning all the signals

        //SC inputs
        sc.lane_alu_ready[0] |= /*(dut->ready_o >> 0) & 1*/;
        sc.lane_mul_ready[0] |= /*(dut->ready_o >> 1) & 1*/;
        sc.lane_div_ready[0] |= /*(dut->ready_o >> 2) & 1*/;
        sc.lane_exp_ready[0] |= /*(dut->ready_o >> 3) & 1*/;
        sc.lane_sqrt_ready[0] |= /*(dut->ready_o >> 4) & 1*/;
        sc.sys_ready = /*dut->sb_ready*/;
        sc.sp_ready = /**/;


        //veggie inputs
        //lanes
        veg.vrf_lane_vs[0] = sc.lane_vs1[0];
        veg.vrf_lane_vs[1] = sc.lane_vs2[1];
        veg.vrf_lane_vs[2] = sc.lane_vs1[0];
        veg.vrf_lane_vs[3] = sc.lane_vs2[1];
        veg.vrf_lane_ren = sc.lane_ren;
        //sysarr
        veg.vrf_sys_vs[0] = sc.sys_vs1;
        veg.vrf_sys_vs[1] = sc.sys_vs2;
        veg.vrf_sys_ren = sc.sys_ren;
        //sp


        //veggie writes
        veg.vrf_lane_vwdata = /*DUT*/;
        veg.vrf_sys_vwdata = /*DUT*/;
        veg.vrf_sp_vwdata = /*DUT*/;
        veg.vrf_lane_wen = /*DUT*/;
        veg.vrf_sys_wen = /*DUT*/;
        veg.vrf_sp_wen = /*DUT*/;
        veg.vrf_lane_vd = /*DUT*/;
        veg.vrf_sys_vd = /*DUT*/;
        veg.vrf_sp_vd = /*DUT*/;

        //mask reads
        veg.vmrf_mren = sc.vmrf_mren;
        veg.vmrf_vs = sc.vmrf_vs;

        //Sysarr inputs
        sys.sa_weight_en = /*DUT*/;
        sys.sa_array_in = /*DUT*/;
        sys.sa_array_in_partials = /*DUT*/;
        sys.sa_input_en = /*DUT*/;
        sys.sa_partial_en /*DUT*/;
        sys.sa_output_ready = /*DUT*/;

        //scratchpad inputs
        sp.valid_in_sp1 = /*DUT*/;
        sp.valid_in_sp2 = /*DUT*/;
        sp.write_sp1 = /*DUT*/;
        sp.write_sp2 = /*DUT*/;
        sp.sp_addr_sp1 = /*DUT*/;
        sp.sp_addr_sp2 = /*DUT*/;
        sp.num_rows_sp1 = /*DUT*/;
        sp.num_rows_sp2 = /*DUT*/;
        sp.num_cols_sp1 = /*DUT*/;
        sp.num_cols_sp2 = /*DUT*/;
        sp.col_id_sp1 = /*DUT*/;
        sp.col_id_sp2 = /*DUT*/;
        sp.row_or_col_sp1 = /*DUT*/;
        sp.row_or_col_sp2 = /*DUT*/;
        sp.wdata_sp1 = /*DUT*/;
        sp.wdata_sp2 = /*DUT*/;

        //lane inputs
        rm = sc.reduction_mode;
        valid_in = sc.lane_valid_in;
        ready_in = 1;
        v1_1 = veg.vrf_lane_vrdata[0];
        v2_1 = sc.broadcast_v2[0] ? sc.lane_v2_broadcast[0] : veg.vrf_lane_vrdata[0];
        v1_2 = veg.vrf_lane_vrdata[1];
        v2_2 = sc.broadcast_v2[1] ? sc.lane_v2_broadcast[1] : veg.vrf_lane_vrdata[1];
        vd = sc.lane_vd;
        vmask = veg.vmrf_rdata;
        vop = sc.alu_op;

        //gsau inputs
        veg_vdata1 = veg.vrf_sys_vrdata[0];
        veg_vdata2 = veg.vrf_sys_vrdata[1];
        veg_valid = veg.vfr_sys_dvalid;

        sb_vdst = sc.sys_vd;
        sb_valid = sc.sys_valid_in;
        sb_weight = sc.sys_weight;
        wb_buffer_ready = 1;
        sa_array_output = sys.sa_array_output;
        sa_out_valid = sys.sa_out_valid;
        sa_fifo_has_space = 1;



    }

};


int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Usage: program <program_name>\n";
        return 1;
    }

    std::string program_name = argv[1];

    // Default folders
    const std::string program_folder = "./testcases/";
    const std::string dump_folder    = "./veggie_dumps/";

    // Ensure folders exist
    std::filesystem::create_directories(program_folder);
    std::filesystem::create_directories(dump_folder);

    // Construct full paths
    std::string program_path = program_folder + program_name;

    top DUT;
    
    if (program_name == "gemm")
    {
        for (size_t row = 0; row < 32; row++) {
            std::array<uint16_t, 32> vec_a{};
            std::array<uint16_t, 32> vec_b{};

            for (size_t col = 0; col < 32; col++) {
                // Example pattern for matrix A
                vec_a[col] = static_cast<uint16_t>((row + col) % 16 + 1);  // 1..16 repeating
                // Example pattern for matrix B
                vec_b[col] = static_cast<uint16_t>((row * 2 + col) % 16 + 1); // 1..16 repeating
            }

            DUT.veg.write_vector(vec_a, row);  // pseudo signature: veg.write_vector(matrix_name, row, data)
            DUT.veg.write_vector(vec_b, row + 32);
        }
    }
    else if (program_name == "throughput")
    {
        //load a lot of vectors to do a lot of instructions
    }
    else
    {
        //loading a few registers of random data
        for (size_t row = 0; row < 3; row++)
        {
            std::array<uint16_t, 32> vec{};

            // Example pattern: you can fill it however you like
            for (size_t col = 0; col < 32; col++) {
                vec[col] = static_cast<uint16_t>(row + col + 1); // simple pattern
            }

            DUT.veg.write_vector(vec, row);
        }
    }


    DUT.sc.load_program(program_path);

    // Run until all instructions issued
    while (!DUT.sc.all_issued)
    {
        DUT.clock();
    }

    // Extra cycles to drain pipeline
    for (uint8_t i = 0; i < 40; i++)
    {
        DUT.clock();
    }

    // Dump veggie VRF to default folder with "_results.txt"
    DUT.veg.dump(dump_folder + program_name);

    return 0;
}
