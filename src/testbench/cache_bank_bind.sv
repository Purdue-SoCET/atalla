`include "cache_types_pkg.svh"

// Note: Structural bindings on cycle exact state transitions for property verification 
// have been disabled due to multi-cycle sram read/write latency integration breaking assumptions.
// Testbenches robustly cover latency-aware testing functionality.

module cache_bank_monitor (
  input logic CLK,
  input logic nRST,
  input cache_set [NUM_SETS_PER_BANK-1:0] bank, 
  input logic enable
);

  integer set, way;
  integer full_sets;
  integer dirty_sets;
  integer filled_ways;
  integer dirty_ways;

  always @(posedge CLK, negedge nRST) begin
    if (enable) begin
      full_sets = 0;
      dirty_sets = 0;
      for (set = 0; set < NUM_SETS_PER_BANK; set = set + 1) begin
        filled_ways = 0;
        dirty_ways = 0; 
        for (way = 0; way < NUM_WAYS; way = way + 1) begin
          if (bank[set][way].valid) filled_ways = filled_ways + 1;
          if (bank[set][way].dirty) dirty_ways = dirty_ways + 1;
        end
        
        $display("    Time %0t: Set %0d has (%0d filled ways) | (%0d dirty ways)", $time, set, filled_ways, dirty_ways);
        
        if (filled_ways == NUM_WAYS) begin 
          full_sets = full_sets + 1;
        end
        if (dirty_ways == NUM_WAYS) begin 
          dirty_sets = dirty_sets + 1;
        end
      end
      $display("Time %0t: (Total full sets: %0d) | (dirty sets: %0d) ", $time, full_sets, dirty_sets);
    end
  end

endmodule