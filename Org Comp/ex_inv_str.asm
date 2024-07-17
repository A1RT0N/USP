# Codifique  em  Assembly  RISC-V  um  
#programa  que  lê  
# uma  string  fornecida  pelo  usuário,  
#inverte  e  imprime  ela 
# invertida. 

    .data
    .align 0
palavra: .space 100

    .text
    .align 2
    .globl main

main:
    la s0, palavra # ENDEREÇO DE PALAVRA

    add a0, zero, s0
    addi a1, zero, 100

    addi a7, zero, 8
    ecall

    li s1, 0 # TAMANHO DA PALAVRA

    la t0, palavra


find_lengh:

    lb t1 , 0(t0) 

    beq t1, zero, antes_inverter

    addi s1, s1, 1
    addi t0, t0, 1

    j find_lengh



antes_inverter:

    la t0, palavra 
    # t0 é o endereço do primeiro caracter

    add t2, s1, t0 
    # t2 é o endereço do último caracter

    addi t2, t2 -1 
    # desconsidera o \n

    
inverter:

    # swap do primeiro com o último

    lb s3, 0(t0) 
    
    lb s4, 0(t2)

    sb s3, 0(t2)

    sb s4, 0(t0)

    addi t0, t0, 1

    addi t2, t2, -1

    beq t0, t2, imprimir

    j inverter


imprimir:


    add a0, zero, s0

    addi a7, zero, 4

    ecall

    addi a7, zero, 10

    ecall

    




