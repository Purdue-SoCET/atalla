/*
*   Copyright 2016 Purdue University
*
*   Licensed under the Apache License, Version 2.0 (the "License");
*   you may not use this file except in compliance with the License.
*   You may obtain a copy of the License at
*
*       http://www.apache.org/licenses/LICENSE-2.0
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.
*
*
*   Filename:     socetlib_divider_control.sv
*
*   Created by:   William Cunningham
*   Email:        wrcunnin@purdue.edu
*   Date Created: 11/02/2025
*   Description:  Shared logic module for determining divider outputs.
*/

module socetlib_divider_control #(
  parameter int NUM_BITS = 32
) (
  input logic is_signed, start_in, div_finished,
  input logic [NUM_BITS-1:0] dividend, divisor,
  input logic [NUM_BITS-1:0] quotient_in, remainder_in,
  output logic start, finished, abort,
  output logic [NUM_BITS-1:0] quotient_out, remainder_out
);
  localparam logic [NUM_BITS-1:0] MIN_SIGNED = {1'b1, {(NUM_BITS-1){1'b0}}};  // For NUM_BITS == 32, should be 32'h8000_0000
  localparam logic [NUM_BITS-1:0] ALL_1 = {(NUM_BITS){1'b1}};  // For NUM_BITS == 32, should be 32'hFFFF_FFFF
  logic overflow, zero;

  assign overflow = (dividend == MIN_SIGNED) && (divisor == ALL_1) && is_signed;
  assign zero = (divisor == '0);
  assign start = start_in && !overflow && !zero;
  assign abort = zero || overflow;
  assign finished = div_finished || abort;

  assign quotient_out = zero ? ALL_1 : (overflow ? MIN_SIGNED : quotient_in);
  assign remainder_out =  zero ? dividend : (overflow ? '0 : remainder_in);

endmodule