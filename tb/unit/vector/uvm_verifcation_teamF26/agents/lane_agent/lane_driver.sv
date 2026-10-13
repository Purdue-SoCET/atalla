//get transaction from sequencer to drive dut
class lane_driver extends uvm_driver #(lane_item);
    `uvm_component_utils(lane_driver)

    virtual vector_tb_if vif; // Handle to the testbench interface

    function new(string name = "lane_driver", 
                uvm_component parent = null);
        super.new(name, parent);
    endfunction

    // Build phase
    function void build_phase(uvm_phase phase);
        super.build_phase(phase);

        // Retrieve virtual interface through uvm_config_db
        if (!uvm_config_db#(virtual vector_tb_if)::get(this, "", "vif", vif)) begin
            `uvm_fatal("NO_VIF", "Could not retrieve vector_tb_if")
        end

    endfunction

    task drive_item(lane_item item);
        @(negedge vif.CLK);

        // Populate issue port 0
        vif.lanes_in.lane_issue_ports[0].v1 = item.v1;
        vif.lanes_in.lane_issue_ports[0].v2 = item.v2;
        vif.lanes_in.lane_issue_ports[0].usel = item.usel;
        vif.lanes_in.lane_issue_ports[0].vd = item.vd;
        vif.lanes_in.lane_issue_ports[0].rm = item.rm;
        vif.lanes_in.lane_issue_ports[0].mask = item.mask;
        vif.lanes_in.lane_issue_ports[0].alu_op = item.alu_op;

        vif.lanes_in.lane_issue_ports[0].input_valid = 1'b1; // Assert valid after preparing inputs

        // Wait for accepted transaction
        do begin
            @(posedge vif.CLK);
        end while (vif.alu_ready !== 1'b1);

        `uvm_info("LANE_DRIVER", $sformatf("Transaction accepted: op=%0d, vd=%0d", item.alu_op, item.vd), UVM_MEDIUM)

        // Deassert valid away from sampling edge
        @(negedge vif.CLK);
        vif.lanes_in.lane_issue_ports[0].input_valid = 1'b0;
    endtask

    task run_phase(uvm_phase phase);
        lane_item req;
        vif.lanes_in = '0;
        wait (vif.nRST === 1'b1); // Wait for reset to be released

        forever begin
            //get the next trasaction from the sequencer
            seq_item_port.get_next_item(req);
            
            //drive here
            drive_item(req);

            //tell sequencer that this transaction is finished
            seq_item_port.item_done();
        end
    endtask

endclass