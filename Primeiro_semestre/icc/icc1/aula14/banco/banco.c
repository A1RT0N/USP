#include <stdio.h>
#include <stdlib.h>

struct pessoa {
    char nome[100];
    int idade;
    char cargo[100];
    int salario;
};

typedef struct pessoa pessoa_t;

int main() {
    int num, max;
    pessoa_t *pessoas = NULL;
    char file_path[100];
    FILE *banco = NULL;
        
    scanf("%s %d", file_path, &max);

    banco = fopen(file_path, "r");
    if(banco == NULL) {
        printf("Este banco de dados nao existe.\n");
        return 0;
    }

    fscanf(banco, "%d", &num);

    pessoas = malloc(num * sizeof(pessoa_t));
    
    for(int i = 0; i < num; i++) {
        fscanf(banco, "%s %d %s %d",
            pessoas[i].nome,
            &pessoas[i].idade,
            pessoas[i].cargo,
            &pessoas[i].salario);
    }

    for(int i = 0; i < num; i++) {
        if(pessoas[i].salario > max) {
            printf("%s\n%d\n%s\n%d\n",
                pessoas[i].nome,
                pessoas[i].idade,
                pessoas[i].cargo,
                pessoas[i].salario);
        }
    }

    fclose(banco);
    banco = NULL;

    free(pessoas);
    pessoas = NULL;

    return 0;
}