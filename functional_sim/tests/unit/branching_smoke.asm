start:
addi.s  $1, $0, 3
addi.s  $2, $0, 0

loop:
addi.s  $2, $2, 1
subi.s  $1, $1, 1
bne.s   $1, $0, loop
beq.s   $2, $0, fail, 5
halt.s

fail:
addi.s  $3, $0, 99
halt.s
