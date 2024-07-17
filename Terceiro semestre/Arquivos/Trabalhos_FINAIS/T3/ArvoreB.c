#include "funcoes.h"
#include "ArvoreB.h"
#include "ArquivoArvoreB.h"
#include "ArvoreBAuxiliar.h"

void Split(FILE *fp, NoArvoreB *no, int RrnOverfitado, ArvoreB *arvore, RetornoInsercao *retorno){
    /*
    Função que realiza o split.
    Tambem recebe como parametro o RetornoInserção, já que como vai ter uma promotion ela ja altera o seu valor 
    para o valor do retorno da função auxiliar estar correto
    */
    //significa que o nó passado está em overflow
    IndexStruct *subir = (IndexStruct *) malloc(sizeof(IndexStruct)); //criar a struct da chave que irá subir
    
    NoArvoreB *NovoNO = CreateNoArvoreB(); //criar o novo nó para fazer split

    //inserir os indices do nó antigo no novo nó
    InserirNo(no->chaves[2], NovoNO); 
    InserirNo(no->chaves[3], NovoNO); 

    //remover ambos os indices que foram passados para o novo nó do nó antigo
    RemoveIndiceNo(no);
    RemoveIndiceNo(no);

    //passar a chave a subir do nó para a nova struct criada
    subir->id = no->chaves[1].id; 
    subir->ByteOffset = no->chaves[1].ByteOffset;
    RemoveIndiceNo(no); //remover o nó que vai fazer promotion

    /*
    O no overfitado contem 4 chaves
    Logo, ao passar a chave de indice 2 e 3 para o novo nó
    Vamos ter que o ponteiro a esquerda da chave de indice 2 está na posição 2
    O ponteiro a direita da chave de indice 3 está na posição 3
    O ponteiro a esquerda da chave de indice 3 está na posição 3
    O ponteiro a direita da chave de indice 4 está na posição 4

    Por isso que estou fazendo essas atribuições abaixo
    */
    NovoNO->RRN[0] = no->RRN[2]; no->RRN[2] = -1;
    NovoNO->RRN[1] = no->RRN[3]; no->RRN[3] = -1;
    NovoNO->RRN[2] = no->RRN[4]; no->RRN[4] = -1;

    NovoNO->alturaNo = no->alturaNo; //setar a altura do novo nó como a altura do no overfitado

    EscreveNo(fp, NovoNO, arvore->proxRRN); //Escrever o novo nó no arquivo

    //atualizar os parametros da struct de retorno
    retorno->Promotion = 1;
    retorno->subir = subir;
    retorno->RRN = arvore->proxRRN;

    FreeNoArvoreB(NovoNO); //liberar memória do nó alocado
}

RetornoInsercao * InserirAux(FILE *fp, int rrn, IndexStruct chave, ArvoreB *arvore){
    /*
    Essa é a função que realmente insere na árvore (menos quando tem q inserir um nó raiz)
    Faz a inserção de forma rescursiva.
    Seu retorno é uma struct que diz se vai ter promotion, e se tiver, qual é a chave e o rrn da nova página criada no split
    */
    if (rrn == -1){ //significa que está no fim da árvore
        RetornoInsercao *retorno = CriarRetornoInsercao(); //criar a struct

        //copiar a struct indice para a struct retorno
        retorno->subir->id = chave.id; 
        retorno->subir->ByteOffset = chave.ByteOffset;

        retorno->Promotion = 1; //colocar que deve ter uma promoção

        return retorno;
    }

    NoArvoreB *NoAtual = CreateNoArvoreB(); //criar o nó da iteração atual

    LerNo(fp, NoAtual, rrn); //ler o no

    int igual = 0; //variavel para verificar se o item já está no nó

    //retorna a qual ponteiro deve ser seguido para continuar a busca até o fim da árvore. Tambem colocar na variável igual se o item que está sendo adicionado já exite e está naquele nó.
    int result = ContemNo(NoAtual, chave.id, &igual); //valores do resultado e seus significados explicados na função ContemNo

    if (igual == 1) {
        //criar uma struct retorno para dizer que não vai haver promotion já que esta chave já existe
        RetornoInsercao *retorno = CriarRetornoInsercao();
        retorno->Promotion = 0;
        
        FreeNoArvoreB(NoAtual); //liberar memória alocada

        return retorno; 
    }
    
    RetornoInsercao *retorno = InserirAux(fp, NoAtual->RRN[result], chave, arvore); //fazer a chamada recursiva

    //se nao tiver que fazer nenhuma promoção
    if (retorno->Promotion == 0) {
        FreeNoArvoreB(NoAtual); //liberar memória alocada

        return retorno; //mandar na recursao o mesmo retorno (de que nao se deve fazer nada)
    }

    int Overflow = InserirNo(*(retorno->subir), NoAtual); //fazer a inserção

    //atualizar a ordem dos rrns após adicionar um índice novo
    AtualizarRRNs(NoAtual, PosicaoIndice(NoAtual, retorno->subir->id), NoAtual->RRN[result], retorno->RRN);

    //a esquerda do cara que vc acabou de inserir vai estar o RRN result
    //a direita do cara que vc acabou de inserir vai estar retorno->RRN

    //se teve overflow na inserção
    if (Overflow == 1) {
        Split(fp, NoAtual, rrn, arvore, retorno); //fazer o split
        arvore->proxRRN += 1; //aumentar o proxRRN, pois criou um nó novo
    }
    else retorno->Promotion = 0; //se nao teve overflow colocar no retorno que não vai ter promoção

    EscreveNo(fp, NoAtual, rrn); //atualizar o nó atual

    FreeNoArvoreB(NoAtual); //liberar memória alocada

    return retorno; //retornar o retorno
}

