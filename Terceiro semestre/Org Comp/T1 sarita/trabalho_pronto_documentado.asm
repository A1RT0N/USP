.macro printar_inteiro (%inteiro)
	li a7, 1          # Syscall para printar inteiro
	addi a0, %inteiro, 0   # Carrega o valor inteiro diretamente em a0
	ecall             # Realizar a syscall
.end_macro
               
.macro ler_inteiro #retorno em a0
	li a7, 5 #Syscall para ler um inteiro
	ecall #Realizar a syscall
.end_macro
   
.macro printar_string (%string)
	li a7, 4 #Syscall para printar uma string
	la a0, %string #colocar o endereço da string em a0
	ecall #Realizar a syscall
.end_macro

.macro alocar_memoria 
	li a7, 9 #Syscall para alocar memória
	li a0, 8 #nesto código vamos sempre alocar 8 bytes (1 inteiro (word) + 1 ponteiro (word))
	ecall #Realizar a syscall
.end_macro

    .eqv numero_sorteado s0
    .eqv qtd_tentativas s5

    
	.data
	.align 0
#declaração das strings
str1: 	.asciz "Bem vindo!\nGerei um número aleatóriamente de 1 a 100, tente descobrir qual é:\n\n"
str2: 	.asciz "De um chute: "
str3: 	.asciz "\nO número inserido é menor que o número correto\n"
str4: 	.asciz "\nO número inserido é maior que o número correto\n"
str5: 	.asciz "\nParabéns, você adivinhou o número!\n"
str6:	.asciz " "
str7: 	.asciz "Os seus chutes foram: "
str8: 	.asciz "\nQuantidade de tentativas: "
	
	.align 2
ptr:	.word 	#declarar o ponteiro para a lista encadeada

	.text
	.align 2
	.globl main
	
main:
	li qtd_tentativas, 0 #inicializar a quantidade de tentativas como 0
	
	#setar o ponteiro da lista encadeado como NULL (zero)
	la t0, ptr #carregar o endereço de ptr em t0 
	sb zero, 0(t0) #guardar o valor 0 no endereço de ptr
	
	#printf("Bem vindo!\nGerei um número aleatóriamente de 1 a 100, tente descobrir qual é:\n\n")
	printar_string(str1)

gerar_numero_aleatório: 
    	li a1, 34 #carrega valores que vão ser usados para gerar números randômicos
	li a2, 145
	li a3, 99
	
	li a7, 42  # Número do syscall para getrandom
	ecall #Realizar a syscall
	
	#em a0 tem o número pseudorandomico
	add t0, zero, a0 #t0 = a0

   	#Aplicar a fórmula (congurente linear)
   	#escolhemos a = 13, c = 29, m = 100
   	#fórmula em questao: Xn+1 = (a.Xn + c) mod m
 

	addi t1, zero, 13 #t1 = 13
	addi t2, zero, 100 #t2 = 100
	
	#a.Xn
	mul t0, t0, t1 #t0 = t0 * 13
	#a.Xn + c
	addi t0, t0, 29 #t0 = t0 + 29 
	#(a.Xn + c) mod m
	rem t0, t0, t2 #to = t0 % t2 (resto da divisao)
	
	#por causa das propriedades de mod, t0 vai estar entre 0 e 99, mas queremos números entre 1 e 100, logo, é só adicionar 1
	addi t0, t0, 1 #t0 = t0 + 1
	
    	add numero_sorteado, zero, t0 #numero_sorteado (S0) = t0
   
loop:
	#printf("De um chute: ")
	printar_string(str2)
	
	#le o chute do usuário
	ler_inteiro() #número vai estar em a0
	
	mv t0, a0 #colocar em t0 para fazer a comparação posteiromente
	
	jal adicionar_tentativa #chamar a função para adicionar a tentativa na lista de tentativas
	
	#input esta em t0 (numero que o usuário adivinhou)
	
	beq t0, numero_sorteado, fim_loop #t0 == numero_sorteado
	
	blt t0, numero_sorteado, menor #t0 < numero_sorteado
	
	#se chegou até aqui signfica que o número é maior
	
