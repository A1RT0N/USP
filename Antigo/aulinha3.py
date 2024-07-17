# lista, também conhecido como ARRAY, é um conjunto de números, palavras, caractes, que você consegue manipular
# toda lista está entre colchetes => []
# Revisão: uma palavra (string) é sempre representa: "raissa". Um caracte é representado: 'a'
comprinhas = ["livrinho", "chocolate", "morango", "beijinho", "cheirinho", "namorado legal"]
# Lista vazia:
vazio_e_triste = []

print(comprinhas)

# INDEX: Index é traduzido como "POSIÇÃO de um elemento de uma lista". O que que significa isso?
# Toda vez que você adiciona um elemento (palavra, caracter, número) em uma lista, há um número INTEIRO
# que mostra para nós onde está localizado esse elemento na lista. Padrão: o primeiro elemento de uma lista 
# sempre começa com o número 0
# livrinho: 0
# chocolate: 1
# morango:2
# beijinho: 3
# cheirinho: 4
# namorado legal: 5

# FUNÇÕES EM LISTAS: append()******, count(), index(), insert()*, pop()***, remove()*, reverse(), sort()********

# append() -> *adiciona* um elemento ao final da lista
# sort() -> *ordena* a lista alfanumericamente
# pop() -> *elimina/apaga* o último elemento de uma lista

comprinhas.append("suquinho")

print(comprinhas)

comprinhas.sort() # Por que vc não coloca nenhuma palavra dentro de sort()? Porque sort() já ordena alfanumericamente

print(comprinhas)

comprinhas.pop()

print(comprinhas)


