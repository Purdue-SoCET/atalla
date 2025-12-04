onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -expand /vreduction_tb/vruif/in
add wave -noupdate -expand -subitemconfig {/vreduction_tb/vruif/out.vector_output -expand} /vreduction_tb/vruif/out
add wave -noupdate -radix unsigned /vreduction_tb/test_count
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {373322 ps} 0}
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
configure wave -timelineunits ps
update
WaveRestoreZoom {118371 ps} {513025 ps}
