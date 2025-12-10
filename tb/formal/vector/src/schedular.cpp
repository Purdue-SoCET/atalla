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
    std::ifstream infile(file); // replace with your file name
    if (!infile.is_open()) {
        std::cerr << "Failed to open program file\n";
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        if (line.empty()) continue; // skip empty lines
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
            std::getline(ss, token, ','); instr.num_rows = std::stoi(token);
            std::getline(ss, token, ','); instr.sid = std::stoi(token);
            std::getline(ss, token, ','); instr.rc = std::stoi(token);
            std::getline(ss, token, ','); instr.rc_id = std::stoi(token);
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
        bool div = (instr.opcode == 53 || instr.opcode == 65 || instr.opcode == 83);
        bool exp = instr.opcode == 66;
        bool sqrt = instr.opcode == 67;
        reduction_mode[i] = (instr.opcode == 71 || instr.opcode == 72 || instr.opcode == 73);

        if (add)
        {
            alu_op[i] = 2;
            fu_sel[i] = VALU;
        }
        else if (subtract)
        {
            alu_op[i] = 3;
            fu_sel[i] = VALU;
        }
        else if (mult)
        {
            fu_sel[i] = MUL;
        }
        else if (div)
        {
            fu_sel[i] = DIV;
        }
        else if (exp)
        {
            fu_sel[i] = EXP;
        }
        else if (sqrt)
        {
            fu_sel[i] = SQRT;
        }
        else if (instr.opcode == 72)
        {
            fu_sel[i] = VALU;
            alu_op[i] = 0;
        }
        else if (instr.opcode == 73)
        {
            fu_sel[i] = VALU;
            alu_op[i] = 1;
        }
        
        switch (instr.type)
        {
            case S:
                lane_valid_in[i] = 0;
            break;
            case VV:
                lane_vd[i] = instr.vd;
                lane_vs1[i] = instr.vs1;
                lane_vs2[i] = instr.vs2;
                vmrf_vs[i] = instr.mask;
                vmrf_mren[i] = 1;
                lane_valid_in[i] = 1;
                broadcast_v2[i] = 0;
            break;
            case VS:
                lane_vd[i] = instr.vd;
                lane_vs1[i] = instr.vs1;
                lane_rs1[i] = instr.rs1;
                vmrf_vs[i] = instr.mask;
                vmrf_mren[i] = 1;
                std::fill(lane_v2_broadcast[i].begin(), lane_v2_broadcast[i].end(), broadcast_value);
                broadcast_v2[i] = 1;
                lane_valid_in[i] = 1;
            break;
            case VI:
                lane_vd[i] = instr.vd;
                lane_vs1[i] = instr.vs1;
                vmrf_vs[i] = instr.mask;
                vmrf_mren[i] = 1;
                reudction_imm[i] = instr.imm8 & 0x1F;
                clear[i] = (instr.imm8 >> 6) & 0x1;
                broadcast[i] = (instr.imm8 >> 7) & 0x1;
                std::fill(lane_v2_broadcast[i].begin(), lane_v2_broadcast[i].end(), (instr.imm8 << 5) | instr.imm5);
                broadcast_v2[i] = 1;
                lane_valid_in[i] = 1;
            break;
            default:
            break;
            
        }
    }
    //end me
    //instr 3
    //only 4 possible operations here
    instruction instr = pkt.inst[2];
    if (instr.opcode == 57) //gemm
    {
        sys_vd = instr.vd;
        sys_vs1 = instr.vs1;
        sys_vs2 = instr.vs2;
        sys_ren[0] = 1;
        sys_ren[1] = 1;
        sys_weight = 0;
        sys_valid_in = 1;
    }
    else if (instr.opcode == 70) //lw
    {
        sys_vs1 = instr.vs1;
        sys_ren[0] = 1;
        sys_ren[1] = 0;
        sys_weight = 1;
        sys_valid_in = 1;
    }
    else if (instr.opcode == 77) //veggie load
    {
        sp_vd[0] = instr.vd;
        sp_rs1[0] = instr.rs1;
        sp_num_cols[0] = instr.num_cols;
        sp_num_rows[0] = instr.num_rows;
        sp_sid[0] = instr.sid;
        sp_rc[0] = instr.rc;
        sp_rcid[0] = instr.rc_id;
        sp_valid_in[0] = 1;

    }
    else if (instr.opcode == 78) //veggie store
    {
        sp_valid_in[0] = 1;
    }
    else if (instr.opcode == 47)
    {
        sp_valid_in[0] = 0;
        sys_valid_in = 0;
        sys_ren[0] = 0;
        sys_ren[1] = 0;
    }

    //instr 4
    //only 3 here
    //its 1 AM fucking kill me please
    instr = pkt.inst[3];
    if (instr.opcode == 47)
    {
        sp_valid_in[1] = 0;
    }
    else if (instr.opcode == 77)
    {
        sp_vd[1] = instr.vd;
        sp_rs1[1] = instr.rs1;
        sp_num_cols[1] = instr.num_cols;
        sp_num_rows[1] = instr.num_rows;
        sp_sid[1] = instr.sid;
        sp_rc[1] = instr.rc;
        sp_rcid[1] = instr.rc_id;
        sp_valid_in[1] = 1;
    }
    else if (instr.opcode == 78)
    {
        sp_valid_in[1] = 1;
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
    std::queue<packet> temp_queue = inst_queue; // copy so we don’t destroy the original

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
                              << ", num_cols=" << +instr.num_cols << ", num_rows=" << +instr.num_rows
                              << ", sid=" << +instr.sid << ", rc=" << +instr.rc
                              << ", rc_id=" << +instr.rc_id;
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
    lane_alu_ready = 0;
    lane_exp_ready = 0;
    lane_sqrt_ready = 0;
    lane_mul_ready = 0;
    lane_div_ready = 0;
    sys_ready = 0;
    sp_ready = 0;

    // SC -> LN
    lane_valid_in.fill(0);
    broadcast_value = 0;
    for (auto& arr : lane_v2_broadcast) {
        arr.fill(0);
    }
    lane_vd.fill(0);
    lane_op.fill(0);
    fu_sel.fill(0);
    reduction_mode.fill(0);
    alu_op.fill(0);
    imm8.fill(0);
    imm5.fill(0);
    broadcast.fill(0);
    clear.fill(0);
    reudction_imm.fill(0);

    // SC -> SYS
    sys_vd = 0;
    sys_valid_in = 0;
    sys_weight = 0;
    sys_vs1 = 0;
    sys_vs2 = 0;
    sys_ren.fill(0);

    // SC -> SP
    sp_vd.fill(0);
    sp_rs1.fill(0);
    sp_num_cols.fill(0);
    sp_num_rows.fill(0);
    sp_sid.fill(0);
    sp_rc.fill(0);
    sp_rcid.fill(0);
    sp_valid_in.fill(0);

    // SC -> VEG
    lane_ren.fill(0);
    lane_vs1.fill(0);
    lane_vs2.fill(0);
    lane_rs1.fill(0);
    
    vmrf_vs.fill(0);
    vmrf_mren.fill(0);
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
            bool div = (instr.opcode == 53 || instr.opcode == 65 || instr.opcode == 83);
            bool exp = instr.opcode == 66;
            bool sqrt = instr.opcode == 67;
            bool reduction = (instr.opcode == 71 || instr.opcode == 72 || instr.opcode == 73);
            if (add && !lane_alu_ready) {return false;}
            if (subtract && !lane_alu_ready) {return false;}
            if (mult && !lane_mul_ready) {return false;}
            if (div && !lane_div_ready) {return false;}
            if (exp && !lane_exp_ready) {return false;}
            if (sqrt && !lane_sqrt_ready) {return false;}
            if (reduction && !lane_alu_ready) {return false;}
        }
        else if (i == 2)
        {
            if (instr.sac)
            {
                if (instr.opcode == 57 && !sys_ready) {return false;} //gemm
                else if (instr.opcode == 70 && !sys_ready) {return false;}//lw
                else if (instr.opcode == 77 && !sp_ready) {return false;} //veggie load
                else if (instr.opcode == 78 && !sp_ready) {return false;}//veggie store
            }
        }
        else if (i == 3)
        {
            if (instr.opcode == 77 & !sp_ready) {return false;} //veggie load
            else if (instr.opcode == 78 & !sp_ready) {return false;}//veggie store
        }
    }
    return true;
}


void schedular::deassert_valids()
{
    lane_valid_in.fill(0);
    sys_valid_in = 0;
    sp_valid_in.fill(0);

    lane_ren.fill(0);
    vmrf_mren.fill(0);

    sys_ren.fill(0);
    
}