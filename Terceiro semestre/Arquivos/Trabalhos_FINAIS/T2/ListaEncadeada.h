#ifndef LISTA_H
	#define LISTA_H

    typedef struct no_ NO;
	
	struct no_{
        NO *prox;
        int id;
        long int ByteOffset;
        int size;
    };

    typedef struct lista_ {
        NO *topo;
        int tamanho;
    }Lista;

    Lista * ListaCriar();
    void ListaInserir(Lista *lista, int id, long int ByteOffset, int size);
    void ListaRemover(Lista *lista, int id);
    
#endif