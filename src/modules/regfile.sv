// register_file 
// lab 1
// rrbathin
// 8/22/2024

`include "cpu_types_pkg.vh"
`include "register_file_if.vh"

module register_file(
    input logic CLK,
    input logic nRST,
    register_file_if.rf rf_if
);

    import cpu_types_pkg::*;

    word_t [31:0] register, next_reg;

    always_ff @(posedge CLK, negedge nRST) begin 
        if (!nRST) begin 
            register <= '0;
        end
        else begin 
            register <= next_reg;
        end
    end
    
    always_comb begin
        next_reg = register;
        if (rf_if.WEN && (rf_if.wsel != 0)) begin 
            next_reg[rf_if.wsel] = rf_if.wdat;
        end
    end

    assign rf_if.rdat1 = register[rf_if.rsel1];
    assign rf_if.rdat2 = register[rf_if.rsel2];


endmodule