#include "schedular.hpp"

schedular::schedular()
{
    clk = 0;
    rst_n = 0;
    reset();
}

schedular::~schedular()
{

}

void schedular::load_program(std::string file)
{
    std::ifstream infile(file);
    if (!infile.is_open()) {
        std::cerr << "Failed to open program file\n";
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        if (line.empty()) continue;
        parse_packet(line);
    }
}


void schedular::parse_packet(const std::string& packet_str)
{
    packet encoded_packet;
    std::stringstream ss(packet_str);
    std::string instr_str;

    for (int i = 0; i < 4; i++)
    {
        std::getline(ss, instr_str, '|');
        encoded_packet.inst[i] = parse_instruction(instr_str);
    }
    inst_queue.push(encoded_packet);
}



schedular::instruction schedular::parse_instruction(const std::string& instr_str)
{
    instruction instr;
    std::stringstream ss(instr_str);
    std::string token;

    std::getline(ss, token, ',');
    instr.type = instr_map[token].type;
    instr.opcode = instr_map[token].opcode;

    switch(instr.type)
    {
        case VV:
            std::getline(ss, token, ','); instr.vd = std::stoi(token);
            std::getline(ss, token, ','); instr.vs1 = std::stoi(token);
            std::getline(ss, token, ','); instr.vs2 = std::stoi(token);
            std::getline(ss, token, ','); instr.mask = std::stoi(token);
            std::getline(ss, token, ','); instr.sac = std::stoi(token);
            break;

        case VS:
            std::getline(ss, token, ','); instr.vd = std::stoi(token);
            std::getline(ss, token, ','); instr.vs1 = std::stoi(token);
            std::getline(ss, token, ','); instr.rs1 = std::stoi(token);
            std::getline(ss, token, ','); instr.mask = std::stoi(token);
            break;

        case VI:
            std::getline(ss, token, ','); instr.vd = std::stoi(token);
            std::getline(ss, token, ','); instr.vs1 = std::stoi(token);
            std::getline(ss, token, ','); instr.imm8 = std::stoi(token);
            std::getline(ss, token, ','); instr.mask = std::stoi(token);
            std::getline(ss, token, ','); instr.imm5 = std::stoi(token);
            break;

        case VM:
            std::getline(ss, token, ','); instr.vd = std::stoi(token);
            std::getline(ss, token, ','); instr.rs1 = std::stoi(token);
            std::getline(ss, token, ','); instr.num_cols = std::stoi(token);
            std::getline(ss, token, ','); instr.sid = std::stoi(token);
            std::getline(ss, token, ','); instr.row_num = std::stoi(token);
            break;

        case MTS:
            std::getline(ss, token, ','); instr.rd = std::stoi(token);
            std::getline(ss, token, ','); instr.vms = std::stoi(token);
            break;
        case STM:
            std::getline(ss, token, ','); instr.vmd = std::stoi(token);
            std::getline(ss, token, ','); instr.rs1 = std::stoi(token);
            break;
        case S:
            break;
    }

    return instr;
}

