fc:
	vlog -sv ./src/testbench/flex_counter_tb.sv ./src/modules/flex_counter.sv
	vsim -voptargs="+acc" work.flex_counter_tb
# make file_name
%:
	vlog -sv -svstrict -pedanticerrors -lint +incdir+./src/include/ \
	     ./src/modules/$*.sv \
	     ./src/testbench/$*_tb.sv
	vsim -voptargs="+acc" work.$*_tb -do "run -all"

#make sf

sf:
	vlog -sv -svstrict -pedanticerrors -lint +incdir+./src/include/ \
	     ./src/modules/sysarr_FIFO.sv \
	     ./src/testbench/sysarr_FIFO_tb.sv
	vsim -voptargs="+acc" work.sysarr_FIFO_tb -do "run -all"