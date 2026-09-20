//`include "dram_pkg.svh"
//`include "arch_defines.v"
//`include "ddr_controller_if.sv"
//`include "arch_defines.v"
//`include "dimm.vh"
`timescale 1 ns / 1 ps
`define DDR4_1333


//Welcome to the mess, here is just a bunch of code that trying to verify DDR4!
// 1. Test the power up state
// 2. Test the refresh cycle 
// 3. Test row miss write row hit read
// 4. Test row hit write row hit read
// 5. Test the refresh and row miss read
// 6. Test 3 consectutive  row miss write
// 7. Test row conflict write (after 3 consecutive write, I write the conflict row into last row of consecutive writes) (REFRESH happened during writing)
// 8. Test row conflcit read (the last consecutive addr conflict number 7)
// 9. Test 16 consecutive write with different bank
// 10. Test 1000 random read and write of different commands

//RUNING SIMULATION: make dram_top

module dram_top_tb;
    parameter PERIOD = 1500ps;
    parameter tCK = 1500ps;
    import dram_pkg::*; 
    import proj_package::*; // protected vcs

    //parameter from dram_command_if.vh
    parameter CONFIGURED_DQ_BITS     = 8;
    parameter CONFIGURED_DQS_BITS    = (16 == CONFIGURED_DQ_BITS) ? 2 : 1;
    parameter CONFIGURED_DM_BITS     = (16 == CONFIGURED_DQ_BITS) ? 2 : 1;
    parameter CONFIGURED_RANKS       = 1;
    
    //CLK and debug signals
    logic CLK = 0, nRST;
    logic CLKx2=0;
    reg model_enable_val;
    wire model_enable;
    string task_name;

    //Instantiate the the iDDR4_1 version
    logic DM_debug; //Used it if you want to debug with writing mask
    assign model_enable = model_enable_val;

    //Signal flag to choose write or read
    reg dq_en;
    reg dqs_en;
    
    //Clock generation of CK and CKx2
    //Issue right now, CK is follow TS_1500 tCK is 1.5ns
    //I want to figure out a way that can change different configurations to choose TS_1500 (right now micron dram is TS_1250 - 1.25ns)
    always begin
        CLK = 1'b0;
        #(PERIOD / 2.0);
        CLK = 1'b1;
        #(PERIOD / 2.0);
    end

    always begin
        CLKx2 = 1'b0;
        #(PERIOD / 4.0);
        CLKx2 = 1'b1;
        #(PERIOD / 4.0);
    end

    //Instantiate the interface of DRAM controller and DDR4 DRAM
    ddr_controller_if ddrif();

    DDR4_if #(.CONFIGURED_DQ_BITS(CONFIGURED_DQ_BITS)) iDDR4_1();
    DDR4_if #(.CONFIGURED_DQ_BITS(CONFIGURED_DQ_BITS)) iDDR4_2();
    DDR4_if #(.CONFIGURED_DQ_BITS(CONFIGURED_DQ_BITS)) iDDR4_3();
    DDR4_if #(.CONFIGURED_DQ_BITS(CONFIGURED_DQ_BITS)) iDDR4_4();
    DDR4_if #(.CONFIGURED_DQ_BITS(CONFIGURED_DQ_BITS)) iDDR4_5();
    DDR4_if #(.CONFIGURED_DQ_BITS(CONFIGURED_DQ_BITS)) iDDR4_6();
    DDR4_if #(.CONFIGURED_DQ_BITS(CONFIGURED_DQ_BITS)) iDDR4_7();
    DDR4_if #(.CONFIGURED_DQ_BITS(CONFIGURED_DQ_BITS)) iDDR4_8();

    ddr_controller_wrapper DUT (.CLK(CLK), .CLKx2(CLKx2), .nRST(nRST), .top(ddrif));

    //No more Cache or Scheduler, but keep the prev_addr
    // TODO: Bank Group maybe? Check TCCD_L vs TCCD_S 

    // ── DRAM model CK and command bus connections ─────────────────────────────
    // The DRAM model is clocked by iDDR4_N.CK[1] (CK_t) / CK[0] (CK_c).
    // Connect these directly to the free-running CLK so the model always has
    // a clock.  All command/address signals are continuous assigns so the DRAM
    // sees every transition without a registered intermediate.
    // CK[1] = CK_t, CK[0] = CK_c (differential pair)
    /*
    assign iDDR4_1.CK = {CLK, ~CLK};
    assign iDDR4_2.CK = {CLK, ~CLK};
    assign iDDR4_3.CK = {CLK, ~CLK};
    assign iDDR4_4.CK = {CLK, ~CLK};
    assign iDDR4_5.CK = {CLK, ~CLK};
    assign iDDR4_6.CK = {CLK, ~CLK};
    assign iDDR4_7.CK = {CLK, ~CLK};
    assign iDDR4_8.CK = {CLK, ~CLK};
    */

    reg clk_val, clk_enb;

    always @(posedge clk_val && clk_enb) begin
      clk_val <= #(tCK/2) 1'b0;
      clk_val <= #(tCK) 1'b1;
      iDDR4_1.CK[1] <= #(tCK/2) 1'b0;
      iDDR4_1.CK[1] <= #(tCK) 1'b1;
      iDDR4_1.CK[0] <= #(tCK/2) 1'b1;
      iDDR4_1.CK[0] <= #(tCK) 1'b0;

      iDDR4_2.CK[1] <= #(tCK/2) 1'b0;
      iDDR4_2.CK[1] <= #(tCK) 1'b1;
      iDDR4_2.CK[0] <= #(tCK/2) 1'b1;
      iDDR4_2.CK[0] <= #(tCK) 1'b0;


      iDDR4_3.CK[1] <= #(tCK/2) 1'b0;
      iDDR4_3.CK[1] <= #(tCK) 1'b1;
      iDDR4_3.CK[0] <= #(tCK/2) 1'b1;
      iDDR4_3.CK[0] <= #(tCK) 1'b0;

      iDDR4_4.CK[1] <= #(tCK/2) 1'b0;
      iDDR4_4.CK[1] <= #(tCK) 1'b1;
      iDDR4_4.CK[0] <= #(tCK/2) 1'b1;
      iDDR4_4.CK[0] <= #(tCK) 1'b0;



      iDDR4_5.CK[1] <= #(tCK/2) 1'b0;
      iDDR4_5.CK[1] <= #(tCK) 1'b1;
      iDDR4_5.CK[0] <= #(tCK/2) 1'b1;
      iDDR4_5.CK[0] <= #(tCK) 1'b0;

      iDDR4_6.CK[1] <= #(tCK/2) 1'b0;
      iDDR4_6.CK[1] <= #(tCK) 1'b1;
      iDDR4_6.CK[0] <= #(tCK/2) 1'b1;
      iDDR4_6.CK[0] <= #(tCK) 1'b0;


      iDDR4_7.CK[1] <= #(tCK/2) 1'b0;
      iDDR4_7.CK[1] <= #(tCK) 1'b1;
      iDDR4_7.CK[0] <= #(tCK/2) 1'b1;
      iDDR4_7.CK[0] <= #(tCK) 1'b0;

      iDDR4_8.CK[1] <= #(tCK/2) 1'b0;
      iDDR4_8.CK[1] <= #(tCK) 1'b1;
      iDDR4_8.CK[0] <= #(tCK/2) 1'b1;
      iDDR4_8.CK[0] <= #(tCK) 1'b0;
      


      iDDR4_1.ACT_n      <= ddrif.ACT_n;
      iDDR4_1.RAS_n_A16  <= ddrif.RAS_n_A16;
      iDDR4_1.CAS_n_A15  <= ddrif.CAS_n_A15;
      iDDR4_1.WE_n_A14   <= ddrif.WE_n_A14;
    // ALERT_n is driven by the DRAM model (parity error output) — do not drive here
      iDDR4_1.PARITY     <= ddrif.PARITY;
      iDDR4_1.RESET_n    <= ddrif.RESET_n;
      iDDR4_1.TEN        <= ddrif.TEN;
      iDDR4_1.CS_n       <= ddrif.CS_n;
      iDDR4_1.CKE        <= ddrif.CKE;
      iDDR4_1.ODT        <= ddrif.ODT;
      iDDR4_1.C          <= ddrif.C;
      iDDR4_1.BG         <= ddrif.BG;
      iDDR4_1.BA         <= ddrif.BA;
      iDDR4_1.ADDR       <= ddrif.ADDR;
      iDDR4_1.ADDR_17    <= ddrif.ADDR_17;
      iDDR4_1.ZQ         <= ddrif.ZQ;
      iDDR4_1.PWR        <= ddrif.PWR;
      iDDR4_1.VREF_CA    <= ddrif.VREF_CA;
      iDDR4_1.VREF_DQ    <= ddrif.VREF_DQ;

      iDDR4_2.ACT_n      <= ddrif.ACT_n;
      iDDR4_2.RAS_n_A16  <= ddrif.RAS_n_A16;
      iDDR4_2.CAS_n_A15  <= ddrif.CAS_n_A15;
      iDDR4_2.WE_n_A14   <= ddrif.WE_n_A14;
      iDDR4_2.PARITY     <= ddrif.PARITY;
      iDDR4_2.RESET_n    <= ddrif.RESET_n;
      iDDR4_2.TEN        <= ddrif.TEN;
      iDDR4_2.CS_n       <= ddrif.CS_n;
      iDDR4_2.CKE        <= ddrif.CKE;
      iDDR4_2.ODT        <= ddrif.ODT;
      iDDR4_2.C          <= ddrif.C;
      iDDR4_2.BG         <= ddrif.BG;
      iDDR4_2.BA         <= ddrif.BA;
      iDDR4_2.ADDR       <= ddrif.ADDR;
      iDDR4_2.ADDR_17    <= ddrif.ADDR_17;
      iDDR4_2.ZQ         <= ddrif.ZQ;
      iDDR4_2.PWR        <= ddrif.PWR;
      iDDR4_2.VREF_CA    <= ddrif.VREF_CA;
      iDDR4_2.VREF_DQ    <= ddrif.VREF_DQ;

      iDDR4_3.ACT_n      <= ddrif.ACT_n;
      iDDR4_3.RAS_n_A16  <= ddrif.RAS_n_A16;
      iDDR4_3.CAS_n_A15  <= ddrif.CAS_n_A15;
      iDDR4_3.WE_n_A14   <= ddrif.WE_n_A14;
      iDDR4_3.PARITY     <= ddrif.PARITY;
      iDDR4_3.RESET_n    <= ddrif.RESET_n;
      iDDR4_3.TEN        <= ddrif.TEN;
      iDDR4_3.CS_n       <= ddrif.CS_n;
      iDDR4_3.CKE        <= ddrif.CKE;
      iDDR4_3.ODT        <= ddrif.ODT;
      iDDR4_3.C          <= ddrif.C;
      iDDR4_3.BG         <= ddrif.BG;
      iDDR4_3.BA         <= ddrif.BA;
      iDDR4_3.ADDR       <= ddrif.ADDR;
      iDDR4_3.ADDR_17    <= ddrif.ADDR_17;
      iDDR4_3.ZQ         <= ddrif.ZQ;
      iDDR4_3.PWR        <= ddrif.PWR;
      iDDR4_3.VREF_CA    <= ddrif.VREF_CA;
      iDDR4_3.VREF_DQ    <= ddrif.VREF_DQ;

      iDDR4_4.ACT_n      <= ddrif.ACT_n;
      iDDR4_4.RAS_n_A16  <= ddrif.RAS_n_A16;
      iDDR4_4.CAS_n_A15  <= ddrif.CAS_n_A15;
      iDDR4_4.WE_n_A14   <= ddrif.WE_n_A14;
      iDDR4_4.PARITY     <= ddrif.PARITY;
      iDDR4_4.RESET_n    <= ddrif.RESET_n;
      iDDR4_4.TEN        <= ddrif.TEN;
      iDDR4_4.CS_n       <= ddrif.CS_n;
      iDDR4_4.CKE        <= ddrif.CKE;
      iDDR4_4.ODT        <= ddrif.ODT;
      iDDR4_4.C          <= ddrif.C;
      iDDR4_4.BG         <= ddrif.BG;
      iDDR4_4.BA         <= ddrif.BA;
      iDDR4_4.ADDR       <= ddrif.ADDR;
      iDDR4_4.ADDR_17    <= ddrif.ADDR_17;
      iDDR4_4.ZQ         <= ddrif.ZQ;
      iDDR4_4.PWR        <= ddrif.PWR;
      iDDR4_4.VREF_CA    <= ddrif.VREF_CA;
      iDDR4_4.VREF_DQ    <= ddrif.VREF_DQ;

      iDDR4_5.ACT_n      <= ddrif.ACT_n;
      iDDR4_5.RAS_n_A16  <= ddrif.RAS_n_A16;
      iDDR4_5.CAS_n_A15  <= ddrif.CAS_n_A15;
      iDDR4_5.WE_n_A14   <= ddrif.WE_n_A14;
      iDDR4_5.PARITY     <= ddrif.PARITY;
      iDDR4_5.RESET_n    <= ddrif.RESET_n;
      iDDR4_5.TEN        <= ddrif.TEN;
      iDDR4_5.CS_n       <= ddrif.CS_n;
      iDDR4_5.CKE        <= ddrif.CKE;
      iDDR4_5.ODT        <= ddrif.ODT;
      iDDR4_5.C          <= ddrif.C;
      iDDR4_5.BG         <= ddrif.BG;
      iDDR4_5.BA         <= ddrif.BA;
      iDDR4_5.ADDR       <= ddrif.ADDR;
      iDDR4_5.ADDR_17    <= ddrif.ADDR_17;
      iDDR4_5.ZQ         <= ddrif.ZQ;
      iDDR4_5.PWR        <= ddrif.PWR;
      iDDR4_5.VREF_CA    <= ddrif.VREF_CA;
      iDDR4_5.VREF_DQ    <= ddrif.VREF_DQ;

      iDDR4_6.ACT_n      <= ddrif.ACT_n;
      iDDR4_6.RAS_n_A16  <= ddrif.RAS_n_A16;
      iDDR4_6.CAS_n_A15  <= ddrif.CAS_n_A15;
      iDDR4_6.WE_n_A14   <= ddrif.WE_n_A14;
      iDDR4_6.PARITY     <= ddrif.PARITY;
      iDDR4_6.RESET_n    <= ddrif.RESET_n;
      iDDR4_6.TEN        <= ddrif.TEN;
      iDDR4_6.CS_n       <= ddrif.CS_n;
      iDDR4_6.CKE        <= ddrif.CKE;
      iDDR4_6.ODT        <= ddrif.ODT;
      iDDR4_6.C          <= ddrif.C;
      iDDR4_6.BG         <= ddrif.BG;
      iDDR4_6.BA         <= ddrif.BA;
      iDDR4_6.ADDR       <= ddrif.ADDR;
      iDDR4_6.ADDR_17    <= ddrif.ADDR_17;
      iDDR4_6.ZQ         <= ddrif.ZQ;
      iDDR4_6.PWR        <= ddrif.PWR;
      iDDR4_6.VREF_CA    <= ddrif.VREF_CA;
      iDDR4_6.VREF_DQ    <= ddrif.VREF_DQ;

      iDDR4_7.ACT_n      <= ddrif.ACT_n;
      iDDR4_7.RAS_n_A16  <= ddrif.RAS_n_A16;
      iDDR4_7.CAS_n_A15  <= ddrif.CAS_n_A15;
      iDDR4_7.WE_n_A14   <= ddrif.WE_n_A14;
      iDDR4_7.PARITY     <= ddrif.PARITY;
      iDDR4_7.RESET_n    <= ddrif.RESET_n;
      iDDR4_7.TEN        <= ddrif.TEN;
      iDDR4_7.CS_n       <= ddrif.CS_n;
      iDDR4_7.CKE        <= ddrif.CKE;
      iDDR4_7.ODT        <= ddrif.ODT;
      iDDR4_7.C          <= ddrif.C;
      iDDR4_7.BG         <= ddrif.BG;
      iDDR4_7.BA         <= ddrif.BA;
      iDDR4_7.ADDR       <= ddrif.ADDR;
      iDDR4_7.ADDR_17    <= ddrif.ADDR_17;
      iDDR4_7.ZQ         <= ddrif.ZQ;
      iDDR4_7.PWR        <= ddrif.PWR;
      iDDR4_7.VREF_CA    <= ddrif.VREF_CA;
      iDDR4_7.VREF_DQ    <= ddrif.VREF_DQ;

      iDDR4_8.ACT_n      <= ddrif.ACT_n;
      iDDR4_8.RAS_n_A16  <= ddrif.RAS_n_A16;
      iDDR4_8.CAS_n_A15  <= ddrif.CAS_n_A15;
      iDDR4_8.WE_n_A14   <= ddrif.WE_n_A14;
      iDDR4_8.PARITY     <= ddrif.PARITY;
      iDDR4_8.RESET_n    <= ddrif.RESET_n;
      iDDR4_8.TEN        <= ddrif.TEN;
      iDDR4_8.CS_n       <= ddrif.CS_n;
      iDDR4_8.CKE        <= ddrif.CKE;
      iDDR4_8.ODT        <= ddrif.ODT;
      iDDR4_8.C          <= ddrif.C;
      iDDR4_8.BG         <= ddrif.BG;
      iDDR4_8.BA         <= ddrif.BA;
      iDDR4_8.ADDR       <= ddrif.ADDR;
      iDDR4_8.ADDR_17    <= ddrif.ADDR_17;
      iDDR4_8.ZQ         <= ddrif.ZQ;
      iDDR4_8.PWR        <= ddrif.PWR;
      iDDR4_8.VREF_CA    <= ddrif.VREF_CA;
      iDDR4_8.VREF_DQ    <= ddrif.VREF_DQ;
