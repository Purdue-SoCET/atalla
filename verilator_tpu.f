// --lint-only
--binary
// --trace
--timing
-f rtl/filelists/TPU_top.f
-Itb/unit/systolic_array
tb/unit/systolic_array/TPU_top_tb.sv
-Wno-WIDTHTRUNC
-Wno-WIDTHEXPAND
-Wno-MODDUP
-Wno-TIMESCALEMOD
--top TPU_top_tb
-threads 6
-j 48
