# Fazer fibonacci recursivo


# int fib(n){
##     if(n == 1 || n == 2){
#         return 1;
#     }else{
#           int x = fib(n-1);
#           int y = fib(n-2);
#           return x + y;
#     }

# }

    .data
    .align 0
str1: .asciz "O fibonacci do elemento "
str2: .asciz " é "


    .text
    .align 2
    .globl main

main:

    li a7, 5
    ecall

    mv s0, a0

    jal fibonacci

    # retorno em a1
    # elemento em s0
    
    la a0, str1
    li a7, 4
    ecall

    mv a0, s0
    li a7, 1
    ecall

    la a0, str2
    li a7, 4
    ecall

    mv a0, a1
    li a7, 1
    ecall

    li a7, 10
    ecall
    

fibonacci:
    addi sp, sp, -12        # Reserva espaço na pilha para ra, a0, e um resultado temporário

    sw ra, 0(sp)            # Salva o endereço de retorno (ra) na pilha
    sw a0, 4(sp)            # Salva o valor atual de a0 (n) na pilha

    li t1, 2
    ble a0, t1, base_case   # Se n <= 2, pule para base_case

    addi a0, a0, -1
    jal fibonacci           # Calcula fibonacci(n-1)
    lw t0, 4(sp)            # Recupera o valor original de n da pilha
    sw a1, 8(sp)            # Salva o resultado de fibonacci(n-1) em a1

    addi a0, t0, -2
    jal fibonacci           # Calcula fibonacci(n-2)
    lw t1, 8(sp)            # Recupera o resultado de fibonacci(n-1) de a1

    add a1, a1, t1          # Soma fibonacci(n-1) + fibonacci(n-2) e armazena em a1

    j exit_recursion        # Pula para exit_recursion para terminar a função

base_case:
    li a1, 1                # Define a1 como 1 para os casos base fib(1) e fib(2)
    j exit_recursion        # Não precisa, mas é para deixar claro

exit_recursion:
    lw ra, 0(sp)            # Restaura o endereço de retorno
    lw a0, 4(sp)            # Restaura o valor original de n
    addi sp, sp, 12         # Libera o espaço da pilha
    jr ra                   # Retorna para o chamador
