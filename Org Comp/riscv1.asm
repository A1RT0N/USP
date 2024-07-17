    .data
array:	.word 7, 5, 2, 1, 1, 3, 4
MAX:    .word 7


    .text
    .align 2
    .globl main

main:
    la t2, array       # Carrega o endereço base do array
    lw t3, MAX         # Carrega o valor de MAX
    addi s3, zero, 4
    addi t3, t3, -1    # MAX - 1 para usar no loop

    # Loop externo (i)
    li t0, 0           # Inicializa i = 0
loop_i:
    # Loop interno (j)
    add t1, zero, t3        # Inicializa j = MAX - 1 para cada iteração de i
    add t6, t0, t2     # Endereço de num[i] para comparação

loop_j:
    addi t4, t1, -1    # Calcula j - 1
    mul t5, t4, s3      # Calcula deslocamento de (j - 1) * 4
    add t5, t5, t2     # Endereço de num[j-1]
    lw s0, 0(t5)       # Carrega num[j-1]

    mul s2, t1, s3      # Calcula deslocamento de j * 4
    add s2, s2, t2     # Endereço de num[j]
    lw s1, 0(s2)       # Carrega num[j]

    # Comparação e possível troca
    ble s1, s0, swap   # Se num[j] < num[j-1], vai para swap
    j skip_swap        # Senão, pula o swap

swap:
    sw s0, 0(s2)       # Troca os valores
    sw s1, 0(t5)

skip_swap:
    addi t1, t1, -1    # Decrementa j
    bgt t1, t0, loop_j # Se j > i, continua o loop interno

    addi t0, t0, 1     # Incrementa i
    blt t0, t3, loop_i # Se i < MAX - 1, continua o loop externo

    # Impressão do array
    li t0, 0            # Reseta i para 0 para impressão
    la t2, array        # Reseta o ponteiro para o início do array
print_loop:
    lw a0, 0(t2)        # Carrega num[i] para imprimir
    li a7, 1            # Syscall para imprimir inteiro
    ecall               # Executa syscall

    addi t2, t2, 4      # Avança para o próximo elemento do array
    addi t0, t0, 1      # Incrementa i
    li t4, 7            # Total de elementos no array
    blt t0, t4, print_loop # Se i < MAX, continua o loop de impressão


    # Termina o programa
    li a7, 10
    ecall
