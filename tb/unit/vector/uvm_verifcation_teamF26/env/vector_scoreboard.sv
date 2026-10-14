class vector_scoreboard extends uvm_scoreboard;

    `uvm_component_utils(vector_scoreboard)

    uvm_analysis_imp #(lane_result_item, vector_scoreboard)
        result_imp;

    int pass_count = 0;
    int fail_count = 0;
    bit check_done = 0;

    function new(string name = "vector_scoreboard", uvm_component parent = null);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        result_imp = new("result_imp", this);
    endfunction

    // Called when the monitor publishes a result
    function void write(lane_result_item item);
        bit passed = 1;
        for (int i = 0; i < vector_pkg::VLMAX; i++) begin
            if (item.result[i] !== 16'h4040) begin
                passed = 0;
                `uvm_error("VECTOR_SB", $sformatf( "Element %0d mismatch: expected=4040 actual=%04h", i, item.result[i]))
            end
        end

        if (item.vd !== 8'd3) begin
            passed = 0;
            `uvm_error("VECTOR_SB", $sformatf("VD mismatch: expected=3 actual=%0d", item.vd))
        end
        if (passed) begin
            pass_count++;
            `uvm_info("VECTOR_SB", "Vector ADD PASSED: all 32 elements match", UVM_LOW)
        end

        else begin
            fail_count++;
        end

        check_done = 1;

    endfunction

endclass
