`include "dram_pkg.svh"
`include "ddr_controller_if.sv"


module nb_wdata_queue_tb; 
    import dram_pkg::*;
    logic CLK, nRST;
    parameter PERIOD = 5ns;

    // clock
    always #(PERIOD/2) CLK++;
    
    ddr_controller_if ddrif0();
    // ddr_controller_if ddrif1;
    nb_wdata_queue_wrapper DUT(CLK, nRST, ddrif0.wdata_wrapper, ddrif0.wdata_queue);

    test PROG(CLK, nRST, ddrif0.wdata_queue, ddrif0.wdata_wrapper);

    bind nb_wdata_queue nb_wdata_queue_prop wdata_queue_monitor(CLK, nRST, ddrif0.wdata_queue, ddrif0.wdata_wrapper);

endmodule

program test(
    input logic CLK, 
    output logic nRST, 
    ddr_controller_if.wdata_queue wdq,
    ddr_controller_if.wdata_wrapper wdw
);
    import dram_pkg::*;
    localparam NUM_REQS = 1000;
    task reset_dut();
        begin
            nRST = 0;
            repeat (5) @(negedge CLK);
            nRST = 1;
        end
    endtask
/*
    typedef struct packed {
        wdq_slot_t input;
        logic [7:0] input_wstrb;
        logic [63:0] wdata_expected;
        logic [7:0] mask_expected;
        integer delay; //delay between setting data and then valid. 
    } wdq_case_in_t;

    typedef struct packed {
        
        bwvalid 
        integer delay; //delay for setting bwready signal.
    }
*/

    ///What to check manually
    /// 1. Check that correct data is outputted. 
    /// 2. Check that ddr_wdata_mask properly masks bits. 
    ///     1. In the case of strobing.
    ///     2. In the case of variable length bursts. 
    typedef struct packed {
        wdq_slot_t input_slot;
        integer delay; //delay when retiring request from wdq. (Delay between driver task call and bwready set high.)
    } awrite_slot_t; //Driver from AXI Write channel.


    typedef struct packed {
        logic [63:0] data_out;
        logic [7:0] mask_out; 
        logic wdata_en_out; //should be high for all 8 cycles. 
    } monitor_block_t; //This block will be constructed by the sequencer and then fed to  scoreboard for verification. 

    typedef struct packed {
        logic [63:0] data_out_correct;
        logic [7:0] mask_out_correct;
        logic wdata_en_correct; 
    } correct_output_t;

    awrite_slot_t [7:0][NUM_REQS-1:0] input_vector; 
    correct_output_t [7:0][NUM_REQS-1:0] correct_vector;
    monitor_block_t [7:0][NUM_REQS-1:0] output_vector;

    logic [$clog2(ID_NUM)-1:0] random_id;
    logic [2:0] random_wlen;
    integer random_delay; 
    task sequencer; //Generates random testcases. Should hit multiple mask configs and all lengths, including (idk about zero)
    //No input logic needed. Just writes to test vectors. (Input and expected)
        begin 
            for(int i = 0; i < NUM_REQS; i++) begin
                random_id = $urandom_range(0, ID_NUM);
                random_wlen = $urandom_range(0, 8);
                random_delay = $urandom_range(0,16);

                for (int j = 0; j < 8; j++) begin
                    input_vector[j][i].input_slot.wstrb = $urandom_range(0, 256);
                    input_vector[j][i].input_slot.wdata = {$urandom(), $urandom()};
		    correct_vector[j][i].data_out_correct = input_vector[j][i].input_slot.wdata;
                    correct_vector[j][i].wdata_en_correct = 1'b1;
                    input_vector[j][i].input_slot.wid = random_id;
                    input_vector[j][i].input_slot.wlen = random_wlen;
                    input_vector[j][i].delay = random_delay;
                    if(j > random_wlen) begin
                        correct_vector[j][i].mask_out_correct = 8'b1111_1111;
                    end else begin
                        correct_vector[j][i].mask_out_correct = input_vector[j][i].input_slot.wstrb;
                    end
                    
                end
            end
        end

    endtask

    task driver_axi_write; //acts as axi write channel to drive writing inputs. 

        input case_num; 
        begin
            @(posedge CLK);
            wdq.wdq_slot.wid = input_vector[0][case_num].input_slot.wid;
            wdq.wdq_slot.wlen = input_vector[0][case_num].input_slot.wlen;
            @(posedge CLK);
            for(int i = 0; i < 8 ; i++) begin
                wdq.wvalid = 1'b1;
                wdq.wdq_slot.wdata = input_vector[i][case_num].input_slot.wdata;
                wdq.wdq_slot.wstrb = input_vector[i][case_num].input_slot.wstrb; 

                wdq.wlast = (i == input_vector[0][case_num].input_slot.wlen);
                if(i == input_vector[0][case_num].input_slot.wlen) begin
                    break; 
                end
                @(posedge CLK);
            end 
            wdq.wvalid = 1'b0;
            @(posedge CLK);
        end

    endtask

    task driver_barb; //acts as barb to command writes.
        input case_num;
        begin 
            @(posedge CLK);
            wdq.be_wid = input_vector[0][case_num].input_slot.wid;
            wdq.be_write = 1'b1;
            @(posedge CLK);
            wdq.be_wid = 1'b0;
            wdq.be_write = 1'b0;
        end
    endtask
   int n ;
    task driver_bresp; //acts as bresp channel. drives ready signal to accept responses.
        input case_num;
        begin 
            @(posedge CLK);
            for(int i = 0; i < input_vector[0][case_num].delay; i++) begin
                @(posedge CLK);
            end
            wdq.bwready = 1'b1;
            n = 0;
            while(!wdw.wrap_bwvalid) begin
                @(posedge CLK);
                if(n > 1000) begin
                    $display("driver_bresp timed out on test %d", case_num);
                    break;
                end
                n++;
                #(1ns);
            end
            @(posedge CLK);
            wdq.bwready = 1'b0;
        end
    endtask 

 
    task monitor; //collects outputs and places them into test vector. 
        input case_num;
        begin
            n = 0;
            while(!wdw.wrap_ddr_we) begin
                @(posedge CLK);
                if (n > 1000) begin
                    $display("monitor timed out on test %d", case_num);
                    break;
                end
                n++;
                #(1ns);
            end
            #(PERIOD/5);
            for(int i = 0; i < 8; i++) begin

                output_vector[i][case_num].data_out = wdw.wrap_ddr_wdata_data;
                output_vector[i][case_num].mask_out = wdw.wrap_ddr_wdata_mask;
                if(!wdw.wrap_ddr_wdata_en) begin
                    $display("case number %d failed. ddr_wdata_en not high when it should be.", case_num);
                end

            end
        end
    endtask

    int num_tests = 0;
    int num_passed = 0;
    task scoreboard; //compares outputs to expected inside giant test vector. reports results.  
        begin
            for(int i = 0; i < NUM_REQS; i++) begin
                for(int j = 0; j < 8; j++) begin
                    num_tests = num_tests + 2;
                    if(output_vector[j][i].data_out == correct_vector[j][i].data_out_correct) begin
                        $display("Test %d data passed.", i);
                        num_passed++;
                    end else begin
                        $display("Test %d data failed", i);
                    end

                    if(output_vector[j][i].mask_out == correct_vector[j][i].mask_out_correct) begin
                        $display("Test %d mask passed.", i); 
                        num_passed++;
                    end else begin
                        $display("Test %d mask failed.", i);
                    end
                end
            end
            $display("%d tests passed out of %d", num_passed, num_tests);
        end

    endtask 


    initial begin 
        nRST = 1;
        wdq.wdq_slot.wdata = 'b0;
        wdq.wdq_slot.wstrb = 'b0;
        wdq.wdq_slot.wid = 'b0;
        wdq.wdq_slot.wlen = 'b0;
        wdq.bwredy = 'b0;
        wdq.wvalid = 'b0;
        wdq.wlast = 'b0;
        wdq.be_wid = 'b0;
        wdq.be_write = 'b0;
        @(posedge CLK);
        reset_dut();
        @(posedge CLK);

        sequencer();

        for(int i = 0; i < NUM_REQS; i++) begin

            driver_axi_write(i);
            repeat(500) @(posedge CLK);
            driver_barb(i);
            @(posedge CLK);
            @(posedge CLK);
            monitor(i);
            @(posedge CLK);
            driver_bresp(i);
            @(posedge CLK);
            

        end

        scoreboard();

        //$display ("Coverage = %0.2f %%", wdqcg.get_inst_coverage());


        $finish;
    end

endprogram
