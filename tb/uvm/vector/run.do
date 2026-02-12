################################################################################
# INITIALIZATION
################################################################################

transcript quietly
if {[file exist modelsim_lib]} { file delete -force modelsim_lib }
file mkdir modelsim_lib

################################################################################
# DIRECTORY VARIABLES
################################################################################

set rtl_dir       ../../../rtl/modules/vector
set agent_dir     ./agent
set env_dir       ./env
set test_dir      ./test
set top_dir       .
set top_name      tb_top
set sim_lib       vector_sim_lib
set rtl_lib       vector_rtl_lib

set uvm_test      lane_test
set uvm_verbosity UVM_MEDIUM

################################################################################
# COMPILE RTL
################################################################################

vlib modelsim_lib/$rtl_lib
vmap $rtl_lib modelsim_lib/$rtl_lib

vlog -sv -work $rtl_lib \
     +incdir+$rtl_dir \
     $rtl_dir/vector_if.sv \
     $rtl_dir/lane.sv \
     $rtl_dir/lane_sequencer.sv \
     $rtl_dir/lane_fu_pt.sv \
     $rtl_dir/valu.sv \
     $rtl_dir/vdiv.sv \
     $rtl_dir/sync_fifo.sv

################################################################################
# COMPILE VERIFICATION (UVM)
################################################################################

vlib modelsim_lib/$sim_lib
vmap $sim_lib modelsim_lib/$sim_lib

vlog -sv -work $sim_lib \
     +incdir+$agent_dir+$env_dir+$test_dir \
     vector_pkg.sv \
     tb_top.sv

################################################################################
# SIMULATE
################################################################################

vsim -voptargs=+acc \
     -L $rtl_lib \
     -lib $sim_lib \
     $top_name \
     +UVM_TESTNAME=$uvm_test \
     +UVM_VERBOSITY=$uvm_verbosity \
     -t 1ns

run -all
