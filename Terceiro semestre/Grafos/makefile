all: graph.o main.o
	gcc graph.o main.o -o graph -std=c99 -Wall


graph.o:
	gcc -c graph.c -o graph.o
	 
main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o graph

run:
	./graph
