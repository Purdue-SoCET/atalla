TBTOP=tb_top
SRCDIR=~/src
TBDIR=~/uvm

TESTNAME=test
VERBOSITY=UVM_MEDIUM
SEED=$(shell echo $$RANDOM)

QUESTA_HOME?=/package/eda/mg/questa2021.4/questasim

fc:
	vlog -sv ./src/testbench/flex_counter_tb.sv ./src/modules/flex_counter.sv
	vsim -voptargs="+acc" work.flex_counter_tb

%.log: 
	@if [ ! -f ./src/testbench/$*_bind.sv ]; then \
	    echo "// Empty file" > ./src/testbench/$*_bind.sv; \
	fi
	vlog -compile_uselibs -cover bs -sv -pedanticerrors -lint +incdir+./src/include/ \
	     ./src/modules/$*.sv \
	     ./src/testbench/$*_tb.sv \
	     ./src/testbench/$*_bind.sv 

%.sim: %.log
	vsim -coverage -c -voptargs="+acc" work.$*_tb -do  "coverage save -onexit $*_coverage.ucdb; run -all; quit" > ./simout/simout.txt

%.wav: %.log
	vsim -coverage -voptargs="+acc" work.$*_tb -do "view objects; do ./waveforms/$*.do; run -all;" -onfinish stop

lint_%:
	vlog -sv -pedanticerrors -lint +incdir+./src/include/ \
	     ./src/modules/$*.sv

sim_%:
	verilator --binary --trace-fst --trace-structs --hierarchical -Wno-TIMESCALEMOD -j 0 src/testbench/$*_tb.sv -y src/include -y src/modules
	./obj_dir/V$*_tb
	gtkwave waveforms/$*_tb.fst

uvm_sim:
	@echo "Building testbench and DUT..."
	vlog +incdir+$(SRCDIR)+$(TBDIR) \
	+acc \
	+cover \
	-L $(QUESTA_HOME)/uvm-1.2 \
	uvm/$(TBTOP).sv \
	-logfile tb_compile.log \
	-printinfilenames=file_search.log

	vsim -c $(TBTOP) -L \
	$(QUESTA_HOME)/uvm-1.2 \
	-voptargs=+acc \
	-coverage \
	+UVM_TESTNAME="$(TESTNAME)" \
	+UVM_VERBOSITY=$(VERBOSITY) \
	-do "run -all" &

uvm_gui:
	@echo "Building testbench and DUT..."
	vlog +incdir+$(SRCDIR)+$(TBDIR) \
	+acc \
	+cover \
	-L $(QUESTA_HOME)/uvm-1.2 \
	uvm/$(TBTOP).sv \
	-logfile tb_compile.log \
	-printinfilenames=file_search.log

	@echo "Running simulation in GUI mode..."
	vsim -coverage -i $(TBTOP) -L \
	$(QUESTA_HOME)/uvm-1.2 \
	-voptargs=+acc \
	+UVM_TESTNAME="$(TESTNAME)" \
	+UVM_VERBOSITY=$(VERBOSITY) \
	-do "do wave.do" -do "run -all" &

cache_wav: cache_bank.log cache_mshr_buffer.log lockup_free_cache.wav
cache_sim: cache_bank.log cache_mshr_buffer.log lockup_free_cache.sim
cache_bank_wav: cache_bank.wav
cache_bank_sim: cache_bank.sim

sf:
	vlog -sv -svstrict -pedanticerrors -lint +incdir+./src/include/ \
	     ./src/modules/sysarr_FIFO.sv \
	     ./src/testbench/sysarr_FIFO_tb.sv
	vsim -voptargs="+acc" work.sysarr_FIFO_tb -do "run -all"

clean: 
	rm -rf ./obj_dir ./verilator ./work ./.deps
	rm -rf work
	rm -f wlf*
	rm -f transcript    
	rm -f *.log
	rm -f *.vstf
	rm -f *.wlf
