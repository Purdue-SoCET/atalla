class lane_add_sequence extends lane_base_sequence;
        uvm_object_utils(lane_add_sequence)

        function new(string name = "lane_add_sequence");
            super.new(name);
        endfunction

        task body();
            lane_item req;
            
            //create one transaction through the uvm factory
            req = lane_item::type_id::create("req");

            //ask the sequencer for permission to send this item
            start_item(req);

            //configure the operation
            req.usel = VALU; //use alu
            req.alu_op = ALU_ADD;
            req.vd = 8'd3;
            req.rm = 1'b0;
            req.mask = '1;

            //set vector operands
            for (int i = 0; i < VLMAX; i++) begin
                req.v1[i] = 16'h3F80; //BF16 1.0
                req.v2[i] = 16'h4000; //BF16 2.0
            end

            //send the completed transaction to the sequencer
            finish_item(req);
            
        endtask
endclass