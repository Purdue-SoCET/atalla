interface vector_tb_if;
    import vector_pkg::*;

    logic CLK;
    logic nRST;
    vector_if_lanes_in_t lanes_in; // Driver-controlled lane issue ports
    logic alu_ready; // DUT readiness
    vector_if_lanes_out_t lanes_out; // DUT results for future lane monitor

endinterface