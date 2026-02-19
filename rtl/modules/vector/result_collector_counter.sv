// ------------------------------------------------------------
// result_collector_counter.sv
// Counter for tracking slice element completion
// Owner: Jacob Walter
// ------------------------------------------------------------

module result_collector_counter #(
    parameter int COUNT_TO = 2  // Default slice width
) (
    input  logic CLK,
    input  logic nRST,
    input  logic increment,     // Pulse to increment counter
    input  logic reset_counter, // Pulse to reset counter
    output logic [$clog2(COUNT_TO)-1:0] count,  // Original width for compatibility
    output logic at_max         // High when count reaches COUNT_TO
);

    // Internal counter with extra bit to reach COUNT_TO
    logic [$clog2(COUNT_TO+1)-1:0] count_internal, count_internal_n;

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            count_internal <= '0;
        end
        else begin
            count_internal <= count_internal_n;
        end
    end

    always_comb begin
        count_internal_n = count_internal;
        
        if (reset_counter) begin
            count_internal_n = '0;
        end
        else if (increment && (count_internal < COUNT_TO)) begin
            count_internal_n = count_internal + 1;
        end
    end

    // Outputs
    assign count = count_internal[$clog2(COUNT_TO)-1:0];  // Truncate to original width
    assign at_max = (count_internal == COUNT_TO);

endmodule