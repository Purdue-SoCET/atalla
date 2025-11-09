
module ice40hx8k (hwclk,pb,ss7,ss6,ss5,ss4,ss3,ss2,ss1,ss0,left,right,red,green,blue,
                  Rx, Tx, CTSn, DCDn);
    input hwclk;
    input [20:0] pb;
    output [7:0] ss7,ss6,ss5,ss4,ss3,ss2,ss1,ss0;
    output [7:0] left,right;
    output red,green,blue;
    input Rx;
    output Tx, CTSn, DCDn;

    // reg hz100;
    // assign hz100 = hwclk;
    reg [15:0] ctr = 0;
    reg hz100 = 0;
    always @ (posedge hwclk)
      if (ctr == 0)
        begin
          ctr <= 0;
          hz100 <= ~hz100;
        end
      else
        ctr <= ctr + 1;

    assign CTSn = ~1; // clear to send
    assign DCDn = ~1; // carrier detect (makes Kermit - not the frog (says Megan) - happy)

// Example calculation (SIMPLE):
//
//    Fref * (DIVF + 1)
// ---------------------------- = out
//    2^(DIVQ + 2) * (DIVR + 1)
//
//     12  *  (95 + 1)
// ---------------------------- = 288
//      2^(0 + 2) * (0 + 1)

// Example calculation (PHASE_AND_DELAY):
// 
//      Fref * (DIVF + 1)
//   ---------------------------- = out
//          (DIVR + 1)
//
//       12  * (21 + 1)
//   ---------------------------- = 264
//          ( 0 + 1 )

// Want the serial clock to be about 2 * 16 * 115200 = 3686400
//       12  * ( 3 + 1)
//   ---------------------------- = 3692307.7  (within 0.16% of target)
//          (12 + 1 )

    /* The PLL instance */
    wire BYPASS = 0;
    wire RESETB = 1;
    wire serclk;
    SB_PLL40_CORE #(
        .FEEDBACK_PATH("SIMPLE"),           // <== switch to simple mode
        .DELAY_ADJUSTMENT_MODE_FEEDBACK("FIXED"),
        .DELAY_ADJUSTMENT_MODE_RELATIVE("FIXED"),
        .PLLOUT_SELECT("SHIFTREG_0deg"),
        .SHIFTREG_DIV_MODE(1'b0), // 0 => div-by-4; 1 => div-by-7
        .FDA_FEEDBACK(4'b0000),
        .FDA_RELATIVE(4'b0000),
        .DIVR(4'b0101),        // 5
        .DIVF(7'b0000100),     // 4
        .DIVQ(3'b011),         // 3
        .FILTER_RANGE(3'b001), // 1
    ) pll (
        .REFERENCECLK (hwclk),
        .PLLOUTCORE   (serclk),
        .BYPASS       (BYPASS),
        .RESETB       (RESETB)
        //.LOCK (LOCK)
    );

    reg xmit;
    wire [7:0] txdata;
    wire       txclk;
    wire       txready;
    reg recv;
    wire [7:0] rxdata;
    wire       rxclk;
    wire       rxready;

    uart uart_inst(
        .clk(serclk),
        .rst(0),
        .input_axis_tdata(txdata),
        .input_axis_tvalid(xmit),
        .input_axis_tready(txready),
        .output_axis_tdata(rxdata),
        .output_axis_tvalid(rxready),
        .output_axis_tready(recv),
        .rxd(Rx),
        .txd(Tx),
        .prescale(4)
    );

    always_ff @(posedge txclk, negedge txready)
      if (~txready)
        xmit <= 0;
      else
        xmit <= 1;

    always_ff @(posedge rxclk, negedge rxready)
      if (~rxready)
        recv <= 0;
      else
        recv <= 1;

    wire reset;
    reset_on_start ros (reset, hz100, pb[3] && pb[0] && pb[16]);
    top top_inst(
      hz100, reset, pb,
      left, right, ss7, ss6, ss5, ss4, ss3, ss2, ss1, ss0,
      red, green, blue,
      txdata,
      rxdata,
      txclk, rxclk,
      txready, rxready
    );

endmodule

module reset_on_start(
    output logic reset,
    input logic clk,
    input logic manual
);
  logic [2:0] startup = 4;
  assign reset = startup[2] | manual;    // MSB drives the reset signal
  always @ (posedge clk, posedge manual)
    if (manual == 1)
      startup <= 4;             // start with reset low to get a rising edge
    else begin
        case(startup)
            4: startup <= 5;
            5: startup <= 6;
            6: startup <= 7;
            7: startup <= 0;    // pull reset low here
        endcase
    end
endmodule
