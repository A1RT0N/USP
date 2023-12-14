#include <stdlib.h>
#include <stdio.h>
#include "item.h"

struct item_{ 
    int vet[2];
};

ITEM *item_criar(int vet[]){

  ITEM *item;

  item = (ITEM *) malloc(sizeof(ITEM));
    
  if (item != NULL){
    item->vet[0] = vet[0]; // Passe valores e não endereços para vet
    item->vet[1] = vet[1];
    return(item);
  }
  return(NULL);
}

bool item_apagar(ITEM **item){
   if (*item != NULL){
      free (*item);
      *item = NULL; 
      return(true);
   }
   return(false);
}

int* item_get_chave(ITEM *item){
  if (item != NULL)
    return(item->vet);
}


bool item_set_chave(ITEM *item, int vet[]){
  if (item != NULL){
      item->vet[0] = vet[0];
      item->vet[1] = vet[1];
      return (true);
  }
  return (false);
}

void item_imprimir(ITEM *item){
  if (item != NULL)
    printf("(%d, %d)", item->vet[0], item->vet[1]);
}
