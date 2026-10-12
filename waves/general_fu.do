onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /general_fu_tb/CLK
add wave -noupdate /general_fu_tb/nRST
add wave -noupdate -expand -group {DUT IO} -expand -subitemconfig {/general_fu_tb/fuif/in.ports -expand {/general_fu_tb/fuif/in.ports[0]} -expand} /general_fu_tb/fuif/in
add wave -noupdate -expand -group {DUT IO} /general_fu_tb/fuif/out
add wave -noupdate -expand -group {Seq IO} /general_fu_tb/DUT/lsif/in
add wave -noupdate -expand -group {Seq IO} /general_fu_tb/DUT/lsif/out
add wave -noupdate -expand -group Internal /general_fu_tb/DUT/vd_r
add wave -noupdate -expand -group Internal /general_fu_tb/DUT/vd_n
add wave -noupdate -expand -group mask_fifo /general_fu_tb/DUT/mask_fifo/wr_en
add wave -noupdate -expand -group mask_fifo /general_fu_tb/DUT/mask_fifo/rd_en
add wave -noupdate -expand -group mask_fifo /general_fu_tb/DUT/mask_fifo/din
add wave -noupdate -expand -group mask_fifo /general_fu_tb/DUT/mask_fifo/dout
add wave -noupdate -expand -group mask_fifo /general_fu_tb/DUT/mask_fifo/count
add wave -noupdate -expand -group mask_fifo /general_fu_tb/DUT/mask_fifo/wptr
add wave -noupdate -expand -group mask_fifo /general_fu_tb/DUT/mask_fifo/rptr
add wave -noupdate -expand -group mask_fifo /general_fu_tb/DUT/mask_fifo/full
add wave -noupdate -expand -group mask_fifo /general_fu_tb/DUT/mask_fifo/empty
add wave -noupdate -expand -group {vd fifo} /general_fu_tb/DUT/vd_fifo/wr_en
add wave -noupdate -expand -group {vd fifo} /general_fu_tb/DUT/vd_fifo/rd_en
add wave -noupdate -expand -group {vd fifo} /general_fu_tb/DUT/vd_fifo/din
add wave -noupdate -expand -group {vd fifo} /general_fu_tb/DUT/vd_fifo/dout
add wave -noupdate -expand -group {vd fifo} /general_fu_tb/DUT/vd_fifo/count
add wave -noupdate -expand -group {vd fifo} /general_fu_tb/DUT/vd_fifo/wptr
add wave -noupdate -expand -group {vd fifo} /general_fu_tb/DUT/vd_fifo/rptr
add wave -noupdate -expand -group {vd fifo} /general_fu_tb/DUT/vd_fifo/full
add wave -noupdate -expand -group {vd fifo} /general_fu_tb/DUT/vd_fifo/empty
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {49233 ps} 0}
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
WaveRestoreZoom {0 ps} {362250 ps}
