   .macro printar_inteiro (%inteiro)
      li a7, 1          # Assumindo que 1 é o número da syscall para imprimir um inteiro
      li a0, %inteiro   # Carrega o valor inteiro diretamente em a0
      ecall             # Realiza a syscall
    .end_macro
               
   .macro ler_inteiro 
      li a7, 5
      ecall	
   .end_macro



    .eqv input_funcao a0
    .eqv retorno_funcao a1
    .eqv numero_sorteado s0


    
.data
.align 2
str1: .asciz "Bem vindo! \n Gerei um número aleatóriamente de 1 a 100, tente descobrir qual é: (FAZ O L!!!)\n"
str2: .asciz "De um chute: \n"
str3: .asciz "O número inserido é menor que o número correto\n"
str4: .asciz "O número inserido é maior que o número correto\n"
str5: .asciz "Parabéns, você adivinhou o número!\n"


.text
.align 2
.globl main

main:
    # printf("Bem vindo! \n Gerei um número aleatóriamente de 1 a 100, tente descobrir qual é: (FAZ O L!!!)")
    addi a7, zero, 4
    la a0, str1
    ecall

gerar_numero_aleatório:

    li a1, 34 #carrega valores que vão ser usados para gerar números randômicos
	li a2, 145
	li a3, 99

    li a7, 42             # Número do syscall para getrandom
    ecall 

    # Agora você pode trabalhar com o número em t0.

    add t0, zero, a0

    # Aplicação da fórmula

    addi t1, zero, 13
    addi t2, zero, 100

    mul t0, t0, t1
    addi t0, t0, 29
    rem t0, t0, t2

    addi t0, t0, 1


    add numero_sorteado, zero, t0




loop:
	#printf("De um chute: ")
	addi a7, zero, 4 
	la a0, str2
	ecall
	
	#le o chute do usuário (número vai para a0)
	addi a7, zero, 5 
	ecall

checar_numero:
	#input esta em a0 (numero que o usuário adivinhou)
	#em s0 tem o valor verdadeiro
	#retorno esta em a1
	#retorna 0 se menor
	#retorna 2 se maior
	#retorna 1 se igual
	
	beq a0, s0, fim_loop #a0 == s0
	
	blt a0, s0, menor #a0 < s0
	
	#se chegou até aqui signfica que o número é maior
	
maior:
	#printf(O número inserido é maior que o número correto")
	addi a7, zero, 4 
	la a0, str4
	ecall
	
	j loop

menor:
	#printf("O número inserido é menor que o número correto")
	addi a7, zero, 4
	la a0, str3
	ecall
	
	j loop
	
fim_loop:	
	#vai escrever na tela "Parabéns, você adivinhou o número!"
	addi a7, zero, 4 
	la a0, str5
	ecall
	
	#finalizar o programa
	addi a7, zero, 10
	ecall