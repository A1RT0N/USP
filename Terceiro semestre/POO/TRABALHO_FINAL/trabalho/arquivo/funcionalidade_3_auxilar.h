#ifndef FUNCIONALIDADE_3_AUXILIAR
/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/
    #define FUNCIONALIDADE_3_AUXILIAR

    #include "funcoes.h"
    #include "funcoes_auxiliares.h"

    void ler_entrada(int *campos_checagem, int *id, int *idade, char **nacionalidade, char **nomeClube, char **nomeJogador, int j);

    void printar_registro(char* nome_jogador_do_registro, char* nacionalidade_do_registro, char* nome_clube_do_registro);

    int LerString_arquivo(char **string, FILE *fp);
#endif