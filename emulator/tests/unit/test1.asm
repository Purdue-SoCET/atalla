start:
instruct_tests:
    addi.s $2, $2, 32
    sw.s $1, 4($2)
    sw.s $8, 0($2)
    addi.s $8, $2, 8
    addi.s $2, $2, 16

instruct_tests_block0:
    addi.s $9, $9, 4
    addi.s $10, $9, 0
    nop.s
    nop.s
    andi.s $9, $11, 255
    xor.s $9, $10, $9
    xori.s $9, $9, 0
    addi.s $9, $9, 0
    lui.s $12, 0
    mul.s $11, $12, $11
    add.s $11, $13, $11
    sw.s $9, 0($11)
    addi.s $11, $9, 1
    addi.s $14, $11, 0
    nop.s
    nop.s
    addi.s $13, $8, 16
    lui.s $11, 4
    addi.s $13, $8, 16
    lui.s $12, 1
    lui.s $11, 4
    mul.s $11, $12, $11
    add.s $11, $13, $11
    sw.s $14, 0($11)
    bge.s $14, $10, instruct_tests_block3
    nop.s
    nop.s
    nop.s

instruct_tests_block3:
    lui.s $10, 2
    sub.s $10, $10, $14
    addi.s $10, $10, 0
    nop.s
    addi.s $11, $10, 0
    nop.s
    nop.s
    nop.s

instruct_tests_block4:
    addi.s $11, $14, 0
    nop.s
    nop.s
    nop.s
    addi.s $11, $11, 0
    nop.s
    nop.s
    nop.s
    beq.s $14, $10, instruct_tests_block6
    nop.s
    nop.s
    nop.s

instruct_tests_block2:
    addi.s $11, $11, 0
    nop.s
    nop.s
    nop.s
    add.s $9, $9, $11
    addi.s $9, $9, 0
    nop.s
    nop.s

instruct_tests_block6:
    addi.s $10, $9, 4
    addi.s $10, $10, 0
    nop.s
    nop.s
    addi.s $11, $10, 0
    nop.s
    nop.s
    nop.s
    addi.s $2, $2, 16
    lw.s $1, 4($2)
    lw.s $8, 0($2)
    addi.s $2, $2, 32
    halt.s
    halt.s
    
