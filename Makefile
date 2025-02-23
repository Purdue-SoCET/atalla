SOURCE_FILES = \
	./src/modules/system.sv \
	./src/modules/scheduler_core.sv \
	./src/modules/memory_control.sv \
	./src/modules/caches.sv \
	./src/modules/icache.sv \
	./src/modules/dcache.sv \
	./src/modules/scoreboard.sv \
	./src/modules/fetch.sv \
	./src/modules/fetch_branch.sv \
	./src/modules/dispatch.sv \
	./src/modules/issue.sv \
	./src/modules/scoreboard.sv \
	./src/modules/fu_alu.sv \
	./src/modules/fu_branch_predictor.sv \
	./src/modules/fu_branch.sv \
	./src/modules/writeback.sv

fc:
	vlog -sv ./src/testbench/flex_counter_tb.sv ./src/modules/flex_counter.sv
	vsim -voptargs="+acc" work.flex_counter_tb

mls:
	vlog -sv +incdir+./src/include ./src/testbench/fu_matrix_ls_tb.sv ./src/modules/fu_matrix_ls.sv
	vsim -voptargs="+acc" work.fu_matrix_ls_tb

wb:
	vlog -sv +incdir+./src/include ./src/testbench/writeback_tb.sv ./src/modules/writeback.sv
	vsim -voptargs="+acc" work.writeback_tb -do "do ./src/waves/writeback.do; run -all"


source:
	vlog -sv $(SOURCE_FILES) +incdir+./src/include/ 

%:
	vlog -sv $(SOURCE_FILES) +incdir+./src/include/ 
	vlog -sv ./src/testbench/$*_tb.sv +incdir+./src/include/
	vsim -voptargs="+acc" work.$*_tb -do "view objects; do ./src/waves/$*.do; run -all;" -onfinish stop

# ./src/waves/$*.do 
%_vlint:
	verilator --lint-only src/modules/$*.sv -Isrc/include -Isrc/modules

vlog: 
	vlog ./src/modules/fu_branch.sv ./src/modules/fu_branch_predictor.sv ./src/modules/fetch_branch.sv ./src/testbench/fetch_branch_tb.sv