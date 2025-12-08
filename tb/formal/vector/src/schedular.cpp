#include "schedular.hpp"

schedular::schedular()
{
    std::fill(std::begin(binary_packets), std::end(binary_packets), 0);
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
        case S:
            break;
    }

    return instr;
}

void schedular::tick()
{

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