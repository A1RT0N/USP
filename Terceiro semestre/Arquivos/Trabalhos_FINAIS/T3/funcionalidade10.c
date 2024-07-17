#include "funcoes.h"
#include "funcionalidade_1_auxiliar.h"
#include "funcionalidade_3_auxilar.h"
#include "funcionalidade_6_auxiliar.h"
#include "funcoes_auxiliares.h"

#include "ArvoreB.h"
#include "ArvoreBAuxiliar.h"
#include "ArquivoArvoreB.h"

long int InserirArquivosDados_AB(FILE *fp, CamposInsercao *campos_insercao, Lista *lista, Cabecalho *cabecalho){

    /*
	Função auxiliar que recebe um arquivo de dados aberto, uma struct de CamposInsercao preenchida, uma lista encadeada de elementos logicamente removidos uma struct cabecalho e não retorna nada
    Ela tem como objetivo inserir um dado registro no arquivo de dados

    Ela retorna o ByteOffset do registro inserido
	*/

    int tamanho_registro = TamanhoRegistro(campos_insercao); //calcular o tamanho do registro

    long int ByteOffsetAnterior; long int ByteOffsetPosterior;
    int tamanho_a_ser_escrito;
    
    // Pega o nó de um registro com menor quantidade de lixo de um registro a ser substituído
    NO *BestFitNode = BestFit(lista, tamanho_registro, &ByteOffsetAnterior, &ByteOffsetPosterior);
    
    long int ByteOffsetInserido; //byteoffset que inseriou o novo registro

    if (BestFitNode == NULL){ //significa que tem que inserir no fim do arquivo
        fseek(fp, cabecalho->proxByteOffset, SEEK_SET); //ir para o fim do arquivo

        ByteOffsetInserido = cabecalho->proxByteOffset;

        cabecalho->proxByteOffset += tamanho_registro; //atualizar o ByteOffset do fim do arquivo

        tamanho_a_ser_escrito = tamanho_registro;
    }else{ //signifca que da para sobreescrever um regitro já removido
        ByteOffsetInserido = BestFitNode->ByteOffset;

        ListaRemover(lista, BestFitNode->id); //remover o cara da lista

        if (lista->tamanho > 0){
            cabecalho->topo = lista->topo->ByteOffset;
        
            //atualizar o registro anterior

            if (ByteOffsetAnterior != -1) {
                fseek(fp, ByteOffsetAnterior, SEEK_SET);
                ler_lixo(fp, 5); //vou até a parte do Prox 
                fwrite(&ByteOffsetPosterior, sizeof(long int), 1, fp); //escrevo o novo prox
            }
        } else{
            long int novo_topo = -1; cabecalho->topo = novo_topo;
        }

        fseek(fp, BestFitNode->ByteOffset, SEEK_SET); //ir para o local do registro que vai ser subistituid
        
        cabecalho->nroRegRem -= 1;

        tamanho_a_ser_escrito = BestFitNode->size;
    }
    
    cabecalho->nroRegArq += 1;
    
    //inserir o novo registro no lugar do registro antigo

    Registro* registro = CriarRegistro();   // Cria um registro


    // Preenche um registro que será inserido
    PreencherRegistro(registro, '0', tamanho_a_ser_escrito, -1, campos_insercao->id, campos_insercao->idade, campos_insercao->nomeJogador, campos_insercao->nacionalidade, campos_insercao->nomeClube);
    
    // Escreve no arquivo de dados o registro preenchido
    EscreverRegistro(fp, registro);
    
    // Se o melhor nó existir
    if (BestFitNode != NULL){
        //verificar se tem espaço sobrando do registro antigo
        if (BestFitNode->size > tamanho_registro){
            char dinheiro = '$';

            for (int i = 0; i < BestFitNode->size - tamanho_registro; i++){ //para a diferença de tamanho
                fwrite(&dinheiro, sizeof(char), 1, fp); //colocar $ em tudo
            }
        }
    }

    return ByteOffsetInserido;
}

int Inserir(char *arquivoDados, char *arquivoArvore, int quantidade){

    /*
	Função principal que recebe um arquivo de dados e de árvore a serem abertos e uma quantidade de elementos a serem inseridos
    Ela insere a quantidade de elementos passados pelo usuário no arquivo de dados e no arquivo da árvore conforme a especificação do trabalho
	*/
    FILE *arqDados; //cria o ponteiro para o arquivo de dados
	
    if(arquivoDados == NULL || !(arqDados = fopen(arquivoDados, "r+b"))){ //abertura e tratamento de arquivo
        printf("Falha no processamento do arquivo.");
        return -1;
    }

    Cabecalho *cabecalho = (Cabecalho *) malloc(sizeof(Cabecalho)); //Alocar a struct para ler o cabecalho do arquivo de dados
	LerCabecalho(arqDados, cabecalho); //ler o cabecalho do arquivo

	if (cabecalho->status == '0'){ //verifica integridado do arquivo de dados
        fclose(arqDados); //fechar o arquivo de dados

		printf("Falha no processamento do arquivo.");
		return -1;
	}

    FILE *arqArvore;
    if(arquivoArvore == NULL || !(arqArvore = fopen(arquivoArvore, "r+b"))){ //abertura e tratamento de arquivo
        printf("Falha no processamento do arquivo.");

        fclose(arqDados); //fechar o arquivo de dados
        return -1;
    }

    ArvoreB *arvore = CreateArvoreB(); //criar a árvore
    LerHeader(arqArvore, arvore); //ler o header da árvore

    if (arvore->status == '0'){ //verificar a integridade do arquivo da árvore
        printf("Falha no processamento do arquivo.");

        //fechar ambos os arquivos
        fclose(arqDados);
        fclose(arqArvore);

        return -1;
    }

    Lista *lista = ListaCriar(); //criar a lista encadeada
    ArquivoToList(arqDados, lista); //coloca todos os registros removidos do arquivo na lista

    mudanca_de_status(arqDados, '0'); // Muda o status do arquivo de dados para inconsistente

    IndexStruct chave;

    // Para cada inserção
    for(int i = 0; i < quantidade; i++){
        CamposInsercao *campos_insercao = CriarCamposInsercao();
        LerCamposInsercao(campos_insercao); // Lê as entradas

        chave.id = campos_insercao->id;

        chave.ByteOffset = InserirArquivosDados_AB(arqDados, campos_insercao, lista, cabecalho);  // Escreve a entrada no arquivo

        InsercaoArvoreB(arqArvore, chave, arvore); //inserir na arvore b
    }

    
    if (lista->tamanho == 0) cabecalho->topo = -1;
    else cabecalho->topo = lista->topo->ByteOffset;

    // Escreve os novos valores do cabeçalho no cabeçalho
    EscreverCabecalho(arqDados, cabecalho);
    mudanca_de_status(arqDados, '1'); //altera o status

    AtualizarHeader(arqArvore, arvore);

    fclose(arqArvore); //fecha o arquivo da árvore
    fclose(arqDados); //fecha o arquivo de dados

    return 1;
}