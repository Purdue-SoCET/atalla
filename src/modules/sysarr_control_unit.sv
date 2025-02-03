`include "systolic_array_control_unit_if.vh"

module sysarr_control_unit #(
    parameter N = 4,    // Default dimension of the systolic array
    parameter MUL_LEN = 2,
    parameter ADD_LEN = 3
)(
    input logic clk, 
    input logic nRST,
    systolic_array_control_unit_if.control_unit cu
);

    logic start_flag;
    // next MAC signals
    logic [$clog2(MUL_LEN+ADD_LEN)-1:0] nxt_MAC_count;
    logic nxt_MAC_start;
    // next add signals for adding partial sums
    logic [$clog2(ADD_LEN)-1:0] nxt_add_count;
    logic nxt_add_start;
    // next signals for iterations
    logic [$clog2(3*N)-1:0] iteration [2:0];    //there can be at most 3 instructions in flight in saturated pipeline
    logic [$clog2(3*N)-1:0] nxt_iteration [2:0];
    logic [2:0] iteration_full;             // whether there is an iteration in this slot: 001 means an iteration in first slot 
    logic [2:0] nxt_iteration_full;
    logic [1:0] input_tracker;
    logic [1:0] data_loaded;
    logic [1:0] nxt_data_loaded;
    logic MAC_done; // flag for if the MAC is done and when data_loaded and mac_done the next mac starts
    logic nxt_MAC_done;
    integer i,j,k;
    // we have space for another instruction to start loading in inputs 
    assign cu.iteration = iteration;
    always_comb begin : input_buses // if we are receiving inputs tell the fifos where to load them :D
        cu.input_type = 1'b0; 
        cu.input_row = '0;
        cu.input_load = 1'b0;
        cu.weight_row = '0;
        cu.weight_load = 1'b0;
        cu.partials_row = '0;
        cu.partials_load = 1'b0;
        if (cu.input_en) begin
            cu.input_row = cu.row_en;
            cu.input_load = 1'b1;
        end else if (cu.weight_en) begin
            cu.input_type = 1'b1;
            cu.weight_row = cu.row_en;
            cu.weight_load = 1'b1;
        end
        if (cu.partial_en) begin
            cu.partials_row = cu.row_en;
            cu.partials_load = 1'b1;
        end
    end
    
    // start an instruction the cycle after the first row of input loads (only need first entry)
    assign start_flag = cu.input_en && (cu.row_en == 0);

    // iteration tracker
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0)begin
            iteration <= '{default: '0};
            iteration_full <= '0;
        end else begin
            iteration <= nxt_iteration;
            iteration_full <= nxt_iteration_full;
        end 
    end
    
    // check control unit draw.io
    always_comb begin
        nxt_iteration = iteration;
        nxt_iteration_full = iteration_full;
        for (i = 0; i < 3; i++)begin // starter for loop to say full
            if (start_flag)begin //if an operation is starting make sure to initialize an iteration slot
                if (iteration_full[i] == 1'b0) begin
                    nxt_iteration_full[i] = 1'b1;
                    break;
                end
            end
        end
        for (j = 0; j < 3; j++)begin // counting logic
            if (nxt_iteration_full[j] && nxt_MAC_start)begin // if there is an iteration counter in this slot and a mac cycle is about to start
                nxt_iteration[j] = iteration[j] + 1;
                if (iteration[j] == 3*N-1) begin // this iteration is done
                    nxt_iteration[j] = 0;
                    nxt_iteration_full[j] = 0;
                end
            end
        end
    end
    
    // fifo shifts and enables
    always_comb begin
        cu.fifo_shift = '0;
        cu.out_fifo_shift = '0;
        if (nxt_MAC_start) begin
            cu.fifo_shift = 1'b1;
        end
        if (cu.add_count == ADD_LEN-1) begin
            cu.out_fifo_shift = 1'b1;
        end
    end
    // MAC 
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0)begin
            cu.MAC_start <= '0;
            cu.MAC_count <= '0;
            MAC_done <= 1'b1;
        end else begin
            cu.MAC_start <= nxt_MAC_start;
            cu.MAC_count <= nxt_MAC_count;
            MAC_done <= nxt_MAC_done;
        end 
    end
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0)begin
            data_loaded <= '0; 
        end else begin
            data_loaded <= nxt_data_loaded;
        end 
    end
    always_comb begin
        nxt_data_loaded = data_loaded;
        if (cu.input_en) begin
            nxt_data_loaded[0] = 1'b1;
        end
        if (cu.partial_en) begin
            nxt_data_loaded[1] = 1'b1;
        end
        if(cu.MAC_start) begin//if(data_loaded == 2'b11 && cu.MAC_start)begin //reset state if another MAC starts which means that data was successfully loaded in array
            nxt_data_loaded = '0;
        end
    end

    always_comb begin // input tracker tracks the iterations if an input is being loaded.
        input_tracker = '0; //no operations
        for (k = 0; k < 3; k++)begin
            if (iteration_full[k] && iteration[k] != 3 * N)begin
                input_tracker = 2'b01; //there is an operation happening but its done loading
                if (iteration[k] < N)begin
                    input_tracker = 2'b11; //there is an operation happening and its not done loading
                    break;
                end
            end
        end
    end
    // tells the memory subsystem if the input fifo has space for another gemm
    // if any iteration slot is still in the backend of the fifos then there is no space
    assign cu.fifo_has_space = input_tracker == 2'b01 || input_tracker == 2'b00;
    
    always_comb begin
        nxt_MAC_count = cu.MAC_count;
        nxt_MAC_done = MAC_done;
        nxt_MAC_start = 1'b0;
        // MAC is free running counter that starts with mac_start and goes until reset by start logic
        if (cu.MAC_count > 0 || cu.MAC_start) begin 
            nxt_MAC_count = cu.MAC_count + 1;
        end
        // set flage of mac done high if count == max
        if ((cu.MAC_count >= (ADD_LEN + MUL_LEN - 2)) || ~|iteration_full)begin // 
            nxt_MAC_done = 1'b1;
        end
        /*if we loaded something or there is not loading to be done and the MAC is done*/
        if((&data_loaded || input_tracker == 2'b01) & MAC_done)begin 
            nxt_MAC_start = 1'b1;
            nxt_MAC_count = '0;
            nxt_MAC_done = 1'b0;
        end

    end
    // add signals
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0)begin
            cu.add_start <= '0;
            cu.add_count <= '0;
        end else begin
            cu.add_start <= nxt_add_start;
            cu.add_count <= nxt_add_count;
        end 
    end
    integer q;
    always_comb begin
        nxt_add_start = 1'b0;
        nxt_add_count = cu.add_count;
        for (q = 0; q < 3; q++)begin
            if (iteration[q] > N && cu.MAC_start)begin
                nxt_add_start = 1'b1;
                break;
            end
        end
        if (cu.add_start || cu.add_count > 0) begin
            nxt_add_count = cu.add_count + 1;
            if (cu.add_count == ADD_LEN)begin
                nxt_add_count = 0;
            end
        end
    end
endmodule
