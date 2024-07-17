    .data
    . align 2

vetor: .word 8, 1, 3, 4, 2, 9, 3

tamanho_vetor: .word 7

    .text
    .aling 2
    .globl main

main:

    la t0, tamanho_vetor

    lw s0, 0(t0)  # s0 é o tamanho do vetor



    li t2, 0 # int i

    li t1, 0 # temporário que compara elemento do vetor

    li s1, 0 # retorno da função 

    la t0, vetor


loop: 

    beq t2, s0, impressao

    lw t1, 0(t0)

    ## if

    bgt t1, s1, atualiza_s1

    addi t0, t0, 4

    addi t2, t2, 1

    j loop

    



atualiza_s1:

    mv s1, t1   
    
    addi t0, t0, 4

    addi t2,t2, 1

    j loop


impressao: 


    li a7, 1

    mv a0, s1

    ecall

    li a7, 10

    ecall




