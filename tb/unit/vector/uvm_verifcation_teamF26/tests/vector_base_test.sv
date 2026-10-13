class vector_base_test extends uvm_test;
    `uvm_component_utils(vector_base_test)
    vector_env env;

    function new(string name = "vector_base_test",
                 uvm_component parent = null);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        env = vector_env::type_id::create("env", this);
    endfunction

endclass
