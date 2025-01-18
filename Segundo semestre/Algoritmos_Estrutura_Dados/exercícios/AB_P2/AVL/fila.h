#ifndef FILA_H
	#define FILA_H

	#include "item.h"	
	#define TAM_MAX 100
	#include <stdio.h>
	#include <stdlib.h>

	typedef struct fila_ FILA;

	typedef struct no_ NO;

	// FILA MODIFICADA PARA NÓ

	FILA *fila_criar(void); 
	bool fila_inserir(FILA *fila, NO* no); 
	NO *fila_remover(FILA *fila); 
	void fila_apagar(FILA **fila);

	ITEM *fila_frente(FILA *fila);
	int fila_tamanho(FILA *fila); 
	bool fila_vazia(FILA *fila); 
	bool fila_cheia(FILA *fila); 
	void fila_imprimir(FILA *fila); 
#endif