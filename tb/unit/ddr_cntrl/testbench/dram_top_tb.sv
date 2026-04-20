`include "dram_pkg.svh"
`include "arch_defines.v"
`include "ddr_controller_if.sv"
`include "arch_defines.v"
`include "dimm.vh"
`timescale 1 ns / 1 ps


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
    parameter PERIOD = 1.5;
    parameter tCK = 1.5;
    import dram_pkg::*; 
    import proj_package::*; // protected vcs

    //parameter from dram_command_if.vh
    parameter CONFIGURED_DQ_BITS     = 8;
    parameter CONFIGURED_DQS_BITS    = (16 == CONFIGURED_DQ_BITS) ? 2 : 1;
    parameter CONFIGURED_DM_BITS     = (16 == CONFIGURED_DQ_BITS) ? 2 : 1;
    parameter CONFIGURED_RANKS       = 1;
    
    //CLK and debug signals
    logic CLK = 1, nRST;
    logic CLKx2=0;
    reg model_enable_val;
    logic model_enable;
    string task_name;

    //Instantiate the the iDDR4_1 version
    reg clk_val, clk_enb;
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
        CLKx2 = 1'b1;
        #(PERIOD / 4.0);
        CLKx2 = 1'b0;
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

    ddr_controller_wrapper DUT (.CLK(CLK), .nRST(nRST), .top(ddrif));

    //No more Cache or Scheduler, but keep the prev_addr
    // TODO: Bank Group maybe? Check TCCD_L vs TCCD_S 

    //DRAM interface latch
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


        iDDR4_1.ACT_n     <= ddrif.ACT_n;
        iDDR4_1.RAS_n_A16 <= ddrif.RAS_n_A16;
        iDDR4_1.CAS_n_A15 <= ddrif.CAS_n_A15;
        iDDR4_1.WE_n_A14  <= ddrif.WE_n_A14;
        iDDR4_1.ALERT_n   <= ddrif.ALERT_n;
        iDDR4_1.PARITY    <= ddrif.PARITY;
        iDDR4_1.RESET_n   <= ddrif.RESET_n;
        iDDR4_1.TEN       <= ddrif.TEN;
        iDDR4_1.CS_n      <= ddrif.CS_n;
        iDDR4_1.CKE       <= ddrif.CKE;
        iDDR4_1.ODT       <= ddrif.ODT;
        iDDR4_1.C         <= ddrif.C;
        iDDR4_1.BG        <= ddrif.BG;
        iDDR4_1.BA        <= ddrif.BA;
        iDDR4_1.ADDR      <= ddrif.ADDR;
        iDDR4_1.ADDR_17   <= ddrif.ADDR_17;
        iDDR4_1.ZQ        <= ddrif.ZQ;
        iDDR4_1.PWR       <= ddrif.PWR;
        iDDR4_1.VREF_CA   <= ddrif.VREF_CA;
        iDDR4_1.VREF_DQ   <= ddrif.VREF_DQ;

        //DRAM 2
        iDDR4_2.ACT_n     <= ddrif.ACT_n;
        iDDR4_2.RAS_n_A16 <= ddrif.RAS_n_A16;
        iDDR4_2.CAS_n_A15 <= ddrif.CAS_n_A15;
        iDDR4_2.WE_n_A14  <= ddrif.WE_n_A14;
        iDDR4_2.ALERT_n   <= ddrif.ALERT_n;
        iDDR4_2.PARITY    <= ddrif.PARITY;
        iDDR4_2.RESET_n   <= ddrif.RESET_n;
        iDDR4_2.TEN       <= ddrif.TEN;
        iDDR4_2.CS_n      <= ddrif.CS_n;
        iDDR4_2.CKE       <= ddrif.CKE;
        iDDR4_2.ODT       <= ddrif.ODT;
        iDDR4_2.C         <= ddrif.C;
        iDDR4_2.BG        <= ddrif.BG;
        iDDR4_2.BA        <= ddrif.BA;
        iDDR4_2.ADDR      <= ddrif.ADDR;
        iDDR4_2.ADDR_17   <= ddrif.ADDR_17;
        iDDR4_2.ZQ        <= ddrif.ZQ;
        iDDR4_2.PWR       <= ddrif.PWR;
        iDDR4_2.VREF_CA   <= ddrif.VREF_CA;
        iDDR4_2.VREF_DQ   <= ddrif.VREF_DQ;

        //DRAM 3
        iDDR4_3.ACT_n     <= ddrif.ACT_n;
        iDDR4_3.RAS_n_A16 <= ddrif.RAS_n_A16;
        iDDR4_3.CAS_n_A15 <= ddrif.CAS_n_A15;
        iDDR4_3.WE_n_A14  <= ddrif.WE_n_A14;
        iDDR4_3.ALERT_n   <= ddrif.ALERT_n;
        iDDR4_3.PARITY    <= ddrif.PARITY;
        iDDR4_3.RESET_n   <= ddrif.RESET_n;
        iDDR4_3.TEN       <= ddrif.TEN;
        iDDR4_3.CS_n      <= ddrif.CS_n;
        iDDR4_3.CKE       <= ddrif.CKE;
        iDDR4_3.ODT       <= ddrif.ODT;
        iDDR4_3.C         <= ddrif.C;
        iDDR4_3.BG        <= ddrif.BG;
        iDDR4_3.BA        <= ddrif.BA;
        iDDR4_3.ADDR      <= ddrif.ADDR;
        iDDR4_3.ADDR_17   <= ddrif.ADDR_17;
        iDDR4_3.ZQ        <= ddrif.ZQ;
        iDDR4_3.PWR       <= ddrif.PWR;
        iDDR4_3.VREF_CA   <= ddrif.VREF_CA;
        iDDR4_3.VREF_DQ   <= ddrif.VREF_DQ;

        //DRAM 4
        iDDR4_4.ACT_n     <= ddrif.ACT_n;
        iDDR4_4.RAS_n_A16 <= ddrif.RAS_n_A16;
        iDDR4_4.CAS_n_A15 <= ddrif.CAS_n_A15;
        iDDR4_4.WE_n_A14  <= ddrif.WE_n_A14;
        iDDR4_4.ALERT_n   <= ddrif.ALERT_n;
        iDDR4_4.PARITY    <= ddrif.PARITY;
        iDDR4_4.RESET_n   <= ddrif.RESET_n;
        iDDR4_4.TEN       <= ddrif.TEN;
        iDDR4_4.CS_n      <= ddrif.CS_n;
        iDDR4_4.CKE       <= ddrif.CKE;
        iDDR4_4.ODT       <= ddrif.ODT;
        iDDR4_4.C         <= ddrif.C;
        iDDR4_4.BG        <= ddrif.BG;
        iDDR4_4.BA        <= ddrif.BA;
        iDDR4_4.ADDR      <= ddrif.ADDR;
        iDDR4_4.ADDR_17   <= ddrif.ADDR_17;
        iDDR4_4.ZQ        <= ddrif.ZQ;
        iDDR4_4.PWR       <= ddrif.PWR;
        iDDR4_4.VREF_CA   <= ddrif.VREF_CA;
        iDDR4_4.VREF_DQ   <= ddrif.VREF_DQ;

        //DRAM 5
        iDDR4_5.ACT_n     <= ddrif.ACT_n;
        iDDR4_5.RAS_n_A16 <= ddrif.RAS_n_A16;
        iDDR4_5.CAS_n_A15 <= ddrif.CAS_n_A15;
        iDDR4_5.WE_n_A14  <= ddrif.WE_n_A14;
        iDDR4_5.ALERT_n   <= ddrif.ALERT_n;
        iDDR4_5.PARITY    <= ddrif.PARITY;
        iDDR4_5.RESET_n   <= ddrif.RESET_n;
        iDDR4_5.TEN       <= ddrif.TEN;
        iDDR4_5.CS_n      <= ddrif.CS_n;
        iDDR4_5.CKE       <= ddrif.CKE;
        iDDR4_5.ODT       <= ddrif.ODT;
        iDDR4_5.C         <= ddrif.C;
        iDDR4_5.BG        <= ddrif.BG;
        iDDR4_5.BA        <= ddrif.BA;
        iDDR4_5.ADDR      <= ddrif.ADDR;
        iDDR4_5.ADDR_17   <= ddrif.ADDR_17;
        iDDR4_5.ZQ        <= ddrif.ZQ;
        iDDR4_5.PWR       <= ddrif.PWR;
        iDDR4_5.VREF_CA   <= ddrif.VREF_CA;
        iDDR4_5.VREF_DQ   <= ddrif.VREF_DQ;

        //DRAM 6
        iDDR4_6.ACT_n     <= ddrif.ACT_n;
        iDDR4_6.RAS_n_A16 <= ddrif.RAS_n_A16;
        iDDR4_6.CAS_n_A15 <= ddrif.CAS_n_A15;
        iDDR4_6.WE_n_A14  <= ddrif.WE_n_A14;
        iDDR4_6.ALERT_n   <= ddrif.ALERT_n;
        iDDR4_6.PARITY    <= ddrif.PARITY;
        iDDR4_6.RESET_n   <= ddrif.RESET_n;
        iDDR4_6.TEN       <= ddrif.TEN;
        iDDR4_6.CS_n      <= ddrif.CS_n;
        iDDR4_6.CKE       <= ddrif.CKE;
        iDDR4_6.ODT       <= ddrif.ODT;
        iDDR4_6.C         <= ddrif.C;
        iDDR4_6.BG        <= ddrif.BG;
        iDDR4_6.BA        <= ddrif.BA;
        iDDR4_6.ADDR      <= ddrif.ADDR;
        iDDR4_6.ADDR_17   <= ddrif.ADDR_17;
        iDDR4_6.ZQ        <= ddrif.ZQ;
        iDDR4_6.PWR       <= ddrif.PWR;
        iDDR4_6.VREF_CA   <= ddrif.VREF_CA;
        iDDR4_6.VREF_DQ   <= ddrif.VREF_DQ;

        //DRAM 7
        iDDR4_7.ACT_n     <= ddrif.ACT_n;
        iDDR4_7.RAS_n_A16 <= ddrif.RAS_n_A16;
        iDDR4_7.CAS_n_A15 <= ddrif.CAS_n_A15;
        iDDR4_7.WE_n_A14  <= ddrif.WE_n_A14;
        iDDR4_7.ALERT_n   <= ddrif.ALERT_n;
        iDDR4_7.PARITY    <= ddrif.PARITY;
        iDDR4_7.RESET_n   <= ddrif.RESET_n;
        iDDR4_7.TEN       <= ddrif.TEN;
        iDDR4_7.CS_n      <= ddrif.CS_n;
        iDDR4_7.CKE       <= ddrif.CKE;
        iDDR4_7.ODT       <= ddrif.ODT;
        iDDR4_7.C         <= ddrif.C;
        iDDR4_7.BG        <= ddrif.BG;
        iDDR4_7.BA        <= ddrif.BA;
        iDDR4_7.ADDR      <= ddrif.ADDR;
        iDDR4_7.ADDR_17   <= ddrif.ADDR_17;
        iDDR4_7.ZQ        <= ddrif.ZQ;
        iDDR4_7.PWR       <= ddrif.PWR;
        iDDR4_7.VREF_CA   <= ddrif.VREF_CA;
        iDDR4_7.VREF_DQ   <= ddrif.VREF_DQ;

        //DRAM 8
        iDDR4_8.ACT_n     <= ddrif.ACT_n;
        iDDR4_8.RAS_n_A16 <= ddrif.RAS_n_A16;
        iDDR4_8.CAS_n_A15 <= ddrif.CAS_n_A15;
        iDDR4_8.WE_n_A14  <= ddrif.WE_n_A14;
        iDDR4_8.ALERT_n   <= ddrif.ALERT_n;
        iDDR4_8.PARITY    <= ddrif.PARITY;
        iDDR4_8.RESET_n   <= ddrif.RESET_n;
        iDDR4_8.TEN       <= ddrif.TEN;
        iDDR4_8.CS_n      <= ddrif.CS_n;
        iDDR4_8.CKE       <= ddrif.CKE;
        iDDR4_8.ODT       <= ddrif.ODT;
        iDDR4_8.C         <= ddrif.C;
        iDDR4_8.BG        <= ddrif.BG;
        iDDR4_8.BA        <= ddrif.BA;
        iDDR4_8.ADDR      <= ddrif.ADDR;
        iDDR4_8.ADDR_17   <= ddrif.ADDR_17;
        iDDR4_8.ZQ        <= ddrif.ZQ;
        iDDR4_8.PWR       <= ddrif.PWR;
        iDDR4_8.VREF_CA   <= ddrif.VREF_CA;
        iDDR4_8.VREF_DQ   <= ddrif.VREF_DQ;
    end

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
        ddrif.DM_n,
        ddrif.DM_n,
        ddrif.DM_n,
        ddrif.DM_n,
        ddrif.DM_n,
        ddrif.DM_n,
        ddrif.DM_n,
        ddrif.DM_n
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

    //Assign these DQ signals back with data transfer (bidirectional) //TODO: Is this necessary? 
    assign ddrif.data_trans.DQS_t = ~dq_en ? iDDR4_1.DQS_t : 1'bz;
    assign ddrif.data_trans.DQS_c = ~dq_en ? iDDR4_1.DQS_c: 1'bz;
    assign ddrif.data_trans.DM_n = ~dq_en ? iDDR4_1.DM_n: 1'bz;
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
                // WDQ
                this.wvif.wdq_slot = {this.wstrb, this.wdata, this.wid, this.wlen};
                this.wvif.bwready  = this.bwready; // TODO: How is this signal determined? 
                this.wvif.wvalid   = this.valid;
                this.wvif.wlast    = this.wlast; // TODO: How is this signal determined?
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
      iDDR4_1.CK = 2'b01;
      clk_enb = 1'b1;
      clk_val = 1'b1;  
      model_enable_val = 1;
      dq_en = 1'b1;
      
      
      axi = new(ddrif.stq, ddrif.wdata_wrapper, ddrif.lq);
      nRST = 1'b0;
      @(posedge CLK);
      @(posedge CLK);
      nRST = 1'b1;

      
      task_name = "Power_up";
      #((tRESET + tPWUP + tRESETCKE + tPDc + tXPR + tDLLKc + tMOD * 7 + tZQinitc) * PERIOD);
      repeat (25) @(posedge CLK);

    
      task_name = "Writing_Cycle Case 1";
      void'(axi.randomize());
      axi.gen_addr("row miss");
      axi.gen_valid(1'b1);
      axi.gen_write(1'b1, 1'b0); // ready, last
      @(posedge CLK);
      axi.writing();
      repeat (50) @(posedge CLK);

    /*
    task_name = "Reading_Cycle";
    dq_en = 1'b0;
    read_with_verify(sch.creating_addr, sch);
    
    
    //checking the write - write - read row hit
    task_name = "write - write - read - row hit";
    dq_en = 1'b1;
    writing_1(prev_addr, dt_class);
    while (ddrif.ctrl.ram_wait) begin
        @(posedge CLK);
    end
    repeat(10) @(posedge CLK);
    read_with_verify(prev_addr, sch);
    

    //Case wait for refreshing refresh everything
    task_name = "refresh 150 cycles";
    repeat(150) @(posedge CLK);
    //PASS CHECKPOINT

    // For the purpose of checking the refresh command
    // We will load the same address and observe
    // 1. Command FSM IDLE -> ACT -> READ
    // 2. Row policy is updated
    read_with_verify(prev_addr, sch);

    //Test case: Testing row miss case with 3 consecutive writes of random address
    task_name = "3 consectutive writing";
    dq_en = 1'b1;
    //1 consectutive
    sch.randomize();
    sch.gen_addr("row miss", prev_addr);
    writing_1(sch.creating_addr, dt_class);
    while (ddrif.ctrl.ram_wait) begin
        @(posedge CLK);
    end
    repeat(10) @(posedge CLK);

    //2 consectutive
    sch.randomize();
    sch.gen_addr("row miss", prev_addr);
    writing_1(sch.creating_addr, dt_class);
    while (ddrif.ctrl.ram_wait) begin
        @(posedge CLK);
    end
    repeat(10) @(posedge CLK);

    //3 consectutive
    task_name = "The last consecutive write of the testcase";
    sch.randomize();
    sch.gen_addr("row miss", prev_addr);
    writing_1(sch.creating_addr, dt_class);
    while (ddrif.ctrl.ram_wait) begin
        @(posedge CLK);
    end
    repeat(10) @(posedge CLK);


    //After that we use the last consecutive write to test the conflict case
    task_name = "Test row conflict write row hit read";
    don_t_write = 1'b1;
    sch.gen_addr("row conflict", prev_addr);
    writing_1(sch.creating_addr, dt_class);
    while(ddrif.ctrl.ram_wait) begin
        @(posedge CLK);
    end
    repeat(10) @(posedge CLK);

    //This task is special because after 3 consecutive writes, and while reading, we jump into refresh request
    task_name = "Test row conflcit read (the old address that cause write)";
    read_with_verify(prev_addr, sch);
    repeat(200) @(posedge CLK);

    //Task 16_consecutive writes
    task_name = "16 write-dif bank";
    consecutive_16_write();

    //Task random
    random_req();

    //CHECKPOINT: DONE ALL PREVIOUS CASES
    //TODO may be: the writing burst mask cases doesn't have general test cases */
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