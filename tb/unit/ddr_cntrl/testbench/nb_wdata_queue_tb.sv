`include "dram_pkg.sv"
`include "cpu_types_pkg.sv"
`include "ddr_controller_if.sv"


module nb_wdata_queue_tb;
    logic CLK, nRST;

    // clock
    always #(PERIOD/2) CLK++;
    
    ddr_controller_if ddrif;
    nb_barb DUT(CLK, nRST, ddrif);

    test PROG(CLK, nRST, ddrif);

    bind nb_wdata_queue nb_wdata_queue_prop barb_monitor(CLK, nRST, ddrif);

endmodule

program test(
    input logic CLK, nRST, 
    ddr_controller_if.wdata_queue wdq
);

    paremeter NUM_REQS = 1000;
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
        wdq_slot_t input;
    } awrite_slot_t; //Driver from AXI Write channel.

    typedef struct packed {
        logic [$clog2(ID_NUM)-1:0] be_wid;
        logic be_write;
    } barb_slot_t; //Driver from backend arbiter.

    typedef struct packed {
        integer delay;
    } bresp_t; //Driver from AXI bresp channel.

    typedef struct packed {
        logic [63:0] data_out;
        logic [7:0] mask_out; 
        logic wdata_en_out; //should be high for all 8 cycles. 
    } ouput_block_t; //This block will be constructed by the sequencer and then fed to 
                     // scoreboard for verification. 

    typedef struct packed {
        logic [63:0] data_out_correct;
        logic [7:0] mask_out_correct;
        logic wdata_en_correct; 
    } correct_output_t;

    awrite_slot_t [7:0][NUM_REQS-1:0] input_vector;
    barb_slot_t [NUM_REQS-1:0] barb_connect;
    bresp_t [NUM_REQS-1:0] input_bresp;
    output_block_t [7:0][NUM_REQS-1:0] output_vector;
    correct_output_t [7:0][NUM_REQS-1:0] correct_vector;

    logic [$clog2(ID_NUM)-1:0] random_id;
    logic [2:0] random_wlen;
    task sequencer; //Generates random testcases. Should hit multiple mask configs and all lengths, including (idk about zero)
    //No input logic needed. Just writes to test vectors. (Input and expected)
        begin 
            for(int i = 0; i < NUM_REQS; i++) begin
                random_id = $urandom_range(0, ID_NUM);
                random_wlen = $urandom_range(0, 8);
                for (int j = 0; j < 8; j++) begin
                    input_vector[j][i].input.wstrb = $urandom_range(0, 256);
                    input_vector[j][i].input.wdata, correct_vector[j][i].data_out_correct = $urandom();
                    correct_vector[j][i].wdata_en_correct = 1'b1;
                    input_vector[j][i].input.wid = random_id;
                    input_vector[j][i].input.wlen = random_wlen;
                    if(j > random_wlen) begin
                        correct_vector[j][i].mask_out_correct = 8'b1111_1111;
                    end else begin
                        correct_vector[j][i].mask_out_correct = input_vector[j][i].input.wstrb;
                    end
                    
                end

                barb_connect[i].wid = random_id;
                barb_connect[i].be_write = 1'b1;
                input_bresp[i].delay = $urandom_range(0, 16);
            end
        end

    endtask

    task driver_axi_write; //acts as axi write channel to drive writing inputs. 

    endtask

    task driver_barb; //acts as barb to command writes.

    endtask

    task driver_bresp; //acts as bresp channel. drives ready signal to accept responses.


    endtask 

    task monitor; //collects outputs and places them into test vector. 

    endtask

    task scoreboard; //compares outputs to expected inside giant test vector. reports results.  


    endtask 


    initial begin 
        nRST = 1;
        reset_dut();
        @(negedge CLK);

        $display ("Coverage = %0.2f %%", wdqcg.get_inst_coverage());


        $finish;
    end

endprogram