`timescale 1ns / 1 ns

`include "systolic_array_FIFO_if.vh"

module sysarr_FIFO_tb();

// Parameters
parameter PERIOD = 10;

// Testbench Signals
logic tb_clk = 0;
logic tb_nrst;


// Clk init
always #(PERIOD/2) tb_clk++;
// FIFO_if instance
systolic_array_FIFO_if fifo_if();

sysarr_FIFO DUT (.nRST(tb_nrst), .clk(tb_clk), .fifo(fifo_if.FIFO));
task wait_n_clocks(input int num_cycles);
    int i;
    for (i = 0; i < num_cycles; i = i + 1) begin
        @(posedge tb_clk); // Wait for one positive edge of clk
    end
endtask
task reset;
    begin
      tb_nrst = 1'b0;
      @(posedge tb_clk);
      @(posedge tb_clk);
      @(negedge tb_clk);
      tb_nrst = 1'b1;
      @(posedge tb_clk);
      @(posedge tb_clk);
    end
endtask
integer i;
// Test scenarios
initial begin
    // Initialize signals
    tb_clk = 0;
    tb_nrst = 0;
    fifo_if.load = 0;
    fifo_if.shift = 0;
    fifo_if.load_values = 0;

    // Reset 
    reset();
    // Test case 1: Load values into the FIFO
    $display("fifo output before load = %h", fifo_if.out);
    fifo_if.load_values = 64'h0123456789ABCDEF; // Example data
    fifo_if.load = 1; // Ensure data is only loaded when load signal is high
    wait_n_clocks(1);
    fifo_if.load = 0;
    $display("fifo output after load = %h", fifo_if.out);
    // Test case 2: Shift values in the FIFO
    for (i = 0; i <= 3; i = i + 1) begin
        fifo_if.shift = 1;
        wait_n_clocks(1);
        fifo_if.shift = 0; 
        $display("fifo_if.out = %h", fifo_if.out);
    end
    
    // Test case 3: Load more data while output row is occupied
    fifo_if.load_values = 'hA5A5A5A5A5A5A5A5; // Example data
    #10;
    fifo_if.load = 1; 
    #10;
    fifo_if.load = 0;
    $display("fifo_if.out = %h", fifo_if.out); //should show same because we loaded into invisible part
    fifo_if.shift = 1;
    wait_n_clocks(1);
    fifo_if.shift = 0; 
    $display("fifo_if.out = %h", fifo_if.out);//should show A5A5 shifted in
    //Test case 4: Checking reset
    reset();
    $display("fifo_if.out = %h", fifo_if.out);

    #50;
    $stop;
end

endmodule
