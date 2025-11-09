import uvm_pkg::*;
`include "../src/modules/lockup_free_cache.sv"
`include "lfc_if.sv"
`include "test.sv"

module tb_top();
    bit clk;

    // Reset Input for both CPU and RAM
    logic n_rst;

    // CPU Inputs
    logic mem_in;
    logic [31:0] mem_in_addr;
    logic mem_in_rw_mode; // 0 = read, 1 = write
    logic [31:0] mem_in_store_value;
    logic dp_in_halt;

    // CPU Outputs
    logic [3:0] mem_out_uuid;
    logic stall;
    logic hit;
    logic [31:0] hit_load;
    logic [NUM_BANKS-1:0] block_status;
    logic [NUM_BANKS-1:0][UUID_SIZE-1:0] uuid_block;
    logic dp_out_flushed;

    // RAM Inputs
    logic [NUM_BANKS-1:0][31:0] ram_mem_data;
    logic [NUM_BANKS-1:0] ram_mem_complete;

    // RAM Outputs
    logic [NUM_BANKS-1:0] ram_mem_REN;
    logic [NUM_BANKS-1:0] ram_mem_WEN;
    logic [NUM_BANKS-1:0][31:0] ram_mem_addr;
    logic [NUM_BANKS-1:0][31:0] ram_mem_store;

    // clock gen
    initial begin
        clk = 0;
        forever #10 clk = !clk;
    end

    lfc_if lfc_interface(clk);

    // Reset input for both CPU and RAM
    //assign lfc_interface.n_rst = n_rst;
    assign n_rst = lfc_interface.n_rst;

    // CPU Inputs
    /*assign lfc_interface.mem_in = mem_in;
    assign lfc_interface.mem_in_addr = mem_in_addr;
    assign lfc_interface.mem_in_rw_mode = mem_in_rw_mode;
    assign lfc_interface.mem_in_store_value = mem_in_store_value;
    assign lfc_interface.dp_in_halt = dp_in_halt;*/
    assign mem_in = lfc_interface.mem_in;
    assign mem_in_addr = lfc_interface.mem_in_addr;
    assign mem_in_rw_mode = lfc_interface.mem_in_rw_mode;
    assign mem_in_store_value = lfc_interface.mem_in_store_value;
    assign dp_in_halt = lfc_interface.dp_in_halt;
    
    // CPU Outputs
    assign lfc_interface.mem_out_uuid = mem_out_uuid;
    assign lfc_interface.stall = stall;
    assign lfc_interface.hit = hit;
    assign lfc_interface.hit_load = hit_load;
    assign lfc_interface.block_status = block_status;
    assign lfc_interface.uuid_block = uuid_block;
    assign lfc_interface.dp_out_flushed = dp_out_flushed;

    // RAM Inputs
    //assign lfc_interface.ram_mem_data = ram_mem_data;
    //assign lfc_interface.ram_mem_complete = ram_mem_complete;
    assign ram_mem_data = lfc_interface.ram_mem_data;
    assign ram_mem_complete = lfc_interface.ram_mem_complete;

    // RAM Outputs
    assign lfc_interface.ram_mem_REN = ram_mem_REN;
    assign lfc_interface.ram_mem_WEN = ram_mem_WEN;
    assign lfc_interface.ram_mem_addr = ram_mem_addr;
    assign lfc_interface.ram_mem_store = ram_mem_store;

    lockup_free_cache DUT(.CLK(clk), .nRST(n_rst), .*);

    initial begin
        uvm_config_db#(virtual lfc_if)::set(null, "", "lfc_vif", lfc_interface);
        run_test("test");
    end

endmodule