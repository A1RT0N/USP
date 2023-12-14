#ifndef FILA_H
	#define FILA_H

	#include <stdio.h>
	#include <stdlib.h>
	#include "item.h"

	typedef struct fila_ FILA;

	FILA *fila_criar(void);
	bool fila_inserir(FILA *fila, ITEM *item);
	ITEM *fila_remover(FILA *fila);
	void fila_apagar(FILA **fila);
	bool fila_cheia(FILA *fila);
	ITEM *fila_frente(FILA *fila);
	int fila_tamanho(FILA *fila);
	bool fila_vazia(FILA *fila);
	void fila_imprimir(FILA *fila);
	void fila_inverter(FILA **fila);
	ITEM* fila_fim_posicao(FILA *fila, int posicao_do_fim);
#endif