#ifndef REGISTRO_H
/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/
	#define REGISTRO_H
	
    #include "funcoes.h"
    #include "funcoes_auxiliares.h"
    #include "funcionalidade_3_auxilar.h"

    typedef struct registro_{
        char removido;
        int tamanhoRegistro;
        long int Prox;
        int id;
        int idade;
        int tamNomeJog;
        char* nomeJogador;
        int tamNacionalidade;
        char* nacionalidade;
        int tamNomeClube;
        char* nomeClube;
    }Registro;

    Registro* CriarRegistro();
    
    void LerRegistro(FILE *fp, Registro *registro);

    void EscreverRegistro(FILE *fp, Registro* registro);

    void PreencherRegistro(Registro* registro, char removido, int tamanhoRegistro, 
        long int Prox, int id, int idade, char* nomeJogador, char* nacionalidade, char* nomeClube);


#endif