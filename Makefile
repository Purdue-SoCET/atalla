

fc:
	vlog -sv ./src/testbench/flex_counter_tb.sv ./src/modules/flex_counter.sv
	vsim -voptargs="+acc" work.flex_counter_tb

%:
	vlog -sv ./src/testbench/$*_tb.sv ./src/**/*
	vsim -voptargs="+acc" work.$*_tb