end
/*
    assign iDDR4_1.ACT_n     = ddrif.ACT_n;
    assign iDDR4_1.RAS_n_A16 = ddrif.RAS_n_A16;
    assign iDDR4_1.CAS_n_A15 = ddrif.CAS_n_A15;
    assign iDDR4_1.WE_n_A14  = ddrif.WE_n_A14;
    // ALERT_n is driven by the DRAM model (parity error output) — do not drive here
    assign iDDR4_1.PARITY    = ddrif.PARITY;
    assign iDDR4_1.RESET_n   = ddrif.RESET_n;
    assign iDDR4_1.TEN       = ddrif.TEN;
    assign iDDR4_1.CS_n      = ddrif.CS_n;
    assign iDDR4_1.CKE       = ddrif.CKE;
    assign iDDR4_1.ODT       = ddrif.ODT;
    assign iDDR4_1.C         = ddrif.C;
    assign iDDR4_1.BG        = ddrif.BG;
    assign iDDR4_1.BA        = ddrif.BA;
    assign iDDR4_1.ADDR      = ddrif.ADDR;
    assign iDDR4_1.ADDR_17   = ddrif.ADDR_17;
    assign iDDR4_1.ZQ        = ddrif.ZQ;
    assign iDDR4_1.PWR       = ddrif.PWR;
    assign iDDR4_1.VREF_CA   = ddrif.VREF_CA;
    assign iDDR4_1.VREF_DQ   = ddrif.VREF_DQ;

    assign iDDR4_2.ACT_n     = ddrif.ACT_n;
    assign iDDR4_2.RAS_n_A16 = ddrif.RAS_n_A16;
    assign iDDR4_2.CAS_n_A15 = ddrif.CAS_n_A15;
    assign iDDR4_2.WE_n_A14  = ddrif.WE_n_A14;
    assign iDDR4_2.PARITY    = ddrif.PARITY;
    assign iDDR4_2.RESET_n   = ddrif.RESET_n;
    assign iDDR4_2.TEN       = ddrif.TEN;
    assign iDDR4_2.CS_n      = ddrif.CS_n;
    assign iDDR4_2.CKE       = ddrif.CKE;
    assign iDDR4_2.ODT       = ddrif.ODT;
    assign iDDR4_2.C         = ddrif.C;
    assign iDDR4_2.BG        = ddrif.BG;
    assign iDDR4_2.BA        = ddrif.BA;
    assign iDDR4_2.ADDR      = ddrif.ADDR;
    assign iDDR4_2.ADDR_17   = ddrif.ADDR_17;
    assign iDDR4_2.ZQ        = ddrif.ZQ;
    assign iDDR4_2.PWR       = ddrif.PWR;
    assign iDDR4_2.VREF_CA   = ddrif.VREF_CA;
    assign iDDR4_2.VREF_DQ   = ddrif.VREF_DQ;

    assign iDDR4_3.ACT_n     = ddrif.ACT_n;
    assign iDDR4_3.RAS_n_A16 = ddrif.RAS_n_A16;
    assign iDDR4_3.CAS_n_A15 = ddrif.CAS_n_A15;
    assign iDDR4_3.WE_n_A14  = ddrif.WE_n_A14;
    assign iDDR4_3.PARITY    = ddrif.PARITY;
    assign iDDR4_3.RESET_n   = ddrif.RESET_n;
    assign iDDR4_3.TEN       = ddrif.TEN;
    assign iDDR4_3.CS_n      = ddrif.CS_n;
    assign iDDR4_3.CKE       = ddrif.CKE;
    assign iDDR4_3.ODT       = ddrif.ODT;
    assign iDDR4_3.C         = ddrif.C;
    assign iDDR4_3.BG        = ddrif.BG;
    assign iDDR4_3.BA        = ddrif.BA;
    assign iDDR4_3.ADDR      = ddrif.ADDR;
    assign iDDR4_3.ADDR_17   = ddrif.ADDR_17;
    assign iDDR4_3.ZQ        = ddrif.ZQ;
    assign iDDR4_3.PWR       = ddrif.PWR;
    assign iDDR4_3.VREF_CA   = ddrif.VREF_CA;
    assign iDDR4_3.VREF_DQ   = ddrif.VREF_DQ;

    assign iDDR4_4.ACT_n     = ddrif.ACT_n;
    assign iDDR4_4.RAS_n_A16 = ddrif.RAS_n_A16;
    assign iDDR4_4.CAS_n_A15 = ddrif.CAS_n_A15;
    assign iDDR4_4.WE_n_A14  = ddrif.WE_n_A14;
    assign iDDR4_4.PARITY    = ddrif.PARITY;
    assign iDDR4_4.RESET_n   = ddrif.RESET_n;
    assign iDDR4_4.TEN       = ddrif.TEN;
    assign iDDR4_4.CS_n      = ddrif.CS_n;
    assign iDDR4_4.CKE       = ddrif.CKE;
    assign iDDR4_4.ODT       = ddrif.ODT;
    assign iDDR4_4.C         = ddrif.C;
    assign iDDR4_4.BG        = ddrif.BG;
    assign iDDR4_4.BA        = ddrif.BA;
    assign iDDR4_4.ADDR      = ddrif.ADDR;
    assign iDDR4_4.ADDR_17   = ddrif.ADDR_17;
    assign iDDR4_4.ZQ        = ddrif.ZQ;
    assign iDDR4_4.PWR       = ddrif.PWR;
    assign iDDR4_4.VREF_CA   = ddrif.VREF_CA;
    assign iDDR4_4.VREF_DQ   = ddrif.VREF_DQ;

    assign iDDR4_5.ACT_n     = ddrif.ACT_n;
    assign iDDR4_5.RAS_n_A16 = ddrif.RAS_n_A16;
    assign iDDR4_5.CAS_n_A15 = ddrif.CAS_n_A15;
    assign iDDR4_5.WE_n_A14  = ddrif.WE_n_A14;
    assign iDDR4_5.PARITY    = ddrif.PARITY;
    assign iDDR4_5.RESET_n   = ddrif.RESET_n;
    assign iDDR4_5.TEN       = ddrif.TEN;
    assign iDDR4_5.CS_n      = ddrif.CS_n;
    assign iDDR4_5.CKE       = ddrif.CKE;
    assign iDDR4_5.ODT       = ddrif.ODT;
    assign iDDR4_5.C         = ddrif.C;
    assign iDDR4_5.BG        = ddrif.BG;
    assign iDDR4_5.BA        = ddrif.BA;
    assign iDDR4_5.ADDR      = ddrif.ADDR;
    assign iDDR4_5.ADDR_17   = ddrif.ADDR_17;
    assign iDDR4_5.ZQ        = ddrif.ZQ;
    assign iDDR4_5.PWR       = ddrif.PWR;
    assign iDDR4_5.VREF_CA   = ddrif.VREF_CA;
    assign iDDR4_5.VREF_DQ   = ddrif.VREF_DQ;

    assign iDDR4_6.ACT_n     = ddrif.ACT_n;
    assign iDDR4_6.RAS_n_A16 = ddrif.RAS_n_A16;
    assign iDDR4_6.CAS_n_A15 = ddrif.CAS_n_A15;
    assign iDDR4_6.WE_n_A14  = ddrif.WE_n_A14;
    assign iDDR4_6.PARITY    = ddrif.PARITY;
    assign iDDR4_6.RESET_n   = ddrif.RESET_n;
    assign iDDR4_6.TEN       = ddrif.TEN;
    assign iDDR4_6.CS_n      = ddrif.CS_n;
    assign iDDR4_6.CKE       = ddrif.CKE;
    assign iDDR4_6.ODT       = ddrif.ODT;
    assign iDDR4_6.C         = ddrif.C;
    assign iDDR4_6.BG        = ddrif.BG;
    assign iDDR4_6.BA        = ddrif.BA;
    assign iDDR4_6.ADDR      = ddrif.ADDR;
    assign iDDR4_6.ADDR_17   = ddrif.ADDR_17;
    assign iDDR4_6.ZQ        = ddrif.ZQ;
    assign iDDR4_6.PWR       = ddrif.PWR;
    assign iDDR4_6.VREF_CA   = ddrif.VREF_CA;
    assign iDDR4_6.VREF_DQ   = ddrif.VREF_DQ;

    assign iDDR4_7.ACT_n     = ddrif.ACT_n;
    assign iDDR4_7.RAS_n_A16 = ddrif.RAS_n_A16;
    assign iDDR4_7.CAS_n_A15 = ddrif.CAS_n_A15;
    assign iDDR4_7.WE_n_A14  = ddrif.WE_n_A14;
    assign iDDR4_7.PARITY    = ddrif.PARITY;
    assign iDDR4_7.RESET_n   = ddrif.RESET_n;
    assign iDDR4_7.TEN       = ddrif.TEN;
    assign iDDR4_7.CS_n      = ddrif.CS_n;
    assign iDDR4_7.CKE       = ddrif.CKE;
    assign iDDR4_7.ODT       = ddrif.ODT;
    assign iDDR4_7.C         = ddrif.C;
    assign iDDR4_7.BG        = ddrif.BG;
    assign iDDR4_7.BA        = ddrif.BA;
    assign iDDR4_7.ADDR      = ddrif.ADDR;
    assign iDDR4_7.ADDR_17   = ddrif.ADDR_17;
    assign iDDR4_7.ZQ        = ddrif.ZQ;
    assign iDDR4_7.PWR       = ddrif.PWR;
    assign iDDR4_7.VREF_CA   = ddrif.VREF_CA;
    assign iDDR4_7.VREF_DQ   = ddrif.VREF_DQ;

    assign iDDR4_8.ACT_n     = ddrif.ACT_n;
    assign iDDR4_8.RAS_n_A16 = ddrif.RAS_n_A16;
    assign iDDR4_8.CAS_n_A15 = ddrif.CAS_n_A15;
    assign iDDR4_8.WE_n_A14  = ddrif.WE_n_A14;
    assign iDDR4_8.PARITY    = ddrif.PARITY;
    assign iDDR4_8.RESET_n   = ddrif.RESET_n;
    assign iDDR4_8.TEN       = ddrif.TEN;
    assign iDDR4_8.CS_n      = ddrif.CS_n;
    assign iDDR4_8.CKE       = ddrif.CKE;
    assign iDDR4_8.ODT       = ddrif.ODT;
    assign iDDR4_8.C         = ddrif.C;
    assign iDDR4_8.BG        = ddrif.BG;
    assign iDDR4_8.BA        = ddrif.BA;
    assign iDDR4_8.ADDR      = ddrif.ADDR;
    assign iDDR4_8.ADDR_17   = ddrif.ADDR_17;
    assign iDDR4_8.ZQ        = ddrif.ZQ;
    assign iDDR4_8.PWR       = ddrif.PWR;
    assign iDDR4_8.VREF_CA   = ddrif.VREF_CA;
    assign iDDR4_8.VREF_DQ   = ddrif.VREF_DQ;
    // (end of continuous command bus connections)
    */

    // Component instantiation
    //Only use 8 chips only, so 64-bit data
    ddr4_model #(.CONFIGURED_DQ_BITS(CONFIGURED_DQ_BITS),  .CONFIGURED_RANKS(CONFIGURED_RANKS)) u0_r0(.model_enable(model_enable), .iDDR4(iDDR4_1));
    ddr4_model #(.CONFIGURED_DQ_BITS(CONFIGURED_DQ_BITS),  .CONFIGURED_RANKS(CONFIGURED_RANKS)) u1_r0(.model_enable(model_enable), .iDDR4(iDDR4_2));
    ddr4_model #(.CONFIGURED_DQ_BITS(CONFIGURED_DQ_BITS),  .CONFIGURED_RANKS(CONFIGURED_RANKS)) u2_r0(.model_enable(model_enable), .iDDR4(iDDR4_3));
    ddr4_model #(.CONFIGURED_DQ_BITS(CONFIGURED_DQ_BITS),  .CONFIGURED_RANKS(CONFIGURED_RANKS)) u3_r0(.model_enable(model_enable), .iDDR4(iDDR4_4));
    ddr4_model #(.CONFIGURED_DQ_BITS(CONFIGURED_DQ_BITS),  .CONFIGURED_RANKS(CONFIGURED_RANKS)) u4_r0(.model_enable(model_enable), .iDDR4(iDDR4_5));
    ddr4_model #(.CONFIGURED_DQ_BITS(CONFIGURED_DQ_BITS),  .CONFIGURED_RANKS(CONFIGURED_RANKS)) u5_r0(.model_enable(model_enable), .iDDR4(iDDR4_6));
    ddr4_model #(.CONFIGURED_DQ_BITS(CONFIGURED_DQ_BITS),  .CONFIGURED_RANKS(CONFIGURED_RANKS)) u6_r0(.model_enable(model_enable), .iDDR4(iDDR4_7));
    ddr4_model #(.CONFIGURED_DQ_BITS(CONFIGURED_DQ_BITS),  .CONFIGURED_RANKS(CONFIGURED_RANKS)) u7_r0(.model_enable(model_enable), .iDDR4(iDDR4_8));

    //Interface between iDDR4 and data transfer example
    // Connect DQ, DQS_t, DQS_c, DM_n
    // Note DM_n is the signal for the writing mask
    assign {
        iDDR4_1.DQ,
        iDDR4_2.DQ,
        iDDR4_3.DQ,
        iDDR4_4.DQ,
        iDDR4_5.DQ,
        iDDR4_6.DQ,
        iDDR4_7.DQ,
        iDDR4_8.DQ
    } = dq_en ? {ddrif.DQ} : {64{1'bz}};


    assign {
        iDDR4_1.DQS_t,
        iDDR4_2.DQS_t,
        iDDR4_3.DQS_t,
        iDDR4_4.DQS_t,
        iDDR4_5.DQS_t,
        iDDR4_6.DQS_t,
        iDDR4_7.DQS_t,
        iDDR4_8.DQS_t
    } = dq_en ? {ddrif.DQS_t,
                 ddrif.DQS_t,
                 ddrif.DQS_t,
                 ddrif.DQS_t,
                 ddrif.DQS_t,
                 ddrif.DQS_t,
                 ddrif.DQS_t,
                 ddrif.DQS_t  
                 } : 8'bzz;

    assign {
        iDDR4_1.DQS_c,
        iDDR4_2.DQS_c,
        iDDR4_3.DQS_c,
        iDDR4_4.DQS_c,
        iDDR4_5.DQS_c,
        iDDR4_6.DQS_c,
        iDDR4_7.DQS_c,
        iDDR4_8.DQS_c
    } = dq_en ? {
        ddrif.DQS_c,
        ddrif.DQS_c,
        ddrif.DQS_c,
        ddrif.DQS_c,
        ddrif.DQS_c,
        ddrif.DQS_c,
        ddrif.DQS_c,
        ddrif.DQS_c
        } : 8'bzz;

    //Writing mask feature
    assign {
        iDDR4_1.DM_n,
        iDDR4_2.DM_n,
        iDDR4_3.DM_n,
        iDDR4_4.DM_n,
        iDDR4_5.DM_n,
        iDDR4_6.DM_n,
        iDDR4_7.DM_n,
        iDDR4_8.DM_n
    } = dq_en ? {
        ddrif.DM_n[0],
        ddrif.DM_n[1],
        ddrif.DM_n[2],
        ddrif.DM_n[3],
        ddrif.DM_n[4],
        ddrif.DM_n[5],
        ddrif.DM_n[6],
        ddrif.DM_n[7]
    } : 8'bzz;


    assign ddrif.DQ = ~dq_en ? {
        iDDR4_1.DQ,
        iDDR4_2.DQ,
        iDDR4_3.DQ,
        iDDR4_4.DQ,
        iDDR4_5.DQ,
        iDDR4_6.DQ,
        iDDR4_7.DQ,
        iDDR4_8.DQ
    } : {64{1'bz}};

    //Assign DQS/DM signals from DRAM model back into the controller interface (read path)
    assign ddrif.DQS_t = ~dq_en ? iDDR4_1.DQS_t : 1'bz;
    assign ddrif.DQS_c = ~dq_en ? iDDR4_1.DQS_c: 1'bz;
    assign ddrif.DM_n  = ~dq_en ? iDDR4_1.DM_n: 8'bz;
    // NOTE: COL_choice mapping needs to be verified - check if this exists in ctrl modport
    // assign ddrif.data_trans.COL_choice = ddrif.ctrl.offset; 

    // Creating class for the transaction -> since this is now an AXI bus vs. scheduler fifo  
    class axi_trans;
        // Getting the AXI Sub->Load/Store Queue and WDQ(wrapper)
        virtual ddr_controller_if.stq           svif;
        virtual ddr_controller_if.lq           lvif; 
        virtual ddr_controller_if.wdata_wrapper wvif;

        //Random rank, bank group, bank, row, col, offset (these go in stq/ldq)
        rand logic [RANK_BITS - 1:0] rank;
        rand logic [BANK_GROUP_BITS - 1:0] BG;
        rand logic [BANK_BITS - 1:0] bank;
        rand logic [ROW_BITS - 1:0] row;
        rand logic [COLUMN_BITS - 1:0] col;
        rand logic [OFFSET_BITS - 1:0] offset;

        // RANDOM WRITE QUEUE SLOT
        rand logic [7:0] wstrb; // TODO: Possible adjustment necessary 
        rand logic [63:0] wdata; 
        rand logic [$clog2(ID_NUM)-1:0] wid; 
        rand logic [2:0] wlen;

        // RANDOM AXI COMMANDS
        rand logic [$clog2(ID_NUM)-1:0] id;
        rand logic [3:0] len; // TODO: Maybe this needs a separate function 

        // Function based
        logic valid, bwready, wlast; // TODO: Possible adjustment necessary 
        logic [31:0] creating_addr, prev_addr; //the actual address

        /* R/W CAN OCCUR SIMULT
        //1. Creating covergroup
        covergroup sch_group @(posedge CLK);
            //2.Creating coverpoint
            sch_point : coverpoint {vif.dREN, vif.dWEN} {
                bins s00 = {2'b00};
                bins s10 = {2'b10};
                bins s01 = {2'b01};
            }
        endgroup        

        //3. Creating the constraint
        //dREN and dWEN should never goes high at the same time
        constraint req_cons {
            {vif.dREN, vif.dWEN} != 2'b11;
        }
        */
        //constraint of addr_rank 
        constraint addr_rank {
            rank == 1'b0;
            row != '1;
            offset == 0;
            col[2:0] == 0; //8-byte align
        }

        function new (
            virtual ddr_controller_if.stq           svif, 
            virtual ddr_controller_if.wdata_wrapper wvif,
            virtual ddr_controller_if.lq            lvif
        );
            this.svif  = svif;
            this.wvif  = wvif;
            this.lvif  = lvif;
        endfunction

        //function for generate the address
        function void gen_addr (string testcase);
            //If you want to add row conflict
            if (testcase == "row conflict") begin
                creating_addr = prev_addr;
                creating_addr[30:17] = '1;
            end else if (testcase == "row hit") begin
                creating_addr = prev_addr;
            end else begin
                creating_addr = {rank, row, bank, BG[1], col[9:3], BG[0], col[2:0], offset};
            end
        endfunction

        function void gen_valid(logic is_valid); 
            this.valid = is_valid; 
        endfunction

        function void gen_write(logic is_ready, logic is_last);
            this.bwready = is_ready;
            this.wlast = is_last;
        endfunction
        
        //This is the task you want to write something in a specific addr
        //Don't worry about the data context

        // AXI_WRITE_CHANNEL -> WRAPPER
        // input wdq_slot, bwready, wvalid, wlast, 
        task writing();
            begin 
                // Send the Write Data to both the STQ and WDQ
                // WDQ: wid and wlen must match awid/awlen so the backend arbiter
                // drains the correct per-ID queue (be_wid = be_id = awid).
                this.wvif.wdq_slot = {this.wstrb, this.wdata, this.id, this.len[2:0]};
                this.wvif.bwready  = this.bwready;
                this.wvif.wvalid   = this.valid;
                this.wvif.wlast    = this.wlast;
                // STQ
                this.svif.awvalid = this.valid;
                this.svif.awaddr  = this.creating_addr;
                this.svif.awlen   = this.len;
                this.svif.awid    = this.id;
                // Store previous for more
                this.prev_addr = this.creating_addr;
                // Randomize 
                // this.randomize();
                // @(posedge CLKx2);
            end
        endtask

        task reading();
            begin 
                // Send the Read Commands to the LQ
                this.lvif.arvalid = this.valid;
                this.lvif.araddr  = this.creating_addr;
                this.lvif.arlen   = this.len;
                this.lvif.arid    = this.id;            
            end
        endtask
    endclass

    //Define class   
    axi_trans axi;

    // TODO: FIX ABOVE, THEN WORK ON BELOW  
    //A random testing case
    task writing_read_row_hit(input axi_trans axi_inst);
        task_name = "Writing_Cycle";
        //Case 2 check the writing cycle
        //Case checking the writing burst
        //Creating new addr
        axi_inst.gen_addr("row miss");
        axi_inst.gen_valid(1'b1);
        axi_inst.gen_write(1'b1, 1'b0); // ready, last
        @(posedge CLK);
        axi_inst.writing();
        repeat (50) @(posedge CLK);

        task_name = "Reading_Cycle";
        dq_en = 1'b0;
        //Case 3 check the reading cycle
        axi_inst.reading();
        repeat (50) @(posedge CLK);
    endtask

    // ── ID tracking: 1 = in-flight, 0 = free ─────────────────────────────
    logic [ID_NUM-1:0] id_in_flight;
    // Shadow memory: addr -> last written data (associative array)
    logic [63:0] shadow_mem [logic [31:0]];

    // Acquire next free ID; blocks until one available
    task automatic acquire_id(output logic [$clog2(ID_NUM)-1:0] got_id);
        got_id = '0;
        forever begin
            for (int k = 0; k < ID_NUM; k++) begin
                if (!id_in_flight[k]) begin
                    id_in_flight[k] = 1'b1;
                    got_id = k[$clog2(ID_NUM)-1:0];
                    return;
                end
            end
            @(posedge CLK);
        end
    endtask

    // Drive AW+W channels for an 8-beat burst write; de-asserts after last beat.
    // Beat b data = wdata ^ {b[3:0], 60'h0}  (beat index in top nibble for traceability).
    task automatic issue_write(
        input logic [31:0]               addr,
        input logic [63:0]               wdata,
        input logic [$clog2(ID_NUM)-1:0] wid
    );
        dq_en          = 1'b1;
        ddrif.awvalid  = 1'b1;
        ddrif.awaddr   = addr;
        ddrif.awid     = wid;
        ddrif.awlen    = 3'd7;   // 8 beats (AXI len = N-1)
        ddrif.bwready  = 1'b1;
        @(posedge CLK);
        while (!ddrif.awready) @(posedge CLK);
        ddrif.awvalid = 1'b0;
        // Drive 8 W-channel beats consecutively; wdq_slot.wlen=7 in every beat
        for (int b = 0; b < 8; b++) begin
            ddrif.wvalid   = 1'b1;
            ddrif.wlast    = (b == 7);
            ddrif.wdq_slot = {8'hFF, wdata ^ {b[3:0], 60'h0}, wid, 3'd7};
            @(posedge CLK);
        end
        ddrif.wvalid = 1'b0;
        ddrif.wlast  = 1'b0;
    endtask

    // Wait for write response matching wid; de-asserts bwready and frees ID
    task automatic wait_write_done(input logic [$clog2(ID_NUM)-1:0] wid);
        while (!(ddrif.bwvalid && ddrif.bwid == wid)) @(posedge CLK);
        ddrif.bwready = 1'b1;
        @(posedge CLK);
        ddrif.bwready     = 1'b0;
        id_in_flight[wid] = 1'b0;
    endtask

    // Drive AR channel for an 8-beat burst read; de-asserts after arready
    task automatic issue_read(
        input logic [31:0]               addr,
        input logic [$clog2(ID_NUM)-1:0] rid
    );
        dq_en         = 1'b0;
        ddrif.arvalid = 1'b1;
        ddrif.araddr  = addr;
        ddrif.arid    = rid;
        ddrif.arlen   = 3'd7;   // 8 beats
        @(posedge CLK);
        while (!ddrif.arready) @(posedge CLK);
        ddrif.arvalid = 1'b0;
    endtask

    // Wait for all 8 read beats from this rid; checks each beat against shadow_mem.
    // Beat b is expected at expected_addr + b*8.  Frees the ID after rlast.
    task automatic wait_read_done(
        input logic [$clog2(ID_NUM)-1:0] rid,
        input logic [31:0]               expected_addr,
        input string                     tc_label
    );
        logic [63:0] got;
        logic        done;
        int          b;
        b    = 0;
        done = 1'b0;
        while (!done) begin
            // Wait for a valid read beat belonging to this transaction
            while (!(ddrif.rvalid && ddrif.rid == rid)) @(posedge CLK);
            got = ddrif.rdata;
            begin : beat_check
                logic [31:0] baddr;
                baddr = expected_addr + 32'(b) * 32'd8;
                if (shadow_mem.exists(baddr)) begin
                    if (got === shadow_mem[baddr])
                        $display("[PASS] %s beat%0d addr=%0h exp=%0h got=%0h",
                                 tc_label, b, baddr, shadow_mem[baddr], got);
                    else
                        $error("[FAIL] %s beat%0d addr=%0h exp=%0h got=%0h",
                               tc_label, b, baddr, shadow_mem[baddr], got);
                end else
                    $display("[INFO] %s beat%0d addr=%0h got=%0h (no shadow)",
                             tc_label, b, baddr, got);
            end
            if (ddrif.rlast) done = 1'b1;
            else begin b++; @(posedge CLK); end
        end
        dq_en             = 1'b1;
        id_in_flight[rid] = 1'b0;
    endtask

    // Directed write then read on a specific bank.
    // bank_idx[3:0] = {BG[1], bank[1], bank[0], BG[0]}
    task automatic directed_wr_rd(
        input logic [3:0]  bank_idx,
        input logic [14:0] row,
        input logic [9:0]  col,
        input logic [63:0] wdata,
        input string       label
    );
        logic [$clog2(ID_NUM)-1:0] txid;
        logic [31:0] addr;
        // {rank=0, row[14:0], bank[1:0]=bank_idx[2:1], BG[1]=bank_idx[3],
        //  col[9:3], BG[0]=bank_idx[0], col[2:0], offset=00}
        addr = {1'b0, row, bank_idx[2:1], bank_idx[3],
                col[9:3], bank_idx[0], col[2:0], 2'b00};
        acquire_id(txid);
        task_name = $sformatf("%s: wr bk%0d", label, bank_idx);
        issue_write(addr, wdata, txid);
        repeat (25) @(posedge CLK);
        wait_write_done(txid);
        // Store expected data for all 8 beats; beat b data = wdata ^ {b[3:0], 60'h0}
        for (int b = 0; b < 8; b++)
            shadow_mem[addr + 32'(b) * 32'd8] = wdata ^ {b[3:0], 60'h0};
        repeat (25) @(posedge CLK);
        acquire_id(txid);
        task_name = $sformatf("%s: rd bk%0d", label, bank_idx);
        issue_read(addr, txid);
        repeat (25) @(posedge CLK);
        wait_read_done(txid, addr, label);
        repeat (25) @(posedge CLK);
    endtask

    /* 
    //This is the task where you want to read the address and verify with cache model
    task read_with_verify (
        input logic [31:0] addr,
        input axi_trans sch
    );
        dq_en = 0;
        add_request(.addr(addr), .write(1'b0), .data(64'hAAAA_AAAA_AAAA_AAAA));
        while (ddrif.ctrl.ram_wait) begin
            cache_read = 1;
            cache_addr = addr[30:16];
            if (ddrif.edge_flag) begin
                cache_offset = cache_offset + 1;
                @(posedge CLKx2);
            end else begin
                cache_offset = 0;
                @(posedge CLKx2);
            end
        end
        dq_en = 1;
        cache_read = 1;
        ddrif.clear = 0;
    endtask
    //Creating the assert to check the failed case of data load
    property wr_verify;
        @(posedge CLK) disable iff (!nRST)
        ddrif.rd_en && (ddrif.edge_flag) |-> (cache_load == ddrif.memload);
    endproperty
    assert property (wr_verify)
    else 
        //If failed it should stop simulation
        $fatal("Time: [%0t], Addr: %0x, offset: %0x, cache load: %0x, dt_memload: %0x",$time,sch.creating_addr[30:16], cache_offset, cache_load, ddrif.memload);


    //Task of writing different 16 writes of different banks
    task consecutive_16_write();
        for (int i = 0; i < 16; i++) begin
            task_name = $sformatf("16 write-dif bank  -%0d", i);
            dq_en = 1'b1;
            sch.randomize();
            sch.gen_addr("row miss", prev_addr);
            writing_1(sch.creating_addr, dt_class);
            while (ddrif.ctrl.ram_wait) begin
                @(posedge CLK);
            end
        end
    endtask

    //1000 request come one by one
    task random_req();
        bit wr_or_rd; 
        for (int i = 0; i < 1000; i++) begin
            task_name = $sformatf("Task random -%0d", i);
            wr_or_rd = $urandom_range(0,1); // simple 0/1;
            if (wr_or_rd) begin
                dq_en = 1'b1;
                sch.randomize();
                sch.gen_addr("row miss", prev_addr);
                writing_1(sch.creating_addr, dt_class);
                while (ddrif.ctrl.ram_wait) begin
                    @(posedge CLK);
                end
            end else begin
                dq_en = 1'b0;
                read_with_verify(sch.creating_addr, sch);
            end 
        end
    endtask */

    initial begin
      // ── DRAM model initialization ─────────────────────────────────────────
      // iDDR4_N.CK is driven by continuous assign {CLK, ~CLK} above — no init needed
      {iDDR4_1.CK, iDDR4_2.CK , iDDR4_3.CK, iDDR4_4.CK , iDDR4_5.CK, iDDR4_6.CK , iDDR4_7.CK, iDDR4_8.CK } <= {8{2'b01}};
      clk_enb <= 1'b1;
      clk_val <= 1'b1;
      model_enable_val = 1'b1;
      dq_en = 1'b1; id_in_flight = '0;

      // ── All DUT inputs idle ────────────────────────────────────────────────
      ddrif.awvalid = 1'b0; ddrif.awaddr = '0; ddrif.awid = '0; ddrif.awlen = '0;
      ddrif.wdq_slot = '0; ddrif.wvalid = 1'b0; ddrif.wlast = 1'b0;
      ddrif.bwready = 1'b0;
      ddrif.arvalid = 1'b0; ddrif.araddr = '0; ddrif.arid = '0; ddrif.arlen = '0;
      ddrif.rready = 1'b1;  // master always ready to accept read data
      ddrif.init_start = 1'b1;
      ddrif.ref_done   = 1'b0;

      axi = new(ddrif.stq, ddrif.wdata_wrapper, ddrif.lq);

      // ── Reset ─────────────────────────────────────────────────────────────
      nRST = 1'b0;
      repeat (2) @(posedge CLK);
      nRST = 1'b1;

      task_name = "Power_up";
      #((tRESET + tPWUP + tRESETCKE + tPDc + tXPR + tDLLKc + tMOD * 7 + tZQinitc) );
      repeat (25) @(posedge CLK);

      // TC1: Basic single write → read-back (bank 0, row miss)
      directed_wr_rd(.bank_idx(4'd0), .row(15'h0001), .col(10'h008),
                     .wdata(64'hDEAD_BEEF_CAFE_BABE), .label("TC1"));

      repeat (50) @(posedge CLK);
      $display("[SIM] TC1 complete.");
      $finish;
    end
endmodule

/* NOT USED AT ALL

//Reference cache for verification
//Use to store 64byte of data in different rows
module sw_cache #( parameter ROW_BITS = 15)
(
    input logic CLKx2,
    input logic nRST,
    input logic wr_en,
    input logic rd_en,
    input logic [ROW_BITS-1:0] row_addr,
    input logic [2:0] offset,
    input logic [63:0] dmemstore,
    output logic [63:0] dmemload
);

    typedef struct packed {
        logic [7:0][63:0] arr;
    } data_8bytes;

    data_8bytes sw_cache [2**ROW_BITS-1:0];

    always_ff @(posedge CLKx2, negedge nRST) begin
        if(!nRST) begin
            for (int i = 0; i < ROW_BITS; i++) begin
                sw_cache[i] <= 0;
            end
        end else begin
            if (wr_en) begin
                sw_cache[row_addr].arr[offset] <= dmemstore;
            end
        end
    end

    always_comb begin
        dmemload = 0;
        if (rd_en) begin
            dmemload = sw_cache[row_addr].arr[offset];
        end
    end
endmodule
*/