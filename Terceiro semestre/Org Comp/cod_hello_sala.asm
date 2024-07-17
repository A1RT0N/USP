
	.data # Assembly não é sensitivo a a tab  
	.align 0 
str1:	.asciz "Hello World ++! " 	# Com \0 no final
str2:	.asciz "Hello World --! " 	# --> label (rótulo)

	.text
	.align 2 # Definindo todas as instruções em múltiplos de 2
	.globl main
	
main:
	addi a7, zero, 5 # sys call de scanf()
# o li é um addi. O la é convertido em 2 verdadeiras
	ecall
	# o valor digitado tá no a0
	add s0, a0, zero
	# O s tem os registradores salvos
	
	blt s0, zero, print_neg #branch less than --> se o valor digitado pelo usuário for menos que zero ele vai pra print_neg:
	
	addi a7, zero, 4 #printf()
	la a0, str1 # carrega o endereço do primeiro byte da string (isso é o parametro do printf)
	
	ecall
	
	j the_end
	
print_neg:	

	addi a7, zero, 4
	la a0, str2
	
	ecall

the_end:

	# O addi é operação direta entre dois números. Add normal é quanto somamos quando tem 1 ou mais registradores, mas ambos os add's sobrescrevem o que tinha antes
	
	addi a7, zero, 1  # imprime inteiro
	add a0, zero, s0 # 
	ecall
	
	li a7, 10 # encerra o programa
	ecall