void schedular::decode(packet pkt)
{
    //instr 1 and 2
    for (uint8_t i = 0; i < 2; i++)
    {
        instruction instr = pkt.inst[i];
        bool add = (instr.opcode == 50 || instr.opcode == 62 || instr.opcode == 71 || instr.opcode == 80);
        bool subtract = (instr.opcode == 51 || instr.opcode == 63 || instr.opcode == 81);
        bool mult = (instr.opcode == 52 || instr.opcode == 64 || instr.opcode == 82);
        bool exp = instr.opcode == 66;
        if (instr.opcode == 71 || instr.opcode == 72 || instr.opcode == 73)
            sc_reduction_signals.reduction_mode = 1;

        if (add)
        {
            sc_lane_signals[i].alu_op = 2;
            sc_lane_signals[i].fu_sel = VALU;
        }
        else if (subtract)
        {
            sc_lane_signals[i].alu_op = 3;
            sc_lane_signals[i].fu_sel = VALU;
        }
        else if (mult)
        {
            sc_lane_signals[i].fu_sel = MUL;
        }
        else if (exp)
        {
            sc_lane_signals[i].fu_sel = EXP;
        }
        else if (instr.opcode == 72)
        {
            sc_lane_signals[i].fu_sel = VALU;
            sc_lane_signals[i].alu_op = 0;
        }
        else if (instr.opcode == 73)
        {
            sc_lane_signals[i].fu_sel = VALU;
            sc_lane_signals[i].alu_op = 1;
        }
        
        switch (instr.type)
        {
            case S:
                sc_lane_signals[i].lane_valid_in = 0;
            break;
            case VV:
                sc_lane_signals[i].lane_vd = instr.vd;
                sc_veggie_signals[i].vs1 = instr.vs1;
                sc_veggie_signals[i].vs2 = instr.vs2;
                sc_mask_signals[i].vmrf_vs = instr.mask;
                sc_mask_signals[i].vmrf_mren = 1;
                sc_lane_signals[i].lane_valid_in = 1;
                sc_lane_signals[i].broadcast_v2 = 0;
            break;
            case VS:
                sc_lane_signals[i].lane_vd = instr.vd;
                sc_veggie_signals[i].vs1 = instr.vs1;
                sc_veggie_signals[i].rs1 = instr.rs1;
                sc_mask_signals[i].vmrf_vs = instr.mask;
                sc_mask_signals[i].vmrf_mren = 1;
                std::fill(sc_lane_signals[i].lane_v2_broadcast.begin(), sc_lane_signals[i].lane_v2_broadcast.end(), sc_lane_signals[i].broadcast_value);
                sc_lane_signals[i].broadcast_v2 = 1;
                sc_lane_signals[i].lane_valid_in = 1;
            break;
            case VI:
                sc_lane_signals[i].lane_vd = instr.vd;
                sc_veggie_signals[i].vs1 = instr.vs1;
                sc_mask_signals[i].vmrf_vs = instr.mask;
                sc_mask_signals[i].vmrf_mren = 1;
                sc_reduction_signals.reudction_imm = instr.imm8 & 0x1F;
                sc_lane_signals[i].clear = (instr.imm8 >> 6) & 0x1;
                sc_lane_signals[i].broadcast = (instr.imm8 >> 7) & 0x1;
                std::fill(sc_lane_signals[i].lane_v2_broadcast.begin(), sc_lane_signals[i].lane_v2_broadcast.end(), (instr.imm8 << 5) | instr.imm5);
                sc_lane_signals[i].broadcast_v2 = 1;
                sc_lane_signals[i].lane_valid_in = 1;
            break;
            default:
            break;
            
        }
    }
    //instr 3
    //only 4 possible operations here
    instruction instr = pkt.inst[2];
    if (instr.opcode == 57) //gemm
    {
        sc_sys_signals.vd = instr.vd;
        sc_sys_signals.vs1 = instr.vs1;
        sc_sys_signals.vs2 = instr.vs2;
        sc_sys_signals.ren[0] = 1;
        sc_sys_signals.ren[1] = 1;
        sc_sys_signals.weight = 0;
        sc_sys_signals.valid_in = 1;
    }
    else if (instr.opcode == 70) //lw
    {
        sc_sys_signals.vs1 = instr.vs1;
        sc_sys_signals.ren[0] = 1;
        sc_sys_signals.ren[1] = 0;
        sc_sys_signals.weight = 1;
        sc_sys_signals.valid_in = 1;
    }
    else if (instr.opcode == 77) //veggie load
    {
        sc_sp_signals[0].vd = instr.vd;
        sc_sp_signals[0].rs1 = instr.rs1;
        sc_sp_signals[0].num_cols = instr.num_cols;
        sc_sp_signals[0].sid = instr.sid;
        sc_sp_signals[0].row_num = instr.row_num;
        sc_sp_signals[0].valid_in = 1;
        sc_sp_signals[0].wen = 0;
    }
    else if (instr.opcode == 78) //veggie store
    {
        sc_sp_signals[0].vd = instr.vd;
        sc_sp_signals[0].rs1 = instr.rs1;
        sc_sp_signals[0].num_cols = instr.num_cols;
        sc_sp_signals[0].sid = instr.sid;
        sc_sp_signals[0].row_num = instr.row_num;
        sc_sp_signals[0].valid_in = 1;
        sc_sp_signals[0].wen = 1;
    }
    else if (instr.opcode == 47)
    {
        sc_sp_signals[0].valid_in = 0;
        sc_sp_signals[0].wen = 0;
        sc_sys_signals.valid_in = 0;
        sc_sys_signals.ren[0] = 0;
        sc_sys_signals.ren[1] = 0;
    }

    //instr 4
    //only 3 here
    instr = pkt.inst[3];
    if (instr.opcode == 47)
    {
        sc_sp_signals[1].valid_in = 0;
        sc_sp_signals[1].wen = 0;
    }
    else if (instr.opcode == 77)
    {
        sc_sp_signals[1].vd = instr.vd;
        sc_sp_signals[1].rs1 = instr.rs1;
        sc_sp_signals[1].num_cols = instr.num_cols;
        sc_sp_signals[1].sid = instr.sid;
        sc_sp_signals[1].row_num = instr.row_num;
        sc_sp_signals[1].valid_in = 1;
        sc_sp_signals[1].wen = 0;
    }
    else if (instr.opcode == 78)
    {
        sc_sp_signals[1].vd = instr.vd;
        sc_sp_signals[1].rs1 = instr.rs1;
        sc_sp_signals[1].num_cols = instr.num_cols;
        sc_sp_signals[1].sid = instr.sid;
        sc_sp_signals[1].row_num = instr.row_num;
        sc_sp_signals[1].valid_in = 1;
        sc_sp_signals[1].wen = 1;
    }

}

