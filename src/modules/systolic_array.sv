`include "systolic_array_if.vh"
`include "systolic_array_control_unit_if.vh"
`include "systolic_array_MAC_if.vh"
`include "systolic_array_FIFO_if.vh"

module systolic_array #(
    parameter N = 4,    // Default dimension of the systolic array
    parameter WIDTH = 16       // Default data width
)(
    input logic CLK, nRST,
    systolic_array_if.memory_array memory
);
    // Input to systolic array
    logic [WIDTH*N-1:0] top_input;
    logic [WIDTH*N-1:0] weights_input;
    logic [WIDTH*N-1:0] partial_sums;
    // Load signals within systolic array
    logic [N-1:0] loadi;
    logic [N-1:0] loadw;
    logic [N-1:0] loadps;
    // MAC Unit connections within systolic array
    logic [WIDTH-1:0] MAC_inputs [N-1:0][N-1:0];
    logic [WIDTH-1:0] out_accumulate [N-1:0][N-1:0];
    // Weight Registers
    logic [WIDTH*N-1:0] weights [N-1:0];
    genvar i,j;
    // Instantiate Control Unit interface
    systolic_array_control_unit_if #(.array_dim(N), .data_w(WIDTH)) control_unit_if();

    // Instantiate the control unit
    control_unit  cu (
        .clk(clk),
        .rst(rst),
        .control_unit(control_unit_if.control_unit)
    );

    // Instantiate MAC unit interfaces
    systolic_array_MAC_if #(.data_w(WIDTH)) mac_ifs[N-1:0][N-1:0] (); 
    // Instantiate Input Fifos
    systolic_array_fifo_if #(.array_dim(N), .data_w(WIDTH)) input_fifos_ifs[N-1:0] (); 
    // Instantiate Partial Fifos
    systolic_array_fifo_if #(.array_dim(N), .data_w(WIDTH)) partial_fifos_ifs[N-1:0] (); 

    //Selection Muxes
    always_comb begin : input_choose
        top_input = '0;
        weights = '{default: '0};;
        if (control_unit_if.input_type == 1'b1) begin
            top_input = memory.array_in;
        end else if (control_unit_if.input_type == 1'b0) begin
            weights = memory.array_in;
        end
    end
    always_comb begin : load_sel
        loadi = '0;
        loadw = '0;
        loadps = '0;
        if (control_unit_if.input_load == 1'b1) begin
            loadi[control_unit_if.input_row] = 1'b1;
        end
        if (control_unit_if.weight_load == 1'b1) begin
            loadw[control_unit_if.weight_row] = 1'b1;
        end
        if (control_unit_if.input_load == 1'b1) begin
            loadps[control_unit_if.partials_row] = 1'b1;
        end
    end
    // Weight registers
    generate
        for (i = 0; i < N; i = i + 1) begin
            always_ff @(posedge CLK, negedge nRST) begin : weights_registers
                if(nRST == 1'b0)begin
                    weights[i] <= '0;
                end else if (loadw[i] == 1'b1) begin
                    weights[i] <= weights_input;
                end
            end
        end
    endgenerate    


    // Generate input fifos
    generate
        for (i = 0; i < N; i = i + 1) begin
            FIFO i_fifo (
                .clk(clk),
                .rst(rst),
                .FIFO(input_fifos_ifs[i].FIFO));
            assign input_fifos_ifs[i].load = loadi[i];
            assign input_fifos_ifs[i].shift = control_unit_if.fifo_shift;
            assign input_fifos_ifs[i].load_values = top_input;
            for (j = 0; j < N; j = j + 1) begin
                assign MAC_inputs[i][j] = input_fifos_ifs[i].out[j * WIDTH +: WIDTH];
            end
        end
    endgenerate

    // generate
    //     for (i = 0; i < N; i = i + 1) begin
    //         FIFO ps_fifo (
    //             .clk(clk),
    //             .rst(rst),
    //             .FIFO(partial_fifos_ifs[i].FIFO));
    //         assign input_fifos_ifs[i].load = loadi[i];
    //         assign input_fifos_ifs[i].shift = control_unit_if.fifo_shift;
    //         assign input_fifos_ifs[i].load_values = top_input;
    //         for (j = 0; j < N; j = j + 1) begin
    //             assign MAC_inputs[i][j] = input_fifos_ifs[i].out[j * WIDTH +: WIDTH];
    //         end
    //     end
    // endgenerate

    generate
        for (i = 0; i < N; i = i + 1) begin
            for (j = 0; j < N; j = j + 1) begin
                MAC_unit mac_inst (
                    .clk(clk),
                    .rst(rst),
                    .MAC(mac_ifs[i][j].MAC)
                );
                assign mac_ifs[i][j].start = control_unit_if.MAC_start;
                assign mac_ifs[i][j].count = control_unit_if.MAC_count;
                assign mac_ifs[i][j].weight = weights[j][i * WIDTH +: WIDTH];
                assign mac_ifs[i][j].in_value = MAC_inputs[i][j];
                if (i == 0) begin
                    assign mac_ifs[i][j].in_accumulate = '0;
                end else begin
                    assign mac_ifs[i][j].in_accumulate = out_accumulate[i][j-1];
                end
                assign out_accumulate[i][j] = mac_ifs[i][j].out_accumulate;
            end
        end
    endgenerate

endmodule
