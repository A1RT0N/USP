all: item.o avl.o main.o
	gcc item.o fila.o avl.o main.o -o avl -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

ab.o:
	gcc -c avl.c -o avl.o
	 
fila.o:
	gcc -c fila.c -o fila.o

main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o avl

run:
	./avl

rodar:
	@make -s clean
	@make -s all
	@make -s run