// arvore_abb.h
#ifndef ARVORE_ABB_H
#define ARVORE_ABB_H

typedef struct NoAbb {
    int valor;
   struct NoAbb* esquerda;
   struct NoAbb* direita;
} NoAbb;

typedef struct ArvoreAbb {
   struct NoAbb* raiz;
} ArvoreAbb;

void inicializar_arvore_abb(ArvoreAbb* arvore);
struct NoAbb* inserir_no_abb(struct NoAbb* raiz, int valor);
struct NoAbb* retorna_no_abb(struct NoAbb* raiz, int valor, int* comparacoes);

#endif