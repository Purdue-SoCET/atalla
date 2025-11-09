`include "gsau_control_unit_if.vh"
`include "sys_arr_pkg.vh"
`include "vector_pkg.vh"

module gsau_control_unit #(
    parameter int VEGGIEREGS = 256,
    // FIFOSIZE is in bits (64 cycle latency * 3 clock cycles per MAC * 8 bits per vdst)
    // We store 8-bit vdst entries -> FIFO_DEPTH = FIFOSIZE / 8 = number of entries.
    parameter int FIFOSIZE = 64*3*8
) (
    input  logic        CLK,
    input  logic        nRST,
    gsau_control_unit_if.gsau gsau_port
);

  import vector_pkg::*;
  import sys_arr_pkg::*; 

  // Number of bits per entry in the fifo
  localparam int ENTRY_BITS = $clog2(VEGGIEREGS);

  // depth of the fifo in elements
  localparam int FIFO_DEPTH = (FIFOSIZE / ENTRY_BITS); 

  // FIFO interface signals
  logic         fifo_wr, fifo_shift;
  logic [ENTRY_BITS-1:0] fifo_din;
  logic [ENTRY_BITS-1:0] fifo_dout;
  logic         fifo_empty, fifo_full;

  sync_fifo #(
    .FIFODEPTH(FIFO_DEPTH),
    .DATAWIDTH(ENTRY_BITS)
  ) rd_fifo (
    .nRST(nRST),
    .CLK(CLK),
    .wr_en(fifo_wr),
    .shift(fifo_shift),
    .din(fifo_din),
    .dout(fifo_dout),
    .empty(fifo_empty),
    .full(fifo_full)
  );

  always_comb begin
    fifo_wr        = 1'b0;
    fifo_shift     = 1'b0;
    fifo_din       = '0;

    // Either activations or weights
    gsau_port.sa_array_in          = gsau_port.veg_vdata1; 

    // Always send partials, but only valid when inputs are loaded
    gsau_port.sa_array_in_partials = gsau_port.veg_vdata2; 

    gsau_port.sa_input_en         = 1'b0;
    gsau_port.sa_weight_en        = 1'b0;
    gsau_port.sa_partial_en       = 1'b0;

    gsau_port.wb_wbdst = fifo_dout;
    gsau_port.wb_psum  = gsau_port.sa_array_output;
    gsau_port.wb_valid = 1'b0;

    // Ready for additional GEMMs when FIFOs are not full and WB Buffer is ready
    gsau_port.sb_ready = !fifo_full && gsau_port.sa_fifo_has_space && gsau_port.wb_output_ready;

    // Ready for systolic array output when WB Buffer is ready, backpressured otherwise
    gsau_port.sa_output_ready = gsau_port.wb_output_ready;

    if (gsau_port.sb_valid && gsau_port.sb_ready) begin
      if (gsau_port.sb_weight) begin
        gsau_port.sa_weight_en = 1'b1;
      end else begin
        // Push register to fifo
        fifo_din = gsau_port.sb_vdst; 
        fifo_wr = 1'b1;
        gsau_port.sa_input_en = 1'b1;
        gsau_port.sa_partial_en = 1'b1;
      end
    end

    // Shift fifo when systolic array output is valid and being accepted
    if (gsau_port.sa_out_valid && gsau_port.sa_output_ready && !fifo_empty) begin 
      fifo_shift = 1'b1;
      gsau_port.wb_valid = 1'b1;
    end
  end
endmodule