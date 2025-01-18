all: avl.o set.o main.o
	gcc avl.o set.o main.o -o avl -std=c99 -Wall

avl.o:
	gcc -c avl.c -o avl.o

set.o:
	gcc -c set.c -o set.o

main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o avl

run:
	./avl