maior:
	#printf(O número inserido é maior que o número correto")
	printar_string(str4)
	
	j loop

menor:
	#printf("O número inserido é menor que o número correto")
	printar_string(str3)
	
	j loop
	
fim_loop:	
	#vai escrever na tela "Parabéns, você adivinhou o número!"
	printar_string(str5)
	
	#printf("Os seus chutes foram: ")
	printar_string(str7)
	
	#chama a função que printa a lista encadeda
	jal printar_lista
	
	#printf("\nQuantidade de tentativas: ")
	printar_string(str8)
	
	printar_inteiro(qtd_tentativas)
	
	#finalizar o programa
	addi a7, zero, 10
	ecall
	
adicionar_tentativa: 
	addi qtd_tentativas, qtd_tentativas, 1 #aumentar a quantidade de tentativas por 1
	#em t0 tem o número a ser adicionado
	
	lw t1, ptr #colocar em t1 o enedereço a qual ptr aponta. t1 = ptr
	beq t1, zero, adicionar_primeiro #se for zero, singifica que ptr aponta para nulo. Logo, não tem nenhum número na lista ainda
	
	#se chegou aqui signfica que a lista nao é vazia, logo, temos que fazer um loop para achar o fim da lista e colocar o novo número no fim dela
	
	#t1 tem o endereço para onde ptr aponta.
	#Se esse endereço n for nulo sinfica que nos 4 primeiros bytes tem um inteiro e nos 4 ulitmos tem o ponteiro.
	
	addi t1, t1, 4 #estou fazendo t1 ir para o quarto byte (início do endereço do ponteiro)
	
procurar_fim_lista:
	lw t2, 0(t1) #pegar o local aonde o ponteiro está apontando

	beq t2, zero, adicionar_numero #se o ponteiro for nulo, signifca que chegamos no fim da lista e podemos adicionar o número
	
	#se o ponteiro não for nulo temos que continuar andando na lista
	addi t1, t2, 4 #pegar o endereço para onde o ponteiro aponta (t2) e somar 4, para consegui o endereço do próximo ponteiro (colocar isso tem t1)
	
	j procurar_fim_lista
	
adicionar_numero:
	#quando chegar aqui signifca que t1 é exatamente o pontiero do fim da lista (aponta para nulo)
	alocar_memoria #em a0 tem o endereço do local alocado
	
	sw t0, 0(a0) #colocar nos primeiros 4 bytes de a0 o inteiro chutado
	sw zero, 4(a0) #colocar nos últimos 4 bytes de a0 "NULL", pois o ponteiro do fim da lista deve apontar para NULL
	
	sw a0, 0(t1) #fazer t1 (fim da lista) apontar para a0 (novo local alocado)
	
	j fim_adicionar_tentativa
	
	
adicionar_primeiro:
	alocar_memoria #em a0 tem o endereço do primeiro byte dos 8 alocados
	
	sw t0, 0(a0) #colocar nos primeiros 4 bytes de a0 o inteiro chutado
	sw zero, 4(a0) #colocar nos últimos 4 bytes de a0 "NULL", pois o ponteiro do fim da lista deve apontar para NULL
	
	la t1, ptr #t1 = &ptr
	
	#fazer ptr apontar para o local alocado
	sw a0, 0(t1) #ptr = a0. 
	
	j fim_adicionar_tentativa
	
	
fim_adicionar_tentativa:
	jr ra

printar_lista:
	la t0, ptr #t0 = &ptr
	lw t1, 0(t0) #t1 = *(&ptr). t1 = ptr
	
loop_printar:
	lw t2, 0(t1) #pegar o inteiro
	lw t3, 4(t1) #pegar o ponteiro
	
	printar_inteiro(t2) #printar o inteiro
	printar_string(str6) #printf(" ")
	
	beq t3, zero, sai_loop_printar #se o ponteiro for nulo (acabou a lista), sair do loop
	
	mv t1, t3 #t1 = t3 (para continuar o loop em t1)
	
	j loop_printar

sai_loop_printar:
	jr ra
