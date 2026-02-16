`ifndef VECTOR_PKG_VH
`define VECTOR_PKG_VH

package vector_pkg;

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

    // VEGGIE Params
    localparam NUM_VREGS       = 256;
    localparam READ_PORTS      = 4;
    localparam WRITE_PORTS     = 4;
    localparam MASK_PORTS      = 2;
    localparam NUM_MASKS       = 16;           // Total masks
    localparam MASK_BANK_COUNT = 2;
    localparam MASK_IDX        = $clog2(NUM_MASKS);

    // Instruction Fields
    localparam OPCODE_W = 7;
    localparam VIDX_W   = 8;
    localparam RIDX_W   = 8;
    localparam IMM_W    = 8;
    localparam DTYPE_W  = 2;
    localparam INSTR_W  = 32;

    typedef logic [OPCODE_W-1:0] opcode_t;
    typedef logic [VIDX_W-1:0]   vsel_t;
    typedef logic [RIDX_W-1:0]   reg_t;
    typedef logic [IMM_W-1:0]    imm_t;
    typedef logic [DTYPE_W-1:0]  dtype_t;

    typedef logic [SLICE_ID_W-1:0] slice_idx_t;
    typedef logic [LANE_ID_W-1:0]  lane_id_t;
    typedef logic [VL_W-1:0]       vl_t;

    typedef logic [$clog2(NUM_MASKS)-1:0] mask_sel_t;
    typedef logic [VLMAX-1:0]             vmask_t;

    // -------------------------------------------------------------------------
    // RISC-V encodings
    // -------------------------------------------------------------------------
    typedef struct packed {
        logic   swizzle;
        logic   transpose; // 0 = row, 1 = column
        dtype_t datatype;
        vsel_t  vd; 
        logic   mask;
        reg_t   rs1;       // base address
        logic   sp;        // scratchpad0, scratchpad1
        opcode_t opcode;
        logic [INSTR_W-DTYPE_W-VIDX_W-RIDX_W-OPCODE_W-5:0] reserve;  
    } rv_mtype_t;

    typedef struct packed {
        logic   mask;
        vsel_t  vd;
        vsel_t  vs1;
        vsel_t  vs2;
        opcode_t opcode;
    } rv_rtype_t;

    typedef struct packed {
        logic   mask;
        vsel_t  vd;
        vsel_t  vs1;
        imm_t   imm; 
        opcode_t opcode;
    } rv_itype_t;

    // =========================================================================
    // Data Structures
    // =========================================================================
    typedef struct packed {
        logic        sign;
        logic [14:7] exp;
        logic [6:0]  frac;
    } bf16_t; 

    typedef bf16_t [SLICE_W-1:0] slice_vt;   // per-lane slice
    typedef logic  [SLICE_W-1:0] slice_mt;   // per-lane mask bits
    typedef bf16_t [VLMAX-1:0]   vreg_t;     // full vector

    // Reduction op (used by VALU for VRMAX/VRMIN/VRSUM/VRSUB)
    typedef enum logic [1:0] {
        VR_MAX = 2'b00,
        VR_MIN = 2'b01,
        VR_SUM = 2'b10,
        VR_SUB = 2'b11
    } valu_op_t;

    // =========================================================================
    // Top-Level Control
    // =========================================================================
    typedef struct packed {
        logic    wen;          // write enable
        vsel_t   vwsel;        // vector write select 
        logic [2:0] valid;     // valid FU bits
        logic [4:0] vop;       // Vector op for ALU (legacy)
        dtype_t  datatype;     // FP16, INT32, etc.
        logic    vm; 
        logic    rm;
        logic [1:0] sp;
        logic    swizzle;
        logic    memtovreg;
        logic    sp_write;
        logic    sp_read;
        vl_t     vl;
        logic [4:0] shift;     // TBD
    } control_t;

    // =========================================================================
    // Veggie interface structs
    // =========================================================================
    typedef struct packed {
        // VDATA Writes
        vsel_t [WRITE_PORTS-1:0] vd;
        vreg_t [WRITE_PORTS-1:0] vdata;
        logic  [WRITE_PORTS-1:0] WEN;

        // VDATA Reads
        vsel_t [READ_PORTS-1:0] vs;
        logic  [READ_PORTS-1:0] REN;

        // MASK Reads/Writes
        mask_sel_t [MASK_BANK_COUNT-1:0] vmd; 
        vmask_t    [MASK_BANK_COUNT-1:0] mvdata;
        logic      [MASK_BANK_COUNT-1:0] MWEN; // mask write enable

        // VMASK Reads
        mask_sel_t [MASK_BANK_COUNT-1:0] vms;
        logic      [MASK_BANK_COUNT-1:0] MREN; // mask read enable
    } veggie_in_t;

    typedef struct packed {
        vreg_t  [READ_PORTS-1:0] vreg;
        logic   [READ_PORTS-1:0] dvalid;
        vmask_t [MASK_PORTS-1:0] vmask;
        logic   [MASK_PORTS-1:0] mvalid;
        logic                    ready; // to SB
    } veggie_out_t;

    typedef struct packed {
        vreg_t  [READ_PORTS-1:0] vreg;
        vmask_t [MASK_PORTS-1:0] vmask;
        logic   [MASK_PORTS-1:0] ivalid; // ASSUMING NUM MASKS = INSTR BW
    } opbuff_out_t; 

    // Bank / mask bank I/O (local to VRF implementation)
    typedef struct {
        logic               REN;
        logic               WEN;
        logic [READ_PORTS-1:0] tag;
        vsel_t              vs;
        vsel_t              vd;
        vreg_t              vdata;
    } bank_in_t;
 
    typedef struct {
        logic               MWEN;    // 1 bit
        logic               MREN;    // 1 bit
        mask_sel_t          vmd;     // write row select
        mask_sel_t          vms;     // read  row select
        vmask_t             mvdata;  // mask write data
        logic [MASK_BANK_COUNT-1:0] tag;
    } mbank_in_t;

    typedef struct {
        logic                      valid;
        logic [ESZ*NUM_ELEMENTS-1:0] ddata;
    } bank_out_t;

    typedef struct {
        logic                 valid;
        logic [NUM_ELEMENTS-1:0] mdata;
    } mbank_out_t;

    typedef enum logic [1:0] {
        READY,
        CONFLICT
    } conflict_state_t;

    // =========================================================================
    // MaskU structs
    // =========================================================================
    typedef struct packed {
        logic                    vm;
        logic [NUM_ELEMENTS-1:0] vmask;
    } masku_in_t;

    // Output to 16 lanes (each lane sees SLICE_W mask bits)
    typedef struct packed {
        logic [NUM_LANES-1:0][SLICE_W-1:0] mask;
    } masku_out_t;

    // =========================================================================
    // Lane structs
    // =========================================================================
    // FU selector encoded as 3 bits (0..4) matching LANE_FU_COUNT = 5
    typedef enum logic [2:0] {
        VALU = 3'b000,
        EXP  = 3'b001,
        SQRT = 3'b010,
        MUL  = 3'b011,
        DIV  = 3'b100
    } fu_t;

    // Metadata carried alongside each element through the lane
    typedef struct packed {
        vsel_t      vd;
        slice_idx_t elem_idx;
        logic       last;      // marks last element of the vector
        logic [7:0] dbg_seq;   // debug sequence number for tracing
        logic       rm;        // reduction mode flag
    } meta_t;

    
    // Lane sequencer in/out (per lane, per issue slot)
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

    // =========================================================================
    // Result Collector structs
    // =========================================================================
    typedef struct packed {
        logic [NUM_LANES-1:0] input_valid;
        logic [NUM_LANES-1:0] mask;
        logic wb_ready;
        logic [NUM_LANES-1:0][ESZ-1:0] lane_input;
        logic [7:0]     vd_input;
    } result_collector_in_t;

    typedef struct packed {
        logic [NUM_LANES-1:0] input_ready;
        logic wb_valid;

        vreg_t          vector_output;
        logic [7:0]     vd_output;
    } result_collector_out_t;

    // =========================================================================
    // Unified Functional Unit Interface structs
    // =========================================================================
    typedef struct packed {
        logic input_valid;
        logic [SLICE_W-1:0][15:0] v1, v2;
        fu_t usel;
        logic [7:0] vd;
        logic rm;
        logic [SLICE_W-1:0] mask;
        valu_op_t alu_op;
    } functional_unit_issue_port_t;
    
    typedef struct packed {
        functional_unit_issue_port_t [LANE_ISSUE_W-1:0] ports;
        logic wb_ready;
    } functional_unit_in_t;

    typedef struct packed {
        logic [ESZ-1:0] result;
        logic wb_valid;
        logic rm;
        logic [7:0] vd;
        logic input_ready;
        logic mask;
    } functional_unit_out_t;

    //lane structs
    typedef struct packed {
        logic [LANE_ISSUE_W-1:0] input_valid;
        logic [LANE_ISSUE_W-1:0][SLICE_W - 1:0][ESZ - 1:0] v1;
        logic [LANE_ISSUE_W-1:0][SLICE_W - 1:0][ESZ - 1:0] v2;
        fu_t  [LANE_ISSUE_W-1:0] usel;
        logic [LANE_ISSUE_W-1:0][7:0] vd;
        logic [LANE_ISSUE_W-1:0] rm;
        logic [LANE_ISSUE_W-1:0][SLICE_W - 1:0] mask;
        valu_op_t [LANE_ISSUE_W-1:0] aluop;
        logic [LANE_FU_COUNT-1:0] rc_ready;
    } lane_in_t;

    typedef struct packed {
        functional_unit_out_t [LANE_FU_COUNT-1:0] units;
    } lane_out_t;


    // =========================================================================
    // Top-level GSAU + vector_datapath structs
    // =========================================================================
    typedef struct packed {
        // From Veggie File to GSAU
        vreg_t    veg_vdata1;         // vs1
        vreg_t    veg_vdata2;         // vs2
        logic     veg_valid;

        // From Scoreboard to GSAU
        vsel_t    sb_vdst;
        logic     sb_valid;
        logic     sb_weight;

        // From WB buffer to GSAU
        logic     wb_output_ready;

        // From Systolic Array to GSAU
        vreg_t    sa_array_output;
        logic     sa_out_valid;
        logic     sa_fifo_has_space;
    } gsau_in_t;

    typedef struct packed {
        // From GSAU to Veggie File
        logic     veg_ready;

        // From GSAU to Scoreboard
        logic     sb_ready;

        // From GSAU to WB buffer
        vreg_t    wb_psum;
        vsel_t    wb_wbdst;
        logic     wb_valid;

        // From GSAU to Systolic Array
        vreg_t    sa_array_in;
        vreg_t    sa_array_in_partials;
        logic     sa_input_en;
        logic     sa_weight_en;
        logic     sa_partial_en;
        logic     sa_output_ready;
    } gsau_out_t;

    // Per-issue-slot vector input (before MaskU / lanes)
    typedef struct packed {
        logic   [LANE_ISSUE_W-1:0]    rm;
        logic   [LANE_ISSUE_W-1:0]    valid_in; // From SB there's valid data
        logic   [LANE_ISSUE_W-1:0]    ready_in; // From WB
        vreg_t  [LANE_ISSUE_W-1:0]    v1;
        vreg_t  [LANE_ISSUE_W-1:0]    v2;       // VS and VI typed come broadcasted
        vsel_t  [LANE_ISSUE_W-1:0]    vd;       // Pass through
        vmask_t [LANE_ISSUE_W-1:0]    vmask; 
        opcode_t[LANE_ISSUE_W-1:0]    vop;      // full ISA opcode, matches lane_in.vop
        fu_t    [LANE_ISSUE_W-1:0]    fu_sel;

        gsau_in_t                     gsau;
    } vector_in_t;

    typedef struct packed {
        // Lane Outputs (post Result Collector)
        vreg_t [LANE_FU_COUNT-1:0] result;
        logic  [LANE_FU_COUNT-1:0] valid_o;   // to WB Buffer
        logic  [LANE_FU_COUNT-1:0] ready_o;   // to SB
        vsel_t [LANE_FU_COUNT-1:0] vd;

        // Reduction Outputs
        vreg_t                     reduction_result;
        logic                      reduction_valid;
        vsel_t                     reduction_vd;

        // GSAU
        gsau_out_t                 gsau;
    } vector_out_t;

endpackage

`endif
