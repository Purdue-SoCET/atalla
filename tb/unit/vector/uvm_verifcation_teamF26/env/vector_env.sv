class vector_env extends uvm_env;

    `uvm_component_utils(vector_env)

    lane_agent lane_agt;

    function new(string name = "vector_env",
                 uvm_component parent = null);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);

        lane_agt = lane_agent::type_id::create(
            "lane_agt", this
        );
    endfunction

endclass