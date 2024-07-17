	.data

	.text	
	.align 2
	.globl main
	
main:
	li a7, 5
	ecall
	
	
	mv s0, a0
	
	jal fatorial
	
	li a7, 1
	mv a0, a1
	ecall
	
	li a7, 10
	ecall
	
fatorial:
	addi sp, sp, -8 #pegar o espaço na pilha
	sw ra, 0(sp) #emilhar a0
	sw a0, 4(sp) #empilhar ra
	
	beq a0, zero, retornar #se a0 for 0
	
	addi a0, a0, -1 #diminuir a0
	
	jal fatorial
	
	lw a0, 4(sp) #desempilhar a0
	
	mul a1, a1, a0 #a1 = a1 * a0
	
	j sai_fatorial
	
retornar:
	li a1, 1 #para a0 =0, o fatorial é 1
	
sai_fatorial:
	lw ra, 0(sp) #desempilhar ra
	addi sp, sp, 8 #liberar espaço da pilha
	jr ra #voltar por ra
