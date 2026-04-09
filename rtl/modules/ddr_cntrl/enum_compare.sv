`include "dram_pkg.svh"

import dram_pkg::*;
function automatic logic [BANK_NUM-1:0] enum_compare (fsm_t [BANK_NUM-1:0] in0, fsm_t [BANK_NUM-1:0] in1);
	for(int i = 0; i < BANK_NUM; i++) begin
		enum_compare[i] = (in0[i] == in1[i]);
	end
endfunction 
