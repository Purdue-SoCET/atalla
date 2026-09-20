# ========================
# PACKAGES
# ========================

/home/asicfab/a/djaideep/atalla_vectorCore/rtl/include/common/arithmetic/divider/div_if.vh
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/include/vector/vector_pkg.vh
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/include/memory/scratchpad/scpad_pkg.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/include/common/xbar/xbar_pkg.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/include/vector/lane_FUs/reduction_FU_if.vh

# ========================
# PARAM / HEADER FILES
# ========================
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/include/memory/scratchpad/scpad_params.svh
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/include/common/xbar/xbar_params.svh

# ========================
# INTERFACES
# ========================

/home/asicfab/a/djaideep/atalla_vectorCore/rtl/include/vector/vector_if.vh
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/include/scheduler/v_wb_arbiter_if.vh
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/include/memory/scratchpad/scpad_if.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/include/common/xbar/xbar_if.vh

# ========================
# MODULES
# ========================
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/common/arithmetic/multipliers/fa.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/common/arithmetic/multipliers/ha.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/common/arithmetic/adders/left_shift_add_bf16.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/common/arithmetic/adders/adder_8b.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/common/arithmetic/multipliers/wallacetree_8b.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/common/arithmetic/adders/add_bf16.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/common/arithmetic/adders/addsub_bf16.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/common/arithmetic/multipliers/mul_bf16.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/slicer.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/common/arithmetic/sqrt/sqrt_bf16.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/common/arithmetic/multipliers/mul_bf16_fu.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/lane_FUs/alu_FU.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/lane_FUs/div_FU.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/lane_FUs/exp_FU.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/lane_FUs/lane_unit_fifo.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/lane_FUs/mul_FU.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/lane_FUs/reduction_FU.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/lane_FUs/sqrt_FU.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/valu.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/vreduction.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/vreduction_alu.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/reduction_tree.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/gsau_control_unit.sv

/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/lane.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/lane_fu_pt.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/lane_sequencer.sv

/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/result_collector.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/result_collector_counter.sv

/home/asicfab/a/djaideep/atalla_vectorCore/rtl/include/vector/vlsu_if.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/sync_fifo.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/vlsu.sv

/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/vector/vector_datapath.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/scheduler/v_wb_arbiter.sv
/home/asicfab/a/djaideep/atalla_vectorCore/rtl/modules/scheduler/vector_execute_wb_top.sv
+incdir+./rtl/include
+incdir+./rtl/include/common/xbar
+incdir+./rtl/include/memory/scratchpad
+incdir+./rtl/modules
+incdir+./rtl/modules/common
+incdir+./rtl/modules/common/general
rtl/include/common/xbar/xbar_pkg.sv
rtl/include/common/xbar/xbar_if.sv
rtl/modules/common/general/sync_fifo.sv
rtl/include/memory/scratchpad/scpad_pkg.sv
rtl/include/memory/scratchpad/scpad_if.sv
rtl/modules/memory/scratchpad/wxbar.sv
rtl/modules/memory/scratchpad/rxbar.sv
rtl/modules/memory/scratchpad/head.sv
rtl/modules/memory/scratchpad/body.sv
rtl/modules/memory/scratchpad/tail.sv
rtl/modules/memory/scratchpad/dram_request_queue.sv
rtl/modules/memory/scratchpad/dram_write_latch.sv
rtl/modules/memory/scratchpad/sram_write_latch.sv
rtl/modules/memory/scratchpad/scpad_cntrl.sv
rtl/modules/memory/scratchpad/backend.sv
tb/unit/memory/scratchpad/wxbar.sv
tb/unit/memory/scratchpad/rxbar.sv
tb/unit/memory/scratchpad/head.sv
tb/unit/memory/scratchpad/body.sv
tb/unit/memory/scratchpad/tail.sv
tb/unit/memory/scratchpad/spad_cntrl.sv
tb/unit/memory/scratchpad/frontend.sv
tb/unit/memory/scratchpad/backend_tb.sv
