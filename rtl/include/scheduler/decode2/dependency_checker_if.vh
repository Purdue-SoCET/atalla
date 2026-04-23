// Navya Datla 2/12/2026

interface dependency_checker_if #(
    parameter NUM_SCALAR_INSTS = 4,
    parameter NUM_VECTOR_INSTS = 4,
    parameter NUM_SDMA_INSTRS  = 4,
    parameter NUM_SCALAR_REGS   = 256,
    parameter SCALAR_READ_PORTS = 4, 
    parameter SCALAR_WRITE_PORTS = 4, 
    parameter NUM_VECTOR_REGS   = 256,
    parameter VECTOR_READ_PORTS = 4, 
    parameter VECTOR_WRITE_PORTS = 4,
    parameter NUM_MASK_REGS     = 16, 
    parameter MASK_READ_PORTS   = 2, 
    parameter MASK_WRITE_PORTS  = 2
);

    localparam SCALAR_REG_BITS = $clog2(NUM_SCALAR_REGS);
    localparam VECTOR_REG_BITS = $clog2(NUM_VECTOR_REGS);
    localparam MASK_REG_BITS   = $clog2(NUM_MASK_REGS);


    //SIGNALS FROM D2
    //Source register signals
    logic [SCALAR_READ_PORTS-1:0]                      scalar_REN;
    logic [SCALAR_READ_PORTS-1:0][SCALAR_REG_BITS-1:0] scalar_rsel;
    logic [VECTOR_READ_PORTS-1:0]                      vector_REN;
    logic [VECTOR_READ_PORTS-1:0][VECTOR_REG_BITS-1:0] vector_rsel;
    logic [MASK_READ_PORTS-1:0]                     mask_REN;
    logic [MASK_READ_PORTS-1:0][MASK_REG_BITS-1:0]  mask_rsel;

    //Dest register signals
    logic [NUM_SCALAR_INSTS-1:0][SCALAR_REG_BITS-1:0] scalar_wsel;
    logic [NUM_SCALAR_INSTS-1:0]                     scalar_WEN;
    logic [NUM_SCALAR_INSTS-1:0]                     scalar_m_WEN;
    logic [NUM_VECTOR_INSTS-1:0][SCALAR_REG_BITS-1:0] vector_s_wsels; //when vec instr wants to wb to scalar reg
    logic [NUM_VECTOR_INSTS-1:0][VECTOR_REG_BITS-1:0] vector_v_wsels; //when vec instr wants to wb to vec reg
    logic [NUM_VECTOR_INSTS-1:0][MASK_REG_BITS-1:0] vector_m_wsels; //when vec instr wants to wb to mask reg
    logic [NUM_VECTOR_INSTS-1:0]                     vector_s_WEN;
    logic [NUM_VECTOR_INSTS-1:0]                     vector_v_WEN;
    logic [NUM_VECTOR_INSTS-1:0]                     vector_m_WEN;

    logic [NUM_SDMA_INSTRS-1:0][SCALAR_REG_BITS-1:0] SDMA_scalar_rs1s; //rs1=rd for SDMA
    logic [NUM_SDMA_INSTRS-1:0]                     SDMA_scalar_WEN;


    //SIGNALS FROM WB
    // SCALAR - WB
    logic [SCALAR_WRITE_PORTS-1:0][SCALAR_REG_BITS-1:0] scalar_WB_wsel;
    logic [SCALAR_WRITE_PORTS-1:0]                      scalar_WB_WEN;

    // VECTOR - WB 
    logic [VECTOR_WRITE_PORTS-1:0][VECTOR_REG_BITS-1:0] vector_WB_wsel;
    logic [VECTOR_WRITE_PORTS-1:0]                      vector_WB_WEN;

    // MASK - WB
    logic [MASK_WRITE_PORTS-1:0][MASK_REG_BITS-1:0] mask_WB_wsel;
    logic [MASK_WRITE_PORTS-1:0]                    mask_WB_WEN;
    
    // SCALAR - SDMA WB (this is just for clearing the bits bc it's not actually writing anything back)
    logic [NUM_SDMA_INSTRS-1:0] scalar_SDMA_WB_WEN;
    logic [NUM_SDMA_INSTRS-1:0][SCALAR_REG_BITS-1:0] scalar_SDMA_WB_wsel;


    logic dependencies_ready;
    logic ready;

    modport dc (
        //src reg signals from D2
        input scalar_REN, scalar_rsel, vector_REN, vector_rsel, mask_REN, mask_rsel,
        //dest reg signals from D2
        input scalar_wsel, scalar_WEN, scalar_m_WEN,
        input vector_s_wsels, vector_v_wsels, vector_m_wsels, vector_s_WEN, vector_v_WEN, vector_m_WEN,
        input SDMA_scalar_rs1s, SDMA_scalar_WEN, 
        //wb signals from WB for clearing bits
        input scalar_WB_wsel, scalar_WB_WEN,
        input vector_WB_wsel, vector_WB_WEN,
        input mask_WB_wsel, mask_WB_WEN,
        input scalar_SDMA_WB_wsel, scalar_SDMA_WB_WEN,
        //signal for when to mark dest registers as busy
        input ready, 
        //all RAW/WAW hazards cleared
        output dependencies_ready
    );

    modport tb (
        input  dependencies_ready,
        //src reg signals from D2
        output scalar_REN, scalar_rsel, vector_REN, vector_rsel, mask_REN, mask_rsel,
        //dest reg signals from D2
        output scalar_wsel, scalar_WEN, 
        output vector_s_wsels, vector_v_wsels, vector_m_wsels, vector_s_WEN, vector_v_WEN, vector_m_WEN,
        output SDMA_scalar_rs1s, SDMA_scalar_WEN,
        //wb signals from WB for clearing bits
        output scalar_WB_wsel, scalar_WB_WEN,
        output vector_WB_wsel, vector_WB_WEN,
        output mask_WB_wsel, mask_WB_WEN,
        output scalar_SDMA_WB_wsel, scalar_SDMA_WB_WEN,
        //signal for when to mark dest registers as busy
        output ready
    );
    
endinterface