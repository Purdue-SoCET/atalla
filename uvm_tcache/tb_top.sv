import uvm_pkg::*;
`include "tc_if.sv"
`include "test.sv"
`include "texture_cache.sv"

module tb_top();
    bit clk;

    // Reset Input for both TMU and MEM
    logic n_rst;

    // Initializations

    // TMU Inputs
    logic v;
    logic u;
    logic tex_width;
    logic base_addr;

    // TMU Outputs
    logic hit_way;
    logic hit;

    // MEM Inputs
    logic [31:0] mem_addr;

    // MEM Outputs
    logic [31:0] mem_data;

    // clock gen
    initial begin
        clk = 0;
        forever #10 clk = !clk;
    end

    tc_if lfc_interface(clk);

    // Assign Statements

    // Reset input for both TMU and MEM
    assign n_rst = tc_interface.n_rst;

    // TMU Inputs
    assign tc_if.v = v;
    assign tc_if.u = u;
    assign tc_if.tex_width = tex_width;
    assign tc_if.base_addr = base_addr;
    
    // TMU Outputs
    assign tc_if.hit_way = hit_way;
    assign tc_if.hit = hit;
    
    // MEM Inputs
    assign tc_if.mem_addr = mem_addr;

    // MEM Outputs
    assign tc_if.mem_data = mem_data;

    texture_cache DUT(.CLK(clk), .nRST(n_rst), .*);

    initial begin
        uvm_config_db#(virtual tc_if)::set(null, "", "lfc_vif", lfc_interface);
        run_test("test");
    end

endmodule
