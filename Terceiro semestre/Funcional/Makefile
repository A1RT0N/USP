CC=ghc

CFLAGS=-Wall -g

SRC=segundo_cod.hs

EXEC=myprogram

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

run:
	./$(EXEC)

clean:
	rm -f $(EXEC)

# Regra 'rodar' que encadeia clean, all e run
rodar: clean all run
