# Descrição: Implemente uma função em Assembly RISC-V que calcula o máximo divisor comum de dois números usando o algoritmo de Euclides.
# Entrada: Dois números inteiros.
# Saída: O MDC dos dois números.
# Desafio: Garantir que a função funcione eficientemente mesmo para grandes números inteiros.

    .data
    .aling 2

int1: .word
int2: .word

    .text
    .aling 2
    .globl main

main:  

    li a7, 5
    ecall

    la t0, int1

    sw a0, 0(t0)

    mv s0, a0 
# s0 é o primeiro inteiro e o menor

    li a7, 5
    ecall

    la t0, int2

    sw a0, 0(t0)

    mv s1, a0 
# s1 é o segundo inteiro e o maior

menor_numero_em_s0:

    ble s0, s1, chamando_funcao

    # swap

    mv t0, s0

    mv s0, s1

    mv s1, t0


chamando_funcao:

    li s3, 1 
 # s3 é o resultado de gcd

    jal gcd


    li a7, 1
    mv a0, s3
    ecall

    li a7, 10
    ecall



gcd:  
# s3 é o resultado de gcd; 
#s0 é o primeiro inteiro e o menor; 
#s1 é o segundo inteiro e o maior;
    
    beq s0, zero, sair_loop

    mv t4, s0

    rem s0, s1, s0

    mv s1, t4

    j gcd



sair_loop:

    mv s3, s1
    
    jr ra


# gcd(int a, int b){

#     if( a< b){
#         m = a;
#     }else{
#         m = b;
#     }
#     // Continuar o loop até que um dos números seja zero
#     while (m != 0) {
#         int temp = m;  // Armazena temporariamente o valor de m
#         m = n % m;     // Atualiza m para ser o resto da divisão de n por m
#         n = temp;      // Atualiza n para ser o antigo valor de m
#     }

#     return n;  // O MDC está no número que não é zero
# }


