lw $v0, 0x0($zero)
lw $v1, 0x4($zero)
lw $a0, 0x8($zero)
nop
nop
add $a1, $v0, $v1
sub $a2, $a0, $v0 
and $a3, $v1, $v0
lw $t3, 0x0($zero)
lw $t3, 0x0($zero)
lw $t3, 0x0($zero)
or $t0,$a0, $v0
slt $t1,$a0, $v0
beq $zero, $zero, start
add $t2,$t0, $t1
lw $t3, 0x0($zero)
lw $t3, 0x0($zero)
lw $t3, 0x0($zero)
lw $t3, 0x0($zero)
lw $t3, 0x0($zero)
lw $t3, 0x0($zero)
lw $t3, 0x0($zero)
lw $t3, 0x0($zero)
start:
lw $t4, 0x0($zero)
lw $t4, 0x0($zero)
lw $t4, 0x0($zero)
lw $t4, 0x0($zero)
lw $t4, 0x0($zero)
lw $t4, 0x0($zero)
lw $t4, 0x0($zero)
lw $t4, 0x0($zero)
lw $t4, 0x0($zero)
lw $t4, 0x0($zero)
#start:
#lw $t0, 0x0($zero)
#lw $t1, 0x4($v0)
#lw $t2, 0x8($v1)
#lw $t3, 0xc($a0)
#lw $t4, 0x10($a1)
#lw $t5, 0x14($a2)
#add $t0, $zero, 0xff 
#sw $t0, 0x100($a3)
#add $t0, $v1, 0xffff
#sw $t0, 0x100($a3)
#add $t0, $t1, $t4
#sw $t0, 0x100($a3)
#add $t0, $t1, $t5
#sw $t0, 0x100($a3)
#add $t0, $t1, $t6
#sw $t0, 0x100($a3)
#add $t0, $t1, $t7
#sw $t0, 0x100($a3)
#add $t0, $t1, $t8
#sw $t0, 0x100($a3)
#add $t0, $t1, $t9
#j start
#lw $t0, 0x20($t1)
#sw $t0, 0x1($t1)	
#lw $t0, 0x20($t2)
#sw $t0, 0x2($t1)
#lw $t0, 0x20($t3)
#sw $t0, 0x3($t1)
#lw $t0, 0x10($t1)
#sw $t0, 0x4($t1)
#lw $t0, 0x40($t1)
#sw $t0, 0x5($t1)
#slt $t4, $t1, $t2
#beq $t0, $t2, start
#slt $t4, $t1, $t2
#beq $t0, $t2, start
#slt $t5, $t3, $t4
#beq $t0, $t2, start
#slt $t5, $t4, $t3

