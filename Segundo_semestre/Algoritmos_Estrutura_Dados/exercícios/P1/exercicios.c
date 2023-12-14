/*
Implemente uma função de Busca em lista
sequencial ordenada que retorne a posição do
item buscado na lista. Exemplo, seja a lista: L
= [1, 4, 5, 9, 15]. Considere que L é um vetor
de itens tal qual definimos em nossas aulas
para o TAD Lista Sequencial e que a chave do
item buscado é 5. A função retornaria 2.
*/ 


/*
Implemente uma função para Remover um
item (dada uma chave) em lista sequencial
ordenada do modo mais eficiente possível.
*/


/*
Implemente uma função para Inserir um item
em lista sequencial ordenada. A interface
definida para o TAD Lista não pode ser
alterada.
*/

int busca(int *v, int tamanho, int numero);
void remover(int* v, int tamanho, int chave);
void insterir(int *v, int tamanho, int chave);

int busca(int *v, int tamanho, int numero){
    int inicial = 0;
    int final = tamanho-1;
    int meio = (inicial+final)/2;
    while(v[meio] != numero){
        if(v[meio] > numero){
            final = meio;
            meio = (inicial+final)/2;
        } else{
            inicial = meio;
            meio = (inicial+final)/2;
        }
    }

    return meio;
}

void remover(int* v, int tamanho, int chave){
    // Tá certo dar shift - p/ esquerda - aqui?
    int pos = busca(v,tamanho,chave);
    for(int i = pos; i<tamanho-1; i++){
        v[i]= v[i+1];
    } // nesse caso tamanho -1 é o index do último elemento
    tamanho--;
}

// Nas duas funções aqui teria que analisar as pré condições de lista cheia ou vazia e se lista tá NULL,
// Mas não vou fazer isso

void inserir(int *v, int tamanho, int chave){
    // Tá certo dar shift aqui? -- Ele não pediu o jeito mais eficiente, mas mesmo assim, tá ok?
    int pos = busca(v,tamanho,chave);
    for(int i = tamanho-1; i>=pos; i--){
        v[i+1] = v[i];
    }

    tamanho++; // Esse tamanho ++ deveria ser antes do for?
    
}



/*

INVERTER PILHA

// Função auxiliar para inverter a pilha
void inverter_pilha_recursiva(PILHA* P, int data) {
    if (pilha_vazia(P)) {
        empilhar(P, data);
        return;
    }

    int temp = desempilhar(P);
    inverter_pilha_recursiva(P, data);
    empilhar(P, temp);
}

// Função principal para inverter a pilha
void pilha_inverter(PILHA* P) {
    if (!pilha_vazia(P)) {
        int data = desempilhar(P);
        pilha_inverter(P);
        inverter_pilha_recursiva(P, data);
    }
}


*/





/*

NA PROVA DO RUDINEI ELE COBROU UMA QUESTÃO QUE PEDIA PALÍNDROMO DA MELHOR MANEIRA POSSÍVEL
(tinha que usar deque e fazer n/2 comparações)

ELE COBROU TAMBÉM UMA QUESTÃO BESTA DE CONCEITO ED TAD(não pode fazer item->chave)

TAMBÉM UMA QUESTÃO DE INSERÇÃO_REMOÇÃO EM LISTA DUPLAMENTE ENCADEADA

PEDIU TAMBÉM PARA IMPLEMENTAR UMA FUNÇÃO LÁ DE BUSCA (creio ser de busca de lista) 

*/ 
