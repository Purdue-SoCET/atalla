# vlsu_tb.do - QuestaSim waveform setup for dual-channel VLSU testbench

add wave -divider "Clock / Reset"
add wave sim:/vlsu_tb/CLK
add wave sim:/vlsu_tb/nRST

add wave -divider "===== Channel 0 ====="

add wave -divider "CH0 Scheduler"
add wave sim:/vlsu_tb/vif/sched_req(0)
add wave sim:/vlsu_tb/vif/sched_res(0)

add wave -divider "CH0 VRF Store"
add wave sim:/vlsu_tb/vif/vrf_store(0)

add wave -divider "CH0 Scratchpad"
add wave sim:/vlsu_tb/sif/vec_req(0)
add wave sim:/vlsu_tb/sif/fe_vec_stall(0)
add wave sim:/vlsu_tb/sif/vec_res(0)

add wave -divider "CH0 Writeback"
add wave sim:/vlsu_tb/vif/wb_out(0)
add wave sim:/vlsu_tb/vif/wb_ready(0)

add wave -divider "CH0 Status"
add wave sim:/vlsu_tb/vif/status(0)

add wave -divider "CH0 DUT Internals"
add wave sim:/vlsu_tb/DUT0/lq_wr_en
add wave sim:/vlsu_tb/DUT0/lq_shift
add wave sim:/vlsu_tb/DUT0/lq_empty
add wave sim:/vlsu_tb/DUT0/lq_full
add wave sim:/vlsu_tb/DUT0/rq_wr_en
add wave sim:/vlsu_tb/DUT0/rq_shift
add wave sim:/vlsu_tb/DUT0/rq_empty
add wave sim:/vlsu_tb/DUT0/rq_full

add wave -divider "===== Channel 1 ====="

add wave -divider "CH1 Scheduler"
add wave sim:/vlsu_tb/vif/sched_req(1)
add wave sim:/vlsu_tb/vif/sched_res(1)

add wave -divider "CH1 VRF Store"
add wave sim:/vlsu_tb/vif/vrf_store(1)

add wave -divider "CH1 Scratchpad"
add wave sim:/vlsu_tb/sif/vec_req(1)
add wave sim:/vlsu_tb/sif/fe_vec_stall(1)
add wave sim:/vlsu_tb/sif/vec_res(1)

add wave -divider "CH1 Writeback"
add wave sim:/vlsu_tb/vif/wb_out(1)
add wave sim:/vlsu_tb/vif/wb_ready(1)

add wave -divider "CH1 Status"
add wave sim:/vlsu_tb/vif/status(1)

add wave -divider "CH1 DUT Internals"
add wave sim:/vlsu_tb/DUT1/lq_wr_en
add wave sim:/vlsu_tb/DUT1/lq_shift
add wave sim:/vlsu_tb/DUT1/lq_empty
add wave sim:/vlsu_tb/DUT1/lq_full
add wave sim:/vlsu_tb/DUT1/rq_wr_en
add wave sim:/vlsu_tb/DUT1/rq_shift
add wave sim:/vlsu_tb/DUT1/rq_empty
add wave sim:/vlsu_tb/DUT1/rq_full

add wave -divider "Test"
add wave -radix unsigned sim:/vlsu_tb/test_num
add wave -radix unsigned sim:/vlsu_tb/errors
