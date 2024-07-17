/* 
O programa é um sistema de gerenciamento de inventário que 
permite ao usuário adicionar, vender e consultar produtos. 
Ele mantém registros dos produtos, quantidades, preços e saldo 
do inventário. O usuário pode executar diversas operações, como 
adicionar produtos, aumentar o estoque, modificar preços, realizar 
vendas e consultar o estoque e saldo. Os dados do inventário podem 
ser salvos e carregados de um arquivo de texto. 

Autores: Ayrton da Costa Ganem Filho, Felipe Volkweis de Oliveira e Matheus Paiva Angarola  (2023)
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LINHA "--------------------------------------------------" // Separação entre as linhas de saída
#define NOME_ARQUIVO "inventario.txt"

/* Struct que representa um produto específico, 
com seus respectivos atributos, como código, nome, 
preço e quantidade.*/

typedef struct {
    int codigo;
    char *nome;
    double preco;
    int quantidade;
} produto_t;

/* Essa struct representa o inventário como um todo, 
contendo a lista de produtos, o tamanho do inventário e 
o saldo total.*/

typedef struct {
    produto_t *produtos;
    int tamanho;
    double saldo;
} inventario_t;

/* Essa struct é utilizada para representar uma venda específica, 
armazenando os produtos vendidos, o valor total da venda e o número 
de produtos vendidos.*/

typedef struct {
    produto_t *produtos;
    double total;
    int tamanho;
} venda_t;

/* Essas structs são utilizadas no programa para representar e 
manipular os dados relacionados aos produtos, inventário e vendas. */

typedef struct {
    int tamanho;
    int *codigos;
    int quantidade_venda;
} codigos_venda_t;


/* Protótipos de funções */
void insere_produto(char *nome, int quantidade, double preco, inventario_t *inventario);
void aumenta_estoque(int codigo, int quantidade, inventario_t *inventario);
void modifica_preco(int codigo, double preco, inventario_t *inventario);
codigos_venda_t scan_codigos_venda();
venda_t venda(int *codigos, int tamanho_codigos, int quantidade_vendidos, inventario_t *inventario);
void mostra_venda(venda_t venda);
void consulta_estoque(inventario_t inventario);
void consulta_saldo(inventario_t inventario);
int finaliza_execucao();
int executa_comando(char *comando, inventario_t *inventario);
int compara_comando(char *input, char *comando);
char *scan_nome(char *nome);
char *scan_nome_arquivo(char *nome, FILE *arquivo);
void free_inventario(inventario_t *inventario);
void grava_no_arquivo(inventario_t inventario);
void le_arquivo(inventario_t *inventario);

/* 
Funcao é responsável por adicionar um novo produto, dado pelo usuário, ao inventário. 
Parametro de Entrada:  nome - nome do produto
                       quantidade - quantos deste tipo serão adicionados ao estoque
                       preco - preço do produto
                       inventario -representar um inventário de produtos      
*/
void insere_produto(char *nome, int quantidade, double preco, inventario_t *inventario) {
    produto_t produto;
    produto.codigo = inventario->tamanho;
    produto.nome = nome;
    produto.preco = preco;
    produto.quantidade = quantidade;

    inventario->tamanho++;

    // Alocação dinâmica de memória para armazenar o produto no inventário
    inventario->produtos = realloc(inventario->produtos, inventario->tamanho * sizeof(produto_t)); 
    inventario->produtos[inventario->tamanho - 1] = produto;
}

/* 
Funcao tilizada para aumentar a quantidade em estoque de um produto específico.
Parametro de Entrada:  codigo - código do produto a ser modificado
                       quantidade - quantos deste tipo serão adicionados ao estoque
                       inventario -representar um inventário de produtos      
*/
void aumenta_estoque(int codigo, int quantidade, inventario_t *inventario) {
    inventario->produtos[codigo].quantidade += quantidade;
}

/* 
Funcao que permite alterar o preço de um produto específico. 
Parametro de Entrada:  codigo - código do produto a ser modificado
                       preco - novo preço do produto
                       inventario -representar um inventário de produtos      
*/
void modifica_preco(int codigo, double preco, inventario_t *inventario) {
    inventario->produtos[codigo].preco = preco;
}

/* 
Funcao que lê uma sequência de códigos de produtos a serem vendidos. 
Os códigos são lidos do teclado até que um valor negativo seja inserido.
Parametro de Entrada:  nenhum      
Parametros de Saída:  codigos_venda_t - contém a lista de códigos, o tamanho da lista e a quantidade vendida
*/

codigos_venda_t scan_codigos_venda() {
    int *codigos = NULL;
    int codigo;
    int tamanho = 0;
    codigos_venda_t codigos_venda;

    scanf("%d", &codigo);
    codigos = malloc(sizeof(int));
    codigos[tamanho] = codigo;
    tamanho++;

    do {
        scanf("%d", &codigo);

        if(codigo >= 0) {
            codigos = realloc(codigos, (tamanho + 1) * sizeof(int));
            codigos[tamanho] = codigo;
            tamanho++;
        }
    } while(codigo >= 0); 

    codigos_venda.tamanho = tamanho; 
    codigos_venda.codigos = codigos; 
    codigos_venda.quantidade_venda = codigo;

    return codigos_venda;
}

