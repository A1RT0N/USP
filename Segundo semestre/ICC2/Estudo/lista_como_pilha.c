#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

void printreverse(struct node *head){
    if(head == NULL){
        return;
    }

    printreverse(head->next);

    printf("%d ", head->data);
}

