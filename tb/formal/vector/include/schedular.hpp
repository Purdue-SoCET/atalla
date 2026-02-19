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
#include <algorithm>
#include <iomanip>


class schedular
{
public:
    struct unit_ready_t {
        uint8_t lane_alu_ready;
        uint8_t lane_exp_ready;
        uint8_t lane_sqrt_ready;
        uint8_t lane_mul_ready;
        uint8_t lane_div_ready;
        uint8_t sys_ready;
        uint8_t sp_ready;
    };

    struct lane_signals_t 
    {
        uint8_t lane_valid_in;
        uint8_t broadcast_value; //this will be an input from a fake scalar register
        uint8_t broadcast_v2;
        std::array<uint16_t, 32> lane_v2_broadcast;
        uint8_t lane_vd;
        uint8_t lane_op;
        uint8_t fu_sel;
        uint8_t reduction_mode;
        uint8_t alu_op;
        uint8_t imm8;
        uint8_t imm5;
        uint8_t broadcast;
        uint8_t clear;
        
    };

    struct reduction_signals_t
    {
        uint8_t reduction_mode;
        uint8_t reudction_imm;
    };

    struct systolic_signals_t
    {
        uint8_t vd;
        uint8_t valid_in;
        uint8_t weight;
        uint8_t vs1;
        uint8_t vs2;
        std::array<uint8_t, 2> ren;
    };

    struct sp_signals_t
    {
        uint8_t vd;
        uint8_t rs1;
        uint8_t num_cols;
        uint8_t num_rows;
        uint8_t sid;
        uint8_t rc;
        uint8_t rcid;
        uint8_t valid_in;
    };
    
    struct veggie_signals_t
    {
        uint8_t ren; //havent a clue but keeping it
        uint8_t vs1; //source
        uint8_t vs2; //source
        uint8_t rs1; //fake scalar register
    };

    struct mask_signals_t
    {
        uint8_t vmrf_vs;
        uint8_t vmrf_mren;
    };

    uint8_t clk;
    uint8_t rst_n;
    unit_ready_t ready_signals;
    std::array<lane_signals_t, 2> sc_lane_signals;
    reduction_signals_t sc_reduction_signals;
    systolic_signals_t sc_sys_signals;
    std::array<sp_signals_t,2> sc_sp_signals;
    std::array<veggie_signals_t, 2> sc_veggie_signals;
    std::array<mask_signals_t, 3> sc_mask_signals;

    

    /*
    std::array<uint8_t, 2> lane_valid_in;
    uint8_t broadcast_value;
    std::array<uint8_t, 2> broadcast_v2;
    std::array<std::array<uint16_t, 32>,2> lane_v2_broadcast;
    std::array<uint8_t, 2> lane_vd;
    std::array<uint8_t, 2> lane_op;
    std::array<uint8_t, 2> fu_sel;
    std::array<uint8_t, 2> reduction_mode;
    std::array<uint8_t, 2> alu_op;
    std::array<uint8_t, 2> imm8;
    std::array<uint8_t, 2> imm5;
    std::array<uint8_t, 2> broadcast;
    std::array<uint8_t, 2> clear;
    std::array<uint8_t, 2> reudction_imm;
    */

    /*
    uint8_t sys_vd;
    uint8_t sys_valid_in;
    uint8_t sys_weight;
    uint8_t sys_vs1;
    uint8_t sys_vs2;
    std::array<uint8_t, 2> sys_ren;
    */

    /*
    std::array<uint8_t, 2> sp_vd;
    std::array<uint8_t, 2> sp_rs1;
    std::array<uint8_t, 2> sp_num_cols;
    std::array<uint8_t, 2> sp_num_rows;
    std::array<uint8_t, 2> sp_sid;
    std::array<uint8_t, 2> sp_rc;
    std::array<uint8_t, 2> sp_rcid;
    std::array<uint8_t, 2> sp_valid_in;
    */

    /*
    std::array<uint8_t, 2> lane_ren; //not sure, we will keep the signal for now
    std::array<uint8_t, 2> lane_vs1; //selecting vector sorce
    std::array<uint8_t, 2> lane_vs2; //selecting vector sorce
    std::array<uint8_t, 2> lane_rs1; //for the fake broadcast value
    
    std::array<uint8_t, 3> vmrf_vs;
    std::array<uint8_t, 3> vmrf_mren;

    */

    bool all_issued = false;


    typedef enum {
        VALU  = 0,
        EXP  =  1,
        SQRT =  2,
        MUL  =  3,
        DIV  =  4
    } fu_t;
    

    typedef enum instr_type_t
    {
        VV,
        VI,
        VS,
        S,
        VM,
        STM,
        MTS
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

        uint8_t rd = 0;
        uint8_t vms = 0;

        uint8_t vmd = 0;
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
    void decode(packet pkt);
    
    void tick();
    void dump_program_queue();
    void reset();
    bool all_ready();
    void deassert_valids();

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
        {"shift.vs", {VS, 74}},
        {"mmv.mts", {MTS, 75}},
        {"mv.stm", {STM, 76}},
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
