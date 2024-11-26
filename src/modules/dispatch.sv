`include "datapath_types.vh"
`include "dispatch_if.vh"
`include "rst_s_if.vh"
`include "rst_m_if.vh"

module dispatch(
    input logic CLK, nRST,
    dispatch_if.DI diif
);

    import isa_pkg::*;
    import datapath_pkg::*;

    // Instantiations
    control_unit_if cuif();
    rst_s_if rstsif();
    rst_m_if rstmif();

    control_unit CU(cuif);
    rst_s RSTS(CLK, nRST, rstsif);
    rst_m RSTM(CLK, nRST, rstmif);

    // Local Variables
    logic WAW;
    logic s_busy;
    logic m_busy;
    logic hazard;
    logic [31:0] instr;
    opcode_t op;
    logic [4:0] s_rd, s_rs1, s_rs2;
    logic [3:0] m_rd, m_rs1, m_rs2, m_rs3;
    logic [15:0] imm;
    logic flush;
    dispatch_t n_dispatch;
    dispatch_t dispatch;

    always_ff @ (posedge CLK, negedge nRST) begin: Pipeline_Latching
      if (~nRST)
        diif.out <= '0;
    	else
        diif.out <= n_dispatch;
    end

    assign flush = diif.flush & diif.ihit;
    always_comb begin : Pipeline_Output
      case (1'b1)
        flush:       n_dispatch = '0;
        diif.freeze: n_dispatch = diif.out;
        hazard:      n_dispatch = diif.out;
        diif.ihit:   n_dispatch = dispatch;
        default:     n_dispatch = diif.out;
      endcase
    end

    always_comb begin: Instr_Signals
      instr = diif.fetch.imemload;
      op = opcode_t'(instr[6:0]);
      s_rd = instr[11:7];
      s_rs1 = instr[19:15];
      s_rs2 = instr[24:20];
      m_rd = instr[31:28];
      m_rs1 = instr[27:24];
      m_rs2 = instr[23:20];
      m_rs3 = instr[19:16];
      imm = instr[15:0];
    end

    always_comb begin : Control_Unit
      cuif.instr = instr;
    end

    always_comb begin : Hazard_Logic
      case (cuif.fu_s)
        FU_ALU:     s_busy = diif.fust_s.op[FU_ALU].busy;
        FU_LD_ST:   s_busy = diif.fust_s.op[FU_LD_ST].busy;
        FU_BRANCH:  s_busy = diif.fust_s.op[FU_BRANCH].busy;
        default: s_busy = 1'b0;
      endcase
      case (cuif.fu_m)
        FU_LD_ST_M: m_busy = diif.fust_m.op[FU_LD_ST_M].busy;
        FU_GEMM:    m_busy = diif.fust_m.op[FU_GEMM].busy;
        default: m_busy = 1'b0;
      endcase

      WAW = (cuif.m_mem_type == M_LOAD | cuif.fu_m == FU_GEMM) ? rstmif.status[m_rd].busy : 
            (cuif.reg_write) ? rstsif.status[s_rd].busy: 1'b0;
      hazard = s_busy | m_busy | WAW;
    end

    always_comb begin : Reg_Status_Tables
      init_rst();

      // only write to Reg Status Table if doing a regwrite,
      // and the instruction is actually moving forward
      if (cuif.reg_write) begin
        if (~WAW & ~flush & ~diif.freeze) begin
          rstsif.di_sel = s_rd;
          rstsif.di_write = 1'b1;
          rstsif.di_tag = (cuif.fu_s == FU_LD_ST); // 0 for ALU, 1 for LD
        end
      end

      // maybe add a m_reg_write in cuif to simplify
      if (cuif.m_mem_type == M_LOAD | cuif.fu_m == FU_GEMM) begin
        if (~WAW & ~flush & ~diif.freeze) begin
          rstmif.di_sel = m_rd;
          rstmif.di_write = 1'b1;
          rstmif.di_tag = (cuif.fu_m == FU_LD_ST_M); // 0 for GEMM, 1 for LD
        end
      end
      
      // writeback needs to update the RST on commits
      if (diif.wb.srw_en) begin
        rstsif.wb_sel = diif.wb.srw;
        rstsif.wb_write = diif.wb.srw_en;
      end

      if (diif.wb.mrw_en) begin
        rstmif.wb_sel = diif.wb.mrw;
        rstmif.wb_write = diif.wb.mrw_en;
      end
    end

    always_comb begin : Dispatch_Out
      dispatch = diif.out;

      // To Issue
      if (cuif.fu_m == FU_LD_ST_M) begin // matrix FUST
        dispatch.fust_m.op.busy = 1'b1;
        dispatch.fust_m.op.rd  = m_rd;
        dispatch.fust_m.op.rs1 = s_rs1;
        dispatch.fust_m.op.rs2 = s_rs2;
        dispatch.fust_m.op.t1 = rstsif.status[s_rs1].tag;
        dispatch.fust_m.op.t2 = rstsif.status[s_rs2].tag;
      end else if (cuif.fu_m == FU_GEMM) begin // gemm FUST
        dispatch.fust_g.op.busy = 1'b1;
        dispatch.fust_g.op.rd  = m_rd;
        dispatch.fust_g.op.rs1 = m_rs1;
        dispatch.fust_g.op.rs2 = m_rs2;
        dispatch.fust_g.op.rs3 = m_rs3;
        dispatch.fust_g.op.t1 = rstmif.status[m_rs1].tag;
        dispatch.fust_g.op.t2 = rstmif.status[m_rs2].tag;
        dispatch.fust_g.op.t3 = rstmif.status[m_rs3].tag;
      end begin // scalar FUST
        dispatch.fust_s.op[cuif.fu_s].busy = 1'b1;
        dispatch.fust_s.op[cuif.fu_s].rd  = s_rd;
        dispatch.fust_s.op[cuif.fu_s].rs1 = s_rs1;
        dispatch.fust_s.op[cuif.fu_s].rs2 = s_rs2;
        dispatch.fust_s.op[cuif.fu_s].t1 = rstsif.status[s_rs1].tag;
        dispatch.fust_s.op[cuif.fu_s].t2 = rstsif.status[s_rs2].tag;
      end

      // To Execute
      dispatch.fu_alu_ctr.alu_op = cuif.alu_op;
      dispatch.fu_branch_ctr.branch_op = cuif.branch_op;
      dispatch.fu_ldst_ctr.imm = cuif.imm;
      dispatch.fu_ldst_ctr.mem_type = cuif.s_mem_type;
      dispatch.fu_ldst_m_ctr.imm = cuif.imm;
      dispatch.fu_ldst_m_ctr.mem_type = cuif.m_mem_type;

      // To Writeback
      dispatch.wb.s_rw_en = cuif.reg_write;
      dispatch.wb.s_rw = s_rd;
      dispatch.wb.m_rw_en = (cuif.m_mem_type == M_LOAD | cuif.m_mem_type == FU_GEMM);
      dispatch.wb.m_rw = m_rd;
    end

    function automatic void init_rst();
      begin
        rstsif.di_sel = '0;
        rstsif.di_write = 1'b0;
        rstsif.di_tag = '0;
        rstsif.wb_sel = '0;
        rstsif.wb_write = 1'b0;

        rstmif.di_sel = '0;
        rstmif.di_write = 1'b0;
        rstmif.di_tag = '0;
        rstmif.wb_sel = '0;
        rstmif.wb_write = 1'b0;
      end
    endfunction
endmodule