void schedular::tick()
{
    static uint8_t last_clk = 0;

    if (clk && !last_clk) {
        if (!rst_n)
        {
            std::queue<packet> q;
            std::swap(inst_queue, q); //clears the queue on reset
            reset();
            all_issued = false;
        }
        else {
            deassert_valids();
            if (all_ready()) //issue instruction
            {
                if (!inst_queue.empty())
                {
                    packet next_pkt = inst_queue.front();
                    inst_queue.pop();
                    decode(next_pkt);
                }
                else
                {
                    all_issued = true;
                }
            }
        }
    }
    last_clk = clk;
}


void schedular::dump_program_queue()
{
    std::queue<packet> temp_queue = inst_queue;

    int pkt_num = 0;
    while (!temp_queue.empty()) {
        const packet& pkt = temp_queue.front();
        std::cout << "Packet " << pkt_num << ":\n";

        for (int i = 0; i < 4; i++) {
            const instruction& instr = pkt.inst[i];
            std::cout << "  Instr " << i << ": opcode=" << +instr.opcode
                      << ", type=" << instr.type;

            // print relevant fields based on type
            switch(instr.type) {
                case VV:
                    std::cout << ", vd=" << +instr.vd << ", vs1=" << +instr.vs1
                              << ", vs2=" << +instr.vs2 << ", mask=" << +instr.mask
                              << ", sac=" << +instr.sac;
                    break;
                case VS:
                    std::cout << ", vd=" << +instr.vd << ", vs1=" << +instr.vs1
                              << ", rs1=" << +instr.rs1 << ", mask=" << +instr.mask;
                    break;
                case VI:
                    std::cout << ", vd=" << +instr.vd << ", vs1=" << +instr.vs1
                              << ", imm8=" << +instr.imm8 << ", mask=" << +instr.mask
                              << ", imm5=" << +instr.imm5;
                    break;
                case VM:
                    std::cout << ", vd=" << +instr.vd << ", rs1=" << +instr.rs1
                              << ", num_cols=" << +instr.num_cols
                              << ", sid=" << +instr.sid << ", row_num=" << +instr.row_num;
                    break;
                case S:
                    std::cout << " (NOP)";
                    break;
                default:
                    break;
            }
            std::cout << "\n";
        }

        temp_queue.pop();
        pkt_num++;
    }
}

