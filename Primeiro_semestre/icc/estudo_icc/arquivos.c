#include <stdio.h>
#include <stdlib.h>
                                //argc      1           2  
int main(int argc, char *argv[]){ // ./arquivos nome_do_arquivo
    FILE *fp;
    char c;
    fp = fopen(argv[1], "r");
    if (argc != 2){
        printf("Faltou o nome do arquivo\n");
        return 0;
    }
    if ((fp = fopen(argv[1], "w")) == NULL){
        printf("Erro na abertura do arquivo\n");
        return 0;
    }
    do{
        scanf("%c", &c); // Se você fizer scanf("%c", c); ele vai ler normalmente (com linhas e tudo), mas, se você fizer scanf(" %c", &c); ele vai ler e colocar no arquivo em uma só linha
        fprintf(fp, "%c", c);
    }while(c != '$');
    fclose(fp);
    return 0;
}