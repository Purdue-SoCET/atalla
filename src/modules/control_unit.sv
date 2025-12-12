`include "dram_pkg.vh"
`include "address_mapper_if.vh"
`include "timing_signals_if.vh"
`include "command_fsm_if.vh"
`include "row_open_if.vh"
`include "init_state_if.vh"

module control_unit (
    input logic clk, nRST,
    address_mapper_if.addr_mapper amif_addr_mapper,
    address_mapper_if.row_open amif_row_open,
    init_state_if.init_fsm initif,
    row_open_if.row_open polif_row_open,
    row_open_if.cmd_fsm polif_cmd_fsm,
    command_fsm_if.cmd_fsm cfsmif_cmd_fsm,
    command_fsm_if.timing_ctrl cfsmif_timing_ctrl,
    timing_signals_if.row_open timif_row_open,
    timing_signals_if.cmd_fsm timif_cmd_fsm,
    timing_signals_if.timing_ctrl timif_timing_ctrl,
    timing_signals_if.data_transfer timif_data_trans,
    control_unit_if.arb cuif_arb,
    control_unit_if.sig_gen cuif_sig_gen,
    control_unit_if.data_trans cuif_data_trans
);
    init_state              init_state      (.CLK(clk), .nRST(nRST), .it(initif));
    addr_mapper             addr_mapper     (.amif(amif_addr_mapper));
    row_open #(.DEPTH(16))  row_open        (.CLK(clk), .nRST(nRST), .pol_if(polif_row_open), .amif(amif_row_open),
                                            .timif(timif_row_open));
    command_FSM             command_fsm     (.CLK(clk), .nRST(nRST), .mycmd(cfsmif_cmd_fsm), .polif(polif_cmd_fsm),
                                            .timif(timif_cmd_fsm));
    timing_control          timing_control  (.clk(clk), .nRST(nRST), .timif(timif_timing_ctrl), 
                                            .cfsmif(cfsmif_timing_ctrl));

    
    // Registering init_done signal because it takes 1 cycle to update states (go from INIT -> CMD_FSM)
    // after init_done goes high
    logic init_done;
    always_ff @(posedge clk, negedge nRST) begin : INIT_DONE_REG
        if (!nRST) begin
            init_done <= 1'b0;
        end
        else begin
            init_done <= initif.init_valid;
        end 
    end
    
    always_comb begin : SIGNAL_CONNECTIONS
        // Assign state signals
        cuif_sig_gen.state  = (init_done == 1'b0) ? initif.init_state   : cfsmif_cmd_fsm.cmd_state;
        cuif_sig_gen.nstate = (init_done == 1'b0) ? initif.n_init_state : cfsmif_cmd_fsm.ncmd_state;
        initif.init = cfsmif_cmd_fsm.init_req;
        
        // Assign address mapping signals
        cuif_sig_gen.rank = amif_addr_mapper.rank;
        cuif_sig_gen.BG = amif_addr_mapper.BG;
        cuif_sig_gen.bank = amif_addr_mapper.bank;
        cuif_sig_gen.row = amif_addr_mapper.row;
        cuif_sig_gen.col = amif_addr_mapper.col;
        cuif_arb.offset = amif_addr_mapper.offset;

        // Assign data transfer signals
        cuif_data_trans.wr_en = timif_data_trans.wr_en;
        cuif_data_trans.rd_en = timif_data_trans.rd_en;
        cuif_data_trans.clear = timif_data_trans.clear;

        // Assign cmd_fsm signals
        cfsmif_cmd_fsm.dREN = cuif_arb.dREN;
        cfsmif_cmd_fsm.dWEN = cuif_arb.dWEN;
        cuif_arb.ram_wait = cfsmif_cmd_fsm.ram_wait;
        cfsmif_cmd_fsm.init_done   = initif.init_valid;

        // Assign address mapper signals
        amif_addr_mapper.address = cuif_arb.address;

        // Assign row policy signals
        polif_row_open.row_resolve  = cfsmif_cmd_fsm.row_resolve;
        polif_row_open.req_en       = cuif_arb.dREN || cuif_arb.dWEN;  

        // Assign timing signals
        cuif_sig_gen.rf_req = timif_timing_ctrl.rf_req;     
    end
endmodule