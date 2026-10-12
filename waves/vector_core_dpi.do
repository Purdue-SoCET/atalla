onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -expand -group CLK_RST /vector_core_dpi_tb/CLK
add wave -noupdate -expand -group CLK_RST /vector_core_dpi_tb/nRST
add wave -noupdate -expand -group CLK_RST -radix unsigned -childformat {{{/vector_core_dpi_tb/cycle_count[31]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[30]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[29]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[28]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[27]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[26]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[25]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[24]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[23]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[22]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[21]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[20]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[19]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[18]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[17]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[16]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[15]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[14]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[13]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[12]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[11]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[10]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[9]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[8]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[7]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[6]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[5]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[4]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[3]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[2]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[1]} -radix unsigned} {{/vector_core_dpi_tb/cycle_count[0]} -radix unsigned}} -subitemconfig {{/vector_core_dpi_tb/cycle_count[31]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[30]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[29]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[28]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[27]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[26]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[25]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[24]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[23]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[22]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[21]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[20]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[19]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[18]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[17]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[16]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[15]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[14]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[13]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[12]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[11]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[10]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[9]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[8]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[7]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[6]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[5]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[4]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[3]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[2]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[1]} {-radix unsigned} {/vector_core_dpi_tb/cycle_count[0]} {-radix unsigned}} /vector_core_dpi_tb/cycle_count
add wave -noupdate -expand -group LANES_IN /vector_core_dpi_tb/vif/lanes_in
add wave -noupdate -expand -group LANES_OUT /vector_core_dpi_tb/vif/lanes_out
add wave -noupdate -expand -group READY_STATUS /vector_core_dpi_tb/vif/unit_ready_signals
add wave -noupdate -expand -group READY_STATUS /vector_core_dpi_tb/vif/wb_ready_signals
add wave -noupdate -expand -group GSAU_IN /vector_core_dpi_tb/vif/gsau_in
add wave -noupdate -expand -group GSAU_OUT /vector_core_dpi_tb/vif/gsau_out
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/veg_vdata1
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/veg_vdata2
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/sb_ready_out
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/sb_vdst
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/sb_valid_in
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/sb_weight
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/wb_psum
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/wb_wbdst
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/wb_valid_out
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/wb_ready_in
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/sa_array_in
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/sa_array_in_partials
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/sa_input_en
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/sa_weight_en
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/sa_partial_en
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/sa_ready_out
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/sa_array_output
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/sa_valid_in
add wave -noupdate -expand -group GSAU_SA /vector_core_dpi_tb/gsauif/sa_ready_in
add wave -noupdate -expand -group VLSU_IN /vector_core_dpi_tb/vif/vlsu_in
add wave -noupdate -expand -group VLSU_OUT /vector_core_dpi_tb/vif/vlsu_out
add wave -noupdate -expand -group SCRATCHPAD /vector_core_dpi_tb/sif/vec_req
add wave -noupdate -expand -group SCRATCHPAD /vector_core_dpi_tb/sif/vec_res
add wave -noupdate -expand -group SCRATCHPAD /vector_core_dpi_tb/sif/fe_vec_stall
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {84520 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 300
configure wave -valuecolwidth 250
configure wave -justifyvalue left
configure wave -signalnamewidth 1
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ps} {200 ns}