void InsercaoArvoreB(FILE *fp, IndexStruct chave, ArvoreB *arvore){
    /*
    Dado o ponteiro para oa rquivo da árvore b
    Uma struct com as informações da chave
    E a árvore B

    Faz a inserção da chave na árvore
    */
    arvore->nroChaves += 1; //aumentar o número de chaves presente na árvore

    int RrnNoRaiz = arvore->noRaiz; //guardar o rrn do no raiz antes de fazer a inserção

    RetornoInsercao *retorno = InserirAux(fp, arvore->noRaiz, chave, arvore); //chamar a função de inserção auxiliar a partir da raiz

    if (retorno->Promotion == 0) return; //se nao tiver que criar nenhum novo nó só acabar a função por aqui

    //se chegou até aqui significa que um novo nó deve ser criado

    NoArvoreB *new_node = CreateNoArvoreB(); //criar um novo nó

    new_node->alturaNo = arvore->alturaRaiz; //setar a altura do nó como a altura da raiz
    arvore->alturaRaiz ++; //aumentar a altura da raiz

    InserirNo(*(retorno->subir), new_node); //adicionar o índice no novo nó

    arvore->noRaiz = arvore->proxRRN; //atualizar o rrn do noRaiz

    //lidar com os ponteiros do novo nó
    new_node->RRN[0] = RrnNoRaiz; //o ponteiro a esquerda do novo nó será o rrn do antigo nó raiz
    new_node->RRN[1] = retorno->RRN; //o ponteiro a direita do novo nó será o rrn resultado da inserção

    if (arvore->nroChaves == 1){ //se acabou de inserir o primerio nó na árvore
        EscreveHeader(fp, arvore); //escrever o header
    } else {
        AtualizarHeader(fp, arvore); //autalizar o header
    }

    EscreveNo(fp, new_node, arvore->proxRRN); //escrever o nó

    FreeNoArvoreB(new_node); //liberar memória do nó alocado

    arvore->proxRRN += 1; //aumenta o número do RRN 
}

long int BuscaAux(int rrn, int id, FILE *fp){
    /*
    Faz a busca na árvore B a partir do id
    Retorna o ByteOffset
    Se não encontrar o id na árvore retorna -1
    */
    if (rrn == -1) return (long int) -1; //retornar o caso base de que não achou 

    NoArvoreB *no = CreateNoArvoreB(); //criar o nó
    LerNo(fp, no, rrn); //ler o nó

    //verificar se id está contido no nó
    int igual = 0; int result = ContemNo(no, id, &igual);

    if (igual == 1) return no->chaves[result].ByteOffset; //se achou, retornar o ByteOffset

    int novo_rrn = no->RRN[result]; //pegar o novo rrn

    FreeNoArvoreB(no); //liberar a memória alocada

    //se não achou
    return BuscaAux(novo_rrn, id, fp); //procurar nos próximos nós
}

long int BuscaArvoreB(ArvoreB *ArvoreB, int id, FILE *fp){
    /*
    Faz a busca na árvore B a partir do id
    Retorna o ByteOffset
    Se não encontrar o id na árvore retorna -1
    */
    return BuscaAux(ArvoreB->noRaiz, id, fp); //chamar a função de busca auxiliar a partir da raiz
}