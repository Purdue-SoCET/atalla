class vector_env extends uvm_env;

    `uvm_component_utils(vector_env)

    lane_agent lane_agt;
    vector_scoreboard scoreboard;

    function new(string name = "vector_env",
                 uvm_component parent = null);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);

        lane_agt = lane_agent::type_id::create("lane_agt", this);
        scoreboard = vector_scoreboard::type_id::create("scoreboard", this);
    endfunction

    function void connect_phase(uvm_phase phase);
        super.connect_phase(phase);
        lane_agt.monitor.ap.connect(scoreboard.result_imp);
    endfunction

endclass