/* 
Funcao que realiza a venda dos produtos com base nos códigos fornecidos.
Parametro de entrada:  codigos - códigos de todos os produtos
                       tamanho_codigos - tamanho do vetor de codigos
                       quantidade_vendidos - quantos produtos foram vendidos
                       inventario -representar um inventário de produtos
*/

venda_t venda(int *codigos, int tamanho_codigos, int quantidade_vendidos, inventario_t *inventario) {
    produto_t *produtos = NULL;
    venda_t venda;
    venda.total = 0;
    venda.tamanho = 0;

    for(int i = 0; i < tamanho_codigos; i++) {
        int index = codigos[i];
        produto_t *produto_atual = &inventario->produtos[index];

        if(produto_atual->quantidade > 0) {
            venda.tamanho++;
            
            produto_atual->quantidade += quantidade_vendidos;

            produto_t produto;
            produto.codigo = produto_atual->codigo;
            produto.nome = produto_atual->nome;
            produto.preco = produto_atual->preco;
            produto.quantidade = quantidade_vendidos * -1; 

            produtos = realloc(produtos, (venda.tamanho) * sizeof(produto_t));
            produtos[venda.tamanho - 1] = produto;

            venda.total += produto.quantidade * produto.preco;
        }
    }
    venda.produtos = produtos;

    inventario->saldo += venda.total;

    return venda;
}

/* 
Funcao que imprime os detalhes de uma venda na tela, incluindo o nome,
o preço de cada produto vendido e o total da venda.
Parametro de entrada:  venda - 
*/

void mostra_venda(venda_t venda) {
    for(int i = 0; i < venda.tamanho; i++) {
        printf("%s %.2lf\n", venda.produtos[i].nome, venda.produtos[i].preco);
    }
    printf("Total: %.2lf\n", venda.total);
    printf("%s\n", LINHA);
}

/* 
Funcao que exibe as informações do inventário na tela, mostrando o código,
o nome e a quantidade de cada produto em estoque.
Parametro de Sáida:  inventario -representar um inventário de produtos  
*/

void consulta_estoque(inventario_t inventario) {
    for(int i = 0; i < inventario.tamanho; i++) {
        printf("%d %s %d\n", 
            inventario.produtos[i].codigo, 
            inventario.produtos[i].nome,
            inventario.produtos[i].quantidade);
    }
    printf("%s\n", LINHA);
}

/* 
Funcao exibe o saldo atual do inventário na tela.
Parametro de Sáida:  inventario -representar um inventário de produtos  
*/

void consulta_saldo(inventario_t inventario) {
    printf("Saldo: %.2lf\n", inventario.saldo);
    printf("%s\n", LINHA);
}

/* 
Funcao é utilizada para encerrar a execução do programa
Parametro de Sáida:  0 - para indicar que o programa deve ser finalizado
*/

int finaliza_execucao() {
    return 0;
}

/* 
Funcao é responsável por comparar se dois comandos são iguais. 
*/

int compara_comando(char *input, char *comando) {
    return input[0] == comando[0] && input[1] == comando[1];
}

/* 
Função é responsável por ler uma sequência de caracteres do teclado e 
armazená-la em um array de caracteres (string).
Parametro de Entrada:  nome - nome digitado pelo usuário
*/

char *scan_nome(char *nome) {
    char c;
    int tamanho = 0;

    while(((c = getchar()) != '\0') && c != ' ' && c != '\n' && c != EOF) {
        tamanho++;
        nome = realloc(nome, tamanho * sizeof(char));
        nome[tamanho - 1] = c;
    }
    nome = realloc(nome, (tamanho + 1) * sizeof(char));

    nome[tamanho] = '\0';

    return nome;
}

/* 
Função é semelhante à função "scan_nome", porém ela 
lê uma sequência de caracteres de um arquivo em vez de ler do teclado.
Parametro de Entrada:  nome - nome digitado pelo usuário
                       arquivo - aquivo que ira armazenar os dados
*/

char *scan_nome_arquivo(char *nome, FILE *arquivo) {
    char c;
    int tamanho = 0;
    
    while(((c = fgetc(arquivo)) != '\0') && c != ' ' && c != '\n' && c != EOF) {
        tamanho++;
        nome = realloc(nome, tamanho * sizeof(char));
        nome[tamanho - 1] = c;
    }
    nome = realloc(nome, (tamanho + 1) * sizeof(char));

    nome[tamanho] = '\0';

    return nome;
}
/* 
Funcao que desaloca o vetor do inventário
Parametro de Entrada:  inventario -representar um inventário de produtos       
*/
void free_inventario(inventario_t *inventario) {
    for(int i = 0; i < inventario->tamanho; i++) {
        free(inventario->produtos[i].nome);
        inventario->produtos[i].nome = NULL;
    }
    
    free(inventario->produtos);
    inventario->produtos = NULL;
}

