onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /icache_tb/PROG/CLK
add wave -noupdate /icache_tb/PROG/nrst
add wave -noupdate /icache_tb/PROG/test_num
add wave -noupdate -group dcif /icache_tb/dcif/halt
add wave -noupdate -group dcif /icache_tb/dcif/ihit
add wave -noupdate -group dcif /icache_tb/dcif/imemREN
add wave -noupdate -group dcif /icache_tb/dcif/imemload
add wave -noupdate -group dcif /icache_tb/dcif/imemaddr
add wave -noupdate -group dcif /icache_tb/dcif/dhit
add wave -noupdate -group dcif /icache_tb/dcif/datomic
add wave -noupdate -group dcif /icache_tb/dcif/dmemREN
add wave -noupdate -group dcif /icache_tb/dcif/dmemWEN
add wave -noupdate -group dcif /icache_tb/dcif/flushed
add wave -noupdate -group dcif /icache_tb/dcif/dmemload
add wave -noupdate -group dcif /icache_tb/dcif/dmemstore
add wave -noupdate -group dcif /icache_tb/dcif/dmemaddr
add wave -noupdate -group cif0 /icache_tb/cif0/iwait
add wave -noupdate -group cif0 /icache_tb/cif0/dwait
add wave -noupdate -group cif0 /icache_tb/cif0/iREN
add wave -noupdate -group cif0 /icache_tb/cif0/dREN
add wave -noupdate -group cif0 /icache_tb/cif0/dWEN
add wave -noupdate -group cif0 /icache_tb/cif0/iload
add wave -noupdate -group cif0 /icache_tb/cif0/dload
add wave -noupdate -group cif0 /icache_tb/cif0/dstore
add wave -noupdate -group cif0 /icache_tb/cif0/iaddr
add wave -noupdate -group cif0 /icache_tb/cif0/daddr
add wave -noupdate -group cif0 /icache_tb/cif0/ccwait
add wave -noupdate -group cif0 /icache_tb/cif0/ccinv
add wave -noupdate -group cif0 /icache_tb/cif0/ccwrite
add wave -noupdate -group cif0 /icache_tb/cif0/cctrans
add wave -noupdate -group cif0 /icache_tb/cif0/ccsnoopaddr
add wave -noupdate -group icache /icache_tb/DUT_icache/icache_format
add wave -noupdate -group icache /icache_tb/DUT_icache/icache
add wave -noupdate -group icache /icache_tb/DUT_icache/nxt_icache
add wave -noupdate -group icache /icache_tb/DUT_icache/icache_state
add wave -noupdate -group icache /icache_tb/DUT_icache/nxt_icache_state
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {333 ns} 0}
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
WaveRestoreZoom {0 ns} {2352 ns}
