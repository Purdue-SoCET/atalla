#include "schedular.hpp"

schedular::schedular()
{
    clk = 0;
    rst_n = 0;
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
        bool add = (instr.opcode ==  50 | instr.opcode == 62 | instr.opcode == 71 | instr.opcode == 80);
        bool subtract = (instr.opcode ==  51 | instr.opcode == 63 | instr.opcode == 81);
        bool mult = (instr.opcode ==  52 | instr.opcode == 64 | instr.opcode == 82);
        bool div = (instr.opcode == 53 | instr.opcode == 65 | instr.opcode == 83);
        bool exp = instr.opcode == 66;
        bool sqrt = instr.opcode == 67;
        reduction_mode[i] == (instr.opcode == 71 | instr.opcode == 72 | instr.opcode == 73);

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
            case VV:
                lane_vd[i] = instr.vd;
                lane_vs1[i] = instr.vs1;
                lane_vs2[i] = instr.vs2;
                vmrf_vs[i] = instr.mask;
                vmrf_mren[i] = 1;
            break;
            case VS:
                lane_vd[i] = instr.vd;
                lane_vs1[i] = instr.vs1;
                lane_rs1[i] = instr.rs1;
                vmrf_vs[i] = instr.mask;
                vmrf_mren[i] = 1;
                std::fill(lane_v2_broadcast[i].begin(), lane_v2_broadcast[i].end(), broadcast_value);
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
            break;
            
        }
    }
    //end me
    //instr 3
    //only 4 possible operations here


    //instr 4
    //only 2 here
    //its 1 AM fucking kill me please
}

void schedular::tick()
{
    static uint8_t last_clk = 0;

    if (clk && !last_clk) {
        if (!rst_n)
        {
            std::queue<packet> q;
            std::swap(inst_queue, q); //clears the queue on reset
        }
        else {

        }
    }
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
            }
            std::cout << "\n";
        }

        temp_queue.pop();
        pkt_num++;
    }
}