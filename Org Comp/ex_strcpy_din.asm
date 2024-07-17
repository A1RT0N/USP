	.data
	.align 0
str_src:.asciz "Hello!"

	.align 2

ptr: .word 
# Isso deixa com um align 0, pq vou mexer com string

	.text
	.align 2
	.globl main

main:

	li t3, 0 
# calcular o tamanho da str_src

	la t0, str_src


#ler o conteúdo da posição apontada por t0

# Fazendo do_while()

loop:
	
	lb t2, 0(t0)    
# t2 = str_src[0]

	addi t3, t3, 1

# Avança o ponteiro da string origem

	addi t0 ,t0, 1

	bne t2, zero, loop  
# Se o caracter lido não for fim de string, volta no loop

# FIM LOOP

	li a7, 9

	add a0, zero, t3  
# PRECISA DA QUANTIDADE DE BYTES PARA SEREM ALOCADOS PARA T3

	ecall


# PARTE MAIS IMPORTANTE

	la t4, ptr

	sw a0, 0(t4)  
# Endereço do primeiro byte do
# sbrk ta colocando no endedreço 

# ARRAY[t4] = a0

# Colocar em t0 o
# endereço da string origem

	la t0, str_src

	lw t1, 0(t4) 
	
# t1: endereço da string 
#destino na heap (t1 é o endereço da heap) 

	mv s0, t1 
# fiz isso pq vou andar com t1 e 
#vou precisar de seu inicial na ecall 


loopinho:
# do while  (não precisa dar free)

	lb t3, 0(t0)

	sb t3, 0(t1)

	addi t0, t0, 1
	addi t1, t1, 1

	bne t3, zero, loopinho


# printando string

	li a7, 4

	add a0, zero, s0

	ecall

	li a7, 10

	ecall








	








