#ifndef SCHEDULAR_H
#define SCHEDULAR_H

#include <iostream>
#include <stdint.h>
#include <queue>
#include <unordered_map>
#include <string>
#include <sstream>
#include <fstream>
#include <array>

class schedular
{
public:
    uint8_t clk;
    uint8_t rst_n;

    //control signals
    //all 4 wide for ease of indexing
    //structure is LANE||LANE||SP||SP/GSAU
    std::array<uint8_t, 4> vd;
    std::array<uint8_t, 4> vs1;
    std::array<uint8_t, 4> vs2;
    std::array<uint8_t, 4> mask;
    std::array<uint8_t, 4> sac;
    std::array<uint8_t, 4> rs1;
    std::array<uint8_t, 4> imm8;
    std::array<uint8_t, 4> imm5;
    std::array<uint8_t, 4> num_cols;
    std::array<uint8_t, 4> num_rows;
    std::array<uint8_t, 4> sid;
    std::array<uint8_t, 4> rc;
    std::array<uint8_t, 4> rc_id;

    typedef enum instr_type_t
    {
        VV,
        VI,
        VS,
        S,
        VM,
    } instr_type_t;

    struct instr_info {
        instr_type_t type;
        uint8_t opcode;
    };

    // Flattened instruction struct
    struct instruction
    {
        uint8_t opcode;
        instr_type_t type;

        // VV / VS / VI fields
        uint8_t vd = 0;
        uint8_t vs1 = 0;
        uint8_t vs2 = 0;
        uint8_t rs1 = 0;
        uint8_t mask = 0;
        uint8_t sac = 0;
        uint8_t imm8 = 0;
        uint8_t imm5 = 0;

        // VM fields
        uint8_t num_cols = 0;
        uint8_t num_rows = 0;
        uint8_t sid = 0;
        uint8_t rc = 0;
        uint8_t rc_id = 0;
    };

    struct packet
    {
        instruction inst[4];
        //Lane OP, Lane OP, SP, SP&SYS
    };

    schedular();
    ~schedular();

    void load_program(std::string file);
    instruction parse_instruction(const std::string& instr_str);
    void parse_packet(const std::string& packet);
    void tick();
    void dump_program_queue();

private:
    std::queue<packet> inst_queue;

    std::unordered_map<std::string, instr_info> instr_map = {
        {"nop.s", {S, 47}},
        {"add.vv", {VV, 50}},
        {"sub.vv", {VV, 51}},
        {"mul.vv", {VV, 52}},
        {"div.vv", {VV, 53}},
        {"and.vv", {VV, 54}},
        {"or.vv", {VV, 55}},
        {"xor.vv", {VV, 56}},
        {"gemm.vv", {VV, 57}},
        {"mgt.vv", {VV, 58}},
        {"mlt.vv", {VV, 59}},
        {"meq.vv", {VV, 60}},
        {"mneq.vv", {VV, 61}},
        {"addi.vi", {VI, 62}},
        {"subi.vi", {VI, 63}},
        {"muli.vi", {VI, 64}},
        {"divi.vi", {VI, 65}},
        {"expi.vi", {VI, 66}},
        {"sqrti.vi", {VI, 67}},
        {"not.vi", {VI, 68}},
        {"shift.vi", {VI, 69}},
        {"lw.vi", {VI, 70}},
        {"rsum.vi", {VI, 71}},
        {"rmin.vi", {VI, 72}},
        {"rmax.vi", {VI, 73}},
        {"shift.vi", {VS, 74}},
        {"vreg.ld", {VM, 77}},
        {"vreg.st", {VM, 78}},
        {"vmov.vi", {VI, 79}},
        {"add.vs",  {VS, 80}},
        {"sub.vs",  {VS, 81}},
        {"mul.vs",  {VS, 82}},
        {"div.vs",  {VS, 83}},
        {"mgt.vs",  {VS, 84}},
        {"mlt.vs",  {VS, 85}},
        {"meq.vs",  {VS, 86}},
        {"mneq.vs", {VS, 87}}
    };
};

#endif
