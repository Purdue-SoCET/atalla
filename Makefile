fc:
	vlog -sv ./src/testbench/fu_gemm_tb.sv ./src/modules/fu_gemm.sv
	vsim -voptargs="+acc" work.fu_gemm_tb

%:
	vlog -sv ./src/testbench/$*_tb.sv ./src/**/*
	vsim -voptargs="+acc" work.$*_tb
