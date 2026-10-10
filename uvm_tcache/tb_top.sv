import uvm_pkg::*;
`include "tc_if.sv"
`include "test.sv"
`include "texture_cache.sv"
`include "tc_types.sv"

module tb_top();
    bit clk;

    // Reset Input for both TMU and MEM
    logic n_rst;

    // Initializations
    // TODO: define widths
    logic batch_id;
    logic [3:0][S_T_WIDTH-1:0] s;
    logic [3:0][S_T_WIDTH-1:0] t;
    logic [3:0][TEXEL_WIDTH-1:0] tex_width;
    logic [3:0][TEXEL_HEIGHT-1:0] tex_height;
    logic [3:0][ADDR_WIDTH-1:0] base_addr;
    logic tmu_valid;

    logic cache_ready;
    logic [3:0][TEXEL_RETURN_WIDTH-1:0] texel_return;

    // TODO: define widths
    logic [ADDR_WIDTH-1:0] mem_addr;
    logic mem_valid;

    logic [DATA_WIDTH-1:0] mem_data;
    logic mem_ready;

    // clock gen
    initial begin
        clk = 0;
        forever #10 clk = !clk;
    end

    tc_if tc_if(clk);

    // Assign Statements

    // Reset input for both TMU and MEM
    assign n_rst = tc_if.n_rst;

    // TMU Inputs
    assign batch_id = tc_if.batch_id;
    assign s = tc_if.s;
    assign t = tc_if.t;
    assign tex_width = tc_if.tex_width;
    assign tex_height = tc_if.tex_height;
    assign base_addr = tc_if.base_addr;
    assign tmu_valid = tc_if.tmu_valid;
    
    // TMU Outputs
    assign tc_if.cache_ready = cache_ready;
    assign tc_if.texel_return = texel_return;
    
    // MEM Inputs
    assign mem_data = tc_if.mem_data;
    assign mem_ready = tc_if.mem_ready;

    // MEM Outputs
    assign tc_if.mem_addr = mem_addr;
    assign tc_if.mem_valid = mem_valid;

    texture_cache DUT(.clk(clk), .n_rst(n_rst), .*);

    initial begin
        uvm_config_db#(virtual tc_if)::set(null, "", "tc_vif", tc_if);
        run_test("test");
    end

endmodule
