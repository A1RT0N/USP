all: item.o fila.o main.o
	gcc item.o fila.o main.o -o fila_programa -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

fila.o:
	gcc -c fila.c -o fila.o

main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm -f *.o fila_programa

run:
	./fila_programa < 1.in

rodar:
	@make -s clean
	@make -s all
	@make -s run