/* 
Funcao que recebe um comando fornecido pelo usuário e chama a função 
correspondente para executar a funcionalidade desejada. 
Parametro de Entrada:  comando - Comando/entrada digitado pelo usuário
                       inventario -representar um inventário de produtos      
*/
int executa_comando(char *comando, inventario_t *inventario) {    
    if(compara_comando(comando, "IP")) {
        char *nome = NULL;
        int quantidade;
        double preco;

        nome = scan_nome(nome);
        scanf("%d %lf ", &quantidade, &preco);

        insere_produto(nome, quantidade, preco, inventario);

    } else if(compara_comando(comando, "AE")) { /* Aumenta estoque: AE_<código>_<quantidade> */
        int codigo;
        int quantidade;
        scanf("%d %d ", &codigo, &quantidade);

        aumenta_estoque(codigo, quantidade, inventario);

    } else if(compara_comando(comando, "MP")) { /* Modifica preço: MP_<código>_<preço> */
        int codigo;
        double preco;
        scanf("%d %lf ", &codigo, &preco);

        modifica_preco(codigo, preco, inventario);

    } else if(compara_comando(comando, "VE")) { /* Venda: VE_<código>_<código>_..._<código>_<-1> */
        codigos_venda_t codigos_venda = scan_codigos_venda();
        venda_t venda_ = venda(codigos_venda.codigos, codigos_venda.tamanho, codigos_venda.quantidade_venda, inventario);
        mostra_venda(venda_);
        
        free(codigos_venda.codigos);
        codigos_venda.codigos = NULL;

        free(venda_.produtos);
        venda_.produtos = NULL;

    } else if(compara_comando(comando, "CE")) { /* Consulta estoque */
        consulta_estoque(*inventario);

    } else if(compara_comando(comando, "CS")) { /* Consulta saldo */
        consulta_saldo(*inventario);

    } else if(compara_comando(comando, "FE")) { /* Finaliza a execução */
        grava_no_arquivo(*inventario);

        return finaliza_execucao();
    }
    return 1;
}
/* 
Funcao que grava as informações coletadas dentro de um .txt
Parametro de Entrada:  inventario -       
*/
void grava_no_arquivo(inventario_t inventario) {
    FILE *arquivo = fopen(NOME_ARQUIVO, "w");

    fprintf(arquivo, "%d\n", inventario.tamanho);
    fprintf(arquivo, "%.2lf\n", inventario.saldo);

    for(int i = 0; i < inventario.tamanho; i++) {
        fprintf(arquivo, "%d %s %d %.2lf\n", 
            inventario.produtos[i].codigo,
            inventario.produtos[i].nome,
            inventario.produtos[i].quantidade,
            inventario.produtos[i].preco);
    }

    fclose(arquivo);
}
/* 
Funcao que lê as informações do inventário a partir de um 
arquivo .txt e atualiza o inventário com os dados lidos.
Parametro de Entrada:  inventario -representar um inventário de produtos       
*/
void le_arquivo(inventario_t *inventario) {
    FILE *arquivo = fopen(NOME_ARQUIVO, "r");
    if(arquivo == NULL)
        return;

    fscanf(arquivo, "%d", &(*inventario).tamanho);
    fscanf(arquivo, "%lf", &(*inventario).saldo);

    (*inventario).produtos = malloc(sizeof(produto_t) * inventario->tamanho);

    for(int i = 0; i < (*inventario).tamanho; i++) {
        (*inventario).produtos[i].nome = NULL;
        fscanf(arquivo, "%d ", &(*inventario).produtos[i].codigo);
        (*inventario).produtos[i].nome = scan_nome_arquivo((*inventario).produtos[i].nome, arquivo);
        fscanf(arquivo, "%d %lf ", 
            &(*inventario).produtos[i].quantidade,
            &(*inventario).produtos[i].preco);
    }

    fclose(arquivo);
}

/* Programa Principal */
int main() {
    char *comando = NULL;   // Comando lido
    int usuario_mandou_fechar = 1;  // Flag utilizada para a execução do loop
    int tamanho;    // Tamanho do estoque

    FILE *arquivo = NULL;   // Ponteiro para file para checar se existe o inventário do dia anterior

    inventario_t inventario;
    inventario.produtos = NULL;
    inventario.tamanho = 0;

    // Checa se existe o inventário do dia anterior
    if((arquivo = fopen(NOME_ARQUIVO, "r")) == NULL) {
        scanf("%d %lf ", &tamanho, &inventario.saldo);
    } else {
        fclose(arquivo);
        le_arquivo(&inventario);
    }

    // Loop de execução dos comandos digitados pelo usuário (até digitar FE)
    while(usuario_mandou_fechar) {
        comando = scan_nome(comando);
        usuario_mandou_fechar = executa_comando(comando, &inventario);

        free(comando);
        comando = NULL;
    }

    free_inventario(&inventario);

    return 0;
}