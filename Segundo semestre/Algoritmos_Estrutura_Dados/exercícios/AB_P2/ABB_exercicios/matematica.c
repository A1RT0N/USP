#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura para um nó da árvore
typedef struct Node {
    char value; // O valor pode ser um operador ou um operando
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* createNode(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para imprimir a expressão na forma infixa
void printInfix(Node* node) {
    if (node == NULL) {
        return;
    }

    // Se for um operador, imprime um parêntese abrindo
    if (node->left && node->right && (node->value == '+' || node->value == '-')) {
        printf("(");
    }

    // Primeiro imprime o filho da esquerda recursivamente
    printInfix(node->left);

    // Depois imprime o valor do nó (que pode ser um operando ou um operador)
    printf("%c", node->value);

    // Por fim, imprime o filho da direita recursivamente
    printInfix(node->right);

    // Se for um operador, imprime um parêntese fechando
    if (node->left && node->right && (node->value == '+' || node->value == '-')) {
        printf(")");
    }
}

// Função principal para testar a função printInfix
int main() {
    // Construindo a árvore para a expressão (3 + 5) * 8
    Node* root = createNode('*');
    root->left = createNode('+');
    root->left->left = createNode('3');
    root->left->right = createNode('5');
    root->right = createNode('8');

    // Imprimindo a expressão na forma infixa
    printInfix(root);
    printf("\n");

    return 0;
}
