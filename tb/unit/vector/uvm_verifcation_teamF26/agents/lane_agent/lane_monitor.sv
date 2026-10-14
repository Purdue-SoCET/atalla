class lane_monitor extends uvm_monitor;

    `uvm_component_utils(lane_monitor)

    virtual vector_tb_if vif; // Virtual interface to observe the DUT
    uvm_analysis_port #(lane_result_item) ap; // Analysis port to send results to the scoreboard

    // Constructor
    function new(string name = "lane_monitor", uvm_component parent = null);
        super.new(name, parent);
    endfunction

    // Build phase
    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        ap = new("ap", this);
        if (!uvm_config_db#(virtual vector_tb_if)::get(this, "", "vif", vif)) begin
            `uvm_fatal("NO_VIF", "Could not retrieve vector_tb_if")
        end
    endfunction

    // Run phase
    task run_phase(uvm_phase phase);
        lane_result_item result_item;

        // Wait until reset is released
        wait (vif.nRST === 1'b1);

        forever begin
            @(negedge vif.CLK);
            // Check if ALU result collector has valid output
            if (vif.lanes_out.result_collectors[0].wb_valid === 1'b1) begin

                // Create a result transaction
                result_item = lane_result_item::type_id::create("result_item");

                // Capture actual DUT output
                result_item.result = vif.lanes_out.result_collectors[0].vector_output;

                // Capture destination register
                result_item.vd = vif.lanes_out.result_collectors[0].vd_output;

                `uvm_info("LANE_MONITOR", $sformatf("Captured ALU result, vd=%0d", result_item.vd), UVM_MEDIUM)

                // Send result to scoreboard
                ap.write(result_item);

            end
        end
    endtask

endclass
