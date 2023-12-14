all: item.o Pilha.o main.o
	gcc item.o Pilha.o main.o balanceada.o -o balanceada -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

Pilha.o:
	gcc -c Pilha.c -o Pilha.o

balanceada.o:
	gcc -c balanceada.c -o balanceada.o

main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o balanceada

run:
	./balanceada
