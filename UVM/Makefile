UVM_HOME := /package/eda/mg/questa2021.4/questasim/verilog_src/uvm-1.2

default:
	@echo 'use $$make run or $$make test'

help:
	@echo 'use $$make run or $$make test'

run : 
	vlib work
	vlog -sv +acc +define+UVM_NO_DPI +incdir+. +incdir+$(UVM_HOME)/src $(UVM_HOME)/src/uvm_pkg.sv
	vlog -sv +acc +define+UVM_NO_DPI +incdir+. +incdir+Source +incdir+UVM_component +incdir+$(UVM_HOME)/src +incdir+Depend Source/* tb_systolic.sv
	vsim -suppress 3009 -debugDB -classdebug -assertdebug work.tb_systolic +UVM_TESTNAME=test +UVM_VERBOSITY=UVM_MEDIUM +UVM_SEQUENCE_TRACE

clean :
	vdel -lib work -all

test :
	clean
