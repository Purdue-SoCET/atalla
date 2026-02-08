// mul_if.vh
interface mul_if;
    // Input channel: lane -> MUL FU
    typedef struct packed {
        logic        valid_in;
        logic [15:0] operand1;   // v1 element
        logic [15:0] operand2;   // v2 element
        logic        ready_out;  // FU can accept new op
    } mul_in_t;

    // Output channel: MUL FU -> lane
    typedef struct packed {
        logic        valid_out;  // result is valid
        logic [15:0] result;     // product
        logic        ready_in;   // lane ready to accept result
    } mul_out_t;

    mul_in_t  in;
    mul_out_t out;

    
endinterface