void schedular::reset()
{
    // Ready signals
    ready_signals.lane_alu_ready = 0;
    ready_signals.lane_exp_ready = 0;
    ready_signals.lane_mul_ready = 0;
    ready_signals.sys_ready = 0;
    ready_signals.sp_ready = 0;

    // SC -> LN
    for (int i = 0; i < 2; i++)
    {
        sc_lane_signals[i].lane_valid_in = 0;
        sc_lane_signals[i].broadcast_value = 0;
        sc_lane_signals[i].broadcast_v2 = 0;
        sc_lane_signals[i].lane_v2_broadcast.fill(0);
        sc_lane_signals[i].lane_vd = 0;
        sc_lane_signals[i].lane_op = 0;
        sc_lane_signals[i].fu_sel = 0;
        sc_lane_signals[i].reduction_mode = 0;
        sc_lane_signals[i].alu_op = 0;
        sc_lane_signals[i].imm8 = 0;
        sc_lane_signals[i].imm5 = 0;
        sc_lane_signals[i].broadcast = 0;
        sc_lane_signals[i].clear = 0;
    }

    // SC -> Reduction
    sc_reduction_signals.reduction_mode = 0;
    sc_reduction_signals.reudction_imm = 0;

    // SC -> SYS
    sc_sys_signals.vd = 0;
    sc_sys_signals.valid_in = 0;
    sc_sys_signals.weight = 0;
    sc_sys_signals.vs1 = 0;
    sc_sys_signals.vs2 = 0;
    sc_sys_signals.ren.fill(0);

    // SC -> SP
    for (int i = 0; i < 2; i++)
    {
        sc_sp_signals[i].vd = 0;
        sc_sp_signals[i].rs1 = 0;
        sc_sp_signals[i].num_cols = 0;
        sc_sp_signals[i].sid = 0;
        sc_sp_signals[i].row_num = 0;
        sc_sp_signals[i].valid_in = 0;
        sc_sp_signals[i].wen = 0;
    }

    // SC -> VEG
    for (int i = 0; i < 2; i++)
    {
        sc_veggie_signals[i].ren = 0;
        sc_veggie_signals[i].vs1 = 0;
        sc_veggie_signals[i].vs2 = 0;
        sc_veggie_signals[i].rs1 = 0;
    }

    // SC -> Mask
    for (int i = 0; i < 3; i++)
    {
        sc_mask_signals[i].vmrf_vs = 0;
        sc_mask_signals[i].vmrf_mren = 0;
    }
}

bool schedular::all_ready()
{
    
    for (int i = 0; i < 4; i++)
    {
        instruction instr = inst_queue.front().inst[i];
        if (i == 0 || i == 1)
        {
            bool add = (instr.opcode == 50 || instr.opcode == 62 || instr.opcode == 71 || instr.opcode == 80);
            bool subtract = (instr.opcode == 51 || instr.opcode == 63 || instr.opcode == 81);
            bool mult = (instr.opcode == 52 || instr.opcode == 64 || instr.opcode == 82);
            bool exp = instr.opcode == 66;
            bool reduction = (instr.opcode == 71 || instr.opcode == 72 || instr.opcode == 73);
            if (add && !ready_signals.lane_alu_ready) {return false;}
            if (subtract && !ready_signals.lane_alu_ready) {return false;}
            if (mult && !ready_signals.lane_mul_ready) {return false;}
            if (exp && !ready_signals.lane_exp_ready) {return false;}
            if (reduction && !ready_signals.lane_alu_ready) {return false;}
        }
        else if (i == 2)
        {
            if (instr.sac)
            {
                if (instr.opcode == 57 && !ready_signals.sys_ready) {return false;} //gemm
                else if (instr.opcode == 70 && !ready_signals.sys_ready) {return false;}//lw
                else if (instr.opcode == 77 && !ready_signals.sp_ready) {return false;} //veggie load
                else if (instr.opcode == 78 && !ready_signals.sp_ready) {return false;}//veggie store
            }
        }
        else if (i == 3)
        {
            if (instr.opcode == 77 && !ready_signals.sp_ready) {return false;} //veggie load
            else if (instr.opcode == 78 && !ready_signals.sp_ready) {return false;}//veggie store
        }
    }
    return true;
}


void schedular::deassert_valids()
{
    sc_lane_signals[0].lane_valid_in = 0;
    sc_lane_signals[1].lane_valid_in = 0;

    sc_sys_signals.valid_in = 0;

    sc_sp_signals[0].valid_in = 0;
    sc_sp_signals[1].valid_in = 0;

    sc_veggie_signals[0].ren = 0;
    sc_veggie_signals[1].ren = 0;

    sc_mask_signals[0].vmrf_mren = 0;
    sc_mask_signals[1].vmrf_mren = 0;
    sc_mask_signals[2].vmrf_mren = 0;

    sc_sys_signals.ren.fill(0);
}