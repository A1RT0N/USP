	.data
	.align 0
str_src:.asciz "Hello!"
str_des: .space 7 # Isso deixa com um align 0, pq vou mexer com string

	.text
	.align 2
	.globl main

main:,
	la t0, str_src
	la t1, str_des

	#ler o conteúdo da posição apontada por t0

	lb t2, 0(t0)  # t2 = str_src[0]

	# fazendo um for

	sb t2, 0(t1) # array[0] = t2 


loop:


	beq t2, zero, fim 
# é diferente de de 0  => byte: 0000 (não é o ASCII '0' -> que é 60 e tantos)

	addi t0, t0, 1 

	addi t1, t1, 1 

	lb t2, 0(t0) # t2 = array[0+1]

	sb t2, 0(t1) # array[0] = t2 

	j loop

fim:	

	li a7, 4

	la a0, str_des

	ecall

	li a7, 10

	ecall







	

