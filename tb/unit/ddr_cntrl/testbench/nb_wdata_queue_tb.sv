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
    typedef struct packed {
        wdq_slot_t input;

    } awrite_slot_t; //Driver from AXI Write channel.

    typedef struct packed {
        logic [$clog2(ID_NUM)-1:0] be_wid;
        logic be_write;
    } barb_slot_t; //Driver from backend arbiter.

    typedef struct packed {
        logic bwready;
        integer delay;
    } bresp_t; //Driver from AXI bresp channel.

    typdef struct packed {

        logic bwready
    } 

    initial begin 
        nRST = 1;
        reset_dut();
        @(negedge CLK);

        $display ("Coverage = %0.2f %%", wdqcg.get_inst_coverage());


        $finish;
    end

endprogram