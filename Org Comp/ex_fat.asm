	.data
	.align 0
string1:	.asciz "Entre com um número: "
string2:	.asciz "O fatorial de "
string3: 	.asciz " eh "
	.text
	.align 2
	.globl main


main:
	li a7, 4
	la a0, string1	# o la (load adress) não existe de fato
	ecall


	li a7, 5
	ecall

	add s0, zero, a0	

    add s1, zero, s0
# equivalente a move s0, a0 -> move é pseudoinstrução assim como li e la

	addi t0, zero, 1 # contador

loop:   # principal do código
	beq s0, zero, sair_loop
	mul t0, t0, s0  # t0 = t0*s0
	addi s0, s0, -1
	j loop

sair_loop:

	li a7, 4
	la a0, string2
	ecall

	li a7, 1
	add a0, zero, s1
	ecall
	
	li a7, 4
	la a0, string3
	ecall

	li a7, 1
	add a0, zero, t0
	ecall

	li a7, 10
	ecall
	
