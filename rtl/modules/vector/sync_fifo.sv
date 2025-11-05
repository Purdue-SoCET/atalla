module sync_fifo #(parameter FIFODEPTH=8, DATAWIDTH=16) // DATAWIDTH = word size
(
        input logic           nRST,               // Active low reset
                            	CLK,                // Clock
                            	wr_en, 				// Write enable
                            	shift, 				// shift (increment read pointer)
        input logic  [DATAWIDTH-1:0] din, 				// Data written into FIFO
        output logic [DATAWIDTH-1:0] dout, 				// Data read from FIFO
        output logic          empty, 				// FIFO is empty when high
                            	full 				// FIFO is full when high
);


  logic [$clog2(FIFODEPTH)-1:0]   wptr;
  logic [$clog2(FIFODEPTH)-1:0]   rptr;
  logic [$clog2(FIFODEPTH):0]     count; // Counter to track number of entries

  logic [FIFODEPTH-1:0][DATAWIDTH-1:0] fifo; // *packed* array

  always_ff @(posedge CLK or negedge nRST) begin
    if (!nRST) begin
      wptr <= '0;
      fifo <= '0;  // Initializes entire array to 0
    end 
    else begin
      if (wr_en & !full) begin
        fifo[wptr] <= din;
        // Rollover pointer when it reaches FIFODEPTH
        if (wptr == FIFODEPTH - 1)
          wptr <= '0;
        else
          wptr <= wptr + 1;
      end
    end
  end

  // For debug
  /*
  initial begin
    $monitor("[%0t] [FIFO] wr_en=%0b din=0x%0h rd_en=%0b dout=0x%0h empty=%0b full=%0b",
             $time, wr_en, din, rd_en, dout, empty, full);
  end */

  always_ff @(posedge CLK or negedge nRST) begin
    if (!nRST) begin
      rptr <= '0;
      dout  <= '0;
    end else begin
      dout <= fifo[rptr]; // do not block data based on shifting (rd_en)
      if (shift & !empty) begin
        // Rollover pointer when it reaches FIFODEPTH
        if (rptr == FIFODEPTH - 1)
          rptr <= '0;
        else
          rptr <= rptr + 1;
      end
    end
  end

  // Counter-based full/empty detection
  always_ff @(posedge CLK or negedge nRST) begin
    if (!nRST) begin
      count <= '0;
    end else begin
      case ({wr_en & !full, shift & !empty})
        2'b10: count <= count + 1; // Write only
        2'b01: count <= count - 1; // Read only
        default: count <= count;    // Both or neither
      endcase
    end
  end

  assign full  = (count == FIFODEPTH);
  assign empty = (count == 0);
endmodule