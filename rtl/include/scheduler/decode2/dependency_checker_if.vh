// Navya Datla 2/12/2026

interface dependency_checker_if #(
    parameter NUM_SCALAR_REGS   = 256,
    parameter SCALAR_READ_PORTS = 4, 
    parameter SCALAR_WRITE_PORTS = 4, 
    parameter NUM_VECTOR_REGS   = 256,
    parameter VECTOR_READ_PORTS = 4, 
    parameter VECTOR_WRITE_PORTS = 4,
    parameter NUM_MASK_REGS     = 32, 
    parameter MASK_READ_PORTS   = 2, 
    parameter MASK_WRITE_PORTS  = 2
);

    localparam SCALAR_REG_BITS = $clog2(NUM_SCALAR_REGS);
    localparam VECTOR_REG_BITS = $clog2(NUM_VECTOR_REGS);
    localparam MASK_REG_BITS   = $clog2(NUM_MASK_REGS);

    // SCALAR - D2
    logic [SCALAR_READ_PORTS-1:0]                      scalar_REN;
    logic [SCALAR_READ_PORTS-1:0][SCALAR_REG_BITS-1:0] scalar_rsel;
    logic [SCALAR_WRITE_PORTS-1:0][SCALAR_REG_BITS-1:0] scalar_wsel;
    logic [SCALAR_WRITE_PORTS-1:0]                     scalar_WEN;

    // SCALAR - WB
    logic [SCALAR_WRITE_PORTS-1:0][SCALAR_REG_BITS-1:0] scalar_WB_wsel;
    logic [SCALAR_WRITE_PORTS-1:0]                      scalar_WB_WEN;

    // SCALAR - SDMA WB
    logic scalar_SDMA_WEN;
    logic [SCALAR_REG_BITS-1:0] scalar_SDMA_wsel;

    // VECTOR - D2
    logic [VECTOR_READ_PORTS-1:0]                      vector_REN;
    logic [VECTOR_READ_PORTS-1:0][VECTOR_REG_BITS-1:0] vector_rsel;
    logic [VECTOR_WRITE_PORTS-1:0][VECTOR_REG_BITS-1:0] vector_wsel;
    logic [VECTOR_WRITE_PORTS-1:0]                     vector_WEN;

    // VECTOR - WB 
    logic [VECTOR_WRITE_PORTS-1:0][VECTOR_REG_BITS-1:0] vector_WB_wsel;
    logic [VECTOR_WRITE_PORTS-1:0]                      vector_WB_WEN;

    // MASK - D2
    logic [MASK_READ_PORTS-1:0]                     mask_REN;
    logic [MASK_READ_PORTS-1:0][MASK_REG_BITS-1:0]  mask_rsel;
    logic [MASK_WRITE_PORTS-1:0][MASK_REG_BITS-1:0] mask_wsel;
    logic [MASK_WRITE_PORTS-1:0]                    mask_WEN;

    // MASK - WB
    logic [MASK_WRITE_PORTS-1:0][MASK_REG_BITS-1:0] mask_WB_wsel;
    logic [MASK_WRITE_PORTS-1:0]                    mask_WB_WEN;

    logic dependencies_ready;
    logic ready;
    
    
    modport dc (
        input  scalar_REN, scalar_rsel, scalar_wsel, scalar_WEN,
        input  scalar_WB_wsel, scalar_WB_WEN,
        input  scalar_SDMA_wsel, scalar_SDMA_WEN,
        input  vector_REN, vector_rsel, vector_wsel, vector_WEN,
        input  vector_WB_wsel, vector_WB_WEN,
        input  mask_REN, mask_rsel, mask_wsel, mask_WEN,
        input  mask_WB_wsel, mask_WB_WEN,
        input ready, //for when to mark dest registers as busy
        output dependencies_ready
    );

    modport tb (
        input  dependencies_ready,
        output scalar_rsel, scalar_wsel, scalar_WEN,
        output scalar_REN, vector_REN, mask_REN,
        output scalar_WB_wsel, scalar_WB_WEN,
        output scalar_SDMA_wsel, scalar_SDMA_WEN,
        output vector_rsel, vector_wsel, vector_WEN,
        output vector_WB_wsel, vector_WB_WEN,
        output mask_rsel, mask_wsel, mask_WEN,
        output mask_WB_wsel, mask_WB_WEN
    );
    
endinterface