/*
tb_result_collector.sv
Non exaustive verification of the result collector
This will not have toggle or branch coverage cause i dont have time
Owner: Jacob Walter

Make command for my testbench:
make test tb_file=result_collector_tb.sv packages=/vector/vector_pkg.vh modules=/vector/result_collector.sv GUI=ON

Test Cases:
1. Power on reset
2. Vector Collection Test
3. Handshake Validation
4. Backpressure

*/
`timescale 1ns/1ps

`include "result_collector_if.vh"
`include "vector_pkg.vh"

module result_collector_tb;
    import vector_pkg::*;

    //Clock setup
    logic CLK;
    logic nRST;

    initial CLK = 1'b0;
    always #5 CLK = ~CLK;   // 100 MHz

    //DUT instanciation
    result_collector_if rcif();
    result_collector DUT (
        .CLK(CLK),
        .nRST(nRST),
        .rcif(rcif)
    );


    //testcase tasks

    task automatic power_on_reset();
        @(posedge CLK);
        nRST = 'b0;
        rcif.in.input_valid = 'b0;
        rcif.in.wb_ready = 'b1;
        rcif.in.lane_input = 'b0;
        rcif.in.vd_input = 'b0;
        @(posedge CLK);
        nRST = 'b1;    
    endtask

    task automatic vector_collection();
        logic [NUM_LANES-1:0][15:0] input_vector_1;
        logic [NUM_LANES-1:0][15:0] input_vector_2;
        int i;
        for (i = 0; i < NUM_LANES; i++) begin
            input_vector_1[i] = i + 1;
        end
        for (i = 0; i < NUM_LANES; i++) begin
            input_vector_2[i] = NUM_LANES + i + 1;
        end
        rcif.in.wb_ready = 'b1;
        @(posedge CLK);
        //drive first half of data into the RC
        rcif.in.lane_input = input_vector_1;
        rcif.in.input_valid = 'b1;
        rcif.in.vd_input = 'd1;
        @(posedge CLK);
        //drive the second half, test to ensure that VD does not change if it changes
        rcif.in.lane_input = input_vector_2;
        rcif.in.input_valid = 'b1;
        rcif.in.vd_input = 'd2;
        //at this point valid should be asserted and the data should be done
    endtask //automatic

    task automatic reset_on_new_vector();
        logic [NUM_LANES-1:0][15:0] input_vector_1;
        logic [NUM_LANES-1:0][15:0] input_vector_2;
        int i;
        for (i = 0; i < NUM_LANES; i++) begin
            input_vector_1[i] = (i + 1) * 10;
        end
        for (i = 0; i < NUM_LANES; i++) begin
            input_vector_2[i] = (NUM_LANES + i + 1) * 10;
        end
        rcif.in.wb_ready = 'b1;
        @(posedge CLK);
        //drive first half of data into the RC
        rcif.in.lane_input = input_vector_1;
        rcif.in.input_valid = 'b1;
        rcif.in.vd_input = 'd3;
        @(posedge CLK);
        //drive the second half, test to ensure that VD does not change if it changes
        rcif.in.lane_input = input_vector_2;
        rcif.in.input_valid = 'b1;
        rcif.in.vd_input = 'd2;
        //at this point valid should be asserted and the data should be done
    endtask //automatic


    task automatic backpressure();
        logic [NUM_LANES-1:0][15:0] input_vector_1;
        logic [NUM_LANES-1:0][15:0] input_vector_2;
        int i;
        for (i = 0; i < NUM_LANES; i++) begin
            input_vector_1[i] = i + 1;
        end
        for (i = 0; i < NUM_LANES; i++) begin
            input_vector_2[i] = NUM_LANES + i + 1;
        end
        rcif.in.wb_ready = 'b0;
        @(posedge CLK);
        //drive first half of data into the RC
        rcif.in.lane_input = input_vector_1;
        rcif.in.input_valid = 'b1;
        rcif.in.vd_input = 'd1;
        @(posedge CLK);
        rcif.in.lane_input = input_vector_2;
        rcif.in.input_valid = 'b1;
        rcif.in.vd_input = 'd2;
        @(posedge CLK); //extra cycles to ensure that the data is held until a ready signal is recived
        @(posedge CLK);
        @(posedge CLK);
        rcif.in.wb_ready = 'b1;
        @(posedge CLK);
    endtask //automatic

    initial begin
        nRST = 'b1;
        power_on_reset();

        @(posedge CLK);
        
        //testing to make sure it can handle back to back inputs and inputs in general
        vector_collection();
        reset_on_new_vector();
        @(posedge CLK);
        @(posedge CLK);
        rcif.in.input_valid = 'b0;

        power_on_reset();
        @(posedge CLK);
        backpressure();
        @(posedge CLK);



        $stop;
    end
    

endmodule
