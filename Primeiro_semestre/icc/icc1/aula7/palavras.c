#include <stdio.h>

int main(void) {
  int ch = 0;
  int linha = 0;
  int palavra = 0;
  char c;
  char anterior = ' ';

  while((c = getchar()) != EOF) {
    if(c != ' ' && (c != '\n' && c != '\r')) {
      ch++;
      if (anterior == ' ' || anterior == '\n' || anterior == '\r'){
        palavra++;
      }
    }

    if(c == '\n') {
      linha++;
    } 

    anterior = c;
  }

  printf("Caracteres: %d\n", ch);
  printf("Palavras: %d\n", palavra);
  printf("Linhas: %d\n", linha + 1);

  return 0;
}
