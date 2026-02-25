`include "cache_types_pkg.svh"

module confirm_uuid (
    input logic CLK,
    input logic nRST,
    input logic miss, 
    input logic stall,
    input logic [UUID_SIZE-1:0] uuid_out,
    input logic [UUID_SIZE-1:0] uuid
);

  property correct_uuid_out;
    @(posedge CLK) disable iff (!nRST)
    (miss && !stall) |-> (uuid_out == uuid);
  endproperty

  property proper_uuid_increment;
    @(posedge CLK) disable iff (!nRST)
    (miss && !stall) |=> (uuid == ($past(uuid) + 1));
  endproperty

  assert property (correct_uuid_out)
    else $error("ASSERTIONERROR: uuid_out did not match internal uuid on accepted miss");

  assert property (proper_uuid_increment)
    else $error("ASSERTIONERROR: Internal UUID was not incremented properly after miss");

endmodule 