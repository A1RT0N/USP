# Codifique em Assembly RISC-V um programa que soma os valores de um vetor de 
# inteiros de tamanho definido no próprio programa.
# Os dados do vetor também podem já estar definidos no código.


    .data
array:  .word 4, 2, 6, 11, 3, 6, 8, 7, 17, 20
    .text
    .align 1
    .globl main

main:

    la s10, array
    
    li s0, 0 # s0 será nosso contador

    li t0, 0 # index

    li s1, 40 # s1 será o tamanho do vetor


loop:

    beq t0,s1, imprimir

    add s2, t0, s10

    lw s3, 0(s2) 

    add s0, s0, s3

    addi t0, t0, 4

    j loop


imprimir:

    add a0, zero, s0

    addi a7, zero, 1

    ecall

    addi a7, zero, 10
    
    ecall



    
# Problema desse: antes eu multiplicava (shiftava o index), mas a técnica de já somar de 4 em 4 bytes (index) salva demais, até pq economiza operação
