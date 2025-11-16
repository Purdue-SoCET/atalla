`timescale 1ps/1ps

`include "scpad_if.sv"
import scpad_pkg::*;

// // Scheduler <=> Backend
//     modport backend_sched (
//         input clk, n_rst, sched_req,
//         output sched_res
//     );

//     // Backend <=> Body
//     modport backend_body (
//         input clk, n_rst, 
//         input  be_stall, be_res, 
//         output be_req
//     );

//     // Backend <=> DRAM
//     modport backend_dram (
//         input clk, n_rst, 
//         output be_dram_req, be_dram_stall,
//         input dram_be_res
//     );

module backend_tb;

    localparam CLK_PERIOD = 10; 
    
    logic  clk = 0;
    logic  n_rst;

    always #(CLK_PERIOD/2) clk = ~clk;

    scpad_if bif(clk, n_rst);

    // module backend #(parameter logic [SCPAD_ID_WIDTH-1:0] IDX = '0) (
    // scpad_if.backend_sched bshif, 
    // scpad_if.backend_body bscif, 
    // scpad_if.backend_dram bdrif
    // );
    
    backend #(.IDX(0)) DUT (
    .bshif(bif),   // scpad_if.backend_sched
    .bbif (bif),   // scpad_if.backend_body
    .bdrif(bif)    // scpad_if.backend_dram
    );

    // modport spad_head (
    //     input clk, n_rst, 
    //     // Downstream backpressure
    //     input w_stall, r_stall,
    //     // Header backpresssure. 
    //     output fe_stall, be_stall,
    //     // Inputs from FE and BE
    //     input fe_req, be_req,
    //     // Outputs toward Body
    //     output head_stomach_req

    // );

    // head #(.IDX(0)) tb_head (.hif(bif));
    // assign bif.fe_req[0]  = '0;
    // assign bif.w_stall[0] = 1'b0;
    // assign bif.r_stall[0] = 1'b0;

    // body #(.IDX(0)) tb_body (.bif(bif)); 

    // tail #(.IDX(0)) tb_tail (.tif(bif));



    initial begin
        n_rst = 0;
        repeat (5) @(posedge clk);
        n_rst = 1;
    end

    // string fname, wavepath; 
    // getenv("WAVEPATH", wavepath);
    // $sformat(fname, "%s/backend_tb.vcd", wavepath); // idk what this is so I'll ignore it for now

    // initial begin 
    //     $dumpfile(fname);
    //     $dumpvars(0);
    // end 

    test PROG (.bif(bif)); 

    // initial begin
    //     #(10_000 * CLK_PERIOD) $fatal(1, "[TB] Timeout");
    // end

endmodule

// modport backend_tb (
//         input clk, n_rst, 
//         input sched_res, be_req,
//         input be_dram_stall, be_dram_req,

//         output be_stall, dram_be_stall,
//         output sched_req, be_res, dram_be_res
//     );

