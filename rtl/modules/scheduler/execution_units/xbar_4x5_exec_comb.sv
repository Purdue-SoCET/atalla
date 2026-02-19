`timescale 1ns/1ps
`include "execution_unit_if.sv"

module xbar_4x5_exec_comb
(
  input  execution_unit_if.in_DEC_t slot_1,
  input  execution_unit_if.in_DEC_t slot_2,
  input  execution_unit_if.in_DEC_t slot_3,
  input  execution_unit_if.in_DEC_t slot_4,

  output execution_unit_if.in_DEC_t ex1_in,
  output execution_unit_if.in_DEC_t ex2_in,
  output execution_unit_if.in_DEC_t ex3_in,
  output execution_unit_if.in_DEC_t ex4_in,
  output execution_unit_if.in_DEC_t ex5_in,

  output logic ex1_valid,
  output logic ex2_valid,
  output logic ex3_valid,
  output logic ex4_valid,
  output logic ex5_valid
);

  typedef enum logic [2:0] {
    DEST_NONE = 3'd0,
    DEST_EX1  = 3'd1,
    DEST_EX2  = 3'd2,
    DEST_EX3  = 3'd3,
    DEST_EX4  = 3'd4,
    DEST_EX5  = 3'd5
  } dest_e;

  function automatic dest_e decode_dest(input execution_unit_if.in_DEC_t s);
    // If multiple valids are high in one slot, this imposes priority.
    if (s.alu_valid || s.control_valid) begin
      return DEST_EX1;
    end
    else if (s.bf_div_valid || s.s_div_valid || s.s_mod_valid ||
             s.BF_to_int_valid || s.int_to_BF_valid) begin
      return DEST_EX2;
    end
    else if (s.bf_add_valid || s.bf_sub_valid || s.bf_mult_valid || s.bf_slt_valid) begin
      return DEST_EX3;
    end
    else if (s.sMult_valid) begin
      return DEST_EX4;
    end
    else if (s.ld_valid || s.st_valid) begin
      return DEST_EX5;
    end
    else begin
      return DEST_NONE;
    end
  endfunction

  dest_e d1, d2, d3, d4;
  always_comb begin
    d1 = decode_dest(slot_1);
    d2 = decode_dest(slot_2);
    d3 = decode_dest(slot_3);
    d4 = decode_dest(slot_4);
  end

  // Convenience request signals (slot has valid_in and targets this output)
  logic r1_ex1, r2_ex1, r3_ex1, r4_ex1;
  logic r1_ex2, r2_ex2, r3_ex2, r4_ex2;
  logic r1_ex3, r2_ex3, r3_ex3, r4_ex3;
  logic r1_ex4, r2_ex4, r3_ex4, r4_ex4;
  logic r1_ex5, r2_ex5, r3_ex5, r4_ex5;

  always_comb begin
    r1_ex1 = slot_1.valid_in && (d1 == DEST_EX1);
    r2_ex1 = slot_2.valid_in && (d2 == DEST_EX1);
    r3_ex1 = slot_3.valid_in && (d3 == DEST_EX1);
    r4_ex1 = slot_4.valid_in && (d4 == DEST_EX1);

    r1_ex2 = slot_1.valid_in && (d1 == DEST_EX2);
    r2_ex2 = slot_2.valid_in && (d2 == DEST_EX2);
    r3_ex2 = slot_3.valid_in && (d3 == DEST_EX2);
    r4_ex2 = slot_4.valid_in && (d4 == DEST_EX2);

    r1_ex3 = slot_1.valid_in && (d1 == DEST_EX3);
    r2_ex3 = slot_2.valid_in && (d2 == DEST_EX3);
    r3_ex3 = slot_3.valid_in && (d3 == DEST_EX3);
    r4_ex3 = slot_4.valid_in && (d4 == DEST_EX3);

    r1_ex4 = slot_1.valid_in && (d1 == DEST_EX4);
    r2_ex4 = slot_2.valid_in && (d2 == DEST_EX4);
    r3_ex4 = slot_3.valid_in && (d3 == DEST_EX4);
    r4_ex4 = slot_4.valid_in && (d4 == DEST_EX4);

    r1_ex5 = slot_1.valid_in && (d1 == DEST_EX5);
    r2_ex5 = slot_2.valid_in && (d2 == DEST_EX5);
    r3_ex5 = slot_3.valid_in && (d3 == DEST_EX5);
    r4_ex5 = slot_4.valid_in && (d4 == DEST_EX5);
  end

  // Per-output mux: fixed priority slot_1 > slot_2 > slot_3 > slot_4
  always_comb begin
    // defaults
    ex1_in = '0; ex2_in = '0; ex3_in = '0; ex4_in = '0; ex5_in = '0;
    ex1_valid = 1'b0; ex2_valid = 1'b0; ex3_valid = 1'b0; ex4_valid = 1'b0; ex5_valid = 1'b0;

    // EX1
    if      (r1_ex1) begin ex1_in = slot_1; ex1_valid = 1'b1; end
    else if (r2_ex1) begin ex1_in = slot_2; ex1_valid = 1'b1; end
    else if (r3_ex1) begin ex1_in = slot_3; ex1_valid = 1'b1; end
    else if (r4_ex1) begin ex1_in = slot_4; ex1_valid = 1'b1; end

    // EX2
    if      (r1_ex2) begin ex2_in = slot_1; ex2_valid = 1'b1; end
    else if (r2_ex2) begin ex2_in = slot_2; ex2_valid = 1'b1; end
    else if (r3_ex2) begin ex2_in = slot_3; ex2_valid = 1'b1; end
    else if (r4_ex2) begin ex2_in = slot_4; ex2_valid = 1'b1; end

    // EX3
    if      (r1_ex3) begin ex3_in = slot_1; ex3_valid = 1'b1; end
    else if (r2_ex3) begin ex3_in = slot_2; ex3_valid = 1'b1; end
    else if (r3_ex3) begin ex3_in = slot_3; ex3_valid = 1'b1; end
    else if (r4_ex3) begin ex3_in = slot_4; ex3_valid = 1'b1; end

    // EX4
    if      (r1_ex4) begin ex4_in = slot_1; ex4_valid = 1'b1; end
    else if (r2_ex4) begin ex4_in = slot_2; ex4_valid = 1'b1; end
    else if (r3_ex4) begin ex4_in = slot_3; ex4_valid = 1'b1; end
    else if (r4_ex4) begin ex4_in = slot_4; ex4_valid = 1'b1; end

    // EX5
    if      (r1_ex5) begin ex5_in = slot_1; ex5_valid = 1'b1; end
    else if (r2_ex5) begin ex5_in = slot_2; ex5_valid = 1'b1; end
    else if (r3_ex5) begin ex5_in = slot_3; ex5_valid = 1'b1; end
    else if (r4_ex5) begin ex5_in = slot_4; ex5_valid = 1'b1; end
  end

endmodule
