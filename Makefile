fc:
	vlog -sv ./src/testbench/flex_counter_tb.sv ./src/modules/flex_counter.sv
	vsim -voptargs="+acc" work.flex_counter_tb

alu:
	vlog -sv +incdir+./src/include ./src/testbench/fu_alu_tb.sv ./src/modules/fu_alu.sv
	vsim -voptargs="+acc" work.fu_alu_tb

mls:
	vlog -sv +incdir+./src/include ./src/testbench/fu_matrix_ls_tb.sv ./src/modules/fu_matrix_ls.sv
	vsim -voptargs="+acc" work.fu_matrix_ls_tb

%:
	vlog -sv ./src/testbench/$*_tb.sv ./src/modules/$*.sv +incdir+./src/include/ 
	vsim -voptargs="+acc" work.$*_tb -do "view objects; do ./src/waves/$*.do; run -all;" -onfinish stop

%_vlint:
	verilator --lint-only src/modules/$*.sv -Isrc/include -Isrc/modules

# ./src/waves/$*.do 

# dispatch:
# 	vlog -sv ./src/testbench/dispatch_tb.sv ./src/modules/dispatch.sv ./src/modules/rst_m.sv ./src/modules/rst_s.sv +incdir+./src/include/
# 	vsim -voptargs="+acc" work.$*_tb