program test (scpad_if.backend_tb bif);
    localparam CLK_PERIOD = 10;
    import scpad_pkg::*;

    task reset(); 
        #(CLK_PERIOD * 2);
    endtask

    task schedule_request(
        logic valid,
        logic write,
        logic [SCPAD_ADDR_WIDTH-1:0] spad_addr,
        logic [DRAM_ADDR_WIDTH-1:0] dram_addr,
        logic [MAX_DIM_WIDTH-1:0] num_rows,
        logic [MAX_DIM_WIDTH-1:0] num_cols,
        logic [SCPAD_ID_WIDTH-1:0] scpad_id
   );
   begin
        bif.sched_req[scpad_id].valid = valid;
        bif.sched_req[scpad_id].write = write;
        bif.sched_req[scpad_id].spad_addr = spad_addr;
        bif.sched_req[scpad_id].dram_addr = dram_addr;
        bif.sched_req[scpad_id].num_rows = num_rows;
        bif.sched_req[scpad_id].num_cols = num_cols;
        bif.sched_req[scpad_id].scpad_id = scpad_id;
    end
   endtask

   task dram_results();
    begin
        automatic int chunks = (bif.sched_req[0].num_cols + 1 + 3) / 4;  // ceil(num_cols/4)
        for (int i = 0; i < (chunks * (bif.sched_req[0].num_rows + 1) + 1); i++) begin
        // Mirror request → response
        bif.dram_be_res[0].valid = bif.be_dram_req[0].valid;
        bif.dram_be_res[0].write = bif.be_dram_req[0].write;
        bif.dram_be_res[0].id    = bif.be_dram_req[0].id;
        // Return a dummy data pattern (can be 'i' or a hash of addr/id)
        bif.dram_be_res[0].rdata = {16'(i), 16'(i), 16'(i), 16'(i)};
        #(CLK_PERIOD);
        end
        bif.dram_be_res[0].valid = 0;
        bif.dram_be_res[0].write = 0;
        bif.dram_be_res[0].id    = 0;
        bif.dram_be_res[0].rdata = 0;
        #(CLK_PERIOD/2);
        bif.sched_req[0].valid = 1'b0;
        #(CLK_PERIOD/2);
        #(CLK_PERIOD);
    end
    endtask

    task sram_results(logic [MAX_DIM_WIDTH:0] num_rows);
        automatic int chunks;
        localparam int LANES = 32;

        begin
            chunks = (num_rows + 1 + 3) / 4;
            for (int i = 0; i < (num_rows + 1); i++) begin
                bif.be_res[0].valid = 1'b1;
                bif.be_res[0].write = 1'b1;
                bif.be_res[0].rdata = {LANES{16'(i)}};
                #(CLK_PERIOD);
            end
            bif.be_res[0].valid = 1'b0;
            bif.be_res[0].write = 1'b0;
            bif.be_res[0].rdata = 0;

            while(1) begin
                #(CLK_PERIOD/2);
                if(bif.sched_res[0].valid == 1'b1) begin
                    bif.sched_req[0].valid = 1'b0;
                    bif.sched_req[0].write = 1'b0;
                    #(CLK_PERIOD/2);
                    break;
                end
            end

            
            // for(int i = 0; i < chunks*(num_rows + 1); i++) begin // wait for dram reads to exit
            //     #(CLK_PERIOD);
            // end

            // #(CLK_PERIOD * chunks);
            // #(CLK_PERIOD/2);
            // bif.sched_req[0].valid = 1'b0;
            // bif.sched_req[0].write = 1'b0;
            // #(CLK_PERIOD/2);
        end
   endtask

    task scpad_load_all_dims(); 
        begin
            for (int i = 0; i < 32; i++) begin
                for (int j = 0; j < 32; j++) begin
                    // valid, write, spad_addr, dram_addr, num_rows, num_cols, scpad_id
                    schedule_request(1'b1, 1'b0, 20'd0, 32'd0, 5'(i), 5'(j), 1'b0);
                    dram_results();
                end
            end
        end
    endtask

    task scpad_store_all_dims(); // purely simulating the request for now
        begin
            for (int i = 0; i < 32; i++) begin
                for (int j = 0; j < 32; j++) begin
                    // valid, write, spad_addr, dram_addr, num_rows, num_cols, scpad_id
                    schedule_request(1'b1, 1'b1, 20'd0, 32'd0, 5'(i), 5'(j), 1'b0);
                    #(CLK_PERIOD);
                    sram_results(6'(i));
                    #(CLK_PERIOD * 2);
                end
            end
        end
    endtask

    initial begin
        bif.dram_be_stall[0] = 'b0;
        bif.sched_req[0] = 'b0;
        bif.dram_be_res[0] = 'b0;
        bif.be_stall[0] = 'b0;
        bif.be_res[0] = 0;
        bif.dram_be_stall[1] = 'b0;
        bif.sched_req[1] = 'b0;
        bif.dram_be_res[1] = 'b0;
        bif.be_stall[1] = 'b0;
        bif.be_res[1] = 0;
        #(CLK_PERIOD * 5);

        // scpad_load_all_dims();
        scpad_store_all_dims();
        // schedule_request(1'b1, 1'b0, 20'd0, 32'd0, 5'd0, 5'd1, 1'b0); // invalid request after normal request
        // dram_results();
        schedule_request(1'b1, 1'b1, 20'd0, 32'd0, 5'd0, 5'd4, 1'b0);
        #(CLK_PERIOD);
        bif.be_res[0].valid = 1'b1;
        bif.be_res[0].write = 1'b1;
        bif.be_res[0].rdata = {64'd64, 64'd64, 64'd64, 64'd64, 64'd64, 64'd64, 64'd64, 64'd64};
        #(CLK_PERIOD);
        bif.be_res[0].valid = 1'b0;
        bif.be_res[0].write = 1'b0;
        bif.be_res[0].rdata = 0;
        #(CLK_PERIOD * 2);
        #(CLK_PERIOD * 0.5);
        schedule_request(1'b0, 1'b0, 20'd0, 32'd0, 5'd31, 5'd31, 1'b0);
        #(CLK_PERIOD * 0.5);
        #(CLK_PERIOD * 5);
        // schedule_request(1'b1, 1'b1, 20'd0, 32'd0, 5'd0, 5'd0, 1'b0);
        // #(CLK_PERIOD);
        // bif.be_res[0].valid = 1'b1;
        // bif.be_res[0].write = 1'b1;
        // bif.be_res[0].rdata = {64'd64, 64'd64, 64'd64, 64'd64, 64'd64, 64'd64, 64'd64, 64'd64};
        // #(CLK_PERIOD);
        // bif.be_res[0].valid = 1'b0;
        // bif.be_res[0].write = 1'b0;
        // bif.be_res[0].rdata = 0;
        // #(CLK_PERIOD * 1.5);
        // schedule_request(1'b0, 1'b0, 20'd0, 32'd0, 5'd31, 5'd31, 1'b0);
        // #(CLK_PERIOD * 0.5);
        // #(CLK_PERIOD * 5);
        // #(CLK_PERIOD * 32);
        
        // #(CLK_PERIOD * 5);
        // sram_results(5'd31);
        // schedule_request(1'b1, 1'b1, 20'd0, 32'd0, 5'd31, 5'd31, 1'b0); // simulate a normal scpad write, sram read -> dram_write
        // #(CLK_PERIOD * 8 * 32); // 32 = num_cols
        // schedule_request(1'b0, 1'b0, 20'd0, 32'd0, 5'd31, 5'd31, 1'b0);
        // schedule_request(1'b0, 1'b0, 20'd0, 32'd0, 5'd31, 5'd31, 1'b0); // invalid request after normal request
        // #(CLK_PERIOD*5);
        // schedule_request(1'b1, 1'b1, 20'd0, 32'd0, 5'd11, 5'd4, 1'b0); // simulate worst case scpad load, dram read -> sram_write
        // #(CLK_PERIOD);
    end

endprogram