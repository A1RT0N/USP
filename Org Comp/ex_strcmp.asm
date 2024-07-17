# 7) Codifique em Assembly RISC-V um programa que implemente a funcionalidade da função strcmp().

# FAÇA ISSO DINAMICAMENTE COM O USUÁRIO TE PASSANDO A STRING

# Nesse código ele malloca 1 byte a mais, assim como o strcat

    .data
    .aling 0
string1: .space 101

string2: .space 101

    .text
    .aling 2
    .globl main

main:
	# Fazendo dinamicamente passsando string
    # LER STRING1 E STRING2

    li a7, 8

    la a0, string1

    addi a1, zero, 100

    ecall

    li a7, 8

    la a0, string2

    addi a1, zero, 100

    ecall


    la t0, string1
    la t1, string2

percorrer:

    lb t3, 0(t0)

    lb t4, 0(t1)

    addi t0, t0, 1

    addi t1, t1, 1

    beq t3, zero, acabou_string1

    beq t4, zero, retornar_string_1_maior

    bgt t3, t4, retornar_string_1_maior

    blt t3, t4, retornar_string_2_maior


    j percorrer

    # aqui eles são diferentes


acabou_string1:

    beq t4, zero, retornar_string_iguais

    j retornar_string_2_maior


retornar_string_2_maior:

    li a7, 1

    li a0, 1

    ecall


    j fim

retornar_string_1_maior:

    li a7, 1

    li a0, -1

    ecall

    j fim

retornar_string_iguais:

    li a7, 1

    li a0, 0

    ecall


    j fim


fim:

    li a7, 10

    ecall


























