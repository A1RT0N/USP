# 5) Codifique em Assembly RISC-V um programa 
#que implemente a funcionalidade da função strcat(). 


    .data
    .aling 0

str1: .asciz "Meu amor é muito "
str2: .asciz "lindo!"

ptr_dest: .word  
# mexer com alocação dinamica é guardar 
# em ponteiro o endereço de sbrk

    .text
    .align 2
    .globl main

main:

    la t0, str1

    la t1, str2

    li s0, 0 # s0 é o valor da primeira string

    li s1, 0


loop_str1:

    lb t2, 0(t0)

    addi s0, s0, 1

    addi t0, t0, 1

    bne t2, zero, loop_str1

loop_str2:

    lb t2, 0(t0)

    addi s1, s1, 1

    addi t0, t0, 1

    bne t2, zero, loop_str2

antes_loop:

    add t0, s0, s1

    addi a7, zero, 9

    mv a0 ,t0

    ecall

    la t3, ptr_dest

    sw a0, 0(t3)

    lw t4, 0(t3)   
    # t4 é o endereço base da heap (que é a0)


    la t0, str1

    la t1, str2


loopinho_str1:

    lb t3, 0(t0)

    beq t3, zero loopinho_str2

    sb t3, 0(t4)

    addi t0, t0, 1

    addi t4, t4, 1

    bne t3, zero, loopinho_str1


loopinho_str2:

    lb t3, 0(t1)

    sb t3, 0(t4)

    addi t1, t1, 1

    addi t4, t4, 1

    bne t3, zero, loopinho_str2


fim:

    li a7, 4

    la t3, ptr_dest

    lw a0, 0(t3)

    ecall

    li a7, 10

    ecall












