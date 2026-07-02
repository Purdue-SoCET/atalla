`ifndef VECTOR_PKG_VH
`define VECTOR_PKG_VH

package vector_pkg;
    `include "scpad_params.svh"
    import scpad_pkg::*;
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
    localparam LANE_FU_COUNT  = 2;              // How many FUs per lane
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

    // =========================================================================
    // Data Structures
    // =========================================================================
    typedef logic [VLMAX-1:0][ESZ-1:0]   vreg_t;     // full vector
    typedef enum logic [1:0] {
        VALU = 2'b00,
        MUL = 2'b01,
        EXP = 2'b10
    } fu_t;

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
    typedef enum logic [3:0] {
        ALU_ADD = 4'b0000, // BF16 addition
        ALU_SUB = 4'b0001, // BF16 subtraction
        ALU_AND = 4'b0010, // Bitwise AND
        ALU_OR = 4'b0011, // Bitwise OR
        ALU_XOR = 4'b0100, // Bitwise XOR
        ALU_NOT = 4'b0101, // Bitwise NOT (v1 only)
        ALU_MGT = 4'b0110, // Mask greater than (v1 > v2)
        ALU_MLT = 4'b0111, // Mask less than (v1 < v2)
        ALU_MEQ = 4'b1000, // Mask equal (v1 == v2)
        ALU_MNEQ = 4'b1001 // Mask not equal (v1 != v2)
    } alu_op_t;

    typedef struct packed {
        logic [ESZ-1:0] v1;
        logic [ESZ-1:0] v2;
        alu_op_t aluop;
        logic rm; // Reduction mode
        logic mask; // Element mask bit
        logic valid_in;
        logic ready_out;
    } valu_if_in_t;

    typedef struct packed {
        logic [ESZ-1:0] result;
        logic valid_out;
        logic ready_in;
    } valu_if_out_t;
    
    // Lane sequencer in/out (per lane, per issue slot)
    typedef struct packed {
        logic [SLICE_W - 1:0][ESZ - 1:0] v1;
        logic [SLICE_W - 1:0][ESZ - 1:0] v2;
        logic [SLICE_W - 1:0] mask;
        logic valid_in;
        logic ready_out;
        alu_op_t [SLICE_W - 1:0] aluop;
        logic [SLICE_W - 1:0] rm;

    } lane_sequencer_if_in_t;

    
    typedef struct packed {
        logic [ESZ - 1:0] v1;
        logic [ESZ - 1:0] v2;
        logic mask;
        logic valid_out;
        logic ready_in;
        alu_op_t aluop;
        logic rm;
    } lane_sequencer_if_out_t;

    // =========================================================================
    // Result Collector structs
    // =========================================================================
    typedef struct packed {
        logic [NUM_LANES-1:0] input_valid;
        logic [NUM_LANES-1:0] mask;
        logic wb_ready;
        logic [NUM_LANES-1:0][ESZ-1:0] lane_input;
        logic [VIDX_W-1:0]     vd_input;
        logic           mop_in;
    } result_collector_in_t;

    typedef struct packed {
        logic [NUM_LANES-1:0] input_ready;
        logic wb_valid;

        vreg_t          vector_output;
        logic [VIDX_W-1:0]     vd_output;
        logic           mop_out;
    } result_collector_out_t;

    // =========================================================================
    // Unified Functional Unit Interface structs
    // =========================================================================
    typedef struct packed {
        logic input_valid;
        logic [SLICE_W-1:0][ESZ-1:0] v1, v2;
        fu_t usel;
        logic [VIDX_W-1:0] vd;
        logic rm;
        logic [SLICE_W-1:0] mask;
        alu_op_t alu_op;
    } functional_unit_issue_port_t;
    
    typedef struct packed {
        functional_unit_issue_port_t [LANE_ISSUE_W-1:0] ports;
        logic wb_ready;
    } functional_unit_in_t;

    typedef struct packed {
        logic [ESZ-1:0] result;
        logic wb_valid;
        logic rm;
        logic [VIDX_W-1:0] vd;
        logic input_ready;
        logic mask;
        logic mop_out;
    } functional_unit_out_t;


    //reduction stuff
        typedef struct packed {
        vreg_t vector_input;
        logic [NUM_LANES-1:0][ESZ-1:0] lane_input;
        logic [4:0] imm;
        logic clear, broadcast, valid_in, ready_out;
        alu_op_t reduction_type;
    } reduction_if_in_t;

    typedef struct packed {
        vreg_t vector_output;
        logic valid_out, ready_in;
    } reduction_if_out_t;

    //lane structs
    typedef struct packed {
        logic [LANE_ISSUE_W-1:0] input_valid;
        logic [LANE_ISSUE_W-1:0][SLICE_W - 1:0][ESZ - 1:0] v1;
        logic [LANE_ISSUE_W-1:0][SLICE_W - 1:0][ESZ - 1:0] v2;
        fu_t  [LANE_ISSUE_W-1:0] usel;
        logic [LANE_ISSUE_W-1:0][VIDX_W-1:0] vd;
        logic [LANE_ISSUE_W-1:0] rm;
        logic [LANE_ISSUE_W-1:0][SLICE_W - 1:0] mask;
        alu_op_t [LANE_ISSUE_W-1:0] aluop;
        logic [LANE_FU_COUNT-1:0] ready;
    } lane_in_t;

    typedef struct packed {
        functional_unit_out_t [LANE_FU_COUNT-1:0] units;
    } lane_out_t;

    typedef struct packed {
        logic                        valid;
        logic                        write;
        logic [SCPAD_ADDR_WIDTH-1:0] spad_addr;
        logic [VIDX_W-1:0]          vdst;
        logic [MAX_DIM_WIDTH-1:0]   num_cols;
        logic [MAX_DIM_WIDTH-1:0]   row_id;
        
    } vlsu_sched_req_t;

    // VLSU => Scheduler
    typedef struct packed {
        logic ready;
    } vlsu_sched_res_t;

    // VRF => VLSU (store data)
    typedef struct packed {
        vreg_t data;
        logic  valid;
    } vlsu_vrf_store_t;

    // VLSU => Writeback Buffer (load data)
    typedef struct packed {
        vreg_t             load_data;
        logic [VIDX_W-1:0] vdst;
        logic              valid;
    } vlsu_wb_t;

    // VLSU status
    typedef struct packed {
        logic busy;
        logic load_queue_full;
    } vlsu_status_t;
    



    // =========================================================================
    // Top-level vector if structs
    // =========================================================================
    
    typedef struct packed {
        logic [LANE_FU_COUNT-1:0] fu_global_status;
        logic gsau_status;
        vlsu_sched_res_t [NUM_SCPADS-1:0] vlsu_status;
        logic reduction_status;
    } vector_if_unit_ready_t;

    typedef struct packed {
        logic [LANE_FU_COUNT-1:0] lanes_wb_ready;
        logic gsau_wb_ready;
        logic [NUM_SCPADS-1:0] vlsu_wb_ready;
        logic reduction_wb_ready;
    } vector_if_wb_ready_t;

    typedef struct packed {
        vreg_t veg_vdata1;
        vreg_t veg_vdata2;
        logic [7:0] vd;
        logic valid_in;
        logic weight;
    } vector_if_gsau_in_t;

    typedef struct packed {
        logic ready_out;
        vreg_t psum;
        logic [7:0] vd;
        logic wb_valid;
    } vector_if_gsau_out_t;
    
    typedef struct packed {
        vlsu_sched_req_t [NUM_SCPADS-1:0] sched_req;
        vlsu_vrf_store_t [NUM_SCPADS-1:0] vrf_data;
    } vector_if_vlsu_in_t;

    typedef struct packed {
        vlsu_wb_t [NUM_SCPADS-1:0] wb;
        vlsu_status_t [NUM_SCPADS-1:0] status;
    } vector_if_vlsu_out_t;

    typedef struct packed {
        logic input_valid;
        vreg_t v1;
        vreg_t v2;
        fu_t usel;
        logic [7:0] vd;
        logic rm;
        vmask_t mask;
        alu_op_t alu_op;
    } lanes_issue_port_t;

    typedef struct packed {
        lanes_issue_port_t [LANE_ISSUE_W-1:0] ports;
        logic [NUM_LANES-1:0][ESZ-1:0] lane_input;
        logic lane_valid;
        logic wb_ready;        
    } vector_if_reduction_in_t;

    typedef struct packed {
        logic wb_valid;
        vreg_t vector_output;
        logic [7:0]     vd_output;
        logic input_ready;
    } vector_if_reduction_out_t;

    typedef struct packed {
        lanes_issue_port_t [LANE_ISSUE_W-1:0] lane_issue_ports;
    } vector_if_lanes_in_t;

    typedef struct packed {
        result_collector_out_t [LANE_FU_COUNT-1:0] result_collectors;
        vector_if_reduction_out_t reduction;
    } vector_if_lanes_out_t;

endpackage

`endif
