    .data
array:	.word 7, 5, 2, 1, 1, 3, 4
	.text
	.align 2
	.globl main

main:
	


li t0, 0 # i
li t1, 6 # j
li s11, 6 # max -1
la s2, array # endereço base do array
li s3, 4 # armazena o valor de 4 bytes para ser usado nas operações --> não precisa delem dá pra usar o slli


li s5, 0
li s6, 28


loop_j:

    # PEGANDO OS VALORES DA MATRIZ!

    addi t3, t1, -1  # t3 é o índice j-1
    mul t3, t3, s3  # byte offset
    add t4, s2, t3 	# t4 agora armazena o valor do índice j-1 ---> endereço base mais índice
    
    lw s0, 0(t4)  # s0 = array[j-1]
    
    # s7 é o índice j ----> não é bom reciclar pq vc vai precisar do endereço de memória depois (tanto o s7 quanto o t4)
    mul s7, t1, s3 
    add t5 , s2, s7
    
    lw s1, 0(t5) # s1 = array[j]

    
    ble s0, s1, fim_loop_interno

    # FAZENDO O SWAP! O COMENTADO ESTÁ ERRADO

    # add s4, zero, s0 # s4 vai ser o registrador aux que vai receber j-1

	# add s0, zero, s1# j-1 recebe j

	# add s1, zero, s4 # j recebe aux

    sw s0, 0(t5)   # array[t5] = s0  --> array[j] = array[j-1]

    sw s1, 0(t4)   # array[t4] = s1  --> array[j-1] = array[j](anterior)


    ### SOBRE O SW(CPU -> RAM) e o LW (RAM->CPU)
    # lw t2, 0(t4)  # t2 = array[j-1]
    # lw t3, 0(t5)  # t3 = array[j]
    # sw t3, 0(t4)  # array[j-1] = t3
    # sw t2, 0(t5)  # array[j] = t2



fim_loop_interno:

    # PROCEDIMENTO DO INICIO FOR DO J

    addi t1, t1, -1 # j = j-1

    beq t1, t0, loop_i  # CONDIÇÃO DE PARADA: j == i

    j loop_j


loop_i:

    addi t0, t0, 1

    beq t0, s11, impressao

    addi t1, zero, 6

    # Problema que tinha principal: quando aqui o t0(i) já é 6

    beq t1, t0, loop_i

    j loop_j



impressao:

	beq s5, s6, fim
	
	add s10, s2, s5
	
	
	addi a7, zero, 1
	lw a0, 0(s10)
	ecall

    addi s5, s5, 4

	j impressao




fim:

	addi a7, zero, 10
	ecall



# PROBLEMAS: CONDIÇÃO DE PARADA: QUANDO j == i e não  quando j == i+1
# Problema no loop_i 
# Problema besta na impressão