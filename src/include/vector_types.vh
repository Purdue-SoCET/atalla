`ifndef VECTOR_PKG_VH
`define VECTOR_PKG_VH

package vector_pkg;

    // Vector ISA ----------------------------------------------------------------------
    parameter OPCODE_W = 7;
    parameter VIDX_W = 8;
    parameter RIDX_W = 8;
    parameter IMM_W = 8;
    parameter DTYPE_W = 2;
    parameter INSTR_W = 32;
    parameter NUM_SP = 2;
    // =========================================================================
    //  Vector ISA / Global Params
    // =========================================================================
    // Top Level localparams
    localparam LANE_ISSUE_W = 2;
    
    // LANE VARIABLES
    localparam NUM_LANES   = 16;
    localparam LANE_ID_W   = $clog2(NUM_LANES);
    localparam VLMAX       = 32;

    // Elements per lane (total elems = NUM_LANES * SLICE_W = VLMAX)
    localparam SLICE_W     = VLMAX / NUM_LANES;
    localparam SLICE_ID_W  = $clog2(SLICE_W);
    localparam VL_W        = $clog2(VLMAX);

    // FU layout per lane
    localparam LANE_FU_COUNT  = 5;              // How many FUs per lane
    localparam LANE_FU_ID_W   = $clog2(LANE_FU_COUNT);

    // Other localparams
    localparam NUM_ELEMENTS = 32;
    localparam ESZ          = 16;               // Element Size (bits)
    localparam ESZ_W        = $clog2(ESZ);


    typedef logic [OPCODE_W-1:0] opcode_t;
    typedef logic [VIDX_W-1:0] vsel_t;
    typedef logic [RIDX_W-1:0] reg_t;
    typedef logic [IMM_W-1:0] imm_t;
    typedef logic [DTYPE_W-1:0] dtype_t;

    typedef struct packed {
        logic swizzle;
        logic transpose; // 0 = row, 1 = column
        dtype_t datatype;
        vsel_t vd; 
        logic mask;
        reg_t rs1; // base address
        logic sp; // scratchpad0, scratchpad1
        opcode_t opcode;
        logic [INSTR_W-DTYPE_W-VIDX_W-RIDX_W-OPCODE_W-5:0] reserve;  
    } rv_mtype_t;

    typedef struct packed {
        logic mask;
        vsel_t vd;
        vsel_t vs1;
        vsel_t vs2;
        opcode_t opcode;
    } rv_rtype_t;

    typedef struct packed {
        logic mask;
        vsel_t vd;
        vsel_t vs1;
        imm_t imm; 
        opcode_t opcode;
    } rv_itype_t;
    // --------------------------------------------------------------------------------

    // Data Structures ----------------------------------------------------------------
    parameter NUM_ELEMENTS = 32;

    typedef struct packed {
        logic sign;
        logic [4:0] exp;
        logic [9:0] frac;
    } fp16_t; 
    
    typedef fp16_t [NUM_ELEMENTS-1:0] vreg_t;

    typedef enum logic [5:0] {
        VALU_ADD       = 6'h00,
        VALU_SUB       = 6'h01
    } valu_op_t;

    typedef struct packed {
        logic wen; // write en
        vsel_t vwsel; // vector write select 
        logic [1:0] valid; // valid FU
        logic [4:0] vop; // Vector op
        logic [1:0] valu_src; // VV, VS, VI
        dtype_t datatype; // FP16, INT32, ETC
        logic vm; 
        logic sp;
        logic swizzle;
        logic memtovreg;
        logic spwrite;
        logic spread;
    } control_t;

    // Lane sequencer in/out (per lane, per functional unit)
        
    //localparam NUM_SLICE = NUM_ELEMENTS / NUM_LANES;

    typedef struct packed {
        logic [SLICE_W - 1:0][ESZ - 1:0] v1;
        logic [SLICE_W - 1:0][ESZ - 1:0] v2;
        logic [SLICE_W - 1:0] mask;
        logic valid_in;
        logic ready_out;

    } lane_sequencer_if_in_t;

    
    typedef struct packed {
        logic [ESZ - 1:0] v1;
        logic [ESZ - 1:0] v2;
        logic mask;
        logic valid_out;
        logic ready_in;
    } lane_sequencer_if_out_t;

endpackage
`endif
