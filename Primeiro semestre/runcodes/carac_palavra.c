#include <stdio.h>
// rn
int main(){
    char carac;
    int caracteres = 0, palavras = 1, linhas = 1, anterior = 0;
    while (scanf("%c", &carac) != EOF){
        if (!(carac == '\n' && anterior == '\r') && ((carac == '\n') || (carac == '\r')) ){
            linhas++;
        } 
        if (((carac <= 'Z') && (carac >= '!')) || ((carac <= 'z') && (carac >= 'a')) ){ // ASCII
            caracteres++; 
        }
        if (((anterior == ' ') || (anterior == '\n')) && ((carac != '\n') && (carac != ' ') && (carac != '\r'))){
           palavras++; 
        }
        anterior = carac;
       }
    printf("Caracteres: %d\nPalavras: %d\nLinhas: %d\n", caracteres, palavras, linhas);
    return 0;
}