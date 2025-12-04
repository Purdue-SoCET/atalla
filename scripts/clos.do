onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /clos_tb/DUT/clk
add wave -noupdate /clos_tb/DUT/n_rst
add wave -noupdate -radix unsigned -childformat {{{/clos_tb/DUT/in[31]} -radix unsigned} {{/clos_tb/DUT/in[30]} -radix unsigned} {{/clos_tb/DUT/in[29]} -radix unsigned} {{/clos_tb/DUT/in[28]} -radix unsigned} {{/clos_tb/DUT/in[27]} -radix unsigned} {{/clos_tb/DUT/in[26]} -radix unsigned} {{/clos_tb/DUT/in[25]} -radix unsigned} {{/clos_tb/DUT/in[24]} -radix unsigned} {{/clos_tb/DUT/in[23]} -radix unsigned} {{/clos_tb/DUT/in[22]} -radix unsigned} {{/clos_tb/DUT/in[21]} -radix unsigned} {{/clos_tb/DUT/in[20]} -radix unsigned} {{/clos_tb/DUT/in[19]} -radix unsigned} {{/clos_tb/DUT/in[18]} -radix unsigned} {{/clos_tb/DUT/in[17]} -radix unsigned} {{/clos_tb/DUT/in[16]} -radix unsigned} {{/clos_tb/DUT/in[15]} -radix unsigned} {{/clos_tb/DUT/in[14]} -radix unsigned} {{/clos_tb/DUT/in[13]} -radix unsigned} {{/clos_tb/DUT/in[12]} -radix unsigned} {{/clos_tb/DUT/in[11]} -radix unsigned} {{/clos_tb/DUT/in[10]} -radix unsigned} {{/clos_tb/DUT/in[9]} -radix unsigned} {{/clos_tb/DUT/in[8]} -radix unsigned} {{/clos_tb/DUT/in[7]} -radix unsigned} {{/clos_tb/DUT/in[6]} -radix unsigned} {{/clos_tb/DUT/in[5]} -radix unsigned} {{/clos_tb/DUT/in[4]} -radix unsigned} {{/clos_tb/DUT/in[3]} -radix unsigned} {{/clos_tb/DUT/in[2]} -radix unsigned} {{/clos_tb/DUT/in[1]} -radix unsigned} {{/clos_tb/DUT/in[0]} -radix unsigned}} -subitemconfig {{/clos_tb/DUT/in[31]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[30]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[29]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[28]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[27]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[26]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[25]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[24]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[23]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[22]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[21]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[20]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[19]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[18]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[17]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[16]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[15]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[14]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[13]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[12]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[11]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[10]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[9]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[8]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[7]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[6]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[5]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[4]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[3]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[2]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[1]} {-height 16 -radix unsigned} {/clos_tb/DUT/in[0]} {-height 16 -radix unsigned}} /clos_tb/DUT/in
add wave -noupdate -radix unsigned /clos_tb/DUT/perm
add wave -noupdate -radix unsigned /clos_tb/DUT/out
add wave -noupdate -radix unsigned -childformat {{{/clos_tb/DUT/input_module[7]} -radix decimal} {{/clos_tb/DUT/input_module[6]} -radix decimal} {{/clos_tb/DUT/input_module[5]} -radix decimal} {{/clos_tb/DUT/input_module[4]} -radix decimal} {{/clos_tb/DUT/input_module[3]} -radix decimal} {{/clos_tb/DUT/input_module[2]} -radix decimal} {{/clos_tb/DUT/input_module[1]} -radix decimal} {{/clos_tb/DUT/input_module[0]} -radix decimal}} -subitemconfig {{/clos_tb/DUT/input_module[7]} {-height 16 -radix decimal} {/clos_tb/DUT/input_module[6]} {-height 16 -radix decimal} {/clos_tb/DUT/input_module[5]} {-height 16 -radix decimal} {/clos_tb/DUT/input_module[4]} {-height 16 -radix decimal} {/clos_tb/DUT/input_module[3]} {-height 16 -radix decimal} {/clos_tb/DUT/input_module[2]} {-height 16 -radix decimal} {/clos_tb/DUT/input_module[1]} {-height 16 -radix decimal} {/clos_tb/DUT/input_module[0]} {-height 16 -radix decimal}} /clos_tb/DUT/input_module
add wave -noupdate -radix unsigned -childformat {{{/clos_tb/DUT/center_module[3]} -radix unsigned} {{/clos_tb/DUT/center_module[2]} -radix unsigned} {{/clos_tb/DUT/center_module[1]} -radix unsigned} {{/clos_tb/DUT/center_module[0]} -radix unsigned}} -subitemconfig {{/clos_tb/DUT/center_module[3]} {-radix unsigned} {/clos_tb/DUT/center_module[2]} {-radix unsigned} {/clos_tb/DUT/center_module[1]} {-radix unsigned} {/clos_tb/DUT/center_module[0]} {-radix unsigned}} /clos_tb/DUT/center_module
add wave -noupdate -radix unsigned /clos_tb/DUT/output_module
add wave -noupdate -radix unsigned /clos_tb/DUT/n_center_module
add wave -noupdate -radix unsigned /clos_tb/DUT/n_output_module
add wave -noupdate -radix unsigned -childformat {{{/clos_tb/DUT/input_perm[7]} -radix unsigned} {{/clos_tb/DUT/input_perm[6]} -radix unsigned} {{/clos_tb/DUT/input_perm[5]} -radix unsigned} {{/clos_tb/DUT/input_perm[4]} -radix unsigned} {{/clos_tb/DUT/input_perm[3]} -radix unsigned} {{/clos_tb/DUT/input_perm[2]} -radix unsigned} {{/clos_tb/DUT/input_perm[1]} -radix unsigned} {{/clos_tb/DUT/input_perm[0]} -radix unsigned}} -subitemconfig {{/clos_tb/DUT/input_perm[7]} {-radix unsigned} {/clos_tb/DUT/input_perm[6]} {-radix unsigned} {/clos_tb/DUT/input_perm[5]} {-radix unsigned} {/clos_tb/DUT/input_perm[4]} {-radix unsigned} {/clos_tb/DUT/input_perm[3]} {-radix unsigned} {/clos_tb/DUT/input_perm[2]} {-radix unsigned} {/clos_tb/DUT/input_perm[1]} {-radix unsigned} {/clos_tb/DUT/input_perm[0]} {-radix unsigned}} /clos_tb/DUT/input_perm
add wave -noupdate -radix unsigned /clos_tb/DUT/center_perm
add wave -noupdate -radix unsigned /clos_tb/DUT/output_perm
add wave -noupdate -radix unsigned /clos_tb/DUT/n_center_perm
add wave -noupdate -radix unsigned /clos_tb/DUT/n_output_perm
add wave -noupdate -radix unsigned /clos_tb/DUT/lsb
add wave -noupdate -radix unsigned /clos_tb/DUT/num_counter
add wave -noupdate -radix unsigned /clos_tb/DUT/om_dest
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {5 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
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
WaveRestoreZoom {0 ns} {64 ns}
