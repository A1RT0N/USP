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
.align 0
str1: .asciz "Bem vindo! \n Gerei um número aleatóriamente de 1 a 100, tente descobrir qual é: (FAZ O L!!!)\n"
str2: .asciz "De um chute: \n"
str3: .asciz "O número inserido é menor que o número correto\n"
str4: .asciz "O número inserido é maior que o número correto\n"
str5: .asciz "Parabéns, você adivinhou o número!\n"

.align 2

ptr: .word

.text
.align 2
.globl main

main:
    # printf("Bem vindo! \n Gerei um número aleatóriamente de 1 a 100, tente descobrir qual é: (FAZ O L!!!)")
    addi a7, zero, 4
    la a0, str1
    ecall


	# Esse s10 vai ser o parametro pra ver é a primeira alocação da primeira sublista (s10 =0) ou não (s10 = 1)



	li s10, 0 



gerar_numero_aleatório:

    li a1, 34  #carrega valores que vão ser usados para gerar números randômicos
	li a2, 145
	li a3, 99

    li a7, 42 # Número do syscall para getrandom
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


	mv s3, a0  # Número chutado fica no s3



criar_sublista_e_colocar_numeros:

	# Adiciona na sublista o número chutado em 4 bytes e outros 4 bytes 
	# armazena o endereço desses 4 bytes em s4 para colocar no conteúdo de s4 a próxima sublista, se houver

	la t3, ptr  

	# Se for o primeiro número chutado, desvia para a label primeira_sublista

	beq s10, zero, primeira_sublista

	# Senão, faz a alocação

	li a7, 9
	li a0, 8
	ecall

	# Valor do endereço de memória da última sublista (0(s4)) aponta pro endereço base dessa alocação

	sw a0, 0(s4)

	# Número sorteado é escrito no primeiro endereço de memória

	sw s3, 0(a0)

	# Atualizar s4

	addi s4, a0, 4
	

	j checar_numero




primeira_sublista:

	# Label para guardar o endereço de memória da primeira sublista alocada em ptr

    li s10, 1 # Deixa a flag s10 sinalizando que já houve a criação da primeira sublista
	# s10 jamais será mudado para 0 no código novemente

	# Alocando memória: 4 bytes para o número e 4 bytes para o endereço da próxima sublista
	li a7, 9
	li a0, 8
	ecall

	sw a0, 0(t3) # Colocando o endereço do primeiro byte alocado no conteúdo de ptr (que tem seu endereço no registrador t3)

	sw s3, 0(a0)	#Colocando o primeiro número chutado na sublista

	addi s4, a0, 4 # O registrador s4 vai ser o endereço de memória da última sublista

	# s4 será fundamental para endereçar a próxima sublista na sua sublista anterior


checar_numero:

	#input esta em s3 (numero que o usuário adivinhou)
	#em s0 tem o valor verdadeiro
	#retorno esta em a1
	#retorna 0 se menor
	#retorna 2 se maior
	#retorna 1 se igual
	
	beq s3, s0, fim_loop #s3 == s0
	
	blt s3, s0, menor #s3 < s0
	
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