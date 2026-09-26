/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    true,
    false
} Boolean;

typedef struct No {
    int codigo;
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct Arvore {
    struct No* raiz;
} Arvore;

void inicializar_arvore(struct Arvore* arvore) {
    arvore->raiz == NULL;
}

Boolean eh_nula(struct No* noAtual) {
    return noAtual == NULL;
}

int maior_altura(struct No* noAtual) {
    if(eh_nula(noAtual))
        return 0;

    int maior_esquerda = maior_altura(noAtual->esquerda);
    int maior_direita = maior_altura(noAtual->direita);

    if(maior_esquerda > maior_direita)
        return maior_esquerda + 1;

    else
        return maior_direita + 1;
}

void popular_arvore(struct Arvore* arv) {
    struct No* n1 = (struct No*)malloc(sizeof(struct No));
    struct No* n2 = (struct No*)malloc(sizeof(struct No));
    struct No* n3 = (struct No*)malloc(sizeof(struct No));
    struct No* n4 = (struct No*)malloc(sizeof(struct No));
    struct No* n5 = (struct No*)malloc(sizeof(struct No));
    struct No* n6 = (struct No*)malloc(sizeof(struct No));
    struct No* n7 = (struct No*)malloc(sizeof(struct No));
    struct No* n8 = (struct No*)malloc(sizeof(struct No));
    
    // Adicionando novos nós para aumentar o tamanho da árvore
    struct No* n9 = (struct No*)malloc(sizeof(struct No));
    struct No* n10 = (struct No*)malloc(sizeof(struct No));

    n1->codigo = 12; // Raiz
    n2->codigo = 5;
    n3->codigo = 19;
    n4->codigo = 2;
    n5->codigo = 8;
    n6->codigo = 14;
    n7->codigo = 23;
    n8->codigo = 27;
    n9->codigo = 30; // Novo nó
    n10->codigo = 35; // Novo nó

    // Conectando os nós
    n1->esquerda = n2;
    n1->direita = n3;

    n2->esquerda = n4;
    n2->direita = n5;

    n3->esquerda = n6;
    n3->direita = n7;

    n4->esquerda = NULL;
    n4->direita = NULL;

    n5->esquerda = NULL;
    n5->direita = NULL;

    n6->esquerda = NULL;
    n6->direita = NULL;

    n7->esquerda = NULL;
    n7->direita = n8; 

    // Estendendo a altura da árvore pelo lado direito
    n8->esquerda = NULL;
    n8->direita = n9;

    n9->esquerda = NULL;
    n9->direita = n10;
    
    n10->esquerda = NULL;
    n10->direita = NULL;

    arv->raiz = n1;
}

int main() {
    struct Arvore arvore;
    struct No no;

    inicializar_arvore(&arvore);
    popular_arvore(&arvore);

    int altura = maior_altura(arvore.raiz);
    
    printf("Altura: %d\n", altura);
}