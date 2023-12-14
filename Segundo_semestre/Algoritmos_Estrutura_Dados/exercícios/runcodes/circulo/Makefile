all: circulo.o ponto.o main.o
	gcc circulo.o ponto.o main.c -lm -o main -std=c99 -Wall

ponto.o:
	gcc -c ponto.c -o ponto.o
	
circulo.o:
	gcc -c circulo.c -o circulo.o

run:
	./main
clean:
	rm ponto.o
	rm circulo.o
	rm main
